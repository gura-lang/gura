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

bool Object_exif::ReadStream(Signal sig, Stream &stream)
{
	return true;
}

//-----------------------------------------------------------------------------
// Gura interfaces for exif
//-----------------------------------------------------------------------------
// implementation of class exif
Gura_ImplementUserClass(exif)
{
}

}}
