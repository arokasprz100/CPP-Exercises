#ifndef Period_h
#define Period_h

#include "Date.h"

class Period
{
public:
    Period(Date start, Date end);
    const Date& end() const;
    bool contains (const Date& isContained) const;
    void print() const;
    bool overlapsWith(const Period& checked) const;
    void shiftDays (int numberOfDays);
    Date& begin();
    Date& end();
private:
    Date startOfPeriod;
    Date endOfPeriod;
};

#endif // Period_h
