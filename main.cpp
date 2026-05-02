#include <iostream>
#include "clsInputValidation.h"
#include "clsDate.h"

using namespace std;

int main()
{
    cout << clsInputValidation::IsNumberBetween(5,  1, 10)   << endl;
    cout << clsInputValidation::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidation::IsDateBetween(clsDate(),clsDate(8,12,2027), clsDate(21,12,2028)) << endl;
    cout << clsInputValidation::IsDateBetween(clsDate(),clsDate(8,12,2025), clsDate(21,12,2028)) << endl;

    cout << "please enter a number:\n";
    int x = clsInputValidation::ReadIntNumber("Invalid Number,please enter the number again");
    cout << "x= " << x << endl;

    cout << "please enter a number between 1 and 5:\n";
    int y = clsInputValidation::ReadIntNumberBetween(1,5,"Invalid Number,please enter the number again");
    cout << "y= " << y << endl;

    cout << "please enter a double number:\n";
    int a= clsInputValidation::ReadDbNumber("Invalid Number,please enter the number again");
    cout << "a= " << a << endl;

    cout << "please enter a double number between 1 and 5:\n";
    int b = clsInputValidation::ReadDbNumberBetween(1,5,"Invalid Number,please enter the number again");
    cout << "b= " << b << endl;


    cout << clsInputValidation::Is_Valid_Date(clsDate(1,2,2025)) << endl;

    return 0;
}
