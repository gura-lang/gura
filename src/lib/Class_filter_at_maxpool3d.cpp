//=============================================================================
// Gura class: filter@maxpool3d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_MaxPool3d
//-----------------------------------------------------------------------------
Filter_MaxPool3d::FilterFuncTable Filter_MaxPool3d::filterFuncTable = {{nullptr}};

Array *Filter_MaxPool3d::Apply(Signal &sig, Array *pArrayResult, const Array *pArray)
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply 3-dimension max pool filter on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayResult, pArray, *this);
}

//-----------------------------------------------------------------------------
// Object_filter_at_maxpool3d
//-----------------------------------------------------------------------------
Object_filter_at_maxpool3d::Object_filter_at_maxpool3d(Environment &env, Filter_MaxPool3d *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_maxpool3d), pFilter)
{
}

Object *Object_filter_at_maxpool3d::Clone() const
{
	return nullptr;
}
	
String Object_filter_at_maxpool3d::ToString(bool exprFlag)
{
	String str;
	str += "<filter@maxpool3d:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@maxpool3d(size[]:number, strides[]?:number, padding?:symbol, format?:symbol):map {block?}
Gura_DeclareFunctionAlias(filter_at_maxpool3d, "filter@maxpool3d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_maxpool3d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@maxpool3d` instance.\n");
}

Gura_ImplementFunction(filter_at_maxpool3d)
{
	Object_filter_at_maxpool3d *pObj = new Object_filter_at_maxpool3d(env, new Filter_MaxPool3d());
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_maxpool3d::Class_filter_at_maxpool3d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_maxpool3d)
{
}

void Class_filter_at_maxpool3d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(filter_at_maxpool3d);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_maxpool3d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
