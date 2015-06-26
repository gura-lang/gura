//----------------------------------------------------------------------------
// wxCommand
// extracted from command.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Command: public wxCommand, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Command *_pObj;
public:
	//inline wx_Command(bool canUndo, const wxString& name) : wxCommand(canUndo, name), _sig(nullptr), _pObj(nullptr) {}
	~wx_Command();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Command *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Command::~wx_Command()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Command::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCommand
//----------------------------------------------------------------------------
Gura_DeclareFunction(Command)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Command));
	DeclareArg(env, "canUndo", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Command)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	bool canUndo = false;
	if (args.IsValid(0)) canUndo = args.GetBoolean(0);
	wxString name = nullptr;
	if (args.IsValid(1)) name = wxString::FromUTF8(args.GetString(1));
	wx_Command *pEntity = new wx_Command(canUndo, name);
	Object_wx_Command *pObj = Object_wx_Command::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Command(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_Command, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Command, CanUndo)
{
	Object_wx_Command *pThis = Object_wx_Command::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Command, Do)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Command, Do)
{
	Object_wx_Command *pThis = Object_wx_Command::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Do();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Command, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Command, GetName)
{
	Object_wx_Command *pThis = Object_wx_Command::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Command, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Command, Undo)
{
	Object_wx_Command *pThis = Object_wx_Command::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Undo();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCommand
//----------------------------------------------------------------------------
Object_wx_Command::~Object_wx_Command()
{
}

Object *Object_wx_Command::Clone() const
{
	return nullptr;
}

String Object_wx_Command::ToString(bool exprFlag)
{
	String rtn("<wx.Command:");
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
// Class implementation for wxCommand
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Command)
{
	Gura_AssignFunction(Command);
	Gura_AssignMethod(wx_Command, CanUndo);
	Gura_AssignMethod(wx_Command, Do);
	Gura_AssignMethod(wx_Command, GetName);
	Gura_AssignMethod(wx_Command, Undo);
}

Gura_ImplementDescendantCreator(wx_Command)
{
	return new Object_wx_Command((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
