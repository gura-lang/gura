//=============================================================================
// Gura class: array
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_array
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_array::Class_array(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_array)
{
}

void Class_array::Prepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(array, Value(Reference()));
	// method assignment

	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en + 1);
}

}
