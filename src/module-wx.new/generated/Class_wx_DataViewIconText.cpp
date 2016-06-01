//----------------------------------------------------------------------------
// wxDataViewIconText
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewIconText
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewIconText
//----------------------------------------------------------------------------
Object_wx_DataViewIconText::~Object_wx_DataViewIconText()
{
}

Object *Object_wx_DataViewIconText::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewIconText::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewIconText:");
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
Gura_DeclareMethod(wx_DataViewIconText, wxDataViewIconText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIconText, wxDataViewIconText)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->wxDataViewIconText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIconText, wxDataViewIconText_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIconText, wxDataViewIconText_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->wxDataViewIconText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIconText, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewIconText, GetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIconText, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewIconText, GetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIconText, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIconText, SetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIconText, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIconText, SetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewIconText
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewIconText)
{
	Gura_AssignMethod(wx_DataViewIconText, wxDataViewIconText);
	Gura_AssignMethod(wx_DataViewIconText, wxDataViewIconText_1);
	Gura_AssignMethod(wx_DataViewIconText, GetIcon);
	Gura_AssignMethod(wx_DataViewIconText, GetText);
	Gura_AssignMethod(wx_DataViewIconText, SetIcon);
	Gura_AssignMethod(wx_DataViewIconText, SetText);
}

Gura_ImplementDescendantCreator(wx_DataViewIconText)
{
	return new Object_wx_DataViewIconText((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
