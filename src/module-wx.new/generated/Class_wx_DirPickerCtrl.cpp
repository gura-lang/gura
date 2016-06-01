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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DirPickerCtrl, wxDirPickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirPickerCtrl, wxDirPickerCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDirPickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirPickerCtrl, wxDirPickerCtrl_1)
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

Gura_ImplementMethod(wx_DirPickerCtrl, wxDirPickerCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int message = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxDirPickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirPickerCtrl, Create)
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

Gura_ImplementMethod(wx_DirPickerCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int message = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirPickerCtrl, GetDirName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirPickerCtrl, GetDirName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDirName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirPickerCtrl, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirPickerCtrl, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirPickerCtrl, SetDirName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirPickerCtrl, SetDirName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dirname = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirPickerCtrl, SetInitialDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirPickerCtrl, SetInitialDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetInitialDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirPickerCtrl, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirPickerCtrl, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dirname = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDirPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirPickerCtrl)
{
	Gura_AssignMethod(wx_DirPickerCtrl, wxDirPickerCtrl);
	Gura_AssignMethod(wx_DirPickerCtrl, wxDirPickerCtrl_1);
	Gura_AssignMethod(wx_DirPickerCtrl, Create);
	Gura_AssignMethod(wx_DirPickerCtrl, GetDirName);
	Gura_AssignMethod(wx_DirPickerCtrl, GetPath);
	Gura_AssignMethod(wx_DirPickerCtrl, SetDirName);
	Gura_AssignMethod(wx_DirPickerCtrl, SetInitialDirectory);
	Gura_AssignMethod(wx_DirPickerCtrl, SetPath);
}

Gura_ImplementDescendantCreator(wx_DirPickerCtrl)
{
	return new Object_wx_DirPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
