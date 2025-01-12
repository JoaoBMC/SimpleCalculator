#include <iostream>
#include <string>
#include "operations.h"

#define MAX_ARGS 4
#define OPERATION_TYPE_INDEX 1
#define NUMBER_01_INDEX 2
#define NUMBER_02_INDEX 3

using namespace std;

void printHelp(string fileName)
{
    cout << "\n=========================== HELP ===========================\n";
    cout << "USAGE:\n";
    cout << "\t" << fileName << " {OPERATION} {NUMBER 1} {NUMBER 2}\n\n";
    cout << "OPERATIONS:\n";
    cout << "\t-sm\tSummation Operation\n";
    cout << "\t-sb\tSubtraction Operation\n";
    cout << "\t-ml\tMultiplication Operation\n";
    cout << "\t-dv\tDivision Operation\n";
    cout << "\t-hp\tDisplay Help\n\n";
    cout << "EXAMPLES:\n";
    cout << "\t" << fileName << " -sm 10 5\t=> Output: 10 + 5 = 15\n";
    cout << "\t" << fileName << " -dv 10 0\t=> Output: Error: Division by zero\n";
    cout << "===========================================================\n";
}

// Valida se uma string é numérica
bool isNumber(const string &str)
{
    try
    {
        stod(str); // Tenta converter para double
        return true;
    }
    catch (...)
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    string auxfileName = argv[0];
    int fileName = auxfileName.find_last_of('\\') + 1;
    string newFileName = auxfileName.substr(fileName);

    if (argc != MAX_ARGS)
    {
        printHelp(newFileName);
    }
    else
    {
        string argOperation = argv[OPERATION_TYPE_INDEX];
        string strNum1 = argv[NUMBER_01_INDEX];
        string strNum2 = argv[NUMBER_02_INDEX];

        if (!isNumber(strNum1) || !isNumber(strNum2))
        {
            cerr << "Error: Arguments must be valid numbers.\n";
            return 1;
        }

        double number1 = stod(strNum1);
        double number2 = stod(strNum2);
        try
        {
            if (argOperation == "-sm")
            {
                cout << "Summation " << number1 << " + " << number2 << " = " << sum(number1, number2) << endl
                     << endl;
            }
            else if (argOperation == "-sb")
            {
                cout << "Subtraction " << number1 << " - " << number2 << " = " << sub(number1, number2) << endl
                     << endl;
            }
            else if (argOperation == "-ml")
            {
                cout << "Multiplication " << number1 << " * " << number2 << " = " << mult(number1, number2) << endl
                     << endl;
            }
            else if (argOperation == "-dv")
            {
                cout << "Division " << number1 << " / " << number2 << " = " << divi(number1, number2) << endl
                     << endl;
            }
            else
            {
                cerr << "Error: Invalid operation.\n";
                printHelp(newFileName);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    cout << "Pressione Enter para sair...";
    cin.get();
    return 0;
}
