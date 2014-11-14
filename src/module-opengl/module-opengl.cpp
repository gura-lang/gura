//-----------------------------------------------------------------------------
// Gura module: opengl
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(opengl)

void AssignValues(Environment &env);
void AssignFunctions(Environment &env);

typedef std::map<GLenum, size_t> ParamInfoDict;

static ParamInfoDict *_pParamInfoDict = NULL;

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
size_t GetParamCount(GLenum pname)
{
	ParamInfoDict::iterator iter = _pParamInfoDict->find(pname);
	if (iter == _pParamInfoDict->end()) return 16;
	return iter->second;
}

void PrepareParamInfoDict()
{
	_pParamInfoDict = new ParamInfoDict();
	static const struct {
		GLenum pname;
		size_t n;
	} tbl[] = {
		{ GL_ACCUM_ALPHA_BITS,						 1 },
		{ GL_ACCUM_BLUE_BITS,						 1 },
		{ GL_ACCUM_CLEAR_VALUE,						 4 },
		{ GL_ACCUM_GREEN_BITS,						 1 },
		{ GL_ACCUM_RED_BITS,						 1 },
		{ GL_ACTIVE_ATTRIBUTES,						 1 },
		{ GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,			 1 },
		{ GL_ACTIVE_TEXTURE,						 1 },
		{ GL_ACTIVE_UNIFORMS,						 1 },
		{ GL_ACTIVE_UNIFORM_MAX_LENGTH,				 1 },
		{ GL_ALIASED_LINE_WIDTH_RANGE,				 2 },
		{ GL_ALIASED_POINT_SIZE_RANGE,				 2 },
		{ GL_ALPHA_BIAS,							 1 },
		{ GL_ALPHA_BITS,							 1 },
		{ GL_ALPHA_SCALE,							 1 },
		{ GL_ALPHA_TEST,							 1 },
		{ GL_ALPHA_TEST_REF,						 1 },
		{ GL_AMBIENT,								 4 },
		{ GL_ARRAY_BUFFER_BINDING,					 1 },
		{ GL_ATTACHED_SHADERS,						 1 },
		{ GL_ATTRIB_STACK_DEPTH,					 1 },
		{ GL_AUTO_NORMAL,							 1 },
		{ GL_AUX_BUFFERS,							 1 },
		{ GL_BLEND,									 1 },
		{ GL_BLEND_COLOR,							 4 },
		{ GL_BLEND_DST_ALPHA,						 1 },
		{ GL_BLEND_DST_RGB,							 1 },
		{ GL_BLEND_EQUATION_ALPHA,					 1 },
		{ GL_BLEND_EQUATION_RGB,					 1 },
		{ GL_BLEND_SRC_ALPHA,						 1 },
		{ GL_BLEND_SRC_RGB,							 1 },
		{ GL_BLUE_BIAS,								 1 },
		{ GL_BLUE_BITS,								 1 },
		{ GL_BLUE_SCALE,							 1 },
		{ GL_CLIENT_ACTIVE_TEXTURE,					 1 },
		{ GL_CLIENT_ATTRIB_STACK_DEPTH,				 1 },
		//{ GL_CLIP_PLANEi,							 1 },
		{ GL_COLOR_ARRAY,							 1 },
		{ GL_COLOR_ARRAY_BUFFER_BINDING,			 1 },
		{ GL_COLOR_ARRAY_SIZE,						 1 },
		{ GL_COLOR_ARRAY_STRIDE,					 1 },
		{ GL_COLOR_ARRAY_TYPE,						 1 },
		{ GL_COLOR_CLEAR_VALUE,						 4 },
		{ GL_COLOR_INDEXES,							 3 },
		{ GL_COLOR_LOGIC_OP,						 1 },
		{ GL_COLOR_MATERIAL,						 1 },
		{ GL_COLOR_MATERIAL_FACE,					 1 },
		{ GL_COLOR_MATERIAL_PARAMETER,				 1 },
		{ GL_COLOR_MATRIX,							16 },
		{ GL_COLOR_MATRIX_STACK_DEPTH,				 1 },
		{ GL_COLOR_SUM,								 1 },
		{ GL_COLOR_TABLE,							 1 },
		{ GL_COLOR_TABLE_ALPHA_SIZE,				 1 },
		{ GL_COLOR_TABLE_BIAS,						 4 },
		{ GL_COLOR_TABLE_BLUE_SIZE,					 1 },
		{ GL_COLOR_TABLE_FORMAT,					 1 },
		{ GL_COLOR_TABLE_GREEN_SIZE,				 1 },
		{ GL_COLOR_TABLE_INTENSITY_SIZE,			 1 },
		{ GL_COLOR_TABLE_LUMINANCE_SIZE,			 1 },
		{ GL_COLOR_TABLE_RED_SIZE,					 1 },
		{ GL_COLOR_TABLE_SCALE,						 4 },
		{ GL_COLOR_TABLE_WIDTH,						 1 },
		{ GL_COLOR_WRITEMASK,						 4 },
		{ GL_COMBINE_ALPHA,							 1 },
		{ GL_COMBINE_RGB,							 1 },
		{ GL_COMPILE_STATUS,						 1 },
		{ GL_COMPRESSED_TEXTURE_FORMATS,			99 },
		{ GL_CONSTANT_ATTENUATION,					 1 },
		{ GL_CONVOLUTION_1D,						 1 },
		{ GL_CONVOLUTION_2D,						 1 },
		{ GL_CONVOLUTION_BORDER_COLOR,				 4 },
		{ GL_CONVOLUTION_BORDER_MODE,				 1 },
		{ GL_CONVOLUTION_FILTER_BIAS,				 4 },
		{ GL_CONVOLUTION_FILTER_SCALE,				 4 },
		{ GL_CONVOLUTION_FORMAT,					 1 },
		{ GL_CONVOLUTION_HEIGHT,					 1 },
		{ GL_CONVOLUTION_WIDTH,						 1 },
		{ GL_COORD_REPLACE,							 1 },
		{ GL_CULL_FACE,								 1 },
		{ GL_CULL_FACE_MODE,						 1 },
		{ GL_CURRENT_COLOR,							 4 },
		{ GL_CURRENT_FOG_COORD,						 1 },
		{ GL_CURRENT_INDEX,							 1 },
		{ GL_CURRENT_NORMAL,						 3 },
		{ GL_CURRENT_PROGRAM,						 1 },
		{ GL_CURRENT_QUERY,							 1 },
		{ GL_CURRENT_RASTER_COLOR,					 4 },
		{ GL_CURRENT_RASTER_DISTANCE,				 1 },
		{ GL_CURRENT_RASTER_INDEX,					 1 },
		{ GL_CURRENT_RASTER_POSITION,				 4 },
		{ GL_CURRENT_RASTER_POSITION_VALID,			 1 },
		{ GL_CURRENT_RASTER_SECONDARY_COLOR,		 4 },
		{ GL_CURRENT_RASTER_TEXTURE_COORDS,			 4 },
		{ GL_CURRENT_SECONDARY_COLOR,				 4 },
		{ GL_CURRENT_TEXTURE_COORDS,				 4 },
		{ GL_DELETE_STATUS,							 1 },
		{ GL_DEPTH_BIAS,							 1 },
		{ GL_DEPTH_BITS,							 1 },
		{ GL_DEPTH_CLEAR_VALUE,						 1 },
		{ GL_DEPTH_FUNC,							 1 },
		{ GL_DEPTH_RANGE,							 2 },
		{ GL_DEPTH_SCALE,							 1 },
		{ GL_DEPTH_TEST,							 1 },
		{ GL_DEPTH_TEXTURE_MODE,					 1 },
		{ GL_DEPTH_WRITEMASK,						 1 },
		{ GL_DIFFUSE,								 4 },
		{ GL_DITHER,								 1 },
		{ GL_DOUBLEBUFFER,							 1 },
		{ GL_DRAW_BUFFER,							 1 },
		//{ GL_DRAW_BUFFERi,						 1 },
		{ GL_EDGE_FLAG,								 1 },
		{ GL_EDGE_FLAG_ARRAY,						 1 },
		{ GL_EDGE_FLAG_ARRAY_BUFFER_BINDING,		 1 },
		{ GL_EDGE_FLAG_ARRAY_STRIDE,				 1 },
		{ GL_ELEMENT_ARRAY_BUFFER_BINDING,			 1 },
		{ GL_EMISSION,								 4 },
		{ GL_EYE_PLANE,								 1 },
		{ GL_FEEDBACK_BUFFER_SIZE,					 1 },
		{ GL_FEEDBACK_BUFFER_TYPE,					 1 },
		{ GL_FOG,									 1 },
		{ GL_FOG_COLOR,								 4 },
		{ GL_FOG_COORD_ARRAY,						 1 },
		{ GL_FOG_COORD_ARRAY_BUFFER_BINDING,		 1 },
		{ GL_FOG_COORD_ARRAY_STRIDE,				 1 },
		{ GL_FOG_COORD_ARRAY_TYPE,					 1 },
		{ GL_FOG_COORD_SRC,							 1 },
		{ GL_FOG_DENSITY,							 1 },
		{ GL_FOG_END,								 1 },
		{ GL_FOG_HINT,								 1 },
		{ GL_FOG_INDEX,								 1 },
		{ GL_FOG_MODE,								 1 },
		{ GL_FOG_START,								 1 },
		{ GL_FRAGMENT_SHADER_DERIVATIVE_HINT,		 1 },
		{ GL_FRONT_FACE,							 1 },
		{ GL_GENERATE_MIPMAP,						 1 },
		{ GL_GENERATE_MIPMAP_HINT,					 1 },
		{ GL_GREEN_BIAS,							 1 },
		{ GL_GREEN_BITS,							 1 },
		{ GL_GREEN_SCALE,							 1 },
		{ GL_HISTOGRAM,								 1 },
		{ GL_HISTOGRAM_ALPHA_SIZE,					 1 },
		{ GL_HISTOGRAM_BLUE_SIZE,					 1 },
		{ GL_HISTOGRAM_FORMAT,						 1 },
		{ GL_HISTOGRAM_GREEN_SIZE,					 1 },
		{ GL_HISTOGRAM_LUMINANCE_SIZE,				 1 },
		{ GL_HISTOGRAM_RED_SIZE,					 1 },
		{ GL_HISTOGRAM_SINK,						 1 },
		{ GL_HISTOGRAM_WIDTH,						 1 },
		{ GL_INDEX_ARRAY,							 1 },
		{ GL_INDEX_ARRAY_BUFFER_BINDING,			 1 },
		{ GL_INDEX_ARRAY_STRIDE,					 1 },
		{ GL_INDEX_ARRAY_TYPE,						 1 },
		{ GL_INDEX_BITS,							 1 },
		{ GL_INDEX_CLEAR_VALUE,						 1 },
		{ GL_INDEX_LOGIC_OP,						 1 },
		{ GL_INDEX_MODE,							 1 },
		{ GL_INDEX_OFFSET,							 1 },
		{ GL_INDEX_SHIFT,							 1 },
		{ GL_INDEX_WRITEMASK,						 1 },
		{ GL_INFO_LOG_LENGTH,						 1 },
		{ GL_LIGHTING,								 1 },
		{ GL_LIGHT_MODEL_AMBIENT,					 4 },
		{ GL_LIGHT_MODEL_COLOR_CONTROL,				 1 },
		{ GL_LIGHT_MODEL_LOCAL_VIEWER,				 1 },
		{ GL_LIGHT_MODEL_TWO_SIDE,					 1 },
		//{ GL_LIGHTi,								 1 },
		{ GL_LINEAR_ATTENUATION,					 1 },
		{ GL_LINE_SMOOTH,							 1 },
		{ GL_LINE_SMOOTH_HINT,						 1 },
		{ GL_LINE_STIPPLE,							 1 },
		{ GL_LINE_STIPPLE_PATTERN,					 1 },
		{ GL_LINE_STIPPLE_REPEAT,					 1 },
		{ GL_LINE_WIDTH,							 1 },
		{ GL_LINE_WIDTH_GRANULARITY,				 1 },
		{ GL_LINE_WIDTH_RANGE,						 2 },
		{ GL_LINK_STATUS,							 1 },
		{ GL_LIST_BASE,								 1 },
		{ GL_LIST_INDEX,							 1 },
		{ GL_LIST_MODE,								 1 },
		{ GL_LOGIC_OP_MODE,							 1 },
		{ GL_MAP1_COLOR_4,							 1 },
		{ GL_MAP1_GRID_DOMAIN,						 2 },
		{ GL_MAP1_GRID_SEGMENTS,					 1 },
		{ GL_MAP1_INDEX,							 1 },
		{ GL_MAP1_NORMAL,							 1 },
		{ GL_MAP1_TEXTURE_COORD_1,					 1 },
		{ GL_MAP1_TEXTURE_COORD_2,					 1 },
		{ GL_MAP1_TEXTURE_COORD_3,					 1 },
		{ GL_MAP1_TEXTURE_COORD_4,					 1 },
		{ GL_MAP1_VERTEX_3,							 1 },
		{ GL_MAP1_VERTEX_4,							 1 },
		{ GL_MAP2_COLOR_4,							 1 },
		{ GL_MAP2_GRID_DOMAIN,						 4 },
		{ GL_MAP2_GRID_SEGMENTS,					 2 },
		{ GL_MAP2_INDEX,							 1 },
		{ GL_MAP2_NORMAL,							 1 },
		{ GL_MAP2_TEXTURE_COORD_1,					 1 },
		{ GL_MAP2_TEXTURE_COORD_2,					 1 },
		{ GL_MAP2_TEXTURE_COORD_3,					 1 },
		{ GL_MAP2_TEXTURE_COORD_4,					 1 },
		{ GL_MAP2_VERTEX_3,							 1 },
		{ GL_MAP2_VERTEX_4,							 1 },
		{ GL_MAP_COLOR,								 1 },
		{ GL_MAP_STENCIL,							 1 },
		{ GL_MATRIX_MODE,							 1 },
		{ GL_MAX_3D_TEXTURE_SIZE,					 1 },
		{ GL_MAX_ATTRIB_STACK_DEPTH,				 1 },
		{ GL_MAX_CLIENT_ATTRIB_STACK_DEPTH,			 1 },
		{ GL_MAX_CLIP_PLANES,						 1 },
		{ GL_MAX_COLOR_MATRIX_STACK_DEPTH,			 1 },
		{ GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,		 1 },
		{ GL_MAX_CONVOLUTION_HEIGHT,				 1 },
		{ GL_MAX_CONVOLUTION_WIDTH,					 1 },
		{ GL_MAX_CUBE_MAP_TEXTURE_SIZE,				 1 },
		{ GL_MAX_DRAW_BUFFERS,						 1 },
		{ GL_MAX_ELEMENTS_INDICES,					 1 },
		{ GL_MAX_ELEMENTS_VERTICES,					 1 },
		{ GL_MAX_EVAL_ORDER,						 1 },
		{ GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,		 1 },
		{ GL_MAX_LIGHTS,							 1 },
		{ GL_MAX_LIST_NESTING,						 1 },
		{ GL_MAX_MODELVIEW_STACK_DEPTH,				 1 },
		{ GL_MAX_NAME_STACK_DEPTH,					 1 },
		{ GL_MAX_PIXEL_MAP_TABLE,					 1 },
		{ GL_MAX_PROJECTION_STACK_DEPTH,			 1 },
		{ GL_MAX_TEXTURE_COORDS,					 1 },
		{ GL_MAX_TEXTURE_IMAGE_UNITS,				 1 },
		{ GL_MAX_TEXTURE_LOD_BIAS,					 1 },
		{ GL_MAX_TEXTURE_SIZE,						 1 },
		{ GL_MAX_TEXTURE_STACK_DEPTH,				 1 },
		{ GL_MAX_TEXTURE_UNITS,						 1 },
		{ GL_MAX_VARYING_FLOATS,					 1 },
		{ GL_MAX_VERTEX_ATTRIBS,					 1 },
		{ GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,		 1 },
		{ GL_MAX_VERTEX_UNIFORM_COMPONENTS,			 1 },
		{ GL_MAX_VIEWPORT_DIMS,						 2 },
		{ GL_MINMAX,								 1 },
		{ GL_MINMAX_FORMAT,							 1 },
		{ GL_MINMAX_SINK,							 1 },
		{ GL_MODELVIEW_MATRIX,						16 },
		{ GL_MODELVIEW_STACK_DEPTH,					 1 },
		{ GL_NAME_STACK_DEPTH,						 1 },
		{ GL_NORMALIZE,								 1 },
		{ GL_NORMAL_ARRAY,							 1 },
		{ GL_NORMAL_ARRAY_BUFFER_BINDING,			 1 },
		{ GL_NORMAL_ARRAY_STRIDE,					 1 },
		{ GL_NORMAL_ARRAY_TYPE,						 1 },
		{ GL_NUM_COMPRESSED_TEXTURE_FORMATS,		 1 },
		{ GL_OBJECT_PLANE,							 1 },
		{ GL_OPERAND0_ALPHA,						 1 },
		{ GL_OPERAND0_RGB,							 1 },
		{ GL_OPERAND1_ALPHA,						 1 },
		{ GL_OPERAND1_RGB,							 1 },
		{ GL_OPERAND2_ALPHA,						 1 },
		{ GL_OPERAND2_RGB,							 1 },
		{ GL_PACK_ALIGNMENT,						 1 },
		{ GL_PACK_IMAGE_HEIGHT,						 1 },
		{ GL_PACK_LSB_FIRST,						 1 },
		{ GL_PACK_ROW_LENGTH,						 1 },
		{ GL_PACK_SKIP_IMAGES,						 1 },
		{ GL_PACK_SKIP_PIXELS,						 1 },
		{ GL_PACK_SKIP_ROWS,						 1 },
		{ GL_PACK_SWAP_BYTES,						 1 },
		{ GL_PERSPECTIVE_CORRECTION_HINT,			 1 },
		{ GL_PIXEL_MAP_A_TO_A_SIZE,					 1 },
		{ GL_PIXEL_MAP_B_TO_B_SIZE,					 1 },
		{ GL_PIXEL_MAP_G_TO_G_SIZE,					 1 },
		{ GL_PIXEL_MAP_I_TO_A_SIZE,					 1 },
		{ GL_PIXEL_MAP_I_TO_B_SIZE,					 1 },
		{ GL_PIXEL_MAP_I_TO_G_SIZE,					 1 },
		{ GL_PIXEL_MAP_I_TO_I_SIZE,					 1 },
		{ GL_PIXEL_MAP_I_TO_R_SIZE,					 1 },
		{ GL_PIXEL_MAP_R_TO_R_SIZE,					 1 },
		{ GL_PIXEL_MAP_S_TO_S_SIZE,					 1 },
		{ GL_PIXEL_PACK_BUFFER_BINDING,				 1 },
		{ GL_PIXEL_UNPACK_BUFFER_BINDING,			 1 },
		{ GL_POINT_DISTANCE_ATTENUATION,			 3 },
		{ GL_POINT_FADE_THRESHOLD_SIZE,				 1 },
		{ GL_POINT_SIZE,							 1 },
		{ GL_POINT_SIZE_GRANULARITY,				 1 },
		{ GL_POINT_SIZE_MAX,						 1 },
		{ GL_POINT_SIZE_MIN,						 1 },
		{ GL_POINT_SIZE_RANGE,						 2 },
		{ GL_POINT_SMOOTH,							 1 },
		{ GL_POINT_SMOOTH_HINT,						 1 },
		{ GL_POINT_SPRITE,							 1 },
		{ GL_POLYGON_MODE,							 2 },
		{ GL_POLYGON_OFFSET_FACTOR,					 1 },
		{ GL_POLYGON_OFFSET_FILL,					 1 },
		{ GL_POLYGON_OFFSET_LINE,					 1 },
		{ GL_POLYGON_OFFSET_POINT,					 1 },
		{ GL_POLYGON_OFFSET_UNITS,					 1 },
		{ GL_POLYGON_SMOOTH,						 1 },
		{ GL_POLYGON_SMOOTH_HINT,					 1 },
		{ GL_POLYGON_STIPPLE,						 1 },
		{ GL_POSITION,								 4 },
		{ GL_POST_COLOR_MATRIX_ALPHA_BIAS,			 1 },
		{ GL_POST_COLOR_MATRIX_ALPHA_SCALE,			 1 },
		{ GL_POST_COLOR_MATRIX_BLUE_BIAS,			 1 },
		{ GL_POST_COLOR_MATRIX_BLUE_SCALE,			 1 },
		{ GL_POST_COLOR_MATRIX_COLOR_TABLE,			 1 },
		{ GL_POST_COLOR_MATRIX_GREEN_BIAS,			 1 },
		{ GL_POST_COLOR_MATRIX_GREEN_SCALE,			 1 },
		{ GL_POST_COLOR_MATRIX_RED_BIAS,			 1 },
		{ GL_POST_COLOR_MATRIX_RED_SCALE,			 1 },
		{ GL_POST_CONVOLUTION_ALPHA_BIAS,			 1 },
		{ GL_POST_CONVOLUTION_ALPHA_SCALE,			 1 },
		{ GL_POST_CONVOLUTION_BLUE_BIAS,			 1 },
		{ GL_POST_CONVOLUTION_BLUE_SCALE,			 1 },
		{ GL_POST_CONVOLUTION_COLOR_TABLE,			 1 },
		{ GL_POST_CONVOLUTION_GREEN_BIAS,			 1 },
		{ GL_POST_CONVOLUTION_GREEN_SCALE,			 1 },
		{ GL_POST_CONVOLUTION_RED_BIAS,				 1 },
		{ GL_POST_CONVOLUTION_RED_SCALE,			 1 },
		{ GL_PROJECTION_MATRIX,						16 },
		{ GL_PROJECTION_STACK_DEPTH,				 1 },
		{ GL_QUADRATIC_ATTENUATION,					 1 },
		{ GL_QUERY_COUNTER_BITS,					 1 },
		{ GL_QUERY_RESULT,							 1 },
		{ GL_QUERY_RESULT_AVAILABLE,				 1 },
		{ GL_READ_BUFFER,							 1 },
		{ GL_RED_BIAS,								 1 },
		{ GL_RED_BITS,								 1 },
		{ GL_RED_SCALE,								 1 },
		{ GL_RENDER_MODE,							 1 },
		{ GL_RESCALE_NORMAL,						 1 },
		{ GL_RGBA_MODE,								 1 },
		{ GL_RGB_SCALE,								 1 },
		{ GL_SAMPLES,								 1 },
		{ GL_SAMPLE_BUFFERS,						 1 },
		{ GL_SAMPLE_COVERAGE_INVERT,				 1 },
		{ GL_SAMPLE_COVERAGE_VALUE,					 1 },
		{ GL_SCISSOR_BOX,							 4 },
		{ GL_SCISSOR_TEST,							 1 },
		{ GL_SECONDARY_COLOR_ARRAY,					 1 },
		{ GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING,	 1 },
		{ GL_SECONDARY_COLOR_ARRAY_SIZE,			 1 },
		{ GL_SECONDARY_COLOR_ARRAY_STRIDE,			 1 },
		{ GL_SECONDARY_COLOR_ARRAY_TYPE,			 1 },
		{ GL_SELECTION_BUFFER_SIZE,					 1 },
		{ GL_SEPARABLE_2D,							 1 },
		{ GL_SHADER_SOURCE_LENGTH,					 1 },
		{ GL_SHADER_TYPE,							 1 },
		{ GL_SHADE_MODEL,							 1 },
		{ GL_SHININESS,								 1 },
		{ GL_SMOOTH_LINE_WIDTH_GRANULARITY,			 1 },
		{ GL_SMOOTH_LINE_WIDTH_RANGE,				 2 },
		{ GL_SMOOTH_POINT_SIZE_GRANULARITY,			 1 },
		{ GL_SMOOTH_POINT_SIZE_RANGE,				 2 },
		{ GL_SPECULAR,								 4 },
		{ GL_SPOT_CUTOFF,							 1 },
		{ GL_SPOT_DIRECTION,						 3 },
		{ GL_SPOT_EXPONENT,							 1 },
		{ GL_SRC0_ALPHA,							 1 },
		{ GL_SRC0_RGB,								 1 },
		{ GL_SRC1_ALPHA,							 1 },
		{ GL_SRC1_RGB,								 1 },
		{ GL_SRC2_ALPHA,							 1 },
		{ GL_SRC2_RGB,								 1 },
		{ GL_STENCIL_BACK_FAIL,						 1 },
		{ GL_STENCIL_BACK_FUNC,						 1 },
		{ GL_STENCIL_BACK_PASS_DEPTH_FAIL,			 1 },
		{ GL_STENCIL_BACK_PASS_DEPTH_PASS,			 1 },
		{ GL_STENCIL_BACK_REF,						 1 },
		{ GL_STENCIL_BACK_VALUE_MASK,				 1 },
		{ GL_STENCIL_BACK_WRITEMASK,				 1 },
		{ GL_STENCIL_BITS,							 1 },
		{ GL_STENCIL_CLEAR_VALUE,					 1 },
		{ GL_STENCIL_FAIL,							 1 },
		{ GL_STENCIL_FUNC,							 1 },
		{ GL_STENCIL_PASS_DEPTH_FAIL,				 1 },
		{ GL_STENCIL_PASS_DEPTH_PASS,				 1 },
		{ GL_STENCIL_REF,							 1 },
		{ GL_STENCIL_TEST,							 1 },
		{ GL_STENCIL_VALUE_MASK,					 1 },
		{ GL_STENCIL_WRITEMASK,						 1 },
		{ GL_STEREO,								 1 },
		{ GL_SUBPIXEL_BITS,							 1 },
		{ GL_TEXTURE_1D,							 1 },
		{ GL_TEXTURE_2D,							 1 },
		{ GL_TEXTURE_3D,							 1 },
		{ GL_TEXTURE_BASE_LEVEL,					 1 },
		{ GL_TEXTURE_BINDING_1D,					 1 },
		{ GL_TEXTURE_BINDING_2D,					 1 },
		{ GL_TEXTURE_BINDING_3D,					 1 },
		{ GL_TEXTURE_BINDING_CUBE_MAP,				 1 },
		{ GL_TEXTURE_BORDER,						 1 },
		{ GL_TEXTURE_BORDER_COLOR,					 4 },
		{ GL_TEXTURE_COMPARE_FUNC,					 1 },
		{ GL_TEXTURE_COMPARE_MODE,					 1 },
		{ GL_TEXTURE_COMPRESSED,					 1 },
		{ GL_TEXTURE_COMPRESSED_IMAGE_SIZE,			 1 },
		{ GL_TEXTURE_COMPRESSION_HINT,				 1 },
		{ GL_TEXTURE_COORD_ARRAY,					 1 },
		{ GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING,	 1 },
		{ GL_TEXTURE_COORD_ARRAY_SIZE,				 1 },
		{ GL_TEXTURE_COORD_ARRAY_STRIDE,			 1 },
		{ GL_TEXTURE_COORD_ARRAY_TYPE,				 1 },
		{ GL_TEXTURE_CUBE_MAP,						 1 },
		{ GL_TEXTURE_DEPTH,							 1 },
		{ GL_TEXTURE_DEPTH_SIZE,					 1 },
		{ GL_TEXTURE_ENV_COLOR,						 4 },
		{ GL_TEXTURE_ENV_MODE,						 1 },
		{ GL_TEXTURE_GEN_MODE,						 1 },
		{ GL_TEXTURE_GEN_Q,							 1 },
		{ GL_TEXTURE_GEN_R,							 1 },
		{ GL_TEXTURE_GEN_S,							 1 },
		{ GL_TEXTURE_GEN_T,							 1 },
		{ GL_TEXTURE_HEIGHT,						 1 },
		{ GL_TEXTURE_INTERNAL_FORMAT,				 1 },
		{ GL_TEXTURE_LOD_BIAS,						 1 },
		{ GL_TEXTURE_MAG_FILTER,					 1 },
		{ GL_TEXTURE_MATRIX,						16 },
		{ GL_TEXTURE_MAX_LEVEL,						 1 },
		{ GL_TEXTURE_MAX_LOD,						 1 },
		{ GL_TEXTURE_MIN_FILTER,					 1 },
		{ GL_TEXTURE_MIN_LOD,						 1 },
		{ GL_TEXTURE_PRIORITY,						 1 },
		{ GL_TEXTURE_RESIDENT,						 1 },
		{ GL_TEXTURE_STACK_DEPTH,					 1 },
		{ GL_TEXTURE_WIDTH,							 1 },
		{ GL_TEXTURE_WRAP_R,						 1 },
		{ GL_TEXTURE_WRAP_S,						 1 },
		{ GL_TEXTURE_WRAP_T,						 1 },
		{ GL_TRANSPOSE_COLOR_MATRIX,				16 },
		{ GL_TRANSPOSE_MODELVIEW_MATRIX,			16 },
		{ GL_TRANSPOSE_PROJECTION_MATRIX,			16 },
		{ GL_TRANSPOSE_TEXTURE_MATRIX,				16 },
		{ GL_UNPACK_ALIGNMENT,						 1 },
		{ GL_UNPACK_IMAGE_HEIGHT,					 1 },
		{ GL_UNPACK_LSB_FIRST,						 1 },
		{ GL_UNPACK_ROW_LENGTH,						 1 },
		{ GL_UNPACK_SKIP_IMAGES,					 1 },
		{ GL_UNPACK_SKIP_PIXELS,					 1 },
		{ GL_UNPACK_SKIP_ROWS,						 1 },
		{ GL_UNPACK_SWAP_BYTES,						 1 },
		{ GL_VALIDATE_STATUS,						 1 },
		{ GL_VERTEX_ARRAY,							 1 },
		{ GL_VERTEX_ARRAY_BUFFER_BINDING,			 1 },
		{ GL_VERTEX_ARRAY_SIZE,						 1 },
		{ GL_VERTEX_ARRAY_STRIDE,					 1 },
		{ GL_VERTEX_ARRAY_TYPE,						 1 },
		{ GL_VERTEX_PROGRAM_POINT_SIZE,				 1 },
		{ GL_VERTEX_PROGRAM_TWO_SIDE,				 1 },
		{ GL_VIEWPORT,								 4 },
		{ GL_ZOOM_X,								 1 },
		{ GL_ZOOM_Y,								 1 },
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		(*_pParamInfoDict)[tbl[i].pname] = tbl[i].n;
	}
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
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->GetImage()->CheckValid(sig)) return Value::Null;
	if (!DoGLSection(env, sig, args, pThis->GetImage())) return Value::Null;
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
		SeqPostHandler *pSeqPostHandler = NULL;
		pExprBlock->Exec2(env, sig, pSeqPostHandler);
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
		pExprBlock->Exec2(env, sig);
	}
	::glReadPixels(0, 0, width, height, GL_BGRA_EXT,
									GL_UNSIGNED_BYTE, pImage->GetBuffer());
#endif
	return true;
}
#endif

Gura_EndModuleBody(opengl, opengl)

Gura_RegisterModule(opengl)
