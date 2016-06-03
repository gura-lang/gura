//----------------------------------------------------------------------------
// wxFileConfig
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileConfig
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileConfig
//----------------------------------------------------------------------------
Object_wx_FileConfig::~Object_wx_FileConfig()
{
}

Object *Object_wx_FileConfig::Clone() const
{
	return nullptr;
}

String Object_wx_FileConfig::ToString(bool exprFlag)
{
	String rtn("<wx.FileConfig:");
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
Gura_DeclareFunctionAlias(__wxFileConfig, "wxFileConfig")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "appName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vendorName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "localFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "globalFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileConfig));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileConfig)
{
	//int appName = arg.GetNumber(0)
	//int vendorName = arg.GetNumber(1)
	//int localFilename = arg.GetNumber(2)
	//int globalFilename = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int conv = arg.GetNumber(5)
	//wxFileConfig();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFileConfig_1, "wxFileConfig_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "is", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileConfig));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileConfig_1)
{
	//int is = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//wxFileConfig();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileConfig, __GetGlobalFile, "GetGlobalFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "basename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetGlobalFile)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int basename = arg.GetNumber(0)
	//pThis->GetEntity()->GetGlobalFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetLocalFile, "GetLocalFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "basename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetLocalFile)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int basename = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetLocalFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetGlobalFileName, "GetGlobalFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "szFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetGlobalFileName)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int szFile = arg.GetNumber(0)
	//pThis->GetEntity()->GetGlobalFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetLocalFileName, "GetLocalFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "szFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetLocalFileName)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int szFile = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetLocalFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __Save, "Save")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "os", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __Save)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int os = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __SetUmask, "SetUmask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __SetUmask)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetUmask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __SetPath, "SetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strPath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __SetPath)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strPath = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileConfig, __GetPath)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetFirstGroup, "GetFirstGroup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetFirstGroup)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int lIndex = arg.GetNumber(1)
	//pThis->GetEntity()->GetFirstGroup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetNextGroup, "GetNextGroup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetNextGroup)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int lIndex = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextGroup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetFirstEntry, "GetFirstEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetFirstEntry)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int lIndex = arg.GetNumber(1)
	//pThis->GetEntity()->GetFirstEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetNextEntry, "GetNextEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetNextEntry)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int lIndex = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetNumberOfEntries, "GetNumberOfEntries")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bRecursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetNumberOfEntries)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bRecursive = arg.GetNumber(0)
	//pThis->GetEntity()->GetNumberOfEntries();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __GetNumberOfGroups, "GetNumberOfGroups")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bRecursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __GetNumberOfGroups)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bRecursive = arg.GetNumber(0)
	//pThis->GetEntity()->GetNumberOfGroups();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __HasGroup, "HasGroup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __HasGroup)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strName = arg.GetNumber(0)
	//pThis->GetEntity()->HasGroup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __HasEntry, "HasEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __HasEntry)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strName = arg.GetNumber(0)
	//pThis->GetEntity()->HasEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __Flush, "Flush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bCurrentOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __Flush)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bCurrentOnly = arg.GetNumber(0)
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __RenameEntry, "RenameEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __RenameEntry)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldName = arg.GetNumber(0)
	//int newName = arg.GetNumber(1)
	//pThis->GetEntity()->RenameEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __RenameGroup, "RenameGroup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __RenameGroup)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldName = arg.GetNumber(0)
	//int newName = arg.GetNumber(1)
	//pThis->GetEntity()->RenameGroup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __DeleteEntry, "DeleteEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bGroupIfEmptyAlso", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __DeleteEntry)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//int bGroupIfEmptyAlso = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __DeleteGroup, "DeleteGroup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "szKey", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, __DeleteGroup)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int szKey = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteGroup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileConfig, __DeleteAll, "DeleteAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileConfig, __DeleteAll)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAll();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileConfig
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileConfig)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFileConfig);
	Gura_AssignFunction(__wxFileConfig_1);
	// Method assignment
	Gura_AssignMethod(wx_FileConfig, __GetGlobalFile);
	Gura_AssignMethod(wx_FileConfig, __GetLocalFile);
	Gura_AssignMethod(wx_FileConfig, __GetGlobalFileName);
	Gura_AssignMethod(wx_FileConfig, __GetLocalFileName);
	Gura_AssignMethod(wx_FileConfig, __Save);
	Gura_AssignMethod(wx_FileConfig, __SetUmask);
	Gura_AssignMethod(wx_FileConfig, __SetPath);
	Gura_AssignMethod(wx_FileConfig, __GetPath);
	Gura_AssignMethod(wx_FileConfig, __GetFirstGroup);
	Gura_AssignMethod(wx_FileConfig, __GetNextGroup);
	Gura_AssignMethod(wx_FileConfig, __GetFirstEntry);
	Gura_AssignMethod(wx_FileConfig, __GetNextEntry);
	Gura_AssignMethod(wx_FileConfig, __GetNumberOfEntries);
	Gura_AssignMethod(wx_FileConfig, __GetNumberOfGroups);
	Gura_AssignMethod(wx_FileConfig, __HasGroup);
	Gura_AssignMethod(wx_FileConfig, __HasEntry);
	Gura_AssignMethod(wx_FileConfig, __Flush);
	Gura_AssignMethod(wx_FileConfig, __RenameEntry);
	Gura_AssignMethod(wx_FileConfig, __RenameGroup);
	Gura_AssignMethod(wx_FileConfig, __DeleteEntry);
	Gura_AssignMethod(wx_FileConfig, __DeleteGroup);
	Gura_AssignMethod(wx_FileConfig, __DeleteAll);
}

Gura_ImplementDescendantCreator(wx_FileConfig)
{
	return new Object_wx_FileConfig((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
