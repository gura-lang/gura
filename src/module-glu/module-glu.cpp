//-----------------------------------------------------------------------------
// Gura module: glu
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(glu)

Signal g_sig;

void AssignValues(Environment &env);
void AssignFunctions(Environment &env);

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
GLenum GetImageFormat(Signal sig, Image *pImage)
{
	GLenum format = 0;
	Image::Format fmt = pImage->GetFormat();
	format =
		(fmt == Image::FORMAT_RGB)? GL_BGR_EXT :
		(fmt == Image::FORMAT_RGBA)? GL_BGRA_EXT : 0;
	if (format == 0) {
		sig.SetError(ERR_ValueError, "unsupported image type");
	}
	return format;
}

void SetError_NotImpFunction(Signal &sig, const char *funcName)
{
	sig.SetError(ERR_RuntimeError, "not implemented function %s", funcName);
}

//-----------------------------------------------------------------------------
// VertexPackOwner
//-----------------------------------------------------------------------------
VertexPackOwner::~VertexPackOwner()
{
	Clear();
}

void VertexPackOwner::Clear()
{
	foreach (VertexPackOwner, ppVertexPack, *this) {
		delete *ppVertexPack;
	}
	clear();
}

//-----------------------------------------------------------------------------
// Object_Quadric
//-----------------------------------------------------------------------------
ImplementCallbackInfo(Quadric, error);

Object_Quadric::Object_Quadric(GLUquadric *quad) : Object(Gura_UserClass(Quadric)), _quad(quad)
{
	InitializeCallbackInfo(error);
}

Object_Quadric::~Object_Quadric()
{
	DeinitializeCallbackInfo(error);
	::gluDeleteQuadric(_quad);
}

Object *Object_Quadric::Clone() const
{
	return NULL;
}

String Object_Quadric::ToString(bool exprFlag)
{
	return String("<quadric>");
}

void Object_Quadric::SetCallback(Signal sig, GLenum which, const Function *func)
{
	switch (which) {
	DispatchCallback(gluQuadricCallback, _quad, GLU_ERROR, error)
	default:
		sig.SetError(ERR_ValueError, "invalid value for which");
		break;
	}
}

// implementation of class Quadric
Gura_ImplementUserClass(Quadric)
{
}

//-----------------------------------------------------------------------------
// Object_Tesselator
//-----------------------------------------------------------------------------
ImplementCallbackInfo(Tesselator, begin);
ImplementCallbackInfo(Tesselator, edge_flag);
ImplementCallbackInfo(Tesselator, vertex);
ImplementCallbackInfo(Tesselator, end);
ImplementCallbackInfo(Tesselator, error);
ImplementCallbackInfo(Tesselator, combine);
ImplementCallbackInfo(Tesselator, begin_data);
ImplementCallbackInfo(Tesselator, edge_flag_data);
ImplementCallbackInfo(Tesselator, end_data);
ImplementCallbackInfo(Tesselator, vertex_data);
ImplementCallbackInfo(Tesselator, error_data);
ImplementCallbackInfo(Tesselator, combine_data);

Object_Tesselator::Object_Tesselator(GLUtesselator *tess) :
						Object(Gura_UserClass(Tesselator)), _tess(tess)
{
	InitializeCallbackInfo(begin);
	InitializeCallbackInfo(edge_flag);
	InitializeCallbackInfo(vertex);
	InitializeCallbackInfo(end);
	InitializeCallbackInfo(error);
	InitializeCallbackInfo(combine);
	InitializeCallbackInfo(begin_data);
	InitializeCallbackInfo(edge_flag_data);
	InitializeCallbackInfo(end_data);
	InitializeCallbackInfo(vertex_data);
	InitializeCallbackInfo(error_data);
	InitializeCallbackInfo(combine_data);
}

Object_Tesselator::~Object_Tesselator()
{
	DeinitializeCallbackInfo(begin);
	DeinitializeCallbackInfo(edge_flag);
	DeinitializeCallbackInfo(vertex);
	DeinitializeCallbackInfo(end);
	DeinitializeCallbackInfo(error);
	DeinitializeCallbackInfo(combine);
	DeinitializeCallbackInfo(begin_data);
	DeinitializeCallbackInfo(edge_flag_data);
	DeinitializeCallbackInfo(end_data);
	DeinitializeCallbackInfo(vertex_data);
	DeinitializeCallbackInfo(error_data);
	DeinitializeCallbackInfo(combine_data);
	::gluDeleteTess(_tess);
}

Object *Object_Tesselator::Clone() const
{
	return NULL;
}

String Object_Tesselator::ToString(bool exprFlag)
{
	return String("<tesselator>");
}

void Object_Tesselator::SetCallback(Signal sig, GLenum which, const Function *func)
{
	switch (which) {
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_BEGIN, begin)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_VERTEX, vertex)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_END, end)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_ERROR, error)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_EDGE_FLAG, edge_flag)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_COMBINE, combine)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_BEGIN_DATA, begin_data)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_VERTEX_DATA, vertex_data)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_END_DATA, end_data)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_ERROR_DATA, error_data)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_EDGE_FLAG_DATA, edge_flag_data)
	DispatchCallback(gluTessCallback, _tess, GLU_TESS_COMBINE_DATA, combine_data)
	default:
		sig.SetError(ERR_ValueError, "invalid value for which");
		break;
	}
}

// implementation of class Tesselator
Gura_ImplementUserClass(Tesselator)
{
}

//-----------------------------------------------------------------------------
// Object_Nurbs
//-----------------------------------------------------------------------------
ImplementCallbackInfo(Nurbs, begin);
ImplementCallbackInfo(Nurbs, vertex);
ImplementCallbackInfo(Nurbs, normal);
ImplementCallbackInfo(Nurbs, color);
ImplementCallbackInfo(Nurbs, texture_coord);
ImplementCallbackInfo(Nurbs, end);
ImplementCallbackInfo(Nurbs, begin_data);
ImplementCallbackInfo(Nurbs, vertex_data);
ImplementCallbackInfo(Nurbs, normal_data);
ImplementCallbackInfo(Nurbs, color_data);
ImplementCallbackInfo(Nurbs, texture_coord_data);
ImplementCallbackInfo(Nurbs, end_data);
ImplementCallbackInfo(Nurbs, error);

Object_Nurbs::Object_Nurbs(GLUnurbs *nurb) : Object(Gura_UserClass(Nurbs)), _nurb(nurb)
{
	InitializeCallbackInfo(begin);
	InitializeCallbackInfo(vertex);
	InitializeCallbackInfo(normal);
	InitializeCallbackInfo(color);
	InitializeCallbackInfo(texture_coord);
	InitializeCallbackInfo(end);
	InitializeCallbackInfo(begin_data);
	InitializeCallbackInfo(vertex_data);
	InitializeCallbackInfo(normal_data);
	InitializeCallbackInfo(color_data);
	InitializeCallbackInfo(texture_coord_data);
	InitializeCallbackInfo(end_data);
	InitializeCallbackInfo(error);
}

Object_Nurbs::~Object_Nurbs()
{
	DeinitializeCallbackInfo(begin);
	DeinitializeCallbackInfo(vertex);
	DeinitializeCallbackInfo(normal);
	DeinitializeCallbackInfo(color);
	DeinitializeCallbackInfo(texture_coord);
	DeinitializeCallbackInfo(end);
	DeinitializeCallbackInfo(begin_data);
	DeinitializeCallbackInfo(vertex_data);
	DeinitializeCallbackInfo(normal_data);
	DeinitializeCallbackInfo(color_data);
	DeinitializeCallbackInfo(texture_coord_data);
	DeinitializeCallbackInfo(end_data);
	DeinitializeCallbackInfo(error);
	::gluDeleteNurbsRenderer(_nurb);
}

Object *Object_Nurbs::Clone() const
{
	return NULL;
}

String Object_Nurbs::ToString(bool exprFlag)
{
	return String("<nurbs>");
}

void Object_Nurbs::SetCallback(Signal sig, GLenum which, const Function *func)
{
	switch (which) {
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_BEGIN, begin)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_VERTEX, vertex)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_NORMAL, normal)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_COLOR, color)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_TEXTURE_COORD, texture_coord)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_END, end)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_BEGIN_DATA, begin_data)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_VERTEX_DATA, vertex_data)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_NORMAL_DATA, normal_data)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_COLOR_DATA, color_data)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_TEXTURE_COORD_DATA, texture_coord_data)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_END_DATA, end_data)
	DispatchCallback(gluNurbsCallback, _nurb, GLU_NURBS_ERROR, error)
	default:
		sig.SetError(ERR_ValueError, "invalid value for which");
		break;
	}
}

// implementation of class Nurbs
Gura_ImplementUserClass(Nurbs)
{
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	g_sig = sig;
	// class realization
	Gura_RealizeUserClass(Quadric,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Tesselator,	env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Nurbs,		env.LookupClass(VTYPE_object));
	AssignValues(env);
	AssignFunctions(env);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(glu, glu)

Gura_RegisterModule(glu)
