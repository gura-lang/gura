//----------------------------------------------------------------------------
// wxPreviewFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPreviewFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPreviewFrame
//----------------------------------------------------------------------------
Object_wx_PreviewFrame::~Object_wx_PreviewFrame()
{
}

Object *Object_wx_PreviewFrame::Clone() const
{
	return nullptr;
}

String Object_wx_PreviewFrame::ToString(bool exprFlag)
{
	String rtn("<wx.PreviewFrame:");
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
Gura_DeclareFunctionAlias(__PreviewFrame, "PreviewFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "preview", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PreviewFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PreviewFrame)
{
	//wxPrintPreviewBase* preview = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxPreviewFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PreviewFrame, __CreateCanvas, "CreateCanvas")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, __CreateCanvas)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateCanvas();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PreviewFrame, __CreateControlBar, "CreateControlBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, __CreateControlBar)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateControlBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PreviewFrame, __Initialize, "Initialize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, __Initialize)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PreviewFrame, __InitializeWithModality, "InitializeWithModality")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewFrame, __InitializeWithModality)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPreviewFrameModalityKind kind = arg.GetNumber(0)
	//pThis->GetEntity()->InitializeWithModality();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PreviewFrame, __OnCloseWindow, "OnCloseWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewFrame, __OnCloseWindow)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCloseEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCloseWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPreviewFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewFrame)
{
	// Constructor assignment
	Gura_AssignFunction(__PreviewFrame);
	// Method assignment
	Gura_AssignMethod(wx_PreviewFrame, __CreateCanvas);
	Gura_AssignMethod(wx_PreviewFrame, __CreateControlBar);
	Gura_AssignMethod(wx_PreviewFrame, __Initialize);
	Gura_AssignMethod(wx_PreviewFrame, __InitializeWithModality);
	Gura_AssignMethod(wx_PreviewFrame, __OnCloseWindow);
}

Gura_ImplementDescendantCreator(wx_PreviewFrame)
{
	return new Object_wx_PreviewFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
