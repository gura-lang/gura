//----------------------------------------------------------------------------
// wxFileCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileCtrl
//----------------------------------------------------------------------------
Object_wx_FileCtrl::~Object_wx_FileCtrl()
{
}

Object *Object_wx_FileCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_FileCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FileCtrl:");
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
Gura_DeclareMethod(wx_FileCtrl, wxFileCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, wxFileCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFileCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, wxFileCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultDirectory", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildCard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, wxFileCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int defaultDirectory = arg.GetNumber(2)
	//int defaultFilename = arg.GetNumber(3)
	//int wildCard = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//int size = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxFileCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultDirectory", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildCard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int defaultDirectory = arg.GetNumber(2)
	//int defaultFilename = arg.GetNumber(3)
	//int wildCard = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//int size = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, GetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, GetDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, GetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, GetFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, GetFilenames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filenames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, GetFilenames)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filenames = arg.GetNumber(0)
	//pThis->GetEntity()->GetFilenames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, GetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, GetFilterIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, GetPaths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, GetPaths)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int paths = arg.GetNumber(0)
	//pThis->GetEntity()->GetPaths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, GetWildcard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, GetWildcard)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWildcard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, SetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "directory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, SetDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int directory = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, SetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, SetFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, SetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filterIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, SetFilterIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filterIndex = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, SetWildcard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wildCard", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, SetWildcard)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int wildCard = arg.GetNumber(0)
	//pThis->GetEntity()->SetWildcard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrl, ShowHidden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, ShowHidden)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHidden();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileCtrl)
{
	Gura_AssignMethod(wx_FileCtrl, wxFileCtrl);
	Gura_AssignMethod(wx_FileCtrl, wxFileCtrl_1);
	Gura_AssignMethod(wx_FileCtrl, Create);
	Gura_AssignMethod(wx_FileCtrl, GetDirectory);
	Gura_AssignMethod(wx_FileCtrl, GetFilename);
	Gura_AssignMethod(wx_FileCtrl, GetFilenames);
	Gura_AssignMethod(wx_FileCtrl, GetFilterIndex);
	Gura_AssignMethod(wx_FileCtrl, GetPath);
	Gura_AssignMethod(wx_FileCtrl, GetPaths);
	Gura_AssignMethod(wx_FileCtrl, GetWildcard);
	Gura_AssignMethod(wx_FileCtrl, SetDirectory);
	Gura_AssignMethod(wx_FileCtrl, SetFilename);
	Gura_AssignMethod(wx_FileCtrl, SetPath);
	Gura_AssignMethod(wx_FileCtrl, SetFilterIndex);
	Gura_AssignMethod(wx_FileCtrl, SetWildcard);
	Gura_AssignMethod(wx_FileCtrl, ShowHidden);
}

Gura_ImplementDescendantCreator(wx_FileCtrl)
{
	return new Object_wx_FileCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
