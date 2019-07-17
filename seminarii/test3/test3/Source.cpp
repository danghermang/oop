#include "Header.h";

void EndlessClock::AddMonitor(Monitor* watcher) {
	monitors.push_back(watcher);
}
void EndlessClock::RunTime() {
	for (auto it = indivizi.begin();it != indivizi.end();it++)
		for (int i = 1;i <= 3000;i++)
			for (int j = 1;j <= 12;j++)
				for (int q = 1;q <= 30;q++)
					if (it.zi_nastere < q&&it->luna_nastere < j&&it.an_nastere < i)
						LifeMonitor::update();
}
EndlessClock::EndlessClock(int day, int month, int year) {
	this->zi = day;
	this->luna = month;
	this->an = year;
}
void EndlessClock::AddHuman(Human* individ) {
	indivizi.push_back(individ);
}
void EndlessClock::RemoveHuman(Human* individ) {
	for (auto it = this->indivizi.begin();it != indivizi.end();it++)
		if (individ == it*)
			it*.erase();
}