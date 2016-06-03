//----------------------------------------------------------------------------
// wxStaticBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticBox
//----------------------------------------------------------------------------
Object_wx_StaticBox::~Object_wx_StaticBox()
{
}

Object *Object_wx_StaticBox::Clone() const
{
	return nullptr;
}

String Object_wx_StaticBox::ToString(bool exprFlag)
{
	String rtn("<wx.StaticBox:");
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
Gura_DeclareMethodAlias(wx_StaticBox, __wxStaticBox, "wxStaticBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticBox, __wxStaticBox)
{
	Object_wx_StaticBox *pThis = Object_wx_StaticBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxStaticBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StaticBox, __wxStaticBox_1, "wxStaticBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticBox, __wxStaticBox_1)
{
	Object_wx_StaticBox *pThis = Object_wx_StaticBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxStaticBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StaticBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticBox, __Create)
{
	Object_wx_StaticBox *pThis = Object_wx_StaticBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStaticBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticBox)
{
	Gura_AssignMethod(wx_StaticBox, __wxStaticBox);
	Gura_AssignMethod(wx_StaticBox, __wxStaticBox_1);
	Gura_AssignMethod(wx_StaticBox, __Create);
}

Gura_ImplementDescendantCreator(wx_StaticBox)
{
	return new Object_wx_StaticBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
