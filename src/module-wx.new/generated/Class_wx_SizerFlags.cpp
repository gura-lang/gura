//----------------------------------------------------------------------------
// wxSizerFlags
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSizerFlags
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSizerFlags
//----------------------------------------------------------------------------
Object_wx_SizerFlags::~Object_wx_SizerFlags()
{
}

Object *Object_wx_SizerFlags::Clone() const
{
	return nullptr;
}

String Object_wx_SizerFlags::ToString(bool exprFlag)
{
	String rtn("<wx.SizerFlags:");
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
Gura_DeclareFunctionAlias(__SizerFlags, "SizerFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SizerFlags));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SizerFlags)
{
	//int proportion = arg.GetNumber(0)
	//wxSizerFlags();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SizerFlags, __Align, "Align")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, __Align)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->Align();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Border, "Border")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "borderinpixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, __Border)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//int borderinpixels = arg.GetNumber(1)
	//pThis->GetEntity()->Border();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Border_1, "Border_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, __Border_1)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Border();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Bottom, "Bottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __Bottom)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Bottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Center, "Center")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __Center)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Center();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Centre, "Centre")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __Centre)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Centre();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __CenterHorizontal, "CenterHorizontal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __CenterHorizontal)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CenterHorizontal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __CenterVertical, "CenterVertical")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __CenterVertical)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CenterVertical();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __CentreHorizontal, "CentreHorizontal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __CentreHorizontal)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CentreHorizontal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __CentreVertical, "CentreVertical")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __CentreVertical)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CentreVertical();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __DoubleBorder, "DoubleBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, __DoubleBorder)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->DoubleBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __DoubleHorzBorder, "DoubleHorzBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __DoubleHorzBorder)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoubleHorzBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Expand, "Expand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __Expand)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __FixedMinSize, "FixedMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __FixedMinSize)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FixedMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __ReserveSpaceEvenIfHidden, "ReserveSpaceEvenIfHidden")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __ReserveSpaceEvenIfHidden)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReserveSpaceEvenIfHidden();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __GetDefaultBorder, "GetDefaultBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __GetDefaultBorder)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Left, "Left")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __Left)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Left();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Proportion, "Proportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, __Proportion)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int proportion = arg.GetNumber(0)
	//pThis->GetEntity()->Proportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Right, "Right")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __Right)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Right();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Shaped, "Shaped")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __Shaped)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Shaped();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __Top, "Top")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, __Top)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Top();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerFlags, __TripleBorder, "TripleBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, __TripleBorder)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->TripleBorder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizerFlags
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizerFlags)
{
	// Constructor assignment
	Gura_AssignFunction(__SizerFlags);
	// Method assignment
	Gura_AssignMethod(wx_SizerFlags, __Align);
	Gura_AssignMethod(wx_SizerFlags, __Border);
	Gura_AssignMethod(wx_SizerFlags, __Border_1);
	Gura_AssignMethod(wx_SizerFlags, __Bottom);
	Gura_AssignMethod(wx_SizerFlags, __Center);
	Gura_AssignMethod(wx_SizerFlags, __Centre);
	Gura_AssignMethod(wx_SizerFlags, __CenterHorizontal);
	Gura_AssignMethod(wx_SizerFlags, __CenterVertical);
	Gura_AssignMethod(wx_SizerFlags, __CentreHorizontal);
	Gura_AssignMethod(wx_SizerFlags, __CentreVertical);
	Gura_AssignMethod(wx_SizerFlags, __DoubleBorder);
	Gura_AssignMethod(wx_SizerFlags, __DoubleHorzBorder);
	Gura_AssignMethod(wx_SizerFlags, __Expand);
	Gura_AssignMethod(wx_SizerFlags, __FixedMinSize);
	Gura_AssignMethod(wx_SizerFlags, __ReserveSpaceEvenIfHidden);
	Gura_AssignMethod(wx_SizerFlags, __GetDefaultBorder);
	Gura_AssignMethod(wx_SizerFlags, __Left);
	Gura_AssignMethod(wx_SizerFlags, __Proportion);
	Gura_AssignMethod(wx_SizerFlags, __Right);
	Gura_AssignMethod(wx_SizerFlags, __Shaped);
	Gura_AssignMethod(wx_SizerFlags, __Top);
	Gura_AssignMethod(wx_SizerFlags, __TripleBorder);
}

Gura_ImplementDescendantCreator(wx_SizerFlags)
{
	return new Object_wx_SizerFlags((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
