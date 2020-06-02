#pragma once
#ifndef DEGREE_H
#define DEGREE_H

#include <string>

using std::string;

// Three types of degree programs
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Parallel array of strings for enumeration
static const string degreeProgramStrings[] = { "Security", "Network", "Software" };

#endif