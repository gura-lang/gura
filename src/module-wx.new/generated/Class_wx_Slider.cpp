//----------------------------------------------------------------------------
// wxSlider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSlider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSlider
//----------------------------------------------------------------------------
Object_wx_Slider::~Object_wx_Slider()
{
}

Object *Object_wx_Slider::Clone() const
{
	return nullptr;
}

String Object_wx_Slider::ToString(bool exprFlag)
{
	String rtn("<wx.Slider:");
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
Gura_DeclareMethod(wx_Slider, wxSlider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, wxSlider)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSlider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, wxSlider_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, wxSlider_1)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int minValue = arg.GetNumber(3)
	//int maxValue = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//int size = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->wxSlider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, ClearSel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, ClearSel)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearSel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, ClearTicks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, ClearTicks)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTicks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, Create)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int minValue = arg.GetNumber(3)
	//int maxValue = arg.GetNumber(4)
	//int point = arg.GetNumber(5)
	//int size = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, GetLineSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, GetLineSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, GetMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, GetMax)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, GetMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, GetMin)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, GetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, GetPageSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, GetSelEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, GetSelEnd)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, GetSelStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, GetSelStart)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, GetThumbLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, GetThumbLength)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetThumbLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, GetTickFreq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, GetTickFreq)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTickFreq();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, GetValue)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetLineSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetLineSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetLineSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetMin)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minValue = arg.GetNumber(0)
	//pThis->GetEntity()->SetMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetMax)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maxValue = arg.GetNumber(0)
	//pThis->GetEntity()->SetMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetPageSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPageSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetRange)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minValue = arg.GetNumber(0)
	//int maxValue = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetSelection)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetThumbLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetThumbLength)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetTick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tickPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetTick)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tickPos = arg.GetNumber(0)
	//pThis->GetEntity()->SetTick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetTickFreq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetTickFreq)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetTickFreq();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Slider, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetValue)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSlider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Slider)
{
	Gura_AssignMethod(wx_Slider, wxSlider);
	Gura_AssignMethod(wx_Slider, wxSlider_1);
	Gura_AssignMethod(wx_Slider, ClearSel);
	Gura_AssignMethod(wx_Slider, ClearTicks);
	Gura_AssignMethod(wx_Slider, Create);
	Gura_AssignMethod(wx_Slider, GetLineSize);
	Gura_AssignMethod(wx_Slider, GetMax);
	Gura_AssignMethod(wx_Slider, GetMin);
	Gura_AssignMethod(wx_Slider, GetPageSize);
	Gura_AssignMethod(wx_Slider, GetSelEnd);
	Gura_AssignMethod(wx_Slider, GetSelStart);
	Gura_AssignMethod(wx_Slider, GetThumbLength);
	Gura_AssignMethod(wx_Slider, GetTickFreq);
	Gura_AssignMethod(wx_Slider, GetValue);
	Gura_AssignMethod(wx_Slider, SetLineSize);
	Gura_AssignMethod(wx_Slider, SetMin);
	Gura_AssignMethod(wx_Slider, SetMax);
	Gura_AssignMethod(wx_Slider, SetPageSize);
	Gura_AssignMethod(wx_Slider, SetRange);
	Gura_AssignMethod(wx_Slider, SetSelection);
	Gura_AssignMethod(wx_Slider, SetThumbLength);
	Gura_AssignMethod(wx_Slider, SetTick);
	Gura_AssignMethod(wx_Slider, SetTickFreq);
	Gura_AssignMethod(wx_Slider, SetValue);
}

Gura_ImplementDescendantCreator(wx_Slider)
{
	return new Object_wx_Slider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
