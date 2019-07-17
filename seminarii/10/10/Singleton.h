#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;
class Singleton {

private:
	Singleton() {
			Singleton::count++;
	}
	
public:
	static Singleton *p;
	static int count;
	static Singleton* getInstance() {
		if (Singleton::p == 0)
			Singleton::p = new Singleton();
		return p;
	};
	void FirstSingleton()
	{
		Singleton::p = 0;
	}
	void SetCount(int count) {
		Singleton::count = count;
	}
};

int Singleton::count = 0;
Singleton *Singleton::p = 0;