//----------------------------------------------------------------------------
// wxSound
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSound
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSound
//----------------------------------------------------------------------------
Object_wx_Sound::~Object_wx_Sound()
{
}

Object *Object_wx_Sound::Clone() const
{
	return nullptr;
}

String Object_wx_Sound::ToString(bool exprFlag)
{
	String rtn("<wx.Sound:");
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
Gura_DeclareFunctionAlias(__wxSound, "wxSound")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Sound));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxSound)
{
	//wxSound();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxSound_1, "wxSound_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isResource", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Sound));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxSound_1)
{
	//int fileName = arg.GetNumber(0)
	//int isResource = arg.GetNumber(1)
	//wxSound();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxSound_2, "wxSound_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Sound));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxSound_2)
{
	//int size = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//wxSound();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Sound, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isResource", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, __Create)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//int isResource = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sound, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, __Create_1)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sound, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sound, __IsOk)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sound, __IsPlaying, "IsPlaying")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sound, __IsPlaying)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPlaying();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sound, __Play, "Play")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, __Play)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sound, __Play_1, "Play_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sound, __Play_1)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Play();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Sound, __Stop, "Stop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sound, __Stop)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSound
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Sound)
{
	// Constructor assignment
	Gura_AssignFunction(__wxSound);
	Gura_AssignFunction(__wxSound_1);
	Gura_AssignFunction(__wxSound_2);
	// Method assignment
	Gura_AssignMethod(wx_Sound, __Create);
	Gura_AssignMethod(wx_Sound, __Create_1);
	Gura_AssignMethod(wx_Sound, __IsOk);
	Gura_AssignMethod(wx_Sound, __IsPlaying);
	Gura_AssignMethod(wx_Sound, __Play);
	Gura_AssignMethod(wx_Sound, __Play_1);
	Gura_AssignMethod(wx_Sound, __Stop);
}

Gura_ImplementDescendantCreator(wx_Sound)
{
	return new Object_wx_Sound((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
