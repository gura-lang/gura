#ifndef __CAIRO_OBJECT_MESH_PATTERN_H__
#define __CAIRO_OBJECT_MESH_PATTERN_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_mesh_pattern declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(mesh_pattern);

class Object_mesh_pattern : public Object_pattern {
public:
	Gura_DeclareObjectAccessor(mesh_pattern)
public:
	inline Object_mesh_pattern(cairo_pattern_t *pattern) :
										Object_pattern(pattern) {}
	virtual String ToString(Signal sig, bool exprFlag);
};

}}

#endif
