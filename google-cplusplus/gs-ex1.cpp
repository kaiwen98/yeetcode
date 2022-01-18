/*
    The common field cricket chirps in direct proportion to the current temperature. Adding 40 to the number of time a cricket chirps in a minute, then dividing that value by 4 gives us the temperature. Write a program that takes as input the number of chirps in a minute and prints the current temperature. 
*/

#include <iostream>
#include <iomanip>

using namespace std;

float calcTemp(int numChirps) {
    return (numChirps + 40) / 4;
}


int main() {
    int numChirps = 120;
    cout 
        << "Number of chirps: " << numChirps << endl
        // fixed = fixed point
        << "The temperature is " << setprecision(1) << fixed << calcTemp(numChirps) << " degrees." << endl;
    return 0;
}
