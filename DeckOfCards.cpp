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
	Card reset()
	{
		size = 20;
		Card newDeck[20];
		for (int i = 0; i < size;i++)
		{
			if (size < 10)
			{
				newDeck[i] = Card("red",i+1);
			}//End if
			else
			{
				newDeck[i] = Card("black", i - 9);
			}//End else
		}//End for
		return *newDeck;                                          //Possible error
	}//End reset

	void shuffle()
	{
		if (size >= 2)
		{
			Card temp;
			for (int i = 0; i < 50; i++)
			{
				int pos1 = (rand() % 49) + 0;
				int pos2 = (rand() % 49) + 0;

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
		Card drawn = deck[size-1];
		size = size - 1;
		Card *deck2 = new Card[size];

		memcpy(deck2,deck,sizeof(Card));

		delete deck;
		deck = deck2;

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