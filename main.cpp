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
// CLEAR INPUT BUFFER
// ==========================================

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// ==========================================
// GET VALID NUMBER
// ==========================================

double getNumber(string message)
{
    double number;

    while (true)
    {
        cout << message;
        cin >> number;

        if (!cin.fail())
        {
            return number;
        }

        cout << "\n❌ Invalid input!";
        cout << "\nPlease enter a valid number.\n\n";

        clearInput();
    }
}


// ==========================================
// GET VALID INTEGER
// ==========================================

int getInteger(string message)
{
    int number;

    while (true)
    {
        cout << message;
        cin >> number;

        if (!cin.fail())
        {
            return number;
        }

        cout << "\n❌ Invalid input!";
        cout << "\nPlease enter a valid integer.\n\n";

        clearInput();
    }
}


// ==========================================
// SAVE CALCULATION TO HISTORY
// ==========================================

void addToHistory(string calculation)
{
    history.push_back(calculation);

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
    double a = getNumber("\nEnter first number: ");
    double b = getNumber("Enter second number: ");

    double result = a + b;

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
    double a = getNumber("\nEnter first number: ");
    double b = getNumber("Enter second number: ");

    double result = a - b;

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
    double a = getNumber("\nEnter first number: ");
    double b = getNumber("Enter second number: ");

    double result = a * b;

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
    double a = getNumber("\nEnter first number: ");
    double b = getNumber("Enter second number: ");

    if (b == 0)
    {
        cout << "\n❌ Error: Cannot divide by zero!\n";
        return;
    }

    double result = a / b;

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
    int a = getInteger("\nEnter first integer: ");
    int b = getInteger("Enter second integer: ");

    if (b == 0)
    {
        cout << "\n❌ Error: Cannot calculate modulus by zero!\n";
        return;
    }

    int result = a % b;

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
    double base = getNumber("\nEnter base: ");
    double exponent = getNumber("Enter exponent: ");

    double result = pow(base, exponent);

    if (isnan(result) || isinf(result))
    {
        cout << "\n❌ Error: Result is not a valid number.\n";
        return;
    }

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
    double number = getNumber("\nEnter a number: ");

    if (number < 0)
    {
        cout << "\n❌ Error: Cannot find square root of a negative number!\n";
        return;
    }

    double result = sqrt(number);

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
    double number = getNumber("\nEnter a positive number: ");

    if (number <= 0)
    {
        cout << "\n❌ Error: Natural log requires a positive number!\n";
        return;
    }

    double result = log(number);

    cout << "\nResult = " << result << endl;

    string calculation =
        "ln(" +
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
    double number = getNumber("\nEnter a positive number: ");

    if (number <= 0)
    {
        cout << "\n❌ Error: Log10 requires a positive number!\n";
        return;
    }

    double result = log10(number);

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
    double degree = getNumber("\nEnter angle in degrees: ");

    double pi = acos(-1);
    double radian = degree * pi / 180.0;

    double result = sin(radian);

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
    double degree = getNumber("\nEnter angle in degrees: ");

    double pi = acos(-1);
    double radian = degree * pi / 180.0;

    double result = cos(radian);

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
    double degree = getNumber("\nEnter angle in degrees: ");

    double pi = acos(-1);
    double radian = degree * pi / 180.0;

    // Prevent undefined tan values
    double cosValue = cos(radian);

    if (fabs(cosValue) < 1e-10)
    {
        cout << "\n❌ Error: Tan is undefined for this angle!\n";
        return;
    }

    double result = tan(radian);

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

    history.clear();

    ofstream outputFile("history.txt");
    outputFile.close();

    cout << "\n✅ History cleared successfully!" << endl;
}


// ==========================================
// DISPLAY MENU
// ==========================================

void displayMenu()
{
    cout << "\n\n";

    cout << "============================================"
         << endl;

    cout << "              CALCNOVA"
         << endl;

    cout << "        SCIENTIFIC CALCULATOR"
         << endl;

    cout << "============================================"
         << endl;

    cout << "\n[ BASIC OPERATIONS ]"
         << endl;

    cout << "1.  Addition" << endl;
    cout << "2.  Subtraction" << endl;
    cout << "3.  Multiplication" << endl;
    cout << "4.  Division" << endl;
    cout << "5.  Modulus" << endl;

    cout << "\n[ SCIENTIFIC OPERATIONS ]"
         << endl;

    cout << "6.  Power" << endl;
    cout << "7.  Square Root" << endl;
    cout << "8.  Natural Log" << endl;
    cout << "9.  Log Base 10" << endl;

    cout << "\n[ TRIGONOMETRY ]"
         << endl;

    cout << "10. Sin" << endl;
    cout << "11. Cos" << endl;
    cout << "12. Tan" << endl;

    cout << "\n[ HISTORY ]"
         << endl;

    cout << "13. View History" << endl;
    cout << "14. Clear History" << endl;

    cout << "\n15. Exit" << endl;

    cout << "\n--------------------------------------------"
         << endl;
}


// ==========================================
// MAIN FUNCTION
// ==========================================

int main()
{
    int choice;

    // Load previous calculations
    loadHistory();

    do
    {
        displayMenu();

        choice = getInteger("Enter your choice: ");

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

                cout << "\n❌ Invalid choice!"
                     << endl;

                cout << "Please select a number between 1 and 15."
                     << endl;
        }

    } while (choice != 15);

    return 0;
}