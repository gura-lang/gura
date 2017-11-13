//=============================================================================
// Gura class: filter@softmax
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_Softmax
//-----------------------------------------------------------------------------
Filter_Softmax::FilterFuncTable Filter_Softmax::filterFuncTable = {{nullptr}};

bool Filter_Softmax::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply softmax filter on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayRtn, pArray, this);
}

String Filter_Softmax::ToString() const
{
	return "softmax";
}

//-----------------------------------------------------------------------------
// Object_filter_at_softmax
//-----------------------------------------------------------------------------
Object_filter_at_softmax::Object_filter_at_softmax(Environment &env, Filter_Softmax *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_softmax), pFilter)
{
}

Object *Object_filter_at_softmax::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@softmax(axis?:number):map {block?}
Gura_DeclareFunctionAlias(filter_at_softmax, "filter@softmax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_softmax));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@softmax` instance.\n");
}

Gura_ImplementFunction(filter_at_softmax)
{
	size_t axis = arg.IsValid(0)? arg.GetSizeT(0) : static_cast<size_t>(-1);
	Object_filter_at_softmax *pObj = new Object_filter_at_softmax(env, new Filter_Softmax(axis));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// filter@softmax#axis
Gura_DeclareProperty_R(filter_at_softmax, axis)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_softmax, axis)
{
	const Filter_Softmax *pFilter = Object_filter_at_softmax::GetObject(valueThis)->GetFilter();
	size_t axis = pFilter->GetAxis();
	return (axis == static_cast<size_t>(-1))? Value::Nil : Value(axis);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_softmax::Class_filter_at_softmax(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_softmax)
{
}

void Class_filter_at_softmax::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(filter_at_softmax);
	// Assignment of properties
	Gura_AssignProperty(filter_at_softmax, axis);
	// Assignment of value
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_softmax::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
