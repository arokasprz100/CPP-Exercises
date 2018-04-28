#ifndef MONEY_H
#define MONEY_H

#include <string>

class Money
{
public:
    Money(int value);

    std::string getType() const;

    int operator -= (int accuracy) const;

    int operator += (int accuracy) const;

private:
    int m_value;
    std::string m_currencyType;

};

extern int _10;
extern int _100;
extern int _1000;

class Currency
{
public:
    static int USD;
    static int PLN;
    static std::string type (const Money& checked);

};

#endif // MONEY_H
