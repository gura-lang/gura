//-----------------------------------------------------------------------------
// Gura module: glu
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#include "stdafx.h"

#if defined(GURA_ON_MSWIN)
#else
#define __stdcall
#endif

Gura_BeginModuleBody(glu)

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
#define ToArrayTemplate(type, getFunc) \
bool ToArray(Signal sig, type v[], const ValueList &valList, size_t n, \
			bool checkFlag, const char *funcName, const char *paramName) \
{ \
	if (checkFlag && valList.size() != n) { \
		sig.SetError(ERR_ValueError, \
				"%s's %s parameter takes a list with %d elements", \
				funcName, paramName, n); \
		return false; \
	} \
	size_t i = 0; \
	foreach_const (ValueList, pValue, valList) { \
		if (i >= n) break; \
		v[i++] = pValue->getFunc(); \
	} \
	return true; \
}

#define DeclareArray(type, varName, n, iParam) \
type varName[n]; \
if (!ToArray(sig, varName, args.GetList(iParam), n, true, GetName(), #varName)) { \
	return Value::Null; \
}

#define DeclareNewArray(type, varName, iParam) \
type *varName = new type[args.GetList(iParam).size()]; \
do { \
	size_t i = 0; \
	foreach_const (ValueList, pValue, args.GetList(iParam)) { \
		varName[i++] = static_cast<type>(pValue->GetNumber()); \
	} \
} while (0);

ToArrayTemplate(GLbyte,		GetChar)
ToArrayTemplate(GLubyte,	GetUChar)
ToArrayTemplate(GLshort,	GetShort)
ToArrayTemplate(GLushort,	GetUShort)
ToArrayTemplate(GLint,		GetInt)
ToArrayTemplate(GLuint,		GetUInt)
ToArrayTemplate(GLfloat,	GetFloat)
ToArrayTemplate(GLdouble,	GetDouble)

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

//-----------------------------------------------------------------------------
// Object_Quadric
//-----------------------------------------------------------------------------
Function *Object_Quadric::_pFunc_QuadricErrorProc = NULL;

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
	Function::Delete(_pFunc_QuadricErrorProc);
	_pFunc_QuadricErrorProc = pFunc;
}

void Object_Quadric::Callback_QuadricErrorProc(GLenum err)
{
	if (_pFunc_QuadricErrorProc == NULL) return;
	Environment &env = _pFunc_QuadricErrorProc->GetEnvScope();
	Signal sig;
	//ValueList valListArg(Value(static_cast<int>(err)));
	AutoPtr<Args> pArgs(new Args());
	pArgs->AddValue(Value(static_cast<int>(err)));
	_pFunc_QuadricErrorProc->Eval(env, sig, *pArgs);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Quadric
//-----------------------------------------------------------------------------
// glu.gluQuadricNormals(qobj:Quadric, normals:number):void
Gura_DeclareFunction(gluQuadricNormals)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "qobj", VTYPE_Quadric);
	DeclareArg(env, "normals", VTYPE_number);
}

Gura_ImplementFunction(gluQuadricNormals)
{
	GLUquadric *qobj = Object_Quadric::GetObject(args, 0)->GetQuadric();
    GLenum normals = args.GetUInt(1);
	::gluQuadricNormals(qobj, normals);
	return Value::Null;
}

// glu.gluQuadricTexture(qobj:Quadric, textureCoords:boolean):void
Gura_DeclareFunction(gluQuadricTexture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "qobj", VTYPE_Quadric);
	DeclareArg(env, "textureCoords", VTYPE_boolean);
}

Gura_ImplementFunction(gluQuadricTexture)
{
	GLUquadric *qobj = Object_Quadric::GetObject(args, 0)->GetQuadric();
    GLboolean textureCoords = args.GetBoolean(0)? 1 : 0;
	::gluQuadricTexture(qobj, textureCoords);
	return Value::Null;
}

// glu.gluQuadricOrientation(qobj:Quadric, orientation:number):void
Gura_DeclareFunction(gluQuadricOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "qobj", VTYPE_Quadric);
	DeclareArg(env, "normals", VTYPE_number);
}

Gura_ImplementFunction(gluQuadricOrientation)
{
	GLUquadric *qobj = Object_Quadric::GetObject(args, 0)->GetQuadric();
    GLenum normals = args.GetUInt(1);
	::gluQuadricOrientation(qobj, normals);
	return Value::Null;
}

// glu.gluQuadricDrawStyle(qobj:Quadric, drawStyle:number):void
Gura_DeclareFunction(gluQuadricDrawStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "qobj", VTYPE_Quadric);
	DeclareArg(env, "drawStyle", VTYPE_number);
}

Gura_ImplementFunction(gluQuadricDrawStyle)
{
	GLUquadric *qobj = Object_Quadric::GetObject(args, 0)->GetQuadric();
    GLenum drawStyle = args.GetUInt(1);
	::gluQuadricDrawStyle(qobj, drawStyle);
	return Value::Null;
}

// glu.gluCylinder(qobj:Quadric, baseRadius:number, topRadius:number, height:number,
//                         slices:number, stacks:number):void
Gura_DeclareFunction(gluCylinder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "qobj", VTYPE_Quadric);
	DeclareArg(env, "baseRadius", VTYPE_number);
	DeclareArg(env, "topRadius", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "slices", VTYPE_number);
	DeclareArg(env, "stacks", VTYPE_number);
}

Gura_ImplementFunction(gluCylinder)
{
	GLUquadric *qobj = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLdouble baseRadius	= args.GetDouble(1);
	GLdouble topRadius	= args.GetDouble(2);
	GLdouble height		= args.GetDouble(3);
	GLint    slices		= args.GetInt(4);
	GLint    stacks		= args.GetInt(5);
	::gluCylinder(qobj, baseRadius, topRadius, height, slices, stacks);
	return Value::Null;
}

// glu.gluDisk(qobj:Quadric, innerRadius:number, outerRadius:number,
//                     slices:number, loops:number):void
Gura_DeclareFunction(gluDisk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "qobj", VTYPE_Quadric);
	DeclareArg(env, "innerRadius", VTYPE_number);
	DeclareArg(env, "outerRadius", VTYPE_number);
	DeclareArg(env, "slices", VTYPE_number);
	DeclareArg(env, "loops", VTYPE_number);
}

Gura_ImplementFunction(gluDisk)
{
	GLUquadric *qobj = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLdouble innerRadius	= args.GetDouble(1);
	GLdouble outerRadius	= args.GetDouble(2);
	GLint    slices			= args.GetInt(3);
	GLint    loops			= args.GetInt(4);
	::gluDisk(qobj, innerRadius, outerRadius, slices, loops);
	return Value::Null;
}

// glu.gluPartialDisk(qobj:Quadric, innerRadius:number, outerRadius:number,
//     slices:number, loops:number, startAngle:number, sweepAngle:number):void
Gura_DeclareFunction(gluPartialDisk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "qobj", VTYPE_Quadric);
	DeclareArg(env, "innerRadius", VTYPE_number);
	DeclareArg(env, "outerRadius", VTYPE_number);
	DeclareArg(env, "slices", VTYPE_number);
	DeclareArg(env, "loops", VTYPE_number);
	DeclareArg(env, "startAngle", VTYPE_number);
	DeclareArg(env, "sweepAngle", VTYPE_number);
}

Gura_ImplementFunction(gluPartialDisk)
{
	GLUquadric *qobj = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLdouble innerRadius	= args.GetDouble(1);
	GLdouble outerRadius	= args.GetDouble(2);
	GLint    slices			= args.GetInt(3);
	GLint    loops			= args.GetInt(4);
	GLdouble startAngle		= args.GetDouble(5);
	GLdouble sweepAngle		= args.GetDouble(6);
	::gluPartialDisk(qobj, innerRadius, outerRadius, slices, loops, startAngle, sweepAngle);
	return Value::Null;
}

// glu.gluSphere(qobj:Quadric, radius:number, slices:number, stacks:number):void
Gura_DeclareFunction(gluSphere)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "qobj", VTYPE_Quadric);
	DeclareArg(env, "radius", VTYPE_number);
	DeclareArg(env, "slices", VTYPE_number);
	DeclareArg(env, "stacks", VTYPE_number);
}

Gura_ImplementFunction(gluSphere)
{
	GLUquadric *qobj = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLdouble radius = args.GetDouble(1);
	GLint    slices = args.GetInt(2);
	GLint    stacks = args.GetInt(3);
	::gluSphere(qobj, radius, slices, stacks);
	return Value::Null;
}

// glu.gluQuadricCallback(qobj:Quadric, which:number, fn:function):void
Gura_DeclareFunction(gluQuadricCallback)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "qobj", VTYPE_Quadric);
	DeclareArg(env, "which", VTYPE_number);
	DeclareArg(env, "fn", VTYPE_function);
}

Gura_ImplementFunction(gluQuadricCallback)
{
	typedef void (__stdcall *funcType)();
	//typedef void (*funcType)();
	GLUquadric *qobj = Object_Quadric::GetObject(args, 0)->GetQuadric();
    GLenum which = args.GetUInt(1);
	Function *fn = Function::Reference(args.GetFunction(2));
	Object_Quadric::GetObject(args, 0)->SetQuadricErrorProc(fn);
	::gluQuadricCallback(qobj, which,
		reinterpret_cast<funcType>(Object_Quadric::Callback_QuadricErrorProc));
	return Value::Null;
}

// implementation of class Quadric
Gura_ImplementUserClass(Quadric)
{
	Gura_AssignFunction(gluQuadricNormals);
	Gura_AssignFunction(gluQuadricTexture);
	Gura_AssignFunction(gluQuadricOrientation);
	Gura_AssignFunction(gluQuadricDrawStyle);
	Gura_AssignFunction(gluCylinder);
	Gura_AssignFunction(gluDisk);
	Gura_AssignFunction(gluPartialDisk);
	Gura_AssignFunction(gluSphere);
	Gura_AssignFunction(gluQuadricCallback);
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

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Tesselator
//-----------------------------------------------------------------------------
// glu.gluTessBeginPolygon(tess:Tesselator):void {block?}
Gura_DeclareFunction(gluTessBeginPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(gluTessBeginPolygon)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	::gluTessBeginPolygon(tess, tess); // pass this object pointer to callback
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::gluTessEndPolygon(tess);
	}
	return Value::Null;
}

// glu.gluTessBeginContour(tess:Tesselator):void {block?}
Gura_DeclareFunction(gluTessBeginContour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(gluTessBeginContour)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	::gluTessBeginContour(tess);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::gluTessEndContour(tess);
	}
	return Value::Null;
}

// glu.gluTessVertex(tess:Tesselator, coords[]:number):void
Gura_DeclareFunction(gluTessVertex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
	DeclareArg(env, "coords", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(gluTessVertex)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	DeclareArray(GLdouble, coords, 3, 1);
	::gluTessVertex(tess, coords, tess); // pass this object pointer to callback
	return Value::Null;
}

// glu.gluTessEndContour(tess:Tesselator):void
Gura_DeclareFunction(gluTessEndContour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
}

Gura_ImplementFunction(gluTessEndContour)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	::gluTessEndContour(tess);
	return Value::Null;
}

// glu.gluTessEndPolygon(tess:Tesselator):void
Gura_DeclareFunction(gluTessEndPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
}

Gura_ImplementFunction(gluTessEndPolygon)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	::gluTessEndPolygon(tess);
	return Value::Null;
}

// glu.gluTessProperty(tess:Tesselator, which:number, value:number):void
Gura_DeclareFunction(gluTessProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
	DeclareArg(env, "which", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
}

Gura_ImplementFunction(gluTessProperty)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	GLenum   which = args.GetUInt(1);
	GLdouble value = args.GetDouble(2);
	::gluTessProperty(tess, which, value);
	return Value::Null;
}

// glu.gluTessNormal(tess:Tesselator, x:number, y:number, z:number):void
Gura_DeclareFunction(gluTessNormal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(gluTessNormal)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	GLdouble x = args.GetDouble(1);
	GLdouble y = args.GetDouble(2);
	GLdouble z = args.GetDouble(3);
	::gluTessNormal(tess, x, y, z);
	return Value::Null;
}

// glu.gluTessCallback(tess:Tesselator, which:number, fn:function):void
Gura_DeclareFunction(gluTessCallback)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
	DeclareArg(env, "which", VTYPE_number);
	DeclareArg(env, "fn", VTYPE_function);
}

Gura_ImplementFunction(gluTessCallback)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
#if 0
    GLenum which = args.GetUInt(1);
	Function *fn = args.GetFunction(2)->IncRef();
	Object_Quadric::GetObject(args, 0)->SetQuadricErrorProc(fn);
	::gluTessCallback(tess, which,
		reinterpret_cast<void (__stdcall *)()>(Object_Tesselator::Callback));
#endif
	sig.SetError(ERR_SystemError, "not implemented");
	return Value::Null;
}

// glu.gluGetTessProperty(tess:Tesselator, which:number)
Gura_DeclareFunction(gluGetTessProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
	DeclareArg(env, "which", VTYPE_number);
}

Gura_ImplementFunction(gluGetTessProperty)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	GLenum   which = args.GetUInt(1);
	GLdouble value = 0;
	::gluGetTessProperty(tess, which, &value);
	return Value(static_cast<Number>(value));
}

// glu.gluBeginPolygon(tess:Tesselator):void {block?}
Gura_DeclareFunction(gluBeginPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(gluBeginPolygon)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	::gluBeginPolygon(tess);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::gluEndPolygon(tess);
	}
	return Value::Null;
}

// glu.gluNextContour(tess:Tesselator, type:number):void
Gura_DeclareFunction(gluNextContour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
	DeclareArg(env, "type", VTYPE_number);
}

Gura_ImplementFunction(gluNextContour)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	GLenum type = args.GetUInt(1);
	::gluNextContour(tess, type);
	return Value::Null;
}

// glu.gluEndPolygon(tess:Tesselator):void
Gura_DeclareFunction(gluEndPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator);
}

Gura_ImplementFunction(gluEndPolygon)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	::gluEndPolygon(tess);
	return Value::Null;
}

// implementation of class Tesselator
Gura_ImplementUserClass(Tesselator)
{
	Gura_AssignFunction(gluTessBeginPolygon);
	Gura_AssignFunction(gluTessBeginContour);
	Gura_AssignFunction(gluTessVertex);
	Gura_AssignFunction(gluTessEndContour);
	Gura_AssignFunction(gluTessEndPolygon);
	Gura_AssignFunction(gluTessProperty);
	Gura_AssignFunction(gluTessNormal);
	Gura_AssignFunction(gluTessCallback);
	Gura_AssignFunction(gluGetTessProperty);
	Gura_AssignFunction(gluBeginPolygon);
	Gura_AssignFunction(gluNextContour);
	Gura_AssignFunction(gluEndPolygon);
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

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Nurbs
//-----------------------------------------------------------------------------
// glu.gluBeginSurface(nobj:Nurbs):void {block?}
Gura_DeclareFunction(gluBeginSurface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(gluBeginSurface)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	::gluBeginSurface(nobj);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::gluEndSurface(nobj);
	}
	return Value::Null;
}

// glu.gluBeginCurve(nobj:Nurbs):void {block?}
Gura_DeclareFunction(gluBeginCurve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(gluBeginCurve)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	::gluBeginCurve(nobj);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::gluEndCurve(nobj);
	}
	return Value::Null;
}

// glu.gluEndCurve(nobj:Nurbs):void
Gura_DeclareFunction(gluEndCurve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
}

Gura_ImplementFunction(gluEndCurve)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	::gluEndCurve(nobj);
	return Value::Null;
}

// glu.gluEndSurface(nobj:Nurbs):void
Gura_DeclareFunction(gluEndSurface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
}

Gura_ImplementFunction(gluEndSurface)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	::gluEndSurface(nobj);
	return Value::Null;
}

// glu.gluBeginTrim(nobj:Nurbs):void {block?}
Gura_DeclareFunction(gluBeginTrim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(gluBeginTrim)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	::gluBeginTrim(nobj);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::gluEndTrim(nobj);
	}
	return Value::Null;
}

// glu.gluEndTrim(nobj:Nurbs):void
Gura_DeclareFunction(gluEndTrim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
}

Gura_ImplementFunction(gluEndTrim)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	::gluEndTrim(nobj);
	return Value::Null;
}

// glu.gluPwlCurve(nobj:Nurbs, data[]:number, stride:number, type:number):void
Gura_DeclareFunction(gluPwlCurve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "stride", VTYPE_number);
	DeclareArg(env, "type", VTYPE_number);
}

Gura_ImplementFunction(gluPwlCurve)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	size_t n = args.GetList(1).size();
	DeclareNewArray(GLfloat, array, 1);
	GLint stride = args.GetInt(2);
	GLenum type = args.GetUInt(3);
	GLint count = 0;
	if (type == GLU_MAP1_TRIM_2) {
		count = static_cast<GLint>(n / 2);
	} else if (type == GLU_MAP1_TRIM_3) {
		count = static_cast<GLint>(n / 3);
	} else {
		sig.SetError(ERR_ValueError, "invalid type");
		return Value::Null;
	}
	::gluPwlCurve(nobj, count, array, stride, type);
	delete[] array;
	return Value::Null;
}

// glu.gluNurbsCurve(nobj:Nurbs, knot[]:number, stride:number,
//                         ctlarray[]:number, order:number, type:number):void
Gura_DeclareFunction(gluNurbsCurve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
	DeclareArg(env, "knot", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "stride", VTYPE_number);
	DeclareArg(env, "ctlarray", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "order", VTYPE_number);
	DeclareArg(env, "type", VTYPE_number);
}

Gura_ImplementFunction(gluNurbsCurve)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	GLint   nknots = static_cast<GLint>(args.GetList(1).size());
	DeclareNewArray(GLfloat, knot, 1);
	GLint   stride = args.GetInt(2);
	DeclareNewArray(GLfloat, ctlarray, 3);
	GLint   order = args.GetInt(4);
	GLenum  type = args.GetUInt(5);
	::gluNurbsCurve(nobj, nknots, knot, stride, ctlarray, order, type);
	delete[] knot;
	delete[] ctlarray;
	return Value::Null;
}

// glu.gluNurbsSurface(nobj:Nurbs, sknot[]:number, tknot[]:number, s_stride:number, t_stride:number,
//                     ctlarray[]:number, order:number, torder:number, type:number):void
Gura_DeclareFunction(gluNurbsSurface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
	DeclareArg(env, "sknot", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "tknot", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "s_stride", VTYPE_number);
	DeclareArg(env, "t_stride", VTYPE_number);
	DeclareArg(env, "ctlarray", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "order", VTYPE_number);
	DeclareArg(env, "torder", VTYPE_number);
	DeclareArg(env, "type", VTYPE_number);
}

Gura_ImplementFunction(gluNurbsSurface)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	GLint   sknot_count = static_cast<GLint>(args.GetList(1).size());
	DeclareNewArray(GLfloat, sknot, 1);
	GLint   tknot_count = static_cast<GLint>(args.GetList(2).size());
	DeclareNewArray(GLfloat, tknot, 2);
	GLint   s_stride = args.GetInt(3);
	GLint   t_stride = args.GetInt(4);
	DeclareNewArray(GLfloat, ctlarray, 5);
	GLint   sorder = args.GetInt(6);
	GLint   torder = args.GetInt(7);
	GLenum  type = args.GetUInt(8);
	::gluNurbsSurface(nobj, sknot_count, sknot, tknot_count,
					tknot, s_stride, t_stride, ctlarray, sorder, torder, type);
	delete[] sknot;
	delete[] tknot;
	delete[] ctlarray;
	return Value::Null;
}

// glu.gluLoadSamplingMatrices(nobj:Nurbs, model[]:number, perspective[]:number, view[]:number):void
Gura_DeclareFunction(gluLoadSamplingMatrices)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
	DeclareArg(env, "model", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "perspective", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "view", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(gluLoadSamplingMatrices)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	DeclareArray(GLfloat, model, 16, 1);
	DeclareArray(GLfloat, perspective, 16, 2);
	DeclareArray(GLint, view, 4, 3);
	::gluLoadSamplingMatrices(nobj, model, perspective, view);
	return Value::Null;
}

// glu.gluNurbsProperty(nobj:Nurbs, property:number, value:number):void
Gura_DeclareFunction(gluNurbsProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
	DeclareArg(env, "property", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
}

Gura_ImplementFunction(gluNurbsProperty)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	GLenum  property = args.GetUInt(1);
	GLfloat value = args.GetFloat(2);
	::gluNurbsProperty(nobj, property, value);
	return Value::Null;
}

// glu.gluGetNurbsProperty(nobj:Nurbs, property:number)
Gura_DeclareFunction(gluGetNurbsProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
	DeclareArg(env, "property", VTYPE_number);
}

Gura_ImplementFunction(gluGetNurbsProperty)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	GLenum  property = args.GetUInt(1);
	GLfloat value = 0;
	::gluGetNurbsProperty(nobj, property, &value);
	return Value(static_cast<Number>(value));
}

// glu.gluNurbsCallback(nobj:Nurbs):void
Gura_DeclareFunction(gluNurbsCallback)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nobj", VTYPE_Nurbs);
}

Gura_ImplementFunction(gluNurbsCallback)
{
	GLUnurbs *nobj = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	sig.SetError(ERR_SystemError, "not implemented");
	return Value::Null;
}

// implementation of class Nurbs
Gura_ImplementUserClass(Nurbs)
{
	Gura_AssignFunction(gluBeginSurface);
	Gura_AssignFunction(gluBeginCurve);
	Gura_AssignFunction(gluEndCurve);
	Gura_AssignFunction(gluEndSurface);
	Gura_AssignFunction(gluBeginTrim);
	Gura_AssignFunction(gluEndTrim);
	Gura_AssignFunction(gluPwlCurve);
	Gura_AssignFunction(gluNurbsCurve);
	Gura_AssignFunction(gluNurbsSurface);
	Gura_AssignFunction(gluLoadSamplingMatrices);
	Gura_AssignFunction(gluNurbsProperty);
	Gura_AssignFunction(gluGetNurbsProperty);
	Gura_AssignFunction(gluNurbsCallback);
}

//-----------------------------------------------------------------------------
// Gura module functions: glu
//-----------------------------------------------------------------------------
// glu.gluErrorStringWIN():void
Gura_DeclareFunction(gluErrorStringWIN)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(gluErrorStringWIN)
{
	sig.SetError(ERR_SystemError, "not implemented");
	return Value::Null;
}

// glu.gluErrorString():void
Gura_DeclareFunction(gluErrorString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(gluErrorString)
{
	sig.SetError(ERR_SystemError, "not implemented");
	return Value::Null;
}

// glu.gluErrorUnicodeStringEXT():void
Gura_DeclareFunction(gluErrorUnicodeStringEXT)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(gluErrorUnicodeStringEXT)
{
	sig.SetError(ERR_SystemError, "not implemented");
	return Value::Null;
}

// glu.gluGetString():void
Gura_DeclareFunction(gluGetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(gluGetString)
{
	sig.SetError(ERR_SystemError, "not implemented");
	return Value::Null;
}

// glu.gluOrtho2D(left:number, right:number, bottom:number, top:number):void
Gura_DeclareFunction(gluOrtho2D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "left", VTYPE_number);
	DeclareArg(env, "right", VTYPE_number);
	DeclareArg(env, "bottom", VTYPE_number);
	DeclareArg(env, "top", VTYPE_number);
}

Gura_ImplementFunction(gluOrtho2D)
{
	GLdouble left = args.GetDouble(0);
	GLdouble right = args.GetDouble(1);
	GLdouble bottom = args.GetDouble(2);
	GLdouble top = args.GetDouble(3);
	::gluOrtho2D(left, right, bottom, top);
	return Value::Null;
}

// glu.gluPerspective(fovy:number, aspect:number, zNear:number, zFar:number):void
Gura_DeclareFunction(gluPerspective)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "fovy", VTYPE_number);
	DeclareArg(env, "aspect", VTYPE_number);
	DeclareArg(env, "zNear", VTYPE_number);
	DeclareArg(env, "zFar", VTYPE_number);
}

Gura_ImplementFunction(gluPerspective)
{
	GLdouble fovy = args.GetDouble(0);
	GLdouble aspect = args.GetDouble(1);
	GLdouble zNear = args.GetDouble(2);
	GLdouble zFar = args.GetDouble(3);
	::gluPerspective(fovy, aspect, zNear, zFar);
	return Value::Null;
}

// glu.gluPickMatrix(x:number, y:number, width:number, height:number, viewport[]:number):void
Gura_DeclareFunction(gluPickMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "viewport", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(gluPickMatrix)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble width = args.GetDouble(2);
	GLdouble height = args.GetDouble(3);
	GLint viewport[4];
	do {
		const ValueList &valList = args.GetList(4);
		if (valList.size() != 4) {
			sig.SetError(ERR_ValueError,
						"viewport must have be a list with four elements");
			return Value::Null;
		}
		int i = 0;
		foreach_const (ValueList, pValue, valList) {
			viewport[i++] = pValue->GetInt();
		}
	} while (0);
	::gluPickMatrix(x, y, width, height, viewport);
	return Value::Null;
}

// glu.gluLookAt(eyex:number, eyey:number, eyez:number,
//               centerx:number, centery:number, centerz:number,
//               upx:number, upy:number, upz:number):void
Gura_DeclareFunction(gluLookAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "eyex", VTYPE_number);
	DeclareArg(env, "eyey", VTYPE_number);
	DeclareArg(env, "eyez", VTYPE_number);
	DeclareArg(env, "centerx", VTYPE_number);
	DeclareArg(env, "centery", VTYPE_number);
	DeclareArg(env, "centerz", VTYPE_number);
	DeclareArg(env, "upx", VTYPE_number);
	DeclareArg(env, "upy", VTYPE_number);
	DeclareArg(env, "upz", VTYPE_number);
}

Gura_ImplementFunction(gluLookAt)
{
	GLdouble eyex = args.GetDouble(0);
	GLdouble eyey = args.GetDouble(1);
	GLdouble eyez = args.GetDouble(2);
	GLdouble centerx = args.GetDouble(3);
	GLdouble centery = args.GetDouble(4);
	GLdouble centerz = args.GetDouble(5);
	GLdouble upx = args.GetDouble(6);
	GLdouble upy = args.GetDouble(7);
	GLdouble upz = args.GetDouble(8);
	::gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
	return Value::Null;
}

// glu.gluProject()
Gura_DeclareFunction(gluProject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "objX", VTYPE_number);
	DeclareArg(env, "objY", VTYPE_number);
	DeclareArg(env, "objZ", VTYPE_number);
	DeclareArg(env, "model", VTYPE_number);
	DeclareArg(env, "proj", VTYPE_number);
	DeclareArg(env, "view", VTYPE_number);
}

Gura_ImplementFunction(gluProject)
{
	GLdouble objX = args.GetDouble(0);
	GLdouble objY = args.GetDouble(1);
	GLdouble objZ = args.GetDouble(2);
	DeclareArray(GLdouble, model, 16, 3);
	DeclareArray(GLdouble, proj, 16, 4);
	DeclareArray(GLint, view, 4, 5);
	GLdouble winX, winY, winZ;
	::gluProject(objX, objY, objZ, model, proj, view, &winX, &winY, &winZ);
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.push_back(Value(winX));
	valList.push_back(Value(winY));
	valList.push_back(Value(winZ));
	return result;
}

// glu.gluUnProject()
Gura_DeclareFunction(gluUnProject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "winX", VTYPE_number);
	DeclareArg(env, "winY", VTYPE_number);
	DeclareArg(env, "winZ", VTYPE_number);
	DeclareArg(env, "model", VTYPE_number);
	DeclareArg(env, "proj", VTYPE_number);
	DeclareArg(env, "view", VTYPE_number);
}

Gura_ImplementFunction(gluUnProject)
{
	GLdouble winX = args.GetDouble(0);
	GLdouble winY = args.GetDouble(1);
	GLdouble winZ = args.GetDouble(2);
	DeclareArray(GLdouble, model, 16, 3);
	DeclareArray(GLdouble, proj, 16, 4);
	DeclareArray(GLint, view, 4, 5);
	GLdouble objX, objY, objZ;
	::gluUnProject(winX, winY, winZ, model, proj, view, &objX, &objY, &objZ);
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.push_back(Value(objX));
	valList.push_back(Value(objY));
	valList.push_back(Value(objZ));
	return result;
}

// glu.gluScaleImage(image:image, w:number, h:number):void
Gura_DeclareFunction(gluScaleImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "image", VTYPE_image);
	DeclareArg(env, "w", VTYPE_number);
	DeclareArg(env, "h", VTYPE_number);
	//DeclareArg(env, "format", VTYPE_symbol);
}

Gura_ImplementFunction(gluScaleImage)
{
	Image *pImageIn = Object_image::GetObject(args, 0)->GetImage();
	GLenum format = GetImageFormat(sig, pImageIn);
	if (sig.IsSignalled()) return Value::Null;
	GLsizei wIn = static_cast<GLsizei>(pImageIn->GetWidth());
	GLsizei hIn = static_cast<GLsizei>(pImageIn->GetHeight());
	GLenum typeIn = GL_UNSIGNED_BYTE;
	const void *dataIn = pImageIn->GetBuffer();
	GLsizei wOut = args.GetInt(1);
	GLsizei hOut = args.GetInt(2);
	GLenum typeOut = GL_UNSIGNED_BYTE;
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<Image> pImageOut(new Image(pImageIn->GetFormat()));
	if (!pImageOut->AllocBuffer(sig, wOut, hOut, 0xff)) {
		return Value::Null;
	}
	GLvoid *dataOut = pImageOut->GetBuffer();
	GLint rtn = ::gluScaleImage(format, wIn, hIn, typeIn, dataIn,
										 	wOut, hOut, typeOut, dataOut);
	if (rtn != 0) {
		sig.SetError(ERR_RuntimeError, "gluScaleImage error");
		return Value::Null;
	}
	return Value(new Object_image(env, pImageOut.release()));
}

// glu.gluBuild1DMipmaps(target:number, internalFormat:number, image:image):map
Gura_DeclareFunction(gluBuild1DMipmaps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "internalFormat", VTYPE_number);
	DeclareArg(env, "image", VTYPE_image);
}

Gura_ImplementFunction(gluBuild1DMipmaps)
{
	GLenum target = args.GetUInt(0);
	GLint internalFormat = args.GetInt(1);
	Image *pImage = Object_image::GetObject(args, 2)->GetImage();
	GLsizei width = static_cast<GLsizei>(pImage->GetWidth());
	GLenum format = static_cast<GLsizei>(GetImageFormat(sig, pImage));
	if (sig.IsSignalled()) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	const void *data = pImage->GetBuffer();
	GLint rtn = ::gluBuild1DMipmaps(target,
					internalFormat, width, format, type, data);
	return Value(rtn);
}

// glu.gluBuild2DMipmaps(target:number, internalFormat:number, image:image):map
Gura_DeclareFunction(gluBuild2DMipmaps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "internalFormat", VTYPE_number);
	DeclareArg(env, "image", VTYPE_image);
}

Gura_ImplementFunction(gluBuild2DMipmaps)
{
	GLenum target = args.GetUInt(0);
	GLint internalFormat = args.GetInt(1);
	Image *pImage = Object_image::GetObject(args, 2)->GetImage();
	Image::Format fmt = pImage->GetFormat();
	GLsizei width = static_cast<GLsizei>(pImage->GetWidth());
	GLsizei height = static_cast<GLsizei>(pImage->GetHeight());
	GLenum format = GetImageFormat(sig, pImage);
	if (sig.IsSignalled()) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	const void *data = pImage->GetBuffer();
	GLint rtn = ::gluBuild2DMipmaps(target,
					internalFormat, width, height, format, type, data);
	return Value(rtn);
}

// glu.gluNewQuadric()
Gura_DeclareFunction(gluNewQuadric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(gluNewQuadric)
{
	GLUquadric *qobj = ::gluNewQuadric();
	return Object_Quadric::CreateValue(qobj);
}

// glu.gluNewTess()
Gura_DeclareFunction(gluNewTess)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(gluNewTess)
{
	GLUtesselator *tess = ::gluNewTess();
	return Object_Tesselator::CreateValue(tess);
}

// glu.gluNewNurbsRenderer()
Gura_DeclareFunction(gluNewNurbsRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(gluNewNurbsRenderer)
{
	GLUnurbs *nobj = ::gluNewNurbsRenderer();
	return Object_Nurbs::CreateValue(nobj);
}

// Module entry
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeUserClass(Quadric,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Tesselator,	env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Nurbs,		env.LookupClass(VTYPE_object));
	// value assignment
	Gura_AssignValue(GLU_VERSION_1_1,                Value(GLU_VERSION_1_1));
	Gura_AssignValue(GLU_VERSION_1_2,                Value(GLU_VERSION_1_2));
	Gura_AssignValue(GLU_INVALID_ENUM,               Value(GLU_INVALID_ENUM));
	Gura_AssignValue(GLU_INVALID_VALUE,              Value(GLU_INVALID_VALUE));
	Gura_AssignValue(GLU_OUT_OF_MEMORY,              Value(GLU_OUT_OF_MEMORY));
	Gura_AssignValue(GLU_INCOMPATIBLE_GL_VERSION,    Value(GLU_INCOMPATIBLE_GL_VERSION));
	Gura_AssignValue(GLU_VERSION,                    Value(GLU_VERSION));
	Gura_AssignValue(GLU_EXTENSIONS,                 Value(GLU_EXTENSIONS));
	Gura_AssignValue(GLU_TRUE,                       Value(GLU_TRUE));
	Gura_AssignValue(GLU_FALSE,                      Value(GLU_FALSE));
	Gura_AssignValue(GLU_SMOOTH,                     Value(GLU_SMOOTH));
	Gura_AssignValue(GLU_FLAT,                       Value(GLU_FLAT));
	Gura_AssignValue(GLU_NONE,                       Value(GLU_NONE));
	Gura_AssignValue(GLU_POINT,                      Value(GLU_POINT));
	Gura_AssignValue(GLU_LINE,                       Value(GLU_LINE));
	Gura_AssignValue(GLU_FILL,                       Value(GLU_FILL));
	Gura_AssignValue(GLU_SILHOUETTE,                 Value(GLU_SILHOUETTE));
	Gura_AssignValue(GLU_OUTSIDE,                    Value(GLU_OUTSIDE));
	Gura_AssignValue(GLU_INSIDE,                     Value(GLU_INSIDE));
	Gura_AssignValue(GLU_TESS_MAX_COORD,             Value(GLU_TESS_MAX_COORD));
	Gura_AssignValue(GLU_TESS_WINDING_RULE,          Value(GLU_TESS_WINDING_RULE));
	Gura_AssignValue(GLU_TESS_BOUNDARY_ONLY,         Value(GLU_TESS_BOUNDARY_ONLY));
	Gura_AssignValue(GLU_TESS_TOLERANCE,             Value(GLU_TESS_TOLERANCE));
	Gura_AssignValue(GLU_TESS_WINDING_ODD,           Value(GLU_TESS_WINDING_ODD));
	Gura_AssignValue(GLU_TESS_WINDING_NONZERO,       Value(GLU_TESS_WINDING_NONZERO));
	Gura_AssignValue(GLU_TESS_WINDING_POSITIVE,      Value(GLU_TESS_WINDING_POSITIVE));
	Gura_AssignValue(GLU_TESS_WINDING_NEGATIVE,      Value(GLU_TESS_WINDING_NEGATIVE));
	Gura_AssignValue(GLU_TESS_WINDING_ABS_GEQ_TWO,   Value(GLU_TESS_WINDING_ABS_GEQ_TWO));
	Gura_AssignValue(GLU_TESS_BEGIN,                 Value(GLU_TESS_BEGIN));
	Gura_AssignValue(GLU_TESS_VERTEX,                Value(GLU_TESS_VERTEX));
	Gura_AssignValue(GLU_TESS_END,                   Value(GLU_TESS_END));
	Gura_AssignValue(GLU_TESS_ERROR,                 Value(GLU_TESS_ERROR));
	Gura_AssignValue(GLU_TESS_EDGE_FLAG,             Value(GLU_TESS_EDGE_FLAG));
	Gura_AssignValue(GLU_TESS_COMBINE,               Value(GLU_TESS_COMBINE));
	Gura_AssignValue(GLU_TESS_BEGIN_DATA,            Value(GLU_TESS_BEGIN_DATA));
	Gura_AssignValue(GLU_TESS_VERTEX_DATA,           Value(GLU_TESS_VERTEX_DATA));
	Gura_AssignValue(GLU_TESS_END_DATA,              Value(GLU_TESS_END_DATA));
	Gura_AssignValue(GLU_TESS_ERROR_DATA,            Value(GLU_TESS_ERROR_DATA));
	Gura_AssignValue(GLU_TESS_EDGE_FLAG_DATA,        Value(GLU_TESS_EDGE_FLAG_DATA));
	Gura_AssignValue(GLU_TESS_COMBINE_DATA,          Value(GLU_TESS_COMBINE_DATA));
	Gura_AssignValue(GLU_TESS_ERROR1,                Value(GLU_TESS_ERROR1));
	Gura_AssignValue(GLU_TESS_ERROR2,                Value(GLU_TESS_ERROR2));
	Gura_AssignValue(GLU_TESS_ERROR3,                Value(GLU_TESS_ERROR3));
	Gura_AssignValue(GLU_TESS_ERROR4,                Value(GLU_TESS_ERROR4));
	Gura_AssignValue(GLU_TESS_ERROR5,                Value(GLU_TESS_ERROR5));
	Gura_AssignValue(GLU_TESS_ERROR6,                Value(GLU_TESS_ERROR6));
	Gura_AssignValue(GLU_TESS_ERROR7,                Value(GLU_TESS_ERROR7));
	Gura_AssignValue(GLU_TESS_ERROR8,                Value(GLU_TESS_ERROR8));
	Gura_AssignValue(GLU_TESS_MISSING_BEGIN_POLYGON, Value(GLU_TESS_MISSING_BEGIN_POLYGON));
	Gura_AssignValue(GLU_TESS_MISSING_BEGIN_CONTOUR, Value(GLU_TESS_MISSING_BEGIN_CONTOUR));
	Gura_AssignValue(GLU_TESS_MISSING_END_POLYGON,   Value(GLU_TESS_MISSING_END_POLYGON));
	Gura_AssignValue(GLU_TESS_MISSING_END_CONTOUR,   Value(GLU_TESS_MISSING_END_CONTOUR));
	Gura_AssignValue(GLU_TESS_COORD_TOO_LARGE,       Value(GLU_TESS_COORD_TOO_LARGE));
	Gura_AssignValue(GLU_TESS_NEED_COMBINE_CALLBACK, Value(GLU_TESS_NEED_COMBINE_CALLBACK));
	Gura_AssignValue(GLU_AUTO_LOAD_MATRIX,           Value(GLU_AUTO_LOAD_MATRIX));
	Gura_AssignValue(GLU_CULLING,                    Value(GLU_CULLING));
	Gura_AssignValue(GLU_SAMPLING_TOLERANCE,         Value(GLU_SAMPLING_TOLERANCE));
	Gura_AssignValue(GLU_DISPLAY_MODE,               Value(GLU_DISPLAY_MODE));
	Gura_AssignValue(GLU_PARAMETRIC_TOLERANCE,       Value(GLU_PARAMETRIC_TOLERANCE));
	Gura_AssignValue(GLU_SAMPLING_METHOD,            Value(GLU_SAMPLING_METHOD));
	Gura_AssignValue(GLU_U_STEP,                     Value(GLU_U_STEP));
	Gura_AssignValue(GLU_V_STEP,                     Value(GLU_V_STEP));
	Gura_AssignValue(GLU_PATH_LENGTH,                Value(GLU_PATH_LENGTH));
	Gura_AssignValue(GLU_PARAMETRIC_ERROR,           Value(GLU_PARAMETRIC_ERROR));
	Gura_AssignValue(GLU_DOMAIN_DISTANCE,            Value(GLU_DOMAIN_DISTANCE));
	Gura_AssignValue(GLU_MAP1_TRIM_2,                Value(GLU_MAP1_TRIM_2));
	Gura_AssignValue(GLU_MAP1_TRIM_3,                Value(GLU_MAP1_TRIM_3));
	Gura_AssignValue(GLU_OUTLINE_POLYGON,            Value(GLU_OUTLINE_POLYGON));
	Gura_AssignValue(GLU_OUTLINE_PATCH,              Value(GLU_OUTLINE_PATCH));
	Gura_AssignValue(GLU_NURBS_ERROR1,               Value(GLU_NURBS_ERROR1));
	Gura_AssignValue(GLU_NURBS_ERROR2,               Value(GLU_NURBS_ERROR2));
	Gura_AssignValue(GLU_NURBS_ERROR3,               Value(GLU_NURBS_ERROR3));
	Gura_AssignValue(GLU_NURBS_ERROR4,               Value(GLU_NURBS_ERROR4));
	Gura_AssignValue(GLU_NURBS_ERROR5,               Value(GLU_NURBS_ERROR5));
	Gura_AssignValue(GLU_NURBS_ERROR6,               Value(GLU_NURBS_ERROR6));
	Gura_AssignValue(GLU_NURBS_ERROR7,               Value(GLU_NURBS_ERROR7));
	Gura_AssignValue(GLU_NURBS_ERROR8,               Value(GLU_NURBS_ERROR8));
	Gura_AssignValue(GLU_NURBS_ERROR9,               Value(GLU_NURBS_ERROR9));
	Gura_AssignValue(GLU_NURBS_ERROR10,              Value(GLU_NURBS_ERROR10));
	Gura_AssignValue(GLU_NURBS_ERROR11,              Value(GLU_NURBS_ERROR11));
	Gura_AssignValue(GLU_NURBS_ERROR12,              Value(GLU_NURBS_ERROR12));
	Gura_AssignValue(GLU_NURBS_ERROR13,              Value(GLU_NURBS_ERROR13));
	Gura_AssignValue(GLU_NURBS_ERROR14,              Value(GLU_NURBS_ERROR14));
	Gura_AssignValue(GLU_NURBS_ERROR15,              Value(GLU_NURBS_ERROR15));
	Gura_AssignValue(GLU_NURBS_ERROR16,              Value(GLU_NURBS_ERROR16));
	Gura_AssignValue(GLU_NURBS_ERROR17,              Value(GLU_NURBS_ERROR17));
	Gura_AssignValue(GLU_NURBS_ERROR18,              Value(GLU_NURBS_ERROR18));
	Gura_AssignValue(GLU_NURBS_ERROR19,              Value(GLU_NURBS_ERROR19));
	Gura_AssignValue(GLU_NURBS_ERROR20,              Value(GLU_NURBS_ERROR20));
	Gura_AssignValue(GLU_NURBS_ERROR21,              Value(GLU_NURBS_ERROR21));
	Gura_AssignValue(GLU_NURBS_ERROR22,              Value(GLU_NURBS_ERROR22));
	Gura_AssignValue(GLU_NURBS_ERROR23,              Value(GLU_NURBS_ERROR23));
	Gura_AssignValue(GLU_NURBS_ERROR24,              Value(GLU_NURBS_ERROR24));
	Gura_AssignValue(GLU_NURBS_ERROR25,              Value(GLU_NURBS_ERROR25));
	Gura_AssignValue(GLU_NURBS_ERROR26,              Value(GLU_NURBS_ERROR26));
	Gura_AssignValue(GLU_NURBS_ERROR27,              Value(GLU_NURBS_ERROR27));
	Gura_AssignValue(GLU_NURBS_ERROR28,              Value(GLU_NURBS_ERROR28));
	Gura_AssignValue(GLU_NURBS_ERROR29,              Value(GLU_NURBS_ERROR29));
	Gura_AssignValue(GLU_NURBS_ERROR30,              Value(GLU_NURBS_ERROR30));
	Gura_AssignValue(GLU_NURBS_ERROR31,              Value(GLU_NURBS_ERROR31));
	Gura_AssignValue(GLU_NURBS_ERROR32,              Value(GLU_NURBS_ERROR32));
	Gura_AssignValue(GLU_NURBS_ERROR33,              Value(GLU_NURBS_ERROR33));
	Gura_AssignValue(GLU_NURBS_ERROR34,              Value(GLU_NURBS_ERROR34));
	Gura_AssignValue(GLU_NURBS_ERROR35,              Value(GLU_NURBS_ERROR35));
	Gura_AssignValue(GLU_NURBS_ERROR36,              Value(GLU_NURBS_ERROR36));
	Gura_AssignValue(GLU_NURBS_ERROR37,              Value(GLU_NURBS_ERROR37));
	Gura_AssignValue(GLU_CW,                         Value(GLU_CW));
	Gura_AssignValue(GLU_CCW,                        Value(GLU_CCW));
	Gura_AssignValue(GLU_INTERIOR,                   Value(GLU_INTERIOR));
	Gura_AssignValue(GLU_EXTERIOR,                   Value(GLU_EXTERIOR));
	Gura_AssignValue(GLU_UNKNOWN,                    Value(GLU_UNKNOWN));
	Gura_AssignValue(GLU_BEGIN,                      Value(GLU_BEGIN));
	Gura_AssignValue(GLU_VERTEX,                     Value(GLU_VERTEX));
	Gura_AssignValue(GLU_END,                        Value(GLU_END));
	Gura_AssignValue(GLU_ERROR,                      Value(GLU_ERROR));
	Gura_AssignValue(GLU_EDGE_FLAG,                  Value(GLU_EDGE_FLAG));
	// function assignment
	Gura_AssignFunction(gluErrorStringWIN);
	Gura_AssignFunction(gluErrorString);
	Gura_AssignFunction(gluErrorUnicodeStringEXT);
	Gura_AssignFunction(gluGetString);
	Gura_AssignFunction(gluOrtho2D);
	Gura_AssignFunction(gluPerspective);
	Gura_AssignFunction(gluPickMatrix);
	Gura_AssignFunction(gluLookAt);
	Gura_AssignFunction(gluProject);
	Gura_AssignFunction(gluUnProject);
	Gura_AssignFunction(gluScaleImage);
	Gura_AssignFunction(gluBuild1DMipmaps);
	Gura_AssignFunction(gluBuild2DMipmaps);
	Gura_AssignFunction(gluNewQuadric);
	Gura_AssignFunction(gluNewTess);
	Gura_AssignFunction(gluNewNurbsRenderer);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(glu, glu)

Gura_RegisterModule(glu)
