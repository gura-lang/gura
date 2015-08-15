//----------------------------------------------------------------------------
// wxStackWalker
// extracted from stackwalker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StackWalker: public wxStackWalker, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StackWalker *_pObj;
public:
	//inline wx_StackWalker() : wxStackWalker(), _pObj(nullptr) {}
	~wx_StackWalker();
	inline void AssocWithGura(Object_wx_StackWalker *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StackWalker::~wx_StackWalker()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StackWalker::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStackWalker
//----------------------------------------------------------------------------
Gura_DeclareFunction(StackWalkerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_StackWalker));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(StackWalkerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_StackWalker *pEntity = new wx_StackWalker();
	Object_wx_StackWalker *pObj = Object_wx_StackWalker::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_StackWalker(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackWalker, OnStackFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "frame", VTYPE_wx_StackFrame, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_StackWalker, OnStackFrame)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxStackFrame *frame = Object_wx_StackFrame::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnStackFrame(*frame);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackWalker, Walk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "skip", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxDepth", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackWalker, Walk)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t skip = 1;
	if (args.IsValid(0)) skip = args.GetSizeT(0);
	size_t maxDepth = 200;
	if (args.IsValid(1)) maxDepth = args.GetSizeT(1);
	pThis->GetEntity()->Walk(skip, maxDepth);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StackWalker, WalkFromException)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackWalker, WalkFromException)
{
	Signal &sig = env.GetSignal();
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WalkFromException();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxStackWalker
//----------------------------------------------------------------------------
Object_wx_StackWalker::~Object_wx_StackWalker()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_StackWalker::Clone() const
{
	return nullptr;
}

String Object_wx_StackWalker::ToString(bool exprFlag)
{
	String rtn("<wx.StackWalker:");
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
// Class implementation for wxStackWalker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackWalker)
{
	Gura_AssignFunction(StackWalkerEmpty);
	Gura_AssignMethod(wx_StackWalker, OnStackFrame);
	Gura_AssignMethod(wx_StackWalker, Walk);
	Gura_AssignMethod(wx_StackWalker, WalkFromException);
}

Gura_ImplementDescendantCreator(wx_StackWalker)
{
	return new Object_wx_StackWalker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
