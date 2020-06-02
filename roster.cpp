#include "degree.h"
#include "roster.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::stoi;

Roster::Roster()
{
	this->Capacity = 0;
	this->LastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->Capacity = capacity;
	this->LastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}


void Roster::add(string row){
	if (LastIndex < Capacity) {
		LastIndex++;
		classRosterArray[LastIndex] = new Student();

		string id, fname, lname, email;
		int age, arr[3];
		DegreeProgram degree;

		string tmp;

		// Student ID
		int i = row.find(",");
		id = row.substr(0, i);
		classRosterArray[LastIndex]->setID(id);

		// First name
		int j = i + 1;
		i = row.find(",", j);
		fname = row.substr(j, i - j);
		classRosterArray[LastIndex]->setFirstName(fname);

		// Last name
		j = i + 1;
		i = row.find(",", j);
		lname = row.substr(j, i - j);
		classRosterArray[LastIndex]->setLastName(lname);

		// Email address
		j = i + 1;
		i = row.find(",", j);
		email = row.substr(j, i - j);
		classRosterArray[LastIndex]->setEmail(email);


		// Age
		j = i + 1;
		i = row.find(",", j);
		age = stoi(row.substr(j, i - j));
		classRosterArray[LastIndex]->setAge(age);

		// DTC1
		j = i + 1;
		i = row.find(",", j);
		arr[0] = stoi(row.substr(j, i - j));

		// dtc2
		j = i + 1;
		i = row.find(",", j);
		arr[1] = stoi(row.substr(j, i - j));

		// DTC3
		j = i + 1;
		i = row.find(",", j);
		arr[2] = stoi(row.substr(j, i - j));
		classRosterArray[LastIndex]->setDaysToComplete(arr);

		// Degree program
		j = i + 1;
		i = row.find(",", j);
		tmp = row.substr(j, i - j);
		if (tmp == "SECURITY") {
			classRosterArray[LastIndex]->setDegreeProgram(SECURITY);
		}
		else if (tmp == "NETWORK") {
			classRosterArray[LastIndex]->setDegreeProgram(NETWORK);
		}
		else
		{
			classRosterArray[LastIndex]->setDegreeProgram(SOFTWARE);
		}
	}

}

void Roster::remove(string id)
{

	for (int i = 0; i <= LastIndex; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "Student ID: " << id << " not found!" << endl;
			break;
		}
		else if (id == classRosterArray[i]->getID()) {
			classRosterArray[i] = nullptr;
			cout << "Student removed" << endl;
		}
	}

}

void Roster::printAll()
{
	for (int i = 0; i <= LastIndex; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAvgDaysInCourse(string id)
{
	bool exists = false;
	double average = 0;
	for (int i = 0; i <= LastIndex; ++i) {
		if (this->classRosterArray[i]->getID() == id) {
			exists = true;
			int* numDays = classRosterArray[i]->getDaysToComplete();
			average = (numDays[0] + numDays[1] + numDays[2]) / 3.0;
			cout << "Average number of days for ID " << id << ": ";
			cout << average << " days." << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= LastIndex; i++) {
		string email = classRosterArray[i]->getEmail();
		string space = " ";
		string emailSymbol = "@";
		string period = ".";
		if (email.find(space) != string::npos) {
			cout << email << "...is invalid!" << endl;
		}
		else if (email.find(emailSymbol) == string::npos) {
			cout << email << "...is invalid!" << endl;
		}
		else if (email.find(period) == string::npos) {
			cout << email << "...is invalid!" << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree)
{
	for (int i = 0; i <= LastIndex; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degree) {
			cout << "Found: ";
			classRosterArray[i]->print();
		}
	}
}
