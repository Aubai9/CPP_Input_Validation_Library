#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class clsDate
{
private:
    short _day = 1;
    short _month = 1;
    short _year = 1900;

public:
    clsDate();
    clsDate(string dateString);
    clsDate(short day, short month, short year);
    clsDate(short year, short allDays);

    void setCurrentDate();
    void print();

    static bool check_If_Leap_Year(short year);
    static int Calc_Days_In_Month(short month, short year);
    int Calc_Days_In_Month();
    static bool Is_Valid_Date(clsDate date);

    short Zeller_Algorithm(short day, short month, short year);
    void Print_Month_Calendar(short month, short year);
    void Print_Month_Calendar();
    void Print_Year_Calendar(short year);
    void Print_Year_Calendar();

    bool Is_Last_Day_In_Month();
    bool Is_Last_Month_In_Year();
    void AddOneDay();
    void Add_Days_To_Date(short day, short month, short year);

    static bool Is_Date1_Before_Date2(clsDate Date1, clsDate Date2);
    static bool Is_Date1_Equal_Date2(clsDate Date1, clsDate Date2);
    static bool Is_Date1_After_Date2(clsDate Date1, clsDate Date2);
    static int Get_Difference_In_Days(clsDate Date1, clsDate Date2, bool IncludeLastDay = false);
    static int Calculate_Age_In_Days(clsDate BirthDate);
};

#endif
