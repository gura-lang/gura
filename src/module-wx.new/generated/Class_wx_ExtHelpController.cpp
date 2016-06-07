//----------------------------------------------------------------------------
// wxExtHelpController
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxExtHelpController
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxExtHelpController
//----------------------------------------------------------------------------
Object_wx_ExtHelpController::~Object_wx_ExtHelpController()
{
}

Object *Object_wx_ExtHelpController::Clone() const
{
	return nullptr;
}

String Object_wx_ExtHelpController::ToString(bool exprFlag)
{
	String rtn("<wx.ExtHelpController:");
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
Gura_DeclareFunctionAlias(__ExtHelpController, "ExtHelpController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ExtHelpController));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ExtHelpController)
{
	//wxWindow* parentWindow = arg.GetNumber(0)
	//wxExtHelpController(parentWindow);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ExtHelpController, __SetViewer, "SetViewer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "viewer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __SetViewer)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& viewer = arg.GetNumber(0)
	//long flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetViewer(viewer, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __Initialize, "Initialize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __Initialize)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dir = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Initialize(dir);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __LoadFile)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& file = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->LoadFile(file);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __DisplayContents, "DisplayContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ExtHelpController, __DisplayContents)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->DisplayContents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __DisplaySection, "DisplaySection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "sectionNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __DisplaySection)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sectionNo = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DisplaySection(sectionNo);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __DisplaySection_1, "DisplaySection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "section", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __DisplaySection_1)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& section = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DisplaySection(section);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __DisplayBlock, "DisplayBlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "blockNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __DisplayBlock)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long blockNo = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DisplayBlock(blockNo);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __KeywordSearch, "KeywordSearch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "k", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __KeywordSearch)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& k = arg.GetNumber(0)
	//wxHelpSearchMode mode = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->KeywordSearch(k, mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __Quit, "Quit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ExtHelpController, __Quit)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Quit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __OnQuit, "OnQuit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ExtHelpController, __OnQuit)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnQuit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __DisplayHelp, "DisplayHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "relativeURL", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __DisplayHelp)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& relativeURL = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DisplayHelp(relativeURL);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __SetFrameParameters, "SetFrameParameters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "titleFormat", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newFrameEachTime", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __SetFrameParameters)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& titleFormat = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//bool newFrameEachTime = arg.GetNumber(3)
	//pThis->GetEntity()->SetFrameParameters(titleFormat, size, pos, newFrameEachTime);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ExtHelpController, __GetFrameParameters, "GetFrameParameters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newFrameEachTime", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ExtHelpController, __GetFrameParameters)
{
	Object_wx_ExtHelpController *pThis = Object_wx_ExtHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize* size = arg.GetNumber(0)
	//wxPoint* pos = arg.GetNumber(1)
	//bool* newFrameEachTime = arg.GetNumber(2)
	//wxFrame* _rtn = pThis->GetEntity()->GetFrameParameters(size, pos, newFrameEachTime);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxExtHelpController
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ExtHelpController)
{
	// Constructor assignment
	Gura_AssignFunction(__ExtHelpController);
	// Method assignment
	Gura_AssignMethod(wx_ExtHelpController, __SetViewer);
	Gura_AssignMethod(wx_ExtHelpController, __Initialize);
	Gura_AssignMethod(wx_ExtHelpController, __LoadFile);
	Gura_AssignMethod(wx_ExtHelpController, __DisplayContents);
	Gura_AssignMethod(wx_ExtHelpController, __DisplaySection);
	Gura_AssignMethod(wx_ExtHelpController, __DisplaySection_1);
	Gura_AssignMethod(wx_ExtHelpController, __DisplayBlock);
	Gura_AssignMethod(wx_ExtHelpController, __KeywordSearch);
	Gura_AssignMethod(wx_ExtHelpController, __Quit);
	Gura_AssignMethod(wx_ExtHelpController, __OnQuit);
	Gura_AssignMethod(wx_ExtHelpController, __DisplayHelp);
	Gura_AssignMethod(wx_ExtHelpController, __SetFrameParameters);
	Gura_AssignMethod(wx_ExtHelpController, __GetFrameParameters);
}

Gura_ImplementDescendantCreator(wx_ExtHelpController)
{
	return new Object_wx_ExtHelpController((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
