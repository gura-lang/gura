//----------------------------------------------------------------------------
// wxFilePickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFilePickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Object_wx_FilePickerCtrl::~Object_wx_FilePickerCtrl()
{
}

Object *Object_wx_FilePickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_FilePickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FilePickerCtrl:");
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
Gura_DeclareFunctionAlias(__wxFilePickerCtrl, "wxFilePickerCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FilePickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFilePickerCtrl)
{
	//wxFilePickerCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFilePickerCtrl_1, "wxFilePickerCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FilePickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFilePickerCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int message = arg.GetNumber(3)
	//int wildcard = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//int size = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//wxFilePickerCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FilePickerCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilePickerCtrl, __Create)
{
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int message = arg.GetNumber(3)
	//int wildcard = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//int size = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilePickerCtrl, __GetFileName, "GetFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilePickerCtrl, __GetFileName)
{
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilePickerCtrl, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilePickerCtrl, __GetPath)
{
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilePickerCtrl, __SetFileName, "SetFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilePickerCtrl, __SetFileName)
{
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilePickerCtrl, __SetInitialDirectory, "SetInitialDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilePickerCtrl, __SetInitialDirectory)
{
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetInitialDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilePickerCtrl, __SetPath, "SetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilePickerCtrl, __SetPath)
{
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilePickerCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFilePickerCtrl);
	Gura_AssignFunction(__wxFilePickerCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_FilePickerCtrl, __Create);
	Gura_AssignMethod(wx_FilePickerCtrl, __GetFileName);
	Gura_AssignMethod(wx_FilePickerCtrl, __GetPath);
	Gura_AssignMethod(wx_FilePickerCtrl, __SetFileName);
	Gura_AssignMethod(wx_FilePickerCtrl, __SetInitialDirectory);
	Gura_AssignMethod(wx_FilePickerCtrl, __SetPath);
}

Gura_ImplementDescendantCreator(wx_FilePickerCtrl)
{
	return new Object_wx_FilePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
