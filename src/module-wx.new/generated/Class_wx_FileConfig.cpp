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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FileConfig, wxFileConfig)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "appName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vendorName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "localFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "globalFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, wxFileConfig)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int appName = arg.GetNumber(0)
	//int vendorName = arg.GetNumber(1)
	//int localFilename = arg.GetNumber(2)
	//int globalFilename = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int conv = arg.GetNumber(5)
	//pThis->GetEntity()->wxFileConfig();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, wxFileConfig_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "is", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, wxFileConfig_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int is = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxFileConfig();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetGlobalFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "basename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetGlobalFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int basename = arg.GetNumber(0)
	//pThis->GetEntity()->GetGlobalFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetLocalFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "basename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetLocalFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int basename = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetLocalFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetGlobalFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "szFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetGlobalFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int szFile = arg.GetNumber(0)
	//pThis->GetEntity()->GetGlobalFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetLocalFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "szFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetLocalFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int szFile = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetLocalFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "os", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, Save)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int os = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, SetUmask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, SetUmask)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetUmask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strPath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strPath = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileConfig, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetFirstGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetFirstGroup)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int lIndex = arg.GetNumber(1)
	//pThis->GetEntity()->GetFirstGroup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetNextGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetNextGroup)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int lIndex = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextGroup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetFirstEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetFirstEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int lIndex = arg.GetNumber(1)
	//pThis->GetEntity()->GetFirstEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetNextEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int lIndex = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetNumberOfEntries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bRecursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetNumberOfEntries)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bRecursive = arg.GetNumber(0)
	//pThis->GetEntity()->GetNumberOfEntries();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, GetNumberOfGroups)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bRecursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, GetNumberOfGroups)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bRecursive = arg.GetNumber(0)
	//pThis->GetEntity()->GetNumberOfGroups();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, HasGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, HasGroup)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strName = arg.GetNumber(0)
	//pThis->GetEntity()->HasGroup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, HasEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, HasEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strName = arg.GetNumber(0)
	//pThis->GetEntity()->HasEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bCurrentOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, Flush)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bCurrentOnly = arg.GetNumber(0)
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, RenameEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, RenameEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int oldName = arg.GetNumber(0)
	//int newName = arg.GetNumber(1)
	//pThis->GetEntity()->RenameEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, RenameGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, RenameGroup)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int oldName = arg.GetNumber(0)
	//int newName = arg.GetNumber(1)
	//pThis->GetEntity()->RenameGroup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, DeleteEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bGroupIfEmptyAlso", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, DeleteEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//int bGroupIfEmptyAlso = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, DeleteGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "szKey", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, DeleteGroup)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int szKey = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteGroup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileConfig, DeleteAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileConfig, DeleteAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteAll();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileConfig
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileConfig)
{
	Gura_AssignMethod(wx_FileConfig, wxFileConfig);
	Gura_AssignMethod(wx_FileConfig, wxFileConfig_1);
	Gura_AssignMethod(wx_FileConfig, GetGlobalFile);
	Gura_AssignMethod(wx_FileConfig, GetLocalFile);
	Gura_AssignMethod(wx_FileConfig, GetGlobalFileName);
	Gura_AssignMethod(wx_FileConfig, GetLocalFileName);
	Gura_AssignMethod(wx_FileConfig, Save);
	Gura_AssignMethod(wx_FileConfig, SetUmask);
	Gura_AssignMethod(wx_FileConfig, SetPath);
	Gura_AssignMethod(wx_FileConfig, GetPath);
	Gura_AssignMethod(wx_FileConfig, GetFirstGroup);
	Gura_AssignMethod(wx_FileConfig, GetNextGroup);
	Gura_AssignMethod(wx_FileConfig, GetFirstEntry);
	Gura_AssignMethod(wx_FileConfig, GetNextEntry);
	Gura_AssignMethod(wx_FileConfig, GetNumberOfEntries);
	Gura_AssignMethod(wx_FileConfig, GetNumberOfGroups);
	Gura_AssignMethod(wx_FileConfig, HasGroup);
	Gura_AssignMethod(wx_FileConfig, HasEntry);
	Gura_AssignMethod(wx_FileConfig, Flush);
	Gura_AssignMethod(wx_FileConfig, RenameEntry);
	Gura_AssignMethod(wx_FileConfig, RenameGroup);
	Gura_AssignMethod(wx_FileConfig, DeleteEntry);
	Gura_AssignMethod(wx_FileConfig, DeleteGroup);
	Gura_AssignMethod(wx_FileConfig, DeleteAll);
}

Gura_ImplementDescendantCreator(wx_FileConfig)
{
	return new Object_wx_FileConfig((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
