//----------------------------------------------------------------------------
// wxDateTimeWorkDays
// extracted from datetime.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DateTimeWorkDays::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDateTimeWorkDays
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateTimeWorkDays
//----------------------------------------------------------------------------
Object_wx_DateTimeWorkDays::~Object_wx_DateTimeWorkDays()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DateTimeWorkDays::Clone() const
{
	return nullptr;
}

String Object_wx_DateTimeWorkDays::ToString(bool exprFlag)
{
	String rtn("<wx.DateTimeWorkDays:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxDateTimeWorkDays
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateTimeWorkDays)
{
}

Gura_ImplementDescendantCreator(wx_DateTimeWorkDays)
{
	return new Object_wx_DateTimeWorkDays((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
