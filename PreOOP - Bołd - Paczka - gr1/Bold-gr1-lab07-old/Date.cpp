#include "Date.h"
#include <iostream>

Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
}

Date::Date (int newYear, int newMonth, int newDay)
{
    year = newYear;
    month = newMonth;
    day = newDay;
}

void Date::print() const
{
    std::cout<<year<<"."<<month<<"."<<day<<" ";
}

void Date::shiftDays(int numberOfDays)
{
    if (numberOfDays>=0)
    {
        for (int i=0; i<numberOfDays; i++)
        {
            day++;
            if ((month==11 && day>30) || (month==12 && day>31))
            {
                day=1;
                month++;
                if (month>12)
                {
                    month=1;
                    year++;
                }
            }
        }

    }
    else
    {
        for (int i=0; i<-numberOfDays; i++)
        {
            day--;
            if (day<1)
            {
                day=30;
                month--;
                if (month<1)
                {
                    month=12;
                    year--;
                }
            }
        }
    }

}
