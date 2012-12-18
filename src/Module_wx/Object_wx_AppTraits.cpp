//----------------------------------------------------------------------------
// wxAppTraits
// extracted from apptraits.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

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
	Gura::Signal _sig;
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
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AppTraits *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AppTraits::~wx_AppTraits()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AppTraits::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAppTraits
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AppTraits, CreateFontMapper)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, CreateFontMapper)
{
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFontMapper *rtn = (wxFontMapper *)pSelf->GetEntity()->CreateFontMapper();
	return ReturnValue(env, sig, args, Value(new Object_wx_FontMapper(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_AppTraits, CreateLogTarget)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, CreateLogTarget)
{
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxLog *rtn = (wxLog *)pSelf->GetEntity()->CreateLogTarget();
	return ReturnValue(env, sig, args, Value(new Object_wx_Log(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_AppTraits, CreateMessageOutput)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, CreateMessageOutput)
{
#if 0
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMessageOutput *rtn = (wxMessageOutput *)pSelf->GetEntity()->CreateMessageOutput();
	return ReturnValue(env, sig, args, Value(new Object_wx_MessageOutput(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AppTraits, CreateRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, CreateRenderer)
{
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRendererNative *rtn = (wxRendererNative *)pSelf->GetEntity()->CreateRenderer();
	return ReturnValue(env, sig, args, Value(new Object_wx_RendererNative(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_AppTraits, GetDesktopEnvironment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, GetDesktopEnvironment)
{
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetDesktopEnvironment();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_AppTraits, GetStandardPaths)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, GetStandardPaths)
{
#if 0
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxStandardPaths &rtn = pSelf->GetEntity()->GetStandardPaths();
	return ReturnValue(env, sig, args, Value(new Object_wx_StandardPaths(new wxStandardPaths(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AppTraits, GetToolkitVersion)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "major", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, GetToolkitVersion)
{
#if 0
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int major = NULL;
	if (args.IsValid(0)) major = args.GetInt(0);
	int minor = NULL;
	if (args.IsValid(1)) minor = args.GetInt(1);
	wxPortId rtn = pSelf->GetEntity()->GetToolkitVersion(major, minor);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AppTraits, HasStderr)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, HasStderr)
{
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasStderr();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AppTraits, IsUsingUniversalWidgets)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, IsUsingUniversalWidgets)
{
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsUsingUniversalWidgets();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AppTraits, ShowAssertDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AppTraits, ShowAssertDialog)
{
#if 0
	Object_wx_AppTraits *pSelf = Object_wx_AppTraits::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString msg = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->ShowAssertDialog(msg);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxAppTraits
//----------------------------------------------------------------------------
Object_wx_AppTraits::~Object_wx_AppTraits()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_AppTraits::Clone() const
{
	return NULL;
}

String Object_wx_AppTraits::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AppTraits:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_AppTraits::OnModuleEntry(Environment &env, Signal sig)
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
}

//----------------------------------------------------------------------------
// Class implementation for wxAppTraits
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppTraits)
{
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
	return new Object_wx_AppTraits((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
