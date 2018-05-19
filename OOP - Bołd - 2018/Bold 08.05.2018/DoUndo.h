#ifndef DoUndo_h
#define DoUndo_h

#include "KeepInt.h"

class DoUndoAction
{
public:
	virtual void dodo() = 0;
	virtual void undoOk() = 0;
	virtual void undoFail() = 0;
	virtual ~DoUndoAction() {}
};


class DoUndo
{
public:
	DoUndo(DoUndoAction* msg);

	DoUndo(KeepInt* keep) : m_msg(nullptr), m_intKeeper(keep) {}

	~DoUndo();

	static bool IsOk() { return m_isOk; }

	static void allok() { m_isOk = true; }

private:
	static bool m_isOk;
	DoUndoAction* m_msg;
	KeepInt* m_intKeeper;

};



#endif