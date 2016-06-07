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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GraphicsGradientStop, "GraphicsGradientStop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GraphicsGradientStop));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GraphicsGradientStop)
{
	//wxColour col = arg.GetNumber(0)
	//float pos = arg.GetNumber(1)
	//wxGraphicsGradientStop(col, pos);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GraphicsGradientStop, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStop, __GetColour)
{
	Object_wx_GraphicsGradientStop *pThis = Object_wx_GraphicsGradientStop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStop, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStop, __SetColour)
{
	Object_wx_GraphicsGradientStop *pThis = Object_wx_GraphicsGradientStop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStop, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStop, __GetPosition)
{
	Object_wx_GraphicsGradientStop *pThis = Object_wx_GraphicsGradientStop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//float _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStop, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStop, __SetPosition)
{
	Object_wx_GraphicsGradientStop *pThis = Object_wx_GraphicsGradientStop::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//float pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition(pos);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsGradientStop
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsGradientStop)
{
	// Constructor assignment
	Gura_AssignFunction(__GraphicsGradientStop);
	// Method assignment
	Gura_AssignMethod(wx_GraphicsGradientStop, __GetColour);
	Gura_AssignMethod(wx_GraphicsGradientStop, __SetColour);
	Gura_AssignMethod(wx_GraphicsGradientStop, __GetPosition);
	Gura_AssignMethod(wx_GraphicsGradientStop, __SetPosition);
}

Gura_ImplementDescendantCreator(wx_GraphicsGradientStop)
{
	return new Object_wx_GraphicsGradientStop((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
