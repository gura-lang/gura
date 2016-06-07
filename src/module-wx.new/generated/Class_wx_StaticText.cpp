//----------------------------------------------------------------------------
// wxStaticText
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticText
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticText
//----------------------------------------------------------------------------
Object_wx_StaticText::~Object_wx_StaticText()
{
}

Object *Object_wx_StaticText::Clone() const
{
	return nullptr;
}

String Object_wx_StaticText::ToString(bool exprFlag)
{
	String rtn("<wx.StaticText:");
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
Gura_DeclareFunctionAlias(__StaticText, "StaticText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StaticText));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StaticText)
{
	//wxStaticText();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__StaticText_1, "StaticText_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StaticText));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StaticText_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxStaticText(parent, id, label, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StaticText, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticText, __Create)
{
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, label, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StaticText, __IsEllipsized, "IsEllipsized")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StaticText, __IsEllipsized)
{
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEllipsized();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StaticText, __Wrap, "Wrap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticText, __Wrap)
{
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->Wrap(width);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStaticText
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticText)
{
	// Constructor assignment
	Gura_AssignFunction(__StaticText);
	Gura_AssignFunction(__StaticText_1);
	// Method assignment
	Gura_AssignMethod(wx_StaticText, __Create);
	Gura_AssignMethod(wx_StaticText, __IsEllipsized);
	Gura_AssignMethod(wx_StaticText, __Wrap);
}

Gura_ImplementDescendantCreator(wx_StaticText)
{
	return new Object_wx_StaticText((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
