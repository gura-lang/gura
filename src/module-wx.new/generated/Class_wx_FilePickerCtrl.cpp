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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FilePickerCtrl, wxFilePickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilePickerCtrl, wxFilePickerCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFilePickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilePickerCtrl, wxFilePickerCtrl_1)
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

Gura_ImplementMethod(wx_FilePickerCtrl, wxFilePickerCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	//pThis->GetEntity()->wxFilePickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilePickerCtrl, Create)
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

Gura_ImplementMethod(wx_FilePickerCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_FilePickerCtrl, GetFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilePickerCtrl, GetFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilePickerCtrl, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilePickerCtrl, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilePickerCtrl, SetFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilePickerCtrl, SetFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilePickerCtrl, SetInitialDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilePickerCtrl, SetInitialDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetInitialDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilePickerCtrl, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilePickerCtrl, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilePickerCtrl)
{
	Gura_AssignMethod(wx_FilePickerCtrl, wxFilePickerCtrl);
	Gura_AssignMethod(wx_FilePickerCtrl, wxFilePickerCtrl_1);
	Gura_AssignMethod(wx_FilePickerCtrl, Create);
	Gura_AssignMethod(wx_FilePickerCtrl, GetFileName);
	Gura_AssignMethod(wx_FilePickerCtrl, GetPath);
	Gura_AssignMethod(wx_FilePickerCtrl, SetFileName);
	Gura_AssignMethod(wx_FilePickerCtrl, SetInitialDirectory);
	Gura_AssignMethod(wx_FilePickerCtrl, SetPath);
}

Gura_ImplementDescendantCreator(wx_FilePickerCtrl)
{
	return new Object_wx_FilePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
