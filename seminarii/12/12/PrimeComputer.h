#pragma once
#include "Computer.h"
#include <iostream>
#include<math.h>
using namespace std;
class PrimeComputer :virtual public Computer{
public:
	void Run();
private:
	long ComputePrime(long number);
	bool CheckPrime(long x);
};