//----------------------------------------------------------------------------
// wxHyperlinkEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHyperlinkEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHyperlinkEvent
//----------------------------------------------------------------------------
Object_wx_HyperlinkEvent::~Object_wx_HyperlinkEvent()
{
}

Object *Object_wx_HyperlinkEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HyperlinkEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HyperlinkEvent:");
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
Gura_DeclareFunctionAlias(__HyperlinkEvent, "HyperlinkEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "generator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HyperlinkEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HyperlinkEvent)
{
	//int generator = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int url = arg.GetNumber(2)
	//wxHyperlinkEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HyperlinkEvent, __GetURL, "GetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HyperlinkEvent, __GetURL)
{
	Object_wx_HyperlinkEvent *pThis = Object_wx_HyperlinkEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HyperlinkEvent, __SetURL, "SetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkEvent, __SetURL)
{
	Object_wx_HyperlinkEvent *pThis = Object_wx_HyperlinkEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHyperlinkEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HyperlinkEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__HyperlinkEvent);
	// Method assignment
	Gura_AssignMethod(wx_HyperlinkEvent, __GetURL);
	Gura_AssignMethod(wx_HyperlinkEvent, __SetURL);
}

Gura_ImplementDescendantCreator(wx_HyperlinkEvent)
{
	return new Object_wx_HyperlinkEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
