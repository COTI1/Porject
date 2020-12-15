package Show;

import java.util.ArrayList;

//批改类
public class Check {
	private ArrayList<Integer> check;
	private int count; //习题数量
	private int right; //正确的习题数量
	private int wrong; //错误的习题数量

	public int getCount() {
		return count;
	}

	public void setCount(int count) {
		this.count = count;
	}

	public int getRight() {
		return right;
	}

	public void setRight(int right) {
		this.right = right;
	}

	public int getWrong() {
		return wrong;
	}

	public void setWrong(int wrong) {
		this.wrong = wrong;
	}


	public Check() {
		right = 0;
		wrong = 0;
		check = new ArrayList<Integer>(); //初始化成员变量
	}
	
	public void check(Exercise ex, Answer an) {
		count = ex.size();
		int wrong = 0, right = 0;
		ex.setIndex(0); //初始化系统中算式的序号
		an.reset();
		while(ex.hasNext()) {
			if(ex.next().getResult() == an.next()) {
				right++;
				check.add(1);
			}
			else {
				wrong++;
				check.add(0);
			}
			
		}
		setRight(right);
		setWrong(wrong);
	}

	//按照题目序号获取答案
	public int get(int index) {
		return check.get(index);
	}

}
