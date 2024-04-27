#pragma once
#include <iostream>
#include "BaseList.h"

class ChainList : public BaseList
{
private:
	class Node
	{
	public:
		int Data;
		Node* Next;

		Node();
		Node(int data);
	};

	Node* head;
	Node* Find(int posit);

protected:
	BaseList* Dummy() override;

public:
	ChainList();
	~ChainList() override;

	int& operator[] (int i);
	void Add(int value) override;
	void Insert(int value, int posit) override;
	void Delete(int posit) override;
	void Clear() override;
	void Show() override;
	void Sort() override;
};