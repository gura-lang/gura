//----------------------------------------------------------------------------
// wxDirDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDirDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDirDialog
//----------------------------------------------------------------------------
Object_wx_DirDialog::~Object_wx_DirDialog()
{
}

Object *Object_wx_DirDialog::Clone() const
{
	return nullptr;
}

String Object_wx_DirDialog::ToString(bool exprFlag)
{
	String rtn("<wx.DirDialog:");
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
Gura_DeclareFunctionAlias(__DirDialog, "DirDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultPath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DirDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DirDialog)
{
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//const wxString& defaultPath = arg.GetNumber(2)
	//long style = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxDirDialog(parent, message, defaultPath, style, pos, size, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DirDialog, __GetMessage, "GetMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DirDialog, __GetMessage)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetMessage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirDialog, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DirDialog, __GetPath)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirDialog, __SetMessage, "SetMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirDialog, __SetMessage)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& message = arg.GetNumber(0)
	//pThis->GetEntity()->SetMessage(message);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirDialog, __SetPath, "SetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirDialog, __SetPath)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath(path);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirDialog, __ShowModal, "ShowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DirDialog, __ShowModal)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDirDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__DirDialog);
	// Method assignment
	Gura_AssignMethod(wx_DirDialog, __GetMessage);
	Gura_AssignMethod(wx_DirDialog, __GetPath);
	Gura_AssignMethod(wx_DirDialog, __SetMessage);
	Gura_AssignMethod(wx_DirDialog, __SetPath);
	Gura_AssignMethod(wx_DirDialog, __ShowModal);
}

Gura_ImplementDescendantCreator(wx_DirDialog)
{
	return new Object_wx_DirDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
