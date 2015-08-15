//----------------------------------------------------------------------------
// wxCriticalSection
// extracted from critsect.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CriticalSection: public wxCriticalSection, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_CriticalSection *_pObj;
public:
	inline wx_CriticalSection() : wxCriticalSection(), _pObj(nullptr) {}
	~wx_CriticalSection();
	inline void AssocWithGura(Object_wx_CriticalSection *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CriticalSection::~wx_CriticalSection()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CriticalSection::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCriticalSection
//----------------------------------------------------------------------------
Gura_DeclareFunction(CriticalSectionEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CriticalSection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CriticalSectionEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_CriticalSection *pEntity = new wx_CriticalSection();
	Object_wx_CriticalSection *pObj = Object_wx_CriticalSection::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_CriticalSection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_CriticalSection, Enter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CriticalSection, Enter)
{
	Signal &sig = env.GetSignal();
	Object_wx_CriticalSection *pThis = Object_wx_CriticalSection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Enter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CriticalSection, Leave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CriticalSection, Leave)
{
	Signal &sig = env.GetSignal();
	Object_wx_CriticalSection *pThis = Object_wx_CriticalSection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Leave();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxCriticalSection
//----------------------------------------------------------------------------
Object_wx_CriticalSection::~Object_wx_CriticalSection()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_CriticalSection::Clone() const
{
	return nullptr;
}

String Object_wx_CriticalSection::ToString(bool exprFlag)
{
	String rtn("<wx.CriticalSection:");
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
// Class implementation for wxCriticalSection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CriticalSection)
{
	Gura_AssignFunction(CriticalSectionEmpty);
	Gura_AssignMethod(wx_CriticalSection, Enter);
	Gura_AssignMethod(wx_CriticalSection, Leave);
}

Gura_ImplementDescendantCreator(wx_CriticalSection)
{
	return new Object_wx_CriticalSection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
