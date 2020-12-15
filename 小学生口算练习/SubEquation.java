package Show;


public class SubEquation extends Equation {

	public SubEquation() {
		generateEquation('-');
	}

	protected int calculate() {
		return this.getLeft() - this.getRight();
	}

}
