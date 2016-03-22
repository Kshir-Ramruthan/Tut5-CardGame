#pragma once
#include<iostream>
#include<string>
using namespace std;

class Card
{
	private:
		//Class variables
		std::string col;
		int num;

	public:
		//Class methods
		std::string colour();
		int number();
		void print();

		//Default constructor
		Card(std::string colo, int number);

		//Default destructor
		~Card();
};//End Class