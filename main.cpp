#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

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

        cout << "\n[ERROR] Please enter a valid number.\n";

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

        cout << "\n[ERROR] Please enter a valid integer.\n";

        clearInput();
    }
}


// ==========================================
// FORMAT NUMBER
// ==========================================

string formatNumber(double number)
{
    ostringstream output;

    output << fixed << setprecision(2) << number;

    string result = output.str();

    // Remove unnecessary zeros
    while (!result.empty() && result.back() == '0')
    {
        result.pop_back();
    }

    // Remove decimal point if not needed
    if (!result.empty() && result.back() == '.')
    {
        result.pop_back();
    }

    return result;
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

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        formatNumber(a) + " + " +
        formatNumber(b) + " = " +
        formatNumber(result);

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

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        formatNumber(a) + " - " +
        formatNumber(b) + " = " +
        formatNumber(result);

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

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        formatNumber(a) + " * " +
        formatNumber(b) + " = " +
        formatNumber(result);

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
        cout << "\n[ERROR] Cannot divide by zero!\n";
        return;
    }

    double result = a / b;

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        formatNumber(a) + " / " +
        formatNumber(b) + " = " +
        formatNumber(result);

    addToHistory(calculation);
}


// ==========================================
// MODULUS
// ==========================================
// Function renamed from modulus() to
// modulusOperation() to avoid conflict with
// std::modulus from the C++ standard library.
// ==========================================

void modulusOperation()
{
    int a = getInteger("\nEnter first integer: ");
    int b = getInteger("Enter second integer: ");

    if (b == 0)
    {
        cout << "\n[ERROR] Cannot calculate modulus by zero!\n";
        return;
    }

    int result = a % b;

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << result << endl;
    cout << "--------------------------------------------\n";

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
        cout << "\n[ERROR] Result is not a valid number!\n";
        return;
    }

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        formatNumber(base) + " ^ " +
        formatNumber(exponent) + " = " +
        formatNumber(result);

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
        cout << "\n[ERROR] Cannot find square root of a negative number!\n";
        return;
    }

    double result = sqrt(number);

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        "sqrt(" +
        formatNumber(number) +
        ") = " +
        formatNumber(result);

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
        cout << "\n[ERROR] Natural log requires a positive number!\n";
        return;
    }

    double result = log(number);

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        "ln(" +
        formatNumber(number) +
        ") = " +
        formatNumber(result);

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
        cout << "\n[ERROR] Log10 requires a positive number!\n";
        return;
    }

    double result = log10(number);

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        "log10(" +
        formatNumber(number) +
        ") = " +
        formatNumber(result);

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

    if (fabs(result) < 0.000001)
    {
        result = 0;
    }

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        "sin(" +
        formatNumber(degree) +
        " deg) = " +
        formatNumber(result);

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

    if (fabs(result) < 0.000001)
    {
        result = 0;
    }

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        "cos(" +
        formatNumber(degree) +
        " deg) = " +
        formatNumber(result);

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

    double cosValue = cos(radian);

    if (fabs(cosValue) < 0.000001)
    {
        cout << "\n[ERROR] Tan is undefined for this angle!\n";
        return;
    }

    double result = tan(radian);

    if (fabs(result) < 0.000001)
    {
        result = 0;
    }

    cout << "\n--------------------------------------------\n";
    cout << "Result = " << formatNumber(result) << endl;
    cout << "--------------------------------------------\n";

    string calculation =
        "tan(" +
        formatNumber(degree) +
        " deg) = " +
        formatNumber(result);

    addToHistory(calculation);
}


// ==========================================
// SHOW HISTORY
// ==========================================

void showHistory()
{
    cout << "\n============================================\n";
    cout << "          CALCULATION HISTORY\n";
    cout << "============================================\n";

    if (history.empty())
    {
        cout << "\nNo calculations yet.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(history.size()); i++)
    {
        cout << i + 1 << ". " << history[i] << endl;
    }

    cout << "============================================\n";
}


// ==========================================
// CLEAR HISTORY
// ==========================================

void clearHistory()
{
    if (history.empty())
    {
        cout << "\nHistory is already empty.\n";
        return;
    }

    history.clear();

    ofstream outputFile("history.txt");
    outputFile.close();

    cout << "\nHistory cleared successfully!\n";
}


// ==========================================
// DISPLAY MENU
// ==========================================

void displayMenu()
{
    cout << "\n\n";
    cout << "============================================\n";
    cout << "              CALCNOVA\n";
    cout << "        SCIENTIFIC CALCULATOR\n";
    cout << "============================================\n";

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

    cout << "\n[ HISTORY ]\n";
    cout << "13. View History\n";
    cout << "14. Clear History\n";

    cout << "\n15. Exit\n";

    cout << "\n--------------------------------------------\n";
}


// ==========================================
// MAIN
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
                showHistory();
                break;

            case 14:
                clearHistory();
                break;

            case 15:
                cout << "\n============================================\n";
                cout << "       Thank you for using CalcNova!\n";
                cout << "============================================\n";
                break;

            default:
                cout << "\n[ERROR] Invalid choice!\n";
                cout << "Please select a number between 1 and 15.\n";
        }

    } while (choice != 15);

    return 0;
}