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

Array *Filter_Relu::Apply(Signal &sig, Array *pArrayRtn, const Array *pArray) const
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply ReLU filter on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayRtn, pArray, this);
}

String Filter_Relu::ToString() const
{
	return "relu";
}

//-----------------------------------------------------------------------------
// Object_filter_at_relu
//-----------------------------------------------------------------------------
Value Object_filter_at_relu::valueConst;

Object_filter_at_relu::Object_filter_at_relu(Environment &env, Filter_Relu *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_relu), pFilter)
{
}

Object *Object_filter_at_relu::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@relu() {block?}
Gura_DeclareFunctionAlias(filter_at_relu, "filter@relu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_relu));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@relu` instance.\n");
}

Gura_ImplementFunction(filter_at_relu)
{
	return ReturnValue(env, arg, Object_filter_at_relu::valueConst);
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
	// Assignment of function
	Gura_AssignFunction(filter_at_relu);
	// Assignment of value
	Object_filter_at_relu::valueConst = Value(new Object_filter_at_relu(env, new Filter_Relu()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_relu::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
