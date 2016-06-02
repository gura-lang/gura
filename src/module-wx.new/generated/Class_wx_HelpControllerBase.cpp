//----------------------------------------------------------------------------
// wxHelpControllerBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpControllerBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHelpControllerBase
//----------------------------------------------------------------------------
Object_wx_HelpControllerBase::~Object_wx_HelpControllerBase()
{
}

Object *Object_wx_HelpControllerBase::Clone() const
{
	return nullptr;
}

String Object_wx_HelpControllerBase::ToString(bool exprFlag)
{
	String rtn("<wx.HelpControllerBase:");
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
Gura_DeclareMethod(wx_HelpControllerBase, wxHelpControllerBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, wxHelpControllerBase)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parentWindow = arg.GetNumber(0)
	//pThis->GetEntity()->wxHelpControllerBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, DisplayBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "blockNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, DisplayBlock)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int blockNo = arg.GetNumber(0)
	//pThis->GetEntity()->DisplayBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, DisplayContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HelpControllerBase, DisplayContents)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisplayContents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, DisplayContextPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "contextId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, DisplayContextPopup)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int contextId = arg.GetNumber(0)
	//pThis->GetEntity()->DisplayContextPopup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, DisplaySection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "section", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, DisplaySection)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int section = arg.GetNumber(0)
	//pThis->GetEntity()->DisplaySection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, DisplaySection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sectionNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, DisplaySection_1)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sectionNo = arg.GetNumber(0)
	//pThis->GetEntity()->DisplaySection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, DisplayTextPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, DisplayTextPopup)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->DisplayTextPopup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, GetFrameParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newFrameEachTime", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, GetFrameParameters)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int newFrameEachTime = arg.GetNumber(2)
	//pThis->GetEntity()->GetFrameParameters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, GetParentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HelpControllerBase, GetParentWindow)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, Initialize)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, Initialize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "server", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, Initialize_1)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int server = arg.GetNumber(1)
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, KeywordSearch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyWord", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, KeywordSearch)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keyWord = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->KeywordSearch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, LoadFile)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, OnQuit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HelpControllerBase, OnQuit)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnQuit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, Quit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HelpControllerBase, Quit)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Quit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, SetFrameParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "titleFormat", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newFrameEachTime", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, SetFrameParameters)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int titleFormat = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int newFrameEachTime = arg.GetNumber(3)
	//pThis->GetEntity()->SetFrameParameters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, SetParentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, SetParentWindow)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parentWindow = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerBase, SetViewer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "viewer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerBase, SetViewer)
{
	Object_wx_HelpControllerBase *pThis = Object_wx_HelpControllerBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int viewer = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetViewer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHelpControllerBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpControllerBase)
{
	Gura_AssignMethod(wx_HelpControllerBase, wxHelpControllerBase);
	Gura_AssignMethod(wx_HelpControllerBase, DisplayBlock);
	Gura_AssignMethod(wx_HelpControllerBase, DisplayContents);
	Gura_AssignMethod(wx_HelpControllerBase, DisplayContextPopup);
	Gura_AssignMethod(wx_HelpControllerBase, DisplaySection);
	Gura_AssignMethod(wx_HelpControllerBase, DisplaySection_1);
	Gura_AssignMethod(wx_HelpControllerBase, DisplayTextPopup);
	Gura_AssignMethod(wx_HelpControllerBase, GetFrameParameters);
	Gura_AssignMethod(wx_HelpControllerBase, GetParentWindow);
	Gura_AssignMethod(wx_HelpControllerBase, Initialize);
	Gura_AssignMethod(wx_HelpControllerBase, Initialize_1);
	Gura_AssignMethod(wx_HelpControllerBase, KeywordSearch);
	Gura_AssignMethod(wx_HelpControllerBase, LoadFile);
	Gura_AssignMethod(wx_HelpControllerBase, OnQuit);
	Gura_AssignMethod(wx_HelpControllerBase, Quit);
	Gura_AssignMethod(wx_HelpControllerBase, SetFrameParameters);
	Gura_AssignMethod(wx_HelpControllerBase, SetParentWindow);
	Gura_AssignMethod(wx_HelpControllerBase, SetViewer);
}

Gura_ImplementDescendantCreator(wx_HelpControllerBase)
{
	return new Object_wx_HelpControllerBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
