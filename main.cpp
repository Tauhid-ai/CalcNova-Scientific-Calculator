#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// ======================================================
// GLOBAL HISTORY
// ======================================================

vector<string> history;

// ======================================================
// CLEAR INPUT BUFFER
// ======================================================

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ======================================================
// SAVE HISTORY TO FILE
// ======================================================

void saveHistory()
{
    ofstream file("history.txt");

    if (!file)
    {
        cout << "\nUnable to save history.\n";
        return;
    }

    for (const string &item : history)
    {
        file << item << endl;
    }

    file.close();
}

// ======================================================
// LOAD HISTORY FROM FILE
// ======================================================

void loadHistory()
{
    ifstream file("history.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        if (!line.empty())
            history.push_back(line);
    }

    file.close();
}

// ======================================================
// ADD CALCULATION TO HISTORY
// ======================================================

void addToHistory(const string &calculation)
{
    history.push_back(calculation);
    saveHistory();
}

// ======================================================
// DISPLAY HISTORY
// ======================================================

void showHistory()
{
    cout << "\n";
    cout << "============================================\n";
    cout << "             CALCULATION HISTORY\n";
    cout << "============================================\n";

    if (history.empty())
    {
        cout << "No calculation history available.\n";
    }
    else
    {
        for (size_t i = 0; i < history.size(); i++)
        {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }

    cout << "============================================\n";
}

// ======================================================
// CLEAR HISTORY
// ======================================================

void clearHistory()
{
    if (history.empty())
    {
        cout << "\nHistory is already empty.\n";
        return;
    }

    char confirm;

    cout << "\nAre you sure you want to clear all history? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        history.clear();

        ofstream file("history.txt", ios::trunc);
        file.close();

        cout << "\nHistory cleared successfully.\n";
    }
    else
    {
        cout << "\nHistory was not cleared.\n";
    }
}

// ======================================================
// ADDITION
// ======================================================

void addition()
{
    double a, b;

    cout << "\nEnter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter valid numbers.\n";
        return;
    }

    double result = a + b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " + " + to_string(b) + " = " + to_string(result)
    );
}

// ======================================================
// SUBTRACTION
// ======================================================

void subtraction()
{
    double a, b;

    cout << "\nEnter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter valid numbers.\n";
        return;
    }

    double result = a - b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " - " + to_string(b) + " = " + to_string(result)
    );
}

// ======================================================
// MULTIPLICATION
// ======================================================

void multiplication()
{
    double a, b;

    cout << "\nEnter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter valid numbers.\n";
        return;
    }

    double result = a * b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " * " + to_string(b) + " = " + to_string(result)
    );
}

// ======================================================
// DIVISION
// ======================================================

void division()
{
    double a, b;

    cout << "\nEnter dividend: ";
    cin >> a;

    cout << "Enter divisor: ";
    cin >> b;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter valid numbers.\n";
        return;
    }

    if (b == 0)
    {
        cout << "\n[ERROR] Division by zero is not allowed.\n";
        return;
    }

    double result = a / b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " / " + to_string(b) + " = " + to_string(result)
    );
}

// ======================================================
// MODULUS
// ======================================================

void modulo()
{
    int a, b;

    cout << "\nEnter first integer: ";
    cin >> a;

    cout << "Enter second integer: ";
    cin >> b;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter valid integers.\n";
        return;
    }

    if (b == 0)
    {
        cout << "\n[ERROR] Modulus by zero is not allowed.\n";
        return;
    }

    int result = a % b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " % " + to_string(b) + " = " + to_string(result)
    );
}

// ======================================================
// POWER
// ======================================================

void power()
{
    double base, exponent;

    cout << "\nEnter base: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exponent;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter valid numbers.\n";
        return;
    }

    double result = pow(base, exponent);

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(base) + " ^ " +
        to_string(exponent) + " = " +
        to_string(result)
    );
}

// ======================================================
// SQUARE ROOT
// ======================================================

void squareRoot()
{
    double number;

    cout << "\nEnter number: ";
    cin >> number;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter a valid number.\n";
        return;
    }

    if (number < 0)
    {
        cout << "\n[ERROR] Square root of negative number is not valid.\n";
        return;
    }

    double result = sqrt(number);

    cout << "\nSquare Root = " << result << endl;

    addToHistory(
        "sqrt(" + to_string(number) + ") = " +
        to_string(result)
    );
}

// ======================================================
// NATURAL LOG
// ======================================================

void naturalLog()
{
    double number;

    cout << "\nEnter number: ";
    cin >> number;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter a valid number.\n";
        return;
    }

    if (number <= 0)
    {
        cout << "\n[ERROR] Natural log requires number > 0.\n";
        return;
    }

    double result = log(number);

    cout << "\nNatural Log = " << result << endl;

    addToHistory(
        "ln(" + to_string(number) + ") = " +
        to_string(result)
    );
}

// ======================================================
// LOG BASE 10
// ======================================================

void logBase10()
{
    double number;

    cout << "\nEnter number: ";
    cin >> number;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter a valid number.\n";
        return;
    }

    if (number <= 0)
    {
        cout << "\n[ERROR] Log requires number > 0.\n";
        return;
    }

    double result = log10(number);

    cout << "\nLog Base 10 = " << result << endl;

    addToHistory(
        "log10(" + to_string(number) + ") = " +
        to_string(result)
    );
}

// ======================================================
// SINE
// ======================================================

void sine()
{
    double angle;

    cout << "\nEnter angle in degrees: ";
    cin >> angle;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter a valid angle.\n";
        return;
    }

    const double PI = acos(-1.0);
    double radians = angle * PI / 180.0;
    double result = sin(radians);

    cout << "\nSin(" << angle << ") = " << result << endl;

    addToHistory(
        "sin(" + to_string(angle) + ") = " +
        to_string(result)
    );
}

// ======================================================
// COSINE
// ======================================================

void cosine()
{
    double angle;

    cout << "\nEnter angle in degrees: ";
    cin >> angle;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter a valid angle.\n";
        return;
    }

    const double PI = acos(-1.0);
    double radians = angle * PI / 180.0;
    double result = cos(radians);

    cout << "\nCos(" << angle << ") = " << result << endl;

    addToHistory(
        "cos(" + to_string(angle) + ") = " +
        to_string(result)
    );
}

// ======================================================
// TANGENT
// ======================================================

void tangent()
{
    double angle;

    cout << "\nEnter angle in degrees: ";
    cin >> angle;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter a valid angle.\n";
        return;
    }

    const double PI = acos(-1.0);
    double radians = angle * PI / 180.0;

    double cosineValue = cos(radians);

    if (fabs(cosineValue) < 1e-10)
    {
        cout << "\n[ERROR] Tangent is undefined for this angle.\n";
        return;
    }

    double result = tan(radians);

    cout << "\nTan(" << angle << ") = " << result << endl;

    addToHistory(
        "tan(" + to_string(angle) + ") = " +
        to_string(result)
    );
}

// ======================================================
// PERCENTAGE
// ======================================================

void percentage()
{
    double number;

    cout << "\nEnter number: ";
    cin >> number;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter a valid number.\n";
        return;
    }

    double result = number / 100.0;

    cout << "\nPercentage = " << result << endl;

    addToHistory(
        to_string(number) + "% = " +
        to_string(result)
    );
}

// ======================================================
// PI VALUE
// ======================================================

void piValue()
{
    const double PI = acos(-1.0);

    cout << fixed << setprecision(10);
    cout << "\nPi = " << PI << endl;

    addToHistory("Pi = " + to_string(PI));
}

// ======================================================
// E VALUE
// ======================================================

void eValue()
{
    const double E = exp(1.0);

    cout << fixed << setprecision(10);
    cout << "\nEuler's Number = " << E << endl;

    addToHistory("e = " + to_string(E));
}

// ======================================================
// ABSOLUTE VALUE
// ======================================================

void absoluteValue()
{
    double number;

    cout << "\nEnter number: ";
    cin >> number;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter a valid number.\n";
        return;
    }

    double result = fabs(number);

    cout << "\nAbsolute Value = " << result << endl;

    addToHistory(
        "abs(" + to_string(number) + ") = " +
        to_string(result)
    );
}

// ======================================================
// RECIPROCAL
// ======================================================

void reciprocal()
{
    double number;

    cout << "\nEnter number: ";
    cin >> number;

    if (cin.fail())
    {
        clearInput();
        cout << "\n[ERROR] Please enter a valid number.\n";
        return;
    }

    if (number == 0)
    {
        cout << "\n[ERROR] Reciprocal of zero is undefined.\n";
        return;
    }

    double result = 1.0 / number;

    cout << "\nReciprocal = " << result << endl;

    addToHistory(
        "1/" + to_string(number) + " = " +
        to_string(result)
    );
}

// ======================================================
// DISPLAY MENU
// ======================================================

void displayMenu()
{
    cout << "\n\n";
    cout << "====================================================\n";
    cout << "                  CALCNOVA\n";
    cout << "             SCIENTIFIC CALCULATOR\n";
    cout << "====================================================\n";

    cout << "\n[ BASIC OPERATIONS ]\n";
    cout << "1.  Addition\n";
    cout << "2.  Subtraction\n";
    cout << "3.  Multiplication\n";
    cout << "4.  Division\n";
    cout << "5.  Modulus\n";

    cout << "\n[ SCIENTIFIC OPERATIONS ]\n";
    cout << "6.  Power\n";
    cout << "7.  Square Root\n";
    cout << "8.  Natural Log\n";
    cout << "9.  Log Base 10\n";

    cout << "\n[ TRIGONOMETRY ]\n";
    cout << "10. Sin\n";
    cout << "11. Cos\n";
    cout << "12. Tan\n";

    cout << "\n[ OTHER OPERATIONS ]\n";
    cout << "13. Percentage\n";
    cout << "14. Pi\n";
    cout << "15. Euler's Number\n";
    cout << "16. Absolute Value\n";
    cout << "17. Reciprocal\n";

    cout << "\n[ HISTORY ]\n";
    cout << "18. Show History\n";
    cout << "19. Clear History\n";

    cout << "\n20. Exit\n";

    cout << "\n====================================================\n";
}

// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    int choice;

    // Load old history when program starts
    loadHistory();

    do
    {
        displayMenu();

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            clearInput();
            cout << "\n[ERROR] Please enter a valid integer.\n";
            continue;
        }

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
                modulo();
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
                percentage();
                break;

            case 14:
                piValue();
                break;

            case 15:
                eValue();
                break;

            case 16:
                absoluteValue();
                break;

            case 17:
                reciprocal();
                break;

            case 18:
                showHistory();
                break;

            case 19:
                clearHistory();
                break;

            case 20:
                cout << "\nThank you for using CalcNova!\n";
                cout << "Goodbye!\n";
                break;

            default:
                cout << "\n[ERROR] Invalid choice. Please select 1-20.\n";
        }

        if (choice != 20)
        {
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (choice != 20);

    return 0;
}