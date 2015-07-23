//----------------------------------------------------------------------------
// wxStackFrame
// extracted from stackframe.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StackFrame: public wxStackFrame, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StackFrame *_pObj;
public:
	~wx_StackFrame();
	inline void AssocWithGura(Object_wx_StackFrame *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StackFrame::~wx_StackFrame()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StackFrame::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStackFrame
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_StackFrame, GetAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StackFrame, GetAddress)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->GetAddress();
	return Value::Null;
}

Gura_DeclareMethod(wx_StackFrame, GetFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackFrame, GetFileName)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFileName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StackFrame, GetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackFrame, GetLevel)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetLevel();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StackFrame, GetLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackFrame, GetLine)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetLine();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StackFrame, GetModule)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackFrame, GetModule)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetModule();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StackFrame, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackFrame, GetName)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StackFrame, GetOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackFrame, GetOffset)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetOffset();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StackFrame, GetParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackFrame, GetParam)
{
#if 0
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxString type = wxString::FromUTF8(args.GetString(1));
	wxString name = wxString::FromUTF8(args.GetString(2));
	wxString value = wxString::FromUTF8(args.GetString(3));
	bool rtn = pThis->GetEntity()->GetParam(n, type, name, value);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StackFrame, GetParamCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackFrame, GetParamCount)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetParamCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StackFrame, HasSourceLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StackFrame, HasSourceLocation)
{
	Object_wx_StackFrame *pThis = Object_wx_StackFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasSourceLocation();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxStackFrame
//----------------------------------------------------------------------------
Object_wx_StackFrame::~Object_wx_StackFrame()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_StackFrame::Clone() const
{
	return nullptr;
}

String Object_wx_StackFrame::ToString(bool exprFlag)
{
	String rtn("<wx.StackFrame:");
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
// Class implementation for wxStackFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackFrame)
{
	Gura_AssignMethod(wx_StackFrame, GetAddress);
	Gura_AssignMethod(wx_StackFrame, GetFileName);
	Gura_AssignMethod(wx_StackFrame, GetLevel);
	Gura_AssignMethod(wx_StackFrame, GetLine);
	Gura_AssignMethod(wx_StackFrame, GetModule);
	Gura_AssignMethod(wx_StackFrame, GetName);
	Gura_AssignMethod(wx_StackFrame, GetOffset);
	Gura_AssignMethod(wx_StackFrame, GetParam);
	Gura_AssignMethod(wx_StackFrame, GetParamCount);
	Gura_AssignMethod(wx_StackFrame, HasSourceLocation);
}

Gura_ImplementDescendantCreator(wx_StackFrame)
{
	return new Object_wx_StackFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
