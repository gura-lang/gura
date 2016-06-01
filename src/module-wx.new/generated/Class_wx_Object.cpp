//----------------------------------------------------------------------------
// wxObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxObject
//----------------------------------------------------------------------------
Object_wx_Object::~Object_wx_Object()
{
}

Object *Object_wx_Object::Clone() const
{
	return nullptr;
}

String Object_wx_Object::ToString(bool exprFlag)
{
	String rtn("<wx.Object:");
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
Gura_DeclareMethod(wx_Object, wxObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, wxObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, wxObject_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, wxObject_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->wxObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, ~wxObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, ~wxObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, GetClassInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, GetClassInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClassInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, GetRefData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, GetRefData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRefData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, IsKindOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, IsKindOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->IsKindOf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, IsSameAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, IsSameAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->IsSameAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, Ref)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, Ref)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int clone = arg.GetNumber(0)
	//pThis->GetEntity()->Ref();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, SetRefData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, SetRefData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetRefData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, UnRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, UnRef)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UnRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, UnShare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, UnShare)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UnShare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, delete)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, new)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lineNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, new)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int filename = arg.GetNumber(1)
	//int lineNum = arg.GetNumber(2)
	//pThis->GetEntity()->new();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, AllocExclusive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, AllocExclusive)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AllocExclusive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, CreateRefData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, CreateRefData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreateRefData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, CloneRefData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, CloneRefData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->CloneRefData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Object)
{
	Gura_AssignMethod(wx_Object, wxObject);
	Gura_AssignMethod(wx_Object, wxObject_1);
	Gura_AssignMethod(wx_Object, ~wxObject);
	Gura_AssignMethod(wx_Object, GetClassInfo);
	Gura_AssignMethod(wx_Object, GetRefData);
	Gura_AssignMethod(wx_Object, IsKindOf);
	Gura_AssignMethod(wx_Object, IsSameAs);
	Gura_AssignMethod(wx_Object, Ref);
	Gura_AssignMethod(wx_Object, SetRefData);
	Gura_AssignMethod(wx_Object, UnRef);
	Gura_AssignMethod(wx_Object, UnShare);
	Gura_AssignMethod(wx_Object, delete);
	Gura_AssignMethod(wx_Object, new);
	Gura_AssignMethod(wx_Object, AllocExclusive);
	Gura_AssignMethod(wx_Object, CreateRefData);
	Gura_AssignMethod(wx_Object, CloneRefData);
}

Gura_ImplementDescendantCreator(wx_Object)
{
	return new Object_wx_Object((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
