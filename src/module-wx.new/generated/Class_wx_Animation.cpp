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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Animation, "Animation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Animation));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Animation)
{
	//wxAnimation();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Animation_1, "Animation_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anim", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Animation));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Animation_1)
{
	//int anim = arg.GetNumber(0)
	//wxAnimation();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Animation_2, "Animation_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Animation));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Animation_2)
{
	//int name = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//wxAnimation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Animation, __GetDelay, "GetDelay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, __GetDelay)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetDelay();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Animation, __GetFrame, "GetFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, __GetFrame)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Animation, __GetFrameCount, "GetFrameCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Animation, __GetFrameCount)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFrameCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Animation, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Animation, __GetSize)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Animation, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Animation, __IsOk)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Animation, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, __Load)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Animation, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Animation, __LoadFile)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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
	// Constructor assignment
	Gura_AssignFunction(__Animation);
	Gura_AssignFunction(__Animation_1);
	Gura_AssignFunction(__Animation_2);
	// Method assignment
	Gura_AssignMethod(wx_Animation, __GetDelay);
	Gura_AssignMethod(wx_Animation, __GetFrame);
	Gura_AssignMethod(wx_Animation, __GetFrameCount);
	Gura_AssignMethod(wx_Animation, __GetSize);
	Gura_AssignMethod(wx_Animation, __IsOk);
	Gura_AssignMethod(wx_Animation, __Load);
	Gura_AssignMethod(wx_Animation, __LoadFile);
}

Gura_ImplementDescendantCreator(wx_Animation)
{
	return new Object_wx_Animation((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
