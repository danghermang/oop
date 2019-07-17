#include <windows.h>
#include <iostream>
using namespace std;

typedef int (*Compute)(int,int);
typedef char* (*GetName)(void); 
#define PLUGIN_COUNT 2

int main(void)
{
	HINSTANCE f[PLUGIN_COUNT];
	int i;
	string modules[PLUGIN_COUNT]={"adunare.dll","scadere.dll"};
	Compute computations[PLUGIN_COUNT];
	GetName getnames[PLUGIN_COUNT];

	//deschidere librarii si incarcare functii
	for (i=0;i<PLUGIN_COUNT;i++)
	{
		f[i]=LoadLibrary(modules[i].c_str());

		if (!f[i])
		{
			cout << "Nu am putut incarca DLL-ul specificat!" << endl;
			return 0;
		}

		computations[i]=(Compute)GetProcAddress(f[i],"Computation");
		getnames[i]=(GetName)GetProcAddress(f[i],"GetName");

		if (!computations[i])
		{
			printf("Nu am gasit functia [Compute] in [%s]\n",modules[i].c_str());
			return 0;
		}

		if (!getnames[i])
		{
			printf("Nu am gasit functia [GetName] in [%s]\n",modules[i].c_str());
			return 0;
		}
	}

	//Apel functii
	for (i=0;i<2;i++)
		printf("Calcul [%s(%d,%d)]=%d\n",getnames[i](),20,10,computations[i](20,10));

	//inchidere librarii
	for (i=0;i<PLUGIN_COUNT;i++)
		FreeLibrary(f[i]);


	return 0;
}