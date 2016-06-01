//----------------------------------------------------------------------------
// wxBusyInfoFlags
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBusyInfoFlags
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBusyInfoFlags
//----------------------------------------------------------------------------
Object_wx_BusyInfoFlags::~Object_wx_BusyInfoFlags()
{
}

Object *Object_wx_BusyInfoFlags::Clone() const
{
	return nullptr;
}

String Object_wx_BusyInfoFlags::ToString(bool exprFlag)
{
	String rtn("<wx.BusyInfoFlags:");
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
Gura_DeclareMethod(wx_BusyInfoFlags, wxBusyInfoFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BusyInfoFlags, wxBusyInfoFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxBusyInfoFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfoFlags, Parent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, Parent)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->Parent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfoFlags, Icon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, Icon)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->Icon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfoFlags, Title)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, Title)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->Title();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfoFlags, Text)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, Text)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->Text();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfoFlags, Label)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, Label)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->Label();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfoFlags, Foreground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "foreground", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, Foreground)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int foreground = arg.GetNumber(0)
	//pThis->GetEntity()->Foreground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfoFlags, Background)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "background", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, Background)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int background = arg.GetNumber(0)
	//pThis->GetEntity()->Background();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfoFlags, Transparency)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, Transparency)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int alpha = arg.GetNumber(0)
	//pThis->GetEntity()->Transparency();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBusyInfoFlags
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyInfoFlags)
{
	Gura_AssignMethod(wx_BusyInfoFlags, wxBusyInfoFlags);
	Gura_AssignMethod(wx_BusyInfoFlags, Parent);
	Gura_AssignMethod(wx_BusyInfoFlags, Icon);
	Gura_AssignMethod(wx_BusyInfoFlags, Title);
	Gura_AssignMethod(wx_BusyInfoFlags, Text);
	Gura_AssignMethod(wx_BusyInfoFlags, Label);
	Gura_AssignMethod(wx_BusyInfoFlags, Foreground);
	Gura_AssignMethod(wx_BusyInfoFlags, Background);
	Gura_AssignMethod(wx_BusyInfoFlags, Transparency);
}

Gura_ImplementDescendantCreator(wx_BusyInfoFlags)
{
	return new Object_wx_BusyInfoFlags((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
