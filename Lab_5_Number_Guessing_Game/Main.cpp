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
int RandomNumber(int min, int max);
int getUserGuess();
bool checkGuess(int userGuess_, int randomNumber, int num_of_guesses);



void printNumberGuessingGame()
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

bool checkGuess(int userGuess_, int randomNumber, int num_of_guesses)
{
	if (userGuess_ == randomNumber)
	{
		WinningMessage1();
		return true;
	}
	else
	{
		LosingMessage1(randomNumber);
		return false;
	}
}



int main()
{ 
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

	int min = 0;
	int max = 100;
	int maxGuesses = 20;
	int randomnumber = RandomNumber(min, max);

	printNumberGuessingGame();

	int userGuess = 0;
	int attempts = 0;

	while(attempts < maxGuesses)
	{
		userGuess = getUserGuess();
		if (checkGuess(userGuess, RandomNumber, attempts))
		{
			return 0;
			attempts == attempts + 1;

			WinningMessage1();
		}

		if (attempts > maxGuesses)
		{
			LosingMessage1(randomnumber);
		}
		else
		{
			cout << " Try again! You have " << maxGuesses - attempts << " attempts left." << endl;
		}
			
	
	}



	return 0;
}