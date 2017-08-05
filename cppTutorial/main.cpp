#include <iostream>
#include <string>

#include "FBullCowGame.h"

using FText = std::string;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main()
{
	do {
		PrintIntro();
		PlayGame();
	} 
	while (AskToPlayAgain());
	
	return 0;
}

void PrintIntro()
{


	std::cout << "Hello and Welcome\n";
	std::cout << "Guess the letter " << BCGame.GetHiddenWordLength() << " letter isogram" << std::endl;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows  = " << BullCowCount.Cows << std::endl;
	}

	PrintGameSummary();

	return;
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << ". Enter your guess\n";

		std::getline(std::cin, Guess);

		Status = BCGame.IsGuessValid(Guess);

		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			EGuessStatus::OK;
			break;
		}
		std::cout << std::endl;

	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word ?  yes or no\n";
	FText Response = "";
	std::getline(std::cin, Response);

	if (Response[0] == 'y') 
		return true;
	else
		return false;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "YOU WIN\n";
	}
	else
	{
		std::cout << "YOU LOSE\n";
	}
};

void fizzbuzz(int32 x, int32 y, int32 z)
{
	for (int32 i = 1; i <= z; i++)
	{
		if (i % x == 0)
		{
			if (i % y == 0) std::cout << "fizzbuzz" << std::endl;
			else std::cout << "fizz" << std::endl;
		}
		else if (i % y == 0)
		{
			if (i % x == 0) std::cout << "fizzbuzz" << std::endl;
			else std::cout << "bzz" << std::endl;
		}
		else std::cout << i << std::endl;
	}

}
