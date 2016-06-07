//----------------------------------------------------------------------------
// wxAnimationCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnimationCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnimationCtrl
//----------------------------------------------------------------------------
Object_wx_AnimationCtrl::~Object_wx_AnimationCtrl()
{
}

Object *Object_wx_AnimationCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_AnimationCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.AnimationCtrl:");
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
Gura_DeclareFunctionAlias(__AnimationCtrl, "AnimationCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "anim", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AnimationCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AnimationCtrl)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxAnimation& anim = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxAnimationCtrl(parent, id, anim, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AnimationCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "anim", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, __Create)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxAnimation& anim = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, anim, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __GetAnimation, "GetAnimation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, __GetAnimation)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAnimation _rtn = pThis->GetEntity()->GetAnimation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __GetInactiveBitmap, "GetInactiveBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, __GetInactiveBitmap)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmap _rtn = pThis->GetEntity()->GetInactiveBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __IsPlaying, "IsPlaying")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, __IsPlaying)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsPlaying();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "animType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, __LoadFile)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& file = arg.GetNumber(0)
	//wxAnimationType animType = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->LoadFile(file, animType);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "animType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, __Load)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream& file = arg.GetNumber(0)
	//wxAnimationType animType = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Load(file, animType);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __Play, "Play")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, __Play)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __SetAnimation, "SetAnimation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, __SetAnimation)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAnimation& anim = arg.GetNumber(0)
	//pThis->GetEntity()->SetAnimation(anim);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __SetInactiveBitmap, "SetInactiveBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, __SetInactiveBitmap)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetInactiveBitmap(bmp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __Stop, "Stop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, __Stop)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAnimationCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnimationCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__AnimationCtrl);
	// Method assignment
	Gura_AssignMethod(wx_AnimationCtrl, __Create);
	Gura_AssignMethod(wx_AnimationCtrl, __GetAnimation);
	Gura_AssignMethod(wx_AnimationCtrl, __GetInactiveBitmap);
	Gura_AssignMethod(wx_AnimationCtrl, __IsPlaying);
	Gura_AssignMethod(wx_AnimationCtrl, __LoadFile);
	Gura_AssignMethod(wx_AnimationCtrl, __Load);
	Gura_AssignMethod(wx_AnimationCtrl, __Play);
	Gura_AssignMethod(wx_AnimationCtrl, __SetAnimation);
	Gura_AssignMethod(wx_AnimationCtrl, __SetInactiveBitmap);
	Gura_AssignMethod(wx_AnimationCtrl, __Stop);
}

Gura_ImplementDescendantCreator(wx_AnimationCtrl)
{
	return new Object_wx_AnimationCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
