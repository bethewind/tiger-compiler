package cfg.stm;

import cfg.Visitor;

public class Move extends T {
	// type of the destination variable
	public cfg.type.T ty;
	public cfg.operand.T src;

	public Move(String dst, cfg.type.T ty, cfg.operand.T src) {
		this.dst = dst;
		this.ty = ty;
		this.src = src;
	}

	@Override
	public void accept(Visitor v) {
		v.visit(this);
	}

	@Override
	public String toString() {
		return this.dst + " = " + this.src.toString() + ";\n";
	}
}
