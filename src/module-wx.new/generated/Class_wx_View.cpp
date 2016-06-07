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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__View, "View")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_View));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__View)
{
	//wxView();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_View, __Activate, "Activate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "activate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __Activate)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool activate = arg.GetNumber(0)
	//pThis->GetEntity()->Activate(activate);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "deleteWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __Close)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool deleteWindow = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Close(deleteWindow);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __GetDocument, "GetDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_View, __GetDocument)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocument* _rtn = pThis->GetEntity()->GetDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __GetDocumentManager, "GetDocumentManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_View, __GetDocumentManager)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocManager* _rtn = pThis->GetEntity()->GetDocumentManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __GetFrame, "GetFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_View, __GetFrame)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __GetViewName, "GetViewName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_View, __GetViewName)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetViewName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __OnActivateView, "OnActivateView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "activate", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "activeView", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deactiveView", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __OnActivateView)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool activate = arg.GetNumber(0)
	//wxView* activeView = arg.GetNumber(1)
	//wxView* deactiveView = arg.GetNumber(2)
	//pThis->GetEntity()->OnActivateView(activate, activeView, deactiveView);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __OnChangeFilename, "OnChangeFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, __OnChangeFilename)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnChangeFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __OnClose, "OnClose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "deleteWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __OnClose)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool deleteWindow = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->OnClose(deleteWindow);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __OnClosingDocument, "OnClosingDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, __OnClosingDocument)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnClosingDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __OnCreate, "OnCreate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __OnCreate)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocument* doc = arg.GetNumber(0)
	//long flags = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->OnCreate(doc, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __OnCreatePrintout, "OnCreatePrintout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_View, __OnCreatePrintout)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintout* _rtn = pThis->GetEntity()->OnCreatePrintout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __OnDraw, "OnDraw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __OnDraw)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC* dc = arg.GetNumber(0)
	//pThis->GetEntity()->OnDraw(dc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __OnUpdate, "OnUpdate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sender", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __OnUpdate)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxView* sender = arg.GetNumber(0)
	//wxObject* hint = arg.GetNumber(1)
	//pThis->GetEntity()->OnUpdate(sender, hint);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __SetDocument, "SetDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __SetDocument)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocument* doc = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocument(doc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __SetFrame, "SetFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __SetFrame)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* frame = arg.GetNumber(0)
	//pThis->GetEntity()->SetFrame(frame);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_View, __SetViewName, "SetViewName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, __SetViewName)
{
	Object_wx_View *pThis = Object_wx_View::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetViewName(name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxView
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_View)
{
	// Constructor assignment
	Gura_AssignFunction(__View);
	// Method assignment
	Gura_AssignMethod(wx_View, __Activate);
	Gura_AssignMethod(wx_View, __Close);
	Gura_AssignMethod(wx_View, __GetDocument);
	Gura_AssignMethod(wx_View, __GetDocumentManager);
	Gura_AssignMethod(wx_View, __GetFrame);
	Gura_AssignMethod(wx_View, __GetViewName);
	Gura_AssignMethod(wx_View, __OnActivateView);
	Gura_AssignMethod(wx_View, __OnChangeFilename);
	Gura_AssignMethod(wx_View, __OnClose);
	Gura_AssignMethod(wx_View, __OnClosingDocument);
	Gura_AssignMethod(wx_View, __OnCreate);
	Gura_AssignMethod(wx_View, __OnCreatePrintout);
	Gura_AssignMethod(wx_View, __OnDraw);
	Gura_AssignMethod(wx_View, __OnUpdate);
	Gura_AssignMethod(wx_View, __SetDocument);
	Gura_AssignMethod(wx_View, __SetFrame);
	Gura_AssignMethod(wx_View, __SetViewName);
}

Gura_ImplementDescendantCreator(wx_View)
{
	return new Object_wx_View((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
