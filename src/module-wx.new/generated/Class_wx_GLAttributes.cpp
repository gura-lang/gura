//----------------------------------------------------------------------------
// wxGLAttributes
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLAttributes
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLAttributes
//----------------------------------------------------------------------------
Object_wx_GLAttributes::~Object_wx_GLAttributes()
{
}

Object *Object_wx_GLAttributes::Clone() const
{
	return nullptr;
}

String Object_wx_GLAttributes::ToString(bool exprFlag)
{
	String rtn("<wx.GLAttributes:");
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
Gura_DeclareMethodAlias(wx_GLAttributes, __RGBA, "RGBA")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, __RGBA)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RGBA();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __BufferSize, "BufferSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, __BufferSize)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->BufferSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __Level, "Level")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, __Level)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Level();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __DoubleBuffer, "DoubleBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, __DoubleBuffer)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoubleBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __Stereo, "Stereo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, __Stereo)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stereo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __AuxBuffers, "AuxBuffers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, __AuxBuffers)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->AuxBuffers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __MinRGBA, "MinRGBA")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mRed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mGreen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mBlue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mAlpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, __MinRGBA)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mRed = arg.GetNumber(0)
	//int mGreen = arg.GetNumber(1)
	//int mBlue = arg.GetNumber(2)
	//int mAlpha = arg.GetNumber(3)
	//pThis->GetEntity()->MinRGBA();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __Depth, "Depth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, __Depth)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Depth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __Stencil, "Stencil")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, __Stencil)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Stencil();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __MinAcumRGBA, "MinAcumRGBA")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mRed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mGreen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mBlue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mAlpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, __MinAcumRGBA)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mRed = arg.GetNumber(0)
	//int mGreen = arg.GetNumber(1)
	//int mBlue = arg.GetNumber(2)
	//int mAlpha = arg.GetNumber(3)
	//pThis->GetEntity()->MinAcumRGBA();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __SampleBuffers, "SampleBuffers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, __SampleBuffers)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SampleBuffers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __Samplers, "Samplers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, __Samplers)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Samplers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __FrameBuffersRGB, "FrameBuffersRGB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, __FrameBuffersRGB)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FrameBuffersRGB();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __PlatformDefaults, "PlatformDefaults")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, __PlatformDefaults)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PlatformDefaults();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __Defaults, "Defaults")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, __Defaults)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Defaults();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLAttributes, __EndList, "EndList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, __EndList)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndList();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGLAttributes
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLAttributes)
{
	Gura_AssignMethod(wx_GLAttributes, __RGBA);
	Gura_AssignMethod(wx_GLAttributes, __BufferSize);
	Gura_AssignMethod(wx_GLAttributes, __Level);
	Gura_AssignMethod(wx_GLAttributes, __DoubleBuffer);
	Gura_AssignMethod(wx_GLAttributes, __Stereo);
	Gura_AssignMethod(wx_GLAttributes, __AuxBuffers);
	Gura_AssignMethod(wx_GLAttributes, __MinRGBA);
	Gura_AssignMethod(wx_GLAttributes, __Depth);
	Gura_AssignMethod(wx_GLAttributes, __Stencil);
	Gura_AssignMethod(wx_GLAttributes, __MinAcumRGBA);
	Gura_AssignMethod(wx_GLAttributes, __SampleBuffers);
	Gura_AssignMethod(wx_GLAttributes, __Samplers);
	Gura_AssignMethod(wx_GLAttributes, __FrameBuffersRGB);
	Gura_AssignMethod(wx_GLAttributes, __PlatformDefaults);
	Gura_AssignMethod(wx_GLAttributes, __Defaults);
	Gura_AssignMethod(wx_GLAttributes, __EndList);
}

Gura_ImplementDescendantCreator(wx_GLAttributes)
{
	return new Object_wx_GLAttributes((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
