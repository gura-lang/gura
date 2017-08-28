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

Array *Filter_Tanh::Apply(Signal &sig, Array *pArrayResult, const Array *pArray) const
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply tanh filter on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayResult, pArray, this);
}

//-----------------------------------------------------------------------------
// Object_filter_at_tanh
//-----------------------------------------------------------------------------
Object_filter_at_tanh::Object_filter_at_tanh(Environment &env, Filter_Tanh *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_tanh), pFilter)
{
}

Object *Object_filter_at_tanh::Clone() const
{
	return nullptr;
}
	
String Object_filter_at_tanh::ToString(bool exprFlag)
{
	String str;
	str += "<filter@tanh:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@tanh():map {block?}
Gura_DeclareFunctionAlias(filter_at_tanh, "filter@tanh")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_tanh));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@tanh` instance.\n");
}

Gura_ImplementFunction(filter_at_tanh)
{
	Object_filter_at_tanh *pObj = new Object_filter_at_tanh(env, new Filter_Tanh());
	return ReturnValue(env, arg, Value(pObj));
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
	Gura_AssignClassValue(inst, Value(new Object_filter_at_tanh(env, new Filter_Tanh())));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_tanh::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
