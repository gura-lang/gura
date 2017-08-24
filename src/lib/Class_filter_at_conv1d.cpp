//=============================================================================
// Gura class: filter@conv1d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_Conv1d
//-----------------------------------------------------------------------------
Filter_Conv1d::FilterFuncTable Filter_Conv1d::filterFuncTable = {{{nullptr}}};

Array *Filter_Conv1d::Apply(
	Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_Conv1d &filter)
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()][Array::ETYPE_None];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply convolution filter on this array");
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayResult, pArray, filter);
}

//-----------------------------------------------------------------------------
// Object_filter_at_conv1d
//-----------------------------------------------------------------------------
Object_filter_at_conv1d::Object_filter_at_conv1d(Environment &env, const Filter_Conv1d &filter) :
	Object(env.LookupClass(VTYPE_filter_at_conv1d)), _filter(filter)
{
}

Object *Object_filter_at_conv1d::Clone() const
{
	return nullptr;
}
	
String Object_filter_at_conv1d::ToString(bool exprFlag)
{
	String str;
	str += "<filter@conv1d:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@conv1d():map {block?}
Gura_DeclareFunctionAlias(filter_at_conv1d, "filter@conv1d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_conv1d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@conv1d` instance.\n");
}

Gura_ImplementFunction(filter_at_conv1d)
{
	Object_filter_at_conv1d *pObj = new Object_filter_at_conv1d(env, Filter_Conv1d());
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_conv1d::Class_filter_at_conv1d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_conv1d)
{
}

void Class_filter_at_conv1d::DoPrepare(Environment &env)
{
	// function assignment
	Gura_AssignFunction(filter_at_conv1d);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_conv1d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
