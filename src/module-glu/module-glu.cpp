//-----------------------------------------------------------------------------
// Gura module: glu
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#include "stdafx.h"

#define SetCallback_Tesselator(which, name) \
case which: { \
	int idx = _cnt_CB_##name++; \
	if (idx >= ArraySizeOf(_tbl_CB_##name)) { \
		sig.SetError(ERR_OutOfRangeError, "too many callbacks"); \
		return; \
	} \
	if (func == NULL) { \
		gluTessCallback(tess, which, NULL); \
	} else { \
		_pFuncs_CB_##name[idx] = func->Reference(); \
		gluTessCallback(tess, which, reinterpret_cast<CallbackType>(_tbl_CB_##name[idx])); \
	} \
	break; \
}

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
int Object_Quadric::_cnt_CB_error = 0;

CallbackType Object_Quadric::_tbl_CB_error[] = {
	reinterpret_cast<CallbackType>(CB_error<0>),
};

Function *Object_Quadric::_pFuncs_CB_error[ArraySizeOf(_tbl_CB_error)] = { NULL };

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
	case GLU_ERROR: {
		int idx = _cnt_CB_error++;
		if (idx >= ArraySizeOf(_tbl_CB_error)) {
			sig.SetError(ERR_OutOfRangeError, "too many callbacks");
			return;
		}
		if (func == NULL) {
			gluQuadricCallback(qobj, which, NULL);
			//_pFuncs_CB_error[idx] = NULL;
		} else {
			_pFuncs_CB_error[idx] = func->Reference();
			gluQuadricCallback(qobj, which, reinterpret_cast<CallbackType>(_tbl_CB_error[idx]));
		}
		break;
	}
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
int Object_Tesselator::_cnt_CB_begin = 0;
int Object_Tesselator::_cnt_CB_edge_flag = 0;
int Object_Tesselator::_cnt_CB_vertex = 0;
int Object_Tesselator::_cnt_CB_end = 0;
int Object_Tesselator::_cnt_CB_error = 0;
int Object_Tesselator::_cnt_CB_combine = 0;
int Object_Tesselator::_cnt_CB_begin_data = 0;
int Object_Tesselator::_cnt_CB_edge_flag_data = 0;
int Object_Tesselator::_cnt_CB_end_data = 0;
int Object_Tesselator::_cnt_CB_vertex_data = 0;
int Object_Tesselator::_cnt_CB_error_data = 0;
int Object_Tesselator::_cnt_CB_combine_data = 0;

CallbackType Object_Tesselator::_tbl_CB_begin[] = {
	reinterpret_cast<CallbackType>(CB_begin<0>),
};
CallbackType Object_Tesselator::_tbl_CB_edge_flag[] = {
	reinterpret_cast<CallbackType>(CB_edge_flag<0>),
};
CallbackType Object_Tesselator::_tbl_CB_vertex[] = {
	reinterpret_cast<CallbackType>(CB_vertex<0>),
};
CallbackType Object_Tesselator::_tbl_CB_end[] = {
	reinterpret_cast<CallbackType>(CB_end<0>),
};
CallbackType Object_Tesselator::_tbl_CB_error[] = {
	reinterpret_cast<CallbackType>(CB_error<0>),
};
CallbackType Object_Tesselator::_tbl_CB_combine[] = {
	reinterpret_cast<CallbackType>(CB_combine<0>),
};
CallbackType Object_Tesselator::_tbl_CB_begin_data[] = {
	reinterpret_cast<CallbackType>(CB_begin_data<0>),
};
CallbackType Object_Tesselator::_tbl_CB_edge_flag_data[] = {
	reinterpret_cast<CallbackType>(CB_edge_flag_data<0>),
};
CallbackType Object_Tesselator::_tbl_CB_end_data[] = {
	reinterpret_cast<CallbackType>(CB_end_data<0>),
};
CallbackType Object_Tesselator::_tbl_CB_vertex_data[] = {
	reinterpret_cast<CallbackType>(CB_vertex_data<0>),
};
CallbackType Object_Tesselator::_tbl_CB_error_data[] = {
	reinterpret_cast<CallbackType>(CB_error_data<0>),
};
CallbackType Object_Tesselator::_tbl_CB_combine_data[] = {
	reinterpret_cast<CallbackType>(CB_combine_data<0>),
};

Function *Object_Tesselator::_pFuncs_CB_begin[ArraySizeOf(_tbl_CB_begin)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_edge_flag[ArraySizeOf(_tbl_CB_edge_flag)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_vertex[ArraySizeOf(_tbl_CB_vertex)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_end[ArraySizeOf(_tbl_CB_end)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_error[ArraySizeOf(_tbl_CB_error)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_combine[ArraySizeOf(_tbl_CB_combine)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_begin_data[ArraySizeOf(_tbl_CB_begin_data)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_edge_flag_data[ArraySizeOf(_tbl_CB_edge_flag_data)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_end_data[ArraySizeOf(_tbl_CB_end_data)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_vertex_data[ArraySizeOf(_tbl_CB_vertex_data)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_error_data[ArraySizeOf(_tbl_CB_error_data)] = { NULL };
Function *Object_Tesselator::_pFuncs_CB_combine_data[ArraySizeOf(_tbl_CB_combine_data)] = { NULL };

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
	SetCallback_Tesselator(GLU_TESS_BEGIN, begin)
	SetCallback_Tesselator(GLU_TESS_VERTEX, vertex)
	SetCallback_Tesselator(GLU_TESS_END, end)
	SetCallback_Tesselator(GLU_TESS_ERROR, error)
	SetCallback_Tesselator(GLU_TESS_EDGE_FLAG, edge_flag)
	SetCallback_Tesselator(GLU_TESS_COMBINE, combine)
	SetCallback_Tesselator(GLU_TESS_BEGIN_DATA, begin_data)
	SetCallback_Tesselator(GLU_TESS_VERTEX_DATA, vertex_data)
	SetCallback_Tesselator(GLU_TESS_END_DATA, end_data)
	SetCallback_Tesselator(GLU_TESS_ERROR_DATA, error_data)
	SetCallback_Tesselator(GLU_TESS_EDGE_FLAG_DATA, edge_flag_data)
	SetCallback_Tesselator(GLU_TESS_COMBINE_DATA, combine_data)
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
