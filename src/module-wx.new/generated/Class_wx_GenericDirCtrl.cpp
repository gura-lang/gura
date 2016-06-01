//----------------------------------------------------------------------------
// wxGenericDirCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGenericDirCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGenericDirCtrl
//----------------------------------------------------------------------------
Object_wx_GenericDirCtrl::~Object_wx_GenericDirCtrl()
{
}

Object *Object_wx_GenericDirCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_GenericDirCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.GenericDirCtrl:");
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
Gura_DeclareMethod(wx_GenericDirCtrl, wxGenericDirCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, wxGenericDirCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGenericDirCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, wxGenericDirCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultFilter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, wxGenericDirCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int dir = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int filter = arg.GetNumber(6)
	//int defaultFilter = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxGenericDirCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, ~wxGenericDirCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, ~wxGenericDirCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxGenericDirCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, CollapsePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, CollapsePath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->CollapsePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, CollapseTree)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, CollapseTree)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CollapseTree();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultFilter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int dir = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int filter = arg.GetNumber(6)
	//int defaultFilter = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, ExpandPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, ExpandPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->ExpandPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetDefaultPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetDefaultPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetFilePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetFilePath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFilePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetFilePaths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetFilePaths)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int paths = arg.GetNumber(0)
	//pThis->GetEntity()->GetFilePaths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetFilter)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFilter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetFilterIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetFilterListCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetFilterListCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFilterListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetPath_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "itemId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetPath_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int itemId = arg.GetNumber(0)
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetPaths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetPaths)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int paths = arg.GetNumber(0)
	//pThis->GetEntity()->GetPaths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetRootId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetRootId)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRootId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetTreeCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetTreeCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTreeCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, ReCreateTree)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, ReCreateTree)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ReCreateTree();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SetDefaultPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SetDefaultPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SetFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SetFilter)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SetFilterIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, ShowHidden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, ShowHidden)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHidden();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SelectPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SelectPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int select = arg.GetNumber(1)
	//pThis->GetEntity()->SelectPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SelectPaths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SelectPaths)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int paths = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPaths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericDirCtrl, UnselectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, UnselectAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UnselectAll();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGenericDirCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericDirCtrl)
{
	Gura_AssignMethod(wx_GenericDirCtrl, wxGenericDirCtrl);
	Gura_AssignMethod(wx_GenericDirCtrl, wxGenericDirCtrl_1);
	Gura_AssignMethod(wx_GenericDirCtrl, ~wxGenericDirCtrl);
	Gura_AssignMethod(wx_GenericDirCtrl, CollapsePath);
	Gura_AssignMethod(wx_GenericDirCtrl, CollapseTree);
	Gura_AssignMethod(wx_GenericDirCtrl, Create);
	Gura_AssignMethod(wx_GenericDirCtrl, ExpandPath);
	Gura_AssignMethod(wx_GenericDirCtrl, GetDefaultPath);
	Gura_AssignMethod(wx_GenericDirCtrl, GetFilePath);
	Gura_AssignMethod(wx_GenericDirCtrl, GetFilePaths);
	Gura_AssignMethod(wx_GenericDirCtrl, GetFilter);
	Gura_AssignMethod(wx_GenericDirCtrl, GetFilterIndex);
	Gura_AssignMethod(wx_GenericDirCtrl, GetFilterListCtrl);
	Gura_AssignMethod(wx_GenericDirCtrl, GetPath);
	Gura_AssignMethod(wx_GenericDirCtrl, GetPath_1);
	Gura_AssignMethod(wx_GenericDirCtrl, GetPaths);
	Gura_AssignMethod(wx_GenericDirCtrl, GetRootId);
	Gura_AssignMethod(wx_GenericDirCtrl, GetTreeCtrl);
	Gura_AssignMethod(wx_GenericDirCtrl, Init);
	Gura_AssignMethod(wx_GenericDirCtrl, ReCreateTree);
	Gura_AssignMethod(wx_GenericDirCtrl, SetDefaultPath);
	Gura_AssignMethod(wx_GenericDirCtrl, SetFilter);
	Gura_AssignMethod(wx_GenericDirCtrl, SetFilterIndex);
	Gura_AssignMethod(wx_GenericDirCtrl, SetPath);
	Gura_AssignMethod(wx_GenericDirCtrl, ShowHidden);
	Gura_AssignMethod(wx_GenericDirCtrl, SelectPath);
	Gura_AssignMethod(wx_GenericDirCtrl, SelectPaths);
	Gura_AssignMethod(wx_GenericDirCtrl, UnselectAll);
}

Gura_ImplementDescendantCreator(wx_GenericDirCtrl)
{
	return new Object_wx_GenericDirCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
