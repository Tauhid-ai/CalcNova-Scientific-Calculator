#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// ==========================================
// GLOBAL HISTORY
// ==========================================

vector<string> history;


// ==========================================
// SAVE CALCULATION TO HISTORY
// ==========================================

void addToHistory(string calculation)
{
    // Add calculation to vector
    history.push_back(calculation);

    // Save calculation permanently in file
    ofstream outputFile("history.txt", ios::app);

    if (outputFile.is_open())
    {
        outputFile << calculation << endl;
        outputFile.close();
    }
}


// ==========================================
// LOAD HISTORY FROM FILE
// ==========================================

void loadHistory()
{
    ifstream inputFile("history.txt");

    string calculation;

    if (inputFile.is_open())
    {
        while (getline(inputFile, calculation))
        {
            history.push_back(calculation);
        }

        inputFile.close();
    }
}


// ==========================================
// ADDITION
// ==========================================

void addition()
{
    double a, b, result;

    cout << "\nEnter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    result = a + b;

    cout << "\nResult = " << result << endl;

    string calculation =
        to_string(a) + " + " +
        to_string(b) + " = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// SUBTRACTION
// ==========================================

void subtraction()
{
    double a, b, result;

    cout << "\nEnter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    result = a - b;

    cout << "\nResult = " << result << endl;

    string calculation =
        to_string(a) + " - " +
        to_string(b) + " = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// MULTIPLICATION
// ==========================================

void multiplication()
{
    double a, b, result;

    cout << "\nEnter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    result = a * b;

    cout << "\nResult = " << result << endl;

    string calculation =
        to_string(a) + " * " +
        to_string(b) + " = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// DIVISION
// ==========================================

void division()
{
    double a, b, result;

    cout << "\nEnter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    if (b == 0)
    {
        cout << "\nError: Cannot divide by zero!" << endl;
        return;
    }

    result = a / b;

    cout << "\nResult = " << result << endl;

    string calculation =
        to_string(a) + " / " +
        to_string(b) + " = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// MODULUS
// ==========================================

void modulus()
{
    int a, b, result;

    cout << "\nEnter first integer: ";
    cin >> a;

    cout << "Enter second integer: ";
    cin >> b;

    if (b == 0)
    {
        cout << "\nError: Cannot find modulus with zero!" << endl;
        return;
    }

    result = a % b;

    cout << "\nResult = " << result << endl;

    string calculation =
        to_string(a) + " % " +
        to_string(b) + " = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// POWER
// ==========================================

void power()
{
    double base, exponent, result;

    cout << "\nEnter base: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exponent;

    result = pow(base, exponent);

    cout << "\nResult = " << result << endl;

    string calculation =
        "pow(" +
        to_string(base) + ", " +
        to_string(exponent) + ") = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// SQUARE ROOT
// ==========================================

void squareRoot()
{
    double number, result;

    cout << "\nEnter a number: ";
    cin >> number;

    if (number < 0)
    {
        cout << "\nError: Square root of a negative number is not valid!"
             << endl;
        return;
    }

    result = sqrt(number);

    cout << "\nResult = " << result << endl;

    string calculation =
        "sqrt(" +
        to_string(number) +
        ") = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// NATURAL LOG
// ==========================================

void naturalLog()
{
    double number, result;

    cout << "\nEnter a positive number: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "\nError: Log is defined only for positive numbers!"
             << endl;
        return;
    }

    result = log(number);

    cout << "\nResult = " << result << endl;

    string calculation =
        "log(" +
        to_string(number) +
        ") = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// LOG BASE 10
// ==========================================

void logBase10()
{
    double number, result;

    cout << "\nEnter a positive number: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "\nError: Log is defined only for positive numbers!"
             << endl;
        return;
    }

    result = log10(number);

    cout << "\nResult = " << result << endl;

    string calculation =
        "log10(" +
        to_string(number) +
        ") = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// SIN
// ==========================================

void sine()
{
    double degree, radian, result;

    cout << "\nEnter angle in degrees: ";
    cin >> degree;

    radian = degree * acos(-1) / 180;

    result = sin(radian);

    cout << "\nResult = " << result << endl;

    string calculation =
        "sin(" +
        to_string(degree) +
        " deg) = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// COS
// ==========================================

void cosine()
{
    double degree, radian, result;

    cout << "\nEnter angle in degrees: ";
    cin >> degree;

    radian = degree * acos(-1) / 180;

    result = cos(radian);

    cout << "\nResult = " << result << endl;

    string calculation =
        "cos(" +
        to_string(degree) +
        " deg) = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// TAN
// ==========================================

void tangent()
{
    double degree, radian, result;

    cout << "\nEnter angle in degrees: ";
    cin >> degree;

    radian = degree * acos(-1) / 180;

    result = tan(radian);

    cout << "\nResult = " << result << endl;

    string calculation =
        "tan(" +
        to_string(degree) +
        " deg) = " +
        to_string(result);

    addToHistory(calculation);
}


// ==========================================
// SHOW HISTORY
// ==========================================

void showHistory()
{
    cout << "\n============================================"
         << endl;

    cout << "          CALCULATION HISTORY"
         << endl;

    cout << "============================================"
         << endl;

    if (history.empty())
    {
        cout << "No calculations yet." << endl;
        return;
    }

    for (int i = 0; i < history.size(); i++)
    {
        cout << i + 1 << ". "
             << history[i] << endl;
    }
}


// ==========================================
// CLEAR HISTORY
// ==========================================

void clearHistory()
{
    if (history.empty())
    {
        cout << "\nHistory is already empty." << endl;
        return;
    }

    // Clear vector
    history.clear();

    // Clear history.txt
    ofstream outputFile("history.txt");

    outputFile.close();

    cout << "\nHistory cleared successfully!" << endl;
}


// ==========================================
// MAIN FUNCTION
// ==========================================

int main()
{
    int choice;

    // Load previous history
    loadHistory();

    do
    {
        // ==========================================
        // HEADER
        // ==========================================

        cout << "\n\n";

        cout << "============================================"
             << endl;

        cout << "              CALCNOVA"
             << endl;

        cout << "        SCIENTIFIC CALCULATOR"
             << endl;

        cout << "============================================"
             << endl;


        // ==========================================
        // BASIC OPERATIONS
        // ==========================================

        cout << "\n[ BASIC OPERATIONS ]"
             << endl;

        cout << "1.  Addition" << endl;
        cout << "2.  Subtraction" << endl;
        cout << "3.  Multiplication" << endl;
        cout << "4.  Division" << endl;
        cout << "5.  Modulus" << endl;


        // ==========================================
        // SCIENTIFIC OPERATIONS
        // ==========================================

        cout << "\n[ SCIENTIFIC OPERATIONS ]"
             << endl;

        cout << "6.  Power" << endl;
        cout << "7.  Square Root" << endl;
        cout << "8.  Natural Log" << endl;
        cout << "9.  Log Base 10" << endl;


        // ==========================================
        // TRIGONOMETRY
        // ==========================================

        cout << "\n[ TRIGONOMETRY ]"
             << endl;

        cout << "10. Sin" << endl;
        cout << "11. Cos" << endl;
        cout << "12. Tan" << endl;


        // ==========================================
        // HISTORY
        // ==========================================

        cout << "\n[ HISTORY ]"
             << endl;

        cout << "13. View History" << endl;
        cout << "14. Clear History" << endl;


        // ==========================================
        // EXIT
        // ==========================================

        cout << "\n15. Exit" << endl;

        cout << "\n--------------------------------------------"
             << endl;

        cout << "Enter your choice: ";

        cin >> choice;


        // ==========================================
        // INPUT VALIDATION
        // ==========================================

        if (cin.fail())
        {
            cout << "\nError: Please enter a number between 1 and 15."
                 << endl;

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            continue;
        }


        // ==========================================
        // SWITCH CASE
        // ==========================================

        switch (choice)
        {
            case 1:
                addition();
                break;

            case 2:
                subtraction();
                break;

            case 3:
                multiplication();
                break;

            case 4:
                division();
                break;

            case 5:
                modulus();
                break;

            case 6:
                power();
                break;

            case 7:
                squareRoot();
                break;

            case 8:
                naturalLog();
                break;

            case 9:
                logBase10();
                break;

            case 10:
                sine();
                break;

            case 11:
                cosine();
                break;

            case 12:
                tangent();
                break;

            case 13:
                showHistory();
                break;

            case 14:
                clearHistory();
                break;

            case 15:
                cout << "\n============================================"
                     << endl;

                cout << "       Thank you for using CalcNova!"
                     << endl;

                cout << "============================================"
                     << endl;

                break;

            default:
                cout << "\nError: Invalid choice!"
                     << endl;

                cout << "Please select a number between 1 and 15."
                     << endl;
        }

    } while (choice != 15);


    return 0;
}