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
