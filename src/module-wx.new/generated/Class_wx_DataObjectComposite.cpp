//----------------------------------------------------------------------------
// wxDataObjectComposite
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataObjectComposite
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataObjectComposite
//----------------------------------------------------------------------------
Object_wx_DataObjectComposite::~Object_wx_DataObjectComposite()
{
}

Object *Object_wx_DataObjectComposite::Clone() const
{
	return nullptr;
}

String Object_wx_DataObjectComposite::ToString(bool exprFlag)
{
	String rtn("<wx.DataObjectComposite:");
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
Gura_DeclareFunctionAlias(__DataObjectComposite, "DataObjectComposite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataObjectComposite));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataObjectComposite)
{
	//wxDataObjectComposite();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataObjectComposite, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dataObject", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "preferred", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectComposite, __Add)
{
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataObjectSimple* dataObject = arg.GetNumber(0)
	//bool preferred = arg.GetNumber(1)
	//pThis->GetEntity()->Add(dataObject, preferred);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataObjectComposite, __GetReceivedFormat, "GetReceivedFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataObjectComposite, __GetReceivedFormat)
{
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataFormat _rtn = pThis->GetEntity()->GetReceivedFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataObjectComposite, __GetObject, "GetObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectComposite, __GetObject)
{
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataFormat& format = arg.GetNumber(0)
	//wxDataObject::Direction dir = arg.GetNumber(1)
	//wxDataObjectSimple* _rtn = pThis->GetEntity()->GetObject(format, dir);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataObjectComposite
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataObjectComposite)
{
	// Constructor assignment
	Gura_AssignFunction(__DataObjectComposite);
	// Method assignment
	Gura_AssignMethod(wx_DataObjectComposite, __Add);
	Gura_AssignMethod(wx_DataObjectComposite, __GetReceivedFormat);
	Gura_AssignMethod(wx_DataObjectComposite, __GetObject);
}

Gura_ImplementDescendantCreator(wx_DataObjectComposite)
{
	return new Object_wx_DataObjectComposite((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
