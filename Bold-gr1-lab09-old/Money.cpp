#include "Money.h"

int _10 = 10;
int _100 = 100;
int _1000 = 1000;

Money::Money(int value)
{
    if (value>=0)
    {
        m_value=value;
        m_currencyType = "USD";
    }
    else
    {
        m_value = -value;
        m_currencyType = "PLN";
    }
}


int Money::operator -= (int accuracy) const
{
    int temp = m_value;
    temp/=accuracy;
    temp*=accuracy;

    return temp;
}

int Money::operator += (int accuracy) const
{
    int temp = m_value;
    temp/=accuracy;
    temp*=accuracy;
    temp+=accuracy;

    return temp;
}

std::string Money::getType() const
{
    return m_currencyType;
}


int Currency::USD = 1;
int Currency::PLN = -1;

std::string Currency::type (const Money& checked)
{
    return checked.getType();
}
