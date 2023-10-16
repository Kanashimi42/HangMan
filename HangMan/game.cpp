#include "game.h"


game::game(const string& word)
{
	game::initialize(word);
}
void game::initialize(string word)
{
	rint = word.length();
	letters = new char[rint + 1];
	get_Letters(word, letters);
	right_letters = new char[rint];
	right_letters[rint] = '\0';

	errors = 0;
	status = 0;
	rcount = 0;
}
void game::get_Letters(string word, char* letters)
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
void game::askNext()
{
	if (status == 1 || status == -1)
	{
		isRunning = false;
		return;
	}
	do {
		cout << "Enter next letter: " << endl;
		cin >> letter;
	} while (letter == ' ');
	Update(letter, right_letters, bad_letters);

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
bool game::letterfound(const char* rbletters, char letter)
{
	if (status == 1)
	{
		return true;
	}
	for (int i = 0; rbletters[i] != '\0'; i++) {
		if (rbletters[i] == letter) {
			return true;
		}
	}
	return false;
}
bool game::letterfoundcheck(char letter)
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
void game::Update(char letter, char* right_letters, char* bad_letters)
{
	if (status == -1 || status == 1)
	{
		return;
	}
	bool Found = false;

	if (letterfound(right_letters, letter) == 1 || letterfound(bad_letters, letter) == 1)
	{
		return;
	}
	if (letterfoundcheck(letter) == 1)
	{
		for (int i = 0; i < rint; i++) {
			if (letters[i] == letter && right_letters[i] != letter) {
				right_letters[i] = letter;
				rcount++;
				Found = true;
			}
		}

		if (rcount == rint)
		{
			status = 1;
		}
	}
	if (!Found)
	{
		bad_letters[counter] = letter;
		counter++;
		errors++;
		if (errors >= 7)
		{
			status = -1;
		}
	}
}


bool game::getIsrunning()
{
	return isRunning;
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