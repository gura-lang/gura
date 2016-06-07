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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ConfigBase, "ConfigBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "appName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vendorName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "localFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "globalFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ConfigBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ConfigBase)
{
	//const wxString& appName = arg.GetNumber(0)
	//const wxString& vendorName = arg.GetNumber(1)
	//const wxString& localFilename = arg.GetNumber(2)
	//const wxString& globalFilename = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxMBConv& conv = arg.GetNumber(5)
	//wxConfigBase(appName, vendorName, localFilename, globalFilename, style, conv);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ConfigBase, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ConfigBase, __GetPath)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConfigBase, __SetPath, "SetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strPath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, __SetPath)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& strPath = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath(strPath);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConfigBase, __GetFirstEntry, "GetFirstEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, __GetFirstEntry)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& str = arg.GetNumber(0)
	//long& index = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetFirstEntry(str, index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConfigBase, __GetFirstGroup, "GetFirstGroup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, __GetFirstGroup)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& str = arg.GetNumber(0)
	//long& index = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetFirstGroup(str, index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConfigBase, __GetNextEntry, "GetNextEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, __GetNextEntry)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& str = arg.GetNumber(0)
	//long& index = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetNextEntry(str, index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConfigBase, __GetNextGroup, "GetNextGroup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, __GetNextGroup)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& str = arg.GetNumber(0)
	//long& index = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetNextGroup(str, index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConfigBase, __GetNumberOfEntries, "GetNumberOfEntries")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bRecursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, __GetNumberOfEntries)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool bRecursive = arg.GetNumber(0)
	//size_t _rtn = pThis->GetEntity()->GetNumberOfEntries(bRecursive);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConfigBase, __GetNumberOfGroups, "GetNumberOfGroups")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bRecursive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, __GetNumberOfGroups)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool bRecursive = arg.GetNumber(0)
	//size_t _rtn = pThis->GetEntity()->GetNumberOfGroups(bRecursive);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxConfigBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConfigBase)
{
	// Constructor assignment
	Gura_AssignFunction(__ConfigBase);
	// Method assignment
	Gura_AssignMethod(wx_ConfigBase, __GetPath);
	Gura_AssignMethod(wx_ConfigBase, __SetPath);
	Gura_AssignMethod(wx_ConfigBase, __GetFirstEntry);
	Gura_AssignMethod(wx_ConfigBase, __GetFirstGroup);
	Gura_AssignMethod(wx_ConfigBase, __GetNextEntry);
	Gura_AssignMethod(wx_ConfigBase, __GetNextGroup);
	Gura_AssignMethod(wx_ConfigBase, __GetNumberOfEntries);
	Gura_AssignMethod(wx_ConfigBase, __GetNumberOfGroups);
}

Gura_ImplementDescendantCreator(wx_ConfigBase)
{
	return new Object_wx_ConfigBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
