#pragma once
#include <iostream>

class BaseList
{
protected:
	int count = 0;
	static int cr_count;
	static int des_count;
	virtual BaseList* Dummy() = 0;
public:
	int Count() const;
	static int CrCount();
	static int DesCount();
	virtual ~BaseList() {};

	virtual void Add(int val) = 0;
	virtual void Delete(int pos) = 0;
	virtual void Insert(int val, int pos) = 0;
	virtual void Clear() = 0;
	virtual void Show() = 0;
	virtual int& operator[](int i) = 0;

	void Assign(BaseList& source);
	void AssignTo(BaseList& dest);
	BaseList* Clone();
	virtual void Sort();
	bool IsEqual(BaseList& list);
};