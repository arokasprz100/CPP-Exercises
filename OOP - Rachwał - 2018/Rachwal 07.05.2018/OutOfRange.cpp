#include "OutOfRange.h"
#include "Number.h"

OutOfRange::~OutOfRange()
{
	Number::ClearFactory();
}

Number* OutOfRange::GetValue() const 
{
	return m_wrongValue;
}

std::ostream& operator<<(std::ostream& stream, const OutOfRange& printed)
{
	stream<<"Number named: "<<printed.GetValue()->m_name<<" has value "<<printed.GetValue()->m_value<<
			" which is outside of the allowed range: ["<<Number::m_lowRange<<", "<<Number::m_highRange<<"]";

	return stream;
}