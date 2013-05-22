//----------------------------------------------------------------------------
// wxStackWalker
// extracted from stackwalker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StackWalker: public wxStackWalker, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StackWalker *_pObj;
public:
	//inline wx_StackWalker() : wxStackWalker(), _sig(NULL), _pObj(NULL) {}
	~wx_StackWalker();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StackWalker *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StackWalker::~wx_StackWalker()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StackWalker::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStackWalker
//----------------------------------------------------------------------------
Gura_DeclareFunction(StackWalkerEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_StackWalker));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(StackWalkerEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_StackWalker *pEntity = new wx_StackWalker();
	Object_wx_StackWalker *pObj = Object_wx_StackWalker::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StackWalker(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_StackWalker, OnStackFrame)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "frame", VTYPE_wx_StackFrame, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_StackWalker, OnStackFrame)
{
#if 0
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxStackFrame *frame = Object_wx_StackFrame::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnStackFrame(*frame);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StackWalker, Walk)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "skip", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxDepth", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackWalker, Walk)
{
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t skip = 1;
	if (args.IsValid(0)) skip = args.GetSizeT(0);
	size_t maxDepth = 200;
	if (args.IsValid(1)) maxDepth = args.GetSizeT(1);
	pThis->GetEntity()->Walk(skip, maxDepth);
	return Value::Null;
}

Gura_DeclareMethod(wx_StackWalker, WalkFromException)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackWalker, WalkFromException)
{
	Object_wx_StackWalker *pThis = Object_wx_StackWalker::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->WalkFromException();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxStackWalker
//----------------------------------------------------------------------------
Object_wx_StackWalker::~Object_wx_StackWalker()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_StackWalker::Clone() const
{
	return NULL;
}

String Object_wx_StackWalker::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StackWalker:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_StackWalker::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(StackWalkerEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxStackWalker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackWalker)
{
	Gura_AssignMethod(wx_StackWalker, OnStackFrame);
	Gura_AssignMethod(wx_StackWalker, Walk);
	Gura_AssignMethod(wx_StackWalker, WalkFromException);
}

Gura_ImplementDescendantCreator(wx_StackWalker)
{
	return new Object_wx_StackWalker((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
