#include "DoUndo.h"

bool DoUndo::m_isOk = false;


DoUndo::DoUndo(DoUndoAction* msg) 
	: m_msg(msg), m_intKeeper(nullptr)
{
	m_msg->dodo();
	m_isOk = false;
}


DoUndo::~DoUndo()
{
	if (m_intKeeper)
	{
		delete m_intKeeper;
		return;
	}

	if (m_isOk)
		m_msg->undoOk();
	else
		m_msg->undoFail();

	delete m_msg;
}