//----------------------------------------------------------------------------
// wxClipboard
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClipboard
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClipboard
//----------------------------------------------------------------------------
Object_wx_Clipboard::~Object_wx_Clipboard()
{
}

Object *Object_wx_Clipboard::Clone() const
{
	return nullptr;
}

String Object_wx_Clipboard::ToString(bool exprFlag)
{
	String rtn("<wx.Clipboard:");
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
Gura_DeclareMethod(wx_Clipboard, wxClipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, wxClipboard)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxClipboard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, AddData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, AddData)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->AddData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, Clear)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, Close)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, Flush)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, GetData)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, IsOpened)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, IsSupported)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, IsSupported)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsSupported();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, IsUsingPrimarySelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, IsUsingPrimarySelection)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsUsingPrimarySelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, Open)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, SetData)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, UsePrimarySelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "primary", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, UsePrimarySelection)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int primary = arg.GetNumber(0)
	//pThis->GetEntity()->UsePrimarySelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, Get)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClipboard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Clipboard)
{
	Gura_AssignMethod(wx_Clipboard, wxClipboard);
	Gura_AssignMethod(wx_Clipboard, AddData);
	Gura_AssignMethod(wx_Clipboard, Clear);
	Gura_AssignMethod(wx_Clipboard, Close);
	Gura_AssignMethod(wx_Clipboard, Flush);
	Gura_AssignMethod(wx_Clipboard, GetData);
	Gura_AssignMethod(wx_Clipboard, IsOpened);
	Gura_AssignMethod(wx_Clipboard, IsSupported);
	Gura_AssignMethod(wx_Clipboard, IsUsingPrimarySelection);
	Gura_AssignMethod(wx_Clipboard, Open);
	Gura_AssignMethod(wx_Clipboard, SetData);
	Gura_AssignMethod(wx_Clipboard, UsePrimarySelection);
	Gura_AssignMethod(wx_Clipboard, Get);
}

Gura_ImplementDescendantCreator(wx_Clipboard)
{
	return new Object_wx_Clipboard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
