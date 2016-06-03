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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DCOverlay, "DCOverlay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "overlay", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DCOverlay));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DCOverlay)
{
	//int overlay = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int x = arg.GetNumber(2)
	//int y = arg.GetNumber(3)
	//int width = arg.GetNumber(4)
	//int height = arg.GetNumber(5)
	//wxDCOverlay();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DCOverlay_1, "DCOverlay_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "overlay", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DCOverlay));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DCOverlay_1)
{
	//int overlay = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//wxDCOverlay();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DCOverlay, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DCOverlay, __Clear)
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
	// Constructor assignment
	Gura_AssignFunction(__DCOverlay);
	Gura_AssignFunction(__DCOverlay_1);
	// Method assignment
	Gura_AssignMethod(wx_DCOverlay, __Clear);
}

Gura_ImplementDescendantCreator(wx_DCOverlay)
{
	return new Object_wx_DCOverlay((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
