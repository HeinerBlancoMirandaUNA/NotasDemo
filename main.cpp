#include <iostream>
#include "include/semester.h"

int main()
{
	Semester current;
	current.readFile("./data/20231020.csv");
	current.readFile("./data/final.csv");
	current.readFile("./data/finalfinal.csv");
	current.readFile("./data/masArchivos.csv");
	current.readFile("./data/MOCK_DATA.csv");
	
	current.displayByCourse();
	current.displayStudent("Silvain","Wiggin", "COTO");
	current.saveByCampus("Guardar por Campus.csv");

}