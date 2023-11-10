#include "file_load_and_save.h"

FileLoadAndSave::FileLoadAndSave() {
	resetData();
}

FileLoadAndSave::~FileLoadAndSave() {

}

void FileLoadAndSave::resetData() {
	fileContents.clear();
	filename = "";
	fileReady = false;
}

bool FileLoadAndSave::fileIsLoaded() {

	return fileReady;

}

void FileLoadAndSave::readFile(string thisFile) {
	resetData();
	ifstream File(thisFile.c_str());

	if (File.fail()) {
		File.close();
		return;
	}

	string currentLine;
	while (getline(File, currentLine)) {
		fileContents.push_back(currentLine);
	}

	fileReady = true;
	File.close();
}

void FileLoadAndSave::saveToFile(string thisFile, vector<string> thisData) {

	ofstream File(thisFile.c_str());

	string currentLine;
	while (!thisData.empty()) {
		currentLine = thisData[0];
		File << currentLine << std::endl;
		thisData.erase(thisData.begin());
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