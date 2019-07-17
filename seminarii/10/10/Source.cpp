#include "Singleton.h"
int main() {
	Singleton *wtfman;
	wtfman = Singleton::getInstance();
	wtfman = Singleton::getInstance();
	wtfman = Singleton::getInstance();
	cout << Singleton::count;
}