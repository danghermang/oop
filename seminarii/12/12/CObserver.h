#ifndef CObserver_h
#define CObserver_h
#include<ctime>
#include<iostream>
using namespace std;
#include "Observer.h"


class CObserver : virtual public Observer {
public:
	virtual void Update();
};

#endif // CObserver_h
