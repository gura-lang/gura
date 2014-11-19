//-----------------------------------------------------------------------------
// Gura module: glu
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(glu)

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
// Object_Quadric
//-----------------------------------------------------------------------------
AutoPtr<Function> Object_Quadric::_pFunc_QuadricErrorProc;

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

void Object_Quadric::SetQuadricErrorProc(Function *pFunc)
{
	_pFunc_QuadricErrorProc.reset(pFunc);
}

void Object_Quadric::Callback_QuadricErrorProc(GLenum err)
{
	if (_pFunc_QuadricErrorProc.IsNull()) return;
	Environment &env = _pFunc_QuadricErrorProc->GetEnvScope();
	Signal sig;
	AutoPtr<Args> pArgs(new Args());
	pArgs->AddValue(Value(static_cast<int>(err)));
	_pFunc_QuadricErrorProc->Eval(env, sig, *pArgs);
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

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
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
