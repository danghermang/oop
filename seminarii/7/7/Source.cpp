#include "Header.h"

template <class e1,e2>
int Compare::CompareElements(void *e1, void *e2) {
	if (e1.Current == e2.Current)
		return 0;
	if (e1.Current > e2.Current)
		return 1;
	else
		return -1;
}
template<class T>
ArrayIterator::ArrayIterator() {
	this->Current = 0;
	this->iterator* = NULL;
}
template <class T>
ArrayIterator::ArrayIterator& operator++ () {
	ArrayIterator arriter;
	arriter.Current = this->Current + 1;
	arriter.iterator = this->iterator + 1;
	return arriter;
}
template <class T>
ArrayIterator::ArrayIterator& operator-- () {
	ArrayIterator arriter;
	arriter.Current = this->Current - 1;
	arriter.iterator = this->iterator - 1;
	return arriter;
}
template <class T>
bool ArrayIterator::operator= (ArrayIterator<T> &comparant) {
	this->Current = comparant.Current;
	*this->iterator = *comparant.iterator;
}
template <class T>
bool ArrayIterator::operator==(ArrayIterator<T> &comparant) {
	if (this->Current == comparant.Current)
		if (*this->iterator == *comparant.iterator)
			return 1;
	return 0;
}
template <class T>
bool ArrayIterator::operator!=(ArrayIterator<T> &comparant) {
	if (this->Current != comparant.Current)
		if (*this->iterator != *comparant.iterator)
			return 1;
	return 0;
}
template <class T>
T* ArrayIterator::GetElement() {
	return *this->iterator;
}
template <class T>
Array::Array()
{
	this->*List = NULL;
	this->Capacity = 0;
	this->Size = 0;
}
template <class T>
Array::Array(int capacity) {
	this->Capacity = capacity;
	this->Size = capacity;
	for (int it = 0;it < capacity;it++)
		this->(*List)[it] = 0;
}

template <class T>
Array::Array(const Array<T> &otherArray) {
	this->Capacity = otherArray.Capacity;
	this->Size = otherArray.Size;
	for (T it = otherArray.begin();it != otherArray.end();it++)
		this->*List[*it] = otherArray.*List[*it];
}


T Array::&operator[] (int index) {
	
}// arunca exceptie daca index este out of range



const Array<T>& operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this

const Array<T>& Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie



bool operator=(const Array<T> &otherArray);



void Sort(); // sorteaza folosind comparatia intre elementele din T

void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie

void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie



								// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

int BinarySearch(const T& elem); // cauta un element folosind binary search in Array

int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie

int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator



int Find(const T& elem); // cauta un element in Array

int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie

int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator



int GetSize();

int GetCapacity();



ArrayIterator<T> GetBeginIterator();

ArrayIterator<T> GetEndIterator();