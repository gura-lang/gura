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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxPreviewControlBar, "wxPreviewControlBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "preview", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buttons", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PreviewControlBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxPreviewControlBar)
{
	//int preview = arg.GetNumber(0)
	//int buttons = arg.GetNumber(1)
	//int parent = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//wxPreviewControlBar();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PreviewControlBar, __CreateButtons, "CreateButtons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewControlBar, __CreateButtons)
{
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateButtons();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PreviewControlBar, __GetPrintPreview, "GetPrintPreview")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewControlBar, __GetPrintPreview)
{
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintPreview();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PreviewControlBar, __GetZoomControl, "GetZoomControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewControlBar, __GetZoomControl)
{
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetZoomControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PreviewControlBar, __SetZoomControl, "SetZoomControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "percent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewControlBar, __SetZoomControl)
{
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int percent = arg.GetNumber(0)
	//pThis->GetEntity()->SetZoomControl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPreviewControlBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewControlBar)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPreviewControlBar);
	// Method assignment
	Gura_AssignMethod(wx_PreviewControlBar, __CreateButtons);
	Gura_AssignMethod(wx_PreviewControlBar, __GetPrintPreview);
	Gura_AssignMethod(wx_PreviewControlBar, __GetZoomControl);
	Gura_AssignMethod(wx_PreviewControlBar, __SetZoomControl);
}

Gura_ImplementDescendantCreator(wx_PreviewControlBar)
{
	return new Object_wx_PreviewControlBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
