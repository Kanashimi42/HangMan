#include "resultprint.h"
#include "game.h"

void resultprint::print_status(game& gameInstance)
{
	system("cls");
	print_hang(gameInstance.getErrors());
	cout << "Word: " << WordToPrint(gameInstance.getLetters(), gameInstance.getRightLetters()) << endl;
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
};

string resultprint::WordToPrint(const char* letters, const char* right_letters) {
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


void resultprint::print_hang(int errors) {
	switch (errors) {
	case 0:
		cout << R"(
          _______
          |/
          |
          |
          |
          |
          |
          |
          |
        __|________
        |         |
        )" << endl;
		break;

	case 1:
		cout << R"(
          _______
          |/
          |     ( )
          |
          |
          |
          |
          |
          |
        __|________
        |         |
        )" << endl;
		break;

	case 2:
		cout << R"(
          _______
          |/
          |     ( )
          |      |
          |
          |
          |
          |
          |
        __|________
        |         |
        )" << endl;
		break;

	case 3:
		cout << R"(
          _______
          |/
          |     ( )
          |      |_
          |        \
          |
          |
          |
          |
        __|________
        |         |
        )" << endl;
		break;

	case 4:
		cout << R"(
          _______
          |/
          |     ( )
          |     _|_
          |    /   \
          |
          |
          |
          |
        __|________
        |         |
        )" << endl;
		break;

	case 5:
		cout << R"(
          _______
          |/
          |     ( )
          |     _|_
          |    / | \
          |      |
          |
          |
          |
        __|________
        |         |
        )" << endl;
		break;

	case 6:
		cout << R"(
          _______
          |/
          |     ( )
          |     _|_
          |    / | \
          |      |
          |     / \
          |    /   \
          |
        __|________
        |         |
        )" << endl;
		break;

	case 7:
		cout << R"(
          _______
          |/     |
          |     (_)
          |     _|_
          |    / | \
          |      |
          |     / \
          |    /   \
          |
        __|________
        |         |
        )" << endl;
		break;
	}
}
