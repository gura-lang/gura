//-----------------------------------------------------------------------------
// Gura opengl module
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#include "Module_opengl.h"

Gura_BeginModule(opengl)

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
ToArrayTemplate(GLbyte,		GetChar)
ToArrayTemplate(GLubyte,	GetUChar)
ToArrayTemplate(GLshort,	GetShort)
ToArrayTemplate(GLushort,	GetUShort)
ToArrayTemplate(GLint,		GetInt)
ToArrayTemplate(GLuint,		GetUInt)
ToArrayTemplate(GLfloat,	GetFloat)
ToArrayTemplate(GLdouble,	GetDouble)

size_t GetParamCount(GLenum pname)
{
	static const struct {
		GLenum pname;
		size_t n;
	} tbl[] = {
		{ GL_ACCUM_ALPHA_BITS,                       1 },
		{ GL_ACCUM_BLUE_BITS,                        1 },
		{ GL_ACCUM_CLEAR_VALUE,                      4 },
		{ GL_ACCUM_GREEN_BITS,                       1 },
		{ GL_ACCUM_RED_BITS,                         1 },
		{ GL_ALPHA_BIAS,                             1 },
		{ GL_ALPHA_BITS,                             1 },
		{ GL_ALPHA_SCALE,                            1 },
		{ GL_ALPHA_TEST,                             1 },
		{ GL_ALPHA_TEST_FUNC,                        1 },
		{ GL_ATTRIB_STACK_DEPTH,                     1 },
		{ GL_AUTO_NORMAL,                            1 },
		{ GL_AUX_BUFFERS,                            1 },
		{ GL_BLEND,                                  1 },
		{ GL_BLUE_BIAS,                              1 },
		{ GL_BLUE_BITS,                              1 },
		{ GL_BLUE_SCALE,                             1 },
		{ GL_CLIENT_ATTRIB_STACK_DEPTH,              1 },
		{ GL_COLOR_ARRAY,                            1 },
		{ GL_COLOR_ARRAY_SIZE,                       1 },
		{ GL_COLOR_ARRAY_STRIDE,                     1 },
		{ GL_COLOR_ARRAY_TYPE,                       1 },
		{ GL_COLOR_CLEAR_VALUE,                      4 },
		{ GL_COLOR_LOGIC_OP,                         1 },
		{ GL_COLOR_MATERIAL,                         1 },
		{ GL_COLOR_MATERIAL_FACE,                    1 },
		{ GL_COLOR_MATERIAL_PARAMETER,               1 },
		{ GL_COLOR_WRITEMASK,                        4 },
		{ GL_CULL_FACE,                              1 },
		{ GL_CULL_FACE_MODE,                         1 },
		{ GL_CURRENT_COLOR,                          4 },
		{ GL_CURRENT_INDEX,                          1 },
		{ GL_CURRENT_NORMAL,                         3 },
		{ GL_CURRENT_RASTER_COLOR,                   4 },
		{ GL_CURRENT_RASTER_DISTANCE,                1 },
		{ GL_CURRENT_RASTER_INDEX,                   1 },
		{ GL_CURRENT_RASTER_POSITION,                4 },
		{ GL_CURRENT_RASTER_POSITION_VALID,          1 },
		{ GL_CURRENT_RASTER_TEXTURE_COORDS,          4 },
		{ GL_CURRENT_TEXTURE_COORDS,                 4 },
		{ GL_DEPTH_BIAS,                             1 },
		{ GL_DEPTH_BITS,                             1 },
		{ GL_DEPTH_CLEAR_VALUE,                      1 },
		{ GL_DEPTH_FUNC,                             1 },
		{ GL_DEPTH_RANGE,                            2 },
		{ GL_DEPTH_SCALE,                            1 },
		{ GL_DEPTH_TEST,                             1 },
		{ GL_DEPTH_WRITEMASK,                        1 },
		{ GL_DITHER,                                 1 },
		{ GL_DOUBLEBUFFER,                           1 },
		{ GL_DRAW_BUFFER,                            1 },
		{ GL_EDGE_FLAG,                              1 },
		{ GL_EDGE_FLAG_ARRAY,                        1 },
		{ GL_EDGE_FLAG_ARRAY_STRIDE,                 1 },
		{ GL_FEEDBACK_BUFFER_SIZE,                   1 },
		{ GL_FEEDBACK_BUFFER_TYPE,                   1 },
		{ GL_FOG,                                    1 },
		{ GL_FOG_COLOR,                              4 },
		{ GL_FOG_DENSITY,                            1 },
		{ GL_FOG_END,                                1 },
		{ GL_FOG_HINT,                               1 },
		{ GL_FOG_INDEX,                              1 },
		{ GL_FOG_MODE,                               1 },
		{ GL_FOG_START,                              1 },
		{ GL_FRONT_FACE,                             1 },
		{ GL_GREEN_BIAS,                             1 },
		{ GL_GREEN_BITS,                             1 },
		{ GL_GREEN_SCALE,                            1 },
		{ GL_INDEX_ARRAY,                            1 },
		{ GL_INDEX_ARRAY_STRIDE,                     1 },
		{ GL_INDEX_ARRAY_TYPE,                       1 },
		{ GL_INDEX_BITS,                             1 },
		{ GL_INDEX_CLEAR_VALUE,                      1 },
		{ GL_INDEX_LOGIC_OP,                         1 },
		{ GL_INDEX_MODE,                             1 },
		{ GL_INDEX_OFFSET,                           1 },
		{ GL_INDEX_SHIFT,                            1 },
		{ GL_INDEX_WRITEMASK,                        1 },
		{ GL_LIGHTING,                               1 },
		{ GL_LIGHT_MODEL_AMBIENT,                    4 },
		{ GL_LIGHT_MODEL_LOCAL_VIEWER,               1 },
		{ GL_LIGHT_MODEL_TWO_SIDE,                   1 },
		{ GL_LINE_SMOOTH,                            1 },
		{ GL_LINE_SMOOTH_HINT,                       1 },
		{ GL_LINE_STIPPLE,                           1 },
		{ GL_LINE_STIPPLE_PATTERN,                   1 },
		{ GL_LINE_STIPPLE_REPEAT,                    1 },
		{ GL_LINE_WIDTH,                             1 },
		{ GL_LINE_WIDTH_GRANULARITY,                 1 },
		{ GL_LINE_WIDTH_RANGE,                       2 },
		{ GL_LIST_BASE,                              1 },
		{ GL_LIST_INDEX,                             1 },
		{ GL_LIST_MODE,                              1 },
		{ GL_LOGIC_OP_MODE,                          1 },
		{ GL_MAP1_COLOR_4,                           1 },
		{ GL_MAP1_GRID_DOMAIN,                       2 },
		{ GL_MAP1_GRID_SEGMENTS,                     1 },
		{ GL_MAP1_INDEX,                             1 },
		{ GL_MAP1_NORMAL,                            1 },
		{ GL_MAP1_TEXTURE_COORD_1,                   1 },
		{ GL_MAP1_TEXTURE_COORD_2,                   1 },
		{ GL_MAP1_TEXTURE_COORD_3,                   1 },
		{ GL_MAP1_TEXTURE_COORD_4,                   1 },
		{ GL_MAP1_VERTEX_3,                          1 },
		{ GL_MAP1_VERTEX_4,                          1 },
		{ GL_MAP2_COLOR_4,                           1 },
		{ GL_MAP2_GRID_DOMAIN,                       4 },
		{ GL_MAP2_GRID_SEGMENTS,                     2 },
		{ GL_MAP2_INDEX,                             1 },
		{ GL_MAP2_NORMAL,                            1 },
		{ GL_MAP2_TEXTURE_COORD_1,                   1 },
		{ GL_MAP2_TEXTURE_COORD_2,                   1 },
		{ GL_MAP2_TEXTURE_COORD_3,                   1 },
		{ GL_MAP2_TEXTURE_COORD_4,                   1 },
		{ GL_MAP2_VERTEX_3,                          1 },
		{ GL_MAP2_VERTEX_4,                          1 },
		{ GL_MAP_COLOR,                              1 },
		{ GL_MAP_STENCIL,                            1 },
		{ GL_MATRIX_MODE,                            1 },
		{ GL_MAX_CLIENT_ATTRIB_STACK_DEPTH,          1 },
		{ GL_MAX_ATTRIB_STACK_DEPTH,                 1 },
		{ GL_MAX_CLIP_PLANES,                        1 },
		{ GL_MAX_EVAL_ORDER,                         1 },
		{ GL_MAX_LIGHTS,                             1 },
		{ GL_MAX_LIST_NESTING,                       1 },
		{ GL_MAX_MODELVIEW_STACK_DEPTH,              1 },
		{ GL_MAX_NAME_STACK_DEPTH,                   1 },
		{ GL_MAX_PIXEL_MAP_TABLE,                    1 },
		{ GL_MAX_PROJECTION_STACK_DEPTH,             1 },
		{ GL_MAX_TEXTURE_SIZE,                       1 },
		{ GL_MAX_TEXTURE_STACK_DEPTH,                1 },
		{ GL_MAX_VIEWPORT_DIMS,                      2 },
		{ GL_MODELVIEW_MATRIX,                      16 },
		{ GL_MODELVIEW_STACK_DEPTH,                  1 },
		{ GL_NAME_STACK_DEPTH,                       1 },
		{ GL_NORMAL_ARRAY,                           1 },
		{ GL_NORMAL_ARRAY_STRIDE,                    1 },
		{ GL_NORMAL_ARRAY_TYPE,                      1 },
		{ GL_NORMALIZE,                              1 },
		{ GL_PACK_ALIGNMENT,                         1 },
		{ GL_PACK_LSB_FIRST,                         1 },
		{ GL_PACK_ROW_LENGTH,                        1 },
		{ GL_PACK_SKIP_PIXELS,                       1 },
		{ GL_PACK_SKIP_ROWS,                         1 },
		{ GL_PACK_SWAP_BYTES,                        1 },
		{ GL_PERSPECTIVE_CORRECTION_HINT,            1 },
		{ GL_PIXEL_MAP_A_TO_A_SIZE,                  1 },
		{ GL_PIXEL_MAP_B_TO_B_SIZE,                  1 },
		{ GL_PIXEL_MAP_G_TO_G_SIZE,                  1 },
		{ GL_PIXEL_MAP_I_TO_A_SIZE,                  1 },
		{ GL_PIXEL_MAP_I_TO_B_SIZE,                  1 },
		{ GL_PIXEL_MAP_I_TO_G_SIZE,                  1 },
		{ GL_PIXEL_MAP_I_TO_I_SIZE,                  1 },
		{ GL_PIXEL_MAP_I_TO_R_SIZE,                  1 },
		{ GL_PIXEL_MAP_R_TO_R_SIZE,                  1 },
		{ GL_PIXEL_MAP_S_TO_S_SIZE,                  1 },
		{ GL_POINT_SIZE,                             1 },
		{ GL_POINT_SIZE_GRANULARITY,                 1 },
		{ GL_POINT_SIZE_RANGE,                       2 },
		{ GL_POINT_SMOOTH,                           1 },
		{ GL_POINT_SMOOTH_HINT,                      1 },
		{ GL_POLYGON_MODE,                           2 },
		{ GL_POLYGON_OFFSET_FACTOR,                  1 },
		{ GL_POLYGON_OFFSET_UNITS,                   1 },
		{ GL_POLYGON_OFFSET_FILL,                    1 },
		{ GL_POLYGON_OFFSET_LINE,                    1 },
		{ GL_POLYGON_OFFSET_POINT,                   1 },
		{ GL_POLYGON_SMOOTH,                         1 },
		{ GL_POLYGON_SMOOTH_HINT,                    1 },
		{ GL_POLYGON_STIPPLE,                        1 },
		{ GL_PROJECTION_MATRIX,                     16 },
		{ GL_PROJECTION_STACK_DEPTH,                 1 },
		{ GL_READ_BUFFER,                            1 },
		{ GL_RED_BIAS,                               1 },
		{ GL_RED_BITS,                               1 },
		{ GL_RED_SCALE,                              1 },
		{ GL_RENDER_MODE,                            1 },
		{ GL_RGBA_MODE,                              1 },
		{ GL_SCISSOR_BOX,                            4 },
		{ GL_SCISSOR_TEST,                           1 },
		{ GL_SELECTION_BUFFER_SIZE,                  1 },
		{ GL_SHADE_MODEL,                            1 },
		{ GL_STENCIL_BITS,                           1 },
		{ GL_STENCIL_CLEAR_VALUE,                    1 },
		{ GL_STENCIL_FAIL,                           1 },
		{ GL_STENCIL_FUNC,                           1 },
		{ GL_STENCIL_PASS_DEPTH_FAIL,                1 },
		{ GL_STENCIL_PASS_DEPTH_PASS,                1 },
		{ GL_STENCIL_REF,                            1 },
		{ GL_STENCIL_TEST,                           1 },
		{ GL_STENCIL_VALUE_MASK,                     1 },
		{ GL_STENCIL_WRITEMASK,                      1 },
		{ GL_STEREO,                                 1 },
		{ GL_SUBPIXEL_BITS,                          1 },
		{ GL_TEXTURE_1D,                             1 },
		{ GL_TEXTURE_BINDING_1D,                     1 },
		{ GL_TEXTURE_2D,                             1 },
		{ GL_TEXTURE_BINDING_2D,                     1 },
		{ GL_TEXTURE_COORD_ARRAY,                    1 },
		{ GL_TEXTURE_COORD_ARRAY_SIZE,               1 },
		{ GL_TEXTURE_COORD_ARRAY_STRIDE,             1 },
		{ GL_TEXTURE_COORD_ARRAY_TYPE,               1 },
		{ GL_TEXTURE_GEN_Q,                          1 },
		{ GL_TEXTURE_GEN_R,                          1 },
		{ GL_TEXTURE_GEN_S,                          1 },
		{ GL_TEXTURE_GEN_T,                          1 },
		{ GL_TEXTURE_MATRIX,                        16 },
		{ GL_TEXTURE_STACK_DEPTH,                    1 },
		{ GL_UNPACK_ALIGNMENT,                       1 },
		{ GL_UNPACK_LSB_FIRST,                       1 },
		{ GL_UNPACK_ROW_LENGTH,                      1 },
		{ GL_UNPACK_SKIP_PIXELS,                     1 },
		{ GL_UNPACK_SKIP_ROWS,                       1 },
		{ GL_UNPACK_SWAP_BYTES,                      1 },
		{ GL_VERTEX_ARRAY,                           1 },
		{ GL_VERTEX_ARRAY_SIZE,                      1 },
		{ GL_VERTEX_ARRAY_STRIDE,                    1 },
		{ GL_VERTEX_ARRAY_TYPE,                      1 },
		{ GL_VIEWPORT,                               4 },
		{ GL_ZOOM_X,                                 1 },
		{ GL_ZOOM_Y,                                 1 },
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].pname == pname) return tbl[i].n;
	}
	return 0;
}

size_t GetLightParamCount(GLenum pname)
{
	static const struct {
		GLenum pname;
		size_t n;
	} tbl[] = {
		{ GL_AMBIENT,               4 },
		{ GL_DIFFUSE,               4 },
		{ GL_SPECULAR,              4 },
		{ GL_POSITION,              4 },
		{ GL_SPOT_DIRECTION,        3 },
		{ GL_SPOT_EXPONENT,         1 },
		{ GL_SPOT_CUTOFF,           1 },
		{ GL_CONSTANT_ATTENUATION,  1 },
		{ GL_LINEAR_ATTENUATION,    1 },
		{ GL_QUADRATIC_ATTENUATION, 1 },
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].pname == pname) return tbl[i].n;
	}
	return 0;
}

GLenum GetImageFormat(Signal sig, const Image *pImage)
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
// Gura interfaces for Object_image
// These method are available after importing opengl module.
//-----------------------------------------------------------------------------
// image#opengl():reduce {block}
Gura_DeclareMethod(image, opengl)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementMethod(image, opengl)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	if (!DoGLSection(env, sig, args, pThis->GetImage())) return Value::Null;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: opengl
//-----------------------------------------------------------------------------
#include "HandCoded.cpp"
#include "Converted.cpp"

Gura_ModuleEntry()
{
	ModuleEntrySub(env, sig);
	Gura_AssignMethodTo(VTYPE_image, image, opengl);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
#if GURA_USE_MSWIN_DIB
bool DoGLSection(Environment &env, Signal sig, Args &args, Image *pImage)
{
	PIXELFORMATDESCRIPTOR pfd = { 
		sizeof(PIXELFORMATDESCRIPTOR), 1,
		PFD_DRAW_TO_BITMAP | PFD_SUPPORT_OPENGL, PFD_TYPE_RGBA,
		static_cast<BYTE>(pImage->GetBitsPerPixel()), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		32, 0, 0, PFD_MAIN_PLANE, 0, 0, 0, 0
	}; 
	HDC hdc = ::CreateCompatibleDC(NULL);
	HBITMAP hBmp = pImage->GetHBITMAP();
	HBITMAP hBmpOld = reinterpret_cast<HBITMAP>(::SelectObject(hdc, hBmp));
	int iPixelFormat = ::ChoosePixelFormat(hdc, &pfd);
	::SetPixelFormat(hdc, iPixelFormat, &pfd);
	HGLRC hglrc = ::wglCreateContext(hdc);
	::wglMakeCurrent(hdc, hglrc);
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (!sig.IsSignalled()) {
		pExprBlock->Exec(env, sig);
	}
	::wglMakeCurrent(NULL, NULL);
	::wglDeleteContext(hglrc);
	::SelectObject(hdc, hBmpOld);
	::DeleteDC(hdc);
	return true;
}
#else
bool DoGLSection(Environment &env, Signal sig, Args &args, Image *pImage)
{
#if 0
	int width = static_cast<int>(pImage->GetWidth());
	int height = static_cast<int>(pImage->GetHeight());
	GLXFBConfig config;
	Pixmap pixmap = ::XCreatePixmap(NULL, d, width, height, 32);
	GLXPixmap xid = ::glXCreatePixmap(NULL, config, pixmap, NULL);
	GLXContext ctx;
	::glXMakeCurrent(NULL, xid, ctx);
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (!sig.IsSignalled()) {
		pExprBlock->Exec(env, sig);
	}
	::glReadPixels(0, 0, width, height, GL_BGRA_EXT,
									GL_UNSIGNED_BYTE, pImage->GetBuffer());
#endif
	return true;
}
#endif

Gura_EndModule(opengl, opengl)

Gura_RegisterModule(opengl)
