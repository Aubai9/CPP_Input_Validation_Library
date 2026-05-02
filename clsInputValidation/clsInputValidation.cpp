#include "clsInputValidation.h"

bool clsInputValidation::IsNumberBetween(int n1, int n2, int n3)
{
    return (n1 >= n2 && n1 <= n3);
}

bool clsInputValidation::IsNumberBetween(double n1, double n2, double n3)
{
    return (n1 >= n2 && n1 <= n3);
}

bool clsInputValidation::IsDateBetween(clsDate date1, clsDate date2, clsDate date3)
{

    if ((clsDate::Is_Date1_After_Date2(date1, date2) || clsDate::Is_Date1_Equal_Date2(date1, date2))
            &&
            (clsDate::Is_Date1_Before_Date2(date1, date3) || clsDate::Is_Date1_Equal_Date2(date1, date3)))
        return true;

    if ((clsDate::Is_Date1_After_Date2(date1, date3) || clsDate::Is_Date1_Equal_Date2(date1, date3))
            &&
            (clsDate::Is_Date1_Before_Date2(date1, date2) || clsDate::Is_Date1_Equal_Date2(date1, date2)))
        return true;

    return false;
}

int clsInputValidation::ReadIntNumber(string msg)
{
    int number;
    while (!(cin >> number))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << msg << endl;
        }
    return number;

}

int clsInputValidation::ReadIntNumberBetween(int n1, int n2, string msg)
{
    int number = ReadIntNumber(msg);

    while (number < n1 || number > n2)
        {
            cout << msg << endl;
            number = ReadIntNumber(msg);
        }

    return number;
}



double clsInputValidation::ReadDbNumber(string msg)
{
    double number;
    while (!(cin >> number))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << msg << endl;
        }
    return number;

}

double clsInputValidation::ReadDbNumberBetween(double n1, double n2, string msg)
{
    double number = ReadDbNumber(msg);

    while (number < n1 || number > n2)
        {
            cout << msg << endl;
            number = ReadDbNumber(msg);
        }

    return number;
}

bool clsInputValidation::Is_Valid_Date(clsDate Date)
{
    return clsDate::Is_Valid_Date(Date);
}

