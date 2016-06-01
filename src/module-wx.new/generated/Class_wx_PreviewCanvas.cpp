//----------------------------------------------------------------------------
// wxPreviewCanvas
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPreviewCanvas
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPreviewCanvas
//----------------------------------------------------------------------------
Object_wx_PreviewCanvas::~Object_wx_PreviewCanvas()
{
}

Object *Object_wx_PreviewCanvas::Clone() const
{
	return nullptr;
}

String Object_wx_PreviewCanvas::ToString(bool exprFlag)
{
	String rtn("<wx.PreviewCanvas:");
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
Gura_DeclareMethod(wx_PreviewCanvas, wxPreviewCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "preview", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewCanvas, wxPreviewCanvas)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewCanvas *pThis = Object_wx_PreviewCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int preview = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxPreviewCanvas();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewCanvas, ~wxPreviewCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewCanvas, ~wxPreviewCanvas)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewCanvas *pThis = Object_wx_PreviewCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPreviewCanvas();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewCanvas, OnPaint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewCanvas, OnPaint)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewCanvas *pThis = Object_wx_PreviewCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnPaint();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPreviewCanvas
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewCanvas)
{
	Gura_AssignMethod(wx_PreviewCanvas, wxPreviewCanvas);
	Gura_AssignMethod(wx_PreviewCanvas, ~wxPreviewCanvas);
	Gura_AssignMethod(wx_PreviewCanvas, OnPaint);
}

Gura_ImplementDescendantCreator(wx_PreviewCanvas)
{
	return new Object_wx_PreviewCanvas((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
