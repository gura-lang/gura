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
Gura_DeclareFunctionAlias(__wxDataObjectComposite, "wxDataObjectComposite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxDataObjectComposite)
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
	//int dataObject = arg.GetNumber(0)
	//int preferred = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataObjectComposite, __GetReceivedFormat, "GetReceivedFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataObjectComposite, __GetReceivedFormat)
{
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetReceivedFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataObjectComposite, __GetObject, "GetObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectComposite, __GetObject)
{
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataObjectComposite
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataObjectComposite)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDataObjectComposite);
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
