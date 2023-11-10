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

void Semester::displayByCourse() {
	detectCourses();
	Courses.go(First);
	while (Courses.isValid()) {
		cout << "\n" << Courses.getItem() << "\n\n";
		Students.go(First);
		while (Students.isValid()) {
			if (Courses.getItem() == Students.getItem().course) { cout << StudentToLine(Students.getItem()) << "\n"; }
			Students.go(Next);
		}/**/
		Courses.go(Next);
	}
}


void Semester::detectCourses() {
	Courses.~DoublyLinkedList();
	Students.go(First);
	while (Students.isValid()) {
		
		Courses.go(First);
		bool addCourse = true;
		while (Courses.isValid()) {
			if (Courses.getItem() == Students.getItem().course) { addCourse = false; }
			Courses.go(Next);
		}
		if (addCourse) {
			Courses.add(Students.getItem().course);
		}
		Students.go(Next);
	}

}