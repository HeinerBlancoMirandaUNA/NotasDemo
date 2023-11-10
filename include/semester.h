#pragma once
#include "file_load_and_save.h"

class Semester : public FileLoadAndSave
{
private:
	DoublyLinkedList<string> Courses;
	void detectCourses();

public:
	Semester();
	~Semester();
	
	void displayByCourse();
	void displayAll();
};

