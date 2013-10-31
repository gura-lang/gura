//----------------------------------------------------------------------------
// wxPageSetupData
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PageSetupData: public wxPageSetupData, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PageSetupData *_pObj;
public:
	~wx_PageSetupData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PageSetupData *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PageSetupData::~wx_PageSetupData()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PageSetupData::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPageSetupData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPageSetupData
//----------------------------------------------------------------------------
Object_wx_PageSetupData::~Object_wx_PageSetupData()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_PageSetupData::Clone() const
{
	return NULL;
}

String Object_wx_PageSetupData::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PageSetupData:");
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
// Class implementation for wxPageSetupData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PageSetupData)
{
}

Gura_ImplementDescendantCreator(wx_PageSetupData)
{
	return new Object_wx_PageSetupData((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
