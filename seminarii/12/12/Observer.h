#ifndef Observer_h
#define Observer_h
#include<iostream>
#include<time.h>
using namespace std;
class Computer;

class Observer {

 public:

    virtual void Update();
	void initialTime() { firstTime = clock(); }
	time_t currTime() { return difftime(clock(), this->firstTime); }

 private:
	Computer *myComputer;
	time_t firstTime;
};

#endif // Observer_h
