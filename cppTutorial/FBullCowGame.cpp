#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "car";

	MaxTries = MAX_TRIES;
	HiddenWord = HIDDEN_WORD;
	CurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::IsGuessValid(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
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

int32 FBullCowGame::GetHiddenWordLength() const { return HiddenWord.length(); }
