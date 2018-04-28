#include "Period.h"
#include <iostream>

Period::Period(Date start, Date end)
{
    startOfPeriod = start;
    endOfPeriod = end;
}

const Date& Period::end() const
{
    return endOfPeriod;
}

bool Period::contains (const Date& isContained) const
{
    if (isContained.year * 10000 + isContained.month * 100 + isContained.day >= startOfPeriod.year * 10000 + startOfPeriod.month * 100 + startOfPeriod.day &&
        isContained.year * 10000 + isContained.month * 100 + isContained.day <= endOfPeriod.year * 10000 + endOfPeriod.month * 100 + endOfPeriod.day )
            return true;
    return false;

}

void Period::print() const
{
    startOfPeriod.print();
    std::cout<<"- ";
    endOfPeriod.print();
}


bool Period::overlapsWith(const Period& checked) const
{
    if (checked.contains(startOfPeriod) || checked.contains(endOfPeriod) || contains(checked.startOfPeriod) || contains(checked.endOfPeriod))
        return true;
    return false;
}

Date& Period::begin()
{
    return startOfPeriod;
}

Date& Period::end()
{
    return endOfPeriod;
}

void Period::shiftDays (int numberOfDays)
{
    endOfPeriod.shiftDays(numberOfDays);
    startOfPeriod.shiftDays(numberOfDays);
}
