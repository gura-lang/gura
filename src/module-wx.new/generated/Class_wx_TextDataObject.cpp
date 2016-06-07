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
Gura_DeclareFunctionAlias(__TextDataObject, "TextDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TextDataObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextDataObject)
{
	//const wxString& text = arg.GetNumber(0)
	//wxTextDataObject(text);
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
	//wxDataObject::Direction dir = arg.GetNumber(0)
	//pThis->GetEntity()->GetFormatCount(dir);
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
	//wxDataFormat* formats = arg.GetNumber(0)
	//wxDataObject::Direction dir = arg.GetNumber(1)
	//pThis->GetEntity()->GetAllFormats(formats, dir);
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
	//const wxString& strText = arg.GetNumber(0)
	//pThis->GetEntity()->SetText(strText);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextDataObject)
{
	// Constructor assignment
	Gura_AssignFunction(__TextDataObject);
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
