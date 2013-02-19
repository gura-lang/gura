#ifndef __CAIRO_OBJECT_RASTER_SOURCE_PATTERN_H__
#define __CAIRO_OBJECT_RASTER_SOURCE_PATTERN_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_raster_source_pattern declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(raster_source_pattern);

class Object_raster_source_pattern : public Object_pattern {
public:
	Gura_DeclareObjectAccessor(raster_source_pattern)
public:
	inline Object_raster_source_pattern(cairo_pattern_t *pattern) :
										Object_pattern(pattern) {}
	virtual String ToString(Signal sig, bool exprFlag);
};

}}

#endif
