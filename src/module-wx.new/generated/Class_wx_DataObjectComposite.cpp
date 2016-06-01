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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataObjectComposite, wxDataObjectComposite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataObjectComposite, wxDataObjectComposite)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDataObjectComposite();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectComposite, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dataObject", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "preferred", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectComposite, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dataObject = arg.GetNumber(0)
	//int preferred = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectComposite, GetReceivedFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataObjectComposite, GetReceivedFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetReceivedFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectComposite, GetObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectComposite, GetObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_DataObjectComposite, wxDataObjectComposite);
	Gura_AssignMethod(wx_DataObjectComposite, Add);
	Gura_AssignMethod(wx_DataObjectComposite, GetReceivedFormat);
	Gura_AssignMethod(wx_DataObjectComposite, GetObject);
}

Gura_ImplementDescendantCreator(wx_DataObjectComposite)
{
	return new Object_wx_DataObjectComposite((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
