//----------------------------------------------------------------------------
// wxBoxSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBoxSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBoxSizer
//----------------------------------------------------------------------------
Object_wx_BoxSizer::~Object_wx_BoxSizer()
{
}

Object *Object_wx_BoxSizer::Clone() const
{
	return nullptr;
}

String Object_wx_BoxSizer::ToString(bool exprFlag)
{
	String rtn("<wx.BoxSizer:");
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
Gura_DeclareFunctionAlias(__BoxSizer, "BoxSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BoxSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BoxSizer)
{
	//int orient = arg.GetNumber(0)
	//wxBoxSizer(orient);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BoxSizer, __AddSpacer, "AddSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BoxSizer, __AddSpacer)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//wxSizerItem* _rtn = pThis->GetEntity()->AddSpacer(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BoxSizer, __CalcMin, "CalcMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_BoxSizer, __CalcMin)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BoxSizer, __GetOrientation, "GetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_BoxSizer, __GetOrientation)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BoxSizer, __SetOrientation, "SetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BoxSizer, __SetOrientation)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->SetOrientation(orient);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BoxSizer, __RecalcSizes, "RecalcSizes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BoxSizer, __RecalcSizes)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBoxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BoxSizer)
{
	// Constructor assignment
	Gura_AssignFunction(__BoxSizer);
	// Method assignment
	Gura_AssignMethod(wx_BoxSizer, __AddSpacer);
	Gura_AssignMethod(wx_BoxSizer, __CalcMin);
	Gura_AssignMethod(wx_BoxSizer, __GetOrientation);
	Gura_AssignMethod(wx_BoxSizer, __SetOrientation);
	Gura_AssignMethod(wx_BoxSizer, __RecalcSizes);
}

Gura_ImplementDescendantCreator(wx_BoxSizer)
{
	return new Object_wx_BoxSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
