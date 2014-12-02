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
AutoPtr<Function> Object_Quadric::_pFunc_CB_error;

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
			Object_Quadric::SetFunc_CB_error(NULL);
		} else {
			Object_Quadric::SetFunc_CB_error(func->Reference());
			gluQuadricCallback(qobj, which, reinterpret_cast<CallbackType>(Object_Quadric::CB_error));
		}
		break;
	default:
		sig.SetError(ERR_ValueError, "invalid value for which");
		break;
	}
}

void Object_Quadric::CB_error(GLenum errno)
{
	const Function *pFunc = _pFunc_CB_error.get();
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
AutoPtr<Function> Object_Tesselator::_pFunc_CB_begin;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_edgeFlag;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_vertex;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_end;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_error;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_combine;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_beginData;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_edgeFlagData;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_endData;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_vertexData;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_errorData;
AutoPtr<Function> Object_Tesselator::_pFunc_CB_combineData;

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

// implementation of class Tesselator
Gura_ImplementUserClass(Tesselator)
{
}

void Object_Tesselator::CB_begin(GLenum type)
{
	const Function *pFunc = _pFunc_CB_begin.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_edgeFlag(GLboolean flag)
{
	const Function *pFunc = _pFunc_CB_edgeFlag.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_vertex(void *vertex_data)
{
	const Function *pFunc = _pFunc_CB_vertex.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_end(void)
{
	const Function *pFunc = _pFunc_CB_end.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_error(GLenum errno)
{
	const Function *pFunc = _pFunc_CB_error.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_combine(GLdouble coords[3], void *vertex_data[4],
						   GLfloat weight[4], void **outData)
{
	const Function *pFunc = _pFunc_CB_combine.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_beginData(GLenum type, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_beginData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_edgeFlagData(GLboolean flag, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_edgeFlagData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_endData(void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_endData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_vertexData(void *vertex_data, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_vertexData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_errorData(GLenum errno, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_errorData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Tesselator::CB_combineData(GLdouble coords[3], void *vertex_data[4],
							   GLfloat weight[4], void **outDatab, void *polygon_data)
{
	const Function *pFunc = _pFunc_CB_combineData.get();
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
AutoPtr<Function> Object_Nurbs::_pFunc_CB_begin;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_vertex;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_normal;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_color;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_texCoord;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_end;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_beginData;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_vertexData;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_normalData;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_colorData;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_texCoordData;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_endData;
AutoPtr<Function> Object_Nurbs::_pFunc_CB_error;

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

// implementation of class Nurbs
Gura_ImplementUserClass(Nurbs)
{
}

void Object_Nurbs::CB_begin(GLenum type)
{
	const Function *pFunc = _pFunc_CB_begin.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_vertex(GLfloat *vertex)
{
	const Function *pFunc = _pFunc_CB_vertex.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_normal(GLfloat *normal)
{
	const Function *pFunc = _pFunc_CB_normal.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_color(GLfloat *color)
{
	const Function *pFunc = _pFunc_CB_color.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_texCoord(GLfloat *tex_coord)
{
	const Function *pFunc = _pFunc_CB_texCoord.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_end(void)
{
	const Function *pFunc = _pFunc_CB_end.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_beginData(GLenum type, void *userData)
{
	const Function *pFunc = _pFunc_CB_beginData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_vertexData(GLfloat *vertex, void *userData)
{
	const Function *pFunc = _pFunc_CB_vertexData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_normalData(GLfloat *normal, void *userData)
{
	const Function *pFunc = _pFunc_CB_normalData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_colorData(GLfloat *color, void *userData)
{
	const Function *pFunc = _pFunc_CB_colorData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_texCoordData(GLfloat *tex_coord, void *userData)
{
	const Function *pFunc = _pFunc_CB_texCoordData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_endData(void *userData)
{
	const Function *pFunc = _pFunc_CB_endData.get();
	if (pFunc == NULL) return;
	Environment &env = pFunc->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());

	pFunc->Eval(env, g_sig, *pArgs);
}

void Object_Nurbs::CB_error(GLenum errno)
{
	const Function *pFunc = _pFunc_CB_error.get();
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
