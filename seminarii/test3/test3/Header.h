#pragma once
#include <iostream>
#include <vector>
using namespace std;
struct Human {
	int zi_nastere;
	int luna_nastere;
	int an_nastere;
	unsigned int live_days;
};
class Monitor {
	virtual void update(int day) = 0;
};
class LifeMonitor: public Monitor{
public:
	LifeMonitor();
	void update(int day) {

	}
};
class EndlessClock :public Monitor{
private:
	vector<Human*> indivizi;
	vector <Monitor*> monitors;
	int zi, luna, an;
public:
	void AddMonitor(Monitor* watcher);
	void RunTime();
	EndlessClock(int day, int month, int year);
	void AddHuman(Human* individ);
	void RemoveHuman(Human* individ);
};