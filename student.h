#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student {
private:
	string ID;
	string FirstName;
	string LastName;
	string Email;
	int Age;
	int* DaysToComplete;
	DegreeProgram Degree;
public:
	// Accessors for each instance variable
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	// Mutators for each instance variable
	void setID(string id);
	void setFirstName(string fname);
	void setLastName(string lname);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int dtc[]);
	void setDegreeProgram(DegreeProgram degree);

	// Print specific student data
	void print();

	// Constructor
	Student();
	Student(string id, string fname, string lname, string email,
		int age, int dtc[], DegreeProgram degree);
};

#endif