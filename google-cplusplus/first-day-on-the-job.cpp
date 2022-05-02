/*
    Example 7: Next steps with decomposition - Your first day on the job
    You have just gotten a position as a salesperson for the ExerShoe company, specializing in high-end exercise shoes costing around $225 per pair. Your boss has given you three options for compensation, which you must choose before you begin your first day:

    Straight salary of $600 per week;
    A salary of $7.00 per hour plus a 10% commission on sales, 40 hours per week;
    No salary, but 20% commissions and $20 for each pair of shoes sold
    You, being an expert C++ programmer, figure you can write a program to help decide the best choice of compensation.

    A common approach in doing decomposition for a larger program is to create a main function that reads like an outline to solving the problem. Then, we write the functions to do each task.

    My approach is to compare the weekly compensation across the 3 schemes.

    The data showed that:
        Weekly Sales > 9  : Compensation 3 is most profitable
        Weekly Sales > 15 : Compensation 2 is most profitable
        Else              : Compensation 1 is most profitable

        If you are not very good at selling, Compensation 1 is good.
        If you can sell, Compensation 3 is good.
        Compensation 2 seems to be inferior in all scenarios.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int weeklySales = 0;

float compensation1() {
    float answer = 600;
    return answer;
}

float compensation2() {
    float answer = 7 * 40 + 0.1 * weeklySales * 225;
    return answer;
}

float compensation3() {
    float answer = weeklySales * (0.2 * 225 + 20);
    return answer;
}

template<typename T> 
void printElement(T t, const int& width)
{
    const char seperator = ' ';
    cout << left << setw(width) << setfill(seperator) << t;
}


int main() {
    printElement("Weekly Sales", 30); 
    printElement("Compensation 1", 30);
    printElement("Compensation 2", 30);
    printElement("Compensation 3", 30);
    cout << endl;
    for (weeklySales = 0; weeklySales < 20; weeklySales += 1) {
        printElement(weeklySales, 30); 
        printElement(compensation1(), 30);
        printElement(compensation2(), 30);
        printElement(compensation3(), 30);
        cout << endl;
    }
    return 0;
}