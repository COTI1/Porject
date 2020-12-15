package Show;

import java.util.ArrayList;
import java.util.Random;

//习题类
public class Exercise {
	private int count = 0;  //习题中包含的算数数量
	private int index = 0;   //当前访问算式的序号 索引
	private ArrayList<Equation> exercise = null;  //习题数据结构  封装集合类
	public int getCount() {
		return count;
	}
	public void setCount(int count) {
		this.count = count;
	}
	public int getIndex() {
		return index;
	}
	public void setIndex(int index) {
		this.index = index;
	}
	public ArrayList<Equation> getExercise() {
		return exercise;
	}
	public void setExercise(ArrayList<Equation> exercise) {
		this.exercise = exercise;
	}
	//创造任意多个习题 的构造函数
	public Exercise(int count) {
		this.setCount(count);
		index = 0;
		exercise = new ArrayList<Equation>();
	}
	//判断算式是否在当前习题中已经存在
	public boolean occursIn(Equation e) {
		boolean b = false;
		for(Equation equation: exercise) {
			if(equation.isEqual(e)) {
				b = true;
				break;
			}
		}
		return b;
	}
	//构造混合习题
	public void generateExercise() {
		int i = 0;
		Random r = new Random();
		while(i<count) {
			Equation e;
			if(r.nextInt(2) == 1) {
				e = new AddEquation();
			}
			else {
				e = new SubEquation();
			}
			if(!occursIn(e)) {
				exercise.add(e);
				i++;
			}
		}
	}
	//构造加法习题
	public void generateAddExercise() {
		int i = 0;
		while(i < count) {
			Equation e = new AddEquation();
			if(!occursIn(e)) {
				exercise.add(e);
				i++;
			}
		}
	}
	//构造减法习题
	public void generateSubExercise() {
		int i = 0;
		while(i < count) {
			Equation e = new SubEquation();
			if(!occursIn(e)) {
				exercise.add(e);
				i++;
			}
		}
	}


	//遍历算式的方法
	//判断在当前算式中
	public boolean hasNext() {
		return index < exercise.size();
	}
	//获取下一个算式
	public Equation next() {
		if(index < exercise.size()) {
			return exercise.get(index++);
		}
		else {
			return null;
		}
	}
	//往系统中添加算式
	public boolean add(Equation e) {
		if(index < count) {
			exercise.add(e);
			index++;
			return true;
		}
		else {
			return false;
		}
	}
	//获取习题中算式数量
	public int size() {
		return exercise.size();
	}
	public Equation get(int index) {
		if(index < size()) {
			return exercise.get(index);
		}
		else {
			return null;
		}
	}

}
