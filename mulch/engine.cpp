//
// THIS FILE IS PART OF THE mulch SOFTWARE SOURCE CODE.
// USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS
// GOVERNED BY A GPL-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE
// IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.
//
//
	
//+---------------------------------------------------------------------------
//
//  DEWEY DEV, 2013.
//
//  File:       engine.cpp
//
//  Contents:   parses a given chemical equation
//              finds the elements present as well as their quantities
//              returns two parallel vectors .
//
//  Classes:    engine
//
//  Functions:  parseInput()
//
//  Author:     shrimpboyho ( shrimpboyhoftw@gmail.com )
//
//  History:    5-25-2013   shrimpboyho   Got stability workin
//
//----------------------------------------------------------------------------


#include "engine.h"
#include <ctype.h>

// Constructor

engine::engine(void)
{
}

// Deconstructor

engine::~engine(void)
{
}

void engine::parseInput(char input[]){

	int endOfString = 0;			    // Variable that stores the end of the string
	int i;							    // Loop counter
	int k;                              // Another loop counter
	int g;                              // Yet Another loop counter  
	int z;                              // HOW MANY!!!!
	vector <string> foundElements;      // Vector that stores the number of found elements
	vector <int> digitsFound;           // A vector that accumulates digits that will later be summed
	vector <int> amountOfFoundElements; // Vector parallel to foundElements
	string temp;                        // A temporary string
	int tempsum = 0;                    // A temporary sum of the amount of elements
	bool paren = false;                 // A boolean representing the state of parenthesis in the equation


	// Determine the end of the string

	while(input[endOfString] != '\n'){

		endOfString++;

	}
	
	printf("Determined the end of the string to be at the index of %d\n", endOfString);

	// Begin scanning the string character by character

	for(i = 0; i < endOfString; i++){
		
		// Check to make sure its not a whitespace character

		if(isspace(input[i])){
			continue;
		}

		// Check to make sure its not a + or = character

		if((input[i] == '+') || (input[i] == '=')){
			continue;
		}

		// Check to make sure its not a number

		if(isdigit(input[i])){
			continue;

			// We'll worry about counting digits later
		}

		// Now if its a letter

		if(isalpha(input[i])){

			// We need to check if its a single letter or a double letter element.

			/* SINGLE LETTER CHECK! */

			if(isupper(input[i]) && ( isupper(input[i+1]) || isdigit(input[i+1]) || isspace(input[i+1]))){

				temp.push_back(input[i]);
				
				// Inject into the vector only if it isn't already in there

				for(k = 0; k < foundElements.size(); k++){
					if(temp == foundElements[k]){
						break;
					}
				}
				
				if(k == foundElements.size()){
					foundElements.push_back(temp);
				}

				// Clear teh string

				temp.clear();

			}

			/* DOUBLE LETTER CHECK! */

			if(isupper(input[i]) && (!isupper(input[i+1])) && (!isspace(input[i+1])) && (!isdigit(input[i+1])) && (input[i+1] != '+')  && (input[i+1] != '=')){

				temp.push_back(input[i]);
				temp.push_back(input[i+1]);
				
				// Inject into the vector only if it isn't already in there

				for(k = 0; k < foundElements.size(); k++){
					if(temp == foundElements[k]){
						break;
					}
				}
				
				if(k == foundElements.size()){
					foundElements.push_back(temp);
				}

				// Clear teh string

				temp.clear();

			}

		}

	}

	// Now print out the contents of the vectors

	for(i = 0; i < foundElements.size(); i++){

		cout << "\n" << foundElements[i] << "\n";

	}

	// Now match the vector the public accesible vector

	this->DATA_BASE.elementNames = foundElements;

	/* BEGIN COUNTING THE AMOUNT OF ELEMENTS*/

	// Loop through each of the found elements

	for(i = 0; i < foundElements.size(); i++){

		// Find instance of the element in the string of input

		for(g = 0; g < endOfString; g++){

			// See if we've hit parenthesis
			
			if(input[g] == '('){
				paren = true;
			}

			if(input[g] == ')'){
				paren = false;
			}

			// See if we've found the element

			// TODO


		}


		/* SUM UP THE CONTENTS OF digitsFound and INJECT IT*/

		for(k = 0; k < digitsFound.size(); k++){
			tempsum = tempsum + digitsFound[k];
		}

		amountOfFoundElements.push_back(tempsum);

		// Reset sum

		tempsum = 0;

	}

}