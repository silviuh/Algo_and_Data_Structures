#include <fstream>
#include <iostream>
#include <sstream> //std::stringstream
#include "HuffmanTree.h"

using namespace text_operations;

int main() {
	FileOperations* fileManager = new FileOperations("file_in.txt");
	HuffmanTree* utilityTree = new HuffmanTree(fileManager->parseFile());

	string bufferToEncode = "aabbbcdeeee";  // you may choose any buffer to encode
	string encodedBuffer = utilityTree->encode(
		bufferToEncode
	);
	string decodedBuffer = utilityTree->decode(
		encodedBuffer
	);

	utilityTree->printHuffmanCodes();

	cout << "\n\nInitial buffer is: [" << bufferToEncode << "]";
	cout << "\nEncoded buffer is: [" << encodedBuffer << "]";
	cout << "\nDecoded buffer is: [" << decodedBuffer << "]";

	fileManager->writeToFile(encodedBuffer, "file_out.txt");

	return 0;
}