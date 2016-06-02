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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Simplebook, wxSimplebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Simplebook, wxSimplebook)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSimplebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Simplebook, wxSimplebook_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, wxSimplebook_1)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxSimplebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Simplebook, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, Create)
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

Gura_DeclareMethod(wx_Simplebook, SetEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showEffect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hideEffect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, SetEffects)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int showEffect = arg.GetNumber(0)
	//int hideEffect = arg.GetNumber(1)
	//pThis->GetEntity()->SetEffects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Simplebook, SetEffect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "effect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, SetEffect)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int effect = arg.GetNumber(0)
	//pThis->GetEntity()->SetEffect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Simplebook, SetEffectsTimeouts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showTimeout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hideTimeout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, SetEffectsTimeouts)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int showTimeout = arg.GetNumber(0)
	//int hideTimeout = arg.GetNumber(1)
	//pThis->GetEntity()->SetEffectsTimeouts();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Simplebook, SetEffectTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timeout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, SetEffectTimeout)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timeout = arg.GetNumber(0)
	//pThis->GetEntity()->SetEffectTimeout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Simplebook, ShowNewPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, ShowNewPage)
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
	Gura_AssignMethod(wx_Simplebook, wxSimplebook);
	Gura_AssignMethod(wx_Simplebook, wxSimplebook_1);
	Gura_AssignMethod(wx_Simplebook, Create);
	Gura_AssignMethod(wx_Simplebook, SetEffects);
	Gura_AssignMethod(wx_Simplebook, SetEffect);
	Gura_AssignMethod(wx_Simplebook, SetEffectsTimeouts);
	Gura_AssignMethod(wx_Simplebook, SetEffectTimeout);
	Gura_AssignMethod(wx_Simplebook, ShowNewPage);
}

Gura_ImplementDescendantCreator(wx_Simplebook)
{
	return new Object_wx_Simplebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
