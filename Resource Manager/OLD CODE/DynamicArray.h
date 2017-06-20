#pragma once

template <class T>
class DynamicArray
{
public:
	DynamicArray<T>(int capacity = 1)
	{
		m_capacity = capacity;
		m_array = new T[m_capacity];
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

	void popback()
	{
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

	~DynamicArray() {}

private:

	T*		m_array;
	int		m_capacity;
	int		m_size = 0;

};

