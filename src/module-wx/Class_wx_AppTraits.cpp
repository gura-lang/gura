//----------------------------------------------------------------------------
// wxAppTraits
// extracted from apptraits.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(CreateFontMapper);
Gura_DeclarePrivUserSymbol(CreateLogTarget);
Gura_DeclarePrivUserSymbol(CreateMessageOutput);
Gura_DeclarePrivUserSymbol(CreateRenderer);
Gura_DeclarePrivUserSymbol(GetDesktopEnvironment);
Gura_DeclarePrivUserSymbol(GetStandardPaths);
Gura_DeclarePrivUserSymbol(GetToolkitVersion);
Gura_DeclarePrivUserSymbol(HasStderr);
Gura_DeclarePrivUserSymbol(ShowAssertDialog);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AppTraits: public wxAppTraits, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_AppTraits *_pObj;
public:
	//virtual wxFontMapper * CreateFontMapper();
	//virtual wxLog * CreateLogTarget();
	//virtual wxMessageOutput * CreateMessageOutput();
	//virtual wxRendererNative * CreateRenderer();
	//virtual wxString GetDesktopEnvironment();
	//virtual wxStandardPaths & GetStandardPaths();
	//virtual wxPortId GetToolkitVersion(int * major, int * minor);
	//virtual bool HasStderr();
	//virtual bool ShowAssertDialog(const wxString & msg);
	~wx_AppTraits();
	inline void AssocWithGura(Object_wx_AppTraits *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AppTraits::~wx_AppTraits()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AppTraits::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAppTraits
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AppTraits, CreateFontMapper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, CreateFontMapper)
{
	Signal &sig = env.GetSignal();
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontMapper *rtn = (wxFontMapper *)pThis->GetEntity()->CreateFontMapper();
	return ReturnValue(env, args, Value(new Object_wx_FontMapper(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_AppTraits, CreateLogTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, CreateLogTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLog *rtn = (wxLog *)pThis->GetEntity()->CreateLogTarget();
	return ReturnValue(env, args, Value(new Object_wx_Log(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_AppTraits, CreateMessageOutput)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, CreateMessageOutput)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMessageOutput *rtn = (wxMessageOutput *)pThis->GetEntity()->CreateMessageOutput();
	return ReturnValue(env, args, Value(new Object_wx_MessageOutput(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, CreateRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, CreateRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRendererNative *rtn = (wxRendererNative *)pThis->GetEntity()->CreateRenderer();
	return ReturnValue(env, args, Value(new Object_wx_RendererNative(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_AppTraits, GetDesktopEnvironment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, GetDesktopEnvironment)
{
	Signal &sig = env.GetSignal();
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDesktopEnvironment();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_AppTraits, GetStandardPaths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, GetStandardPaths)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxStandardPaths &rtn = pThis->GetEntity()->GetStandardPaths();
	return ReturnValue(env, args, Value(new Object_wx_StandardPaths(new wxStandardPaths(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, GetToolkitVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "major", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, GetToolkitVersion)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int major = nullptr;
	if (args.IsValid(0)) major = args.GetInt(0);
	int minor = nullptr;
	if (args.IsValid(1)) minor = args.GetInt(1);
	wxPortId rtn = pThis->GetEntity()->GetToolkitVersion(major, minor);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, HasStderr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, HasStderr)
{
	Signal &sig = env.GetSignal();
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasStderr();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AppTraits, IsUsingUniversalWidgets)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, IsUsingUniversalWidgets)
{
	Signal &sig = env.GetSignal();
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsUsingUniversalWidgets();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AppTraits, ShowAssertDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, ShowAssertDialog)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString msg = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->ShowAssertDialog(msg);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxAppTraits
//----------------------------------------------------------------------------
Object_wx_AppTraits::~Object_wx_AppTraits()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_AppTraits::Clone() const
{
	return nullptr;
}

String Object_wx_AppTraits::ToString(bool exprFlag)
{
	String rtn("<wx.AppTraits:");
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
// Class implementation for wxAppTraits
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppTraits)
{
	Gura_RealizeUserSymbol(CreateFontMapper);
	Gura_RealizeUserSymbol(CreateLogTarget);
	Gura_RealizeUserSymbol(CreateMessageOutput);
	Gura_RealizeUserSymbol(CreateRenderer);
	Gura_RealizeUserSymbol(GetDesktopEnvironment);
	Gura_RealizeUserSymbol(GetStandardPaths);
	Gura_RealizeUserSymbol(GetToolkitVersion);
	Gura_RealizeUserSymbol(HasStderr);
	Gura_RealizeUserSymbol(ShowAssertDialog);
	Gura_AssignMethod(wx_AppTraits, CreateFontMapper);
	Gura_AssignMethod(wx_AppTraits, CreateLogTarget);
	Gura_AssignMethod(wx_AppTraits, CreateMessageOutput);
	Gura_AssignMethod(wx_AppTraits, CreateRenderer);
	Gura_AssignMethod(wx_AppTraits, GetDesktopEnvironment);
	Gura_AssignMethod(wx_AppTraits, GetStandardPaths);
	Gura_AssignMethod(wx_AppTraits, GetToolkitVersion);
	Gura_AssignMethod(wx_AppTraits, HasStderr);
	Gura_AssignMethod(wx_AppTraits, IsUsingUniversalWidgets);
	Gura_AssignMethod(wx_AppTraits, ShowAssertDialog);
}

Gura_ImplementDescendantCreator(wx_AppTraits)
{
	return new Object_wx_AppTraits((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
