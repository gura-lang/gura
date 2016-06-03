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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxCommand, "wxCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "canUndo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Command));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxCommand)
{
	//int canUndo = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//wxCommand();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Command, __CanUndo, "CanUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Command, __CanUndo)
{
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Command, __Do, "Do")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Command, __Do)
{
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Do();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Command, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Command, __GetName)
{
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Command, __Undo, "Undo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Command, __Undo)
{
	Object_wx_Command *pThis = Object_wx_Command::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCommand
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Command)
{
	// Constructor assignment
	Gura_AssignFunction(__wxCommand);
	// Method assignment
	Gura_AssignMethod(wx_Command, __CanUndo);
	Gura_AssignMethod(wx_Command, __Do);
	Gura_AssignMethod(wx_Command, __GetName);
	Gura_AssignMethod(wx_Command, __Undo);
}

Gura_ImplementDescendantCreator(wx_Command)
{
	return new Object_wx_Command((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
