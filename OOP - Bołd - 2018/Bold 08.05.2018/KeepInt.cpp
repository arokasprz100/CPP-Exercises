#include "KeepInt.h"
#include "DoUndo.h"

void KeepInt::Restore() 
{
	m_intToKeep = m_startingValue;
}


KeepInt::~KeepInt()
{
	if (!DoUndo::IsOk())
		Restore();
}