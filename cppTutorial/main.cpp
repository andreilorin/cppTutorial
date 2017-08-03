#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();

int main()
{
	cout << "Hello\n";

	PrintIntro();
	string MyGuess = GetGuess();
			
	cout << MyGuess << endl;

	return 0;
}

void PrintIntro()
{
	constexpr int WORLD_LENGHT = 7;

	cout << "Welcome\n";
	cout << "Guess the letter " << WORLD_LENGHT << " letter isogram";
	cout << endl;
}

string GetGuess()
{
	cout << "Enter your guess\n";

	string Guess = "";

	getline(cin, Guess);

	return Guess;
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


