
package Show;

import java.util.ArrayList;

//答案类
public class Answer {
	private ArrayList<Integer> answer;
	private int index;

	public Answer() {

		answer = new ArrayList<Integer>(); //初始化成员变量
		index = 0;
	}

	//重置答案的索引序号
	public void reset() {
		index = 0;
	}

	//实现对答案数据集合的遍历访问
	public boolean add(int a) {
		return answer.add(a);
	}

	public boolean hasNext() {
		return index < answer.size();
	}
	//获取下一个答案
	public int next() {
		if(index<answer.size()) {
			return answer.get(index++);
		}
		else {
			return -1;
		}
	}
	//按照题目序号获取答案
	public int get(int index) {
		return answer.get(index);
	}
	//按照题目序号设置答案
	public void set(int index, int x) {
		answer.set(index, x);
	}
}
