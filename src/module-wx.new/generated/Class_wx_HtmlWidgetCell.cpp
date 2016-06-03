//----------------------------------------------------------------------------
// wxHtmlWidgetCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWidgetCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Object_wx_HtmlWidgetCell::~Object_wx_HtmlWidgetCell()
{
}

Object *Object_wx_HtmlWidgetCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWidgetCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWidgetCell:");
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
Gura_DeclareMethodAlias(wx_HtmlWidgetCell, __wxHtmlWidgetCell, "wxHtmlWidgetCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWidgetCell, __wxHtmlWidgetCell)
{
	Object_wx_HtmlWidgetCell *pThis = Object_wx_HtmlWidgetCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wnd = arg.GetNumber(0)
	//int w = arg.GetNumber(1)
	//pThis->GetEntity()->wxHtmlWidgetCell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWidgetCell)
{
	Gura_AssignMethod(wx_HtmlWidgetCell, __wxHtmlWidgetCell);
}

Gura_ImplementDescendantCreator(wx_HtmlWidgetCell)
{
	return new Object_wx_HtmlWidgetCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
