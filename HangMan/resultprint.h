#pragma once
using namespace std;
#include<iostream>
#include<string.h>

#include "game.h"
class resultprint
{
public:
	void print_status(game& gameInstance);
	string WordToPrint(const char*, const char*);
	void print_hang(int errors);
};

