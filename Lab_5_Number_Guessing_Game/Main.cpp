/*******************
Jack Ratcliffe
Computer Science Fall 2025
Due Date 11/11/2025
Lab 5: Number Guessing Game
Description:
********************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RamdomNumber()


bool checkGuess()



void NumerGuessingGame()
{
	cout << "Welcome to the Number Guessing Game!" << endl;
	cout << "I have selected a number between 0 and 100." << endl;
	cout << "You have 20 attempts to guess the correct number." << endl;
}

void WinningMessage1()
{
	cout << "Congratulations! You've guessed the correct number!" << endl;
}

void LosingMessage1(int correctNumber)
{
	cout << "Sorry, you've used all your attempts. The correct number was " << correctNumber << "." << endl;
}

void PlayAgain()
{
	cout << "Would you like to play again?" << endl;
	cout << "Yes or No" << endl;
}

int main()
{ 
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

	int min = 0;
	int max = 100;
	int maxGuesses = 20;
	int randomnumber = RamdomNumber(min, max);

	while()
	{
		if ()
		{
			printWinningMessage1();
		
		}
		else
		{
			printLosingMessage1(randomnumber);
		}
	
	
	}



	return 0;
}