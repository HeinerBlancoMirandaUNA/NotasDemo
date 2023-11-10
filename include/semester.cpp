#include "semester.h"

Semester::Semester() {
	Student fake = lineToStudent("sede,cedula,nombre,lastname,course,nota,estado,22,45");
	cout << "\n\n\n\n";
	cout << StudentToLine(fake);
}
Semester::~Semester() {

}