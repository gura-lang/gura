//----------------------------------------------------------------------------
// wxList
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_List: public wxList, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_List *_pObj;
public:
	~wx_List();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_List *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_List::~wx_List()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_List::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxList
//----------------------------------------------------------------------------
Object_wx_List::~Object_wx_List()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_List::Clone() const
{
	return nullptr;
}

String Object_wx_List::ToString(bool exprFlag)
{
	String rtn("<wx.List:");
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
// Class implementation for wxList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_List)
{
}

Gura_ImplementDescendantCreator(wx_List)
{
	return new Object_wx_List((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
