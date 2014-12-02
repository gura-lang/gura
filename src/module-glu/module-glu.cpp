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
Object_Quadric::~Object_Quadric()
{
	::gluDeleteQuadric(_qobj);
}

Object *Object_Quadric::Clone() const
{
	return NULL;
}

String Object_Quadric::ToString(bool exprFlag)
{
	return String("<quadric>");
}

void Object_Quadric::CB_error(GLenum errno)
{
#if 0
	if (_pFunc_CB_error.IsNull()) return;
	Environment &env = _pFunc_CB_error->GetEnvScope();
	AutoPtr<Args> pArgs(new Args());
	pArgs->AddValue(Value(static_cast<int>(errno)));
	_pFunc_CB_error->Eval(env, g_sig, *pArgs);
#endif
}

// implementation of class Quadric
Gura_ImplementUserClass(Quadric)
{
}

//-----------------------------------------------------------------------------
// Object_Tesselator
//-----------------------------------------------------------------------------
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
}

void Object_Tesselator::CB_edgeFlag(GLboolean flag)
{
}

void Object_Tesselator::CB_vertex(void *vertex_data)
{
}

void Object_Tesselator::CB_end(void)
{
}

void Object_Tesselator::CB_error(GLenum errno)
{
}

void Object_Tesselator::CB_combine(GLdouble coords[3], void *vertex_data[4],
						   GLfloat weight[4], void **outData)
{
}

void Object_Tesselator::CB_beginData(GLenum type, void *polygon_data)
{
}

void Object_Tesselator::CB_edgeFlagData(GLboolean flag, void *polygon_data)
{
}

void Object_Tesselator::CB_endData(void *polygon_data)
{
}

void Object_Tesselator::CB_vertexData(void *vertex_data, void *polygon_data)
{
}

void Object_Tesselator::CB_errorData(GLenum errno, void *polygon_data)
{
}

void Object_Tesselator::CB_combineData(GLdouble coords[3], void *vertex_data[4],
							   GLfloat weight[4], void **outDatab, void *polygon_data)
{
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
Object_Nurbs::~Object_Nurbs()
{
	::gluDeleteNurbsRenderer(_nobj);
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
}

void Object_Nurbs::CB_vertex(GLfloat *vertex)
{
}

void Object_Nurbs::CB_normal(GLfloat *normal)
{
}

void Object_Nurbs::CB_color(GLfloat *color)
{
}

void Object_Nurbs::CB_texCoord(GLfloat *tex_coord)
{
}

void Object_Nurbs::CB_end(void)
{
}

void Object_Nurbs::CB_beginData(GLenum type, void *userData)
{
}

void Object_Nurbs::CB_vertexData(GLfloat *vertex, void *userData)
{
}

void Object_Nurbs::CB_normalData(GLfloat *normal, void *userData)
{
}

void Object_Nurbs::CB_colorData(GLfloat *color, void *userData)
{
}

void Object_Nurbs::CB_texCoordData(GLfloat *tex_coord, void *userData)
{
}

void Object_Nurbs::CB_endData(void *userData)
{
}

void Object_Nurbs::CB_error(GLenum errno)
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
