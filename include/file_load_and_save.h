#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "doubly_linked_list.h"
using std::string;
using std::ifstream; 
using std::ofstream;
using std::cout;
using std::to_string;


class FileLoadAndSave
{
private:
	Student lineToStudent(string line);
	
public:
	FileLoadAndSave();
	~FileLoadAndSave();
	DoublyLinkedList<Student> Students;
	string StudentToLine(Student thisStudent);

	void readFile(string thisFile);
	void saveToFile(string thisFile, DoublyLinkedList<Student>& thisData);

};

