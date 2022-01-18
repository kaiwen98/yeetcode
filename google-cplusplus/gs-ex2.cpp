/*
    Write a program that will compute your final grade for a programming course you are taking. Here is the grading scheme:

    Final grades will be based on the following:
    40% Assignments   15% Midterm Examination
    35% Final Examination
    10% Class Participation Grade 

    Your program should ask the user for the four assignment scores, the midterm, final and section grades. Then, the final score is calculated and printed. To do the calculations, you average the four assignment scores together and then multiply it by 0.4 (40%). You then multiply the midterm score by 0.15, the final by 0.35 and the participation grade by 0.1. Then you add all the results of these multiplications together.

    Use functions wherever you can in this program. You can create a function to get the input by passing in as a parameter the string to be displayed in an explanatory cout. 
*/

#include <iostream>
#include <iomanip>
#define ASSIGNMENTS 0
#define MIDTERMS 1
#define FINALS 2
#define PART 3

using namespace std;

float calcTemp(int numChirps) {
    return (numChirps + 40) / 4;
}

template <typename T>
void printElement(T t, const int& width) {
    const char seperator = ' ';
    cout << left << setw(width) << setfill(seperator) << t;
}

void askForInput(float* scores) {
    int assignmentCount = 0;
    float temp;
    float sum = 0;
    while (assignmentCount++ < 4) {
        cout << "What is your Assignment " << assignmentCount << " Score?" << endl;
        cin >> temp;
        sum += temp / 100;
        cout << sum << endl;
    }

    *(scores + ASSIGNMENTS) = (sum / 4) * 0.4;

    cout << "What is your Midterm Score?" << endl;
    cin >> temp;
    *(scores + MIDTERMS) = temp / 100 * 0.15;

    cout << "What is your Finals Score?" << endl;
    cin >> temp;
    *(scores + FINALS) = temp / 100 * 0.35;

    cout << "What is your Class Participation Score?" << endl;
    cin >> temp;
    *(scores + PART) = temp / 100 * 0.10;
}

int main() {
    float* scores = (float*) malloc(3 * sizeof(float));
    askForInput(scores);
    // cout 
    //     << *(scores + ASSIGNMENTS) << " "  
    //     << *(scores + MIDTERMS) << " " 
    //     << *(scores + FINALS) << " "   
    //     << *(scores + PART) << " "  
    //     << endl;

    printElement("Assignment Scores", 30);
    printElement(*(scores + ASSIGNMENTS), 30);
    cout << endl;
    printElement("Midterm Scores", 30);
    printElement(*(scores + MIDTERMS), 30);
    cout << endl;
    printElement("Finals Scores", 30);
    printElement(*(scores + FINALS), 30);
    cout << endl;
    printElement("Class Part Scores", 30);
    printElement(*(scores + PART), 30);
    return 0;
}
