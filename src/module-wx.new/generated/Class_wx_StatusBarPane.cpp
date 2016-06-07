//----------------------------------------------------------------------------
// wxStatusBarPane
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStatusBarPane
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStatusBarPane
//----------------------------------------------------------------------------
Object_wx_StatusBarPane::~Object_wx_StatusBarPane()
{
}

Object *Object_wx_StatusBarPane::Clone() const
{
	return nullptr;
}

String Object_wx_StatusBarPane::ToString(bool exprFlag)
{
	String rtn("<wx.StatusBarPane:");
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
Gura_DeclareFunctionAlias(__StatusBarPane, "StatusBarPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StatusBarPane));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StatusBarPane)
{
	//int style = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//wxStatusBarPane(style, width);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StatusBarPane, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StatusBarPane, __GetWidth)
{
	Object_wx_StatusBarPane *pThis = Object_wx_StatusBarPane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBarPane, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StatusBarPane, __GetStyle)
{
	Object_wx_StatusBarPane *pThis = Object_wx_StatusBarPane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBarPane, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StatusBarPane, __GetText)
{
	Object_wx_StatusBarPane *pThis = Object_wx_StatusBarPane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStatusBarPane
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StatusBarPane)
{
	// Constructor assignment
	Gura_AssignFunction(__StatusBarPane);
	// Method assignment
	Gura_AssignMethod(wx_StatusBarPane, __GetWidth);
	Gura_AssignMethod(wx_StatusBarPane, __GetStyle);
	Gura_AssignMethod(wx_StatusBarPane, __GetText);
}

Gura_ImplementDescendantCreator(wx_StatusBarPane)
{
	return new Object_wx_StatusBarPane((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
