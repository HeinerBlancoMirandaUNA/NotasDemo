#include <iostream>
#include "include/semester.h"

int main()
{
	Semester current;
	current.readFile("./data/final.csv");
	current.readFile("./data/final.csv");
	current.displayAll();
	current.saveToFile("prueba de basura.csv", current.Students);

}