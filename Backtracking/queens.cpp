#include <iostream>
using namespace std;

#define M_SIZE 5
#define QUEENS_NR 3

bool valid(int k, int solution[]) {
	for (int i = 0; i <= k - 1; i++) {
		if (solution[i] == solution[k] or
			(abs(k - i) == abs(solution[k] - solution[i])))
			return false;
	}
	return true;
}

void printSolution(int solution[]) {
	for (int i = 0; i < M_SIZE; i++) {
		for (int j = 0; j < M_SIZE; j++) {
			if (solution[i] == j) {
				cout << 'D';
			}
			else
				cout << '-';
			cout << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

void solve(int k, int solution[]) {
	if (k == QUEENS_NR) {
		printSolution(solution);
		return;
	}

	for (int i = 0; i <= QUEENS_NR; i++) {
		solution[k] = i;
		if (valid(k, solution))
			solve(k + 1, solution);
	}
}



int main() {
	int solution[QUEENS_NR] = { 0 };
	solve(0, solution);

	return 0;
}