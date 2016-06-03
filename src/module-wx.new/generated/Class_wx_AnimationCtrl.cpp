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
Gura_DeclareFunctionAlias(__wxAnimationCtrl, "wxAnimationCtrl")
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

Gura_ImplementFunction(__wxAnimationCtrl)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int anim = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//wxAnimationCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AnimationCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_AnimationCtrl, __Create)
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

Gura_DeclareMethodAlias(wx_AnimationCtrl, __GetAnimation, "GetAnimation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, __GetAnimation)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAnimation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __GetInactiveBitmap, "GetInactiveBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, __GetInactiveBitmap)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInactiveBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __IsPlaying, "IsPlaying")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, __IsPlaying)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPlaying();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "animType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, __LoadFile)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int animType = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "animType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, __Load)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int animType = arg.GetNumber(1)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnimationCtrl, __Play, "Play")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, __Play)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Play();
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
	//int anim = arg.GetNumber(0)
	//pThis->GetEntity()->SetAnimation();
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
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetInactiveBitmap();
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
	Gura_AssignFunction(__wxAnimationCtrl);
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
