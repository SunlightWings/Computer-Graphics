#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib> // For rand()

void clearScreen() {
    // Clear the console screen (for UNIX-like systems)
    std::cout << "\033[2J\033[H" << std::flush;
}

void displayRandomChoice() {
    int choice = rand() % 3; // 0: rock, 1: paper, 2: scissors

    switch (choice) {
        case 0:
            std::cout << "Rock\n";
            break;
        case 1:
            std::cout << "Paper\n";
            break;
        case 2:
            std::cout << "Scissors\n";
            break;
        default:
            // Shouldn't reach here, but handle the unexpected just in case
            std::cout << "Error: Invalid choice\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    const int numRounds = 5;

    int userScore = 0;
    int computerScore = 0;

    for (int round = 0; round < numRounds; ++round) {
        clearScreen();

        std::cout << "Round " << round + 1 << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pause for a short time

        clearScreen();
        std::cout << "Guess the choice (0: Rock, 1: Paper, 2: Scissors): ";
        
        int userGuess;
        std::cin >> userGuess;

        if (userGuess < 0 || userGuess > 2) {
            std::cout << "Invalid choice. Please enter 0, 1, or 2.\n";
            --round; // Retry the same round
            std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // Pause before the next round
            continue;
        }

        clearScreen();
        std::cout << "Your choice: ";
        switch (userGuess) {
            case 0:
                std::cout << "Rock\n";
                break;
            case 1:
                std::cout << "Paper\n";
                break;
            case 2:
                std::cout << "Scissors\n";
                break;
        }

        std::cout << "Computer's choice:\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pause for a short time
        displayRandomChoice();

        int computerGuess = rand() % 3; // Computer's random choice

        std::cout << "Computer's choice: ";
        switch (computerGuess) {
            case 0:
                std::cout << "Rock\n";
                break;
            case 1:
                std::cout << "Paper\n";
                break;
            case 2:
                std::cout << "Scissors\n";
                break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // Pause before the next round

        // Determine the winner of the round
        if (userGuess == computerGuess) {
            std::cout << "It's a tie!\n";
        } else if ((userGuess == 0 && computerGuess == 2) ||
                   (userGuess == 1 && computerGuess == 0) ||
                   (userGuess == 2 && computerGuess == 1)) {
            std::cout << "You win this round!\n";
            ++userScore;
        } else {
            std::cout << "Computer wins this round!\n";
            ++computerScore;
        }

        std::cout << "\nCurrent Score:\n";
        std::cout << "User: " << userScore << " | Computer: " << computerScore << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // Pause before the next round
    }

    // Print the winner and final score
    clearScreen();
    std::cout << "Game Over!\n";
    if (userScore > computerScore) {
        std::cout << "Congratulations! You win!\n";
    } else if (userScore < computerScore) {
        std::cout << "Computer wins! Better luck next time.\n";
    } else {
        std::cout << "It's a tie! Well played.\n";
    }

    std::cout << "Final Score:\n";
    std::cout << "User: " << userScore << " | Computer: " << computerScore << "\n";

    return 0;
}
