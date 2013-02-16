#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_path implementation
//-----------------------------------------------------------------------------
Object_path::~Object_path()
{
	::cairo_path_destroy(_path);
}

Object *Object_path::Clone() const
{
	return NULL;
}

String Object_path::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.path>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for path
//-----------------------------------------------------------------------------
//#void cairo_path_destroy(cairo_path_t *path);

// implementation of class path
Gura_ImplementUserClass(path)
{
}

}}
