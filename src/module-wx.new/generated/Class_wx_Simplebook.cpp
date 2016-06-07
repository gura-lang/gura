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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxSimplebook(parent, id, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Simplebook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, style, name);
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
	//wxShowEffect showEffect = arg.GetNumber(0)
	//wxShowEffect hideEffect = arg.GetNumber(1)
	//pThis->GetEntity()->SetEffects(showEffect, hideEffect);
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
	//wxShowEffect effect = arg.GetNumber(0)
	//pThis->GetEntity()->SetEffect(effect);
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
	//unsigned showTimeout = arg.GetNumber(0)
	//unsigned hideTimeout = arg.GetNumber(1)
	//pThis->GetEntity()->SetEffectsTimeouts(showTimeout, hideTimeout);
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
	//unsigned timeout = arg.GetNumber(0)
	//pThis->GetEntity()->SetEffectTimeout(timeout);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Simplebook, __ShowNewPage, "ShowNewPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Simplebook, __ShowNewPage)
{
	Object_wx_Simplebook *pThis = Object_wx_Simplebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ShowNewPage(page);
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
