//----------------------------------------------------------------------------
// wxStaticBoxSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticBoxSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticBoxSizer
//----------------------------------------------------------------------------
Object_wx_StaticBoxSizer::~Object_wx_StaticBoxSizer()
{
}

Object *Object_wx_StaticBoxSizer::Clone() const
{
	return nullptr;
}

String Object_wx_StaticBoxSizer::ToString(bool exprFlag)
{
	String rtn("<wx.StaticBoxSizer:");
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
Gura_DeclareFunctionAlias(__StaticBoxSizer, "StaticBoxSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "box", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StaticBoxSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StaticBoxSizer)
{
	//wxStaticBox* box = arg.GetNumber(0)
	//int orient = arg.GetNumber(1)
	//wxStaticBoxSizer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__StaticBoxSizer_1, "StaticBoxSizer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StaticBoxSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StaticBoxSizer_1)
{
	//int orient = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//wxStaticBoxSizer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StaticBoxSizer, __GetStaticBox, "GetStaticBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticBoxSizer, __GetStaticBox)
{
	Object_wx_StaticBoxSizer *pThis = Object_wx_StaticBoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStaticBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StaticBoxSizer, __CalcMin, "CalcMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticBoxSizer, __CalcMin)
{
	Object_wx_StaticBoxSizer *pThis = Object_wx_StaticBoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StaticBoxSizer, __RecalcSizes, "RecalcSizes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticBoxSizer, __RecalcSizes)
{
	Object_wx_StaticBoxSizer *pThis = Object_wx_StaticBoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStaticBoxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticBoxSizer)
{
	// Constructor assignment
	Gura_AssignFunction(__StaticBoxSizer);
	Gura_AssignFunction(__StaticBoxSizer_1);
	// Method assignment
	Gura_AssignMethod(wx_StaticBoxSizer, __GetStaticBox);
	Gura_AssignMethod(wx_StaticBoxSizer, __CalcMin);
	Gura_AssignMethod(wx_StaticBoxSizer, __RecalcSizes);
}

Gura_ImplementDescendantCreator(wx_StaticBoxSizer)
{
	return new Object_wx_StaticBoxSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
