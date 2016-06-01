//----------------------------------------------------------------------------
// wxPrintPreview
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintPreview
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintPreview
//----------------------------------------------------------------------------
Object_wx_PrintPreview::~Object_wx_PrintPreview()
{
}

Object *Object_wx_PrintPreview::Clone() const
{
	return nullptr;
}

String Object_wx_PrintPreview::ToString(bool exprFlag)
{
	String rtn("<wx.PrintPreview:");
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
Gura_DeclareMethod(wx_PrintPreview, wxPrintPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "printoutForPrinting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, wxPrintPreview)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printout = arg.GetNumber(0)
	//int printoutForPrinting = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//pThis->GetEntity()->wxPrintPreview();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, wxPrintPreview_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "printoutForPrinting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, wxPrintPreview_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printout = arg.GetNumber(0)
	//int printoutForPrinting = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//pThis->GetEntity()->wxPrintPreview();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, ~wxPrintPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintPreview, ~wxPrintPreview)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPrintPreview();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, GetCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintPreview, GetCanvas)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCanvas();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, GetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintPreview, GetCurrentPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintPreview, GetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, GetMaxPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintPreview, GetMaxPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMaxPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, GetMinPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintPreview, GetMinPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, GetPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintPreview, GetPrintout)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, GetPrintoutForPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintPreview, GetPrintoutForPrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintoutForPrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintPreview, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, PaintPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "canvas", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, PaintPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int canvas = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//pThis->GetEntity()->PaintPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, Print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prompt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, Print)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prompt = arg.GetNumber(0)
	//pThis->GetEntity()->Print();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, RenderPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, RenderPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageNum = arg.GetNumber(0)
	//pThis->GetEntity()->RenderPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, SetCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetCanvas)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetCanvas();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, SetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetCurrentPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageNum = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrentPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, SetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->SetFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, SetPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetPrintout)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printout = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, SetZoom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "percent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetZoom)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int percent = arg.GetNumber(0)
	//pThis->GetEntity()->SetZoom();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintPreview
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintPreview)
{
	Gura_AssignMethod(wx_PrintPreview, wxPrintPreview);
	Gura_AssignMethod(wx_PrintPreview, wxPrintPreview_1);
	Gura_AssignMethod(wx_PrintPreview, ~wxPrintPreview);
	Gura_AssignMethod(wx_PrintPreview, GetCanvas);
	Gura_AssignMethod(wx_PrintPreview, GetCurrentPage);
	Gura_AssignMethod(wx_PrintPreview, GetFrame);
	Gura_AssignMethod(wx_PrintPreview, GetMaxPage);
	Gura_AssignMethod(wx_PrintPreview, GetMinPage);
	Gura_AssignMethod(wx_PrintPreview, GetPrintout);
	Gura_AssignMethod(wx_PrintPreview, GetPrintoutForPrinting);
	Gura_AssignMethod(wx_PrintPreview, IsOk);
	Gura_AssignMethod(wx_PrintPreview, PaintPage);
	Gura_AssignMethod(wx_PrintPreview, Print);
	Gura_AssignMethod(wx_PrintPreview, RenderPage);
	Gura_AssignMethod(wx_PrintPreview, SetCanvas);
	Gura_AssignMethod(wx_PrintPreview, SetCurrentPage);
	Gura_AssignMethod(wx_PrintPreview, SetFrame);
	Gura_AssignMethod(wx_PrintPreview, SetPrintout);
	Gura_AssignMethod(wx_PrintPreview, SetZoom);
}

Gura_ImplementDescendantCreator(wx_PrintPreview)
{
	return new Object_wx_PrintPreview((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
