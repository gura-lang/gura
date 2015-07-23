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
	//Gura::Signal *_pSig;
	Object_wx_PageSetupData *_pObj;
public:
	~wx_PageSetupData();
	inline void AssocWithGura(Object_wx_PageSetupData *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PageSetupData::~wx_PageSetupData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PageSetupData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPageSetupData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPageSetupData
//----------------------------------------------------------------------------
Object_wx_PageSetupData::~Object_wx_PageSetupData()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_PageSetupData::Clone() const
{
	return nullptr;
}

String Object_wx_PageSetupData::ToString(bool exprFlag)
{
	String rtn("<wx.PageSetupData:");
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
// Class implementation for wxPageSetupData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PageSetupData)
{
}

Gura_ImplementDescendantCreator(wx_PageSetupData)
{
	return new Object_wx_PageSetupData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
