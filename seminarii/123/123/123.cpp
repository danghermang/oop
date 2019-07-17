// 123.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int x = 10, y = 10;

	int &a = x;
	x += y;
	y += x;
	&a = x;
	x += y;
	y += x;

	}
}

