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

Array *Filter_Softmax::Apply(Signal &sig, Array *pArrayResult, const Array *pArray)
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply softmax filter on this array");
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayResult, pArray, *this);
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
	
String Object_filter_at_softmax::ToString(bool exprFlag)
{
	String str;
	str += "<filter@softmax:";
	str += ">";
	return str;
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
	// Assignment of value
	Gura_AssignClassValue(inst, Value(new Object_filter_at_softmax(env, new Filter_Softmax())));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_softmax::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
