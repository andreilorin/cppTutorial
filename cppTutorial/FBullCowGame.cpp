#include "FBullCowGame.h"
#include <map>

#define TMap std::map

int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return HiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const 
{
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 5}, {5, 5}, {6, 5} };
	return WordLengthToMaxTries[HiddenWord.length()]; 
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "car";
	HiddenWord = HIDDEN_WORD;

	CurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::IsGuessValid(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
		return EGuessStatus::OK;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	CurrentTry++;

	FBullCowCount BullCowCount;

	int32 WordLength = HiddenWord.length();
	for (int32 HiddenWordChar = 0; HiddenWordChar < WordLength; HiddenWordChar++)
	{
		for (int32 GuessChar = 0; GuessChar < WordLength; GuessChar++)
		{
			if (Guess[GuessChar] == HiddenWord[HiddenWordChar])
			{
				if (HiddenWordChar == GuessChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word)
	{
		Letter = tolower(Letter);

		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		return false;
	}
	return true;
}
