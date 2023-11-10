#include "file_load_and_save.h"

FileLoadAndSave::FileLoadAndSave() {

}

FileLoadAndSave::~FileLoadAndSave() {

}

void FileLoadAndSave::readFile(string thisFile) {

	ifstream File(thisFile.c_str());

	if (File.fail()) {
		File.close();
		return;
	}

	string currentLine;
	getline(File, currentLine);
	while (getline(File, currentLine)) {
		if (currentLine.length() > 1) { Students.add(lineToStudent(currentLine));; }
	}


	File.close();
}

void FileLoadAndSave::saveToFile(string thisFile, DoublyLinkedList<Student>& thisData) {

	ofstream File(thisFile.c_str());

	thisData.go(First);
	File << "sede, cedula, nombre, lastname, course, nota, estado, puntos obtenidos, puntos totales" << std::endl;
	while (thisData.isValid()) {
		File << StudentToLine(thisData.getItem()) << std::endl;
		thisData.go(Next);
	}

	File.close();

}

Student FileLoadAndSave::lineToStudent(string line) {
	int counter = 0;
	int totalLines = 0;
	string currentLine;
	Student toReturn;
	while (!(counter > line.size())) {
		if ((line[counter] == ',')or(counter == line.size())) {

			if (totalLines == 0) { toReturn.campus = currentLine; }
			if (totalLines == 1) { toReturn.id = currentLine; }
			if (totalLines == 2) { toReturn.name = currentLine; }
			if (totalLines == 3) { toReturn.lastName = currentLine; }
			if (totalLines == 4) { toReturn.course = currentLine; }
			
			if (totalLines == 6) { toReturn.status = currentLine; }
			if (totalLines == 7) { toReturn.obtainedPoints = stoi(currentLine); }
			if (totalLines == 8) { toReturn.maxPoints = stoi(currentLine); }

			currentLine = "";
			totalLines++;
		}
		else {
			currentLine = currentLine + line[counter];
		}
		counter++;
	}
	return toReturn;
}

string FileLoadAndSave::StudentToLine(Student thisStudent) {

	thisStudent.status = "REVISADO";

	return
		thisStudent.campus + ","
		+ thisStudent.id + ","
		+ thisStudent.name + ","
		+ thisStudent.lastName + ","
		+ thisStudent.course + ","
		+ to_string(thisStudent.getGrade()) + ","
		+ thisStudent.status + ","
		+ to_string(thisStudent.obtainedPoints) + ","
		+ to_string(thisStudent.maxPoints);
}