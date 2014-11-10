#include "stdafx.h"

Gura_BeginModuleScope(opengl)

// opengl.glAccum
Gura_DeclareFunction(glAccum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "op", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glAccum)
{
	GLenum op = static_cast<GLenum>(args.GetInt(0));
	GLfloat value = args.GetFloat(1);
	glAccum(op, value);
	return Value::Null;
}

// opengl.glAlphaFunc
Gura_DeclareFunction(glAlphaFunc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "func", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ref", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glAlphaFunc)
{
	GLenum func = static_cast<GLenum>(args.GetInt(0));
	GLclampf ref = args.GetFloat(1);
	glAlphaFunc(func, ref);
	return Value::Null;
}

// opengl.glAreTexturesResident
Gura_DeclareFunction(glAreTexturesResident)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "textures", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glAreTexturesResident)
{
	CArray<GLuint> textures = args.GetList(0);
	GLsizei n = textures.GetSize();
	CArray<GLboolean> residences(n);
	GLboolean _rtn = glAreTexturesResident(n, textures, residences);
	if (_rtn == 0) return Value::Null;
	Value _rtnVal;
	ValueList &valList = _rtnVal.InitAsList(env, n);
	for (GLsizei i = 0; i < n; i++) {
		valList.push_back(residences[i] != 0);
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// opengl.glArrayElement
Gura_DeclareFunction(glArrayElement)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glArrayElement)
{
	GLint i = args.GetInt(0);
	glArrayElement(i);
	return Value::Null;
}

// opengl.glBegin
Gura_DeclareFunction(glBegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBegin)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	glBegin(mode);
	return Value::Null;
}

// opengl.glBindTexture
Gura_DeclareFunction(glBindTexture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBindTexture)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLuint texture = args.GetUInt(1);
	glBindTexture(target, texture);
	return Value::Null;
}

// opengl.glBitmap
Gura_DeclareFunction(glBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "xorig", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "yorig", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "xmove", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ymove", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bitmap", VTYPE_binary, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBitmap)
{
	GLsizei width = args.GetInt(0);
	GLsizei height = args.GetInt(1);
	GLfloat xorig = args.GetFloat(2);
	GLfloat yorig = args.GetFloat(3);
	GLfloat xmove = args.GetFloat(4);
	GLfloat ymove = args.GetFloat(5);
	const Binary &bitmap = Object_binary::GetObject(args, 6)->GetBinary();
	size_t bytesReq = ((width + 7) / 8) * height;
	if (bytesReq < bitmap.size()) {
		sig.SetError(ERR_ValueError, "binary doesn\'t contain enough data");
		return Value::Null;
	}
	glBitmap(width, height, xorig, yorig, xmove, ymove,
			 reinterpret_cast<const GLubyte *>(bitmap.data()));
	return Value::Null;
}

// opengl.glBlendColor
Gura_DeclareFunction(glBlendColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBlendColor)
{
	GLclampf red = args.GetFloat(0);
	GLclampf green = args.GetFloat(1);
	GLclampf blue = args.GetFloat(2);
	GLclampf alpha = args.GetFloat(3);
	glBlendColor(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glBlendEquation
Gura_DeclareFunction(glBlendEquation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBlendEquation)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	glBlendEquation(mode);
	return Value::Null;
}

// opengl.glBlendEquationSeparate
Gura_DeclareFunction(glBlendEquationSeparate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "modeRGB", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "modeAlpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBlendEquationSeparate)
{
	GLenum modeRGB = static_cast<GLenum>(args.GetInt(0));
	GLenum modeAlpha = static_cast<GLenum>(args.GetInt(1));
	glBlendEquationSeparate(modeRGB, modeAlpha);
	return Value::Null;
}

// opengl.glBlendFunc
Gura_DeclareFunction(glBlendFunc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "sfactor", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dfactor", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBlendFunc)
{
	GLenum sfactor = static_cast<GLenum>(args.GetInt(0));
	GLenum dfactor = static_cast<GLenum>(args.GetInt(1));
	glBlendFunc(sfactor, dfactor);
	return Value::Null;
}

// opengl.glCallList
Gura_DeclareFunction(glCallList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "list", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCallList)
{
	GLuint list = args.GetUInt(0);
	glCallList(list);
	return Value::Null;
}

// opengl.glCallLists
Gura_DeclareFunction(glCallLists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "lists", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCallLists)
{
	GLenum type = static_cast<GLenum>(args.GetInt(0));
	const ValueList &lists = args.GetList(1);
	const ValueList &lists_in = args.GetList(1);
	GLsizei n = static_cast<GLsizei>(lists.size());
	AutoPtr<Memory> pListsBuff;
	if (type == GL_BYTE) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLbyte) * n));
		GLbyte *p = reinterpret_cast<GLbyte *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetChar(); }
	} else if (type == GL_UNSIGNED_BYTE) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLubyte) * n));
		GLubyte *p = reinterpret_cast<GLubyte *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetUChar(); }
	} else if (type == GL_SHORT) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLshort) * n));
		GLshort *p = reinterpret_cast<GLshort *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetShort(); }
	} else if (type == GL_UNSIGNED_SHORT) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLushort) * n));
		GLushort *p = reinterpret_cast<GLushort *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetUShort(); }
	} else if (type == GL_INT) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLint) * n));
		GLint *p = reinterpret_cast<GLint *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetInt(); }
	} else if (type == GL_UNSIGNED_INT) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLuint) * n));
		GLuint *p = reinterpret_cast<GLuint *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetUInt(); }
	} else if (type == GL_FLOAT) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLfloat) * n));
		GLfloat *p = reinterpret_cast<GLfloat *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetFloat(); }
	} else if (type == GL_2_BYTES) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLubyte) * 2 * n));
		GLubyte *p = reinterpret_cast<GLubyte *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) {
			UShort num = pValue->GetUShort();
			*p++ = static_cast<GLubyte>(num >> 8);
			*p++ = static_cast<GLubyte>(num);
		}
	} else if (type == GL_3_BYTES) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLubyte) * 3 * n));
		GLubyte *p = reinterpret_cast<GLubyte *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) {
			ULong num = pValue->GetULong();
			*p++ = static_cast<GLubyte>(num >> 16);
			*p++ = static_cast<GLubyte>(num >> 8);
			*p++ = static_cast<GLubyte>(num);
		}
	} else if (type == GL_4_BYTES) {
		pListsBuff.reset(new MemoryHeap(sizeof(GLubyte) * 4 * n));
		GLubyte *p = reinterpret_cast<GLubyte *>(pListsBuff->GetPointer());
		foreach_const (ValueList, pValue, lists_in) {
			ULong num = pValue->GetULong();
			*p++ = static_cast<GLubyte>(num >> 24);
			*p++ = static_cast<GLubyte>(num >> 16);
			*p++ = static_cast<GLubyte>(num >> 8);
			*p++ = static_cast<GLubyte>(num);
		}
	} else {
		sig.SetError(ERR_ValueError, "invalid type specification");
		return Value::Null;
	}
	// GLsizei n, GLenum type, const GLvoid *lists
	glCallLists(n, type, pListsBuff->GetPointer());
	return Value::Null;
}

// opengl.glClear
Gura_DeclareFunction(glClear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glClear)
{
	GLbitfield mask = args.GetUInt(0);
	glClear(mask);
	return Value::Null;
}

// opengl.glClearAccum
Gura_DeclareFunction(glClearAccum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glClearAccum)
{
	GLfloat red = args.GetFloat(0);
	GLfloat green = args.GetFloat(1);
	GLfloat blue = args.GetFloat(2);
	GLfloat alpha = args.GetFloat(3);
	glClearAccum(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glClearColor
Gura_DeclareFunction(glClearColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glClearColor)
{
	GLclampf red = args.GetFloat(0);
	GLclampf green = args.GetFloat(1);
	GLclampf blue = args.GetFloat(2);
	GLclampf alpha = args.GetFloat(3);
	glClearColor(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glClearDepth
Gura_DeclareFunction(glClearDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glClearDepth)
{
	GLclampd depth = args.GetDouble(0);
	glClearDepth(depth);
	return Value::Null;
}

// opengl.glClearIndex
Gura_DeclareFunction(glClearIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glClearIndex)
{
	GLfloat c = args.GetFloat(0);
	glClearIndex(c);
	return Value::Null;
}

// opengl.glClearStencil
Gura_DeclareFunction(glClearStencil)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glClearStencil)
{
	GLint s = args.GetInt(0);
	glClearStencil(s);
	return Value::Null;
}

// opengl.glClipPlane
Gura_DeclareFunction(glClipPlane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "plane", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glClipPlane)
{
	GLenum plane = static_cast<GLenum>(args.GetInt(0));
	GLdouble equation[4];
	glGetClipPlane(plane, equation);
	return Value::CreateList(env, equation, ArraySizeOf(equation));
}

// opengl.glColor3b
Gura_DeclareFunction(glColor3b)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3b)
{
	GLbyte red = args.GetChar(0);
	GLbyte green = args.GetChar(1);
	GLbyte blue = args.GetChar(2);
	glColor3b(red, green, blue);
	return Value::Null;
}

// opengl.glColor3bv
Gura_DeclareFunction(glColor3bv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3bv)
{
	CArray<GLbyte> v = args.GetList(0);

	glColor3bv(v);
	return Value::Null;
}

// opengl.glColor3d
Gura_DeclareFunction(glColor3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3d)
{
	GLdouble red = args.GetDouble(0);
	GLdouble green = args.GetDouble(1);
	GLdouble blue = args.GetDouble(2);
	glColor3d(red, green, blue);
	return Value::Null;
}

// opengl.glColor3dv
Gura_DeclareFunction(glColor3dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glColor3dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor3dv");
	return Value::Null;
}

// opengl.glColor3f
Gura_DeclareFunction(glColor3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3f)
{
	GLfloat red = args.GetFloat(0);
	GLfloat green = args.GetFloat(1);
	GLfloat blue = args.GetFloat(2);
	glColor3f(red, green, blue);
	return Value::Null;
}

// opengl.glColor3fv
Gura_DeclareFunction(glColor3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glColor3fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor3fv");
	return Value::Null;
}

// opengl.glColor3i
Gura_DeclareFunction(glColor3i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3i)
{
	GLint red = args.GetInt(0);
	GLint green = args.GetInt(1);
	GLint blue = args.GetInt(2);
	glColor3i(red, green, blue);
	return Value::Null;
}

// opengl.glColor3iv
Gura_DeclareFunction(glColor3iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glColor3iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor3iv");
	return Value::Null;
}

// opengl.glColor3s
Gura_DeclareFunction(glColor3s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3s)
{
	GLshort red = args.GetShort(0);
	GLshort green = args.GetShort(1);
	GLshort blue = args.GetShort(2);
	glColor3s(red, green, blue);
	return Value::Null;
}

// opengl.glColor3sv
Gura_DeclareFunction(glColor3sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glColor3sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor3sv");
	return Value::Null;
}

// opengl.glColor3ub
Gura_DeclareFunction(glColor3ub)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3ub)
{
	GLubyte red = args.GetUChar(0);
	GLubyte green = args.GetUChar(1);
	GLubyte blue = args.GetUChar(2);
	glColor3ub(red, green, blue);
	return Value::Null;
}

// opengl.glColor3ubv
Gura_DeclareFunction(glColor3ubv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3ubv)
{
#if 0
	CArray<GLubyte> v = args.GetList(0);
	glColor3ubv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor3ubv");
	return Value::Null;
}

// opengl.glColor3ui
Gura_DeclareFunction(glColor3ui)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3ui)
{
	GLuint red = args.GetUInt(0);
	GLuint green = args.GetUInt(1);
	GLuint blue = args.GetUInt(2);
	glColor3ui(red, green, blue);
	return Value::Null;
}

// opengl.glColor3uiv
Gura_DeclareFunction(glColor3uiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3uiv)
{
#if 0
	CArray<GLuint> v = args.GetList(0);
	glColor3uiv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor3uiv");
	return Value::Null;
}

// opengl.glColor3us
Gura_DeclareFunction(glColor3us)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3us)
{
	GLushort red = args.GetUShort(0);
	GLushort green = args.GetUShort(1);
	GLushort blue = args.GetUShort(2);
	glColor3us(red, green, blue);
	return Value::Null;
}

// opengl.glColor3usv
Gura_DeclareFunction(glColor3usv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor3usv)
{
#if 0
	CArray<GLushort> v = args.GetList(0);
	glColor3usv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor3usv");
	return Value::Null;
}

// opengl.glColor4b
Gura_DeclareFunction(glColor4b)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4b)
{
	GLbyte red = args.GetChar(0);
	GLbyte green = args.GetChar(1);
	GLbyte blue = args.GetChar(2);
	GLbyte alpha = args.GetChar(3);
	glColor4b(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4bv
Gura_DeclareFunction(glColor4bv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4bv)
{
#if 0
	CArray<GLbyte> v = args.GetList(0);
	glColor4bv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor4bv");
	return Value::Null;
}

// opengl.glColor4d
Gura_DeclareFunction(glColor4d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4d)
{
	GLdouble red = args.GetDouble(0);
	GLdouble green = args.GetDouble(1);
	GLdouble blue = args.GetDouble(2);
	GLdouble alpha = args.GetDouble(3);
	glColor4d(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4dv
Gura_DeclareFunction(glColor4dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glColor4dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor4dv");
	return Value::Null;
}

// opengl.glColor4f
Gura_DeclareFunction(glColor4f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4f)
{
	GLfloat red = args.GetFloat(0);
	GLfloat green = args.GetFloat(1);
	GLfloat blue = args.GetFloat(2);
	GLfloat alpha = args.GetFloat(3);
	glColor4f(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4fv
Gura_DeclareFunction(glColor4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glColor4fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor4fv");
	return Value::Null;
}

// opengl.glColor4i
Gura_DeclareFunction(glColor4i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4i)
{
	GLint red = args.GetInt(0);
	GLint green = args.GetInt(1);
	GLint blue = args.GetInt(2);
	GLint alpha = args.GetInt(3);
	glColor4i(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4iv
Gura_DeclareFunction(glColor4iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glColor4iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor4iv");
	return Value::Null;
}

// opengl.glColor4s
Gura_DeclareFunction(glColor4s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4s)
{
	GLshort red = args.GetShort(0);
	GLshort green = args.GetShort(1);
	GLshort blue = args.GetShort(2);
	GLshort alpha = args.GetShort(3);
	glColor4s(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4sv
Gura_DeclareFunction(glColor4sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glColor4sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor4sv");
	return Value::Null;
}

// opengl.glColor4ub
Gura_DeclareFunction(glColor4ub)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4ub)
{
	GLubyte red = args.GetUChar(0);
	GLubyte green = args.GetUChar(1);
	GLubyte blue = args.GetUChar(2);
	GLubyte alpha = args.GetUChar(3);
	glColor4ub(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4ubv
Gura_DeclareFunction(glColor4ubv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4ubv)
{
#if 0
	CArray<GLubyte> v = args.GetList(0);
	glColor4ubv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor4ubv");
	return Value::Null;
}

// opengl.glColor4ui
Gura_DeclareFunction(glColor4ui)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4ui)
{
	GLuint red = args.GetUInt(0);
	GLuint green = args.GetUInt(1);
	GLuint blue = args.GetUInt(2);
	GLuint alpha = args.GetUInt(3);
	glColor4ui(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4uiv
Gura_DeclareFunction(glColor4uiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4uiv)
{
#if 0
	CArray<GLuint> v = args.GetList(0);
	glColor4uiv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor4uiv");
	return Value::Null;
}

// opengl.glColor4us
Gura_DeclareFunction(glColor4us)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4us)
{
	GLushort red = args.GetUShort(0);
	GLushort green = args.GetUShort(1);
	GLushort blue = args.GetUShort(2);
	GLushort alpha = args.GetUShort(3);
	glColor4us(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4usv
Gura_DeclareFunction(glColor4usv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColor4usv)
{
#if 0
	CArray<GLushort> v = args.GetList(0);
	glColor4usv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColor4usv");
	return Value::Null;
}

// opengl.glColorMask
Gura_DeclareFunction(glColorMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColorMask)
{
	GLboolean red = (args.GetBoolean(0)? 1 : 0);
	GLboolean green = (args.GetBoolean(1)? 1 : 0);
	GLboolean blue = (args.GetBoolean(2)? 1 : 0);
	GLboolean alpha = (args.GetBoolean(3)? 1 : 0);
	glColorMask(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColorMaterial
Gura_DeclareFunction(glColorMaterial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColorMaterial)
{
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum mode = static_cast<GLenum>(args.GetInt(1));
	glColorMaterial(face, mode);
	return Value::Null;
}

// opengl.glColorTableParameterfv
Gura_DeclareFunction(glColorTableParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColorTableParameterfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glColorTableParameterfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColorTableParameterfv");
	return Value::Null;
}

// opengl.glColorTableParameteriv
Gura_DeclareFunction(glColorTableParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glColorTableParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glColorTableParameteriv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glColorTableParameteriv");
	return Value::Null;
}

// opengl.glConvolutionParameterf
Gura_DeclareFunction(glConvolutionParameterf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glConvolutionParameterf)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLfloat params = args.GetFloat(2);
	glConvolutionParameterf(target, pname, params);
	return Value::Null;
}

// opengl.glConvolutionParameterfv
Gura_DeclareFunction(glConvolutionParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glConvolutionParameterfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glConvolutionParameterfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glConvolutionParameterfv");
	return Value::Null;
}

// opengl.glConvolutionParameteri
Gura_DeclareFunction(glConvolutionParameteri)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glConvolutionParameteri)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLint params = args.GetInt(2);
	glConvolutionParameteri(target, pname, params);
	return Value::Null;
}

// opengl.glConvolutionParameteriv
Gura_DeclareFunction(glConvolutionParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glConvolutionParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glConvolutionParameteriv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glConvolutionParameteriv");
	return Value::Null;
}

// opengl.glCopyColorSubTable
Gura_DeclareFunction(glCopyColorSubTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyColorSubTable)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLsizei start = args.GetInt(1);
	GLint x = args.GetInt(2);
	GLint y = args.GetInt(3);
	GLsizei width = args.GetInt(4);
	glCopyColorSubTable(target, start, x, y, width);
	return Value::Null;
}

// opengl.glCopyColorTable
Gura_DeclareFunction(glCopyColorTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "internalformat", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyColorTable)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum internalformat = static_cast<GLenum>(args.GetInt(1));
	GLint x = args.GetInt(2);
	GLint y = args.GetInt(3);
	GLsizei width = args.GetInt(4);
	glCopyColorTable(target, internalformat, x, y, width);
	return Value::Null;
}

// opengl.glCopyConvolutionFilter1D
Gura_DeclareFunction(glCopyConvolutionFilter1D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "internalformat", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyConvolutionFilter1D)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum internalformat = static_cast<GLenum>(args.GetInt(1));
	GLint x = args.GetInt(2);
	GLint y = args.GetInt(3);
	GLsizei width = args.GetInt(4);
	glCopyConvolutionFilter1D(target, internalformat, x, y, width);
	return Value::Null;
}

// opengl.glCopyConvolutionFilter2D
Gura_DeclareFunction(glCopyConvolutionFilter2D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "internalformat", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyConvolutionFilter2D)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum internalformat = static_cast<GLenum>(args.GetInt(1));
	GLint x = args.GetInt(2);
	GLint y = args.GetInt(3);
	GLsizei width = args.GetInt(4);
	GLsizei height = args.GetInt(5);
	glCopyConvolutionFilter2D(target, internalformat, x, y, width, height);
	return Value::Null;
}

// opengl.glCopyPixels
Gura_DeclareFunction(glCopyPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyPixels)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLsizei width = args.GetInt(2);
	GLsizei height = args.GetInt(3);
	GLenum type = static_cast<GLenum>(args.GetInt(4));
	glCopyPixels(x, y, width, height, type);
	return Value::Null;
}

// opengl.glCopyTexImage1D
Gura_DeclareFunction(glCopyTexImage1D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "internalformat", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyTexImage1D)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint level = args.GetInt(1);
	GLenum internalformat = static_cast<GLenum>(args.GetInt(2));
	GLint x = args.GetInt(3);
	GLint y = args.GetInt(4);
	GLsizei width = args.GetInt(5);
	GLint border = args.GetInt(6);
	glCopyTexImage1D(target, level, internalformat, x, y, width, border);
	return Value::Null;
}

// opengl.glCopyTexImage2D
Gura_DeclareFunction(glCopyTexImage2D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "internalformat", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyTexImage2D)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint level = args.GetInt(1);
	GLenum internalformat = static_cast<GLenum>(args.GetInt(2));
	GLint x = args.GetInt(3);
	GLint y = args.GetInt(4);
	GLsizei width = args.GetInt(5);
	GLsizei height = args.GetInt(6);
	GLint border = args.GetInt(7);
	glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
	return Value::Null;
}

// opengl.glCopyTexSubImage1D
Gura_DeclareFunction(glCopyTexSubImage1D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyTexSubImage1D)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint level = args.GetInt(1);
	GLint xoffset = args.GetInt(2);
	GLint x = args.GetInt(3);
	GLint y = args.GetInt(4);
	GLsizei width = args.GetInt(5);
	glCopyTexSubImage1D(target, level, xoffset, x, y, width);
	return Value::Null;
}

// opengl.glCopyTexSubImage2D
Gura_DeclareFunction(glCopyTexSubImage2D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyTexSubImage2D)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint level = args.GetInt(1);
	GLint xoffset = args.GetInt(2);
	GLint yoffset = args.GetInt(3);
	GLint x = args.GetInt(4);
	GLint y = args.GetInt(5);
	GLsizei width = args.GetInt(6);
	GLsizei height = args.GetInt(7);
	glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
	return Value::Null;
}

// opengl.glCopyTexSubImage3D
Gura_DeclareFunction(glCopyTexSubImage3D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zoffset", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCopyTexSubImage3D)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint level = args.GetInt(1);
	GLint xoffset = args.GetInt(2);
	GLint yoffset = args.GetInt(3);
	GLint zoffset = args.GetInt(4);
	GLint x = args.GetInt(5);
	GLint y = args.GetInt(6);
	GLsizei width = args.GetInt(7);
	GLsizei height = args.GetInt(8);
	glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
	return Value::Null;
}

// opengl.glCullFace
Gura_DeclareFunction(glCullFace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCullFace)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	glCullFace(mode);
	return Value::Null;
}

// opengl.glDeleteLists
Gura_DeclareFunction(glDeleteLists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "list", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDeleteLists)
{
	GLuint list = args.GetUInt(0);
	GLsizei range = args.GetInt(1);
	glDeleteLists(list, range);
	return Value::Null;
}

// opengl.glDeleteTextures
Gura_DeclareFunction(glDeleteTextures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "textures", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDeleteTextures)
{
#if 0
	GLsizei n = args.GetInt(0);
	CArray<GLuint> textures = args.GetList(1);
	glDeleteTextures(n, textures);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glDeleteTextures");
	return Value::Null;
}

// opengl.glDepthFunc
Gura_DeclareFunction(glDepthFunc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "func", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDepthFunc)
{
	GLenum func = static_cast<GLenum>(args.GetInt(0));
	glDepthFunc(func);
	return Value::Null;
}

// opengl.glDepthMask
Gura_DeclareFunction(glDepthMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDepthMask)
{
	GLboolean flag = (args.GetBoolean(0)? 1 : 0);
	glDepthMask(flag);
	return Value::Null;
}

// opengl.glDepthRange
Gura_DeclareFunction(glDepthRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "zNear", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zFar", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDepthRange)
{
	GLclampd zNear = args.GetDouble(0);
	GLclampd zFar = args.GetDouble(1);
	glDepthRange(zNear, zFar);
	return Value::Null;
}

// opengl.glDisable
Gura_DeclareFunction(glDisable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cap", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDisable)
{
	GLenum cap = static_cast<GLenum>(args.GetInt(0));
	glDisable(cap);
	return Value::Null;
}

// opengl.glDisableClientState
Gura_DeclareFunction(glDisableClientState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "array", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDisableClientState)
{
	GLenum array = static_cast<GLenum>(args.GetInt(0));
	glDisableClientState(array);
	return Value::Null;
}

// opengl.glDrawArrays
Gura_DeclareFunction(glDrawArrays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "first", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDrawArrays)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	GLint first = args.GetInt(1);
	GLsizei count = args.GetInt(2);
	glDrawArrays(mode, first, count);
	return Value::Null;
}

// opengl.glDrawBuffer
Gura_DeclareFunction(glDrawBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDrawBuffer)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	glDrawBuffer(mode);
	return Value::Null;
}

// opengl.glEdgeFlag
Gura_DeclareFunction(glEdgeFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEdgeFlag)
{
	GLboolean flag = (args.GetBoolean(0)? 1 : 0);
	glEdgeFlag(flag);
	return Value::Null;
}

// opengl.glEdgeFlagv
Gura_DeclareFunction(glEdgeFlagv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEdgeFlagv)
{
#if 0
	CArray<GLboolean> flag = args.GetList(0);
	glEdgeFlagv(flag);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glEdgeFlagv");
	return Value::Null;
}

// opengl.glEnable
Gura_DeclareFunction(glEnable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cap", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEnable)
{
	GLenum cap = static_cast<GLenum>(args.GetInt(0));
	glEnable(cap);
	return Value::Null;
}

// opengl.glEnableClientState
Gura_DeclareFunction(glEnableClientState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "array", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEnableClientState)
{
	GLenum array = static_cast<GLenum>(args.GetInt(0));
	glEnableClientState(array);
	return Value::Null;
}

// opengl.glEnd
Gura_DeclareFunction(glEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEnd)
{
	glEnd();
	return Value::Null;
}

// opengl.glEndList
Gura_DeclareFunction(glEndList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEndList)
{
	glEndList();
	return Value::Null;
}

// opengl.glEvalCoord1d
Gura_DeclareFunction(glEvalCoord1d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalCoord1d)
{
	GLdouble u = args.GetDouble(0);
	glEvalCoord1d(u);
	return Value::Null;
}

// opengl.glEvalCoord1dv
Gura_DeclareFunction(glEvalCoord1dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalCoord1dv)
{
#if 0
	CArray<GLdouble> u = args.GetList(0);
	glEvalCoord1dv(u);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glEvalCoord1dv");
	return Value::Null;
}

// opengl.glEvalCoord1f
Gura_DeclareFunction(glEvalCoord1f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalCoord1f)
{
	GLfloat u = args.GetFloat(0);
	glEvalCoord1f(u);
	return Value::Null;
}

// opengl.glEvalCoord1fv
Gura_DeclareFunction(glEvalCoord1fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalCoord1fv)
{
#if 0
	CArray<GLfloat> u = args.GetList(0);
	glEvalCoord1fv(u);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glEvalCoord1fv");
	return Value::Null;
}

// opengl.glEvalCoord2d
Gura_DeclareFunction(glEvalCoord2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalCoord2d)
{
	GLdouble u = args.GetDouble(0);
	GLdouble v = args.GetDouble(1);
	glEvalCoord2d(u, v);
	return Value::Null;
}

// opengl.glEvalCoord2dv
Gura_DeclareFunction(glEvalCoord2dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalCoord2dv)
{
#if 0
	CArray<GLdouble> u = args.GetList(0);
	glEvalCoord2dv(u);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glEvalCoord2dv");
	return Value::Null;
}

// opengl.glEvalCoord2f
Gura_DeclareFunction(glEvalCoord2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalCoord2f)
{
	GLfloat u = args.GetFloat(0);
	GLfloat v = args.GetFloat(1);
	glEvalCoord2f(u, v);
	return Value::Null;
}

// opengl.glEvalCoord2fv
Gura_DeclareFunction(glEvalCoord2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalCoord2fv)
{
#if 0
	CArray<GLfloat> u = args.GetList(0);
	glEvalCoord2fv(u);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glEvalCoord2fv");
	return Value::Null;
}

// opengl.glEvalMesh1
Gura_DeclareFunction(glEvalMesh1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "i1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "i2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalMesh1)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	GLint i1 = args.GetInt(1);
	GLint i2 = args.GetInt(2);
	glEvalMesh1(mode, i1, i2);
	return Value::Null;
}

// opengl.glEvalMesh2
Gura_DeclareFunction(glEvalMesh2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "i1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "i2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "j1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "j2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalMesh2)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	GLint i1 = args.GetInt(1);
	GLint i2 = args.GetInt(2);
	GLint j1 = args.GetInt(3);
	GLint j2 = args.GetInt(4);
	glEvalMesh2(mode, i1, i2, j1, j2);
	return Value::Null;
}

// opengl.glEvalPoint1
Gura_DeclareFunction(glEvalPoint1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalPoint1)
{
	GLint i = args.GetInt(0);
	glEvalPoint1(i);
	return Value::Null;
}

// opengl.glEvalPoint2
Gura_DeclareFunction(glEvalPoint2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "j", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEvalPoint2)
{
	GLint i = args.GetInt(0);
	GLint j = args.GetInt(1);
	glEvalPoint2(i, j);
	return Value::Null;
}

// opengl.glFeedbackBuffer
Gura_DeclareFunction(glFeedbackBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFeedbackBuffer)
{
#if 0
	GLsizei size = args.GetInt(0);
	GLenum type = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> buffer = args.GetList(2);
	glFeedbackBuffer(size, type, buffer);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glFeedbackBuffer");
	return Value::Null;
}

// opengl.glFinish
Gura_DeclareFunction(glFinish)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFinish)
{
	glFinish();
	return Value::Null;
}

// opengl.glFlush
Gura_DeclareFunction(glFlush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFlush)
{
	glFlush();
	return Value::Null;
}

// opengl.glFogf
Gura_DeclareFunction(glFogf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFogf)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLfloat param = args.GetFloat(1);
	glFogf(pname, param);
	return Value::Null;
}

// opengl.glFogfv
Gura_DeclareFunction(glFogfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFogfv)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLfloat> params = args.GetList(1);
	glFogfv(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glFogfv");
	return Value::Null;
}

// opengl.glFogi
Gura_DeclareFunction(glFogi)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFogi)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLint param = args.GetInt(1);
	glFogi(pname, param);
	return Value::Null;
}

// opengl.glFogiv
Gura_DeclareFunction(glFogiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFogiv)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLint> params = args.GetList(1);
	glFogiv(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glFogiv");
	return Value::Null;
}

// opengl.glFrontFace
Gura_DeclareFunction(glFrontFace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFrontFace)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	glFrontFace(mode);
	return Value::Null;
}

// opengl.glFrustum
Gura_DeclareFunction(glFrustum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "left", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "right", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "top", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zNear", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zFar", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFrustum)
{
	GLdouble left = args.GetDouble(0);
	GLdouble right = args.GetDouble(1);
	GLdouble bottom = args.GetDouble(2);
	GLdouble top = args.GetDouble(3);
	GLdouble zNear = args.GetDouble(4);
	GLdouble zFar = args.GetDouble(5);
	glFrustum(left, right, bottom, top, zNear, zFar);
	return Value::Null;
}

// opengl.glGenLists
Gura_DeclareFunction(glGenLists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGenLists)
{
	GLsizei range = args.GetInt(0);
	GLuint _rtn = glGenLists(range);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// opengl.glGenTextures
Gura_DeclareFunction(glGenTextures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "textures", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGenTextures)
{
#if 0
	GLsizei n = args.GetInt(0);
	CArray<GLuint> textures = args.GetList(1);
	glGenTextures(n, textures);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGenTextures");
	return Value::Null;
}

// opengl.glGetBooleanv
Gura_DeclareFunction(glGetBooleanv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_boolean, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetBooleanv)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLboolean> params = args.GetList(1);
	glGetBooleanv(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetBooleanv");
	return Value::Null;
}

// opengl.glGetClipPlane
Gura_DeclareFunction(glGetClipPlane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "plane", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "equation", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetClipPlane)
{
#if 0
	GLenum plane = static_cast<GLenum>(args.GetInt(0));
	CArray<GLdouble> equation = args.GetList(1);
	glGetClipPlane(plane, equation);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetClipPlane");
	return Value::Null;
}

// opengl.glGetColorTableParameterfv
Gura_DeclareFunction(glGetColorTableParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetColorTableParameterfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetColorTableParameterfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetColorTableParameterfv");
	return Value::Null;
}

// opengl.glGetColorTableParameteriv
Gura_DeclareFunction(glGetColorTableParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetColorTableParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetColorTableParameteriv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetColorTableParameteriv");
	return Value::Null;
}

// opengl.glGetConvolutionParameterfv
Gura_DeclareFunction(glGetConvolutionParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetConvolutionParameterfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetConvolutionParameterfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetConvolutionParameterfv");
	return Value::Null;
}

// opengl.glGetConvolutionParameteriv
Gura_DeclareFunction(glGetConvolutionParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetConvolutionParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetConvolutionParameteriv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetConvolutionParameteriv");
	return Value::Null;
}

// opengl.glGetDoublev
Gura_DeclareFunction(glGetDoublev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetDoublev)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLdouble> params = args.GetList(1);
	glGetDoublev(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetDoublev");
	return Value::Null;
}

// opengl.glGetError
Gura_DeclareFunction(glGetError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetError)
{
	GLenum _rtn = glGetError();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// opengl.glGetFloatv
Gura_DeclareFunction(glGetFloatv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetFloatv)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLfloat> params = args.GetList(1);
	glGetFloatv(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetFloatv");
	return Value::Null;
}

// opengl.glGetHistogramParameterfv
Gura_DeclareFunction(glGetHistogramParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetHistogramParameterfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetHistogramParameterfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetHistogramParameterfv");
	return Value::Null;
}

// opengl.glGetHistogramParameteriv
Gura_DeclareFunction(glGetHistogramParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetHistogramParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetHistogramParameteriv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetHistogramParameteriv");
	return Value::Null;
}

// opengl.glGetIntegerv
Gura_DeclareFunction(glGetIntegerv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetIntegerv)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLint> params = args.GetList(1);
	glGetIntegerv(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetIntegerv");
	return Value::Null;
}

// opengl.glGetLightfv
Gura_DeclareFunction(glGetLightfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "light", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetLightfv)
{
#if 0
	GLenum light = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetLightfv(light, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetLightfv");
	return Value::Null;
}

// opengl.glGetLightiv
Gura_DeclareFunction(glGetLightiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "light", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetLightiv)
{
#if 0
	GLenum light = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetLightiv(light, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetLightiv");
	return Value::Null;
}

// opengl.glGetMapdv
Gura_DeclareFunction(glGetMapdv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "query", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetMapdv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum query = static_cast<GLenum>(args.GetInt(1));
	CArray<GLdouble> v = args.GetList(2);
	glGetMapdv(target, query, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetMapdv");
	return Value::Null;
}

// opengl.glGetMapfv
Gura_DeclareFunction(glGetMapfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "query", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetMapfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum query = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> v = args.GetList(2);
	glGetMapfv(target, query, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetMapfv");
	return Value::Null;
}

// opengl.glGetMapiv
Gura_DeclareFunction(glGetMapiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "query", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetMapiv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum query = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> v = args.GetList(2);
	glGetMapiv(target, query, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetMapiv");
	return Value::Null;
}

// opengl.glGetMaterialfv
Gura_DeclareFunction(glGetMaterialfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetMaterialfv)
{
#if 0
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetMaterialfv(face, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetMaterialfv");
	return Value::Null;
}

// opengl.glGetMaterialiv
Gura_DeclareFunction(glGetMaterialiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetMaterialiv)
{
#if 0
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetMaterialiv(face, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetMaterialiv");
	return Value::Null;
}

// opengl.glGetMinmaxParameterfv
Gura_DeclareFunction(glGetMinmaxParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetMinmaxParameterfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetMinmaxParameterfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetMinmaxParameterfv");
	return Value::Null;
}

// opengl.glGetMinmaxParameteriv
Gura_DeclareFunction(glGetMinmaxParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetMinmaxParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetMinmaxParameteriv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetMinmaxParameteriv");
	return Value::Null;
}

// opengl.glGetPixelMapfv
Gura_DeclareFunction(glGetPixelMapfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "map", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetPixelMapfv)
{
#if 0
	GLenum map = static_cast<GLenum>(args.GetInt(0));
	CArray<GLfloat> values = args.GetList(1);
	glGetPixelMapfv(map, values);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetPixelMapfv");
	return Value::Null;
}

// opengl.glGetPixelMapuiv
Gura_DeclareFunction(glGetPixelMapuiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "map", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetPixelMapuiv)
{
#if 0
	GLenum map = static_cast<GLenum>(args.GetInt(0));
	CArray<GLuint> values = args.GetList(1);
	glGetPixelMapuiv(map, values);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetPixelMapuiv");
	return Value::Null;
}

// opengl.glGetPixelMapusv
Gura_DeclareFunction(glGetPixelMapusv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "map", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetPixelMapusv)
{
#if 0
	GLenum map = static_cast<GLenum>(args.GetInt(0));
	CArray<GLushort> values = args.GetList(1);
	glGetPixelMapusv(map, values);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetPixelMapusv");
	return Value::Null;
}

// opengl.glGetPolygonStipple
Gura_DeclareFunction(glGetPolygonStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetPolygonStipple)
{
#if 0
	CArray<GLubyte> mask = args.GetList(0);
	glGetPolygonStipple(mask);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetPolygonStipple");
	return Value::Null;
}

// opengl.glGetString
Gura_DeclareFunction(glGetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetString)
{
#if 0
	GLenum name = static_cast<GLenum>(args.GetInt(0));
	CArray<GLubyte>_rtn = glGetString(name);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetString");
	return Value::Null;
}

// opengl.glGetTexEnvfv
Gura_DeclareFunction(glGetTexEnvfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetTexEnvfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetTexEnvfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetTexEnvfv");
	return Value::Null;
}

// opengl.glGetTexEnviv
Gura_DeclareFunction(glGetTexEnviv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetTexEnviv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetTexEnviv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetTexEnviv");
	return Value::Null;
}

// opengl.glGetTexGendv
Gura_DeclareFunction(glGetTexGendv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetTexGendv)
{
#if 0
	GLenum coord = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLdouble> params = args.GetList(2);
	glGetTexGendv(coord, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetTexGendv");
	return Value::Null;
}

// opengl.glGetTexGenfv
Gura_DeclareFunction(glGetTexGenfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetTexGenfv)
{
#if 0
	GLenum coord = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetTexGenfv(coord, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetTexGenfv");
	return Value::Null;
}

// opengl.glGetTexGeniv
Gura_DeclareFunction(glGetTexGeniv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetTexGeniv)
{
#if 0
	GLenum coord = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetTexGeniv(coord, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetTexGeniv");
	return Value::Null;
}

// opengl.glGetTexLevelParameterfv
Gura_DeclareFunction(glGetTexLevelParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetTexLevelParameterfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint level = args.GetInt(1);
	GLenum pname = static_cast<GLenum>(args.GetInt(2));
	CArray<GLfloat> params = args.GetList(3);
	glGetTexLevelParameterfv(target, level, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetTexLevelParameterfv");
	return Value::Null;
}

// opengl.glGetTexLevelParameteriv
Gura_DeclareFunction(glGetTexLevelParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetTexLevelParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint level = args.GetInt(1);
	GLenum pname = static_cast<GLenum>(args.GetInt(2));
	CArray<GLint> params = args.GetList(3);
	glGetTexLevelParameteriv(target, level, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetTexLevelParameteriv");
	return Value::Null;
}

// opengl.glGetTexParameterfv
Gura_DeclareFunction(glGetTexParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetTexParameterfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetTexParameterfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetTexParameterfv");
	return Value::Null;
}

// opengl.glGetTexParameteriv
Gura_DeclareFunction(glGetTexParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetTexParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetTexParameteriv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetTexParameteriv");
	return Value::Null;
}

// opengl.glHint
Gura_DeclareFunction(glHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glHint)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum mode = static_cast<GLenum>(args.GetInt(1));
	glHint(target, mode);
	return Value::Null;
}

// opengl.glHistogram
Gura_DeclareFunction(glHistogram)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "internalformat", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "sink", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glHistogram)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLsizei width = args.GetInt(1);
	GLenum internalformat = static_cast<GLenum>(args.GetInt(2));
	GLboolean sink = (args.GetBoolean(3)? 1 : 0);
	glHistogram(target, width, internalformat, sink);
	return Value::Null;
}

// opengl.glIndexMask
Gura_DeclareFunction(glIndexMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexMask)
{
	GLuint mask = args.GetUInt(0);
	glIndexMask(mask);
	return Value::Null;
}

// opengl.glIndexd
Gura_DeclareFunction(glIndexd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexd)
{
	GLdouble c = args.GetDouble(0);
	glIndexd(c);
	return Value::Null;
}

// opengl.glIndexdv
Gura_DeclareFunction(glIndexdv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexdv)
{
#if 0
	CArray<GLdouble> c = args.GetList(0);
	glIndexdv(c);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glIndexdv");
	return Value::Null;
}

// opengl.glIndexf
Gura_DeclareFunction(glIndexf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexf)
{
	GLfloat c = args.GetFloat(0);
	glIndexf(c);
	return Value::Null;
}

// opengl.glIndexfv
Gura_DeclareFunction(glIndexfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexfv)
{
#if 0
	CArray<GLfloat> c = args.GetList(0);
	glIndexfv(c);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glIndexfv");
	return Value::Null;
}

// opengl.glIndexi
Gura_DeclareFunction(glIndexi)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexi)
{
	GLint c = args.GetInt(0);
	glIndexi(c);
	return Value::Null;
}

// opengl.glIndexiv
Gura_DeclareFunction(glIndexiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexiv)
{
#if 0
	CArray<GLint> c = args.GetList(0);
	glIndexiv(c);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glIndexiv");
	return Value::Null;
}

// opengl.glIndexs
Gura_DeclareFunction(glIndexs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexs)
{
	GLshort c = args.GetShort(0);
	glIndexs(c);
	return Value::Null;
}

// opengl.glIndexsv
Gura_DeclareFunction(glIndexsv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexsv)
{
#if 0
	CArray<GLshort> c = args.GetList(0);
	glIndexsv(c);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glIndexsv");
	return Value::Null;
}

// opengl.glIndexub
Gura_DeclareFunction(glIndexub)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexub)
{
	GLubyte c = args.GetUChar(0);
	glIndexub(c);
	return Value::Null;
}

// opengl.glIndexubv
Gura_DeclareFunction(glIndexubv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIndexubv)
{
#if 0
	CArray<GLubyte> c = args.GetList(0);
	glIndexubv(c);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glIndexubv");
	return Value::Null;
}

// opengl.glInitNames
Gura_DeclareFunction(glInitNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glInitNames)
{
	glInitNames();
	return Value::Null;
}

// opengl.glIsEnabled
Gura_DeclareFunction(glIsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "cap", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIsEnabled)
{
	GLenum cap = static_cast<GLenum>(args.GetInt(0));
	GLboolean _rtn = glIsEnabled(cap);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// opengl.glIsList
Gura_DeclareFunction(glIsList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "list", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIsList)
{
	GLuint list = args.GetUInt(0);
	GLboolean _rtn = glIsList(list);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// opengl.glIsTexture
Gura_DeclareFunction(glIsTexture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIsTexture)
{
	GLuint texture = args.GetUInt(0);
	GLboolean _rtn = glIsTexture(texture);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// opengl.glLightModelf
Gura_DeclareFunction(glLightModelf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLightModelf)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLfloat param = args.GetFloat(1);
	glLightModelf(pname, param);
	return Value::Null;
}

// opengl.glLightModelfv
Gura_DeclareFunction(glLightModelfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLightModelfv)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLfloat> params = args.GetList(1);
	glLightModelfv(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glLightModelfv");
	return Value::Null;
}

// opengl.glLightModeli
Gura_DeclareFunction(glLightModeli)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLightModeli)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLint param = args.GetInt(1);
	glLightModeli(pname, param);
	return Value::Null;
}

// opengl.glLightModeliv
Gura_DeclareFunction(glLightModeliv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLightModeliv)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLint> params = args.GetList(1);
	glLightModeliv(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glLightModeliv");
	return Value::Null;
}

// opengl.glLightf
Gura_DeclareFunction(glLightf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "light", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLightf)
{
	GLenum light = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLfloat param = args.GetFloat(2);
	glLightf(light, pname, param);
	return Value::Null;
}

// opengl.glLightfv
Gura_DeclareFunction(glLightfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "light", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLightfv)
{
#if 0
	GLenum light = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glLightfv(light, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glLightfv");
	return Value::Null;
}

// opengl.glLighti
Gura_DeclareFunction(glLighti)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "light", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLighti)
{
	GLenum light = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLint param = args.GetInt(2);
	glLighti(light, pname, param);
	return Value::Null;
}

// opengl.glLightiv
Gura_DeclareFunction(glLightiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "light", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLightiv)
{
#if 0
	GLenum light = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glLightiv(light, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glLightiv");
	return Value::Null;
}

// opengl.glLineStipple
Gura_DeclareFunction(glLineStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "factor", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pattern", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLineStipple)
{
	GLint factor = args.GetInt(0);
	GLushort pattern = args.GetUShort(1);
	glLineStipple(factor, pattern);
	return Value::Null;
}

// opengl.glLineWidth
Gura_DeclareFunction(glLineWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLineWidth)
{
	GLfloat width = args.GetFloat(0);
	glLineWidth(width);
	return Value::Null;
}

// opengl.glListBase
Gura_DeclareFunction(glListBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "base", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glListBase)
{
	GLuint base = args.GetUInt(0);
	glListBase(base);
	return Value::Null;
}

// opengl.glLoadIdentity
Gura_DeclareFunction(glLoadIdentity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLoadIdentity)
{
	glLoadIdentity();
	return Value::Null;
}

// opengl.glLoadMatrixd
Gura_DeclareFunction(glLoadMatrixd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLoadMatrixd)
{
#if 0
	CArray<GLdouble> m = args.GetList(0);
	glLoadMatrixd(m);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glLoadMatrixd");
	return Value::Null;
}

// opengl.glLoadMatrixf
Gura_DeclareFunction(glLoadMatrixf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLoadMatrixf)
{
#if 0
	CArray<GLfloat> m = args.GetList(0);
	glLoadMatrixf(m);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glLoadMatrixf");
	return Value::Null;
}

// opengl.glLoadName
Gura_DeclareFunction(glLoadName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLoadName)
{
	GLuint name = args.GetUInt(0);
	glLoadName(name);
	return Value::Null;
}

// opengl.glLogicOp
Gura_DeclareFunction(glLogicOp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "opcode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLogicOp)
{
	GLenum opcode = static_cast<GLenum>(args.GetInt(0));
	glLogicOp(opcode);
	return Value::Null;
}

// opengl.glMap1d
Gura_DeclareFunction(glMap1d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "stride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "order", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMap1d)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLdouble u1 = args.GetDouble(1);
	GLdouble u2 = args.GetDouble(2);
	GLint stride = args.GetInt(3);
	GLint order = args.GetInt(4);
	CArray<GLdouble> points = args.GetList(5);
	glMap1d(target, u1, u2, stride, order, points);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMap1d");
	return Value::Null;
}

// opengl.glMap1f
Gura_DeclareFunction(glMap1f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "stride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "order", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMap1f)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLfloat u1 = args.GetFloat(1);
	GLfloat u2 = args.GetFloat(2);
	GLint stride = args.GetInt(3);
	GLint order = args.GetInt(4);
	CArray<GLfloat> points = args.GetList(5);
	glMap1f(target, u1, u2, stride, order, points);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMap1f");
	return Value::Null;
}

// opengl.glMap2d
Gura_DeclareFunction(glMap2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ustride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "uorder", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "vstride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "vorder", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMap2d)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLdouble u1 = args.GetDouble(1);
	GLdouble u2 = args.GetDouble(2);
	GLint ustride = args.GetInt(3);
	GLint uorder = args.GetInt(4);
	GLdouble v1 = args.GetDouble(5);
	GLdouble v2 = args.GetDouble(6);
	GLint vstride = args.GetInt(7);
	GLint vorder = args.GetInt(8);
	CArray<GLdouble> points = args.GetList(9);
	glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMap2d");
	return Value::Null;
}

// opengl.glMap2f
Gura_DeclareFunction(glMap2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ustride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "uorder", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "vstride", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "vorder", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMap2f)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLfloat u1 = args.GetFloat(1);
	GLfloat u2 = args.GetFloat(2);
	GLint ustride = args.GetInt(3);
	GLint uorder = args.GetInt(4);
	GLfloat v1 = args.GetFloat(5);
	GLfloat v2 = args.GetFloat(6);
	GLint vstride = args.GetInt(7);
	GLint vorder = args.GetInt(8);
	CArray<GLfloat> points = args.GetList(9);
	glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMap2f");
	return Value::Null;
}

// opengl.glMapGrid1d
Gura_DeclareFunction(glMapGrid1d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "un", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMapGrid1d)
{
	GLint un = args.GetInt(0);
	GLdouble u1 = args.GetDouble(1);
	GLdouble u2 = args.GetDouble(2);
	glMapGrid1d(un, u1, u2);
	return Value::Null;
}

// opengl.glMapGrid1f
Gura_DeclareFunction(glMapGrid1f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "un", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMapGrid1f)
{
	GLint un = args.GetInt(0);
	GLfloat u1 = args.GetFloat(1);
	GLfloat u2 = args.GetFloat(2);
	glMapGrid1f(un, u1, u2);
	return Value::Null;
}

// opengl.glMapGrid2d
Gura_DeclareFunction(glMapGrid2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "un", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "vn", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMapGrid2d)
{
	GLint un = args.GetInt(0);
	GLdouble u1 = args.GetDouble(1);
	GLdouble u2 = args.GetDouble(2);
	GLint vn = args.GetInt(3);
	GLdouble v1 = args.GetDouble(4);
	GLdouble v2 = args.GetDouble(5);
	glMapGrid2d(un, u1, u2, vn, v1, v2);
	return Value::Null;
}

// opengl.glMapGrid2f
Gura_DeclareFunction(glMapGrid2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "un", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "u2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "vn", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMapGrid2f)
{
	GLint un = args.GetInt(0);
	GLfloat u1 = args.GetFloat(1);
	GLfloat u2 = args.GetFloat(2);
	GLint vn = args.GetInt(3);
	GLfloat v1 = args.GetFloat(4);
	GLfloat v2 = args.GetFloat(5);
	glMapGrid2f(un, u1, u2, vn, v1, v2);
	return Value::Null;
}

// opengl.glMaterialf
Gura_DeclareFunction(glMaterialf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMaterialf)
{
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLfloat param = args.GetFloat(2);
	glMaterialf(face, pname, param);
	return Value::Null;
}

// opengl.glMaterialfv
Gura_DeclareFunction(glMaterialfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMaterialfv)
{
#if 0
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glMaterialfv(face, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMaterialfv");
	return Value::Null;
}

// opengl.glMateriali
Gura_DeclareFunction(glMateriali)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMateriali)
{
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLint param = args.GetInt(2);
	glMateriali(face, pname, param);
	return Value::Null;
}

// opengl.glMaterialiv
Gura_DeclareFunction(glMaterialiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMaterialiv)
{
#if 0
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glMaterialiv(face, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMaterialiv");
	return Value::Null;
}

// opengl.glMatrixMode
Gura_DeclareFunction(glMatrixMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMatrixMode)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	glMatrixMode(mode);
	return Value::Null;
}

// opengl.glMinmax
Gura_DeclareFunction(glMinmax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "internalformat", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "sink", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMinmax)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum internalformat = static_cast<GLenum>(args.GetInt(1));
	GLboolean sink = (args.GetBoolean(2)? 1 : 0);
	glMinmax(target, internalformat, sink);
	return Value::Null;
}

// opengl.glMultMatrixd
Gura_DeclareFunction(glMultMatrixd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultMatrixd)
{
#if 0
	CArray<GLdouble> m = args.GetList(0);
	glMultMatrixd(m);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultMatrixd");
	return Value::Null;
}

// opengl.glMultMatrixf
Gura_DeclareFunction(glMultMatrixf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultMatrixf)
{
#if 0
	CArray<GLfloat> m = args.GetList(0);
	glMultMatrixf(m);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultMatrixf");
	return Value::Null;
}

// opengl.glNewList
Gura_DeclareFunction(glNewList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "list", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNewList)
{
	GLuint list = args.GetUInt(0);
	GLenum mode = static_cast<GLenum>(args.GetInt(1));
	glNewList(list, mode);
	return Value::Null;
}

// opengl.glNormal3b
Gura_DeclareFunction(glNormal3b)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nx", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ny", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "nz", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3b)
{
	GLbyte nx = args.GetChar(0);
	GLbyte ny = args.GetChar(1);
	GLbyte nz = args.GetChar(2);
	glNormal3b(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3bv
Gura_DeclareFunction(glNormal3bv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3bv)
{
#if 0
	CArray<GLbyte> v = args.GetList(0);
	glNormal3bv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glNormal3bv");
	return Value::Null;
}

// opengl.glNormal3d
Gura_DeclareFunction(glNormal3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nx", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ny", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "nz", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3d)
{
	GLdouble nx = args.GetDouble(0);
	GLdouble ny = args.GetDouble(1);
	GLdouble nz = args.GetDouble(2);
	glNormal3d(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3dv
Gura_DeclareFunction(glNormal3dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glNormal3dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glNormal3dv");
	return Value::Null;
}

// opengl.glNormal3f
Gura_DeclareFunction(glNormal3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nx", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ny", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "nz", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3f)
{
	GLfloat nx = args.GetFloat(0);
	GLfloat ny = args.GetFloat(1);
	GLfloat nz = args.GetFloat(2);
	glNormal3f(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3fv
Gura_DeclareFunction(glNormal3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glNormal3fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glNormal3fv");
	return Value::Null;
}

// opengl.glNormal3i
Gura_DeclareFunction(glNormal3i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nx", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ny", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "nz", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3i)
{
	GLint nx = args.GetInt(0);
	GLint ny = args.GetInt(1);
	GLint nz = args.GetInt(2);
	glNormal3i(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3iv
Gura_DeclareFunction(glNormal3iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glNormal3iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glNormal3iv");
	return Value::Null;
}

// opengl.glNormal3s
Gura_DeclareFunction(glNormal3s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "nx", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ny", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "nz", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3s)
{
	GLshort nx = args.GetShort(0);
	GLshort ny = args.GetShort(1);
	GLshort nz = args.GetShort(2);
	glNormal3s(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3sv
Gura_DeclareFunction(glNormal3sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glNormal3sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glNormal3sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glNormal3sv");
	return Value::Null;
}

// opengl.glOrtho
Gura_DeclareFunction(glOrtho)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "left", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "right", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "top", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zNear", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zFar", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glOrtho)
{
	GLdouble left = args.GetDouble(0);
	GLdouble right = args.GetDouble(1);
	GLdouble bottom = args.GetDouble(2);
	GLdouble top = args.GetDouble(3);
	GLdouble zNear = args.GetDouble(4);
	GLdouble zFar = args.GetDouble(5);
	glOrtho(left, right, bottom, top, zNear, zFar);
	return Value::Null;
}

// opengl.glPassThrough
Gura_DeclareFunction(glPassThrough)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "token", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPassThrough)
{
	GLfloat token = args.GetFloat(0);
	glPassThrough(token);
	return Value::Null;
}

// opengl.glPixelMapfv
Gura_DeclareFunction(glPixelMapfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "map", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mapsize", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPixelMapfv)
{
#if 0
	GLenum map = static_cast<GLenum>(args.GetInt(0));
	GLint mapsize = args.GetInt(1);
	CArray<GLfloat> values = args.GetList(2);
	glPixelMapfv(map, mapsize, values);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glPixelMapfv");
	return Value::Null;
}

// opengl.glPixelMapuiv
Gura_DeclareFunction(glPixelMapuiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "map", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mapsize", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPixelMapuiv)
{
#if 0
	GLenum map = static_cast<GLenum>(args.GetInt(0));
	GLint mapsize = args.GetInt(1);
	CArray<GLuint> values = args.GetList(2);
	glPixelMapuiv(map, mapsize, values);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glPixelMapuiv");
	return Value::Null;
}

// opengl.glPixelMapusv
Gura_DeclareFunction(glPixelMapusv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "map", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mapsize", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPixelMapusv)
{
#if 0
	GLenum map = static_cast<GLenum>(args.GetInt(0));
	GLint mapsize = args.GetInt(1);
	CArray<GLushort> values = args.GetList(2);
	glPixelMapusv(map, mapsize, values);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glPixelMapusv");
	return Value::Null;
}

// opengl.glPixelStoref
Gura_DeclareFunction(glPixelStoref)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPixelStoref)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLfloat param = args.GetFloat(1);
	glPixelStoref(pname, param);
	return Value::Null;
}

// opengl.glPixelStorei
Gura_DeclareFunction(glPixelStorei)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPixelStorei)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLint param = args.GetInt(1);
	glPixelStorei(pname, param);
	return Value::Null;
}

// opengl.glPixelTransferf
Gura_DeclareFunction(glPixelTransferf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPixelTransferf)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLfloat param = args.GetFloat(1);
	glPixelTransferf(pname, param);
	return Value::Null;
}

// opengl.glPixelTransferi
Gura_DeclareFunction(glPixelTransferi)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPixelTransferi)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLint param = args.GetInt(1);
	glPixelTransferi(pname, param);
	return Value::Null;
}

// opengl.glPixelZoom
Gura_DeclareFunction(glPixelZoom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "xfactor", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "yfactor", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPixelZoom)
{
	GLfloat xfactor = args.GetFloat(0);
	GLfloat yfactor = args.GetFloat(1);
	glPixelZoom(xfactor, yfactor);
	return Value::Null;
}

// opengl.glPointSize
Gura_DeclareFunction(glPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPointSize)
{
	GLfloat size = args.GetFloat(0);
	glPointSize(size);
	return Value::Null;
}

// opengl.glPolygonMode
Gura_DeclareFunction(glPolygonMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPolygonMode)
{
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum mode = static_cast<GLenum>(args.GetInt(1));
	glPolygonMode(face, mode);
	return Value::Null;
}

// opengl.glPolygonOffset
Gura_DeclareFunction(glPolygonOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "factor", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "units", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPolygonOffset)
{
	GLfloat factor = args.GetFloat(0);
	GLfloat units = args.GetFloat(1);
	glPolygonOffset(factor, units);
	return Value::Null;
}

// opengl.glPolygonStipple
Gura_DeclareFunction(glPolygonStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPolygonStipple)
{
#if 0
	CArray<GLubyte> mask = args.GetList(0);
	glPolygonStipple(mask);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glPolygonStipple");
	return Value::Null;
}

// opengl.glPopAttrib
Gura_DeclareFunction(glPopAttrib)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPopAttrib)
{
	glPopAttrib();
	return Value::Null;
}

// opengl.glPopClientAttrib
Gura_DeclareFunction(glPopClientAttrib)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPopClientAttrib)
{
	glPopClientAttrib();
	return Value::Null;
}

// opengl.glPopMatrix
Gura_DeclareFunction(glPopMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPopMatrix)
{
	glPopMatrix();
	return Value::Null;
}

// opengl.glPopName
Gura_DeclareFunction(glPopName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPopName)
{
	glPopName();
	return Value::Null;
}

// opengl.glPrioritizeTextures
Gura_DeclareFunction(glPrioritizeTextures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "textures", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "priorities", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPrioritizeTextures)
{
#if 0
	GLsizei n = args.GetInt(0);
	CArray<GLuint> textures = args.GetList(1);
	CArray<GLclampf> priorities = args.GetList(2);
	glPrioritizeTextures(n, textures, priorities);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glPrioritizeTextures");
	return Value::Null;
}

// opengl.glPushAttrib
Gura_DeclareFunction(glPushAttrib)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPushAttrib)
{
	GLbitfield mask = args.GetUInt(0);
	glPushAttrib(mask);
	return Value::Null;
}

// opengl.glPushClientAttrib
Gura_DeclareFunction(glPushClientAttrib)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPushClientAttrib)
{
	GLbitfield mask = args.GetUInt(0);
	glPushClientAttrib(mask);
	return Value::Null;
}

// opengl.glPushMatrix
Gura_DeclareFunction(glPushMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPushMatrix)
{
	glPushMatrix();
	return Value::Null;
}

// opengl.glPushName
Gura_DeclareFunction(glPushName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPushName)
{
	GLuint name = args.GetUInt(0);
	glPushName(name);
	return Value::Null;
}

// opengl.glRasterPos2d
Gura_DeclareFunction(glRasterPos2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos2d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	glRasterPos2d(x, y);
	return Value::Null;
}

// opengl.glRasterPos2dv
Gura_DeclareFunction(glRasterPos2dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos2dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glRasterPos2dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos2dv");
	return Value::Null;
}

// opengl.glRasterPos2f
Gura_DeclareFunction(glRasterPos2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos2f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	glRasterPos2f(x, y);
	return Value::Null;
}

// opengl.glRasterPos2fv
Gura_DeclareFunction(glRasterPos2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos2fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glRasterPos2fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos2fv");
	return Value::Null;
}

// opengl.glRasterPos2i
Gura_DeclareFunction(glRasterPos2i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos2i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	glRasterPos2i(x, y);
	return Value::Null;
}

// opengl.glRasterPos2iv
Gura_DeclareFunction(glRasterPos2iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos2iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glRasterPos2iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos2iv");
	return Value::Null;
}

// opengl.glRasterPos2s
Gura_DeclareFunction(glRasterPos2s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos2s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	glRasterPos2s(x, y);
	return Value::Null;
}

// opengl.glRasterPos2sv
Gura_DeclareFunction(glRasterPos2sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos2sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glRasterPos2sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos2sv");
	return Value::Null;
}

// opengl.glRasterPos3d
Gura_DeclareFunction(glRasterPos3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos3d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	glRasterPos3d(x, y, z);
	return Value::Null;
}

// opengl.glRasterPos3dv
Gura_DeclareFunction(glRasterPos3dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos3dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glRasterPos3dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos3dv");
	return Value::Null;
}

// opengl.glRasterPos3f
Gura_DeclareFunction(glRasterPos3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos3f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	glRasterPos3f(x, y, z);
	return Value::Null;
}

// opengl.glRasterPos3fv
Gura_DeclareFunction(glRasterPos3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos3fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glRasterPos3fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos3fv");
	return Value::Null;
}

// opengl.glRasterPos3i
Gura_DeclareFunction(glRasterPos3i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos3i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLint z = args.GetInt(2);
	glRasterPos3i(x, y, z);
	return Value::Null;
}

// opengl.glRasterPos3iv
Gura_DeclareFunction(glRasterPos3iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos3iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glRasterPos3iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos3iv");
	return Value::Null;
}

// opengl.glRasterPos3s
Gura_DeclareFunction(glRasterPos3s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos3s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	GLshort z = args.GetShort(2);
	glRasterPos3s(x, y, z);
	return Value::Null;
}

// opengl.glRasterPos3sv
Gura_DeclareFunction(glRasterPos3sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos3sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glRasterPos3sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos3sv");
	return Value::Null;
}

// opengl.glRasterPos4d
Gura_DeclareFunction(glRasterPos4d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos4d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	GLdouble w = args.GetDouble(3);
	glRasterPos4d(x, y, z, w);
	return Value::Null;
}

// opengl.glRasterPos4dv
Gura_DeclareFunction(glRasterPos4dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos4dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glRasterPos4dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos4dv");
	return Value::Null;
}

// opengl.glRasterPos4f
Gura_DeclareFunction(glRasterPos4f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos4f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	GLfloat w = args.GetFloat(3);
	glRasterPos4f(x, y, z, w);
	return Value::Null;
}

// opengl.glRasterPos4fv
Gura_DeclareFunction(glRasterPos4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos4fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glRasterPos4fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos4fv");
	return Value::Null;
}

// opengl.glRasterPos4i
Gura_DeclareFunction(glRasterPos4i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos4i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLint z = args.GetInt(2);
	GLint w = args.GetInt(3);
	glRasterPos4i(x, y, z, w);
	return Value::Null;
}

// opengl.glRasterPos4iv
Gura_DeclareFunction(glRasterPos4iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos4iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glRasterPos4iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos4iv");
	return Value::Null;
}

// opengl.glRasterPos4s
Gura_DeclareFunction(glRasterPos4s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos4s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	GLshort z = args.GetShort(2);
	GLshort w = args.GetShort(3);
	glRasterPos4s(x, y, z, w);
	return Value::Null;
}

// opengl.glRasterPos4sv
Gura_DeclareFunction(glRasterPos4sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRasterPos4sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glRasterPos4sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRasterPos4sv");
	return Value::Null;
}

// opengl.glReadBuffer
Gura_DeclareFunction(glReadBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glReadBuffer)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	glReadBuffer(mode);
	return Value::Null;
}

// opengl.glRectd
Gura_DeclareFunction(glRectd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRectd)
{
	GLdouble x1 = args.GetDouble(0);
	GLdouble y1 = args.GetDouble(1);
	GLdouble x2 = args.GetDouble(2);
	GLdouble y2 = args.GetDouble(3);
	glRectd(x1, y1, x2, y2);
	return Value::Null;
}

// opengl.glRectdv
Gura_DeclareFunction(glRectdv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRectdv)
{
#if 0
	CArray<GLdouble> v1 = args.GetList(0);
	CArray<GLdouble> v2 = args.GetList(1);
	glRectdv(v1, v2);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRectdv");
	return Value::Null;
}

// opengl.glRectf
Gura_DeclareFunction(glRectf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRectf)
{
	GLfloat x1 = args.GetFloat(0);
	GLfloat y1 = args.GetFloat(1);
	GLfloat x2 = args.GetFloat(2);
	GLfloat y2 = args.GetFloat(3);
	glRectf(x1, y1, x2, y2);
	return Value::Null;
}

// opengl.glRectfv
Gura_DeclareFunction(glRectfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRectfv)
{
#if 0
	CArray<GLfloat> v1 = args.GetList(0);
	CArray<GLfloat> v2 = args.GetList(1);
	glRectfv(v1, v2);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRectfv");
	return Value::Null;
}

// opengl.glRecti
Gura_DeclareFunction(glRecti)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRecti)
{
	GLint x1 = args.GetInt(0);
	GLint y1 = args.GetInt(1);
	GLint x2 = args.GetInt(2);
	GLint y2 = args.GetInt(3);
	glRecti(x1, y1, x2, y2);
	return Value::Null;
}

// opengl.glRectiv
Gura_DeclareFunction(glRectiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRectiv)
{
#if 0
	CArray<GLint> v1 = args.GetList(0);
	CArray<GLint> v2 = args.GetList(1);
	glRectiv(v1, v2);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRectiv");
	return Value::Null;
}

// opengl.glRects
Gura_DeclareFunction(glRects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRects)
{
	GLshort x1 = args.GetShort(0);
	GLshort y1 = args.GetShort(1);
	GLshort x2 = args.GetShort(2);
	GLshort y2 = args.GetShort(3);
	glRects(x1, y1, x2, y2);
	return Value::Null;
}

// opengl.glRectsv
Gura_DeclareFunction(glRectsv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRectsv)
{
#if 0
	CArray<GLshort> v1 = args.GetList(0);
	CArray<GLshort> v2 = args.GetList(1);
	glRectsv(v1, v2);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glRectsv");
	return Value::Null;
}

// opengl.glRenderMode
Gura_DeclareFunction(glRenderMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRenderMode)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	GLint _rtn = glRenderMode(mode);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// opengl.glResetHistogram
Gura_DeclareFunction(glResetHistogram)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glResetHistogram)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	glResetHistogram(target);
	return Value::Null;
}

// opengl.glResetMinmax
Gura_DeclareFunction(glResetMinmax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glResetMinmax)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	glResetMinmax(target);
	return Value::Null;
}

// opengl.glRotated
Gura_DeclareFunction(glRotated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRotated)
{
	GLdouble angle = args.GetDouble(0);
	GLdouble x = args.GetDouble(1);
	GLdouble y = args.GetDouble(2);
	GLdouble z = args.GetDouble(3);
	glRotated(angle, x, y, z);
	return Value::Null;
}

// opengl.glRotatef
Gura_DeclareFunction(glRotatef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glRotatef)
{
	GLfloat angle = args.GetFloat(0);
	GLfloat x = args.GetFloat(1);
	GLfloat y = args.GetFloat(2);
	GLfloat z = args.GetFloat(3);
	glRotatef(angle, x, y, z);
	return Value::Null;
}

// opengl.glScaled
Gura_DeclareFunction(glScaled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glScaled)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	glScaled(x, y, z);
	return Value::Null;
}

// opengl.glScalef
Gura_DeclareFunction(glScalef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glScalef)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	glScalef(x, y, z);
	return Value::Null;
}

// opengl.glScissor
Gura_DeclareFunction(glScissor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glScissor)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLsizei width = args.GetInt(2);
	GLsizei height = args.GetInt(3);
	glScissor(x, y, width, height);
	return Value::Null;
}

// opengl.glSelectBuffer
Gura_DeclareFunction(glSelectBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSelectBuffer)
{
#if 0
	GLsizei size = args.GetInt(0);
	CArray<GLuint> buffer = args.GetList(1);
	glSelectBuffer(size, buffer);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glSelectBuffer");
	return Value::Null;
}

// opengl.glShadeModel
Gura_DeclareFunction(glShadeModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glShadeModel)
{
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	glShadeModel(mode);
	return Value::Null;
}

// opengl.glStencilFunc
Gura_DeclareFunction(glStencilFunc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "func", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ref", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glStencilFunc)
{
	GLenum func = static_cast<GLenum>(args.GetInt(0));
	GLint ref = args.GetInt(1);
	GLuint mask = args.GetUInt(2);
	glStencilFunc(func, ref, mask);
	return Value::Null;
}

// opengl.glStencilMask
Gura_DeclareFunction(glStencilMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glStencilMask)
{
	GLuint mask = args.GetUInt(0);
	glStencilMask(mask);
	return Value::Null;
}

// opengl.glStencilOp
Gura_DeclareFunction(glStencilOp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "fail", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zfail", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zpass", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glStencilOp)
{
	GLenum fail = static_cast<GLenum>(args.GetInt(0));
	GLenum zfail = static_cast<GLenum>(args.GetInt(1));
	GLenum zpass = static_cast<GLenum>(args.GetInt(2));
	glStencilOp(fail, zfail, zpass);
	return Value::Null;
}

// opengl.glTexCoord1d
Gura_DeclareFunction(glTexCoord1d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord1d)
{
	GLdouble s = args.GetDouble(0);
	glTexCoord1d(s);
	return Value::Null;
}

// opengl.glTexCoord1dv
Gura_DeclareFunction(glTexCoord1dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord1dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glTexCoord1dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord1dv");
	return Value::Null;
}

// opengl.glTexCoord1f
Gura_DeclareFunction(glTexCoord1f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord1f)
{
	GLfloat s = args.GetFloat(0);
	glTexCoord1f(s);
	return Value::Null;
}

// opengl.glTexCoord1fv
Gura_DeclareFunction(glTexCoord1fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord1fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glTexCoord1fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord1fv");
	return Value::Null;
}

// opengl.glTexCoord1i
Gura_DeclareFunction(glTexCoord1i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord1i)
{
	GLint s = args.GetInt(0);
	glTexCoord1i(s);
	return Value::Null;
}

// opengl.glTexCoord1iv
Gura_DeclareFunction(glTexCoord1iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord1iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glTexCoord1iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord1iv");
	return Value::Null;
}

// opengl.glTexCoord1s
Gura_DeclareFunction(glTexCoord1s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord1s)
{
	GLshort s = args.GetShort(0);
	glTexCoord1s(s);
	return Value::Null;
}

// opengl.glTexCoord1sv
Gura_DeclareFunction(glTexCoord1sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord1sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glTexCoord1sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord1sv");
	return Value::Null;
}

// opengl.glTexCoord2d
Gura_DeclareFunction(glTexCoord2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord2d)
{
	GLdouble s = args.GetDouble(0);
	GLdouble t = args.GetDouble(1);
	glTexCoord2d(s, t);
	return Value::Null;
}

// opengl.glTexCoord2dv
Gura_DeclareFunction(glTexCoord2dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord2dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glTexCoord2dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord2dv");
	return Value::Null;
}

// opengl.glTexCoord2f
Gura_DeclareFunction(glTexCoord2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord2f)
{
	GLfloat s = args.GetFloat(0);
	GLfloat t = args.GetFloat(1);
	glTexCoord2f(s, t);
	return Value::Null;
}

// opengl.glTexCoord2fv
Gura_DeclareFunction(glTexCoord2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord2fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glTexCoord2fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord2fv");
	return Value::Null;
}

// opengl.glTexCoord2i
Gura_DeclareFunction(glTexCoord2i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord2i)
{
	GLint s = args.GetInt(0);
	GLint t = args.GetInt(1);
	glTexCoord2i(s, t);
	return Value::Null;
}

// opengl.glTexCoord2iv
Gura_DeclareFunction(glTexCoord2iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord2iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glTexCoord2iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord2iv");
	return Value::Null;
}

// opengl.glTexCoord2s
Gura_DeclareFunction(glTexCoord2s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord2s)
{
	GLshort s = args.GetShort(0);
	GLshort t = args.GetShort(1);
	glTexCoord2s(s, t);
	return Value::Null;
}

// opengl.glTexCoord2sv
Gura_DeclareFunction(glTexCoord2sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord2sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glTexCoord2sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord2sv");
	return Value::Null;
}

// opengl.glTexCoord3d
Gura_DeclareFunction(glTexCoord3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord3d)
{
	GLdouble s = args.GetDouble(0);
	GLdouble t = args.GetDouble(1);
	GLdouble r = args.GetDouble(2);
	glTexCoord3d(s, t, r);
	return Value::Null;
}

// opengl.glTexCoord3dv
Gura_DeclareFunction(glTexCoord3dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord3dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glTexCoord3dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord3dv");
	return Value::Null;
}

// opengl.glTexCoord3f
Gura_DeclareFunction(glTexCoord3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord3f)
{
	GLfloat s = args.GetFloat(0);
	GLfloat t = args.GetFloat(1);
	GLfloat r = args.GetFloat(2);
	glTexCoord3f(s, t, r);
	return Value::Null;
}

// opengl.glTexCoord3fv
Gura_DeclareFunction(glTexCoord3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord3fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glTexCoord3fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord3fv");
	return Value::Null;
}

// opengl.glTexCoord3i
Gura_DeclareFunction(glTexCoord3i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord3i)
{
	GLint s = args.GetInt(0);
	GLint t = args.GetInt(1);
	GLint r = args.GetInt(2);
	glTexCoord3i(s, t, r);
	return Value::Null;
}

// opengl.glTexCoord3iv
Gura_DeclareFunction(glTexCoord3iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord3iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glTexCoord3iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord3iv");
	return Value::Null;
}

// opengl.glTexCoord3s
Gura_DeclareFunction(glTexCoord3s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord3s)
{
	GLshort s = args.GetShort(0);
	GLshort t = args.GetShort(1);
	GLshort r = args.GetShort(2);
	glTexCoord3s(s, t, r);
	return Value::Null;
}

// opengl.glTexCoord3sv
Gura_DeclareFunction(glTexCoord3sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord3sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glTexCoord3sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord3sv");
	return Value::Null;
}

// opengl.glTexCoord4d
Gura_DeclareFunction(glTexCoord4d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "q", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord4d)
{
	GLdouble s = args.GetDouble(0);
	GLdouble t = args.GetDouble(1);
	GLdouble r = args.GetDouble(2);
	GLdouble q = args.GetDouble(3);
	glTexCoord4d(s, t, r, q);
	return Value::Null;
}

// opengl.glTexCoord4dv
Gura_DeclareFunction(glTexCoord4dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord4dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glTexCoord4dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord4dv");
	return Value::Null;
}

// opengl.glTexCoord4f
Gura_DeclareFunction(glTexCoord4f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "q", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord4f)
{
	GLfloat s = args.GetFloat(0);
	GLfloat t = args.GetFloat(1);
	GLfloat r = args.GetFloat(2);
	GLfloat q = args.GetFloat(3);
	glTexCoord4f(s, t, r, q);
	return Value::Null;
}

// opengl.glTexCoord4fv
Gura_DeclareFunction(glTexCoord4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord4fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glTexCoord4fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord4fv");
	return Value::Null;
}

// opengl.glTexCoord4i
Gura_DeclareFunction(glTexCoord4i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "q", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord4i)
{
	GLint s = args.GetInt(0);
	GLint t = args.GetInt(1);
	GLint r = args.GetInt(2);
	GLint q = args.GetInt(3);
	glTexCoord4i(s, t, r, q);
	return Value::Null;
}

// opengl.glTexCoord4iv
Gura_DeclareFunction(glTexCoord4iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord4iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glTexCoord4iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord4iv");
	return Value::Null;
}

// opengl.glTexCoord4s
Gura_DeclareFunction(glTexCoord4s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "q", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord4s)
{
	GLshort s = args.GetShort(0);
	GLshort t = args.GetShort(1);
	GLshort r = args.GetShort(2);
	GLshort q = args.GetShort(3);
	glTexCoord4s(s, t, r, q);
	return Value::Null;
}

// opengl.glTexCoord4sv
Gura_DeclareFunction(glTexCoord4sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexCoord4sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glTexCoord4sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexCoord4sv");
	return Value::Null;
}

// opengl.glTexEnvf
Gura_DeclareFunction(glTexEnvf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexEnvf)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLfloat param = args.GetFloat(2);
	glTexEnvf(target, pname, param);
	return Value::Null;
}

// opengl.glTexEnvfv
Gura_DeclareFunction(glTexEnvfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexEnvfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glTexEnvfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexEnvfv");
	return Value::Null;
}

// opengl.glTexEnvi
Gura_DeclareFunction(glTexEnvi)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexEnvi)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLint param = args.GetInt(2);
	glTexEnvi(target, pname, param);
	return Value::Null;
}

// opengl.glTexEnviv
Gura_DeclareFunction(glTexEnviv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexEnviv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glTexEnviv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexEnviv");
	return Value::Null;
}

// opengl.glTexGend
Gura_DeclareFunction(glTexGend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexGend)
{
	GLenum coord = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLdouble param = args.GetDouble(2);
	glTexGend(coord, pname, param);
	return Value::Null;
}

// opengl.glTexGendv
Gura_DeclareFunction(glTexGendv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexGendv)
{
#if 0
	GLenum coord = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLdouble> params = args.GetList(2);
	glTexGendv(coord, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexGendv");
	return Value::Null;
}

// opengl.glTexGenf
Gura_DeclareFunction(glTexGenf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexGenf)
{
	GLenum coord = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLfloat param = args.GetFloat(2);
	glTexGenf(coord, pname, param);
	return Value::Null;
}

// opengl.glTexGenfv
Gura_DeclareFunction(glTexGenfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexGenfv)
{
#if 0
	GLenum coord = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glTexGenfv(coord, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexGenfv");
	return Value::Null;
}

// opengl.glTexGeni
Gura_DeclareFunction(glTexGeni)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexGeni)
{
	GLenum coord = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLint param = args.GetInt(2);
	glTexGeni(coord, pname, param);
	return Value::Null;
}

// opengl.glTexGeniv
Gura_DeclareFunction(glTexGeniv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexGeniv)
{
#if 0
	GLenum coord = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glTexGeniv(coord, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexGeniv");
	return Value::Null;
}

// opengl.glTexParameterf
Gura_DeclareFunction(glTexParameterf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexParameterf)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLfloat param = args.GetFloat(2);
	glTexParameterf(target, pname, param);
	return Value::Null;
}

// opengl.glTexParameterfv
Gura_DeclareFunction(glTexParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexParameterfv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glTexParameterfv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexParameterfv");
	return Value::Null;
}

// opengl.glTexParameteri
Gura_DeclareFunction(glTexParameteri)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexParameteri)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	GLint param = args.GetInt(2);
	glTexParameteri(target, pname, param);
	return Value::Null;
}

// opengl.glTexParameteriv
Gura_DeclareFunction(glTexParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTexParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glTexParameteriv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glTexParameteriv");
	return Value::Null;
}

// opengl.glTranslated
Gura_DeclareFunction(glTranslated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTranslated)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	glTranslated(x, y, z);
	return Value::Null;
}

// opengl.glTranslatef
Gura_DeclareFunction(glTranslatef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glTranslatef)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	glTranslatef(x, y, z);
	return Value::Null;
}

// opengl.glVertex2d
Gura_DeclareFunction(glVertex2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex2d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	glVertex2d(x, y);
	return Value::Null;
}

// opengl.glVertex2dv
Gura_DeclareFunction(glVertex2dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex2dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glVertex2dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex2dv");
	return Value::Null;
}

// opengl.glVertex2f
Gura_DeclareFunction(glVertex2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex2f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	glVertex2f(x, y);
	return Value::Null;
}

// opengl.glVertex2fv
Gura_DeclareFunction(glVertex2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex2fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glVertex2fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex2fv");
	return Value::Null;
}

// opengl.glVertex2i
Gura_DeclareFunction(glVertex2i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex2i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	glVertex2i(x, y);
	return Value::Null;
}

// opengl.glVertex2iv
Gura_DeclareFunction(glVertex2iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex2iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glVertex2iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex2iv");
	return Value::Null;
}

// opengl.glVertex2s
Gura_DeclareFunction(glVertex2s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex2s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	glVertex2s(x, y);
	return Value::Null;
}

// opengl.glVertex2sv
Gura_DeclareFunction(glVertex2sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex2sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glVertex2sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex2sv");
	return Value::Null;
}

// opengl.glVertex3d
Gura_DeclareFunction(glVertex3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex3d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	glVertex3d(x, y, z);
	return Value::Null;
}

// opengl.glVertex3dv
Gura_DeclareFunction(glVertex3dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex3dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glVertex3dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex3dv");
	return Value::Null;
}

// opengl.glVertex3f
Gura_DeclareFunction(glVertex3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex3f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	glVertex3f(x, y, z);
	return Value::Null;
}

// opengl.glVertex3fv
Gura_DeclareFunction(glVertex3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex3fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glVertex3fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex3fv");
	return Value::Null;
}

// opengl.glVertex3i
Gura_DeclareFunction(glVertex3i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex3i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLint z = args.GetInt(2);
	glVertex3i(x, y, z);
	return Value::Null;
}

// opengl.glVertex3iv
Gura_DeclareFunction(glVertex3iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex3iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glVertex3iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex3iv");
	return Value::Null;
}

// opengl.glVertex3s
Gura_DeclareFunction(glVertex3s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex3s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	GLshort z = args.GetShort(2);
	glVertex3s(x, y, z);
	return Value::Null;
}

// opengl.glVertex3sv
Gura_DeclareFunction(glVertex3sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex3sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glVertex3sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex3sv");
	return Value::Null;
}

// opengl.glVertex4d
Gura_DeclareFunction(glVertex4d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex4d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	GLdouble w = args.GetDouble(3);
	glVertex4d(x, y, z, w);
	return Value::Null;
}

// opengl.glVertex4dv
Gura_DeclareFunction(glVertex4dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex4dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glVertex4dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex4dv");
	return Value::Null;
}

// opengl.glVertex4f
Gura_DeclareFunction(glVertex4f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex4f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	GLfloat w = args.GetFloat(3);
	glVertex4f(x, y, z, w);
	return Value::Null;
}

// opengl.glVertex4fv
Gura_DeclareFunction(glVertex4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex4fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glVertex4fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex4fv");
	return Value::Null;
}

// opengl.glVertex4i
Gura_DeclareFunction(glVertex4i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex4i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLint z = args.GetInt(2);
	GLint w = args.GetInt(3);
	glVertex4i(x, y, z, w);
	return Value::Null;
}

// opengl.glVertex4iv
Gura_DeclareFunction(glVertex4iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex4iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glVertex4iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex4iv");
	return Value::Null;
}

// opengl.glVertex4s
Gura_DeclareFunction(glVertex4s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex4s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	GLshort z = args.GetShort(2);
	GLshort w = args.GetShort(3);
	glVertex4s(x, y, z, w);
	return Value::Null;
}

// opengl.glVertex4sv
Gura_DeclareFunction(glVertex4sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertex4sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glVertex4sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertex4sv");
	return Value::Null;
}

// opengl.glViewport
Gura_DeclareFunction(glViewport)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glViewport)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLsizei width = args.GetInt(2);
	GLsizei height = args.GetInt(3);
	glViewport(x, y, width, height);
	return Value::Null;
}

// opengl.glSampleCoverage
Gura_DeclareFunction(glSampleCoverage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "invert", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSampleCoverage)
{
	GLclampf value = args.GetFloat(0);
	GLboolean invert = (args.GetBoolean(1)? 1 : 0);
	glSampleCoverage(value, invert);
	return Value::Null;
}

// opengl.glLoadTransposeMatrixf
Gura_DeclareFunction(glLoadTransposeMatrixf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLoadTransposeMatrixf)
{
#if 0
	CArray<GLfloat> m = args.GetList(0);
	glLoadTransposeMatrixf(m);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glLoadTransposeMatrixf");
	return Value::Null;
}

// opengl.glLoadTransposeMatrixd
Gura_DeclareFunction(glLoadTransposeMatrixd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLoadTransposeMatrixd)
{
#if 0
	CArray<GLdouble> m = args.GetList(0);
	glLoadTransposeMatrixd(m);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glLoadTransposeMatrixd");
	return Value::Null;
}

// opengl.glMultTransposeMatrixf
Gura_DeclareFunction(glMultTransposeMatrixf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultTransposeMatrixf)
{
#if 0
	CArray<GLfloat> m = args.GetList(0);
	glMultTransposeMatrixf(m);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultTransposeMatrixf");
	return Value::Null;
}

// opengl.glMultTransposeMatrixd
Gura_DeclareFunction(glMultTransposeMatrixd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultTransposeMatrixd)
{
#if 0
	CArray<GLdouble> m = args.GetList(0);
	glMultTransposeMatrixd(m);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultTransposeMatrixd");
	return Value::Null;
}

// opengl.glActiveTexture
Gura_DeclareFunction(glActiveTexture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glActiveTexture)
{
	GLenum texture = static_cast<GLenum>(args.GetInt(0));
	glActiveTexture(texture);
	return Value::Null;
}

// opengl.glClientActiveTexture
Gura_DeclareFunction(glClientActiveTexture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glClientActiveTexture)
{
	GLenum texture = static_cast<GLenum>(args.GetInt(0));
	glClientActiveTexture(texture);
	return Value::Null;
}

// opengl.glMultiTexCoord1d
Gura_DeclareFunction(glMultiTexCoord1d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord1d)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLdouble s = args.GetDouble(1);
	glMultiTexCoord1d(target, s);
	return Value::Null;
}

// opengl.glMultiTexCoord1dv
Gura_DeclareFunction(glMultiTexCoord1dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord1dv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLdouble> v = args.GetList(1);
	glMultiTexCoord1dv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord1dv");
	return Value::Null;
}

// opengl.glMultiTexCoord1f
Gura_DeclareFunction(glMultiTexCoord1f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord1f)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLfloat s = args.GetFloat(1);
	glMultiTexCoord1f(target, s);
	return Value::Null;
}

// opengl.glMultiTexCoord1fv
Gura_DeclareFunction(glMultiTexCoord1fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord1fv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLfloat> v = args.GetList(1);
	glMultiTexCoord1fv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord1fv");
	return Value::Null;
}

// opengl.glMultiTexCoord1i
Gura_DeclareFunction(glMultiTexCoord1i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord1i)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint s = args.GetInt(1);
	glMultiTexCoord1i(target, s);
	return Value::Null;
}

// opengl.glMultiTexCoord1iv
Gura_DeclareFunction(glMultiTexCoord1iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord1iv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLint> v = args.GetList(1);
	glMultiTexCoord1iv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord1iv");
	return Value::Null;
}

// opengl.glMultiTexCoord1s
Gura_DeclareFunction(glMultiTexCoord1s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord1s)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLshort s = args.GetShort(1);
	glMultiTexCoord1s(target, s);
	return Value::Null;
}

// opengl.glMultiTexCoord1sv
Gura_DeclareFunction(glMultiTexCoord1sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord1sv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLshort> v = args.GetList(1);
	glMultiTexCoord1sv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord1sv");
	return Value::Null;
}

// opengl.glMultiTexCoord2d
Gura_DeclareFunction(glMultiTexCoord2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord2d)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLdouble s = args.GetDouble(1);
	GLdouble t = args.GetDouble(2);
	glMultiTexCoord2d(target, s, t);
	return Value::Null;
}

// opengl.glMultiTexCoord2dv
Gura_DeclareFunction(glMultiTexCoord2dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord2dv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLdouble> v = args.GetList(1);
	glMultiTexCoord2dv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord2dv");
	return Value::Null;
}

// opengl.glMultiTexCoord2f
Gura_DeclareFunction(glMultiTexCoord2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord2f)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLfloat s = args.GetFloat(1);
	GLfloat t = args.GetFloat(2);
	glMultiTexCoord2f(target, s, t);
	return Value::Null;
}

// opengl.glMultiTexCoord2fv
Gura_DeclareFunction(glMultiTexCoord2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord2fv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLfloat> v = args.GetList(1);
	glMultiTexCoord2fv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord2fv");
	return Value::Null;
}

// opengl.glMultiTexCoord2i
Gura_DeclareFunction(glMultiTexCoord2i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord2i)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint s = args.GetInt(1);
	GLint t = args.GetInt(2);
	glMultiTexCoord2i(target, s, t);
	return Value::Null;
}

// opengl.glMultiTexCoord2iv
Gura_DeclareFunction(glMultiTexCoord2iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord2iv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLint> v = args.GetList(1);
	glMultiTexCoord2iv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord2iv");
	return Value::Null;
}

// opengl.glMultiTexCoord2s
Gura_DeclareFunction(glMultiTexCoord2s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord2s)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLshort s = args.GetShort(1);
	GLshort t = args.GetShort(2);
	glMultiTexCoord2s(target, s, t);
	return Value::Null;
}

// opengl.glMultiTexCoord2sv
Gura_DeclareFunction(glMultiTexCoord2sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord2sv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLshort> v = args.GetList(1);
	glMultiTexCoord2sv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord2sv");
	return Value::Null;
}

// opengl.glMultiTexCoord3d
Gura_DeclareFunction(glMultiTexCoord3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord3d)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLdouble s = args.GetDouble(1);
	GLdouble t = args.GetDouble(2);
	GLdouble r = args.GetDouble(3);
	glMultiTexCoord3d(target, s, t, r);
	return Value::Null;
}

// opengl.glMultiTexCoord3dv
Gura_DeclareFunction(glMultiTexCoord3dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord3dv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLdouble> v = args.GetList(1);
	glMultiTexCoord3dv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord3dv");
	return Value::Null;
}

// opengl.glMultiTexCoord3f
Gura_DeclareFunction(glMultiTexCoord3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord3f)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLfloat s = args.GetFloat(1);
	GLfloat t = args.GetFloat(2);
	GLfloat r = args.GetFloat(3);
	glMultiTexCoord3f(target, s, t, r);
	return Value::Null;
}

// opengl.glMultiTexCoord3fv
Gura_DeclareFunction(glMultiTexCoord3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord3fv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLfloat> v = args.GetList(1);
	glMultiTexCoord3fv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord3fv");
	return Value::Null;
}

// opengl.glMultiTexCoord3i
Gura_DeclareFunction(glMultiTexCoord3i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord3i)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint s = args.GetInt(1);
	GLint t = args.GetInt(2);
	GLint r = args.GetInt(3);
	glMultiTexCoord3i(target, s, t, r);
	return Value::Null;
}

// opengl.glMultiTexCoord3iv
Gura_DeclareFunction(glMultiTexCoord3iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord3iv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLint> v = args.GetList(1);
	glMultiTexCoord3iv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord3iv");
	return Value::Null;
}

// opengl.glMultiTexCoord3s
Gura_DeclareFunction(glMultiTexCoord3s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord3s)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLshort s = args.GetShort(1);
	GLshort t = args.GetShort(2);
	GLshort r = args.GetShort(3);
	glMultiTexCoord3s(target, s, t, r);
	return Value::Null;
}

// opengl.glMultiTexCoord3sv
Gura_DeclareFunction(glMultiTexCoord3sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord3sv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLshort> v = args.GetList(1);
	glMultiTexCoord3sv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord3sv");
	return Value::Null;
}

// opengl.glMultiTexCoord4d
Gura_DeclareFunction(glMultiTexCoord4d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "q", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord4d)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLdouble s = args.GetDouble(1);
	GLdouble t = args.GetDouble(2);
	GLdouble r = args.GetDouble(3);
	GLdouble q = args.GetDouble(4);
	glMultiTexCoord4d(target, s, t, r, q);
	return Value::Null;
}

// opengl.glMultiTexCoord4dv
Gura_DeclareFunction(glMultiTexCoord4dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord4dv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLdouble> v = args.GetList(1);
	glMultiTexCoord4dv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord4dv");
	return Value::Null;
}

// opengl.glMultiTexCoord4f
Gura_DeclareFunction(glMultiTexCoord4f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "q", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord4f)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLfloat s = args.GetFloat(1);
	GLfloat t = args.GetFloat(2);
	GLfloat r = args.GetFloat(3);
	GLfloat q = args.GetFloat(4);
	glMultiTexCoord4f(target, s, t, r, q);
	return Value::Null;
}

// opengl.glMultiTexCoord4fv
Gura_DeclareFunction(glMultiTexCoord4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord4fv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLfloat> v = args.GetList(1);
	glMultiTexCoord4fv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord4fv");
	return Value::Null;
}

// opengl.glMultiTexCoord4i
Gura_DeclareFunction(glMultiTexCoord4i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "q", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord4i)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLint s = args.GetInt(1);
	GLint t = args.GetInt(2);
	GLint r = args.GetInt(3);
	GLint q = args.GetInt(4);
	glMultiTexCoord4i(target, s, t, r, q);
	return Value::Null;
}

// opengl.glMultiTexCoord4iv
Gura_DeclareFunction(glMultiTexCoord4iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord4iv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLint> v = args.GetList(1);
	glMultiTexCoord4iv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord4iv");
	return Value::Null;
}

// opengl.glMultiTexCoord4s
Gura_DeclareFunction(glMultiTexCoord4s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "t", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "q", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord4s)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLshort s = args.GetShort(1);
	GLshort t = args.GetShort(2);
	GLshort r = args.GetShort(3);
	GLshort q = args.GetShort(4);
	glMultiTexCoord4s(target, s, t, r, q);
	return Value::Null;
}

// opengl.glMultiTexCoord4sv
Gura_DeclareFunction(glMultiTexCoord4sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiTexCoord4sv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	CArray<GLshort> v = args.GetList(1);
	glMultiTexCoord4sv(target, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiTexCoord4sv");
	return Value::Null;
}

// opengl.glFogCoordf
Gura_DeclareFunction(glFogCoordf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFogCoordf)
{
	GLfloat coord = args.GetFloat(0);
	glFogCoordf(coord);
	return Value::Null;
}

// opengl.glFogCoordfv
Gura_DeclareFunction(glFogCoordfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFogCoordfv)
{
#if 0
	CArray<GLfloat> coord = args.GetList(0);
	glFogCoordfv(coord);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glFogCoordfv");
	return Value::Null;
}

// opengl.glFogCoordd
Gura_DeclareFunction(glFogCoordd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFogCoordd)
{
	GLdouble coord = args.GetDouble(0);
	glFogCoordd(coord);
	return Value::Null;
}

// opengl.glFogCoorddv
Gura_DeclareFunction(glFogCoorddv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glFogCoorddv)
{
#if 0
	CArray<GLdouble> coord = args.GetList(0);
	glFogCoorddv(coord);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glFogCoorddv");
	return Value::Null;
}

// opengl.glSecondaryColor3b
Gura_DeclareFunction(glSecondaryColor3b)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3b)
{
	GLbyte red = args.GetChar(0);
	GLbyte green = args.GetChar(1);
	GLbyte blue = args.GetChar(2);
	glSecondaryColor3b(red, green, blue);
	return Value::Null;
}

// opengl.glSecondaryColor3bv
Gura_DeclareFunction(glSecondaryColor3bv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3bv)
{
#if 0
	CArray<GLbyte> v = args.GetList(0);
	glSecondaryColor3bv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glSecondaryColor3bv");
	return Value::Null;
}

// opengl.glSecondaryColor3d
Gura_DeclareFunction(glSecondaryColor3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3d)
{
	GLdouble red = args.GetDouble(0);
	GLdouble green = args.GetDouble(1);
	GLdouble blue = args.GetDouble(2);
	glSecondaryColor3d(red, green, blue);
	return Value::Null;
}

// opengl.glSecondaryColor3dv
Gura_DeclareFunction(glSecondaryColor3dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glSecondaryColor3dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glSecondaryColor3dv");
	return Value::Null;
}

// opengl.glSecondaryColor3f
Gura_DeclareFunction(glSecondaryColor3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3f)
{
	GLfloat red = args.GetFloat(0);
	GLfloat green = args.GetFloat(1);
	GLfloat blue = args.GetFloat(2);
	glSecondaryColor3f(red, green, blue);
	return Value::Null;
}

// opengl.glSecondaryColor3fv
Gura_DeclareFunction(glSecondaryColor3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glSecondaryColor3fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glSecondaryColor3fv");
	return Value::Null;
}

// opengl.glSecondaryColor3i
Gura_DeclareFunction(glSecondaryColor3i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3i)
{
	GLint red = args.GetInt(0);
	GLint green = args.GetInt(1);
	GLint blue = args.GetInt(2);
	glSecondaryColor3i(red, green, blue);
	return Value::Null;
}

// opengl.glSecondaryColor3iv
Gura_DeclareFunction(glSecondaryColor3iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glSecondaryColor3iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glSecondaryColor3iv");
	return Value::Null;
}

// opengl.glSecondaryColor3s
Gura_DeclareFunction(glSecondaryColor3s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3s)
{
	GLshort red = args.GetShort(0);
	GLshort green = args.GetShort(1);
	GLshort blue = args.GetShort(2);
	glSecondaryColor3s(red, green, blue);
	return Value::Null;
}

// opengl.glSecondaryColor3sv
Gura_DeclareFunction(glSecondaryColor3sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glSecondaryColor3sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glSecondaryColor3sv");
	return Value::Null;
}

// opengl.glSecondaryColor3ub
Gura_DeclareFunction(glSecondaryColor3ub)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3ub)
{
	GLubyte red = args.GetUChar(0);
	GLubyte green = args.GetUChar(1);
	GLubyte blue = args.GetUChar(2);
	glSecondaryColor3ub(red, green, blue);
	return Value::Null;
}

// opengl.glSecondaryColor3ubv
Gura_DeclareFunction(glSecondaryColor3ubv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3ubv)
{
#if 0
	CArray<GLubyte> v = args.GetList(0);
	glSecondaryColor3ubv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glSecondaryColor3ubv");
	return Value::Null;
}

// opengl.glSecondaryColor3ui
Gura_DeclareFunction(glSecondaryColor3ui)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3ui)
{
	GLuint red = args.GetUInt(0);
	GLuint green = args.GetUInt(1);
	GLuint blue = args.GetUInt(2);
	glSecondaryColor3ui(red, green, blue);
	return Value::Null;
}

// opengl.glSecondaryColor3uiv
Gura_DeclareFunction(glSecondaryColor3uiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3uiv)
{
#if 0
	CArray<GLuint> v = args.GetList(0);
	glSecondaryColor3uiv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glSecondaryColor3uiv");
	return Value::Null;
}

// opengl.glSecondaryColor3us
Gura_DeclareFunction(glSecondaryColor3us)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3us)
{
	GLushort red = args.GetUShort(0);
	GLushort green = args.GetUShort(1);
	GLushort blue = args.GetUShort(2);
	glSecondaryColor3us(red, green, blue);
	return Value::Null;
}

// opengl.glSecondaryColor3usv
Gura_DeclareFunction(glSecondaryColor3usv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glSecondaryColor3usv)
{
#if 0
	CArray<GLushort> v = args.GetList(0);
	glSecondaryColor3usv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glSecondaryColor3usv");
	return Value::Null;
}

// opengl.glPointParameterf
Gura_DeclareFunction(glPointParameterf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPointParameterf)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLfloat param = args.GetFloat(1);
	glPointParameterf(pname, param);
	return Value::Null;
}

// opengl.glPointParameterfv
Gura_DeclareFunction(glPointParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPointParameterfv)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLfloat> params = args.GetList(1);
	glPointParameterfv(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glPointParameterfv");
	return Value::Null;
}

// opengl.glPointParameteri
Gura_DeclareFunction(glPointParameteri)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPointParameteri)
{
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	GLint param = args.GetInt(1);
	glPointParameteri(pname, param);
	return Value::Null;
}

// opengl.glPointParameteriv
Gura_DeclareFunction(glPointParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glPointParameteriv)
{
#if 0
	GLenum pname = static_cast<GLenum>(args.GetInt(0));
	CArray<GLint> params = args.GetList(1);
	glPointParameteriv(pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glPointParameteriv");
	return Value::Null;
}

// opengl.glBlendFuncSeparate
Gura_DeclareFunction(glBlendFuncSeparate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "srcRGB", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstRGB", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcAlpha", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstAlpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBlendFuncSeparate)
{
	GLenum srcRGB = static_cast<GLenum>(args.GetInt(0));
	GLenum dstRGB = static_cast<GLenum>(args.GetInt(1));
	GLenum srcAlpha = static_cast<GLenum>(args.GetInt(2));
	GLenum dstAlpha = static_cast<GLenum>(args.GetInt(3));
	glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
	return Value::Null;
}

// opengl.glMultiDrawArrays
Gura_DeclareFunction(glMultiDrawArrays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "first", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "primcount", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glMultiDrawArrays)
{
#if 0
	GLenum mode = static_cast<GLenum>(args.GetInt(0));
	CArray<GLint> first = args.GetList(1);
	CArray<GLsizei> count = args.GetList(2);
	GLsizei primcount = args.GetInt(3);
	glMultiDrawArrays(mode, first, count, primcount);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glMultiDrawArrays");
	return Value::Null;
}

// opengl.glWindowPos2d
Gura_DeclareFunction(glWindowPos2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos2d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	glWindowPos2d(x, y);
	return Value::Null;
}

// opengl.glWindowPos2dv
Gura_DeclareFunction(glWindowPos2dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos2dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glWindowPos2dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glWindowPos2dv");
	return Value::Null;
}

// opengl.glWindowPos2f
Gura_DeclareFunction(glWindowPos2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos2f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	glWindowPos2f(x, y);
	return Value::Null;
}

// opengl.glWindowPos2fv
Gura_DeclareFunction(glWindowPos2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos2fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glWindowPos2fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glWindowPos2fv");
	return Value::Null;
}

// opengl.glWindowPos2i
Gura_DeclareFunction(glWindowPos2i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos2i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	glWindowPos2i(x, y);
	return Value::Null;
}

// opengl.glWindowPos2iv
Gura_DeclareFunction(glWindowPos2iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos2iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glWindowPos2iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glWindowPos2iv");
	return Value::Null;
}

// opengl.glWindowPos2s
Gura_DeclareFunction(glWindowPos2s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos2s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	glWindowPos2s(x, y);
	return Value::Null;
}

// opengl.glWindowPos2sv
Gura_DeclareFunction(glWindowPos2sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos2sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glWindowPos2sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glWindowPos2sv");
	return Value::Null;
}

// opengl.glWindowPos3d
Gura_DeclareFunction(glWindowPos3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos3d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	glWindowPos3d(x, y, z);
	return Value::Null;
}

// opengl.glWindowPos3dv
Gura_DeclareFunction(glWindowPos3dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos3dv)
{
#if 0
	CArray<GLdouble> v = args.GetList(0);
	glWindowPos3dv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glWindowPos3dv");
	return Value::Null;
}

// opengl.glWindowPos3f
Gura_DeclareFunction(glWindowPos3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos3f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	glWindowPos3f(x, y, z);
	return Value::Null;
}

// opengl.glWindowPos3fv
Gura_DeclareFunction(glWindowPos3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos3fv)
{
#if 0
	CArray<GLfloat> v = args.GetList(0);
	glWindowPos3fv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glWindowPos3fv");
	return Value::Null;
}

// opengl.glWindowPos3i
Gura_DeclareFunction(glWindowPos3i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos3i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLint z = args.GetInt(2);
	glWindowPos3i(x, y, z);
	return Value::Null;
}

// opengl.glWindowPos3iv
Gura_DeclareFunction(glWindowPos3iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos3iv)
{
#if 0
	CArray<GLint> v = args.GetList(0);
	glWindowPos3iv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glWindowPos3iv");
	return Value::Null;
}

// opengl.glWindowPos3s
Gura_DeclareFunction(glWindowPos3s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos3s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	GLshort z = args.GetShort(2);
	glWindowPos3s(x, y, z);
	return Value::Null;
}

// opengl.glWindowPos3sv
Gura_DeclareFunction(glWindowPos3sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glWindowPos3sv)
{
#if 0
	CArray<GLshort> v = args.GetList(0);
	glWindowPos3sv(v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glWindowPos3sv");
	return Value::Null;
}

// opengl.glGenQueries
Gura_DeclareFunction(glGenQueries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ids", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGenQueries)
{
#if 0
	GLsizei n = args.GetInt(0);
	CArray<GLuint> ids = args.GetList(1);
	glGenQueries(n, ids);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGenQueries");
	return Value::Null;
}

// opengl.glDeleteQueries
Gura_DeclareFunction(glDeleteQueries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ids", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDeleteQueries)
{
#if 0
	GLsizei n = args.GetInt(0);
	CArray<GLuint> ids = args.GetList(1);
	glDeleteQueries(n, ids);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glDeleteQueries");
	return Value::Null;
}

// opengl.glIsQuery
Gura_DeclareFunction(glIsQuery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIsQuery)
{
	GLuint id = args.GetUInt(0);
	GLboolean _rtn = glIsQuery(id);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// opengl.glBeginQuery
Gura_DeclareFunction(glBeginQuery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBeginQuery)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLuint id = args.GetUInt(1);
	glBeginQuery(target, id);
	return Value::Null;
}

// opengl.glEndQuery
Gura_DeclareFunction(glEndQuery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEndQuery)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	glEndQuery(target);
	return Value::Null;
}

// opengl.glGetQueryiv
Gura_DeclareFunction(glGetQueryiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetQueryiv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetQueryiv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetQueryiv");
	return Value::Null;
}

// opengl.glGetQueryObjectiv
Gura_DeclareFunction(glGetQueryObjectiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetQueryObjectiv)
{
#if 0
	GLuint id = args.GetUInt(0);
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetQueryObjectiv(id, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetQueryObjectiv");
	return Value::Null;
}

// opengl.glGetQueryObjectuiv
Gura_DeclareFunction(glGetQueryObjectuiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetQueryObjectuiv)
{
#if 0
	GLuint id = args.GetUInt(0);
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLuint> params = args.GetList(2);
	glGetQueryObjectuiv(id, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetQueryObjectuiv");
	return Value::Null;
}

// opengl.glBindBuffer
Gura_DeclareFunction(glBindBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBindBuffer)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLuint buffer = args.GetUInt(1);
	glBindBuffer(target, buffer);
	return Value::Null;
}

// opengl.glDeleteBuffers
Gura_DeclareFunction(glDeleteBuffers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "buffers", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDeleteBuffers)
{
#if 0
	GLsizei n = args.GetInt(0);
	CArray<GLuint> buffers = args.GetList(1);
	glDeleteBuffers(n, buffers);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glDeleteBuffers");
	return Value::Null;
}

// opengl.glGenBuffers
Gura_DeclareFunction(glGenBuffers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "buffers", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGenBuffers)
{
#if 0
	GLsizei n = args.GetInt(0);
	CArray<GLuint> buffers = args.GetList(1);
	glGenBuffers(n, buffers);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGenBuffers");
	return Value::Null;
}

// opengl.glIsBuffer
Gura_DeclareFunction(glIsBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIsBuffer)
{
	GLuint buffer = args.GetUInt(0);
	GLboolean _rtn = glIsBuffer(buffer);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// opengl.glUnmapBuffer
Gura_DeclareFunction(glUnmapBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUnmapBuffer)
{
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLboolean _rtn = glUnmapBuffer(target);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// opengl.glGetBufferParameteriv
Gura_DeclareFunction(glGetBufferParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetBufferParameteriv)
{
#if 0
	GLenum target = static_cast<GLenum>(args.GetInt(0));
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetBufferParameteriv(target, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetBufferParameteriv");
	return Value::Null;
}

// opengl.glDrawBuffers
Gura_DeclareFunction(glDrawBuffers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bufs", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDrawBuffers)
{
#if 0
	GLsizei n = args.GetInt(0);
	CArray<GLenum> bufs = args.GetList(1);
	glDrawBuffers(n, bufs);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glDrawBuffers");
	return Value::Null;
}

// opengl.glVertexAttrib1d
Gura_DeclareFunction(glVertexAttrib1d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib1d)
{
	GLuint index = args.GetUInt(0);
	GLdouble x = args.GetDouble(1);
	glVertexAttrib1d(index, x);
	return Value::Null;
}

// opengl.glVertexAttrib1dv
Gura_DeclareFunction(glVertexAttrib1dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib1dv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLdouble> v = args.GetList(1);
	glVertexAttrib1dv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib1dv");
	return Value::Null;
}

// opengl.glVertexAttrib1f
Gura_DeclareFunction(glVertexAttrib1f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib1f)
{
	GLuint index = args.GetUInt(0);
	GLfloat x = args.GetFloat(1);
	glVertexAttrib1f(index, x);
	return Value::Null;
}

// opengl.glVertexAttrib1fv
Gura_DeclareFunction(glVertexAttrib1fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib1fv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLfloat> v = args.GetList(1);
	glVertexAttrib1fv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib1fv");
	return Value::Null;
}

// opengl.glVertexAttrib1s
Gura_DeclareFunction(glVertexAttrib1s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib1s)
{
	GLuint index = args.GetUInt(0);
	GLshort x = args.GetShort(1);
	glVertexAttrib1s(index, x);
	return Value::Null;
}

// opengl.glVertexAttrib1sv
Gura_DeclareFunction(glVertexAttrib1sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib1sv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLshort> v = args.GetList(1);
	glVertexAttrib1sv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib1sv");
	return Value::Null;
}

// opengl.glVertexAttrib2d
Gura_DeclareFunction(glVertexAttrib2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib2d)
{
	GLuint index = args.GetUInt(0);
	GLdouble x = args.GetDouble(1);
	GLdouble y = args.GetDouble(2);
	glVertexAttrib2d(index, x, y);
	return Value::Null;
}

// opengl.glVertexAttrib2dv
Gura_DeclareFunction(glVertexAttrib2dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib2dv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLdouble> v = args.GetList(1);
	glVertexAttrib2dv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib2dv");
	return Value::Null;
}

// opengl.glVertexAttrib2f
Gura_DeclareFunction(glVertexAttrib2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib2f)
{
	GLuint index = args.GetUInt(0);
	GLfloat x = args.GetFloat(1);
	GLfloat y = args.GetFloat(2);
	glVertexAttrib2f(index, x, y);
	return Value::Null;
}

// opengl.glVertexAttrib2fv
Gura_DeclareFunction(glVertexAttrib2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib2fv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLfloat> v = args.GetList(1);
	glVertexAttrib2fv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib2fv");
	return Value::Null;
}

// opengl.glVertexAttrib2s
Gura_DeclareFunction(glVertexAttrib2s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib2s)
{
	GLuint index = args.GetUInt(0);
	GLshort x = args.GetShort(1);
	GLshort y = args.GetShort(2);
	glVertexAttrib2s(index, x, y);
	return Value::Null;
}

// opengl.glVertexAttrib2sv
Gura_DeclareFunction(glVertexAttrib2sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib2sv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLshort> v = args.GetList(1);
	glVertexAttrib2sv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib2sv");
	return Value::Null;
}

// opengl.glVertexAttrib3d
Gura_DeclareFunction(glVertexAttrib3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib3d)
{
	GLuint index = args.GetUInt(0);
	GLdouble x = args.GetDouble(1);
	GLdouble y = args.GetDouble(2);
	GLdouble z = args.GetDouble(3);
	glVertexAttrib3d(index, x, y, z);
	return Value::Null;
}

// opengl.glVertexAttrib3dv
Gura_DeclareFunction(glVertexAttrib3dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib3dv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLdouble> v = args.GetList(1);
	glVertexAttrib3dv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib3dv");
	return Value::Null;
}

// opengl.glVertexAttrib3f
Gura_DeclareFunction(glVertexAttrib3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib3f)
{
	GLuint index = args.GetUInt(0);
	GLfloat x = args.GetFloat(1);
	GLfloat y = args.GetFloat(2);
	GLfloat z = args.GetFloat(3);
	glVertexAttrib3f(index, x, y, z);
	return Value::Null;
}

// opengl.glVertexAttrib3fv
Gura_DeclareFunction(glVertexAttrib3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib3fv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLfloat> v = args.GetList(1);
	glVertexAttrib3fv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib3fv");
	return Value::Null;
}

// opengl.glVertexAttrib3s
Gura_DeclareFunction(glVertexAttrib3s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib3s)
{
	GLuint index = args.GetUInt(0);
	GLshort x = args.GetShort(1);
	GLshort y = args.GetShort(2);
	GLshort z = args.GetShort(3);
	glVertexAttrib3s(index, x, y, z);
	return Value::Null;
}

// opengl.glVertexAttrib3sv
Gura_DeclareFunction(glVertexAttrib3sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib3sv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLshort> v = args.GetList(1);
	glVertexAttrib3sv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib3sv");
	return Value::Null;
}

// opengl.glVertexAttrib4Nbv
Gura_DeclareFunction(glVertexAttrib4Nbv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4Nbv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLbyte> v = args.GetList(1);
	glVertexAttrib4Nbv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4Nbv");
	return Value::Null;
}

// opengl.glVertexAttrib4Niv
Gura_DeclareFunction(glVertexAttrib4Niv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4Niv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLint> v = args.GetList(1);
	glVertexAttrib4Niv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4Niv");
	return Value::Null;
}

// opengl.glVertexAttrib4Nsv
Gura_DeclareFunction(glVertexAttrib4Nsv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4Nsv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLshort> v = args.GetList(1);
	glVertexAttrib4Nsv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4Nsv");
	return Value::Null;
}

// opengl.glVertexAttrib4Nub
Gura_DeclareFunction(glVertexAttrib4Nub)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4Nub)
{
	GLuint index = args.GetUInt(0);
	GLubyte x = args.GetUChar(1);
	GLubyte y = args.GetUChar(2);
	GLubyte z = args.GetUChar(3);
	GLubyte w = args.GetUChar(4);
	glVertexAttrib4Nub(index, x, y, z, w);
	return Value::Null;
}

// opengl.glVertexAttrib4Nubv
Gura_DeclareFunction(glVertexAttrib4Nubv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4Nubv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLubyte> v = args.GetList(1);
	glVertexAttrib4Nubv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4Nubv");
	return Value::Null;
}

// opengl.glVertexAttrib4Nuiv
Gura_DeclareFunction(glVertexAttrib4Nuiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4Nuiv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLuint> v = args.GetList(1);
	glVertexAttrib4Nuiv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4Nuiv");
	return Value::Null;
}

// opengl.glVertexAttrib4Nusv
Gura_DeclareFunction(glVertexAttrib4Nusv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4Nusv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLushort> v = args.GetList(1);
	glVertexAttrib4Nusv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4Nusv");
	return Value::Null;
}

// opengl.glVertexAttrib4bv
Gura_DeclareFunction(glVertexAttrib4bv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4bv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLbyte> v = args.GetList(1);
	glVertexAttrib4bv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4bv");
	return Value::Null;
}

// opengl.glVertexAttrib4d
Gura_DeclareFunction(glVertexAttrib4d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4d)
{
	GLuint index = args.GetUInt(0);
	GLdouble x = args.GetDouble(1);
	GLdouble y = args.GetDouble(2);
	GLdouble z = args.GetDouble(3);
	GLdouble w = args.GetDouble(4);
	glVertexAttrib4d(index, x, y, z, w);
	return Value::Null;
}

// opengl.glVertexAttrib4dv
Gura_DeclareFunction(glVertexAttrib4dv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4dv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLdouble> v = args.GetList(1);
	glVertexAttrib4dv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4dv");
	return Value::Null;
}

// opengl.glVertexAttrib4f
Gura_DeclareFunction(glVertexAttrib4f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4f)
{
	GLuint index = args.GetUInt(0);
	GLfloat x = args.GetFloat(1);
	GLfloat y = args.GetFloat(2);
	GLfloat z = args.GetFloat(3);
	GLfloat w = args.GetFloat(4);
	glVertexAttrib4f(index, x, y, z, w);
	return Value::Null;
}

// opengl.glVertexAttrib4fv
Gura_DeclareFunction(glVertexAttrib4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4fv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLfloat> v = args.GetList(1);
	glVertexAttrib4fv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4fv");
	return Value::Null;
}

// opengl.glVertexAttrib4iv
Gura_DeclareFunction(glVertexAttrib4iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4iv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLint> v = args.GetList(1);
	glVertexAttrib4iv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4iv");
	return Value::Null;
}

// opengl.glVertexAttrib4s
Gura_DeclareFunction(glVertexAttrib4s)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "z", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4s)
{
	GLuint index = args.GetUInt(0);
	GLshort x = args.GetShort(1);
	GLshort y = args.GetShort(2);
	GLshort z = args.GetShort(3);
	GLshort w = args.GetShort(4);
	glVertexAttrib4s(index, x, y, z, w);
	return Value::Null;
}

// opengl.glVertexAttrib4sv
Gura_DeclareFunction(glVertexAttrib4sv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4sv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLshort> v = args.GetList(1);
	glVertexAttrib4sv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4sv");
	return Value::Null;
}

// opengl.glVertexAttrib4ubv
Gura_DeclareFunction(glVertexAttrib4ubv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4ubv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLubyte> v = args.GetList(1);
	glVertexAttrib4ubv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4ubv");
	return Value::Null;
}

// opengl.glVertexAttrib4uiv
Gura_DeclareFunction(glVertexAttrib4uiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4uiv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLuint> v = args.GetList(1);
	glVertexAttrib4uiv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4uiv");
	return Value::Null;
}

// opengl.glVertexAttrib4usv
Gura_DeclareFunction(glVertexAttrib4usv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glVertexAttrib4usv)
{
#if 0
	GLuint index = args.GetUInt(0);
	CArray<GLushort> v = args.GetList(1);
	glVertexAttrib4usv(index, v);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glVertexAttrib4usv");
	return Value::Null;
}

// opengl.glEnableVertexAttribArray
Gura_DeclareFunction(glEnableVertexAttribArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glEnableVertexAttribArray)
{
	GLuint index = args.GetUInt(0);
	glEnableVertexAttribArray(index);
	return Value::Null;
}

// opengl.glDisableVertexAttribArray
Gura_DeclareFunction(glDisableVertexAttribArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDisableVertexAttribArray)
{
	GLuint index = args.GetUInt(0);
	glDisableVertexAttribArray(index);
	return Value::Null;
}

// opengl.glGetVertexAttribdv
Gura_DeclareFunction(glGetVertexAttribdv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetVertexAttribdv)
{
#if 0
	GLuint index = args.GetUInt(0);
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLdouble> params = args.GetList(2);
	glGetVertexAttribdv(index, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetVertexAttribdv");
	return Value::Null;
}

// opengl.glGetVertexAttribfv
Gura_DeclareFunction(glGetVertexAttribfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetVertexAttribfv)
{
#if 0
	GLuint index = args.GetUInt(0);
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLfloat> params = args.GetList(2);
	glGetVertexAttribfv(index, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetVertexAttribfv");
	return Value::Null;
}

// opengl.glGetVertexAttribiv
Gura_DeclareFunction(glGetVertexAttribiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetVertexAttribiv)
{
#if 0
	GLuint index = args.GetUInt(0);
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetVertexAttribiv(index, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetVertexAttribiv");
	return Value::Null;
}

// opengl.glDeleteShader
Gura_DeclareFunction(glDeleteShader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "shader", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDeleteShader)
{
	GLuint shader = args.GetUInt(0);
	glDeleteShader(shader);
	return Value::Null;
}

// opengl.glDetachShader
Gura_DeclareFunction(glDetachShader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "shader", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDetachShader)
{
	GLuint program = args.GetUInt(0);
	GLuint shader = args.GetUInt(1);
	glDetachShader(program, shader);
	return Value::Null;
}

// opengl.glCreateShader
Gura_DeclareFunction(glCreateShader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCreateShader)
{
	GLenum type = static_cast<GLenum>(args.GetInt(0));
	GLuint _rtn = glCreateShader(type);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// opengl.glShaderSource
Gura_DeclareFunction(glShaderSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "shader", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "string", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glShaderSource)
{
#if 0
	GLuint shader = args.GetUInt(0);
	GLsizei count = args.GetInt(1);
	CArray<GLchar> string = args.GetList(2);
	CArray<GLint> length = args.GetList(3);
	glShaderSource(shader, count, string, length);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glShaderSource");
	return Value::Null;
}

// opengl.glCompileShader
Gura_DeclareFunction(glCompileShader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "shader", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCompileShader)
{
	GLuint shader = args.GetUInt(0);
	glCompileShader(shader);
	return Value::Null;
}

// opengl.glCreateProgram
Gura_DeclareFunction(glCreateProgram)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glCreateProgram)
{
	GLuint _rtn = glCreateProgram();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// opengl.glAttachShader
Gura_DeclareFunction(glAttachShader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "shader", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glAttachShader)
{
	GLuint program = args.GetUInt(0);
	GLuint shader = args.GetUInt(1);
	glAttachShader(program, shader);
	return Value::Null;
}

// opengl.glLinkProgram
Gura_DeclareFunction(glLinkProgram)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glLinkProgram)
{
	GLuint program = args.GetUInt(0);
	glLinkProgram(program);
	return Value::Null;
}

// opengl.glUseProgram
Gura_DeclareFunction(glUseProgram)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUseProgram)
{
	GLuint program = args.GetUInt(0);
	glUseProgram(program);
	return Value::Null;
}

// opengl.glDeleteProgram
Gura_DeclareFunction(glDeleteProgram)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glDeleteProgram)
{
	GLuint program = args.GetUInt(0);
	glDeleteProgram(program);
	return Value::Null;
}

// opengl.glValidateProgram
Gura_DeclareFunction(glValidateProgram)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glValidateProgram)
{
	GLuint program = args.GetUInt(0);
	glValidateProgram(program);
	return Value::Null;
}

// opengl.glUniform1f
Gura_DeclareFunction(glUniform1f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v0", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform1f)
{
	GLint location = args.GetInt(0);
	GLfloat v0 = args.GetFloat(1);
	glUniform1f(location, v0);
	return Value::Null;
}

// opengl.glUniform2f
Gura_DeclareFunction(glUniform2f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v0", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform2f)
{
	GLint location = args.GetInt(0);
	GLfloat v0 = args.GetFloat(1);
	GLfloat v1 = args.GetFloat(2);
	glUniform2f(location, v0, v1);
	return Value::Null;
}

// opengl.glUniform3f
Gura_DeclareFunction(glUniform3f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v0", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform3f)
{
	GLint location = args.GetInt(0);
	GLfloat v0 = args.GetFloat(1);
	GLfloat v1 = args.GetFloat(2);
	GLfloat v2 = args.GetFloat(3);
	glUniform3f(location, v0, v1, v2);
	return Value::Null;
}

// opengl.glUniform4f
Gura_DeclareFunction(glUniform4f)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v0", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v3", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform4f)
{
	GLint location = args.GetInt(0);
	GLfloat v0 = args.GetFloat(1);
	GLfloat v1 = args.GetFloat(2);
	GLfloat v2 = args.GetFloat(3);
	GLfloat v3 = args.GetFloat(4);
	glUniform4f(location, v0, v1, v2, v3);
	return Value::Null;
}

// opengl.glUniform1i
Gura_DeclareFunction(glUniform1i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v0", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform1i)
{
	GLint location = args.GetInt(0);
	GLint v0 = args.GetInt(1);
	glUniform1i(location, v0);
	return Value::Null;
}

// opengl.glUniform2i
Gura_DeclareFunction(glUniform2i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v0", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform2i)
{
	GLint location = args.GetInt(0);
	GLint v0 = args.GetInt(1);
	GLint v1 = args.GetInt(2);
	glUniform2i(location, v0, v1);
	return Value::Null;
}

// opengl.glUniform3i
Gura_DeclareFunction(glUniform3i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v0", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform3i)
{
	GLint location = args.GetInt(0);
	GLint v0 = args.GetInt(1);
	GLint v1 = args.GetInt(2);
	GLint v2 = args.GetInt(3);
	glUniform3i(location, v0, v1, v2);
	return Value::Null;
}

// opengl.glUniform4i
Gura_DeclareFunction(glUniform4i)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v0", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "v3", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform4i)
{
	GLint location = args.GetInt(0);
	GLint v0 = args.GetInt(1);
	GLint v1 = args.GetInt(2);
	GLint v2 = args.GetInt(3);
	GLint v3 = args.GetInt(4);
	glUniform4i(location, v0, v1, v2, v3);
	return Value::Null;
}

// opengl.glUniform1fv
Gura_DeclareFunction(glUniform1fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform1fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	CArray<GLfloat> value = args.GetList(2);
	glUniform1fv(location, count, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniform1fv");
	return Value::Null;
}

// opengl.glUniform2fv
Gura_DeclareFunction(glUniform2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform2fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	CArray<GLfloat> value = args.GetList(2);
	glUniform2fv(location, count, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniform2fv");
	return Value::Null;
}

// opengl.glUniform3fv
Gura_DeclareFunction(glUniform3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform3fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	CArray<GLfloat> value = args.GetList(2);
	glUniform3fv(location, count, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniform3fv");
	return Value::Null;
}

// opengl.glUniform4fv
Gura_DeclareFunction(glUniform4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform4fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	CArray<GLfloat> value = args.GetList(2);
	glUniform4fv(location, count, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniform4fv");
	return Value::Null;
}

// opengl.glUniform1iv
Gura_DeclareFunction(glUniform1iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform1iv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	CArray<GLint> value = args.GetList(2);
	glUniform1iv(location, count, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniform1iv");
	return Value::Null;
}

// opengl.glUniform2iv
Gura_DeclareFunction(glUniform2iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform2iv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	CArray<GLint> value = args.GetList(2);
	glUniform2iv(location, count, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniform2iv");
	return Value::Null;
}

// opengl.glUniform3iv
Gura_DeclareFunction(glUniform3iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform3iv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	CArray<GLint> value = args.GetList(2);
	glUniform3iv(location, count, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniform3iv");
	return Value::Null;
}

// opengl.glUniform4iv
Gura_DeclareFunction(glUniform4iv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniform4iv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	CArray<GLint> value = args.GetList(2);
	glUniform4iv(location, count, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniform4iv");
	return Value::Null;
}

// opengl.glUniformMatrix2fv
Gura_DeclareFunction(glUniformMatrix2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "transpose", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniformMatrix2fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	GLboolean transpose = (args.GetBoolean(2)? 1 : 0);
	CArray<GLfloat> value = args.GetList(3);
	glUniformMatrix2fv(location, count, transpose, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniformMatrix2fv");
	return Value::Null;
}

// opengl.glUniformMatrix3fv
Gura_DeclareFunction(glUniformMatrix3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "transpose", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniformMatrix3fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	GLboolean transpose = (args.GetBoolean(2)? 1 : 0);
	CArray<GLfloat> value = args.GetList(3);
	glUniformMatrix3fv(location, count, transpose, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniformMatrix3fv");
	return Value::Null;
}

// opengl.glUniformMatrix4fv
Gura_DeclareFunction(glUniformMatrix4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "transpose", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniformMatrix4fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	GLboolean transpose = (args.GetBoolean(2)? 1 : 0);
	CArray<GLfloat> value = args.GetList(3);
	glUniformMatrix4fv(location, count, transpose, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniformMatrix4fv");
	return Value::Null;
}

// opengl.glIsShader
Gura_DeclareFunction(glIsShader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "shader", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIsShader)
{
	GLuint shader = args.GetUInt(0);
	GLboolean _rtn = glIsShader(shader);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// opengl.glIsProgram
Gura_DeclareFunction(glIsProgram)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glIsProgram)
{
	GLuint program = args.GetUInt(0);
	GLboolean _rtn = glIsProgram(program);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// opengl.glGetShaderiv
Gura_DeclareFunction(glGetShaderiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "shader", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetShaderiv)
{
#if 0
	GLuint shader = args.GetUInt(0);
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetShaderiv(shader, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetShaderiv");
	return Value::Null;
}

// opengl.glGetProgramiv
Gura_DeclareFunction(glGetProgramiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetProgramiv)
{
#if 0
	GLuint program = args.GetUInt(0);
	GLenum pname = static_cast<GLenum>(args.GetInt(1));
	CArray<GLint> params = args.GetList(2);
	glGetProgramiv(program, pname, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetProgramiv");
	return Value::Null;
}

// opengl.glGetAttachedShaders
Gura_DeclareFunction(glGetAttachedShaders)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxCount", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "shaders", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetAttachedShaders)
{
#if 0
	GLuint program = args.GetUInt(0);
	GLsizei maxCount = args.GetInt(1);
	CArray<GLsizei> count = args.GetList(2);
	CArray<GLuint> shaders = args.GetList(3);
	glGetAttachedShaders(program, maxCount, count, shaders);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetAttachedShaders");
	return Value::Null;
}

// opengl.glGetShaderInfoLog
Gura_DeclareFunction(glGetShaderInfoLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "shader", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bufSize", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "infoLog", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetShaderInfoLog)
{
#if 0
	GLuint shader = args.GetUInt(0);
	GLsizei bufSize = args.GetInt(1);
	CArray<GLsizei> length = args.GetList(2);
	CArray<GLchar> infoLog = args.GetList(3);
	glGetShaderInfoLog(shader, bufSize, length, infoLog);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetShaderInfoLog");
	return Value::Null;
}

// opengl.glGetProgramInfoLog
Gura_DeclareFunction(glGetProgramInfoLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bufSize", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "infoLog", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetProgramInfoLog)
{
#if 0
	GLuint program = args.GetUInt(0);
	GLsizei bufSize = args.GetInt(1);
	CArray<GLsizei> length = args.GetList(2);
	CArray<GLchar> infoLog = args.GetList(3);
	glGetProgramInfoLog(program, bufSize, length, infoLog);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetProgramInfoLog");
	return Value::Null;
}

// opengl.glGetUniformLocation
Gura_DeclareFunction(glGetUniformLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetUniformLocation)
{
#if 0
	GLuint program = args.GetUInt(0);
	CArray<GLchar> name = args.GetList(1);
	GLint _rtn = glGetUniformLocation(program, name);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "glGetUniformLocation");
	return Value::Null;
}

// opengl.glGetActiveUniform
Gura_DeclareFunction(glGetActiveUniform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bufSize", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetActiveUniform)
{
#if 0
	GLuint program = args.GetUInt(0);
	GLuint index = args.GetUInt(1);
	GLsizei bufSize = args.GetInt(2);
	CArray<GLsizei> length = args.GetList(3);
	CArray<GLint> size = args.GetList(4);
	CArray<GLenum> type = args.GetList(5);
	CArray<GLchar> name = args.GetList(6);
	glGetActiveUniform(program, index, bufSize, length, size, type, name);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetActiveUniform");
	return Value::Null;
}

// opengl.glGetUniformfv
Gura_DeclareFunction(glGetUniformfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetUniformfv)
{
#if 0
	GLuint program = args.GetUInt(0);
	GLint location = args.GetInt(1);
	CArray<GLfloat> params = args.GetList(2);
	glGetUniformfv(program, location, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetUniformfv");
	return Value::Null;
}

// opengl.glGetUniformiv
Gura_DeclareFunction(glGetUniformiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetUniformiv)
{
#if 0
	GLuint program = args.GetUInt(0);
	GLint location = args.GetInt(1);
	CArray<GLint> params = args.GetList(2);
	glGetUniformiv(program, location, params);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetUniformiv");
	return Value::Null;
}

// opengl.glGetShaderSource
Gura_DeclareFunction(glGetShaderSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "shader", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bufSize", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "source", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetShaderSource)
{
#if 0
	GLuint shader = args.GetUInt(0);
	GLsizei bufSize = args.GetInt(1);
	CArray<GLsizei> length = args.GetList(2);
	CArray<GLchar> source = args.GetList(3);
	glGetShaderSource(shader, bufSize, length, source);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetShaderSource");
	return Value::Null;
}

// opengl.glBindAttribLocation
Gura_DeclareFunction(glBindAttribLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glBindAttribLocation)
{
#if 0
	GLuint program = args.GetUInt(0);
	GLuint index = args.GetUInt(1);
	CArray<GLchar> name = args.GetList(2);
	glBindAttribLocation(program, index, name);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glBindAttribLocation");
	return Value::Null;
}

// opengl.glGetActiveAttrib
Gura_DeclareFunction(glGetActiveAttrib)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bufSize", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetActiveAttrib)
{
#if 0
	GLuint program = args.GetUInt(0);
	GLuint index = args.GetUInt(1);
	GLsizei bufSize = args.GetInt(2);
	CArray<GLsizei> length = args.GetList(3);
	CArray<GLint> size = args.GetList(4);
	CArray<GLenum> type = args.GetList(5);
	CArray<GLchar> name = args.GetList(6);
	glGetActiveAttrib(program, index, bufSize, length, size, type, name);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glGetActiveAttrib");
	return Value::Null;
}

// opengl.glGetAttribLocation
Gura_DeclareFunction(glGetAttribLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "program", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glGetAttribLocation)
{
#if 0
	GLuint program = args.GetUInt(0);
	CArray<GLchar> name = args.GetList(1);
	GLint _rtn = glGetAttribLocation(program, name);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "glGetAttribLocation");
	return Value::Null;
}

// opengl.glStencilFuncSeparate
Gura_DeclareFunction(glStencilFuncSeparate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "func", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ref", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glStencilFuncSeparate)
{
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum func = static_cast<GLenum>(args.GetInt(1));
	GLint ref = args.GetInt(2);
	GLuint mask = args.GetUInt(3);
	glStencilFuncSeparate(face, func, ref, mask);
	return Value::Null;
}

// opengl.glStencilOpSeparate
Gura_DeclareFunction(glStencilOpSeparate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "fail", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zfail", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "zpass", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glStencilOpSeparate)
{
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLenum fail = static_cast<GLenum>(args.GetInt(1));
	GLenum zfail = static_cast<GLenum>(args.GetInt(2));
	GLenum zpass = static_cast<GLenum>(args.GetInt(3));
	glStencilOpSeparate(face, fail, zfail, zpass);
	return Value::Null;
}

// opengl.glStencilMaskSeparate
Gura_DeclareFunction(glStencilMaskSeparate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "face", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glStencilMaskSeparate)
{
	GLenum face = static_cast<GLenum>(args.GetInt(0));
	GLuint mask = args.GetUInt(1);
	glStencilMaskSeparate(face, mask);
	return Value::Null;
}

// opengl.glUniformMatrix2x3fv
Gura_DeclareFunction(glUniformMatrix2x3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "transpose", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniformMatrix2x3fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	GLboolean transpose = (args.GetBoolean(2)? 1 : 0);
	CArray<GLfloat> value = args.GetList(3);
	glUniformMatrix2x3fv(location, count, transpose, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniformMatrix2x3fv");
	return Value::Null;
}

// opengl.glUniformMatrix3x2fv
Gura_DeclareFunction(glUniformMatrix3x2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "transpose", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniformMatrix3x2fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	GLboolean transpose = (args.GetBoolean(2)? 1 : 0);
	CArray<GLfloat> value = args.GetList(3);
	glUniformMatrix3x2fv(location, count, transpose, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniformMatrix3x2fv");
	return Value::Null;
}

// opengl.glUniformMatrix2x4fv
Gura_DeclareFunction(glUniformMatrix2x4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "transpose", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniformMatrix2x4fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	GLboolean transpose = (args.GetBoolean(2)? 1 : 0);
	CArray<GLfloat> value = args.GetList(3);
	glUniformMatrix2x4fv(location, count, transpose, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniformMatrix2x4fv");
	return Value::Null;
}

// opengl.glUniformMatrix4x2fv
Gura_DeclareFunction(glUniformMatrix4x2fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "transpose", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniformMatrix4x2fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	GLboolean transpose = (args.GetBoolean(2)? 1 : 0);
	CArray<GLfloat> value = args.GetList(3);
	glUniformMatrix4x2fv(location, count, transpose, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniformMatrix4x2fv");
	return Value::Null;
}

// opengl.glUniformMatrix3x4fv
Gura_DeclareFunction(glUniformMatrix3x4fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "transpose", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniformMatrix3x4fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	GLboolean transpose = (args.GetBoolean(2)? 1 : 0);
	CArray<GLfloat> value = args.GetList(3);
	glUniformMatrix3x4fv(location, count, transpose, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniformMatrix3x4fv");
	return Value::Null;
}

// opengl.glUniformMatrix4x3fv
Gura_DeclareFunction(glUniformMatrix4x3fv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "location", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "transpose", VTYPE_boolean, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(glUniformMatrix4x3fv)
{
#if 0
	GLint location = args.GetInt(0);
	GLsizei count = args.GetInt(1);
	GLboolean transpose = (args.GetBoolean(2)? 1 : 0);
	CArray<GLfloat> value = args.GetList(3);
	glUniformMatrix4x3fv(location, count, transpose, value);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "glUniformMatrix4x3fv");
	return Value::Null;
}


void AssignFunctions(Environment &env)
{
	Gura_AssignFunction(glAccum);
	Gura_AssignFunction(glAlphaFunc);
	Gura_AssignFunction(glAreTexturesResident);
	Gura_AssignFunction(glArrayElement);
	Gura_AssignFunction(glBegin);
	Gura_AssignFunction(glBindTexture);
	Gura_AssignFunction(glBitmap);
	Gura_AssignFunction(glBlendColor);
	Gura_AssignFunction(glBlendEquation);
	Gura_AssignFunction(glBlendEquationSeparate);
	Gura_AssignFunction(glBlendFunc);
	Gura_AssignFunction(glCallList);
	Gura_AssignFunction(glCallLists);
	Gura_AssignFunction(glClear);
	Gura_AssignFunction(glClearAccum);
	Gura_AssignFunction(glClearColor);
	Gura_AssignFunction(glClearDepth);
	Gura_AssignFunction(glClearIndex);
	Gura_AssignFunction(glClearStencil);
	Gura_AssignFunction(glClipPlane);
	Gura_AssignFunction(glColor3b);
	Gura_AssignFunction(glColor3bv);
	Gura_AssignFunction(glColor3d);
	Gura_AssignFunction(glColor3dv);
	Gura_AssignFunction(glColor3f);
	Gura_AssignFunction(glColor3fv);
	Gura_AssignFunction(glColor3i);
	Gura_AssignFunction(glColor3iv);
	Gura_AssignFunction(glColor3s);
	Gura_AssignFunction(glColor3sv);
	Gura_AssignFunction(glColor3ub);
	Gura_AssignFunction(glColor3ubv);
	Gura_AssignFunction(glColor3ui);
	Gura_AssignFunction(glColor3uiv);
	Gura_AssignFunction(glColor3us);
	Gura_AssignFunction(glColor3usv);
	Gura_AssignFunction(glColor4b);
	Gura_AssignFunction(glColor4bv);
	Gura_AssignFunction(glColor4d);
	Gura_AssignFunction(glColor4dv);
	Gura_AssignFunction(glColor4f);
	Gura_AssignFunction(glColor4fv);
	Gura_AssignFunction(glColor4i);
	Gura_AssignFunction(glColor4iv);
	Gura_AssignFunction(glColor4s);
	Gura_AssignFunction(glColor4sv);
	Gura_AssignFunction(glColor4ub);
	Gura_AssignFunction(glColor4ubv);
	Gura_AssignFunction(glColor4ui);
	Gura_AssignFunction(glColor4uiv);
	Gura_AssignFunction(glColor4us);
	Gura_AssignFunction(glColor4usv);
	Gura_AssignFunction(glColorMask);
	Gura_AssignFunction(glColorMaterial);
	Gura_AssignFunction(glColorTableParameterfv);
	Gura_AssignFunction(glColorTableParameteriv);
	Gura_AssignFunction(glConvolutionParameterf);
	Gura_AssignFunction(glConvolutionParameterfv);
	Gura_AssignFunction(glConvolutionParameteri);
	Gura_AssignFunction(glConvolutionParameteriv);
	Gura_AssignFunction(glCopyColorSubTable);
	Gura_AssignFunction(glCopyColorTable);
	Gura_AssignFunction(glCopyConvolutionFilter1D);
	Gura_AssignFunction(glCopyConvolutionFilter2D);
	Gura_AssignFunction(glCopyPixels);
	Gura_AssignFunction(glCopyTexImage1D);
	Gura_AssignFunction(glCopyTexImage2D);
	Gura_AssignFunction(glCopyTexSubImage1D);
	Gura_AssignFunction(glCopyTexSubImage2D);
	Gura_AssignFunction(glCopyTexSubImage3D);
	Gura_AssignFunction(glCullFace);
	Gura_AssignFunction(glDeleteLists);
	Gura_AssignFunction(glDeleteTextures);
	Gura_AssignFunction(glDepthFunc);
	Gura_AssignFunction(glDepthMask);
	Gura_AssignFunction(glDepthRange);
	Gura_AssignFunction(glDisable);
	Gura_AssignFunction(glDisableClientState);
	Gura_AssignFunction(glDrawArrays);
	Gura_AssignFunction(glDrawBuffer);
	Gura_AssignFunction(glEdgeFlag);
	Gura_AssignFunction(glEdgeFlagv);
	Gura_AssignFunction(glEnable);
	Gura_AssignFunction(glEnableClientState);
	Gura_AssignFunction(glEnd);
	Gura_AssignFunction(glEndList);
	Gura_AssignFunction(glEvalCoord1d);
	Gura_AssignFunction(glEvalCoord1dv);
	Gura_AssignFunction(glEvalCoord1f);
	Gura_AssignFunction(glEvalCoord1fv);
	Gura_AssignFunction(glEvalCoord2d);
	Gura_AssignFunction(glEvalCoord2dv);
	Gura_AssignFunction(glEvalCoord2f);
	Gura_AssignFunction(glEvalCoord2fv);
	Gura_AssignFunction(glEvalMesh1);
	Gura_AssignFunction(glEvalMesh2);
	Gura_AssignFunction(glEvalPoint1);
	Gura_AssignFunction(glEvalPoint2);
	Gura_AssignFunction(glFeedbackBuffer);
	Gura_AssignFunction(glFinish);
	Gura_AssignFunction(glFlush);
	Gura_AssignFunction(glFogf);
	Gura_AssignFunction(glFogfv);
	Gura_AssignFunction(glFogi);
	Gura_AssignFunction(glFogiv);
	Gura_AssignFunction(glFrontFace);
	Gura_AssignFunction(glFrustum);
	Gura_AssignFunction(glGenLists);
	Gura_AssignFunction(glGenTextures);
	Gura_AssignFunction(glGetBooleanv);
	Gura_AssignFunction(glGetClipPlane);
	Gura_AssignFunction(glGetColorTableParameterfv);
	Gura_AssignFunction(glGetColorTableParameteriv);
	Gura_AssignFunction(glGetConvolutionParameterfv);
	Gura_AssignFunction(glGetConvolutionParameteriv);
	Gura_AssignFunction(glGetDoublev);
	Gura_AssignFunction(glGetError);
	Gura_AssignFunction(glGetFloatv);
	Gura_AssignFunction(glGetHistogramParameterfv);
	Gura_AssignFunction(glGetHistogramParameteriv);
	Gura_AssignFunction(glGetIntegerv);
	Gura_AssignFunction(glGetLightfv);
	Gura_AssignFunction(glGetLightiv);
	Gura_AssignFunction(glGetMapdv);
	Gura_AssignFunction(glGetMapfv);
	Gura_AssignFunction(glGetMapiv);
	Gura_AssignFunction(glGetMaterialfv);
	Gura_AssignFunction(glGetMaterialiv);
	Gura_AssignFunction(glGetMinmaxParameterfv);
	Gura_AssignFunction(glGetMinmaxParameteriv);
	Gura_AssignFunction(glGetPixelMapfv);
	Gura_AssignFunction(glGetPixelMapuiv);
	Gura_AssignFunction(glGetPixelMapusv);
	Gura_AssignFunction(glGetPolygonStipple);
	Gura_AssignFunction(glGetString);
	Gura_AssignFunction(glGetTexEnvfv);
	Gura_AssignFunction(glGetTexEnviv);
	Gura_AssignFunction(glGetTexGendv);
	Gura_AssignFunction(glGetTexGenfv);
	Gura_AssignFunction(glGetTexGeniv);
	Gura_AssignFunction(glGetTexLevelParameterfv);
	Gura_AssignFunction(glGetTexLevelParameteriv);
	Gura_AssignFunction(glGetTexParameterfv);
	Gura_AssignFunction(glGetTexParameteriv);
	Gura_AssignFunction(glHint);
	Gura_AssignFunction(glHistogram);
	Gura_AssignFunction(glIndexMask);
	Gura_AssignFunction(glIndexd);
	Gura_AssignFunction(glIndexdv);
	Gura_AssignFunction(glIndexf);
	Gura_AssignFunction(glIndexfv);
	Gura_AssignFunction(glIndexi);
	Gura_AssignFunction(glIndexiv);
	Gura_AssignFunction(glIndexs);
	Gura_AssignFunction(glIndexsv);
	Gura_AssignFunction(glIndexub);
	Gura_AssignFunction(glIndexubv);
	Gura_AssignFunction(glInitNames);
	Gura_AssignFunction(glIsEnabled);
	Gura_AssignFunction(glIsList);
	Gura_AssignFunction(glIsTexture);
	Gura_AssignFunction(glLightModelf);
	Gura_AssignFunction(glLightModelfv);
	Gura_AssignFunction(glLightModeli);
	Gura_AssignFunction(glLightModeliv);
	Gura_AssignFunction(glLightf);
	Gura_AssignFunction(glLightfv);
	Gura_AssignFunction(glLighti);
	Gura_AssignFunction(glLightiv);
	Gura_AssignFunction(glLineStipple);
	Gura_AssignFunction(glLineWidth);
	Gura_AssignFunction(glListBase);
	Gura_AssignFunction(glLoadIdentity);
	Gura_AssignFunction(glLoadMatrixd);
	Gura_AssignFunction(glLoadMatrixf);
	Gura_AssignFunction(glLoadName);
	Gura_AssignFunction(glLogicOp);
	Gura_AssignFunction(glMap1d);
	Gura_AssignFunction(glMap1f);
	Gura_AssignFunction(glMap2d);
	Gura_AssignFunction(glMap2f);
	Gura_AssignFunction(glMapGrid1d);
	Gura_AssignFunction(glMapGrid1f);
	Gura_AssignFunction(glMapGrid2d);
	Gura_AssignFunction(glMapGrid2f);
	Gura_AssignFunction(glMaterialf);
	Gura_AssignFunction(glMaterialfv);
	Gura_AssignFunction(glMateriali);
	Gura_AssignFunction(glMaterialiv);
	Gura_AssignFunction(glMatrixMode);
	Gura_AssignFunction(glMinmax);
	Gura_AssignFunction(glMultMatrixd);
	Gura_AssignFunction(glMultMatrixf);
	Gura_AssignFunction(glNewList);
	Gura_AssignFunction(glNormal3b);
	Gura_AssignFunction(glNormal3bv);
	Gura_AssignFunction(glNormal3d);
	Gura_AssignFunction(glNormal3dv);
	Gura_AssignFunction(glNormal3f);
	Gura_AssignFunction(glNormal3fv);
	Gura_AssignFunction(glNormal3i);
	Gura_AssignFunction(glNormal3iv);
	Gura_AssignFunction(glNormal3s);
	Gura_AssignFunction(glNormal3sv);
	Gura_AssignFunction(glOrtho);
	Gura_AssignFunction(glPassThrough);
	Gura_AssignFunction(glPixelMapfv);
	Gura_AssignFunction(glPixelMapuiv);
	Gura_AssignFunction(glPixelMapusv);
	Gura_AssignFunction(glPixelStoref);
	Gura_AssignFunction(glPixelStorei);
	Gura_AssignFunction(glPixelTransferf);
	Gura_AssignFunction(glPixelTransferi);
	Gura_AssignFunction(glPixelZoom);
	Gura_AssignFunction(glPointSize);
	Gura_AssignFunction(glPolygonMode);
	Gura_AssignFunction(glPolygonOffset);
	Gura_AssignFunction(glPolygonStipple);
	Gura_AssignFunction(glPopAttrib);
	Gura_AssignFunction(glPopClientAttrib);
	Gura_AssignFunction(glPopMatrix);
	Gura_AssignFunction(glPopName);
	Gura_AssignFunction(glPrioritizeTextures);
	Gura_AssignFunction(glPushAttrib);
	Gura_AssignFunction(glPushClientAttrib);
	Gura_AssignFunction(glPushMatrix);
	Gura_AssignFunction(glPushName);
	Gura_AssignFunction(glRasterPos2d);
	Gura_AssignFunction(glRasterPos2dv);
	Gura_AssignFunction(glRasterPos2f);
	Gura_AssignFunction(glRasterPos2fv);
	Gura_AssignFunction(glRasterPos2i);
	Gura_AssignFunction(glRasterPos2iv);
	Gura_AssignFunction(glRasterPos2s);
	Gura_AssignFunction(glRasterPos2sv);
	Gura_AssignFunction(glRasterPos3d);
	Gura_AssignFunction(glRasterPos3dv);
	Gura_AssignFunction(glRasterPos3f);
	Gura_AssignFunction(glRasterPos3fv);
	Gura_AssignFunction(glRasterPos3i);
	Gura_AssignFunction(glRasterPos3iv);
	Gura_AssignFunction(glRasterPos3s);
	Gura_AssignFunction(glRasterPos3sv);
	Gura_AssignFunction(glRasterPos4d);
	Gura_AssignFunction(glRasterPos4dv);
	Gura_AssignFunction(glRasterPos4f);
	Gura_AssignFunction(glRasterPos4fv);
	Gura_AssignFunction(glRasterPos4i);
	Gura_AssignFunction(glRasterPos4iv);
	Gura_AssignFunction(glRasterPos4s);
	Gura_AssignFunction(glRasterPos4sv);
	Gura_AssignFunction(glReadBuffer);
	Gura_AssignFunction(glRectd);
	Gura_AssignFunction(glRectdv);
	Gura_AssignFunction(glRectf);
	Gura_AssignFunction(glRectfv);
	Gura_AssignFunction(glRecti);
	Gura_AssignFunction(glRectiv);
	Gura_AssignFunction(glRects);
	Gura_AssignFunction(glRectsv);
	Gura_AssignFunction(glRenderMode);
	Gura_AssignFunction(glResetHistogram);
	Gura_AssignFunction(glResetMinmax);
	Gura_AssignFunction(glRotated);
	Gura_AssignFunction(glRotatef);
	Gura_AssignFunction(glScaled);
	Gura_AssignFunction(glScalef);
	Gura_AssignFunction(glScissor);
	Gura_AssignFunction(glSelectBuffer);
	Gura_AssignFunction(glShadeModel);
	Gura_AssignFunction(glStencilFunc);
	Gura_AssignFunction(glStencilMask);
	Gura_AssignFunction(glStencilOp);
	Gura_AssignFunction(glTexCoord1d);
	Gura_AssignFunction(glTexCoord1dv);
	Gura_AssignFunction(glTexCoord1f);
	Gura_AssignFunction(glTexCoord1fv);
	Gura_AssignFunction(glTexCoord1i);
	Gura_AssignFunction(glTexCoord1iv);
	Gura_AssignFunction(glTexCoord1s);
	Gura_AssignFunction(glTexCoord1sv);
	Gura_AssignFunction(glTexCoord2d);
	Gura_AssignFunction(glTexCoord2dv);
	Gura_AssignFunction(glTexCoord2f);
	Gura_AssignFunction(glTexCoord2fv);
	Gura_AssignFunction(glTexCoord2i);
	Gura_AssignFunction(glTexCoord2iv);
	Gura_AssignFunction(glTexCoord2s);
	Gura_AssignFunction(glTexCoord2sv);
	Gura_AssignFunction(glTexCoord3d);
	Gura_AssignFunction(glTexCoord3dv);
	Gura_AssignFunction(glTexCoord3f);
	Gura_AssignFunction(glTexCoord3fv);
	Gura_AssignFunction(glTexCoord3i);
	Gura_AssignFunction(glTexCoord3iv);
	Gura_AssignFunction(glTexCoord3s);
	Gura_AssignFunction(glTexCoord3sv);
	Gura_AssignFunction(glTexCoord4d);
	Gura_AssignFunction(glTexCoord4dv);
	Gura_AssignFunction(glTexCoord4f);
	Gura_AssignFunction(glTexCoord4fv);
	Gura_AssignFunction(glTexCoord4i);
	Gura_AssignFunction(glTexCoord4iv);
	Gura_AssignFunction(glTexCoord4s);
	Gura_AssignFunction(glTexCoord4sv);
	Gura_AssignFunction(glTexEnvf);
	Gura_AssignFunction(glTexEnvfv);
	Gura_AssignFunction(glTexEnvi);
	Gura_AssignFunction(glTexEnviv);
	Gura_AssignFunction(glTexGend);
	Gura_AssignFunction(glTexGendv);
	Gura_AssignFunction(glTexGenf);
	Gura_AssignFunction(glTexGenfv);
	Gura_AssignFunction(glTexGeni);
	Gura_AssignFunction(glTexGeniv);
	Gura_AssignFunction(glTexParameterf);
	Gura_AssignFunction(glTexParameterfv);
	Gura_AssignFunction(glTexParameteri);
	Gura_AssignFunction(glTexParameteriv);
	Gura_AssignFunction(glTranslated);
	Gura_AssignFunction(glTranslatef);
	Gura_AssignFunction(glVertex2d);
	Gura_AssignFunction(glVertex2dv);
	Gura_AssignFunction(glVertex2f);
	Gura_AssignFunction(glVertex2fv);
	Gura_AssignFunction(glVertex2i);
	Gura_AssignFunction(glVertex2iv);
	Gura_AssignFunction(glVertex2s);
	Gura_AssignFunction(glVertex2sv);
	Gura_AssignFunction(glVertex3d);
	Gura_AssignFunction(glVertex3dv);
	Gura_AssignFunction(glVertex3f);
	Gura_AssignFunction(glVertex3fv);
	Gura_AssignFunction(glVertex3i);
	Gura_AssignFunction(glVertex3iv);
	Gura_AssignFunction(glVertex3s);
	Gura_AssignFunction(glVertex3sv);
	Gura_AssignFunction(glVertex4d);
	Gura_AssignFunction(glVertex4dv);
	Gura_AssignFunction(glVertex4f);
	Gura_AssignFunction(glVertex4fv);
	Gura_AssignFunction(glVertex4i);
	Gura_AssignFunction(glVertex4iv);
	Gura_AssignFunction(glVertex4s);
	Gura_AssignFunction(glVertex4sv);
	Gura_AssignFunction(glViewport);
	Gura_AssignFunction(glSampleCoverage);
	Gura_AssignFunction(glLoadTransposeMatrixf);
	Gura_AssignFunction(glLoadTransposeMatrixd);
	Gura_AssignFunction(glMultTransposeMatrixf);
	Gura_AssignFunction(glMultTransposeMatrixd);
	Gura_AssignFunction(glActiveTexture);
	Gura_AssignFunction(glClientActiveTexture);
	Gura_AssignFunction(glMultiTexCoord1d);
	Gura_AssignFunction(glMultiTexCoord1dv);
	Gura_AssignFunction(glMultiTexCoord1f);
	Gura_AssignFunction(glMultiTexCoord1fv);
	Gura_AssignFunction(glMultiTexCoord1i);
	Gura_AssignFunction(glMultiTexCoord1iv);
	Gura_AssignFunction(glMultiTexCoord1s);
	Gura_AssignFunction(glMultiTexCoord1sv);
	Gura_AssignFunction(glMultiTexCoord2d);
	Gura_AssignFunction(glMultiTexCoord2dv);
	Gura_AssignFunction(glMultiTexCoord2f);
	Gura_AssignFunction(glMultiTexCoord2fv);
	Gura_AssignFunction(glMultiTexCoord2i);
	Gura_AssignFunction(glMultiTexCoord2iv);
	Gura_AssignFunction(glMultiTexCoord2s);
	Gura_AssignFunction(glMultiTexCoord2sv);
	Gura_AssignFunction(glMultiTexCoord3d);
	Gura_AssignFunction(glMultiTexCoord3dv);
	Gura_AssignFunction(glMultiTexCoord3f);
	Gura_AssignFunction(glMultiTexCoord3fv);
	Gura_AssignFunction(glMultiTexCoord3i);
	Gura_AssignFunction(glMultiTexCoord3iv);
	Gura_AssignFunction(glMultiTexCoord3s);
	Gura_AssignFunction(glMultiTexCoord3sv);
	Gura_AssignFunction(glMultiTexCoord4d);
	Gura_AssignFunction(glMultiTexCoord4dv);
	Gura_AssignFunction(glMultiTexCoord4f);
	Gura_AssignFunction(glMultiTexCoord4fv);
	Gura_AssignFunction(glMultiTexCoord4i);
	Gura_AssignFunction(glMultiTexCoord4iv);
	Gura_AssignFunction(glMultiTexCoord4s);
	Gura_AssignFunction(glMultiTexCoord4sv);
	Gura_AssignFunction(glFogCoordf);
	Gura_AssignFunction(glFogCoordfv);
	Gura_AssignFunction(glFogCoordd);
	Gura_AssignFunction(glFogCoorddv);
	Gura_AssignFunction(glSecondaryColor3b);
	Gura_AssignFunction(glSecondaryColor3bv);
	Gura_AssignFunction(glSecondaryColor3d);
	Gura_AssignFunction(glSecondaryColor3dv);
	Gura_AssignFunction(glSecondaryColor3f);
	Gura_AssignFunction(glSecondaryColor3fv);
	Gura_AssignFunction(glSecondaryColor3i);
	Gura_AssignFunction(glSecondaryColor3iv);
	Gura_AssignFunction(glSecondaryColor3s);
	Gura_AssignFunction(glSecondaryColor3sv);
	Gura_AssignFunction(glSecondaryColor3ub);
	Gura_AssignFunction(glSecondaryColor3ubv);
	Gura_AssignFunction(glSecondaryColor3ui);
	Gura_AssignFunction(glSecondaryColor3uiv);
	Gura_AssignFunction(glSecondaryColor3us);
	Gura_AssignFunction(glSecondaryColor3usv);
	Gura_AssignFunction(glPointParameterf);
	Gura_AssignFunction(glPointParameterfv);
	Gura_AssignFunction(glPointParameteri);
	Gura_AssignFunction(glPointParameteriv);
	Gura_AssignFunction(glBlendFuncSeparate);
	Gura_AssignFunction(glMultiDrawArrays);
	Gura_AssignFunction(glWindowPos2d);
	Gura_AssignFunction(glWindowPos2dv);
	Gura_AssignFunction(glWindowPos2f);
	Gura_AssignFunction(glWindowPos2fv);
	Gura_AssignFunction(glWindowPos2i);
	Gura_AssignFunction(glWindowPos2iv);
	Gura_AssignFunction(glWindowPos2s);
	Gura_AssignFunction(glWindowPos2sv);
	Gura_AssignFunction(glWindowPos3d);
	Gura_AssignFunction(glWindowPos3dv);
	Gura_AssignFunction(glWindowPos3f);
	Gura_AssignFunction(glWindowPos3fv);
	Gura_AssignFunction(glWindowPos3i);
	Gura_AssignFunction(glWindowPos3iv);
	Gura_AssignFunction(glWindowPos3s);
	Gura_AssignFunction(glWindowPos3sv);
	Gura_AssignFunction(glGenQueries);
	Gura_AssignFunction(glDeleteQueries);
	Gura_AssignFunction(glIsQuery);
	Gura_AssignFunction(glBeginQuery);
	Gura_AssignFunction(glEndQuery);
	Gura_AssignFunction(glGetQueryiv);
	Gura_AssignFunction(glGetQueryObjectiv);
	Gura_AssignFunction(glGetQueryObjectuiv);
	Gura_AssignFunction(glBindBuffer);
	Gura_AssignFunction(glDeleteBuffers);
	Gura_AssignFunction(glGenBuffers);
	Gura_AssignFunction(glIsBuffer);
	Gura_AssignFunction(glUnmapBuffer);
	Gura_AssignFunction(glGetBufferParameteriv);
	Gura_AssignFunction(glDrawBuffers);
	Gura_AssignFunction(glVertexAttrib1d);
	Gura_AssignFunction(glVertexAttrib1dv);
	Gura_AssignFunction(glVertexAttrib1f);
	Gura_AssignFunction(glVertexAttrib1fv);
	Gura_AssignFunction(glVertexAttrib1s);
	Gura_AssignFunction(glVertexAttrib1sv);
	Gura_AssignFunction(glVertexAttrib2d);
	Gura_AssignFunction(glVertexAttrib2dv);
	Gura_AssignFunction(glVertexAttrib2f);
	Gura_AssignFunction(glVertexAttrib2fv);
	Gura_AssignFunction(glVertexAttrib2s);
	Gura_AssignFunction(glVertexAttrib2sv);
	Gura_AssignFunction(glVertexAttrib3d);
	Gura_AssignFunction(glVertexAttrib3dv);
	Gura_AssignFunction(glVertexAttrib3f);
	Gura_AssignFunction(glVertexAttrib3fv);
	Gura_AssignFunction(glVertexAttrib3s);
	Gura_AssignFunction(glVertexAttrib3sv);
	Gura_AssignFunction(glVertexAttrib4Nbv);
	Gura_AssignFunction(glVertexAttrib4Niv);
	Gura_AssignFunction(glVertexAttrib4Nsv);
	Gura_AssignFunction(glVertexAttrib4Nub);
	Gura_AssignFunction(glVertexAttrib4Nubv);
	Gura_AssignFunction(glVertexAttrib4Nuiv);
	Gura_AssignFunction(glVertexAttrib4Nusv);
	Gura_AssignFunction(glVertexAttrib4bv);
	Gura_AssignFunction(glVertexAttrib4d);
	Gura_AssignFunction(glVertexAttrib4dv);
	Gura_AssignFunction(glVertexAttrib4f);
	Gura_AssignFunction(glVertexAttrib4fv);
	Gura_AssignFunction(glVertexAttrib4iv);
	Gura_AssignFunction(glVertexAttrib4s);
	Gura_AssignFunction(glVertexAttrib4sv);
	Gura_AssignFunction(glVertexAttrib4ubv);
	Gura_AssignFunction(glVertexAttrib4uiv);
	Gura_AssignFunction(glVertexAttrib4usv);
	Gura_AssignFunction(glEnableVertexAttribArray);
	Gura_AssignFunction(glDisableVertexAttribArray);
	Gura_AssignFunction(glGetVertexAttribdv);
	Gura_AssignFunction(glGetVertexAttribfv);
	Gura_AssignFunction(glGetVertexAttribiv);
	Gura_AssignFunction(glDeleteShader);
	Gura_AssignFunction(glDetachShader);
	Gura_AssignFunction(glCreateShader);
	Gura_AssignFunction(glShaderSource);
	Gura_AssignFunction(glCompileShader);
	Gura_AssignFunction(glCreateProgram);
	Gura_AssignFunction(glAttachShader);
	Gura_AssignFunction(glLinkProgram);
	Gura_AssignFunction(glUseProgram);
	Gura_AssignFunction(glDeleteProgram);
	Gura_AssignFunction(glValidateProgram);
	Gura_AssignFunction(glUniform1f);
	Gura_AssignFunction(glUniform2f);
	Gura_AssignFunction(glUniform3f);
	Gura_AssignFunction(glUniform4f);
	Gura_AssignFunction(glUniform1i);
	Gura_AssignFunction(glUniform2i);
	Gura_AssignFunction(glUniform3i);
	Gura_AssignFunction(glUniform4i);
	Gura_AssignFunction(glUniform1fv);
	Gura_AssignFunction(glUniform2fv);
	Gura_AssignFunction(glUniform3fv);
	Gura_AssignFunction(glUniform4fv);
	Gura_AssignFunction(glUniform1iv);
	Gura_AssignFunction(glUniform2iv);
	Gura_AssignFunction(glUniform3iv);
	Gura_AssignFunction(glUniform4iv);
	Gura_AssignFunction(glUniformMatrix2fv);
	Gura_AssignFunction(glUniformMatrix3fv);
	Gura_AssignFunction(glUniformMatrix4fv);
	Gura_AssignFunction(glIsShader);
	Gura_AssignFunction(glIsProgram);
	Gura_AssignFunction(glGetShaderiv);
	Gura_AssignFunction(glGetProgramiv);
	Gura_AssignFunction(glGetAttachedShaders);
	Gura_AssignFunction(glGetShaderInfoLog);
	Gura_AssignFunction(glGetProgramInfoLog);
	Gura_AssignFunction(glGetUniformLocation);
	Gura_AssignFunction(glGetActiveUniform);
	Gura_AssignFunction(glGetUniformfv);
	Gura_AssignFunction(glGetUniformiv);
	Gura_AssignFunction(glGetShaderSource);
	Gura_AssignFunction(glBindAttribLocation);
	Gura_AssignFunction(glGetActiveAttrib);
	Gura_AssignFunction(glGetAttribLocation);
	Gura_AssignFunction(glStencilFuncSeparate);
	Gura_AssignFunction(glStencilOpSeparate);
	Gura_AssignFunction(glStencilMaskSeparate);
	Gura_AssignFunction(glUniformMatrix2x3fv);
	Gura_AssignFunction(glUniformMatrix3x2fv);
	Gura_AssignFunction(glUniformMatrix2x4fv);
	Gura_AssignFunction(glUniformMatrix4x2fv);
	Gura_AssignFunction(glUniformMatrix3x4fv);
	Gura_AssignFunction(glUniformMatrix4x3fv);
}

Gura_EndModuleScope(opengl)
