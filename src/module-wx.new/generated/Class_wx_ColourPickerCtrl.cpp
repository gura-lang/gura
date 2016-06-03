//----------------------------------------------------------------------------
// wxColourPickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColourPickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxColourPickerCtrl
//----------------------------------------------------------------------------
Object_wx_ColourPickerCtrl::~Object_wx_ColourPickerCtrl()
{
}

Object *Object_wx_ColourPickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_ColourPickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.ColourPickerCtrl:");
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
Gura_DeclareFunctionAlias(__wxColourPickerCtrl, "wxColourPickerCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ColourPickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxColourPickerCtrl)
{
	//wxColourPickerCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxColourPickerCtrl_1, "wxColourPickerCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ColourPickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxColourPickerCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int colour = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//wxColourPickerCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ColourPickerCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, __Create)
{
	Object_wx_ColourPickerCtrl *pThis = Object_wx_ColourPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int colour = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ColourPickerCtrl, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, __GetColour)
{
	Object_wx_ColourPickerCtrl *pThis = Object_wx_ColourPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ColourPickerCtrl, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, __SetColour)
{
	Object_wx_ColourPickerCtrl *pThis = Object_wx_ColourPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ColourPickerCtrl, __SetColour_1, "SetColour_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, __SetColour_1)
{
	Object_wx_ColourPickerCtrl *pThis = Object_wx_ColourPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colname = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxColourPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourPickerCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__wxColourPickerCtrl);
	Gura_AssignFunction(__wxColourPickerCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_ColourPickerCtrl, __Create);
	Gura_AssignMethod(wx_ColourPickerCtrl, __GetColour);
	Gura_AssignMethod(wx_ColourPickerCtrl, __SetColour);
	Gura_AssignMethod(wx_ColourPickerCtrl, __SetColour_1);
}

Gura_ImplementDescendantCreator(wx_ColourPickerCtrl)
{
	return new Object_wx_ColourPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
