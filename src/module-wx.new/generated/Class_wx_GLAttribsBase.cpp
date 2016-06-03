//----------------------------------------------------------------------------
// wxGLAttribsBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLAttribsBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLAttribsBase
//----------------------------------------------------------------------------
Object_wx_GLAttribsBase::~Object_wx_GLAttribsBase()
{
}

Object *Object_wx_GLAttribsBase::Clone() const
{
	return nullptr;
}

String Object_wx_GLAttribsBase::ToString(bool exprFlag)
{
	String rtn("<wx.GLAttribsBase:");
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
Gura_DeclareMethodAlias(wx_GLAttribsBase, __wxGLAttribsBase, "wxGLAttribsBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttribsBase, __wxGLAttribsBase)
{
	Object_wx_GLAttribsBase *pThis = Object_wx_GLAttribsBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGLAttribsBase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttribsBase, __AddAttribute, "AddAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attribute", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttribsBase, __AddAttribute)
{
	Object_wx_GLAttribsBase *pThis = Object_wx_GLAttribsBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attribute = arg.GetNumber(0)
	//pThis->GetEntity()->AddAttribute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttribsBase, __AddAttribBits, "AddAttribBits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "searchVal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "combineVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttribsBase, __AddAttribBits)
{
	Object_wx_GLAttribsBase *pThis = Object_wx_GLAttribsBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int searchVal = arg.GetNumber(0)
	//int combineVal = arg.GetNumber(1)
	//pThis->GetEntity()->AddAttribBits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttribsBase, __SetNeedsARB, "SetNeedsARB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "needsARB", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttribsBase, __SetNeedsARB)
{
	Object_wx_GLAttribsBase *pThis = Object_wx_GLAttribsBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int needsARB = arg.GetNumber(0)
	//pThis->GetEntity()->SetNeedsARB();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttribsBase, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttribsBase, __Reset)
{
	Object_wx_GLAttribsBase *pThis = Object_wx_GLAttribsBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttribsBase, __GetGLAttrs, "GetGLAttrs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttribsBase, __GetGLAttrs)
{
	Object_wx_GLAttribsBase *pThis = Object_wx_GLAttribsBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGLAttrs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttribsBase, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttribsBase, __GetSize)
{
	Object_wx_GLAttribsBase *pThis = Object_wx_GLAttribsBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttribsBase, __NeedsARB, "NeedsARB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttribsBase, __NeedsARB)
{
	Object_wx_GLAttribsBase *pThis = Object_wx_GLAttribsBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->NeedsARB();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGLAttribsBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLAttribsBase)
{
	Gura_AssignMethod(wx_GLAttribsBase, __wxGLAttribsBase);
	Gura_AssignMethod(wx_GLAttribsBase, __AddAttribute);
	Gura_AssignMethod(wx_GLAttribsBase, __AddAttribBits);
	Gura_AssignMethod(wx_GLAttribsBase, __SetNeedsARB);
	Gura_AssignMethod(wx_GLAttribsBase, __Reset);
	Gura_AssignMethod(wx_GLAttribsBase, __GetGLAttrs);
	Gura_AssignMethod(wx_GLAttribsBase, __GetSize);
	Gura_AssignMethod(wx_GLAttribsBase, __NeedsARB);
}

Gura_ImplementDescendantCreator(wx_GLAttribsBase)
{
	return new Object_wx_GLAttribsBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
