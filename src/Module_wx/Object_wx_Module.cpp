//----------------------------------------------------------------------------
// wxModule
// extracted from module.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(OnExit);
Gura_DeclarePrivUserSymbol(OnInit);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Module: public wxModule, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Module *_pObj;
public:
	//inline wx_Module() : wxModule(), _sig(NULL), _pObj(NULL) {}
	//virtual void OnExit();
	//virtual bool OnInit();
	~wx_Module();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Module *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Module::~wx_Module()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Module::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxModule
//----------------------------------------------------------------------------
Gura_DeclareFunction(ModuleEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Module));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ModuleEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_Module *pEntity = new wx_Module();
	Object_wx_Module *pObj = Object_wx_Module::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Module(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Module, AddDependency)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dep", VTYPE_wx_ClassInfo, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Module, AddDependency)
{
#if 0
	Object_wx_Module *pThis = Object_wx_Module::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxClassInfo *dep = Object_wx_ClassInfo::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddDependency(dep);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Module, OnExit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Module, OnExit)
{
	Object_wx_Module *pThis = Object_wx_Module::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnExit();
	return Value::Null;
}

Gura_DeclareMethod(wx_Module, OnInit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Module, OnInit)
{
	Object_wx_Module *pThis = Object_wx_Module::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->OnInit();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxModule
//----------------------------------------------------------------------------
Object_wx_Module::~Object_wx_Module()
{
}

Object *Object_wx_Module::Clone() const
{
	return NULL;
}

String Object_wx_Module::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Module:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Module::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(OnExit);
	Gura_RealizeUserSymbol(OnInit);
	Gura_AssignFunction(ModuleEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxModule
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Module)
{
	Gura_AssignMethod(wx_Module, AddDependency);
	Gura_AssignMethod(wx_Module, OnExit);
	Gura_AssignMethod(wx_Module, OnInit);
}

Gura_ImplementDescendantCreator(wx_Module)
{
	return new Object_wx_Module((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
