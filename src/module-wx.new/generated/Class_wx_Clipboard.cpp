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
Gura_DeclareMethodAlias(wx_Clipboard, __wxClipboard, "wxClipboard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, __wxClipboard)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxClipboard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __AddData, "AddData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, __AddData)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->AddData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, __Clear)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, __Close)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __Flush, "Flush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, __Flush)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, __GetData)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __IsOpened, "IsOpened")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, __IsOpened)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __IsSupported, "IsSupported")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, __IsSupported)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsSupported();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __IsUsingPrimarySelection, "IsUsingPrimarySelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, __IsUsingPrimarySelection)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsUsingPrimarySelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __Open, "Open")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, __Open)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __SetData, "SetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, __SetData)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __UsePrimarySelection, "UsePrimarySelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "primary", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Clipboard, __UsePrimarySelection)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int primary = arg.GetNumber(0)
	//pThis->GetEntity()->UsePrimarySelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Clipboard, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, __Get)
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
	Gura_AssignMethod(wx_Clipboard, __wxClipboard);
	Gura_AssignMethod(wx_Clipboard, __AddData);
	Gura_AssignMethod(wx_Clipboard, __Clear);
	Gura_AssignMethod(wx_Clipboard, __Close);
	Gura_AssignMethod(wx_Clipboard, __Flush);
	Gura_AssignMethod(wx_Clipboard, __GetData);
	Gura_AssignMethod(wx_Clipboard, __IsOpened);
	Gura_AssignMethod(wx_Clipboard, __IsSupported);
	Gura_AssignMethod(wx_Clipboard, __IsUsingPrimarySelection);
	Gura_AssignMethod(wx_Clipboard, __Open);
	Gura_AssignMethod(wx_Clipboard, __SetData);
	Gura_AssignMethod(wx_Clipboard, __UsePrimarySelection);
	Gura_AssignMethod(wx_Clipboard, __Get);
}

Gura_ImplementDescendantCreator(wx_Clipboard)
{
	return new Object_wx_Clipboard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
