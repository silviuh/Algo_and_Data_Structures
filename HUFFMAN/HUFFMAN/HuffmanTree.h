#pragma once
#include "FileOperations.h"
#include <queue>
using namespace text_operations;

#define UNDEFINED_SYMBOL '$'

struct Node {
public:
	char symbol;
	uint32_t frequency;
	Node* left;
	Node* right;

	Node(char ch, uint32_t frequency, Node* leftChild, Node* rightChild) {
		this->symbol = ch;
		this->frequency = frequency;
		this->left = leftChild;
		this->right = rightChild;
	}

	void setLeftLink(Node* link) {
		this->left = link;
	}

	void setRightLink(Node* link) {
		this->right = link;
	}
};

class frequencyDescendingOrder{
public:
	bool operator()(Node* leftNode, Node* rightNode){
		return leftNode->frequency > rightNode->frequency;
	}
};

class HuffmanTree {
private:
	Node* root;
	unordered_map<char, string> huffmanTable;

public:
	string optionalHeavyBuffer;

	HuffmanTree(inputData* data);

	void buildHuffmanTableUtil(Node* currentRoot, string code, unordered_map<char, string>& huffmanTableCodes);
	void buildHuffmanTable();
	void printHuffmanCodes();

	string encode(string& bufferToEncode);
	string decode(string& bufferToDecode);
	char decodeUtil(string& buffer, int& currentBit, Node* root);

	void readHeavyBuffer(string filePath);

};

