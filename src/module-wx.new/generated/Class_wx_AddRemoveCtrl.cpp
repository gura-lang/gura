//----------------------------------------------------------------------------
// wxAddRemoveCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAddRemoveCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAddRemoveCtrl
//----------------------------------------------------------------------------
Object_wx_AddRemoveCtrl::~Object_wx_AddRemoveCtrl()
{
}

Object *Object_wx_AddRemoveCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_AddRemoveCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.AddRemoveCtrl:");
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
Gura_DeclareFunctionAlias(__AddRemoveCtrl, "AddRemoveCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AddRemoveCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AddRemoveCtrl)
{
	//wxAddRemoveCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__AddRemoveCtrl_1, "AddRemoveCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AddRemoveCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AddRemoveCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxAddRemoveCtrl(parent, winid, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AddRemoveCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, __Create)
{
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->Create(parent, winid, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AddRemoveCtrl, __SetAdaptor, "SetAdaptor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "adaptor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, __SetAdaptor)
{
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAddRemoveAdaptor* adaptor = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdaptor(adaptor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AddRemoveCtrl, __SetButtonsToolTips, "SetButtonsToolTips")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "addtip", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "removetip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, __SetButtonsToolTips)
{
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& addtip = arg.GetNumber(0)
	//const wxString& removetip = arg.GetNumber(1)
	//pThis->GetEntity()->SetButtonsToolTips(addtip, removetip);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAddRemoveCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AddRemoveCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__AddRemoveCtrl);
	Gura_AssignFunction(__AddRemoveCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_AddRemoveCtrl, __Create);
	Gura_AssignMethod(wx_AddRemoveCtrl, __SetAdaptor);
	Gura_AssignMethod(wx_AddRemoveCtrl, __SetButtonsToolTips);
}

Gura_ImplementDescendantCreator(wx_AddRemoveCtrl)
{
	return new Object_wx_AddRemoveCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
