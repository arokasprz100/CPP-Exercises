#include "Executor.h"


Executor::Result::operator double() const 
{
	if (valid)
		return value;
	else 
		throw "Error, could not convert. ";
}


std::ostream& Executor::operator<< (std::ostream& stream, const Executor::Result& printed)
{
	if (printed.valid)
		stream<<printed.value;
	else 
		stream<<printed.errorMessage;
	return stream;
}



Executor::Result Executor::secureRun (const Executor::Function& fun, double x)
{
	Result functionResult;

	try
	{
		functionResult.value = fun(x);
		functionResult.valid = true;
	}
	catch(bool error)
	{
		functionResult.valid = false;
		functionResult.errorMessage = "ERROR Boolean of value false thrown";
	}
	catch (const char * error)
	{
		functionResult.valid = false;
		functionResult.errorMessage = "ERROR " + std::string(error);
	}

	return functionResult;
}
