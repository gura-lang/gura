#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_raster_source_pattern implementation
//-----------------------------------------------------------------------------
String Object_raster_source_pattern::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.raster_source_pattern>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for raster_source_pattern
//-----------------------------------------------------------------------------
// implementation of class raster_source_pattern
Gura_ImplementUserClass(raster_source_pattern)
{
}

}}
