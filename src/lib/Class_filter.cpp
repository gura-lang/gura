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
