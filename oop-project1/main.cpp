#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned)time(NULL)); // generates random numbers each time

	int player;
	while (true)
	{ // loop until user enters a number at least 2 and at most 5
		cout << "How many people are playing bingo? (2-5) -> ";
		cin >> player; // gets the number of players from the user through the keyboard
		if (2 <= player && player <= 5)
		{ // checks whether the number of players is at least 2 and at most 5
			cout << endl;
			break; // terminates the while loop
		}
	}

	int totalScoreOfPlayersArray[5]; // the array that stores the total score of players
	for (int i = 0; i < player; i++)
	{ // the loop that assigns zero point to all players
		totalScoreOfPlayersArray[i] = 0;
	}

	for (int i = 1; i <= 3; i++)
	{ // the loop that allows the game to be played 3 times
		void CreateCards(int card[][15], int numberOfCards);
		void SelectedCards(int selectedCardsArray[5], int player, int card[10][15]);
		void SelectedNumbers(int selectedNumbersArray[][10], int numberOfRow);
		int FirstPhase(int counterArray[5], int totalScoreOfPlayersArray[5], int player, int card[10][15], int selectedCardsArray[10], int selectedNumbersArray[9][10]);
		int SecondPhase(int counterArray[5], int totalScoreOfPlayersArray[5], int player, int card[10][15], int selectedCardsArray[10], int selectedNumbersArray[9][10]);
		int ThirdPhase(int counterArray[5], int totalScoreOfPlayersArray[5], int player, int card[10][15], int selectedCardsArray[10], int selectedNumbersArray[9][10]);

		cout << "The bingo cards are creating..." << endl;
		int card[10][15];	  // two-dimensional array that stores the bingo cards
		CreateCards(card, 9); // the function that generates the bingo cards

		cout << "The number of players is " << player << endl;
		cout << "Randomly selected cards for players: " << endl;
		int selectedCardsArray[5];						 // one-dimensional array that stores the randomly selected bingo cards to each player
		SelectedCards(selectedCardsArray, player, card); // the function that generates the randomly selected bingo cards to each player

		cout << "SELECTED NUMBERS:" << endl;
		int selectedNumbersArray[9][10];		  // two-dimensional array that stores the bingo bag
		SelectedNumbers(selectedNumbersArray, 8); // the function that generates the bingo bag

		int counterArray[5];																						 // one-dimensional array that stores the number of -1 on the players' cards.
		FirstPhase(counterArray, totalScoreOfPlayersArray, player, card, selectedCardsArray, selectedNumbersArray);	 // the function that finds the winner of the first Cinko and gives 5 points to the winner
		SecondPhase(counterArray, totalScoreOfPlayersArray, player, card, selectedCardsArray, selectedNumbersArray); // the function that finds the winner of the second Cinko and gives 10 points to the winner
		ThirdPhase(counterArray, totalScoreOfPlayersArray, player, card, selectedCardsArray, selectedNumbersArray);	 // the function that finds the winner of the Bingo and gives 15 points to the winner
		cout << endl
			 << endl
			 << endl
			 << endl
			 << endl; // seperates the games from each other
	}

	for (int i = 0; i < player; i++)
	{ // the loop that prints the total points of the players
		cout << "The score of player " << i << ":   " << totalScoreOfPlayersArray[i] << endl;
	}

	int maximumScore = totalScoreOfPlayersArray[0]; // assume that player 0 has maximum score
	for (int i = 1; i < player; i++)
	{
		if (totalScoreOfPlayersArray[i] > maximumScore)
		{ // the condition that finds the maximum score
			maximumScore = totalScoreOfPlayersArray[i];
		}
	}
	for (int i = 0; i < player; i++)
	{
		if (totalScoreOfPlayersArray[i] == maximumScore)
		{ // the condition that finds the player(s) who have the maximum score
			cout << endl
				 << "Player " << i << " wins." << endl;
		}
	}
}

void CreateCards(int card[][15], int numberOfCards)
{
	for (int i = 0; i <= numberOfCards; i++)
	{ // iterates the number of the bingo cards(row)
		cout << "Card " << i << ":   ";
		for (int j = 0; j <= 14; j++)
		{								  // iterates the numbers on the bingo card(column)
			card[i][j] = rand() % 90 + 1; // generates a random number that is at least 1 and at most 90

			if (j >= 1)
			{ // to start with index [0][1]
				bool check = true;
				do
				{
					for (int k = 0; k < j; k++)
					{ // the loop that compares all the numbers until [i][j] on a card with previous numbers
						if (card[i][j] == card[i][k])
						{								  // checks whether number already exists in  the array
							card[i][j] = rand() % 90 + 1; // assigns a new number that is at least 1 and at most 90
							check = true;
							break; // terminates the for loop
						}
						else
						{
							check = false;
						}
					}
				} while (check); // starts index [0][1] and compares all the numbers on a card with previous numbers
			}
			cout << card[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void SelectedCards(int selectedCardsArray[5], int player, int card[10][15])
{
	for (int i = 0; i < player; i++)
	{										 // iterates the randomly selected bingo cards(column)
		selectedCardsArray[i] = rand() % 10; // generates a random number that is at least 0 and at most 9

		if (i >= 1)
		{ // to start with index [1]
			bool check = true;
			do
			{
				for (int j = 0; j < i; j++)
				{ // the loop that compares all the numbers until [i] with previous numbers
					if (selectedCardsArray[i] == selectedCardsArray[j])
					{										 // checks whether number already exists in  the array
						selectedCardsArray[i] = rand() % 10; // assigns a new number that is at least 0 and at most 9
						check = true;
						break; // terminates the for loop
					}
					else
					{
						check = false;
					}
				}
			} while (check); // starts index [1] and compares all the numbers with previous numbers
		}
		cout << selectedCardsArray[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < player; i++)
	{ // iterates the number of the selected bingo cards(row)
		cout << "Bingo card of player " << i << ":   ";
		for (int j = 0; j <= 14; j++)
		{ // iterates the numbers on the selected bingo card(column)
			cout << card[selectedCardsArray[i]][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void SelectedNumbers(int selectedNumbersArray[][10], int numberOfRow)
{
	int array[90]; // one-dimensional array that stores the bingo bag
	for (int i = 0; i < 90; i++)
	{								// iterates 90 elements for the one-dimensional array
		array[i] = rand() % 90 + 1; // // generates a random number that is at least 1 and at most 90

		if (i >= 1)
		{ // to start with index [1]
			bool check = true;
			do
			{
				for (int j = 0; j < i; j++)
				{ // the loop that compares all the numbers until [i] with previous numbers
					if (array[i] == array[j])
					{								// checks whether number already exists in  the array
						array[i] = rand() % 90 + 1; // assigns a new number that is at least 1 and at most 90
						check = true;
						break; // terminates the for loop
					}
					else
					{
						check = false;
					}
				}
			} while (check); // starts index [1] and compares all the numbers with previous numbers
		}
	}

	int rowOfArray = 0; // to make the numbers in the bingo bag a two-dimensional array
	for (int i = 0; i <= numberOfRow; i++)
	{ // iterates the row of the two-dimensional array
		for (int j = 0; j <= 9; j++)
		{													// { // iterates the cloumn of the two-dimensional array
			selectedNumbersArray[i][j] = array[rowOfArray]; // assigns array which has unique random integers to selectedNumbersArray which is the bingo bag
			cout << selectedNumbersArray[i][j] << " ";		// prints the bingo bag
			rowOfArray++;
		}
		cout << endl;
	}
	cout << endl;
}

int FirstPhase(int counterArray[5], int totalScoreOfPlayersArray[5], int player, int card[10][15], int selectedCardsArray[10], int selectedNumbersArray[9][10])
{
	for (int i = 0; i < player; i++)
	{						 // the loop that assigns zero point to all players
		counterArray[i] = 0; // the array that stores the number of -1 on the players' card
	}

	for (int i = 0; i <= 8; i++)
	{ // iterates the row of the bingo bag
		for (int j = 0; j <= 9; j++)
		{ // iterates the colums of the bingo bag

			for (int k = 0; k < player; k++)
			{ // iterates the row of the players' cards
				for (int l = 0; l <= 14; l++)
				{ // iterates the column of the players' cards

					if (selectedNumbersArray[i][j] == card[selectedCardsArray[k]][l])
					{										 // all the elements in the bingo bag is compared with numbers on the players' cards of all players one by one
						card[selectedCardsArray[k]][l] = -1; // assigns -1 to be matched numbers
						counterArray[k]++;					 // increases the number of -1 on the players' card
						break;								 // terminates the inner loop
					}
				}
			}

			for (int k = 0; k < player; k++)
			{ // iterates the number of -1 on the players' card
				if (counterArray[k] == 5)
				{ // checks the number of -1 on the players' card
					cout << "The winner of the first Cinko is player " << k << ":" << endl;
					for (int l = 0; l < player; l++)
					{ // iterates the row of the players' cards
						for (int m = 0; m <= 14; m++)
						{												   // iterates the column of the players' cards
							cout << card[selectedCardsArray[l]][m] << " "; // prints the result of the first Cinko on the screen
						}
						cout << endl;
					}
					totalScoreOfPlayersArray[k] = totalScoreOfPlayersArray[k] + 5; // gives 5 points to the winner of the first Cinko
					cout << endl;
					return 0; // terminates the function
				}
			}
		}
	}
	return 0; // terminates the function
}

int SecondPhase(int counterArray[5], int totalScoreOfPlayersArray[5], int player, int card[10][15], int selectedCardsArray[10], int selectedNumbersArray[9][10])
{
	for (int i = 0; i <= 8; i++)
	{ // iterates the row of the bingo bag
		for (int j = 0; j <= 9; j++)
		{ // iterates the colums of the bingo bag

			for (int k = 0; k < player; k++)
			{ // iterates the row of the players' cards
				for (int l = 0; l <= 14; l++)
				{ // iterates the column of the players' cards

					if (selectedNumbersArray[i][j] == card[selectedCardsArray[k]][l])
					{										 // all the elements in the bingo bag is compared with the numbers on the players' cards of all players one by one
						card[selectedCardsArray[k]][l] = -1; // assigns -1 to be matched numbers which are left from first Cinko
						counterArray[k]++;					 // increases the number of -1 on the players' card
						break;								 // terminates the inner loop
					}
				}
			}

			for (int k = 0; k < player; k++)
			{ // iterates the number of -1 on the players' card
				if (counterArray[k] == 10)
				{ // checks the number of -1 on the players' card
					cout << "The winner of the second Cinko is player " << k << ":" << endl;
					for (int l = 0; l < player; l++)
					{ // iterates the row of the players' cards
						for (int m = 0; m <= 14; m++)
						{												   // iterates the column of the players' cards
							cout << card[selectedCardsArray[l]][m] << " "; // prints the result of the second Cinko on the screen
						}
						cout << endl;
					}
					totalScoreOfPlayersArray[k] = totalScoreOfPlayersArray[k] + 10; // gives 10 points to the winner of the second Cinko
					cout << endl;
					return 0; // terminates the function
				}
			}
		}
	}
	return 0; // terminates the function
}

int ThirdPhase(int counterArray[5], int totalScoreOfPlayersArray[5], int player, int card[10][15], int selectedCardsArray[10], int selectedNumbersArray[9][10])
{
	for (int i = 0; i <= 8; i++)
	{ // iterates the row of the bingo bag
		for (int j = 0; j <= 9; j++)
		{ // iterates the colums of the bingo bag

			for (int k = 0; k < player; k++)
			{ // iterates the row of the players' cards
				for (int l = 0; l <= 14; l++)
				{ // iterates the column of the players' cards

					if (selectedNumbersArray[i][j] == card[selectedCardsArray[k]][l])
					{										 // all the elements in the bingo bag is compared with the numbers on the players' cards of all players one by one
						card[selectedCardsArray[k]][l] = -1; // assigns -1 to be matched numbers which are left from second Cinko
						counterArray[k]++;					 // increases the number of -1 on the players' card
						break;								 // terminates the inner loop
					}
				}
			}

			for (int k = 0; k < player; k++)
			{ // iterates the number of -1 on the players' card
				if (counterArray[k] == 15)
				{ // checks the number of -1 on the players' card
					cout << "The winner of the Bingo is player " << k << ":" << endl;
					for (int l = 0; l < player; l++)
					{ // iterates the row of the players' cards
						for (int m = 0; m <= 14; m++)
						{												   // iterates the column of the players' cards
							cout << card[selectedCardsArray[l]][m] << " "; // prints the result of the third Cinko on the screen
						}
						cout << endl;
					}
					totalScoreOfPlayersArray[k] = totalScoreOfPlayersArray[k] + 15; // gives 15 points to the winner of the third Cinko
					cout << endl;
					return 0; // terminates the function
				}
			}
		}
	}
	return 0; // terminates the function
}
