#include "ArrayList.h"

ArrayList::ArrayList() : size(1)
{
	buf = new int[size];
	cr_count++;
}
ArrayList::~ArrayList()
{
	delete[] buf;
	des_count++;
}

void ArrayList::Expd()
{
	size *= 2;
	int* new_buf = new int[size];
	for (int i = 0; i < size / 2; i++)
	{
		new_buf[i] = buf[i];
	}
	delete[] buf;
	buf = new_buf;
}

BaseList* ArrayList::Dummy()
{
	return new ArrayList;
}

int& ArrayList::operator[] (int i)
{
	static int invalid_index = 0;
	if (i >= count || i < 0) return invalid_index;
	return buf[i];
}

void ArrayList::Add(int val)
{
	if (count >= size) { Expd(); }
	buf[count] = val;
	count++;

}

void ArrayList::Insert(int val, int pos)
{
	if (pos == count && pos == 0) Add(val);

	else if (pos == count) Add(val);

	else if (pos < count)
	{
		count++;
		if (count >= size) Expd();

		for (int i = count - 1; i != pos; i--)
		{
			buf[i] = buf[i - 1];
		}
		buf[pos] = val;
	}
}

void ArrayList::Delete(int pos)
{
	if (pos < count)
	{
		for (int i = pos; i < count - 1; i++)
		{
			buf[i] = buf[i + 1];
		}
		count--;
	}

	else if (pos == count - 1 && count > 0)
	{
		buf[pos] = 0;
		count--;
	}
}

void ArrayList::Clear()
{
	for (int i = 0; i < count; i++)
	{
		buf[i] = 0;
	}
	count = 0;
}

void ArrayList::Show()
{
	if (count >= 0)
	{
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1) std::cout << buf[i] << ". ";
			else std::cout << buf[i] << ", ";
		}
	}
	else std::cout << ("Нет элементов в array листе");
	std::cout << "\n\n";
}