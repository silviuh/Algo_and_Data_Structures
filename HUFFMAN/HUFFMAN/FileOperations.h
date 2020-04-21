#pragma once
#include <fstream>
#include <iostream>
#include <sstream> //std::stringstream
#include <vector>
#include <stdint.h>
#include <unordered_map>
#include <utility>

using namespace std;
typedef pair<string, unordered_map<char, uint32_t>> inputData;

namespace text_operations {

	class FileOperations {
	private:
		string filePath;
		string fileBuffer;
		unordered_map<char, uint32_t> frequencyMap;
	public:

		FileOperations(const char* givenFilePath) : filePath(givenFilePath) {}

		inputData* parseFile();

		string getFileBuffer() {
			return this->fileBuffer;
		}

		void writeToFile(string& bufferToWrite, const char* filePath) {
			std::ofstream out(filePath);
			out << bufferToWrite;
		}
	};
}


