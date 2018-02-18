#ifndef Date_h
#define Date_h

class Date
{
public:
    friend class Period;
    Date();
    Date(int newYear, int newMonth, int newDay);
    void print() const;
    void shiftDays(int numberOfDays);
private:
    int year;
    int month;
    int day;

};

#endif // Date_h
