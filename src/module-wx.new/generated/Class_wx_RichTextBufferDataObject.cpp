//----------------------------------------------------------------------------
// wxRichTextBufferDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextBufferDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextBufferDataObject
//----------------------------------------------------------------------------
Object_wx_RichTextBufferDataObject::~Object_wx_RichTextBufferDataObject()
{
}

Object *Object_wx_RichTextBufferDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextBufferDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextBufferDataObject:");
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
Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __wxRichTextBufferDataObject, "wxRichTextBufferDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "richTextBuffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __wxRichTextBufferDataObject)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int richTextBuffer = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextBufferDataObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __GetRichTextBuffer, "GetRichTextBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __GetRichTextBuffer)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __GetRichTextBufferFormatId, "GetRichTextBufferFormatId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __GetRichTextBufferFormatId)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextBufferFormatId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __GetPreferredFormat, "GetPreferredFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __GetPreferredFormat)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->GetPreferredFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __GetDataSize, "GetDataSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __GetDataSize)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __GetDataHere, "GetDataHere")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pBuf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __GetDataHere)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pBuf = arg.GetNumber(0)
	//pThis->GetEntity()->GetDataHere();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __SetData, "SetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __SetData)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//int buf = arg.GetNumber(1)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __GetDataSize_1, "GetDataSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __GetDataSize_1)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __GetDataHere_1, "GetDataHere_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __GetDataHere_1)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->GetDataHere();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBufferDataObject, __SetData_1, "SetData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, __SetData_1)
{
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//int buf = arg.GetNumber(1)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextBufferDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextBufferDataObject)
{
	Gura_AssignMethod(wx_RichTextBufferDataObject, __wxRichTextBufferDataObject);
	Gura_AssignMethod(wx_RichTextBufferDataObject, __GetRichTextBuffer);
	Gura_AssignMethod(wx_RichTextBufferDataObject, __GetRichTextBufferFormatId);
	Gura_AssignMethod(wx_RichTextBufferDataObject, __GetPreferredFormat);
	Gura_AssignMethod(wx_RichTextBufferDataObject, __GetDataSize);
	Gura_AssignMethod(wx_RichTextBufferDataObject, __GetDataHere);
	Gura_AssignMethod(wx_RichTextBufferDataObject, __SetData);
	Gura_AssignMethod(wx_RichTextBufferDataObject, __GetDataSize_1);
	Gura_AssignMethod(wx_RichTextBufferDataObject, __GetDataHere_1);
	Gura_AssignMethod(wx_RichTextBufferDataObject, __SetData_1);
}

Gura_ImplementDescendantCreator(wx_RichTextBufferDataObject)
{
	return new Object_wx_RichTextBufferDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
