/*
    https://developers.google.com/edu/c++/getting-started
    With reference to one of the problem sets.

    (1)
    An experiment:

    When an input error is made, the stream "breaks," cin returns false, and the program stops. It's very important to guard against such errors as we did in the program above. But what if we want to recover from the error, rather than have the program stop? There are two steps to recovering from an error:

    Clear the error with cin.clear().
    Remove the incorrect characters from the stream. One way to do this is with cin.ignore().
    Write a program that recovers from bad input using these two steps. Use Google to search for how these methods work.

    (2)
    Time for us to start writing computer games! This first one will be a bit simple, but it's a start. Our task is to write a program that implements a guessing game. Our program generates a random number between 0 and 100. The player must guess the secret number. The program provides hints like "that's too high" or "that's too low" until the player finally guesses the secret number.

    We will work on this game in three steps. 

    Figure out how to generate a random number within a given range of values.
    Create a main function that processes one guess from the player, and provides hints.
    Add what we need to allow for multiple guesses until the player guesses the number.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ios>
#include <limits>

int LOW_RANGE = 0;
int HIGH_RANGE = 5;

int generateRandomNumber() {
    srand(time(NULL));
    std::cout << "Game begins! The seed is " << rand() << std::endl;
    int number = rand() % (HIGH_RANGE - LOW_RANGE) + LOW_RANGE;
    return number;
}

void resetCinBuffer() {
    std::cin.clear();
    // Ignores characters for max char length and also newline characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int input = -1;
    
    std::cout 
        << "Game begins! The seed is " 
        << rand() 
        << std::endl;

    int number = generateRandomNumber();

    while (true) {
        if (!(std::cin >> input)) {
            resetCinBuffer();
            std::cout 
                << "You have input a non integer...." << std::endl;
            continue;
        }

        if (input == number) break;

        std::cout 
            << "The number is too " 
            << (input < number ? "small" : "big") 
            << ". Please try again!" 
            << std::endl;
    }
    std::cout << "You did it! The number is " << number << std::endl;
    return 0;
}