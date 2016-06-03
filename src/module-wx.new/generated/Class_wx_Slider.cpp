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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxSlider, "wxSlider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxSlider)
{
	//wxSlider();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxSlider_1, "wxSlider_1")
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

Gura_ImplementFunction(__wxSlider_1)
{
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
	//wxSlider();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Slider, __ClearSel, "ClearSel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __ClearSel)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearSel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __ClearTicks, "ClearTicks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __ClearTicks)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTicks();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __Create, "Create")
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

Gura_ImplementMethod(wx_Slider, __Create)
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

Gura_DeclareMethodAlias(wx_Slider, __GetLineSize, "GetLineSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __GetLineSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __GetMax, "GetMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __GetMax)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __GetMin, "GetMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __GetMin)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __GetPageSize, "GetPageSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __GetPageSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __GetSelEnd, "GetSelEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __GetSelEnd)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __GetSelStart, "GetSelStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __GetSelStart)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __GetThumbLength, "GetThumbLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __GetThumbLength)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetThumbLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __GetTickFreq, "GetTickFreq")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __GetTickFreq)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTickFreq();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, __GetValue)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetLineSize, "SetLineSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetLineSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetLineSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetMin, "SetMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetMin)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minValue = arg.GetNumber(0)
	//pThis->GetEntity()->SetMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetMax, "SetMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetMax)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maxValue = arg.GetNumber(0)
	//pThis->GetEntity()->SetMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetPageSize, "SetPageSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetPageSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPageSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetRange)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minValue = arg.GetNumber(0)
	//int maxValue = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetSelection)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetThumbLength, "SetThumbLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetThumbLength)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetTick, "SetTick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tickPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetTick)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tickPos = arg.GetNumber(0)
	//pThis->GetEntity()->SetTick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetTickFreq, "SetTickFreq")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetTickFreq)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetTickFreq();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Slider, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, __SetValue)
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
	// Constructor assignment
	Gura_AssignFunction(__wxSlider);
	Gura_AssignFunction(__wxSlider_1);
	// Method assignment
	Gura_AssignMethod(wx_Slider, __ClearSel);
	Gura_AssignMethod(wx_Slider, __ClearTicks);
	Gura_AssignMethod(wx_Slider, __Create);
	Gura_AssignMethod(wx_Slider, __GetLineSize);
	Gura_AssignMethod(wx_Slider, __GetMax);
	Gura_AssignMethod(wx_Slider, __GetMin);
	Gura_AssignMethod(wx_Slider, __GetPageSize);
	Gura_AssignMethod(wx_Slider, __GetSelEnd);
	Gura_AssignMethod(wx_Slider, __GetSelStart);
	Gura_AssignMethod(wx_Slider, __GetThumbLength);
	Gura_AssignMethod(wx_Slider, __GetTickFreq);
	Gura_AssignMethod(wx_Slider, __GetValue);
	Gura_AssignMethod(wx_Slider, __SetLineSize);
	Gura_AssignMethod(wx_Slider, __SetMin);
	Gura_AssignMethod(wx_Slider, __SetMax);
	Gura_AssignMethod(wx_Slider, __SetPageSize);
	Gura_AssignMethod(wx_Slider, __SetRange);
	Gura_AssignMethod(wx_Slider, __SetSelection);
	Gura_AssignMethod(wx_Slider, __SetThumbLength);
	Gura_AssignMethod(wx_Slider, __SetTick);
	Gura_AssignMethod(wx_Slider, __SetTickFreq);
	Gura_AssignMethod(wx_Slider, __SetValue);
}

Gura_ImplementDescendantCreator(wx_Slider)
{
	return new Object_wx_Slider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
