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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AddRemoveCtrl, __wxAddRemoveCtrl, "wxAddRemoveCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, __wxAddRemoveCtrl)
{
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAddRemoveCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AddRemoveCtrl, __wxAddRemoveCtrl_1, "wxAddRemoveCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, __wxAddRemoveCtrl_1)
{
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxAddRemoveCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AddRemoveCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
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
	//int adaptor = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdaptor();
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
	//int addtip = arg.GetNumber(0)
	//int removetip = arg.GetNumber(1)
	//pThis->GetEntity()->SetButtonsToolTips();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAddRemoveCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AddRemoveCtrl)
{
	Gura_AssignMethod(wx_AddRemoveCtrl, __wxAddRemoveCtrl);
	Gura_AssignMethod(wx_AddRemoveCtrl, __wxAddRemoveCtrl_1);
	Gura_AssignMethod(wx_AddRemoveCtrl, __Create);
	Gura_AssignMethod(wx_AddRemoveCtrl, __SetAdaptor);
	Gura_AssignMethod(wx_AddRemoveCtrl, __SetButtonsToolTips);
}

Gura_ImplementDescendantCreator(wx_AddRemoveCtrl)
{
	return new Object_wx_AddRemoveCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
