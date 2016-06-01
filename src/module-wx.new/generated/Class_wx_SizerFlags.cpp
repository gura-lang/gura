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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_SizerFlags, wxSizerFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, wxSizerFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int proportion = arg.GetNumber(0)
	//pThis->GetEntity()->wxSizerFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Align)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, Align)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->Align();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Border)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "borderinpixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, Border)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//int borderinpixels = arg.GetNumber(1)
	//pThis->GetEntity()->Border();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Border_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, Border_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Border();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Bottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, Bottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Bottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Center)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, Center)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Center();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Centre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, Centre)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Centre();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, CenterHorizontal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, CenterHorizontal)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CenterHorizontal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, CenterVertical)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, CenterVertical)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CenterVertical();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, CentreHorizontal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, CentreHorizontal)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CentreHorizontal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, CentreVertical)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, CentreVertical)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CentreVertical();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, DoubleBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, DoubleBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->DoubleBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, DoubleHorzBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, DoubleHorzBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DoubleHorzBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Expand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, Expand)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, FixedMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, FixedMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->FixedMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, ReserveSpaceEvenIfHidden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, ReserveSpaceEvenIfHidden)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ReserveSpaceEvenIfHidden();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, GetDefaultBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, GetDefaultBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Left)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, Left)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Left();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Proportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, Proportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int proportion = arg.GetNumber(0)
	//pThis->GetEntity()->Proportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Right)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, Right)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Right();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Shaped)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, Shaped)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Shaped();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, Top)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerFlags, Top)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Top();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerFlags, TripleBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerFlags, TripleBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->TripleBorder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizerFlags
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizerFlags)
{
	Gura_AssignMethod(wx_SizerFlags, wxSizerFlags);
	Gura_AssignMethod(wx_SizerFlags, Align);
	Gura_AssignMethod(wx_SizerFlags, Border);
	Gura_AssignMethod(wx_SizerFlags, Border_1);
	Gura_AssignMethod(wx_SizerFlags, Bottom);
	Gura_AssignMethod(wx_SizerFlags, Center);
	Gura_AssignMethod(wx_SizerFlags, Centre);
	Gura_AssignMethod(wx_SizerFlags, CenterHorizontal);
	Gura_AssignMethod(wx_SizerFlags, CenterVertical);
	Gura_AssignMethod(wx_SizerFlags, CentreHorizontal);
	Gura_AssignMethod(wx_SizerFlags, CentreVertical);
	Gura_AssignMethod(wx_SizerFlags, DoubleBorder);
	Gura_AssignMethod(wx_SizerFlags, DoubleHorzBorder);
	Gura_AssignMethod(wx_SizerFlags, Expand);
	Gura_AssignMethod(wx_SizerFlags, FixedMinSize);
	Gura_AssignMethod(wx_SizerFlags, ReserveSpaceEvenIfHidden);
	Gura_AssignMethod(wx_SizerFlags, GetDefaultBorder);
	Gura_AssignMethod(wx_SizerFlags, Left);
	Gura_AssignMethod(wx_SizerFlags, Proportion);
	Gura_AssignMethod(wx_SizerFlags, Right);
	Gura_AssignMethod(wx_SizerFlags, Shaped);
	Gura_AssignMethod(wx_SizerFlags, Top);
	Gura_AssignMethod(wx_SizerFlags, TripleBorder);
}

Gura_ImplementDescendantCreator(wx_SizerFlags)
{
	return new Object_wx_SizerFlags((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
