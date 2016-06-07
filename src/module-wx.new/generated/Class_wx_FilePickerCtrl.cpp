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
Gura_DeclareFunctionAlias(__FilePickerCtrl, "FilePickerCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FilePickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FilePickerCtrl)
{
	//wxFilePickerCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FilePickerCtrl_1, "FilePickerCtrl_1")
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

Gura_ImplementFunction(__FilePickerCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& path = arg.GetNumber(2)
	//const wxString& message = arg.GetNumber(3)
	//const wxString& wildcard = arg.GetNumber(4)
	//const wxPoint& pos = arg.GetNumber(5)
	//const wxSize& size = arg.GetNumber(6)
	//long style = arg.GetNumber(7)
	//const wxValidator& validator = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//wxFilePickerCtrl(parent, id, path, message, wildcard, pos, size, style, validator, name);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& path = arg.GetNumber(2)
	//const wxString& message = arg.GetNumber(3)
	//const wxString& wildcard = arg.GetNumber(4)
	//const wxPoint& pos = arg.GetNumber(5)
	//const wxSize& size = arg.GetNumber(6)
	//long style = arg.GetNumber(7)
	//const wxValidator& validator = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//pThis->GetEntity()->Create(parent, id, path, message, wildcard, pos, size, style, validator, name);
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
	//const wxFileName& filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileName(filename);
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
	//const wxString& dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetInitialDirectory(dir);
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
	//const wxString& filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath(filename);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilePickerCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__FilePickerCtrl);
	Gura_AssignFunction(__FilePickerCtrl_1);
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
