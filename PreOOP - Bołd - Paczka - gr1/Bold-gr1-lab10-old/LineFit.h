#ifndef LineFit_h
#define LineFit_h

#include "Fit.h"

class LineFit : public Fit 
{
public:
	LineFit();

	virtual void appendPoint(double x, double y);

	virtual FitResult result();

private:
	double sumX;
	double sumY;
	int N;

};

#endif