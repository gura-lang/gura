//----------------------------------------------------------------------------
// wxConfigBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxConfigBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConfigBase
//----------------------------------------------------------------------------
Object_wx_ConfigBase::~Object_wx_ConfigBase()
{
}

Object *Object_wx_ConfigBase::Clone() const
{
	return nullptr;
}

String Object_wx_ConfigBase::ToString(bool exprFlag)
{
	String rtn("<wx.ConfigBase:");
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
Gura_DeclareMethod(wx_ConfigBase, wxConfigBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "appName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vendorName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "localFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "globalFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, wxConfigBase)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int appName = arg.GetNumber(0)
	//int vendorName = arg.GetNumber(1)
	//int localFilename = arg.GetNumber(2)
	//int globalFilename = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int conv = arg.GetNumber(5)
	//pThis->GetEntity()->wxConfigBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigBase, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConfigBase, GetPath)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigBase, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strPath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, SetPath)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strPath = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigBase, GetFirstEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, GetFirstEntry)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->GetFirstEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigBase, GetFirstGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, GetFirstGroup)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->GetFirstGroup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigBase, GetNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, GetNextEntry)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigBase, GetNextGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, GetNextGroup)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextGroup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigBase, GetNumberOfEntries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bRecursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, GetNumberOfEntries)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bRecursive = arg.GetNumber(0)
	//pThis->GetEntity()->GetNumberOfEntries();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigBase, GetNumberOfGroups)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bRecursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, GetNumberOfGroups)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bRecursive = arg.GetNumber(0)
	//pThis->GetEntity()->GetNumberOfGroups();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxConfigBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConfigBase)
{
	Gura_AssignMethod(wx_ConfigBase, wxConfigBase);
	Gura_AssignMethod(wx_ConfigBase, GetPath);
	Gura_AssignMethod(wx_ConfigBase, SetPath);
	Gura_AssignMethod(wx_ConfigBase, GetFirstEntry);
	Gura_AssignMethod(wx_ConfigBase, GetFirstGroup);
	Gura_AssignMethod(wx_ConfigBase, GetNextEntry);
	Gura_AssignMethod(wx_ConfigBase, GetNextGroup);
	Gura_AssignMethod(wx_ConfigBase, GetNumberOfEntries);
	Gura_AssignMethod(wx_ConfigBase, GetNumberOfGroups);
}

Gura_ImplementDescendantCreator(wx_ConfigBase)
{
	return new Object_wx_ConfigBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
