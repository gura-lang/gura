//----------------------------------------------------------------------------
// wxListbook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListbook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListbook
//----------------------------------------------------------------------------
Object_wx_Listbook::~Object_wx_Listbook()
{
}

Object *Object_wx_Listbook::Clone() const
{
	return nullptr;
}

String Object_wx_Listbook::ToString(bool exprFlag)
{
	String rtn("<wx.Listbook:");
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
Gura_DeclareMethod(wx_Listbook, wxListbook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Listbook, wxListbook)
{
	Object_wx_Listbook *pThis = Object_wx_Listbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxListbook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Listbook, wxListbook_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Listbook, wxListbook_1)
{
	Object_wx_Listbook *pThis = Object_wx_Listbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxListbook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Listbook, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Listbook, Create)
{
	Object_wx_Listbook *pThis = Object_wx_Listbook::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_Listbook, GetListView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Listbook, GetListView)
{
	Object_wx_Listbook *pThis = Object_wx_Listbook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetListView();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListbook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Listbook)
{
	Gura_AssignMethod(wx_Listbook, wxListbook);
	Gura_AssignMethod(wx_Listbook, wxListbook_1);
	Gura_AssignMethod(wx_Listbook, Create);
	Gura_AssignMethod(wx_Listbook, GetListView);
}

Gura_ImplementDescendantCreator(wx_Listbook)
{
	return new Object_wx_Listbook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
