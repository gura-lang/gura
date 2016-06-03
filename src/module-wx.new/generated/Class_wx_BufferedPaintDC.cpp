//----------------------------------------------------------------------------
// wxBufferedPaintDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedPaintDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedPaintDC
//----------------------------------------------------------------------------
Object_wx_BufferedPaintDC::~Object_wx_BufferedPaintDC()
{
}

Object *Object_wx_BufferedPaintDC::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedPaintDC::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedPaintDC:");
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
Gura_DeclareMethodAlias(wx_BufferedPaintDC, __wxBufferedPaintDC, "wxBufferedPaintDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedPaintDC, __wxBufferedPaintDC)
{
	Object_wx_BufferedPaintDC *pThis = Object_wx_BufferedPaintDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->wxBufferedPaintDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BufferedPaintDC, __wxBufferedPaintDC_1, "wxBufferedPaintDC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedPaintDC, __wxBufferedPaintDC_1)
{
	Object_wx_BufferedPaintDC *pThis = Object_wx_BufferedPaintDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->wxBufferedPaintDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedPaintDC)
{
	Gura_AssignMethod(wx_BufferedPaintDC, __wxBufferedPaintDC);
	Gura_AssignMethod(wx_BufferedPaintDC, __wxBufferedPaintDC_1);
}

Gura_ImplementDescendantCreator(wx_BufferedPaintDC)
{
	return new Object_wx_BufferedPaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
