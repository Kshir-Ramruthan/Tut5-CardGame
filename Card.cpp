#include "Card.h"

#include<iostream>
#include<string>

using namespace std;

	std::string Card::colour()
	{
		return col;
	}//End colour

	int Card::number()
	{
		return num;
	}//End number

	void Card::print()
	{
		cout << "Card is: " <<col << " " << num << endl;
	}//End print

	//Default constructor
	Card::Card(string colo, int number)
	{
		col = colo;
		num = number;
	}//End Constructor

	//Default destructor
	Card::~Card()
	{
	
	}//End Destructor