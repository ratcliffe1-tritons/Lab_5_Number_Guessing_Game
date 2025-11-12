/*******************
Jack Ratcliffe
Computer Science Fall 2025
Due Date 11/11/2025
Lab 5: Number Guessing Game
Description: A number guessing game where the user has 20 attempts to guess a randomly generated number between 0 and 100.
********************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int RandomNumber(int min, int max);
int getUserGuess();
bool checkGuess(int userGuess_, int randomNumber, int num_of_guesses);
bool PlayAgain();
void WinningMessage();
void LosingMessage(int correctNumber);
void printNumberGuessingGame();


int wins = 0;
int losses = 0;

int main()
{
	srand(static_cast<unsigned int>(time(0))); // seed the random number generator
	int min = 0;
	int max = 100;
	int maxGuesses = 20;
	
	do
	{
		bool Replay = false; // indicates if the user wants to replay the game
		int randomnumber = RandomNumber(min, max); // generate a random number between 0 and 100
		printNumberGuessingGame(); // prints the Number Guessing Game welcome message
		cout << endl; 
		int userGuess = 0;
		int attempts = 0;
		
		while (attempts < maxGuesses) // loop until the user has used all 20 attempts
		{
			attempts++;
			userGuess = getUserGuess(); // get the user's guess
	
			do // validation loop for user input
			{
				if (userGuess < 0 || userGuess > 100) // check if the guess is out of range and if so, prompt for a valid response
				{
					cout << "Please enter a valid response." << endl;
					cin >> userGuess;
				}
			} while (userGuess < 0 || userGuess > 100);
			
			if (!cin) // checks if stream is in a failed state
			{
				cout << "Invalid input. Stream in failed state, exiting program." << endl;
				return 1;
			}

			if (checkGuess(userGuess, randomnumber, attempts)) // check if the user's guess is correct
			{
				WinningMessage(); // prints winning message
				wins++;
				
				cout << endl;
				Replay = PlayAgain(); // asks the user if they want to play again
				break; 
			}
			else // if the guess is incorrect and prints the number of attempts left
			{
				cout << "Try again! You have " << maxGuesses - attempts << " attempts left." << endl;
			}
		}

		if (attempts >= maxGuesses && !checkGuess(userGuess, randomnumber, attempts)) // checks if the user has no attempts left
		{
			LosingMessage(randomnumber); // prints losing message
			losses++;
			cout << endl;

			Replay = PlayAgain(); // asks the user if they want to play again
		}
		if (Replay) // if the user wants to replay, the loop continues
			{
				continue; //restarts the game
			}
			else // if the user doesn't want to replay
			{
			break; // exits the loop and ends the program
			}
		
	} while (true); 

	return 0; 
}

int RandomNumber(int min, int max) // generates a random number between min and max
{
    // returns a random number between min and max 
    return rand() % (max - min + 1) + min;

	/*
	Precondition: min and max are integers where min <= max
	Postcondition: returns a random integer between min and max inclusive
	*/
}


int getUserGuess() // gets the user's guess
{
	int guess;
	cout << "Enter your guess: ";
	cin >> guess;
	return guess;

	/*
	Precondition: none
	Postcondition: 
	- returns the user's guess as an integer 
	- if the input is non-integer, the stream enters a failed state
	*/
}

void printNumberGuessingGame() // prints the Number Guessing Game welcome message
{
	cout << "\nWelcome to the Number Guessing Game!" << 
		"\nI have selected a number between 0 and 100." << 
		"\nYou have 20 attempts to guess the correct number." <<
		"\nGood luck!" << endl;
	/*
	Precondition: none
	Postcondition: prints the welcome message for the Number Guessing Game
	*/
}

void WinningMessage() // prints a random winning message
{
	int msgNum = rand() % 10 + 1; // generates a random number between 1 and 10
	switch (msgNum) // selects a winning message based on the random number
	{
	case 1: cout << "Congratulations! You've guessed the correct number!"; break;
	case 2: cout << "Well done! You found the number!"; break;
	case 3: cout << "Awesome! You nailed it!"; break;
	case 4: cout << "Fantastic! You got it right!"; break;
	case 5: cout << "Brilliant! You guessed the number!"; break;
	case 6: cout << "Superb! You found the correct number!"; break;
	case 7: cout << "Excellent! You guessed it!"; break;
	case 8: cout << "Great job! You got the number right!"; break;
	case 9: cout << "Impressive! You guessed the correct number!"; break;
	case 10: cout << "Congratulations! You've cracked the code!"; break;
	}
	/*
	Precondition: none
	Postcondition: prints a random winning message to the program
	*/
}


void LosingMessage(int correctNumber) // prints a random losing message with the correct number
{
	int msgNum = rand() % 10 + 1;
	switch (msgNum) 
	{
	case 1: cout << "Sorry, you've used all your attempts. The correct number was " << correctNumber << "."; break;
	case 2: cout << "Unfortunately, you didn't guess the number. It was " << correctNumber << "."; break;
	case 3: cout << "Better luck next time! The number was " << correctNumber << "."; break;
	case 4: cout << "You didn't get it this time. The correct number was " << correctNumber << "."; break;
	case 5: cout << "Don't worry! The number was " << correctNumber << "."; break;
	case 6: cout << "Keep trying! The correct number was " << correctNumber << "."; break;
	case 7: cout << "Almost had it! The number was " << correctNumber << "."; break;
	case 8: cout << "Not quite! The correct number was " << correctNumber << "."; break;
	case 9: cout << "You were close! The number was " << correctNumber << "."; break;
	case 10: cout << "Good effort! The correct number was " << correctNumber << "."; break;
	}
	/*
	Precondition: correctNumber is an integer representing the correct number
	Postcondition: prints a random losing message with the correct number to the program
	*/
} 

bool checkGuess(int userGuess_, int randomNumber, int num_of_guesses) // checks if the user's guess is correct
{
	if (userGuess_ == randomNumber) 
	{
		return true; 
	}
	else
	{
		return false;
	}
	/*
	Precondition: userGuess_ and randomNumber are valid integers
	Postcondition: returns true if userGuess_ equals randomNumber, otherwise returns false
	*/
}

bool PlayAgain() // asks the user if they want to play again
{
	int msgNum = rand() % 10 + 1;
	switch (msgNum)
	{
	case 1: cout << "Do you want to try again?"; break;
	case 2: cout << "Would you like another go?"; break;
	case 3: cout << "Fancy another round?"; break;
	case 4: cout << "Care to play again?"; break;
	case 5: cout << "Up for another game?"; break;
	case 6: cout << "Want to give it another shot?"; break;
	case 7: cout << "Ready for another round?"; break;
	case 8: cout << "How about another game?"; break;
	case 9: cout << "Shall we play again?"; break;
	case 10: cout << "Would you like to play again?"; break;
	}

	cout << " (y/n): ";

	char userInput;
	bool validInput = false; // flag to check for valid input
	do // checks for valid input
	{
		cin >> userInput;
		if (userInput == 'y' || userInput == 'Y' || userInput == 'n' || userInput == 'N')
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input. Please enter 'y' for yes or 'n' for no: ";
		}
	} while (!validInput); 

	if (userInput == 'y' || userInput == 'Y') // if the user wants to play again
	{
		return true;
	}
	if (userInput == 'n' || userInput == 'N') // if the user doesn't want to play again
	{
		cout << endl;
		cout << "Thank you for playing the Number Guessing Game!" << "\nNumber of wins: "
			<< wins << "\nNumber of losses: " << losses << endl;
		return false;
	}
	return false;
	/*
	Precondition: none
	Postcondition: 
	- prints a random play again message
	- prompts the user for input (y/n)
	- returns true if the user wants to play again, otherwise returns false 
	- displays the total wins and losses
	- handles invalid input by prompting the user until a valid response is received
	*/
}