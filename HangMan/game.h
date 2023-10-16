#pragma once
using namespace std;
#include<iostream>
#include<string.h>
class game
{
public:
	void initialize(string word);
	void get_letters(string word, char* letters);
	void ask_next_letter();
	bool letterfound(char* letters, char letter);
	void step(char letter, char* right_letters, char* bad_letters, char* letters);

	int getStatus() const;


	int getErrors() const;

	const char* getLetters() const;

	const char* getRightLetters() const;

	const char* getBadLetters() const;

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

