//----------------------------------------------------------------------------
// wxHtmlTagsModule
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTagsModule
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTagsModule
//----------------------------------------------------------------------------
Object_wx_HtmlTagsModule::~Object_wx_HtmlTagsModule()
{
}

Object *Object_wx_HtmlTagsModule::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTagsModule::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTagsModule:");
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
Gura_DeclareMethod(wx_HtmlTagsModule, FillHandlersTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTagsModule, FillHandlersTable)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTagsModule *pThis = Object_wx_HtmlTagsModule::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->FillHandlersTable();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlTagsModule
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTagsModule)
{
	Gura_AssignMethod(wx_HtmlTagsModule, FillHandlersTable);
}

Gura_ImplementDescendantCreator(wx_HtmlTagsModule)
{
	return new Object_wx_HtmlTagsModule((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
