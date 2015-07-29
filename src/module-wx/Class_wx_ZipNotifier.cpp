//----------------------------------------------------------------------------
// wxZipNotifier
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZipNotifier: public wxZipNotifier, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ZipNotifier *_pObj;
public:
	~wx_ZipNotifier();
	inline void AssocWithGura(Object_wx_ZipNotifier *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZipNotifier::~wx_ZipNotifier()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ZipNotifier::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZipNotifier
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ZipNotifier, OnEntryUpdated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_ZipEntry, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipNotifier, OnEntryUpdated)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipNotifier *pThis = Object_wx_ZipNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxZipEntry *entry = Object_wx_ZipEntry::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnEntryUpdated(*entry);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxZipNotifier
//----------------------------------------------------------------------------
Object_wx_ZipNotifier::~Object_wx_ZipNotifier()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ZipNotifier::Clone() const
{
	return nullptr;
}

String Object_wx_ZipNotifier::ToString(bool exprFlag)
{
	String rtn("<wx.ZipNotifier:");
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
// Class implementation for wxZipNotifier
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipNotifier)
{
	Gura_AssignMethod(wx_ZipNotifier, OnEntryUpdated);
}

Gura_ImplementDescendantCreator(wx_ZipNotifier)
{
	return new Object_wx_ZipNotifier((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
