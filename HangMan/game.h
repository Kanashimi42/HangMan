#pragma once
using namespace std;
#include<iostream>
#include<string.h>
class game
{

	void initialize(string word)
	{
		rint = word.length();
		letters = new char[rint + 1];
		get_letters(word, letters);
		right_letters = new char[rint];
		errors = 0;
		status = 0;
	}
	void get_letters(string word, char* letters)
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
	void ask_next_letter()
	{
		do {
			cout << "Enter next letter: " << endl;
			cin >> letter;
		} while (letter == ' ');
		step(letter, right_letters, bad_letters, letters);
	}
	bool letterfound(char* letters, char letter)
	{
		for (int i = 0; letters[i] != '\0'; i++) {
			if (letters[i] == letter) {
				return true;
			}
		}
		return false;
	}
	void step(char letter, char* right_letters, char* bad_letters, char* letters)
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
			if (strcmp(right_letters, letters) == 0)
			{
				status = 1;
			}
		}
		else {
			bad_letters[counter] = letter;
			counter++;
		}
	}


	bool getstatus()
	{
		return status;
	}

	int geterrors()
	{
		return errors;
	}

	char* getletters()
	{
		return letters;
	}


	char* getright_letters()
	{
		return right_letters;
	}


	char getbad_letters(int i)
	{
		return bad_letters[i];
	}

private:
	char* split_word;
	int rint = 0;
	int rcount = 0;
	int counter = 0;
	char letter;
	char* letters;
	int errors;
	char* right_letters;
	char bad_letters[7];
	bool status;
};

