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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PreviewCanvas, "PreviewCanvas")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "preview", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PreviewCanvas));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PreviewCanvas)
{
	//wxPrintPreview* preview = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxPreviewCanvas();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PreviewCanvas, __OnPaint, "OnPaint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewCanvas, __OnPaint)
{
	Object_wx_PreviewCanvas *pThis = Object_wx_PreviewCanvas::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPaintEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnPaint();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPreviewCanvas
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewCanvas)
{
	// Constructor assignment
	Gura_AssignFunction(__PreviewCanvas);
	// Method assignment
	Gura_AssignMethod(wx_PreviewCanvas, __OnPaint);
}

Gura_ImplementDescendantCreator(wx_PreviewCanvas)
{
	return new Object_wx_PreviewCanvas((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
