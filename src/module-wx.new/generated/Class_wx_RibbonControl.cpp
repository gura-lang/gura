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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RibbonControl, "RibbonControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RibbonControl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonControl)
{
	//wxRibbonControl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RibbonControl_1, "RibbonControl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonControl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonControl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxValidator& validator = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxRibbonControl(parent, id, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonControl, __SetArtProvider, "SetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, __SetArtProvider)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonArtProvider* art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider(art);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __GetArtProvider, "GetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, __GetArtProvider)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonArtProvider* _rtn = pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __IsSizingContinuous, "IsSizingContinuous")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, __IsSizingContinuous)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsSizingContinuous();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __GetNextSmallerSize, "GetNextSmallerSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, __GetNextSmallerSize)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOrientation direction = arg.GetNumber(0)
	//wxSize _rtn = pThis->GetEntity()->GetNextSmallerSize(direction);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __GetNextSmallerSize_1, "GetNextSmallerSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative_to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, __GetNextSmallerSize_1)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOrientation direction = arg.GetNumber(0)
	//wxSize relative_to = arg.GetNumber(1)
	//wxSize _rtn = pThis->GetEntity()->GetNextSmallerSize(direction, relative_to);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __GetNextLargerSize, "GetNextLargerSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, __GetNextLargerSize)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOrientation direction = arg.GetNumber(0)
	//wxSize _rtn = pThis->GetEntity()->GetNextLargerSize(direction);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __GetNextLargerSize_1, "GetNextLargerSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative_to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, __GetNextLargerSize_1)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOrientation direction = arg.GetNumber(0)
	//wxSize relative_to = arg.GetNumber(1)
	//wxSize _rtn = pThis->GetEntity()->GetNextLargerSize(direction, relative_to);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, __Realize)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __Realise, "Realise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, __Realise)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Realise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __GetAncestorRibbonBar, "GetAncestorRibbonBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonControl, __GetAncestorRibbonBar)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonBar* _rtn = pThis->GetEntity()->GetAncestorRibbonBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __GetBestSizeForParentSize, "GetBestSizeForParentSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, __GetBestSizeForParentSize)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& parentSize = arg.GetNumber(0)
	//wxSize _rtn = pThis->GetEntity()->GetBestSizeForParentSize(parentSize);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __DoGetNextSmallerSize, "DoGetNextSmallerSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative_to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, __DoGetNextSmallerSize)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOrientation direction = arg.GetNumber(0)
	//wxSize relative_to = arg.GetNumber(1)
	//wxSize _rtn = pThis->GetEntity()->DoGetNextSmallerSize(direction, relative_to);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonControl, __DoGetNextLargerSize, "DoGetNextLargerSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative_to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonControl, __DoGetNextLargerSize)
{
	Object_wx_RibbonControl *pThis = Object_wx_RibbonControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOrientation direction = arg.GetNumber(0)
	//wxSize relative_to = arg.GetNumber(1)
	//wxSize _rtn = pThis->GetEntity()->DoGetNextLargerSize(direction, relative_to);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonControl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonControl)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonControl);
	Gura_AssignFunction(__RibbonControl_1);
	// Method assignment
	Gura_AssignMethod(wx_RibbonControl, __SetArtProvider);
	Gura_AssignMethod(wx_RibbonControl, __GetArtProvider);
	Gura_AssignMethod(wx_RibbonControl, __IsSizingContinuous);
	Gura_AssignMethod(wx_RibbonControl, __GetNextSmallerSize);
	Gura_AssignMethod(wx_RibbonControl, __GetNextSmallerSize_1);
	Gura_AssignMethod(wx_RibbonControl, __GetNextLargerSize);
	Gura_AssignMethod(wx_RibbonControl, __GetNextLargerSize_1);
	Gura_AssignMethod(wx_RibbonControl, __Realize);
	Gura_AssignMethod(wx_RibbonControl, __Realise);
	Gura_AssignMethod(wx_RibbonControl, __GetAncestorRibbonBar);
	Gura_AssignMethod(wx_RibbonControl, __GetBestSizeForParentSize);
	Gura_AssignMethod(wx_RibbonControl, __DoGetNextSmallerSize);
	Gura_AssignMethod(wx_RibbonControl, __DoGetNextLargerSize);
}

Gura_ImplementDescendantCreator(wx_RibbonControl)
{
	return new Object_wx_RibbonControl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
