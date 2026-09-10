#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
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
// STATISTICS CALCULATOR
// ======================================================

void statisticsCalculator()
{
    int n = static_cast<int>(getInteger("Enter number of values (2 or more): "));

    if (n < 2)
    {
        cout << "\n[ERROR] Please enter at least 2 values.\n";
        return;
    }

    vector<double> values(n);
    double sum = 0.0;

    for (int i = 0; i < n; ++i)
    {
        values[i] = getNumber("Enter value " + to_string(i + 1) + ": ");
        sum += values[i];
    }

    double mean = sum / n;
    double minimum = values[0];
    double maximum = values[0];

    for (double value : values)
    {
        minimum = min(minimum, value);
        maximum = max(maximum, value);
    }

    double range = maximum - minimum;
    double variance = 0.0;

    for (double value : values)
        variance += (value - mean) * (value - mean);

    variance /= n;
    double standardDeviation = sqrt(variance);

    cout << "\n====================================================\n";
    cout << "                 STATISTICS RESULT\n";
    cout << "====================================================\n";
    cout << "Sum                = " << sum << '\n';
    cout << "Mean / Average     = " << mean << '\n';
    cout << "Minimum            = " << minimum << '\n';
    cout << "Maximum            = " << maximum << '\n';
    cout << "Range              = " << range << '\n';
    cout << "Standard Deviation = " << standardDeviation << '\n';
    cout << "====================================================\n";

    setPreviousAnswer(mean);
    addToHistory("Statistics: mean = " + to_string(mean));
}

// ======================================================
// SCIENTIFIC CONSTANTS
// ======================================================

void showConstant(const string& name, double value, const string& unit)
{
    cout << "\n" << name << " = " << setprecision(12) << value;
    if (!unit.empty()) cout << " " << unit;
    cout << '\n';
    cout << setprecision(6);
    setPreviousAnswer(value);
    addToHistory(name + " = " + to_string(value));
}

void speedOfLight() { showConstant("Speed of Light (c)", 299792458.0, "m/s"); }
void gravitationalConstant() { showConstant("Gravitational Constant (G)", 6.67430e-11, "m^3 kg^-1 s^-2"); }
void planckConstant() { showConstant("Planck Constant (h)", 6.62607015e-34, "J s"); }
void avogadroConstant() { showConstant("Avogadro Constant (NA)", 6.02214076e23, "mol^-1"); }
void electronCharge() { showConstant("Elementary Charge (e)", 1.602176634e-19, "C"); }

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
    cout << "- Statistics Calculator\n";
    cout << "- Scientific Constants\n";
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
    cout << "35 - Statistics Calculator\n";
    cout << "36 - Speed of Light (c)\n";
    cout << "37 - Gravitational Constant (G)\n";
    cout << "38 - Planck Constant (h)\n";
    cout << "39 - Avogadro Constant (NA)\n";
    cout << "40 - Electron Charge (e)\n";
    cout << "41 - GCD & LCM Calculator\n";
    cout << "42 - Binary <-> Decimal Converter\n";
    cout << "43 - Unit Converter\n";
    cout << "44 - Number System Converter\n";
    cout << "45 - Combinations & Permutations (nCr / nPr)\n";
    cout << "46 - Quadratic Equation Solver\n";
    cout << "47 - Matrix Calculator\n";
    cout << "48 - Matrix Determinant Calculator\n";

    cout << "\nExpression Calculator supports:\n";
    cout << "+  -  *  /  %  ^  ( ) and Ans\n";

    cout << "====================================================\n";
}


// ======================================================
// GCD & LCM CALCULATOR
// ======================================================

void gcdLcmCalculator()
{
    long long a = getInteger("Enter first integer: ");
    long long b = getInteger("Enter second integer: ");

    long long x = llabs(a);
    long long y = llabs(b);

    while (y != 0)
    {
        long long temp = x % y;
        x = y;
        y = temp;
    }

    long long gcd = x;
    long long lcm = 0;

    if (a != 0 && b != 0)
        lcm = llabs((a / gcd) * b);

    cout << "\n====================================================\n";
    cout << "                 GCD & LCM RESULT\n";
    cout << "====================================================\n";
    cout << "GCD = " << gcd << '\n';
    cout << "LCM = " << lcm << '\n';
    cout << "====================================================\n";

    setPreviousAnswer(static_cast<double>(gcd));
    addToHistory("GCD(" + to_string(a) + ", " + to_string(b) + ") = " +
                 to_string(gcd) + " | LCM = " + to_string(lcm));
}

// ======================================================
// BINARY <-> DECIMAL CONVERTER
// ======================================================

void binaryDecimalConverter()
{
    int choice;

    cout << "\n====================================================\n";
    cout << "             BINARY <-> DECIMAL CONVERTER\n";
    cout << "====================================================\n";
    cout << "1. Binary to Decimal\n";
    cout << "2. Decimal to Binary\n";
    cout << "\nEnter your choice: ";

    while (!(cin >> choice) || (choice != 1 && choice != 2))
    {
        cout << "[ERROR] Please enter 1 or 2: ";
        clearInput();
    }

    if (choice == 1)
    {
        string binary;
        cout << "\nEnter binary number: ";
        cin >> binary;

        unsigned long long decimal = 0;

        for (char bit : binary)
        {
            if (bit != '0' && bit != '1')
            {
                cout << "\n[ERROR] Invalid binary number. Use only 0 and 1.\n";
                return;
            }

            if (decimal > (numeric_limits<unsigned long long>::max() - (bit - '0')) / 2)
            {
                cout << "\n[ERROR] Binary number is too large.\n";
                return;
            }

            decimal = decimal * 2 + (bit - '0');
        }

        cout << "\nDecimal = " << decimal << '\n';
        setPreviousAnswer(static_cast<double>(decimal));
        addToHistory("Binary " + binary + " = Decimal " + to_string(decimal));
    }
    else
    {
        long long decimal = getInteger("Enter decimal integer: ");

        if (decimal < 0)
        {
            cout << "\n[ERROR] Please enter a non-negative decimal integer.\n";
            return;
        }

        if (decimal == 0)
        {
            cout << "\nBinary = 0\n";
            setPreviousAnswer(0.0);
            addToHistory("Decimal 0 = Binary 0");
            return;
        }

        unsigned long long value = static_cast<unsigned long long>(decimal);
        string binary;

        while (value > 0)
        {
            binary.push_back((value % 2) ? '1' : '0');
            value /= 2;
        }

        reverse(binary.begin(), binary.end());

        cout << "\nBinary = " << binary << '\n';
        setPreviousAnswer(static_cast<double>(decimal));
        addToHistory("Decimal " + to_string(decimal) + " = Binary " + binary);
    }

    cout << "====================================================\n";
}

// ======================================================
// UNIT CONVERTER - OPTION 43
// ======================================================

void unitConverter()
{
    int type;

    cout << "\n====================================================\n";
    cout << "                  UNIT CONVERTER\n";
    cout << "====================================================\n";
    cout << "1. Length\n";
    cout << "2. Weight\n";
    cout << "3. Temperature\n";
    cout << "4. Back\n";
    cout << "====================================================\n";

    cout << "Enter your choice: ";

    while (!(cin >> type) || type < 1 || type > 4)
    {
        cout << "[ERROR] Please enter 1-4: ";
        clearInput();
    }

    if (type == 4)
        return;

    if (type == 1)
    {
        int choice;
        double value, result;

        cout << "\n--- LENGTH CONVERTER ---\n";
        cout << "1. Meter -> Kilometer\n";
        cout << "2. Kilometer -> Meter\n";
        cout << "3. Meter -> Centimeter\n";
        cout << "4. Centimeter -> Meter\n";
        cout << "5. Kilometer -> Mile\n";
        cout << "6. Mile -> Kilometer\n";
        cout << "7. Feet -> Meter\n";
        cout << "8. Meter -> Feet\n";

        cout << "\nEnter choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 8)
        {
            cout << "[ERROR] Please enter 1-8: ";
            clearInput();
        }

        value = getNumber("Enter value: ");

        switch (choice)
        {
            case 1: result = value / 1000.0; cout << "\nResult = " << result << " km\n"; break;
            case 2: result = value * 1000.0; cout << "\nResult = " << result << " m\n"; break;
            case 3: result = value * 100.0; cout << "\nResult = " << result << " cm\n"; break;
            case 4: result = value / 100.0; cout << "\nResult = " << result << " m\n"; break;
            case 5: result = value * 0.621371; cout << "\nResult = " << result << " miles\n"; break;
            case 6: result = value * 1.609344; cout << "\nResult = " << result << " km\n"; break;
            case 7: result = value * 0.3048; cout << "\nResult = " << result << " m\n"; break;
            case 8: result = value * 3.28084; cout << "\nResult = " << result << " feet\n"; break;
            default: return;
        }

        setPreviousAnswer(result);
        addToHistory("Unit Conversion - Length");
    }
    else if (type == 2)
    {
        int choice;
        double value, result;

        cout << "\n--- WEIGHT CONVERTER ---\n";
        cout << "1. Kilogram -> Gram\n";
        cout << "2. Gram -> Kilogram\n";
        cout << "3. Kilogram -> Pound\n";
        cout << "4. Pound -> Kilogram\n";
        cout << "5. Gram -> Milligram\n";
        cout << "6. Milligram -> Gram\n";

        cout << "\nEnter choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 6)
        {
            cout << "[ERROR] Please enter 1-6: ";
            clearInput();
        }

        value = getNumber("Enter value: ");

        switch (choice)
        {
            case 1: result = value * 1000.0; cout << "\nResult = " << result << " g\n"; break;
            case 2: result = value / 1000.0; cout << "\nResult = " << result << " kg\n"; break;
            case 3: result = value * 2.20462; cout << "\nResult = " << result << " pounds\n"; break;
            case 4: result = value * 0.453592; cout << "\nResult = " << result << " kg\n"; break;
            case 5: result = value * 1000.0; cout << "\nResult = " << result << " mg\n"; break;
            case 6: result = value / 1000.0; cout << "\nResult = " << result << " g\n"; break;
            default: return;
        }

        setPreviousAnswer(result);
        addToHistory("Unit Conversion - Weight");
    }
    else
    {
        int choice;
        double value, result;

        cout << "\n--- TEMPERATURE CONVERTER ---\n";
        cout << "1. Celsius -> Fahrenheit\n";
        cout << "2. Fahrenheit -> Celsius\n";
        cout << "3. Celsius -> Kelvin\n";
        cout << "4. Kelvin -> Celsius\n";
        cout << "5. Fahrenheit -> Kelvin\n";
        cout << "6. Kelvin -> Fahrenheit\n";

        cout << "\nEnter choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 6)
        {
            cout << "[ERROR] Please enter 1-6: ";
            clearInput();
        }

        value = getNumber("Enter temperature: ");

        if ((choice == 4 || choice == 6) && value < 0)
        {
            cout << "\n[ERROR] Kelvin cannot be negative.\n";
            return;
        }

        switch (choice)
        {
            case 1: result = (value * 9.0 / 5.0) + 32.0; cout << "\nResult = " << result << " F\n"; break;
            case 2: result = (value - 32.0) * 5.0 / 9.0; cout << "\nResult = " << result << " C\n"; break;
            case 3: result = value + 273.15; cout << "\nResult = " << result << " K\n"; break;
            case 4: result = value - 273.15; cout << "\nResult = " << result << " C\n"; break;
            case 5: result = (value - 32.0) * 5.0 / 9.0 + 273.15; cout << "\nResult = " << result << " K\n"; break;
            case 6: result = (value - 273.15) * 9.0 / 5.0 + 32.0; cout << "\nResult = " << result << " F\n"; break;
            default: return;
        }

        setPreviousAnswer(result);
        addToHistory("Unit Conversion - Temperature");
    }

    cout << "\n====================================================\n";
}


// ======================================================
// NUMBER SYSTEM CONVERTER - OPTION 44
// ======================================================

string decimalToBase(unsigned long long number, int base)
{
    if (number == 0)
        return "0";

    const string digits = "0123456789ABCDEF";
    string result;

    while (number > 0)
    {
        result.push_back(digits[number % base]);
        number /= base;
    }

    reverse(result.begin(), result.end());
    return result;
}

bool isValidForBase(const string& value, int base)
{
    if (value.empty())
        return false;

    size_t start = (value[0] == '-') ? 1 : 0;

    if (start == value.size())
        return false;

    for (size_t i = start; i < value.size(); ++i)
    {
        char c = static_cast<char>(toupper(
            static_cast<unsigned char>(value[i])
        ));

        int digit;

        if (c >= '0' && c <= '9')
            digit = c - '0';
        else if (c >= 'A' && c <= 'F')
            digit = c - 'A' + 10;
        else
            return false;

        if (digit >= base)
            return false;
    }

    return true;
}

unsigned long long baseToDecimal(const string& value, int base)
{
    unsigned long long result = 0;

    for (char c : value)
    {
        int digit;

        c = static_cast<char>(toupper(
            static_cast<unsigned char>(c)
        ));

        if (c >= '0' && c <= '9')
            digit = c - '0';
        else
            digit = c - 'A' + 10;

        if (result > (numeric_limits<unsigned long long>::max() -
                      static_cast<unsigned long long>(digit)) /
                     static_cast<unsigned long long>(base))
        {
            throw runtime_error("Number is too large.");
        }

        result = result * static_cast<unsigned long long>(base) +
                 static_cast<unsigned long long>(digit);
    }

    return result;
}

void numberSystemConverter()
{
    int choice;

    cout << "\n====================================================\n";
    cout << "                NUMBER SYSTEM CONVERTER\n";
    cout << "====================================================\n";
    cout << "1. Decimal -> Binary\n";
    cout << "2. Decimal -> Octal\n";
    cout << "3. Decimal -> Hexadecimal\n";
    cout << "4. Binary -> Decimal\n";
    cout << "5. Octal -> Decimal\n";
    cout << "6. Hexadecimal -> Decimal\n";
    cout << "7. Binary -> Octal\n";
    cout << "8. Binary -> Hexadecimal\n";
    cout << "9. Back\n";
    cout << "====================================================\n";

    cout << "Enter your choice: ";

    while (!(cin >> choice) || choice < 1 || choice > 9)
    {
        cout << "[ERROR] Please enter 1-9: ";
        clearInput();
    }

    if (choice == 9)
        return;

    try
    {
        if (choice >= 1 && choice <= 3)
        {
            long long decimal = getInteger("Enter decimal number: ");

            if (decimal < 0)
            {
                cout << "\n[ERROR] Please enter a non-negative decimal number.\n";
                return;
            }

            int base = (choice == 1) ? 2 : (choice == 2 ? 8 : 16);
            string result = decimalToBase(
                static_cast<unsigned long long>(decimal), base
            );

            cout << "\nResult = " << result << '\n';

            setPreviousAnswer(static_cast<double>(decimal));
            addToHistory(
                "Decimal " + to_string(decimal) +
                " converted to base " + to_string(base) +
                " = " + result
            );
        }
        else
        {
            string value;
            int base = 0;

            if (choice == 4 || choice == 7 || choice == 8)
                base = 2;
            else if (choice == 5)
                base = 8;
            else if (choice == 6)
                base = 16;

            cout << "Enter number: ";
            cin >> value;

            if (!isValidForBase(value, base))
            {
                cout << "\n[ERROR] Invalid number for base "
                     << base << ".\n";
                return;
            }

            unsigned long long decimal = baseToDecimal(value, base);

            if (choice == 4 || choice == 5 || choice == 6)
            {
                cout << "\nDecimal = " << decimal << '\n';

                setPreviousAnswer(static_cast<double>(decimal));
                addToHistory(
                    "Base " + to_string(base) + " " + value +
                    " = Decimal " + to_string(decimal)
                );
            }
            else
            {
                int targetBase = (choice == 7) ? 8 : 16;
                string result = decimalToBase(decimal, targetBase);

                cout << "\nResult = " << result << '\n';

                setPreviousAnswer(static_cast<double>(decimal));
                addToHistory(
                    "Binary " + value +
                    " = Base " + to_string(targetBase) +
                    " " + result
                );
            }
        }
    }
    catch (const exception& error)
    {
        cout << "\n[ERROR] " << error.what() << '\n';
    }

    cout << "====================================================\n";
}


// ======================================================
// nCr / nPr CALCULATOR - OPTION 45
// ======================================================

long long factorialInteger(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

void combinationPermutationCalculator()
{
    int choice;

    cout << "\n====================================================\n";
    cout << "           COMBINATION & PERMUTATION\n";
    cout << "====================================================\n";
    cout << "1. Combination (nCr)\n";
    cout << "2. Permutation (nPr)\n";
    cout << "3. Back\n";
    cout << "====================================================\n";
    cout << "Enter your choice: ";

    while (!(cin >> choice) || choice < 1 || choice > 3)
    {
        cout << "[ERROR] Please enter 1-3: ";
        clearInput();
    }

    if (choice == 3)
        return;

    int n, r;

    cout << "\nEnter n (0-20): ";
    while (!(cin >> n) || n < 0 || n > 20)
    {
        cout << "[ERROR] Please enter an integer from 0 to 20: ";
        clearInput();
    }

    cout << "Enter r (0 <= r <= n): ";
    while (!(cin >> r) || r < 0 || r > n)
    {
        cout << "[ERROR] Please enter r between 0 and n: ";
        clearInput();
    }

    long long result;

    if (choice == 1)
    {
        result = factorialInteger(n) /
                 (factorialInteger(r) * factorialInteger(n - r));

        cout << "\nnCr = " << result << '\n';

        addToHistory(
            "nCr(" + to_string(n) + ", " + to_string(r) +
            ") = " + to_string(result)
        );
    }
    else
    {
        result = factorialInteger(n) /
                 factorialInteger(n - r);

        cout << "\nnPr = " << result << '\n';

        addToHistory(
            "nPr(" + to_string(n) + ", " + to_string(r) +
            ") = " + to_string(result)
        );
    }

    setPreviousAnswer(static_cast<double>(result));

    cout << "====================================================\n";
}


// ======================================================
// QUADRATIC EQUATION SOLVER - OPTION 46
// Solves: ax^2 + bx + c = 0
// ======================================================

void quadraticEquationSolver()
{
    cout << "\n====================================================\n";
    cout << "              QUADRATIC EQUATION SOLVER\n";
    cout << "====================================================\n";
    cout << "Equation format: ax^2 + bx + c = 0\n\n";

    double a = getNumber("Enter coefficient a: ");
    double b = getNumber("Enter coefficient b: ");
    double c = getNumber("Enter coefficient c: ");

    if (fabs(a) < 1e-15)
    {
        if (fabs(b) < 1e-15)
        {
            if (fabs(c) < 1e-15)
                cout << "\nResult: Infinite solutions (0 = 0).\n";
            else
                cout << "\nResult: No solution.\n";

            cout << "====================================================\n";
            return;
        }

        double x = -c / b;
        cout << "\nThis is a linear equation.\n";
        cout << "x = " << x << '\n';
        setPreviousAnswer(x);
        addToHistory("Linear equation: " + to_string(b) + "x + " +
                     to_string(c) + " = 0, x = " + to_string(x));
        cout << "====================================================\n";
        return;
    }

    double discriminant = b * b - 4.0 * a * c;

    cout << "\nDiscriminant (D) = " << discriminant << '\n';

    if (discriminant > 1e-15)
    {
        double sqrtD = sqrt(discriminant);
        double x1 = (-b + sqrtD) / (2.0 * a);
        double x2 = (-b - sqrtD) / (2.0 * a);

        cout << "Two real and distinct roots:\n";
        cout << "x1 = " << x1 << '\n';
        cout << "x2 = " << x2 << '\n';

        setPreviousAnswer(x1);
        addToHistory("Quadratic: " + to_string(a) + "x^2 + " +
                     to_string(b) + "x + " + to_string(c) +
                     " = 0 | x1 = " + to_string(x1) +
                     ", x2 = " + to_string(x2));
    }
    else if (fabs(discriminant) <= 1e-15)
    {
        double x = -b / (2.0 * a);

        cout << "One real repeated root:\n";
        cout << "x1 = x2 = " << x << '\n';

        setPreviousAnswer(x);
        addToHistory("Quadratic: " + to_string(a) + "x^2 + " +
                     to_string(b) + "x + " + to_string(c) +
                     " = 0 | repeated root = " + to_string(x));
    }
    else
    {
        double realPart = -b / (2.0 * a);
        double imaginaryPart = sqrt(-discriminant) / (2.0 * fabs(a));

        cout << "Two complex conjugate roots:\n";
        cout << "x1 = " << realPart << " + " << imaginaryPart << "i\n";
        cout << "x2 = " << realPart << " - " << imaginaryPart << "i\n";

        setPreviousAnswer(realPart);
        addToHistory("Quadratic: " + to_string(a) + "x^2 + " +
                     to_string(b) + "x + " + to_string(c) +
                     " = 0 | complex roots");
    }

    cout << "====================================================\n";
}


// ======================================================
// MATRIX CALCULATOR - OPTION 47
// Addition, Subtraction, Multiplication, Transpose
// ======================================================

void matrixCalculator()
{
    cout << "\n====================================================\n";
    cout << "                  MATRIX CALCULATOR\n";
    cout << "====================================================\n";
    cout << "1. Matrix Addition\n";
    cout << "2. Matrix Subtraction\n";
    cout << "3. Matrix Multiplication\n";
    cout << "4. Matrix Transpose\n";
    cout << "5. Back\n";
    cout << "====================================================\n";

    int operation;
    while (true)
    {
        cout << "Enter your choice: ";
        if (cin >> operation && operation >= 1 && operation <= 5)
            break;
        cout << "[ERROR] Please enter a choice between 1 and 5.\n";
        clearInput();
    }

    if (operation == 5)
        return;

    int rowsA, colsA;
    while (true)
    {
        cout << "Enter rows of Matrix A (1-10): ";
        if (cin >> rowsA && rowsA >= 1 && rowsA <= 10)
            break;
        cout << "[ERROR] Rows must be between 1 and 10.\n";
        clearInput();
    }

    while (true)
    {
        cout << "Enter columns of Matrix A (1-10): ";
        if (cin >> colsA && colsA >= 1 && colsA <= 10)
            break;
        cout << "[ERROR] Columns must be between 1 and 10.\n";
        clearInput();
    }

    vector<vector<double>> A(rowsA, vector<double>(colsA));
    cout << "\nEnter Matrix A elements:\n";
    for (int i = 0; i < rowsA; ++i)
    {
        for (int j = 0; j < colsA; ++j)
        {
            A[i][j] = getNumber("A[" + to_string(i + 1) + "][" + to_string(j + 1) + "] = ");
        }
    }

    if (operation == 4)
    {
        vector<vector<double>> result(colsA, vector<double>(rowsA));
        for (int i = 0; i < rowsA; ++i)
            for (int j = 0; j < colsA; ++j)
                result[j][i] = A[i][j];

        cout << "\nTranspose of Matrix A:\n";
        for (int i = 0; i < colsA; ++i)
        {
            for (int j = 0; j < rowsA; ++j)
                cout << setw(10) << result[i][j];
            cout << '\n';
        }

        if (!result.empty() && !result[0].empty())
            setPreviousAnswer(result[0][0]);
        addToHistory("Matrix transpose calculated");
        return;
    }

    int rowsB, colsB;
    while (true)
    {
        cout << "\nEnter rows of Matrix B (1-10): ";
        if (cin >> rowsB && rowsB >= 1 && rowsB <= 10)
            break;
        cout << "[ERROR] Rows must be between 1 and 10.\n";
        clearInput();
    }

    while (true)
    {
        cout << "Enter columns of Matrix B (1-10): ";
        if (cin >> colsB && colsB >= 1 && colsB <= 10)
            break;
        cout << "[ERROR] Columns must be between 1 and 10.\n";
        clearInput();
    }

    if ((operation == 1 || operation == 2) &&
        (rowsA != rowsB || colsA != colsB))
    {
        cout << "\n[ERROR] Addition/Subtraction requires matrices of the same size.\n";
        return;
    }

    if (operation == 3 && colsA != rowsB)
    {
        cout << "\n[ERROR] Multiplication requires columns of A = rows of B.\n";
        return;
    }

    vector<vector<double>> B(rowsB, vector<double>(colsB));
    cout << "\nEnter Matrix B elements:\n";
    for (int i = 0; i < rowsB; ++i)
    {
        for (int j = 0; j < colsB; ++j)
        {
            B[i][j] = getNumber("B[" + to_string(i + 1) + "][" + to_string(j + 1) + "] = ");
        }
    }

    if (operation == 1 || operation == 2)
    {
        vector<vector<double>> result(rowsA, vector<double>(colsA));
        for (int i = 0; i < rowsA; ++i)
            for (int j = 0; j < colsA; ++j)
                result[i][j] = (operation == 1) ? A[i][j] + B[i][j] : A[i][j] - B[i][j];

        cout << "\n" << (operation == 1 ? "Matrix Addition" : "Matrix Subtraction") << " Result:\n";
        for (int i = 0; i < rowsA; ++i)
        {
            for (int j = 0; j < colsA; ++j)
                cout << setw(10) << result[i][j];
            cout << '\n';
        }

        if (!result.empty() && !result[0].empty())
            setPreviousAnswer(result[0][0]);
        addToHistory(operation == 1 ? "Matrix addition calculated" : "Matrix subtraction calculated");
    }
    else
    {
        vector<vector<double>> result(rowsA, vector<double>(colsB, 0.0));
        for (int i = 0; i < rowsA; ++i)
            for (int j = 0; j < colsB; ++j)
                for (int k = 0; k < colsA; ++k)
                    result[i][j] += A[i][k] * B[k][j];

        cout << "\nMatrix Multiplication Result:\n";
        for (int i = 0; i < rowsA; ++i)
        {
            for (int j = 0; j < colsB; ++j)
                cout << setw(10) << result[i][j];
            cout << '\n';
        }

        if (!result.empty() && !result[0].empty())
            setPreviousAnswer(result[0][0]);
        addToHistory("Matrix multiplication calculated");
    }

    cout << "====================================================\n";
}


// ======================================================
// MATRIX DETERMINANT CALCULATOR - OPTION 48
// Supports 2x2 and 3x3 matrices
// ======================================================
void determinantCalculator()
{
    cout << "\n====================================================\n";
    cout << "             MATRIX DETERMINANT CALCULATOR\n";
    cout << "====================================================\n";

    int n;
    while (true)
    {
        cout << "Enter matrix size (2 or 3): ";
        if (cin >> n && (n == 2 || n == 3))
            break;

        cout << "[ERROR] Only 2x2 or 3x3 matrices are supported.\n";
        clearInput();
    }

    vector<vector<double>> A(n, vector<double>(n));

    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            A[i][j] = getNumber(
                "A[" + to_string(i + 1) + "][" + to_string(j + 1) + "] = "
            );
        }
    }

    double determinant = 0.0;

    if (n == 2)
    {
        determinant = A[0][0] * A[1][1]
                    - A[0][1] * A[1][0];
    }
    else
    {
        determinant =
            A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
          - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
          + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    }

    cout << "\n----------------------------------------------------\n";
    cout << "Determinant = " << determinant << '\n';
    cout << "----------------------------------------------------\n";

    setPreviousAnswer(determinant);
    addToHistory("Matrix determinant = " + to_string(determinant));

    cout << "====================================================\n";
}

// ======================================================
// PRIME NUMBER CHECKER - OPTION 49
// ======================================================
void primeNumberChecker()
{
    cout << "\n====================================================\n";
    cout << "                 PRIME NUMBER CHECKER\n";
    cout << "====================================================\n";

    long long n = getInteger("Enter an integer: " );

    if (n < 2)
    {
        cout << "\n" << n << " is NOT a prime number.\n";
        setPreviousAnswer(0);
        addToHistory(to_string(n) + " is not prime");
        cout << "====================================================\n";
        return;
    }

    bool isPrime = true;
    for (long long i = 2; i <= n / i; ++i)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    cout << "\n----------------------------------------------------\n";
    cout << n << (isPrime ? " is a PRIME number.\n" : " is NOT a prime number.\n");
    cout << "----------------------------------------------------\n";

    setPreviousAnswer(isPrime ? 1.0 : 0.0);
    addToHistory(to_string(n) + (isPrime ? " is prime" : " is not prime"));
    cout << "====================================================\n";
}

// ======================================================
// ARMSTRONG NUMBER CHECKER - OPTION 50
// ======================================================
void armstrongNumberChecker()
{
    cout << "\n====================================================\n";
    cout << "                ARMSTRONG NUMBER CHECKER\n";
    cout << "====================================================\n";

    long long n = getInteger("Enter a non-negative integer: ");

    if (n < 0)
    {
        cout << "\n[ERROR] Please enter a non-negative integer.\n";
        cout << "====================================================\n";
        return;
    }

    long long original = n;
    long long temp = n;
    int digits = (n == 0) ? 1 : static_cast<int>(to_string(n).length());
    long long sum = 0;

    while (temp > 0)
    {
        int digit = static_cast<int>(temp % 10);
        long long powerValue = 1;

        for (int i = 0; i < digits; ++i)
            powerValue *= digit;

        sum += powerValue;
        temp /= 10;
    }

    bool isArmstrong = (sum == original);

    cout << "\n----------------------------------------------------\n";
    cout << original << (isArmstrong
        ? " is an ARMSTRONG number.\n"
        : " is NOT an ARMSTRONG number.\n");
    cout << "----------------------------------------------------\n";

    setPreviousAnswer(isArmstrong ? 1.0 : 0.0);
    addToHistory(to_string(original) +
                 (isArmstrong ? " is Armstrong" : " is not Armstrong"));

    cout << "====================================================\n";
}

// ======================================================
// PALINDROME NUMBER CHECKER - OPTION 51
// ======================================================
void palindromeNumberChecker()
{
    cout << "\n====================================================\n";
    cout << "                PALINDROME NUMBER CHECKER\n";
    cout << "====================================================\n";

    long long n = getInteger("Enter a non-negative integer: ");

    if (n < 0)
    {
        cout << "\n[ERROR] Please enter a non-negative integer.\n";
        cout << "====================================================\n";
        return;
    }

    long long original = n;
    long long temp = n;
    long long reversed = 0;

    while (temp > 0)
    {
        int digit = static_cast<int>(temp % 10);
        reversed = reversed * 10 + digit;
        temp /= 10;
    }

    bool isPalindrome = (original == reversed);

    cout << "\n----------------------------------------------------\n";
    cout << original << (isPalindrome
        ? " is a PALINDROME number.\n"
        : " is NOT a PALINDROME number.\n");
    cout << "----------------------------------------------------\n";

    setPreviousAnswer(isPalindrome ? 1.0 : 0.0);
    addToHistory(to_string(original) +
                 (isPalindrome ? " is palindrome" : " is not palindrome"));

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
    cout << "35. Statistics Calculator\n";
    cout << "36. Speed of Light (c)\n";
    cout << "37. Gravitational Constant (G)\n";
    cout << "38. Planck Constant (h)\n";
    cout << "39. Avogadro Constant (NA)\n";
    cout << "40. Electron Charge (e)\n";
    cout << "41. GCD & LCM Calculator\n";
    cout << "42. Binary <-> Decimal Converter\n";
    cout << "43. Unit Converter\n";
    cout << "44. Number System Converter\n";
    cout << "45. Combinations & Permutations (nCr / nPr)\n";
    cout << "46. Quadratic Equation Solver\n";
    cout << "47. Matrix Calculator\n";
    cout << "48. Determinant Calculator\n";
    cout << "49. Prime Number Checker\n";
    cout << "50. Armstrong Number Checker\n";
    cout << "51. Palindrome Number Checker\n";

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
            case 35: statisticsCalculator(); break;
            case 36: speedOfLight(); break;
            case 37: gravitationalConstant(); break;
            case 38: planckConstant(); break;
            case 39: avogadroConstant(); break;
            case 40: electronCharge(); break;
            case 41: gcdLcmCalculator(); break;
            case 42: binaryDecimalConverter(); break;
            case 43: unitConverter(); break;
            case 44: numberSystemConverter(); break;
            case 45: combinationPermutationCalculator(); break;
            case 46: quadraticEquationSolver(); break;
            case 47: matrixCalculator(); break;
            case 48: determinantCalculator(); break;
            case 49: primeNumberChecker(); break;
            case 50: armstrongNumberChecker(); break;
            case 51: palindromeNumberChecker(); break;

            default:
                cout << "\n[ERROR] Invalid choice. Please enter 1-51.\n";
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
