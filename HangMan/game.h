#pragma once
using namespace std;
#include<iostream>
#include<string.h>
class game
{
public:
	game(const string& word);
	void initialize(string word);
	void get_Letters(string word, char* letters);
	void askNext();
	bool letterfound(const char* letters, char letter);
	bool letterfoundcheck(char letter);
	void Update(char letter, char* right_letters, char* bad_letters);

	int getStatus();

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
	int status;
};
