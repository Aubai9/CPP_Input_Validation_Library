#ifndef CLSINPUTVALIDATION_H
#define CLSINPUTVALIDATION_H
#include "clsDate.h"
#include <string>

class clsInputValidation
{

public:

    static bool   IsNumberBetween(int n1, int n2, int n3);
    static bool   IsNumberBetween(double n1, double n2, double n3);
    static bool   Is_Valid_Date(clsDate Date);
    static bool   IsDateBetween(clsDate date1, clsDate date2, clsDate date3);
    static int    ReadIntNumber(string msg);
    static int    ReadIntNumberBetween(int n1, int n2, string msg);
    static double ReadDbNumber(string msg);
    static double ReadDbNumberBetween(double n1, double n2, string msg);
};

#endif
