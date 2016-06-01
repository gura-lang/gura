//----------------------------------------------------------------------------
// wxHtmlModalHelp
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlModalHelp
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlModalHelp
//----------------------------------------------------------------------------
Object_wx_HtmlModalHelp::~Object_wx_HtmlModalHelp()
{
}

Object *Object_wx_HtmlModalHelp::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlModalHelp::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlModalHelp:");
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
Gura_DeclareMethod(wx_HtmlModalHelp, wxHtmlModalHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlModalHelp, wxHtmlModalHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlModalHelp *pThis = Object_wx_HtmlModalHelp::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int helpFile = arg.GetNumber(1)
	//int topic = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->wxHtmlModalHelp();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlModalHelp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlModalHelp)
{
	Gura_AssignMethod(wx_HtmlModalHelp, wxHtmlModalHelp);
}

Gura_ImplementDescendantCreator(wx_HtmlModalHelp)
{
	return new Object_wx_HtmlModalHelp((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
