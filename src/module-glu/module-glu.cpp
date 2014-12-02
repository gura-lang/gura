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
Function *Object_Quadric::_pFunc_CB_error = NULL;

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

void Object_Quadric::SetCallback(Signal sig, GLUquadric *qobj, GLenum which, const Function *func)
{
	switch (which) {
	case GLU_ERROR:
		if (func == NULL) {
			gluQuadricCallback(qobj, which, NULL);
			_pFunc_CB_error = NULL;
		} else {
			_pFunc_CB_error = func->Reference();
			gluQuadricCallback(qobj, which, reinterpret_cast<CallbackType>(CB_error));
		}
		break;
	default:
		sig.SetError(ERR_ValueError, "invalid value for which");
		break;
	}
}

void Object_Quadric::CB_error(GLenum errno)
{
	const Function *pFunc = _pFunc_CB_error;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());
	pArgs->AddValue(Value(static_cast<int>(errno)));
	pFunc->Eval(env, g_sig, *pArgs);
}

// implementation of class Quadric
Gura_ImplementUserClass(Quadric)
{
}

//-----------------------------------------------------------------------------
// Object_Tesselator
//-----------------------------------------------------------------------------
Function *Object_Tesselator::_pFunc_CB_begin = NULL;
Function *Object_Tesselator::_pFunc_CB_edge_flag = NULL;
Function *Object_Tesselator::_pFunc_CB_vertex = NULL;
Function *Object_Tesselator::_pFunc_CB_end = NULL;
Function *Object_Tesselator::_pFunc_CB_error = NULL;
Function *Object_Tesselator::_pFunc_CB_combine = NULL;
Function *Object_Tesselator::_pFunc_CB_begin_data = NULL;
Function *Object_Tesselator::_pFunc_CB_edge_flag_data = NULL;
Function *Object_Tesselator::_pFunc_CB_end_data = NULL;
Function *Object_Tesselator::_pFunc_CB_vertex_data = NULL;
Function *Object_Tesselator::_pFunc_CB_error_data = NULL;
Function *Object_Tesselator::_pFunc_CB_combine_data = NULL;

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
	case GLU_TESS_BEGIN:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_begin = NULL;
		} else {
			_pFunc_CB_begin = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_begin));
		}
		break;
	case GLU_TESS_VERTEX:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_vertex = NULL;
		} else {
			_pFunc_CB_vertex = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_vertex));
		}
		break;
	case GLU_TESS_END:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_end = NULL;
		} else {
			_pFunc_CB_end = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_end));
		}
		break;
	case GLU_TESS_ERROR:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_error = NULL;
		} else {
			_pFunc_CB_error = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_error));
		}
		break;
	case GLU_TESS_EDGE_FLAG:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_edge_flag = NULL;
		} else {
			_pFunc_CB_edge_flag = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_edge_flag));
		}
		break;
	case GLU_TESS_COMBINE:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_combine = NULL;
		} else {
			_pFunc_CB_combine = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_combine));
		}
		break;
	case GLU_TESS_BEGIN_DATA:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_begin_data = NULL;
		} else {
			_pFunc_CB_begin_data = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_begin_data));
		}
		break;
	case GLU_TESS_VERTEX_DATA:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_vertex_data = NULL;
		} else {
			_pFunc_CB_vertex_data = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_vertex_data));
		}
		break;
	case GLU_TESS_END_DATA:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_end_data = NULL;
		} else {
			_pFunc_CB_end_data = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_end_data));
		}
		break;
	case GLU_TESS_ERROR_DATA:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_error_data = NULL;
		} else {
			_pFunc_CB_error_data = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_error_data));
		}
		break;
	case GLU_TESS_EDGE_FLAG_DATA:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_edge_flag_data = NULL;
		} else {
			_pFunc_CB_edge_flag_data = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_edge_flag_data));
		}
		break;
	case GLU_TESS_COMBINE_DATA:
		if (func == NULL) {
			gluTessCallback(tess, which, NULL);
			_pFunc_CB_combine_data = NULL;
		} else {
			_pFunc_CB_combine_data = func->Reference();
			gluTessCallback(tess, which, reinterpret_cast<CallbackType>(CB_combine_data));
		}
		break;
	default:
		sig.SetError(ERR_ValueError, "invalid value for which");
		break;
	}
}

// implementation of class Tesselator
Gura_ImplementUserClass(Tesselator)
{
}

void Object_Tesselator::CB_begin(GLenum type)
{
	const Function *pFunc = _pFunc_CB_begin;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_edge_flag(GLboolean flag)
{
	const Function *pFunc = _pFunc_CB_edge_flag;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_vertex(void *vertex_data)
{
	const Function *pFunc = _pFunc_CB_vertex;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_end(void)
{
	const Function *pFunc = _pFunc_CB_end;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_error(GLenum errno)
{
	const Function *pFunc = _pFunc_CB_error;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_combine(GLdouble coords[3], void *vertex_data[4],
						   GLfloat weight[4], void **outData)
{
	const Function *pFunc = _pFunc_CB_combine;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_begin_data(GLenum type, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_begin_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_edge_flag_data(GLboolean flag, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_edge_flag_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_end_data(void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_end_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_vertex_data(void *vertex_data, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_vertex_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_error_data(GLenum errno, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_error_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_combine_data(GLdouble coords[3], void *vertex_data[4],
							   GLfloat weight[4], void **outDatab, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_combine_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
#if 0
	AutoPtr<Args> pArgs;
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		for (int i = 0; i < 3; i++) {
			valList.push_back(Value(coords[i]));
		}
	} while (0);
	for (int i = 0; i < 4; i++) {
		reinterpret_cast<VertexPack *>(vertex_data[i])->GetVertexData();
	}
#endif
}

//-----------------------------------------------------------------------------
// Object_Nurbs
//-----------------------------------------------------------------------------
Function *Object_Nurbs::_pFunc_CB_begin = NULL;
Function *Object_Nurbs::_pFunc_CB_vertex = NULL;
Function *Object_Nurbs::_pFunc_CB_normal = NULL;
Function *Object_Nurbs::_pFunc_CB_color = NULL;
Function *Object_Nurbs::_pFunc_CB_tex_coord = NULL;
Function *Object_Nurbs::_pFunc_CB_end = NULL;
Function *Object_Nurbs::_pFunc_CB_begin_data = NULL;
Function *Object_Nurbs::_pFunc_CB_vertex_data = NULL;
Function *Object_Nurbs::_pFunc_CB_normal_data = NULL;
Function *Object_Nurbs::_pFunc_CB_color_data = NULL;
Function *Object_Nurbs::_pFunc_CB_tex_coord_data = NULL;
Function *Object_Nurbs::_pFunc_CB_end_data = NULL;
Function *Object_Nurbs::_pFunc_CB_error = NULL;

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
/*
	case GLU_ERROR:
		if (func == NULL) {
			gluQuadricCallback(qobj, which, NULL);
			Object_Quadric::SetFunc_CB_error(NULL);
		} else {
			Object_Quadric::SetFunc_CB_error(func->Reference());
			gluQuadricCallback(qobj, which, reinterpret_cast<CallbackType>(Object_Quadric::CB_error));
		}
		break;
*/		
	default:
		sig.SetError(ERR_ValueError, "invalid value for which");
		break;
	}
}

// implementation of class Nurbs
Gura_ImplementUserClass(Nurbs)
{
}

void Object_Nurbs::CB_begin(GLenum type)
{
	const Function *pFunc = _pFunc_CB_begin;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_vertex(GLfloat *vertex)
{
	const Function *pFunc = _pFunc_CB_vertex;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_normal(GLfloat *normal)
{
	const Function *pFunc = _pFunc_CB_normal;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_color(GLfloat *color)
{
	const Function *pFunc = _pFunc_CB_color;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_tex_coord(GLfloat *tex_coord)
{
	const Function *pFunc = _pFunc_CB_tex_coord;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_end(void)
{
	const Function *pFunc = _pFunc_CB_end;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_begin_data(GLenum type, void *userData)
{
	const Function *pFunc = _pFunc_CB_begin_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_vertex_data(GLfloat *vertex, void *userData)
{
	const Function *pFunc = _pFunc_CB_vertex_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_normal_data(GLfloat *normal, void *userData)
{
	const Function *pFunc = _pFunc_CB_normal_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_color_data(GLfloat *color, void *userData)
{
	const Function *pFunc = _pFunc_CB_color_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_tex_coord_data(GLfloat *tex_coord, void *userData)
{
	const Function *pFunc = _pFunc_CB_tex_coord_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_end_data(void *userData)
{
	const Function *pFunc = _pFunc_CB_end_data;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_error(GLenum errno)
{
	const Function *pFunc = _pFunc_CB_error;
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
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
