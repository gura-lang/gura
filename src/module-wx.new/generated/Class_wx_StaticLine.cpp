//----------------------------------------------------------------------------
// wxStaticLine
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticLine
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticLine
//----------------------------------------------------------------------------
Object_wx_StaticLine::~Object_wx_StaticLine()
{
}

Object *Object_wx_StaticLine::Clone() const
{
	return nullptr;
}

String Object_wx_StaticLine::ToString(bool exprFlag)
{
	String rtn("<wx.StaticLine:");
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
Gura_DeclareMethod(wx_StaticLine, wxStaticLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticLine, wxStaticLine)
{
	Object_wx_StaticLine *pThis = Object_wx_StaticLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxStaticLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticLine, wxStaticLine_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticLine, wxStaticLine_1)
{
	Object_wx_StaticLine *pThis = Object_wx_StaticLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxStaticLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticLine, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticLine, Create)
{
	Object_wx_StaticLine *pThis = Object_wx_StaticLine::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_StaticLine, GetDefaultSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticLine, GetDefaultSize)
{
	Object_wx_StaticLine *pThis = Object_wx_StaticLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticLine, IsVertical)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticLine, IsVertical)
{
	Object_wx_StaticLine *pThis = Object_wx_StaticLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVertical();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStaticLine
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticLine)
{
	Gura_AssignMethod(wx_StaticLine, wxStaticLine);
	Gura_AssignMethod(wx_StaticLine, wxStaticLine_1);
	Gura_AssignMethod(wx_StaticLine, Create);
	Gura_AssignMethod(wx_StaticLine, GetDefaultSize);
	Gura_AssignMethod(wx_StaticLine, IsVertical);
}

Gura_ImplementDescendantCreator(wx_StaticLine)
{
	return new Object_wx_StaticLine((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
