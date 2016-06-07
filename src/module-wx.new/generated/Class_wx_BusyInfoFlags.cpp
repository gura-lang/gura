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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__BusyInfoFlags, "BusyInfoFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BusyInfoFlags));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BusyInfoFlags)
{
	//wxBusyInfoFlags();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BusyInfoFlags, __Parent, "Parent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, __Parent)
{
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//pThis->GetEntity()->Parent(parent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BusyInfoFlags, __Icon, "Icon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, __Icon)
{
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxIcon& icon = arg.GetNumber(0)
	//pThis->GetEntity()->Icon(icon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BusyInfoFlags, __Title, "Title")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, __Title)
{
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//pThis->GetEntity()->Title(title);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BusyInfoFlags, __Text, "Text")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, __Text)
{
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->Text(text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BusyInfoFlags, __Label, "Label")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, __Label)
{
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//pThis->GetEntity()->Label(label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BusyInfoFlags, __Foreground, "Foreground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "foreground", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, __Foreground)
{
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& foreground = arg.GetNumber(0)
	//pThis->GetEntity()->Foreground(foreground);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BusyInfoFlags, __Background, "Background")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "background", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, __Background)
{
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& background = arg.GetNumber(0)
	//pThis->GetEntity()->Background(background);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BusyInfoFlags, __Transparency, "Transparency")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfoFlags, __Transparency)
{
	Object_wx_BusyInfoFlags *pThis = Object_wx_BusyInfoFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxByte alpha = arg.GetNumber(0)
	//pThis->GetEntity()->Transparency(alpha);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBusyInfoFlags
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyInfoFlags)
{
	// Constructor assignment
	Gura_AssignFunction(__BusyInfoFlags);
	// Method assignment
	Gura_AssignMethod(wx_BusyInfoFlags, __Parent);
	Gura_AssignMethod(wx_BusyInfoFlags, __Icon);
	Gura_AssignMethod(wx_BusyInfoFlags, __Title);
	Gura_AssignMethod(wx_BusyInfoFlags, __Text);
	Gura_AssignMethod(wx_BusyInfoFlags, __Label);
	Gura_AssignMethod(wx_BusyInfoFlags, __Foreground);
	Gura_AssignMethod(wx_BusyInfoFlags, __Background);
	Gura_AssignMethod(wx_BusyInfoFlags, __Transparency);
}

Gura_ImplementDescendantCreator(wx_BusyInfoFlags)
{
	return new Object_wx_BusyInfoFlags((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
