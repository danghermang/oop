#include "Matrice.h"
#include <iostream>
using namespace std;
Matrice::Matrice() {
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			this->Matrix[i][j] = 0;
}
Matrice::Matrice(int **array) {
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			this->Matrix[i][j] = array[i][j];
}
Matrice::Matrice(const Matrice &altaMatrice) {
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			this->Matrix[i][j] = altaMatrice.Matrix[i][j];
}
bool Matrice::Set(int **matrix) {
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			this->Matrix[i][j] = matrix[i][j];
	return 1;
}
void Matrice::Print() {
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
			cout << this->Matrix[i][j] << " ";
		cout << endl;
	}
}
Matrice Matrice::operator-(const Matrice &operand) {
	Matrice out;
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			out.Matrix[i][j] = this->Matrix[i][j] - operand.Matrix[i][j];
	return out;
}
Matrice Matrice::operator+(const Matrice &operand) {
	Matrice out;
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			out.Matrix[i][j] = this->Matrix[i][j] + operand.Matrix[i][j];
	return out;
}
Matrice Matrice::operator*(const Matrice &operand) {
	Matrice out;
	int a;
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
		{
			a = 0;
			for (int q = 0;j < 3;q++)
				a += this->Matrix[i][q] * operand.Matrix[q][j];
			out.Matrix[i][j] = a;
		}
	return out;
}
Matrice operator!(const Matrice &matrice) {
	Matrice out;
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			out.Matrix[i][j] = matrice.Matrix[j][i];
	return out;
}
int operator~(const Matrice &matrice) {
	int out;
	out = matrice.Matrix[0][0] * matrice.Matrix[1][1] * matrice.Matrix[2][2] + matrice.Matrix[1][0] * matrice.Matrix[2][1] * matrice.Matrix[0][2] + matrice.Matrix[0][1] * matrice.Matrix[1][2] * matrice.Matrix[2][0];
	out = out - (matrice.Matrix[0][2] * matrice.Matrix[1][1] * matrice.Matrix[2][0] + matrice.Matrix[0][0] * matrice.Matrix[1][2] * matrice.Matrix[2][1] + matrice.Matrix[0][1] * matrice.Matrix[1][0] * matrice.Matrix[2][2]);
	return out;
}
Matrice:: bool &operator==(const Matrice&operand1, const Matrice &operand2) {
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			if (operand1.Matrix[i][j] != operand2.Maatrix[i][j])
				return 0;
	return 1;
}