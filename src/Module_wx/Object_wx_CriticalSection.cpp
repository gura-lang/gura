//----------------------------------------------------------------------------
// wxCriticalSection
// extracted from critsect.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CriticalSection: public wxCriticalSection, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CriticalSection *_pObj;
public:
	inline wx_CriticalSection() : wxCriticalSection(), _sig(NULL), _pObj(NULL) {}
	~wx_CriticalSection();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CriticalSection *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CriticalSection::~wx_CriticalSection()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CriticalSection::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCriticalSection
//----------------------------------------------------------------------------
Gura_DeclareFunction(CriticalSectionEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CriticalSection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CriticalSectionEmpty)
{
	wx_CriticalSection *pEntity = new wx_CriticalSection();
	Object_wx_CriticalSection *pObj = Object_wx_CriticalSection::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CriticalSection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_CriticalSection, Enter)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CriticalSection, Enter)
{
	Object_wx_CriticalSection *pSelf = Object_wx_CriticalSection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Enter();
	return Value::Null;
}

Gura_DeclareMethod(wx_CriticalSection, Leave)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CriticalSection, Leave)
{
	Object_wx_CriticalSection *pSelf = Object_wx_CriticalSection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Leave();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxCriticalSection
//----------------------------------------------------------------------------
Object_wx_CriticalSection::~Object_wx_CriticalSection()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_CriticalSection::Clone() const
{
	return NULL;
}

String Object_wx_CriticalSection::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.CriticalSection:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_CriticalSection::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(CriticalSectionEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxCriticalSection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CriticalSection)
{
	Gura_AssignMethod(wx_CriticalSection, Enter);
	Gura_AssignMethod(wx_CriticalSection, Leave);
}

Gura_ImplementDescendantCreator(wx_CriticalSection)
{
	return new Object_wx_CriticalSection((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
