#include "resultprint.h"
#include "game.h"

void resultprint::print_status(const game& gameInstance)
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

	if (gameInstance.getStatus() == -1)
	{
		cout << "You lost!" << endl;
		cout << "The hidden word was: " << gameInstance.getLetters() << endl;
	}
	else if (gameInstance.getStatus() == 1)
	{
		cout << "You won! Congrats!" << endl;
	}
	else {
		cout << "You got: " << 7 - gameInstance.getErrors() << " errors!" << endl;
	}
}

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
}


