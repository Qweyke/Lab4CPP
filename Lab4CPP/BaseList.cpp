#include "BaseList.h"

int BaseList::cr_count = 0;
int BaseList::des_count = 0;

int BaseList::Count() const { return count; }
int BaseList::CrCount() { return cr_count; }
int BaseList::DesCount() { return des_count; }

void BaseList::Assign(BaseList& source)
{
	Clear();
	for (int i = 0; i < source.Count(); i++) Add(source[i]);
}

void BaseList::AssignTo(BaseList& dest)
{
	dest.Assign(*this);
}

BaseList* BaseList::Clone()
{
	BaseList* clone = Dummy();
	clone->Assign(*this);
	return clone;
}

void BaseList::Sort()
{
	if (this->Count() == 0 || this->Count() == 1) { return; }

	int pstn = 0;
	while (pstn < this->Count() - 1)
	{
		if ((*this)[pstn] >= (*this)[pstn + 1])
		{
			pstn++;
		}

		else
		{
			int temp = (*this)[pstn + 1];
			(*this)[pstn + 1] = (*this)[pstn];
			(*this)[pstn] = temp;

			if (pstn > 0) pstn--;
		}
	}
}

bool BaseList::IsEqual(BaseList& list)
{
	if (this->Count() > 0)
	{
		for (int i = 0; i <= this->Count(); i++)
		{
			if ((*this)[i] != list[i]) return false;
		}
		return true;
	}
	else if (this->Count() == 0) return true;
	else return false;
}