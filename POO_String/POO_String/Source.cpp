#include <iostream>
#include <stdio.h>
#include "String.h"
#pragma warning(disable:4996)
using namespace std;


int main()
{
	String s1("azi");
	String s2("Am examen ");
	printf("%d %c\n", (int)s2, s2[0]);
	String s;
	s = s2 & s1;
	s = s & "!";
	printf("Caractere a = %d\n", (s | 'a'));
	printf("!s = %s\n", (char*)(!s));
	cin.get();
}