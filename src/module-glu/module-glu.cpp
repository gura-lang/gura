//-----------------------------------------------------------------------------
// Gura module: glu
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#include "stdafx.h"

#define DispatchCallback(funcToSetCallback, obj, which, name) \
case which: { \
	int idx = _cnt_CB_##name++; \
	if (idx >= ArraySizeOf(_tbl_CB_##name)) { \
		sig.SetError(ERR_OutOfRangeError, "too many callbacks"); \
		return; \
	} \
	if (func == NULL) { \
		funcToSetCallback(obj, which, NULL); \
	} else { \
		_pFuncs_CB_##name[idx] = func->Reference(); \
		funcToSetCallback(obj, which, reinterpret_cast<CallbackType>(_tbl_CB_##name[idx])); \
	} \
	break; \
}

#define RealizeCallbackFuncs(objClass, name)	\
int Object_##objClass::_cnt_CB_##name = 0; \
CallbackType Object_##objClass::_tbl_CB_##name[] = { \
	reinterpret_cast<CallbackType>(CB_##name<0>), reinterpret_cast<CallbackType>(CB_##name<1>), \
	reinterpret_cast<CallbackType>(CB_##name<2>), reinterpret_cast<CallbackType>(CB_##name<3>), \
	reinterpret_cast<CallbackType>(CB_##name<4>), reinterpret_cast<CallbackType>(CB_##name<5>), \
	reinterpret_cast<CallbackType>(CB_##name<6>), reinterpret_cast<CallbackType>(CB_##name<7>), \
	reinterpret_cast<CallbackType>(CB_##name<8>), reinterpret_cast<CallbackType>(CB_##name<9>), \
}; \
Function *Object_##objClass::_pFuncs_CB_##name[ArraySizeOf(_tbl_CB_##name)] = {}

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
RealizeCallbackFuncs(Quadric, error);

Object_Quadric::~Object_Quadric()
{
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

void Object_Quadric::SetCallback(Signal sig, GLUquadric *quad, GLenum which, const Function *func)
{
	switch (which) {
	DispatchCallback(gluQuadricCallback, quad, GLU_ERROR, error)
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
RealizeCallbackFuncs(Tesselator, begin);
RealizeCallbackFuncs(Tesselator, edge_flag);
RealizeCallbackFuncs(Tesselator, vertex);
RealizeCallbackFuncs(Tesselator, end);
RealizeCallbackFuncs(Tesselator, error);
RealizeCallbackFuncs(Tesselator, combine);
RealizeCallbackFuncs(Tesselator, begin_data);
RealizeCallbackFuncs(Tesselator, edge_flag_data);
RealizeCallbackFuncs(Tesselator, end_data);
RealizeCallbackFuncs(Tesselator, vertex_data);
RealizeCallbackFuncs(Tesselator, error_data);
RealizeCallbackFuncs(Tesselator, combine_data);

Object_Tesselator::~Object_Tesselator()
{
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

void Object_Tesselator::SetCallback(Signal sig, GLUtesselator *tess, GLenum which, const Function *func)
{
	switch (which) {
	DispatchCallback(gluTessCallback, tess, GLU_TESS_BEGIN, begin)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_VERTEX, vertex)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_END, end)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_ERROR, error)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_EDGE_FLAG, edge_flag)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_COMBINE, combine)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_BEGIN_DATA, begin_data)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_VERTEX_DATA, vertex_data)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_END_DATA, end_data)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_ERROR_DATA, error_data)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_EDGE_FLAG_DATA, edge_flag_data)
	DispatchCallback(gluTessCallback, tess, GLU_TESS_COMBINE_DATA, combine_data)
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
RealizeCallbackFuncs(Nurbs, begin);
RealizeCallbackFuncs(Nurbs, vertex);
RealizeCallbackFuncs(Nurbs, normal);
RealizeCallbackFuncs(Nurbs, color);
RealizeCallbackFuncs(Nurbs, texture_coord);
RealizeCallbackFuncs(Nurbs, end);
RealizeCallbackFuncs(Nurbs, begin_data);
RealizeCallbackFuncs(Nurbs, vertex_data);
RealizeCallbackFuncs(Nurbs, normal_data);
RealizeCallbackFuncs(Nurbs, color_data);
RealizeCallbackFuncs(Nurbs, texture_coord_data);
RealizeCallbackFuncs(Nurbs, end_data);
RealizeCallbackFuncs(Nurbs, error);

Object_Nurbs::~Object_Nurbs()
{
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

void Object_Nurbs::SetCallback(Signal sig, GLUnurbs *nurb, GLenum which, const Function *func)
{
	switch (which) {
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_BEGIN, begin)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_VERTEX, vertex)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_NORMAL, normal)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_COLOR, color)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_TEXTURE_COORD, texture_coord)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_END, end)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_BEGIN_DATA, begin_data)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_VERTEX_DATA, vertex_data)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_NORMAL_DATA, normal_data)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_COLOR_DATA, color_data)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_TEXTURE_COORD_DATA, texture_coord_data)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_END_DATA, end_data)
	DispatchCallback(gluNurbsCallback, nurb, GLU_NURBS_ERROR, error)
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
