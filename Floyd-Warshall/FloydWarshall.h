#pragma once
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

#define NR_MAX_OF_VERTICES 4

class Digraph {
private:
	size_t numberOfVertices;
	// vector<vector<int>*>* adjacencyMatrix;
	int matrix[NR_MAX_OF_VERTICES][NR_MAX_OF_VERTICES];

public:
	Digraph(size_t givenNrOfVertices) : numberOfVertices(givenNrOfVertices) {
		for (int i = 0; i < NR_MAX_OF_VERTICES; i++) {
			for (int j = 0; j < NR_MAX_OF_VERTICES; j++) {
				if (i == j)
					matrix[i][j] = 0;
				else
					matrix[i][j] = INT_MAX;
			}
		}

		/*
		adjacencyMatrix = new vector<vector<int>*>(givenNrOfVertices);

		for (size_t i = 0; i < givenNrOfVertices; i++) {
			adjacencyMatrix->push_back(  new vector<int>(givenNrOfVertices) );
		}
		*/
		numberOfVertices = NR_MAX_OF_VERTICES;
		// memset(matrix, UCHAR_MAX -1, sizeof(matrix[0][0]) * NR_MAX_OF_VERTICES * NR_MAX_OF_VERTICES);
	}

	void addEdge(int srcNode, int destNode, int cost) {
		// adjacencyMatrix->at(srcNode)->at(destNode) = cost;
		matrix[srcNode][destNode] = cost;
	}

	void floydWarshall() {
		int dist[NR_MAX_OF_VERTICES][NR_MAX_OF_VERTICES];

		for (int i = 0; i < NR_MAX_OF_VERTICES; i++) {
			for (int j = 0; j < NR_MAX_OF_VERTICES; j++)
				dist[i][j] = matrix[i][j];
		}

		for (int k = 0; k < numberOfVertices; k++){
			for (int i = 0; i < numberOfVertices; i++){
				for (int j = 0; j < numberOfVertices; j++){
					if (dist[i][k] != INT_MAX and dist[k][j] != INT_MAX) {
						if (dist[i][k] + dist[k][j] < dist[i][j])
							dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		printSolution(dist);
	}

	void printSolution(int matrix[][NR_MAX_OF_VERTICES]) {
		cout << "[MINIMUM DISTANCES ARE]: \n";

		for (int i = 0; i < NR_MAX_OF_VERTICES; i++){
			for (int j = 0; j < NR_MAX_OF_VERTICES; j++){
				if (matrix[i][j] == INT_MAX)
					cout << "INF" << "     ";
				else
					cout << matrix[i][j] << "     ";
			}
			cout << endl;
		}
	}


};