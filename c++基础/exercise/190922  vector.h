#pragma once



namespace vec
{
	template <class T>
	class vector
	{
		T * m_start;
		T * m_finish;
		T * m_endOfStorage;
	public:
		typedef T * iterator;
		typedef const T * const_iterator;

		vector() :
			m_start(nullptr),
			m_finish(nullptr),
			m_endOfStorage(nullptr)
		{

		}


		vector(int n, const T &val = T()) :
			m_start(nullptr),
			m_finish(nullptr),
			m_endOfStorage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				m_start[i] = val;
			}
			m_finish = m_start + n;
		}


		vector(T * start, T * end) :
			m_start(nullptr),
			m_finish(nullptr),
			m_endOfStorage(nullptr)
		{
			int _size = end - start;
			reserve(_size);

			for (int i = 0; i < _size; i++)
			{//��һ��ȫ��ǳ���������Բ�����memcpy
				m_start[i] = start[i];
			}
			m_finish = m_start + _size;
		}


		iterator begin()
		{
			return m_start;
		}


		iterator end()
		{
			return m_finish;
		}


		size_t size()
		{
			return m_finish - m_start;
		}


		size_t capacity()
		{
			return m_endOfStorage - m_start;
		}


		T & operator [] (int i)
		{
			return m_start[i];
		}

		const T & operator [] (int i) const
		{
			return m_start[i];
		}

		void reserve(size_t _size)
		{
			int _capacity = capacity();
			if (_capacity < _size)
			{
				if (_capacity == 0)
				{
					_capacity = 1;
				}

				while (_capacity < _size)
				{
					_capacity *= 2;
				}
			}

			T * tmp = new T[_capacity];
			m_endOfStorage = tmp + _capacity;
			int oldsize = size();
			m_finish = tmp + oldsize;
			if (m_start != nullptr)
			{
				for (int i = 0; i < oldsize; i++)
				{
					tmp[i] = m_start[i];
				}
				delete[] m_start;
			}
			m_start = tmp;
		}

		void resize(size_t _size,const T &val=T())
		{
			reserve(_size);
			for (int i = size(); i < _size:i++)
			{
				m_start[i] = val;
			}
			m_finish = m_start + size;
		}
		
		//��ֹ������ʧЧ�����ص�����
		iterator insert(iterator pos, const T &val)
		{
			int tmp = pos - m_start;
			reserve(size() + 1);//����resize()��m_finish��ֱ�Ӽ�
			pos = m_start + tmp;//��֤pos��λ�ò����ı�
			int i;
			for (i = size()-1, i > pos - m_start; i--)//��ΪҪ�õ�pos��ֵ����pos��ָ��
			{
				m_start[i+1] = m_start[i];
			}
			*pos = val;
			m_finish++;
			return pos;
		}
	
		iterator insert(iterator pos,int n, const T &val)
		{
			int tmp = pos - m_start;
			reserve(size() + n);
			pos = m_start + tmp;
			int i;
			for (i = size()-1, i >= pos - m_start; i--)
			{
				m_start[i+n] = m_start[i];
			}
			for (i = 0; i < n; i++)
			{
				pos[i] = val;
			}
			m_finish+=n;
			return pos;
		}

	
		iterator insert(iterator pos, const T* start , const T* end)
		{
			int tmp = pos - m_start;
			int extsize = end - start;
			reserve(size() + extsize);
			pos = m_start + tmp;
			int i;
			for (i = size() - 1; i >= pos-m_start; i--)
			{
				m_start[i + extsize] = m_start[i];
			}
			for (i = 0; i < extsize; i++)
			{
				pos[i] = start[i];
			}
			m_finish += extsize;
			return pos;
		}

	
		iterator erase(iterator pos)
		{
			int i;

			for (i = pos - m_start; i < size() - 1; i++)
			{
				m_start[i] = m_start[i + 1];
			}
			m_finish--;

			return pos;
		}

		iterator erase(iterator start, iterator end)
		{
			int i;
			int extsize = end - start;

			for (i = start - m_start; i < size() - extsize; i++)
			{
				m_start[i] = m_start[i + extsize];
			}
			m_finish -= extsize;

			return start;
		}



		void push_back(const T &val)
		{
			reserve(size() + 1);
			*m_finish = val;
			m_finish++;
		}

		void pop_back()
		{
			//�п�
			m_finish--;
		}

	};
};




/*
int main()
{
	int a[] = { 2, 3, 4, 5 };
	vec::vector<int> v2(a, a + 4);
	vec::vector<int> v(v2.begin(), v2.end());

	v.insert(v.begin() + 2, a + 1, a + 3);

	v.erase(v.begin() + 2, v.end() - 1);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	//cout << v.size();
	return 0;
}

*/