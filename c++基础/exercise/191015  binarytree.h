#pragma once
#include<stack>
#include<queue>
#include<iostream>
using namespace std;

	template<class T>
	class TreeNode
	{
		T m_val;

		TreeNode<T> *m_left;
		TreeNode<T> *m_right;

	public:
		TreeNode(const T &val) :
			m_val(val)
		{

		}
		template<class T>
		friend class Tree;//TreeNode为私有，所以许设友元，Tree才能访问
	};



template<class T>
class Tree
{
	TreeNode<T> *m_root;
	static TreeNode<T> * makeTree(const T *val,const T &end, int &i)
	{
		if (val[i] == end)
		{
			i++;
			return nullptr;
		}

		TreeNode<T>* root = new TreeNode<T>(val[i]);
		i++;

		root->m_left= makeTree(val, end, i);
		root->m_right = makeTree(val, end, i);
		return root;
	}
public:
	Tree() :
		m_root(nullptr)
	{

	}

	Tree(const T *val, const T &end)
	{
		int i=0;
		m_root= makeTree(val,end,i);
	} 
	
	//前序，打印，叙写成push
	void pre_order()
    {
		TreeNode<T>* cur = m_root;
		stack<TreeNode<T> *> st;

		while (cur)
		{
			cout << cur->m_val;
			if (cur->m_right)
			{
				st.push(cur->m_right);
			}
			if (cur->m_left)
			{
				cur=cur->m_left;
			}
			else
			{
				if (st.empty())
				{
					cur = nullptr;
				}
				else
				{
					cur = st.top();
					st.pop();
				}
			}
		}
	}

	//中序
	void in_order()
	{
		TreeNode<T>* cur = m_root;
		stack<TreeNode<T> *> st;

		while (cur||!st.empty())
		{
			for(;cur;cur=cur->m_left)
			{
				st.push(cur);
			}
			if(!st.empty())
			{
			    cur = st.top();
				st.pop();
				cout << cur->m_val;
				cur = cur->m_right;
		    }
		}
	}
	
	//后序
	void post_order()
	{
		TreeNode<T>* cur = m_root;
		stack<TreeNode<T> *> st;
		stack<bool> tag;

		while (cur || !st.empty())
		{
			for (; cur; cur = cur->m_left)
			{
				st.push(cur);
				tag.push(false);
			}
			while (!st.empty() && tag.top())
			{
				cur = st.top();
				cout << cur->m_val;
				st.pop();
				tag.pop();

				cur = nullptr;
			}
			if (!st.empty())
			{
				tag.top() = true;
				cur = st.top();
				cur = cur->m_right;
			}

		}
	}
	//两个数的公共祖先  后序
	TreeNode<T> * lowestCommonAncestor(TreeNode<T> * p, TreeNode<T> * q)
	{
		TreeNode<T>* cur = m_root;
		stack<TreeNode<T> *> st;
		stack<bool> tag;

		stack<TreeNode<T> *> res1;
		stack<TreeNode<T> *> res2;

		while (cur || !st.empty())
		{
			for (; cur; cur = cur->m_left)
			{
				st.push(cur);
				tag.push(false);
			}
			while (!st.empty() && tag.top())
			{
				cur = st.top();
				if (cur == p || cur == q)
				{
					if (res1.empty)
					{
						res1 = st;
					}
					else
					{
						res2 = st;
					}
				}
				st.pop();
				tag.pop();

				cur = nullptr;
			}
			if (!st.empty())
			{
				tag.top() = true;
				cur = st.top();
				cur = cur->m_right;
			}
		}
		if (res1.size() < res2.size())
		{
			swap(res1, res2);
		}

		int i = res1.size() - res2.size();

		for (; i > 0; i--)
		{
			res1.pop();
		}

		while (res1.top() != res2.top())
		{
			res1.pop();
			res2.pop();
        }
        
		return res1.top();
	}
		
	//两个数的公共祖先 中序	
	TreeNode<T> * lowestCommonAncestori(TreeNode<T> * p, TreeNode<T> * q)
    {
			TreeNode<T> * cur = m_root;
			stack<TreeNode<T> *> st;
			TreeNode<T> * tmp = nullptr;
			size_t stsize = 0;//栈的大小

			while (cur || !st.empty())
			{
    			for (; cur; cur = cur->m_left)
				{
					st.push(cur);
				}


				if (!st.empty())
				{
					cur = st.top();

					if (stsize > st.size())
					{
						tmp = cur;
						stsize = st.size();
					}

					if (cur == p || cur == q)
					{
						if (!tmp)
						{
							tmp = cur;
							stsize = st.size();
						}
						else
						{
							return tmp;
						}
					}

					st.pop();
  				    cur = cur->m_right;
				}
			}
			return nullptr;
		}

		void test()
		{
			TreeNode<T> * t = lowestCommonAncestori(m_root->m_right->m_left->m_right, m_root->m_right);
     		cout << t->m_val;
		}

		void level_order()
		{
			queue<TreeNode<T> *> qu;
			TreeNode<T> * tmp;

			qu.push(m_root);

			while (!qu.empty())
			{
				tmp = qu.front();
				cout << tmp->m_val << ' ';
				qu.pop();

				if (tmp->m_left)
				{
					qu.push(tmp->m_left);
				}

				if (tmp->m_right)
				{
					qu.push(tmp->m_right);
				}
			}
		}

		void everyline_level_order()
		{
			queue<TreeNode<T> *> qu;
			TreeNode<T> * tmp;
			int length = 1;

			qu.push(m_root);

			while (!qu.empty())
			{
				for (int i = 0; i < length; i++)
				{
					tmp = qu.front();
					cout << tmp->m_val << ' ';
					qu.pop();

					if (tmp->m_left)
					{
						qu.push(tmp->m_left);
					}

					if (tmp->m_right)
					{
						qu.push(tmp->m_right);
					}
				}
				cout << endl;
				length = qu.size();
			}
		}

		void max_level_order()
		{
			queue<TreeNode<T> *> qu;
			TreeNode<T> * tmp;
			int length = 1;
			T max;

			qu.push(m_root);

			while (!qu.empty())
			{
				max = qu.front()->m_val;
				for (int i = 0; i < length; i++)
				{
					tmp = qu.front();

					if (max < tmp->m_val)
					{
						max = tmp->m_val;
					}
					qu.pop();

					if (tmp->m_left)
					{
						qu.push(tmp->m_left);
					}

					if (tmp->m_right)
					{
						qu.push(tmp->m_right);
					}
				}
				cout << max << ' ';
				length = qu.size();
			}
		}


		//二叉树镜像，从下往上层序遍历交换左右节点
};
  





/*

#include"10.15binarytree.h"

int main()
{
	Tree<char> tr("ABD##E##CFH##I##G##", '#');

	tr.pre_order();
	cout << endl;
	tr.in_order();
	cout << endl;

	tr.post_order();
	cout << endl;
	tr.test();
	tr.level_order();
	cout << endl;
	tr.everyline_level_order();


	return 0;
}
*/