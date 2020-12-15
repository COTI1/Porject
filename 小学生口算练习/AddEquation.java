package Show;


public class AddEquation extends Equation {

	public AddEquation() {
		generateEquation('+');
	}

	protected int calculate() {
		return this.getLeft() + this.getRight();
	}

}
