#ifndef myerrors_h
#define myerrors_h

#include <string>
#include <stdexcept>
#include <iostream>

namespace myerrors
{
	class calc_error : public std::runtime_error
	{
	public:
		calc_error (const std::runtime_error * exception, const std::string& place, const std::string& file, unsigned line ) :
			std::runtime_error(place + " [w pliku: " + file + " w linii: " + std::to_string(line) + "]"), m_error(const_cast<std::runtime_error*>(exception)) {}

		std::runtime_error* m_error;
	};

	void handler();
}

#endif