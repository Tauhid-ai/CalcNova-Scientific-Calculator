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
// INPUT BUFFER CLEAR
// ======================================================

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ======================================================
// LOAD HISTORY FROM FILE
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
// SAVE HISTORY TO FILE
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
// ADD CALCULATION TO HISTORY
// ======================================================

void addToHistory(string calculation)
{
    history.push_back(calculation);
    saveHistory();
}

// ======================================================
// VIEW HISTORY
// ======================================================

void viewHistory()
{
    cout << "\n";
    cout << "====================================================\n";
    cout << "                  CALCULATION HISTORY\n";
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
// GET VALID NUMBER
// ======================================================

double getNumber(string message)
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
        to_string(a) + " + " + to_string(b) +
        " = " + to_string(result)
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
        to_string(a) + " - " + to_string(b) +
        " = " + to_string(result)
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
        to_string(a) + " * " + to_string(b) +
        " = " + to_string(result)
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
        to_string(a) + " / " + to_string(b) +
        " = " + to_string(result)
    );
}

// ======================================================
// MODULUS
// ======================================================

void modulus()
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
        to_string(a) + " % " + to_string(b) +
        " = " + to_string(result)
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

    double cosineValue = cos(radians);

    if (fabs(cosineValue) < 1e-10)
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
// PI VALUE
// ======================================================

void piValue()
{
    cout << fixed << setprecision(10);

    cout << "\nPI = " << M_PI << endl;

    addToHistory(
        "PI = " + to_string(M_PI)
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
// ABOUT
// ======================================================

void about()
{
    cout << "\n";
    cout << "====================================================\n";
    cout << "                    ABOUT CALCNOVA\n";
    cout << "====================================================\n";
    cout << "CalcNova - Scientific Calculator\n";
    cout << "\n";
    cout << "Version : 2.0\n";
    cout << "Language: C++\n";
    cout << "\n";
    cout << "Features:\n";
    cout << "- Basic arithmetic operations\n";
    cout << "- Scientific calculations\n";
    cout << "- Trigonometric functions\n";
    cout << "- Calculation history\n";
    cout << "- File-based history storage\n";
    cout << "- Input validation\n";
    cout << "\n";
    cout << "Developed as a C++ project.\n";
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
    cout << "\n";
    cout << "Basic Operations:\n";
    cout << "1-5   : Arithmetic operations\n";
    cout << "\n";
    cout << "Scientific Operations:\n";
    cout << "6     : Power\n";
    cout << "7     : Square Root\n";
    cout << "8     : Natural Log\n";
    cout << "9     : Log Base 10\n";
    cout << "\n";
    cout << "Trigonometry:\n";
    cout << "10    : Sin\n";
    cout << "11    : Cos\n";
    cout << "12    : Tan\n";
    cout << "\n";
    cout << "Other Operations:\n";
    cout << "13    : Percentage\n";
    cout << "14    : PI\n";
    cout << "15    : e\n";
    cout << "16    : Absolute Value\n";
    cout << "17    : Reciprocal\n";
    cout << "\n";
    cout << "History:\n";
    cout << "18    : View History\n";
    cout << "19    : Clear History\n";
    cout << "\n";
    cout << "20    : About\n";
    cout << "21    : Help\n";
    cout << "22    : Exit\n";
    cout << "\n";
    cout << "Important:\n";
    cout << "- Trigonometric angles are entered in degrees.\n";
    cout << "- Division by zero is not allowed.\n";
    cout << "- Logarithm requires a positive number.\n";
    cout << "- Square root requires a non-negative number.\n";
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

    // Load previous calculations
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

            default:
                cout << "\n[ERROR] Invalid choice. Please enter 1-22.\n";
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