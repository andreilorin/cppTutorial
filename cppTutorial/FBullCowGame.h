#pragma once

class FBullCowGame
{
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool IsGuessValid(string);

private:
	int CurrentTry;
	int MaxTries;
};
