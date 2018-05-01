#ifndef Executor_h
#define Executor_h

#include <string>
#include <iostream>

namespace Executor
{

	class Function
	{
	public:
		virtual double operator() (double x) const = 0;
	};

	class Result
	{
	public:
		bool valid;
		double value;
		std::string errorMessage;

		operator double() const;

	};

	std::ostream& operator<< (std::ostream& stream, const Result& printed);

	Result secureRun (const Function& fun, double x);

};


#endif