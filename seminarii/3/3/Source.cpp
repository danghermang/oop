#include "Header.h"
#include <iostream>
#include <cstring>
using namespace std;
BigNumber::BigNumber() {
	CharactersCount = 0;
	for (int i = 0;i < 256;i++)
		Number[i] = '0';
}
BigNumber::BigNumber(int value) {
	itoa(value, Number, 10);
	for (int a = value;a != 0;a = a / 10)
		CharactersCount++;
}
BigNumber::BigNumber(const char * number) {
	CharactersCount = strlen(number);
	memcpy(Number, number, CharactersCount);
}

bool BigNumber::Set(int value) {
	itoa(value, Number, 10);
	for (int a = value;a != 0;a = a / 10)
		CharactersCount++;
	return true;
}

bool BigNumber::Set(const char * number) {
	CharactersCount = strlen(number);
	memcpy(Number, number, CharactersCount);
	return true;
}



BigNumber BigNumber::operator+ (const BigNumber & number) {
	BigNumber answer;
	int i;
	for (i = 0;i != CharactersCount && i != number.CharactersCount;i++)
	{
		int k = (Number[i] - '0') + (number.Number[i] - '0');
		if (k < 10)
			answer.Number[i] += k + '0';
		else
		{
			answer.Number[i] += k % 10 + '0';
			answer.Number[i + 1] += k / 10 + '0';
		}
		if (answer.Number[i] > '9') {
			answer.Number[i] -= 10;
			answer.Number[i + 1]++;
		}
	}
	answer.CharactersCount = i;
	return answer;
}

BigNumber BigNumber::operator* (const BigNumber & number) {
	BigNumber answer;
	int i;
	for (i = 0;i != CharactersCount && i != number.CharactersCount;i++)
	{
		int k = (Number[i] - '0') * (number.Number[i] - '0');
		if (k < 10)
			answer.Number[i] += k + '0';
		else
		{
			answer.Number[i] += k % 10 +'0';
			answer.Number[i + 1] += k / 10 + '0';
		}
		while (answer.Number[i]>'9')
		{
			answer.Number[i] -= 10;
			answer.Number[i + 1]++;
		}
	}
	answer.CharactersCount = i;
	return answer;
}

BigNumber BigNumber::operator- (const BigNumber & number) {
	BigNumber answer;
	for (int i = 0;i != CharactersCount && i != number.CharactersCount;i++)
	{
		int k = (Number[i] - '0') - (number.Number[i] - '0');
		if (k >= 0)
			answer.Number[i] += k;
		else
		{
			answer.Number[i] += k + 10;
			int q = i + 1, ok = 0;
			while (q < CharactersCount && q < number.CharactersCount && ok == 0)
			{
				if (Number[q]>'0')
				{
					ok = 1;
					answer.Number[q]--;
				}
				else q++;
			}
			if (CharactersCount >= number.CharactersCount)
			{
				if (q == CharactersCount)
					answer.Number[i + 1] = '-';
			}
			else
				if (q == number.CharactersCount)
					answer.Number[i + 1] = '-';
		}
	}
}

BigNumber BigNumber::operator/ (const BigNumber & number) {
	BigNumber answer;
	int i=number.CharactersCount,k=0,j=0;
	while (i < CharactersCount)
	{
		for (int q = i;
	}

	
}


bool operator == (const BigNumber & n1, const BigNumber & n2) {
	if (n1.CharactersCount != n2.CharactersCount)
		return false;
	for (int i = 0;i < n1.CharactersCount;i++)
		if (n1.Number[i] != n2.Number[i])
			return false;
	return true;
}

bool operator != (const BigNumber & n1, const BigNumber & n2) {
	if (n1.CharactersCount != n2.CharactersCount)
		return true;
	for (int i = 0;i < n1.CharactersCount;i++)
		if (n1.Number[i] == n2.Number[i])
			return false;
	return true;
}

bool operator <  (const BigNumber & n1, const BigNumber & n2) {
	if (n1.CharactersCount < n2.CharactersCount)
		return true;
	for (int i = 0;i < n1.CharactersCount;i++)
		if (n1.Number[i] >= n2.Number[i])
			return false;
	return true;
}

bool operator >  (const BigNumber & n1, const BigNumber & n2) {
	if (n1.CharactersCount > n2.CharactersCount)
		return true;
	for (int i = 0;i < n2.CharactersCount;i++)
		if (n1.Number[i] <= n2.Number[i])
			return false;
	return true;
}

bool operator >= (const BigNumber & n1, const BigNumber & n2) {
	if (n1.CharactersCount >= n2.CharactersCount)
		return true;
	for (int i = 0;i < n2.CharactersCount;i++)
		if (n1.Number[i] < n2.Number[i])
			return false;
	return true;
}

bool operator <= (const BigNumber & n1, const BigNumber & n2) {
	if (n1.CharactersCount <= n2.CharactersCount)
		return true;
	for (int i = 0;i < n1.CharactersCount;i++)
		if (n1.Number[i] > n2.Number[i])
			return false;
	return true;
}
/*
BigNumber::operator const int() {

}*/
char BigNumber::operator[] (int index) {
	if (index >= 0 && index < 256)	return Number[index];
	return '/0';
}// returneaza caracterul de pe pozitia index sau \0 in rest
BigNumber BigNumber::operator() (int start, int end) {
	BigNumber answer;
	answer.CharactersCount = 0;
	if (start >= 0 && start < 256 && end >= 0 && end < 256)
	{
		for (int i = start;i < end;i++, answer.CharactersCount++)
			answer.Number[answer.CharactersCount] = Number[i];
		return answer;
	}
	return 0;
}// returneaza subnumarul de la caracterul start pana la caracterul index sau "0" daca start/index nu sunt valide.