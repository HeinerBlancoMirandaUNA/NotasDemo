#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "doubly_linked_list.h"
using std::string;
using std::vector;
using std::ifstream; 
using std::ofstream;
using std::cout;
using std::to_string;


class FileLoadAndSave
{
public:
	FileLoadAndSave();
	~FileLoadAndSave();
	DoublyLinkedList<Student> Students;
	string filename;
	vector<string> fileContents;

	bool fileIsLoaded();
	void readFile(string thisFile);
	Student lineToStudent(string line);
	string StudentToLine(Student thisStudent);
	void saveToFile(string thisFile, vector<string> data);

private:
	bool fileReady;
	void resetData();
};

