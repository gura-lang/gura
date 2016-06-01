//----------------------------------------------------------------------------
// wxPreviewControlBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPreviewControlBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPreviewControlBar
//----------------------------------------------------------------------------
Object_wx_PreviewControlBar::~Object_wx_PreviewControlBar()
{
}

Object *Object_wx_PreviewControlBar::Clone() const
{
	return nullptr;
}

String Object_wx_PreviewControlBar::ToString(bool exprFlag)
{
	String rtn("<wx.PreviewControlBar:");
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
Gura_DeclareMethod(wx_PreviewControlBar, wxPreviewControlBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "preview", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buttons", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewControlBar, wxPreviewControlBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int preview = arg.GetNumber(0)
	//int buttons = arg.GetNumber(1)
	//int parent = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxPreviewControlBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewControlBar, ~wxPreviewControlBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewControlBar, ~wxPreviewControlBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPreviewControlBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewControlBar, CreateButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewControlBar, CreateButtons)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreateButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewControlBar, GetPrintPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewControlBar, GetPrintPreview)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintPreview();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewControlBar, GetZoomControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewControlBar, GetZoomControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetZoomControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewControlBar, SetZoomControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "percent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewControlBar, SetZoomControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int percent = arg.GetNumber(0)
	//pThis->GetEntity()->SetZoomControl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPreviewControlBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewControlBar)
{
	Gura_AssignMethod(wx_PreviewControlBar, wxPreviewControlBar);
	Gura_AssignMethod(wx_PreviewControlBar, ~wxPreviewControlBar);
	Gura_AssignMethod(wx_PreviewControlBar, CreateButtons);
	Gura_AssignMethod(wx_PreviewControlBar, GetPrintPreview);
	Gura_AssignMethod(wx_PreviewControlBar, GetZoomControl);
	Gura_AssignMethod(wx_PreviewControlBar, SetZoomControl);
}

Gura_ImplementDescendantCreator(wx_PreviewControlBar)
{
	return new Object_wx_PreviewControlBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
