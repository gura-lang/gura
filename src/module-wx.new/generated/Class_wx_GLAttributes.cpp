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
Gura_DeclareMethod(wx_GLAttributes, RGBA)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, RGBA)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RGBA();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, BufferSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, BufferSize)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->BufferSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, Level)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, Level)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Level();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, DoubleBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, DoubleBuffer)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoubleBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, Stereo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, Stereo)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stereo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, AuxBuffers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, AuxBuffers)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->AuxBuffers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, MinRGBA)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mRed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mGreen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mBlue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mAlpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, MinRGBA)
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

Gura_DeclareMethod(wx_GLAttributes, Depth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, Depth)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Depth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, Stencil)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, Stencil)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Stencil();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, MinAcumRGBA)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mRed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mGreen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mBlue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mAlpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, MinAcumRGBA)
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

Gura_DeclareMethod(wx_GLAttributes, SampleBuffers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, SampleBuffers)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SampleBuffers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, Samplers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLAttributes, Samplers)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Samplers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, FrameBuffersRGB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, FrameBuffersRGB)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FrameBuffersRGB();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, PlatformDefaults)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, PlatformDefaults)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PlatformDefaults();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, Defaults)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, Defaults)
{
	Object_wx_GLAttributes *pThis = Object_wx_GLAttributes::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Defaults();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLAttributes, EndList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLAttributes, EndList)
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
	Gura_AssignMethod(wx_GLAttributes, RGBA);
	Gura_AssignMethod(wx_GLAttributes, BufferSize);
	Gura_AssignMethod(wx_GLAttributes, Level);
	Gura_AssignMethod(wx_GLAttributes, DoubleBuffer);
	Gura_AssignMethod(wx_GLAttributes, Stereo);
	Gura_AssignMethod(wx_GLAttributes, AuxBuffers);
	Gura_AssignMethod(wx_GLAttributes, MinRGBA);
	Gura_AssignMethod(wx_GLAttributes, Depth);
	Gura_AssignMethod(wx_GLAttributes, Stencil);
	Gura_AssignMethod(wx_GLAttributes, MinAcumRGBA);
	Gura_AssignMethod(wx_GLAttributes, SampleBuffers);
	Gura_AssignMethod(wx_GLAttributes, Samplers);
	Gura_AssignMethod(wx_GLAttributes, FrameBuffersRGB);
	Gura_AssignMethod(wx_GLAttributes, PlatformDefaults);
	Gura_AssignMethod(wx_GLAttributes, Defaults);
	Gura_AssignMethod(wx_GLAttributes, EndList);
}

Gura_ImplementDescendantCreator(wx_GLAttributes)
{
	return new Object_wx_GLAttributes((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
