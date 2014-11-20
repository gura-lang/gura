#include "stdafx.h"

Gura_BeginModuleScope(glu)

void AssignValues(Environment &env)
{
#if defined(GLU_EXT_object_space_tess)
	Gura_AssignValue(GLU_EXT_object_space_tess, Value(GLU_EXT_object_space_tess));
#endif
#if defined(GLU_EXT_nurbs_tessellator)
	Gura_AssignValue(GLU_EXT_nurbs_tessellator, Value(GLU_EXT_nurbs_tessellator));
#endif
#if defined(GLU_FALSE)
	Gura_AssignValue(GLU_FALSE, Value(GLU_FALSE));
#endif
#if defined(GLU_TRUE)
	Gura_AssignValue(GLU_TRUE, Value(GLU_TRUE));
#endif
#if defined(GLU_VERSION_1_1)
	Gura_AssignValue(GLU_VERSION_1_1, Value(GLU_VERSION_1_1));
#endif
#if defined(GLU_VERSION_1_2)
	Gura_AssignValue(GLU_VERSION_1_2, Value(GLU_VERSION_1_2));
#endif
#if defined(GLU_VERSION_1_3)
	Gura_AssignValue(GLU_VERSION_1_3, Value(GLU_VERSION_1_3));
#endif
#if defined(GLU_VERSION)
	Gura_AssignValue(GLU_VERSION, Value(GLU_VERSION));
#endif
#if defined(GLU_EXTENSIONS)
	Gura_AssignValue(GLU_EXTENSIONS, Value(GLU_EXTENSIONS));
#endif
#if defined(GLU_INVALID_ENUM)
	Gura_AssignValue(GLU_INVALID_ENUM, Value(GLU_INVALID_ENUM));
#endif
#if defined(GLU_INVALID_VALUE)
	Gura_AssignValue(GLU_INVALID_VALUE, Value(GLU_INVALID_VALUE));
#endif
#if defined(GLU_OUT_OF_MEMORY)
	Gura_AssignValue(GLU_OUT_OF_MEMORY, Value(GLU_OUT_OF_MEMORY));
#endif
#if defined(GLU_INCOMPATIBLE_GL_VERSION)
	Gura_AssignValue(GLU_INCOMPATIBLE_GL_VERSION, Value(GLU_INCOMPATIBLE_GL_VERSION));
#endif
#if defined(GLU_INVALID_OPERATION)
	Gura_AssignValue(GLU_INVALID_OPERATION, Value(GLU_INVALID_OPERATION));
#endif
#if defined(GLU_OUTLINE_POLYGON)
	Gura_AssignValue(GLU_OUTLINE_POLYGON, Value(GLU_OUTLINE_POLYGON));
#endif
#if defined(GLU_OUTLINE_PATCH)
	Gura_AssignValue(GLU_OUTLINE_PATCH, Value(GLU_OUTLINE_PATCH));
#endif
#if defined(GLU_NURBS_ERROR)
	Gura_AssignValue(GLU_NURBS_ERROR, Value(GLU_NURBS_ERROR));
#endif
#if defined(GLU_ERROR)
	Gura_AssignValue(GLU_ERROR, Value(GLU_ERROR));
#endif
#if defined(GLU_NURBS_BEGIN)
	Gura_AssignValue(GLU_NURBS_BEGIN, Value(GLU_NURBS_BEGIN));
#endif
#if defined(GLU_NURBS_BEGIN_EXT)
	Gura_AssignValue(GLU_NURBS_BEGIN_EXT, Value(GLU_NURBS_BEGIN_EXT));
#endif
#if defined(GLU_NURBS_VERTEX)
	Gura_AssignValue(GLU_NURBS_VERTEX, Value(GLU_NURBS_VERTEX));
#endif
#if defined(GLU_NURBS_VERTEX_EXT)
	Gura_AssignValue(GLU_NURBS_VERTEX_EXT, Value(GLU_NURBS_VERTEX_EXT));
#endif
#if defined(GLU_NURBS_NORMAL)
	Gura_AssignValue(GLU_NURBS_NORMAL, Value(GLU_NURBS_NORMAL));
#endif
#if defined(GLU_NURBS_NORMAL_EXT)
	Gura_AssignValue(GLU_NURBS_NORMAL_EXT, Value(GLU_NURBS_NORMAL_EXT));
#endif
#if defined(GLU_NURBS_COLOR)
	Gura_AssignValue(GLU_NURBS_COLOR, Value(GLU_NURBS_COLOR));
#endif
#if defined(GLU_NURBS_COLOR_EXT)
	Gura_AssignValue(GLU_NURBS_COLOR_EXT, Value(GLU_NURBS_COLOR_EXT));
#endif
#if defined(GLU_NURBS_TEXTURE_COORD)
	Gura_AssignValue(GLU_NURBS_TEXTURE_COORD, Value(GLU_NURBS_TEXTURE_COORD));
#endif
#if defined(GLU_NURBS_TEX_COORD_EXT)
	Gura_AssignValue(GLU_NURBS_TEX_COORD_EXT, Value(GLU_NURBS_TEX_COORD_EXT));
#endif
#if defined(GLU_NURBS_END)
	Gura_AssignValue(GLU_NURBS_END, Value(GLU_NURBS_END));
#endif
#if defined(GLU_NURBS_END_EXT)
	Gura_AssignValue(GLU_NURBS_END_EXT, Value(GLU_NURBS_END_EXT));
#endif
#if defined(GLU_NURBS_BEGIN_DATA)
	Gura_AssignValue(GLU_NURBS_BEGIN_DATA, Value(GLU_NURBS_BEGIN_DATA));
#endif
#if defined(GLU_NURBS_BEGIN_DATA_EXT)
	Gura_AssignValue(GLU_NURBS_BEGIN_DATA_EXT, Value(GLU_NURBS_BEGIN_DATA_EXT));
#endif
#if defined(GLU_NURBS_VERTEX_DATA)
	Gura_AssignValue(GLU_NURBS_VERTEX_DATA, Value(GLU_NURBS_VERTEX_DATA));
#endif
#if defined(GLU_NURBS_VERTEX_DATA_EXT)
	Gura_AssignValue(GLU_NURBS_VERTEX_DATA_EXT, Value(GLU_NURBS_VERTEX_DATA_EXT));
#endif
#if defined(GLU_NURBS_NORMAL_DATA)
	Gura_AssignValue(GLU_NURBS_NORMAL_DATA, Value(GLU_NURBS_NORMAL_DATA));
#endif
#if defined(GLU_NURBS_NORMAL_DATA_EXT)
	Gura_AssignValue(GLU_NURBS_NORMAL_DATA_EXT, Value(GLU_NURBS_NORMAL_DATA_EXT));
#endif
#if defined(GLU_NURBS_COLOR_DATA)
	Gura_AssignValue(GLU_NURBS_COLOR_DATA, Value(GLU_NURBS_COLOR_DATA));
#endif
#if defined(GLU_NURBS_COLOR_DATA_EXT)
	Gura_AssignValue(GLU_NURBS_COLOR_DATA_EXT, Value(GLU_NURBS_COLOR_DATA_EXT));
#endif
#if defined(GLU_NURBS_TEXTURE_COORD_DATA)
	Gura_AssignValue(GLU_NURBS_TEXTURE_COORD_DATA, Value(GLU_NURBS_TEXTURE_COORD_DATA));
#endif
#if defined(GLU_NURBS_TEX_COORD_DATA_EXT)
	Gura_AssignValue(GLU_NURBS_TEX_COORD_DATA_EXT, Value(GLU_NURBS_TEX_COORD_DATA_EXT));
#endif
#if defined(GLU_NURBS_END_DATA)
	Gura_AssignValue(GLU_NURBS_END_DATA, Value(GLU_NURBS_END_DATA));
#endif
#if defined(GLU_NURBS_END_DATA_EXT)
	Gura_AssignValue(GLU_NURBS_END_DATA_EXT, Value(GLU_NURBS_END_DATA_EXT));
#endif
#if defined(GLU_NURBS_ERROR1)
	Gura_AssignValue(GLU_NURBS_ERROR1, Value(GLU_NURBS_ERROR1));
#endif
#if defined(GLU_NURBS_ERROR2)
	Gura_AssignValue(GLU_NURBS_ERROR2, Value(GLU_NURBS_ERROR2));
#endif
#if defined(GLU_NURBS_ERROR3)
	Gura_AssignValue(GLU_NURBS_ERROR3, Value(GLU_NURBS_ERROR3));
#endif
#if defined(GLU_NURBS_ERROR4)
	Gura_AssignValue(GLU_NURBS_ERROR4, Value(GLU_NURBS_ERROR4));
#endif
#if defined(GLU_NURBS_ERROR5)
	Gura_AssignValue(GLU_NURBS_ERROR5, Value(GLU_NURBS_ERROR5));
#endif
#if defined(GLU_NURBS_ERROR6)
	Gura_AssignValue(GLU_NURBS_ERROR6, Value(GLU_NURBS_ERROR6));
#endif
#if defined(GLU_NURBS_ERROR7)
	Gura_AssignValue(GLU_NURBS_ERROR7, Value(GLU_NURBS_ERROR7));
#endif
#if defined(GLU_NURBS_ERROR8)
	Gura_AssignValue(GLU_NURBS_ERROR8, Value(GLU_NURBS_ERROR8));
#endif
#if defined(GLU_NURBS_ERROR9)
	Gura_AssignValue(GLU_NURBS_ERROR9, Value(GLU_NURBS_ERROR9));
#endif
#if defined(GLU_NURBS_ERROR10)
	Gura_AssignValue(GLU_NURBS_ERROR10, Value(GLU_NURBS_ERROR10));
#endif
#if defined(GLU_NURBS_ERROR11)
	Gura_AssignValue(GLU_NURBS_ERROR11, Value(GLU_NURBS_ERROR11));
#endif
#if defined(GLU_NURBS_ERROR12)
	Gura_AssignValue(GLU_NURBS_ERROR12, Value(GLU_NURBS_ERROR12));
#endif
#if defined(GLU_NURBS_ERROR13)
	Gura_AssignValue(GLU_NURBS_ERROR13, Value(GLU_NURBS_ERROR13));
#endif
#if defined(GLU_NURBS_ERROR14)
	Gura_AssignValue(GLU_NURBS_ERROR14, Value(GLU_NURBS_ERROR14));
#endif
#if defined(GLU_NURBS_ERROR15)
	Gura_AssignValue(GLU_NURBS_ERROR15, Value(GLU_NURBS_ERROR15));
#endif
#if defined(GLU_NURBS_ERROR16)
	Gura_AssignValue(GLU_NURBS_ERROR16, Value(GLU_NURBS_ERROR16));
#endif
#if defined(GLU_NURBS_ERROR17)
	Gura_AssignValue(GLU_NURBS_ERROR17, Value(GLU_NURBS_ERROR17));
#endif
#if defined(GLU_NURBS_ERROR18)
	Gura_AssignValue(GLU_NURBS_ERROR18, Value(GLU_NURBS_ERROR18));
#endif
#if defined(GLU_NURBS_ERROR19)
	Gura_AssignValue(GLU_NURBS_ERROR19, Value(GLU_NURBS_ERROR19));
#endif
#if defined(GLU_NURBS_ERROR20)
	Gura_AssignValue(GLU_NURBS_ERROR20, Value(GLU_NURBS_ERROR20));
#endif
#if defined(GLU_NURBS_ERROR21)
	Gura_AssignValue(GLU_NURBS_ERROR21, Value(GLU_NURBS_ERROR21));
#endif
#if defined(GLU_NURBS_ERROR22)
	Gura_AssignValue(GLU_NURBS_ERROR22, Value(GLU_NURBS_ERROR22));
#endif
#if defined(GLU_NURBS_ERROR23)
	Gura_AssignValue(GLU_NURBS_ERROR23, Value(GLU_NURBS_ERROR23));
#endif
#if defined(GLU_NURBS_ERROR24)
	Gura_AssignValue(GLU_NURBS_ERROR24, Value(GLU_NURBS_ERROR24));
#endif
#if defined(GLU_NURBS_ERROR25)
	Gura_AssignValue(GLU_NURBS_ERROR25, Value(GLU_NURBS_ERROR25));
#endif
#if defined(GLU_NURBS_ERROR26)
	Gura_AssignValue(GLU_NURBS_ERROR26, Value(GLU_NURBS_ERROR26));
#endif
#if defined(GLU_NURBS_ERROR27)
	Gura_AssignValue(GLU_NURBS_ERROR27, Value(GLU_NURBS_ERROR27));
#endif
#if defined(GLU_NURBS_ERROR28)
	Gura_AssignValue(GLU_NURBS_ERROR28, Value(GLU_NURBS_ERROR28));
#endif
#if defined(GLU_NURBS_ERROR29)
	Gura_AssignValue(GLU_NURBS_ERROR29, Value(GLU_NURBS_ERROR29));
#endif
#if defined(GLU_NURBS_ERROR30)
	Gura_AssignValue(GLU_NURBS_ERROR30, Value(GLU_NURBS_ERROR30));
#endif
#if defined(GLU_NURBS_ERROR31)
	Gura_AssignValue(GLU_NURBS_ERROR31, Value(GLU_NURBS_ERROR31));
#endif
#if defined(GLU_NURBS_ERROR32)
	Gura_AssignValue(GLU_NURBS_ERROR32, Value(GLU_NURBS_ERROR32));
#endif
#if defined(GLU_NURBS_ERROR33)
	Gura_AssignValue(GLU_NURBS_ERROR33, Value(GLU_NURBS_ERROR33));
#endif
#if defined(GLU_NURBS_ERROR34)
	Gura_AssignValue(GLU_NURBS_ERROR34, Value(GLU_NURBS_ERROR34));
#endif
#if defined(GLU_NURBS_ERROR35)
	Gura_AssignValue(GLU_NURBS_ERROR35, Value(GLU_NURBS_ERROR35));
#endif
#if defined(GLU_NURBS_ERROR36)
	Gura_AssignValue(GLU_NURBS_ERROR36, Value(GLU_NURBS_ERROR36));
#endif
#if defined(GLU_NURBS_ERROR37)
	Gura_AssignValue(GLU_NURBS_ERROR37, Value(GLU_NURBS_ERROR37));
#endif
#if defined(GLU_AUTO_LOAD_MATRIX)
	Gura_AssignValue(GLU_AUTO_LOAD_MATRIX, Value(GLU_AUTO_LOAD_MATRIX));
#endif
#if defined(GLU_CULLING)
	Gura_AssignValue(GLU_CULLING, Value(GLU_CULLING));
#endif
#if defined(GLU_SAMPLING_TOLERANCE)
	Gura_AssignValue(GLU_SAMPLING_TOLERANCE, Value(GLU_SAMPLING_TOLERANCE));
#endif
#if defined(GLU_DISPLAY_MODE)
	Gura_AssignValue(GLU_DISPLAY_MODE, Value(GLU_DISPLAY_MODE));
#endif
#if defined(GLU_PARAMETRIC_TOLERANCE)
	Gura_AssignValue(GLU_PARAMETRIC_TOLERANCE, Value(GLU_PARAMETRIC_TOLERANCE));
#endif
#if defined(GLU_SAMPLING_METHOD)
	Gura_AssignValue(GLU_SAMPLING_METHOD, Value(GLU_SAMPLING_METHOD));
#endif
#if defined(GLU_U_STEP)
	Gura_AssignValue(GLU_U_STEP, Value(GLU_U_STEP));
#endif
#if defined(GLU_V_STEP)
	Gura_AssignValue(GLU_V_STEP, Value(GLU_V_STEP));
#endif
#if defined(GLU_NURBS_MODE)
	Gura_AssignValue(GLU_NURBS_MODE, Value(GLU_NURBS_MODE));
#endif
#if defined(GLU_NURBS_MODE_EXT)
	Gura_AssignValue(GLU_NURBS_MODE_EXT, Value(GLU_NURBS_MODE_EXT));
#endif
#if defined(GLU_NURBS_TESSELLATOR)
	Gura_AssignValue(GLU_NURBS_TESSELLATOR, Value(GLU_NURBS_TESSELLATOR));
#endif
#if defined(GLU_NURBS_TESSELLATOR_EXT)
	Gura_AssignValue(GLU_NURBS_TESSELLATOR_EXT, Value(GLU_NURBS_TESSELLATOR_EXT));
#endif
#if defined(GLU_NURBS_RENDERER)
	Gura_AssignValue(GLU_NURBS_RENDERER, Value(GLU_NURBS_RENDERER));
#endif
#if defined(GLU_NURBS_RENDERER_EXT)
	Gura_AssignValue(GLU_NURBS_RENDERER_EXT, Value(GLU_NURBS_RENDERER_EXT));
#endif
#if defined(GLU_OBJECT_PARAMETRIC_ERROR)
	Gura_AssignValue(GLU_OBJECT_PARAMETRIC_ERROR, Value(GLU_OBJECT_PARAMETRIC_ERROR));
#endif
#if defined(GLU_OBJECT_PARAMETRIC_ERROR_EXT)
	Gura_AssignValue(GLU_OBJECT_PARAMETRIC_ERROR_EXT, Value(GLU_OBJECT_PARAMETRIC_ERROR_EXT));
#endif
#if defined(GLU_OBJECT_PATH_LENGTH)
	Gura_AssignValue(GLU_OBJECT_PATH_LENGTH, Value(GLU_OBJECT_PATH_LENGTH));
#endif
#if defined(GLU_OBJECT_PATH_LENGTH_EXT)
	Gura_AssignValue(GLU_OBJECT_PATH_LENGTH_EXT, Value(GLU_OBJECT_PATH_LENGTH_EXT));
#endif
#if defined(GLU_PATH_LENGTH)
	Gura_AssignValue(GLU_PATH_LENGTH, Value(GLU_PATH_LENGTH));
#endif
#if defined(GLU_PARAMETRIC_ERROR)
	Gura_AssignValue(GLU_PARAMETRIC_ERROR, Value(GLU_PARAMETRIC_ERROR));
#endif
#if defined(GLU_DOMAIN_DISTANCE)
	Gura_AssignValue(GLU_DOMAIN_DISTANCE, Value(GLU_DOMAIN_DISTANCE));
#endif
#if defined(GLU_MAP1_TRIM_2)
	Gura_AssignValue(GLU_MAP1_TRIM_2, Value(GLU_MAP1_TRIM_2));
#endif
#if defined(GLU_MAP1_TRIM_3)
	Gura_AssignValue(GLU_MAP1_TRIM_3, Value(GLU_MAP1_TRIM_3));
#endif
#if defined(GLU_POINT)
	Gura_AssignValue(GLU_POINT, Value(GLU_POINT));
#endif
#if defined(GLU_LINE)
	Gura_AssignValue(GLU_LINE, Value(GLU_LINE));
#endif
#if defined(GLU_FILL)
	Gura_AssignValue(GLU_FILL, Value(GLU_FILL));
#endif
#if defined(GLU_SILHOUETTE)
	Gura_AssignValue(GLU_SILHOUETTE, Value(GLU_SILHOUETTE));
#endif
#if defined(GLU_SMOOTH)
	Gura_AssignValue(GLU_SMOOTH, Value(GLU_SMOOTH));
#endif
#if defined(GLU_FLAT)
	Gura_AssignValue(GLU_FLAT, Value(GLU_FLAT));
#endif
#if defined(GLU_NONE)
	Gura_AssignValue(GLU_NONE, Value(GLU_NONE));
#endif
#if defined(GLU_OUTSIDE)
	Gura_AssignValue(GLU_OUTSIDE, Value(GLU_OUTSIDE));
#endif
#if defined(GLU_INSIDE)
	Gura_AssignValue(GLU_INSIDE, Value(GLU_INSIDE));
#endif
#if defined(GLU_TESS_BEGIN)
	Gura_AssignValue(GLU_TESS_BEGIN, Value(GLU_TESS_BEGIN));
#endif
#if defined(GLU_BEGIN)
	Gura_AssignValue(GLU_BEGIN, Value(GLU_BEGIN));
#endif
#if defined(GLU_TESS_VERTEX)
	Gura_AssignValue(GLU_TESS_VERTEX, Value(GLU_TESS_VERTEX));
#endif
#if defined(GLU_VERTEX)
	Gura_AssignValue(GLU_VERTEX, Value(GLU_VERTEX));
#endif
#if defined(GLU_TESS_END)
	Gura_AssignValue(GLU_TESS_END, Value(GLU_TESS_END));
#endif
#if defined(GLU_END)
	Gura_AssignValue(GLU_END, Value(GLU_END));
#endif
#if defined(GLU_TESS_ERROR)
	Gura_AssignValue(GLU_TESS_ERROR, Value(GLU_TESS_ERROR));
#endif
#if defined(GLU_TESS_EDGE_FLAG)
	Gura_AssignValue(GLU_TESS_EDGE_FLAG, Value(GLU_TESS_EDGE_FLAG));
#endif
#if defined(GLU_EDGE_FLAG)
	Gura_AssignValue(GLU_EDGE_FLAG, Value(GLU_EDGE_FLAG));
#endif
#if defined(GLU_TESS_COMBINE)
	Gura_AssignValue(GLU_TESS_COMBINE, Value(GLU_TESS_COMBINE));
#endif
#if defined(GLU_TESS_BEGIN_DATA)
	Gura_AssignValue(GLU_TESS_BEGIN_DATA, Value(GLU_TESS_BEGIN_DATA));
#endif
#if defined(GLU_TESS_VERTEX_DATA)
	Gura_AssignValue(GLU_TESS_VERTEX_DATA, Value(GLU_TESS_VERTEX_DATA));
#endif
#if defined(GLU_TESS_END_DATA)
	Gura_AssignValue(GLU_TESS_END_DATA, Value(GLU_TESS_END_DATA));
#endif
#if defined(GLU_TESS_ERROR_DATA)
	Gura_AssignValue(GLU_TESS_ERROR_DATA, Value(GLU_TESS_ERROR_DATA));
#endif
#if defined(GLU_TESS_EDGE_FLAG_DATA)
	Gura_AssignValue(GLU_TESS_EDGE_FLAG_DATA, Value(GLU_TESS_EDGE_FLAG_DATA));
#endif
#if defined(GLU_TESS_COMBINE_DATA)
	Gura_AssignValue(GLU_TESS_COMBINE_DATA, Value(GLU_TESS_COMBINE_DATA));
#endif
#if defined(GLU_CW)
	Gura_AssignValue(GLU_CW, Value(GLU_CW));
#endif
#if defined(GLU_CCW)
	Gura_AssignValue(GLU_CCW, Value(GLU_CCW));
#endif
#if defined(GLU_INTERIOR)
	Gura_AssignValue(GLU_INTERIOR, Value(GLU_INTERIOR));
#endif
#if defined(GLU_EXTERIOR)
	Gura_AssignValue(GLU_EXTERIOR, Value(GLU_EXTERIOR));
#endif
#if defined(GLU_UNKNOWN)
	Gura_AssignValue(GLU_UNKNOWN, Value(GLU_UNKNOWN));
#endif
#if defined(GLU_TESS_WINDING_RULE)
	Gura_AssignValue(GLU_TESS_WINDING_RULE, Value(GLU_TESS_WINDING_RULE));
#endif
#if defined(GLU_TESS_BOUNDARY_ONLY)
	Gura_AssignValue(GLU_TESS_BOUNDARY_ONLY, Value(GLU_TESS_BOUNDARY_ONLY));
#endif
#if defined(GLU_TESS_TOLERANCE)
	Gura_AssignValue(GLU_TESS_TOLERANCE, Value(GLU_TESS_TOLERANCE));
#endif
#if defined(GLU_TESS_ERROR1)
	Gura_AssignValue(GLU_TESS_ERROR1, Value(GLU_TESS_ERROR1));
#endif
#if defined(GLU_TESS_ERROR2)
	Gura_AssignValue(GLU_TESS_ERROR2, Value(GLU_TESS_ERROR2));
#endif
#if defined(GLU_TESS_ERROR3)
	Gura_AssignValue(GLU_TESS_ERROR3, Value(GLU_TESS_ERROR3));
#endif
#if defined(GLU_TESS_ERROR4)
	Gura_AssignValue(GLU_TESS_ERROR4, Value(GLU_TESS_ERROR4));
#endif
#if defined(GLU_TESS_ERROR5)
	Gura_AssignValue(GLU_TESS_ERROR5, Value(GLU_TESS_ERROR5));
#endif
#if defined(GLU_TESS_ERROR6)
	Gura_AssignValue(GLU_TESS_ERROR6, Value(GLU_TESS_ERROR6));
#endif
#if defined(GLU_TESS_ERROR7)
	Gura_AssignValue(GLU_TESS_ERROR7, Value(GLU_TESS_ERROR7));
#endif
#if defined(GLU_TESS_ERROR8)
	Gura_AssignValue(GLU_TESS_ERROR8, Value(GLU_TESS_ERROR8));
#endif
#if defined(GLU_TESS_MISSING_BEGIN_POLYGON)
	Gura_AssignValue(GLU_TESS_MISSING_BEGIN_POLYGON, Value(GLU_TESS_MISSING_BEGIN_POLYGON));
#endif
#if defined(GLU_TESS_MISSING_BEGIN_CONTOUR)
	Gura_AssignValue(GLU_TESS_MISSING_BEGIN_CONTOUR, Value(GLU_TESS_MISSING_BEGIN_CONTOUR));
#endif
#if defined(GLU_TESS_MISSING_END_POLYGON)
	Gura_AssignValue(GLU_TESS_MISSING_END_POLYGON, Value(GLU_TESS_MISSING_END_POLYGON));
#endif
#if defined(GLU_TESS_MISSING_END_CONTOUR)
	Gura_AssignValue(GLU_TESS_MISSING_END_CONTOUR, Value(GLU_TESS_MISSING_END_CONTOUR));
#endif
#if defined(GLU_TESS_COORD_TOO_LARGE)
	Gura_AssignValue(GLU_TESS_COORD_TOO_LARGE, Value(GLU_TESS_COORD_TOO_LARGE));
#endif
#if defined(GLU_TESS_NEED_COMBINE_CALLBACK)
	Gura_AssignValue(GLU_TESS_NEED_COMBINE_CALLBACK, Value(GLU_TESS_NEED_COMBINE_CALLBACK));
#endif
#if defined(GLU_TESS_WINDING_ODD)
	Gura_AssignValue(GLU_TESS_WINDING_ODD, Value(GLU_TESS_WINDING_ODD));
#endif
#if defined(GLU_TESS_WINDING_NONZERO)
	Gura_AssignValue(GLU_TESS_WINDING_NONZERO, Value(GLU_TESS_WINDING_NONZERO));
#endif
#if defined(GLU_TESS_WINDING_POSITIVE)
	Gura_AssignValue(GLU_TESS_WINDING_POSITIVE, Value(GLU_TESS_WINDING_POSITIVE));
#endif
#if defined(GLU_TESS_WINDING_NEGATIVE)
	Gura_AssignValue(GLU_TESS_WINDING_NEGATIVE, Value(GLU_TESS_WINDING_NEGATIVE));
#endif
#if defined(GLU_TESS_WINDING_ABS_GEQ_TWO)
	Gura_AssignValue(GLU_TESS_WINDING_ABS_GEQ_TWO, Value(GLU_TESS_WINDING_ABS_GEQ_TWO));
#endif
#if defined(GLU_TESS_MAX_COORD)
	Gura_AssignValue(GLU_TESS_MAX_COORD, Value(GLU_TESS_MAX_COORD));
#endif
}

Gura_EndModuleScope(glu)
