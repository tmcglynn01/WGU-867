// TrevorMcGlynnC867.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "roster.h"
#include <sstream>

using std::cout;
using std::endl;
using std::string;

int main() {

	// WGU Student Info
	cout << "*****************************************************************************";
	cout << endl << endl;
	cout << "\tCourse Title:\t\tScripting and Programming Applications C867";
	cout << endl;
	cout << "\tProgramming language:\tC++";
	cout << endl;
	cout << "\tWGU Student ID:\t\t1350072";
	cout << endl;
	cout << "\tName:\t\t\tTrevor McGlynn";
	cout << endl << endl;
	cout << "*****************************************************************************";
	cout << endl << endl;


	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Trevor,McGlynn,trevormcglyn@wgu.edu,28,20,30,22,SOFTWARE"
	};


	cout << "Creating class Roster..." << endl;
	Roster* classRoster = new Roster(5);
	for (int i = 0; i < 5; i++) 
	{
		classRoster->add(studentData[i]);
	}
	cout << "Class roster created successfully!" << endl;
	cout << "\n\n";

	cout << "-----------------------------------------------------------------------------";

	cout << "\n\n";
	cout << "Printing all students..." << endl;
	classRoster->printAll();
	cout << "\n\n";
	cout << "Printing all invalid emails..." << endl;
	classRoster->printInvalidEmails();
	cout << "\n\n";
	cout << "Printing average..." << endl;
	for (int i = 0; i < 5; ++i) {
		classRoster->printAvgDaysInCourse(classRoster->classRosterArray[i]->getID());
	}
	classRoster->printAvgDaysInCourse("A3");
	cout << "\n\n";
	cout << "Priting by degree program..." << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << "\n\n";
	cout << "Removing A3..." << endl;
	classRoster->remove("A3");
	cout << "\nA3 removed!\n\n";
	cout << "Printing all students to verify...\n";
	classRoster->printAll();
	cout << "Removing A3 again...\n";
	classRoster->remove("a3");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
