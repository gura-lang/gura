
// opengl.glAccum(op:number, value:number):void:map
Gura_DeclareFunction(glAccum)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "op", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
}

Gura_ImplementFunction(glAccum)
{
	GLenum op = args.GetUInt(0);
	GLfloat value = args.GetFloat(1);
	// GLenum op, GLfloat value
	::glAccum(op, value);
	return Value::Null;
}

// opengl.glAlphaFunc(func:number, ref:number):void:map
Gura_DeclareFunction(glAlphaFunc)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "func", VTYPE_number);
	DeclareArg(env, "ref", VTYPE_number);
}

Gura_ImplementFunction(glAlphaFunc)
{
	GLenum func = args.GetUInt(0);
	GLclampf ref = args.GetFloat(1);
	// GLenum func, GLclampf ref
	::glAlphaFunc(func, ref);
	return Value::Null;
}

// opengl.glArrayElement(i:number):void:map
Gura_DeclareFunction(glArrayElement)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number);
}

Gura_ImplementFunction(glArrayElement)
{
	GLint i = args.GetInt(0);
	// GLint i
	::glArrayElement(i);
	return Value::Null;
}

// opengl.glBindTexture(target:number, texture:number):void:map
Gura_DeclareFunction(glBindTexture)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "texture", VTYPE_number);
}

Gura_ImplementFunction(glBindTexture)
{
	GLenum target = args.GetUInt(0);
	GLuint texture = args.GetUInt(1);
	// GLenum target, GLuint texture
	::glBindTexture(target, texture);
	return Value::Null;
}

// opengl.glBlendFunc(sfactor:number, dfactor:number):void:map
Gura_DeclareFunction(glBlendFunc)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sfactor", VTYPE_number);
	DeclareArg(env, "dfactor", VTYPE_number);
}

Gura_ImplementFunction(glBlendFunc)
{
	GLenum sfactor = args.GetUInt(0);
	GLenum dfactor = args.GetUInt(1);
	// GLenum sfactor, GLenum dfactor
	::glBlendFunc(sfactor, dfactor);
	return Value::Null;
}

// opengl.glCallList(list:number):void:map
Gura_DeclareFunction(glCallList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "list", VTYPE_number);
}

Gura_ImplementFunction(glCallList)
{
	GLuint list = args.GetUInt(0);
	// GLuint list
	::glCallList(list);
	return Value::Null;
}

// opengl.glClear(mask:number):void:map
Gura_DeclareFunction(glClear)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_number);
}

Gura_ImplementFunction(glClear)
{
	GLbitfield mask = args.GetUInt(0);
	// GLbitfield mask
	::glClear(mask);
	return Value::Null;
}

// opengl.glClearAccum(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glClearAccum)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glClearAccum)
{
	GLfloat red = args.GetFloat(0);
	GLfloat green = args.GetFloat(1);
	GLfloat blue = args.GetFloat(2);
	GLfloat alpha = args.GetFloat(3);
	// GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha
	::glClearAccum(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glClearColor(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glClearColor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glClearColor)
{
	GLclampf red = args.GetFloat(0);
	GLclampf green = args.GetFloat(1);
	GLclampf blue = args.GetFloat(2);
	GLclampf alpha = args.GetFloat(3);
	// GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha
	::glClearColor(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glClearDepth(depth:number):void:map
Gura_DeclareFunction(glClearDepth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "depth", VTYPE_number);
}

Gura_ImplementFunction(glClearDepth)
{
	GLclampd depth = args.GetDouble(0);
	// GLclampd depth
	::glClearDepth(depth);
	return Value::Null;
}

// opengl.glClearIndex(c:number):void:map
Gura_DeclareFunction(glClearIndex)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number);
}

Gura_ImplementFunction(glClearIndex)
{
	GLfloat c = args.GetFloat(0);
	// GLfloat c
	::glClearIndex(c);
	return Value::Null;
}

// opengl.glClearStencil(s:number):void:map
Gura_DeclareFunction(glClearStencil)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
}

Gura_ImplementFunction(glClearStencil)
{
	GLint s = args.GetInt(0);
	// GLint s
	::glClearStencil(s);
	return Value::Null;
}

// opengl.glClipPlane(plane:number, equation[]:number):void:map
Gura_DeclareFunction(glClipPlane)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "plane", VTYPE_number);
	DeclareArg(env, "equation", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glClipPlane)
{
	GLenum plane = args.GetUInt(0);
	DeclareNewArray(GLdouble, equation, 1);
	// GLenum plane, const GLdouble *equation
	::glClipPlane(plane, equation);
	delete[] equation;
	return Value::Null;
}

// opengl.glColor3b(red:number, green:number, blue:number):void:map
Gura_DeclareFunction(glColor3b)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementFunction(glColor3b)
{
	GLbyte red = args.GetChar(0);
	GLbyte green = args.GetChar(1);
	GLbyte blue = args.GetChar(2);
	// GLbyte red, GLbyte green, GLbyte blue
	::glColor3b(red, green, blue);
	return Value::Null;
}

// opengl.glColor3bv(v[]:number):void:map
Gura_DeclareFunction(glColor3bv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor3bv)
{
	DeclareArray(GLbyte, v, 3, 0);
	// const GLbyte *v
	::glColor3bv(v);
	return Value::Null;
}

// opengl.glColor3d(red:number, green:number, blue:number):void:map
Gura_DeclareFunction(glColor3d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementFunction(glColor3d)
{
	GLdouble red = args.GetDouble(0);
	GLdouble green = args.GetDouble(1);
	GLdouble blue = args.GetDouble(2);
	// GLdouble red, GLdouble green, GLdouble blue
	::glColor3d(red, green, blue);
	return Value::Null;
}

// opengl.glColor3dv(v[]:number):void:map
Gura_DeclareFunction(glColor3dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor3dv)
{
	DeclareArray(GLdouble, v, 3, 0);
	// const GLdouble *v
	::glColor3dv(v);
	return Value::Null;
}

// opengl.glColor3f(red:number, green:number, blue:number):void:map
Gura_DeclareFunction(glColor3f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementFunction(glColor3f)
{
	GLfloat red = args.GetFloat(0);
	GLfloat green = args.GetFloat(1);
	GLfloat blue = args.GetFloat(2);
	// GLfloat red, GLfloat green, GLfloat blue
	::glColor3f(red, green, blue);
	return Value::Null;
}

// opengl.glColor3fv(v[]:number):void:map
Gura_DeclareFunction(glColor3fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor3fv)
{
	DeclareArray(GLfloat, v, 3, 0);
	// const GLfloat *v
	::glColor3fv(v);
	return Value::Null;
}

// opengl.glColor3i(red:number, green:number, blue:number):void:map
Gura_DeclareFunction(glColor3i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementFunction(glColor3i)
{
	GLint red = args.GetInt(0);
	GLint green = args.GetInt(1);
	GLint blue = args.GetInt(2);
	// GLint red, GLint green, GLint blue
	::glColor3i(red, green, blue);
	return Value::Null;
}

// opengl.glColor3iv(v[]:number):void:map
Gura_DeclareFunction(glColor3iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor3iv)
{
	DeclareArray(GLint, v, 3, 0);
	// const GLint *v
	::glColor3iv(v);
	return Value::Null;
}

// opengl.glColor3s(red:number, green:number, blue:number):void:map
Gura_DeclareFunction(glColor3s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementFunction(glColor3s)
{
	GLshort red = args.GetShort(0);
	GLshort green = args.GetShort(1);
	GLshort blue = args.GetShort(2);
	// GLshort red, GLshort green, GLshort blue
	::glColor3s(red, green, blue);
	return Value::Null;
}

// opengl.glColor3sv(v[]:number):void:map
Gura_DeclareFunction(glColor3sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor3sv)
{
	DeclareArray(GLshort, v, 3, 0);
	// const GLshort *v
	::glColor3sv(v);
	return Value::Null;
}

// opengl.glColor3ub(red:number, green:number, blue:number):void:map
Gura_DeclareFunction(glColor3ub)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementFunction(glColor3ub)
{
	GLubyte red = args.GetUChar(0);
	GLubyte green = args.GetUChar(1);
	GLubyte blue = args.GetUChar(2);
	// GLubyte red, GLubyte green, GLubyte blue
	::glColor3ub(red, green, blue);
	return Value::Null;
}

// opengl.glColor3ubv(v[]:number):void:map
Gura_DeclareFunction(glColor3ubv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor3ubv)
{
	DeclareArray(GLubyte, v, 3, 0);
	// const GLubyte *v
	::glColor3ubv(v);
	return Value::Null;
}

// opengl.glColor3ui(red:number, green:number, blue:number):void:map
Gura_DeclareFunction(glColor3ui)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementFunction(glColor3ui)
{
	GLuint red = args.GetUInt(0);
	GLuint green = args.GetUInt(1);
	GLuint blue = args.GetUInt(2);
	// GLuint red, GLuint green, GLuint blue
	::glColor3ui(red, green, blue);
	return Value::Null;
}

// opengl.glColor3uiv(v[]:number):void:map
Gura_DeclareFunction(glColor3uiv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor3uiv)
{
	DeclareArray(GLuint, v, 3, 0);
	// const GLuint *v
	::glColor3uiv(v);
	return Value::Null;
}

// opengl.glColor3us(red:number, green:number, blue:number):void:map
Gura_DeclareFunction(glColor3us)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementFunction(glColor3us)
{
	GLushort red = args.GetUShort(0);
	GLushort green = args.GetUShort(1);
	GLushort blue = args.GetUShort(2);
	// GLushort red, GLushort green, GLushort blue
	::glColor3us(red, green, blue);
	return Value::Null;
}

// opengl.glColor3usv(v[]:number):void:map
Gura_DeclareFunction(glColor3usv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor3usv)
{
	DeclareArray(GLushort, v, 3, 0);
	// const GLushort *v
	::glColor3usv(v);
	return Value::Null;
}

// opengl.glColor4b(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glColor4b)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glColor4b)
{
	GLbyte red = args.GetChar(0);
	GLbyte green = args.GetChar(1);
	GLbyte blue = args.GetChar(2);
	GLbyte alpha = args.GetChar(3);
	// GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha
	::glColor4b(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4bv(v[]:number):void:map
Gura_DeclareFunction(glColor4bv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor4bv)
{
	DeclareArray(GLbyte, v, 4, 0);
	// const GLbyte *v
	::glColor4bv(v);
	return Value::Null;
}

// opengl.glColor4d(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glColor4d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glColor4d)
{
	GLdouble red = args.GetDouble(0);
	GLdouble green = args.GetDouble(1);
	GLdouble blue = args.GetDouble(2);
	GLdouble alpha = args.GetDouble(3);
	// GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha
	::glColor4d(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4dv(v[]:number):void:map
Gura_DeclareFunction(glColor4dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor4dv)
{
	DeclareArray(GLdouble, v, 4, 0);
	// const GLdouble *v
	::glColor4dv(v);
	return Value::Null;
}

// opengl.glColor4f(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glColor4f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glColor4f)
{
	GLfloat red = args.GetFloat(0);
	GLfloat green = args.GetFloat(1);
	GLfloat blue = args.GetFloat(2);
	GLfloat alpha = args.GetFloat(3);
	// GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha
	::glColor4f(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4fv(v[]:number):void:map
Gura_DeclareFunction(glColor4fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor4fv)
{
	DeclareArray(GLfloat, v, 4, 0);
	// const GLfloat *v
	::glColor4fv(v);
	return Value::Null;
}

// opengl.glColor4i(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glColor4i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glColor4i)
{
	GLint red = args.GetInt(0);
	GLint green = args.GetInt(1);
	GLint blue = args.GetInt(2);
	GLint alpha = args.GetInt(3);
	// GLint red, GLint green, GLint blue, GLint alpha
	::glColor4i(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4iv(v[]:number):void:map
Gura_DeclareFunction(glColor4iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor4iv)
{
	DeclareArray(GLint, v, 4, 0);
	// const GLint *v
	::glColor4iv(v);
	return Value::Null;
}

// opengl.glColor4s(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glColor4s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glColor4s)
{
	GLshort red = args.GetShort(0);
	GLshort green = args.GetShort(1);
	GLshort blue = args.GetShort(2);
	GLshort alpha = args.GetShort(3);
	// GLshort red, GLshort green, GLshort blue, GLshort alpha
	::glColor4s(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4sv(v[]:number):void:map
Gura_DeclareFunction(glColor4sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor4sv)
{
	DeclareArray(GLshort, v, 4, 0);
	// const GLshort *v
	::glColor4sv(v);
	return Value::Null;
}

// opengl.glColor4ub(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glColor4ub)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glColor4ub)
{
	GLubyte red = args.GetUChar(0);
	GLubyte green = args.GetUChar(1);
	GLubyte blue = args.GetUChar(2);
	GLubyte alpha = args.GetUChar(3);
	// GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha
	::glColor4ub(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4ubv(v[]:number):void:map
Gura_DeclareFunction(glColor4ubv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor4ubv)
{
	DeclareArray(GLubyte, v, 4, 0);
	// const GLubyte *v
	::glColor4ubv(v);
	return Value::Null;
}

// opengl.glColor4ui(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glColor4ui)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glColor4ui)
{
	GLuint red = args.GetUInt(0);
	GLuint green = args.GetUInt(1);
	GLuint blue = args.GetUInt(2);
	GLuint alpha = args.GetUInt(3);
	// GLuint red, GLuint green, GLuint blue, GLuint alpha
	::glColor4ui(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4uiv(v[]:number):void:map
Gura_DeclareFunction(glColor4uiv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor4uiv)
{
	DeclareArray(GLuint, v, 4, 0);
	// const GLuint *v
	::glColor4uiv(v);
	return Value::Null;
}

// opengl.glColor4us(red:number, green:number, blue:number, alpha:number):void:map
Gura_DeclareFunction(glColor4us)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementFunction(glColor4us)
{
	GLushort red = args.GetUShort(0);
	GLushort green = args.GetUShort(1);
	GLushort blue = args.GetUShort(2);
	GLushort alpha = args.GetUShort(3);
	// GLushort red, GLushort green, GLushort blue, GLushort alpha
	::glColor4us(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColor4usv(v[]:number):void:map
Gura_DeclareFunction(glColor4usv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glColor4usv)
{
	DeclareArray(GLushort, v, 4, 0);
	// const GLushort *v
	::glColor4usv(v);
	return Value::Null;
}

// opengl.glColorMask(red:boolean, green:boolean, blue:boolean, alpha:boolean):void:map
Gura_DeclareFunction(glColorMask)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_boolean);
	DeclareArg(env, "green", VTYPE_boolean);
	DeclareArg(env, "blue", VTYPE_boolean);
	DeclareArg(env, "alpha", VTYPE_boolean);
}

Gura_ImplementFunction(glColorMask)
{
	GLboolean red = args.GetBoolean(0)? 1 : 0;
	GLboolean green = args.GetBoolean(1)? 1 : 0;
	GLboolean blue = args.GetBoolean(2)? 1 : 0;
	GLboolean alpha = args.GetBoolean(3)? 1 : 0;
	// GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha
	::glColorMask(red, green, blue, alpha);
	return Value::Null;
}

// opengl.glColorMaterial(face:number, mode:number):void:map
Gura_DeclareFunction(glColorMaterial)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "face", VTYPE_number);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glColorMaterial)
{
	GLenum face = args.GetUInt(0);
	GLenum mode = args.GetUInt(1);
	// GLenum face, GLenum mode
	::glColorMaterial(face, mode);
	return Value::Null;
}

// opengl.glCopyPixels(x:number, y:number, width:number, height:number, type:number):void:map
Gura_DeclareFunction(glCopyPixels)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "type", VTYPE_number);
}

Gura_ImplementFunction(glCopyPixels)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLsizei width = args.GetInt(2);
	GLsizei height = args.GetInt(3);
	GLenum type = args.GetUInt(4);
	// GLint x, GLint y, GLsizei width, GLsizei height, GLenum type
	::glCopyPixels(x, y, width, height, type);
	return Value::Null;
}

// opengl.glCopyTexImage1D(target:number, level:number, internalFormat:number, x:number, y:number, width:number, border:number):void:map
Gura_DeclareFunction(glCopyTexImage1D)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "internalFormat", VTYPE_number);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "border", VTYPE_number);
}

Gura_ImplementFunction(glCopyTexImage1D)
{
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLenum internalFormat = args.GetUInt(2);
	GLint x = args.GetInt(3);
	GLint y = args.GetInt(4);
	GLsizei width = args.GetInt(5);
	GLint border = args.GetInt(6);
	// GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border
	::glCopyTexImage1D(target, level, internalFormat, x, y, width, border);
	return Value::Null;
}

// opengl.glCopyTexImage2D(target:number, level:number, internalFormat:number, x:number, y:number, width:number, height:number, border:number):void:map
Gura_DeclareFunction(glCopyTexImage2D)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "internalFormat", VTYPE_number);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "border", VTYPE_number);
}

Gura_ImplementFunction(glCopyTexImage2D)
{
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLenum internalFormat = args.GetUInt(2);
	GLint x = args.GetInt(3);
	GLint y = args.GetInt(4);
	GLsizei width = args.GetInt(5);
	GLsizei height = args.GetInt(6);
	GLint border = args.GetInt(7);
	// GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border
	::glCopyTexImage2D(target, level, internalFormat, x, y, width, height, border);
	return Value::Null;
}

// opengl.glCopyTexSubImage1D(target:number, level:number, xoffset:number, x:number, y:number, width:number):void:map
Gura_DeclareFunction(glCopyTexSubImage1D)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "xoffset", VTYPE_number);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
}

Gura_ImplementFunction(glCopyTexSubImage1D)
{
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLint xoffset = args.GetInt(2);
	GLint x = args.GetInt(3);
	GLint y = args.GetInt(4);
	GLsizei width = args.GetInt(5);
	// GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width
	::glCopyTexSubImage1D(target, level, xoffset, x, y, width);
	return Value::Null;
}

// opengl.glCopyTexSubImage2D(target:number, level:number, xoffset:number, yoffset:number, x:number, y:number, width:number, height:number):void:map
Gura_DeclareFunction(glCopyTexSubImage2D)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "xoffset", VTYPE_number);
	DeclareArg(env, "yoffset", VTYPE_number);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementFunction(glCopyTexSubImage2D)
{
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLint xoffset = args.GetInt(2);
	GLint yoffset = args.GetInt(3);
	GLint x = args.GetInt(4);
	GLint y = args.GetInt(5);
	GLsizei width = args.GetInt(6);
	GLsizei height = args.GetInt(7);
	// GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height
	::glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
	return Value::Null;
}

// opengl.glCullFace(mode:number):void:map
Gura_DeclareFunction(glCullFace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glCullFace)
{
	GLenum mode = args.GetUInt(0);
	// GLenum mode
	::glCullFace(mode);
	return Value::Null;
}

// opengl.glDeleteLists(list:number, range:number):void:map
Gura_DeclareFunction(glDeleteLists)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "list", VTYPE_number);
	DeclareArg(env, "range", VTYPE_number);
}

Gura_ImplementFunction(glDeleteLists)
{
	GLuint list = args.GetUInt(0);
	GLsizei range = args.GetInt(1);
	// GLuint list, GLsizei range
	::glDeleteLists(list, range);
	return Value::Null;
}

// opengl.glDepthFunc(func:number):void:map
Gura_DeclareFunction(glDepthFunc)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "func", VTYPE_number);
}

Gura_ImplementFunction(glDepthFunc)
{
	GLenum func = args.GetUInt(0);
	// GLenum func
	::glDepthFunc(func);
	return Value::Null;
}

// opengl.glDepthMask(flag:boolean):void:map
Gura_DeclareFunction(glDepthMask)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean);
}

Gura_ImplementFunction(glDepthMask)
{
	GLboolean flag = args.GetBoolean(0)? 1 : 0;
	// GLboolean flag
	::glDepthMask(flag);
	return Value::Null;
}

// opengl.glDepthRange(zNear:number, zFar:number):void:map
Gura_DeclareFunction(glDepthRange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "zNear", VTYPE_number);
	DeclareArg(env, "zFar", VTYPE_number);
}

Gura_ImplementFunction(glDepthRange)
{
	GLclampd zNear = args.GetDouble(0);
	GLclampd zFar = args.GetDouble(1);
	// GLclampd zNear, GLclampd zFar
	::glDepthRange(zNear, zFar);
	return Value::Null;
}

// opengl.glDisable(cap:number):void:map
Gura_DeclareFunction(glDisable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cap", VTYPE_number);
}

Gura_ImplementFunction(glDisable)
{
	GLenum cap = args.GetUInt(0);
	// GLenum cap
	::glDisable(cap);
	return Value::Null;
}

// opengl.glDisableClientState(array:number):void:map
Gura_DeclareFunction(glDisableClientState)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "array", VTYPE_number);
}

Gura_ImplementFunction(glDisableClientState)
{
	GLenum array = args.GetUInt(0);
	// GLenum array
	::glDisableClientState(array);
	return Value::Null;
}

// opengl.glDrawArrays(mode:number, first:number, count:number):void:map
Gura_DeclareFunction(glDrawArrays)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
	DeclareArg(env, "first", VTYPE_number);
	DeclareArg(env, "count", VTYPE_number);
}

Gura_ImplementFunction(glDrawArrays)
{
	GLenum mode = args.GetUInt(0);
	GLint first = args.GetInt(1);
	GLsizei count = args.GetInt(2);
	// GLenum mode, GLint first, GLsizei count
	::glDrawArrays(mode, first, count);
	return Value::Null;
}

// opengl.glDrawBuffer(mode:number):void:map
Gura_DeclareFunction(glDrawBuffer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glDrawBuffer)
{
	GLenum mode = args.GetUInt(0);
	// GLenum mode
	::glDrawBuffer(mode);
	return Value::Null;
}

// opengl.glEdgeFlag(flag:boolean):void:map
Gura_DeclareFunction(glEdgeFlag)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean);
}

Gura_ImplementFunction(glEdgeFlag)
{
	GLboolean flag = args.GetBoolean(0)? 1 : 0;
	// GLboolean flag
	::glEdgeFlag(flag);
	return Value::Null;
}

// opengl.glEdgeFlagv(flag[]:boolean):void:map
Gura_DeclareFunction(glEdgeFlagv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glEdgeFlagv)
{
	DeclareNewArray(GLboolean, flag, 0);
	// const GLboolean *flag
	::glEdgeFlagv(flag);
	delete[] flag;
	return Value::Null;
}

// opengl.glEnable(cap:number):void:map
Gura_DeclareFunction(glEnable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cap", VTYPE_number);
}

Gura_ImplementFunction(glEnable)
{
	GLenum cap = args.GetUInt(0);
	// GLenum cap
	::glEnable(cap);
	return Value::Null;
}

// opengl.glEnableClientState(array:number):void:map
Gura_DeclareFunction(glEnableClientState)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "array", VTYPE_number);
}

Gura_ImplementFunction(glEnableClientState)
{
	GLenum array = args.GetUInt(0);
	// GLenum array
	::glEnableClientState(array);
	return Value::Null;
}

// opengl.glEnd():void
Gura_DeclareFunction(glEnd)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glEnd)
{
	// void
	::glEnd();
	return Value::Null;
}

// opengl.glEndList():void
Gura_DeclareFunction(glEndList)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glEndList)
{
	// void
	::glEndList();
	return Value::Null;
}

// opengl.glEvalCoord1d(u:number):void:map
Gura_DeclareFunction(glEvalCoord1d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "u", VTYPE_number);
}

Gura_ImplementFunction(glEvalCoord1d)
{
	GLdouble u = args.GetDouble(0);
	// GLdouble u
	::glEvalCoord1d(u);
	return Value::Null;
}

// opengl.glEvalCoord1dv(u[]:number):void:map
Gura_DeclareFunction(glEvalCoord1dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glEvalCoord1dv)
{
	DeclareArray(GLdouble, u, 1, 0);
	// const GLdouble *u
	::glEvalCoord1dv(u);
	return Value::Null;
}

// opengl.glEvalCoord1f(u:number):void:map
Gura_DeclareFunction(glEvalCoord1f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "u", VTYPE_number);
}

Gura_ImplementFunction(glEvalCoord1f)
{
	GLfloat u = args.GetFloat(0);
	// GLfloat u
	::glEvalCoord1f(u);
	return Value::Null;
}

// opengl.glEvalCoord1fv(u[]:number):void:map
Gura_DeclareFunction(glEvalCoord1fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glEvalCoord1fv)
{
	DeclareArray(GLfloat, u, 1, 0);
	// const GLfloat *u
	::glEvalCoord1fv(u);
	return Value::Null;
}

// opengl.glEvalCoord2d(u:number, v:number):void:map
Gura_DeclareFunction(glEvalCoord2d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "u", VTYPE_number);
	DeclareArg(env, "v", VTYPE_number);
}

Gura_ImplementFunction(glEvalCoord2d)
{
	GLdouble u = args.GetDouble(0);
	GLdouble v = args.GetDouble(1);
	// GLdouble u, GLdouble v
	::glEvalCoord2d(u, v);
	return Value::Null;
}

// opengl.glEvalCoord2dv(u[]:number):void:map
Gura_DeclareFunction(glEvalCoord2dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glEvalCoord2dv)
{
	DeclareArray(GLdouble, u, 2, 0);
	// const GLdouble *u
	::glEvalCoord2dv(u);
	return Value::Null;
}

// opengl.glEvalCoord2f(u:number, v:number):void:map
Gura_DeclareFunction(glEvalCoord2f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "u", VTYPE_number);
	DeclareArg(env, "v", VTYPE_number);
}

Gura_ImplementFunction(glEvalCoord2f)
{
	GLfloat u = args.GetFloat(0);
	GLfloat v = args.GetFloat(1);
	// GLfloat u, GLfloat v
	::glEvalCoord2f(u, v);
	return Value::Null;
}

// opengl.glEvalCoord2fv(u[]:number):void:map
Gura_DeclareFunction(glEvalCoord2fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "u", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glEvalCoord2fv)
{
	DeclareArray(GLfloat, u, 2, 0);
	// const GLfloat *u
	::glEvalCoord2fv(u);
	return Value::Null;
}

// opengl.glEvalMesh1(mode:number, i1:number, i2:number):void:map
Gura_DeclareFunction(glEvalMesh1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
	DeclareArg(env, "i1", VTYPE_number);
	DeclareArg(env, "i2", VTYPE_number);
}

Gura_ImplementFunction(glEvalMesh1)
{
	GLenum mode = args.GetUInt(0);
	GLint i1 = args.GetInt(1);
	GLint i2 = args.GetInt(2);
	// GLenum mode, GLint i1, GLint i2
	::glEvalMesh1(mode, i1, i2);
	return Value::Null;
}

// opengl.glEvalMesh2(mode:number, i1:number, i2:number, j1:number, j2:number):void:map
Gura_DeclareFunction(glEvalMesh2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
	DeclareArg(env, "i1", VTYPE_number);
	DeclareArg(env, "i2", VTYPE_number);
	DeclareArg(env, "j1", VTYPE_number);
	DeclareArg(env, "j2", VTYPE_number);
}

Gura_ImplementFunction(glEvalMesh2)
{
	GLenum mode = args.GetUInt(0);
	GLint i1 = args.GetInt(1);
	GLint i2 = args.GetInt(2);
	GLint j1 = args.GetInt(3);
	GLint j2 = args.GetInt(4);
	// GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2
	::glEvalMesh2(mode, i1, i2, j1, j2);
	return Value::Null;
}

// opengl.glEvalPoint1(i:number):void:map
Gura_DeclareFunction(glEvalPoint1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number);
}

Gura_ImplementFunction(glEvalPoint1)
{
	GLint i = args.GetInt(0);
	// GLint i
	::glEvalPoint1(i);
	return Value::Null;
}

// opengl.glEvalPoint2(i:number, j:number):void:map
Gura_DeclareFunction(glEvalPoint2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number);
	DeclareArg(env, "j", VTYPE_number);
}

Gura_ImplementFunction(glEvalPoint2)
{
	GLint i = args.GetInt(0);
	GLint j = args.GetInt(1);
	// GLint i, GLint j
	::glEvalPoint2(i, j);
	return Value::Null;
}

// opengl.glFinish():void
Gura_DeclareFunction(glFinish)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glFinish)
{
	// void
	::glFinish();
	return Value::Null;
}

// opengl.glFlush():void
Gura_DeclareFunction(glFlush)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glFlush)
{
	// void
	::glFlush();
	return Value::Null;
}

// opengl.glFogf(pname:number, param:number):void:map
Gura_DeclareFunction(glFogf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glFogf)
{
	GLenum pname = args.GetUInt(0);
	GLfloat param = args.GetFloat(1);
	// GLenum pname, GLfloat param
	::glFogf(pname, param);
	return Value::Null;
}

// opengl.glFogfv(pname:number, params[]:number):void:map
Gura_DeclareFunction(glFogfv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glFogfv)
{
	GLenum pname = args.GetUInt(0);
	DeclareNewArray(GLfloat, params, 1);
	// GLenum pname, const GLfloat *params
	::glFogfv(pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glFogi(pname:number, param:number):void:map
Gura_DeclareFunction(glFogi)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glFogi)
{
	GLenum pname = args.GetUInt(0);
	GLint param = args.GetInt(1);
	// GLenum pname, GLint param
	::glFogi(pname, param);
	return Value::Null;
}

// opengl.glFogiv(pname:number, params[]:number):void:map
Gura_DeclareFunction(glFogiv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glFogiv)
{
	GLenum pname = args.GetUInt(0);
	DeclareNewArray(GLint, params, 1);
	// GLenum pname, const GLint *params
	::glFogiv(pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glFrontFace(mode:number):void:map
Gura_DeclareFunction(glFrontFace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glFrontFace)
{
	GLenum mode = args.GetUInt(0);
	// GLenum mode
	::glFrontFace(mode);
	return Value::Null;
}

// opengl.glFrustum(left:number, right:number, bottom:number, top:number, zNear:number, zFar:number):void:map
Gura_DeclareFunction(glFrustum)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "left", VTYPE_number);
	DeclareArg(env, "right", VTYPE_number);
	DeclareArg(env, "bottom", VTYPE_number);
	DeclareArg(env, "top", VTYPE_number);
	DeclareArg(env, "zNear", VTYPE_number);
	DeclareArg(env, "zFar", VTYPE_number);
}

Gura_ImplementFunction(glFrustum)
{
	GLdouble left = args.GetDouble(0);
	GLdouble right = args.GetDouble(1);
	GLdouble bottom = args.GetDouble(2);
	GLdouble top = args.GetDouble(3);
	GLdouble zNear = args.GetDouble(4);
	GLdouble zFar = args.GetDouble(5);
	// GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar
	::glFrustum(left, right, bottom, top, zNear, zFar);
	return Value::Null;
}

// opengl.glHint(target:number, mode:number):void:map
Gura_DeclareFunction(glHint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glHint)
{
	GLenum target = args.GetUInt(0);
	GLenum mode = args.GetUInt(1);
	// GLenum target, GLenum mode
	::glHint(target, mode);
	return Value::Null;
}

// opengl.glIndexMask(mask:number):void:map
Gura_DeclareFunction(glIndexMask)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_number);
}

Gura_ImplementFunction(glIndexMask)
{
	GLuint mask = args.GetUInt(0);
	// GLuint mask
	::glIndexMask(mask);
	return Value::Null;
}

// opengl.glIndexd(c:number):void:map
Gura_DeclareFunction(glIndexd)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number);
}

Gura_ImplementFunction(glIndexd)
{
	GLdouble c = args.GetDouble(0);
	// GLdouble c
	::glIndexd(c);
	return Value::Null;
}

// opengl.glIndexdv(c[]:number):void:map
Gura_DeclareFunction(glIndexdv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glIndexdv)
{
	DeclareNewArray(GLdouble, c, 0);
	// const GLdouble *c
	::glIndexdv(c);
	delete[] c;
	return Value::Null;
}

// opengl.glIndexf(c:number):void:map
Gura_DeclareFunction(glIndexf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number);
}

Gura_ImplementFunction(glIndexf)
{
	GLfloat c = args.GetFloat(0);
	// GLfloat c
	::glIndexf(c);
	return Value::Null;
}

// opengl.glIndexfv(c[]:number):void:map
Gura_DeclareFunction(glIndexfv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glIndexfv)
{
	DeclareNewArray(GLfloat, c, 0);
	// const GLfloat *c
	::glIndexfv(c);
	delete[] c;
	return Value::Null;
}

// opengl.glIndexi(c:number):void:map
Gura_DeclareFunction(glIndexi)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number);
}

Gura_ImplementFunction(glIndexi)
{
	GLint c = args.GetInt(0);
	// GLint c
	::glIndexi(c);
	return Value::Null;
}

// opengl.glIndexiv(c[]:number):void:map
Gura_DeclareFunction(glIndexiv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glIndexiv)
{
	DeclareNewArray(GLint, c, 0);
	// const GLint *c
	::glIndexiv(c);
	delete[] c;
	return Value::Null;
}

// opengl.glIndexs(c:number):void:map
Gura_DeclareFunction(glIndexs)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number);
}

Gura_ImplementFunction(glIndexs)
{
	GLshort c = args.GetShort(0);
	// GLshort c
	::glIndexs(c);
	return Value::Null;
}

// opengl.glIndexsv(c[]:number):void:map
Gura_DeclareFunction(glIndexsv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glIndexsv)
{
	DeclareNewArray(GLshort, c, 0);
	// const GLshort *c
	::glIndexsv(c);
	delete[] c;
	return Value::Null;
}

// opengl.glIndexub(c:number):void:map
Gura_DeclareFunction(glIndexub)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number);
}

Gura_ImplementFunction(glIndexub)
{
	GLubyte c = args.GetUChar(0);
	// GLubyte c
	::glIndexub(c);
	return Value::Null;
}

// opengl.glIndexubv(c[]:number):void:map
Gura_DeclareFunction(glIndexubv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glIndexubv)
{
	DeclareNewArray(GLubyte, c, 0);
	// const GLubyte *c
	::glIndexubv(c);
	delete[] c;
	return Value::Null;
}

// opengl.glInitNames():void
Gura_DeclareFunction(glInitNames)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glInitNames)
{
	// void
	::glInitNames();
	return Value::Null;
}

// opengl.glLightModelf(pname:number, param:number):void:map
Gura_DeclareFunction(glLightModelf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glLightModelf)
{
	GLenum pname = args.GetUInt(0);
	GLfloat param = args.GetFloat(1);
	// GLenum pname, GLfloat param
	::glLightModelf(pname, param);
	return Value::Null;
}

// opengl.glLightModelfv(pname:number, params[]:number):void:map
Gura_DeclareFunction(glLightModelfv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glLightModelfv)
{
	GLenum pname = args.GetUInt(0);
	DeclareNewArray(GLfloat, params, 1);
	// GLenum pname, const GLfloat *params
	::glLightModelfv(pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glLightModeli(pname:number, param:number):void:map
Gura_DeclareFunction(glLightModeli)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glLightModeli)
{
	GLenum pname = args.GetUInt(0);
	GLint param = args.GetInt(1);
	// GLenum pname, GLint param
	::glLightModeli(pname, param);
	return Value::Null;
}

// opengl.glLightModeliv(pname:number, params[]:number):void:map
Gura_DeclareFunction(glLightModeliv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glLightModeliv)
{
	GLenum pname = args.GetUInt(0);
	DeclareNewArray(GLint, params, 1);
	// GLenum pname, const GLint *params
	::glLightModeliv(pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glLightf(light:number, pname:number, param:number):void:map
Gura_DeclareFunction(glLightf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "light", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glLightf)
{
	GLenum light = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLfloat param = args.GetFloat(2);
	// GLenum light, GLenum pname, GLfloat param
	::glLightf(light, pname, param);
	return Value::Null;
}

// opengl.glLightfv(light:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glLightfv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "light", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glLightfv)
{
	GLenum light = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLfloat, params, 2);
	// GLenum light, GLenum pname, const GLfloat *params
	::glLightfv(light, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glLighti(light:number, pname:number, param:number):void:map
Gura_DeclareFunction(glLighti)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "light", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glLighti)
{
	GLenum light = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLint param = args.GetInt(2);
	// GLenum light, GLenum pname, GLint param
	::glLighti(light, pname, param);
	return Value::Null;
}

// opengl.glLightiv(light:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glLightiv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "light", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glLightiv)
{
	GLenum light = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLint, params, 2);
	// GLenum light, GLenum pname, const GLint *params
	::glLightiv(light, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glLineStipple(factor:number, pattern:number):void:map
Gura_DeclareFunction(glLineStipple)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "factor", VTYPE_number);
	DeclareArg(env, "pattern", VTYPE_number);
}

Gura_ImplementFunction(glLineStipple)
{
	GLint factor = args.GetInt(0);
	GLushort pattern = args.GetUShort(1);
	// GLint factor, GLushort pattern
	::glLineStipple(factor, pattern);
	return Value::Null;
}

// opengl.glLineWidth(width:number):void:map
Gura_DeclareFunction(glLineWidth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number);
}

Gura_ImplementFunction(glLineWidth)
{
	GLfloat width = args.GetFloat(0);
	// GLfloat width
	::glLineWidth(width);
	return Value::Null;
}

// opengl.glListBase(base:number):void:map
Gura_DeclareFunction(glListBase)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number);
}

Gura_ImplementFunction(glListBase)
{
	GLuint base = args.GetUInt(0);
	// GLuint base
	::glListBase(base);
	return Value::Null;
}

// opengl.glLoadIdentity():void
Gura_DeclareFunction(glLoadIdentity)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glLoadIdentity)
{
	// void
	::glLoadIdentity();
	return Value::Null;
}

// opengl.glLoadMatrixd(m[]:number):void:map
Gura_DeclareFunction(glLoadMatrixd)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glLoadMatrixd)
{
	DeclareNewArray(GLdouble, m, 0);
	// const GLdouble *m
	::glLoadMatrixd(m);
	delete[] m;
	return Value::Null;
}

// opengl.glLoadMatrixf(m[]:number):void:map
Gura_DeclareFunction(glLoadMatrixf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glLoadMatrixf)
{
	DeclareNewArray(GLfloat, m, 0);
	// const GLfloat *m
	::glLoadMatrixf(m);
	delete[] m;
	return Value::Null;
}

// opengl.glLoadName(name:number):void:map
Gura_DeclareFunction(glLoadName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_number);
}

Gura_ImplementFunction(glLoadName)
{
	GLuint name = args.GetUInt(0);
	// GLuint name
	::glLoadName(name);
	return Value::Null;
}

// opengl.glLogicOp(opcode:number):void:map
Gura_DeclareFunction(glLogicOp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "opcode", VTYPE_number);
}

Gura_ImplementFunction(glLogicOp)
{
	GLenum opcode = args.GetUInt(0);
	// GLenum opcode
	::glLogicOp(opcode);
	return Value::Null;
}

// opengl.glMap1d(target:number, u1:number, u2:number, stride:number, order:number, points[]:number):void:map
Gura_DeclareFunction(glMap1d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "u1", VTYPE_number);
	DeclareArg(env, "u2", VTYPE_number);
	DeclareArg(env, "stride", VTYPE_number);
	DeclareArg(env, "order", VTYPE_number);
	DeclareArg(env, "points", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glMap1d)
{
	GLenum target = args.GetUInt(0);
	GLdouble u1 = args.GetDouble(1);
	GLdouble u2 = args.GetDouble(2);
	GLint stride = args.GetInt(3);
	GLint order = args.GetInt(4);
	DeclareNewArray(GLdouble, points, 5);
	// GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points
	::glMap1d(target, u1, u2, stride, order, points);
	delete[] points;
	return Value::Null;
}

// opengl.glMap1f(target:number, u1:number, u2:number, stride:number, order:number, points[]:number):void:map
Gura_DeclareFunction(glMap1f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "u1", VTYPE_number);
	DeclareArg(env, "u2", VTYPE_number);
	DeclareArg(env, "stride", VTYPE_number);
	DeclareArg(env, "order", VTYPE_number);
	DeclareArg(env, "points", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glMap1f)
{
	GLenum target = args.GetUInt(0);
	GLfloat u1 = args.GetFloat(1);
	GLfloat u2 = args.GetFloat(2);
	GLint stride = args.GetInt(3);
	GLint order = args.GetInt(4);
	DeclareNewArray(GLfloat, points, 5);
	// GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points
	::glMap1f(target, u1, u2, stride, order, points);
	delete[] points;
	return Value::Null;
}

// opengl.glMap2d(target:number, u1:number, u2:number, ustride:number, uorder:number, v1:number, v2:number, vstride:number, vorder:number, points[]:number):void:map
Gura_DeclareFunction(glMap2d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "u1", VTYPE_number);
	DeclareArg(env, "u2", VTYPE_number);
	DeclareArg(env, "ustride", VTYPE_number);
	DeclareArg(env, "uorder", VTYPE_number);
	DeclareArg(env, "v1", VTYPE_number);
	DeclareArg(env, "v2", VTYPE_number);
	DeclareArg(env, "vstride", VTYPE_number);
	DeclareArg(env, "vorder", VTYPE_number);
	DeclareArg(env, "points", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glMap2d)
{
	GLenum target = args.GetUInt(0);
	GLdouble u1 = args.GetDouble(1);
	GLdouble u2 = args.GetDouble(2);
	GLint ustride = args.GetInt(3);
	GLint uorder = args.GetInt(4);
	GLdouble v1 = args.GetDouble(5);
	GLdouble v2 = args.GetDouble(6);
	GLint vstride = args.GetInt(7);
	GLint vorder = args.GetInt(8);
	DeclareNewArray(GLdouble, points, 9);
	// GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points
	::glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
	delete[] points;
	return Value::Null;
}

// opengl.glMap2f(target:number, u1:number, u2:number, ustride:number, uorder:number, v1:number, v2:number, vstride:number, vorder:number, points[]:number):void:map
Gura_DeclareFunction(glMap2f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "u1", VTYPE_number);
	DeclareArg(env, "u2", VTYPE_number);
	DeclareArg(env, "ustride", VTYPE_number);
	DeclareArg(env, "uorder", VTYPE_number);
	DeclareArg(env, "v1", VTYPE_number);
	DeclareArg(env, "v2", VTYPE_number);
	DeclareArg(env, "vstride", VTYPE_number);
	DeclareArg(env, "vorder", VTYPE_number);
	DeclareArg(env, "points", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glMap2f)
{
	GLenum target = args.GetUInt(0);
	GLfloat u1 = args.GetFloat(1);
	GLfloat u2 = args.GetFloat(2);
	GLint ustride = args.GetInt(3);
	GLint uorder = args.GetInt(4);
	GLfloat v1 = args.GetFloat(5);
	GLfloat v2 = args.GetFloat(6);
	GLint vstride = args.GetInt(7);
	GLint vorder = args.GetInt(8);
	DeclareNewArray(GLfloat, points, 9);
	// GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points
	::glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
	delete[] points;
	return Value::Null;
}

// opengl.glMapGrid1d(un:number, u1:number, u2:number):void:map
Gura_DeclareFunction(glMapGrid1d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "un", VTYPE_number);
	DeclareArg(env, "u1", VTYPE_number);
	DeclareArg(env, "u2", VTYPE_number);
}

Gura_ImplementFunction(glMapGrid1d)
{
	GLint un = args.GetInt(0);
	GLdouble u1 = args.GetDouble(1);
	GLdouble u2 = args.GetDouble(2);
	// GLint un, GLdouble u1, GLdouble u2
	::glMapGrid1d(un, u1, u2);
	return Value::Null;
}

// opengl.glMapGrid1f(un:number, u1:number, u2:number):void:map
Gura_DeclareFunction(glMapGrid1f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "un", VTYPE_number);
	DeclareArg(env, "u1", VTYPE_number);
	DeclareArg(env, "u2", VTYPE_number);
}

Gura_ImplementFunction(glMapGrid1f)
{
	GLint un = args.GetInt(0);
	GLfloat u1 = args.GetFloat(1);
	GLfloat u2 = args.GetFloat(2);
	// GLint un, GLfloat u1, GLfloat u2
	::glMapGrid1f(un, u1, u2);
	return Value::Null;
}

// opengl.glMapGrid2d(un:number, u1:number, u2:number, vn:number, v1:number, v2:number):void:map
Gura_DeclareFunction(glMapGrid2d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "un", VTYPE_number);
	DeclareArg(env, "u1", VTYPE_number);
	DeclareArg(env, "u2", VTYPE_number);
	DeclareArg(env, "vn", VTYPE_number);
	DeclareArg(env, "v1", VTYPE_number);
	DeclareArg(env, "v2", VTYPE_number);
}

Gura_ImplementFunction(glMapGrid2d)
{
	GLint un = args.GetInt(0);
	GLdouble u1 = args.GetDouble(1);
	GLdouble u2 = args.GetDouble(2);
	GLint vn = args.GetInt(3);
	GLdouble v1 = args.GetDouble(4);
	GLdouble v2 = args.GetDouble(5);
	// GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2
	::glMapGrid2d(un, u1, u2, vn, v1, v2);
	return Value::Null;
}

// opengl.glMapGrid2f(un:number, u1:number, u2:number, vn:number, v1:number, v2:number):void:map
Gura_DeclareFunction(glMapGrid2f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "un", VTYPE_number);
	DeclareArg(env, "u1", VTYPE_number);
	DeclareArg(env, "u2", VTYPE_number);
	DeclareArg(env, "vn", VTYPE_number);
	DeclareArg(env, "v1", VTYPE_number);
	DeclareArg(env, "v2", VTYPE_number);
}

Gura_ImplementFunction(glMapGrid2f)
{
	GLint un = args.GetInt(0);
	GLfloat u1 = args.GetFloat(1);
	GLfloat u2 = args.GetFloat(2);
	GLint vn = args.GetInt(3);
	GLfloat v1 = args.GetFloat(4);
	GLfloat v2 = args.GetFloat(5);
	// GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2
	::glMapGrid2f(un, u1, u2, vn, v1, v2);
	return Value::Null;
}

// opengl.glMaterialf(face:number, pname:number, param:number):void:map
Gura_DeclareFunction(glMaterialf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "face", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glMaterialf)
{
	GLenum face = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLfloat param = args.GetFloat(2);
	// GLenum face, GLenum pname, GLfloat param
	::glMaterialf(face, pname, param);
	return Value::Null;
}

// opengl.glMaterialfv(face:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glMaterialfv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "face", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glMaterialfv)
{
	GLenum face = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLfloat, params, 2);
	// GLenum face, GLenum pname, const GLfloat *params
	::glMaterialfv(face, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glMateriali(face:number, pname:number, param:number):void:map
Gura_DeclareFunction(glMateriali)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "face", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glMateriali)
{
	GLenum face = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLint param = args.GetInt(2);
	// GLenum face, GLenum pname, GLint param
	::glMateriali(face, pname, param);
	return Value::Null;
}

// opengl.glMaterialiv(face:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glMaterialiv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "face", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glMaterialiv)
{
	GLenum face = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLint, params, 2);
	// GLenum face, GLenum pname, const GLint *params
	::glMaterialiv(face, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glMatrixMode(mode:number):void:map
Gura_DeclareFunction(glMatrixMode)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glMatrixMode)
{
	GLenum mode = args.GetUInt(0);
	// GLenum mode
	::glMatrixMode(mode);
	return Value::Null;
}

// opengl.glMultMatrixd(m[]:number):void:map
Gura_DeclareFunction(glMultMatrixd)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glMultMatrixd)
{
	DeclareNewArray(GLdouble, m, 0);
	// const GLdouble *m
	::glMultMatrixd(m);
	delete[] m;
	return Value::Null;
}

// opengl.glMultMatrixf(m[]:number):void:map
Gura_DeclareFunction(glMultMatrixf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "m", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glMultMatrixf)
{
	DeclareNewArray(GLfloat, m, 0);
	// const GLfloat *m
	::glMultMatrixf(m);
	delete[] m;
	return Value::Null;
}

// opengl.glNormal3b(nx:number, ny:number, nz:number):void:map
Gura_DeclareFunction(glNormal3b)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nx", VTYPE_number);
	DeclareArg(env, "ny", VTYPE_number);
	DeclareArg(env, "nz", VTYPE_number);
}

Gura_ImplementFunction(glNormal3b)
{
	GLbyte nx = args.GetChar(0);
	GLbyte ny = args.GetChar(1);
	GLbyte nz = args.GetChar(2);
	// GLbyte nx, GLbyte ny, GLbyte nz
	::glNormal3b(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3bv(v[]:number):void:map
Gura_DeclareFunction(glNormal3bv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glNormal3bv)
{
	DeclareArray(GLbyte, v, 3, 0);
	// const GLbyte *v
	::glNormal3bv(v);
	return Value::Null;
}

// opengl.glNormal3d(nx:number, ny:number, nz:number):void:map
Gura_DeclareFunction(glNormal3d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nx", VTYPE_number);
	DeclareArg(env, "ny", VTYPE_number);
	DeclareArg(env, "nz", VTYPE_number);
}

Gura_ImplementFunction(glNormal3d)
{
	GLdouble nx = args.GetDouble(0);
	GLdouble ny = args.GetDouble(1);
	GLdouble nz = args.GetDouble(2);
	// GLdouble nx, GLdouble ny, GLdouble nz
	::glNormal3d(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3dv(v[]:number):void:map
Gura_DeclareFunction(glNormal3dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glNormal3dv)
{
	DeclareArray(GLdouble, v, 3, 0);
	// const GLdouble *v
	::glNormal3dv(v);
	return Value::Null;
}

// opengl.glNormal3f(nx:number, ny:number, nz:number):void:map
Gura_DeclareFunction(glNormal3f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nx", VTYPE_number);
	DeclareArg(env, "ny", VTYPE_number);
	DeclareArg(env, "nz", VTYPE_number);
}

Gura_ImplementFunction(glNormal3f)
{
	GLfloat nx = args.GetFloat(0);
	GLfloat ny = args.GetFloat(1);
	GLfloat nz = args.GetFloat(2);
	// GLfloat nx, GLfloat ny, GLfloat nz
	::glNormal3f(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3fv(v[]:number):void:map
Gura_DeclareFunction(glNormal3fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glNormal3fv)
{
	DeclareArray(GLfloat, v, 3, 0);
	// const GLfloat *v
	::glNormal3fv(v);
	return Value::Null;
}

// opengl.glNormal3i(nx:number, ny:number, nz:number):void:map
Gura_DeclareFunction(glNormal3i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nx", VTYPE_number);
	DeclareArg(env, "ny", VTYPE_number);
	DeclareArg(env, "nz", VTYPE_number);
}

Gura_ImplementFunction(glNormal3i)
{
	GLint nx = args.GetInt(0);
	GLint ny = args.GetInt(1);
	GLint nz = args.GetInt(2);
	// GLint nx, GLint ny, GLint nz
	::glNormal3i(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3iv(v[]:number):void:map
Gura_DeclareFunction(glNormal3iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glNormal3iv)
{
	DeclareArray(GLint, v, 3, 0);
	// const GLint *v
	::glNormal3iv(v);
	return Value::Null;
}

// opengl.glNormal3s(nx:number, ny:number, nz:number):void:map
Gura_DeclareFunction(glNormal3s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nx", VTYPE_number);
	DeclareArg(env, "ny", VTYPE_number);
	DeclareArg(env, "nz", VTYPE_number);
}

Gura_ImplementFunction(glNormal3s)
{
	GLshort nx = args.GetShort(0);
	GLshort ny = args.GetShort(1);
	GLshort nz = args.GetShort(2);
	// GLshort nx, GLshort ny, GLshort nz
	::glNormal3s(nx, ny, nz);
	return Value::Null;
}

// opengl.glNormal3sv(v[]:number):void:map
Gura_DeclareFunction(glNormal3sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glNormal3sv)
{
	DeclareArray(GLshort, v, 3, 0);
	// const GLshort *v
	::glNormal3sv(v);
	return Value::Null;
}

// opengl.glOrtho(left:number, right:number, bottom:number, top:number, zNear:number, zFar:number):void:map
Gura_DeclareFunction(glOrtho)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "left", VTYPE_number);
	DeclareArg(env, "right", VTYPE_number);
	DeclareArg(env, "bottom", VTYPE_number);
	DeclareArg(env, "top", VTYPE_number);
	DeclareArg(env, "zNear", VTYPE_number);
	DeclareArg(env, "zFar", VTYPE_number);
}

Gura_ImplementFunction(glOrtho)
{
	GLdouble left = args.GetDouble(0);
	GLdouble right = args.GetDouble(1);
	GLdouble bottom = args.GetDouble(2);
	GLdouble top = args.GetDouble(3);
	GLdouble zNear = args.GetDouble(4);
	GLdouble zFar = args.GetDouble(5);
	// GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar
	::glOrtho(left, right, bottom, top, zNear, zFar);
	return Value::Null;
}

// opengl.glPassThrough(token:number):void:map
Gura_DeclareFunction(glPassThrough)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "token", VTYPE_number);
}

Gura_ImplementFunction(glPassThrough)
{
	GLfloat token = args.GetFloat(0);
	// GLfloat token
	::glPassThrough(token);
	return Value::Null;
}

// opengl.glPixelMapfv(map:number, mapsize:number, values[]:number):void:map
Gura_DeclareFunction(glPixelMapfv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "map", VTYPE_number);
	DeclareArg(env, "mapsize", VTYPE_number);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glPixelMapfv)
{
	GLenum map = args.GetUInt(0);
	GLsizei mapsize = args.GetInt(1);
	DeclareNewArray(GLfloat, values, 2);
	// GLenum map, GLsizei mapsize, const GLfloat *values
	::glPixelMapfv(map, mapsize, values);
	delete[] values;
	return Value::Null;
}

// opengl.glPixelMapuiv(map:number, mapsize:number, values[]:number):void:map
Gura_DeclareFunction(glPixelMapuiv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "map", VTYPE_number);
	DeclareArg(env, "mapsize", VTYPE_number);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glPixelMapuiv)
{
	GLenum map = args.GetUInt(0);
	GLsizei mapsize = args.GetInt(1);
	DeclareNewArray(GLuint, values, 2);
	// GLenum map, GLsizei mapsize, const GLuint *values
	::glPixelMapuiv(map, mapsize, values);
	delete[] values;
	return Value::Null;
}

// opengl.glPixelMapusv(map:number, mapsize:number, values[]:number):void:map
Gura_DeclareFunction(glPixelMapusv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "map", VTYPE_number);
	DeclareArg(env, "mapsize", VTYPE_number);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glPixelMapusv)
{
	GLenum map = args.GetUInt(0);
	GLsizei mapsize = args.GetInt(1);
	DeclareNewArray(GLushort, values, 2);
	// GLenum map, GLsizei mapsize, const GLushort *values
	::glPixelMapusv(map, mapsize, values);
	delete[] values;
	return Value::Null;
}

// opengl.glPixelStoref(pname:number, param:number):void:map
Gura_DeclareFunction(glPixelStoref)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glPixelStoref)
{
	GLenum pname = args.GetUInt(0);
	GLfloat param = args.GetFloat(1);
	// GLenum pname, GLfloat param
	::glPixelStoref(pname, param);
	return Value::Null;
}

// opengl.glPixelStorei(pname:number, param:number):void:map
Gura_DeclareFunction(glPixelStorei)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glPixelStorei)
{
	GLenum pname = args.GetUInt(0);
	GLint param = args.GetInt(1);
	// GLenum pname, GLint param
	::glPixelStorei(pname, param);
	return Value::Null;
}

// opengl.glPixelTransferf(pname:number, param:number):void:map
Gura_DeclareFunction(glPixelTransferf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glPixelTransferf)
{
	GLenum pname = args.GetUInt(0);
	GLfloat param = args.GetFloat(1);
	// GLenum pname, GLfloat param
	::glPixelTransferf(pname, param);
	return Value::Null;
}

// opengl.glPixelTransferi(pname:number, param:number):void:map
Gura_DeclareFunction(glPixelTransferi)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glPixelTransferi)
{
	GLenum pname = args.GetUInt(0);
	GLint param = args.GetInt(1);
	// GLenum pname, GLint param
	::glPixelTransferi(pname, param);
	return Value::Null;
}

// opengl.glPixelZoom(xfactor:number, yfactor:number):void:map
Gura_DeclareFunction(glPixelZoom)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xfactor", VTYPE_number);
	DeclareArg(env, "yfactor", VTYPE_number);
}

Gura_ImplementFunction(glPixelZoom)
{
	GLfloat xfactor = args.GetFloat(0);
	GLfloat yfactor = args.GetFloat(1);
	// GLfloat xfactor, GLfloat yfactor
	::glPixelZoom(xfactor, yfactor);
	return Value::Null;
}

// opengl.glPointSize(size:number):void:map
Gura_DeclareFunction(glPointSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number);
}

Gura_ImplementFunction(glPointSize)
{
	GLfloat size = args.GetFloat(0);
	// GLfloat size
	::glPointSize(size);
	return Value::Null;
}

// opengl.glPolygonMode(face:number, mode:number):void:map
Gura_DeclareFunction(glPolygonMode)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "face", VTYPE_number);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glPolygonMode)
{
	GLenum face = args.GetUInt(0);
	GLenum mode = args.GetUInt(1);
	// GLenum face, GLenum mode
	::glPolygonMode(face, mode);
	return Value::Null;
}

// opengl.glPolygonOffset(factor:number, units:number):void:map
Gura_DeclareFunction(glPolygonOffset)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "factor", VTYPE_number);
	DeclareArg(env, "units", VTYPE_number);
}

Gura_ImplementFunction(glPolygonOffset)
{
	GLfloat factor = args.GetFloat(0);
	GLfloat units = args.GetFloat(1);
	// GLfloat factor, GLfloat units
	::glPolygonOffset(factor, units);
	return Value::Null;
}

// opengl.glPopAttrib():void
Gura_DeclareFunction(glPopAttrib)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glPopAttrib)
{
	// void
	::glPopAttrib();
	return Value::Null;
}

// opengl.glPopClientAttrib():void
Gura_DeclareFunction(glPopClientAttrib)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glPopClientAttrib)
{
	// void
	::glPopClientAttrib();
	return Value::Null;
}

// opengl.glPopMatrix():void
Gura_DeclareFunction(glPopMatrix)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glPopMatrix)
{
	// void
	::glPopMatrix();
	return Value::Null;
}

// opengl.glPopName():void
Gura_DeclareFunction(glPopName)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(glPopName)
{
	// void
	::glPopName();
	return Value::Null;
}

// opengl.glRasterPos2d(x:number, y:number):void:map
Gura_DeclareFunction(glRasterPos2d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos2d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	// GLdouble x, GLdouble y
	::glRasterPos2d(x, y);
	return Value::Null;
}

// opengl.glRasterPos2dv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos2dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos2dv)
{
	DeclareArray(GLdouble, v, 2, 0);
	// const GLdouble *v
	::glRasterPos2dv(v);
	return Value::Null;
}

// opengl.glRasterPos2f(x:number, y:number):void:map
Gura_DeclareFunction(glRasterPos2f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos2f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	// GLfloat x, GLfloat y
	::glRasterPos2f(x, y);
	return Value::Null;
}

// opengl.glRasterPos2fv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos2fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos2fv)
{
	DeclareArray(GLfloat, v, 2, 0);
	// const GLfloat *v
	::glRasterPos2fv(v);
	return Value::Null;
}

// opengl.glRasterPos2i(x:number, y:number):void:map
Gura_DeclareFunction(glRasterPos2i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos2i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	// GLint x, GLint y
	::glRasterPos2i(x, y);
	return Value::Null;
}

// opengl.glRasterPos2iv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos2iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos2iv)
{
	DeclareArray(GLint, v, 2, 0);
	// const GLint *v
	::glRasterPos2iv(v);
	return Value::Null;
}

// opengl.glRasterPos2s(x:number, y:number):void:map
Gura_DeclareFunction(glRasterPos2s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos2s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	// GLshort x, GLshort y
	::glRasterPos2s(x, y);
	return Value::Null;
}

// opengl.glRasterPos2sv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos2sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos2sv)
{
	DeclareArray(GLshort, v, 2, 0);
	// const GLshort *v
	::glRasterPos2sv(v);
	return Value::Null;
}

// opengl.glRasterPos3d(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glRasterPos3d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos3d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	// GLdouble x, GLdouble y, GLdouble z
	::glRasterPos3d(x, y, z);
	return Value::Null;
}

// opengl.glRasterPos3dv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos3dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos3dv)
{
	DeclareArray(GLdouble, v, 3, 0);
	// const GLdouble *v
	::glRasterPos3dv(v);
	return Value::Null;
}

// opengl.glRasterPos3f(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glRasterPos3f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos3f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	// GLfloat x, GLfloat y, GLfloat z
	::glRasterPos3f(x, y, z);
	return Value::Null;
}

// opengl.glRasterPos3fv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos3fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos3fv)
{
	DeclareArray(GLfloat, v, 3, 0);
	// const GLfloat *v
	::glRasterPos3fv(v);
	return Value::Null;
}

// opengl.glRasterPos3i(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glRasterPos3i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos3i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLint z = args.GetInt(2);
	// GLint x, GLint y, GLint z
	::glRasterPos3i(x, y, z);
	return Value::Null;
}

// opengl.glRasterPos3iv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos3iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos3iv)
{
	DeclareArray(GLint, v, 3, 0);
	// const GLint *v
	::glRasterPos3iv(v);
	return Value::Null;
}

// opengl.glRasterPos3s(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glRasterPos3s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos3s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	GLshort z = args.GetShort(2);
	// GLshort x, GLshort y, GLshort z
	::glRasterPos3s(x, y, z);
	return Value::Null;
}

// opengl.glRasterPos3sv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos3sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos3sv)
{
	DeclareArray(GLshort, v, 3, 0);
	// const GLshort *v
	::glRasterPos3sv(v);
	return Value::Null;
}

// opengl.glRasterPos4d(x:number, y:number, z:number, w:number):void:map
Gura_DeclareFunction(glRasterPos4d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos4d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	GLdouble w = args.GetDouble(3);
	// GLdouble x, GLdouble y, GLdouble z, GLdouble w
	::glRasterPos4d(x, y, z, w);
	return Value::Null;
}

// opengl.glRasterPos4dv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos4dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos4dv)
{
	DeclareArray(GLdouble, v, 4, 0);
	// const GLdouble *v
	::glRasterPos4dv(v);
	return Value::Null;
}

// opengl.glRasterPos4f(x:number, y:number, z:number, w:number):void:map
Gura_DeclareFunction(glRasterPos4f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos4f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	GLfloat w = args.GetFloat(3);
	// GLfloat x, GLfloat y, GLfloat z, GLfloat w
	::glRasterPos4f(x, y, z, w);
	return Value::Null;
}

// opengl.glRasterPos4fv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos4fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos4fv)
{
	DeclareArray(GLfloat, v, 4, 0);
	// const GLfloat *v
	::glRasterPos4fv(v);
	return Value::Null;
}

// opengl.glRasterPos4i(x:number, y:number, z:number, w:number):void:map
Gura_DeclareFunction(glRasterPos4i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos4i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLint z = args.GetInt(2);
	GLint w = args.GetInt(3);
	// GLint x, GLint y, GLint z, GLint w
	::glRasterPos4i(x, y, z, w);
	return Value::Null;
}

// opengl.glRasterPos4iv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos4iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos4iv)
{
	DeclareArray(GLint, v, 4, 0);
	// const GLint *v
	::glRasterPos4iv(v);
	return Value::Null;
}

// opengl.glRasterPos4s(x:number, y:number, z:number, w:number):void:map
Gura_DeclareFunction(glRasterPos4s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
}

Gura_ImplementFunction(glRasterPos4s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	GLshort z = args.GetShort(2);
	GLshort w = args.GetShort(3);
	// GLshort x, GLshort y, GLshort z, GLshort w
	::glRasterPos4s(x, y, z, w);
	return Value::Null;
}

// opengl.glRasterPos4sv(v[]:number):void:map
Gura_DeclareFunction(glRasterPos4sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRasterPos4sv)
{
	DeclareArray(GLshort, v, 4, 0);
	// const GLshort *v
	::glRasterPos4sv(v);
	return Value::Null;
}

// opengl.glReadBuffer(mode:number):void:map
Gura_DeclareFunction(glReadBuffer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glReadBuffer)
{
	GLenum mode = args.GetUInt(0);
	// GLenum mode
	::glReadBuffer(mode);
	return Value::Null;
}

// opengl.glRectd(x1:number, y1:number, x2:number, y2:number):void:map
Gura_DeclareFunction(glRectd)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareArg(env, "x2", VTYPE_number);
	DeclareArg(env, "y2", VTYPE_number);
}

Gura_ImplementFunction(glRectd)
{
	GLdouble x1 = args.GetDouble(0);
	GLdouble y1 = args.GetDouble(1);
	GLdouble x2 = args.GetDouble(2);
	GLdouble y2 = args.GetDouble(3);
	// GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2
	::glRectd(x1, y1, x2, y2);
	return Value::Null;
}

// opengl.glRectf(x1:number, y1:number, x2:number, y2:number):void:map
Gura_DeclareFunction(glRectf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareArg(env, "x2", VTYPE_number);
	DeclareArg(env, "y2", VTYPE_number);
}

Gura_ImplementFunction(glRectf)
{
	GLfloat x1 = args.GetFloat(0);
	GLfloat y1 = args.GetFloat(1);
	GLfloat x2 = args.GetFloat(2);
	GLfloat y2 = args.GetFloat(3);
	// GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2
	::glRectf(x1, y1, x2, y2);
	return Value::Null;
}

// opengl.glRecti(x1:number, y1:number, x2:number, y2:number):void:map
Gura_DeclareFunction(glRecti)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareArg(env, "x2", VTYPE_number);
	DeclareArg(env, "y2", VTYPE_number);
}

Gura_ImplementFunction(glRecti)
{
	GLint x1 = args.GetInt(0);
	GLint y1 = args.GetInt(1);
	GLint x2 = args.GetInt(2);
	GLint y2 = args.GetInt(3);
	// GLint x1, GLint y1, GLint x2, GLint y2
	::glRecti(x1, y1, x2, y2);
	return Value::Null;
}

// opengl.glRects(x1:number, y1:number, x2:number, y2:number):void:map
Gura_DeclareFunction(glRects)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareArg(env, "x2", VTYPE_number);
	DeclareArg(env, "y2", VTYPE_number);
}

Gura_ImplementFunction(glRects)
{
	GLshort x1 = args.GetShort(0);
	GLshort y1 = args.GetShort(1);
	GLshort x2 = args.GetShort(2);
	GLshort y2 = args.GetShort(3);
	// GLshort x1, GLshort y1, GLshort x2, GLshort y2
	::glRects(x1, y1, x2, y2);
	return Value::Null;
}

// opengl.glRotated(angle:number, x:number, y:number, z:number):void:map
Gura_DeclareFunction(glRotated)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glRotated)
{
	GLdouble angle = args.GetDouble(0);
	GLdouble x = args.GetDouble(1);
	GLdouble y = args.GetDouble(2);
	GLdouble z = args.GetDouble(3);
	// GLdouble angle, GLdouble x, GLdouble y, GLdouble z
	::glRotated(angle, x, y, z);
	return Value::Null;
}

// opengl.glRotatef(angle:number, x:number, y:number, z:number):void:map
Gura_DeclareFunction(glRotatef)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glRotatef)
{
	GLfloat angle = args.GetFloat(0);
	GLfloat x = args.GetFloat(1);
	GLfloat y = args.GetFloat(2);
	GLfloat z = args.GetFloat(3);
	// GLfloat angle, GLfloat x, GLfloat y, GLfloat z
	::glRotatef(angle, x, y, z);
	return Value::Null;
}

// opengl.glScaled(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glScaled)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glScaled)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	// GLdouble x, GLdouble y, GLdouble z
	::glScaled(x, y, z);
	return Value::Null;
}

// opengl.glScalef(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glScalef)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glScalef)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	// GLfloat x, GLfloat y, GLfloat z
	::glScalef(x, y, z);
	return Value::Null;
}

// opengl.glScissor(x:number, y:number, width:number, height:number):void:map
Gura_DeclareFunction(glScissor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementFunction(glScissor)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLsizei width = args.GetInt(2);
	GLsizei height = args.GetInt(3);
	// GLint x, GLint y, GLsizei width, GLsizei height
	::glScissor(x, y, width, height);
	return Value::Null;
}

// opengl.glShadeModel(mode:number):void:map
Gura_DeclareFunction(glShadeModel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glShadeModel)
{
	GLenum mode = args.GetUInt(0);
	// GLenum mode
	::glShadeModel(mode);
	return Value::Null;
}

// opengl.glStencilFunc(func:number, ref:number, mask:number):void:map
Gura_DeclareFunction(glStencilFunc)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "func", VTYPE_number);
	DeclareArg(env, "ref", VTYPE_number);
	DeclareArg(env, "mask", VTYPE_number);
}

Gura_ImplementFunction(glStencilFunc)
{
	GLenum func = args.GetUInt(0);
	GLint ref = args.GetInt(1);
	GLuint mask = args.GetUInt(2);
	// GLenum func, GLint ref, GLuint mask
	::glStencilFunc(func, ref, mask);
	return Value::Null;
}

// opengl.glStencilMask(mask:number):void:map
Gura_DeclareFunction(glStencilMask)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_number);
}

Gura_ImplementFunction(glStencilMask)
{
	GLuint mask = args.GetUInt(0);
	// GLuint mask
	::glStencilMask(mask);
	return Value::Null;
}

// opengl.glStencilOp(fail:number, zfail:number, zpass:number):void:map
Gura_DeclareFunction(glStencilOp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fail", VTYPE_number);
	DeclareArg(env, "zfail", VTYPE_number);
	DeclareArg(env, "zpass", VTYPE_number);
}

Gura_ImplementFunction(glStencilOp)
{
	GLenum fail = args.GetUInt(0);
	GLenum zfail = args.GetUInt(1);
	GLenum zpass = args.GetUInt(2);
	// GLenum fail, GLenum zfail, GLenum zpass
	::glStencilOp(fail, zfail, zpass);
	return Value::Null;
}

// opengl.glTexCoord1d(s:number):void:map
Gura_DeclareFunction(glTexCoord1d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord1d)
{
	GLdouble s = args.GetDouble(0);
	// GLdouble s
	::glTexCoord1d(s);
	return Value::Null;
}

// opengl.glTexCoord1dv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord1dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord1dv)
{
	DeclareArray(GLdouble, v, 1, 0);
	// const GLdouble *v
	::glTexCoord1dv(v);
	return Value::Null;
}

// opengl.glTexCoord1f(s:number):void:map
Gura_DeclareFunction(glTexCoord1f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord1f)
{
	GLfloat s = args.GetFloat(0);
	// GLfloat s
	::glTexCoord1f(s);
	return Value::Null;
}

// opengl.glTexCoord1fv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord1fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord1fv)
{
	DeclareArray(GLfloat, v, 1, 0);
	// const GLfloat *v
	::glTexCoord1fv(v);
	return Value::Null;
}

// opengl.glTexCoord1i(s:number):void:map
Gura_DeclareFunction(glTexCoord1i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord1i)
{
	GLint s = args.GetInt(0);
	// GLint s
	::glTexCoord1i(s);
	return Value::Null;
}

// opengl.glTexCoord1iv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord1iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord1iv)
{
	DeclareArray(GLint, v, 1, 0);
	// const GLint *v
	::glTexCoord1iv(v);
	return Value::Null;
}

// opengl.glTexCoord1s(s:number):void:map
Gura_DeclareFunction(glTexCoord1s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord1s)
{
	GLshort s = args.GetShort(0);
	// GLshort s
	::glTexCoord1s(s);
	return Value::Null;
}

// opengl.glTexCoord1sv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord1sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord1sv)
{
	DeclareArray(GLshort, v, 1, 0);
	// const GLshort *v
	::glTexCoord1sv(v);
	return Value::Null;
}

// opengl.glTexCoord2d(s:number, t:number):void:map
Gura_DeclareFunction(glTexCoord2d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord2d)
{
	GLdouble s = args.GetDouble(0);
	GLdouble t = args.GetDouble(1);
	// GLdouble s, GLdouble t
	::glTexCoord2d(s, t);
	return Value::Null;
}

// opengl.glTexCoord2dv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord2dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord2dv)
{
	DeclareArray(GLdouble, v, 2, 0);
	// const GLdouble *v
	::glTexCoord2dv(v);
	return Value::Null;
}

// opengl.glTexCoord2f(s:number, t:number):void:map
Gura_DeclareFunction(glTexCoord2f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord2f)
{
	GLfloat s = args.GetFloat(0);
	GLfloat t = args.GetFloat(1);
	// GLfloat s, GLfloat t
	::glTexCoord2f(s, t);
	return Value::Null;
}

// opengl.glTexCoord2fv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord2fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord2fv)
{
	DeclareArray(GLfloat, v, 2, 0);
	// const GLfloat *v
	::glTexCoord2fv(v);
	return Value::Null;
}

// opengl.glTexCoord2i(s:number, t:number):void:map
Gura_DeclareFunction(glTexCoord2i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord2i)
{
	GLint s = args.GetInt(0);
	GLint t = args.GetInt(1);
	// GLint s, GLint t
	::glTexCoord2i(s, t);
	return Value::Null;
}

// opengl.glTexCoord2iv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord2iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord2iv)
{
	DeclareArray(GLint, v, 2, 0);
	// const GLint *v
	::glTexCoord2iv(v);
	return Value::Null;
}

// opengl.glTexCoord2s(s:number, t:number):void:map
Gura_DeclareFunction(glTexCoord2s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord2s)
{
	GLshort s = args.GetShort(0);
	GLshort t = args.GetShort(1);
	// GLshort s, GLshort t
	::glTexCoord2s(s, t);
	return Value::Null;
}

// opengl.glTexCoord2sv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord2sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord2sv)
{
	DeclareArray(GLshort, v, 2, 0);
	// const GLshort *v
	::glTexCoord2sv(v);
	return Value::Null;
}

// opengl.glTexCoord3d(s:number, t:number, r:number):void:map
Gura_DeclareFunction(glTexCoord3d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
	DeclareArg(env, "r", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord3d)
{
	GLdouble s = args.GetDouble(0);
	GLdouble t = args.GetDouble(1);
	GLdouble r = args.GetDouble(2);
	// GLdouble s, GLdouble t, GLdouble r
	::glTexCoord3d(s, t, r);
	return Value::Null;
}

// opengl.glTexCoord3dv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord3dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord3dv)
{
	DeclareArray(GLdouble, v, 3, 0);
	// const GLdouble *v
	::glTexCoord3dv(v);
	return Value::Null;
}

// opengl.glTexCoord3f(s:number, t:number, r:number):void:map
Gura_DeclareFunction(glTexCoord3f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
	DeclareArg(env, "r", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord3f)
{
	GLfloat s = args.GetFloat(0);
	GLfloat t = args.GetFloat(1);
	GLfloat r = args.GetFloat(2);
	// GLfloat s, GLfloat t, GLfloat r
	::glTexCoord3f(s, t, r);
	return Value::Null;
}

// opengl.glTexCoord3fv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord3fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord3fv)
{
	DeclareArray(GLfloat, v, 3, 0);
	// const GLfloat *v
	::glTexCoord3fv(v);
	return Value::Null;
}

// opengl.glTexCoord3i(s:number, t:number, r:number):void:map
Gura_DeclareFunction(glTexCoord3i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
	DeclareArg(env, "r", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord3i)
{
	GLint s = args.GetInt(0);
	GLint t = args.GetInt(1);
	GLint r = args.GetInt(2);
	// GLint s, GLint t, GLint r
	::glTexCoord3i(s, t, r);
	return Value::Null;
}

// opengl.glTexCoord3iv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord3iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord3iv)
{
	DeclareArray(GLint, v, 3, 0);
	// const GLint *v
	::glTexCoord3iv(v);
	return Value::Null;
}

// opengl.glTexCoord3s(s:number, t:number, r:number):void:map
Gura_DeclareFunction(glTexCoord3s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
	DeclareArg(env, "r", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord3s)
{
	GLshort s = args.GetShort(0);
	GLshort t = args.GetShort(1);
	GLshort r = args.GetShort(2);
	// GLshort s, GLshort t, GLshort r
	::glTexCoord3s(s, t, r);
	return Value::Null;
}

// opengl.glTexCoord3sv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord3sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord3sv)
{
	DeclareArray(GLshort, v, 3, 0);
	// const GLshort *v
	::glTexCoord3sv(v);
	return Value::Null;
}

// opengl.glTexCoord4d(s:number, t:number, r:number, q:number):void:map
Gura_DeclareFunction(glTexCoord4d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "q", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord4d)
{
	GLdouble s = args.GetDouble(0);
	GLdouble t = args.GetDouble(1);
	GLdouble r = args.GetDouble(2);
	GLdouble q = args.GetDouble(3);
	// GLdouble s, GLdouble t, GLdouble r, GLdouble q
	::glTexCoord4d(s, t, r, q);
	return Value::Null;
}

// opengl.glTexCoord4dv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord4dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord4dv)
{
	DeclareArray(GLdouble, v, 4, 0);
	// const GLdouble *v
	::glTexCoord4dv(v);
	return Value::Null;
}

// opengl.glTexCoord4f(s:number, t:number, r:number, q:number):void:map
Gura_DeclareFunction(glTexCoord4f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "q", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord4f)
{
	GLfloat s = args.GetFloat(0);
	GLfloat t = args.GetFloat(1);
	GLfloat r = args.GetFloat(2);
	GLfloat q = args.GetFloat(3);
	// GLfloat s, GLfloat t, GLfloat r, GLfloat q
	::glTexCoord4f(s, t, r, q);
	return Value::Null;
}

// opengl.glTexCoord4fv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord4fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord4fv)
{
	DeclareArray(GLfloat, v, 4, 0);
	// const GLfloat *v
	::glTexCoord4fv(v);
	return Value::Null;
}

// opengl.glTexCoord4i(s:number, t:number, r:number, q:number):void:map
Gura_DeclareFunction(glTexCoord4i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "q", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord4i)
{
	GLint s = args.GetInt(0);
	GLint t = args.GetInt(1);
	GLint r = args.GetInt(2);
	GLint q = args.GetInt(3);
	// GLint s, GLint t, GLint r, GLint q
	::glTexCoord4i(s, t, r, q);
	return Value::Null;
}

// opengl.glTexCoord4iv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord4iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord4iv)
{
	DeclareArray(GLint, v, 4, 0);
	// const GLint *v
	::glTexCoord4iv(v);
	return Value::Null;
}

// opengl.glTexCoord4s(s:number, t:number, r:number, q:number):void:map
Gura_DeclareFunction(glTexCoord4s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number);
	DeclareArg(env, "t", VTYPE_number);
	DeclareArg(env, "r", VTYPE_number);
	DeclareArg(env, "q", VTYPE_number);
}

Gura_ImplementFunction(glTexCoord4s)
{
	GLshort s = args.GetShort(0);
	GLshort t = args.GetShort(1);
	GLshort r = args.GetShort(2);
	GLshort q = args.GetShort(3);
	// GLshort s, GLshort t, GLshort r, GLshort q
	::glTexCoord4s(s, t, r, q);
	return Value::Null;
}

// opengl.glTexCoord4sv(v[]:number):void:map
Gura_DeclareFunction(glTexCoord4sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexCoord4sv)
{
	DeclareArray(GLshort, v, 4, 0);
	// const GLshort *v
	::glTexCoord4sv(v);
	return Value::Null;
}

// opengl.glTexEnvf(target:number, pname:number, param:number):void:map
Gura_DeclareFunction(glTexEnvf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glTexEnvf)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLfloat param = args.GetFloat(2);
	// GLenum target, GLenum pname, GLfloat param
	::glTexEnvf(target, pname, param);
	return Value::Null;
}

// opengl.glTexEnvfv(target:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glTexEnvfv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexEnvfv)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLfloat, params, 2);
	// GLenum target, GLenum pname, const GLfloat *params
	::glTexEnvfv(target, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glTexEnvi(target:number, pname:number, param:number):void:map
Gura_DeclareFunction(glTexEnvi)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glTexEnvi)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLint param = args.GetInt(2);
	// GLenum target, GLenum pname, GLint param
	::glTexEnvi(target, pname, param);
	return Value::Null;
}

// opengl.glTexEnviv(target:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glTexEnviv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexEnviv)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLint, params, 2);
	// GLenum target, GLenum pname, const GLint *params
	::glTexEnviv(target, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glTexGend(coord:number, pname:number, param:number):void:map
Gura_DeclareFunction(glTexGend)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "coord", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glTexGend)
{
	GLenum coord = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLdouble param = args.GetDouble(2);
	// GLenum coord, GLenum pname, GLdouble param
	::glTexGend(coord, pname, param);
	return Value::Null;
}

// opengl.glTexGendv(coord:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glTexGendv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "coord", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexGendv)
{
	GLenum coord = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLdouble, params, 2);
	// GLenum coord, GLenum pname, const GLdouble *params
	::glTexGendv(coord, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glTexGenf(coord:number, pname:number, param:number):void:map
Gura_DeclareFunction(glTexGenf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "coord", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glTexGenf)
{
	GLenum coord = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLfloat param = args.GetFloat(2);
	// GLenum coord, GLenum pname, GLfloat param
	::glTexGenf(coord, pname, param);
	return Value::Null;
}

// opengl.glTexGenfv(coord:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glTexGenfv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "coord", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexGenfv)
{
	GLenum coord = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLfloat, params, 2);
	// GLenum coord, GLenum pname, const GLfloat *params
	::glTexGenfv(coord, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glTexGeni(coord:number, pname:number, param:number):void:map
Gura_DeclareFunction(glTexGeni)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "coord", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glTexGeni)
{
	GLenum coord = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLint param = args.GetInt(2);
	// GLenum coord, GLenum pname, GLint param
	::glTexGeni(coord, pname, param);
	return Value::Null;
}

// opengl.glTexGeniv(coord:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glTexGeniv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "coord", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexGeniv)
{
	GLenum coord = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLint, params, 2);
	// GLenum coord, GLenum pname, const GLint *params
	::glTexGeniv(coord, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glTexParameterf(target:number, pname:number, param:number):void:map
Gura_DeclareFunction(glTexParameterf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glTexParameterf)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLfloat param = args.GetFloat(2);
	// GLenum target, GLenum pname, GLfloat param
	::glTexParameterf(target, pname, param);
	return Value::Null;
}

// opengl.glTexParameterfv(target:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glTexParameterfv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexParameterfv)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLfloat, params, 2);
	// GLenum target, GLenum pname, const GLfloat *params
	::glTexParameterfv(target, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glTexParameteri(target:number, pname:number, param:number):void:map
Gura_DeclareFunction(glTexParameteri)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "param", VTYPE_number);
}

Gura_ImplementFunction(glTexParameteri)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	GLint param = args.GetInt(2);
	// GLenum target, GLenum pname, GLint param
	::glTexParameteri(target, pname, param);
	return Value::Null;
}

// opengl.glTexParameteriv(target:number, pname:number, params[]:number):void:map
Gura_DeclareFunction(glTexParameteriv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glTexParameteriv)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLint, params, 2);
	// GLenum target, GLenum pname, const GLint *params
	::glTexParameteriv(target, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glTranslated(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glTranslated)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glTranslated)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	// GLdouble x, GLdouble y, GLdouble z
	::glTranslated(x, y, z);
	return Value::Null;
}

// opengl.glTranslatef(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glTranslatef)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glTranslatef)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	// GLfloat x, GLfloat y, GLfloat z
	::glTranslatef(x, y, z);
	return Value::Null;
}

// opengl.glVertex2d(x:number, y:number):void:map
Gura_DeclareFunction(glVertex2d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementFunction(glVertex2d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	// GLdouble x, GLdouble y
	::glVertex2d(x, y);
	return Value::Null;
}

// opengl.glVertex2dv(v[]:number):void:map
Gura_DeclareFunction(glVertex2dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex2dv)
{
	DeclareArray(GLdouble, v, 2, 0);
	// const GLdouble *v
	::glVertex2dv(v);
	return Value::Null;
}

// opengl.glVertex2f(x:number, y:number):void:map
Gura_DeclareFunction(glVertex2f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementFunction(glVertex2f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	// GLfloat x, GLfloat y
	::glVertex2f(x, y);
	return Value::Null;
}

// opengl.glVertex2fv(v[]:number):void:map
Gura_DeclareFunction(glVertex2fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex2fv)
{
	DeclareArray(GLfloat, v, 2, 0);
	// const GLfloat *v
	::glVertex2fv(v);
	return Value::Null;
}

// opengl.glVertex2i(x:number, y:number):void:map
Gura_DeclareFunction(glVertex2i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementFunction(glVertex2i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	// GLint x, GLint y
	::glVertex2i(x, y);
	return Value::Null;
}

// opengl.glVertex2iv(v[]:number):void:map
Gura_DeclareFunction(glVertex2iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex2iv)
{
	DeclareArray(GLint, v, 2, 0);
	// const GLint *v
	::glVertex2iv(v);
	return Value::Null;
}

// opengl.glVertex2s(x:number, y:number):void:map
Gura_DeclareFunction(glVertex2s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementFunction(glVertex2s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	// GLshort x, GLshort y
	::glVertex2s(x, y);
	return Value::Null;
}

// opengl.glVertex2sv(v[]:number):void:map
Gura_DeclareFunction(glVertex2sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex2sv)
{
	DeclareArray(GLshort, v, 2, 0);
	// const GLshort *v
	::glVertex2sv(v);
	return Value::Null;
}

// opengl.glVertex3d(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glVertex3d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glVertex3d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	// GLdouble x, GLdouble y, GLdouble z
	::glVertex3d(x, y, z);
	return Value::Null;
}

// opengl.glVertex3dv(v[]:number):void:map
Gura_DeclareFunction(glVertex3dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex3dv)
{
	DeclareArray(GLdouble, v, 3, 0);
	// const GLdouble *v
	::glVertex3dv(v);
	return Value::Null;
}

// opengl.glVertex3f(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glVertex3f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glVertex3f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	// GLfloat x, GLfloat y, GLfloat z
	::glVertex3f(x, y, z);
	return Value::Null;
}

// opengl.glVertex3fv(v[]:number):void:map
Gura_DeclareFunction(glVertex3fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex3fv)
{
	DeclareArray(GLfloat, v, 3, 0);
	// const GLfloat *v
	::glVertex3fv(v);
	return Value::Null;
}

// opengl.glVertex3i(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glVertex3i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glVertex3i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLint z = args.GetInt(2);
	// GLint x, GLint y, GLint z
	::glVertex3i(x, y, z);
	return Value::Null;
}

// opengl.glVertex3iv(v[]:number):void:map
Gura_DeclareFunction(glVertex3iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex3iv)
{
	DeclareArray(GLint, v, 3, 0);
	// const GLint *v
	::glVertex3iv(v);
	return Value::Null;
}

// opengl.glVertex3s(x:number, y:number, z:number):void:map
Gura_DeclareFunction(glVertex3s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
}

Gura_ImplementFunction(glVertex3s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	GLshort z = args.GetShort(2);
	// GLshort x, GLshort y, GLshort z
	::glVertex3s(x, y, z);
	return Value::Null;
}

// opengl.glVertex3sv(v[]:number):void:map
Gura_DeclareFunction(glVertex3sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex3sv)
{
	DeclareArray(GLshort, v, 3, 0);
	// const GLshort *v
	::glVertex3sv(v);
	return Value::Null;
}

// opengl.glVertex4d(x:number, y:number, z:number, w:number):void:map
Gura_DeclareFunction(glVertex4d)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
}

Gura_ImplementFunction(glVertex4d)
{
	GLdouble x = args.GetDouble(0);
	GLdouble y = args.GetDouble(1);
	GLdouble z = args.GetDouble(2);
	GLdouble w = args.GetDouble(3);
	// GLdouble x, GLdouble y, GLdouble z, GLdouble w
	::glVertex4d(x, y, z, w);
	return Value::Null;
}

// opengl.glVertex4dv(v[]:number):void:map
Gura_DeclareFunction(glVertex4dv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex4dv)
{
	DeclareArray(GLdouble, v, 4, 0);
	// const GLdouble *v
	::glVertex4dv(v);
	return Value::Null;
}

// opengl.glVertex4f(x:number, y:number, z:number, w:number):void:map
Gura_DeclareFunction(glVertex4f)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
}

Gura_ImplementFunction(glVertex4f)
{
	GLfloat x = args.GetFloat(0);
	GLfloat y = args.GetFloat(1);
	GLfloat z = args.GetFloat(2);
	GLfloat w = args.GetFloat(3);
	// GLfloat x, GLfloat y, GLfloat z, GLfloat w
	::glVertex4f(x, y, z, w);
	return Value::Null;
}

// opengl.glVertex4fv(v[]:number):void:map
Gura_DeclareFunction(glVertex4fv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex4fv)
{
	DeclareArray(GLfloat, v, 4, 0);
	// const GLfloat *v
	::glVertex4fv(v);
	return Value::Null;
}

// opengl.glVertex4i(x:number, y:number, z:number, w:number):void:map
Gura_DeclareFunction(glVertex4i)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
}

Gura_ImplementFunction(glVertex4i)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLint z = args.GetInt(2);
	GLint w = args.GetInt(3);
	// GLint x, GLint y, GLint z, GLint w
	::glVertex4i(x, y, z, w);
	return Value::Null;
}

// opengl.glVertex4iv(v[]:number):void:map
Gura_DeclareFunction(glVertex4iv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex4iv)
{
	DeclareArray(GLint, v, 4, 0);
	// const GLint *v
	::glVertex4iv(v);
	return Value::Null;
}

// opengl.glVertex4s(x:number, y:number, z:number, w:number):void:map
Gura_DeclareFunction(glVertex4s)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "z", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
}

Gura_ImplementFunction(glVertex4s)
{
	GLshort x = args.GetShort(0);
	GLshort y = args.GetShort(1);
	GLshort z = args.GetShort(2);
	GLshort w = args.GetShort(3);
	// GLshort x, GLshort y, GLshort z, GLshort w
	::glVertex4s(x, y, z, w);
	return Value::Null;
}

// opengl.glVertex4sv(v[]:number):void:map
Gura_DeclareFunction(glVertex4sv)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "v", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glVertex4sv)
{
	DeclareArray(GLshort, v, 4, 0);
	// const GLshort *v
	::glVertex4sv(v);
	return Value::Null;
}

// opengl.glViewport(x:number, y:number, width:number, height:number):void:map
Gura_DeclareFunction(glViewport)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementFunction(glViewport)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLsizei width = args.GetInt(2);
	GLsizei height = args.GetInt(3);
	// GLint x, GLint y, GLsizei width, GLsizei height
	::glViewport(x, y, width, height);
	return Value::Null;
}

// Module entry
void ModuleEntrySub(Environment &env, Signal sig)
{
	// value assignment
	Gura_AssignValue(GL_VERSION_1_1,                     Value(GL_VERSION_1_1));
	Gura_AssignValue(GL_ACCUM,                           Value(GL_ACCUM));
	Gura_AssignValue(GL_LOAD,                            Value(GL_LOAD));
	Gura_AssignValue(GL_RETURN,                          Value(GL_RETURN));
	Gura_AssignValue(GL_MULT,                            Value(GL_MULT));
	Gura_AssignValue(GL_ADD,                             Value(GL_ADD));
	Gura_AssignValue(GL_NEVER,                           Value(GL_NEVER));
	Gura_AssignValue(GL_LESS,                            Value(GL_LESS));
	Gura_AssignValue(GL_EQUAL,                           Value(GL_EQUAL));
	Gura_AssignValue(GL_LEQUAL,                          Value(GL_LEQUAL));
	Gura_AssignValue(GL_GREATER,                         Value(GL_GREATER));
	Gura_AssignValue(GL_NOTEQUAL,                        Value(GL_NOTEQUAL));
	Gura_AssignValue(GL_GEQUAL,                          Value(GL_GEQUAL));
	Gura_AssignValue(GL_ALWAYS,                          Value(GL_ALWAYS));
	Gura_AssignValue(GL_CURRENT_BIT,                     Value(GL_CURRENT_BIT));
	Gura_AssignValue(GL_POINT_BIT,                       Value(GL_POINT_BIT));
	Gura_AssignValue(GL_LINE_BIT,                        Value(GL_LINE_BIT));
	Gura_AssignValue(GL_POLYGON_BIT,                     Value(GL_POLYGON_BIT));
	Gura_AssignValue(GL_POLYGON_STIPPLE_BIT,             Value(GL_POLYGON_STIPPLE_BIT));
	Gura_AssignValue(GL_PIXEL_MODE_BIT,                  Value(GL_PIXEL_MODE_BIT));
	Gura_AssignValue(GL_LIGHTING_BIT,                    Value(GL_LIGHTING_BIT));
	Gura_AssignValue(GL_FOG_BIT,                         Value(GL_FOG_BIT));
	Gura_AssignValue(GL_DEPTH_BUFFER_BIT,                Value(GL_DEPTH_BUFFER_BIT));
	Gura_AssignValue(GL_ACCUM_BUFFER_BIT,                Value(GL_ACCUM_BUFFER_BIT));
	Gura_AssignValue(GL_STENCIL_BUFFER_BIT,              Value(GL_STENCIL_BUFFER_BIT));
	Gura_AssignValue(GL_VIEWPORT_BIT,                    Value(GL_VIEWPORT_BIT));
	Gura_AssignValue(GL_TRANSFORM_BIT,                   Value(GL_TRANSFORM_BIT));
	Gura_AssignValue(GL_ENABLE_BIT,                      Value(GL_ENABLE_BIT));
	Gura_AssignValue(GL_COLOR_BUFFER_BIT,                Value(GL_COLOR_BUFFER_BIT));
	Gura_AssignValue(GL_HINT_BIT,                        Value(GL_HINT_BIT));
	Gura_AssignValue(GL_EVAL_BIT,                        Value(GL_EVAL_BIT));
	Gura_AssignValue(GL_LIST_BIT,                        Value(GL_LIST_BIT));
	Gura_AssignValue(GL_TEXTURE_BIT,                     Value(GL_TEXTURE_BIT));
	Gura_AssignValue(GL_SCISSOR_BIT,                     Value(GL_SCISSOR_BIT));
	Gura_AssignValue(GL_ALL_ATTRIB_BITS,                 Value(GL_ALL_ATTRIB_BITS));
	Gura_AssignValue(GL_POINTS,                          Value(GL_POINTS));
	Gura_AssignValue(GL_LINES,                           Value(GL_LINES));
	Gura_AssignValue(GL_LINE_LOOP,                       Value(GL_LINE_LOOP));
	Gura_AssignValue(GL_LINE_STRIP,                      Value(GL_LINE_STRIP));
	Gura_AssignValue(GL_TRIANGLES,                       Value(GL_TRIANGLES));
	Gura_AssignValue(GL_TRIANGLE_STRIP,                  Value(GL_TRIANGLE_STRIP));
	Gura_AssignValue(GL_TRIANGLE_FAN,                    Value(GL_TRIANGLE_FAN));
	Gura_AssignValue(GL_QUADS,                           Value(GL_QUADS));
	Gura_AssignValue(GL_QUAD_STRIP,                      Value(GL_QUAD_STRIP));
	Gura_AssignValue(GL_POLYGON,                         Value(GL_POLYGON));
	Gura_AssignValue(GL_ZERO,                            Value(GL_ZERO));
	Gura_AssignValue(GL_ONE,                             Value(GL_ONE));
	Gura_AssignValue(GL_SRC_COLOR,                       Value(GL_SRC_COLOR));
	Gura_AssignValue(GL_ONE_MINUS_SRC_COLOR,             Value(GL_ONE_MINUS_SRC_COLOR));
	Gura_AssignValue(GL_SRC_ALPHA,                       Value(GL_SRC_ALPHA));
	Gura_AssignValue(GL_ONE_MINUS_SRC_ALPHA,             Value(GL_ONE_MINUS_SRC_ALPHA));
	Gura_AssignValue(GL_DST_ALPHA,                       Value(GL_DST_ALPHA));
	Gura_AssignValue(GL_ONE_MINUS_DST_ALPHA,             Value(GL_ONE_MINUS_DST_ALPHA));
	Gura_AssignValue(GL_DST_COLOR,                       Value(GL_DST_COLOR));
	Gura_AssignValue(GL_ONE_MINUS_DST_COLOR,             Value(GL_ONE_MINUS_DST_COLOR));
	Gura_AssignValue(GL_SRC_ALPHA_SATURATE,              Value(GL_SRC_ALPHA_SATURATE));
	Gura_AssignValue(GL_TRUE,                            Value(GL_TRUE));
	Gura_AssignValue(GL_FALSE,                           Value(GL_FALSE));
	Gura_AssignValue(GL_CLIP_PLANE0,                     Value(GL_CLIP_PLANE0));
	Gura_AssignValue(GL_CLIP_PLANE1,                     Value(GL_CLIP_PLANE1));
	Gura_AssignValue(GL_CLIP_PLANE2,                     Value(GL_CLIP_PLANE2));
	Gura_AssignValue(GL_CLIP_PLANE3,                     Value(GL_CLIP_PLANE3));
	Gura_AssignValue(GL_CLIP_PLANE4,                     Value(GL_CLIP_PLANE4));
	Gura_AssignValue(GL_CLIP_PLANE5,                     Value(GL_CLIP_PLANE5));
	Gura_AssignValue(GL_BYTE,                            Value(GL_BYTE));
	Gura_AssignValue(GL_UNSIGNED_BYTE,                   Value(GL_UNSIGNED_BYTE));
	Gura_AssignValue(GL_SHORT,                           Value(GL_SHORT));
	Gura_AssignValue(GL_UNSIGNED_SHORT,                  Value(GL_UNSIGNED_SHORT));
	Gura_AssignValue(GL_INT,                             Value(GL_INT));
	Gura_AssignValue(GL_UNSIGNED_INT,                    Value(GL_UNSIGNED_INT));
	Gura_AssignValue(GL_FLOAT,                           Value(GL_FLOAT));
	Gura_AssignValue(GL_2_BYTES,                         Value(GL_2_BYTES));
	Gura_AssignValue(GL_3_BYTES,                         Value(GL_3_BYTES));
	Gura_AssignValue(GL_4_BYTES,                         Value(GL_4_BYTES));
	Gura_AssignValue(GL_DOUBLE,                          Value(GL_DOUBLE));
	Gura_AssignValue(GL_NONE,                            Value(GL_NONE));
	Gura_AssignValue(GL_FRONT_LEFT,                      Value(GL_FRONT_LEFT));
	Gura_AssignValue(GL_FRONT_RIGHT,                     Value(GL_FRONT_RIGHT));
	Gura_AssignValue(GL_BACK_LEFT,                       Value(GL_BACK_LEFT));
	Gura_AssignValue(GL_BACK_RIGHT,                      Value(GL_BACK_RIGHT));
	Gura_AssignValue(GL_FRONT,                           Value(GL_FRONT));
	Gura_AssignValue(GL_BACK,                            Value(GL_BACK));
	Gura_AssignValue(GL_LEFT,                            Value(GL_LEFT));
	Gura_AssignValue(GL_RIGHT,                           Value(GL_RIGHT));
	Gura_AssignValue(GL_FRONT_AND_BACK,                  Value(GL_FRONT_AND_BACK));
	Gura_AssignValue(GL_AUX0,                            Value(GL_AUX0));
	Gura_AssignValue(GL_AUX1,                            Value(GL_AUX1));
	Gura_AssignValue(GL_AUX2,                            Value(GL_AUX2));
	Gura_AssignValue(GL_AUX3,                            Value(GL_AUX3));
	Gura_AssignValue(GL_NO_ERROR,                        Value(GL_NO_ERROR));
	Gura_AssignValue(GL_INVALID_ENUM,                    Value(GL_INVALID_ENUM));
	Gura_AssignValue(GL_INVALID_VALUE,                   Value(GL_INVALID_VALUE));
	Gura_AssignValue(GL_INVALID_OPERATION,               Value(GL_INVALID_OPERATION));
	Gura_AssignValue(GL_STACK_OVERFLOW,                  Value(GL_STACK_OVERFLOW));
	Gura_AssignValue(GL_STACK_UNDERFLOW,                 Value(GL_STACK_UNDERFLOW));
	Gura_AssignValue(GL_OUT_OF_MEMORY,                   Value(GL_OUT_OF_MEMORY));
	Gura_AssignValue(GL_2D,                              Value(GL_2D));
	Gura_AssignValue(GL_3D,                              Value(GL_3D));
	Gura_AssignValue(GL_3D_COLOR,                        Value(GL_3D_COLOR));
	Gura_AssignValue(GL_3D_COLOR_TEXTURE,                Value(GL_3D_COLOR_TEXTURE));
	Gura_AssignValue(GL_4D_COLOR_TEXTURE,                Value(GL_4D_COLOR_TEXTURE));
	Gura_AssignValue(GL_PASS_THROUGH_TOKEN,              Value(GL_PASS_THROUGH_TOKEN));
	Gura_AssignValue(GL_POINT_TOKEN,                     Value(GL_POINT_TOKEN));
	Gura_AssignValue(GL_LINE_TOKEN,                      Value(GL_LINE_TOKEN));
	Gura_AssignValue(GL_POLYGON_TOKEN,                   Value(GL_POLYGON_TOKEN));
	Gura_AssignValue(GL_BITMAP_TOKEN,                    Value(GL_BITMAP_TOKEN));
	Gura_AssignValue(GL_DRAW_PIXEL_TOKEN,                Value(GL_DRAW_PIXEL_TOKEN));
	Gura_AssignValue(GL_COPY_PIXEL_TOKEN,                Value(GL_COPY_PIXEL_TOKEN));
	Gura_AssignValue(GL_LINE_RESET_TOKEN,                Value(GL_LINE_RESET_TOKEN));
	Gura_AssignValue(GL_EXP,                             Value(GL_EXP));
	Gura_AssignValue(GL_EXP2,                            Value(GL_EXP2));
	Gura_AssignValue(GL_CW,                              Value(GL_CW));
	Gura_AssignValue(GL_CCW,                             Value(GL_CCW));
	Gura_AssignValue(GL_COEFF,                           Value(GL_COEFF));
	Gura_AssignValue(GL_ORDER,                           Value(GL_ORDER));
	Gura_AssignValue(GL_DOMAIN,                          Value(GL_DOMAIN));
	Gura_AssignValue(GL_CURRENT_COLOR,                   Value(GL_CURRENT_COLOR));
	Gura_AssignValue(GL_CURRENT_INDEX,                   Value(GL_CURRENT_INDEX));
	Gura_AssignValue(GL_CURRENT_NORMAL,                  Value(GL_CURRENT_NORMAL));
	Gura_AssignValue(GL_CURRENT_TEXTURE_COORDS,          Value(GL_CURRENT_TEXTURE_COORDS));
	Gura_AssignValue(GL_CURRENT_RASTER_COLOR,            Value(GL_CURRENT_RASTER_COLOR));
	Gura_AssignValue(GL_CURRENT_RASTER_INDEX,            Value(GL_CURRENT_RASTER_INDEX));
	Gura_AssignValue(GL_CURRENT_RASTER_TEXTURE_COORDS,   Value(GL_CURRENT_RASTER_TEXTURE_COORDS));
	Gura_AssignValue(GL_CURRENT_RASTER_POSITION,         Value(GL_CURRENT_RASTER_POSITION));
	Gura_AssignValue(GL_CURRENT_RASTER_POSITION_VALID,   Value(GL_CURRENT_RASTER_POSITION_VALID));
	Gura_AssignValue(GL_CURRENT_RASTER_DISTANCE,         Value(GL_CURRENT_RASTER_DISTANCE));
	Gura_AssignValue(GL_POINT_SMOOTH,                    Value(GL_POINT_SMOOTH));
	Gura_AssignValue(GL_POINT_SIZE,                      Value(GL_POINT_SIZE));
	Gura_AssignValue(GL_POINT_SIZE_RANGE,                Value(GL_POINT_SIZE_RANGE));
	Gura_AssignValue(GL_POINT_SIZE_GRANULARITY,          Value(GL_POINT_SIZE_GRANULARITY));
	Gura_AssignValue(GL_LINE_SMOOTH,                     Value(GL_LINE_SMOOTH));
	Gura_AssignValue(GL_LINE_WIDTH,                      Value(GL_LINE_WIDTH));
	Gura_AssignValue(GL_LINE_WIDTH_RANGE,                Value(GL_LINE_WIDTH_RANGE));
	Gura_AssignValue(GL_LINE_WIDTH_GRANULARITY,          Value(GL_LINE_WIDTH_GRANULARITY));
	Gura_AssignValue(GL_LINE_STIPPLE,                    Value(GL_LINE_STIPPLE));
	Gura_AssignValue(GL_LINE_STIPPLE_PATTERN,            Value(GL_LINE_STIPPLE_PATTERN));
	Gura_AssignValue(GL_LINE_STIPPLE_REPEAT,             Value(GL_LINE_STIPPLE_REPEAT));
	Gura_AssignValue(GL_LIST_MODE,                       Value(GL_LIST_MODE));
	Gura_AssignValue(GL_MAX_LIST_NESTING,                Value(GL_MAX_LIST_NESTING));
	Gura_AssignValue(GL_LIST_BASE,                       Value(GL_LIST_BASE));
	Gura_AssignValue(GL_LIST_INDEX,                      Value(GL_LIST_INDEX));
	Gura_AssignValue(GL_POLYGON_MODE,                    Value(GL_POLYGON_MODE));
	Gura_AssignValue(GL_POLYGON_SMOOTH,                  Value(GL_POLYGON_SMOOTH));
	Gura_AssignValue(GL_POLYGON_STIPPLE,                 Value(GL_POLYGON_STIPPLE));
	Gura_AssignValue(GL_EDGE_FLAG,                       Value(GL_EDGE_FLAG));
	Gura_AssignValue(GL_CULL_FACE,                       Value(GL_CULL_FACE));
	Gura_AssignValue(GL_CULL_FACE_MODE,                  Value(GL_CULL_FACE_MODE));
	Gura_AssignValue(GL_FRONT_FACE,                      Value(GL_FRONT_FACE));
	Gura_AssignValue(GL_LIGHTING,                        Value(GL_LIGHTING));
	Gura_AssignValue(GL_LIGHT_MODEL_LOCAL_VIEWER,        Value(GL_LIGHT_MODEL_LOCAL_VIEWER));
	Gura_AssignValue(GL_LIGHT_MODEL_TWO_SIDE,            Value(GL_LIGHT_MODEL_TWO_SIDE));
	Gura_AssignValue(GL_LIGHT_MODEL_AMBIENT,             Value(GL_LIGHT_MODEL_AMBIENT));
	Gura_AssignValue(GL_SHADE_MODEL,                     Value(GL_SHADE_MODEL));
	Gura_AssignValue(GL_COLOR_MATERIAL_FACE,             Value(GL_COLOR_MATERIAL_FACE));
	Gura_AssignValue(GL_COLOR_MATERIAL_PARAMETER,        Value(GL_COLOR_MATERIAL_PARAMETER));
	Gura_AssignValue(GL_COLOR_MATERIAL,                  Value(GL_COLOR_MATERIAL));
	Gura_AssignValue(GL_FOG,                             Value(GL_FOG));
	Gura_AssignValue(GL_FOG_INDEX,                       Value(GL_FOG_INDEX));
	Gura_AssignValue(GL_FOG_DENSITY,                     Value(GL_FOG_DENSITY));
	Gura_AssignValue(GL_FOG_START,                       Value(GL_FOG_START));
	Gura_AssignValue(GL_FOG_END,                         Value(GL_FOG_END));
	Gura_AssignValue(GL_FOG_MODE,                        Value(GL_FOG_MODE));
	Gura_AssignValue(GL_FOG_COLOR,                       Value(GL_FOG_COLOR));
	Gura_AssignValue(GL_DEPTH_RANGE,                     Value(GL_DEPTH_RANGE));
	Gura_AssignValue(GL_DEPTH_TEST,                      Value(GL_DEPTH_TEST));
	Gura_AssignValue(GL_DEPTH_WRITEMASK,                 Value(GL_DEPTH_WRITEMASK));
	Gura_AssignValue(GL_DEPTH_CLEAR_VALUE,               Value(GL_DEPTH_CLEAR_VALUE));
	Gura_AssignValue(GL_DEPTH_FUNC,                      Value(GL_DEPTH_FUNC));
	Gura_AssignValue(GL_ACCUM_CLEAR_VALUE,               Value(GL_ACCUM_CLEAR_VALUE));
	Gura_AssignValue(GL_STENCIL_TEST,                    Value(GL_STENCIL_TEST));
	Gura_AssignValue(GL_STENCIL_CLEAR_VALUE,             Value(GL_STENCIL_CLEAR_VALUE));
	Gura_AssignValue(GL_STENCIL_FUNC,                    Value(GL_STENCIL_FUNC));
	Gura_AssignValue(GL_STENCIL_VALUE_MASK,              Value(GL_STENCIL_VALUE_MASK));
	Gura_AssignValue(GL_STENCIL_FAIL,                    Value(GL_STENCIL_FAIL));
	Gura_AssignValue(GL_STENCIL_PASS_DEPTH_FAIL,         Value(GL_STENCIL_PASS_DEPTH_FAIL));
	Gura_AssignValue(GL_STENCIL_PASS_DEPTH_PASS,         Value(GL_STENCIL_PASS_DEPTH_PASS));
	Gura_AssignValue(GL_STENCIL_REF,                     Value(GL_STENCIL_REF));
	Gura_AssignValue(GL_STENCIL_WRITEMASK,               Value(GL_STENCIL_WRITEMASK));
	Gura_AssignValue(GL_MATRIX_MODE,                     Value(GL_MATRIX_MODE));
	Gura_AssignValue(GL_NORMALIZE,                       Value(GL_NORMALIZE));
	Gura_AssignValue(GL_VIEWPORT,                        Value(GL_VIEWPORT));
	Gura_AssignValue(GL_MODELVIEW_STACK_DEPTH,           Value(GL_MODELVIEW_STACK_DEPTH));
	Gura_AssignValue(GL_PROJECTION_STACK_DEPTH,          Value(GL_PROJECTION_STACK_DEPTH));
	Gura_AssignValue(GL_TEXTURE_STACK_DEPTH,             Value(GL_TEXTURE_STACK_DEPTH));
	Gura_AssignValue(GL_MODELVIEW_MATRIX,                Value(GL_MODELVIEW_MATRIX));
	Gura_AssignValue(GL_PROJECTION_MATRIX,               Value(GL_PROJECTION_MATRIX));
	Gura_AssignValue(GL_TEXTURE_MATRIX,                  Value(GL_TEXTURE_MATRIX));
	Gura_AssignValue(GL_ATTRIB_STACK_DEPTH,              Value(GL_ATTRIB_STACK_DEPTH));
	Gura_AssignValue(GL_CLIENT_ATTRIB_STACK_DEPTH,       Value(GL_CLIENT_ATTRIB_STACK_DEPTH));
	Gura_AssignValue(GL_ALPHA_TEST,                      Value(GL_ALPHA_TEST));
	Gura_AssignValue(GL_ALPHA_TEST_FUNC,                 Value(GL_ALPHA_TEST_FUNC));
	Gura_AssignValue(GL_ALPHA_TEST_REF,                  Value(GL_ALPHA_TEST_REF));
	Gura_AssignValue(GL_DITHER,                          Value(GL_DITHER));
	Gura_AssignValue(GL_BLEND_DST,                       Value(GL_BLEND_DST));
	Gura_AssignValue(GL_BLEND_SRC,                       Value(GL_BLEND_SRC));
	Gura_AssignValue(GL_BLEND,                           Value(GL_BLEND));
	Gura_AssignValue(GL_LOGIC_OP_MODE,                   Value(GL_LOGIC_OP_MODE));
	Gura_AssignValue(GL_INDEX_LOGIC_OP,                  Value(GL_INDEX_LOGIC_OP));
	Gura_AssignValue(GL_COLOR_LOGIC_OP,                  Value(GL_COLOR_LOGIC_OP));
	Gura_AssignValue(GL_AUX_BUFFERS,                     Value(GL_AUX_BUFFERS));
	Gura_AssignValue(GL_DRAW_BUFFER,                     Value(GL_DRAW_BUFFER));
	Gura_AssignValue(GL_READ_BUFFER,                     Value(GL_READ_BUFFER));
	Gura_AssignValue(GL_SCISSOR_BOX,                     Value(GL_SCISSOR_BOX));
	Gura_AssignValue(GL_SCISSOR_TEST,                    Value(GL_SCISSOR_TEST));
	Gura_AssignValue(GL_INDEX_CLEAR_VALUE,               Value(GL_INDEX_CLEAR_VALUE));
	Gura_AssignValue(GL_INDEX_WRITEMASK,                 Value(GL_INDEX_WRITEMASK));
	Gura_AssignValue(GL_COLOR_CLEAR_VALUE,               Value(GL_COLOR_CLEAR_VALUE));
	Gura_AssignValue(GL_COLOR_WRITEMASK,                 Value(GL_COLOR_WRITEMASK));
	Gura_AssignValue(GL_INDEX_MODE,                      Value(GL_INDEX_MODE));
	Gura_AssignValue(GL_RGBA_MODE,                       Value(GL_RGBA_MODE));
	Gura_AssignValue(GL_DOUBLEBUFFER,                    Value(GL_DOUBLEBUFFER));
	Gura_AssignValue(GL_STEREO,                          Value(GL_STEREO));
	Gura_AssignValue(GL_RENDER_MODE,                     Value(GL_RENDER_MODE));
	Gura_AssignValue(GL_PERSPECTIVE_CORRECTION_HINT,     Value(GL_PERSPECTIVE_CORRECTION_HINT));
	Gura_AssignValue(GL_POINT_SMOOTH_HINT,               Value(GL_POINT_SMOOTH_HINT));
	Gura_AssignValue(GL_LINE_SMOOTH_HINT,                Value(GL_LINE_SMOOTH_HINT));
	Gura_AssignValue(GL_POLYGON_SMOOTH_HINT,             Value(GL_POLYGON_SMOOTH_HINT));
	Gura_AssignValue(GL_FOG_HINT,                        Value(GL_FOG_HINT));
	Gura_AssignValue(GL_TEXTURE_GEN_S,                   Value(GL_TEXTURE_GEN_S));
	Gura_AssignValue(GL_TEXTURE_GEN_T,                   Value(GL_TEXTURE_GEN_T));
	Gura_AssignValue(GL_TEXTURE_GEN_R,                   Value(GL_TEXTURE_GEN_R));
	Gura_AssignValue(GL_TEXTURE_GEN_Q,                   Value(GL_TEXTURE_GEN_Q));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_I,                Value(GL_PIXEL_MAP_I_TO_I));
	Gura_AssignValue(GL_PIXEL_MAP_S_TO_S,                Value(GL_PIXEL_MAP_S_TO_S));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_R,                Value(GL_PIXEL_MAP_I_TO_R));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_G,                Value(GL_PIXEL_MAP_I_TO_G));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_B,                Value(GL_PIXEL_MAP_I_TO_B));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_A,                Value(GL_PIXEL_MAP_I_TO_A));
	Gura_AssignValue(GL_PIXEL_MAP_R_TO_R,                Value(GL_PIXEL_MAP_R_TO_R));
	Gura_AssignValue(GL_PIXEL_MAP_G_TO_G,                Value(GL_PIXEL_MAP_G_TO_G));
	Gura_AssignValue(GL_PIXEL_MAP_B_TO_B,                Value(GL_PIXEL_MAP_B_TO_B));
	Gura_AssignValue(GL_PIXEL_MAP_A_TO_A,                Value(GL_PIXEL_MAP_A_TO_A));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_I_SIZE,           Value(GL_PIXEL_MAP_I_TO_I_SIZE));
	Gura_AssignValue(GL_PIXEL_MAP_S_TO_S_SIZE,           Value(GL_PIXEL_MAP_S_TO_S_SIZE));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_R_SIZE,           Value(GL_PIXEL_MAP_I_TO_R_SIZE));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_G_SIZE,           Value(GL_PIXEL_MAP_I_TO_G_SIZE));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_B_SIZE,           Value(GL_PIXEL_MAP_I_TO_B_SIZE));
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_A_SIZE,           Value(GL_PIXEL_MAP_I_TO_A_SIZE));
	Gura_AssignValue(GL_PIXEL_MAP_R_TO_R_SIZE,           Value(GL_PIXEL_MAP_R_TO_R_SIZE));
	Gura_AssignValue(GL_PIXEL_MAP_G_TO_G_SIZE,           Value(GL_PIXEL_MAP_G_TO_G_SIZE));
	Gura_AssignValue(GL_PIXEL_MAP_B_TO_B_SIZE,           Value(GL_PIXEL_MAP_B_TO_B_SIZE));
	Gura_AssignValue(GL_PIXEL_MAP_A_TO_A_SIZE,           Value(GL_PIXEL_MAP_A_TO_A_SIZE));
	Gura_AssignValue(GL_UNPACK_SWAP_BYTES,               Value(GL_UNPACK_SWAP_BYTES));
	Gura_AssignValue(GL_UNPACK_LSB_FIRST,                Value(GL_UNPACK_LSB_FIRST));
	Gura_AssignValue(GL_UNPACK_ROW_LENGTH,               Value(GL_UNPACK_ROW_LENGTH));
	Gura_AssignValue(GL_UNPACK_SKIP_ROWS,                Value(GL_UNPACK_SKIP_ROWS));
	Gura_AssignValue(GL_UNPACK_SKIP_PIXELS,              Value(GL_UNPACK_SKIP_PIXELS));
	Gura_AssignValue(GL_UNPACK_ALIGNMENT,                Value(GL_UNPACK_ALIGNMENT));
	Gura_AssignValue(GL_PACK_SWAP_BYTES,                 Value(GL_PACK_SWAP_BYTES));
	Gura_AssignValue(GL_PACK_LSB_FIRST,                  Value(GL_PACK_LSB_FIRST));
	Gura_AssignValue(GL_PACK_ROW_LENGTH,                 Value(GL_PACK_ROW_LENGTH));
	Gura_AssignValue(GL_PACK_SKIP_ROWS,                  Value(GL_PACK_SKIP_ROWS));
	Gura_AssignValue(GL_PACK_SKIP_PIXELS,                Value(GL_PACK_SKIP_PIXELS));
	Gura_AssignValue(GL_PACK_ALIGNMENT,                  Value(GL_PACK_ALIGNMENT));
	Gura_AssignValue(GL_MAP_COLOR,                       Value(GL_MAP_COLOR));
	Gura_AssignValue(GL_MAP_STENCIL,                     Value(GL_MAP_STENCIL));
	Gura_AssignValue(GL_INDEX_SHIFT,                     Value(GL_INDEX_SHIFT));
	Gura_AssignValue(GL_INDEX_OFFSET,                    Value(GL_INDEX_OFFSET));
	Gura_AssignValue(GL_RED_SCALE,                       Value(GL_RED_SCALE));
	Gura_AssignValue(GL_RED_BIAS,                        Value(GL_RED_BIAS));
	Gura_AssignValue(GL_ZOOM_X,                          Value(GL_ZOOM_X));
	Gura_AssignValue(GL_ZOOM_Y,                          Value(GL_ZOOM_Y));
	Gura_AssignValue(GL_GREEN_SCALE,                     Value(GL_GREEN_SCALE));
	Gura_AssignValue(GL_GREEN_BIAS,                      Value(GL_GREEN_BIAS));
	Gura_AssignValue(GL_BLUE_SCALE,                      Value(GL_BLUE_SCALE));
	Gura_AssignValue(GL_BLUE_BIAS,                       Value(GL_BLUE_BIAS));
	Gura_AssignValue(GL_ALPHA_SCALE,                     Value(GL_ALPHA_SCALE));
	Gura_AssignValue(GL_ALPHA_BIAS,                      Value(GL_ALPHA_BIAS));
	Gura_AssignValue(GL_DEPTH_SCALE,                     Value(GL_DEPTH_SCALE));
	Gura_AssignValue(GL_DEPTH_BIAS,                      Value(GL_DEPTH_BIAS));
	Gura_AssignValue(GL_MAX_EVAL_ORDER,                  Value(GL_MAX_EVAL_ORDER));
	Gura_AssignValue(GL_MAX_LIGHTS,                      Value(GL_MAX_LIGHTS));
	Gura_AssignValue(GL_MAX_CLIP_PLANES,                 Value(GL_MAX_CLIP_PLANES));
	Gura_AssignValue(GL_MAX_TEXTURE_SIZE,                Value(GL_MAX_TEXTURE_SIZE));
	Gura_AssignValue(GL_MAX_PIXEL_MAP_TABLE,             Value(GL_MAX_PIXEL_MAP_TABLE));
	Gura_AssignValue(GL_MAX_ATTRIB_STACK_DEPTH,          Value(GL_MAX_ATTRIB_STACK_DEPTH));
	Gura_AssignValue(GL_MAX_MODELVIEW_STACK_DEPTH,       Value(GL_MAX_MODELVIEW_STACK_DEPTH));
	Gura_AssignValue(GL_MAX_NAME_STACK_DEPTH,            Value(GL_MAX_NAME_STACK_DEPTH));
	Gura_AssignValue(GL_MAX_PROJECTION_STACK_DEPTH,      Value(GL_MAX_PROJECTION_STACK_DEPTH));
	Gura_AssignValue(GL_MAX_TEXTURE_STACK_DEPTH,         Value(GL_MAX_TEXTURE_STACK_DEPTH));
	Gura_AssignValue(GL_MAX_VIEWPORT_DIMS,               Value(GL_MAX_VIEWPORT_DIMS));
	Gura_AssignValue(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH,   Value(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH));
	Gura_AssignValue(GL_SUBPIXEL_BITS,                   Value(GL_SUBPIXEL_BITS));
	Gura_AssignValue(GL_INDEX_BITS,                      Value(GL_INDEX_BITS));
	Gura_AssignValue(GL_RED_BITS,                        Value(GL_RED_BITS));
	Gura_AssignValue(GL_GREEN_BITS,                      Value(GL_GREEN_BITS));
	Gura_AssignValue(GL_BLUE_BITS,                       Value(GL_BLUE_BITS));
	Gura_AssignValue(GL_ALPHA_BITS,                      Value(GL_ALPHA_BITS));
	Gura_AssignValue(GL_DEPTH_BITS,                      Value(GL_DEPTH_BITS));
	Gura_AssignValue(GL_STENCIL_BITS,                    Value(GL_STENCIL_BITS));
	Gura_AssignValue(GL_ACCUM_RED_BITS,                  Value(GL_ACCUM_RED_BITS));
	Gura_AssignValue(GL_ACCUM_GREEN_BITS,                Value(GL_ACCUM_GREEN_BITS));
	Gura_AssignValue(GL_ACCUM_BLUE_BITS,                 Value(GL_ACCUM_BLUE_BITS));
	Gura_AssignValue(GL_ACCUM_ALPHA_BITS,                Value(GL_ACCUM_ALPHA_BITS));
	Gura_AssignValue(GL_NAME_STACK_DEPTH,                Value(GL_NAME_STACK_DEPTH));
	Gura_AssignValue(GL_AUTO_NORMAL,                     Value(GL_AUTO_NORMAL));
	Gura_AssignValue(GL_MAP1_COLOR_4,                    Value(GL_MAP1_COLOR_4));
	Gura_AssignValue(GL_MAP1_INDEX,                      Value(GL_MAP1_INDEX));
	Gura_AssignValue(GL_MAP1_NORMAL,                     Value(GL_MAP1_NORMAL));
	Gura_AssignValue(GL_MAP1_TEXTURE_COORD_1,            Value(GL_MAP1_TEXTURE_COORD_1));
	Gura_AssignValue(GL_MAP1_TEXTURE_COORD_2,            Value(GL_MAP1_TEXTURE_COORD_2));
	Gura_AssignValue(GL_MAP1_TEXTURE_COORD_3,            Value(GL_MAP1_TEXTURE_COORD_3));
	Gura_AssignValue(GL_MAP1_TEXTURE_COORD_4,            Value(GL_MAP1_TEXTURE_COORD_4));
	Gura_AssignValue(GL_MAP1_VERTEX_3,                   Value(GL_MAP1_VERTEX_3));
	Gura_AssignValue(GL_MAP1_VERTEX_4,                   Value(GL_MAP1_VERTEX_4));
	Gura_AssignValue(GL_MAP2_COLOR_4,                    Value(GL_MAP2_COLOR_4));
	Gura_AssignValue(GL_MAP2_INDEX,                      Value(GL_MAP2_INDEX));
	Gura_AssignValue(GL_MAP2_NORMAL,                     Value(GL_MAP2_NORMAL));
	Gura_AssignValue(GL_MAP2_TEXTURE_COORD_1,            Value(GL_MAP2_TEXTURE_COORD_1));
	Gura_AssignValue(GL_MAP2_TEXTURE_COORD_2,            Value(GL_MAP2_TEXTURE_COORD_2));
	Gura_AssignValue(GL_MAP2_TEXTURE_COORD_3,            Value(GL_MAP2_TEXTURE_COORD_3));
	Gura_AssignValue(GL_MAP2_TEXTURE_COORD_4,            Value(GL_MAP2_TEXTURE_COORD_4));
	Gura_AssignValue(GL_MAP2_VERTEX_3,                   Value(GL_MAP2_VERTEX_3));
	Gura_AssignValue(GL_MAP2_VERTEX_4,                   Value(GL_MAP2_VERTEX_4));
	Gura_AssignValue(GL_MAP1_GRID_DOMAIN,                Value(GL_MAP1_GRID_DOMAIN));
	Gura_AssignValue(GL_MAP1_GRID_SEGMENTS,              Value(GL_MAP1_GRID_SEGMENTS));
	Gura_AssignValue(GL_MAP2_GRID_DOMAIN,                Value(GL_MAP2_GRID_DOMAIN));
	Gura_AssignValue(GL_MAP2_GRID_SEGMENTS,              Value(GL_MAP2_GRID_SEGMENTS));
	Gura_AssignValue(GL_TEXTURE_1D,                      Value(GL_TEXTURE_1D));
	Gura_AssignValue(GL_TEXTURE_2D,                      Value(GL_TEXTURE_2D));
	Gura_AssignValue(GL_FEEDBACK_BUFFER_POINTER,         Value(GL_FEEDBACK_BUFFER_POINTER));
	Gura_AssignValue(GL_FEEDBACK_BUFFER_SIZE,            Value(GL_FEEDBACK_BUFFER_SIZE));
	Gura_AssignValue(GL_FEEDBACK_BUFFER_TYPE,            Value(GL_FEEDBACK_BUFFER_TYPE));
	Gura_AssignValue(GL_SELECTION_BUFFER_POINTER,        Value(GL_SELECTION_BUFFER_POINTER));
	Gura_AssignValue(GL_SELECTION_BUFFER_SIZE,           Value(GL_SELECTION_BUFFER_SIZE));
	Gura_AssignValue(GL_TEXTURE_WIDTH,                   Value(GL_TEXTURE_WIDTH));
	Gura_AssignValue(GL_TEXTURE_HEIGHT,                  Value(GL_TEXTURE_HEIGHT));
	Gura_AssignValue(GL_TEXTURE_INTERNAL_FORMAT,         Value(GL_TEXTURE_INTERNAL_FORMAT));
	Gura_AssignValue(GL_TEXTURE_BORDER_COLOR,            Value(GL_TEXTURE_BORDER_COLOR));
	Gura_AssignValue(GL_TEXTURE_BORDER,                  Value(GL_TEXTURE_BORDER));
	Gura_AssignValue(GL_DONT_CARE,                       Value(GL_DONT_CARE));
	Gura_AssignValue(GL_FASTEST,                         Value(GL_FASTEST));
	Gura_AssignValue(GL_NICEST,                          Value(GL_NICEST));
	Gura_AssignValue(GL_LIGHT0,                          Value(GL_LIGHT0));
	Gura_AssignValue(GL_LIGHT1,                          Value(GL_LIGHT1));
	Gura_AssignValue(GL_LIGHT2,                          Value(GL_LIGHT2));
	Gura_AssignValue(GL_LIGHT3,                          Value(GL_LIGHT3));
	Gura_AssignValue(GL_LIGHT4,                          Value(GL_LIGHT4));
	Gura_AssignValue(GL_LIGHT5,                          Value(GL_LIGHT5));
	Gura_AssignValue(GL_LIGHT6,                          Value(GL_LIGHT6));
	Gura_AssignValue(GL_LIGHT7,                          Value(GL_LIGHT7));
	Gura_AssignValue(GL_AMBIENT,                         Value(GL_AMBIENT));
	Gura_AssignValue(GL_DIFFUSE,                         Value(GL_DIFFUSE));
	Gura_AssignValue(GL_SPECULAR,                        Value(GL_SPECULAR));
	Gura_AssignValue(GL_POSITION,                        Value(GL_POSITION));
	Gura_AssignValue(GL_SPOT_DIRECTION,                  Value(GL_SPOT_DIRECTION));
	Gura_AssignValue(GL_SPOT_EXPONENT,                   Value(GL_SPOT_EXPONENT));
	Gura_AssignValue(GL_SPOT_CUTOFF,                     Value(GL_SPOT_CUTOFF));
	Gura_AssignValue(GL_CONSTANT_ATTENUATION,            Value(GL_CONSTANT_ATTENUATION));
	Gura_AssignValue(GL_LINEAR_ATTENUATION,              Value(GL_LINEAR_ATTENUATION));
	Gura_AssignValue(GL_QUADRATIC_ATTENUATION,           Value(GL_QUADRATIC_ATTENUATION));
	Gura_AssignValue(GL_COMPILE,                         Value(GL_COMPILE));
	Gura_AssignValue(GL_COMPILE_AND_EXECUTE,             Value(GL_COMPILE_AND_EXECUTE));
	Gura_AssignValue(GL_CLEAR,                           Value(GL_CLEAR));
	Gura_AssignValue(GL_AND,                             Value(GL_AND));
	Gura_AssignValue(GL_AND_REVERSE,                     Value(GL_AND_REVERSE));
	Gura_AssignValue(GL_COPY,                            Value(GL_COPY));
	Gura_AssignValue(GL_AND_INVERTED,                    Value(GL_AND_INVERTED));
	Gura_AssignValue(GL_NOOP,                            Value(GL_NOOP));
	Gura_AssignValue(GL_XOR,                             Value(GL_XOR));
	Gura_AssignValue(GL_OR,                              Value(GL_OR));
	Gura_AssignValue(GL_NOR,                             Value(GL_NOR));
	Gura_AssignValue(GL_EQUIV,                           Value(GL_EQUIV));
	Gura_AssignValue(GL_INVERT,                          Value(GL_INVERT));
	Gura_AssignValue(GL_OR_REVERSE,                      Value(GL_OR_REVERSE));
	Gura_AssignValue(GL_COPY_INVERTED,                   Value(GL_COPY_INVERTED));
	Gura_AssignValue(GL_OR_INVERTED,                     Value(GL_OR_INVERTED));
	Gura_AssignValue(GL_NAND,                            Value(GL_NAND));
	Gura_AssignValue(GL_SET,                             Value(GL_SET));
	Gura_AssignValue(GL_EMISSION,                        Value(GL_EMISSION));
	Gura_AssignValue(GL_SHININESS,                       Value(GL_SHININESS));
	Gura_AssignValue(GL_AMBIENT_AND_DIFFUSE,             Value(GL_AMBIENT_AND_DIFFUSE));
	Gura_AssignValue(GL_COLOR_INDEXES,                   Value(GL_COLOR_INDEXES));
	Gura_AssignValue(GL_MODELVIEW,                       Value(GL_MODELVIEW));
	Gura_AssignValue(GL_PROJECTION,                      Value(GL_PROJECTION));
	Gura_AssignValue(GL_TEXTURE,                         Value(GL_TEXTURE));
	Gura_AssignValue(GL_COLOR,                           Value(GL_COLOR));
	Gura_AssignValue(GL_DEPTH,                           Value(GL_DEPTH));
	Gura_AssignValue(GL_STENCIL,                         Value(GL_STENCIL));
	Gura_AssignValue(GL_COLOR_INDEX,                     Value(GL_COLOR_INDEX));
	Gura_AssignValue(GL_STENCIL_INDEX,                   Value(GL_STENCIL_INDEX));
	Gura_AssignValue(GL_DEPTH_COMPONENT,                 Value(GL_DEPTH_COMPONENT));
	Gura_AssignValue(GL_RED,                             Value(GL_RED));
	Gura_AssignValue(GL_GREEN,                           Value(GL_GREEN));
	Gura_AssignValue(GL_BLUE,                            Value(GL_BLUE));
	Gura_AssignValue(GL_ALPHA,                           Value(GL_ALPHA));
	Gura_AssignValue(GL_RGB,                             Value(GL_RGB));
	Gura_AssignValue(GL_RGBA,                            Value(GL_RGBA));
	Gura_AssignValue(GL_LUMINANCE,                       Value(GL_LUMINANCE));
	Gura_AssignValue(GL_LUMINANCE_ALPHA,                 Value(GL_LUMINANCE_ALPHA));
	Gura_AssignValue(GL_BITMAP,                          Value(GL_BITMAP));
	Gura_AssignValue(GL_POINT,                           Value(GL_POINT));
	Gura_AssignValue(GL_LINE,                            Value(GL_LINE));
	Gura_AssignValue(GL_FILL,                            Value(GL_FILL));
	Gura_AssignValue(GL_RENDER,                          Value(GL_RENDER));
	Gura_AssignValue(GL_FEEDBACK,                        Value(GL_FEEDBACK));
	Gura_AssignValue(GL_SELECT,                          Value(GL_SELECT));
	Gura_AssignValue(GL_FLAT,                            Value(GL_FLAT));
	Gura_AssignValue(GL_SMOOTH,                          Value(GL_SMOOTH));
	Gura_AssignValue(GL_KEEP,                            Value(GL_KEEP));
	Gura_AssignValue(GL_REPLACE,                         Value(GL_REPLACE));
	Gura_AssignValue(GL_INCR,                            Value(GL_INCR));
	Gura_AssignValue(GL_DECR,                            Value(GL_DECR));
	Gura_AssignValue(GL_VENDOR,                          Value(GL_VENDOR));
	Gura_AssignValue(GL_RENDERER,                        Value(GL_RENDERER));
	Gura_AssignValue(GL_VERSION,                         Value(GL_VERSION));
	Gura_AssignValue(GL_EXTENSIONS,                      Value(GL_EXTENSIONS));
	Gura_AssignValue(GL_S,                               Value(GL_S));
	Gura_AssignValue(GL_T,                               Value(GL_T));
	Gura_AssignValue(GL_R,                               Value(GL_R));
	Gura_AssignValue(GL_Q,                               Value(GL_Q));
	Gura_AssignValue(GL_MODULATE,                        Value(GL_MODULATE));
	Gura_AssignValue(GL_DECAL,                           Value(GL_DECAL));
	Gura_AssignValue(GL_TEXTURE_ENV_MODE,                Value(GL_TEXTURE_ENV_MODE));
	Gura_AssignValue(GL_TEXTURE_ENV_COLOR,               Value(GL_TEXTURE_ENV_COLOR));
	Gura_AssignValue(GL_TEXTURE_ENV,                     Value(GL_TEXTURE_ENV));
	Gura_AssignValue(GL_EYE_LINEAR,                      Value(GL_EYE_LINEAR));
	Gura_AssignValue(GL_OBJECT_LINEAR,                   Value(GL_OBJECT_LINEAR));
	Gura_AssignValue(GL_SPHERE_MAP,                      Value(GL_SPHERE_MAP));
	Gura_AssignValue(GL_TEXTURE_GEN_MODE,                Value(GL_TEXTURE_GEN_MODE));
	Gura_AssignValue(GL_OBJECT_PLANE,                    Value(GL_OBJECT_PLANE));
	Gura_AssignValue(GL_EYE_PLANE,                       Value(GL_EYE_PLANE));
	Gura_AssignValue(GL_NEAREST,                         Value(GL_NEAREST));
	Gura_AssignValue(GL_LINEAR,                          Value(GL_LINEAR));
	Gura_AssignValue(GL_NEAREST_MIPMAP_NEAREST,          Value(GL_NEAREST_MIPMAP_NEAREST));
	Gura_AssignValue(GL_LINEAR_MIPMAP_NEAREST,           Value(GL_LINEAR_MIPMAP_NEAREST));
	Gura_AssignValue(GL_NEAREST_MIPMAP_LINEAR,           Value(GL_NEAREST_MIPMAP_LINEAR));
	Gura_AssignValue(GL_LINEAR_MIPMAP_LINEAR,            Value(GL_LINEAR_MIPMAP_LINEAR));
	Gura_AssignValue(GL_TEXTURE_MAG_FILTER,              Value(GL_TEXTURE_MAG_FILTER));
	Gura_AssignValue(GL_TEXTURE_MIN_FILTER,              Value(GL_TEXTURE_MIN_FILTER));
	Gura_AssignValue(GL_TEXTURE_WRAP_S,                  Value(GL_TEXTURE_WRAP_S));
	Gura_AssignValue(GL_TEXTURE_WRAP_T,                  Value(GL_TEXTURE_WRAP_T));
	Gura_AssignValue(GL_CLAMP,                           Value(GL_CLAMP));
	Gura_AssignValue(GL_REPEAT,                          Value(GL_REPEAT));
	Gura_AssignValue(GL_CLIENT_PIXEL_STORE_BIT,          Value(GL_CLIENT_PIXEL_STORE_BIT));
	Gura_AssignValue(GL_CLIENT_VERTEX_ARRAY_BIT,         Value(GL_CLIENT_VERTEX_ARRAY_BIT));
	Gura_AssignValue(GL_CLIENT_ALL_ATTRIB_BITS,          Value(GL_CLIENT_ALL_ATTRIB_BITS));
	Gura_AssignValue(GL_POLYGON_OFFSET_FACTOR,           Value(GL_POLYGON_OFFSET_FACTOR));
	Gura_AssignValue(GL_POLYGON_OFFSET_UNITS,            Value(GL_POLYGON_OFFSET_UNITS));
	Gura_AssignValue(GL_POLYGON_OFFSET_POINT,            Value(GL_POLYGON_OFFSET_POINT));
	Gura_AssignValue(GL_POLYGON_OFFSET_LINE,             Value(GL_POLYGON_OFFSET_LINE));
	Gura_AssignValue(GL_POLYGON_OFFSET_FILL,             Value(GL_POLYGON_OFFSET_FILL));
	Gura_AssignValue(GL_ALPHA4,                          Value(GL_ALPHA4));
	Gura_AssignValue(GL_ALPHA8,                          Value(GL_ALPHA8));
	Gura_AssignValue(GL_ALPHA12,                         Value(GL_ALPHA12));
	Gura_AssignValue(GL_ALPHA16,                         Value(GL_ALPHA16));
	Gura_AssignValue(GL_LUMINANCE4,                      Value(GL_LUMINANCE4));
	Gura_AssignValue(GL_LUMINANCE8,                      Value(GL_LUMINANCE8));
	Gura_AssignValue(GL_LUMINANCE12,                     Value(GL_LUMINANCE12));
	Gura_AssignValue(GL_LUMINANCE16,                     Value(GL_LUMINANCE16));
	Gura_AssignValue(GL_LUMINANCE4_ALPHA4,               Value(GL_LUMINANCE4_ALPHA4));
	Gura_AssignValue(GL_LUMINANCE6_ALPHA2,               Value(GL_LUMINANCE6_ALPHA2));
	Gura_AssignValue(GL_LUMINANCE8_ALPHA8,               Value(GL_LUMINANCE8_ALPHA8));
	Gura_AssignValue(GL_LUMINANCE12_ALPHA4,              Value(GL_LUMINANCE12_ALPHA4));
	Gura_AssignValue(GL_LUMINANCE12_ALPHA12,             Value(GL_LUMINANCE12_ALPHA12));
	Gura_AssignValue(GL_LUMINANCE16_ALPHA16,             Value(GL_LUMINANCE16_ALPHA16));
	Gura_AssignValue(GL_INTENSITY,                       Value(GL_INTENSITY));
	Gura_AssignValue(GL_INTENSITY4,                      Value(GL_INTENSITY4));
	Gura_AssignValue(GL_INTENSITY8,                      Value(GL_INTENSITY8));
	Gura_AssignValue(GL_INTENSITY12,                     Value(GL_INTENSITY12));
	Gura_AssignValue(GL_INTENSITY16,                     Value(GL_INTENSITY16));
	Gura_AssignValue(GL_R3_G3_B2,                        Value(GL_R3_G3_B2));
	Gura_AssignValue(GL_RGB4,                            Value(GL_RGB4));
	Gura_AssignValue(GL_RGB5,                            Value(GL_RGB5));
	Gura_AssignValue(GL_RGB8,                            Value(GL_RGB8));
	Gura_AssignValue(GL_RGB10,                           Value(GL_RGB10));
	Gura_AssignValue(GL_RGB12,                           Value(GL_RGB12));
	Gura_AssignValue(GL_RGB16,                           Value(GL_RGB16));
	Gura_AssignValue(GL_RGBA2,                           Value(GL_RGBA2));
	Gura_AssignValue(GL_RGBA4,                           Value(GL_RGBA4));
	Gura_AssignValue(GL_RGB5_A1,                         Value(GL_RGB5_A1));
	Gura_AssignValue(GL_RGBA8,                           Value(GL_RGBA8));
	Gura_AssignValue(GL_RGB10_A2,                        Value(GL_RGB10_A2));
	Gura_AssignValue(GL_RGBA12,                          Value(GL_RGBA12));
	Gura_AssignValue(GL_RGBA16,                          Value(GL_RGBA16));
	Gura_AssignValue(GL_TEXTURE_RED_SIZE,                Value(GL_TEXTURE_RED_SIZE));
	Gura_AssignValue(GL_TEXTURE_GREEN_SIZE,              Value(GL_TEXTURE_GREEN_SIZE));
	Gura_AssignValue(GL_TEXTURE_BLUE_SIZE,               Value(GL_TEXTURE_BLUE_SIZE));
	Gura_AssignValue(GL_TEXTURE_ALPHA_SIZE,              Value(GL_TEXTURE_ALPHA_SIZE));
	Gura_AssignValue(GL_TEXTURE_LUMINANCE_SIZE,          Value(GL_TEXTURE_LUMINANCE_SIZE));
	Gura_AssignValue(GL_TEXTURE_INTENSITY_SIZE,          Value(GL_TEXTURE_INTENSITY_SIZE));
	Gura_AssignValue(GL_PROXY_TEXTURE_1D,                Value(GL_PROXY_TEXTURE_1D));
	Gura_AssignValue(GL_PROXY_TEXTURE_2D,                Value(GL_PROXY_TEXTURE_2D));
	Gura_AssignValue(GL_TEXTURE_PRIORITY,                Value(GL_TEXTURE_PRIORITY));
	Gura_AssignValue(GL_TEXTURE_RESIDENT,                Value(GL_TEXTURE_RESIDENT));
	Gura_AssignValue(GL_TEXTURE_BINDING_1D,              Value(GL_TEXTURE_BINDING_1D));
	Gura_AssignValue(GL_TEXTURE_BINDING_2D,              Value(GL_TEXTURE_BINDING_2D));
	Gura_AssignValue(GL_VERTEX_ARRAY,                    Value(GL_VERTEX_ARRAY));
	Gura_AssignValue(GL_NORMAL_ARRAY,                    Value(GL_NORMAL_ARRAY));
	Gura_AssignValue(GL_COLOR_ARRAY,                     Value(GL_COLOR_ARRAY));
	Gura_AssignValue(GL_INDEX_ARRAY,                     Value(GL_INDEX_ARRAY));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY,             Value(GL_TEXTURE_COORD_ARRAY));
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY,                 Value(GL_EDGE_FLAG_ARRAY));
	Gura_AssignValue(GL_VERTEX_ARRAY_SIZE,               Value(GL_VERTEX_ARRAY_SIZE));
	Gura_AssignValue(GL_VERTEX_ARRAY_TYPE,               Value(GL_VERTEX_ARRAY_TYPE));
	Gura_AssignValue(GL_VERTEX_ARRAY_STRIDE,             Value(GL_VERTEX_ARRAY_STRIDE));
	Gura_AssignValue(GL_NORMAL_ARRAY_TYPE,               Value(GL_NORMAL_ARRAY_TYPE));
	Gura_AssignValue(GL_NORMAL_ARRAY_STRIDE,             Value(GL_NORMAL_ARRAY_STRIDE));
	Gura_AssignValue(GL_COLOR_ARRAY_SIZE,                Value(GL_COLOR_ARRAY_SIZE));
	Gura_AssignValue(GL_COLOR_ARRAY_TYPE,                Value(GL_COLOR_ARRAY_TYPE));
	Gura_AssignValue(GL_COLOR_ARRAY_STRIDE,              Value(GL_COLOR_ARRAY_STRIDE));
	Gura_AssignValue(GL_INDEX_ARRAY_TYPE,                Value(GL_INDEX_ARRAY_TYPE));
	Gura_AssignValue(GL_INDEX_ARRAY_STRIDE,              Value(GL_INDEX_ARRAY_STRIDE));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_SIZE,        Value(GL_TEXTURE_COORD_ARRAY_SIZE));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_TYPE,        Value(GL_TEXTURE_COORD_ARRAY_TYPE));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_STRIDE,      Value(GL_TEXTURE_COORD_ARRAY_STRIDE));
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY_STRIDE,          Value(GL_EDGE_FLAG_ARRAY_STRIDE));
	Gura_AssignValue(GL_VERTEX_ARRAY_POINTER,            Value(GL_VERTEX_ARRAY_POINTER));
	Gura_AssignValue(GL_NORMAL_ARRAY_POINTER,            Value(GL_NORMAL_ARRAY_POINTER));
	Gura_AssignValue(GL_COLOR_ARRAY_POINTER,             Value(GL_COLOR_ARRAY_POINTER));
	Gura_AssignValue(GL_INDEX_ARRAY_POINTER,             Value(GL_INDEX_ARRAY_POINTER));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_POINTER,     Value(GL_TEXTURE_COORD_ARRAY_POINTER));
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY_POINTER,         Value(GL_EDGE_FLAG_ARRAY_POINTER));
	Gura_AssignValue(GL_V2F,                             Value(GL_V2F));
	Gura_AssignValue(GL_V3F,                             Value(GL_V3F));
	Gura_AssignValue(GL_C4UB_V2F,                        Value(GL_C4UB_V2F));
	Gura_AssignValue(GL_C4UB_V3F,                        Value(GL_C4UB_V3F));
	Gura_AssignValue(GL_C3F_V3F,                         Value(GL_C3F_V3F));
	Gura_AssignValue(GL_N3F_V3F,                         Value(GL_N3F_V3F));
	Gura_AssignValue(GL_C4F_N3F_V3F,                     Value(GL_C4F_N3F_V3F));
	Gura_AssignValue(GL_T2F_V3F,                         Value(GL_T2F_V3F));
	Gura_AssignValue(GL_T4F_V4F,                         Value(GL_T4F_V4F));
	Gura_AssignValue(GL_T2F_C4UB_V3F,                    Value(GL_T2F_C4UB_V3F));
	Gura_AssignValue(GL_T2F_C3F_V3F,                     Value(GL_T2F_C3F_V3F));
	Gura_AssignValue(GL_T2F_N3F_V3F,                     Value(GL_T2F_N3F_V3F));
	Gura_AssignValue(GL_T2F_C4F_N3F_V3F,                 Value(GL_T2F_C4F_N3F_V3F));
	Gura_AssignValue(GL_T4F_C4F_N3F_V4F,                 Value(GL_T4F_C4F_N3F_V4F));
	Gura_AssignValue(GL_EXT_vertex_array,                Value(GL_EXT_vertex_array));
	Gura_AssignValue(GL_EXT_bgra,                        Value(GL_EXT_bgra));
	Gura_AssignValue(GL_EXT_paletted_texture,            Value(GL_EXT_paletted_texture));
#if 0
	Gura_AssignValue(GL_WIN_swap_hint,                   Value(GL_WIN_swap_hint));
	Gura_AssignValue(GL_WIN_draw_range_elements,         Value(GL_WIN_draw_range_elements));
#endif
	Gura_AssignValue(GL_VERTEX_ARRAY_EXT,                Value(GL_VERTEX_ARRAY_EXT));
	Gura_AssignValue(GL_NORMAL_ARRAY_EXT,                Value(GL_NORMAL_ARRAY_EXT));
	Gura_AssignValue(GL_COLOR_ARRAY_EXT,                 Value(GL_COLOR_ARRAY_EXT));
	Gura_AssignValue(GL_INDEX_ARRAY_EXT,                 Value(GL_INDEX_ARRAY_EXT));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_EXT,         Value(GL_TEXTURE_COORD_ARRAY_EXT));
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY_EXT,             Value(GL_EDGE_FLAG_ARRAY_EXT));
	Gura_AssignValue(GL_VERTEX_ARRAY_SIZE_EXT,           Value(GL_VERTEX_ARRAY_SIZE_EXT));
	Gura_AssignValue(GL_VERTEX_ARRAY_TYPE_EXT,           Value(GL_VERTEX_ARRAY_TYPE_EXT));
	Gura_AssignValue(GL_VERTEX_ARRAY_STRIDE_EXT,         Value(GL_VERTEX_ARRAY_STRIDE_EXT));
	Gura_AssignValue(GL_VERTEX_ARRAY_COUNT_EXT,          Value(GL_VERTEX_ARRAY_COUNT_EXT));
	Gura_AssignValue(GL_NORMAL_ARRAY_TYPE_EXT,           Value(GL_NORMAL_ARRAY_TYPE_EXT));
	Gura_AssignValue(GL_NORMAL_ARRAY_STRIDE_EXT,         Value(GL_NORMAL_ARRAY_STRIDE_EXT));
	Gura_AssignValue(GL_NORMAL_ARRAY_COUNT_EXT,          Value(GL_NORMAL_ARRAY_COUNT_EXT));
	Gura_AssignValue(GL_COLOR_ARRAY_SIZE_EXT,            Value(GL_COLOR_ARRAY_SIZE_EXT));
	Gura_AssignValue(GL_COLOR_ARRAY_TYPE_EXT,            Value(GL_COLOR_ARRAY_TYPE_EXT));
	Gura_AssignValue(GL_COLOR_ARRAY_STRIDE_EXT,          Value(GL_COLOR_ARRAY_STRIDE_EXT));
	Gura_AssignValue(GL_COLOR_ARRAY_COUNT_EXT,           Value(GL_COLOR_ARRAY_COUNT_EXT));
	Gura_AssignValue(GL_INDEX_ARRAY_TYPE_EXT,            Value(GL_INDEX_ARRAY_TYPE_EXT));
	Gura_AssignValue(GL_INDEX_ARRAY_STRIDE_EXT,          Value(GL_INDEX_ARRAY_STRIDE_EXT));
	Gura_AssignValue(GL_INDEX_ARRAY_COUNT_EXT,           Value(GL_INDEX_ARRAY_COUNT_EXT));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_SIZE_EXT,    Value(GL_TEXTURE_COORD_ARRAY_SIZE_EXT));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_TYPE_EXT,    Value(GL_TEXTURE_COORD_ARRAY_TYPE_EXT));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_STRIDE_EXT,  Value(GL_TEXTURE_COORD_ARRAY_STRIDE_EXT));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_COUNT_EXT,   Value(GL_TEXTURE_COORD_ARRAY_COUNT_EXT));
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY_STRIDE_EXT,      Value(GL_EDGE_FLAG_ARRAY_STRIDE_EXT));
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY_COUNT_EXT,       Value(GL_EDGE_FLAG_ARRAY_COUNT_EXT));
	Gura_AssignValue(GL_VERTEX_ARRAY_POINTER_EXT,        Value(GL_VERTEX_ARRAY_POINTER_EXT));
	Gura_AssignValue(GL_NORMAL_ARRAY_POINTER_EXT,        Value(GL_NORMAL_ARRAY_POINTER_EXT));
	Gura_AssignValue(GL_COLOR_ARRAY_POINTER_EXT,         Value(GL_COLOR_ARRAY_POINTER_EXT));
	Gura_AssignValue(GL_INDEX_ARRAY_POINTER_EXT,         Value(GL_INDEX_ARRAY_POINTER_EXT));
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_POINTER_EXT, Value(GL_TEXTURE_COORD_ARRAY_POINTER_EXT));
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY_POINTER_EXT,     Value(GL_EDGE_FLAG_ARRAY_POINTER_EXT));
	//Gura_AssignValue(GL_DOUBLE_EXT,                      Value(GL_DOUBLE_EXT));
	Gura_AssignValue(GL_BGR_EXT,                         Value(GL_BGR_EXT));
	Gura_AssignValue(GL_BGRA_EXT,                        Value(GL_BGRA_EXT));
#if 0
	Gura_AssignValue(GL_COLOR_TABLE_FORMAT_EXT,          Value(GL_COLOR_TABLE_FORMAT_EXT));
	Gura_AssignValue(GL_COLOR_TABLE_WIDTH_EXT,           Value(GL_COLOR_TABLE_WIDTH_EXT));
	Gura_AssignValue(GL_COLOR_TABLE_RED_SIZE_EXT,        Value(GL_COLOR_TABLE_RED_SIZE_EXT));
	Gura_AssignValue(GL_COLOR_TABLE_GREEN_SIZE_EXT,      Value(GL_COLOR_TABLE_GREEN_SIZE_EXT));
	Gura_AssignValue(GL_COLOR_TABLE_BLUE_SIZE_EXT,       Value(GL_COLOR_TABLE_BLUE_SIZE_EXT));
	Gura_AssignValue(GL_COLOR_TABLE_ALPHA_SIZE_EXT,      Value(GL_COLOR_TABLE_ALPHA_SIZE_EXT));
	Gura_AssignValue(GL_COLOR_TABLE_LUMINANCE_SIZE_EXT,  Value(GL_COLOR_TABLE_LUMINANCE_SIZE_EXT));
	Gura_AssignValue(GL_COLOR_TABLE_INTENSITY_SIZE_EXT,  Value(GL_COLOR_TABLE_INTENSITY_SIZE_EXT));
#endif
	Gura_AssignValue(GL_COLOR_INDEX1_EXT,                Value(GL_COLOR_INDEX1_EXT));
	Gura_AssignValue(GL_COLOR_INDEX2_EXT,                Value(GL_COLOR_INDEX2_EXT));
	Gura_AssignValue(GL_COLOR_INDEX4_EXT,                Value(GL_COLOR_INDEX4_EXT));
	Gura_AssignValue(GL_COLOR_INDEX8_EXT,                Value(GL_COLOR_INDEX8_EXT));
	Gura_AssignValue(GL_COLOR_INDEX12_EXT,               Value(GL_COLOR_INDEX12_EXT));
	Gura_AssignValue(GL_COLOR_INDEX16_EXT,               Value(GL_COLOR_INDEX16_EXT));
#if 0
	Gura_AssignValue(GL_MAX_ELEMENTS_VERTICES_WIN,       Value(GL_MAX_ELEMENTS_VERTICES_WIN));
	Gura_AssignValue(GL_MAX_ELEMENTS_INDICES_WIN,        Value(GL_MAX_ELEMENTS_INDICES_WIN));
#endif
	Gura_AssignValue(GL_PHONG_WIN,                       Value(GL_PHONG_WIN));
	Gura_AssignValue(GL_PHONG_HINT_WIN,                  Value(GL_PHONG_HINT_WIN));
	Gura_AssignValue(GL_FOG_SPECULAR_TEXTURE_WIN,        Value(GL_FOG_SPECULAR_TEXTURE_WIN));
	Gura_AssignValue(GL_LOGIC_OP,                        Value(GL_LOGIC_OP));
	Gura_AssignValue(GL_TEXTURE_COMPONENTS,              Value(GL_TEXTURE_COMPONENTS));
	// function assignment
	Gura_AssignFunction(glAccum);
	Gura_AssignFunction(glAlphaFunc);
	Gura_AssignFunction(glAreTexturesResident);
	Gura_AssignFunction(glArrayElement);
	Gura_AssignFunction(glBegin);
	Gura_AssignFunction(glBindTexture);
	Gura_AssignFunction(glBitmap);
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
	Gura_AssignFunction(glCopyPixels);
	Gura_AssignFunction(glCopyTexImage1D);
	Gura_AssignFunction(glCopyTexImage2D);
	Gura_AssignFunction(glCopyTexSubImage1D);
	Gura_AssignFunction(glCopyTexSubImage2D);
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
	Gura_AssignFunction(glDrawPixels);
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
	Gura_AssignFunction(glGetDoublev);
	Gura_AssignFunction(glGetError);
	Gura_AssignFunction(glGetFloatv);
	Gura_AssignFunction(glGetIntegerv);
	Gura_AssignFunction(glGetLightfv);
	Gura_AssignFunction(glGetLightiv);
	Gura_AssignFunction(glGetMapdv);
	Gura_AssignFunction(glGetMapfv);
	Gura_AssignFunction(glGetMapiv);
	Gura_AssignFunction(glGetMaterialfv);
	Gura_AssignFunction(glGetMaterialiv);
	Gura_AssignFunction(glGetPixelMapfv);
	Gura_AssignFunction(glGetPixelMapuiv);
	Gura_AssignFunction(glGetPixelMapusv);
	Gura_AssignFunction(glGetPointerv);
	Gura_AssignFunction(glGetPolygonStipple);
	Gura_AssignFunction(glGetString);
	Gura_AssignFunction(glGetTexEnvfv);
	Gura_AssignFunction(glGetTexEnviv);
	Gura_AssignFunction(glGetTexGendv);
	Gura_AssignFunction(glGetTexGenfv);
	Gura_AssignFunction(glGetTexGeniv);
	Gura_AssignFunction(glGetTexImage);
	Gura_AssignFunction(glGetTexLevelParameterfv);
	Gura_AssignFunction(glGetTexLevelParameteriv);
	Gura_AssignFunction(glGetTexParameterfv);
	Gura_AssignFunction(glGetTexParameteriv);
	Gura_AssignFunction(glHint);
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
	Gura_AssignFunction(glReadPixels);
	Gura_AssignFunction(glRectd);
	Gura_AssignFunction(glRectdv);
	Gura_AssignFunction(glRectf);
	Gura_AssignFunction(glRectfv);
	Gura_AssignFunction(glRecti);
	Gura_AssignFunction(glRectiv);
	Gura_AssignFunction(glRects);
	Gura_AssignFunction(glRectsv);
	Gura_AssignFunction(glRenderMode);
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
	Gura_AssignFunction(glTexImage1D);
	Gura_AssignFunction(glTexImage2D);
	Gura_AssignFunction(glTexParameterf);
	Gura_AssignFunction(glTexParameterfv);
	Gura_AssignFunction(glTexParameteri);
	Gura_AssignFunction(glTexParameteriv);
	Gura_AssignFunction(glTexSubImage1D);
	Gura_AssignFunction(glTexSubImage2D);
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
}
