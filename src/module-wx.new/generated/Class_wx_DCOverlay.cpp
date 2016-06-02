//----------------------------------------------------------------------------
// wxDCOverlay
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCOverlay
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCOverlay
//----------------------------------------------------------------------------
Object_wx_DCOverlay::~Object_wx_DCOverlay()
{
}

Object *Object_wx_DCOverlay::Clone() const
{
	return nullptr;
}

String Object_wx_DCOverlay::ToString(bool exprFlag)
{
	String rtn("<wx.DCOverlay:");
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
Gura_DeclareMethod(wx_DCOverlay, wxDCOverlay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "overlay", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCOverlay, wxDCOverlay)
{
	Object_wx_DCOverlay *pThis = Object_wx_DCOverlay::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int overlay = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int x = arg.GetNumber(2)
	//int y = arg.GetNumber(3)
	//int width = arg.GetNumber(4)
	//int height = arg.GetNumber(5)
	//pThis->GetEntity()->wxDCOverlay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DCOverlay, wxDCOverlay_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "overlay", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCOverlay, wxDCOverlay_1)
{
	Object_wx_DCOverlay *pThis = Object_wx_DCOverlay::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int overlay = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//pThis->GetEntity()->wxDCOverlay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DCOverlay, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DCOverlay, Clear)
{
	Object_wx_DCOverlay *pThis = Object_wx_DCOverlay::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCOverlay
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCOverlay)
{
	Gura_AssignMethod(wx_DCOverlay, wxDCOverlay);
	Gura_AssignMethod(wx_DCOverlay, wxDCOverlay_1);
	Gura_AssignMethod(wx_DCOverlay, Clear);
}

Gura_ImplementDescendantCreator(wx_DCOverlay)
{
	return new Object_wx_DCOverlay((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
