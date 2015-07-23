//----------------------------------------------------------------------------
// wxModule
// extracted from module.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnExit);
Gura_DeclarePrivUserSymbol(OnInit);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Module: public wxModule, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_Module *_pObj;
public:
	//inline wx_Module() : wxModule(), _pSig(nullptr), _pObj(nullptr) {}
	//virtual void OnExit();
	//virtual bool OnInit();
	~wx_Module();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Module *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Module::~wx_Module()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Module::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxModule
//----------------------------------------------------------------------------
Gura_DeclareFunction(ModuleEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	if (pObj == nullptr) {
		pObj = new Object_wx_Module(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Module, AddDependency)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Module, OnInit)
{
	Object_wx_Module *pThis = Object_wx_Module::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->OnInit();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxModule
//----------------------------------------------------------------------------
Object_wx_Module::~Object_wx_Module()
{
}

Object *Object_wx_Module::Clone() const
{
	return nullptr;
}

String Object_wx_Module::ToString(bool exprFlag)
{
	String rtn("<wx.Module:");
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
// Class implementation for wxModule
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Module)
{
	Gura_RealizeUserSymbol(OnExit);
	Gura_RealizeUserSymbol(OnInit);
	Gura_AssignFunction(ModuleEmpty);
	Gura_AssignMethod(wx_Module, AddDependency);
	Gura_AssignMethod(wx_Module, OnExit);
	Gura_AssignMethod(wx_Module, OnInit);
}

Gura_ImplementDescendantCreator(wx_Module)
{
	return new Object_wx_Module((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
