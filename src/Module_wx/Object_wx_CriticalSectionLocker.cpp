//----------------------------------------------------------------------------
// wxCriticalSectionLocker
// extracted from crtslock.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CriticalSectionLocker: public wxCriticalSectionLocker, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CriticalSectionLocker *_pObj;
public:
	inline wx_CriticalSectionLocker(wxCriticalSection& criticalsection) : wxCriticalSectionLocker(criticalsection), _sig(NULL), _pObj(NULL) {}
	~wx_CriticalSectionLocker();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CriticalSectionLocker *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CriticalSectionLocker::~wx_CriticalSectionLocker()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CriticalSectionLocker::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Gura_DeclareFunction(CriticalSectionLocker)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CriticalSectionLocker));
	DeclareArg(env, "criticalsection", VTYPE_wx_CriticalSection, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CriticalSectionLocker)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxCriticalSection *criticalsection = Object_wx_CriticalSection::GetObject(args, 0)->GetEntity();
	wx_CriticalSectionLocker *pEntity = new wx_CriticalSectionLocker(*criticalsection);
	Object_wx_CriticalSectionLocker *pObj = Object_wx_CriticalSectionLocker::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CriticalSectionLocker(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Object_wx_CriticalSectionLocker::~Object_wx_CriticalSectionLocker()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_CriticalSectionLocker::Clone() const
{
	return NULL;
}

String Object_wx_CriticalSectionLocker::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.CriticalSectionLocker:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_CriticalSectionLocker::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(CriticalSectionLocker);
}

//----------------------------------------------------------------------------
// Class implementation for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CriticalSectionLocker)
{
}

Gura_ImplementDescendantCreator(wx_CriticalSectionLocker)
{
	return new Object_wx_CriticalSectionLocker((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
