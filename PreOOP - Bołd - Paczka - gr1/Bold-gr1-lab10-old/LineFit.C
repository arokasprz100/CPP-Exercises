#include "LineFit.h"

LineFit::LineFit()
{
	sumXY = 0.0;
	sumXX = 0.0;
	sumX = 0.0;
	sumY = 0.0;
	N = 0;
}

void LineFit::appendPoint(double x, double y)
{
	sumXX+=x*x;
	sumXY+=x*y;
	sumX+=x;
	sumY+=y;
	N++;
}

FitResult LineFit::result()
{
	double a = (sumXY - sumX*sumY/N)/(sumXX-sumX*sumX/N);
	double b = (sumY - a*sumX)/N; 
	double* params = new double[2];
	params[0] = a;
	params[1] = b;
	return FitResult("y = a * x + b", 2, params);
}