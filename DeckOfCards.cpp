#include<iostream>
#include<string>
#include<new>
#include "Card.h"

using namespace std;

class DeckOfCards
{
private:
	int size = 20;
	Card *deck = new Card[size];

public:
	//Default constructor
	DeckOfCards()
	{
		reset();
	}

	void reset()
	{
		size = 20;
		for (int i = 0; i < size;i++)
		{
			if (i < 10)
			{
				deck[i] = Card("red",i+1);
			}//End if
			else
			{
				deck[i] = Card("black", i - 9);
			}//End else
		}//End for                               
	}//End reset

	void shuffle()
	{
		if (size >= 2)
		{
			Card temp;
			for (int i = 0; i < 50; i++)
			{
				int pos1 = (rand() % (size)) + 0;
				int pos2 = (rand() % (size)) + 0;

				temp = deck[pos1];
				deck[pos1] = deck[pos2];
				deck[pos2] = temp;
			}//End for
		}//End if
		else
		{
			cout << "Too few cards" << endl;
		}//End else
	}//End shuffle

	Card draw()
	{
		Card drawn = deck[(size-1)];
		size = size - 1;
		Card *deck2 = new Card[size];

		memcpy(deck2,deck,size*sizeof(Card));

		delete[] deck;
		Card *deck = new Card[size];
		memcpy(deck, deck2, size*sizeof(Card));

		return drawn;
	}//End draw

	Card peek()
	{
		Card drawn = deck[size - 1];

		return drawn;
	}//End peek

	int numberOfCards()
	{
		return size;
	}//End numberOfCards
};

int main()
{
	DeckOfCards obj;
	obj.peek().print();
	obj.shuffle();
	obj.peek().print();
	obj.draw().print();
	obj.peek().print();
	cout << obj.numberOfCards() << endl;

	return 1;
}