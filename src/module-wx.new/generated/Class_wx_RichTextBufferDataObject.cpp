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
Gura_DeclareMethod(wx_RichTextBufferDataObject, wxRichTextBufferDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "richTextBuffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, wxRichTextBufferDataObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int richTextBuffer = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextBufferDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, ~wxRichTextBufferDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, ~wxRichTextBufferDataObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRichTextBufferDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, GetRichTextBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, GetRichTextBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, GetRichTextBufferFormatId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, GetRichTextBufferFormatId)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextBufferFormatId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, GetPreferredFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, GetPreferredFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->GetPreferredFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, GetDataSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, GetDataSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, GetDataHere)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pBuf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, GetDataHere)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pBuf = arg.GetNumber(0)
	//pThis->GetEntity()->GetDataHere();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, SetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//int buf = arg.GetNumber(1)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, GetDataSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, GetDataSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, GetDataHere_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, GetDataHere_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->GetDataHere();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBufferDataObject, SetData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBufferDataObject, SetData_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBufferDataObject *pThis = Object_wx_RichTextBufferDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_RichTextBufferDataObject, wxRichTextBufferDataObject);
	Gura_AssignMethod(wx_RichTextBufferDataObject, ~wxRichTextBufferDataObject);
	Gura_AssignMethod(wx_RichTextBufferDataObject, GetRichTextBuffer);
	Gura_AssignMethod(wx_RichTextBufferDataObject, GetRichTextBufferFormatId);
	Gura_AssignMethod(wx_RichTextBufferDataObject, GetPreferredFormat);
	Gura_AssignMethod(wx_RichTextBufferDataObject, GetDataSize);
	Gura_AssignMethod(wx_RichTextBufferDataObject, GetDataHere);
	Gura_AssignMethod(wx_RichTextBufferDataObject, SetData);
	Gura_AssignMethod(wx_RichTextBufferDataObject, GetDataSize_1);
	Gura_AssignMethod(wx_RichTextBufferDataObject, GetDataHere_1);
	Gura_AssignMethod(wx_RichTextBufferDataObject, SetData_1);
}

Gura_ImplementDescendantCreator(wx_RichTextBufferDataObject)
{
	return new Object_wx_RichTextBufferDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
