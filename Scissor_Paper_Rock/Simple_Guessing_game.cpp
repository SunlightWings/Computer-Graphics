#include <iostream>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function

int main() {
    // Seed for random number generation
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "Can you guess the secret number between 1 and 100?\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        attempts++;

        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }

    } while (guess != secretNumber);

    return 0;
}


/*
Output:
Welcome to the Number Guessing Game!
Can you guess the secret number between 1 and 100?
Enter your guess: 4
Too low! Try again.
Enter your guess: 50
Too low! Try again.
Enter your guess: 80
Too high! Try again.
Enter your guess: 70
Too high! Try again.
Enter your guess: 69
Too high! Try again.
Enter your guess: 60
Too low! Try again.
Enter your guess: 64
Too low! Try again.
Enter your guess: 65
Too low! Try again.
Enter your guess: 66
Too low! Try again.
Enter your guess: 67
Too low! Try again.
Enter your guess: 68
Congratulations! You guessed the correct number in 11 attempts.
  */
