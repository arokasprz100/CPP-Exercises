#ifndef Fit_h
#define Fit_h

#include "FitResult.h"

class Fit
{
public:
	virtual void appendPoint(double x, double y) = 0;

	virtual FitResult result() = 0;

protected:
	double sumXY;
	double sumXX;
};

#endif