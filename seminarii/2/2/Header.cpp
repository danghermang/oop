#include "Header.h";

IntList::IntList() {
	Count = 0;
	for (int i = 0;i < 999;i++)
		Elemente[i] = 0;
}
bool IntList::Add(int element) {
	if (Count >= 999)
		return false;
	Elemente[Count] = element;
	Count++;
	return true;
}
bool IntList::Insert(int index, int element)
{
	if (Count + 1 < index || Count >= 999)
		return false;
	for (int i = Count + 1;i > index;i++)
		Elemente[i] = Elemente[i - 1];
	Elemente[index] = element;
	Count++;
	return true;
}
bool IntList::Delete(int index) {
	if (Count <= 0)
		return false;
	for (int i = index;i < Count;i++)
		Elemente[i] = Elemente[i + 1];
	Elemente[Count] = 0;
	Count--;
	return true;
}
void IntList::Clear() {
	for (int i = 0;i < Count;i++)
		Elemente[i] = 0;
	Count = 0;
}
int IntList::IndexOf(int valoare, int startPosition) {
	int check = -1;
	for (int i = startPosition;i < Count;i++)
		if (Elemente[i] == valoare)
			check = i;
	return check;
}
void IntList::RemoveDuplicates() {
	for (int i = 0;i < Count - 1;i++)
		for (int j = i + 1;j < Count;j++)
			if (Elemente[i] == Elemente[j])
				Delete(j);
}
void IntList::Sort() {
	int aux;
	for (int i = 0;i < Count-1;i++)
		for (int j = i + 1;j < Count;j++)
			if (Elemente[j] < Elemente[i])
			{
				aux = Elemente[i];
				Elemente[i] = Elemente[j];
				Elemente[j] = aux;
			}
}
void IntList::Reverse() {
	for (int i = 0;i < Count;i++)
		Insert(i, Elemente[Count-1]);
}
int IntList::Get(int index) {
	return Elemente[index];
}
int IntList::GetCount() {
	return Count;
}
void IntList::Intersection(IntList* withList, IntList * resultList) {
	int i = 0;
	resultList->RemoveDuplicates();
	withList->RemoveDuplicates();
	withList->Sort();
	resultList->Sort();
	while (resultList->Count<1000 && resultList->IndexOf(withList->Elemente[i],0))
	{
		resultList->Add(withList->Elemente[i]);
			i++;
	}
}