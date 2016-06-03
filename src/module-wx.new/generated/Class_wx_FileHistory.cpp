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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FileHistory, "FileHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maxFiles", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idBase", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileHistory));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileHistory)
{
	//int maxFiles = arg.GetNumber(0)
	//int idBase = arg.GetNumber(1)
	//wxFileHistory();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileHistory, __AddFileToHistory, "AddFileToHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, __AddFileToHistory)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->AddFileToHistory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __AddFilesToMenu, "AddFilesToMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, __AddFilesToMenu)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AddFilesToMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __AddFilesToMenu_1, "AddFilesToMenu_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, __AddFilesToMenu_1)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->AddFilesToMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __GetBaseId, "GetBaseId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, __GetBaseId)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBaseId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, __GetCount)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __GetHistoryFile, "GetHistoryFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, __GetHistoryFile)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetHistoryFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __GetMaxFiles, "GetMaxFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, __GetMaxFiles)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxFiles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __GetMenus, "GetMenus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, __GetMenus)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, __Load)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int config = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __RemoveFileFromHistory, "RemoveFileFromHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, __RemoveFileFromHistory)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFileFromHistory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __RemoveMenu, "RemoveMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, __RemoveMenu)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __Save, "Save")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, __Save)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int config = arg.GetNumber(0)
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __SetBaseId, "SetBaseId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "baseId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, __SetBaseId)
{
	Object_wx_FileHistory *pThis = Object_wx_FileHistory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int baseId = arg.GetNumber(0)
	//pThis->GetEntity()->SetBaseId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileHistory, __UseMenu, "UseMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, __UseMenu)
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
	// Constructor assignment
	Gura_AssignFunction(__FileHistory);
	// Method assignment
	Gura_AssignMethod(wx_FileHistory, __AddFileToHistory);
	Gura_AssignMethod(wx_FileHistory, __AddFilesToMenu);
	Gura_AssignMethod(wx_FileHistory, __AddFilesToMenu_1);
	Gura_AssignMethod(wx_FileHistory, __GetBaseId);
	Gura_AssignMethod(wx_FileHistory, __GetCount);
	Gura_AssignMethod(wx_FileHistory, __GetHistoryFile);
	Gura_AssignMethod(wx_FileHistory, __GetMaxFiles);
	Gura_AssignMethod(wx_FileHistory, __GetMenus);
	Gura_AssignMethod(wx_FileHistory, __Load);
	Gura_AssignMethod(wx_FileHistory, __RemoveFileFromHistory);
	Gura_AssignMethod(wx_FileHistory, __RemoveMenu);
	Gura_AssignMethod(wx_FileHistory, __Save);
	Gura_AssignMethod(wx_FileHistory, __SetBaseId);
	Gura_AssignMethod(wx_FileHistory, __UseMenu);
}

Gura_ImplementDescendantCreator(wx_FileHistory)
{
	return new Object_wx_FileHistory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
