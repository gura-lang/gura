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
	//Gura::Signal *_pSig;
	Object_wx_DebugContext *_pObj;
public:
	~wx_DebugContext();
	inline void AssocWithGura(Object_wx_DebugContext *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugContext::~wx_DebugContext()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DebugContext::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugContext
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DebugContext, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, Check)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->Check();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, Dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, Dump)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Dump();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetCheckPrevious)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetCheckPrevious)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetCheckPrevious();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetDebugMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetDebugMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetDebugMode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLevel();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	Stream & rtn = pThis->GetEntity()->GetStream();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, GetStreamBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, GetStreamBuf)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, HasStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, HasStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasStream();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, PrintClasses)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, PrintClasses)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->PrintClasses();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, PrintStatistics)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "detailed", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, PrintStatistics)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool detailed = true;
	if (args.IsValid(0)) detailed = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->PrintStatistics(detailed);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, SetCheckpoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "all", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, SetCheckpoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool all = false;
	if (args.IsValid(0)) all = args.GetBoolean(0);
	pThis->GetEntity()->SetCheckpoint(all);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, SetCheckPrevious)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetCheckPrevious)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool check = args.GetBoolean(0);
	pThis->GetEntity()->SetCheckPrevious(check);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, SetDebugMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "debug", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetDebugMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool debug = args.GetBoolean(0);
	pThis->GetEntity()->SetDebugMode(debug);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, SetFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, SetFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SetFile(filename);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, SetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	pThis->GetEntity()->SetLevel(level);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugContext, SetStandardError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugContext, SetStandardError)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugContext *pThis = Object_wx_DebugContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->SetStandardError();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugContext, SetStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugContext, SetStream)
{
	Signal &sig = env.GetSignal();
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
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DebugContext::Clone() const
{
	return nullptr;
}

String Object_wx_DebugContext::ToString(bool exprFlag)
{
	String rtn("<wx.DebugContext:");
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
	return new Object_wx_DebugContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
