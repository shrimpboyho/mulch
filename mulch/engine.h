#pragma once
#include "std_lib_facilities.h"
class engine
{
public:

	// Public variables that will hold shit

	typedef struct {

		vector <string> elementNames;
		vector <int> amountOfElement;



	} databank;

	// Instance of the database

	databank DATA_BASE;

	// Member functions

	void parseInput(char stringInput[]);

	void calculate(int length, int position);
	void elementLookup(string element);

	engine(void);
	~engine(void);
};

