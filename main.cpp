#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int choice;

    // Store calculation history
    vector<string> history;

    do
    {
        // Header
        cout << "\n\n";
        cout << "============================================" << endl;
        cout << "              CALCNOVA" << endl;
        cout << "        SCIENTIFIC CALCULATOR" << endl;
        cout << "============================================" << endl;

        // Basic Operations
        cout << "\n[ BASIC OPERATIONS ]" << endl;
        cout << "1.  Addition" << endl;
        cout << "2.  Subtraction" << endl;
        cout << "3.  Multiplication" << endl;
        cout << "4.  Division" << endl;
        cout << "5.  Modulus" << endl;

        // Scientific Operations
        cout << "\n[ SCIENTIFIC OPERATIONS ]" << endl;
        cout << "6.  Power" << endl;
        cout << "7.  Square Root" << endl;
        cout << "8.  Natural Log" << endl;
        cout << "9.  Log Base 10" << endl;

        // Trigonometry
        cout << "\n[ TRIGONOMETRY ]" << endl;
        cout << "10. Sin" << endl;
        cout << "11. Cos" << endl;
        cout << "12. Tan" << endl;

        // History
        cout << "\n[ HISTORY ]" << endl;
        cout << "13. View History" << endl;
        cout << "14. Clear History" << endl;

        // Exit
        cout << "\n15. Exit" << endl;

        cout << "\n--------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Invalid input handling
        if (cin.fail())
        {
            cout << "\nError: Please enter a number between 1 and 15.";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch(choice)
        {
            // ==========================================
            // 1. ADDITION
            // ==========================================
            case 1:
            {
                double a, b, result;

                cout << "\nEnter first number: ";
                cin >> a;

                cout << "Enter second number: ";
                cin >> b;

                result = a + b;

                cout << "\nResult = " << result << endl;

                history.push_back(
                    to_string(a) + " + " +
                    to_string(b) + " = " +
                    to_string(result)
                );

                break;
            }

            // ==========================================
            // 2. SUBTRACTION
            // ==========================================
            case 2:
            {
                double a, b, result;

                cout << "\nEnter first number: ";
                cin >> a;

                cout << "Enter second number: ";
                cin >> b;

                result = a - b;

                cout << "\nResult = " << result << endl;

                history.push_back(
                    to_string(a) + " - " +
                    to_string(b) + " = " +
                    to_string(result)
                );

                break;
            }

            // ==========================================
            // 3. MULTIPLICATION
            // ==========================================
            case 3:
            {
                double a, b, result;

                cout << "\nEnter first number: ";
                cin >> a;

                cout << "Enter second number: ";
                cin >> b;

                result = a * b;

                cout << "\nResult = " << result << endl;

                history.push_back(
                    to_string(a) + " * " +
                    to_string(b) + " = " +
                    to_string(result)
                );

                break;
            }

            // ==========================================
            // 4. DIVISION
            // ==========================================
            case 4:
            {
                double a, b, result;

                cout << "\nEnter first number: ";
                cin >> a;

                cout << "Enter second number: ";
                cin >> b;

                if (b == 0)
                {
                    cout << "\nError: Cannot divide by zero!" << endl;
                }
                else
                {
                    result = a / b;

                    cout << "\nResult = " << result << endl;

                    history.push_back(
                        to_string(a) + " / " +
                        to_string(b) + " = " +
                        to_string(result)
                    );
                }

                break;
            }

            // ==========================================
            // 5. MODULUS
            // ==========================================
            case 5:
            {
                int a, b, result;

                cout << "\nEnter first integer: ";
                cin >> a;

                cout << "Enter second integer: ";
                cin >> b;

                if (b == 0)
                {
                    cout << "\nError: Cannot find modulus with zero!" << endl;
                }
                else
                {
                    result = a % b;

                    cout << "\nResult = " << result << endl;

                    history.push_back(
                        to_string(a) + " % " +
                        to_string(b) + " = " +
                        to_string(result)
                    );
                }

                break;
            }

            // ==========================================
            // 6. POWER
            // ==========================================
            case 6:
            {
                double base, exponent, result;

                cout << "\nEnter base: ";
                cin >> base;

                cout << "Enter exponent: ";
                cin >> exponent;

                result = pow(base, exponent);

                cout << "\nResult = " << result << endl;

                history.push_back(
                    "pow(" +
                    to_string(base) + ", " +
                    to_string(exponent) + ") = " +
                    to_string(result)
                );

                break;
            }

            // ==========================================
            // 7. SQUARE ROOT
            // ==========================================
            case 7:
            {
                double number, result;

                cout << "\nEnter a number: ";
                cin >> number;

                if (number < 0)
                {
                    cout << "\nError: Square root of a negative number is not valid!" << endl;
                }
                else
                {
                    result = sqrt(number);

                    cout << "\nResult = " << result << endl;

                    history.push_back(
                        "sqrt(" +
                        to_string(number) +
                        ") = " +
                        to_string(result)
                    );
                }

                break;
            }

            // ==========================================
            // 8. NATURAL LOG
            // ==========================================
            case 8:
            {
                double number, result;

                cout << "\nEnter a positive number: ";
                cin >> number;

                if (number <= 0)
                {
                    cout << "\nError: Log is defined only for positive numbers!" << endl;
                }
                else
                {
                    result = log(number);

                    cout << "\nResult = " << result << endl;

                    history.push_back(
                        "log(" +
                        to_string(number) +
                        ") = " +
                        to_string(result)
                    );
                }

                break;
            }

            // ==========================================
            // 9. LOG BASE 10
            // ==========================================
            case 9:
            {
                double number, result;

                cout << "\nEnter a positive number: ";
                cin >> number;

                if (number <= 0)
                {
                    cout << "\nError: Log is defined only for positive numbers!" << endl;
                }
                else
                {
                    result = log10(number);

                    cout << "\nResult = " << result << endl;

                    history.push_back(
                        "log10(" +
                        to_string(number) +
                        ") = " +
                        to_string(result)
                    );
                }

                break;
            }

            // ==========================================
            // 10. SIN
            // ==========================================
            case 10:
            {
                double degree, radian, result;

                cout << "\nEnter angle in degrees: ";
                cin >> degree;

                radian = degree * acos(-1) / 180;
                result = sin(radian);

                cout << "\nResult = " << result << endl;

                history.push_back(
                    "sin(" +
                    to_string(degree) +
                    " deg) = " +
                    to_string(result)
                );

                break;
            }

            // ==========================================
            // 11. COS
            // ==========================================
            case 11:
            {
                double degree, radian, result;

                cout << "\nEnter angle in degrees: ";
                cin >> degree;

                radian = degree * acos(-1) / 180;
                result = cos(radian);

                cout << "\nResult = " << result << endl;

                history.push_back(
                    "cos(" +
                    to_string(degree) +
                    " deg) = " +
                    to_string(result)
                );

                break;
            }

            // ==========================================
            // 12. TAN
            // ==========================================
            case 12:
            {
                double degree, radian, result;

                cout << "\nEnter angle in degrees: ";
                cin >> degree;

                radian = degree * acos(-1) / 180;
                result = tan(radian);

                cout << "\nResult = " << result << endl;

                history.push_back(
                    "tan(" +
                    to_string(degree) +
                    " deg) = " +
                    to_string(result)
                );

                break;
            }

            // ==========================================
            // 13. VIEW HISTORY
            // ==========================================
            case 13:
            {
                cout << "\n============================================" << endl;
                cout << "          CALCULATION HISTORY" << endl;
                cout << "============================================" << endl;

                if (history.empty())
                {
                    cout << "No calculations yet." << endl;
                }
                else
                {
                    for (int i = 0; i < history.size(); i++)
                    {
                        cout << i + 1 << ". "
                             << history[i] << endl;
                    }
                }

                break;
            }

            // ==========================================
            // 14. CLEAR HISTORY
            // ==========================================
            case 14:
            {
                if (history.empty())
                {
                    cout << "\nHistory is already empty." << endl;
                }
                else
                {
                    history.clear();

                    cout << "\nHistory cleared successfully!" << endl;
                }

                break;
            }

            // ==========================================
            // 15. EXIT
            // ==========================================
            case 15:
            {
                cout << "\n============================================" << endl;
                cout << "       Thank you for using CalcNova!" << endl;
                cout << "============================================" << endl;

                break;
            }

            // ==========================================
            // INVALID CHOICE
            // ==========================================
            default:
            {
                cout << "\nError: Invalid choice!" << endl;
                cout << "Please select a number between 1 and 15." << endl;
            }
        }

    } while(choice != 15);

    return 0;
}