#include "game.h"


game::game(const string& word)
{
	game::initialize(word);
}
void game::initialize(string word)
{
	rint = word.length() - 1;
	letters = new char[rint + 1];
	get_letters(word, letters);
	right_letters = new char[rint];
	errors = 0;
	status = 0;
	rcount = 0;
}
void game::get_letters(string word, char* letters)
{
	if (word.empty())
	{
		cout << "Word is not entered!!! Check words.txt file!" << endl;
		status = 1;
	}
	else
	{

		for (int i = 0; i < word.length(); i++) {
			letters[i] = word[i];
		}

		letters[word.length()] = '\0';

	}
}
void game::ask_next_letter()
{
	do {
		cout << "Enter next letter: " << endl;
		cin >> letter;
	} while (letter == ' ');
	step(letter, right_letters, bad_letters, letters);

	if (getStatus() == -1)
	{
		cout << "You lost!" << endl;
		cout << "The hidden word was: " << getLetters() << endl;
	}
	else if (getStatus() == 1)
	{
		cout << "You won! Congrats!" << endl;
	}
}
bool game::letterfound(char* letters, char letter)
{
	if (status == 1)
	{
		return true;
	}
	for (int i = 0; letters[i] != '\0'; i++) {
		if (letters[i] == letter) {
			return true;
		}
	}
	return false;
}
void game::step(char letter, char* right_letters, char* bad_letters, char* letters)
{
	if (status == -1 || status == 1)
	{
		return;
	}
	if (letterfound(right_letters, letter) == 1 || letterfound(bad_letters, letter) == 1)
	{
		return;
	}
	if (letterfound(letters, letter) == 1)
	{
		right_letters[rcount] = letter;
		rcount++;
		if (rcount == rint)
		{
			status = 1;
		}
	}
	else {
		bad_letters[counter] = letter;
		counter++;
		errors++;
		if (errors >= 7)
		{
			status = -1;
		}
	}
}



int game::getStatus() {
	return status;
}


int game::getErrors() const {
	return errors;
}

const char* game::getLetters() const {
	return letters;
}

const char* game::getRightLetters() const {
	return right_letters;
}

const char* game::getBadLetters() const {
	return bad_letters;
}