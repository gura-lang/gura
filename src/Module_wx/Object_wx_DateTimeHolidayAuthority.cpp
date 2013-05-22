//----------------------------------------------------------------------------
// wxDateTimeHolidayAuthority
// extracted from datetime.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DateTimeHolidayAuthority: public wxDateTimeHolidayAuthority, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DateTimeHolidayAuthority *_pObj;
public:
	~wx_DateTimeHolidayAuthority();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DateTimeHolidayAuthority *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DateTimeHolidayAuthority::~wx_DateTimeHolidayAuthority()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DateTimeHolidayAuthority::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------
Object_wx_DateTimeHolidayAuthority::~Object_wx_DateTimeHolidayAuthority()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DateTimeHolidayAuthority::Clone() const
{
	return NULL;
}

String Object_wx_DateTimeHolidayAuthority::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DateTimeHolidayAuthority:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateTimeHolidayAuthority)
{
}

Gura_ImplementDescendantCreator(wx_DateTimeHolidayAuthority)
{
	return new Object_wx_DateTimeHolidayAuthority((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
