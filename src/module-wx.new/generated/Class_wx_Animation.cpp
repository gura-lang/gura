//----------------------------------------------------------------------------
// wxAnimation
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnimation
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnimation
//----------------------------------------------------------------------------
Object_wx_Animation::~Object_wx_Animation()
{
}

Object *Object_wx_Animation::Clone() const
{
	return nullptr;
}

String Object_wx_Animation::ToString(bool exprFlag)
{
	String rtn("<wx.Animation:");
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
Gura_DeclareMethod(wx_Animation, wxAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Animation, wxAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, wxAnimation_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, wxAnimation_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int anim = arg.GetNumber(0)
	//pThis->GetEntity()->wxAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, wxAnimation_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, wxAnimation_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->wxAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, ~wxAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Animation, ~wxAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, GetDelay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, GetDelay)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetDelay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, GetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, GetFrameCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Animation, GetFrameCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFrameCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Animation, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Animation, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, Load)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Animation, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAnimation
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Animation)
{
	Gura_AssignMethod(wx_Animation, wxAnimation);
	Gura_AssignMethod(wx_Animation, wxAnimation_1);
	Gura_AssignMethod(wx_Animation, wxAnimation_2);
	Gura_AssignMethod(wx_Animation, ~wxAnimation);
	Gura_AssignMethod(wx_Animation, GetDelay);
	Gura_AssignMethod(wx_Animation, GetFrame);
	Gura_AssignMethod(wx_Animation, GetFrameCount);
	Gura_AssignMethod(wx_Animation, GetSize);
	Gura_AssignMethod(wx_Animation, IsOk);
	Gura_AssignMethod(wx_Animation, Load);
	Gura_AssignMethod(wx_Animation, LoadFile);
}

Gura_ImplementDescendantCreator(wx_Animation)
{
	return new Object_wx_Animation((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
