#include "Object_exif.h"

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Object_exif implementation
//-----------------------------------------------------------------------------
Object_exif::~Object_exif()
{
}

Object *Object_exif::Clone() const
{
	return NULL;
}

String Object_exif::ToString(Signal sig, bool exprFlag)
{
	return String("<jpeg.exif>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for exif
//-----------------------------------------------------------------------------
// implementation of class exif
Gura_ImplementUserClass(exif)
{
}

}}
