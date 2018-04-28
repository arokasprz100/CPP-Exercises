#ifndef FitResult_h
#define FitResult_h

#include <string>

class FitResult
{
public:
	FitResult(std::string expression, unsigned nParams, double* paramVals);

	std::string expression() const;

	char parameterName(int index) const;

	double parameterValue(int index) const;

	unsigned nParams() const;

	~FitResult();


private:
	std::string m_expression;
	unsigned m_numberOfParams;
	char* m_paramNames;
	double * m_paramVals;

};

#endif