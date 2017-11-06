//=============================================================================
// Gura class: filter@conv2d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_Conv2d
//-----------------------------------------------------------------------------
Filter_Conv2d::FilterFuncTable Filter_Conv2d::filterFuncTable = {{{nullptr}}};

bool Filter_Conv2d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()][_pArrayFilter->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply 2-dimension convolution filter on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayRtn, pArray, this);
}

String Filter_Conv2d::ToString() const
{
	return "conv2d";
}

//-----------------------------------------------------------------------------
// Object_filter_at_conv2d
//-----------------------------------------------------------------------------
Object_filter_at_conv2d::Object_filter_at_conv2d(Environment &env, Filter_Conv2d *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_conv2d), pFilter)
{
}

Object *Object_filter_at_conv2d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@conv2d(array:array):map {block?}
Gura_DeclareFunctionAlias(filter_at_conv2d, "filter@conv2d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "array", VTYPE_array);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_conv2d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@conv2d` instance.\n"
		"\n"
		"The given `array` instance shoud have a shape of `[FN, C, FH, FW]` for channel first format\n"
		"or `[FN, FH, FW, C]` for channel last format\n"
		"where `FN` is the number of filters, `C` is the number of channels and\n"
		"`FH` and `FW` is the size of the filter's kernel.\n");
}

Gura_ImplementFunction(filter_at_conv2d)
{
	const Array *pArrayFilter = Object_array::GetObject(arg, 0)->GetArray();
	const Array::Dimensions &dims = pArrayFilter->GetDimensions();
	if (dims.size() != 4) {
		env.SetError(ERR_ValueError,
					 "the `array` instance given to `filter@conv2d` constructor must have 4 dimensions.");
		return Value::Nil;
	}
	Object_filter_at_conv2d *pObj = new Object_filter_at_conv2d(env, new Filter_Conv2d(pArrayFilter->Reference()));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// filter@conv2d#array
Gura_DeclareProperty_R(filter_at_conv2d, array)
{
	SetPropAttr(VTYPE_array);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(filter_at_conv2d, array)
{
	const Filter_Conv2d *pFilter = Object_filter_at_conv2d::GetObject(valueThis)->GetFilter();
	Object_array *pObj = new Object_array(env, pFilter->GetArray()->Reference());
	return Value(pObj);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_conv2d::Class_filter_at_conv2d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_conv2d)
{
}

void Class_filter_at_conv2d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(filter_at_conv2d);
	// Assignment of properties
	Gura_AssignProperty(filter_at_conv2d, array);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_conv2d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
