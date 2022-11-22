#pragma once

#include "Common.h"

template <class T>
class StaticArray
{
public:
	StaticArray(int size = 0)
	{
		count = size;
		if (size > 0)
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] = T();
			}
		}
	}

	void Add(T newVal)
	{
		if (count < SIZE)
		{
			arr[count++] = newVal;
		}
	}

	void Delete(int index)
	{
		if (index < 0 || index >= count)
		{
			return;
		}
		count--;
		
		for (int i = index; i < count; i++)
		{
			arr[i] = arr[i + 1];
		}
	}

	T& operator[](int index)
	{
		if (index < 0 || index >= count)
		{
			throw 0;
		}
		return arr[index];
	}

	int Find(const T& val)
	{
		for (int i = 0; i < count; i++)
		{
			if (arr[i] == val)
			{
				return i;
			}
		}
		return -1;
	}

	int Size()
	{
		return count;
	}

private:
	T arr[SIZE];
	int count;
};