class IntList {
private:
	int Elemente[1000];
	int Count;
public:
	IntList(); //Constructor implicit
	bool Add(int element); //returneaza false daca lista este plina(peste 100 de elemente)
	bool Insert(int index, int element);
	bool Delete(int index);
	void Clear();
	int IndexOf(int valoare, int StartPosition); // indexul pozitiei unei valori sau "-1" in caz contrar
	void RemoveDuplicates();
	void Intersection(IntList* withList, IntList * resultList);
	void Sort();
	void Reverse();
	int Get(int index);//returneaza elementul de pe pozitia index sau -1 in caz contrar
	int GetCount();
};