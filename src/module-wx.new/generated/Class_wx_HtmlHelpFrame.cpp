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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlHelpFrame, "HtmlHelpFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlHelpFrame)
{
	//wxHtmlHelpData* data = arg.GetNumber(0)
	//wxHtmlHelpFrame(data);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HtmlHelpFrame_1, "HtmlHelpFrame_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootpath", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlHelpFrame_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//wxHtmlHelpData* data = arg.GetNumber(4)
	//wxConfigBase* config = arg.GetNumber(5)
	//const wxString& rootpath = arg.GetNumber(6)
	//wxHtmlHelpFrame(parent, id, title, style, data, config, rootpath);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlHelpFrame, __AddToolbarButtons, "AddToolbarButtons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolBar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, __AddToolbarButtons)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxToolBar* toolBar = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->AddToolbarButtons(toolBar, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpFrame, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootpath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, __Create)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//wxConfigBase* config = arg.GetNumber(4)
	//const wxString& rootpath = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, title, style, config, rootpath);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpFrame, __GetController, "GetController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, __GetController)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlHelpController* _rtn = pThis->GetEntity()->GetController();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpFrame, __SetController, "SetController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "controller", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, __SetController)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlHelpController* controller = arg.GetNumber(0)
	//pThis->GetEntity()->SetController(controller);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpFrame, __SetTitleFormat, "SetTitleFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, __SetTitleFormat)
{
	Object_wx_HtmlHelpFrame *pThis = Object_wx_HtmlHelpFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& format = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitleFormat(format);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpFrame)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlHelpFrame);
	Gura_AssignFunction(__HtmlHelpFrame_1);
	// Method assignment
	Gura_AssignMethod(wx_HtmlHelpFrame, __AddToolbarButtons);
	Gura_AssignMethod(wx_HtmlHelpFrame, __Create);
	Gura_AssignMethod(wx_HtmlHelpFrame, __GetController);
	Gura_AssignMethod(wx_HtmlHelpFrame, __SetController);
	Gura_AssignMethod(wx_HtmlHelpFrame, __SetTitleFormat);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpFrame)
{
	return new Object_wx_HtmlHelpFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
