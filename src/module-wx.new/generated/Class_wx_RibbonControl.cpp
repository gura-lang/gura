//----------------------------------------------------------------------------
// wxRibbonControl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonControl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonControl
//----------------------------------------------------------------------------
Object_wx_RibbonControl::~Object_wx_RibbonControl()
{
}

Object *Object_wx_RibbonControl::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonControl::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonControl:");
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
Gura_DeclareMethod(wx_RibbonControl, wxRibbonControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, wxRibbonControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRibbonControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, wxRibbonControl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, wxRibbonControl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxRibbonControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, SetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, GetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, GetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, IsSizingContinuous)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, IsSizingContinuous)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSizingContinuous();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, GetNextSmallerSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, GetNextSmallerSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextSmallerSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, GetNextSmallerSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative_to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, GetNextSmallerSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//int relative_to = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextSmallerSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, GetNextLargerSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, GetNextLargerSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextLargerSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, GetNextLargerSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative_to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, GetNextLargerSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//int relative_to = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextLargerSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, Realize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, Realise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, Realise)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Realise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, GetAncestorRibbonBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, GetAncestorRibbonBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAncestorRibbonBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, GetBestSizeForParentSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, GetBestSizeForParentSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parentSize = arg.GetNumber(0)
	//pThis->GetEntity()->GetBestSizeForParentSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, DoGetNextSmallerSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative_to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, DoGetNextSmallerSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//int relative_to = arg.GetNumber(1)
	//pThis->GetEntity()->DoGetNextSmallerSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonControl, DoGetNextLargerSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative_to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, DoGetNextLargerSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//int relative_to = arg.GetNumber(1)
	//pThis->GetEntity()->DoGetNextLargerSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonControl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonControl)
{
	Gura_AssignMethod(wx_RibbonControl, wxRibbonControl);
	Gura_AssignMethod(wx_RibbonControl, wxRibbonControl_1);
	Gura_AssignMethod(wx_RibbonControl, SetArtProvider);
	Gura_AssignMethod(wx_RibbonControl, GetArtProvider);
	Gura_AssignMethod(wx_RibbonControl, IsSizingContinuous);
	Gura_AssignMethod(wx_RibbonControl, GetNextSmallerSize);
	Gura_AssignMethod(wx_RibbonControl, GetNextSmallerSize_1);
	Gura_AssignMethod(wx_RibbonControl, GetNextLargerSize);
	Gura_AssignMethod(wx_RibbonControl, GetNextLargerSize_1);
	Gura_AssignMethod(wx_RibbonControl, Realize);
	Gura_AssignMethod(wx_RibbonControl, Realise);
	Gura_AssignMethod(wx_RibbonControl, GetAncestorRibbonBar);
	Gura_AssignMethod(wx_RibbonControl, GetBestSizeForParentSize);
	Gura_AssignMethod(wx_RibbonControl, DoGetNextSmallerSize);
	Gura_AssignMethod(wx_RibbonControl, DoGetNextLargerSize);
}

Gura_ImplementDescendantCreator(wx_RibbonControl)
{
	return new Object_wx_RibbonControl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
