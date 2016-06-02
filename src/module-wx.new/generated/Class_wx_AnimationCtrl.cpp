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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AnimationCtrl, wxAnimationCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "anim", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, wxAnimationCtrl)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int anim = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxAnimationCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "anim", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, Create)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int anim = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, GetAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, GetAnimation)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, GetInactiveBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, GetInactiveBitmap)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInactiveBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, IsPlaying)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, IsPlaying)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPlaying();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "animType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, LoadFile)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int animType = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "animType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, Load)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int animType = arg.GetNumber(1)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, Play)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, Play)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, SetAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, SetAnimation)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int anim = arg.GetNumber(0)
	//pThis->GetEntity()->SetAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, SetInactiveBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, SetInactiveBitmap)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetInactiveBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnimationCtrl, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, Stop)
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
	Gura_AssignMethod(wx_AnimationCtrl, wxAnimationCtrl);
	Gura_AssignMethod(wx_AnimationCtrl, Create);
	Gura_AssignMethod(wx_AnimationCtrl, GetAnimation);
	Gura_AssignMethod(wx_AnimationCtrl, GetInactiveBitmap);
	Gura_AssignMethod(wx_AnimationCtrl, IsPlaying);
	Gura_AssignMethod(wx_AnimationCtrl, LoadFile);
	Gura_AssignMethod(wx_AnimationCtrl, Load);
	Gura_AssignMethod(wx_AnimationCtrl, Play);
	Gura_AssignMethod(wx_AnimationCtrl, SetAnimation);
	Gura_AssignMethod(wx_AnimationCtrl, SetInactiveBitmap);
	Gura_AssignMethod(wx_AnimationCtrl, Stop);
}

Gura_ImplementDescendantCreator(wx_AnimationCtrl)
{
	return new Object_wx_AnimationCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
