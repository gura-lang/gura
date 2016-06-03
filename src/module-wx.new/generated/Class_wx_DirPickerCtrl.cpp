//----------------------------------------------------------------------------
// wxDirPickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDirPickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDirPickerCtrl
//----------------------------------------------------------------------------
Object_wx_DirPickerCtrl::~Object_wx_DirPickerCtrl()
{
}

Object *Object_wx_DirPickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DirPickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DirPickerCtrl:");
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
Gura_DeclareFunctionAlias(__DirPickerCtrl, "DirPickerCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DirPickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DirPickerCtrl)
{
	//wxDirPickerCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DirPickerCtrl_1, "DirPickerCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DirPickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DirPickerCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& path = arg.GetNumber(2)
	//const wxString& message = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxDirPickerCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DirPickerCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirPickerCtrl, __Create)
{
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& path = arg.GetNumber(2)
	//const wxString& message = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirPickerCtrl, __GetDirName, "GetDirName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirPickerCtrl, __GetDirName)
{
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDirName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirPickerCtrl, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirPickerCtrl, __GetPath)
{
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirPickerCtrl, __SetDirName, "SetDirName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirPickerCtrl, __SetDirName)
{
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFileName& dirname = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirPickerCtrl, __SetInitialDirectory, "SetInitialDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirPickerCtrl, __SetInitialDirectory)
{
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetInitialDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirPickerCtrl, __SetPath, "SetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirPickerCtrl, __SetPath)
{
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dirname = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDirPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirPickerCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__DirPickerCtrl);
	Gura_AssignFunction(__DirPickerCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_DirPickerCtrl, __Create);
	Gura_AssignMethod(wx_DirPickerCtrl, __GetDirName);
	Gura_AssignMethod(wx_DirPickerCtrl, __GetPath);
	Gura_AssignMethod(wx_DirPickerCtrl, __SetDirName);
	Gura_AssignMethod(wx_DirPickerCtrl, __SetInitialDirectory);
	Gura_AssignMethod(wx_DirPickerCtrl, __SetPath);
}

Gura_ImplementDescendantCreator(wx_DirPickerCtrl)
{
	return new Object_wx_DirPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
