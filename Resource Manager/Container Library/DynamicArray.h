#pragma once

template <class T>
class DynamicArray
{
public:

	typedef T* iterator;

	DynamicArray<T>(int capacity = 1)
	{
		m_capacity = capacity;
		m_array = new T[m_capacity];
	}

	DynamicArray<T>(const DynamicArray &obj)
	{
		m_capacity = obj.m_capacity;
		m_size = obj.m_size;
		m_array = new T[m_capacity];
		for (int i = 0; i < m_capacity; i ++)
		{
			m_array[i] = obj.m_array[i];
		}
	}

	void operator=(DynamicArray<T> other)
	{
		if (this != other)
		{
			T* tempArray = new T[other.m_capacity];
			for (int i = 0; i < other.m_capacity; i++)
			{
				tempArray[i] = other[i];
			}
			delete[] m_array;
			m_array = tempArray;
			m_capacity = other.m_capacity;
			m_size = other.m_size;
		}
	}

	T& operator[](int x) 
	{ 
		return m_array[x];
	}


	int size()
	{
		return m_size;
	}

	void pushBack(T element)
	{
		m_size ++;
		if (m_size > m_capacity)
			expandArray(1);
		m_array[m_size-1] = element;
	}

	void popBack()
	{
		m_size--;
	}

	void erase(int element)
	{
		int amountToMove = m_size - element;
		for (int i = element; i < m_size-1; i++)
		{
			m_array[i] = m_array[i + 1];
		}
		m_size--;
	}

	void expandArray(int amount)
	{
		m_capacity += amount;
		T* tempArray = new T[m_capacity];
		for (int i = 0; i < m_size-1; i ++)
		{
			tempArray[i] = m_array[i];
		}
		delete[] m_array;
		m_array = tempArray;
	}

	void resize(int amount)
	{
		m_capacity = amount;
	}

	bool empty()
	{
		return (m_size == 0);
	}

	void clear()
	{
		m_size = 0;
	}

	iterator begin() { return m_array; }

	iterator end() { return m_array + m_size; }

	virtual ~DynamicArray() {}

protected:

	T*		m_array;
	int		m_capacity;
	int		m_size = 0;

};

