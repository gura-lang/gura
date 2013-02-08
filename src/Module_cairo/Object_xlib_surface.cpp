#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_xlib_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for xlib_surface
//-----------------------------------------------------------------------------
//#cairo_surface_t *cairo_xlib_surface_create(Display *dpy, Drawable drawable, Visual *visual, int width, int height);
//#cairo_surface_t *cairo_xlib_surface_create_for_bitmap(Display *dpy, Pixmap bitmap, Screen *screen, int width, int height);
//#void cairo_xlib_surface_set_size(cairo_surface_t *surface, int width, int height);
//#Display *cairo_xlib_surface_get_display(cairo_surface_t *surface);
//#Screen *cairo_xlib_surface_get_screen(cairo_surface_t *surface);
//#void cairo_xlib_surface_set_drawable(cairo_surface_t *surface, Drawable drawable, int width, int height);
//#Drawable cairo_xlib_surface_get_drawable(cairo_surface_t *surface);
//#Visual *cairo_xlib_surface_get_visual(cairo_surface_t *surface);
//#int cairo_xlib_surface_get_width(cairo_surface_t *surface);
//#int cairo_xlib_surface_get_height(cairo_surface_t *surface);
//#int cairo_xlib_surface_get_depth(cairo_surface_t *surface);
//#void cairo_xlib_device_debug_cap_xrender_version(cairo_device_t *device, int major_version, int minor_version);
//#int cairo_xlib_device_debug_get_precision(cairo_device_t *device);
//#void cairo_xlib_device_debug_set_precision(cairo_device_t *device, int precision);

//#cairo_surface_t *   cairo_xlib_surface_create_with_xrender_format(Display *dpy, Drawable drawable, Screen *screen, XRenderPictFormat *format, int width, int height);
//#XRenderPictFormat * cairo_xlib_surface_get_xrender_format(cairo_surface_t *surface);

Gura_ImplementUserClass(xlib_surface)
{
}

}}
