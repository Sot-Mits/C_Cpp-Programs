#include <iostream>
#include <limits>
#include <random>
using namespace std;

int main() {
    //Intro
    cout << "This program generates a number and you need to guess it." << endl;
    int lowerLimit;
    int upperLimit;

    //Limit Validation
    bool stillCheckingLimits = true;
    while (stillCheckingLimits) {
        //Lower limit checking
        cout << "Please enter the lower limit." << endl;
        cin >> lowerLimit;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Please try again." << endl;
            cin >> lowerLimit;
        }

        //Upper limit checking
        cout << "Please enter the upper limit." << endl;
        cin >> upperLimit;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Please try again." << endl;
            cin >> upperLimit;
        }
        
        //Checking lesser is lowerLimit than upperLimit
        if (lowerLimit > upperLimit) {
            cout << "Lower limit is greater than upper limit. Please try again." << endl;
        }

        else if (lowerLimit == upperLimit) {
            cout << "Both limits are equal. Please try again." << endl;
        }

        else if (lowerLimit < upperLimit) {
            stillCheckingLimits = false;
        }
    }

    //Number generation
    random_device numberGen; //I think I know?
    mt19937 gen(numberGen()); //Idfk
    uniform_int_distribution<> distr(lowerLimit, upperLimit); //Idfk
    int genuineNumber = distr(gen);

    //Guess the number
    bool isGameRunning = true;
    cout << "Please enter a number." << endl;
    while (isGameRunning) {
        int guessedNumber;
        cin >> guessedNumber;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Please try again." << endl;
        }
        
        if (guessedNumber < genuineNumber) {
            cout << "Bigger" << endl;
        }
        else if (guessedNumber > genuineNumber) {
            cout << "Smaller" << endl;
        }
        else if (guessedNumber == genuineNumber) {
            cout << "You guessed correctly!!!" << endl;
            isGameRunning = false;
        }
    }

    return 0;
} 