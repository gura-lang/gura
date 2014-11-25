// Don't edit this file. This has been generated by Functions.cpp.gura.
#include "stdafx.h"

Gura_BeginModuleScope(glu)

// glu.gluBeginCurve
Gura_DeclareFunction(gluBeginCurve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluBeginCurve)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	gluBeginCurve(nurb);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		gluEndCurve(nurb);
	}
	return Value::Null;
}

// glu.gluBeginPolygon
Gura_DeclareFunction(gluBeginPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluBeginPolygon)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	gluBeginPolygon(tess);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		gluEndPolygon(tess);
	}
	return Value::Null;
}

// glu.gluBeginSurface
Gura_DeclareFunction(gluBeginSurface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluBeginSurface)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	gluBeginSurface(nurb);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		gluEndSurface(nurb);
	}
	return Value::Null;
}

// glu.gluBeginTrim
Gura_DeclareFunction(gluBeginTrim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluBeginTrim)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	gluBeginTrim(nurb);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		gluEndTrim(nurb);
	}
	return Value::Null;
}

// glu.gluBuild1DMipmaps
Gura_DeclareFunction(gluBuild1DMipmaps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "internalFormat", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "image", VTYPE_image, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluBuild1DMipmaps)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint internalFormat = args.GetInt(1);
	Image *image = Object_image::GetObject(args, 2)->GetImage();
	GLsizei width = static_cast<GLsizei>(image->GetWidth());
	GLenum format = static_cast<GLsizei>(GetImageFormat(sig, image));
	if (sig.IsSignalled()) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	const void *data = image->GetBuffer();
	GLint _rtn = gluBuild1DMipmaps(target,
					internalFormat, width, format, type, data);
	return Value(_rtn);
}

// glu.gluBuild2DMipmaps
Gura_DeclareFunction(gluBuild2DMipmaps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "internalFormat", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "image", VTYPE_image, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluBuild2DMipmaps)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint internalFormat = args.GetInt(1);
	Image *image = Object_image::GetObject(args, 2)->GetImage();
	GLsizei width = static_cast<GLsizei>(image->GetWidth());
	GLsizei height = static_cast<GLsizei>(image->GetHeight());
	GLenum format = static_cast<GLsizei>(GetImageFormat(sig, image));
	if (sig.IsSignalled()) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	const void *data = image->GetBuffer();
	GLint _rtn = gluBuild2DMipmaps(target,
					internalFormat, width, height, format, type, data);
	return Value(_rtn);
}

// glu.gluCylinder
Gura_DeclareFunction(gluCylinder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	DeclareArg(env, "base", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "top", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "slices", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "stacks", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluCylinder)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLdouble base = args.GetDouble(1);
	GLdouble top = args.GetDouble(2);
	GLdouble height = args.GetDouble(3);
	GLint slices = args.GetInt(4);
	GLint stacks = args.GetInt(5);
	gluCylinder(quad, base, top, height, slices, stacks);
	return Value::Null;
}

// glu.gluDeleteNurbsRenderer
Gura_DeclareFunction(gluDeleteNurbsRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluDeleteNurbsRenderer)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	gluDeleteNurbsRenderer(nurb);
	return Value::Null;
}

// glu.gluDeleteQuadric
Gura_DeclareFunction(gluDeleteQuadric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluDeleteQuadric)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	gluDeleteQuadric(quad);
	return Value::Null;
}

// glu.gluDeleteTess
Gura_DeclareFunction(gluDeleteTess)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluDeleteTess)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	gluDeleteTess(tess);
	return Value::Null;
}

// glu.gluDisk
Gura_DeclareFunction(gluDisk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	DeclareArg(env, "inner", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "outer", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "slices", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "loops", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluDisk)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLdouble inner = args.GetDouble(1);
	GLdouble outer = args.GetDouble(2);
	GLint slices = args.GetInt(3);
	GLint loops = args.GetInt(4);
	gluDisk(quad, inner, outer, slices, loops);
	return Value::Null;
}

// glu.gluEndCurve
Gura_DeclareFunction(gluEndCurve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluEndCurve)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	gluEndCurve(nurb);
	return Value::Null;
}

// glu.gluEndPolygon
Gura_DeclareFunction(gluEndPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluEndPolygon)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	gluEndPolygon(tess);
	return Value::Null;
}

// glu.gluEndSurface
Gura_DeclareFunction(gluEndSurface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluEndSurface)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	gluEndSurface(nurb);
	return Value::Null;
}

// glu.gluEndTrim
Gura_DeclareFunction(gluEndTrim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluEndTrim)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	gluEndTrim(nurb);
	return Value::Null;
}

// glu.gluErrorString
Gura_DeclareFunction(gluErrorString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "error", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluErrorString)
{
	GLenum error = static_cast<GLenum>(args.GetInt(0));
	const GLubyte *_rtn = gluErrorString(error);
	return ReturnValue(env, sig, args, Value(reinterpret_cast<const char *>(_rtn)));
}

// glu.gluGetNurbsProperty
Gura_DeclareFunction(gluGetNurbsProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	DeclareArg(env, "property", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluGetNurbsProperty)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	GLenum property = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> data = args.GetList(2);
	gluGetNurbsProperty(nurb, property, data);
	return Value::Null;
}

// glu.gluGetString
Gura_DeclareFunction(gluGetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluGetString)
{
	GLenum name = static_cast<GLenum>(args.GetInt(0));
	const GLubyte *_rtn = gluGetString(name);
	return ReturnValue(env, sig, args, Value(reinterpret_cast<const char *>(_rtn)));
}

// glu.gluGetTessProperty
Gura_DeclareFunction(gluGetTessProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluGetTessProperty)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	GLenum which = static_cast<GLenum>(args.GetInt(1));
	CArray<GLdouble> data = args.GetList(2);
	gluGetTessProperty(tess, which, data);
	return Value::Null;
}

// glu.gluLoadSamplingMatrices
Gura_DeclareFunction(gluLoadSamplingMatrices)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	DeclareArg(env, "model", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "perspective", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "view", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluLoadSamplingMatrices)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	CArray<GLfloat> model = args.GetList(1);
	CArray<GLfloat> perspective = args.GetList(2);
	CArray<GLint> view = args.GetList(3);
	gluLoadSamplingMatrices(nurb, model, perspective, view);
	return Value::Null;
}

// glu.gluLookAt
Gura_DeclareFunction(gluLookAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "eyeX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "eyeY", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "eyeZ", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "centerX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "centerY", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "centerZ", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "upX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "upY", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "upZ", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluLookAt)
{
	GLdouble eyeX = args.GetDouble(0);
	GLdouble eyeY = args.GetDouble(1);
	GLdouble eyeZ = args.GetDouble(2);
	GLdouble centerX = args.GetDouble(3);
	GLdouble centerY = args.GetDouble(4);
	GLdouble centerZ = args.GetDouble(5);
	GLdouble upX = args.GetDouble(6);
	GLdouble upY = args.GetDouble(7);
	GLdouble upZ = args.GetDouble(8);
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
	return Value::Null;
}

// glu.gluNewNurbsRenderer
Gura_DeclareFunction(gluNewNurbsRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNewNurbsRenderer)
{
	GLUnurbs *_rtn = gluNewNurbsRenderer();
	return ReturnValue(env, sig, args, Value(new Object_Nurbs(_rtn)));
}

// glu.gluNewQuadric
Gura_DeclareFunction(gluNewQuadric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNewQuadric)
{
	GLUquadric *_rtn = gluNewQuadric();
	return ReturnValue(env, sig, args, Value(new Object_Quadric(_rtn)));
}

// glu.gluNewTess
Gura_DeclareFunction(gluNewTess)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNewTess)
{
	GLUtesselator *_rtn = gluNewTess();
	return ReturnValue(env, sig, args, Value(new Object_Tesselator(_rtn)));
}

// glu.gluNextContour
Gura_DeclareFunction(gluNextContour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNextContour)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	GLenum type = static_cast<GLenum>(args.GetInt(1));
	gluNextContour(tess, type);
	return Value::Null;
}

// glu.gluNurbsCallback
Gura_DeclareFunction(gluNurbsCallback)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurbs", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "CallBackFunc", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNurbsCallback)
{
#if 0
	GLUnurbs *nurbs = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	GLenum which = static_cast<GLenum>(args.GetInt(1));
	int CallBackFunc = args.GetInt(2);
	gluNurbsCallback(nurbs, which, CallBackFunc);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "gluNurbsCallback");
	return Value::Null;
}

// glu.gluNurbsCallbackData
Gura_DeclareFunction(gluNurbsCallbackData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	DeclareArg(env, "userData", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNurbsCallbackData)
{
#if 0
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	int userData = args.GetInt(1);
	gluNurbsCallbackData(nurb, userData);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "gluNurbsCallbackData");
	return Value::Null;
}

// glu.gluNurbsCallbackDataEXT
Gura_DeclareFunction(gluNurbsCallbackDataEXT)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	DeclareArg(env, "userData", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNurbsCallbackDataEXT)
{
#if 0
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	int userData = args.GetInt(1);
	gluNurbsCallbackDataEXT(nurb, userData);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "gluNurbsCallbackDataEXT");
	return Value::Null;
}

// glu.gluNurbsCurve
Gura_DeclareFunction(gluNurbsCurve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	DeclareArg(env, "knots", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "stride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "control", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "order", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNurbsCurve)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	CArray<GLfloat> knots = args.GetList(1);
	GLint stride = args.GetInt(2);
	CArray<GLfloat> control = args.GetList(3);
	GLint order = args.GetInt(4);
	GLenum type = static_cast<GLenum>(args.GetInt(5));
	GLint knotCount = static_cast<GLint>(knots.GetSize());
	gluNurbsCurve(nurb, knotCount, knots, stride, control, order, type);
	return Value::Null;
}

// glu.gluNurbsProperty
Gura_DeclareFunction(gluNurbsProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	DeclareArg(env, "property", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNurbsProperty)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	GLenum property = static_cast<GLenum>(args.GetInt(1));
	GLfloat value = args.GetFloat(2);
	gluNurbsProperty(nurb, property, value);
	return Value::Null;
}

// glu.gluNurbsSurface
Gura_DeclareFunction(gluNurbsSurface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	DeclareArg(env, "sKnots", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "tKnots", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "sStride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "tStride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "control", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "sOrder", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "tOrder", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluNurbsSurface)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	CArray<GLfloat> sKnots = args.GetList(1);
	CArray<GLfloat> tKnots = args.GetList(2);
	GLint sStride = args.GetInt(3);
	GLint tStride = args.GetInt(4);
	CArray<GLfloat> control = args.GetList(5);
	GLint sOrder = args.GetInt(6);
	GLint tOrder = args.GetInt(7);
	GLenum type = static_cast<GLenum>(args.GetInt(8));
	GLint sKnotCount = static_cast<GLint>(sKnots.GetSize());
	GLint tKnotCount = static_cast<GLint>(tKnots.GetSize());
	gluNurbsSurface(nurb, sKnotCount, sKnots, tKnotCount, tKnots, sStride, tStride,
	control, sOrder, tOrder, type);
	return Value::Null;
}

// glu.gluOrtho2D
Gura_DeclareFunction(gluOrtho2D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "left", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "right", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "top", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluOrtho2D)
{
	GLdouble left = args.GetDouble(0);
	GLdouble right = args.GetDouble(1);
	GLdouble bottom = args.GetDouble(2);
	GLdouble top = args.GetDouble(3);
	gluOrtho2D(left, right, bottom, top);
	return Value::Null;
}

// glu.gluPartialDisk
Gura_DeclareFunction(gluPartialDisk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	DeclareArg(env, "inner", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "outer", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "slices", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "loops", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "sweep", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluPartialDisk)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLdouble inner = args.GetDouble(1);
	GLdouble outer = args.GetDouble(2);
	GLint slices = args.GetInt(3);
	GLint loops = args.GetInt(4);
	GLdouble start = args.GetDouble(5);
	GLdouble sweep = args.GetDouble(6);
	gluPartialDisk(quad, inner, outer, slices, loops, start, sweep);
	return Value::Null;
}

// glu.gluPerspective
Gura_DeclareFunction(gluPerspective)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "fovy", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "aspect", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zNear", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zFar", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluPerspective)
{
	GLdouble fovy = args.GetDouble(0);
	GLdouble aspect = args.GetDouble(1);
	GLdouble zNear = args.GetDouble(2);
	GLdouble zFar = args.GetDouble(3);
	gluPerspective(fovy, aspect, zNear, zFar);
	return Value::Null;
}

// glu.gluPickMatrix
Gura_DeclareFunction(gluPickMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "delX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "delY", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "viewport", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluPickMatrix)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble delX = args.GetDouble(2);
	GLdouble delY = args.GetDouble(3);
	CArray<GLint> viewport = args.GetList(4);
	gluPickMatrix(x, y, delX, delY, viewport);
	return Value::Null;
}

// glu.gluProject
Gura_DeclareFunction(gluProject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "objX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "objY", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "objZ", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "model", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "proj", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "view", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "winX", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "winY", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "winZ", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluProject)
{
	GLdouble objX = args.GetDouble(0);
	GLdouble objY = args.GetDouble(1);
	GLdouble objZ = args.GetDouble(2);
	CArray<GLdouble> model = args.GetList(3);
	CArray<GLdouble> proj = args.GetList(4);
	CArray<GLint> view = args.GetList(5);
	CArray<GLdouble> winX = args.GetList(6);
	CArray<GLdouble> winY = args.GetList(7);
	CArray<GLdouble> winZ = args.GetList(8);
	GLint _rtn = gluProject(objX, objY, objZ, model, proj, view, winX, winY, winZ);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// glu.gluPwlCurve
Gura_DeclareFunction(gluPwlCurve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nurb", VTYPE_Nurbs, OCCUR_Once, FLAG_None);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "stride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluPwlCurve)
{
	GLUnurbs *nurb = Object_Nurbs::GetObject(args, 0)->GetNurbs();
	CArray<GLfloat> data = args.GetList(1);
	GLint stride = args.GetInt(2);
	GLenum type = static_cast<GLenum>(args.GetInt(3));
	GLint count = static_cast<GLint>(data.GetSize());
	gluPwlCurve(nurb, count, data, stride, type);
	return Value::Null;
}

// glu.gluQuadricCallback
Gura_DeclareFunction(gluQuadricCallback)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "CallbackFunc", VTYPE_function, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluQuadricCallback)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLenum which = static_cast<GLenum>(args.GetInt(1));
	const Function *CallbackFunc = Object_function::GetObject(args, 2)->GetFunction();
	typedef void (__stdcall *funcType)();
	Object_Quadric::GetObject(args, 0)->SetQuadricErrorProc(CallbackFunc->Reference());
	gluQuadricCallback(quad, which,
		reinterpret_cast<funcType>(Object_Quadric::Callback_QuadricErrorProc));
	return Value::Null;
}

// glu.gluQuadricDrawStyle
Gura_DeclareFunction(gluQuadricDrawStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	DeclareArg(env, "draw", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluQuadricDrawStyle)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLenum draw = static_cast<GLenum>(args.GetInt(1));
	gluQuadricDrawStyle(quad, draw);
	return Value::Null;
}

// glu.gluQuadricNormals
Gura_DeclareFunction(gluQuadricNormals)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	DeclareArg(env, "normal", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluQuadricNormals)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLenum normal = static_cast<GLenum>(args.GetInt(1));
	gluQuadricNormals(quad, normal);
	return Value::Null;
}

// glu.gluQuadricOrientation
Gura_DeclareFunction(gluQuadricOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluQuadricOrientation)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLenum orientation = static_cast<GLenum>(args.GetInt(1));
	gluQuadricOrientation(quad, orientation);
	return Value::Null;
}

// glu.gluQuadricTexture
Gura_DeclareFunction(gluQuadricTexture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluQuadricTexture)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLboolean texture = (args.GetBoolean(1)? GL_TRUE : GL_FALSE);
	gluQuadricTexture(quad, texture);
	return Value::Null;
}

// glu.gluScaleImage
Gura_DeclareFunction(gluScaleImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "imageIn", VTYPE_image, OCCUR_Once, FLAG_None);
	DeclareArg(env, "wOut", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hOut", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluScaleImage)
{
	Image *imageIn = Object_image::GetObject(args, 0)->GetImage();
	GLsizei wOut = args.GetInt(1);
	GLsizei hOut = args.GetInt(2);
	GLenum format = GetImageFormat(sig, imageIn);
	if (sig.IsSignalled()) return Value::Null;
	GLsizei wIn = static_cast<GLsizei>(imageIn->GetWidth());
	GLsizei hIn = static_cast<GLsizei>(imageIn->GetHeight());
	GLenum typeIn = GL_UNSIGNED_BYTE;
	const void *dataIn = imageIn->GetBuffer();
	GLenum typeOut = GL_UNSIGNED_BYTE;
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<Image> imageOut(new Image(imageIn->GetFormat()));
	if (!imageOut->AllocBuffer(sig, wOut, hOut, 0xff)) {
		return Value::Null;
	}
	GLvoid *dataOut = imageOut->GetBuffer();
	GLint rtn = gluScaleImage(format, wIn, hIn, typeIn, dataIn,
										 	wOut, hOut, typeOut, dataOut);
	if (rtn != 0) {
		sig.SetError(ERR_RuntimeError, "gluScaleImage error");
		return Value::Null;
	}
	return Value(new Object_image(env, imageOut.release()));
}

// glu.gluSphere
Gura_DeclareFunction(gluSphere)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "quad", VTYPE_Quadric, OCCUR_Once, FLAG_None);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "slices", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "stacks", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluSphere)
{
	GLUquadric *quad = Object_Quadric::GetObject(args, 0)->GetQuadric();
	GLdouble radius = args.GetDouble(1);
	GLint slices = args.GetInt(2);
	GLint stacks = args.GetInt(3);
	gluSphere(quad, radius, slices, stacks);
	return Value::Null;
}

// glu.gluTessBeginContour
Gura_DeclareFunction(gluTessBeginContour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluTessBeginContour)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	gluTessBeginContour(tess);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		gluTessEndContour(tess);
	}
	return Value::Null;
}

// glu.gluTessBeginPolygon
Gura_DeclareFunction(gluTessBeginPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluTessBeginPolygon)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	int data = args.GetInt(1);
	gluTessBeginPolygon(tess, tess); // pass this object pointer to callback
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		gluTessEndPolygon(tess);
	}
	return Value::Null;
}

// glu.gluTessCallback
Gura_DeclareFunction(gluTessCallback)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "CallBackFunc", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluTessCallback)
{
#if 0
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	GLenum which = static_cast<GLenum>(args.GetInt(1));
	int CallBackFunc = args.GetInt(2);
	gluTessCallback(tess, which, CallBackFunc);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "gluTessCallback");
	return Value::Null;
}

// glu.gluTessEndContour
Gura_DeclareFunction(gluTessEndContour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluTessEndContour)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	gluTessEndContour(tess);
	return Value::Null;
}

// glu.gluTessEndPolygon
Gura_DeclareFunction(gluTessEndPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluTessEndPolygon)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	gluTessEndPolygon(tess);
	return Value::Null;
}

// glu.gluTessNormal
Gura_DeclareFunction(gluTessNormal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	DeclareArg(env, "valueX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "valueY", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "valueZ", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluTessNormal)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	GLdouble valueX = args.GetDouble(1);
	GLdouble valueY = args.GetDouble(2);
	GLdouble valueZ = args.GetDouble(3);
	gluTessNormal(tess, valueX, valueY, valueZ);
	return Value::Null;
}

// glu.gluTessProperty
Gura_DeclareFunction(gluTessProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluTessProperty)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	GLenum which = static_cast<GLenum>(args.GetInt(1));
	GLdouble data = args.GetDouble(2);
	gluTessProperty(tess, which, data);
	return Value::Null;
}

// glu.gluTessVertex
Gura_DeclareFunction(gluTessVertex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "tess", VTYPE_Tesselator, OCCUR_Once, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluTessVertex)
{
	GLUtesselator *tess = Object_Tesselator::GetObject(args, 0)->GetTesselator();
	CArray<GLdouble> location = args.GetList(1);
	gluTessVertex(tess, location, tess); // pass this object pointer to callback
	return Value::Null;
}

// glu.gluUnProject
Gura_DeclareFunction(gluUnProject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "winX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "winY", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "winZ", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "model", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "proj", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "view", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "objX", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "objY", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "objZ", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(gluUnProject)
{
	GLdouble winX = args.GetDouble(0);
	GLdouble winY = args.GetDouble(1);
	GLdouble winZ = args.GetDouble(2);
	CArray<GLdouble> model = args.GetList(3);
	CArray<GLdouble> proj = args.GetList(4);
	CArray<GLint> view = args.GetList(5);
	CArray<GLdouble> objX = args.GetList(6);
	CArray<GLdouble> objY = args.GetList(7);
	CArray<GLdouble> objZ = args.GetList(8);
	GLint _rtn = gluUnProject(winX, winY, winZ, model, proj, view, objX, objY, objZ);
	return ReturnValue(env, sig, args, Value(_rtn));
}


void AssignFunctions(Environment &env)
{
	Gura_AssignFunction(gluBeginCurve);
	Gura_AssignFunction(gluBeginPolygon);
	Gura_AssignFunction(gluBeginSurface);
	Gura_AssignFunction(gluBeginTrim);
	Gura_AssignFunction(gluBuild1DMipmaps);
	Gura_AssignFunction(gluBuild2DMipmaps);
	Gura_AssignFunction(gluCylinder);
	Gura_AssignFunction(gluDeleteNurbsRenderer);
	Gura_AssignFunction(gluDeleteQuadric);
	Gura_AssignFunction(gluDeleteTess);
	Gura_AssignFunction(gluDisk);
	Gura_AssignFunction(gluEndCurve);
	Gura_AssignFunction(gluEndPolygon);
	Gura_AssignFunction(gluEndSurface);
	Gura_AssignFunction(gluEndTrim);
	Gura_AssignFunction(gluErrorString);
	Gura_AssignFunction(gluGetNurbsProperty);
	Gura_AssignFunction(gluGetString);
	Gura_AssignFunction(gluGetTessProperty);
	Gura_AssignFunction(gluLoadSamplingMatrices);
	Gura_AssignFunction(gluLookAt);
	Gura_AssignFunction(gluNewNurbsRenderer);
	Gura_AssignFunction(gluNewQuadric);
	Gura_AssignFunction(gluNewTess);
	Gura_AssignFunction(gluNextContour);
	Gura_AssignFunction(gluNurbsCallback);
	Gura_AssignFunction(gluNurbsCallbackData);
	Gura_AssignFunction(gluNurbsCallbackDataEXT);
	Gura_AssignFunction(gluNurbsCurve);
	Gura_AssignFunction(gluNurbsProperty);
	Gura_AssignFunction(gluNurbsSurface);
	Gura_AssignFunction(gluOrtho2D);
	Gura_AssignFunction(gluPartialDisk);
	Gura_AssignFunction(gluPerspective);
	Gura_AssignFunction(gluPickMatrix);
	Gura_AssignFunction(gluProject);
	Gura_AssignFunction(gluPwlCurve);
	Gura_AssignFunction(gluQuadricCallback);
	Gura_AssignFunction(gluQuadricDrawStyle);
	Gura_AssignFunction(gluQuadricNormals);
	Gura_AssignFunction(gluQuadricOrientation);
	Gura_AssignFunction(gluQuadricTexture);
	Gura_AssignFunction(gluScaleImage);
	Gura_AssignFunction(gluSphere);
	Gura_AssignFunction(gluTessBeginContour);
	Gura_AssignFunction(gluTessBeginPolygon);
	Gura_AssignFunction(gluTessCallback);
	Gura_AssignFunction(gluTessEndContour);
	Gura_AssignFunction(gluTessEndPolygon);
	Gura_AssignFunction(gluTessNormal);
	Gura_AssignFunction(gluTessProperty);
	Gura_AssignFunction(gluTessVertex);
	Gura_AssignFunction(gluUnProject);
}

Gura_EndModuleScope(glu)
