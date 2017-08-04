#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

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
	constexpr int WORLD_LENGHT = 7;

	cout << "Hello and Welcome\n";
	cout << "Guess the letter " << WORLD_LENGHT << " letter isogram";
	cout << endl;
}

void PlayGame()
{
	constexpr int TURNS = 5;

	for (int i = 0; i < TURNS; i++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
	}
}

string GetGuess()
{
	cout << "Enter your guess\n";

	string Guess = "";

	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again ?  yes or no";
	string Response = "";
	getline(cin, Response);

	if (Response[0] == 'y') 
		return true;
	else
		return false;
}

void fizzbuzz(int x, int y, int z)
{
	for (int i = 1; i <= z; i++)
	{
		if (i % x == 0)
		{
			if (i % y == 0) cout << "fizzbuzz" << endl;
			else cout << "fizz" << endl;
		}
		else if (i % y == 0)
		{
			if (i % x == 0) cout << "fizzbuzz" << endl;
			else cout << "bzz" << endl;
		}
		else cout << i << endl;
	}
}

