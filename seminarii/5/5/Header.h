#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include<cstring>
#include<string>
using namespace std;
vector<const char*> cuvinte;
char *semne = ".,:; ";
char *s;
void citire(vector<const char*> cuvinte)
{
	ifstream fin("cuvinte.txt");
	char c;
	int i = 0, j = 0;
	while (fin.eof!=0)
	{
		fin >> c;
		while (strchr(semne, c) != 0)
		{
			s[i] = c;
			i++;
		}
		cuvinte[j]=s;
		i = 0;
		j++;
	}
}
const char* lungime(vector<const char*> cuvinte)
{

}