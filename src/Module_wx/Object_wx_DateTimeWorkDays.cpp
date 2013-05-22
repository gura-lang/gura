//----------------------------------------------------------------------------
// wxDateTimeWorkDays
// extracted from datetime.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DateTimeWorkDays: public wxDateTimeWorkDays, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DateTimeWorkDays *_pObj;
public:
	~wx_DateTimeWorkDays();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DateTimeWorkDays *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DateTimeWorkDays::~wx_DateTimeWorkDays()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DateTimeWorkDays::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDateTimeWorkDays
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateTimeWorkDays
//----------------------------------------------------------------------------
Object_wx_DateTimeWorkDays::~Object_wx_DateTimeWorkDays()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DateTimeWorkDays::Clone() const
{
	return NULL;
}

String Object_wx_DateTimeWorkDays::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DateTimeWorkDays:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DateTimeWorkDays::DoAssignConstructor(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxDateTimeWorkDays
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateTimeWorkDays)
{
}

Gura_ImplementDescendantCreator(wx_DateTimeWorkDays)
{
	return new Object_wx_DateTimeWorkDays((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
