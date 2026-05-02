#include "clsDate.h"
#include <cstdio>

clsDate::clsDate()
{
    setCurrentDate();
}

clsDate::clsDate(string dateString)
{
    int d, m, y;
    sscanf(dateString.c_str(), "%d/%d/%d", &d, &m, &y);
    _day = (short)d;
    _month = (short)m;
    _year = (short)y;
}

clsDate::clsDate(short day, short month, short year)
{
    _day = day;
    _month = month;
    _year = year;
}

clsDate::clsDate(short year, short allDays)
{
    _year = year;
    _month = 1;
    while (allDays > Calc_Days_In_Month(_month, _year))
    {
        allDays -= Calc_Days_In_Month(_month, _year);
        _month++;
    }
    _day = allDays;
}

void clsDate::setCurrentDate()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    _day = ltm->tm_mday;
    _month = ltm->tm_mon + 1;
    _year = ltm->tm_year + 1900;
}

void clsDate::print()
{
    cout << _day << "/" << _month << "/" << _year << endl;
}

bool clsDate::check_If_Leap_Year(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int clsDate::Calc_Days_In_Month(short month, short year)
{
    if (month < 1 || month > 12) return 0;
    static short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2 && check_If_Leap_Year(year)) ? 29 : NumberOfDays[month - 1];
}

int clsDate::Calc_Days_In_Month()
{
    return Calc_Days_In_Month(_month, _year);
}

bool clsDate::Is_Valid_Date(clsDate date)
{
    if (date._month < 1 || date._month > 12) return false;
    if (date._day < 1 || date._day > Calc_Days_In_Month(date._month, date._year)) return false;
    if (date._year <= 0) return false;
    return true;
}

short clsDate::Zeller_Algorithm(short d, short m, short y)
{
    if (m == 1 || m == 2)
    {
        m += 12;
        y -= 1;
    }
    int k = y % 100;
    int j = y / 100;
    int h = (d + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) - 2 * j) % 7;
    if (h < 0) h += 7;
    return (h + 6) % 7;
}

void clsDate::Print_Month_Calendar(short Month, short Year)
{
    int NumberOfDays = Calc_Days_In_Month(Month, Year);
    int current = Zeller_Algorithm(1, Month, Year);
    printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int i;
    for (i = 0; i < current; i++) printf("     ");
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n-----------------------------------\n");
}

void clsDate::Print_Month_Calendar()
{
    Print_Month_Calendar(_month, _year);
}

void clsDate::Print_Year_Calendar(short year)
{
    for (short month = 1; month <= 12; month++)
    {
        printf("\n------- %d -------", month);
        Print_Month_Calendar(month, year);
    }
}

void clsDate::Print_Year_Calendar()
{
    Print_Year_Calendar(_year);
}

bool clsDate::Is_Last_Day_In_Month()
{
    return (_day == Calc_Days_In_Month(_month, _year));
}

bool clsDate::Is_Last_Month_In_Year()
{
    return (_month == 12);
}

void clsDate::AddOneDay()
{
    if (Is_Last_Day_In_Month())
    {
        if (Is_Last_Month_In_Year())
        {
            _month = 1;
            _day = 1;
            _year++;
        }
        else
        {
            _day = 1;
            _month++;
        }
    }
    else
    {
        _day++;
    }
}

void clsDate::Add_Days_To_Date(short day, short month, short year)
{
    _day = day;
    _month = month;
    _year = year;
    short daysToAdd;
    cout << "Enter number of days you want to add: ";
    cin >> daysToAdd;
    for (short i = 1; i <= daysToAdd; i++)
    {
        AddOneDay();
    }
    cout << "\nNew Date is: ";
    print();
}

bool clsDate::Is_Date1_Before_Date2(clsDate Date1, clsDate Date2)
{
    return (Date1._year < Date2._year) ? true : ((Date1._year == Date2._year) ? (Date1._month < Date2._month ? true : (Date1._month == Date2._month ? Date1._day < Date2._day : false)) : false);
}

bool clsDate::Is_Date1_Equal_Date2(clsDate Date1, clsDate Date2)
{
    return (Date1._year == Date2._year && Date1._month == Date2._month && Date1._day == Date2._day);
}

bool clsDate::Is_Date1_After_Date2(clsDate Date1, clsDate Date2)
{
    return !Is_Date1_Before_Date2(Date1, Date2) && !Is_Date1_Equal_Date2(Date1, Date2);
}

int clsDate::Get_Difference_In_Days(clsDate Date1, clsDate Date2, bool IncludeLastDay)
{
    int Days = 0;
    while (Is_Date1_Before_Date2(Date1, Date2))
    {
        Days++;
        Date1.AddOneDay();
    }
    return IncludeLastDay ? ++Days : Days;
}

int clsDate::Calculate_Age_In_Days(clsDate BirthDate)
{
    clsDate SystemDate;
    return Get_Difference_In_Days(BirthDate, SystemDate, true);
}
