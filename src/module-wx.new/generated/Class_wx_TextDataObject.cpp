//----------------------------------------------------------------------------
// wxTextDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextDataObject
//----------------------------------------------------------------------------
Object_wx_TextDataObject::~Object_wx_TextDataObject()
{
}

Object *Object_wx_TextDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_TextDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.TextDataObject:");
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
Gura_DeclareMethod(wx_TextDataObject, wxTextDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDataObject, wxTextDataObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->wxTextDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextDataObject, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextDataObject, GetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextDataObject, GetTextLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextDataObject, GetTextLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextDataObject, GetFormatCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDataObject, GetFormatCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->GetFormatCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextDataObject, GetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextDataObject, GetFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextDataObject, GetAllFormats)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "formats", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDataObject, GetAllFormats)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int formats = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->GetAllFormats();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextDataObject, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDataObject, SetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strText = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextDataObject)
{
	Gura_AssignMethod(wx_TextDataObject, wxTextDataObject);
	Gura_AssignMethod(wx_TextDataObject, GetText);
	Gura_AssignMethod(wx_TextDataObject, GetTextLength);
	Gura_AssignMethod(wx_TextDataObject, GetFormatCount);
	Gura_AssignMethod(wx_TextDataObject, GetFormat);
	Gura_AssignMethod(wx_TextDataObject, GetAllFormats);
	Gura_AssignMethod(wx_TextDataObject, SetText);
}

Gura_ImplementDescendantCreator(wx_TextDataObject)
{
	return new Object_wx_TextDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
