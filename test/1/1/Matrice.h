#pragma once
class Matrice {
private:
	int Matrix[3][3];
public:
	Matrice();
	Matrice(int **array);
	Matrice(const Matrice &altaMatrice);

	bool Set(int **matrix);
	void Print();
	Matrice operator-(const Matrice &operand);
	Matrice operator+(const Matrice &operand);
	Matrice operator*(const Matrice &operand);

	friend Matrice operator!(const Matrice &matrice);
	friend int operator~(const Matrice &matrice);
	friend bool operator==(const Matrice &operand1, const Matrice &operand2);
	Matrice &operator=(Matrice &);
	Matrice &operator=(int **);
};