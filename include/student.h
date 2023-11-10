#pragma once
#include <string>
using std::string;

class Student
{
public:
	Student();
	virtual ~Student();

	string campus, name, lastName, course, status, id;
	int obtainedPoints, maxPoints;

	int getGrade();

};

