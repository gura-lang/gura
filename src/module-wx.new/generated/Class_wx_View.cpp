//----------------------------------------------------------------------------
// wxView
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxView
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxView
//----------------------------------------------------------------------------
Object_wx_View::~Object_wx_View()
{
}

Object *Object_wx_View::Clone() const
{
	return nullptr;
}

String Object_wx_View::ToString(bool exprFlag)
{
	String rtn("<wx.View:");
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
Gura_DeclareMethod(wx_View, wxView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, wxView)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, Activate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "activate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, Activate)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int activate = arg.GetNumber(0)
	//pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "deleteWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, Close)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int deleteWindow = arg.GetNumber(0)
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, GetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, GetDocument)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, GetDocumentManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, GetDocumentManager)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, GetFrame)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, GetViewName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, GetViewName)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, OnActivateView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "activate", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "activeView", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deactiveView", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, OnActivateView)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int activate = arg.GetNumber(0)
	//int activeView = arg.GetNumber(1)
	//int deactiveView = arg.GetNumber(2)
	//pThis->GetEntity()->OnActivateView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, OnChangeFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, OnChangeFilename)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnChangeFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, OnClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "deleteWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, OnClose)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int deleteWindow = arg.GetNumber(0)
	//pThis->GetEntity()->OnClose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, OnClosingDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, OnClosingDocument)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnClosingDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, OnCreate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, OnCreate)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->OnCreate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, OnCreatePrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, OnCreatePrintout)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnCreatePrintout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, OnDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, OnDraw)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->OnDraw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, OnUpdate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sender", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, OnUpdate)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sender = arg.GetNumber(0)
	//int hint = arg.GetNumber(1)
	//pThis->GetEntity()->OnUpdate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, SetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, SetDocument)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, SetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, SetFrame)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->SetFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_View, SetViewName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, SetViewName)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetViewName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxView
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_View)
{
	Gura_AssignMethod(wx_View, wxView);
	Gura_AssignMethod(wx_View, Activate);
	Gura_AssignMethod(wx_View, Close);
	Gura_AssignMethod(wx_View, GetDocument);
	Gura_AssignMethod(wx_View, GetDocumentManager);
	Gura_AssignMethod(wx_View, GetFrame);
	Gura_AssignMethod(wx_View, GetViewName);
	Gura_AssignMethod(wx_View, OnActivateView);
	Gura_AssignMethod(wx_View, OnChangeFilename);
	Gura_AssignMethod(wx_View, OnClose);
	Gura_AssignMethod(wx_View, OnClosingDocument);
	Gura_AssignMethod(wx_View, OnCreate);
	Gura_AssignMethod(wx_View, OnCreatePrintout);
	Gura_AssignMethod(wx_View, OnDraw);
	Gura_AssignMethod(wx_View, OnUpdate);
	Gura_AssignMethod(wx_View, SetDocument);
	Gura_AssignMethod(wx_View, SetFrame);
	Gura_AssignMethod(wx_View, SetViewName);
}

Gura_ImplementDescendantCreator(wx_View)
{
	return new Object_wx_View((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
