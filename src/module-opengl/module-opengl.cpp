//-----------------------------------------------------------------------------
// Gura module: opengl
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(opengl)

void AssignValues(Environment &env);
void AssignFunctions(Environment &env);

typedef std::map<GLenum, size_t> ParamInfoDict;

static ParamInfoDict *_pParamInfoDict = nullptr;

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
size_t GetParamCount(GLenum pname)
{
	ParamInfoDict::iterator iter = _pParamInfoDict->find(pname);
	if (iter == _pParamInfoDict->end()) return 16;
	return iter->second;
}

bool CheckParamCount(GLenum pname, size_t n)
{
	ParamInfoDict::iterator iter = _pParamInfoDict->find(pname);
	if (iter == _pParamInfoDict->end()) return true;
	return n == iter->second;
}

void PrepareParamInfoDict()
{
	_pParamInfoDict = new ParamInfoDict();
	static const struct {
		GLenum pname;
		size_t n;
	} tbl[] = {
#if defined(GL_ACCUM_ALPHA_BITS)
		{ GL_ACCUM_ALPHA_BITS,						 1 },
#endif
#if defined(GL_ACCUM_BLUE_BITS)
		{ GL_ACCUM_BLUE_BITS,						 1 },
#endif
#if defined(GL_ACCUM_CLEAR_VALUE)
		{ GL_ACCUM_CLEAR_VALUE,						 4 },
#endif
#if defined(GL_ACCUM_GREEN_BITS)
		{ GL_ACCUM_GREEN_BITS,						 1 },
#endif
#if defined(GL_ACCUM_RED_BITS)
		{ GL_ACCUM_RED_BITS,						 1 },
#endif
#if defined(GL_ACTIVE_ATTRIBUTES)
		{ GL_ACTIVE_ATTRIBUTES,						 1 },
#endif
#if defined(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH)
		{ GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,			 1 },
#endif
#if defined(GL_ACTIVE_TEXTURE)
		{ GL_ACTIVE_TEXTURE,						 1 },
#endif
#if defined(GL_ACTIVE_UNIFORMS)
		{ GL_ACTIVE_UNIFORMS,						 1 },
#endif
#if defined(GL_ACTIVE_UNIFORM_MAX_LENGTH)
		{ GL_ACTIVE_UNIFORM_MAX_LENGTH,				 1 },
#endif
#if defined(GL_ALIASED_LINE_WIDTH_RANGE)
		{ GL_ALIASED_LINE_WIDTH_RANGE,				 2 },
#endif
#if defined(GL_ALIASED_POINT_SIZE_RANGE)
		{ GL_ALIASED_POINT_SIZE_RANGE,				 2 },
#endif
#if defined(GL_ALPHA_BIAS)
		{ GL_ALPHA_BIAS,							 1 },
#endif
#if defined(GL_ALPHA_BITS)
		{ GL_ALPHA_BITS,							 1 },
#endif
#if defined(GL_ALPHA_SCALE)
		{ GL_ALPHA_SCALE,							 1 },
#endif
#if defined(GL_ALPHA_TEST)
		{ GL_ALPHA_TEST,							 1 },
#endif
#if defined(GL_ALPHA_TEST_REF)
		{ GL_ALPHA_TEST_REF,						 1 },
#endif
#if defined(GL_AMBIENT)
		{ GL_AMBIENT,								 4 },
#endif
#if defined(GL_ARRAY_BUFFER_BINDING)
		{ GL_ARRAY_BUFFER_BINDING,					 1 },
#endif
#if defined(GL_ATTACHED_SHADERS)
		{ GL_ATTACHED_SHADERS,						 1 },
#endif
#if defined(GL_ATTRIB_STACK_DEPTH)
		{ GL_ATTRIB_STACK_DEPTH,					 1 },
#endif
#if defined(GL_AUTO_NORMAL)
		{ GL_AUTO_NORMAL,							 1 },
#endif
#if defined(GL_AUX_BUFFERS)
		{ GL_AUX_BUFFERS,							 1 },
#endif
#if defined(GL_BLEND)
		{ GL_BLEND,									 1 },
#endif
#if defined(GL_BLEND_COLOR)
		{ GL_BLEND_COLOR,							 4 },
#endif
#if defined(GL_BLEND_DST_ALPHA)
		{ GL_BLEND_DST_ALPHA,						 1 },
#endif
#if defined(GL_BLEND_DST_RGB)
		{ GL_BLEND_DST_RGB,							 1 },
#endif
#if defined(GL_BLEND_EQUATION_ALPHA)
		{ GL_BLEND_EQUATION_ALPHA,					 1 },
#endif
#if defined(GL_BLEND_EQUATION_RGB)
		{ GL_BLEND_EQUATION_RGB,					 1 },
#endif
#if defined(GL_BLEND_SRC_ALPHA)
		{ GL_BLEND_SRC_ALPHA,						 1 },
#endif
#if defined(GL_BLEND_SRC_RGB)
		{ GL_BLEND_SRC_RGB,							 1 },
#endif
#if defined(GL_BLUE_BIAS)
		{ GL_BLUE_BIAS,								 1 },
#endif
#if defined(GL_BLUE_BITS)
		{ GL_BLUE_BITS,								 1 },
#endif
#if defined(GL_BLUE_SCALE)
		{ GL_BLUE_SCALE,							 1 },
#endif
#if defined(GL_CLIENT_ACTIVE_TEXTURE)
		{ GL_CLIENT_ACTIVE_TEXTURE,					 1 },
#endif
#if defined(GL_CLIENT_ATTRIB_STACK_DEPTH)
		{ GL_CLIENT_ATTRIB_STACK_DEPTH,				 1 },
#endif
//#if defined(GL_CLIP_PLANEi)
//		{ GL_CLIP_PLANEi,							 1 },
//#endif
#if defined(GL_COLOR_ARRAY)
		{ GL_COLOR_ARRAY,							 1 },
#endif
#if defined(GL_COLOR_ARRAY_BUFFER_BINDING)
		{ GL_COLOR_ARRAY_BUFFER_BINDING,			 1 },
#endif
#if defined(GL_COLOR_ARRAY_SIZE)
		{ GL_COLOR_ARRAY_SIZE,						 1 },
#endif
#if defined(GL_COLOR_ARRAY_STRIDE)
		{ GL_COLOR_ARRAY_STRIDE,					 1 },
#endif
#if defined(GL_COLOR_ARRAY_TYPE)
		{ GL_COLOR_ARRAY_TYPE,						 1 },
#endif
#if defined(GL_COLOR_CLEAR_VALUE)
		{ GL_COLOR_CLEAR_VALUE,						 4 },
#endif
#if defined(GL_COLOR_INDEXES)
		{ GL_COLOR_INDEXES,							 3 },
#endif
#if defined(GL_COLOR_LOGIC_OP)
		{ GL_COLOR_LOGIC_OP,						 1 },
#endif
#if defined(GL_COLOR_MATERIAL)
		{ GL_COLOR_MATERIAL,						 1 },
#endif
#if defined(GL_COLOR_MATERIAL_FACE)
		{ GL_COLOR_MATERIAL_FACE,					 1 },
#endif
#if defined(GL_COLOR_MATERIAL_PARAMETER)
		{ GL_COLOR_MATERIAL_PARAMETER,				 1 },
#endif
#if defined(GL_COLOR_MATRIX)
		{ GL_COLOR_MATRIX,							16 },
#endif
#if defined(GL_COLOR_MATRIX_STACK_DEPTH)
		{ GL_COLOR_MATRIX_STACK_DEPTH,				 1 },
#endif
#if defined(GL_COLOR_SUM)
		{ GL_COLOR_SUM,								 1 },
#endif
#if defined(GL_COLOR_TABLE)
		{ GL_COLOR_TABLE,							 1 },
#endif
#if defined(GL_COLOR_TABLE_ALPHA_SIZE)
		{ GL_COLOR_TABLE_ALPHA_SIZE,				 1 },
#endif
#if defined(GL_COLOR_TABLE_BIAS)
		{ GL_COLOR_TABLE_BIAS,						 4 },
#endif
#if defined(GL_COLOR_TABLE_BLUE_SIZE)
		{ GL_COLOR_TABLE_BLUE_SIZE,					 1 },
#endif
#if defined(GL_COLOR_TABLE_FORMAT)
		{ GL_COLOR_TABLE_FORMAT,					 1 },
#endif
#if defined(GL_COLOR_TABLE_GREEN_SIZE)
		{ GL_COLOR_TABLE_GREEN_SIZE,				 1 },
#endif
#if defined(GL_COLOR_TABLE_INTENSITY_SIZE)
		{ GL_COLOR_TABLE_INTENSITY_SIZE,			 1 },
#endif
#if defined(GL_COLOR_TABLE_LUMINANCE_SIZE)
		{ GL_COLOR_TABLE_LUMINANCE_SIZE,			 1 },
#endif
#if defined(GL_COLOR_TABLE_RED_SIZE)
		{ GL_COLOR_TABLE_RED_SIZE,					 1 },
#endif
#if defined(GL_COLOR_TABLE_SCALE)
		{ GL_COLOR_TABLE_SCALE,						 4 },
#endif
#if defined(GL_COLOR_TABLE_WIDTH)
		{ GL_COLOR_TABLE_WIDTH,						 1 },
#endif
#if defined(GL_COLOR_WRITEMASK)
		{ GL_COLOR_WRITEMASK,						 4 },
#endif
#if defined(GL_COMBINE_ALPHA)
		{ GL_COMBINE_ALPHA,							 1 },
#endif
#if defined(GL_COMBINE_RGB)
		{ GL_COMBINE_RGB,							 1 },
#endif
#if defined(GL_COMPILE_STATUS)
		{ GL_COMPILE_STATUS,						 1 },
#endif
#if defined(GL_COMPRESSED_TEXTURE_FORMATS)
		{ GL_COMPRESSED_TEXTURE_FORMATS,			99 },
#endif
#if defined(GL_CONSTANT_ATTENUATION)
		{ GL_CONSTANT_ATTENUATION,					 1 },
#endif
#if defined(GL_CONVOLUTION_1D)
		{ GL_CONVOLUTION_1D,						 1 },
#endif
#if defined(GL_CONVOLUTION_2D)
		{ GL_CONVOLUTION_2D,						 1 },
#endif
#if defined(GL_CONVOLUTION_BORDER_COLOR)
		{ GL_CONVOLUTION_BORDER_COLOR,				 4 },
#endif
#if defined(GL_CONVOLUTION_BORDER_MODE)
		{ GL_CONVOLUTION_BORDER_MODE,				 1 },
#endif
#if defined(GL_CONVOLUTION_FILTER_BIAS)
		{ GL_CONVOLUTION_FILTER_BIAS,				 4 },
#endif
#if defined(GL_CONVOLUTION_FILTER_SCALE)
		{ GL_CONVOLUTION_FILTER_SCALE,				 4 },
#endif
#if defined(GL_CONVOLUTION_FORMAT)
		{ GL_CONVOLUTION_FORMAT,					 1 },
#endif
#if defined(GL_CONVOLUTION_HEIGHT)
		{ GL_CONVOLUTION_HEIGHT,					 1 },
#endif
#if defined(GL_CONVOLUTION_WIDTH)
		{ GL_CONVOLUTION_WIDTH,						 1 },
#endif
#if defined(GL_COORD_REPLACE)
		{ GL_COORD_REPLACE,							 1 },
#endif
#if defined(GL_CULL_FACE)
		{ GL_CULL_FACE,								 1 },
#endif
#if defined(GL_CULL_FACE_MODE)
		{ GL_CULL_FACE_MODE,						 1 },
#endif
#if defined(GL_CURRENT_COLOR)
		{ GL_CURRENT_COLOR,							 4 },
#endif
#if defined(GL_CURRENT_FOG_COORD)
		{ GL_CURRENT_FOG_COORD,						 1 },
#endif
#if defined(GL_CURRENT_INDEX)
		{ GL_CURRENT_INDEX,							 1 },
#endif
#if defined(GL_CURRENT_NORMAL)
		{ GL_CURRENT_NORMAL,						 3 },
#endif
#if defined(GL_CURRENT_PROGRAM)
		{ GL_CURRENT_PROGRAM,						 1 },
#endif
#if defined(GL_CURRENT_QUERY)
		{ GL_CURRENT_QUERY,							 1 },
#endif
#if defined(GL_CURRENT_RASTER_COLOR)
		{ GL_CURRENT_RASTER_COLOR,					 4 },
#endif
#if defined(GL_CURRENT_RASTER_DISTANCE)
		{ GL_CURRENT_RASTER_DISTANCE,				 1 },
#endif
#if defined(GL_CURRENT_RASTER_INDEX)
		{ GL_CURRENT_RASTER_INDEX,					 1 },
#endif
#if defined(GL_CURRENT_RASTER_POSITION)
		{ GL_CURRENT_RASTER_POSITION,				 4 },
#endif
#if defined(GL_CURRENT_RASTER_POSITION_VALID)
		{ GL_CURRENT_RASTER_POSITION_VALID,			 1 },
#endif
#if defined(GL_CURRENT_RASTER_SECONDARY_COLOR)
		{ GL_CURRENT_RASTER_SECONDARY_COLOR,		 4 },
#endif
#if defined(GL_CURRENT_RASTER_TEXTURE_COORDS)
		{ GL_CURRENT_RASTER_TEXTURE_COORDS,			 4 },
#endif
#if defined(GL_CURRENT_SECONDARY_COLOR)
		{ GL_CURRENT_SECONDARY_COLOR,				 4 },
#endif
#if defined(GL_CURRENT_TEXTURE_COORDS)
		{ GL_CURRENT_TEXTURE_COORDS,				 4 },
#endif
#if defined(GL_DELETE_STATUS)
		{ GL_DELETE_STATUS,							 1 },
#endif
#if defined(GL_DEPTH_BIAS)
		{ GL_DEPTH_BIAS,							 1 },
#endif
#if defined(GL_DEPTH_BITS)
		{ GL_DEPTH_BITS,							 1 },
#endif
#if defined(GL_DEPTH_CLEAR_VALUE)
		{ GL_DEPTH_CLEAR_VALUE,						 1 },
#endif
#if defined(GL_DEPTH_FUNC)
		{ GL_DEPTH_FUNC,							 1 },
#endif
#if defined(GL_DEPTH_RANGE)
		{ GL_DEPTH_RANGE,							 2 },
#endif
#if defined(GL_DEPTH_SCALE)
		{ GL_DEPTH_SCALE,							 1 },
#endif
#if defined(GL_DEPTH_TEST)
		{ GL_DEPTH_TEST,							 1 },
#endif
#if defined(GL_DEPTH_TEXTURE_MODE)
		{ GL_DEPTH_TEXTURE_MODE,					 1 },
#endif
#if defined(GL_DEPTH_WRITEMASK)
		{ GL_DEPTH_WRITEMASK,						 1 },
#endif
#if defined(GL_DIFFUSE)
		{ GL_DIFFUSE,								 4 },
#endif
#if defined(GL_DITHER)
		{ GL_DITHER,								 1 },
#endif
#if defined(GL_DOUBLEBUFFER)
		{ GL_DOUBLEBUFFER,							 1 },
#endif
#if defined(GL_DRAW_BUFFER)
		{ GL_DRAW_BUFFER,							 1 },
#endif
//#if defined(GL_DRAW_BUFFERi)
//		{ GL_DRAW_BUFFERi,							 1 },
//#endif
#if defined(GL_EDGE_FLAG)
		{ GL_EDGE_FLAG,								 1 },
#endif
#if defined(GL_EDGE_FLAG_ARRAY)
		{ GL_EDGE_FLAG_ARRAY,						 1 },
#endif
#if defined(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING)
		{ GL_EDGE_FLAG_ARRAY_BUFFER_BINDING,		 1 },
#endif
#if defined(GL_EDGE_FLAG_ARRAY_STRIDE)
		{ GL_EDGE_FLAG_ARRAY_STRIDE,				 1 },
#endif
#if defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
		{ GL_ELEMENT_ARRAY_BUFFER_BINDING,			 1 },
#endif
#if defined(GL_EMISSION)
		{ GL_EMISSION,								 4 },
#endif
#if defined(GL_EYE_PLANE)
		{ GL_EYE_PLANE,								 1 },
#endif
#if defined(GL_FEEDBACK_BUFFER_SIZE)
		{ GL_FEEDBACK_BUFFER_SIZE,					 1 },
#endif
#if defined(GL_FEEDBACK_BUFFER_TYPE)
		{ GL_FEEDBACK_BUFFER_TYPE,					 1 },
#endif
#if defined(GL_FOG)
		{ GL_FOG,									 1 },
#endif
#if defined(GL_FOG_COLOR)
		{ GL_FOG_COLOR,								 4 },
#endif
#if defined(GL_FOG_COORD_ARRAY)
		{ GL_FOG_COORD_ARRAY,						 1 },
#endif
#if defined(GL_FOG_COORD_ARRAY_BUFFER_BINDING)
		{ GL_FOG_COORD_ARRAY_BUFFER_BINDING,		 1 },
#endif
#if defined(GL_FOG_COORD_ARRAY_STRIDE)
		{ GL_FOG_COORD_ARRAY_STRIDE,				 1 },
#endif
#if defined(GL_FOG_COORD_ARRAY_TYPE)
		{ GL_FOG_COORD_ARRAY_TYPE,					 1 },
#endif
#if defined(GL_FOG_COORD_SRC)
		{ GL_FOG_COORD_SRC,							 1 },
#endif
#if defined(GL_FOG_DENSITY)
		{ GL_FOG_DENSITY,							 1 },
#endif
#if defined(GL_FOG_END)
		{ GL_FOG_END,								 1 },
#endif
#if defined(GL_FOG_HINT)
		{ GL_FOG_HINT,								 1 },
#endif
#if defined(GL_FOG_INDEX)
		{ GL_FOG_INDEX,								 1 },
#endif
#if defined(GL_FOG_MODE)
		{ GL_FOG_MODE,								 1 },
#endif
#if defined(GL_FOG_START)
		{ GL_FOG_START,								 1 },
#endif
#if defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
		{ GL_FRAGMENT_SHADER_DERIVATIVE_HINT,		 1 },
#endif
#if defined(GL_FRONT_FACE)
		{ GL_FRONT_FACE,							 1 },
#endif
#if defined(GL_GENERATE_MIPMAP)
		{ GL_GENERATE_MIPMAP,						 1 },
#endif
#if defined(GL_GENERATE_MIPMAP_HINT)
		{ GL_GENERATE_MIPMAP_HINT,					 1 },
#endif
#if defined(GL_GREEN_BIAS)
		{ GL_GREEN_BIAS,							 1 },
#endif
#if defined(GL_GREEN_BITS)
		{ GL_GREEN_BITS,							 1 },
#endif
#if defined(GL_GREEN_SCALE)
		{ GL_GREEN_SCALE,							 1 },
#endif
#if defined(GL_HISTOGRAM)
		{ GL_HISTOGRAM,								 1 },
#endif
#if defined(GL_HISTOGRAM_ALPHA_SIZE)
		{ GL_HISTOGRAM_ALPHA_SIZE,					 1 },
#endif
#if defined(GL_HISTOGRAM_BLUE_SIZE)
		{ GL_HISTOGRAM_BLUE_SIZE,					 1 },
#endif
#if defined(GL_HISTOGRAM_FORMAT)
		{ GL_HISTOGRAM_FORMAT,						 1 },
#endif
#if defined(GL_HISTOGRAM_GREEN_SIZE)
		{ GL_HISTOGRAM_GREEN_SIZE,					 1 },
#endif
#if defined(GL_HISTOGRAM_LUMINANCE_SIZE)
		{ GL_HISTOGRAM_LUMINANCE_SIZE,				 1 },
#endif
#if defined(GL_HISTOGRAM_RED_SIZE)
		{ GL_HISTOGRAM_RED_SIZE,					 1 },
#endif
#if defined(GL_HISTOGRAM_SINK)
		{ GL_HISTOGRAM_SINK,						 1 },
#endif
#if defined(GL_HISTOGRAM_WIDTH)
		{ GL_HISTOGRAM_WIDTH,						 1 },
#endif
#if defined(GL_INDEX_ARRAY)
		{ GL_INDEX_ARRAY,							 1 },
#endif
#if defined(GL_INDEX_ARRAY_BUFFER_BINDING)
		{ GL_INDEX_ARRAY_BUFFER_BINDING,			 1 },
#endif
#if defined(GL_INDEX_ARRAY_STRIDE)
		{ GL_INDEX_ARRAY_STRIDE,					 1 },
#endif
#if defined(GL_INDEX_ARRAY_TYPE)
		{ GL_INDEX_ARRAY_TYPE,						 1 },
#endif
#if defined(GL_INDEX_BITS)
		{ GL_INDEX_BITS,							 1 },
#endif
#if defined(GL_INDEX_CLEAR_VALUE)
		{ GL_INDEX_CLEAR_VALUE,						 1 },
#endif
#if defined(GL_INDEX_LOGIC_OP)
		{ GL_INDEX_LOGIC_OP,						 1 },
#endif
#if defined(GL_INDEX_MODE)
		{ GL_INDEX_MODE,							 1 },
#endif
#if defined(GL_INDEX_OFFSET)
		{ GL_INDEX_OFFSET,							 1 },
#endif
#if defined(GL_INDEX_SHIFT)
		{ GL_INDEX_SHIFT,							 1 },
#endif
#if defined(GL_INDEX_WRITEMASK)
		{ GL_INDEX_WRITEMASK,						 1 },
#endif
#if defined(GL_INFO_LOG_LENGTH)
		{ GL_INFO_LOG_LENGTH,						 1 },
#endif
#if defined(GL_LIGHTING)
		{ GL_LIGHTING,								 1 },
#endif
#if defined(GL_LIGHT_MODEL_AMBIENT)
		{ GL_LIGHT_MODEL_AMBIENT,					 4 },
#endif
#if defined(GL_LIGHT_MODEL_COLOR_CONTROL)
		{ GL_LIGHT_MODEL_COLOR_CONTROL,				 1 },
#endif
#if defined(GL_LIGHT_MODEL_LOCAL_VIEWER)
		{ GL_LIGHT_MODEL_LOCAL_VIEWER,				 1 },
#endif
#if defined(GL_LIGHT_MODEL_TWO_SIDE)
		{ GL_LIGHT_MODEL_TWO_SIDE,					 1 },
#endif
//#if defined(GL_LIGHTi)
//		{ GL_LIGHTi,								 1 },
//#endif
#if defined(GL_LINEAR_ATTENUATION)
		{ GL_LINEAR_ATTENUATION,					 1 },
#endif
#if defined(GL_LINE_SMOOTH)
		{ GL_LINE_SMOOTH,							 1 },
#endif
#if defined(GL_LINE_SMOOTH_HINT)
		{ GL_LINE_SMOOTH_HINT,						 1 },
#endif
#if defined(GL_LINE_STIPPLE)
		{ GL_LINE_STIPPLE,							 1 },
#endif
#if defined(GL_LINE_STIPPLE_PATTERN)
		{ GL_LINE_STIPPLE_PATTERN,					 1 },
#endif
#if defined(GL_LINE_STIPPLE_REPEAT)
		{ GL_LINE_STIPPLE_REPEAT,					 1 },
#endif
#if defined(GL_LINE_WIDTH)
		{ GL_LINE_WIDTH,							 1 },
#endif
#if defined(GL_LINE_WIDTH_GRANULARITY)
		{ GL_LINE_WIDTH_GRANULARITY,				 1 },
#endif
#if defined(GL_LINE_WIDTH_RANGE)
		{ GL_LINE_WIDTH_RANGE,						 2 },
#endif
#if defined(GL_LINK_STATUS)
		{ GL_LINK_STATUS,							 1 },
#endif
#if defined(GL_LIST_BASE)
		{ GL_LIST_BASE,								 1 },
#endif
#if defined(GL_LIST_INDEX)
		{ GL_LIST_INDEX,							 1 },
#endif
#if defined(GL_LIST_MODE)
		{ GL_LIST_MODE,								 1 },
#endif
#if defined(GL_LOGIC_OP_MODE)
		{ GL_LOGIC_OP_MODE,							 1 },
#endif
#if defined(GL_MAP1_COLOR_4)
		{ GL_MAP1_COLOR_4,							 1 },
#endif
#if defined(GL_MAP1_GRID_DOMAIN)
		{ GL_MAP1_GRID_DOMAIN,						 2 },
#endif
#if defined(GL_MAP1_GRID_SEGMENTS)
		{ GL_MAP1_GRID_SEGMENTS,					 1 },
#endif
#if defined(GL_MAP1_INDEX)
		{ GL_MAP1_INDEX,							 1 },
#endif
#if defined(GL_MAP1_NORMAL)
		{ GL_MAP1_NORMAL,							 1 },
#endif
#if defined(GL_MAP1_TEXTURE_COORD_1)
		{ GL_MAP1_TEXTURE_COORD_1,					 1 },
#endif
#if defined(GL_MAP1_TEXTURE_COORD_2)
		{ GL_MAP1_TEXTURE_COORD_2,					 1 },
#endif
#if defined(GL_MAP1_TEXTURE_COORD_3)
		{ GL_MAP1_TEXTURE_COORD_3,					 1 },
#endif
#if defined(GL_MAP1_TEXTURE_COORD_4)
		{ GL_MAP1_TEXTURE_COORD_4,					 1 },
#endif
#if defined(GL_MAP1_VERTEX_3)
		{ GL_MAP1_VERTEX_3,							 1 },
#endif
#if defined(GL_MAP1_VERTEX_4)
		{ GL_MAP1_VERTEX_4,							 1 },
#endif
#if defined(GL_MAP2_COLOR_4)
		{ GL_MAP2_COLOR_4,							 1 },
#endif
#if defined(GL_MAP2_GRID_DOMAIN)
		{ GL_MAP2_GRID_DOMAIN,						 4 },
#endif
#if defined(GL_MAP2_GRID_SEGMENTS)
		{ GL_MAP2_GRID_SEGMENTS,					 2 },
#endif
#if defined(GL_MAP2_INDEX)
		{ GL_MAP2_INDEX,							 1 },
#endif
#if defined(GL_MAP2_NORMAL)
		{ GL_MAP2_NORMAL,							 1 },
#endif
#if defined(GL_MAP2_TEXTURE_COORD_1)
		{ GL_MAP2_TEXTURE_COORD_1,					 1 },
#endif
#if defined(GL_MAP2_TEXTURE_COORD_2)
		{ GL_MAP2_TEXTURE_COORD_2,					 1 },
#endif
#if defined(GL_MAP2_TEXTURE_COORD_3)
		{ GL_MAP2_TEXTURE_COORD_3,					 1 },
#endif
#if defined(GL_MAP2_TEXTURE_COORD_4)
		{ GL_MAP2_TEXTURE_COORD_4,					 1 },
#endif
#if defined(GL_MAP2_VERTEX_3)
		{ GL_MAP2_VERTEX_3,							 1 },
#endif
#if defined(GL_MAP2_VERTEX_4)
		{ GL_MAP2_VERTEX_4,							 1 },
#endif
#if defined(GL_MAP_COLOR)
		{ GL_MAP_COLOR,								 1 },
#endif
#if defined(GL_MAP_STENCIL)
		{ GL_MAP_STENCIL,							 1 },
#endif
#if defined(GL_MATRIX_MODE)
		{ GL_MATRIX_MODE,							 1 },
#endif
#if defined(GL_MAX_3D_TEXTURE_SIZE)
		{ GL_MAX_3D_TEXTURE_SIZE,					 1 },
#endif
#if defined(GL_MAX_ATTRIB_STACK_DEPTH)
		{ GL_MAX_ATTRIB_STACK_DEPTH,				 1 },
#endif
#if defined(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH)
		{ GL_MAX_CLIENT_ATTRIB_STACK_DEPTH,			 1 },
#endif
#if defined(GL_MAX_CLIP_PLANES)
		{ GL_MAX_CLIP_PLANES,						 1 },
#endif
#if defined(GL_MAX_COLOR_MATRIX_STACK_DEPTH)
		{ GL_MAX_COLOR_MATRIX_STACK_DEPTH,			 1 },
#endif
#if defined(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS)
		{ GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,		 1 },
#endif
#if defined(GL_MAX_CONVOLUTION_HEIGHT)
		{ GL_MAX_CONVOLUTION_HEIGHT,				 1 },
#endif
#if defined(GL_MAX_CONVOLUTION_WIDTH)
		{ GL_MAX_CONVOLUTION_WIDTH,					 1 },
#endif
#if defined(GL_MAX_CUBE_MAP_TEXTURE_SIZE)
		{ GL_MAX_CUBE_MAP_TEXTURE_SIZE,				 1 },
#endif
#if defined(GL_MAX_DRAW_BUFFERS)
		{ GL_MAX_DRAW_BUFFERS,						 1 },
#endif
#if defined(GL_MAX_ELEMENTS_INDICES)
		{ GL_MAX_ELEMENTS_INDICES,					 1 },
#endif
#if defined(GL_MAX_ELEMENTS_VERTICES)
		{ GL_MAX_ELEMENTS_VERTICES,					 1 },
#endif
#if defined(GL_MAX_EVAL_ORDER)
		{ GL_MAX_EVAL_ORDER,						 1 },
#endif
#if defined(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS)
		{ GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,		 1 },
#endif
#if defined(GL_MAX_LIGHTS)
		{ GL_MAX_LIGHTS,							 1 },
#endif
#if defined(GL_MAX_LIST_NESTING)
		{ GL_MAX_LIST_NESTING,						 1 },
#endif
#if defined(GL_MAX_MODELVIEW_STACK_DEPTH)
		{ GL_MAX_MODELVIEW_STACK_DEPTH,				 1 },
#endif
#if defined(GL_MAX_NAME_STACK_DEPTH)
		{ GL_MAX_NAME_STACK_DEPTH,					 1 },
#endif
#if defined(GL_MAX_PIXEL_MAP_TABLE)
		{ GL_MAX_PIXEL_MAP_TABLE,					 1 },
#endif
#if defined(GL_MAX_PROJECTION_STACK_DEPTH)
		{ GL_MAX_PROJECTION_STACK_DEPTH,			 1 },
#endif
#if defined(GL_MAX_TEXTURE_COORDS)
		{ GL_MAX_TEXTURE_COORDS,					 1 },
#endif
#if defined(GL_MAX_TEXTURE_IMAGE_UNITS)
		{ GL_MAX_TEXTURE_IMAGE_UNITS,				 1 },
#endif
#if defined(GL_MAX_TEXTURE_LOD_BIAS)
		{ GL_MAX_TEXTURE_LOD_BIAS,					 1 },
#endif
#if defined(GL_MAX_TEXTURE_SIZE)
		{ GL_MAX_TEXTURE_SIZE,						 1 },
#endif
#if defined(GL_MAX_TEXTURE_STACK_DEPTH)
		{ GL_MAX_TEXTURE_STACK_DEPTH,				 1 },
#endif
#if defined(GL_MAX_TEXTURE_UNITS)
		{ GL_MAX_TEXTURE_UNITS,						 1 },
#endif
#if defined(GL_MAX_VARYING_FLOATS)
		{ GL_MAX_VARYING_FLOATS,					 1 },
#endif
#if defined(GL_MAX_VERTEX_ATTRIBS)
		{ GL_MAX_VERTEX_ATTRIBS,					 1 },
#endif
#if defined(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS)
		{ GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,		 1 },
#endif
#if defined(GL_MAX_VERTEX_UNIFORM_COMPONENTS)
		{ GL_MAX_VERTEX_UNIFORM_COMPONENTS,			 1 },
#endif
#if defined(GL_MAX_VIEWPORT_DIMS)
		{ GL_MAX_VIEWPORT_DIMS,						 2 },
#endif
#if defined(GL_MINMAX)
		{ GL_MINMAX,								 1 },
#endif
#if defined(GL_MINMAX_FORMAT)
		{ GL_MINMAX_FORMAT,							 1 },
#endif
#if defined(GL_MINMAX_SINK)
		{ GL_MINMAX_SINK,							 1 },
#endif
#if defined(GL_MODELVIEW_MATRIX)
		{ GL_MODELVIEW_MATRIX,						16 },
#endif
#if defined(GL_MODELVIEW_STACK_DEPTH)
		{ GL_MODELVIEW_STACK_DEPTH,					 1 },
#endif
#if defined(GL_NAME_STACK_DEPTH)
		{ GL_NAME_STACK_DEPTH,						 1 },
#endif
#if defined(GL_NORMALIZE)
		{ GL_NORMALIZE,								 1 },
#endif
#if defined(GL_NORMAL_ARRAY)
		{ GL_NORMAL_ARRAY,							 1 },
#endif
#if defined(GL_NORMAL_ARRAY_BUFFER_BINDING)
		{ GL_NORMAL_ARRAY_BUFFER_BINDING,			 1 },
#endif
#if defined(GL_NORMAL_ARRAY_STRIDE)
		{ GL_NORMAL_ARRAY_STRIDE,					 1 },
#endif
#if defined(GL_NORMAL_ARRAY_TYPE)
		{ GL_NORMAL_ARRAY_TYPE,						 1 },
#endif
#if defined(GL_NUM_COMPRESSED_TEXTURE_FORMATS)
		{ GL_NUM_COMPRESSED_TEXTURE_FORMATS,		 1 },
#endif
#if defined(GL_OBJECT_PLANE)
		{ GL_OBJECT_PLANE,							 1 },
#endif
#if defined(GL_OPERAND0_ALPHA)
		{ GL_OPERAND0_ALPHA,						 1 },
#endif
#if defined(GL_OPERAND0_RGB)
		{ GL_OPERAND0_RGB,							 1 },
#endif
#if defined(GL_OPERAND1_ALPHA)
		{ GL_OPERAND1_ALPHA,						 1 },
#endif
#if defined(GL_OPERAND1_RGB)
		{ GL_OPERAND1_RGB,							 1 },
#endif
#if defined(GL_OPERAND2_ALPHA)
		{ GL_OPERAND2_ALPHA,						 1 },
#endif
#if defined(GL_OPERAND2_RGB)
		{ GL_OPERAND2_RGB,							 1 },
#endif
#if defined(GL_PACK_ALIGNMENT)
		{ GL_PACK_ALIGNMENT,						 1 },
#endif
#if defined(GL_PACK_IMAGE_HEIGHT)
		{ GL_PACK_IMAGE_HEIGHT,						 1 },
#endif
#if defined(GL_PACK_LSB_FIRST)
		{ GL_PACK_LSB_FIRST,						 1 },
#endif
#if defined(GL_PACK_ROW_LENGTH)
		{ GL_PACK_ROW_LENGTH,						 1 },
#endif
#if defined(GL_PACK_SKIP_IMAGES)
		{ GL_PACK_SKIP_IMAGES,						 1 },
#endif
#if defined(GL_PACK_SKIP_PIXELS)
		{ GL_PACK_SKIP_PIXELS,						 1 },
#endif
#if defined(GL_PACK_SKIP_ROWS)
		{ GL_PACK_SKIP_ROWS,						 1 },
#endif
#if defined(GL_PACK_SWAP_BYTES)
		{ GL_PACK_SWAP_BYTES,						 1 },
#endif
#if defined(GL_PERSPECTIVE_CORRECTION_HINT)
		{ GL_PERSPECTIVE_CORRECTION_HINT,			 1 },
#endif
#if defined(GL_PIXEL_MAP_A_TO_A_SIZE)
		{ GL_PIXEL_MAP_A_TO_A_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_MAP_B_TO_B_SIZE)
		{ GL_PIXEL_MAP_B_TO_B_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_MAP_G_TO_G_SIZE)
		{ GL_PIXEL_MAP_G_TO_G_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_MAP_I_TO_A_SIZE)
		{ GL_PIXEL_MAP_I_TO_A_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_MAP_I_TO_B_SIZE)
		{ GL_PIXEL_MAP_I_TO_B_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_MAP_I_TO_G_SIZE)
		{ GL_PIXEL_MAP_I_TO_G_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_MAP_I_TO_I_SIZE)
		{ GL_PIXEL_MAP_I_TO_I_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_MAP_I_TO_R_SIZE)
		{ GL_PIXEL_MAP_I_TO_R_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_MAP_R_TO_R_SIZE)
		{ GL_PIXEL_MAP_R_TO_R_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_MAP_S_TO_S_SIZE)
		{ GL_PIXEL_MAP_S_TO_S_SIZE,					 1 },
#endif
#if defined(GL_PIXEL_PACK_BUFFER_BINDING)
		{ GL_PIXEL_PACK_BUFFER_BINDING,				 1 },
#endif
#if defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
		{ GL_PIXEL_UNPACK_BUFFER_BINDING,			 1 },
#endif
#if defined(GL_POINT_DISTANCE_ATTENUATION)
		{ GL_POINT_DISTANCE_ATTENUATION,			 3 },
#endif
#if defined(GL_POINT_FADE_THRESHOLD_SIZE)
		{ GL_POINT_FADE_THRESHOLD_SIZE,				 1 },
#endif
#if defined(GL_POINT_SIZE)
		{ GL_POINT_SIZE,							 1 },
#endif
#if defined(GL_POINT_SIZE_GRANULARITY)
		{ GL_POINT_SIZE_GRANULARITY,				 1 },
#endif
#if defined(GL_POINT_SIZE_MAX)
		{ GL_POINT_SIZE_MAX,						 1 },
#endif
#if defined(GL_POINT_SIZE_MIN)
		{ GL_POINT_SIZE_MIN,						 1 },
#endif
#if defined(GL_POINT_SIZE_RANGE)
		{ GL_POINT_SIZE_RANGE,						 2 },
#endif
#if defined(GL_POINT_SMOOTH)
		{ GL_POINT_SMOOTH,							 1 },
#endif
#if defined(GL_POINT_SMOOTH_HINT)
		{ GL_POINT_SMOOTH_HINT,						 1 },
#endif
#if defined(GL_POINT_SPRITE)
		{ GL_POINT_SPRITE,							 1 },
#endif
#if defined(GL_POLYGON_MODE)
		{ GL_POLYGON_MODE,							 2 },
#endif
#if defined(GL_POLYGON_OFFSET_FACTOR)
		{ GL_POLYGON_OFFSET_FACTOR,					 1 },
#endif
#if defined(GL_POLYGON_OFFSET_FILL)
		{ GL_POLYGON_OFFSET_FILL,					 1 },
#endif
#if defined(GL_POLYGON_OFFSET_LINE)
		{ GL_POLYGON_OFFSET_LINE,					 1 },
#endif
#if defined(GL_POLYGON_OFFSET_POINT)
		{ GL_POLYGON_OFFSET_POINT,					 1 },
#endif
#if defined(GL_POLYGON_OFFSET_UNITS)
		{ GL_POLYGON_OFFSET_UNITS,					 1 },
#endif
#if defined(GL_POLYGON_SMOOTH)
		{ GL_POLYGON_SMOOTH,						 1 },
#endif
#if defined(GL_POLYGON_SMOOTH_HINT)
		{ GL_POLYGON_SMOOTH_HINT,					 1 },
#endif
#if defined(GL_POLYGON_STIPPLE)
		{ GL_POLYGON_STIPPLE,						 1 },
#endif
#if defined(GL_POSITION)
		{ GL_POSITION,								 4 },
#endif
#if defined(GL_POST_COLOR_MATRIX_ALPHA_BIAS)
		{ GL_POST_COLOR_MATRIX_ALPHA_BIAS,			 1 },
#endif
#if defined(GL_POST_COLOR_MATRIX_ALPHA_SCALE)
		{ GL_POST_COLOR_MATRIX_ALPHA_SCALE,			 1 },
#endif
#if defined(GL_POST_COLOR_MATRIX_BLUE_BIAS)
		{ GL_POST_COLOR_MATRIX_BLUE_BIAS,			 1 },
#endif
#if defined(GL_POST_COLOR_MATRIX_BLUE_SCALE)
		{ GL_POST_COLOR_MATRIX_BLUE_SCALE,			 1 },
#endif
#if defined(GL_POST_COLOR_MATRIX_COLOR_TABLE)
		{ GL_POST_COLOR_MATRIX_COLOR_TABLE,			 1 },
#endif
#if defined(GL_POST_COLOR_MATRIX_GREEN_BIAS)
		{ GL_POST_COLOR_MATRIX_GREEN_BIAS,			 1 },
#endif
#if defined(GL_POST_COLOR_MATRIX_GREEN_SCALE)
		{ GL_POST_COLOR_MATRIX_GREEN_SCALE,			 1 },
#endif
#if defined(GL_POST_COLOR_MATRIX_RED_BIAS)
		{ GL_POST_COLOR_MATRIX_RED_BIAS,			 1 },
#endif
#if defined(GL_POST_COLOR_MATRIX_RED_SCALE)
		{ GL_POST_COLOR_MATRIX_RED_SCALE,			 1 },
#endif
#if defined(GL_POST_CONVOLUTION_ALPHA_BIAS)
		{ GL_POST_CONVOLUTION_ALPHA_BIAS,			 1 },
#endif
#if defined(GL_POST_CONVOLUTION_ALPHA_SCALE)
		{ GL_POST_CONVOLUTION_ALPHA_SCALE,			 1 },
#endif
#if defined(GL_POST_CONVOLUTION_BLUE_BIAS)
		{ GL_POST_CONVOLUTION_BLUE_BIAS,			 1 },
#endif
#if defined(GL_POST_CONVOLUTION_BLUE_SCALE)
		{ GL_POST_CONVOLUTION_BLUE_SCALE,			 1 },
#endif
#if defined(GL_POST_CONVOLUTION_COLOR_TABLE)
		{ GL_POST_CONVOLUTION_COLOR_TABLE,			 1 },
#endif
#if defined(GL_POST_CONVOLUTION_GREEN_BIAS)
		{ GL_POST_CONVOLUTION_GREEN_BIAS,			 1 },
#endif
#if defined(GL_POST_CONVOLUTION_GREEN_SCALE)
		{ GL_POST_CONVOLUTION_GREEN_SCALE,			 1 },
#endif
#if defined(GL_POST_CONVOLUTION_RED_BIAS)
		{ GL_POST_CONVOLUTION_RED_BIAS,				 1 },
#endif
#if defined(GL_POST_CONVOLUTION_RED_SCALE)
		{ GL_POST_CONVOLUTION_RED_SCALE,			 1 },
#endif
#if defined(GL_PROJECTION_MATRIX)
		{ GL_PROJECTION_MATRIX,						16 },
#endif
#if defined(GL_PROJECTION_STACK_DEPTH)
		{ GL_PROJECTION_STACK_DEPTH,				 1 },
#endif
#if defined(GL_QUADRATIC_ATTENUATION)
		{ GL_QUADRATIC_ATTENUATION,					 1 },
#endif
#if defined(GL_QUERY_COUNTER_BITS)
		{ GL_QUERY_COUNTER_BITS,					 1 },
#endif
#if defined(GL_QUERY_RESULT)
		{ GL_QUERY_RESULT,							 1 },
#endif
#if defined(GL_QUERY_RESULT_AVAILABLE)
		{ GL_QUERY_RESULT_AVAILABLE,				 1 },
#endif
#if defined(GL_READ_BUFFER)
		{ GL_READ_BUFFER,							 1 },
#endif
#if defined(GL_RED_BIAS)
		{ GL_RED_BIAS,								 1 },
#endif
#if defined(GL_RED_BITS)
		{ GL_RED_BITS,								 1 },
#endif
#if defined(GL_RED_SCALE)
		{ GL_RED_SCALE,								 1 },
#endif
#if defined(GL_RENDER_MODE)
		{ GL_RENDER_MODE,							 1 },
#endif
#if defined(GL_RESCALE_NORMAL)
		{ GL_RESCALE_NORMAL,						 1 },
#endif
#if defined(GL_RGBA_MODE)
		{ GL_RGBA_MODE,								 1 },
#endif
#if defined(GL_RGB_SCALE)
		{ GL_RGB_SCALE,								 1 },
#endif
#if defined(GL_SAMPLES)
		{ GL_SAMPLES,								 1 },
#endif
#if defined(GL_SAMPLE_BUFFERS)
		{ GL_SAMPLE_BUFFERS,						 1 },
#endif
#if defined(GL_SAMPLE_COVERAGE_INVERT)
		{ GL_SAMPLE_COVERAGE_INVERT,				 1 },
#endif
#if defined(GL_SAMPLE_COVERAGE_VALUE)
		{ GL_SAMPLE_COVERAGE_VALUE,					 1 },
#endif
#if defined(GL_SCISSOR_BOX)
		{ GL_SCISSOR_BOX,							 4 },
#endif
#if defined(GL_SCISSOR_TEST)
		{ GL_SCISSOR_TEST,							 1 },
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY)
		{ GL_SECONDARY_COLOR_ARRAY,					 1 },
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING)
		{ GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING,	 1 },
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY_SIZE)
		{ GL_SECONDARY_COLOR_ARRAY_SIZE,			 1 },
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY_STRIDE)
		{ GL_SECONDARY_COLOR_ARRAY_STRIDE,			 1 },
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY_TYPE)
		{ GL_SECONDARY_COLOR_ARRAY_TYPE,			 1 },
#endif
#if defined(GL_SELECTION_BUFFER_SIZE)
		{ GL_SELECTION_BUFFER_SIZE,					 1 },
#endif
#if defined(GL_SEPARABLE_2D)
		{ GL_SEPARABLE_2D,							 1 },
#endif
#if defined(GL_SHADER_SOURCE_LENGTH)
		{ GL_SHADER_SOURCE_LENGTH,					 1 },
#endif
#if defined(GL_SHADER_TYPE)
		{ GL_SHADER_TYPE,							 1 },
#endif
#if defined(GL_SHADE_MODEL)
		{ GL_SHADE_MODEL,							 1 },
#endif
#if defined(GL_SHININESS)
		{ GL_SHININESS,								 1 },
#endif
#if defined(GL_SMOOTH_LINE_WIDTH_GRANULARITY)
		{ GL_SMOOTH_LINE_WIDTH_GRANULARITY,			 1 },
#endif
#if defined(GL_SMOOTH_LINE_WIDTH_RANGE)
		{ GL_SMOOTH_LINE_WIDTH_RANGE,				 2 },
#endif
#if defined(GL_SMOOTH_POINT_SIZE_GRANULARITY)
		{ GL_SMOOTH_POINT_SIZE_GRANULARITY,			 1 },
#endif
#if defined(GL_SMOOTH_POINT_SIZE_RANGE)
		{ GL_SMOOTH_POINT_SIZE_RANGE,				 2 },
#endif
#if defined(GL_SPECULAR)
		{ GL_SPECULAR,								 4 },
#endif
#if defined(GL_SPOT_CUTOFF)
		{ GL_SPOT_CUTOFF,							 1 },
#endif
#if defined(GL_SPOT_DIRECTION)
		{ GL_SPOT_DIRECTION,						 3 },
#endif
#if defined(GL_SPOT_EXPONENT)
		{ GL_SPOT_EXPONENT,							 1 },
#endif
#if defined(GL_SRC0_ALPHA)
		{ GL_SRC0_ALPHA,							 1 },
#endif
#if defined(GL_SRC0_RGB)
		{ GL_SRC0_RGB,								 1 },
#endif
#if defined(GL_SRC1_ALPHA)
		{ GL_SRC1_ALPHA,							 1 },
#endif
#if defined(GL_SRC1_RGB)
		{ GL_SRC1_RGB,								 1 },
#endif
#if defined(GL_SRC2_ALPHA)
		{ GL_SRC2_ALPHA,							 1 },
#endif
#if defined(GL_SRC2_RGB)
		{ GL_SRC2_RGB,								 1 },
#endif
#if defined(GL_STENCIL_BACK_FAIL)
		{ GL_STENCIL_BACK_FAIL,						 1 },
#endif
#if defined(GL_STENCIL_BACK_FUNC)
		{ GL_STENCIL_BACK_FUNC,						 1 },
#endif
#if defined(GL_STENCIL_BACK_PASS_DEPTH_FAIL)
		{ GL_STENCIL_BACK_PASS_DEPTH_FAIL,			 1 },
#endif
#if defined(GL_STENCIL_BACK_PASS_DEPTH_PASS)
		{ GL_STENCIL_BACK_PASS_DEPTH_PASS,			 1 },
#endif
#if defined(GL_STENCIL_BACK_REF)
		{ GL_STENCIL_BACK_REF,						 1 },
#endif
#if defined(GL_STENCIL_BACK_VALUE_MASK)
		{ GL_STENCIL_BACK_VALUE_MASK,				 1 },
#endif
#if defined(GL_STENCIL_BACK_WRITEMASK)
		{ GL_STENCIL_BACK_WRITEMASK,				 1 },
#endif
#if defined(GL_STENCIL_BITS)
		{ GL_STENCIL_BITS,							 1 },
#endif
#if defined(GL_STENCIL_CLEAR_VALUE)
		{ GL_STENCIL_CLEAR_VALUE,					 1 },
#endif
#if defined(GL_STENCIL_FAIL)
		{ GL_STENCIL_FAIL,							 1 },
#endif
#if defined(GL_STENCIL_FUNC)
		{ GL_STENCIL_FUNC,							 1 },
#endif
#if defined(GL_STENCIL_PASS_DEPTH_FAIL)
		{ GL_STENCIL_PASS_DEPTH_FAIL,				 1 },
#endif
#if defined(GL_STENCIL_PASS_DEPTH_PASS)
		{ GL_STENCIL_PASS_DEPTH_PASS,				 1 },
#endif
#if defined(GL_STENCIL_REF)
		{ GL_STENCIL_REF,							 1 },
#endif
#if defined(GL_STENCIL_TEST)
		{ GL_STENCIL_TEST,							 1 },
#endif
#if defined(GL_STENCIL_VALUE_MASK)
		{ GL_STENCIL_VALUE_MASK,					 1 },
#endif
#if defined(GL_STENCIL_WRITEMASK)
		{ GL_STENCIL_WRITEMASK,						 1 },
#endif
#if defined(GL_STEREO)
		{ GL_STEREO,								 1 },
#endif
#if defined(GL_SUBPIXEL_BITS)
		{ GL_SUBPIXEL_BITS,							 1 },
#endif
#if defined(GL_TEXTURE_1D)
		{ GL_TEXTURE_1D,							 1 },
#endif
#if defined(GL_TEXTURE_2D)
		{ GL_TEXTURE_2D,							 1 },
#endif
#if defined(GL_TEXTURE_3D)
		{ GL_TEXTURE_3D,							 1 },
#endif
#if defined(GL_TEXTURE_BASE_LEVEL)
		{ GL_TEXTURE_BASE_LEVEL,					 1 },
#endif
#if defined(GL_TEXTURE_BINDING_1D)
		{ GL_TEXTURE_BINDING_1D,					 1 },
#endif
#if defined(GL_TEXTURE_BINDING_2D)
		{ GL_TEXTURE_BINDING_2D,					 1 },
#endif
#if defined(GL_TEXTURE_BINDING_3D)
		{ GL_TEXTURE_BINDING_3D,					 1 },
#endif
#if defined(GL_TEXTURE_BINDING_CUBE_MAP)
		{ GL_TEXTURE_BINDING_CUBE_MAP,				 1 },
#endif
#if defined(GL_TEXTURE_BORDER)
		{ GL_TEXTURE_BORDER,						 1 },
#endif
#if defined(GL_TEXTURE_BORDER_COLOR)
		{ GL_TEXTURE_BORDER_COLOR,					 4 },
#endif
#if defined(GL_TEXTURE_COMPARE_FUNC)
		{ GL_TEXTURE_COMPARE_FUNC,					 1 },
#endif
#if defined(GL_TEXTURE_COMPARE_MODE)
		{ GL_TEXTURE_COMPARE_MODE,					 1 },
#endif
#if defined(GL_TEXTURE_COMPRESSED)
		{ GL_TEXTURE_COMPRESSED,					 1 },
#endif
#if defined(GL_TEXTURE_COMPRESSED_IMAGE_SIZE)
		{ GL_TEXTURE_COMPRESSED_IMAGE_SIZE,			 1 },
#endif
#if defined(GL_TEXTURE_COMPRESSION_HINT)
		{ GL_TEXTURE_COMPRESSION_HINT,				 1 },
#endif
#if defined(GL_TEXTURE_COORD_ARRAY)
		{ GL_TEXTURE_COORD_ARRAY,					 1 },
#endif
#if defined(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING)
		{ GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING,	 1 },
#endif
#if defined(GL_TEXTURE_COORD_ARRAY_SIZE)
		{ GL_TEXTURE_COORD_ARRAY_SIZE,				 1 },
#endif
#if defined(GL_TEXTURE_COORD_ARRAY_STRIDE)
		{ GL_TEXTURE_COORD_ARRAY_STRIDE,			 1 },
#endif
#if defined(GL_TEXTURE_COORD_ARRAY_TYPE)
		{ GL_TEXTURE_COORD_ARRAY_TYPE,				 1 },
#endif
#if defined(GL_TEXTURE_CUBE_MAP)
		{ GL_TEXTURE_CUBE_MAP,						 1 },
#endif
#if defined(GL_TEXTURE_DEPTH)
		{ GL_TEXTURE_DEPTH,							 1 },
#endif
#if defined(GL_TEXTURE_DEPTH_SIZE)
		{ GL_TEXTURE_DEPTH_SIZE,					 1 },
#endif
#if defined(GL_TEXTURE_ENV_COLOR)
		{ GL_TEXTURE_ENV_COLOR,						 4 },
#endif
#if defined(GL_TEXTURE_ENV_MODE)
		{ GL_TEXTURE_ENV_MODE,						 1 },
#endif
#if defined(GL_TEXTURE_GEN_MODE)
		{ GL_TEXTURE_GEN_MODE,						 1 },
#endif
#if defined(GL_TEXTURE_GEN_Q)
		{ GL_TEXTURE_GEN_Q,							 1 },
#endif
#if defined(GL_TEXTURE_GEN_R)
		{ GL_TEXTURE_GEN_R,							 1 },
#endif
#if defined(GL_TEXTURE_GEN_S)
		{ GL_TEXTURE_GEN_S,							 1 },
#endif
#if defined(GL_TEXTURE_GEN_T)
		{ GL_TEXTURE_GEN_T,							 1 },
#endif
#if defined(GL_TEXTURE_HEIGHT)
		{ GL_TEXTURE_HEIGHT,						 1 },
#endif
#if defined(GL_TEXTURE_INTERNAL_FORMAT)
		{ GL_TEXTURE_INTERNAL_FORMAT,				 1 },
#endif
#if defined(GL_TEXTURE_LOD_BIAS)
		{ GL_TEXTURE_LOD_BIAS,						 1 },
#endif
#if defined(GL_TEXTURE_MAG_FILTER)
		{ GL_TEXTURE_MAG_FILTER,					 1 },
#endif
#if defined(GL_TEXTURE_MATRIX)
		{ GL_TEXTURE_MATRIX,						16 },
#endif
#if defined(GL_TEXTURE_MAX_LEVEL)
		{ GL_TEXTURE_MAX_LEVEL,						 1 },
#endif
#if defined(GL_TEXTURE_MAX_LOD)
		{ GL_TEXTURE_MAX_LOD,						 1 },
#endif
#if defined(GL_TEXTURE_MIN_FILTER)
		{ GL_TEXTURE_MIN_FILTER,					 1 },
#endif
#if defined(GL_TEXTURE_MIN_LOD)
		{ GL_TEXTURE_MIN_LOD,						 1 },
#endif
#if defined(GL_TEXTURE_PRIORITY)
		{ GL_TEXTURE_PRIORITY,						 1 },
#endif
#if defined(GL_TEXTURE_RESIDENT)
		{ GL_TEXTURE_RESIDENT,						 1 },
#endif
#if defined(GL_TEXTURE_STACK_DEPTH)
		{ GL_TEXTURE_STACK_DEPTH,					 1 },
#endif
#if defined(GL_TEXTURE_WIDTH)
		{ GL_TEXTURE_WIDTH,							 1 },
#endif
#if defined(GL_TEXTURE_WRAP_R)
		{ GL_TEXTURE_WRAP_R,						 1 },
#endif
#if defined(GL_TEXTURE_WRAP_S)
		{ GL_TEXTURE_WRAP_S,						 1 },
#endif
#if defined(GL_TEXTURE_WRAP_T)
		{ GL_TEXTURE_WRAP_T,						 1 },
#endif
#if defined(GL_TRANSPOSE_COLOR_MATRIX)
		{ GL_TRANSPOSE_COLOR_MATRIX,				16 },
#endif
#if defined(GL_TRANSPOSE_MODELVIEW_MATRIX)
		{ GL_TRANSPOSE_MODELVIEW_MATRIX,			16 },
#endif
#if defined(GL_TRANSPOSE_PROJECTION_MATRIX)
		{ GL_TRANSPOSE_PROJECTION_MATRIX,			16 },
#endif
#if defined(GL_TRANSPOSE_TEXTURE_MATRIX)
		{ GL_TRANSPOSE_TEXTURE_MATRIX,				16 },
#endif
#if defined(GL_UNPACK_ALIGNMENT)
		{ GL_UNPACK_ALIGNMENT,						 1 },
#endif
#if defined(GL_UNPACK_IMAGE_HEIGHT)
		{ GL_UNPACK_IMAGE_HEIGHT,					 1 },
#endif
#if defined(GL_UNPACK_LSB_FIRST)
		{ GL_UNPACK_LSB_FIRST,						 1 },
#endif
#if defined(GL_UNPACK_ROW_LENGTH)
		{ GL_UNPACK_ROW_LENGTH,						 1 },
#endif
#if defined(GL_UNPACK_SKIP_IMAGES)
		{ GL_UNPACK_SKIP_IMAGES,					 1 },
#endif
#if defined(GL_UNPACK_SKIP_PIXELS)
		{ GL_UNPACK_SKIP_PIXELS,					 1 },
#endif
#if defined(GL_UNPACK_SKIP_ROWS)
		{ GL_UNPACK_SKIP_ROWS,						 1 },
#endif
#if defined(GL_UNPACK_SWAP_BYTES)
		{ GL_UNPACK_SWAP_BYTES,						 1 },
#endif
#if defined(GL_VALIDATE_STATUS)
		{ GL_VALIDATE_STATUS,						 1 },
#endif
#if defined(GL_VERTEX_ARRAY)
		{ GL_VERTEX_ARRAY,							 1 },
#endif
#if defined(GL_VERTEX_ARRAY_BUFFER_BINDING)
		{ GL_VERTEX_ARRAY_BUFFER_BINDING,			 1 },
#endif
#if defined(GL_VERTEX_ARRAY_SIZE)
		{ GL_VERTEX_ARRAY_SIZE,						 1 },
#endif
#if defined(GL_VERTEX_ARRAY_STRIDE)
		{ GL_VERTEX_ARRAY_STRIDE,					 1 },
#endif
#if defined(GL_VERTEX_ARRAY_TYPE)
		{ GL_VERTEX_ARRAY_TYPE,						 1 },
#endif
#if defined(GL_VERTEX_PROGRAM_POINT_SIZE)
		{ GL_VERTEX_PROGRAM_POINT_SIZE,				 1 },
#endif
#if defined(GL_VERTEX_PROGRAM_TWO_SIDE)
		{ GL_VERTEX_PROGRAM_TWO_SIDE,				 1 },
#endif
#if defined(GL_VIEWPORT)
		{ GL_VIEWPORT,								 4 },
#endif
#if defined(GL_ZOOM_X)
		{ GL_ZOOM_X,								 1 },
#endif
#if defined(GL_ZOOM_Y)
		{ GL_ZOOM_Y,								 1 },
#endif
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		(*_pParamInfoDict)[tbl[i].pname] = tbl[i].n;
	}
}

GLenum GetImageFormat(Signal &sig, const Image *pImage)
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
// Gura interfaces for Object_image
// These method are available after importing opengl module.
//-----------------------------------------------------------------------------
// image#opengl():reduce {block}
Gura_DeclareMethod(image, opengl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementMethod(image, opengl)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Nil;
	if (!DoGLSection(env, sig, args, pThis->GetImage())) return Value::Nil;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: opengl
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	PrepareParamInfoDict();
	AssignValues(env);
	AssignFunctions(env);
	Gura_AssignMethodTo(VTYPE_image, image, opengl);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
bool DoGLSection(Environment &env, Signal &sig, Args &args, Image *pImage)
{
#if GURA_USE_MSWIN_DIB
	PIXELFORMATDESCRIPTOR pfd = { 
		sizeof(PIXELFORMATDESCRIPTOR), 1,
		PFD_DRAW_TO_BITMAP | PFD_SUPPORT_OPENGL, PFD_TYPE_RGBA,
		static_cast<BYTE>(pImage->GetBitsPerPixel()), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		32, 0, 0, PFD_MAIN_PLANE, 0, 0, 0, 0
	}; 
	HDC hdc = ::CreateCompatibleDC(nullptr);
	HBITMAP hBmp = pImage->GetHBITMAP();
	HBITMAP hBmpOld = reinterpret_cast<HBITMAP>(::SelectObject(hdc, hBmp));
	int iPixelFormat = ::ChoosePixelFormat(hdc, &pfd);
	::SetPixelFormat(hdc, iPixelFormat, &pfd);
	HGLRC hglrc = ::wglCreateContext(hdc);
	::wglMakeCurrent(hdc, hglrc);
	const Expr_Block *pExprBlock = args.GetBlockCooked(env);
	if (!sig.IsSignalled()) {
		SeqPostHandler *pSeqPostHandler = nullptr;
		pExprBlock->Exec2(env, pSeqPostHandler);
	}
	::wglMakeCurrent(nullptr, nullptr);
	::wglDeleteContext(hglrc);
	::SelectObject(hdc, hBmpOld);
	::DeleteDC(hdc);
	return true;
#elif defined(GURA_ON_DARWIN)
	//*****************
	// not working yet.
	//*****************
	GLsizei width = static_cast<GLsizei>(pImage->GetWidth());
	GLsizei height = static_cast<GLsizei>(pImage->GetHeight());
    CGLError errCode = kCGLNoError;
	GLuint texOut = 0;
	CGLContextObj ctx = nullptr;
	CGLContextObj ctxOrg = CGLGetCurrentContext();
	CGLPixelFormatAttribute attributes[4] = {
		kCGLPFAAccelerated,
		kCGLPFAOpenGLProfile,
		(CGLPixelFormatAttribute)kCGLOGLPVersion_3_2_Core,
		(CGLPixelFormatAttribute)0
	};
	CGLPixelFormatObj pixelFormat = nullptr;
	GLint numPixelFormats = 0;
	errCode = CGLChoosePixelFormat(attributes, &pixelFormat, &numPixelFormats);
	errCode = CGLCreateContext(pixelFormat, nullptr, &ctx);
	errCode = CGLSetCurrentContext(ctx);
	glGenTextures(1, &texOut);
	glBindTexture(GL_TEXTURE_2D, texOut);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_FLOAT, nullptr);
	GLuint frameBuffer = 0;
	glGenFramebuffers(1, &frameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texOut, 0);
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (status == GL_FRAMEBUFFER_COMPLETE) {
		const Expr_Block *pExprBlock = args.GetBlockCooked(env);
		if (!sig.IsSignalled()) {
			SeqPostHandler *pSeqPostHandler = nullptr;
			pExprBlock->Exec2(env, pSeqPostHandler);
		}
	}
	do {
		GLenum format = GetImageFormat(sig, pImage);
		if (sig.IsSignalled()) return false;
		glBindTexture(GL_TEXTURE_2D, texOut);
		glGetTexImage(GL_TEXTURE_2D, 0, format, GL_UNSIGNED_BYTE, pImage->GetBuffer());
	} while (0);
	glDeleteTextures(1, &texOut);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	CGLSetCurrentContext(ctxOrg);
	CGLDestroyContext(ctx);
	return true;
#else
#if 0
	int width = static_cast<int>(pImage->GetWidth());
	int height = static_cast<int>(pImage->GetHeight());
	GLXFBConfig config;
	Pixmap pixmap = ::XCreatePixmap(nullptr, d, width, height, 32);
	GLXPixmap xid = ::glXCreatePixmap(nullptr, config, pixmap, nullptr);
	GLXContext ctx;
	::glXMakeCurrent(nullptr, xid, ctx);
	const Expr_Block *pExprBlock = args.GetBlockCooked(env);
	if (!sig.IsSignalled()) {
		pExprBlock->Exec2(env);
	}
	::glReadPixels(0, 0, width, height, GL_BGRA_EXT,
									GL_UNSIGNED_BYTE, pImage->GetBuffer());
#endif
#endif
	return true;
}

Gura_EndModuleBody(opengl, opengl)

Gura_RegisterModule(opengl)
