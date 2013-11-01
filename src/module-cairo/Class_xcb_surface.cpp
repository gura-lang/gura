#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_xcb_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for xcb_surface
//-----------------------------------------------------------------------------
//#cairo_surface_t *cairo_xcb_surface_create(xcb_connection_t *connection, xcb_drawable_t drawable, xcb_visualtype_t *visual, int width, int height);
//#cairo_surface_t *cairo_xcb_surface_create_for_bitmap(xcb_connection_t *connection, xcb_screen_t *screen, xcb_pixmap_t bitmap, int width, int height);
//#cairo_surface_t *cairo_xcb_surface_create_with_xrender_format(xcb_connection_t *connection, xcb_screen_t *screen, xcb_drawable_t drawable, xcb_render_pictforminfo_t *format, int width, int height);
//#void cairo_xcb_surface_set_size(cairo_surface_t *surface, int width, int height);
//#void cairo_xcb_surface_set_drawable(cairo_surface_t *surface, xcb_drawable_t drawable, int width, int height);
//#xcb_connection_t *cairo_xcb_device_get_connection(cairo_device_t *device);
//#void cairo_xcb_device_debug_cap_xrender_version(cairo_device_t *device, int major_version, int minor_version);
//#void cairo_xcb_device_debug_cap_xshm_version(cairo_device_t *device, int major_version, int minor_version);
//#int cairo_xcb_device_debug_get_precision(cairo_device_t *device);
//#void cairo_xcb_device_debug_set_precision(cairo_device_t *device, int precision);

Gura_ImplementUserClass(xcb_surface)
{
}

Gura_EndModuleScope(cairo)
