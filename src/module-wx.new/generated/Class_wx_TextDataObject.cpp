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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxTextDataObject, "wxTextDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxTextDataObject)
{
	//int text = arg.GetNumber(0)
	//wxTextDataObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextDataObject, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextDataObject, __GetText)
{
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextDataObject, __GetTextLength, "GetTextLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextDataObject, __GetTextLength)
{
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextDataObject, __GetFormatCount, "GetFormatCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDataObject, __GetFormatCount)
{
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->GetFormatCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextDataObject, __GetFormat, "GetFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextDataObject, __GetFormat)
{
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextDataObject, __GetAllFormats, "GetAllFormats")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "formats", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDataObject, __GetAllFormats)
{
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int formats = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->GetAllFormats();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextDataObject, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDataObject, __SetText)
{
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strText = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextDataObject)
{
	// Constructor assignment
	Gura_AssignFunction(__wxTextDataObject);
	// Method assignment
	Gura_AssignMethod(wx_TextDataObject, __GetText);
	Gura_AssignMethod(wx_TextDataObject, __GetTextLength);
	Gura_AssignMethod(wx_TextDataObject, __GetFormatCount);
	Gura_AssignMethod(wx_TextDataObject, __GetFormat);
	Gura_AssignMethod(wx_TextDataObject, __GetAllFormats);
	Gura_AssignMethod(wx_TextDataObject, __SetText);
}

Gura_ImplementDescendantCreator(wx_TextDataObject)
{
	return new Object_wx_TextDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
