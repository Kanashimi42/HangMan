#include "resultprint.h"
#include "game.h"

void resultprint::print_status(game& gameInstance)
{
	system("cls");
	cout << "Word: " << get_word_for_print(gameInstance.getLetters(), gameInstance.getRightLetters()) << endl;
	cout << "Errors: ";
	for (int i = 0; i < 7; i++)
	{
		if (i < gameInstance.getErrors())
		{
			cout << gameInstance.getBadLetters()[i];
			if (i < 6 && i < gameInstance.getErrors() - 1) {
				cout << ", ";
			}
		}
	}
	cout << endl;
};

string resultprint::get_word_for_print(const char* letters, const char* right_letters) {
	string result = "";

	for (const char* item = letters; *item; item++) {
		if (strchr(right_letters, *item) != nullptr) {
			result += *item;
			result += ' ';
		}
		else {
			result += "__ ";
		}
	}

	return result;
};


