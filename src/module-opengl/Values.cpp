#include "stdafx.h"

Gura_BeginModuleScope(opengl)

void AssignValues(Environment &env)
{
#if defined(GL_TYPEDEFS_2_0)
	Gura_AssignValue(GL_TYPEDEFS_2_0, Value(GL_TYPEDEFS_2_0));
#endif
#if defined(GL_LOGIC_OP)
	Gura_AssignValue(GL_LOGIC_OP, Value(GL_LOGIC_OP));
#endif
#if defined(GL_TEXTURE_COMPONENTS)
	Gura_AssignValue(GL_TEXTURE_COMPONENTS, Value(GL_TEXTURE_COMPONENTS));
#endif
#if defined(GL_VERSION_1_1)
	Gura_AssignValue(GL_VERSION_1_1, Value(GL_VERSION_1_1));
#endif
#if defined(GL_VERSION_1_2)
	Gura_AssignValue(GL_VERSION_1_2, Value(GL_VERSION_1_2));
#endif
#if defined(GL_VERSION_1_3)
	Gura_AssignValue(GL_VERSION_1_3, Value(GL_VERSION_1_3));
#endif
#if defined(GL_VERSION_1_4)
	Gura_AssignValue(GL_VERSION_1_4, Value(GL_VERSION_1_4));
#endif
#if defined(GL_VERSION_1_5)
	Gura_AssignValue(GL_VERSION_1_5, Value(GL_VERSION_1_5));
#endif
#if defined(GL_VERSION_2_0)
	Gura_AssignValue(GL_VERSION_2_0, Value(GL_VERSION_2_0));
#endif
#if defined(GL_VERSION_2_1)
	Gura_AssignValue(GL_VERSION_2_1, Value(GL_VERSION_2_1));
#endif
#if defined(GL_ACCUM)
	Gura_AssignValue(GL_ACCUM, Value(GL_ACCUM));
#endif
#if defined(GL_LOAD)
	Gura_AssignValue(GL_LOAD, Value(GL_LOAD));
#endif
#if defined(GL_RETURN)
	Gura_AssignValue(GL_RETURN, Value(GL_RETURN));
#endif
#if defined(GL_MULT)
	Gura_AssignValue(GL_MULT, Value(GL_MULT));
#endif
#if defined(GL_ADD)
	Gura_AssignValue(GL_ADD, Value(GL_ADD));
#endif
#if defined(GL_NEVER)
	Gura_AssignValue(GL_NEVER, Value(GL_NEVER));
#endif
#if defined(GL_LESS)
	Gura_AssignValue(GL_LESS, Value(GL_LESS));
#endif
#if defined(GL_EQUAL)
	Gura_AssignValue(GL_EQUAL, Value(GL_EQUAL));
#endif
#if defined(GL_LEQUAL)
	Gura_AssignValue(GL_LEQUAL, Value(GL_LEQUAL));
#endif
#if defined(GL_GREATER)
	Gura_AssignValue(GL_GREATER, Value(GL_GREATER));
#endif
#if defined(GL_NOTEQUAL)
	Gura_AssignValue(GL_NOTEQUAL, Value(GL_NOTEQUAL));
#endif
#if defined(GL_GEQUAL)
	Gura_AssignValue(GL_GEQUAL, Value(GL_GEQUAL));
#endif
#if defined(GL_ALWAYS)
	Gura_AssignValue(GL_ALWAYS, Value(GL_ALWAYS));
#endif
#if defined(GL_CURRENT_BIT)
	Gura_AssignValue(GL_CURRENT_BIT, Value(GL_CURRENT_BIT));
#endif
#if defined(GL_POINT_BIT)
	Gura_AssignValue(GL_POINT_BIT, Value(GL_POINT_BIT));
#endif
#if defined(GL_LINE_BIT)
	Gura_AssignValue(GL_LINE_BIT, Value(GL_LINE_BIT));
#endif
#if defined(GL_POLYGON_BIT)
	Gura_AssignValue(GL_POLYGON_BIT, Value(GL_POLYGON_BIT));
#endif
#if defined(GL_POLYGON_STIPPLE_BIT)
	Gura_AssignValue(GL_POLYGON_STIPPLE_BIT, Value(GL_POLYGON_STIPPLE_BIT));
#endif
#if defined(GL_PIXEL_MODE_BIT)
	Gura_AssignValue(GL_PIXEL_MODE_BIT, Value(GL_PIXEL_MODE_BIT));
#endif
#if defined(GL_LIGHTING_BIT)
	Gura_AssignValue(GL_LIGHTING_BIT, Value(GL_LIGHTING_BIT));
#endif
#if defined(GL_FOG_BIT)
	Gura_AssignValue(GL_FOG_BIT, Value(GL_FOG_BIT));
#endif
#if defined(GL_DEPTH_BUFFER_BIT)
	Gura_AssignValue(GL_DEPTH_BUFFER_BIT, Value(GL_DEPTH_BUFFER_BIT));
#endif
#if defined(GL_ACCUM_BUFFER_BIT)
	Gura_AssignValue(GL_ACCUM_BUFFER_BIT, Value(GL_ACCUM_BUFFER_BIT));
#endif
#if defined(GL_STENCIL_BUFFER_BIT)
	Gura_AssignValue(GL_STENCIL_BUFFER_BIT, Value(GL_STENCIL_BUFFER_BIT));
#endif
#if defined(GL_VIEWPORT_BIT)
	Gura_AssignValue(GL_VIEWPORT_BIT, Value(GL_VIEWPORT_BIT));
#endif
#if defined(GL_TRANSFORM_BIT)
	Gura_AssignValue(GL_TRANSFORM_BIT, Value(GL_TRANSFORM_BIT));
#endif
#if defined(GL_ENABLE_BIT)
	Gura_AssignValue(GL_ENABLE_BIT, Value(GL_ENABLE_BIT));
#endif
#if defined(GL_COLOR_BUFFER_BIT)
	Gura_AssignValue(GL_COLOR_BUFFER_BIT, Value(GL_COLOR_BUFFER_BIT));
#endif
#if defined(GL_HINT_BIT)
	Gura_AssignValue(GL_HINT_BIT, Value(GL_HINT_BIT));
#endif
#if defined(GL_EVAL_BIT)
	Gura_AssignValue(GL_EVAL_BIT, Value(GL_EVAL_BIT));
#endif
#if defined(GL_LIST_BIT)
	Gura_AssignValue(GL_LIST_BIT, Value(GL_LIST_BIT));
#endif
#if defined(GL_TEXTURE_BIT)
	Gura_AssignValue(GL_TEXTURE_BIT, Value(GL_TEXTURE_BIT));
#endif
#if defined(GL_SCISSOR_BIT)
	Gura_AssignValue(GL_SCISSOR_BIT, Value(GL_SCISSOR_BIT));
#endif
#if defined(GL_ALL_ATTRIB_BITS)
	Gura_AssignValue(GL_ALL_ATTRIB_BITS, Value(GL_ALL_ATTRIB_BITS));
#endif
#if defined(GL_POINTS)
	Gura_AssignValue(GL_POINTS, Value(GL_POINTS));
#endif
#if defined(GL_LINES)
	Gura_AssignValue(GL_LINES, Value(GL_LINES));
#endif
#if defined(GL_LINE_LOOP)
	Gura_AssignValue(GL_LINE_LOOP, Value(GL_LINE_LOOP));
#endif
#if defined(GL_LINE_STRIP)
	Gura_AssignValue(GL_LINE_STRIP, Value(GL_LINE_STRIP));
#endif
#if defined(GL_TRIANGLES)
	Gura_AssignValue(GL_TRIANGLES, Value(GL_TRIANGLES));
#endif
#if defined(GL_TRIANGLE_STRIP)
	Gura_AssignValue(GL_TRIANGLE_STRIP, Value(GL_TRIANGLE_STRIP));
#endif
#if defined(GL_TRIANGLE_FAN)
	Gura_AssignValue(GL_TRIANGLE_FAN, Value(GL_TRIANGLE_FAN));
#endif
#if defined(GL_QUADS)
	Gura_AssignValue(GL_QUADS, Value(GL_QUADS));
#endif
#if defined(GL_QUAD_STRIP)
	Gura_AssignValue(GL_QUAD_STRIP, Value(GL_QUAD_STRIP));
#endif
#if defined(GL_POLYGON)
	Gura_AssignValue(GL_POLYGON, Value(GL_POLYGON));
#endif
#if defined(GL_ZERO)
	Gura_AssignValue(GL_ZERO, Value(GL_ZERO));
#endif
#if defined(GL_ONE)
	Gura_AssignValue(GL_ONE, Value(GL_ONE));
#endif
#if defined(GL_SRC_COLOR)
	Gura_AssignValue(GL_SRC_COLOR, Value(GL_SRC_COLOR));
#endif
#if defined(GL_ONE_MINUS_SRC_COLOR)
	Gura_AssignValue(GL_ONE_MINUS_SRC_COLOR, Value(GL_ONE_MINUS_SRC_COLOR));
#endif
#if defined(GL_SRC_ALPHA)
	Gura_AssignValue(GL_SRC_ALPHA, Value(GL_SRC_ALPHA));
#endif
#if defined(GL_ONE_MINUS_SRC_ALPHA)
	Gura_AssignValue(GL_ONE_MINUS_SRC_ALPHA, Value(GL_ONE_MINUS_SRC_ALPHA));
#endif
#if defined(GL_DST_ALPHA)
	Gura_AssignValue(GL_DST_ALPHA, Value(GL_DST_ALPHA));
#endif
#if defined(GL_ONE_MINUS_DST_ALPHA)
	Gura_AssignValue(GL_ONE_MINUS_DST_ALPHA, Value(GL_ONE_MINUS_DST_ALPHA));
#endif
#if defined(GL_DST_COLOR)
	Gura_AssignValue(GL_DST_COLOR, Value(GL_DST_COLOR));
#endif
#if defined(GL_ONE_MINUS_DST_COLOR)
	Gura_AssignValue(GL_ONE_MINUS_DST_COLOR, Value(GL_ONE_MINUS_DST_COLOR));
#endif
#if defined(GL_SRC_ALPHA_SATURATE)
	Gura_AssignValue(GL_SRC_ALPHA_SATURATE, Value(GL_SRC_ALPHA_SATURATE));
#endif
#if defined(GL_TRUE)
	Gura_AssignValue(GL_TRUE, Value(GL_TRUE));
#endif
#if defined(GL_FALSE)
	Gura_AssignValue(GL_FALSE, Value(GL_FALSE));
#endif
#if defined(GL_CLIP_PLANE0)
	Gura_AssignValue(GL_CLIP_PLANE0, Value(GL_CLIP_PLANE0));
#endif
#if defined(GL_CLIP_PLANE1)
	Gura_AssignValue(GL_CLIP_PLANE1, Value(GL_CLIP_PLANE1));
#endif
#if defined(GL_CLIP_PLANE2)
	Gura_AssignValue(GL_CLIP_PLANE2, Value(GL_CLIP_PLANE2));
#endif
#if defined(GL_CLIP_PLANE3)
	Gura_AssignValue(GL_CLIP_PLANE3, Value(GL_CLIP_PLANE3));
#endif
#if defined(GL_CLIP_PLANE4)
	Gura_AssignValue(GL_CLIP_PLANE4, Value(GL_CLIP_PLANE4));
#endif
#if defined(GL_CLIP_PLANE5)
	Gura_AssignValue(GL_CLIP_PLANE5, Value(GL_CLIP_PLANE5));
#endif
#if defined(GL_BYTE)
	Gura_AssignValue(GL_BYTE, Value(GL_BYTE));
#endif
#if defined(GL_UNSIGNED_BYTE)
	Gura_AssignValue(GL_UNSIGNED_BYTE, Value(GL_UNSIGNED_BYTE));
#endif
#if defined(GL_SHORT)
	Gura_AssignValue(GL_SHORT, Value(GL_SHORT));
#endif
#if defined(GL_UNSIGNED_SHORT)
	Gura_AssignValue(GL_UNSIGNED_SHORT, Value(GL_UNSIGNED_SHORT));
#endif
#if defined(GL_INT)
	Gura_AssignValue(GL_INT, Value(GL_INT));
#endif
#if defined(GL_UNSIGNED_INT)
	Gura_AssignValue(GL_UNSIGNED_INT, Value(GL_UNSIGNED_INT));
#endif
#if defined(GL_FLOAT)
	Gura_AssignValue(GL_FLOAT, Value(GL_FLOAT));
#endif
#if defined(GL_2_BYTES)
	Gura_AssignValue(GL_2_BYTES, Value(GL_2_BYTES));
#endif
#if defined(GL_3_BYTES)
	Gura_AssignValue(GL_3_BYTES, Value(GL_3_BYTES));
#endif
#if defined(GL_4_BYTES)
	Gura_AssignValue(GL_4_BYTES, Value(GL_4_BYTES));
#endif
#if defined(GL_DOUBLE)
	Gura_AssignValue(GL_DOUBLE, Value(GL_DOUBLE));
#endif
#if defined(GL_NONE)
	Gura_AssignValue(GL_NONE, Value(GL_NONE));
#endif
#if defined(GL_FRONT_LEFT)
	Gura_AssignValue(GL_FRONT_LEFT, Value(GL_FRONT_LEFT));
#endif
#if defined(GL_FRONT_RIGHT)
	Gura_AssignValue(GL_FRONT_RIGHT, Value(GL_FRONT_RIGHT));
#endif
#if defined(GL_BACK_LEFT)
	Gura_AssignValue(GL_BACK_LEFT, Value(GL_BACK_LEFT));
#endif
#if defined(GL_BACK_RIGHT)
	Gura_AssignValue(GL_BACK_RIGHT, Value(GL_BACK_RIGHT));
#endif
#if defined(GL_FRONT)
	Gura_AssignValue(GL_FRONT, Value(GL_FRONT));
#endif
#if defined(GL_BACK)
	Gura_AssignValue(GL_BACK, Value(GL_BACK));
#endif
#if defined(GL_LEFT)
	Gura_AssignValue(GL_LEFT, Value(GL_LEFT));
#endif
#if defined(GL_RIGHT)
	Gura_AssignValue(GL_RIGHT, Value(GL_RIGHT));
#endif
#if defined(GL_FRONT_AND_BACK)
	Gura_AssignValue(GL_FRONT_AND_BACK, Value(GL_FRONT_AND_BACK));
#endif
#if defined(GL_AUX0)
	Gura_AssignValue(GL_AUX0, Value(GL_AUX0));
#endif
#if defined(GL_AUX1)
	Gura_AssignValue(GL_AUX1, Value(GL_AUX1));
#endif
#if defined(GL_AUX2)
	Gura_AssignValue(GL_AUX2, Value(GL_AUX2));
#endif
#if defined(GL_AUX3)
	Gura_AssignValue(GL_AUX3, Value(GL_AUX3));
#endif
#if defined(GL_NO_ERROR)
	Gura_AssignValue(GL_NO_ERROR, Value(GL_NO_ERROR));
#endif
#if defined(GL_INVALID_ENUM)
	Gura_AssignValue(GL_INVALID_ENUM, Value(GL_INVALID_ENUM));
#endif
#if defined(GL_INVALID_VALUE)
	Gura_AssignValue(GL_INVALID_VALUE, Value(GL_INVALID_VALUE));
#endif
#if defined(GL_INVALID_OPERATION)
	Gura_AssignValue(GL_INVALID_OPERATION, Value(GL_INVALID_OPERATION));
#endif
#if defined(GL_STACK_OVERFLOW)
	Gura_AssignValue(GL_STACK_OVERFLOW, Value(GL_STACK_OVERFLOW));
#endif
#if defined(GL_STACK_UNDERFLOW)
	Gura_AssignValue(GL_STACK_UNDERFLOW, Value(GL_STACK_UNDERFLOW));
#endif
#if defined(GL_OUT_OF_MEMORY)
	Gura_AssignValue(GL_OUT_OF_MEMORY, Value(GL_OUT_OF_MEMORY));
#endif
#if defined(GL_2D)
	Gura_AssignValue(GL_2D, Value(GL_2D));
#endif
#if defined(GL_3D)
	Gura_AssignValue(GL_3D, Value(GL_3D));
#endif
#if defined(GL_3D_COLOR)
	Gura_AssignValue(GL_3D_COLOR, Value(GL_3D_COLOR));
#endif
#if defined(GL_3D_COLOR_TEXTURE)
	Gura_AssignValue(GL_3D_COLOR_TEXTURE, Value(GL_3D_COLOR_TEXTURE));
#endif
#if defined(GL_4D_COLOR_TEXTURE)
	Gura_AssignValue(GL_4D_COLOR_TEXTURE, Value(GL_4D_COLOR_TEXTURE));
#endif
#if defined(GL_PASS_THROUGH_TOKEN)
	Gura_AssignValue(GL_PASS_THROUGH_TOKEN, Value(GL_PASS_THROUGH_TOKEN));
#endif
#if defined(GL_POINT_TOKEN)
	Gura_AssignValue(GL_POINT_TOKEN, Value(GL_POINT_TOKEN));
#endif
#if defined(GL_LINE_TOKEN)
	Gura_AssignValue(GL_LINE_TOKEN, Value(GL_LINE_TOKEN));
#endif
#if defined(GL_POLYGON_TOKEN)
	Gura_AssignValue(GL_POLYGON_TOKEN, Value(GL_POLYGON_TOKEN));
#endif
#if defined(GL_BITMAP_TOKEN)
	Gura_AssignValue(GL_BITMAP_TOKEN, Value(GL_BITMAP_TOKEN));
#endif
#if defined(GL_DRAW_PIXEL_TOKEN)
	Gura_AssignValue(GL_DRAW_PIXEL_TOKEN, Value(GL_DRAW_PIXEL_TOKEN));
#endif
#if defined(GL_COPY_PIXEL_TOKEN)
	Gura_AssignValue(GL_COPY_PIXEL_TOKEN, Value(GL_COPY_PIXEL_TOKEN));
#endif
#if defined(GL_LINE_RESET_TOKEN)
	Gura_AssignValue(GL_LINE_RESET_TOKEN, Value(GL_LINE_RESET_TOKEN));
#endif
#if defined(GL_EXP)
	Gura_AssignValue(GL_EXP, Value(GL_EXP));
#endif
#if defined(GL_EXP2)
	Gura_AssignValue(GL_EXP2, Value(GL_EXP2));
#endif
#if defined(GL_CW)
	Gura_AssignValue(GL_CW, Value(GL_CW));
#endif
#if defined(GL_CCW)
	Gura_AssignValue(GL_CCW, Value(GL_CCW));
#endif
#if defined(GL_COEFF)
	Gura_AssignValue(GL_COEFF, Value(GL_COEFF));
#endif
#if defined(GL_ORDER)
	Gura_AssignValue(GL_ORDER, Value(GL_ORDER));
#endif
#if defined(GL_DOMAIN)
	Gura_AssignValue(GL_DOMAIN, Value(GL_DOMAIN));
#endif
#if defined(GL_CURRENT_COLOR)
	Gura_AssignValue(GL_CURRENT_COLOR, Value(GL_CURRENT_COLOR));
#endif
#if defined(GL_CURRENT_INDEX)
	Gura_AssignValue(GL_CURRENT_INDEX, Value(GL_CURRENT_INDEX));
#endif
#if defined(GL_CURRENT_NORMAL)
	Gura_AssignValue(GL_CURRENT_NORMAL, Value(GL_CURRENT_NORMAL));
#endif
#if defined(GL_CURRENT_TEXTURE_COORDS)
	Gura_AssignValue(GL_CURRENT_TEXTURE_COORDS, Value(GL_CURRENT_TEXTURE_COORDS));
#endif
#if defined(GL_CURRENT_RASTER_COLOR)
	Gura_AssignValue(GL_CURRENT_RASTER_COLOR, Value(GL_CURRENT_RASTER_COLOR));
#endif
#if defined(GL_CURRENT_RASTER_INDEX)
	Gura_AssignValue(GL_CURRENT_RASTER_INDEX, Value(GL_CURRENT_RASTER_INDEX));
#endif
#if defined(GL_CURRENT_RASTER_TEXTURE_COORDS)
	Gura_AssignValue(GL_CURRENT_RASTER_TEXTURE_COORDS, Value(GL_CURRENT_RASTER_TEXTURE_COORDS));
#endif
#if defined(GL_CURRENT_RASTER_POSITION)
	Gura_AssignValue(GL_CURRENT_RASTER_POSITION, Value(GL_CURRENT_RASTER_POSITION));
#endif
#if defined(GL_CURRENT_RASTER_POSITION_VALID)
	Gura_AssignValue(GL_CURRENT_RASTER_POSITION_VALID, Value(GL_CURRENT_RASTER_POSITION_VALID));
#endif
#if defined(GL_CURRENT_RASTER_DISTANCE)
	Gura_AssignValue(GL_CURRENT_RASTER_DISTANCE, Value(GL_CURRENT_RASTER_DISTANCE));
#endif
#if defined(GL_POINT_SMOOTH)
	Gura_AssignValue(GL_POINT_SMOOTH, Value(GL_POINT_SMOOTH));
#endif
#if defined(GL_POINT_SIZE)
	Gura_AssignValue(GL_POINT_SIZE, Value(GL_POINT_SIZE));
#endif
#if defined(GL_POINT_SIZE_RANGE)
	Gura_AssignValue(GL_POINT_SIZE_RANGE, Value(GL_POINT_SIZE_RANGE));
#endif
#if defined(GL_POINT_SIZE_GRANULARITY)
	Gura_AssignValue(GL_POINT_SIZE_GRANULARITY, Value(GL_POINT_SIZE_GRANULARITY));
#endif
#if defined(GL_LINE_SMOOTH)
	Gura_AssignValue(GL_LINE_SMOOTH, Value(GL_LINE_SMOOTH));
#endif
#if defined(GL_LINE_WIDTH)
	Gura_AssignValue(GL_LINE_WIDTH, Value(GL_LINE_WIDTH));
#endif
#if defined(GL_LINE_WIDTH_RANGE)
	Gura_AssignValue(GL_LINE_WIDTH_RANGE, Value(GL_LINE_WIDTH_RANGE));
#endif
#if defined(GL_LINE_WIDTH_GRANULARITY)
	Gura_AssignValue(GL_LINE_WIDTH_GRANULARITY, Value(GL_LINE_WIDTH_GRANULARITY));
#endif
#if defined(GL_LINE_STIPPLE)
	Gura_AssignValue(GL_LINE_STIPPLE, Value(GL_LINE_STIPPLE));
#endif
#if defined(GL_LINE_STIPPLE_PATTERN)
	Gura_AssignValue(GL_LINE_STIPPLE_PATTERN, Value(GL_LINE_STIPPLE_PATTERN));
#endif
#if defined(GL_LINE_STIPPLE_REPEAT)
	Gura_AssignValue(GL_LINE_STIPPLE_REPEAT, Value(GL_LINE_STIPPLE_REPEAT));
#endif
#if defined(GL_LIST_MODE)
	Gura_AssignValue(GL_LIST_MODE, Value(GL_LIST_MODE));
#endif
#if defined(GL_MAX_LIST_NESTING)
	Gura_AssignValue(GL_MAX_LIST_NESTING, Value(GL_MAX_LIST_NESTING));
#endif
#if defined(GL_LIST_BASE)
	Gura_AssignValue(GL_LIST_BASE, Value(GL_LIST_BASE));
#endif
#if defined(GL_LIST_INDEX)
	Gura_AssignValue(GL_LIST_INDEX, Value(GL_LIST_INDEX));
#endif
#if defined(GL_POLYGON_MODE)
	Gura_AssignValue(GL_POLYGON_MODE, Value(GL_POLYGON_MODE));
#endif
#if defined(GL_POLYGON_SMOOTH)
	Gura_AssignValue(GL_POLYGON_SMOOTH, Value(GL_POLYGON_SMOOTH));
#endif
#if defined(GL_POLYGON_STIPPLE)
	Gura_AssignValue(GL_POLYGON_STIPPLE, Value(GL_POLYGON_STIPPLE));
#endif
#if defined(GL_EDGE_FLAG)
	Gura_AssignValue(GL_EDGE_FLAG, Value(GL_EDGE_FLAG));
#endif
#if defined(GL_CULL_FACE)
	Gura_AssignValue(GL_CULL_FACE, Value(GL_CULL_FACE));
#endif
#if defined(GL_CULL_FACE_MODE)
	Gura_AssignValue(GL_CULL_FACE_MODE, Value(GL_CULL_FACE_MODE));
#endif
#if defined(GL_FRONT_FACE)
	Gura_AssignValue(GL_FRONT_FACE, Value(GL_FRONT_FACE));
#endif
#if defined(GL_LIGHTING)
	Gura_AssignValue(GL_LIGHTING, Value(GL_LIGHTING));
#endif
#if defined(GL_LIGHT_MODEL_LOCAL_VIEWER)
	Gura_AssignValue(GL_LIGHT_MODEL_LOCAL_VIEWER, Value(GL_LIGHT_MODEL_LOCAL_VIEWER));
#endif
#if defined(GL_LIGHT_MODEL_TWO_SIDE)
	Gura_AssignValue(GL_LIGHT_MODEL_TWO_SIDE, Value(GL_LIGHT_MODEL_TWO_SIDE));
#endif
#if defined(GL_LIGHT_MODEL_AMBIENT)
	Gura_AssignValue(GL_LIGHT_MODEL_AMBIENT, Value(GL_LIGHT_MODEL_AMBIENT));
#endif
#if defined(GL_SHADE_MODEL)
	Gura_AssignValue(GL_SHADE_MODEL, Value(GL_SHADE_MODEL));
#endif
#if defined(GL_COLOR_MATERIAL_FACE)
	Gura_AssignValue(GL_COLOR_MATERIAL_FACE, Value(GL_COLOR_MATERIAL_FACE));
#endif
#if defined(GL_COLOR_MATERIAL_PARAMETER)
	Gura_AssignValue(GL_COLOR_MATERIAL_PARAMETER, Value(GL_COLOR_MATERIAL_PARAMETER));
#endif
#if defined(GL_COLOR_MATERIAL)
	Gura_AssignValue(GL_COLOR_MATERIAL, Value(GL_COLOR_MATERIAL));
#endif
#if defined(GL_FOG)
	Gura_AssignValue(GL_FOG, Value(GL_FOG));
#endif
#if defined(GL_FOG_INDEX)
	Gura_AssignValue(GL_FOG_INDEX, Value(GL_FOG_INDEX));
#endif
#if defined(GL_FOG_DENSITY)
	Gura_AssignValue(GL_FOG_DENSITY, Value(GL_FOG_DENSITY));
#endif
#if defined(GL_FOG_START)
	Gura_AssignValue(GL_FOG_START, Value(GL_FOG_START));
#endif
#if defined(GL_FOG_END)
	Gura_AssignValue(GL_FOG_END, Value(GL_FOG_END));
#endif
#if defined(GL_FOG_MODE)
	Gura_AssignValue(GL_FOG_MODE, Value(GL_FOG_MODE));
#endif
#if defined(GL_FOG_COLOR)
	Gura_AssignValue(GL_FOG_COLOR, Value(GL_FOG_COLOR));
#endif
#if defined(GL_DEPTH_RANGE)
	Gura_AssignValue(GL_DEPTH_RANGE, Value(GL_DEPTH_RANGE));
#endif
#if defined(GL_DEPTH_TEST)
	Gura_AssignValue(GL_DEPTH_TEST, Value(GL_DEPTH_TEST));
#endif
#if defined(GL_DEPTH_WRITEMASK)
	Gura_AssignValue(GL_DEPTH_WRITEMASK, Value(GL_DEPTH_WRITEMASK));
#endif
#if defined(GL_DEPTH_CLEAR_VALUE)
	Gura_AssignValue(GL_DEPTH_CLEAR_VALUE, Value(GL_DEPTH_CLEAR_VALUE));
#endif
#if defined(GL_DEPTH_FUNC)
	Gura_AssignValue(GL_DEPTH_FUNC, Value(GL_DEPTH_FUNC));
#endif
#if defined(GL_ACCUM_CLEAR_VALUE)
	Gura_AssignValue(GL_ACCUM_CLEAR_VALUE, Value(GL_ACCUM_CLEAR_VALUE));
#endif
#if defined(GL_STENCIL_TEST)
	Gura_AssignValue(GL_STENCIL_TEST, Value(GL_STENCIL_TEST));
#endif
#if defined(GL_STENCIL_CLEAR_VALUE)
	Gura_AssignValue(GL_STENCIL_CLEAR_VALUE, Value(GL_STENCIL_CLEAR_VALUE));
#endif
#if defined(GL_STENCIL_FUNC)
	Gura_AssignValue(GL_STENCIL_FUNC, Value(GL_STENCIL_FUNC));
#endif
#if defined(GL_STENCIL_VALUE_MASK)
	Gura_AssignValue(GL_STENCIL_VALUE_MASK, Value(GL_STENCIL_VALUE_MASK));
#endif
#if defined(GL_STENCIL_FAIL)
	Gura_AssignValue(GL_STENCIL_FAIL, Value(GL_STENCIL_FAIL));
#endif
#if defined(GL_STENCIL_PASS_DEPTH_FAIL)
	Gura_AssignValue(GL_STENCIL_PASS_DEPTH_FAIL, Value(GL_STENCIL_PASS_DEPTH_FAIL));
#endif
#if defined(GL_STENCIL_PASS_DEPTH_PASS)
	Gura_AssignValue(GL_STENCIL_PASS_DEPTH_PASS, Value(GL_STENCIL_PASS_DEPTH_PASS));
#endif
#if defined(GL_STENCIL_REF)
	Gura_AssignValue(GL_STENCIL_REF, Value(GL_STENCIL_REF));
#endif
#if defined(GL_STENCIL_WRITEMASK)
	Gura_AssignValue(GL_STENCIL_WRITEMASK, Value(GL_STENCIL_WRITEMASK));
#endif
#if defined(GL_MATRIX_MODE)
	Gura_AssignValue(GL_MATRIX_MODE, Value(GL_MATRIX_MODE));
#endif
#if defined(GL_NORMALIZE)
	Gura_AssignValue(GL_NORMALIZE, Value(GL_NORMALIZE));
#endif
#if defined(GL_VIEWPORT)
	Gura_AssignValue(GL_VIEWPORT, Value(GL_VIEWPORT));
#endif
#if defined(GL_MODELVIEW_STACK_DEPTH)
	Gura_AssignValue(GL_MODELVIEW_STACK_DEPTH, Value(GL_MODELVIEW_STACK_DEPTH));
#endif
#if defined(GL_PROJECTION_STACK_DEPTH)
	Gura_AssignValue(GL_PROJECTION_STACK_DEPTH, Value(GL_PROJECTION_STACK_DEPTH));
#endif
#if defined(GL_TEXTURE_STACK_DEPTH)
	Gura_AssignValue(GL_TEXTURE_STACK_DEPTH, Value(GL_TEXTURE_STACK_DEPTH));
#endif
#if defined(GL_MODELVIEW_MATRIX)
	Gura_AssignValue(GL_MODELVIEW_MATRIX, Value(GL_MODELVIEW_MATRIX));
#endif
#if defined(GL_PROJECTION_MATRIX)
	Gura_AssignValue(GL_PROJECTION_MATRIX, Value(GL_PROJECTION_MATRIX));
#endif
#if defined(GL_TEXTURE_MATRIX)
	Gura_AssignValue(GL_TEXTURE_MATRIX, Value(GL_TEXTURE_MATRIX));
#endif
#if defined(GL_ATTRIB_STACK_DEPTH)
	Gura_AssignValue(GL_ATTRIB_STACK_DEPTH, Value(GL_ATTRIB_STACK_DEPTH));
#endif
#if defined(GL_CLIENT_ATTRIB_STACK_DEPTH)
	Gura_AssignValue(GL_CLIENT_ATTRIB_STACK_DEPTH, Value(GL_CLIENT_ATTRIB_STACK_DEPTH));
#endif
#if defined(GL_ALPHA_TEST)
	Gura_AssignValue(GL_ALPHA_TEST, Value(GL_ALPHA_TEST));
#endif
#if defined(GL_ALPHA_TEST_FUNC)
	Gura_AssignValue(GL_ALPHA_TEST_FUNC, Value(GL_ALPHA_TEST_FUNC));
#endif
#if defined(GL_ALPHA_TEST_REF)
	Gura_AssignValue(GL_ALPHA_TEST_REF, Value(GL_ALPHA_TEST_REF));
#endif
#if defined(GL_DITHER)
	Gura_AssignValue(GL_DITHER, Value(GL_DITHER));
#endif
#if defined(GL_BLEND_DST)
	Gura_AssignValue(GL_BLEND_DST, Value(GL_BLEND_DST));
#endif
#if defined(GL_BLEND_SRC)
	Gura_AssignValue(GL_BLEND_SRC, Value(GL_BLEND_SRC));
#endif
#if defined(GL_BLEND)
	Gura_AssignValue(GL_BLEND, Value(GL_BLEND));
#endif
#if defined(GL_LOGIC_OP_MODE)
	Gura_AssignValue(GL_LOGIC_OP_MODE, Value(GL_LOGIC_OP_MODE));
#endif
#if defined(GL_INDEX_LOGIC_OP)
	Gura_AssignValue(GL_INDEX_LOGIC_OP, Value(GL_INDEX_LOGIC_OP));
#endif
#if defined(GL_COLOR_LOGIC_OP)
	Gura_AssignValue(GL_COLOR_LOGIC_OP, Value(GL_COLOR_LOGIC_OP));
#endif
#if defined(GL_AUX_BUFFERS)
	Gura_AssignValue(GL_AUX_BUFFERS, Value(GL_AUX_BUFFERS));
#endif
#if defined(GL_DRAW_BUFFER)
	Gura_AssignValue(GL_DRAW_BUFFER, Value(GL_DRAW_BUFFER));
#endif
#if defined(GL_READ_BUFFER)
	Gura_AssignValue(GL_READ_BUFFER, Value(GL_READ_BUFFER));
#endif
#if defined(GL_SCISSOR_BOX)
	Gura_AssignValue(GL_SCISSOR_BOX, Value(GL_SCISSOR_BOX));
#endif
#if defined(GL_SCISSOR_TEST)
	Gura_AssignValue(GL_SCISSOR_TEST, Value(GL_SCISSOR_TEST));
#endif
#if defined(GL_INDEX_CLEAR_VALUE)
	Gura_AssignValue(GL_INDEX_CLEAR_VALUE, Value(GL_INDEX_CLEAR_VALUE));
#endif
#if defined(GL_INDEX_WRITEMASK)
	Gura_AssignValue(GL_INDEX_WRITEMASK, Value(GL_INDEX_WRITEMASK));
#endif
#if defined(GL_COLOR_CLEAR_VALUE)
	Gura_AssignValue(GL_COLOR_CLEAR_VALUE, Value(GL_COLOR_CLEAR_VALUE));
#endif
#if defined(GL_COLOR_WRITEMASK)
	Gura_AssignValue(GL_COLOR_WRITEMASK, Value(GL_COLOR_WRITEMASK));
#endif
#if defined(GL_INDEX_MODE)
	Gura_AssignValue(GL_INDEX_MODE, Value(GL_INDEX_MODE));
#endif
#if defined(GL_RGBA_MODE)
	Gura_AssignValue(GL_RGBA_MODE, Value(GL_RGBA_MODE));
#endif
#if defined(GL_DOUBLEBUFFER)
	Gura_AssignValue(GL_DOUBLEBUFFER, Value(GL_DOUBLEBUFFER));
#endif
#if defined(GL_STEREO)
	Gura_AssignValue(GL_STEREO, Value(GL_STEREO));
#endif
#if defined(GL_RENDER_MODE)
	Gura_AssignValue(GL_RENDER_MODE, Value(GL_RENDER_MODE));
#endif
#if defined(GL_PERSPECTIVE_CORRECTION_HINT)
	Gura_AssignValue(GL_PERSPECTIVE_CORRECTION_HINT, Value(GL_PERSPECTIVE_CORRECTION_HINT));
#endif
#if defined(GL_POINT_SMOOTH_HINT)
	Gura_AssignValue(GL_POINT_SMOOTH_HINT, Value(GL_POINT_SMOOTH_HINT));
#endif
#if defined(GL_LINE_SMOOTH_HINT)
	Gura_AssignValue(GL_LINE_SMOOTH_HINT, Value(GL_LINE_SMOOTH_HINT));
#endif
#if defined(GL_POLYGON_SMOOTH_HINT)
	Gura_AssignValue(GL_POLYGON_SMOOTH_HINT, Value(GL_POLYGON_SMOOTH_HINT));
#endif
#if defined(GL_FOG_HINT)
	Gura_AssignValue(GL_FOG_HINT, Value(GL_FOG_HINT));
#endif
#if defined(GL_TEXTURE_GEN_S)
	Gura_AssignValue(GL_TEXTURE_GEN_S, Value(GL_TEXTURE_GEN_S));
#endif
#if defined(GL_TEXTURE_GEN_T)
	Gura_AssignValue(GL_TEXTURE_GEN_T, Value(GL_TEXTURE_GEN_T));
#endif
#if defined(GL_TEXTURE_GEN_R)
	Gura_AssignValue(GL_TEXTURE_GEN_R, Value(GL_TEXTURE_GEN_R));
#endif
#if defined(GL_TEXTURE_GEN_Q)
	Gura_AssignValue(GL_TEXTURE_GEN_Q, Value(GL_TEXTURE_GEN_Q));
#endif
#if defined(GL_PIXEL_MAP_I_TO_I)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_I, Value(GL_PIXEL_MAP_I_TO_I));
#endif
#if defined(GL_PIXEL_MAP_S_TO_S)
	Gura_AssignValue(GL_PIXEL_MAP_S_TO_S, Value(GL_PIXEL_MAP_S_TO_S));
#endif
#if defined(GL_PIXEL_MAP_I_TO_R)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_R, Value(GL_PIXEL_MAP_I_TO_R));
#endif
#if defined(GL_PIXEL_MAP_I_TO_G)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_G, Value(GL_PIXEL_MAP_I_TO_G));
#endif
#if defined(GL_PIXEL_MAP_I_TO_B)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_B, Value(GL_PIXEL_MAP_I_TO_B));
#endif
#if defined(GL_PIXEL_MAP_I_TO_A)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_A, Value(GL_PIXEL_MAP_I_TO_A));
#endif
#if defined(GL_PIXEL_MAP_R_TO_R)
	Gura_AssignValue(GL_PIXEL_MAP_R_TO_R, Value(GL_PIXEL_MAP_R_TO_R));
#endif
#if defined(GL_PIXEL_MAP_G_TO_G)
	Gura_AssignValue(GL_PIXEL_MAP_G_TO_G, Value(GL_PIXEL_MAP_G_TO_G));
#endif
#if defined(GL_PIXEL_MAP_B_TO_B)
	Gura_AssignValue(GL_PIXEL_MAP_B_TO_B, Value(GL_PIXEL_MAP_B_TO_B));
#endif
#if defined(GL_PIXEL_MAP_A_TO_A)
	Gura_AssignValue(GL_PIXEL_MAP_A_TO_A, Value(GL_PIXEL_MAP_A_TO_A));
#endif
#if defined(GL_PIXEL_MAP_I_TO_I_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_I_SIZE, Value(GL_PIXEL_MAP_I_TO_I_SIZE));
#endif
#if defined(GL_PIXEL_MAP_S_TO_S_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_S_TO_S_SIZE, Value(GL_PIXEL_MAP_S_TO_S_SIZE));
#endif
#if defined(GL_PIXEL_MAP_I_TO_R_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_R_SIZE, Value(GL_PIXEL_MAP_I_TO_R_SIZE));
#endif
#if defined(GL_PIXEL_MAP_I_TO_G_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_G_SIZE, Value(GL_PIXEL_MAP_I_TO_G_SIZE));
#endif
#if defined(GL_PIXEL_MAP_I_TO_B_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_B_SIZE, Value(GL_PIXEL_MAP_I_TO_B_SIZE));
#endif
#if defined(GL_PIXEL_MAP_I_TO_A_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_I_TO_A_SIZE, Value(GL_PIXEL_MAP_I_TO_A_SIZE));
#endif
#if defined(GL_PIXEL_MAP_R_TO_R_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_R_TO_R_SIZE, Value(GL_PIXEL_MAP_R_TO_R_SIZE));
#endif
#if defined(GL_PIXEL_MAP_G_TO_G_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_G_TO_G_SIZE, Value(GL_PIXEL_MAP_G_TO_G_SIZE));
#endif
#if defined(GL_PIXEL_MAP_B_TO_B_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_B_TO_B_SIZE, Value(GL_PIXEL_MAP_B_TO_B_SIZE));
#endif
#if defined(GL_PIXEL_MAP_A_TO_A_SIZE)
	Gura_AssignValue(GL_PIXEL_MAP_A_TO_A_SIZE, Value(GL_PIXEL_MAP_A_TO_A_SIZE));
#endif
#if defined(GL_UNPACK_SWAP_BYTES)
	Gura_AssignValue(GL_UNPACK_SWAP_BYTES, Value(GL_UNPACK_SWAP_BYTES));
#endif
#if defined(GL_UNPACK_LSB_FIRST)
	Gura_AssignValue(GL_UNPACK_LSB_FIRST, Value(GL_UNPACK_LSB_FIRST));
#endif
#if defined(GL_UNPACK_ROW_LENGTH)
	Gura_AssignValue(GL_UNPACK_ROW_LENGTH, Value(GL_UNPACK_ROW_LENGTH));
#endif
#if defined(GL_UNPACK_SKIP_ROWS)
	Gura_AssignValue(GL_UNPACK_SKIP_ROWS, Value(GL_UNPACK_SKIP_ROWS));
#endif
#if defined(GL_UNPACK_SKIP_PIXELS)
	Gura_AssignValue(GL_UNPACK_SKIP_PIXELS, Value(GL_UNPACK_SKIP_PIXELS));
#endif
#if defined(GL_UNPACK_ALIGNMENT)
	Gura_AssignValue(GL_UNPACK_ALIGNMENT, Value(GL_UNPACK_ALIGNMENT));
#endif
#if defined(GL_PACK_SWAP_BYTES)
	Gura_AssignValue(GL_PACK_SWAP_BYTES, Value(GL_PACK_SWAP_BYTES));
#endif
#if defined(GL_PACK_LSB_FIRST)
	Gura_AssignValue(GL_PACK_LSB_FIRST, Value(GL_PACK_LSB_FIRST));
#endif
#if defined(GL_PACK_ROW_LENGTH)
	Gura_AssignValue(GL_PACK_ROW_LENGTH, Value(GL_PACK_ROW_LENGTH));
#endif
#if defined(GL_PACK_SKIP_ROWS)
	Gura_AssignValue(GL_PACK_SKIP_ROWS, Value(GL_PACK_SKIP_ROWS));
#endif
#if defined(GL_PACK_SKIP_PIXELS)
	Gura_AssignValue(GL_PACK_SKIP_PIXELS, Value(GL_PACK_SKIP_PIXELS));
#endif
#if defined(GL_PACK_ALIGNMENT)
	Gura_AssignValue(GL_PACK_ALIGNMENT, Value(GL_PACK_ALIGNMENT));
#endif
#if defined(GL_MAP_COLOR)
	Gura_AssignValue(GL_MAP_COLOR, Value(GL_MAP_COLOR));
#endif
#if defined(GL_MAP_STENCIL)
	Gura_AssignValue(GL_MAP_STENCIL, Value(GL_MAP_STENCIL));
#endif
#if defined(GL_INDEX_SHIFT)
	Gura_AssignValue(GL_INDEX_SHIFT, Value(GL_INDEX_SHIFT));
#endif
#if defined(GL_INDEX_OFFSET)
	Gura_AssignValue(GL_INDEX_OFFSET, Value(GL_INDEX_OFFSET));
#endif
#if defined(GL_RED_SCALE)
	Gura_AssignValue(GL_RED_SCALE, Value(GL_RED_SCALE));
#endif
#if defined(GL_RED_BIAS)
	Gura_AssignValue(GL_RED_BIAS, Value(GL_RED_BIAS));
#endif
#if defined(GL_ZOOM_X)
	Gura_AssignValue(GL_ZOOM_X, Value(GL_ZOOM_X));
#endif
#if defined(GL_ZOOM_Y)
	Gura_AssignValue(GL_ZOOM_Y, Value(GL_ZOOM_Y));
#endif
#if defined(GL_GREEN_SCALE)
	Gura_AssignValue(GL_GREEN_SCALE, Value(GL_GREEN_SCALE));
#endif
#if defined(GL_GREEN_BIAS)
	Gura_AssignValue(GL_GREEN_BIAS, Value(GL_GREEN_BIAS));
#endif
#if defined(GL_BLUE_SCALE)
	Gura_AssignValue(GL_BLUE_SCALE, Value(GL_BLUE_SCALE));
#endif
#if defined(GL_BLUE_BIAS)
	Gura_AssignValue(GL_BLUE_BIAS, Value(GL_BLUE_BIAS));
#endif
#if defined(GL_ALPHA_SCALE)
	Gura_AssignValue(GL_ALPHA_SCALE, Value(GL_ALPHA_SCALE));
#endif
#if defined(GL_ALPHA_BIAS)
	Gura_AssignValue(GL_ALPHA_BIAS, Value(GL_ALPHA_BIAS));
#endif
#if defined(GL_DEPTH_SCALE)
	Gura_AssignValue(GL_DEPTH_SCALE, Value(GL_DEPTH_SCALE));
#endif
#if defined(GL_DEPTH_BIAS)
	Gura_AssignValue(GL_DEPTH_BIAS, Value(GL_DEPTH_BIAS));
#endif
#if defined(GL_MAX_EVAL_ORDER)
	Gura_AssignValue(GL_MAX_EVAL_ORDER, Value(GL_MAX_EVAL_ORDER));
#endif
#if defined(GL_MAX_LIGHTS)
	Gura_AssignValue(GL_MAX_LIGHTS, Value(GL_MAX_LIGHTS));
#endif
#if defined(GL_MAX_CLIP_PLANES)
	Gura_AssignValue(GL_MAX_CLIP_PLANES, Value(GL_MAX_CLIP_PLANES));
#endif
#if defined(GL_MAX_TEXTURE_SIZE)
	Gura_AssignValue(GL_MAX_TEXTURE_SIZE, Value(GL_MAX_TEXTURE_SIZE));
#endif
#if defined(GL_MAX_PIXEL_MAP_TABLE)
	Gura_AssignValue(GL_MAX_PIXEL_MAP_TABLE, Value(GL_MAX_PIXEL_MAP_TABLE));
#endif
#if defined(GL_MAX_ATTRIB_STACK_DEPTH)
	Gura_AssignValue(GL_MAX_ATTRIB_STACK_DEPTH, Value(GL_MAX_ATTRIB_STACK_DEPTH));
#endif
#if defined(GL_MAX_MODELVIEW_STACK_DEPTH)
	Gura_AssignValue(GL_MAX_MODELVIEW_STACK_DEPTH, Value(GL_MAX_MODELVIEW_STACK_DEPTH));
#endif
#if defined(GL_MAX_NAME_STACK_DEPTH)
	Gura_AssignValue(GL_MAX_NAME_STACK_DEPTH, Value(GL_MAX_NAME_STACK_DEPTH));
#endif
#if defined(GL_MAX_PROJECTION_STACK_DEPTH)
	Gura_AssignValue(GL_MAX_PROJECTION_STACK_DEPTH, Value(GL_MAX_PROJECTION_STACK_DEPTH));
#endif
#if defined(GL_MAX_TEXTURE_STACK_DEPTH)
	Gura_AssignValue(GL_MAX_TEXTURE_STACK_DEPTH, Value(GL_MAX_TEXTURE_STACK_DEPTH));
#endif
#if defined(GL_MAX_VIEWPORT_DIMS)
	Gura_AssignValue(GL_MAX_VIEWPORT_DIMS, Value(GL_MAX_VIEWPORT_DIMS));
#endif
#if defined(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH)
	Gura_AssignValue(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH, Value(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH));
#endif
#if defined(GL_SUBPIXEL_BITS)
	Gura_AssignValue(GL_SUBPIXEL_BITS, Value(GL_SUBPIXEL_BITS));
#endif
#if defined(GL_INDEX_BITS)
	Gura_AssignValue(GL_INDEX_BITS, Value(GL_INDEX_BITS));
#endif
#if defined(GL_RED_BITS)
	Gura_AssignValue(GL_RED_BITS, Value(GL_RED_BITS));
#endif
#if defined(GL_GREEN_BITS)
	Gura_AssignValue(GL_GREEN_BITS, Value(GL_GREEN_BITS));
#endif
#if defined(GL_BLUE_BITS)
	Gura_AssignValue(GL_BLUE_BITS, Value(GL_BLUE_BITS));
#endif
#if defined(GL_ALPHA_BITS)
	Gura_AssignValue(GL_ALPHA_BITS, Value(GL_ALPHA_BITS));
#endif
#if defined(GL_DEPTH_BITS)
	Gura_AssignValue(GL_DEPTH_BITS, Value(GL_DEPTH_BITS));
#endif
#if defined(GL_STENCIL_BITS)
	Gura_AssignValue(GL_STENCIL_BITS, Value(GL_STENCIL_BITS));
#endif
#if defined(GL_ACCUM_RED_BITS)
	Gura_AssignValue(GL_ACCUM_RED_BITS, Value(GL_ACCUM_RED_BITS));
#endif
#if defined(GL_ACCUM_GREEN_BITS)
	Gura_AssignValue(GL_ACCUM_GREEN_BITS, Value(GL_ACCUM_GREEN_BITS));
#endif
#if defined(GL_ACCUM_BLUE_BITS)
	Gura_AssignValue(GL_ACCUM_BLUE_BITS, Value(GL_ACCUM_BLUE_BITS));
#endif
#if defined(GL_ACCUM_ALPHA_BITS)
	Gura_AssignValue(GL_ACCUM_ALPHA_BITS, Value(GL_ACCUM_ALPHA_BITS));
#endif
#if defined(GL_NAME_STACK_DEPTH)
	Gura_AssignValue(GL_NAME_STACK_DEPTH, Value(GL_NAME_STACK_DEPTH));
#endif
#if defined(GL_AUTO_NORMAL)
	Gura_AssignValue(GL_AUTO_NORMAL, Value(GL_AUTO_NORMAL));
#endif
#if defined(GL_MAP1_COLOR_4)
	Gura_AssignValue(GL_MAP1_COLOR_4, Value(GL_MAP1_COLOR_4));
#endif
#if defined(GL_MAP1_INDEX)
	Gura_AssignValue(GL_MAP1_INDEX, Value(GL_MAP1_INDEX));
#endif
#if defined(GL_MAP1_NORMAL)
	Gura_AssignValue(GL_MAP1_NORMAL, Value(GL_MAP1_NORMAL));
#endif
#if defined(GL_MAP1_TEXTURE_COORD_1)
	Gura_AssignValue(GL_MAP1_TEXTURE_COORD_1, Value(GL_MAP1_TEXTURE_COORD_1));
#endif
#if defined(GL_MAP1_TEXTURE_COORD_2)
	Gura_AssignValue(GL_MAP1_TEXTURE_COORD_2, Value(GL_MAP1_TEXTURE_COORD_2));
#endif
#if defined(GL_MAP1_TEXTURE_COORD_3)
	Gura_AssignValue(GL_MAP1_TEXTURE_COORD_3, Value(GL_MAP1_TEXTURE_COORD_3));
#endif
#if defined(GL_MAP1_TEXTURE_COORD_4)
	Gura_AssignValue(GL_MAP1_TEXTURE_COORD_4, Value(GL_MAP1_TEXTURE_COORD_4));
#endif
#if defined(GL_MAP1_VERTEX_3)
	Gura_AssignValue(GL_MAP1_VERTEX_3, Value(GL_MAP1_VERTEX_3));
#endif
#if defined(GL_MAP1_VERTEX_4)
	Gura_AssignValue(GL_MAP1_VERTEX_4, Value(GL_MAP1_VERTEX_4));
#endif
#if defined(GL_MAP2_COLOR_4)
	Gura_AssignValue(GL_MAP2_COLOR_4, Value(GL_MAP2_COLOR_4));
#endif
#if defined(GL_MAP2_INDEX)
	Gura_AssignValue(GL_MAP2_INDEX, Value(GL_MAP2_INDEX));
#endif
#if defined(GL_MAP2_NORMAL)
	Gura_AssignValue(GL_MAP2_NORMAL, Value(GL_MAP2_NORMAL));
#endif
#if defined(GL_MAP2_TEXTURE_COORD_1)
	Gura_AssignValue(GL_MAP2_TEXTURE_COORD_1, Value(GL_MAP2_TEXTURE_COORD_1));
#endif
#if defined(GL_MAP2_TEXTURE_COORD_2)
	Gura_AssignValue(GL_MAP2_TEXTURE_COORD_2, Value(GL_MAP2_TEXTURE_COORD_2));
#endif
#if defined(GL_MAP2_TEXTURE_COORD_3)
	Gura_AssignValue(GL_MAP2_TEXTURE_COORD_3, Value(GL_MAP2_TEXTURE_COORD_3));
#endif
#if defined(GL_MAP2_TEXTURE_COORD_4)
	Gura_AssignValue(GL_MAP2_TEXTURE_COORD_4, Value(GL_MAP2_TEXTURE_COORD_4));
#endif
#if defined(GL_MAP2_VERTEX_3)
	Gura_AssignValue(GL_MAP2_VERTEX_3, Value(GL_MAP2_VERTEX_3));
#endif
#if defined(GL_MAP2_VERTEX_4)
	Gura_AssignValue(GL_MAP2_VERTEX_4, Value(GL_MAP2_VERTEX_4));
#endif
#if defined(GL_MAP1_GRID_DOMAIN)
	Gura_AssignValue(GL_MAP1_GRID_DOMAIN, Value(GL_MAP1_GRID_DOMAIN));
#endif
#if defined(GL_MAP1_GRID_SEGMENTS)
	Gura_AssignValue(GL_MAP1_GRID_SEGMENTS, Value(GL_MAP1_GRID_SEGMENTS));
#endif
#if defined(GL_MAP2_GRID_DOMAIN)
	Gura_AssignValue(GL_MAP2_GRID_DOMAIN, Value(GL_MAP2_GRID_DOMAIN));
#endif
#if defined(GL_MAP2_GRID_SEGMENTS)
	Gura_AssignValue(GL_MAP2_GRID_SEGMENTS, Value(GL_MAP2_GRID_SEGMENTS));
#endif
#if defined(GL_TEXTURE_1D)
	Gura_AssignValue(GL_TEXTURE_1D, Value(GL_TEXTURE_1D));
#endif
#if defined(GL_TEXTURE_2D)
	Gura_AssignValue(GL_TEXTURE_2D, Value(GL_TEXTURE_2D));
#endif
#if defined(GL_FEEDBACK_BUFFER_POINTER)
	Gura_AssignValue(GL_FEEDBACK_BUFFER_POINTER, Value(GL_FEEDBACK_BUFFER_POINTER));
#endif
#if defined(GL_FEEDBACK_BUFFER_SIZE)
	Gura_AssignValue(GL_FEEDBACK_BUFFER_SIZE, Value(GL_FEEDBACK_BUFFER_SIZE));
#endif
#if defined(GL_FEEDBACK_BUFFER_TYPE)
	Gura_AssignValue(GL_FEEDBACK_BUFFER_TYPE, Value(GL_FEEDBACK_BUFFER_TYPE));
#endif
#if defined(GL_SELECTION_BUFFER_POINTER)
	Gura_AssignValue(GL_SELECTION_BUFFER_POINTER, Value(GL_SELECTION_BUFFER_POINTER));
#endif
#if defined(GL_SELECTION_BUFFER_SIZE)
	Gura_AssignValue(GL_SELECTION_BUFFER_SIZE, Value(GL_SELECTION_BUFFER_SIZE));
#endif
#if defined(GL_TEXTURE_WIDTH)
	Gura_AssignValue(GL_TEXTURE_WIDTH, Value(GL_TEXTURE_WIDTH));
#endif
#if defined(GL_TEXTURE_HEIGHT)
	Gura_AssignValue(GL_TEXTURE_HEIGHT, Value(GL_TEXTURE_HEIGHT));
#endif
#if defined(GL_TEXTURE_INTERNAL_FORMAT)
	Gura_AssignValue(GL_TEXTURE_INTERNAL_FORMAT, Value(GL_TEXTURE_INTERNAL_FORMAT));
#endif
#if defined(GL_TEXTURE_BORDER_COLOR)
	Gura_AssignValue(GL_TEXTURE_BORDER_COLOR, Value(GL_TEXTURE_BORDER_COLOR));
#endif
#if defined(GL_TEXTURE_BORDER)
	Gura_AssignValue(GL_TEXTURE_BORDER, Value(GL_TEXTURE_BORDER));
#endif
#if defined(GL_DONT_CARE)
	Gura_AssignValue(GL_DONT_CARE, Value(GL_DONT_CARE));
#endif
#if defined(GL_FASTEST)
	Gura_AssignValue(GL_FASTEST, Value(GL_FASTEST));
#endif
#if defined(GL_NICEST)
	Gura_AssignValue(GL_NICEST, Value(GL_NICEST));
#endif
#if defined(GL_LIGHT0)
	Gura_AssignValue(GL_LIGHT0, Value(GL_LIGHT0));
#endif
#if defined(GL_LIGHT1)
	Gura_AssignValue(GL_LIGHT1, Value(GL_LIGHT1));
#endif
#if defined(GL_LIGHT2)
	Gura_AssignValue(GL_LIGHT2, Value(GL_LIGHT2));
#endif
#if defined(GL_LIGHT3)
	Gura_AssignValue(GL_LIGHT3, Value(GL_LIGHT3));
#endif
#if defined(GL_LIGHT4)
	Gura_AssignValue(GL_LIGHT4, Value(GL_LIGHT4));
#endif
#if defined(GL_LIGHT5)
	Gura_AssignValue(GL_LIGHT5, Value(GL_LIGHT5));
#endif
#if defined(GL_LIGHT6)
	Gura_AssignValue(GL_LIGHT6, Value(GL_LIGHT6));
#endif
#if defined(GL_LIGHT7)
	Gura_AssignValue(GL_LIGHT7, Value(GL_LIGHT7));
#endif
#if defined(GL_AMBIENT)
	Gura_AssignValue(GL_AMBIENT, Value(GL_AMBIENT));
#endif
#if defined(GL_DIFFUSE)
	Gura_AssignValue(GL_DIFFUSE, Value(GL_DIFFUSE));
#endif
#if defined(GL_SPECULAR)
	Gura_AssignValue(GL_SPECULAR, Value(GL_SPECULAR));
#endif
#if defined(GL_POSITION)
	Gura_AssignValue(GL_POSITION, Value(GL_POSITION));
#endif
#if defined(GL_SPOT_DIRECTION)
	Gura_AssignValue(GL_SPOT_DIRECTION, Value(GL_SPOT_DIRECTION));
#endif
#if defined(GL_SPOT_EXPONENT)
	Gura_AssignValue(GL_SPOT_EXPONENT, Value(GL_SPOT_EXPONENT));
#endif
#if defined(GL_SPOT_CUTOFF)
	Gura_AssignValue(GL_SPOT_CUTOFF, Value(GL_SPOT_CUTOFF));
#endif
#if defined(GL_CONSTANT_ATTENUATION)
	Gura_AssignValue(GL_CONSTANT_ATTENUATION, Value(GL_CONSTANT_ATTENUATION));
#endif
#if defined(GL_LINEAR_ATTENUATION)
	Gura_AssignValue(GL_LINEAR_ATTENUATION, Value(GL_LINEAR_ATTENUATION));
#endif
#if defined(GL_QUADRATIC_ATTENUATION)
	Gura_AssignValue(GL_QUADRATIC_ATTENUATION, Value(GL_QUADRATIC_ATTENUATION));
#endif
#if defined(GL_COMPILE)
	Gura_AssignValue(GL_COMPILE, Value(GL_COMPILE));
#endif
#if defined(GL_COMPILE_AND_EXECUTE)
	Gura_AssignValue(GL_COMPILE_AND_EXECUTE, Value(GL_COMPILE_AND_EXECUTE));
#endif
#if defined(GL_CLEAR)
	Gura_AssignValue(GL_CLEAR, Value(GL_CLEAR));
#endif
#if defined(GL_AND)
	Gura_AssignValue(GL_AND, Value(GL_AND));
#endif
#if defined(GL_AND_REVERSE)
	Gura_AssignValue(GL_AND_REVERSE, Value(GL_AND_REVERSE));
#endif
#if defined(GL_COPY)
	Gura_AssignValue(GL_COPY, Value(GL_COPY));
#endif
#if defined(GL_AND_INVERTED)
	Gura_AssignValue(GL_AND_INVERTED, Value(GL_AND_INVERTED));
#endif
#if defined(GL_NOOP)
	Gura_AssignValue(GL_NOOP, Value(GL_NOOP));
#endif
#if defined(GL_XOR)
	Gura_AssignValue(GL_XOR, Value(GL_XOR));
#endif
#if defined(GL_OR)
	Gura_AssignValue(GL_OR, Value(GL_OR));
#endif
#if defined(GL_NOR)
	Gura_AssignValue(GL_NOR, Value(GL_NOR));
#endif
#if defined(GL_EQUIV)
	Gura_AssignValue(GL_EQUIV, Value(GL_EQUIV));
#endif
#if defined(GL_INVERT)
	Gura_AssignValue(GL_INVERT, Value(GL_INVERT));
#endif
#if defined(GL_OR_REVERSE)
	Gura_AssignValue(GL_OR_REVERSE, Value(GL_OR_REVERSE));
#endif
#if defined(GL_COPY_INVERTED)
	Gura_AssignValue(GL_COPY_INVERTED, Value(GL_COPY_INVERTED));
#endif
#if defined(GL_OR_INVERTED)
	Gura_AssignValue(GL_OR_INVERTED, Value(GL_OR_INVERTED));
#endif
#if defined(GL_NAND)
	Gura_AssignValue(GL_NAND, Value(GL_NAND));
#endif
#if defined(GL_SET)
	Gura_AssignValue(GL_SET, Value(GL_SET));
#endif
#if defined(GL_EMISSION)
	Gura_AssignValue(GL_EMISSION, Value(GL_EMISSION));
#endif
#if defined(GL_SHININESS)
	Gura_AssignValue(GL_SHININESS, Value(GL_SHININESS));
#endif
#if defined(GL_AMBIENT_AND_DIFFUSE)
	Gura_AssignValue(GL_AMBIENT_AND_DIFFUSE, Value(GL_AMBIENT_AND_DIFFUSE));
#endif
#if defined(GL_COLOR_INDEXES)
	Gura_AssignValue(GL_COLOR_INDEXES, Value(GL_COLOR_INDEXES));
#endif
#if defined(GL_MODELVIEW)
	Gura_AssignValue(GL_MODELVIEW, Value(GL_MODELVIEW));
#endif
#if defined(GL_PROJECTION)
	Gura_AssignValue(GL_PROJECTION, Value(GL_PROJECTION));
#endif
#if defined(GL_TEXTURE)
	Gura_AssignValue(GL_TEXTURE, Value(GL_TEXTURE));
#endif
#if defined(GL_COLOR)
	Gura_AssignValue(GL_COLOR, Value(GL_COLOR));
#endif
#if defined(GL_DEPTH)
	Gura_AssignValue(GL_DEPTH, Value(GL_DEPTH));
#endif
#if defined(GL_STENCIL)
	Gura_AssignValue(GL_STENCIL, Value(GL_STENCIL));
#endif
#if defined(GL_COLOR_INDEX)
	Gura_AssignValue(GL_COLOR_INDEX, Value(GL_COLOR_INDEX));
#endif
#if defined(GL_STENCIL_INDEX)
	Gura_AssignValue(GL_STENCIL_INDEX, Value(GL_STENCIL_INDEX));
#endif
#if defined(GL_DEPTH_COMPONENT)
	Gura_AssignValue(GL_DEPTH_COMPONENT, Value(GL_DEPTH_COMPONENT));
#endif
#if defined(GL_RED)
	Gura_AssignValue(GL_RED, Value(GL_RED));
#endif
#if defined(GL_GREEN)
	Gura_AssignValue(GL_GREEN, Value(GL_GREEN));
#endif
#if defined(GL_BLUE)
	Gura_AssignValue(GL_BLUE, Value(GL_BLUE));
#endif
#if defined(GL_ALPHA)
	Gura_AssignValue(GL_ALPHA, Value(GL_ALPHA));
#endif
#if defined(GL_RGB)
	Gura_AssignValue(GL_RGB, Value(GL_RGB));
#endif
#if defined(GL_RGBA)
	Gura_AssignValue(GL_RGBA, Value(GL_RGBA));
#endif
#if defined(GL_LUMINANCE)
	Gura_AssignValue(GL_LUMINANCE, Value(GL_LUMINANCE));
#endif
#if defined(GL_LUMINANCE_ALPHA)
	Gura_AssignValue(GL_LUMINANCE_ALPHA, Value(GL_LUMINANCE_ALPHA));
#endif
#if defined(GL_BITMAP)
	Gura_AssignValue(GL_BITMAP, Value(GL_BITMAP));
#endif
#if defined(GL_POINT)
	Gura_AssignValue(GL_POINT, Value(GL_POINT));
#endif
#if defined(GL_LINE)
	Gura_AssignValue(GL_LINE, Value(GL_LINE));
#endif
#if defined(GL_FILL)
	Gura_AssignValue(GL_FILL, Value(GL_FILL));
#endif
#if defined(GL_RENDER)
	Gura_AssignValue(GL_RENDER, Value(GL_RENDER));
#endif
#if defined(GL_FEEDBACK)
	Gura_AssignValue(GL_FEEDBACK, Value(GL_FEEDBACK));
#endif
#if defined(GL_SELECT)
	Gura_AssignValue(GL_SELECT, Value(GL_SELECT));
#endif
#if defined(GL_FLAT)
	Gura_AssignValue(GL_FLAT, Value(GL_FLAT));
#endif
#if defined(GL_SMOOTH)
	Gura_AssignValue(GL_SMOOTH, Value(GL_SMOOTH));
#endif
#if defined(GL_KEEP)
	Gura_AssignValue(GL_KEEP, Value(GL_KEEP));
#endif
#if defined(GL_REPLACE)
	Gura_AssignValue(GL_REPLACE, Value(GL_REPLACE));
#endif
#if defined(GL_INCR)
	Gura_AssignValue(GL_INCR, Value(GL_INCR));
#endif
#if defined(GL_DECR)
	Gura_AssignValue(GL_DECR, Value(GL_DECR));
#endif
#if defined(GL_VENDOR)
	Gura_AssignValue(GL_VENDOR, Value(GL_VENDOR));
#endif
#if defined(GL_RENDERER)
	Gura_AssignValue(GL_RENDERER, Value(GL_RENDERER));
#endif
#if defined(GL_VERSION)
	Gura_AssignValue(GL_VERSION, Value(GL_VERSION));
#endif
#if defined(GL_EXTENSIONS)
	Gura_AssignValue(GL_EXTENSIONS, Value(GL_EXTENSIONS));
#endif
#if defined(GL_S)
	Gura_AssignValue(GL_S, Value(GL_S));
#endif
#if defined(GL_T)
	Gura_AssignValue(GL_T, Value(GL_T));
#endif
#if defined(GL_R)
	Gura_AssignValue(GL_R, Value(GL_R));
#endif
#if defined(GL_Q)
	Gura_AssignValue(GL_Q, Value(GL_Q));
#endif
#if defined(GL_MODULATE)
	Gura_AssignValue(GL_MODULATE, Value(GL_MODULATE));
#endif
#if defined(GL_DECAL)
	Gura_AssignValue(GL_DECAL, Value(GL_DECAL));
#endif
#if defined(GL_TEXTURE_ENV_MODE)
	Gura_AssignValue(GL_TEXTURE_ENV_MODE, Value(GL_TEXTURE_ENV_MODE));
#endif
#if defined(GL_TEXTURE_ENV_COLOR)
	Gura_AssignValue(GL_TEXTURE_ENV_COLOR, Value(GL_TEXTURE_ENV_COLOR));
#endif
#if defined(GL_TEXTURE_ENV)
	Gura_AssignValue(GL_TEXTURE_ENV, Value(GL_TEXTURE_ENV));
#endif
#if defined(GL_EYE_LINEAR)
	Gura_AssignValue(GL_EYE_LINEAR, Value(GL_EYE_LINEAR));
#endif
#if defined(GL_OBJECT_LINEAR)
	Gura_AssignValue(GL_OBJECT_LINEAR, Value(GL_OBJECT_LINEAR));
#endif
#if defined(GL_SPHERE_MAP)
	Gura_AssignValue(GL_SPHERE_MAP, Value(GL_SPHERE_MAP));
#endif
#if defined(GL_TEXTURE_GEN_MODE)
	Gura_AssignValue(GL_TEXTURE_GEN_MODE, Value(GL_TEXTURE_GEN_MODE));
#endif
#if defined(GL_OBJECT_PLANE)
	Gura_AssignValue(GL_OBJECT_PLANE, Value(GL_OBJECT_PLANE));
#endif
#if defined(GL_EYE_PLANE)
	Gura_AssignValue(GL_EYE_PLANE, Value(GL_EYE_PLANE));
#endif
#if defined(GL_NEAREST)
	Gura_AssignValue(GL_NEAREST, Value(GL_NEAREST));
#endif
#if defined(GL_LINEAR)
	Gura_AssignValue(GL_LINEAR, Value(GL_LINEAR));
#endif
#if defined(GL_NEAREST_MIPMAP_NEAREST)
	Gura_AssignValue(GL_NEAREST_MIPMAP_NEAREST, Value(GL_NEAREST_MIPMAP_NEAREST));
#endif
#if defined(GL_LINEAR_MIPMAP_NEAREST)
	Gura_AssignValue(GL_LINEAR_MIPMAP_NEAREST, Value(GL_LINEAR_MIPMAP_NEAREST));
#endif
#if defined(GL_NEAREST_MIPMAP_LINEAR)
	Gura_AssignValue(GL_NEAREST_MIPMAP_LINEAR, Value(GL_NEAREST_MIPMAP_LINEAR));
#endif
#if defined(GL_LINEAR_MIPMAP_LINEAR)
	Gura_AssignValue(GL_LINEAR_MIPMAP_LINEAR, Value(GL_LINEAR_MIPMAP_LINEAR));
#endif
#if defined(GL_TEXTURE_MAG_FILTER)
	Gura_AssignValue(GL_TEXTURE_MAG_FILTER, Value(GL_TEXTURE_MAG_FILTER));
#endif
#if defined(GL_TEXTURE_MIN_FILTER)
	Gura_AssignValue(GL_TEXTURE_MIN_FILTER, Value(GL_TEXTURE_MIN_FILTER));
#endif
#if defined(GL_TEXTURE_WRAP_S)
	Gura_AssignValue(GL_TEXTURE_WRAP_S, Value(GL_TEXTURE_WRAP_S));
#endif
#if defined(GL_TEXTURE_WRAP_T)
	Gura_AssignValue(GL_TEXTURE_WRAP_T, Value(GL_TEXTURE_WRAP_T));
#endif
#if defined(GL_CLAMP)
	Gura_AssignValue(GL_CLAMP, Value(GL_CLAMP));
#endif
#if defined(GL_REPEAT)
	Gura_AssignValue(GL_REPEAT, Value(GL_REPEAT));
#endif
#if defined(GL_CLIENT_PIXEL_STORE_BIT)
	Gura_AssignValue(GL_CLIENT_PIXEL_STORE_BIT, Value(GL_CLIENT_PIXEL_STORE_BIT));
#endif
#if defined(GL_CLIENT_VERTEX_ARRAY_BIT)
	Gura_AssignValue(GL_CLIENT_VERTEX_ARRAY_BIT, Value(GL_CLIENT_VERTEX_ARRAY_BIT));
#endif
#if defined(GL_CLIENT_ALL_ATTRIB_BITS)
	Gura_AssignValue(GL_CLIENT_ALL_ATTRIB_BITS, Value(GL_CLIENT_ALL_ATTRIB_BITS));
#endif
#if defined(GL_POLYGON_OFFSET_FACTOR)
	Gura_AssignValue(GL_POLYGON_OFFSET_FACTOR, Value(GL_POLYGON_OFFSET_FACTOR));
#endif
#if defined(GL_POLYGON_OFFSET_UNITS)
	Gura_AssignValue(GL_POLYGON_OFFSET_UNITS, Value(GL_POLYGON_OFFSET_UNITS));
#endif
#if defined(GL_POLYGON_OFFSET_POINT)
	Gura_AssignValue(GL_POLYGON_OFFSET_POINT, Value(GL_POLYGON_OFFSET_POINT));
#endif
#if defined(GL_POLYGON_OFFSET_LINE)
	Gura_AssignValue(GL_POLYGON_OFFSET_LINE, Value(GL_POLYGON_OFFSET_LINE));
#endif
#if defined(GL_POLYGON_OFFSET_FILL)
	Gura_AssignValue(GL_POLYGON_OFFSET_FILL, Value(GL_POLYGON_OFFSET_FILL));
#endif
#if defined(GL_ALPHA4)
	Gura_AssignValue(GL_ALPHA4, Value(GL_ALPHA4));
#endif
#if defined(GL_ALPHA8)
	Gura_AssignValue(GL_ALPHA8, Value(GL_ALPHA8));
#endif
#if defined(GL_ALPHA12)
	Gura_AssignValue(GL_ALPHA12, Value(GL_ALPHA12));
#endif
#if defined(GL_ALPHA16)
	Gura_AssignValue(GL_ALPHA16, Value(GL_ALPHA16));
#endif
#if defined(GL_LUMINANCE4)
	Gura_AssignValue(GL_LUMINANCE4, Value(GL_LUMINANCE4));
#endif
#if defined(GL_LUMINANCE8)
	Gura_AssignValue(GL_LUMINANCE8, Value(GL_LUMINANCE8));
#endif
#if defined(GL_LUMINANCE12)
	Gura_AssignValue(GL_LUMINANCE12, Value(GL_LUMINANCE12));
#endif
#if defined(GL_LUMINANCE16)
	Gura_AssignValue(GL_LUMINANCE16, Value(GL_LUMINANCE16));
#endif
#if defined(GL_LUMINANCE4_ALPHA4)
	Gura_AssignValue(GL_LUMINANCE4_ALPHA4, Value(GL_LUMINANCE4_ALPHA4));
#endif
#if defined(GL_LUMINANCE6_ALPHA2)
	Gura_AssignValue(GL_LUMINANCE6_ALPHA2, Value(GL_LUMINANCE6_ALPHA2));
#endif
#if defined(GL_LUMINANCE8_ALPHA8)
	Gura_AssignValue(GL_LUMINANCE8_ALPHA8, Value(GL_LUMINANCE8_ALPHA8));
#endif
#if defined(GL_LUMINANCE12_ALPHA4)
	Gura_AssignValue(GL_LUMINANCE12_ALPHA4, Value(GL_LUMINANCE12_ALPHA4));
#endif
#if defined(GL_LUMINANCE12_ALPHA12)
	Gura_AssignValue(GL_LUMINANCE12_ALPHA12, Value(GL_LUMINANCE12_ALPHA12));
#endif
#if defined(GL_LUMINANCE16_ALPHA16)
	Gura_AssignValue(GL_LUMINANCE16_ALPHA16, Value(GL_LUMINANCE16_ALPHA16));
#endif
#if defined(GL_INTENSITY)
	Gura_AssignValue(GL_INTENSITY, Value(GL_INTENSITY));
#endif
#if defined(GL_INTENSITY4)
	Gura_AssignValue(GL_INTENSITY4, Value(GL_INTENSITY4));
#endif
#if defined(GL_INTENSITY8)
	Gura_AssignValue(GL_INTENSITY8, Value(GL_INTENSITY8));
#endif
#if defined(GL_INTENSITY12)
	Gura_AssignValue(GL_INTENSITY12, Value(GL_INTENSITY12));
#endif
#if defined(GL_INTENSITY16)
	Gura_AssignValue(GL_INTENSITY16, Value(GL_INTENSITY16));
#endif
#if defined(GL_R3_G3_B2)
	Gura_AssignValue(GL_R3_G3_B2, Value(GL_R3_G3_B2));
#endif
#if defined(GL_RGB4)
	Gura_AssignValue(GL_RGB4, Value(GL_RGB4));
#endif
#if defined(GL_RGB5)
	Gura_AssignValue(GL_RGB5, Value(GL_RGB5));
#endif
#if defined(GL_RGB8)
	Gura_AssignValue(GL_RGB8, Value(GL_RGB8));
#endif
#if defined(GL_RGB10)
	Gura_AssignValue(GL_RGB10, Value(GL_RGB10));
#endif
#if defined(GL_RGB12)
	Gura_AssignValue(GL_RGB12, Value(GL_RGB12));
#endif
#if defined(GL_RGB16)
	Gura_AssignValue(GL_RGB16, Value(GL_RGB16));
#endif
#if defined(GL_RGBA2)
	Gura_AssignValue(GL_RGBA2, Value(GL_RGBA2));
#endif
#if defined(GL_RGBA4)
	Gura_AssignValue(GL_RGBA4, Value(GL_RGBA4));
#endif
#if defined(GL_RGB5_A1)
	Gura_AssignValue(GL_RGB5_A1, Value(GL_RGB5_A1));
#endif
#if defined(GL_RGBA8)
	Gura_AssignValue(GL_RGBA8, Value(GL_RGBA8));
#endif
#if defined(GL_RGB10_A2)
	Gura_AssignValue(GL_RGB10_A2, Value(GL_RGB10_A2));
#endif
#if defined(GL_RGBA12)
	Gura_AssignValue(GL_RGBA12, Value(GL_RGBA12));
#endif
#if defined(GL_RGBA16)
	Gura_AssignValue(GL_RGBA16, Value(GL_RGBA16));
#endif
#if defined(GL_TEXTURE_RED_SIZE)
	Gura_AssignValue(GL_TEXTURE_RED_SIZE, Value(GL_TEXTURE_RED_SIZE));
#endif
#if defined(GL_TEXTURE_GREEN_SIZE)
	Gura_AssignValue(GL_TEXTURE_GREEN_SIZE, Value(GL_TEXTURE_GREEN_SIZE));
#endif
#if defined(GL_TEXTURE_BLUE_SIZE)
	Gura_AssignValue(GL_TEXTURE_BLUE_SIZE, Value(GL_TEXTURE_BLUE_SIZE));
#endif
#if defined(GL_TEXTURE_ALPHA_SIZE)
	Gura_AssignValue(GL_TEXTURE_ALPHA_SIZE, Value(GL_TEXTURE_ALPHA_SIZE));
#endif
#if defined(GL_TEXTURE_LUMINANCE_SIZE)
	Gura_AssignValue(GL_TEXTURE_LUMINANCE_SIZE, Value(GL_TEXTURE_LUMINANCE_SIZE));
#endif
#if defined(GL_TEXTURE_INTENSITY_SIZE)
	Gura_AssignValue(GL_TEXTURE_INTENSITY_SIZE, Value(GL_TEXTURE_INTENSITY_SIZE));
#endif
#if defined(GL_PROXY_TEXTURE_1D)
	Gura_AssignValue(GL_PROXY_TEXTURE_1D, Value(GL_PROXY_TEXTURE_1D));
#endif
#if defined(GL_PROXY_TEXTURE_2D)
	Gura_AssignValue(GL_PROXY_TEXTURE_2D, Value(GL_PROXY_TEXTURE_2D));
#endif
#if defined(GL_TEXTURE_PRIORITY)
	Gura_AssignValue(GL_TEXTURE_PRIORITY, Value(GL_TEXTURE_PRIORITY));
#endif
#if defined(GL_TEXTURE_RESIDENT)
	Gura_AssignValue(GL_TEXTURE_RESIDENT, Value(GL_TEXTURE_RESIDENT));
#endif
#if defined(GL_TEXTURE_BINDING_1D)
	Gura_AssignValue(GL_TEXTURE_BINDING_1D, Value(GL_TEXTURE_BINDING_1D));
#endif
#if defined(GL_TEXTURE_BINDING_2D)
	Gura_AssignValue(GL_TEXTURE_BINDING_2D, Value(GL_TEXTURE_BINDING_2D));
#endif
#if defined(GL_TEXTURE_BINDING_3D)
	Gura_AssignValue(GL_TEXTURE_BINDING_3D, Value(GL_TEXTURE_BINDING_3D));
#endif
#if defined(GL_VERTEX_ARRAY)
	Gura_AssignValue(GL_VERTEX_ARRAY, Value(GL_VERTEX_ARRAY));
#endif
#if defined(GL_NORMAL_ARRAY)
	Gura_AssignValue(GL_NORMAL_ARRAY, Value(GL_NORMAL_ARRAY));
#endif
#if defined(GL_COLOR_ARRAY)
	Gura_AssignValue(GL_COLOR_ARRAY, Value(GL_COLOR_ARRAY));
#endif
#if defined(GL_INDEX_ARRAY)
	Gura_AssignValue(GL_INDEX_ARRAY, Value(GL_INDEX_ARRAY));
#endif
#if defined(GL_TEXTURE_COORD_ARRAY)
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY, Value(GL_TEXTURE_COORD_ARRAY));
#endif
#if defined(GL_EDGE_FLAG_ARRAY)
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY, Value(GL_EDGE_FLAG_ARRAY));
#endif
#if defined(GL_VERTEX_ARRAY_SIZE)
	Gura_AssignValue(GL_VERTEX_ARRAY_SIZE, Value(GL_VERTEX_ARRAY_SIZE));
#endif
#if defined(GL_VERTEX_ARRAY_TYPE)
	Gura_AssignValue(GL_VERTEX_ARRAY_TYPE, Value(GL_VERTEX_ARRAY_TYPE));
#endif
#if defined(GL_VERTEX_ARRAY_STRIDE)
	Gura_AssignValue(GL_VERTEX_ARRAY_STRIDE, Value(GL_VERTEX_ARRAY_STRIDE));
#endif
#if defined(GL_NORMAL_ARRAY_TYPE)
	Gura_AssignValue(GL_NORMAL_ARRAY_TYPE, Value(GL_NORMAL_ARRAY_TYPE));
#endif
#if defined(GL_NORMAL_ARRAY_STRIDE)
	Gura_AssignValue(GL_NORMAL_ARRAY_STRIDE, Value(GL_NORMAL_ARRAY_STRIDE));
#endif
#if defined(GL_COLOR_ARRAY_SIZE)
	Gura_AssignValue(GL_COLOR_ARRAY_SIZE, Value(GL_COLOR_ARRAY_SIZE));
#endif
#if defined(GL_COLOR_ARRAY_TYPE)
	Gura_AssignValue(GL_COLOR_ARRAY_TYPE, Value(GL_COLOR_ARRAY_TYPE));
#endif
#if defined(GL_COLOR_ARRAY_STRIDE)
	Gura_AssignValue(GL_COLOR_ARRAY_STRIDE, Value(GL_COLOR_ARRAY_STRIDE));
#endif
#if defined(GL_INDEX_ARRAY_TYPE)
	Gura_AssignValue(GL_INDEX_ARRAY_TYPE, Value(GL_INDEX_ARRAY_TYPE));
#endif
#if defined(GL_INDEX_ARRAY_STRIDE)
	Gura_AssignValue(GL_INDEX_ARRAY_STRIDE, Value(GL_INDEX_ARRAY_STRIDE));
#endif
#if defined(GL_TEXTURE_COORD_ARRAY_SIZE)
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_SIZE, Value(GL_TEXTURE_COORD_ARRAY_SIZE));
#endif
#if defined(GL_TEXTURE_COORD_ARRAY_TYPE)
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_TYPE, Value(GL_TEXTURE_COORD_ARRAY_TYPE));
#endif
#if defined(GL_TEXTURE_COORD_ARRAY_STRIDE)
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_STRIDE, Value(GL_TEXTURE_COORD_ARRAY_STRIDE));
#endif
#if defined(GL_EDGE_FLAG_ARRAY_STRIDE)
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY_STRIDE, Value(GL_EDGE_FLAG_ARRAY_STRIDE));
#endif
#if defined(GL_VERTEX_ARRAY_POINTER)
	Gura_AssignValue(GL_VERTEX_ARRAY_POINTER, Value(GL_VERTEX_ARRAY_POINTER));
#endif
#if defined(GL_NORMAL_ARRAY_POINTER)
	Gura_AssignValue(GL_NORMAL_ARRAY_POINTER, Value(GL_NORMAL_ARRAY_POINTER));
#endif
#if defined(GL_COLOR_ARRAY_POINTER)
	Gura_AssignValue(GL_COLOR_ARRAY_POINTER, Value(GL_COLOR_ARRAY_POINTER));
#endif
#if defined(GL_INDEX_ARRAY_POINTER)
	Gura_AssignValue(GL_INDEX_ARRAY_POINTER, Value(GL_INDEX_ARRAY_POINTER));
#endif
#if defined(GL_TEXTURE_COORD_ARRAY_POINTER)
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_POINTER, Value(GL_TEXTURE_COORD_ARRAY_POINTER));
#endif
#if defined(GL_EDGE_FLAG_ARRAY_POINTER)
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY_POINTER, Value(GL_EDGE_FLAG_ARRAY_POINTER));
#endif
#if defined(GL_V2F)
	Gura_AssignValue(GL_V2F, Value(GL_V2F));
#endif
#if defined(GL_V3F)
	Gura_AssignValue(GL_V3F, Value(GL_V3F));
#endif
#if defined(GL_C4UB_V2F)
	Gura_AssignValue(GL_C4UB_V2F, Value(GL_C4UB_V2F));
#endif
#if defined(GL_C4UB_V3F)
	Gura_AssignValue(GL_C4UB_V3F, Value(GL_C4UB_V3F));
#endif
#if defined(GL_C3F_V3F)
	Gura_AssignValue(GL_C3F_V3F, Value(GL_C3F_V3F));
#endif
#if defined(GL_N3F_V3F)
	Gura_AssignValue(GL_N3F_V3F, Value(GL_N3F_V3F));
#endif
#if defined(GL_C4F_N3F_V3F)
	Gura_AssignValue(GL_C4F_N3F_V3F, Value(GL_C4F_N3F_V3F));
#endif
#if defined(GL_T2F_V3F)
	Gura_AssignValue(GL_T2F_V3F, Value(GL_T2F_V3F));
#endif
#if defined(GL_T4F_V4F)
	Gura_AssignValue(GL_T4F_V4F, Value(GL_T4F_V4F));
#endif
#if defined(GL_T2F_C4UB_V3F)
	Gura_AssignValue(GL_T2F_C4UB_V3F, Value(GL_T2F_C4UB_V3F));
#endif
#if defined(GL_T2F_C3F_V3F)
	Gura_AssignValue(GL_T2F_C3F_V3F, Value(GL_T2F_C3F_V3F));
#endif
#if defined(GL_T2F_N3F_V3F)
	Gura_AssignValue(GL_T2F_N3F_V3F, Value(GL_T2F_N3F_V3F));
#endif
#if defined(GL_T2F_C4F_N3F_V3F)
	Gura_AssignValue(GL_T2F_C4F_N3F_V3F, Value(GL_T2F_C4F_N3F_V3F));
#endif
#if defined(GL_T4F_C4F_N3F_V4F)
	Gura_AssignValue(GL_T4F_C4F_N3F_V4F, Value(GL_T4F_C4F_N3F_V4F));
#endif
#if defined(GL_BGR)
	Gura_AssignValue(GL_BGR, Value(GL_BGR));
#endif
#if defined(GL_BGRA)
	Gura_AssignValue(GL_BGRA, Value(GL_BGRA));
#endif
#if defined(GL_CONSTANT_COLOR)
	Gura_AssignValue(GL_CONSTANT_COLOR, Value(GL_CONSTANT_COLOR));
#endif
#if defined(GL_ONE_MINUS_CONSTANT_COLOR)
	Gura_AssignValue(GL_ONE_MINUS_CONSTANT_COLOR, Value(GL_ONE_MINUS_CONSTANT_COLOR));
#endif
#if defined(GL_CONSTANT_ALPHA)
	Gura_AssignValue(GL_CONSTANT_ALPHA, Value(GL_CONSTANT_ALPHA));
#endif
#if defined(GL_ONE_MINUS_CONSTANT_ALPHA)
	Gura_AssignValue(GL_ONE_MINUS_CONSTANT_ALPHA, Value(GL_ONE_MINUS_CONSTANT_ALPHA));
#endif
#if defined(GL_BLEND_COLOR)
	Gura_AssignValue(GL_BLEND_COLOR, Value(GL_BLEND_COLOR));
#endif
#if defined(GL_FUNC_ADD)
	Gura_AssignValue(GL_FUNC_ADD, Value(GL_FUNC_ADD));
#endif
#if defined(GL_MIN)
	Gura_AssignValue(GL_MIN, Value(GL_MIN));
#endif
#if defined(GL_MAX)
	Gura_AssignValue(GL_MAX, Value(GL_MAX));
#endif
#if defined(GL_BLEND_EQUATION)
	Gura_AssignValue(GL_BLEND_EQUATION, Value(GL_BLEND_EQUATION));
#endif
#if defined(GL_BLEND_EQUATION_RGB)
	Gura_AssignValue(GL_BLEND_EQUATION_RGB, Value(GL_BLEND_EQUATION_RGB));
#endif
#if defined(GL_BLEND_EQUATION_ALPHA)
	Gura_AssignValue(GL_BLEND_EQUATION_ALPHA, Value(GL_BLEND_EQUATION_ALPHA));
#endif
#if defined(GL_FUNC_SUBTRACT)
	Gura_AssignValue(GL_FUNC_SUBTRACT, Value(GL_FUNC_SUBTRACT));
#endif
#if defined(GL_FUNC_REVERSE_SUBTRACT)
	Gura_AssignValue(GL_FUNC_REVERSE_SUBTRACT, Value(GL_FUNC_REVERSE_SUBTRACT));
#endif
#if defined(GL_COLOR_MATRIX)
	Gura_AssignValue(GL_COLOR_MATRIX, Value(GL_COLOR_MATRIX));
#endif
#if defined(GL_COLOR_MATRIX_STACK_DEPTH)
	Gura_AssignValue(GL_COLOR_MATRIX_STACK_DEPTH, Value(GL_COLOR_MATRIX_STACK_DEPTH));
#endif
#if defined(GL_MAX_COLOR_MATRIX_STACK_DEPTH)
	Gura_AssignValue(GL_MAX_COLOR_MATRIX_STACK_DEPTH, Value(GL_MAX_COLOR_MATRIX_STACK_DEPTH));
#endif
#if defined(GL_POST_COLOR_MATRIX_RED_SCALE)
	Gura_AssignValue(GL_POST_COLOR_MATRIX_RED_SCALE, Value(GL_POST_COLOR_MATRIX_RED_SCALE));
#endif
#if defined(GL_POST_COLOR_MATRIX_GREEN_SCALE)
	Gura_AssignValue(GL_POST_COLOR_MATRIX_GREEN_SCALE, Value(GL_POST_COLOR_MATRIX_GREEN_SCALE));
#endif
#if defined(GL_POST_COLOR_MATRIX_BLUE_SCALE)
	Gura_AssignValue(GL_POST_COLOR_MATRIX_BLUE_SCALE, Value(GL_POST_COLOR_MATRIX_BLUE_SCALE));
#endif
#if defined(GL_POST_COLOR_MATRIX_ALPHA_SCALE)
	Gura_AssignValue(GL_POST_COLOR_MATRIX_ALPHA_SCALE, Value(GL_POST_COLOR_MATRIX_ALPHA_SCALE));
#endif
#if defined(GL_POST_COLOR_MATRIX_RED_BIAS)
	Gura_AssignValue(GL_POST_COLOR_MATRIX_RED_BIAS, Value(GL_POST_COLOR_MATRIX_RED_BIAS));
#endif
#if defined(GL_POST_COLOR_MATRIX_GREEN_BIAS)
	Gura_AssignValue(GL_POST_COLOR_MATRIX_GREEN_BIAS, Value(GL_POST_COLOR_MATRIX_GREEN_BIAS));
#endif
#if defined(GL_POST_COLOR_MATRIX_BLUE_BIAS)
	Gura_AssignValue(GL_POST_COLOR_MATRIX_BLUE_BIAS, Value(GL_POST_COLOR_MATRIX_BLUE_BIAS));
#endif
#if defined(GL_POST_COLOR_MATRIX_ALPHA_BIAS)
	Gura_AssignValue(GL_POST_COLOR_MATRIX_ALPHA_BIAS, Value(GL_POST_COLOR_MATRIX_ALPHA_BIAS));
#endif
#if defined(GL_COLOR_TABLE)
	Gura_AssignValue(GL_COLOR_TABLE, Value(GL_COLOR_TABLE));
#endif
#if defined(GL_POST_CONVOLUTION_COLOR_TABLE)
	Gura_AssignValue(GL_POST_CONVOLUTION_COLOR_TABLE, Value(GL_POST_CONVOLUTION_COLOR_TABLE));
#endif
#if defined(GL_POST_COLOR_MATRIX_COLOR_TABLE)
	Gura_AssignValue(GL_POST_COLOR_MATRIX_COLOR_TABLE, Value(GL_POST_COLOR_MATRIX_COLOR_TABLE));
#endif
#if defined(GL_PROXY_COLOR_TABLE)
	Gura_AssignValue(GL_PROXY_COLOR_TABLE, Value(GL_PROXY_COLOR_TABLE));
#endif
#if defined(GL_PROXY_POST_CONVOLUTION_COLOR_TABLE)
	Gura_AssignValue(GL_PROXY_POST_CONVOLUTION_COLOR_TABLE, Value(GL_PROXY_POST_CONVOLUTION_COLOR_TABLE));
#endif
#if defined(GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE)
	Gura_AssignValue(GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE, Value(GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE));
#endif
#if defined(GL_COLOR_TABLE_SCALE)
	Gura_AssignValue(GL_COLOR_TABLE_SCALE, Value(GL_COLOR_TABLE_SCALE));
#endif
#if defined(GL_COLOR_TABLE_BIAS)
	Gura_AssignValue(GL_COLOR_TABLE_BIAS, Value(GL_COLOR_TABLE_BIAS));
#endif
#if defined(GL_COLOR_TABLE_FORMAT)
	Gura_AssignValue(GL_COLOR_TABLE_FORMAT, Value(GL_COLOR_TABLE_FORMAT));
#endif
#if defined(GL_COLOR_TABLE_WIDTH)
	Gura_AssignValue(GL_COLOR_TABLE_WIDTH, Value(GL_COLOR_TABLE_WIDTH));
#endif
#if defined(GL_COLOR_TABLE_RED_SIZE)
	Gura_AssignValue(GL_COLOR_TABLE_RED_SIZE, Value(GL_COLOR_TABLE_RED_SIZE));
#endif
#if defined(GL_COLOR_TABLE_GREEN_SIZE)
	Gura_AssignValue(GL_COLOR_TABLE_GREEN_SIZE, Value(GL_COLOR_TABLE_GREEN_SIZE));
#endif
#if defined(GL_COLOR_TABLE_BLUE_SIZE)
	Gura_AssignValue(GL_COLOR_TABLE_BLUE_SIZE, Value(GL_COLOR_TABLE_BLUE_SIZE));
#endif
#if defined(GL_COLOR_TABLE_ALPHA_SIZE)
	Gura_AssignValue(GL_COLOR_TABLE_ALPHA_SIZE, Value(GL_COLOR_TABLE_ALPHA_SIZE));
#endif
#if defined(GL_COLOR_TABLE_LUMINANCE_SIZE)
	Gura_AssignValue(GL_COLOR_TABLE_LUMINANCE_SIZE, Value(GL_COLOR_TABLE_LUMINANCE_SIZE));
#endif
#if defined(GL_COLOR_TABLE_INTENSITY_SIZE)
	Gura_AssignValue(GL_COLOR_TABLE_INTENSITY_SIZE, Value(GL_COLOR_TABLE_INTENSITY_SIZE));
#endif
#if defined(GL_CONVOLUTION_1D)
	Gura_AssignValue(GL_CONVOLUTION_1D, Value(GL_CONVOLUTION_1D));
#endif
#if defined(GL_CONVOLUTION_2D)
	Gura_AssignValue(GL_CONVOLUTION_2D, Value(GL_CONVOLUTION_2D));
#endif
#if defined(GL_SEPARABLE_2D)
	Gura_AssignValue(GL_SEPARABLE_2D, Value(GL_SEPARABLE_2D));
#endif
#if defined(GL_CONVOLUTION_BORDER_MODE)
	Gura_AssignValue(GL_CONVOLUTION_BORDER_MODE, Value(GL_CONVOLUTION_BORDER_MODE));
#endif
#if defined(GL_CONVOLUTION_FILTER_SCALE)
	Gura_AssignValue(GL_CONVOLUTION_FILTER_SCALE, Value(GL_CONVOLUTION_FILTER_SCALE));
#endif
#if defined(GL_CONVOLUTION_FILTER_BIAS)
	Gura_AssignValue(GL_CONVOLUTION_FILTER_BIAS, Value(GL_CONVOLUTION_FILTER_BIAS));
#endif
#if defined(GL_REDUCE)
	Gura_AssignValue(GL_REDUCE, Value(GL_REDUCE));
#endif
#if defined(GL_CONVOLUTION_FORMAT)
	Gura_AssignValue(GL_CONVOLUTION_FORMAT, Value(GL_CONVOLUTION_FORMAT));
#endif
#if defined(GL_CONVOLUTION_WIDTH)
	Gura_AssignValue(GL_CONVOLUTION_WIDTH, Value(GL_CONVOLUTION_WIDTH));
#endif
#if defined(GL_CONVOLUTION_HEIGHT)
	Gura_AssignValue(GL_CONVOLUTION_HEIGHT, Value(GL_CONVOLUTION_HEIGHT));
#endif
#if defined(GL_MAX_CONVOLUTION_WIDTH)
	Gura_AssignValue(GL_MAX_CONVOLUTION_WIDTH, Value(GL_MAX_CONVOLUTION_WIDTH));
#endif
#if defined(GL_MAX_CONVOLUTION_HEIGHT)
	Gura_AssignValue(GL_MAX_CONVOLUTION_HEIGHT, Value(GL_MAX_CONVOLUTION_HEIGHT));
#endif
#if defined(GL_POST_CONVOLUTION_RED_SCALE)
	Gura_AssignValue(GL_POST_CONVOLUTION_RED_SCALE, Value(GL_POST_CONVOLUTION_RED_SCALE));
#endif
#if defined(GL_POST_CONVOLUTION_GREEN_SCALE)
	Gura_AssignValue(GL_POST_CONVOLUTION_GREEN_SCALE, Value(GL_POST_CONVOLUTION_GREEN_SCALE));
#endif
#if defined(GL_POST_CONVOLUTION_BLUE_SCALE)
	Gura_AssignValue(GL_POST_CONVOLUTION_BLUE_SCALE, Value(GL_POST_CONVOLUTION_BLUE_SCALE));
#endif
#if defined(GL_POST_CONVOLUTION_ALPHA_SCALE)
	Gura_AssignValue(GL_POST_CONVOLUTION_ALPHA_SCALE, Value(GL_POST_CONVOLUTION_ALPHA_SCALE));
#endif
#if defined(GL_POST_CONVOLUTION_RED_BIAS)
	Gura_AssignValue(GL_POST_CONVOLUTION_RED_BIAS, Value(GL_POST_CONVOLUTION_RED_BIAS));
#endif
#if defined(GL_POST_CONVOLUTION_GREEN_BIAS)
	Gura_AssignValue(GL_POST_CONVOLUTION_GREEN_BIAS, Value(GL_POST_CONVOLUTION_GREEN_BIAS));
#endif
#if defined(GL_POST_CONVOLUTION_BLUE_BIAS)
	Gura_AssignValue(GL_POST_CONVOLUTION_BLUE_BIAS, Value(GL_POST_CONVOLUTION_BLUE_BIAS));
#endif
#if defined(GL_POST_CONVOLUTION_ALPHA_BIAS)
	Gura_AssignValue(GL_POST_CONVOLUTION_ALPHA_BIAS, Value(GL_POST_CONVOLUTION_ALPHA_BIAS));
#endif
#if defined(GL_CONSTANT_BORDER)
	Gura_AssignValue(GL_CONSTANT_BORDER, Value(GL_CONSTANT_BORDER));
#endif
#if defined(GL_REPLICATE_BORDER)
	Gura_AssignValue(GL_REPLICATE_BORDER, Value(GL_REPLICATE_BORDER));
#endif
#if defined(GL_CONVOLUTION_BORDER_COLOR)
	Gura_AssignValue(GL_CONVOLUTION_BORDER_COLOR, Value(GL_CONVOLUTION_BORDER_COLOR));
#endif
#if defined(GL_MAX_ELEMENTS_VERTICES)
	Gura_AssignValue(GL_MAX_ELEMENTS_VERTICES, Value(GL_MAX_ELEMENTS_VERTICES));
#endif
#if defined(GL_MAX_ELEMENTS_INDICES)
	Gura_AssignValue(GL_MAX_ELEMENTS_INDICES, Value(GL_MAX_ELEMENTS_INDICES));
#endif
#if defined(GL_HISTOGRAM)
	Gura_AssignValue(GL_HISTOGRAM, Value(GL_HISTOGRAM));
#endif
#if defined(GL_PROXY_HISTOGRAM)
	Gura_AssignValue(GL_PROXY_HISTOGRAM, Value(GL_PROXY_HISTOGRAM));
#endif
#if defined(GL_HISTOGRAM_WIDTH)
	Gura_AssignValue(GL_HISTOGRAM_WIDTH, Value(GL_HISTOGRAM_WIDTH));
#endif
#if defined(GL_HISTOGRAM_FORMAT)
	Gura_AssignValue(GL_HISTOGRAM_FORMAT, Value(GL_HISTOGRAM_FORMAT));
#endif
#if defined(GL_HISTOGRAM_RED_SIZE)
	Gura_AssignValue(GL_HISTOGRAM_RED_SIZE, Value(GL_HISTOGRAM_RED_SIZE));
#endif
#if defined(GL_HISTOGRAM_GREEN_SIZE)
	Gura_AssignValue(GL_HISTOGRAM_GREEN_SIZE, Value(GL_HISTOGRAM_GREEN_SIZE));
#endif
#if defined(GL_HISTOGRAM_BLUE_SIZE)
	Gura_AssignValue(GL_HISTOGRAM_BLUE_SIZE, Value(GL_HISTOGRAM_BLUE_SIZE));
#endif
#if defined(GL_HISTOGRAM_ALPHA_SIZE)
	Gura_AssignValue(GL_HISTOGRAM_ALPHA_SIZE, Value(GL_HISTOGRAM_ALPHA_SIZE));
#endif
#if defined(GL_HISTOGRAM_LUMINANCE_SIZE)
	Gura_AssignValue(GL_HISTOGRAM_LUMINANCE_SIZE, Value(GL_HISTOGRAM_LUMINANCE_SIZE));
#endif
#if defined(GL_HISTOGRAM_SINK)
	Gura_AssignValue(GL_HISTOGRAM_SINK, Value(GL_HISTOGRAM_SINK));
#endif
#if defined(GL_MINMAX)
	Gura_AssignValue(GL_MINMAX, Value(GL_MINMAX));
#endif
#if defined(GL_MINMAX_FORMAT)
	Gura_AssignValue(GL_MINMAX_FORMAT, Value(GL_MINMAX_FORMAT));
#endif
#if defined(GL_MINMAX_SINK)
	Gura_AssignValue(GL_MINMAX_SINK, Value(GL_MINMAX_SINK));
#endif
#if defined(GL_TABLE_TOO_LARGE)
	Gura_AssignValue(GL_TABLE_TOO_LARGE, Value(GL_TABLE_TOO_LARGE));
#endif
#if defined(GL_UNSIGNED_BYTE_3_3_2)
	Gura_AssignValue(GL_UNSIGNED_BYTE_3_3_2, Value(GL_UNSIGNED_BYTE_3_3_2));
#endif
#if defined(GL_UNSIGNED_SHORT_4_4_4_4)
	Gura_AssignValue(GL_UNSIGNED_SHORT_4_4_4_4, Value(GL_UNSIGNED_SHORT_4_4_4_4));
#endif
#if defined(GL_UNSIGNED_SHORT_5_5_5_1)
	Gura_AssignValue(GL_UNSIGNED_SHORT_5_5_5_1, Value(GL_UNSIGNED_SHORT_5_5_5_1));
#endif
#if defined(GL_UNSIGNED_INT_8_8_8_8)
	Gura_AssignValue(GL_UNSIGNED_INT_8_8_8_8, Value(GL_UNSIGNED_INT_8_8_8_8));
#endif
#if defined(GL_UNSIGNED_INT_10_10_10_2)
	Gura_AssignValue(GL_UNSIGNED_INT_10_10_10_2, Value(GL_UNSIGNED_INT_10_10_10_2));
#endif
#if defined(GL_UNSIGNED_BYTE_2_3_3_REV)
	Gura_AssignValue(GL_UNSIGNED_BYTE_2_3_3_REV, Value(GL_UNSIGNED_BYTE_2_3_3_REV));
#endif
#if defined(GL_UNSIGNED_SHORT_5_6_5)
	Gura_AssignValue(GL_UNSIGNED_SHORT_5_6_5, Value(GL_UNSIGNED_SHORT_5_6_5));
#endif
#if defined(GL_UNSIGNED_SHORT_5_6_5_REV)
	Gura_AssignValue(GL_UNSIGNED_SHORT_5_6_5_REV, Value(GL_UNSIGNED_SHORT_5_6_5_REV));
#endif
#if defined(GL_UNSIGNED_SHORT_4_4_4_4_REV)
	Gura_AssignValue(GL_UNSIGNED_SHORT_4_4_4_4_REV, Value(GL_UNSIGNED_SHORT_4_4_4_4_REV));
#endif
#if defined(GL_UNSIGNED_SHORT_1_5_5_5_REV)
	Gura_AssignValue(GL_UNSIGNED_SHORT_1_5_5_5_REV, Value(GL_UNSIGNED_SHORT_1_5_5_5_REV));
#endif
#if defined(GL_UNSIGNED_INT_8_8_8_8_REV)
	Gura_AssignValue(GL_UNSIGNED_INT_8_8_8_8_REV, Value(GL_UNSIGNED_INT_8_8_8_8_REV));
#endif
#if defined(GL_UNSIGNED_INT_2_10_10_10_REV)
	Gura_AssignValue(GL_UNSIGNED_INT_2_10_10_10_REV, Value(GL_UNSIGNED_INT_2_10_10_10_REV));
#endif
#if defined(GL_RESCALE_NORMAL)
	Gura_AssignValue(GL_RESCALE_NORMAL, Value(GL_RESCALE_NORMAL));
#endif
#if defined(GL_LIGHT_MODEL_COLOR_CONTROL)
	Gura_AssignValue(GL_LIGHT_MODEL_COLOR_CONTROL, Value(GL_LIGHT_MODEL_COLOR_CONTROL));
#endif
#if defined(GL_SINGLE_COLOR)
	Gura_AssignValue(GL_SINGLE_COLOR, Value(GL_SINGLE_COLOR));
#endif
#if defined(GL_SEPARATE_SPECULAR_COLOR)
	Gura_AssignValue(GL_SEPARATE_SPECULAR_COLOR, Value(GL_SEPARATE_SPECULAR_COLOR));
#endif
#if defined(GL_PACK_SKIP_IMAGES)
	Gura_AssignValue(GL_PACK_SKIP_IMAGES, Value(GL_PACK_SKIP_IMAGES));
#endif
#if defined(GL_PACK_IMAGE_HEIGHT)
	Gura_AssignValue(GL_PACK_IMAGE_HEIGHT, Value(GL_PACK_IMAGE_HEIGHT));
#endif
#if defined(GL_UNPACK_SKIP_IMAGES)
	Gura_AssignValue(GL_UNPACK_SKIP_IMAGES, Value(GL_UNPACK_SKIP_IMAGES));
#endif
#if defined(GL_UNPACK_IMAGE_HEIGHT)
	Gura_AssignValue(GL_UNPACK_IMAGE_HEIGHT, Value(GL_UNPACK_IMAGE_HEIGHT));
#endif
#if defined(GL_TEXTURE_3D)
	Gura_AssignValue(GL_TEXTURE_3D, Value(GL_TEXTURE_3D));
#endif
#if defined(GL_PROXY_TEXTURE_3D)
	Gura_AssignValue(GL_PROXY_TEXTURE_3D, Value(GL_PROXY_TEXTURE_3D));
#endif
#if defined(GL_TEXTURE_DEPTH)
	Gura_AssignValue(GL_TEXTURE_DEPTH, Value(GL_TEXTURE_DEPTH));
#endif
#if defined(GL_TEXTURE_WRAP_R)
	Gura_AssignValue(GL_TEXTURE_WRAP_R, Value(GL_TEXTURE_WRAP_R));
#endif
#if defined(GL_MAX_3D_TEXTURE_SIZE)
	Gura_AssignValue(GL_MAX_3D_TEXTURE_SIZE, Value(GL_MAX_3D_TEXTURE_SIZE));
#endif
#if defined(GL_CLAMP_TO_EDGE)
	Gura_AssignValue(GL_CLAMP_TO_EDGE, Value(GL_CLAMP_TO_EDGE));
#endif
#if defined(GL_CLAMP_TO_BORDER)
	Gura_AssignValue(GL_CLAMP_TO_BORDER, Value(GL_CLAMP_TO_BORDER));
#endif
#if defined(GL_TEXTURE_MIN_LOD)
	Gura_AssignValue(GL_TEXTURE_MIN_LOD, Value(GL_TEXTURE_MIN_LOD));
#endif
#if defined(GL_TEXTURE_MAX_LOD)
	Gura_AssignValue(GL_TEXTURE_MAX_LOD, Value(GL_TEXTURE_MAX_LOD));
#endif
#if defined(GL_TEXTURE_BASE_LEVEL)
	Gura_AssignValue(GL_TEXTURE_BASE_LEVEL, Value(GL_TEXTURE_BASE_LEVEL));
#endif
#if defined(GL_TEXTURE_MAX_LEVEL)
	Gura_AssignValue(GL_TEXTURE_MAX_LEVEL, Value(GL_TEXTURE_MAX_LEVEL));
#endif
#if defined(GL_SMOOTH_POINT_SIZE_RANGE)
	Gura_AssignValue(GL_SMOOTH_POINT_SIZE_RANGE, Value(GL_SMOOTH_POINT_SIZE_RANGE));
#endif
#if defined(GL_SMOOTH_POINT_SIZE_GRANULARITY)
	Gura_AssignValue(GL_SMOOTH_POINT_SIZE_GRANULARITY, Value(GL_SMOOTH_POINT_SIZE_GRANULARITY));
#endif
#if defined(GL_SMOOTH_LINE_WIDTH_RANGE)
	Gura_AssignValue(GL_SMOOTH_LINE_WIDTH_RANGE, Value(GL_SMOOTH_LINE_WIDTH_RANGE));
#endif
#if defined(GL_SMOOTH_LINE_WIDTH_GRANULARITY)
	Gura_AssignValue(GL_SMOOTH_LINE_WIDTH_GRANULARITY, Value(GL_SMOOTH_LINE_WIDTH_GRANULARITY));
#endif
#if defined(GL_ALIASED_POINT_SIZE_RANGE)
	Gura_AssignValue(GL_ALIASED_POINT_SIZE_RANGE, Value(GL_ALIASED_POINT_SIZE_RANGE));
#endif
#if defined(GL_ALIASED_LINE_WIDTH_RANGE)
	Gura_AssignValue(GL_ALIASED_LINE_WIDTH_RANGE, Value(GL_ALIASED_LINE_WIDTH_RANGE));
#endif
#if defined(GL_TEXTURE0)
	Gura_AssignValue(GL_TEXTURE0, Value(GL_TEXTURE0));
#endif
#if defined(GL_TEXTURE1)
	Gura_AssignValue(GL_TEXTURE1, Value(GL_TEXTURE1));
#endif
#if defined(GL_TEXTURE2)
	Gura_AssignValue(GL_TEXTURE2, Value(GL_TEXTURE2));
#endif
#if defined(GL_TEXTURE3)
	Gura_AssignValue(GL_TEXTURE3, Value(GL_TEXTURE3));
#endif
#if defined(GL_TEXTURE4)
	Gura_AssignValue(GL_TEXTURE4, Value(GL_TEXTURE4));
#endif
#if defined(GL_TEXTURE5)
	Gura_AssignValue(GL_TEXTURE5, Value(GL_TEXTURE5));
#endif
#if defined(GL_TEXTURE6)
	Gura_AssignValue(GL_TEXTURE6, Value(GL_TEXTURE6));
#endif
#if defined(GL_TEXTURE7)
	Gura_AssignValue(GL_TEXTURE7, Value(GL_TEXTURE7));
#endif
#if defined(GL_TEXTURE8)
	Gura_AssignValue(GL_TEXTURE8, Value(GL_TEXTURE8));
#endif
#if defined(GL_TEXTURE9)
	Gura_AssignValue(GL_TEXTURE9, Value(GL_TEXTURE9));
#endif
#if defined(GL_TEXTURE10)
	Gura_AssignValue(GL_TEXTURE10, Value(GL_TEXTURE10));
#endif
#if defined(GL_TEXTURE11)
	Gura_AssignValue(GL_TEXTURE11, Value(GL_TEXTURE11));
#endif
#if defined(GL_TEXTURE12)
	Gura_AssignValue(GL_TEXTURE12, Value(GL_TEXTURE12));
#endif
#if defined(GL_TEXTURE13)
	Gura_AssignValue(GL_TEXTURE13, Value(GL_TEXTURE13));
#endif
#if defined(GL_TEXTURE14)
	Gura_AssignValue(GL_TEXTURE14, Value(GL_TEXTURE14));
#endif
#if defined(GL_TEXTURE15)
	Gura_AssignValue(GL_TEXTURE15, Value(GL_TEXTURE15));
#endif
#if defined(GL_TEXTURE16)
	Gura_AssignValue(GL_TEXTURE16, Value(GL_TEXTURE16));
#endif
#if defined(GL_TEXTURE17)
	Gura_AssignValue(GL_TEXTURE17, Value(GL_TEXTURE17));
#endif
#if defined(GL_TEXTURE18)
	Gura_AssignValue(GL_TEXTURE18, Value(GL_TEXTURE18));
#endif
#if defined(GL_TEXTURE19)
	Gura_AssignValue(GL_TEXTURE19, Value(GL_TEXTURE19));
#endif
#if defined(GL_TEXTURE20)
	Gura_AssignValue(GL_TEXTURE20, Value(GL_TEXTURE20));
#endif
#if defined(GL_TEXTURE21)
	Gura_AssignValue(GL_TEXTURE21, Value(GL_TEXTURE21));
#endif
#if defined(GL_TEXTURE22)
	Gura_AssignValue(GL_TEXTURE22, Value(GL_TEXTURE22));
#endif
#if defined(GL_TEXTURE23)
	Gura_AssignValue(GL_TEXTURE23, Value(GL_TEXTURE23));
#endif
#if defined(GL_TEXTURE24)
	Gura_AssignValue(GL_TEXTURE24, Value(GL_TEXTURE24));
#endif
#if defined(GL_TEXTURE25)
	Gura_AssignValue(GL_TEXTURE25, Value(GL_TEXTURE25));
#endif
#if defined(GL_TEXTURE26)
	Gura_AssignValue(GL_TEXTURE26, Value(GL_TEXTURE26));
#endif
#if defined(GL_TEXTURE27)
	Gura_AssignValue(GL_TEXTURE27, Value(GL_TEXTURE27));
#endif
#if defined(GL_TEXTURE28)
	Gura_AssignValue(GL_TEXTURE28, Value(GL_TEXTURE28));
#endif
#if defined(GL_TEXTURE29)
	Gura_AssignValue(GL_TEXTURE29, Value(GL_TEXTURE29));
#endif
#if defined(GL_TEXTURE30)
	Gura_AssignValue(GL_TEXTURE30, Value(GL_TEXTURE30));
#endif
#if defined(GL_TEXTURE31)
	Gura_AssignValue(GL_TEXTURE31, Value(GL_TEXTURE31));
#endif
#if defined(GL_ACTIVE_TEXTURE)
	Gura_AssignValue(GL_ACTIVE_TEXTURE, Value(GL_ACTIVE_TEXTURE));
#endif
#if defined(GL_CLIENT_ACTIVE_TEXTURE)
	Gura_AssignValue(GL_CLIENT_ACTIVE_TEXTURE, Value(GL_CLIENT_ACTIVE_TEXTURE));
#endif
#if defined(GL_MAX_TEXTURE_UNITS)
	Gura_AssignValue(GL_MAX_TEXTURE_UNITS, Value(GL_MAX_TEXTURE_UNITS));
#endif
#if defined(GL_COMBINE)
	Gura_AssignValue(GL_COMBINE, Value(GL_COMBINE));
#endif
#if defined(GL_COMBINE_RGB)
	Gura_AssignValue(GL_COMBINE_RGB, Value(GL_COMBINE_RGB));
#endif
#if defined(GL_COMBINE_ALPHA)
	Gura_AssignValue(GL_COMBINE_ALPHA, Value(GL_COMBINE_ALPHA));
#endif
#if defined(GL_RGB_SCALE)
	Gura_AssignValue(GL_RGB_SCALE, Value(GL_RGB_SCALE));
#endif
#if defined(GL_ADD_SIGNED)
	Gura_AssignValue(GL_ADD_SIGNED, Value(GL_ADD_SIGNED));
#endif
#if defined(GL_INTERPOLATE)
	Gura_AssignValue(GL_INTERPOLATE, Value(GL_INTERPOLATE));
#endif
#if defined(GL_CONSTANT)
	Gura_AssignValue(GL_CONSTANT, Value(GL_CONSTANT));
#endif
#if defined(GL_PRIMARY_COLOR)
	Gura_AssignValue(GL_PRIMARY_COLOR, Value(GL_PRIMARY_COLOR));
#endif
#if defined(GL_PREVIOUS)
	Gura_AssignValue(GL_PREVIOUS, Value(GL_PREVIOUS));
#endif
#if defined(GL_SUBTRACT)
	Gura_AssignValue(GL_SUBTRACT, Value(GL_SUBTRACT));
#endif
#if defined(GL_SRC0_RGB)
	Gura_AssignValue(GL_SRC0_RGB, Value(GL_SRC0_RGB));
#endif
#if defined(GL_SRC1_RGB)
	Gura_AssignValue(GL_SRC1_RGB, Value(GL_SRC1_RGB));
#endif
#if defined(GL_SRC2_RGB)
	Gura_AssignValue(GL_SRC2_RGB, Value(GL_SRC2_RGB));
#endif
#if defined(GL_SRC0_ALPHA)
	Gura_AssignValue(GL_SRC0_ALPHA, Value(GL_SRC0_ALPHA));
#endif
#if defined(GL_SRC1_ALPHA)
	Gura_AssignValue(GL_SRC1_ALPHA, Value(GL_SRC1_ALPHA));
#endif
#if defined(GL_SRC2_ALPHA)
	Gura_AssignValue(GL_SRC2_ALPHA, Value(GL_SRC2_ALPHA));
#endif
#if defined(GL_SOURCE0_RGB)
	Gura_AssignValue(GL_SOURCE0_RGB, Value(GL_SOURCE0_RGB));
#endif
#if defined(GL_SOURCE1_RGB)
	Gura_AssignValue(GL_SOURCE1_RGB, Value(GL_SOURCE1_RGB));
#endif
#if defined(GL_SOURCE2_RGB)
	Gura_AssignValue(GL_SOURCE2_RGB, Value(GL_SOURCE2_RGB));
#endif
#if defined(GL_SOURCE0_ALPHA)
	Gura_AssignValue(GL_SOURCE0_ALPHA, Value(GL_SOURCE0_ALPHA));
#endif
#if defined(GL_SOURCE1_ALPHA)
	Gura_AssignValue(GL_SOURCE1_ALPHA, Value(GL_SOURCE1_ALPHA));
#endif
#if defined(GL_SOURCE2_ALPHA)
	Gura_AssignValue(GL_SOURCE2_ALPHA, Value(GL_SOURCE2_ALPHA));
#endif
#if defined(GL_OPERAND0_RGB)
	Gura_AssignValue(GL_OPERAND0_RGB, Value(GL_OPERAND0_RGB));
#endif
#if defined(GL_OPERAND1_RGB)
	Gura_AssignValue(GL_OPERAND1_RGB, Value(GL_OPERAND1_RGB));
#endif
#if defined(GL_OPERAND2_RGB)
	Gura_AssignValue(GL_OPERAND2_RGB, Value(GL_OPERAND2_RGB));
#endif
#if defined(GL_OPERAND0_ALPHA)
	Gura_AssignValue(GL_OPERAND0_ALPHA, Value(GL_OPERAND0_ALPHA));
#endif
#if defined(GL_OPERAND1_ALPHA)
	Gura_AssignValue(GL_OPERAND1_ALPHA, Value(GL_OPERAND1_ALPHA));
#endif
#if defined(GL_OPERAND2_ALPHA)
	Gura_AssignValue(GL_OPERAND2_ALPHA, Value(GL_OPERAND2_ALPHA));
#endif
#if defined(GL_DOT3_RGB)
	Gura_AssignValue(GL_DOT3_RGB, Value(GL_DOT3_RGB));
#endif
#if defined(GL_DOT3_RGBA)
	Gura_AssignValue(GL_DOT3_RGBA, Value(GL_DOT3_RGBA));
#endif
#if defined(GL_TRANSPOSE_MODELVIEW_MATRIX)
	Gura_AssignValue(GL_TRANSPOSE_MODELVIEW_MATRIX, Value(GL_TRANSPOSE_MODELVIEW_MATRIX));
#endif
#if defined(GL_TRANSPOSE_PROJECTION_MATRIX)
	Gura_AssignValue(GL_TRANSPOSE_PROJECTION_MATRIX, Value(GL_TRANSPOSE_PROJECTION_MATRIX));
#endif
#if defined(GL_TRANSPOSE_TEXTURE_MATRIX)
	Gura_AssignValue(GL_TRANSPOSE_TEXTURE_MATRIX, Value(GL_TRANSPOSE_TEXTURE_MATRIX));
#endif
#if defined(GL_TRANSPOSE_COLOR_MATRIX)
	Gura_AssignValue(GL_TRANSPOSE_COLOR_MATRIX, Value(GL_TRANSPOSE_COLOR_MATRIX));
#endif
#if defined(GL_NORMAL_MAP)
	Gura_AssignValue(GL_NORMAL_MAP, Value(GL_NORMAL_MAP));
#endif
#if defined(GL_REFLECTION_MAP)
	Gura_AssignValue(GL_REFLECTION_MAP, Value(GL_REFLECTION_MAP));
#endif
#if defined(GL_TEXTURE_CUBE_MAP)
	Gura_AssignValue(GL_TEXTURE_CUBE_MAP, Value(GL_TEXTURE_CUBE_MAP));
#endif
#if defined(GL_TEXTURE_BINDING_CUBE_MAP)
	Gura_AssignValue(GL_TEXTURE_BINDING_CUBE_MAP, Value(GL_TEXTURE_BINDING_CUBE_MAP));
#endif
#if defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
	Gura_AssignValue(GL_TEXTURE_CUBE_MAP_POSITIVE_X, Value(GL_TEXTURE_CUBE_MAP_POSITIVE_X));
#endif
#if defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
	Gura_AssignValue(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, Value(GL_TEXTURE_CUBE_MAP_NEGATIVE_X));
#endif
#if defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
	Gura_AssignValue(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, Value(GL_TEXTURE_CUBE_MAP_POSITIVE_Y));
#endif
#if defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
	Gura_AssignValue(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, Value(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y));
#endif
#if defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
	Gura_AssignValue(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, Value(GL_TEXTURE_CUBE_MAP_POSITIVE_Z));
#endif
#if defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
	Gura_AssignValue(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, Value(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z));
#endif
#if defined(GL_PROXY_TEXTURE_CUBE_MAP)
	Gura_AssignValue(GL_PROXY_TEXTURE_CUBE_MAP, Value(GL_PROXY_TEXTURE_CUBE_MAP));
#endif
#if defined(GL_MAX_CUBE_MAP_TEXTURE_SIZE)
	Gura_AssignValue(GL_MAX_CUBE_MAP_TEXTURE_SIZE, Value(GL_MAX_CUBE_MAP_TEXTURE_SIZE));
#endif
#if defined(GL_COMPRESSED_ALPHA)
	Gura_AssignValue(GL_COMPRESSED_ALPHA, Value(GL_COMPRESSED_ALPHA));
#endif
#if defined(GL_COMPRESSED_LUMINANCE)
	Gura_AssignValue(GL_COMPRESSED_LUMINANCE, Value(GL_COMPRESSED_LUMINANCE));
#endif
#if defined(GL_COMPRESSED_LUMINANCE_ALPHA)
	Gura_AssignValue(GL_COMPRESSED_LUMINANCE_ALPHA, Value(GL_COMPRESSED_LUMINANCE_ALPHA));
#endif
#if defined(GL_COMPRESSED_INTENSITY)
	Gura_AssignValue(GL_COMPRESSED_INTENSITY, Value(GL_COMPRESSED_INTENSITY));
#endif
#if defined(GL_COMPRESSED_RGB)
	Gura_AssignValue(GL_COMPRESSED_RGB, Value(GL_COMPRESSED_RGB));
#endif
#if defined(GL_COMPRESSED_RGBA)
	Gura_AssignValue(GL_COMPRESSED_RGBA, Value(GL_COMPRESSED_RGBA));
#endif
#if defined(GL_TEXTURE_COMPRESSION_HINT)
	Gura_AssignValue(GL_TEXTURE_COMPRESSION_HINT, Value(GL_TEXTURE_COMPRESSION_HINT));
#endif
#if defined(GL_TEXTURE_COMPRESSED_IMAGE_SIZE)
	Gura_AssignValue(GL_TEXTURE_COMPRESSED_IMAGE_SIZE, Value(GL_TEXTURE_COMPRESSED_IMAGE_SIZE));
#endif
#if defined(GL_TEXTURE_COMPRESSED)
	Gura_AssignValue(GL_TEXTURE_COMPRESSED, Value(GL_TEXTURE_COMPRESSED));
#endif
#if defined(GL_NUM_COMPRESSED_TEXTURE_FORMATS)
	Gura_AssignValue(GL_NUM_COMPRESSED_TEXTURE_FORMATS, Value(GL_NUM_COMPRESSED_TEXTURE_FORMATS));
#endif
#if defined(GL_COMPRESSED_TEXTURE_FORMATS)
	Gura_AssignValue(GL_COMPRESSED_TEXTURE_FORMATS, Value(GL_COMPRESSED_TEXTURE_FORMATS));
#endif
#if defined(GL_MULTISAMPLE)
	Gura_AssignValue(GL_MULTISAMPLE, Value(GL_MULTISAMPLE));
#endif
#if defined(GL_SAMPLE_ALPHA_TO_COVERAGE)
	Gura_AssignValue(GL_SAMPLE_ALPHA_TO_COVERAGE, Value(GL_SAMPLE_ALPHA_TO_COVERAGE));
#endif
#if defined(GL_SAMPLE_ALPHA_TO_ONE)
	Gura_AssignValue(GL_SAMPLE_ALPHA_TO_ONE, Value(GL_SAMPLE_ALPHA_TO_ONE));
#endif
#if defined(GL_SAMPLE_COVERAGE)
	Gura_AssignValue(GL_SAMPLE_COVERAGE, Value(GL_SAMPLE_COVERAGE));
#endif
#if defined(GL_SAMPLE_BUFFERS)
	Gura_AssignValue(GL_SAMPLE_BUFFERS, Value(GL_SAMPLE_BUFFERS));
#endif
#if defined(GL_SAMPLES)
	Gura_AssignValue(GL_SAMPLES, Value(GL_SAMPLES));
#endif
#if defined(GL_SAMPLE_COVERAGE_VALUE)
	Gura_AssignValue(GL_SAMPLE_COVERAGE_VALUE, Value(GL_SAMPLE_COVERAGE_VALUE));
#endif
#if defined(GL_SAMPLE_COVERAGE_INVERT)
	Gura_AssignValue(GL_SAMPLE_COVERAGE_INVERT, Value(GL_SAMPLE_COVERAGE_INVERT));
#endif
#if defined(GL_MULTISAMPLE_BIT)
	Gura_AssignValue(GL_MULTISAMPLE_BIT, Value(GL_MULTISAMPLE_BIT));
#endif
#if defined(GL_DEPTH_COMPONENT16)
	Gura_AssignValue(GL_DEPTH_COMPONENT16, Value(GL_DEPTH_COMPONENT16));
#endif
#if defined(GL_DEPTH_COMPONENT24)
	Gura_AssignValue(GL_DEPTH_COMPONENT24, Value(GL_DEPTH_COMPONENT24));
#endif
#if defined(GL_DEPTH_COMPONENT32)
	Gura_AssignValue(GL_DEPTH_COMPONENT32, Value(GL_DEPTH_COMPONENT32));
#endif
#if defined(GL_TEXTURE_DEPTH_SIZE)
	Gura_AssignValue(GL_TEXTURE_DEPTH_SIZE, Value(GL_TEXTURE_DEPTH_SIZE));
#endif
#if defined(GL_DEPTH_TEXTURE_MODE)
	Gura_AssignValue(GL_DEPTH_TEXTURE_MODE, Value(GL_DEPTH_TEXTURE_MODE));
#endif
#if defined(GL_TEXTURE_COMPARE_MODE)
	Gura_AssignValue(GL_TEXTURE_COMPARE_MODE, Value(GL_TEXTURE_COMPARE_MODE));
#endif
#if defined(GL_TEXTURE_COMPARE_FUNC)
	Gura_AssignValue(GL_TEXTURE_COMPARE_FUNC, Value(GL_TEXTURE_COMPARE_FUNC));
#endif
#if defined(GL_COMPARE_R_TO_TEXTURE)
	Gura_AssignValue(GL_COMPARE_R_TO_TEXTURE, Value(GL_COMPARE_R_TO_TEXTURE));
#endif
#if defined(GL_QUERY_COUNTER_BITS)
	Gura_AssignValue(GL_QUERY_COUNTER_BITS, Value(GL_QUERY_COUNTER_BITS));
#endif
#if defined(GL_CURRENT_QUERY)
	Gura_AssignValue(GL_CURRENT_QUERY, Value(GL_CURRENT_QUERY));
#endif
#if defined(GL_QUERY_RESULT)
	Gura_AssignValue(GL_QUERY_RESULT, Value(GL_QUERY_RESULT));
#endif
#if defined(GL_QUERY_RESULT_AVAILABLE)
	Gura_AssignValue(GL_QUERY_RESULT_AVAILABLE, Value(GL_QUERY_RESULT_AVAILABLE));
#endif
#if defined(GL_SAMPLES_PASSED)
	Gura_AssignValue(GL_SAMPLES_PASSED, Value(GL_SAMPLES_PASSED));
#endif
#if defined(GL_FOG_COORD_SRC)
	Gura_AssignValue(GL_FOG_COORD_SRC, Value(GL_FOG_COORD_SRC));
#endif
#if defined(GL_FOG_COORD)
	Gura_AssignValue(GL_FOG_COORD, Value(GL_FOG_COORD));
#endif
#if defined(GL_FRAGMENT_DEPTH)
	Gura_AssignValue(GL_FRAGMENT_DEPTH, Value(GL_FRAGMENT_DEPTH));
#endif
#if defined(GL_CURRENT_FOG_COORD)
	Gura_AssignValue(GL_CURRENT_FOG_COORD, Value(GL_CURRENT_FOG_COORD));
#endif
#if defined(GL_FOG_COORD_ARRAY_TYPE)
	Gura_AssignValue(GL_FOG_COORD_ARRAY_TYPE, Value(GL_FOG_COORD_ARRAY_TYPE));
#endif
#if defined(GL_FOG_COORD_ARRAY_STRIDE)
	Gura_AssignValue(GL_FOG_COORD_ARRAY_STRIDE, Value(GL_FOG_COORD_ARRAY_STRIDE));
#endif
#if defined(GL_FOG_COORD_ARRAY_POINTER)
	Gura_AssignValue(GL_FOG_COORD_ARRAY_POINTER, Value(GL_FOG_COORD_ARRAY_POINTER));
#endif
#if defined(GL_FOG_COORD_ARRAY)
	Gura_AssignValue(GL_FOG_COORD_ARRAY, Value(GL_FOG_COORD_ARRAY));
#endif
#if defined(GL_FOG_COORDINATE_SOURCE)
	Gura_AssignValue(GL_FOG_COORDINATE_SOURCE, Value(GL_FOG_COORDINATE_SOURCE));
#endif
#if defined(GL_FOG_COORDINATE)
	Gura_AssignValue(GL_FOG_COORDINATE, Value(GL_FOG_COORDINATE));
#endif
#if defined(GL_CURRENT_FOG_COORDINATE)
	Gura_AssignValue(GL_CURRENT_FOG_COORDINATE, Value(GL_CURRENT_FOG_COORDINATE));
#endif
#if defined(GL_FOG_COORDINATE_ARRAY_TYPE)
	Gura_AssignValue(GL_FOG_COORDINATE_ARRAY_TYPE, Value(GL_FOG_COORDINATE_ARRAY_TYPE));
#endif
#if defined(GL_FOG_COORDINATE_ARRAY_STRIDE)
	Gura_AssignValue(GL_FOG_COORDINATE_ARRAY_STRIDE, Value(GL_FOG_COORDINATE_ARRAY_STRIDE));
#endif
#if defined(GL_FOG_COORDINATE_ARRAY_POINTER)
	Gura_AssignValue(GL_FOG_COORDINATE_ARRAY_POINTER, Value(GL_FOG_COORDINATE_ARRAY_POINTER));
#endif
#if defined(GL_FOG_COORDINATE_ARRAY)
	Gura_AssignValue(GL_FOG_COORDINATE_ARRAY, Value(GL_FOG_COORDINATE_ARRAY));
#endif
#if defined(GL_COLOR_SUM)
	Gura_AssignValue(GL_COLOR_SUM, Value(GL_COLOR_SUM));
#endif
#if defined(GL_CURRENT_SECONDARY_COLOR)
	Gura_AssignValue(GL_CURRENT_SECONDARY_COLOR, Value(GL_CURRENT_SECONDARY_COLOR));
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY_SIZE)
	Gura_AssignValue(GL_SECONDARY_COLOR_ARRAY_SIZE, Value(GL_SECONDARY_COLOR_ARRAY_SIZE));
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY_TYPE)
	Gura_AssignValue(GL_SECONDARY_COLOR_ARRAY_TYPE, Value(GL_SECONDARY_COLOR_ARRAY_TYPE));
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY_STRIDE)
	Gura_AssignValue(GL_SECONDARY_COLOR_ARRAY_STRIDE, Value(GL_SECONDARY_COLOR_ARRAY_STRIDE));
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY_POINTER)
	Gura_AssignValue(GL_SECONDARY_COLOR_ARRAY_POINTER, Value(GL_SECONDARY_COLOR_ARRAY_POINTER));
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY)
	Gura_AssignValue(GL_SECONDARY_COLOR_ARRAY, Value(GL_SECONDARY_COLOR_ARRAY));
#endif
#if defined(GL_POINT_SIZE_MIN)
	Gura_AssignValue(GL_POINT_SIZE_MIN, Value(GL_POINT_SIZE_MIN));
#endif
#if defined(GL_POINT_SIZE_MAX)
	Gura_AssignValue(GL_POINT_SIZE_MAX, Value(GL_POINT_SIZE_MAX));
#endif
#if defined(GL_POINT_FADE_THRESHOLD_SIZE)
	Gura_AssignValue(GL_POINT_FADE_THRESHOLD_SIZE, Value(GL_POINT_FADE_THRESHOLD_SIZE));
#endif
#if defined(GL_POINT_DISTANCE_ATTENUATION)
	Gura_AssignValue(GL_POINT_DISTANCE_ATTENUATION, Value(GL_POINT_DISTANCE_ATTENUATION));
#endif
#if defined(GL_BLEND_DST_RGB)
	Gura_AssignValue(GL_BLEND_DST_RGB, Value(GL_BLEND_DST_RGB));
#endif
#if defined(GL_BLEND_SRC_RGB)
	Gura_AssignValue(GL_BLEND_SRC_RGB, Value(GL_BLEND_SRC_RGB));
#endif
#if defined(GL_BLEND_DST_ALPHA)
	Gura_AssignValue(GL_BLEND_DST_ALPHA, Value(GL_BLEND_DST_ALPHA));
#endif
#if defined(GL_BLEND_SRC_ALPHA)
	Gura_AssignValue(GL_BLEND_SRC_ALPHA, Value(GL_BLEND_SRC_ALPHA));
#endif
#if defined(GL_GENERATE_MIPMAP)
	Gura_AssignValue(GL_GENERATE_MIPMAP, Value(GL_GENERATE_MIPMAP));
#endif
#if defined(GL_GENERATE_MIPMAP_HINT)
	Gura_AssignValue(GL_GENERATE_MIPMAP_HINT, Value(GL_GENERATE_MIPMAP_HINT));
#endif
#if defined(GL_INCR_WRAP)
	Gura_AssignValue(GL_INCR_WRAP, Value(GL_INCR_WRAP));
#endif
#if defined(GL_DECR_WRAP)
	Gura_AssignValue(GL_DECR_WRAP, Value(GL_DECR_WRAP));
#endif
#if defined(GL_MIRRORED_REPEAT)
	Gura_AssignValue(GL_MIRRORED_REPEAT, Value(GL_MIRRORED_REPEAT));
#endif
#if defined(GL_MAX_TEXTURE_LOD_BIAS)
	Gura_AssignValue(GL_MAX_TEXTURE_LOD_BIAS, Value(GL_MAX_TEXTURE_LOD_BIAS));
#endif
#if defined(GL_TEXTURE_FILTER_CONTROL)
	Gura_AssignValue(GL_TEXTURE_FILTER_CONTROL, Value(GL_TEXTURE_FILTER_CONTROL));
#endif
#if defined(GL_TEXTURE_LOD_BIAS)
	Gura_AssignValue(GL_TEXTURE_LOD_BIAS, Value(GL_TEXTURE_LOD_BIAS));
#endif
#if defined(GL_ARRAY_BUFFER)
	Gura_AssignValue(GL_ARRAY_BUFFER, Value(GL_ARRAY_BUFFER));
#endif
#if defined(GL_ELEMENT_ARRAY_BUFFER)
	Gura_AssignValue(GL_ELEMENT_ARRAY_BUFFER, Value(GL_ELEMENT_ARRAY_BUFFER));
#endif
#if defined(GL_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_ARRAY_BUFFER_BINDING, Value(GL_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_ELEMENT_ARRAY_BUFFER_BINDING, Value(GL_ELEMENT_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_VERTEX_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_VERTEX_ARRAY_BUFFER_BINDING, Value(GL_VERTEX_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_NORMAL_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_NORMAL_ARRAY_BUFFER_BINDING, Value(GL_NORMAL_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_COLOR_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_COLOR_ARRAY_BUFFER_BINDING, Value(GL_COLOR_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_INDEX_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_INDEX_ARRAY_BUFFER_BINDING, Value(GL_INDEX_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING, Value(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING, Value(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING, Value(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_FOG_COORD_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_FOG_COORD_ARRAY_BUFFER_BINDING, Value(GL_FOG_COORD_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_WEIGHT_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_WEIGHT_ARRAY_BUFFER_BINDING, Value(GL_WEIGHT_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, Value(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_STREAM_DRAW)
	Gura_AssignValue(GL_STREAM_DRAW, Value(GL_STREAM_DRAW));
#endif
#if defined(GL_STREAM_READ)
	Gura_AssignValue(GL_STREAM_READ, Value(GL_STREAM_READ));
#endif
#if defined(GL_STREAM_COPY)
	Gura_AssignValue(GL_STREAM_COPY, Value(GL_STREAM_COPY));
#endif
#if defined(GL_STATIC_DRAW)
	Gura_AssignValue(GL_STATIC_DRAW, Value(GL_STATIC_DRAW));
#endif
#if defined(GL_STATIC_READ)
	Gura_AssignValue(GL_STATIC_READ, Value(GL_STATIC_READ));
#endif
#if defined(GL_STATIC_COPY)
	Gura_AssignValue(GL_STATIC_COPY, Value(GL_STATIC_COPY));
#endif
#if defined(GL_DYNAMIC_DRAW)
	Gura_AssignValue(GL_DYNAMIC_DRAW, Value(GL_DYNAMIC_DRAW));
#endif
#if defined(GL_DYNAMIC_READ)
	Gura_AssignValue(GL_DYNAMIC_READ, Value(GL_DYNAMIC_READ));
#endif
#if defined(GL_DYNAMIC_COPY)
	Gura_AssignValue(GL_DYNAMIC_COPY, Value(GL_DYNAMIC_COPY));
#endif
#if defined(GL_READ_ONLY)
	Gura_AssignValue(GL_READ_ONLY, Value(GL_READ_ONLY));
#endif
#if defined(GL_WRITE_ONLY)
	Gura_AssignValue(GL_WRITE_ONLY, Value(GL_WRITE_ONLY));
#endif
#if defined(GL_READ_WRITE)
	Gura_AssignValue(GL_READ_WRITE, Value(GL_READ_WRITE));
#endif
#if defined(GL_BUFFER_SIZE)
	Gura_AssignValue(GL_BUFFER_SIZE, Value(GL_BUFFER_SIZE));
#endif
#if defined(GL_BUFFER_USAGE)
	Gura_AssignValue(GL_BUFFER_USAGE, Value(GL_BUFFER_USAGE));
#endif
#if defined(GL_BUFFER_ACCESS)
	Gura_AssignValue(GL_BUFFER_ACCESS, Value(GL_BUFFER_ACCESS));
#endif
#if defined(GL_BUFFER_MAPPED)
	Gura_AssignValue(GL_BUFFER_MAPPED, Value(GL_BUFFER_MAPPED));
#endif
#if defined(GL_BUFFER_MAP_POINTER)
	Gura_AssignValue(GL_BUFFER_MAP_POINTER, Value(GL_BUFFER_MAP_POINTER));
#endif
#if defined(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING)
	Gura_AssignValue(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING, Value(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING));
#endif
#if defined(GL_CURRENT_PROGRAM)
	Gura_AssignValue(GL_CURRENT_PROGRAM, Value(GL_CURRENT_PROGRAM));
#endif
#if defined(GL_SHADER_TYPE)
	Gura_AssignValue(GL_SHADER_TYPE, Value(GL_SHADER_TYPE));
#endif
#if defined(GL_DELETE_STATUS)
	Gura_AssignValue(GL_DELETE_STATUS, Value(GL_DELETE_STATUS));
#endif
#if defined(GL_COMPILE_STATUS)
	Gura_AssignValue(GL_COMPILE_STATUS, Value(GL_COMPILE_STATUS));
#endif
#if defined(GL_LINK_STATUS)
	Gura_AssignValue(GL_LINK_STATUS, Value(GL_LINK_STATUS));
#endif
#if defined(GL_VALIDATE_STATUS)
	Gura_AssignValue(GL_VALIDATE_STATUS, Value(GL_VALIDATE_STATUS));
#endif
#if defined(GL_INFO_LOG_LENGTH)
	Gura_AssignValue(GL_INFO_LOG_LENGTH, Value(GL_INFO_LOG_LENGTH));
#endif
#if defined(GL_ATTACHED_SHADERS)
	Gura_AssignValue(GL_ATTACHED_SHADERS, Value(GL_ATTACHED_SHADERS));
#endif
#if defined(GL_ACTIVE_UNIFORMS)
	Gura_AssignValue(GL_ACTIVE_UNIFORMS, Value(GL_ACTIVE_UNIFORMS));
#endif
#if defined(GL_ACTIVE_UNIFORM_MAX_LENGTH)
	Gura_AssignValue(GL_ACTIVE_UNIFORM_MAX_LENGTH, Value(GL_ACTIVE_UNIFORM_MAX_LENGTH));
#endif
#if defined(GL_SHADER_SOURCE_LENGTH)
	Gura_AssignValue(GL_SHADER_SOURCE_LENGTH, Value(GL_SHADER_SOURCE_LENGTH));
#endif
#if defined(GL_FLOAT_VEC2)
	Gura_AssignValue(GL_FLOAT_VEC2, Value(GL_FLOAT_VEC2));
#endif
#if defined(GL_FLOAT_VEC3)
	Gura_AssignValue(GL_FLOAT_VEC3, Value(GL_FLOAT_VEC3));
#endif
#if defined(GL_FLOAT_VEC4)
	Gura_AssignValue(GL_FLOAT_VEC4, Value(GL_FLOAT_VEC4));
#endif
#if defined(GL_INT_VEC2)
	Gura_AssignValue(GL_INT_VEC2, Value(GL_INT_VEC2));
#endif
#if defined(GL_INT_VEC3)
	Gura_AssignValue(GL_INT_VEC3, Value(GL_INT_VEC3));
#endif
#if defined(GL_INT_VEC4)
	Gura_AssignValue(GL_INT_VEC4, Value(GL_INT_VEC4));
#endif
#if defined(GL_BOOL)
	Gura_AssignValue(GL_BOOL, Value(GL_BOOL));
#endif
#if defined(GL_BOOL_VEC2)
	Gura_AssignValue(GL_BOOL_VEC2, Value(GL_BOOL_VEC2));
#endif
#if defined(GL_BOOL_VEC3)
	Gura_AssignValue(GL_BOOL_VEC3, Value(GL_BOOL_VEC3));
#endif
#if defined(GL_BOOL_VEC4)
	Gura_AssignValue(GL_BOOL_VEC4, Value(GL_BOOL_VEC4));
#endif
#if defined(GL_FLOAT_MAT2)
	Gura_AssignValue(GL_FLOAT_MAT2, Value(GL_FLOAT_MAT2));
#endif
#if defined(GL_FLOAT_MAT3)
	Gura_AssignValue(GL_FLOAT_MAT3, Value(GL_FLOAT_MAT3));
#endif
#if defined(GL_FLOAT_MAT4)
	Gura_AssignValue(GL_FLOAT_MAT4, Value(GL_FLOAT_MAT4));
#endif
#if defined(GL_SAMPLER_1D)
	Gura_AssignValue(GL_SAMPLER_1D, Value(GL_SAMPLER_1D));
#endif
#if defined(GL_SAMPLER_2D)
	Gura_AssignValue(GL_SAMPLER_2D, Value(GL_SAMPLER_2D));
#endif
#if defined(GL_SAMPLER_3D)
	Gura_AssignValue(GL_SAMPLER_3D, Value(GL_SAMPLER_3D));
#endif
#if defined(GL_SAMPLER_CUBE)
	Gura_AssignValue(GL_SAMPLER_CUBE, Value(GL_SAMPLER_CUBE));
#endif
#if defined(GL_SAMPLER_1D_SHADOW)
	Gura_AssignValue(GL_SAMPLER_1D_SHADOW, Value(GL_SAMPLER_1D_SHADOW));
#endif
#if defined(GL_SAMPLER_2D_SHADOW)
	Gura_AssignValue(GL_SAMPLER_2D_SHADOW, Value(GL_SAMPLER_2D_SHADOW));
#endif
#if defined(GL_SHADING_LANGUAGE_VERSION)
	Gura_AssignValue(GL_SHADING_LANGUAGE_VERSION, Value(GL_SHADING_LANGUAGE_VERSION));
#endif
#if defined(GL_VERTEX_SHADER)
	Gura_AssignValue(GL_VERTEX_SHADER, Value(GL_VERTEX_SHADER));
#endif
#if defined(GL_MAX_VERTEX_UNIFORM_COMPONENTS)
	Gura_AssignValue(GL_MAX_VERTEX_UNIFORM_COMPONENTS, Value(GL_MAX_VERTEX_UNIFORM_COMPONENTS));
#endif
#if defined(GL_MAX_VARYING_FLOATS)
	Gura_AssignValue(GL_MAX_VARYING_FLOATS, Value(GL_MAX_VARYING_FLOATS));
#endif
#if defined(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS)
	Gura_AssignValue(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, Value(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS));
#endif
#if defined(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS)
	Gura_AssignValue(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, Value(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS));
#endif
#if defined(GL_ACTIVE_ATTRIBUTES)
	Gura_AssignValue(GL_ACTIVE_ATTRIBUTES, Value(GL_ACTIVE_ATTRIBUTES));
#endif
#if defined(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH)
	Gura_AssignValue(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, Value(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH));
#endif
#if defined(GL_FRAGMENT_SHADER)
	Gura_AssignValue(GL_FRAGMENT_SHADER, Value(GL_FRAGMENT_SHADER));
#endif
#if defined(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS)
	Gura_AssignValue(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, Value(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS));
#endif
#if defined(GL_FRAGMENT_SHADER_DERIVATIVE_HINT)
	Gura_AssignValue(GL_FRAGMENT_SHADER_DERIVATIVE_HINT, Value(GL_FRAGMENT_SHADER_DERIVATIVE_HINT));
#endif
#if defined(GL_MAX_VERTEX_ATTRIBS)
	Gura_AssignValue(GL_MAX_VERTEX_ATTRIBS, Value(GL_MAX_VERTEX_ATTRIBS));
#endif
#if defined(GL_VERTEX_ATTRIB_ARRAY_ENABLED)
	Gura_AssignValue(GL_VERTEX_ATTRIB_ARRAY_ENABLED, Value(GL_VERTEX_ATTRIB_ARRAY_ENABLED));
#endif
#if defined(GL_VERTEX_ATTRIB_ARRAY_SIZE)
	Gura_AssignValue(GL_VERTEX_ATTRIB_ARRAY_SIZE, Value(GL_VERTEX_ATTRIB_ARRAY_SIZE));
#endif
#if defined(GL_VERTEX_ATTRIB_ARRAY_STRIDE)
	Gura_AssignValue(GL_VERTEX_ATTRIB_ARRAY_STRIDE, Value(GL_VERTEX_ATTRIB_ARRAY_STRIDE));
#endif
#if defined(GL_VERTEX_ATTRIB_ARRAY_TYPE)
	Gura_AssignValue(GL_VERTEX_ATTRIB_ARRAY_TYPE, Value(GL_VERTEX_ATTRIB_ARRAY_TYPE));
#endif
#if defined(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED)
	Gura_AssignValue(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, Value(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED));
#endif
#if defined(GL_CURRENT_VERTEX_ATTRIB)
	Gura_AssignValue(GL_CURRENT_VERTEX_ATTRIB, Value(GL_CURRENT_VERTEX_ATTRIB));
#endif
#if defined(GL_VERTEX_ATTRIB_ARRAY_POINTER)
	Gura_AssignValue(GL_VERTEX_ATTRIB_ARRAY_POINTER, Value(GL_VERTEX_ATTRIB_ARRAY_POINTER));
#endif
#if defined(GL_VERTEX_PROGRAM_POINT_SIZE)
	Gura_AssignValue(GL_VERTEX_PROGRAM_POINT_SIZE, Value(GL_VERTEX_PROGRAM_POINT_SIZE));
#endif
#if defined(GL_VERTEX_PROGRAM_TWO_SIDE)
	Gura_AssignValue(GL_VERTEX_PROGRAM_TWO_SIDE, Value(GL_VERTEX_PROGRAM_TWO_SIDE));
#endif
#if defined(GL_MAX_TEXTURE_COORDS)
	Gura_AssignValue(GL_MAX_TEXTURE_COORDS, Value(GL_MAX_TEXTURE_COORDS));
#endif
#if defined(GL_MAX_TEXTURE_IMAGE_UNITS)
	Gura_AssignValue(GL_MAX_TEXTURE_IMAGE_UNITS, Value(GL_MAX_TEXTURE_IMAGE_UNITS));
#endif
#if defined(GL_MAX_DRAW_BUFFERS)
	Gura_AssignValue(GL_MAX_DRAW_BUFFERS, Value(GL_MAX_DRAW_BUFFERS));
#endif
#if defined(GL_DRAW_BUFFER0)
	Gura_AssignValue(GL_DRAW_BUFFER0, Value(GL_DRAW_BUFFER0));
#endif
#if defined(GL_DRAW_BUFFER1)
	Gura_AssignValue(GL_DRAW_BUFFER1, Value(GL_DRAW_BUFFER1));
#endif
#if defined(GL_DRAW_BUFFER2)
	Gura_AssignValue(GL_DRAW_BUFFER2, Value(GL_DRAW_BUFFER2));
#endif
#if defined(GL_DRAW_BUFFER3)
	Gura_AssignValue(GL_DRAW_BUFFER3, Value(GL_DRAW_BUFFER3));
#endif
#if defined(GL_DRAW_BUFFER4)
	Gura_AssignValue(GL_DRAW_BUFFER4, Value(GL_DRAW_BUFFER4));
#endif
#if defined(GL_DRAW_BUFFER5)
	Gura_AssignValue(GL_DRAW_BUFFER5, Value(GL_DRAW_BUFFER5));
#endif
#if defined(GL_DRAW_BUFFER6)
	Gura_AssignValue(GL_DRAW_BUFFER6, Value(GL_DRAW_BUFFER6));
#endif
#if defined(GL_DRAW_BUFFER7)
	Gura_AssignValue(GL_DRAW_BUFFER7, Value(GL_DRAW_BUFFER7));
#endif
#if defined(GL_DRAW_BUFFER8)
	Gura_AssignValue(GL_DRAW_BUFFER8, Value(GL_DRAW_BUFFER8));
#endif
#if defined(GL_DRAW_BUFFER9)
	Gura_AssignValue(GL_DRAW_BUFFER9, Value(GL_DRAW_BUFFER9));
#endif
#if defined(GL_DRAW_BUFFER10)
	Gura_AssignValue(GL_DRAW_BUFFER10, Value(GL_DRAW_BUFFER10));
#endif
#if defined(GL_DRAW_BUFFER11)
	Gura_AssignValue(GL_DRAW_BUFFER11, Value(GL_DRAW_BUFFER11));
#endif
#if defined(GL_DRAW_BUFFER12)
	Gura_AssignValue(GL_DRAW_BUFFER12, Value(GL_DRAW_BUFFER12));
#endif
#if defined(GL_DRAW_BUFFER13)
	Gura_AssignValue(GL_DRAW_BUFFER13, Value(GL_DRAW_BUFFER13));
#endif
#if defined(GL_DRAW_BUFFER14)
	Gura_AssignValue(GL_DRAW_BUFFER14, Value(GL_DRAW_BUFFER14));
#endif
#if defined(GL_DRAW_BUFFER15)
	Gura_AssignValue(GL_DRAW_BUFFER15, Value(GL_DRAW_BUFFER15));
#endif
#if defined(GL_POINT_SPRITE)
	Gura_AssignValue(GL_POINT_SPRITE, Value(GL_POINT_SPRITE));
#endif
#if defined(GL_COORD_REPLACE)
	Gura_AssignValue(GL_COORD_REPLACE, Value(GL_COORD_REPLACE));
#endif
#if defined(GL_POINT_SPRITE_COORD_ORIGIN)
	Gura_AssignValue(GL_POINT_SPRITE_COORD_ORIGIN, Value(GL_POINT_SPRITE_COORD_ORIGIN));
#endif
#if defined(GL_LOWER_LEFT)
	Gura_AssignValue(GL_LOWER_LEFT, Value(GL_LOWER_LEFT));
#endif
#if defined(GL_UPPER_LEFT)
	Gura_AssignValue(GL_UPPER_LEFT, Value(GL_UPPER_LEFT));
#endif
#if defined(GL_STENCIL_BACK_FUNC)
	Gura_AssignValue(GL_STENCIL_BACK_FUNC, Value(GL_STENCIL_BACK_FUNC));
#endif
#if defined(GL_STENCIL_BACK_VALUE_MASK)
	Gura_AssignValue(GL_STENCIL_BACK_VALUE_MASK, Value(GL_STENCIL_BACK_VALUE_MASK));
#endif
#if defined(GL_STENCIL_BACK_REF)
	Gura_AssignValue(GL_STENCIL_BACK_REF, Value(GL_STENCIL_BACK_REF));
#endif
#if defined(GL_STENCIL_BACK_FAIL)
	Gura_AssignValue(GL_STENCIL_BACK_FAIL, Value(GL_STENCIL_BACK_FAIL));
#endif
#if defined(GL_STENCIL_BACK_PASS_DEPTH_FAIL)
	Gura_AssignValue(GL_STENCIL_BACK_PASS_DEPTH_FAIL, Value(GL_STENCIL_BACK_PASS_DEPTH_FAIL));
#endif
#if defined(GL_STENCIL_BACK_PASS_DEPTH_PASS)
	Gura_AssignValue(GL_STENCIL_BACK_PASS_DEPTH_PASS, Value(GL_STENCIL_BACK_PASS_DEPTH_PASS));
#endif
#if defined(GL_STENCIL_BACK_WRITEMASK)
	Gura_AssignValue(GL_STENCIL_BACK_WRITEMASK, Value(GL_STENCIL_BACK_WRITEMASK));
#endif
#if defined(GL_CURRENT_RASTER_SECONDARY_COLOR)
	Gura_AssignValue(GL_CURRENT_RASTER_SECONDARY_COLOR, Value(GL_CURRENT_RASTER_SECONDARY_COLOR));
#endif
#if defined(GL_PIXEL_PACK_BUFFER)
	Gura_AssignValue(GL_PIXEL_PACK_BUFFER, Value(GL_PIXEL_PACK_BUFFER));
#endif
#if defined(GL_PIXEL_UNPACK_BUFFER)
	Gura_AssignValue(GL_PIXEL_UNPACK_BUFFER, Value(GL_PIXEL_UNPACK_BUFFER));
#endif
#if defined(GL_PIXEL_PACK_BUFFER_BINDING)
	Gura_AssignValue(GL_PIXEL_PACK_BUFFER_BINDING, Value(GL_PIXEL_PACK_BUFFER_BINDING));
#endif
#if defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
	Gura_AssignValue(GL_PIXEL_UNPACK_BUFFER_BINDING, Value(GL_PIXEL_UNPACK_BUFFER_BINDING));
#endif
#if defined(GL_FLOAT_MAT2x3)
	Gura_AssignValue(GL_FLOAT_MAT2x3, Value(GL_FLOAT_MAT2x3));
#endif
#if defined(GL_FLOAT_MAT2x4)
	Gura_AssignValue(GL_FLOAT_MAT2x4, Value(GL_FLOAT_MAT2x4));
#endif
#if defined(GL_FLOAT_MAT3x2)
	Gura_AssignValue(GL_FLOAT_MAT3x2, Value(GL_FLOAT_MAT3x2));
#endif
#if defined(GL_FLOAT_MAT3x4)
	Gura_AssignValue(GL_FLOAT_MAT3x4, Value(GL_FLOAT_MAT3x4));
#endif
#if defined(GL_FLOAT_MAT4x2)
	Gura_AssignValue(GL_FLOAT_MAT4x2, Value(GL_FLOAT_MAT4x2));
#endif
#if defined(GL_FLOAT_MAT4x3)
	Gura_AssignValue(GL_FLOAT_MAT4x3, Value(GL_FLOAT_MAT4x3));
#endif
#if defined(GL_SRGB)
	Gura_AssignValue(GL_SRGB, Value(GL_SRGB));
#endif
#if defined(GL_SRGB8)
	Gura_AssignValue(GL_SRGB8, Value(GL_SRGB8));
#endif
#if defined(GL_SRGB_ALPHA)
	Gura_AssignValue(GL_SRGB_ALPHA, Value(GL_SRGB_ALPHA));
#endif
#if defined(GL_SRGB8_ALPHA8)
	Gura_AssignValue(GL_SRGB8_ALPHA8, Value(GL_SRGB8_ALPHA8));
#endif
#if defined(GL_SLUMINANCE_ALPHA)
	Gura_AssignValue(GL_SLUMINANCE_ALPHA, Value(GL_SLUMINANCE_ALPHA));
#endif
#if defined(GL_SLUMINANCE8_ALPHA8)
	Gura_AssignValue(GL_SLUMINANCE8_ALPHA8, Value(GL_SLUMINANCE8_ALPHA8));
#endif
#if defined(GL_SLUMINANCE)
	Gura_AssignValue(GL_SLUMINANCE, Value(GL_SLUMINANCE));
#endif
#if defined(GL_SLUMINANCE8)
	Gura_AssignValue(GL_SLUMINANCE8, Value(GL_SLUMINANCE8));
#endif
#if defined(GL_COMPRESSED_SRGB)
	Gura_AssignValue(GL_COMPRESSED_SRGB, Value(GL_COMPRESSED_SRGB));
#endif
#if defined(GL_COMPRESSED_SRGB_ALPHA)
	Gura_AssignValue(GL_COMPRESSED_SRGB_ALPHA, Value(GL_COMPRESSED_SRGB_ALPHA));
#endif
#if defined(GL_COMPRESSED_SLUMINANCE)
	Gura_AssignValue(GL_COMPRESSED_SLUMINANCE, Value(GL_COMPRESSED_SLUMINANCE));
#endif
#if defined(GL_COMPRESSED_SLUMINANCE_ALPHA)
	Gura_AssignValue(GL_COMPRESSED_SLUMINANCE_ALPHA, Value(GL_COMPRESSED_SLUMINANCE_ALPHA));
#endif
}

Gura_EndModuleScope(opengl)
