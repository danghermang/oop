#include <iostream>
#include "Matrice.h"
using namespace std;
int main(void)
{
	int A[3][3] = { {1,0,0},{0,1,0} ,{0,0,1} };
	int B[3][3] = { { 1,0,0 },{ 0,1,0 } ,{ 0,0,1 } };
	int C[3][3] = { { 1,0,0 },{ 0,1,0 } ,{ 0,0,1 } };
	Matrice M1, M2(A), M3(M2), M4, M5, M6;
	M4.Set(A);
	M4.Print();
	M1 = B;
	M4 = M1 + M2;
	M1.Print();
	M2.Print();
	M3.Print();
	M4.Print();
	M5 = B - C;
	M6 = M4*B;
	C = !B;
	C.Print();
	int det = ~M6;
	cout << "Determinant M6=" << det << endl;
	int Y[3][3] = { {2,2,2},{-1,1,4},{2,1,6} };
	M1.Set(Y);
	M2 = B - M1;
	if (M2 == A)
		cout << "identice" << endl;
	else
		cout << "diferite" << endl;
	return 0;




}