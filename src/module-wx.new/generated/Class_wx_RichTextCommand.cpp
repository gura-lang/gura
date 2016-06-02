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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextCommand, wxRichTextCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ignoreFirstTime", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCommand, wxRichTextCommand)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int buffer = arg.GetNumber(2)
	//int container = arg.GetNumber(3)
	//int ctrl = arg.GetNumber(4)
	//int ignoreFirstTime = arg.GetNumber(5)
	//pThis->GetEntity()->wxRichTextCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCommand, wxRichTextCommand_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCommand, wxRichTextCommand_1)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCommand, Do)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCommand, Do)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Do();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCommand, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCommand, Undo)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCommand, AddAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCommand, AddAction)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//pThis->GetEntity()->AddAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCommand, ClearActions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCommand, ClearActions)
{
	Object_wx_RichTextCommand *pThis = Object_wx_RichTextCommand::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearActions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCommand, GetActions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCommand, GetActions)
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
	Gura_AssignMethod(wx_RichTextCommand, wxRichTextCommand);
	Gura_AssignMethod(wx_RichTextCommand, wxRichTextCommand_1);
	Gura_AssignMethod(wx_RichTextCommand, Do);
	Gura_AssignMethod(wx_RichTextCommand, Undo);
	Gura_AssignMethod(wx_RichTextCommand, AddAction);
	Gura_AssignMethod(wx_RichTextCommand, ClearActions);
	Gura_AssignMethod(wx_RichTextCommand, GetActions);
}

Gura_ImplementDescendantCreator(wx_RichTextCommand)
{
	return new Object_wx_RichTextCommand((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
