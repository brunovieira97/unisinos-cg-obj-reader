#include <Classes/CurveReader.h>

CurveReader::CurveReader() {
	
}

std::vector<glm::vec3*> CurveReader::GetCurvePoints() {
	return this -> curvePoints;
}

void CurveReader::Read(std::string filename) {
	std::ifstream file;

	file.open(filename);

	if(!file.is_open()) {
		std::cerr << "Unable to open " + filename + ". Application will terminate." << std::endl;
		exit(EXIT_FAILURE);
	}

	lineCount = 0;

	while(!file.eof()) {
		std::string currentLine;
		std::stringstream lineStream;
		
		lineCount++;

		getline(file, currentLine);
		lineStream << currentLine;
		
		if (currentLine != "") {
			std::string x, y, z;

			std::getline(lineStream, x, ' ');
			std::getline(lineStream, y, ' ');
			std::getline(lineStream, z, ' ');

			glm::vec3 *pointCoordinates = new glm::vec3(
				stof(x),
				stof(y),
				stof(z)
			);

			this -> curvePoints.push_back(pointCoordinates);
		}
	}
}

