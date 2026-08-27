#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// ======================================================
// GLOBAL VARIABLES
// ======================================================

vector<string> history;

const string HISTORY_FILE = "history.txt";

// ======================================================
// CLEAR INPUT BUFFER
// ======================================================

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ======================================================
// LOAD HISTORY
// ======================================================

void loadHistory()
{
    ifstream inputFile(HISTORY_FILE);

    if (!inputFile.is_open())
        return;

    string line;

    while (getline(inputFile, line))
    {
        if (!line.empty())
        {
            history.push_back(line);
        }
    }

    inputFile.close();
}

// ======================================================
// SAVE HISTORY
// ======================================================

void saveHistory()
{
    ofstream outputFile(HISTORY_FILE);

    if (!outputFile.is_open())
    {
        cout << "\n[ERROR] Unable to save history.\n";
        return;
    }

    for (const string &calculation : history)
    {
        outputFile << calculation << endl;
    }

    outputFile.close();
}

// ======================================================
// ADD TO HISTORY
// ======================================================

void addToHistory(const string &calculation)
{
    history.push_back(calculation);
    saveHistory();
}

// ======================================================
// GET VALID NUMBER
// ======================================================

double getNumber(const string &message)
{
    double number;

    while (true)
    {
        cout << message;

        if (cin >> number)
        {
            return number;
        }

        cout << "[ERROR] Please enter a valid number.\n";
        clearInput();
    }
}

// ======================================================
// ADDITION
// ======================================================

void addition()
{
    double a = getNumber("Enter first number: ");
    double b = getNumber("Enter second number: ");

    double result = a + b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " + " +
        to_string(b) + " = " +
        to_string(result)
    );
}

// ======================================================
// SUBTRACTION
// ======================================================

void subtraction()
{
    double a = getNumber("Enter first number: ");
    double b = getNumber("Enter second number: ");

    double result = a - b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " - " +
        to_string(b) + " = " +
        to_string(result)
    );
}

// ======================================================
// MULTIPLICATION
// ======================================================

void multiplication()
{
    double a = getNumber("Enter first number: ");
    double b = getNumber("Enter second number: ");

    double result = a * b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " * " +
        to_string(b) + " = " +
        to_string(result)
    );
}

// ======================================================
// DIVISION
// ======================================================

void division()
{
    double a = getNumber("Enter numerator: ");
    double b = getNumber("Enter denominator: ");

    if (b == 0)
    {
        cout << "\n[ERROR] Division by zero is not allowed.\n";
        return;
    }

    double result = a / b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " / " +
        to_string(b) + " = " +
        to_string(result)
    );
}

// ======================================================
// MODULUS
// ======================================================

void modulusOperation()
{
    long long a, b;

    cout << "Enter first integer: ";

    while (!(cin >> a))
    {
        cout << "[ERROR] Please enter a valid integer.\n";
        clearInput();
        cout << "Enter first integer: ";
    }

    cout << "Enter second integer: ";

    while (!(cin >> b))
    {
        cout << "[ERROR] Please enter a valid integer.\n";
        clearInput();
        cout << "Enter second integer: ";
    }

    if (b == 0)
    {
        cout << "\n[ERROR] Modulus by zero is not allowed.\n";
        return;
    }

    long long result = a % b;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(a) + " % " +
        to_string(b) + " = " +
        to_string(result)
    );
}

// ======================================================
// POWER
// ======================================================

void power()
{
    double base = getNumber("Enter base: ");
    double exponent = getNumber("Enter exponent: ");

    double result = pow(base, exponent);

    cout << "\nResult = " << result << endl;

    addToHistory(
        "pow(" + to_string(base) + ", " +
        to_string(exponent) + ") = " +
        to_string(result)
    );
}

// ======================================================
// SQUARE ROOT
// ======================================================

void squareRoot()
{
    double number = getNumber("Enter number: ");

    if (number < 0)
    {
        cout << "\n[ERROR] Square root of negative number is not allowed.\n";
        return;
    }

    double result = sqrt(number);

    cout << "\nResult = " << result << endl;

    addToHistory(
        "sqrt(" + to_string(number) +
        ") = " + to_string(result)
    );
}

// ======================================================
// NATURAL LOG
// ======================================================

void naturalLog()
{
    double number = getNumber("Enter number: ");

    if (number <= 0)
    {
        cout << "\n[ERROR] Natural logarithm requires number > 0.\n";
        return;
    }

    double result = log(number);

    cout << "\nResult = " << result << endl;

    addToHistory(
        "ln(" + to_string(number) +
        ") = " + to_string(result)
    );
}

// ======================================================
// LOG BASE 10
// ======================================================

void logBase10()
{
    double number = getNumber("Enter number: ");

    if (number <= 0)
    {
        cout << "\n[ERROR] Logarithm requires number > 0.\n";
        return;
    }

    double result = log10(number);

    cout << "\nResult = " << result << endl;

    addToHistory(
        "log10(" + to_string(number) +
        ") = " + to_string(result)
    );
}

// ======================================================
// SINE
// ======================================================

void sine()
{
    double angle = getNumber("Enter angle in degrees: ");

    double radians = angle * M_PI / 180.0;
    double result = sin(radians);

    cout << "\nResult = " << result << endl;

    addToHistory(
        "sin(" + to_string(angle) +
        " degrees) = " + to_string(result)
    );
}

// ======================================================
// COSINE
// ======================================================

void cosine()
{
    double angle = getNumber("Enter angle in degrees: ");

    double radians = angle * M_PI / 180.0;
    double result = cos(radians);

    cout << "\nResult = " << result << endl;

    addToHistory(
        "cos(" + to_string(angle) +
        " degrees) = " + to_string(result)
    );
}

// ======================================================
// TANGENT
// ======================================================

void tangent()
{
    double angle = getNumber("Enter angle in degrees: ");

    double radians = angle * M_PI / 180.0;

    if (fabs(cos(radians)) < 1e-10)
    {
        cout << "\n[ERROR] Tangent is undefined for this angle.\n";
        return;
    }

    double result = tan(radians);

    cout << "\nResult = " << result << endl;

    addToHistory(
        "tan(" + to_string(angle) +
        " degrees) = " + to_string(result)
    );
}

// ======================================================
// PERCENTAGE
// ======================================================

void percentage()
{
    double number = getNumber("Enter number: ");

    double result = number / 100.0;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(number) + "% = " +
        to_string(result)
    );
}

// ======================================================
// PI
// ======================================================

void piValue()
{
    double result = acos(-1.0);

    cout << fixed << setprecision(10);
    cout << "\nPI = " << result << endl;

    addToHistory(
        "PI = " + to_string(result)
    );
}

// ======================================================
// E VALUE
// ======================================================

void eValue()
{
    double result = exp(1.0);

    cout << fixed << setprecision(10);
    cout << "\ne = " << result << endl;

    addToHistory(
        "e = " + to_string(result)
    );
}

// ======================================================
// ABSOLUTE VALUE
// ======================================================

void absoluteValue()
{
    double number = getNumber("Enter number: ");

    double result = fabs(number);

    cout << "\nResult = " << result << endl;

    addToHistory(
        "abs(" + to_string(number) +
        ") = " + to_string(result)
    );
}

// ======================================================
// RECIPROCAL
// ======================================================

void reciprocal()
{
    double number = getNumber("Enter number: ");

    if (number == 0)
    {
        cout << "\n[ERROR] Reciprocal of zero is undefined.\n";
        return;
    }

    double result = 1.0 / number;

    cout << "\nResult = " << result << endl;

    addToHistory(
        "1/" + to_string(number) +
        " = " + to_string(result)
    );
}

// ======================================================
// FACTORIAL
// ======================================================

void factorial()
{
    long long n;

    cout << "Enter a non-negative integer: ";

    while (!(cin >> n))
    {
        cout << "[ERROR] Please enter a valid integer.\n";
        clearInput();
        cout << "Enter a non-negative integer: ";
    }

    if (n < 0)
    {
        cout << "\n[ERROR] Factorial is not defined for negative numbers.\n";
        return;
    }

    if (n > 20)
    {
        cout << "\n[ERROR] Please enter a number between 0 and 20.\n";
        return;
    }

    unsigned long long result = 1;

    for (long long i = 1; i <= n; i++)
    {
        result *= i;
    }

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(n) + "! = " +
        to_string(result)
    );
}

// ======================================================
// SQUARE
// ======================================================

void square()
{
    double number = getNumber("Enter number: ");

    double result = number * number;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(number) + "^2 = " +
        to_string(result)
    );
}

// ======================================================
// CUBE
// ======================================================

void cube()
{
    double number = getNumber("Enter number: ");

    double result = number * number * number;

    cout << "\nResult = " << result << endl;

    addToHistory(
        to_string(number) + "^3 = " +
        to_string(result)
    );
}

// ======================================================
// EXPONENTIAL
// ======================================================

void exponential()
{
    double number = getNumber("Enter value of x: ");

    double result = exp(number);

    cout << "\ne^" << number << " = " << result << endl;

    addToHistory(
        "e^" + to_string(number) +
        " = " + to_string(result)
    );
}

// ======================================================
// VIEW HISTORY
// ======================================================

void viewHistory()
{
    cout << "\n";
    cout << "====================================================\n";
    cout << "                 CALCULATION HISTORY\n";
    cout << "====================================================\n";

    if (history.empty())
    {
        cout << "\nNo calculations yet.\n";
    }
    else
    {
        for (size_t i = 0; i < history.size(); i++)
        {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }

    cout << "====================================================\n";
}

// ======================================================
// CLEAR HISTORY
// ======================================================

void clearHistory()
{
    history.clear();

    ofstream outputFile(HISTORY_FILE, ios::trunc);

    if (outputFile.is_open())
    {
        outputFile.close();

        cout << "\nHistory cleared successfully!\n";
    }
    else
    {
        cout << "\n[ERROR] Unable to clear history file.\n";
    }
}

// ======================================================
// ABOUT
// ======================================================

void about()
{
    cout << "\n";
    cout << "====================================================\n";
    cout << "                   ABOUT CALCNOVA\n";
    cout << "====================================================\n";

    cout << "CalcNova - Scientific Calculator\n";
    cout << "\n";

    cout << "Version : 3.0\n";
    cout << "Language: C++\n";

    cout << "\nFeatures:\n";
    cout << "- Basic arithmetic operations\n";
    cout << "- Scientific calculations\n";
    cout << "- Trigonometric functions\n";
    cout << "- Factorial\n";
    cout << "- Square and Cube\n";
    cout << "- Exponential calculation\n";
    cout << "- Calculation history\n";
    cout << "- File-based history storage\n";
    cout << "- Input validation\n";

    cout << "\nDeveloped as a C++ project.\n";

    cout << "====================================================\n";
}

// ======================================================
// HELP
// ======================================================

void help()
{
    cout << "\n";
    cout << "====================================================\n";
    cout << "                       HELP\n";
    cout << "====================================================\n";

    cout << "\n[ BASIC OPERATIONS ]\n";
    cout << "1  - Addition\n";
    cout << "2  - Subtraction\n";
    cout << "3  - Multiplication\n";
    cout << "4  - Division\n";
    cout << "5  - Modulus\n";

    cout << "\n[ SCIENTIFIC OPERATIONS ]\n";
    cout << "6  - Power\n";
    cout << "7  - Square Root\n";
    cout << "8  - Natural Log\n";
    cout << "9  - Log Base 10\n";

    cout << "\n[ TRIGONOMETRY ]\n";
    cout << "10 - Sin\n";
    cout << "11 - Cos\n";
    cout << "12 - Tan\n";

    cout << "\n[ OTHER OPERATIONS ]\n";
    cout << "13 - Percentage\n";
    cout << "14 - PI Value\n";
    cout << "15 - e Value\n";
    cout << "16 - Absolute Value\n";
    cout << "17 - Reciprocal\n";
    cout << "23 - Factorial\n";
    cout << "24 - Square\n";
    cout << "25 - Cube\n";
    cout << "26 - Exponential e^x\n";

    cout << "\n[ HISTORY ]\n";
    cout << "18 - View History\n";
    cout << "19 - Clear History\n";

    cout << "\n[ INFORMATION ]\n";
    cout << "20 - About\n";
    cout << "21 - Help\n";

    cout << "\n22 - Exit\n";

    cout << "\nImportant:\n";
    cout << "- Trigonometric angles are entered in degrees.\n";
    cout << "- Division by zero is not allowed.\n";
    cout << "- Modulus requires integers.\n";
    cout << "- Logarithm requires a positive number.\n";
    cout << "- Square root requires a non-negative number.\n";
    cout << "- Factorial accepts values from 0 to 20.\n";

    cout << "====================================================\n";
}

// ======================================================
// DISPLAY MENU
// ======================================================

void displayMenu()
{
    cout << "\n\n";

    cout << "====================================================\n";
    cout << "                    CALCNOVA\n";
    cout << "              SCIENTIFIC CALCULATOR\n";
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
    cout << "14. PI Value\n";
    cout << "15. e Value\n";
    cout << "16. Absolute Value\n";
    cout << "17. Reciprocal (1/x)\n";
    cout << "23. Factorial (n!)\n";
    cout << "24. Square (x^2)\n";
    cout << "25. Cube (x^3)\n";
    cout << "26. Exponential (e^x)\n";

    cout << "\n[ HISTORY ]\n";
    cout << "18. View History\n";
    cout << "19. Clear History\n";

    cout << "\n[ INFORMATION ]\n";
    cout << "20. About\n";
    cout << "21. Help\n";

    cout << "\n22. Exit\n";

    cout << "====================================================\n";
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

        if (!(cin >> choice))
        {
            cout << "\n[ERROR] Please enter a valid integer.\n";

            clearInput();

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
                modulusOperation();
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
                viewHistory();
                break;

            case 19:
                clearHistory();
                break;

            case 20:
                about();
                break;

            case 21:
                help();
                break;

            case 22:
                cout << "\n";
                cout << "====================================================\n";
                cout << "             Thank you for using CalcNova!\n";
                cout << "                    Goodbye!\n";
                cout << "====================================================\n";
                break;

            case 23:
                factorial();
                break;

            case 24:
                square();
                break;

            case 25:
                cube();
                break;

            case 26:
                exponential();
                break;

            default:
                cout << "\n[ERROR] Invalid choice. Please enter 1-26.\n";
        }

        if (choice != 22)
        {
            cout << "\nPress Enter to continue...";

            clearInput();
            cin.get();
        }

    } while (choice != 22);

    return 0;
}