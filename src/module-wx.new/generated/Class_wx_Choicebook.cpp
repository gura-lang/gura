//----------------------------------------------------------------------------
// wxChoicebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxChoicebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxChoicebook
//----------------------------------------------------------------------------
Object_wx_Choicebook::~Object_wx_Choicebook()
{
}

Object *Object_wx_Choicebook::Clone() const
{
	return nullptr;
}

String Object_wx_Choicebook::ToString(bool exprFlag)
{
	String rtn("<wx.Choicebook:");
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
Gura_DeclareMethodAlias(wx_Choicebook, __wxChoicebook, "wxChoicebook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Choicebook, __wxChoicebook)
{
	Object_wx_Choicebook *pThis = Object_wx_Choicebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxChoicebook();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choicebook, __wxChoicebook_1, "wxChoicebook_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choicebook, __wxChoicebook_1)
{
	Object_wx_Choicebook *pThis = Object_wx_Choicebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxChoicebook();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choicebook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choicebook, __Create)
{
	Object_wx_Choicebook *pThis = Object_wx_Choicebook::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_Choicebook, __GetChoiceCtrl, "GetChoiceCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Choicebook, __GetChoiceCtrl)
{
	Object_wx_Choicebook *pThis = Object_wx_Choicebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChoiceCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxChoicebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Choicebook)
{
	Gura_AssignMethod(wx_Choicebook, __wxChoicebook);
	Gura_AssignMethod(wx_Choicebook, __wxChoicebook_1);
	Gura_AssignMethod(wx_Choicebook, __Create);
	Gura_AssignMethod(wx_Choicebook, __GetChoiceCtrl);
}

Gura_ImplementDescendantCreator(wx_Choicebook)
{
	return new Object_wx_Choicebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
