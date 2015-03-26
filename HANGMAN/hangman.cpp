#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

int main(){
	//setup
	const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed

	std::vector<std::string> words; //collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(time(0));
	random_shuffle(words.begin(), words.end());
	const std::string THE_WORD = words[0];	//word to guess
	int wrong = 0;
	std::string soFar(THE_WORD.size(), '-');
	std::string used = "";

	std::cout << "Welcome to hangman.  Good luck!\n";

	// main loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		std::cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
		std::cout << "\nYou've used the following letters:\n" << used << std::endl;
		std::cout << "\nSo far, the word is:\n" << soFar << std::endl;

		char guess;
		std::cout << "\n\nEnter your guess: ";
		std::cin >> guess;
		guess = toupper(guess); //make uppercase since secretword is uppercase
		while (used.find(guess) != std::string::npos)
		{
			std::cout << "\nYou've already guessed " << guess << std::endl;
			std::cout << "Enter your guess: ";
			std::cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if (THE_WORD.find(guess) != std::string::npos)
		{
			std::cout << "That's right! " << guess << " is in the word.\n";

			//update soFar to include newly guessed letter
			for (int i = 0; i < THE_WORD.length(); ++i)
				if (THE_WORD[i] == guess)
					soFar[i] = guess;
		}
		else
		{
			std::cout << "Sorry, " << guess << " isn't in the word.\n";
			++wrong;
		}
	}

	//shut down
	if (wrong == MAX_WRONG)
		std::cout << "\nYou've been hanged!";
	else
		std::cout << "\nYou guessed it!";

	std::cout << "\nThe word was " << THE_WORD << std::endl;

	system("PAUSE");

	return 0;
}