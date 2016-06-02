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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PreviewFrame, wxPreviewFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "preview", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewFrame, wxPreviewFrame)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int preview = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxPreviewFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewFrame, CreateCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, CreateCanvas)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateCanvas();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewFrame, CreateControlBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, CreateControlBar)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateControlBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewFrame, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, Initialize)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewFrame, InitializeWithModality)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewFrame, InitializeWithModality)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int kind = arg.GetNumber(0)
	//pThis->GetEntity()->InitializeWithModality();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewFrame, OnCloseWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewFrame, OnCloseWindow)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCloseWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPreviewFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewFrame)
{
	Gura_AssignMethod(wx_PreviewFrame, wxPreviewFrame);
	Gura_AssignMethod(wx_PreviewFrame, CreateCanvas);
	Gura_AssignMethod(wx_PreviewFrame, CreateControlBar);
	Gura_AssignMethod(wx_PreviewFrame, Initialize);
	Gura_AssignMethod(wx_PreviewFrame, InitializeWithModality);
	Gura_AssignMethod(wx_PreviewFrame, OnCloseWindow);
}

Gura_ImplementDescendantCreator(wx_PreviewFrame)
{
	return new Object_wx_PreviewFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
