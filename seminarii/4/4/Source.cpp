#include <iostream>
#include "Header.h"
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

Dreptunghi::Dreptunghi(int lungime, int latime) {
	Latime = latime;
	Lungime = Lungime;
}
double Dreptunghi::ComputeArea() {
	return Lungime*Latime;
}
const char* Dreptunghi::GetName() {
	return "Dreptunghi";
}
Cerc::Cerc(int raza) {
	Raza = raza;
}
double Cerc::ComputeArea() {
	return atan(1)*4*Raza*Raza;
}
const char *Cerc::GetName() {
	return "Cerc";
}
Triunghi::Triunghi(int x1, int y1, int x2, int y2, int x3, int y3) {
	X1 = x1;
	X2 = x2;
	X3 = x3;
	Y1 = y1;
	Y2 = y2;
	Y3 = y3;

}
double Triunghi::ComputeArea() {
	double p1, p2, p3, p;
	p1 = sqrt(pow(X1 - X2, 2) + pow((Y1 - Y2), 2));
	p2 = sqrt(pow(X1 - X3, 2) + pow((Y1 - Y3), 2));
	p3 = sqrt(pow(X3 - X2, 2) + pow((Y3 - Y2), 2));
	p = (p1 + p2 + p3) / 2;
	return sqrt(p*(p - p1)*(p - p2)*(p - p3));
}
const char *Triunghi::GetName() {
	return "Triunghi";
}