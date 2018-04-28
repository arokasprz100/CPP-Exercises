#ifndef SlopeFit_h
#define SlopeFit_h

#include "Fit.h"

class SlopeFit : public Fit 
{
public:
	SlopeFit();

	virtual void appendPoint(double x, double y);

	virtual FitResult result();

private:


};

#endif