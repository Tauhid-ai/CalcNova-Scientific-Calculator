#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <stdexcept>

using namespace std;

// ======================================================
// CALCNOVA - COMPLETE SCIENTIFIC CALCULATOR
// ======================================================

vector<string> history;
const string HISTORY_FILE = "history.txt";

double previousAnswer = 0.0;
bool hasPreviousAnswer = false;

bool radiansMode = false;

double memoryValue = 0.0;
bool hasMemoryValue = false;

// ======================================================
// INPUT HELPERS
// ======================================================

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getNumber(const string& message)
{
    double value;

    while (true)
    {
        cout << message;

        if (cin >> value)
            return value;

        cout << "[ERROR] Please enter a valid number.\n";
        clearInput();
    }
}

long long getInteger(const string& message)
{
    long long value;

    while (true)
    {
        cout << message;

        if (cin >> value)
            return value;

        cout << "[ERROR] Please enter a valid integer.\n";
        clearInput();
    }
}

// ======================================================
// HISTORY
// ======================================================

void loadHistory()
{
    ifstream file(HISTORY_FILE);

    if (!file.is_open())
        return;

    string line;

    while (getline(file, line))
    {
        if (!line.empty())
            history.push_back(line);
    }
}

void saveHistory()
{
    ofstream file(HISTORY_FILE);

    if (!file.is_open())
    {
        cout << "\n[ERROR] Unable to save history.\n";
        return;
    }

    for (const string& item : history)
        file << item << '\n';
}

void addToHistory(const string& calculation)
{
    history.push_back(calculation);
    saveHistory();
}

void viewHistory()
{
    cout << "\n====================================================\n";
    cout << "                 CALCULATION HISTORY\n";
    cout << "====================================================\n";

    if (history.empty())
    {
        cout << "No calculations yet.\n";
    }
    else
    {
        for (size_t i = 0; i < history.size(); ++i)
            cout << i + 1 << ". " << history[i] << '\n';
    }

    cout << "====================================================\n";
}

void clearHistory()
{
    if (history.empty())
    {
        cout << "\nHistory is already empty.\n";
        return;
    }

    char choice;

    cout << "\nAre you sure you want to clear history? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        history.clear();

        ofstream file(HISTORY_FILE, ios::trunc);

        if (file.is_open())
            cout << "\nHistory cleared successfully!\n";
        else
            cout << "\n[ERROR] Unable to clear history file.\n";
    }
    else
    {
        cout << "\nHistory was not cleared.\n";
    }
}

// ======================================================
// PREVIOUS ANSWER
// ======================================================

void setPreviousAnswer(double result)
{
    previousAnswer = result;
    hasPreviousAnswer = true;
}

void showPreviousAnswer()
{
    cout << "\n====================================================\n";

    if (hasPreviousAnswer)
        cout << "Previous Answer = " << previousAnswer << '\n';
    else
        cout << "No previous answer available in this session.\n";

    cout << "====================================================\n";
}

// ======================================================
// MEMORY
// ======================================================

void memoryStore()
{
    if (!hasPreviousAnswer)
    {
        cout << "\n[ERROR] No previous answer available to store.\n";
        return;
    }

    memoryValue = previousAnswer;
    hasMemoryValue = true;

    cout << "\nMemory stored = " << memoryValue << '\n';
}

void memoryRecall()
{
    if (!hasMemoryValue)
    {
        cout << "\nMemory is empty.\n";
        return;
    }

    cout << "\nMemory = " << memoryValue << '\n';
    setPreviousAnswer(memoryValue);
}

void memoryAdd()
{
    if (!hasPreviousAnswer)
    {
        cout << "\n[ERROR] No previous answer available.\n";
        return;
    }

    if (!hasMemoryValue)
    {
        memoryValue = 0.0;
        hasMemoryValue = true;
    }

    memoryValue += previousAnswer;

    cout << "\nMemory = " << memoryValue << '\n';
}

void memoryClear()
{
    memoryValue = 0.0;
    hasMemoryValue = false;

    cout << "\nMemory cleared successfully!\n";
}

void showMemory()
{
    cout << "\n====================================================\n";

    if (hasMemoryValue)
        cout << "Memory = " << memoryValue << '\n';
    else
        cout << "Memory is empty.\n";

    cout << "====================================================\n";
}

// ======================================================
// ANGLE MODE
// ======================================================

void toggleAngleMode()
{
    radiansMode = !radiansMode;

    cout << "\nAngle mode: "
         << (radiansMode ? "RADIANS" : "DEGREES") << '\n';
}

// ======================================================
// BASIC OPERATIONS
// ======================================================

void addition()
{
    double a = getNumber("Enter first number: ");
    double b = getNumber("Enter second number: ");
    double result = a + b;

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory(to_string(a) + " + " + to_string(b) +
                 " = " + to_string(result));
}

void subtraction()
{
    double a = getNumber("Enter first number: ");
    double b = getNumber("Enter second number: ");
    double result = a - b;

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory(to_string(a) + " - " + to_string(b) +
                 " = " + to_string(result));
}

void multiplication()
{
    double a = getNumber("Enter first number: ");
    double b = getNumber("Enter second number: ");
    double result = a * b;

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory(to_string(a) + " * " + to_string(b) +
                 " = " + to_string(result));
}

void division()
{
    double a = getNumber("Enter numerator: ");
    double b = getNumber("Enter denominator: ");

    if (fabs(b) < 1e-15)
    {
        cout << "\n[ERROR] Division by zero is not allowed.\n";
        return;
    }

    double result = a / b;

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory(to_string(a) + " / " + to_string(b) +
                 " = " + to_string(result));
}

void modulusOperation()
{
    long long a = getInteger("Enter first integer: ");
    long long b = getInteger("Enter second integer: ");

    if (b == 0)
    {
        cout << "\n[ERROR] Modulus by zero is not allowed.\n";
        return;
    }

    long long result = a % b;

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(static_cast<double>(result));

    addToHistory(to_string(a) + " % " + to_string(b) +
                 " = " + to_string(result));
}

// ======================================================
// SCIENTIFIC OPERATIONS
// ======================================================

void power()
{
    double base = getNumber("Enter base: ");
    double exponent = getNumber("Enter exponent: ");
    double result = pow(base, exponent);

    if (!isfinite(result))
    {
        cout << "\n[ERROR] Result is too large or invalid.\n";
        return;
    }

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("pow(" + to_string(base) + ", " +
                 to_string(exponent) + ") = " + to_string(result));
}

void squareRoot()
{
    double number = getNumber("Enter number: ");

    if (number < 0)
    {
        cout << "\n[ERROR] Square root requires a non-negative number.\n";
        return;
    }

    double result = sqrt(number);

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("sqrt(" + to_string(number) +
                 ") = " + to_string(result));
}

void naturalLog()
{
    double number = getNumber("Enter number: ");

    if (number <= 0)
    {
        cout << "\n[ERROR] Natural logarithm requires number > 0.\n";
        return;
    }

    double result = log(number);

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("ln(" + to_string(number) +
                 ") = " + to_string(result));
}

void logBase10()
{
    double number = getNumber("Enter number: ");

    if (number <= 0)
    {
        cout << "\n[ERROR] Logarithm requires number > 0.\n";
        return;
    }

    double result = log10(number);

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("log10(" + to_string(number) +
                 ") = " + to_string(result));
}

// ======================================================
// TRIGONOMETRY
// ======================================================

double toRadians(double angle)
{
    if (radiansMode)
        return angle;

    return angle * acos(-1.0) / 180.0;
}

string angleUnit()
{
    return radiansMode ? " radians" : " degrees";
}

void sine()
{
    double angle = getNumber("Enter angle: ");
    double result = sin(toRadians(angle));

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("sin(" + to_string(angle) + angleUnit() +
                 ") = " + to_string(result));
}

void cosine()
{
    double angle = getNumber("Enter angle: ");
    double result = cos(toRadians(angle));

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("cos(" + to_string(angle) + angleUnit() +
                 ") = " + to_string(result));
}

void tangent()
{
    double angle = getNumber("Enter angle: ");
    double radians = toRadians(angle);

    if (fabs(cos(radians)) < 1e-10)
    {
        cout << "\n[ERROR] Tangent is undefined for this angle.\n";
        return;
    }

    double result = tan(radians);

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("tan(" + to_string(angle) + angleUnit() +
                 ") = " + to_string(result));
}

// ======================================================
// OTHER OPERATIONS
// ======================================================

void percentage()
{
    double number = getNumber("Enter number: ");
    double result = number / 100.0;

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory(to_string(number) + "% = " + to_string(result));
}

void piValue()
{
    double result = acos(-1.0);

    cout << fixed << setprecision(10);
    cout << "\nPI = " << result << '\n';
    cout.unsetf(ios::floatfield);
    cout << setprecision(6);

    setPreviousAnswer(result);
    addToHistory("PI = " + to_string(result));
}

void eValue()
{
    double result = exp(1.0);

    cout << fixed << setprecision(10);
    cout << "\ne = " << result << '\n';
    cout.unsetf(ios::floatfield);
    cout << setprecision(6);

    setPreviousAnswer(result);
    addToHistory("e = " + to_string(result));
}

void absoluteValue()
{
    double number = getNumber("Enter number: ");
    double result = fabs(number);

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("abs(" + to_string(number) +
                 ") = " + to_string(result));
}

void reciprocal()
{
    double number = getNumber("Enter number: ");

    if (fabs(number) < 1e-15)
    {
        cout << "\n[ERROR] Reciprocal of zero is undefined.\n";
        return;
    }

    double result = 1.0 / number;

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("1/" + to_string(number) +
                 " = " + to_string(result));
}

void factorial()
{
    long long n = getInteger("Enter a non-negative integer: ");

    if (n < 0 || n > 20)
    {
        cout << "\n[ERROR] Please enter a number between 0 and 20.\n";
        return;
    }

    unsigned long long result = 1;

    for (long long i = 1; i <= n; ++i)
        result *= static_cast<unsigned long long>(i);

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(static_cast<double>(result));

    addToHistory(to_string(n) + "! = " + to_string(result));
}

void square()
{
    double number = getNumber("Enter number: ");
    double result = number * number;

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory(to_string(number) + "^2 = " +
                 to_string(result));
}

void cube()
{
    double number = getNumber("Enter number: ");
    double result = number * number * number;

    cout << "\nResult = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory(to_string(number) + "^3 = " +
                 to_string(result));
}

void exponential()
{
    double number = getNumber("Enter value of x: ");
    double result = exp(number);

    if (!isfinite(result))
    {
        cout << "\n[ERROR] Result is too large.\n";
        return;
    }

    cout << "\ne^" << number << " = " << result << '\n';
    setPreviousAnswer(result);

    addToHistory("e^" + to_string(number) +
                 " = " + to_string(result));
}

// ======================================================
// EXPRESSION CALCULATOR
// Supports: + - * / % ^ ( ) and Ans
// ======================================================

class ExpressionParser
{
private:
    string expression;
    size_t position = 0;

    void skipSpaces()
    {
        while (position < expression.size() &&
               isspace(static_cast<unsigned char>(expression[position])))
        {
            ++position;
        }
    }

    bool match(char c)
    {
        skipSpaces();

        if (position < expression.size() && expression[position] == c)
        {
            ++position;
            return true;
        }

        return false;
    }

    double parseNumber()
    {
        skipSpaces();

        size_t start = position;
        bool hasDigit = false;
        bool hasDot = false;

        while (position < expression.size())
        {
            char c = expression[position];

            if (isdigit(static_cast<unsigned char>(c)))
            {
                hasDigit = true;
                ++position;
            }
            else if (c == '.' && !hasDot)
            {
                hasDot = true;
                ++position;
            }
            else
            {
                break;
            }
        }

        if (!hasDigit)
            throw runtime_error("Expected a number.");

        try
        {
            return stod(expression.substr(start, position - start));
        }
        catch (...)
        {
            throw runtime_error("Invalid number.");
        }
    }

    double parsePrimary()
    {
        skipSpaces();

        if (match('('))
        {
            double value = parseExpression();

            if (!match(')'))
                throw runtime_error("Missing closing parenthesis.");

            return value;
        }

        if (position + 3 <= expression.size())
        {
            string word = expression.substr(position, 3);

            for (char& c : word)
                c = static_cast<char>(
                    tolower(static_cast<unsigned char>(c))
                );

            if (word == "ans")
            {
                if (!hasPreviousAnswer)
                    throw runtime_error("No previous answer available.");

                position += 3;
                return previousAnswer;
            }
        }

        return parseNumber();
    }

    double parseUnary()
    {
        skipSpaces();

        if (match('+'))
            return parseUnary();

        if (match('-'))
            return -parseUnary();

        return parsePrimary();
    }

    double parsePower()
    {
        double left = parseUnary();

        skipSpaces();

        if (match('^'))
        {
            double right = parsePower();
            return pow(left, right);
        }

        return left;
    }

    double parseTerm()
    {
        double value = parsePower();

        while (true)
        {
            if (match('*'))
            {
                value *= parsePower();
            }
            else if (match('/'))
            {
                double divisor = parsePower();

                if (fabs(divisor) < 1e-15)
                    throw runtime_error("Division by zero is not allowed.");

                value /= divisor;
            }
            else if (match('%'))
            {
                double divisor = parsePower();

                if (fabs(divisor) < 1e-15)
                    throw runtime_error("Modulus by zero is not allowed.");

                value = fmod(value, divisor);
            }
            else
            {
                break;
            }
        }

        return value;
    }

    double parseExpression()
    {
        double value = parseTerm();

        while (true)
        {
            if (match('+'))
                value += parseTerm();
            else if (match('-'))
                value -= parseTerm();
            else
                break;
        }

        return value;
    }

public:
    explicit ExpressionParser(const string& input)
        : expression(input)
    {
    }

    double parse()
    {
        double result = parseExpression();

        skipSpaces();

        if (position != expression.size())
            throw runtime_error("Invalid expression.");

        if (!isfinite(result))
            throw runtime_error("Result is too large or invalid.");

        return result;
    }
};

void expressionCalculator()
{
    clearInput();

    cout << "\n====================================================\n";
    cout << "              EXPRESSION CALCULATOR\n";
    cout << "====================================================\n";

    cout << "\nSupported:\n";
    cout << "+  -  *  /  %  ^  ( )  Ans\n";

    cout << "\nExamples:\n";
    cout << "5 + 10 * 2\n";
    cout << "(10 + 5) * 2\n";
    cout << "2 ^ 3 + 5\n";
    cout << "Ans + 10\n";

    cout << "\nEnter expression: ";

    string expression;
    getline(cin, expression);

    if (expression.empty())
    {
        cout << "\n[ERROR] Expression cannot be empty.\n";
        return;
    }

    try
    {
        ExpressionParser parser(expression);
        double result = parser.parse();

        cout << "\nResult = " << result << '\n';

        setPreviousAnswer(result);

        addToHistory(expression + " = " + to_string(result));
    }
    catch (const exception& error)
    {
        cout << "\n[ERROR] " << error.what() << '\n';
    }
}

// ======================================================
// ABOUT
// ======================================================

void about()
{
    cout << "\n====================================================\n";
    cout << "                   ABOUT CALCNOVA\n";
    cout << "====================================================\n";

    cout << "CalcNova - Scientific Calculator\n\n";
    cout << "Version : 6.0\n";
    cout << "Language: C++\n\n";

    cout << "Features:\n";
    cout << "- Basic arithmetic operations\n";
    cout << "- Scientific calculations\n";
    cout << "- Trigonometric functions\n";
    cout << "- Degree/Radian mode\n";
    cout << "- Factorial, Square and Cube\n";
    cout << "- Exponential calculation\n";
    cout << "- Persistent calculation history\n";
    cout << "- Previous Answer (Ans)\n";
    cout << "- Memory functions\n";
    cout << "- Expression Calculator\n";
    cout << "- Input validation and error handling\n";

    cout << "====================================================\n";
}

// ======================================================
// HELP
// ======================================================

void help()
{
    cout << "\n====================================================\n";
    cout << "                       HELP\n";
    cout << "====================================================\n";

    cout << "\n[ BASIC OPERATIONS ]\n";
    cout << "1  - Addition\n";
    cout << "2  - Subtraction\n";
    cout << "3  - Multiplication\n";
    cout << "4  - Division\n";
    cout << "5  - Modulus\n";

    cout << "\n[ SCIENTIFIC ]\n";
    cout << "6  - Power\n";
    cout << "7  - Square Root\n";
    cout << "8  - Natural Log\n";
    cout << "9  - Log Base 10\n";

    cout << "\n[ TRIGONOMETRY ]\n";
    cout << "10 - Sin\n";
    cout << "11 - Cos\n";
    cout << "12 - Tan\n";

    cout << "\n[ OTHER ]\n";
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
    cout << "22 - Exit\n";

    cout << "\n[ ANSWER & MEMORY ]\n";
    cout << "27 - Show Previous Answer\n";
    cout << "28 - Toggle Degree/Radian\n";
    cout << "29 - Memory Store (MS)\n";
    cout << "30 - Memory Recall (MR)\n";
    cout << "31 - Memory Add (M+)\n";
    cout << "32 - Memory Clear (MC)\n";
    cout << "33 - Show Memory\n";
    cout << "34 - Expression Calculator\n";

    cout << "\nExpression Calculator supports:\n";
    cout << "+  -  *  /  %  ^  ( ) and Ans\n";

    cout << "====================================================\n";
}

// ======================================================
// MENU
// ======================================================

void displayMenu()
{
    cout << "\n\n====================================================\n";
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
    cout << "17. Reciprocal\n";
    cout << "23. Factorial\n";
    cout << "24. Square\n";
    cout << "25. Cube\n";
    cout << "26. Exponential (e^x)\n";

    cout << "\n[ HISTORY ]\n";
    cout << "18. View History\n";
    cout << "19. Clear History\n";

    cout << "\n[ INFORMATION ]\n";
    cout << "20. About\n";
    cout << "21. Help\n";
    cout << "22. Exit\n";

    cout << "\n[ ANSWER & MEMORY ]\n";
    cout << "27. Show Previous Answer\n";
    cout << "28. Toggle Degree/Radian\n";
    cout << "29. Memory Store (MS)\n";
    cout << "30. Memory Recall (MR)\n";
    cout << "31. Memory Add (M+)\n";
    cout << "32. Memory Clear (MC)\n";
    cout << "33. Show Memory\n";
    cout << "34. Expression Calculator\n";

    cout << "\n====================================================\n";
}

// ======================================================
// MAIN
// ======================================================

int main()
{
    loadHistory();

    int choice;

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
            case 1:  addition(); break;
            case 2:  subtraction(); break;
            case 3:  multiplication(); break;
            case 4:  division(); break;
            case 5:  modulusOperation(); break;

            case 6:  power(); break;
            case 7:  squareRoot(); break;
            case 8:  naturalLog(); break;
            case 9:  logBase10(); break;

            case 10: sine(); break;
            case 11: cosine(); break;
            case 12: tangent(); break;

            case 13: percentage(); break;
            case 14: piValue(); break;
            case 15: eValue(); break;
            case 16: absoluteValue(); break;
            case 17: reciprocal(); break;

            case 18: viewHistory(); break;
            case 19: clearHistory(); break;

            case 20: about(); break;
            case 21: help(); break;

            case 22:
                cout << "\n====================================================\n";
                cout << "          Thank you for using CalcNova!\n";
                cout << "                   Goodbye!\n";
                cout << "====================================================\n";
                break;

            case 23: factorial(); break;
            case 24: square(); break;
            case 25: cube(); break;
            case 26: exponential(); break;

            case 27: showPreviousAnswer(); break;
            case 28: toggleAngleMode(); break;
            case 29: memoryStore(); break;
            case 30: memoryRecall(); break;
            case 31: memoryAdd(); break;
            case 32: memoryClear(); break;
            case 33: showMemory(); break;
            case 34: expressionCalculator(); break;

            default:
                cout << "\n[ERROR] Invalid choice. Please enter 1-34.\n";
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
