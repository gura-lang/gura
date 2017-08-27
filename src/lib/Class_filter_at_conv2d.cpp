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

Array *Filter_Conv2d::Apply(Signal &sig, Array *pArrayResult, const Array *pArray)
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()][Array::ETYPE_None];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply 2-dimension convolution filter on this array");
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayResult, pArray, *this);
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
	
String Object_filter_at_conv2d::ToString(bool exprFlag)
{
	String str;
	str += "<filter@conv2d:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@conv2d():map {block?}
Gura_DeclareFunctionAlias(filter_at_conv2d, "filter@conv2d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_conv2d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@conv2d` instance.\n");
}

Gura_ImplementFunction(filter_at_conv2d)
{
	Object_filter_at_conv2d *pObj = new Object_filter_at_conv2d(env, new Filter_Conv2d());
	return ReturnValue(env, arg, Value(pObj));
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
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_conv2d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
