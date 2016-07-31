package ast.optimizations;

// Dead class elimination optimizations on an AST.

public class DeadClass implements ast.Visitor {
	private java.util.HashSet<String> set;
	private java.util.LinkedList<String> worklist;
	public ast.program.T program;

	public DeadClass() {
		this.set = new java.util.HashSet<String>();
		this.worklist = new java.util.LinkedList<String>();
		this.program = null;
	}

	// /////////////////////////////////////////////////////
	// expressions
	@Override
	public void visit(ast.exp.Add e) {
		e.left.accept(this);
		e.right.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.And e) {
		e.left.accept(this);
		e.right.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.ArraySelect e) {
		e.array.accept(this);
		e.index.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.Call e) {
		e.exp.accept(this);
		for (ast.exp.T arg : e.args) {
			arg.accept(this);
		}
		return;
	}

	@Override
	public void visit(ast.exp.False e) {
		return;
	}

	@Override
	public void visit(ast.exp.Id e) {
		return;
	}

	@Override
	public void visit(ast.exp.Length e) {
		e.array.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.Lt e) {
		e.left.accept(this);
		e.right.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.Gt e) {
		e.left.accept(this);
		e.right.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.NewIntArray e) {
		e.exp.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.NewObject e) {
		if (this.set.contains(e.id))
			return;
		this.worklist.add(e.id);
		this.set.add(e.id);
		return;
	}

	@Override
	public void visit(ast.exp.Not e) {
		e.exp.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.Num e) {
		return;
	}

	@Override
	public void visit(ast.exp.Sub e) {
		e.left.accept(this);
		e.right.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.This e) {
		return;
	}

	@Override
	public void visit(ast.exp.Times e) {
		e.left.accept(this);
		e.right.accept(this);
		return;
	}

	@Override
	public void visit(ast.exp.True e) {
		return;
	}

	@Override
	public void visit(ast.exp.Block s) {
		s.exp.accept(this);
		return;
	}

	// statements
	@Override
	public void visit(ast.stm.Assign s) {
		s.exp.accept(this);
		return;
	}

	@Override
	public void visit(ast.stm.AssignArray s) {
		s.index.accept(this);
		s.exp.accept(this);
		return;
	}

	@Override
	public void visit(ast.stm.Block s) {
		for (ast.stm.T x : s.stms)
			x.accept(this);
		return;
	}

	@Override
	public void visit(ast.stm.If s) {
		s.condition.accept(this);
		s.thenn.accept(this);
		s.elsee.accept(this);
		return;
	}

	@Override
	public void visit(ast.stm.Print s) {
		s.exp.accept(this);
		return;
	}

	@Override
	public void visit(ast.stm.While s) {
		s.condition.accept(this);
		s.body.accept(this);
		return;
	}

	@Override
	public void visit(ast.type.Id t) {
	}

	// type
	@Override
	public void visit(ast.type.Boolean t) {
		return;
	}

	@Override
	public void visit(ast.type.Class t) {
		return;
	}

	@Override
	public void visit(ast.type.Int t) {
		return;
	}

	@Override
	public void visit(ast.type.IntArray t) {
	}

	// dec
	@Override
	public void visit(ast.dec.Dec d) {

		if (d.type.toString().toCharArray()[0] != '@') {
			if (this.set.contains(d.type.toString()))
				return;
			this.worklist.add(d.type.toString());
			this.set.add(d.type.toString());
			return;
		}

		return;
	}

	// method
	@Override
	public void visit(ast.method.Method m) {
		for (ast.dec.T d : m.formals)
			d.accept(this);
		for (ast.dec.T d : m.locals)
			d.accept(this);
		for (ast.stm.T s : m.stms)
			s.accept(this);
		m.retExp.accept(this);
		return;
	}

	// class
	@Override
	public void visit(ast.classs.Class c) {
		if (c.extendss != null && !this.set.contains(c.extendss)) {
			this.worklist.add(c.extendss);
			this.set.add(c.extendss);
		}
		for (ast.dec.T d : c.decs)
			d.accept(this);

		for (ast.method.T m : c.methods)
			m.accept(this);
	}

	// main class
	@Override
	public void visit(ast.mainClass.MainClass c) {
		for (ast.stm.T s : c.stms)
			s.accept(this);
		return;
	}

	// program
	@Override
	public void visit(ast.program.Program p) {
		// we push the class name for mainClass onto the worklist
		ast.mainClass.MainClass mainclass = (ast.mainClass.MainClass) p.mainClass;
		this.set.add(mainclass.id);

		p.mainClass.accept(this);

		while (!this.worklist.isEmpty()) {
			String cid = this.worklist.removeFirst();

			for (ast.classs.T c : p.classes) {
				ast.classs.Class current = (ast.classs.Class) c;

				if (current.id.equals(cid)) {
					c.accept(this);
					break;
				}
			}
		}

		java.util.LinkedList<ast.classs.T> newClasses = new java.util.LinkedList<ast.classs.T>();
		for (ast.classs.T classs : p.classes) {
			ast.classs.Class c = (ast.classs.Class) classs;
			if (this.set.contains(c.id)) {
				newClasses.add(c);
			}
		}

		this.program = new ast.program.Program(p.mainClass, newClasses);

		if (newClasses.size() != p.classes.size())
			ast.optimizations.Main.modified();

		if (control.Control.isTracing("ast.DeadClass")) {
			System.out.println("before optimization:");
			ast.PrettyPrintVisitor pp = new ast.PrettyPrintVisitor();
			p.accept(pp);
			System.out.println("after optimization:");
			this.program.accept(pp);
		}

		return;
	}
}
