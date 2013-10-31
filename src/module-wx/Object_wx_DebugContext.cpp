//----------------------------------------------------------------------------
// wxDebugContext
// extracted from debugcxt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DebugContext: public wxDebugContext, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DebugContext *_pObj;
public:
	~wx_DebugContext();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DebugContext *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugContext::~wx_DebugContext()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DebugContext::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugContext
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DebugContext, Check)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, Check)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->Check();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, Dump)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, Dump)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Dump();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetCheckPrevious)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetCheckPrevious)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetCheckPrevious();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetDebugMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetDebugMode)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetDebugMode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetLevel)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetStream)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetStream)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	Stream & rtn = pThis->GetEntity()->GetStream();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetStreamBuf)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetStreamBuf)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, HasStream)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, HasStream)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasStream();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, PrintClasses)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, PrintClasses)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->PrintClasses();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, PrintStatistics)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "detailed", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, PrintStatistics)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool detailed = true;
	if (args.IsValid(0)) detailed = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->PrintStatistics(detailed);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, SetCheckpoint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "all", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, SetCheckpoint)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool all = false;
	if (args.IsValid(0)) all = args.GetBoolean(0);
	pThis->GetEntity()->SetCheckpoint(all);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, SetCheckPrevious)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetCheckPrevious)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool check = args.GetBoolean(0);
	pThis->GetEntity()->SetCheckPrevious(check);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, SetDebugMode)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "debug", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetDebugMode)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool debug = args.GetBoolean(0);
	pThis->GetEntity()->SetDebugMode(debug);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, SetFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, SetFile)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SetFile(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, SetLevel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetLevel)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	pThis->GetEntity()->SetLevel(level);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, SetStandardError)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, SetStandardError)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->SetStandardError();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, SetStream)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetStream)
{
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	Stream & stream = args.GetStream(0);
	pThis->GetEntity()->SetStream(stream, );
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugContext
//----------------------------------------------------------------------------
Object_wx_DebugContext::~Object_wx_DebugContext()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DebugContext::Clone() const
{
	return NULL;
}

String Object_wx_DebugContext::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DebugContext:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugContext)
{
	Gura_AssignMethod(wx_DebugContext, Check);
	Gura_AssignMethod(wx_DebugContext, Dump);
	Gura_AssignMethod(wx_DebugContext, GetCheckPrevious);
	Gura_AssignMethod(wx_DebugContext, GetDebugMode);
	Gura_AssignMethod(wx_DebugContext, GetLevel);
	Gura_AssignMethod(wx_DebugContext, GetStream);
	Gura_AssignMethod(wx_DebugContext, GetStreamBuf);
	Gura_AssignMethod(wx_DebugContext, HasStream);
	Gura_AssignMethod(wx_DebugContext, PrintClasses);
	Gura_AssignMethod(wx_DebugContext, PrintStatistics);
	Gura_AssignMethod(wx_DebugContext, SetCheckpoint);
	Gura_AssignMethod(wx_DebugContext, SetCheckPrevious);
	Gura_AssignMethod(wx_DebugContext, SetDebugMode);
	Gura_AssignMethod(wx_DebugContext, SetFile);
	Gura_AssignMethod(wx_DebugContext, SetLevel);
	Gura_AssignMethod(wx_DebugContext, SetStandardError);
	Gura_AssignMethod(wx_DebugContext, SetStream);
}

Gura_ImplementDescendantCreator(wx_DebugContext)
{
	return new Object_wx_DebugContext((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
