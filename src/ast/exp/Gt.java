package ast.exp;

public class Gt extends T
{
  public T left;
  public T right;

  public Gt(T left, T right)
  {
    this.left = left;
    this.right = right;
  }

  @Override
  public void accept(ast.Visitor v)
  {
    v.visit(this);
    return;
  }
}