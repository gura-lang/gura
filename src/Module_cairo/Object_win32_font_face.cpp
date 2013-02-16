#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_win32_font_face implementation
//-----------------------------------------------------------------------------
String Object_win32_font_face::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.win32_font_face>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for win32_font_face
//-----------------------------------------------------------------------------
//#cairo_font_face_t *cairo_win32_font_face_create_for_logfontw(LOGFONTW *logfont);
//#cairo_font_face_t *cairo_win32_font_face_create_for_hfont(HFONT font);
//#cairo_font_face_t *cairo_win32_font_face_create_for_logfontw_hfont(LOGFONTW *logfont, HFONT font);

// implementation of class win32_font_face
Gura_ImplementUserClass(win32_font_face)
{
}

}}
