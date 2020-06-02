#include <iostream>
#include "student.h"
#include "degree.h"

using std::cout;
using std::endl;

Student::Student() {
	this->ID = "";
	this->FirstName = "";
	this->LastName = "";
	this->Email = "";
	this->Age = 0;
	this->DaysToComplete = new int[3];
	this->Degree;
}

Student::Student(string id, string fname, string lname, string email, 
	int age, int dtc[], DegreeProgram degree)
{
	this->ID = id;
	this->FirstName = fname;
	this->LastName = lname;
	this->Email = email;
	this->Age = age;
	this->DaysToComplete = new int[3];
	for (int i = 0; i < 3; ++i) this->DaysToComplete[i] = dtc[i];
	this->Degree = degree;
}

string Student::getID()
{
	return ID;
}

void Student::setID(string id)
{
	this->ID = id;
}

void Student::setFirstName(string fname)
{
	this->FirstName = fname;
}

void Student::setLastName(string lname)
{
	this->LastName = lname;
}

void Student::setEmail(string email)
{
	this->Email = email;
}

void Student::setAge(int age)
{
	this->Age = age;
}

void Student::setDaysToComplete(int dtc[])
{
	if (this->DaysToComplete != nullptr) {
		delete[] this->DaysToComplete;
		this->DaysToComplete = nullptr;
	}
	this->DaysToComplete = new int[3];
	for (int i = 0; i < 3; ++i) {
		this->DaysToComplete[i] = dtc[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degree)
{
	this->Degree = degree;
}

void Student::print()
{
	int* days = getDaysToComplete();
	cout << ID << "\t";
	cout << FirstName << "\t";
	cout << LastName << "\t";
	cout << Email << "\t";
	cout << Age << "\t";
	cout << *days << "," << *(days + 1) << "," << *(days + 2) << "\t";
	cout << degreeProgramStrings[getDegreeProgram()] << endl;
}

string Student::getFirstName()
{
	return FirstName;
}

string Student::getLastName()
{
	return LastName;
}

string Student::getEmail()
{
	return Email;
}

int Student::getAge()
{
	return Age;
}

int* Student::getDaysToComplete()
{
	return DaysToComplete;
}

DegreeProgram Student::getDegreeProgram()
{
	return Degree;
}
