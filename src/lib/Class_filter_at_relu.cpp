//=============================================================================
// Gura class: filter@relu
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_Relu
//-----------------------------------------------------------------------------
Filter_Relu::FilterFuncTable Filter_Relu::filterFuncTable = {{nullptr}};

Array *Filter_Relu::Apply(
	Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_Relu &filter)
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply convolution filter on this array");
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayResult, pArray, filter);
}

//-----------------------------------------------------------------------------
// Object_filter_at_relu
//-----------------------------------------------------------------------------
Object_filter_at_relu::Object_filter_at_relu(Environment &env, const Filter_Relu &filter) :
	Object(env.LookupClass(VTYPE_filter_at_relu)), _filter(filter)
{
}

Object *Object_filter_at_relu::Clone() const
{
	return nullptr;
}
	
String Object_filter_at_relu::ToString(bool exprFlag)
{
	String str;
	str += "<filter@relu:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@relu():map {block?}
Gura_DeclareFunctionAlias(filter_at_relu, "filter@relu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_relu));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@relu` instance.\n");
}

Gura_ImplementFunction(filter_at_relu)
{
	Object_filter_at_relu *pObj = new Object_filter_at_relu(env, Filter_Relu());
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_relu::Class_filter_at_relu(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_relu)
{
}

void Class_filter_at_relu::DoPrepare(Environment &env)
{
	// function assignment
	Gura_AssignFunction(filter_at_relu);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_relu::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
