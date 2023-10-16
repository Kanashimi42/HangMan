#include <fstream>
#include <time.h>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "game.h"
#include "resultprint.h"
using namespace std;
int main(int argc, char* argv[]) {
	clock_t start = clock();
	if (argc < 2) {
		cout << "Check words.txt!" << endl;
		return 1;
	}

	vector<string> words;
	ifstream inputFile("words.txt");

	if (inputFile.is_open()) {
		string word;
		while (getline(inputFile, word)) {
			words.push_back(word);
		}
		inputFile.close();
	}
	else {
		cerr << "Unable to open words.txt" << endl;
		return 1;
	}

	srand(static_cast<unsigned>(time(0)));

	string word = words[rand() % words.size()];

	game game(word);
	resultprint printer;

	while (game.getStatus() == 0) {
		printer.print_status(game);
		game.askNext();
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "You completed the word in: " << seconds << " seconds!";


	return 0;
}