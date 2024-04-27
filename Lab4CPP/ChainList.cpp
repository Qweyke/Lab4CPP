#include "ChainList.h"

ChainList::Node::Node() : Data(0), Next(nullptr) {}
ChainList::Node::Node(int data) : Data(data), Next(nullptr) {}

ChainList::ChainList()
{
	head = nullptr;
	cr_count++;
}
ChainList::~ChainList()
{
	Clear();
	des_count++;
}

ChainList::Node* ChainList::Find(int posit)
{
	if (posit >= count || head == nullptr) return nullptr;

	int i = 0;
	Node* P = head;

	while (P != nullptr && i < posit)
	{
		P = P->Next;
		i++;
	}

	if (i == posit) return P;
	else return nullptr;
}

BaseList* ChainList::Dummy()
{
	return new ChainList;
}

int& ChainList::operator[] (int i)
{
	static int invalid_index = 0;
	if (i >= count || i < 0) return invalid_index;
	Node* found = Find(i);
	return found->Data;
}

void ChainList::Add(int value)
{
	if (head == nullptr)
	{
		head = new Node(value);
	}

	else
	{
		Node* last = Find(count - 1);
		last->Next = new Node(value);

	}
	count++;
}
void ChainList::Insert(int value, int posit)
{
	if (posit == count && posit == 0) Add(value);

	else if (posit == count) Add(value);

	else if (posit < count)
	{
		if (posit == 0)
		{
			Node* head_temp = head;
			head = new Node(value);
			head->Next = head_temp;
			count++;
		}

		else
		{
			Node* prev = Find(posit - 1);
			Node* curr = Find(posit);
			Node* insr = new Node(value);
			insr->Next = curr;
			prev->Next = insr;
			count++;
		}
	}
}
void ChainList::Delete(int posit)
{
	if (posit < count && posit > 0)
	{
		Node* prev = Find(posit - 1);
		Node* current = prev->Next;
		if (current->Next != nullptr)
		{
			prev->Next = current->Next;
			delete current;
		}
		else
		{
			prev->Next = nullptr;
			delete current;
		}
		count--;
	}

	else if (posit == 0 && posit < count)
	{
		Node* head_temp = head->Next;
		delete head;
		head = head_temp;
		count--;
	}

	else if (posit == 0 && count == 1)
	{
		head = nullptr;
		count--;
	}
}
void ChainList::Clear()
{
	while (head != nullptr)
	{
		Node* head_temp = head;
		head = head->Next;
		delete head_temp;
	}
	count = 0;
}
void ChainList::Show()
{
	Node* cur = head;
	if (cur != nullptr)
	{
		while (cur->Next != nullptr)
		{
			std::cout << cur->Data << "; ";
			cur = cur->Next;
		}
		std::cout << cur->Data << ". ";
	}
	else std::cout << ("Нет элементов в array листе");
	std::cout << "\n\n";
}
void ChainList::Sort()
{
	if (count == 0 || count == 1) { return; }

	bool swap;
	do
	{
		swap = false;
		Node* curr = head;
		for (int i = 0; i < count - 1; i++)
		{
			if (curr->Data < curr->Next->Data)
			{
				int temp = curr->Data;
				curr->Data = curr->Next->Data;
				curr->Next->Data = temp;
				swap = true;
			}
			curr = curr->Next;
		}
	} while (swap);
}