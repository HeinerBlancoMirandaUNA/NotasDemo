#pragma once
#include "file_load_and_save.h"

class Semester : public FileLoadAndSave
{
private:
	DoublyLinkedList<string> Courses;
	DoublyLinkedList<string> Locations;
	void detectCourses();
	void detectLocations();
	

public:
	Semester();
	~Semester();
	
	void saveByCampus(string thisFile);
	void displayByCourse();
	void displayStudent(string name, string lastName, string campus);
	
	void displayAll();
};

