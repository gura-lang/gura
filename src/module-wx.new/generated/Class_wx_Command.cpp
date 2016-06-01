//----------------------------------------------------------------------------
// wxCommand
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCommand
//----------------------------------------------------------------------------

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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Command, wxCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "canUndo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Command, wxCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int canUndo = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Command, ~wxCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Command, ~wxCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Command, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Command, CanUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Command, Do)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Command, Do)
{
	Signal &sig = env.GetSignal();
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Do();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Command, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Command, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Command, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Command, Undo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCommand
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Command)
{
	Gura_AssignMethod(wx_Command, wxCommand);
	Gura_AssignMethod(wx_Command, ~wxCommand);
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
