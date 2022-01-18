// file.cpp, Maggie Johnson
// Description: An illustration of file processing
/*
    Example 9: Processing Files
    File processing in C++ is performed using fstream. To save to a file, we declare an ofstream, and open it using the "out" mode. Check this out in the following example.
*/
#include <fstream>
#include <iostream>
using namespace std;

void display(char file_name[20]) {
    char first_name[30], last_name[30]; int age;
    ifstream People(file_name, ios::in);
    People >> first_name >> last_name >> age;
    cout << first_name << endl;
    cout << last_name << endl;
    cout << age << endl;
}

void displayLoop(char file_name[20]) {
    string buf;
    ifstream People(file_name, ios::in);
    while (getline(People, buf)) {
        cout << buf << endl;
    }
    People.close();
}

void inputLoop(ofstream &People) {
    string input = "";
    do {
        cin >> input;
        if (input == "exit") return;
        People << input << endl;
    } while (true);
}

int main() {
    char first_name[30], last_name[30]; int age;
    char file_name[20];
    // Collect the data.
    //   cout << "Enter First Name: "; cin >> first_name;
    //   cout << "Enter Last Name: "; cin >> last_name;
    //   cout << "Enter Age: "; cin >> age;
    cout << endl << "Enter the name of the file: "; cin >> file_name;

    

    // Create an ofstream called People, open the stream for output.
    ofstream People(file_name, ios::out);
    inputLoop(People);
    // Write the output to the stream.
    // People << first_name << endl << last_name << endl << age << endl; 
    displayLoop(file_name);
    return 0;
} 