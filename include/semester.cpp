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
			//NOTE: código muy anidado
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
		while (Courses.isValid()) {//NOTE: código muy anidado
			if (Courses.getItem() == Students.getItem().course) { addCourse = false; }
			Courses.go(Next);
		}
		if (addCourse) {
			Courses.add(Students.getItem().course);
		}
		Students.go(Next);
	}

}

void Semester::detectLocations() {
	Locations.~DoublyLinkedList();
	Students.go(First);
	while (Students.isValid()) {

		Locations.go(First);
		bool addLocation = true;
		while (Locations.isValid()) {//NOTE: código muy anidado
			if (Locations.getItem() == Students.getItem().campus) { addLocation = false; }
			Locations.go(Next);
		}
		if (addLocation) {
			Locations.add(Students.getItem().campus);
		}
		Students.go(Next);

	}

}

void Semester::saveByCampus(string thisFile) {
	detectLocations();
	DoublyLinkedList<Student> toSave;
	Student newStudent;
	Locations.go(First);
	while (Locations.isValid()) {
		Students.go(First);
		while (Students.isValid()) {//NOTE: código muy anidado
			if (Locations.getItem() == Students.getItem().campus) { 
				newStudent = Students.getItem();
				newStudent.status = "REVISADO";
				toSave.add(newStudent); 
				
			}
			Students.go(Next);
		}
		Locations.go(Next);
	}

	saveToFile(thisFile, toSave);

}

void Semester::displayStudent(string name, string lastName, string campus) {

	cout << "\n#############\n";
	Students.go(First);
	while (Students.isValid()) {

		bool show = Students.getItem().name == name &&
			Students.getItem().lastName == lastName &&
			Students.getItem().campus == campus;

		if (show) {	cout << StudentToLine(Students.getItem()) << "\n"; }
		
		Students.go(Next);
	}

}