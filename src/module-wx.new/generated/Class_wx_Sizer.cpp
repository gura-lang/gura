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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Sizer, wxSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, wxSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, ~wxSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, ~wxSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Add_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Add_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Add_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Add_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Add_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Add_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//int userData = arg.GetNumber(5)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Add_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Add_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Add_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Add_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, AddSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, AddSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->AddSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, AddStretchSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, AddStretchSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->AddStretchSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "delete_windows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int delete_windows = arg.GetNumber(0)
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, ComputeFittingClientSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, ComputeFittingClientSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->ComputeFittingClientSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, ComputeFittingWindowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, ComputeFittingWindowSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->ComputeFittingWindowSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Detach)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Detach_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Detach_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Detach_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Detach_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Fit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Fit)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->Fit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, FitInside)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, FitInside)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->FitInside();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, InformFirstDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableOtherDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, InformFirstDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int availableOtherDir = arg.GetNumber(2)
	//pThis->GetEntity()->InformFirstDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, GetChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetChildren_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, GetChildren_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetContainingWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, GetContainingWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetContainingWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetContainingWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetContainingWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainingWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, GetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int recursive = arg.GetNumber(1)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, GetItem_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int recursive = arg.GetNumber(1)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetItem_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, GetItem_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetItemById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, GetItemById)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int recursive = arg.GetNumber(1)
	//pThis->GetEntity()->GetItemById();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, GetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Hide)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int recursive = arg.GetNumber(1)
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Hide_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Hide_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int recursive = arg.GetNumber(1)
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Hide_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Hide_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Insert_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//int userData = arg.GetNumber(5)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Insert_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int sizer = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Insert_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Insert_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int sizer = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//int userData = arg.GetNumber(5)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Insert_4)
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

Gura_ImplementMethod(wx_Sizer, Insert_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//int proportion = arg.GetNumber(3)
	//int flag = arg.GetNumber(4)
	//int border = arg.GetNumber(5)
	//int userData = arg.GetNumber(6)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Insert_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Insert_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Insert_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Insert_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, InsertSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, InsertSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->InsertSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, InsertStretchSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, InsertStretchSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int prop = arg.GetNumber(1)
	//pThis->GetEntity()->InsertStretchSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, IsShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, IsShown_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, IsShown_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, IsShown_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, IsShown_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, Layout)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Prepend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Prepend)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Prepend_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Prepend_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Prepend_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Prepend_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Prepend_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Prepend_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Prepend_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Prepend_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//int userData = arg.GetNumber(5)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Prepend_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Prepend_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Prepend_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Prepend_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, PrependSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, PrependSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->PrependSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, PrependStretchSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, PrependStretchSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->PrependStretchSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, RecalcSizes)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Remove_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Remove_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Remove_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Remove_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldwin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newwin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Replace)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int oldwin = arg.GetNumber(0)
	//int newwin = arg.GetNumber(1)
	//int recursive = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Replace_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldsz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newsz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Replace_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int oldsz = arg.GetNumber(0)
	//int newsz = arg.GetNumber(1)
	//int recursive = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Replace_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newitem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Replace_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int newitem = arg.GetNumber(1)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetDimension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetDimension)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->SetDimension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetDimension_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetDimension_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->SetDimension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetItemMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetItemMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetItemMinSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetItemMinSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetItemMinSize_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetItemMinSize_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetItemMinSize_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetItemMinSize_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetItemMinSize_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetItemMinSize_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetItemMinSize_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetItemMinSize_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetMinSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetMinSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetSizeHints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetSizeHints)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetSizeHints();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetVirtualSizeHints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetVirtualSizeHints)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetVirtualSizeHints();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//int recursive = arg.GetNumber(2)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Show_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Show_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//int recursive = arg.GetNumber(2)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Show_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, Show_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, ShowItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, ShowItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowItems();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Sizer)
{
	Gura_AssignMethod(wx_Sizer, wxSizer);
	Gura_AssignMethod(wx_Sizer, ~wxSizer);
	Gura_AssignMethod(wx_Sizer, Add);
	Gura_AssignMethod(wx_Sizer, Add_1);
	Gura_AssignMethod(wx_Sizer, Add_2);
	Gura_AssignMethod(wx_Sizer, Add_3);
	Gura_AssignMethod(wx_Sizer, Add_4);
	Gura_AssignMethod(wx_Sizer, Add_5);
	Gura_AssignMethod(wx_Sizer, Add_6);
	Gura_AssignMethod(wx_Sizer, AddSpacer);
	Gura_AssignMethod(wx_Sizer, AddStretchSpacer);
	Gura_AssignMethod(wx_Sizer, CalcMin);
	Gura_AssignMethod(wx_Sizer, Clear);
	Gura_AssignMethod(wx_Sizer, ComputeFittingClientSize);
	Gura_AssignMethod(wx_Sizer, ComputeFittingWindowSize);
	Gura_AssignMethod(wx_Sizer, Detach);
	Gura_AssignMethod(wx_Sizer, Detach_1);
	Gura_AssignMethod(wx_Sizer, Detach_2);
	Gura_AssignMethod(wx_Sizer, Fit);
	Gura_AssignMethod(wx_Sizer, FitInside);
	Gura_AssignMethod(wx_Sizer, InformFirstDirection);
	Gura_AssignMethod(wx_Sizer, GetChildren);
	Gura_AssignMethod(wx_Sizer, GetChildren_1);
	Gura_AssignMethod(wx_Sizer, GetContainingWindow);
	Gura_AssignMethod(wx_Sizer, SetContainingWindow);
	Gura_AssignMethod(wx_Sizer, GetItemCount);
	Gura_AssignMethod(wx_Sizer, GetItem);
	Gura_AssignMethod(wx_Sizer, GetItem_1);
	Gura_AssignMethod(wx_Sizer, GetItem_2);
	Gura_AssignMethod(wx_Sizer, GetItemById);
	Gura_AssignMethod(wx_Sizer, GetMinSize);
	Gura_AssignMethod(wx_Sizer, GetPosition);
	Gura_AssignMethod(wx_Sizer, GetSize);
	Gura_AssignMethod(wx_Sizer, Hide);
	Gura_AssignMethod(wx_Sizer, Hide_1);
	Gura_AssignMethod(wx_Sizer, Hide_2);
	Gura_AssignMethod(wx_Sizer, Insert);
	Gura_AssignMethod(wx_Sizer, Insert_1);
	Gura_AssignMethod(wx_Sizer, Insert_2);
	Gura_AssignMethod(wx_Sizer, Insert_3);
	Gura_AssignMethod(wx_Sizer, Insert_4);
	Gura_AssignMethod(wx_Sizer, Insert_5);
	Gura_AssignMethod(wx_Sizer, Insert_6);
	Gura_AssignMethod(wx_Sizer, InsertSpacer);
	Gura_AssignMethod(wx_Sizer, InsertStretchSpacer);
	Gura_AssignMethod(wx_Sizer, IsEmpty);
	Gura_AssignMethod(wx_Sizer, IsShown);
	Gura_AssignMethod(wx_Sizer, IsShown_1);
	Gura_AssignMethod(wx_Sizer, IsShown_2);
	Gura_AssignMethod(wx_Sizer, Layout);
	Gura_AssignMethod(wx_Sizer, Prepend);
	Gura_AssignMethod(wx_Sizer, Prepend_1);
	Gura_AssignMethod(wx_Sizer, Prepend_2);
	Gura_AssignMethod(wx_Sizer, Prepend_3);
	Gura_AssignMethod(wx_Sizer, Prepend_4);
	Gura_AssignMethod(wx_Sizer, Prepend_5);
	Gura_AssignMethod(wx_Sizer, Prepend_6);
	Gura_AssignMethod(wx_Sizer, PrependSpacer);
	Gura_AssignMethod(wx_Sizer, PrependStretchSpacer);
	Gura_AssignMethod(wx_Sizer, RecalcSizes);
	Gura_AssignMethod(wx_Sizer, Remove);
	Gura_AssignMethod(wx_Sizer, Remove_1);
	Gura_AssignMethod(wx_Sizer, Remove_2);
	Gura_AssignMethod(wx_Sizer, Replace);
	Gura_AssignMethod(wx_Sizer, Replace_1);
	Gura_AssignMethod(wx_Sizer, Replace_2);
	Gura_AssignMethod(wx_Sizer, SetDimension);
	Gura_AssignMethod(wx_Sizer, SetDimension_1);
	Gura_AssignMethod(wx_Sizer, SetItemMinSize);
	Gura_AssignMethod(wx_Sizer, SetItemMinSize_1);
	Gura_AssignMethod(wx_Sizer, SetItemMinSize_2);
	Gura_AssignMethod(wx_Sizer, SetItemMinSize_3);
	Gura_AssignMethod(wx_Sizer, SetItemMinSize_4);
	Gura_AssignMethod(wx_Sizer, SetItemMinSize_5);
	Gura_AssignMethod(wx_Sizer, SetMinSize);
	Gura_AssignMethod(wx_Sizer, SetMinSize_1);
	Gura_AssignMethod(wx_Sizer, SetSizeHints);
	Gura_AssignMethod(wx_Sizer, SetVirtualSizeHints);
	Gura_AssignMethod(wx_Sizer, Show);
	Gura_AssignMethod(wx_Sizer, Show_1);
	Gura_AssignMethod(wx_Sizer, Show_2);
	Gura_AssignMethod(wx_Sizer, ShowItems);
}

Gura_ImplementDescendantCreator(wx_Sizer)
{
	return new Object_wx_Sizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
