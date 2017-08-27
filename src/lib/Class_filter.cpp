//=============================================================================
// Gura class: filter
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Object_filter
//-----------------------------------------------------------------------------
Object_filter::Object_filter(Environment &env, Filter *pFilter) :
	Object(env.LookupClass(VTYPE_filter_at_conv1d)), _pFilter(pFilter)
{
}

Object_filter::Object_filter(Class *pClass, Filter *pFilter) :
	Object(pClass), _pFilter(pFilter)
{
}

Object *Object_filter::Clone() const
{
	return nullptr;
}
	
String Object_filter::ToString(bool exprFlag)
{
	String str;
	str += "<filter";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter::Class_filter(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_filter)
{
}

void Class_filter::DoPrepare(Environment &env)
{
	// Assignment of value
	Gura_AssignValue(filter, Value(this));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
