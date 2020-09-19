#pragma once

template<class T>
class SFVector
{
public:
	SFVector(int i)
	{
		_mas = new T[i];
		_count = i;
	}
	~SFVector()
	{
		delete this;
		delete[] _mas;
	}
	VOID pushBack(T item)
	{
		static int j = -1;

		if (j == _count) return;

		j++;

		_mas[j] = item;
	}

	INT getSize()
	{
		return _count;
	}
	T& operator[](int i)
	{
		return _mas[i];
	}
	VOID insert(int i, T value)
	{
		_mas[i] = value;
	}
	VOID remove(int i)
	{
		for (int j = i; j < _count; ++j) {

			_mas[j] = _mas[j + 1];
		}
		--_count;
	}
private:
	INT _count;
	T* _mas;
};