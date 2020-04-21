#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(inputData* data) {
	priority_queue<Node*, vector<Node*>, frequencyDescendingOrder>* container = 
		new priority_queue<Node*, vector<Node*>, frequencyDescendingOrder>();

	for (auto item : data->second) {
		container->push(new Node(
			item.first,
			item.second,
			nullptr,
			nullptr)
		);
	}

	while (container->size() != 1){
		Node* leftChild = container->top();
		container->pop();

		Node* rightChild = container->top();
		container->pop();

		uint32_t sum = leftChild->frequency + rightChild->frequency;
		container->push(new Node(
			UNDEFINED_SYMBOL,
			sum,
			leftChild,
			rightChild)
		);
	}

	this->root = container->top();
	container->pop();

	this->huffmanTable = unordered_map<char, string>();
	buildHuffmanTable();
}


void HuffmanTree::buildHuffmanTable() {
	buildHuffmanTableUtil(this->root, string(), this->huffmanTable);
}

void HuffmanTree::buildHuffmanTableUtil(Node* currentRoot, string code, unordered_map<char, string>& huffmanTableCodes){
	if (currentRoot == nullptr) {
		return;
	}

	if (nullptr == currentRoot->left and nullptr == currentRoot->right) {
		huffmanTableCodes[currentRoot->symbol] = code;
	}

	buildHuffmanTableUtil(
		currentRoot->left,
		code + "0",
		huffmanTableCodes
	);

	buildHuffmanTableUtil(
		currentRoot->right,
		code + "1",
		huffmanTableCodes
	);
}

void HuffmanTree::printHuffmanCodes() {
	cout << "Huffman table is: \n";
	for (auto pair : this->huffmanTable) {
		if(pair.first == (char) '\n')
			cout << "[ " << "endline" << " ] : " << pair.second << '\n';
		else
			cout << "[ " << pair.first << " ] : " << pair.second << '\n';
	}
}

string HuffmanTree::encode(string& bufferToEncode) {
	string encodedBuffer = "";
	for (auto byteSymbol : bufferToEncode) {
		encodedBuffer += this->huffmanTable[byteSymbol];
	}

	return encodedBuffer;
}

string HuffmanTree::decode(string& bufferToDecode){
	string decodedBuffer = "";
	int currentBitInBuffer = -1;

	while (currentBitInBuffer < (int)bufferToDecode.size() - 2) {
		decodedBuffer += decodeUtil(
			bufferToDecode,
			currentBitInBuffer,
			this->root
		);
	}

	return decodedBuffer;
}

char HuffmanTree::decodeUtil(string& buffer, int& currentBit, Node* root) {
	if (nullptr == root->left and nullptr == root->right) {
		return root->symbol;
	}

	currentBit++;
	if (buffer[currentBit] == '0') {
		return decodeUtil(
			buffer,
			currentBit,
			root->left
		);
	}
	else{
		return decodeUtil(
			buffer,
			currentBit,
			root->right
		);
	}
}

void HuffmanTree::readHeavyBuffer(string filePath) {
	std::ifstream inFile;
	inFile.open(filePath);

	std::stringstream strStream;
	strStream << inFile.rdbuf();
	this->optionalHeavyBuffer = strStream.str();
}