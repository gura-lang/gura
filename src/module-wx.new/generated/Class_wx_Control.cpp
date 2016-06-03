//----------------------------------------------------------------------------
// wxControl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxControl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxControl
//----------------------------------------------------------------------------
Object_wx_Control::~Object_wx_Control()
{
}

Object *Object_wx_Control::Clone() const
{
	return nullptr;
}

String Object_wx_Control::ToString(bool exprFlag)
{
	String rtn("<wx.Control:");
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
Gura_DeclareMethodAlias(wx_Control, __wxControl, "wxControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __wxControl)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __wxControl_1, "wxControl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Control, __wxControl_1)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __Create)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __Command, "Command")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __Command)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->Command();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Control, __GetLabel)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __GetLabelText, "GetLabelText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Control, __GetLabelText)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabelText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __GetSizeFromTextSize, "GetSizeFromTextSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xlen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ylen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __GetSizeFromTextSize)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xlen = arg.GetNumber(0)
	//int ylen = arg.GetNumber(1)
	//pThis->GetEntity()->GetSizeFromTextSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __GetSizeFromTextSize_1, "GetSizeFromTextSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __GetSizeFromTextSize_1)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tsize = arg.GetNumber(0)
	//pThis->GetEntity()->GetSizeFromTextSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __SetLabel, "SetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __SetLabel)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __SetLabelText, "SetLabelText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __SetLabelText)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabelText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __SetLabelMarkup, "SetLabelMarkup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markup", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __SetLabelMarkup)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markup = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabelMarkup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __GetLabelText_1, "GetLabelText_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __GetLabelText_1)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabelText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __RemoveMnemonics, "RemoveMnemonics")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __RemoveMnemonics)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveMnemonics();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __EscapeMnemonics, "EscapeMnemonics")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __EscapeMnemonics)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->EscapeMnemonics();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Control, __Ellipsize, "Ellipsize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxWidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Control, __Ellipsize)
{
	Object_wx_Control *pThis = Object_wx_Control::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//int maxWidth = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->Ellipsize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxControl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Control)
{
	Gura_AssignMethod(wx_Control, __wxControl);
	Gura_AssignMethod(wx_Control, __wxControl_1);
	Gura_AssignMethod(wx_Control, __Create);
	Gura_AssignMethod(wx_Control, __Command);
	Gura_AssignMethod(wx_Control, __GetLabel);
	Gura_AssignMethod(wx_Control, __GetLabelText);
	Gura_AssignMethod(wx_Control, __GetSizeFromTextSize);
	Gura_AssignMethod(wx_Control, __GetSizeFromTextSize_1);
	Gura_AssignMethod(wx_Control, __SetLabel);
	Gura_AssignMethod(wx_Control, __SetLabelText);
	Gura_AssignMethod(wx_Control, __SetLabelMarkup);
	Gura_AssignMethod(wx_Control, __GetLabelText_1);
	Gura_AssignMethod(wx_Control, __RemoveMnemonics);
	Gura_AssignMethod(wx_Control, __EscapeMnemonics);
	Gura_AssignMethod(wx_Control, __Ellipsize);
}

Gura_ImplementDescendantCreator(wx_Control)
{
	return new Object_wx_Control((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
