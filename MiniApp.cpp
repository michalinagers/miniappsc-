#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

void KeepCounting();
void SquareRootCalculator();
void EncryptText();
void DecryptText();


int main() {

    cout << "P4CS Mini Applications \n ----------------------\n";
    cout << "1) Keep Counting\n";
    cout << "2) Square Root Calculator\n";
    cout << "3) Encrypt Text (Caesar Cipher)\n";
    cout << "4) Decrypt Text (Caesar Cipher)\n";
    cout << "9) Quit\n";
    cout << "Please enter option:\n";

    int input;
    cin >> input;

    switch (input) {
    case 1:
        KeepCounting();
        break;
    case 2:
        SquareRootCalculator();
        break;
    case 3:
        EncryptText();
        break;
    case 4:
        DecryptText();
        break;
    case 9:
        cout << "Quitting program\n";
        break;
    default:
        cout << "Error, bad input, quitting\n";
        break;
    }
    return 0;
}


void KeepCounting() {

    cout << "Keep Counting\n";
    cout << " ----------------------\n";
    cout << "You will be presented with 10 arithmetic questions. \nAfter the first question, the left - hand operand is the result of the previous addition\n";

    srand((unsigned int)time(nullptr));
    int correctAnswers = 0;
    int totalQuestions = 10;

    for (int i = 0; i < totalQuestions; i++) {
        int firstNumber = rand() % 10 + 1;
        int secondNumber = rand() % 10 + 1;
        int userAnswer;
        int correctResult;
        bool isAddition = rand() % 2 == 0;

        if (isAddition) {
            correctResult = firstNumber + secondNumber;
            cout << "Question " << (i + 1) << ": " << firstNumber << " + " << secondNumber << " = \n";
        }
        else {
            correctResult = firstNumber - secondNumber;
            cout << "Question " << (i + 1) << ": " << firstNumber << " - " << secondNumber << " = \n";
        }

        cin >> userAnswer;

        if (userAnswer == correctResult) {
            cout << "Correct answer!\n";
            correctAnswers++;
        }
        else {

            cout << "Incorrect answer! The correct answer is " << correctResult << ".\n";


        }

        

    }

    cout << "You got " << correctAnswers << " out of " << totalQuestions << " questions correct.\n";

}

void SquareRootCalculator() {

    double userInput;
    int decimal;
    cout << "Square Root Calculator\n";
    cout << " ----------------------\n";
    cout << "Please enter a positive number:\n";
    cin >> userInput;

    while (userInput <= 0 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter only positive numbers\n";
        cin >> userInput;
    }

    cout << "How many decimal places do you want the solution calculated to (1 to 6 decimal places):\n";
    cin >> decimal;

    if (decimal < 1 || decimal > 6 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter between 1 to 6 decimal places\n";
        cin >> decimal;
    }

    double precision = pow(10, -decimal);
    double lowerBound = 0;
    double upperBound = userInput;
    double midpoint;

    while ((upperBound - lowerBound) > precision) {
        midpoint = (lowerBound + upperBound) / 2.0;
        double square = midpoint * midpoint;

        if (square > userInput) {
            upperBound = midpoint;  
        }
        else {
            lowerBound = midpoint; 
        }
    }

    cout << "The square root of " << userInput << " to " << decimal << " decimal places is " << fixed << setprecision(decimal) << midpoint << endl;
}


void EncryptText() {
    string userInput;
    string validChar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    int shift;

    cout << "Encrypt Text\n";
    cout << "----------------------\n";

 
    while (true) {
        cout << "Please enter text to encrypt:\n";
        getline(cin, userInput); 

      
        bool isValid = true; 
        for (char ch : userInput) {
            if (validChar.find(ch) == string::npos) { 
                isValid = false; 
                break; 
            }
        }

        if (!isValid) { 
            cout << "Please enter only valid characters (letters, numbers, and spaces).";
        }
        else {
            break; 
        }
    }

   
    while (true) {
        cout << "Please enter shift (between 1 and 36):\n";
        cin >> shift;

       
        if (cin.fail() || shift < 1 || shift > 36) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Please enter a number between 1 and 36 only.\n";
        }
        else {
           
            break; 
        }
    }

   
    string encryptedMessage;
    for (char ch : userInput) {
        if (ch >= 'A' && ch <= 'Z') {
            
            char shiftedChar = (ch - 'A' + shift) % 26 + 'A';
            encryptedMessage += shiftedChar;
        }
        else if (ch >= 'a' && ch <= 'z') {
            
            char shiftedChar = (ch - 'a' + shift) % 26 + 'a';
            encryptedMessage += shiftedChar;
        }
        else if (ch >= '0' && ch <= '9') {
            
            char shiftedChar = (ch - '0' + shift) % 10 + '0';
            encryptedMessage += shiftedChar;
        }
        else {
            
            encryptedMessage += ch;
        }
    }

   
    cout << "Encoded/Decoded string is: '" << encryptedMessage << "'" << endl;
}



void DecryptText() {
    string userInput;
    string validChar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    int shift;

    cout << "Decrypt Text\n";
    cout << "----------------------\n";


    while (true) {

        cout << "Please enter text to decrypt:\n";
        getline(cin, userInput);


        bool isValid = true;
        for (char ch : userInput) {
            if (validChar.find(ch) == string::npos) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            cout << "Please enter only valid characters (letters, numbers, and spaces).";
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Please enter shift (between 1 and 36):\n";
        cin >> shift;


        if (cin.fail() || shift < 1 || shift > 36) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number between 1 and 36 only.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        string decryptedMessage;
        for (char ch : userInput) {
            if (ch >= 'A' && ch <= 'Z') {

                char shiftedChar = (ch - 'A' - shift + 26) % 26 + 'A';
                decryptedMessage += shiftedChar;
            }
            else if (ch >= 'a' && ch <= 'z') {

                char shiftedChar = (ch - 'a' - shift + 26) % 26 + 'a';
                decryptedMessage += shiftedChar;
            }
            else if (ch >= '0' && ch <= '9') {

                char shiftedChar = (ch - '0' - shift + 10) % 10 + '0';
                decryptedMessage += shiftedChar;
            }
            else {

                decryptedMessage += ch;
            }
        }


        cout << "Decrypted text is: '" << decryptedMessage << "'" << endl;


    }
}
