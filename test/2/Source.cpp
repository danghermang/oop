//Implementare
#include "Header.h"

Grade::operator< (const Grade& a) const {
	if (this->value < a.value)
		return true;
	return false;
}

unsigned Student::getPoints() {
	unsigned total = 0, count = 0;
	for (auto it = this->grades.begin;it != this->grades.end;it++)
	{
		if (this->grades[*it].value >= 5)
		{
			count++;
			total += grades[*it].value;
		}
	}
	return total / count;
}
void Student::setName(const string& name) {
    this->name = name;
}

void Student::setAge(unsigned age) {
	this->age = age;
}

void Student::addGrade(const Grade& grade) {
	this->grades.push_back(grade.subject);
	this->grades.push_back(grade.value);
}
set<Grade> Student::getGradeSet() {
	set<Grade> new_set;
	for (auto it = this->grades.begin;it != this->grades.end;it++)
	{
		new_set.insert(this->grades[*it]);
	}//
	return new_set;
}
bool Student::isFailing() {
	for (auto it = this->grades.begin;it != this->grades.end;it++)
	{
		if (this->grades[*i].value < 5)
			return false;
	}
	return true;
}
string Student::getName() {
	return this->name;
}
unsigned BachelorStudent::getPointsPerGrade()
{
	return 5;
}
unsigned MasterStudent::getPointsPerGrade()
{
	return 8;
}
StudentType BachelorStudent::getStudentType()
{
	return{ BACHELOR };
}
StudentType BachelorStudent::getStudentType()
{
	return{ MASTER };
}
BachelorStudent::BachelorStudent(const string& name, unsigned age) {
	this->name = name;
	this->age = age;
}
BachelorStudent::BachelorStudent() {
	this->name = "";
	this -> age = 0;
}
MasterStudent::MasterStudent(const string& name, unsigned age) {
	this->name = name;
	this->age = age;
}
MasterStudent::MasterStudent() {
	this->name = "";
	this->age = 0;
}
void DBStudents::loadFromFile() {

}