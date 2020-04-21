#include "FileOperations.h"


namespace text_operations {
	inputData* FileOperations::parseFile() {
		std::ifstream inFile;
		inFile.open(this->filePath);

		std::stringstream strStream;
		strStream << inFile.rdbuf();
		this->fileBuffer = strStream.str();

		for (auto symbol : this->fileBuffer) {
			this->frequencyMap[symbol]++;
		}

		return new pair <string, unordered_map<char, uint32_t>>
			(make_pair(this->fileBuffer, this->frequencyMap));

		inFile.close();
	}
}