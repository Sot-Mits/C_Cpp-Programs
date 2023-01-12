#include <iostream>
#include <string>
using namespace std;

int main() {
    //Intro
    cout << "C++ \n";
    cout << "Odd (1) or Even (2) parity bit \n";

    //Taking bit
    string parityInput;
    cin >> parityInput;
    while (true) {
        if (parityInput == "2") {
            cout << "You have chosen an even parity bit \n";
            break;
        }
        else if (parityInput == "1") {
            cout << "You have chosen an odd parity bit \n";
            break;
        }
        else {
            cout << "Please enter either 1 or 2 \n";
        }
        cin >> parityInput;
    }

    //Converting bit to int
    int parityMethod = stoi(parityInput);

    //Taking 7-bit data
    //Think I'll use switch statements this time
    string userInput;
    while(true) {
        cout << "Please enter 7 bits \n";
        cin >> userInput;

        //Evaluating Length
        bool legalLength = false;
        if (userInput.length() == 7) {
            legalLength = true;
        }

        //Evaluating Input
        bool legalInput = true;
        int i = 0;
        while (i < userInput.length()) {
            if ((userInput[i] != '0') && (userInput[i] != '1')) {
				legalInput = false;
			}
			i++;
        }
        
       if ((legalLength == true) && (legalInput == true)) {
			cout << "You have entered 7 bits \n";
			break;
		}
		else if ((legalLength == true) && (legalInput == false)) {
			cout << "You have entered 7 characters, but they're not bits \n";
		}
		else if ((legalLength == false) && (legalInput == true)) {
			cout << "You have entered an incorrect amount of bits \n";
		}
		else if ((legalLength == false) && (legalInput == false)) {
			cout << "You have entered neither 7 characters, nor bits \n";
		}

    }

    //Generating bit
    int numberOfOnes = 0;
	int i = 0;
	while (i < 7) {
		if (userInput[i] == '1') {
			numberOfOnes++;
		}
		i++;
	}
	int parityBit = (((numberOfOnes % 2) + parityMethod) % 2);

    //Adding Parity Bit & printing
	string transmittedByte = userInput + to_string(parityBit); 
	cout << "Transmitted byte will be " << transmittedByte << endl;

    //Closing
    return 1;
}
