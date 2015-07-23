//----------------------------------------------------------------------------
// wxCriticalSectionLocker
// extracted from crtslock.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CriticalSectionLocker: public wxCriticalSectionLocker, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_CriticalSectionLocker *_pObj;
public:
	inline wx_CriticalSectionLocker(wxCriticalSection& criticalsection) : wxCriticalSectionLocker(criticalsection), _pObj(nullptr) {}
	~wx_CriticalSectionLocker();
	inline void AssocWithGura(Object_wx_CriticalSectionLocker *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CriticalSectionLocker::~wx_CriticalSectionLocker()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CriticalSectionLocker::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Gura_DeclareFunction(CriticalSectionLocker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CriticalSectionLocker));
	DeclareArg(env, "criticalsection", VTYPE_wx_CriticalSection, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CriticalSectionLocker)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxCriticalSection *criticalsection = Object_wx_CriticalSection::GetObject(args, 0)->GetEntity();
	wx_CriticalSectionLocker *pEntity = new wx_CriticalSectionLocker(*criticalsection);
	Object_wx_CriticalSectionLocker *pObj = Object_wx_CriticalSectionLocker::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_CriticalSectionLocker(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Object_wx_CriticalSectionLocker::~Object_wx_CriticalSectionLocker()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_CriticalSectionLocker::Clone() const
{
	return nullptr;
}

String Object_wx_CriticalSectionLocker::ToString(bool exprFlag)
{
	String rtn("<wx.CriticalSectionLocker:");
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
// Class implementation for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CriticalSectionLocker)
{
	Gura_AssignFunction(CriticalSectionLocker);
}

Gura_ImplementDescendantCreator(wx_CriticalSectionLocker)
{
	return new Object_wx_CriticalSectionLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
