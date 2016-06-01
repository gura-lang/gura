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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_StaticText, wxStaticText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticText, wxStaticText)
{
	Signal &sig = env.GetSignal();
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxStaticText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticText, wxStaticText_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticText, wxStaticText_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxStaticText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticText, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticText, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticText, IsEllipsized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticText, IsEllipsized)
{
	Signal &sig = env.GetSignal();
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEllipsized();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticText, Wrap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticText, Wrap)
{
	Signal &sig = env.GetSignal();
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->Wrap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStaticText
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticText)
{
	Gura_AssignMethod(wx_StaticText, wxStaticText);
	Gura_AssignMethod(wx_StaticText, wxStaticText_1);
	Gura_AssignMethod(wx_StaticText, Create);
	Gura_AssignMethod(wx_StaticText, IsEllipsized);
	Gura_AssignMethod(wx_StaticText, Wrap);
}

Gura_ImplementDescendantCreator(wx_StaticText)
{
	return new Object_wx_StaticText((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
