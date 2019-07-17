#ifndef Computer_h
#define Computer_h
#include <vector>
#include <iostream>
using namespace std;
class Observer;
class PrimeComputer;

class Computer :virtual public Observer{

 public:

    virtual void Remove(Observer *o);

    virtual void Add(Observer *o);

private:
	int count;
    vector<Observer> myObserver;
    PrimeComputer *myPrimeComputer;
};

#endif // Computer_h
