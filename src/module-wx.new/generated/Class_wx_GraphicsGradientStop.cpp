//----------------------------------------------------------------------------
// wxGraphicsGradientStop
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsGradientStop
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsGradientStop
//----------------------------------------------------------------------------
Object_wx_GraphicsGradientStop::~Object_wx_GraphicsGradientStop()
{
}

Object *Object_wx_GraphicsGradientStop::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsGradientStop::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsGradientStop:");
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
Gura_DeclareMethod(wx_GraphicsGradientStop, wxGraphicsGradientStop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStop, wxGraphicsGradientStop)
{
	Object_wx_GraphicsGradientStop *pThis = Object_wx_GraphicsGradientStop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->wxGraphicsGradientStop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStop, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStop, GetColour)
{
	Object_wx_GraphicsGradientStop *pThis = Object_wx_GraphicsGradientStop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStop, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStop, SetColour)
{
	Object_wx_GraphicsGradientStop *pThis = Object_wx_GraphicsGradientStop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStop, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStop, GetPosition)
{
	Object_wx_GraphicsGradientStop *pThis = Object_wx_GraphicsGradientStop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStop, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStop, SetPosition)
{
	Object_wx_GraphicsGradientStop *pThis = Object_wx_GraphicsGradientStop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsGradientStop
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsGradientStop)
{
	Gura_AssignMethod(wx_GraphicsGradientStop, wxGraphicsGradientStop);
	Gura_AssignMethod(wx_GraphicsGradientStop, GetColour);
	Gura_AssignMethod(wx_GraphicsGradientStop, SetColour);
	Gura_AssignMethod(wx_GraphicsGradientStop, GetPosition);
	Gura_AssignMethod(wx_GraphicsGradientStop, SetPosition);
}

Gura_ImplementDescendantCreator(wx_GraphicsGradientStop)
{
	return new Object_wx_GraphicsGradientStop((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
