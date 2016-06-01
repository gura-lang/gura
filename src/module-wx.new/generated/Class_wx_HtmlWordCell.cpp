//----------------------------------------------------------------------------
// wxHtmlWordCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWordCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWordCell
//----------------------------------------------------------------------------
Object_wx_HtmlWordCell::~Object_wx_HtmlWordCell()
{
}

Object *Object_wx_HtmlWordCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWordCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWordCell:");
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
Gura_DeclareMethod(wx_HtmlWordCell, wxHtmlWordCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "word", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWordCell, wxHtmlWordCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWordCell *pThis = Object_wx_HtmlWordCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int word = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//pThis->GetEntity()->wxHtmlWordCell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWordCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWordCell)
{
	Gura_AssignMethod(wx_HtmlWordCell, wxHtmlWordCell);
}

Gura_ImplementDescendantCreator(wx_HtmlWordCell)
{
	return new Object_wx_HtmlWordCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
