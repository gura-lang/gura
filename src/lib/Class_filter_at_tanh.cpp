//=============================================================================
// Gura class: filter@tanh
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_Tanh
//-----------------------------------------------------------------------------
Filter_Tanh::FilterFuncTable Filter_Tanh::filterFuncTable = {{nullptr}};

bool Filter_Tanh::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply tanh filter on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayRtn, pArray, this);
}

String Filter_Tanh::ToString() const
{
	return "tanh";
}

//-----------------------------------------------------------------------------
// Object_filter_at_tanh
//-----------------------------------------------------------------------------
Value Object_filter_at_tanh::valueConst;

Object_filter_at_tanh::Object_filter_at_tanh(Environment &env, Filter_Tanh *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_tanh), pFilter)
{
}

Object *Object_filter_at_tanh::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@tanh() {block?}
Gura_DeclareFunctionAlias(filter_at_tanh, "filter@tanh")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_tanh));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@tanh` instance.\n");
}

Gura_ImplementFunction(filter_at_tanh)
{
	return ReturnValue(env, arg, Object_filter_at_tanh::valueConst);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_tanh::Class_filter_at_tanh(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_tanh)
{
}

void Class_filter_at_tanh::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(filter_at_tanh);
	// Assignment of value
	Object_filter_at_tanh::valueConst = Value(new Object_filter_at_tanh(env, new Filter_Tanh()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_tanh::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
