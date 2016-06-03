//----------------------------------------------------------------------------
// wxSimplebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSimplebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSimplebook
//----------------------------------------------------------------------------
Object_wx_Simplebook::~Object_wx_Simplebook()
{
}

Object *Object_wx_Simplebook::Clone() const
{
	return nullptr;
}

String Object_wx_Simplebook::ToString(bool exprFlag)
{
	String rtn("<wx.Simplebook:");
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
Gura_DeclareFunctionAlias(__Simplebook, "Simplebook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Simplebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Simplebook)
{
	//wxSimplebook();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Simplebook_1, "Simplebook_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Simplebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Simplebook_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//wxSimplebook();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Simplebook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, __Create)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_Simplebook, __SetEffects, "SetEffects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showEffect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hideEffect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, __SetEffects)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int showEffect = arg.GetNumber(0)
	//int hideEffect = arg.GetNumber(1)
	//pThis->GetEntity()->SetEffects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Simplebook, __SetEffect, "SetEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "effect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, __SetEffect)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int effect = arg.GetNumber(0)
	//pThis->GetEntity()->SetEffect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Simplebook, __SetEffectsTimeouts, "SetEffectsTimeouts")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showTimeout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hideTimeout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, __SetEffectsTimeouts)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int showTimeout = arg.GetNumber(0)
	//int hideTimeout = arg.GetNumber(1)
	//pThis->GetEntity()->SetEffectsTimeouts();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Simplebook, __SetEffectTimeout, "SetEffectTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timeout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, __SetEffectTimeout)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timeout = arg.GetNumber(0)
	//pThis->GetEntity()->SetEffectTimeout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Simplebook, __ShowNewPage, "ShowNewPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, __ShowNewPage)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->ShowNewPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSimplebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Simplebook)
{
	// Constructor assignment
	Gura_AssignFunction(__Simplebook);
	Gura_AssignFunction(__Simplebook_1);
	// Method assignment
	Gura_AssignMethod(wx_Simplebook, __Create);
	Gura_AssignMethod(wx_Simplebook, __SetEffects);
	Gura_AssignMethod(wx_Simplebook, __SetEffect);
	Gura_AssignMethod(wx_Simplebook, __SetEffectsTimeouts);
	Gura_AssignMethod(wx_Simplebook, __SetEffectTimeout);
	Gura_AssignMethod(wx_Simplebook, __ShowNewPage);
}

Gura_ImplementDescendantCreator(wx_Simplebook)
{
	return new Object_wx_Simplebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
