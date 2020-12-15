package Show;

import java.util.Random;

//算式类
public abstract class Equation {
	private final int MAX = 100;
	private final int MIN = 0;

	public int getLeft() {
		return left;
	}

	public void setLeft(int left) {
		this.left = left;
	}

	public int getRight() {
		return right;
	}

	public void setRight(int right) {
		this.right = right;
	}

	public int getResult() {
		return result;
	}

	public void setResult(int result) {
		this.result = result;
	}

	public char getOp() {
		return op;
	}

	public void setOp(char op) {
		this.op = op;
	}

	private int left, right, result;
	private char op;

	public Equation() {

	}
	//生成随机数
	private int generateRandom(int min, int max) {
		Random r = new Random();
		return r.nextInt(max - min + 1) + min;
	}

	//判断数值结果是否在最大值 最小值的范围内
	private boolean isBetween(int value, int min, int max) {
		return value >= min && value <= max;
	}

	//定义运算的方法  因为加法类和减法类不同，所以算式类中定义为抽象方法
	protected abstract int calculate();

	//定义两个算式是否相等
	public boolean isEqual(Equation e) {
		boolean b = false;
		if(e.getOp() != this.getOp()) {
			b = false;
		}
		else {
			b = e.getLeft() == this.getLeft() && e.getRight() == this.getRight();
		}
		return b;
	}

	//将算式转换为字符串
	public String toString() {
		return "" + this.getLeft() + this.getOp() + this.getRight()+"=";
	}

	//构造算式
	public void generateEquation(char op) {
		do {
			left = generateRandom(MIN, MAX);
			right = generateRandom(MIN, MAX);
			result = calculate();
		}while(!isBetween(result, MIN, MAX));//判断当前生成的算是是否在有效范围之内
		this.setOp(op);
	}

}
