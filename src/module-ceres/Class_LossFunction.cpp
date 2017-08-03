#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_LossFunction implementation
//-----------------------------------------------------------------------------
Object_LossFunction::Object_LossFunction(ceres::LossFunction *pLossFunction, const char *name) :
	Object(Gura_UserClass(LossFunction)), _pLossFunction(pLossFunction), _name(name)
{
}

String Object_LossFunction::ToString(bool exprFlag)
{
	String str = "<ceres.LossFunction:";
	str += _name;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.LossFunction() {block?}
Gura_DeclareFunction(LossFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(LossFunction));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(LossFunction)
{
	Object_LossFunction *pObj = new Object_LossFunction(new ceres::TrivialLoss(), "TribialLoss");
	return ReturnValue(env, arg, Value(pObj));
}

// ceres.TrivialLoss() {block?}
Gura_DeclareFunction(TrivialLoss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(TrivialLoss)
{
	Object_LossFunction *pObj = new Object_LossFunction(new ceres::TrivialLoss(), "TrivialLoss");
	return ReturnValue(env, arg, Value(pObj));
}

// ceres.HuberLoss(a:number) {block?}
Gura_DeclareFunction(HuberLoss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(HuberLoss)
{
	double a = arg.GetDouble(0);
	Object_LossFunction *pObj = new Object_LossFunction(new ceres::HuberLoss(a), "HuberLoss");
	return ReturnValue(env, arg, Value(pObj));
}

// ceres.SoftLOneLoss(a:number) {block?}
Gura_DeclareFunction(SoftLOneLoss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(SoftLOneLoss)
{
	double a = arg.GetDouble(0);
	Object_LossFunction *pObj = new Object_LossFunction(new ceres::SoftLOneLoss(a), "SoftLOneLoss");
	return ReturnValue(env, arg, Value(pObj));
}

// ceres.CauchyLoss(a:number) {block?}
Gura_DeclareFunction(CauchyLoss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(CauchyLoss)
{
	double a = arg.GetDouble(0);
	Object_LossFunction *pObj = new Object_LossFunction(new ceres::CauchyLoss(a), "CauchyLoss");
	return ReturnValue(env, arg, Value(pObj));
}

// ceres.ArctanLoss(a:number) {block?}
Gura_DeclareFunction(ArctanLoss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(ArctanLoss)
{
	double a = arg.GetDouble(0);
	Object_LossFunction *pObj = new Object_LossFunction(new ceres::ArctanLoss(a), "ArctanLoss");
	return ReturnValue(env, arg, Value(pObj));
}

// ceres.TolerantLoss(a:number, b:number) {block?}
Gura_DeclareFunction(TolerantLoss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(TolerantLoss)
{
	double a = arg.GetDouble(0);
	double b = arg.GetDouble(1);
	Object_LossFunction *pObj = new Object_LossFunction(new ceres::TolerantLoss(a, b), "TolerantLoss");
	return ReturnValue(env, arg, Value(pObj));
}

#if 0
// ceres.ComposedLoss() {block?}
Gura_DeclareFunction(ComposedLoss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(ComposedLoss)
{
	Object_LossFunction *pObj = new Object_LossFunction(new ceres::ComposedLoss(), "ComposedLoss");
	return ReturnValue(env, arg, Value(pObj));
}
#endif

#if 0
// ceres.ScaledLoss() {block?}
Gura_DeclareFunction(ScaledLoss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(ScaledLoss)
{
	Object_LossFunction *pObj = new Object_LossFunction(new ceres::ScaledLoss(), "ScaledLoss");
	return ReturnValue(env, arg, Value(pObj));
}
#endif

//-----------------------------------------------------------------------------
// Implementation of class ceres.LossFunction
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(LossFunction)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(LossFunction);
	Gura_AssignFunction(TrivialLoss);
	Gura_AssignFunction(HuberLoss);
	Gura_AssignFunction(SoftLOneLoss);
	Gura_AssignFunction(CauchyLoss);
	Gura_AssignFunction(ArctanLoss);
	Gura_AssignFunction(TolerantLoss);
	//Gura_AssignFunction(ComposedLoss);
	//Gura_AssignFunction(ScaledLoss);
}

Gura_EndModuleScope(ceres)
