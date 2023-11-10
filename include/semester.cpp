#include "semester.h"

Semester::Semester() {

}
Semester::~Semester() {

}

void Semester::displayAll() {
	Students.go(First);
	while (Students.isValid()) {
		cout << StudentToLine(Students.getItem()) << "\n";
		Students.go(Next);
	}
}