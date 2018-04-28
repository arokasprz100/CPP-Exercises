#include "SlopeFit.h"

SlopeFit::SlopeFit()
{
	sumXY = 0.0;
	sumXX = 0.0;

}

void SlopeFit::appendPoint(double x, double y)
{
	sumXX+=x*x;
	sumXY+=x*y;
}

FitResult SlopeFit::result()
{
	double a = sumXY/sumXX;
	double* params = new double[1];
	params[0] = a;
	return FitResult("y = a * x", 1, params);
}