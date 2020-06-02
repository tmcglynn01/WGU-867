#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

using std::string;

class Roster {
private:
	int LastIndex;
	int Capacity;
public:
	Student** classRosterArray;
	void remove(string id);
	void add(string row);
	// Functions to display in main()
	void printAll();
	void printAvgDaysInCourse(string id);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);

	// Constructor
	Roster();
	Roster(int capacity);
	~Roster();
};

#endif