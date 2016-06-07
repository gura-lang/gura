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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DataViewIconText, "DataViewIconText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewIconText));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewIconText)
{
	//const wxString& text = arg.GetNumber(0)
	//const wxIcon& icon = arg.GetNumber(1)
	//wxDataViewIconText(text, icon);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DataViewIconText_1, "DataViewIconText_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewIconText));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewIconText_1)
{
	//const wxDataViewIconText& other = arg.GetNumber(0)
	//wxDataViewIconText(other);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewIconText, __GetIcon, "GetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewIconText, __GetIcon)
{
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIconText, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewIconText, __GetText)
{
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIconText, __SetIcon, "SetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIconText, __SetIcon)
{
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxIcon& icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon(icon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIconText, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIconText, __SetText)
{
	Object_wx_DataViewIconText *pThis = Object_wx_DataViewIconText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText(text);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewIconText
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewIconText)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewIconText);
	Gura_AssignFunction(__DataViewIconText_1);
	// Method assignment
	Gura_AssignMethod(wx_DataViewIconText, __GetIcon);
	Gura_AssignMethod(wx_DataViewIconText, __GetText);
	Gura_AssignMethod(wx_DataViewIconText, __SetIcon);
	Gura_AssignMethod(wx_DataViewIconText, __SetText);
}

Gura_ImplementDescendantCreator(wx_DataViewIconText)
{
	return new Object_wx_DataViewIconText((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
