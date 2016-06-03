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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Object, "Object")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Object));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Object)
{
	//wxObject();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Object_1, "Object_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Object));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Object_1)
{
	//const wxObject& other = arg.GetNumber(0)
	//wxObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Object, __GetClassInfo, "GetClassInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, __GetClassInfo)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClassInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __GetRefData, "GetRefData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, __GetRefData)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRefData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __IsKindOf, "IsKindOf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, __IsKindOf)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxClassInfo* info = arg.GetNumber(0)
	//pThis->GetEntity()->IsKindOf();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __IsSameAs, "IsSameAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, __IsSameAs)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxObject& obj = arg.GetNumber(0)
	//pThis->GetEntity()->IsSameAs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __Ref, "Ref")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, __Ref)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxObject& clone = arg.GetNumber(0)
	//pThis->GetEntity()->Ref();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __SetRefData, "SetRefData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, __SetRefData)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxObjectRefData* data = arg.GetNumber(0)
	//pThis->GetEntity()->SetRefData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __UnRef, "UnRef")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, __UnRef)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnRef();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __UnShare, "UnShare")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, __UnShare)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnShare();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __delete, "delete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, __delete)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* buf = arg.GetNumber(0)
	//pThis->GetEntity()->delete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __new, "new")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lineNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, __new)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t size = arg.GetNumber(0)
	//const wxString& filename = arg.GetNumber(1)
	//int lineNum = arg.GetNumber(2)
	//pThis->GetEntity()->new();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __AllocExclusive, "AllocExclusive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, __AllocExclusive)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AllocExclusive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __CreateRefData, "CreateRefData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, __CreateRefData)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateRefData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Object, __CloneRefData, "CloneRefData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, __CloneRefData)
{
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxObjectRefData* data = arg.GetNumber(0)
	//pThis->GetEntity()->CloneRefData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Object)
{
	// Constructor assignment
	Gura_AssignFunction(__Object);
	Gura_AssignFunction(__Object_1);
	// Method assignment
	Gura_AssignMethod(wx_Object, __GetClassInfo);
	Gura_AssignMethod(wx_Object, __GetRefData);
	Gura_AssignMethod(wx_Object, __IsKindOf);
	Gura_AssignMethod(wx_Object, __IsSameAs);
	Gura_AssignMethod(wx_Object, __Ref);
	Gura_AssignMethod(wx_Object, __SetRefData);
	Gura_AssignMethod(wx_Object, __UnRef);
	Gura_AssignMethod(wx_Object, __UnShare);
	Gura_AssignMethod(wx_Object, __delete);
	Gura_AssignMethod(wx_Object, __new);
	Gura_AssignMethod(wx_Object, __AllocExclusive);
	Gura_AssignMethod(wx_Object, __CreateRefData);
	Gura_AssignMethod(wx_Object, __CloneRefData);
}

Gura_ImplementDescendantCreator(wx_Object)
{
	return new Object_wx_Object((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
