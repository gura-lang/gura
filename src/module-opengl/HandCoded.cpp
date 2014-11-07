// opengl.glAreTexturesResident(textures[]:number)
Gura_DeclareFunction(glAreTexturesResident)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "textures", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glAreTexturesResident)
{
	const ValueList &textures_in = args.GetList(0);
	GLsizei n = static_cast<GLsizei>(textures_in.size());
	GLuint *textures = new GLuint[n];
	GLboolean *residences = new GLboolean[n];
	do {
		GLuint *p = textures;
		foreach_const (ValueList, pValue, textures_in) { *p++ = pValue->GetUInt(); }
	} while (0);
	// GLsizei n, const GLuint *textures, GLboolean *residences
	GLboolean rtn = ::glAreTexturesResident(n, textures, residences);
	if (rtn) {
		delete[] textures;
		delete[] residences;
		return Value(true);
	}
	Value result;
	ValueList &residences_out = result.InitAsList(env);
	do {
		GLboolean *p = residences;
		for (GLsizei i = 0; i < n; i++, p++) {
			residences_out.push_back(Value(*p? true : false));
		}
	} while (0);
	delete[] textures;
	delete[] residences;
	return result;
}

// opengl.glBegin(mode:number):void {block?}
Gura_DeclareFunction(glBegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mode", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(glBegin)
{
	GLenum mode = args.GetUInt(0);
	// GLenum mode
	::glBegin(mode);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::glEnd();
	}
	return Value::Null;
}

// opengl.glBitmap(width:number, height:number, xorig:number, yorig:number, xmove:number, ymove:number, bitmap:binary):void
Gura_DeclareFunction(glBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "xorig", VTYPE_number);
	DeclareArg(env, "yorig", VTYPE_number);
	DeclareArg(env, "xmove", VTYPE_number);
	DeclareArg(env, "ymove", VTYPE_number);
	DeclareArg(env, "bitmap", VTYPE_binary);
}

Gura_ImplementFunction(glBitmap)
{
	GLsizei width = args.GetInt(0);
	GLsizei height = args.GetInt(1);
	GLfloat xorig = args.GetFloat(2);
	GLfloat yorig = args.GetFloat(3);
	GLfloat xmove = args.GetFloat(4);
	GLfloat ymove = args.GetFloat(5);
	GLubyte *bitmap = reinterpret_cast<GLubyte *>(const_cast<char *>(args.GetBinary(6).data()));
	// GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap
	::glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
	return Value::Null;
}

// opengl.glCallLists(type:number, lists[]:number):void
Gura_DeclareFunction(glCallLists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "type", VTYPE_number);
	DeclareArg(env, "lists", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glCallLists)
{
	const ValueList &lists_in = args.GetList(1);
	GLsizei n = static_cast<GLsizei>(lists_in.size());
	GLenum type = args.GetUInt(0);
	GLvoid *lists = NULL;
	if (type == GL_BYTE) {
		lists = ::malloc(sizeof(GLbyte) * n);
		GLbyte *p = reinterpret_cast<GLbyte *>(lists);
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetChar(); }
	} else if (type == GL_UNSIGNED_BYTE) {
		lists = ::malloc(sizeof(GLubyte) * n);
		GLubyte *p = reinterpret_cast<GLubyte *>(lists);
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetUChar(); }
	} else if (type == GL_SHORT) {
		lists = ::malloc(sizeof(GLshort) * n);
		GLshort *p = reinterpret_cast<GLshort *>(lists);
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetShort(); }
	} else if (type == GL_UNSIGNED_SHORT) {
		lists = ::malloc(sizeof(GLushort) * n);
		GLushort *p = reinterpret_cast<GLushort *>(lists);
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetUShort(); }
	} else if (type == GL_INT) {
		lists = ::malloc(sizeof(GLint) * n);
		GLint *p = reinterpret_cast<GLint *>(lists);
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetInt(); }
	} else if (type == GL_UNSIGNED_INT) {
		lists = ::malloc(sizeof(GLuint) * n);
		GLuint *p = reinterpret_cast<GLuint *>(lists);
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetUInt(); }
	} else if (type == GL_FLOAT) {
		lists = ::malloc(sizeof(GLfloat) * n);
		GLfloat *p = reinterpret_cast<GLfloat *>(lists);
		foreach_const (ValueList, pValue, lists_in) { *p++ = pValue->GetFloat(); }
	} else if (type == GL_2_BYTES) {
		lists = ::malloc(sizeof(GLubyte) * 2 * n);
		GLubyte *p = reinterpret_cast<GLubyte *>(lists);
		foreach_const (ValueList, pValue, lists_in) {
			UShort num = pValue->GetUShort();
			*p++ = static_cast<GLubyte>(num >> 8);
			*p++ = static_cast<GLubyte>(num);
		}
	} else if (type == GL_3_BYTES) {
		lists = ::malloc(sizeof(GLubyte) * 3 * n);
		GLubyte *p = reinterpret_cast<GLubyte *>(lists);
		foreach_const (ValueList, pValue, lists_in) {
			ULong num = pValue->GetULong();
			*p++ = static_cast<GLubyte>(num >> 16);
			*p++ = static_cast<GLubyte>(num >> 8);
			*p++ = static_cast<GLubyte>(num);
		}
	} else if (type == GL_4_BYTES) {
		lists = ::malloc(sizeof(GLubyte) * 4 * n);
		GLubyte *p = reinterpret_cast<GLubyte *>(lists);
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
	::glCallLists(n, type, lists);
	::free(lists);
	return Value::Null;
}

// opengl.glDeleteTextures(textures[]:number):void
Gura_DeclareFunction(glDeleteTextures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "textures", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glDeleteTextures)
{
	GLsizei n = static_cast<GLsizei>(args.GetList(0).size());
	DeclareNewArray(GLuint, textures, 0);
	// GLsizei n, const GLuint *textures
	::glDeleteTextures(n, textures);
	delete[] textures;
	return Value::Null;
}

// opengl.glDrawPixels(image:image):void
Gura_DeclareFunction(glDrawPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "image", VTYPE_image);
}

Gura_ImplementFunction(glDrawPixels)
{
	Image *pImage = Object_image::GetObject(args, 0)->GetImage();
	GLsizei width = static_cast<GLsizei>(pImage->GetWidth());
	GLsizei height = static_cast<GLsizei>(pImage->GetHeight());
	GLenum format = GetImageFormat(sig, pImage);
	if (sig.IsSignalled()) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	const GLvoid *pixels = pImage->GetBuffer();
	// GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels
	::glDrawPixels(width, height, format, type, pixels);
	return Value::Null;
}

// opengl.glFeedbackBuffer(size:number, type:number, buffer[]:number):void
Gura_DeclareFunction(glFeedbackBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "size", VTYPE_number);
	DeclareArg(env, "type", VTYPE_number);
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glFeedbackBuffer)
{
	GLsizei size = args.GetInt(0);
	GLenum type = args.GetUInt(1);
	DeclareNewArray(GLfloat, buffer, 2);
	// GLsizei size, GLenum type, GLfloat *buffer
	//GL_2D, GL_3D, GL_3D_COLOR, GL_3D_COLOR_TEXTURE, GL_4D_COLOR_TEXTURE
	sig.SetError(ERR_SystemError, "not implemented");
	//::glFeedbackBuffer(size, type, buffer);
	delete[] buffer;
	return Value::Null;
}

// opengl.glGenLists(range:number):map
Gura_DeclareFunction(glGenLists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_number);
}

Gura_ImplementFunction(glGenLists)
{
	GLsizei range = args.GetInt(0);
	// GLsizei range
	return Value(::glGenLists(range));
}

// opengl.glGenTextures(n:number)
Gura_DeclareFunction(glGenTextures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
}

Gura_ImplementFunction(glGenTextures)
{
	GLsizei n = args.GetInt(0);
	GLuint *textures = new GLuint[n];
	// GLsizei n, GLuint *textures
	::glGenTextures(n, textures);
	Value result;
	ValueList &textures_out = result.InitAsList(env);
	for (int i = 0; i < n; i++) {
		textures_out.push_back(Value(static_cast<unsigned int>(textures[i])));
	}
	delete[] textures;
	return result;
}

// opengl.glGetBooleanv(pname:number):map
Gura_DeclareFunction(glGetBooleanv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
}

Gura_ImplementFunction(glGetBooleanv)
{
	GLenum pname = args.GetUInt(0);
	size_t n = GetParamCount(pname);
	if (n == 0) {
		sig.SetError(ERR_ValueError, "invalid pname");
		return Value::Null;
	}
	GLboolean params[16];
	// GLenum pname, GLboolean *params
	::glGetBooleanv(pname, params);
	if (n == 1) return Value(params[0]? true : false);
	Value result;
	ValueList &params_out = result.InitAsList(env);
	for (size_t i = 0; i < n; i++) {
		params_out.push_back(params[i]? true : false);
	}
	return result;
}

// opengl.glGetDoublev(pname:number):map
Gura_DeclareFunction(glGetDoublev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
}

Gura_ImplementFunction(glGetDoublev)
{
	GLenum pname = args.GetUInt(0);
	size_t n = GetParamCount(pname);
	if (n == 0) {
		sig.SetError(ERR_ValueError, "invalid pname");
		return Value::Null;
	}
	GLdouble params[16];
	// GLenum pname, GLdouble *params
	::glGetDoublev(pname, params);
	if (n == 1) return Value(static_cast<double>(params[0]));
	Value result;
	ValueList &params_out = result.InitAsList(env);
	for (size_t i = 0; i < n; i++) {
		params_out.push_back(static_cast<double>(params[i]));
	}
	return result;
}

// opengl.glGetFloatv(pname:number):map
Gura_DeclareFunction(glGetFloatv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
}

Gura_ImplementFunction(glGetFloatv)
{
	GLenum pname = args.GetUInt(0);
	size_t n = GetParamCount(pname);
	if (n == 0) {
		sig.SetError(ERR_ValueError, "invalid pname");
		return Value::Null;
	}
	GLfloat params[16];
	// GLenum pname, GLfloat *params
	::glGetFloatv(pname, params);
	if (n == 1) return Value(static_cast<float>(params[0]));
	Value result;
	ValueList &params_out = result.InitAsList(env);
	for (size_t i = 0; i < n; i++) {
		params_out.push_back(static_cast<float>(params[i]));
	}
	return result;
}

// opengl.glGetIntegerv(pname:number):map
Gura_DeclareFunction(glGetIntegerv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pname", VTYPE_number);
}

Gura_ImplementFunction(glGetIntegerv)
{
	GLenum pname = args.GetUInt(0);
	size_t n = GetParamCount(pname);
	if (n == 0) {
		sig.SetError(ERR_ValueError, "invalid pname");
		return Value::Null;
	}
	GLint params[16];
	// GLenum pname, GLint *params
	::glGetIntegerv(pname, params);
	if (n == 1) return Value(static_cast<int>(params[0]));
	Value result;
	ValueList &params_out = result.InitAsList(env);
	for (size_t i = 0; i < n; i++) {
		params_out.push_back(static_cast<int>(params[i]));
	}
	return result;
}

// opengl.glGetClipPlane(plane:number):map
Gura_DeclareFunction(glGetClipPlane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "plane", VTYPE_number);
}

Gura_ImplementFunction(glGetClipPlane)
{
	GLenum plane = args.GetUInt(0);
	GLdouble equation[4];
	// GLenum plane, GLdouble *equation
	::glGetClipPlane(plane, equation);
	Value result;
	ValueList &equation_out = result.InitAsList(env);
	for (size_t i = 0; i < 4; i++) {
		equation_out.push_back(static_cast<double>(equation[i]));
	}
	return result;
}

// opengl.glGetError()
Gura_DeclareFunction(glGetError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(glGetError)
{
	GLenum err = ::glGetError();
	return Value(static_cast<unsigned int>(err));
}

// opengl.glGetLightfv(light:number, pname:number):map
Gura_DeclareFunction(glGetLightfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "light", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
}

Gura_ImplementFunction(glGetLightfv)
{
	GLenum light = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	size_t n = GetParamCount(pname);
	if (n == 0) {
		sig.SetError(ERR_ValueError, "invalid pname");
		return Value::Null;
	}
	GLfloat params[4];
	// GLenum light, GLenum pname, GLfloat *params
	::glGetLightfv(light, pname, params);
	if (n == 1) return Value(static_cast<float>(params[0]));
	Value result;
	ValueList &params_out = result.InitAsList(env);
	for (size_t i = 0; i < n; i++) {
		params_out.push_back(static_cast<float>(params[i]));
	}
	return result;
}

// opengl.glGetLightiv(light:number, pname:number):map
Gura_DeclareFunction(glGetLightiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "light", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
}

Gura_ImplementFunction(glGetLightiv)
{
	GLenum light = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	size_t n = GetParamCount(pname);
	if (n == 0) {
		sig.SetError(ERR_ValueError, "invalid pname");
		return Value::Null;
	}
	GLint params[4];
	// GLenum light, GLenum pname, GLint *params
	::glGetLightiv(light, pname, params);
	if (n == 1) return Value(static_cast<int>(params[0]));
	Value result;
	ValueList &params_out = result.InitAsList(env);
	for (size_t i = 0; i < n; i++) {
		params_out.push_back(static_cast<int>(params[i]));
	}
	return result;
}

//****************************************************

// opengl.glGetMapdv(target:number, query:number)
Gura_DeclareFunction(glGetMapdv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "query", VTYPE_number);
}

Gura_ImplementFunction(glGetMapdv)
{
	/*
	GL_MAP1_COLOR_4, GL_MAP1_INDEX, GL_MAP1_NORMAL,
	GL_MAP1_TEXTURE_COORD_1, GL_MAP1_TEXTURE_COORD_2,
	GL_MAP1_TEXTURE_COORD_3, GL_MAP1_TEXTURE_COORD_4,
	GL_MAP1_VERTEX_3, GL_MAP1_VERTEX_4,
	GL_MAP2_COLOR_4, GL_MAP2_INDEX, GL_MAP2_NORMAL,
	GL_MAP2_TEXTURE_COORD_1, GL_MAP2_TEXTURE_COORD_2,
	GL_MAP2_TEXTURE_COORD_3, GL_MAP2_TEXTURE_COORD_4,
	GL_MAP2_VERTEX_3, GL_MAP2_VERTEX_4
	*/
	/*
	GL_COEFF, GL_ORDER, GL_DOMAIN
	*/
	GLenum target = args.GetUInt(0);
	GLenum query = args.GetUInt(1);
	//DeclareNewArray(GLdouble, v, 2);
	// GLenum target, GLenum query, GLdouble *v
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetMapdv(target, query, v);
	//delete[] v;
	return Value::Null;
}

// opengl.glGetMapfv(target:number, query:number)
Gura_DeclareFunction(glGetMapfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "query", VTYPE_number);
}

Gura_ImplementFunction(glGetMapfv)
{
	GLenum target = args.GetUInt(0);
	GLenum query = args.GetUInt(1);
	//DeclareNewArray(GLfloat, v, 2);
	// GLenum target, GLenum query, GLfloat *v
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetMapfv(target, query, v);
	//delete[] v;
	return Value::Null;
}

// opengl.glGetMapiv(target:number, query:number)
Gura_DeclareFunction(glGetMapiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "query", VTYPE_number);
}

Gura_ImplementFunction(glGetMapiv)
{
	GLenum target = args.GetUInt(0);
	GLenum query = args.GetUInt(1);
	//DeclareNewArray(GLint, v, 2);
	// GLenum target, GLenum query, GLint *v
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetMapiv(target, query, v);
	//delete[] v;
	return Value::Null;
}

// opengl.glGetMaterialfv(face:number, pname:number)
Gura_DeclareFunction(glGetMaterialfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "face", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
}

static size_t LookupMaterialVarLen(GLenum pname)
{
	static const struct {
		GLenum pname;
		size_t len;
	} tbl[] = {
		{ GL_AMBIENT,		4 },
		{ GL_DIFFUSE,		4 },
		{ GL_SPECULAR,		4 },
		{ GL_EMISSION,		4 },
		{ GL_SHININESS,		1 },
		{ GL_COLOR_INDEXES,	3 },
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].pname == pname) return tbl[i].len;
	}
	return 0;
}

Gura_ImplementFunction(glGetMaterialfv)
{
	GLenum face = args.GetUInt(0); //GL_FRONT, GL_BACK
	GLenum pname = args.GetUInt(1);
	GLfloat params[4];
	::glGetMaterialfv(face, pname, params);
	size_t len = LookupMaterialVarLen(pname);
	Value result;
	if (len > 0) {
		ValueList &valList = result.InitAsList(env);
		valList.reserve(len);
		for (size_t i = 0; i < len; i++) {
			valList.push_back(Value(params[i]));
		}
	}
	return result;
}

// opengl.glGetMaterialiv(face:number, pname:number)
Gura_DeclareFunction(glGetMaterialiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "face", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
}

Gura_ImplementFunction(glGetMaterialiv)
{
	GLenum face = args.GetUInt(0); //GL_FRONT, GL_BACK
	GLenum pname = args.GetUInt(1);
	GLint params[4];
	::glGetMaterialiv(face, pname, params);
	size_t len = LookupMaterialVarLen(pname);
	Value result;
	if (len > 0) {
		ValueList &valList = result.InitAsList(env);
		valList.reserve(len);
		for (size_t i = 0; i < len; i++) {
			valList.push_back(Value(params[i]));
		}
	}
	return result;
}

// opengl.glGetPixelMapfv(map:number, values[]:number)
Gura_DeclareFunction(glGetPixelMapfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "map", VTYPE_number);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetPixelMapfv)
{
	GLenum map = args.GetUInt(0);
	DeclareNewArray(GLfloat, values, 1);
	// GLenum map, GLfloat *values
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetPixelMapfv(map, values);
	delete[] values;
	return Value::Null;
}

// opengl.glGetPixelMapuiv(map:number, values[]:number)
Gura_DeclareFunction(glGetPixelMapuiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "map", VTYPE_number);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetPixelMapuiv)
{
	GLenum map = args.GetUInt(0);
	DeclareNewArray(GLuint, values, 1);
	// GLenum map, GLuint *values
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetPixelMapuiv(map, values);
	delete[] values;
	return Value::Null;
}

// opengl.glGetPixelMapusv(map:number, values[]:number)
Gura_DeclareFunction(glGetPixelMapusv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "map", VTYPE_number);
	DeclareArg(env, "values", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetPixelMapusv)
{
	GLenum map = args.GetUInt(0);
	DeclareNewArray(GLushort, values, 1);
	// GLenum map, GLushort *values
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetPixelMapusv(map, values);
	delete[] values;
	return Value::Null;
}

// opengl.glGetPointerv(pname:number, params[]:number)
Gura_DeclareFunction(glGetPointerv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetPointerv)
{
	GLenum pname = args.GetUInt(0);
	DeclareNewArray(int, params, 1);
	// GLenum pname, GLvoid* *params
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetPointerv(pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glGetPolygonStipple(mask[]:number)
Gura_DeclareFunction(glGetPolygonStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetPolygonStipple)
{
	DeclareNewArray(GLubyte, mask, 0);
	// GLubyte *mask
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetPolygonStipple(mask);
	delete[] mask;
	return Value::Null;
}

// opengl.glGetString(name:number):map
Gura_DeclareFunction(glGetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_number);
}

Gura_ImplementFunction(glGetString)
{
	GLenum name = args.GetUInt(0);
	// GLenum name
	const GLubyte *rtn = ::glGetString(name);
	if (rtn == NULL) return Value::Null;
	return Value(reinterpret_cast<const char *>(rtn));
}

// opengl.glGetTexEnvfv(target:number, pname:number, params[]:number)
Gura_DeclareFunction(glGetTexEnvfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexEnvfv)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLfloat, params, 2);
	// GLenum target, GLenum pname, GLfloat *params
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetTexEnvfv(target, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glGetTexEnviv(target:number, pname:number, params[]:number)
Gura_DeclareFunction(glGetTexEnviv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexEnviv)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLint, params, 2);
	// GLenum target, GLenum pname, GLint *params
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetTexEnviv(target, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glGetTexGendv(coord:number, pname:number, params[]:number)
Gura_DeclareFunction(glGetTexGendv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexGendv)
{
	GLenum coord = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLdouble, params, 2);
	// GLenum coord, GLenum pname, GLdouble *params
	//::glGetTexGendv(coord, pname, params);
	sig.SetError(ERR_SystemError, "not implemented");
	delete[] params;
	return Value::Null;
}

// opengl.glGetTexGenfv(coord:number, pname:number, params[]:number)
Gura_DeclareFunction(glGetTexGenfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexGenfv)
{
	GLenum coord = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLfloat, params, 2);
	// GLenum coord, GLenum pname, GLfloat *params
	//::glGetTexGenfv(coord, pname, params);
	sig.SetError(ERR_SystemError, "not implemented");
	delete[] params;
	return Value::Null;
}

// opengl.glGetTexGeniv(coord:number, pname:number, params[]:number)
Gura_DeclareFunction(glGetTexGeniv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "coord", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexGeniv)
{
	GLenum coord = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLint, params, 2);
	// GLenum coord, GLenum pname, GLint *params
	//::glGetTexGeniv(coord, pname, params);
	sig.SetError(ERR_SystemError, "not implemented");
	delete[] params;
	return Value::Null;
}

// opengl.glGetTexImage(target:number, level:number, format:number, type:number, pixels[]:number)
Gura_DeclareFunction(glGetTexImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "format", VTYPE_number);
	DeclareArg(env, "type", VTYPE_number);
	DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexImage)
{
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLenum format = args.GetUInt(2);
	GLenum type = args.GetUInt(3);
	DeclareNewArray(int, pixels, 4);
	// GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetTexImage(target, level, format, type, pixels);
	delete[] pixels;
	return Value::Null;
}

// opengl.glGetTexLevelParameterfv(target:number, level:number, pname:number, params[]:number)
Gura_DeclareFunction(glGetTexLevelParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexLevelParameterfv)
{
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLenum pname = args.GetUInt(2);
	DeclareNewArray(GLfloat, params, 3);
	// GLenum target, GLint level, GLenum pname, GLfloat *params
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetTexLevelParameterfv(target, level, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glGetTexLevelParameteriv(target:number, level:number, pname:number, params[]:number)
Gura_DeclareFunction(glGetTexLevelParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexLevelParameteriv)
{
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLenum pname = args.GetUInt(2);
	DeclareNewArray(GLint, params, 3);
	// GLenum target, GLint level, GLenum pname, GLint *params
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetTexLevelParameteriv(target, level, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glGetTexParameterfv(target:number, pname:number, params[]:number)
Gura_DeclareFunction(glGetTexParameterfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexParameterfv)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLfloat, params, 2);
	// GLenum target, GLenum pname, GLfloat *params
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetTexParameterfv(target, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glGetTexParameteriv(target:number, pname:number, params[]:number)
Gura_DeclareFunction(glGetTexParameteriv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "pname", VTYPE_number);
	DeclareArg(env, "params", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glGetTexParameteriv)
{
	GLenum target = args.GetUInt(0);
	GLenum pname = args.GetUInt(1);
	DeclareNewArray(GLint, params, 2);
	// GLenum target, GLenum pname, GLint *params
	sig.SetError(ERR_SystemError, "not implemented");
	//::glGetTexParameteriv(target, pname, params);
	delete[] params;
	return Value::Null;
}

// opengl.glIsEnabled(cap:number):void:map
Gura_DeclareFunction(glIsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cap", VTYPE_number);
}

Gura_ImplementFunction(glIsEnabled)
{
	GLenum cap = args.GetUInt(0);
	// GLenum cap
	return Value(::glIsEnabled(cap)? true : false);
}

// opengl.glIsList(list:number):void:map
Gura_DeclareFunction(glIsList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "list", VTYPE_number);
}

Gura_ImplementFunction(glIsList)
{
	GLuint list = args.GetUInt(0);
	// GLuint list
	return Value(::glIsList(list)? true : false);
}

// opengl.glIsTexture(texture:number):void:map
Gura_DeclareFunction(glIsTexture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "texture", VTYPE_number);
}

Gura_ImplementFunction(glIsTexture)
{
	GLuint texture = args.GetUInt(0);
	// GLuint texture
	return Value(::glIsTexture(texture)? true : false);
}

//****************************************************
// opengl.glNewList(list:number, mode:number):void:map {block?}
Gura_DeclareFunction(glNewList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "list", VTYPE_number);
	DeclareArg(env, "mode", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(glNewList)
{
	GLuint list = args.GetUInt(0);
	GLenum mode = args.GetUInt(1);
	// GLuint list, GLenum mode
	::glNewList(list, mode);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::glEndList();
	}
	return Value::Null;
}

// opengl.glPolygonStipple(mask:binary):void
Gura_DeclareFunction(glPolygonStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_binary);
}

Gura_ImplementFunction(glPolygonStipple)
{
	const Binary &mask_in = args.GetBinary(0);
	if (mask_in.size() != 32 * 4) {
		sig.SetError(ERR_ValueError, "length of bytes must be 32 * 4");
		return Value::Null;
	}
	const GLubyte *mask = reinterpret_cast<const GLubyte *>(mask_in.data());
	// const GLubyte *mask
	::glPolygonStipple(mask);
	return Value::Null;
}

// opengl.glPrioritizeTextures(textures[]:number, priorities[]:number):void
Gura_DeclareFunction(glPrioritizeTextures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "textures", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "priorities", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glPrioritizeTextures)
{
	if (args.GetList(0).size() != args.GetList(1).size()) {
		sig.SetError(ERR_ValueError, "textures and priorities must be in the same length");
		return Value::Null;
	}
	GLsizei n = static_cast<GLsizei>(args.GetList(0).size());
	DeclareNewArray(GLuint, textures, 0);
	DeclareNewArray(GLclampf, priorities, 1);
	// GLsizei n, const GLuint *textures, const GLclampf *priorities
	::glPrioritizeTextures(n, textures, priorities);
	delete[] textures;
	delete[] priorities;
	return Value::Null;
}

// opengl.glPushAttrib(mask:number):void {block?}
Gura_DeclareFunction(glPushAttrib)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(glPushAttrib)
{
	GLbitfield mask = args.GetUInt(0);
	// GLbitfield mask
	::glPushAttrib(mask);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::glPopAttrib();
	}
	return Value::Null;
}

// opengl.glPushClientAttrib(mask:number):void {block?}
Gura_DeclareFunction(glPushClientAttrib)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "mask", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(glPushClientAttrib)
{
	GLbitfield mask = args.GetUInt(0);
	// GLbitfield mask
	::glPushClientAttrib(mask);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::glPopClientAttrib();
	}
	return Value::Null;
}

// opengl.glPushMatrix():void {block?}
Gura_DeclareFunction(glPushMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(glPushMatrix)
{
	// void
	::glPushMatrix();
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::glPopMatrix();
	}
	return Value::Null;
}

// opengl.glPushName(name:number):void {block?}
Gura_DeclareFunction(glPushName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "name", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(glPushName)
{
	GLuint name = args.GetUInt(0);
	// GLuint name
	::glPushName(name);
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
		::glPopName();
	}
	return Value::Null;
}

// opengl.glReadPixels(x:number, y:number, width:number, height:number, format:symbol)
Gura_DeclareFunction(glReadPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "format", VTYPE_symbol);
}

Gura_ImplementFunction(glReadPixels)
{
	GLint x = args.GetInt(0);
	GLint y = args.GetInt(1);
	GLsizei width = args.GetInt(2);
	GLsizei height = args.GetInt(3);
	Image::Format fmt = Image::SymbolToFormat(sig, args.GetSymbol(4));
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<Image> pImage(new Image(fmt));
	GLenum format = GetImageFormat(sig, pImage.get());
	if (sig.IsSignalled()) return Value::Null;
	if (!pImage->AllocBuffer(sig, width, height, 0xff)) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	::glReadPixels(x, y, width, height, format, type, pImage->GetBuffer());
	return Value(new Object_image(env, pImage.release()));
}

// opengl.glRectdv(v1[]:number, v2[]:number):void
Gura_DeclareFunction(glRectdv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRectdv)
{
	DeclareArray(GLdouble, v1, 2, 0);
	DeclareArray(GLdouble, v2, 2, 1);
	// const GLdouble *v1, const GLdouble *v2
	::glRectdv(v1, v2);
	return Value::Null;
}

// opengl.glRectfv(v1[]:number, v2[]:number):void
Gura_DeclareFunction(glRectfv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRectfv)
{
	DeclareArray(GLfloat, v1, 2, 0);
	DeclareArray(GLfloat, v2, 2, 1);
	// const GLfloat *v1, const GLfloat *v2
	::glRectfv(v1, v2);
	return Value::Null;
}

// opengl.glRectiv(v1[]:number, v2[]:number):void
Gura_DeclareFunction(glRectiv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRectiv)
{
	DeclareArray(GLint, v1, 2, 0);
	DeclareArray(GLint, v2, 2, 1);
	// const GLint *v1, const GLint *v2
	::glRectiv(v1, v2);
	return Value::Null;
}

// opengl.glRectsv(v1[]:number, v2[]:number):void
Gura_DeclareFunction(glRectsv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "v1", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "v2", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(glRectsv)
{
	DeclareArray(GLshort, v1, 2, 0);
	DeclareArray(GLshort, v2, 2, 1);
	// const GLshort *v1, const GLshort *v2
	::glRectsv(v1, v2);
	return Value::Null;
}

// opengl.glRenderMode(mode:number):void:map
Gura_DeclareFunction(glRenderMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number);
}

Gura_ImplementFunction(glRenderMode)
{
	GLenum mode = args.GetUInt(0);
	// GLenum mode
	return Value(::glRenderMode(mode));
}

// opengl.glSelectBuffer(size:number)
Gura_DeclareFunction(glSelectBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "size", VTYPE_number);
}

Gura_ImplementFunction(glSelectBuffer)
{
	GLsizei size = args.GetInt(0);
	GLuint *buffer = new GLuint[size];
	// GLsizei size, GLuint *buffer
	::glSelectBuffer(size, buffer);
	Value result;
	ValueList &buffer_out = result.InitAsList(env);
	for (int i = 0; i < size; i++) {
		buffer_out.push_back(Value(static_cast<unsigned int>(buffer[i])));
	}
	delete[] buffer;
	return result;
}

// opengl.glTexImage1D(target:number, level:number,
//                 internalformat:number, border:number, image:image):void
Gura_DeclareFunction(glTexImage1D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "internalformat", VTYPE_number);
	DeclareArg(env, "border", VTYPE_number);
	DeclareArg(env, "image", VTYPE_image);
}

Gura_ImplementFunction(glTexImage1D)
{
	Image *pImage = Object_image::GetObject(args, 4)->GetImage();
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLint internalformat = args.GetInt(2);
	GLint border = args.GetInt(3);
	GLsizei width = static_cast<GLsizei>(pImage->GetWidth()) + border * 2;
	GLenum format = GetImageFormat(sig, pImage);
	if (sig.IsSignalled()) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	const GLvoid *pixels = pImage->GetBuffer();
	// GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels
	::glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
	return Value::Null;
}

// opengl.glTexImage2D(target:number, level:number,
//                 internalformat:number, border:number, image:image):void
Gura_DeclareFunction(glTexImage2D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "internalformat", VTYPE_number);
	DeclareArg(env, "border", VTYPE_number);
	DeclareArg(env, "image", VTYPE_image);
}

Gura_ImplementFunction(glTexImage2D)
{
	Image *pImage = Object_image::GetObject(args, 4)->GetImage();
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLint internalformat = args.GetInt(2);
	GLint border = args.GetInt(3);
	GLsizei width = static_cast<GLsizei>(pImage->GetWidth()) + border * 2;
	GLsizei height = static_cast<GLsizei>(pImage->GetHeight()) + border * 2;
	GLenum format = GetImageFormat(sig, pImage);
	if (sig.IsSignalled()) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	const GLvoid *pixels = pImage->GetBuffer();
	// GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels
	::glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
	return Value::Null;
}

// opengl.glTexSubImage1D(target:number, level:number, xoffset:number, image:image):void
Gura_DeclareFunction(glTexSubImage1D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "xoffset", VTYPE_number);
	DeclareArg(env, "image", VTYPE_image);
}

Gura_ImplementFunction(glTexSubImage1D)
{
	Image *pImage = Object_image::GetObject(args, 3)->GetImage();
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLint xoffset = args.GetInt(2);
	GLsizei width = static_cast<GLsizei>(pImage->GetWidth());
	GLenum format = GetImageFormat(sig, pImage);
	if (sig.IsSignalled()) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	const GLvoid *pixels = pImage->GetBuffer();
	// GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels
	::glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
	return Value::Null;
}

// opengl.glTexSubImage2D(target:number, level:number, xoffset:number, yoffset:number, image:image):void
Gura_DeclareFunction(glTexSubImage2D)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "target", VTYPE_number);
	DeclareArg(env, "level", VTYPE_number);
	DeclareArg(env, "xoffset", VTYPE_number);
	DeclareArg(env, "yoffset", VTYPE_number);
	DeclareArg(env, "image", VTYPE_image);
}

Gura_ImplementFunction(glTexSubImage2D)
{
	Image *pImage = Object_image::GetObject(args, 4)->GetImage();
	GLenum target = args.GetUInt(0);
	GLint level = args.GetInt(1);
	GLint xoffset = args.GetInt(2);
	GLint yoffset = args.GetInt(3);
	GLsizei width = static_cast<GLsizei>(pImage->GetWidth());
	GLsizei height = static_cast<GLsizei>(pImage->GetHeight());
	GLenum format = GetImageFormat(sig, pImage);
	if (sig.IsSignalled()) return Value::Null;
	GLenum type = GL_UNSIGNED_BYTE;
	const GLvoid *pixels = pImage->GetBuffer();
	// GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels
	::glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
	return Value::Null;
}
