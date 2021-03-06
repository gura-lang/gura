#include "stdafx.h"
#include "Class_feature.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_feature implementation
//-----------------------------------------------------------------------------
Object_feature::Object_feature(Feature *pFeature) :
					Object(Gura_UserClass(feature)), _pFeature(pFeature)
{
}

String Object_feature::ToString(bool exprFlag)
{
	String str;
	struct feature_node *pNode = _pFeature->GetNodes();
	if (exprFlag) str += "ml.linear.feature(";
	str += "[";
	for (size_t iNode = 0; iNode < _pFeature->CountNodes() - 2; iNode++, pNode++) {
		char buff[80];
		::sprintf(buff, "%d => %g", pNode->index, pNode->value);
		if (iNode > 0) str += ", ";
		str += buff;
	}
	str += "]";
	if (exprFlag) str += ")";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// ml.linear.feature(x[]:list) {block?}
Gura_DeclareFunction(feature)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_list, OCCUR_Once, FLAG_ListVar);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(feature));
	AddHelp(
		Gura_Symbol(en),
		"Creates an instance of ml.linear.feature.\n");
}

Gura_ImplementFunction(feature)
{
	AutoPtr<Feature> pFeature(Feature::Create(env, arg.GetList(0)));
	if (pFeature.IsNull()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_feature(pFeature.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(feature)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(feature);
}

Gura_ImplementCastFrom(feature)
{
	if (value.Is_list()) {
		AutoPtr<Feature> pFeature(Feature::Create(env, value.GetList()));
		if (pFeature.IsNull()) return false;
		value = Value(new Object_feature(pFeature.release()));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(feature)
{
	return false;
}

Gura_EndModuleScope(ml_linear)
