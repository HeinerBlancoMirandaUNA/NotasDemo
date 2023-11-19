#include <iostream>
#include "include/semester.h"

int main()
{
	Semester current;//NOTE: debe leer los archivos del directorio, no uno por uno
	current.readFile("./data/20231020.csv");
	current.readFile("./data/final.csv");
	current.readFile("./data/finalfinal.csv");
	current.readFile("./data/masArchivos.csv");
	current.readFile("./data/MOCK_DATA.csv");
	
	current.displayByCourse();//NOTE: no esta bien hecho
	current.displayStudent("Silvain","Wiggin", "COTO");
	current.saveByCampus("Guardar por Campus.csv");

}