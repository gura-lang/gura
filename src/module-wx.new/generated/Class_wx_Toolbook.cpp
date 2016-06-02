//----------------------------------------------------------------------------
// wxToolbook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxToolbook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolbook
//----------------------------------------------------------------------------
Object_wx_Toolbook::~Object_wx_Toolbook()
{
}

Object *Object_wx_Toolbook::Clone() const
{
	return nullptr;
}

String Object_wx_Toolbook::ToString(bool exprFlag)
{
	String rtn("<wx.Toolbook:");
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
Gura_DeclareMethod(wx_Toolbook, wxToolbook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Toolbook, wxToolbook)
{
	Object_wx_Toolbook *pThis = Object_wx_Toolbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxToolbook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Toolbook, wxToolbook_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Toolbook, wxToolbook_1)
{
	Object_wx_Toolbook *pThis = Object_wx_Toolbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxToolbook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Toolbook, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Toolbook, Create)
{
	Object_wx_Toolbook *pThis = Object_wx_Toolbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Toolbook, GetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Toolbook, GetToolBar)
{
	Object_wx_Toolbook *pThis = Object_wx_Toolbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxToolbook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Toolbook)
{
	Gura_AssignMethod(wx_Toolbook, wxToolbook);
	Gura_AssignMethod(wx_Toolbook, wxToolbook_1);
	Gura_AssignMethod(wx_Toolbook, Create);
	Gura_AssignMethod(wx_Toolbook, GetToolBar);
}

Gura_ImplementDescendantCreator(wx_Toolbook)
{
	return new Object_wx_Toolbook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
