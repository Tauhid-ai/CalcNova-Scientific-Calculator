#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    int choice;

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

        // Exit
        cout << "\n13. Exit" << endl;

        cout << "\n--------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Check invalid input
        if (cin.fail())
        {
            cout << "\nError: Please enter a number between 1 and 13.";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch(choice)
        {
            // Addition
            case 1:
            {
                double a, b;

                cout << "\nEnter first number: ";
                cin >> a;

                cout << "Enter second number: ";
                cin >> b;

                cout << "\nResult = " << a + b << endl;

                break;
            }

            // Subtraction
            case 2:
            {
                double a, b;

                cout << "\nEnter first number: ";
                cin >> a;

                cout << "Enter second number: ";
                cin >> b;

                cout << "\nResult = " << a - b << endl;

                break;
            }

            // Multiplication
            case 3:
            {
                double a, b;

                cout << "\nEnter first number: ";
                cin >> a;

                cout << "Enter second number: ";
                cin >> b;

                cout << "\nResult = " << a * b << endl;

                break;
            }

            // Division
            case 4:
            {
                double a, b;

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
                    cout << "\nResult = " << a / b << endl;
                }

                break;
            }

            // Modulus
            case 5:
            {
                int a, b;

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
                    cout << "\nResult = " << a % b << endl;
                }

                break;
            }

            // Power
            case 6:
            {
                double base, exponent;

                cout << "\nEnter base: ";
                cin >> base;

                cout << "Enter exponent: ";
                cin >> exponent;

                cout << "\nResult = " << pow(base, exponent) << endl;

                break;
            }

            // Square Root
            case 7:
            {
                double number;

                cout << "\nEnter a number: ";
                cin >> number;

                if (number < 0)
                {
                    cout << "\nError: Square root of a negative number is not valid!" << endl;
                }
                else
                {
                    cout << "\nResult = " << sqrt(number) << endl;
                }

                break;
            }

            // Natural Log
            case 8:
            {
                double number;

                cout << "\nEnter a positive number: ";
                cin >> number;

                if (number <= 0)
                {
                    cout << "\nError: Log is defined only for positive numbers!" << endl;
                }
                else
                {
                    cout << "\nResult = " << log(number) << endl;
                }

                break;
            }

            // Log Base 10
            case 9:
            {
                double number;

                cout << "\nEnter a positive number: ";
                cin >> number;

                if (number <= 0)
                {
                    cout << "\nError: Log is defined only for positive numbers!" << endl;
                }
                else
                {
                    cout << "\nResult = " << log10(number) << endl;
                }

                break;
            }

            // Sin
            case 10:
            {
                double degree;

                cout << "\nEnter angle in degrees: ";
                cin >> degree;

                double radian = degree * acos(-1) / 180;

                cout << "\nResult = " << sin(radian) << endl;

                break;
            }

            // Cos
            case 11:
            {
                double degree;

                cout << "\nEnter angle in degrees: ";
                cin >> degree;

                double radian = degree * acos(-1) / 180;

                cout << "\nResult = " << cos(radian) << endl;

                break;
            }

            // Tan
            case 12:
            {
                double degree;

                cout << "\nEnter angle in degrees: ";
                cin >> degree;

                double radian = degree * acos(-1) / 180;

                cout << "\nResult = " << tan(radian) << endl;

                break;
            }

            // Exit
            case 13:
            {
                cout << "\n============================================" << endl;
                cout << "       Thank you for using CalcNova!" << endl;
                cout << "============================================" << endl;

                break;
            }

            // Invalid Choice
            default:
            {
                cout << "\nError: Invalid choice!" << endl;
                cout << "Please select a number between 1 and 13." << endl;
            }
        }

    } while(choice != 13);

    return 0;
}