//----------------------------------------------------------------------------
// wxSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSizer
//----------------------------------------------------------------------------
Object_wx_Sizer::~Object_wx_Sizer()
{
}

Object *Object_wx_Sizer::Clone() const
{
	return nullptr;
}

String Object_wx_Sizer::ToString(bool exprFlag)
{
	String rtn("<wx.Sizer:");
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
Gura_DeclareFunctionAlias(__Sizer, "Sizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Sizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Sizer)
{
	//wxSizer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Sizer, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Add)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxSizerFlags& flags = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Add_1, "Add_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Add_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//wxObject* userData = arg.GetNumber(4)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Add_2, "Add_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Add_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//const wxSizerFlags& flags = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Add_3, "Add_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Add_3)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//wxObject* userData = arg.GetNumber(4)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Add_4, "Add_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Add_4)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//wxObject* userData = arg.GetNumber(5)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Add_5, "Add_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Add_5)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//const wxSizerFlags& flags = arg.GetNumber(2)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Add_6, "Add_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Add_6)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizerItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __AddSpacer, "AddSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __AddSpacer)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->AddSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __AddStretchSpacer, "AddStretchSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __AddStretchSpacer)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->AddStretchSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __CalcMin, "CalcMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __CalcMin)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "delete_windows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Clear)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool delete_windows = arg.GetNumber(0)
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __ComputeFittingClientSize, "ComputeFittingClientSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __ComputeFittingClientSize)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->ComputeFittingClientSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __ComputeFittingWindowSize, "ComputeFittingWindowSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __ComputeFittingWindowSize)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->ComputeFittingWindowSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Detach, "Detach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Detach)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Detach_1, "Detach_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Detach_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Detach_2, "Detach_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Detach_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Fit, "Fit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Fit)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->Fit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __FitInside, "FitInside")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __FitInside)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->FitInside();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __InformFirstDirection, "InformFirstDirection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableOtherDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __InformFirstDirection)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int availableOtherDir = arg.GetNumber(2)
	//pThis->GetEntity()->InformFirstDirection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetChildren, "GetChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __GetChildren)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetChildren_1, "GetChildren_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __GetChildren_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetContainingWindow, "GetContainingWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __GetContainingWindow)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainingWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetContainingWindow, "SetContainingWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetContainingWindow)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainingWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetItemCount, "GetItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __GetItemCount)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetItem, "GetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __GetItem)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//bool recursive = arg.GetNumber(1)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetItem_1, "GetItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __GetItem_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//bool recursive = arg.GetNumber(1)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetItem_2, "GetItem_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __GetItem_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetItemById, "GetItemById")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __GetItemById)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//bool recursive = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemById();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetMinSize, "GetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __GetMinSize)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __GetPosition)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __GetSize)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Hide, "Hide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Hide)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//bool recursive = arg.GetNumber(1)
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Hide_1, "Hide_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Hide_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//bool recursive = arg.GetNumber(1)
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Hide_2, "Hide_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Hide_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Insert)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//wxWindow* window = arg.GetNumber(1)
	//const wxSizerFlags& flags = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Insert_1, "Insert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Insert_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//wxWindow* window = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//wxObject* userData = arg.GetNumber(5)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Insert_2, "Insert_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Insert_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//wxSizer* sizer = arg.GetNumber(1)
	//const wxSizerFlags& flags = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Insert_3, "Insert_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Insert_3)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//wxSizer* sizer = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//wxObject* userData = arg.GetNumber(5)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Insert_4, "Insert_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Insert_4)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//int proportion = arg.GetNumber(3)
	//int flag = arg.GetNumber(4)
	//int border = arg.GetNumber(5)
	//wxObject* userData = arg.GetNumber(6)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Insert_5, "Insert_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Insert_5)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//const wxSizerFlags& flags = arg.GetNumber(3)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Insert_6, "Insert_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Insert_6)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//wxSizerItem* item = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __InsertSpacer, "InsertSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __InsertSpacer)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->InsertSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __InsertStretchSpacer, "InsertStretchSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __InsertStretchSpacer)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//int prop = arg.GetNumber(1)
	//pThis->GetEntity()->InsertStretchSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __IsEmpty)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __IsShown, "IsShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __IsShown)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __IsShown_1, "IsShown_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __IsShown_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __IsShown_2, "IsShown_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __IsShown_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __Layout)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Prepend, "Prepend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Prepend)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxSizerFlags& flags = arg.GetNumber(1)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Prepend_1, "Prepend_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Prepend_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//wxObject* userData = arg.GetNumber(4)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Prepend_2, "Prepend_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Prepend_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//const wxSizerFlags& flags = arg.GetNumber(1)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Prepend_3, "Prepend_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Prepend_3)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//wxObject* userData = arg.GetNumber(4)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Prepend_4, "Prepend_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Prepend_4)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//wxObject* userData = arg.GetNumber(5)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Prepend_5, "Prepend_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Prepend_5)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//const wxSizerFlags& flags = arg.GetNumber(2)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Prepend_6, "Prepend_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Prepend_6)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizerItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __PrependSpacer, "PrependSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __PrependSpacer)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->PrependSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __PrependStretchSpacer, "PrependStretchSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __PrependStretchSpacer)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->PrependStretchSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __RecalcSizes, "RecalcSizes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, __RecalcSizes)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Remove)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Remove_1, "Remove_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Remove_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Remove_2, "Remove_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Remove_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Replace, "Replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldwin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newwin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Replace)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* oldwin = arg.GetNumber(0)
	//wxWindow* newwin = arg.GetNumber(1)
	//bool recursive = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Replace_1, "Replace_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldsz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newsz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Replace_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* oldsz = arg.GetNumber(0)
	//wxSizer* newsz = arg.GetNumber(1)
	//bool recursive = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Replace_2, "Replace_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newitem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Replace_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//wxSizerItem* newitem = arg.GetNumber(1)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetDimension, "SetDimension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetDimension)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->SetDimension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetDimension_1, "SetDimension_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetDimension_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pos = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//pThis->GetEntity()->SetDimension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetItemMinSize, "SetItemMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetItemMinSize)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetItemMinSize_1, "SetItemMinSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetItemMinSize_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetItemMinSize_2, "SetItemMinSize_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetItemMinSize_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetItemMinSize_3, "SetItemMinSize_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetItemMinSize_3)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetItemMinSize_4, "SetItemMinSize_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetItemMinSize_4)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetItemMinSize_5, "SetItemMinSize_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetItemMinSize_5)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetMinSize, "SetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetMinSize)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetMinSize_1, "SetMinSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetMinSize_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetSizeHints, "SetSizeHints")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetSizeHints)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->SetSizeHints();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __SetVirtualSizeHints, "SetVirtualSizeHints")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __SetVirtualSizeHints)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->SetVirtualSizeHints();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Show)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//bool show = arg.GetNumber(1)
	//bool recursive = arg.GetNumber(2)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Show_1, "Show_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Show_1)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//bool show = arg.GetNumber(1)
	//bool recursive = arg.GetNumber(2)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __Show_2, "Show_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __Show_2)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//bool show = arg.GetNumber(1)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sizer, __ShowItems, "ShowItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, __ShowItems)
{
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowItems();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Sizer)
{
	// Constructor assignment
	Gura_AssignFunction(__Sizer);
	// Method assignment
	Gura_AssignMethod(wx_Sizer, __Add);
	Gura_AssignMethod(wx_Sizer, __Add_1);
	Gura_AssignMethod(wx_Sizer, __Add_2);
	Gura_AssignMethod(wx_Sizer, __Add_3);
	Gura_AssignMethod(wx_Sizer, __Add_4);
	Gura_AssignMethod(wx_Sizer, __Add_5);
	Gura_AssignMethod(wx_Sizer, __Add_6);
	Gura_AssignMethod(wx_Sizer, __AddSpacer);
	Gura_AssignMethod(wx_Sizer, __AddStretchSpacer);
	Gura_AssignMethod(wx_Sizer, __CalcMin);
	Gura_AssignMethod(wx_Sizer, __Clear);
	Gura_AssignMethod(wx_Sizer, __ComputeFittingClientSize);
	Gura_AssignMethod(wx_Sizer, __ComputeFittingWindowSize);
	Gura_AssignMethod(wx_Sizer, __Detach);
	Gura_AssignMethod(wx_Sizer, __Detach_1);
	Gura_AssignMethod(wx_Sizer, __Detach_2);
	Gura_AssignMethod(wx_Sizer, __Fit);
	Gura_AssignMethod(wx_Sizer, __FitInside);
	Gura_AssignMethod(wx_Sizer, __InformFirstDirection);
	Gura_AssignMethod(wx_Sizer, __GetChildren);
	Gura_AssignMethod(wx_Sizer, __GetChildren_1);
	Gura_AssignMethod(wx_Sizer, __GetContainingWindow);
	Gura_AssignMethod(wx_Sizer, __SetContainingWindow);
	Gura_AssignMethod(wx_Sizer, __GetItemCount);
	Gura_AssignMethod(wx_Sizer, __GetItem);
	Gura_AssignMethod(wx_Sizer, __GetItem_1);
	Gura_AssignMethod(wx_Sizer, __GetItem_2);
	Gura_AssignMethod(wx_Sizer, __GetItemById);
	Gura_AssignMethod(wx_Sizer, __GetMinSize);
	Gura_AssignMethod(wx_Sizer, __GetPosition);
	Gura_AssignMethod(wx_Sizer, __GetSize);
	Gura_AssignMethod(wx_Sizer, __Hide);
	Gura_AssignMethod(wx_Sizer, __Hide_1);
	Gura_AssignMethod(wx_Sizer, __Hide_2);
	Gura_AssignMethod(wx_Sizer, __Insert);
	Gura_AssignMethod(wx_Sizer, __Insert_1);
	Gura_AssignMethod(wx_Sizer, __Insert_2);
	Gura_AssignMethod(wx_Sizer, __Insert_3);
	Gura_AssignMethod(wx_Sizer, __Insert_4);
	Gura_AssignMethod(wx_Sizer, __Insert_5);
	Gura_AssignMethod(wx_Sizer, __Insert_6);
	Gura_AssignMethod(wx_Sizer, __InsertSpacer);
	Gura_AssignMethod(wx_Sizer, __InsertStretchSpacer);
	Gura_AssignMethod(wx_Sizer, __IsEmpty);
	Gura_AssignMethod(wx_Sizer, __IsShown);
	Gura_AssignMethod(wx_Sizer, __IsShown_1);
	Gura_AssignMethod(wx_Sizer, __IsShown_2);
	Gura_AssignMethod(wx_Sizer, __Layout);
	Gura_AssignMethod(wx_Sizer, __Prepend);
	Gura_AssignMethod(wx_Sizer, __Prepend_1);
	Gura_AssignMethod(wx_Sizer, __Prepend_2);
	Gura_AssignMethod(wx_Sizer, __Prepend_3);
	Gura_AssignMethod(wx_Sizer, __Prepend_4);
	Gura_AssignMethod(wx_Sizer, __Prepend_5);
	Gura_AssignMethod(wx_Sizer, __Prepend_6);
	Gura_AssignMethod(wx_Sizer, __PrependSpacer);
	Gura_AssignMethod(wx_Sizer, __PrependStretchSpacer);
	Gura_AssignMethod(wx_Sizer, __RecalcSizes);
	Gura_AssignMethod(wx_Sizer, __Remove);
	Gura_AssignMethod(wx_Sizer, __Remove_1);
	Gura_AssignMethod(wx_Sizer, __Remove_2);
	Gura_AssignMethod(wx_Sizer, __Replace);
	Gura_AssignMethod(wx_Sizer, __Replace_1);
	Gura_AssignMethod(wx_Sizer, __Replace_2);
	Gura_AssignMethod(wx_Sizer, __SetDimension);
	Gura_AssignMethod(wx_Sizer, __SetDimension_1);
	Gura_AssignMethod(wx_Sizer, __SetItemMinSize);
	Gura_AssignMethod(wx_Sizer, __SetItemMinSize_1);
	Gura_AssignMethod(wx_Sizer, __SetItemMinSize_2);
	Gura_AssignMethod(wx_Sizer, __SetItemMinSize_3);
	Gura_AssignMethod(wx_Sizer, __SetItemMinSize_4);
	Gura_AssignMethod(wx_Sizer, __SetItemMinSize_5);
	Gura_AssignMethod(wx_Sizer, __SetMinSize);
	Gura_AssignMethod(wx_Sizer, __SetMinSize_1);
	Gura_AssignMethod(wx_Sizer, __SetSizeHints);
	Gura_AssignMethod(wx_Sizer, __SetVirtualSizeHints);
	Gura_AssignMethod(wx_Sizer, __Show);
	Gura_AssignMethod(wx_Sizer, __Show_1);
	Gura_AssignMethod(wx_Sizer, __Show_2);
	Gura_AssignMethod(wx_Sizer, __ShowItems);
}

Gura_ImplementDescendantCreator(wx_Sizer)
{
	return new Object_wx_Sizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
