#include "FitResult.h"

FitResult::FitResult(std::string expression, unsigned nParams, double* paramVals):
	m_expression(expression), m_numberOfParams(nParams), m_paramVals(paramVals)
{
	m_paramNames = new char[nParams];
	for (unsigned i =0; i<nParams; ++i)
		m_paramNames[i] = 'a' + i;
}


std::string FitResult::expression() const
{
	return m_expression;
}

char FitResult::parameterName(int index) const
{
	return m_paramNames[index];
}

double FitResult::parameterValue(int index) const
{
	return m_paramVals[index];
}

unsigned FitResult::nParams() const
{
	return m_numberOfParams;
}

FitResult::~FitResult()
{
	delete [] m_paramNames;
	delete [] m_paramVals;
}