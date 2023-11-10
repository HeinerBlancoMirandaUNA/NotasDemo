#include "student.h"

Student::Student() {
	obtainedPoints = 0;
	maxPoints = 0;
}

Student::~Student() {

}

int Student::getGrade() {
	float endResult = static_cast<float>(obtainedPoints) / static_cast<float>(maxPoints);
	endResult = endResult * 10;
	return static_cast<int>(endResult);
}