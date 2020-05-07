#include "FloydWarshall.h"

int main() {
	Digraph* graph = new Digraph(NR_MAX_OF_VERTICES);

	graph->addEdge(0, 1, 3);
	graph->addEdge(0, 3, 7);
	graph->addEdge(1, 0, 8);
	graph->addEdge(1, 2, 2);
	graph->addEdge(2, 0, 5);
	graph->addEdge(2, 3, 1);
	graph->addEdge(3, 0, 2);

	graph->floydWarshall();

	return 0;
}