//----------------------------------------------------------------------------
// wxRichTextCommand
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCommand
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCommand
//----------------------------------------------------------------------------
Object_wx_RichTextCommand::~Object_wx_RichTextCommand()
{
}

Object *Object_wx_RichTextCommand::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCommand::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCommand:");
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
Gura_DeclareFunctionAlias(__RichTextCommand, "RichTextCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ignoreFirstTime", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCommand));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextCommand)
{
	//int name = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int buffer = arg.GetNumber(2)
	//int container = arg.GetNumber(3)
	//int ctrl = arg.GetNumber(4)
	//int ignoreFirstTime = arg.GetNumber(5)
	//wxRichTextCommand();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextCommand_1, "RichTextCommand_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCommand));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextCommand_1)
{
	//int name = arg.GetNumber(0)
	//wxRichTextCommand();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextCommand, __Do, "Do")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCommand, __Do)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Do();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCommand, __Undo, "Undo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCommand, __Undo)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCommand, __AddAction, "AddAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCommand, __AddAction)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//pThis->GetEntity()->AddAction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCommand, __ClearActions, "ClearActions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCommand, __ClearActions)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearActions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCommand, __GetActions, "GetActions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCommand, __GetActions)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActions();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCommand
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCommand)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextCommand);
	Gura_AssignFunction(__RichTextCommand_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextCommand, __Do);
	Gura_AssignMethod(wx_RichTextCommand, __Undo);
	Gura_AssignMethod(wx_RichTextCommand, __AddAction);
	Gura_AssignMethod(wx_RichTextCommand, __ClearActions);
	Gura_AssignMethod(wx_RichTextCommand, __GetActions);
}

Gura_ImplementDescendantCreator(wx_RichTextCommand)
{
	return new Object_wx_RichTextCommand((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
