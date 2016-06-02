//----------------------------------------------------------------------------
// wxFileHistory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileHistory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileHistory
//----------------------------------------------------------------------------
Object_wx_FileHistory::~Object_wx_FileHistory()
{
}

Object *Object_wx_FileHistory::Clone() const
{
	return nullptr;
}

String Object_wx_FileHistory::ToString(bool exprFlag)
{
	String rtn("<wx.FileHistory:");
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
Gura_DeclareMethod(wx_FileHistory, wxFileHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maxFiles", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idBase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, wxFileHistory)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maxFiles = arg.GetNumber(0)
	//int idBase = arg.GetNumber(1)
	//pThis->GetEntity()->wxFileHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, AddFileToHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, AddFileToHistory)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->AddFileToHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, AddFilesToMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, AddFilesToMenu)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AddFilesToMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, AddFilesToMenu_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, AddFilesToMenu_1)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->AddFilesToMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, GetBaseId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, GetBaseId)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBaseId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, GetCount)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, GetHistoryFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, GetHistoryFile)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetHistoryFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, GetMaxFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, GetMaxFiles)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, GetMenus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, GetMenus)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, Load)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int config = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, RemoveFileFromHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, RemoveFileFromHistory)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFileFromHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, RemoveMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, RemoveMenu)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, Save)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int config = arg.GetNumber(0)
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, SetBaseId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "baseId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, SetBaseId)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int baseId = arg.GetNumber(0)
	//pThis->GetEntity()->SetBaseId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileHistory, UseMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, UseMenu)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->UseMenu();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileHistory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileHistory)
{
	Gura_AssignMethod(wx_FileHistory, wxFileHistory);
	Gura_AssignMethod(wx_FileHistory, AddFileToHistory);
	Gura_AssignMethod(wx_FileHistory, AddFilesToMenu);
	Gura_AssignMethod(wx_FileHistory, AddFilesToMenu_1);
	Gura_AssignMethod(wx_FileHistory, GetBaseId);
	Gura_AssignMethod(wx_FileHistory, GetCount);
	Gura_AssignMethod(wx_FileHistory, GetHistoryFile);
	Gura_AssignMethod(wx_FileHistory, GetMaxFiles);
	Gura_AssignMethod(wx_FileHistory, GetMenus);
	Gura_AssignMethod(wx_FileHistory, Load);
	Gura_AssignMethod(wx_FileHistory, RemoveFileFromHistory);
	Gura_AssignMethod(wx_FileHistory, RemoveMenu);
	Gura_AssignMethod(wx_FileHistory, Save);
	Gura_AssignMethod(wx_FileHistory, SetBaseId);
	Gura_AssignMethod(wx_FileHistory, UseMenu);
}

Gura_ImplementDescendantCreator(wx_FileHistory)
{
	return new Object_wx_FileHistory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
