#pragma once
#include <iostream>
#include "BaseList.h"

class ArrayList : public BaseList
{
private:
	int size;
	int* buf;
	void Expd();

protected:
	BaseList* Dummy() override;

public:
	ArrayList();
	~ArrayList() override;

	int& operator[] (int i);
	void Add(int val) override;
	void Insert(int val, int pos) override;
	void Delete(int pos) override;
	void Clear() override;
	void Show() override;
};