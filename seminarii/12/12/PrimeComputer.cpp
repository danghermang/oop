#include "PrimeComputer.h"

long PrimeComputer::ComputePrime(long number) {
	long count = 1;
	long nr=3;
	if (number == 1)
		return 2;
	while (count != number)
	{
		if (CheckPrime(nr) == 1)
			count++;
		nr = nr + 2;;
	}
	return nr - 2;
}
bool PrimeComputer::CheckPrime(long x) {
	if (x < 2)
		return 0;
	if (x > 2 && x % 2 == 0)
		return 0;
	for (long it = 3;it < sqrt(x);it++)
		if (x%it == 0)
			return 0;
	return 1;
}