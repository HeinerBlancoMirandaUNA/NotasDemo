#pragma once
#include "file_load_and_save.h"

class Semester : public FileLoadAndSave
{
private:
	DoublyLinkedList<Student> Courses;

public:
	Semester();
	~Semester();
	void displayAll();
};

