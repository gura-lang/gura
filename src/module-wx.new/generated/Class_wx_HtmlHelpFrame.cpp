//----------------------------------------------------------------------------
// wxHtmlHelpFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Object_wx_HtmlHelpFrame::~Object_wx_HtmlHelpFrame()
{
}

Object *Object_wx_HtmlHelpFrame::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpFrame::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpFrame:");
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
Gura_DeclareMethod(wx_HtmlHelpFrame, wxHtmlHelpFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, wxHtmlHelpFrame)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxHtmlHelpFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, wxHtmlHelpFrame_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootpath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, wxHtmlHelpFrame_1)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//int config = arg.GetNumber(5)
	//int rootpath = arg.GetNumber(6)
	//pThis->GetEntity()->wxHtmlHelpFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, AddToolbarButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolBar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, AddToolbarButtons)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolBar = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->AddToolbarButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootpath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, Create)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//int config = arg.GetNumber(4)
	//int rootpath = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, GetController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, GetController)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetController();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, SetController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "controller", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, SetController)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int controller = arg.GetNumber(0)
	//pThis->GetEntity()->SetController();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, SetTitleFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, SetTitleFormat)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitleFormat();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpFrame)
{
	Gura_AssignMethod(wx_HtmlHelpFrame, wxHtmlHelpFrame);
	Gura_AssignMethod(wx_HtmlHelpFrame, wxHtmlHelpFrame_1);
	Gura_AssignMethod(wx_HtmlHelpFrame, AddToolbarButtons);
	Gura_AssignMethod(wx_HtmlHelpFrame, Create);
	Gura_AssignMethod(wx_HtmlHelpFrame, GetController);
	Gura_AssignMethod(wx_HtmlHelpFrame, SetController);
	Gura_AssignMethod(wx_HtmlHelpFrame, SetTitleFormat);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpFrame)
{
	return new Object_wx_HtmlHelpFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
