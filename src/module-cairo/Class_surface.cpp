#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_surface implementation
//-----------------------------------------------------------------------------
Object_surface::~Object_surface()
{
	if (_surface != nullptr) {
		::cairo_surface_destroy(_surface);
		_surface = nullptr;
	}
}

Object *Object_surface::Clone() const
{
	return nullptr;
}

bool Object_surface::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	return true;
}

Value Object_surface::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		cairo_surface_type_t surface_type = ::cairo_surface_get_type(_surface);
		return Value(surface_type);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_surface::ToString(bool exprFlag)
{
	String str;
	str += "<cairo.surface:";
	cairo_surface_type_t surface_type = ::cairo_surface_get_type(_surface);
	str += SurfaceTypeToName(surface_type);
	if (surface_type == CAIRO_SURFACE_TYPE_IMAGE) {
		str += ":";
		str += NumberToString(::cairo_image_surface_get_width(_surface));
		str += "x";
		str += NumberToString(::cairo_image_surface_get_height(_surface));
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for surface
//-----------------------------------------------------------------------------
// cairo.surface.create_similar(other:cairo.surface, content:number, width:number, height:number) {block?}
Gura_DeclareClassMethod(surface, create_similar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_surface);
	DeclareArg(env, "content", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Create a new surface that is as compatible as possible with an existing surface.\n"
	"For example the new surface will have the same fallback resolution and font options as other.\n"
	"Generally, the new surface will also use the same backend as other, unless that is not possible for some reason.\n"
	"The type of the returned surface may be examined with cairo.surface#get_type().\n"
	"\n"
	"Initially the surface contents are all 0 (transparent if contents have transparency, black otherwise.)\n"
	"\n"
	"Use cairo.surface.create_similar_image() if you need an image surface which can be painted quickly to the target surface.\n"
	);
}

Gura_ImplementClassMethod(surface, create_similar)
{
	cairo_surface_t *other = Object_surface::GetObject(args, 0)->GetEntity();
	cairo_content_t content = static_cast<cairo_content_t>(args.GetInt(1));
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	cairo_surface_t *surface = ::cairo_surface_create_similar(other, content, width, height);
	Object_surface *pObjSurface = new Object_surface(surface);
	return ReturnValue(env, args, Value(pObjSurface));
}

// cairo.surface.create_similar(other:cairo.surface, content:number, width:number, height:number) {block?}
Gura_DeclareClassMethod(surface, create_similar_image)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_surface);
	DeclareArg(env, "format", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Create a new image surface that is as compatible as possible for uploading to and the use in conjunction with an existing surface.\n"
	"However, this surface can still be used like any normal image surface.\n"
	"\n"
	"Initially the surface contents are all 0 (transparent if contents have transparency, black otherwise.)\n"
	"\n"
	"Use cairo.surface.create_similar() if you don't need an image surface.\n"
	);
}

Gura_ImplementClassMethod(surface, create_similar_image)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	cairo_surface_t *other = Object_surface::GetObject(args, 0)->GetEntity();
	cairo_format_t format = static_cast<cairo_format_t>(args.GetInt(1));
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	cairo_surface_t *surface = ::cairo_surface_create_similar_image(other, format, width, height);
	Object_surface *pObjSurface = new Object_surface(surface);
	return ReturnValue(env, args, Value(pObjSurface));
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.surface.create_for_rectangle(target:cairo.surface, x:number, y:number, width:number, height:number) {block?}
Gura_DeclareClassMethod(surface, create_for_rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_surface);
	DeclareArg(env, "format", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Create a new surface that is a rectangle within the target surface.\n"
	"All operations drawn to this surface are then clipped and translated onto the target surface.\n"
	"Nothing drawn via this sub-surface outside of its bounds is drawn onto the target surface,\n"
	"making this a useful method for passing constrained child surfaces to library routines that draw directly onto the parent surface,\n"
	"i.e. with no further backend allocations, double buffering or copies.\n"
	"\n"
	"*Note:* The semantics of subsurfaces have not been finalized yet unless the rectangle is in full device units,\n"
	"is contained within the extents of the target surface, and the target or subsurface's device transforms are not changed.\n"
	);
}

Gura_ImplementClassMethod(surface, create_for_rectangle)
{
	cairo_surface_t *target = Object_surface::GetObject(args, 0)->GetEntity();
	double x = args.GetDouble(1);
	double y = args.GetDouble(2);
	double width = args.GetDouble(3);
	double height = args.GetDouble(4);
	cairo_surface_t *surface = ::cairo_surface_create_for_rectangle(target, x, y, width, height);
	Object_surface *pObjSurface = new Object_surface(surface);
	return ReturnValue(env, args, Value(pObjSurface));
}

//#cairo_surface_t *cairo_surface_reference(cairo_surface_t *surface);
//#void cairo_surface_destroy(cairo_surface_t *surface);

// cairo.surface#status()
Gura_DeclareMethod(surface, status)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Checks whether an error has previously occurred for this surface.\n"
	);
}

Gura_ImplementMethod(surface, status)
{
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_status_t rtn = ::cairo_surface_status(surface);
	return Value(rtn);
}

// cairo.surface#finish():reduce
Gura_DeclareMethod(surface, finish)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This function finishes the surface and drops all references to external resources.\n"
	"For example, for the Xlib backend it means that cairo will no longer access the drawable, which can be freed.\n"
	"After calling cairo.surface#finish() the only valid operations on a surface are getting and setting user,\n"
	"referencing and destroying, and flushing and finishing it.\n"
	"Further drawing to the surface will not affect the surface but will instead trigger a cairo.STATUS_SURFACE_FINISHED error.\n"
	"\n"
	"When the last call to cairo_surface_destroy() decreases the reference count to zero,\n"
	"cairo will call cairo_surface_finish() if it hasn't been called already, before freeing the resources associated with the surface.\n"
	);
}

Gura_ImplementMethod(surface, finish)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_finish(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.surface#flush():reduce
Gura_DeclareMethod(surface, flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Do any pending drawing for the surface and also restore any temporary modifications cairo has made to the surface's state.\n"
	"This function must be called before switching from drawing on the surface with cairo to drawing on it directly with native APIs.\n"
	"If the surface doesn't support direct access, then this function does nothing.\n"
	);
}

Gura_ImplementMethod(surface, flush)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_flush(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.surface#get_device()
Gura_DeclareMethod(surface, get_device)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This function returns the device for a surface. See cairo.device.\n"
	);
}

Gura_ImplementMethod(surface, get_device)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_device_t *device = ::cairo_surface_get_device(surface);
	if (Is_error(sig, surface) || device == nullptr) return Value::Nil;
	Object_device *pObjDevice = new Object_device(::cairo_device_reference(device));
	return Value(pObjDevice);
}

// cairo.surface#get_font_options()
Gura_DeclareMethod(surface, get_font_options)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Retrieves the default font rendering options for the surface.\n"
	"This allows display surfaces to report the correct subpixel order for rendering on them,\n"
	"print surfaces to disable hinting of metrics and so forth.\n"
	"The result can then be used with cairo.scaled_font.create().\n"
	);
}

Gura_ImplementMethod(surface, get_font_options)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_font_options_t *options = ::cairo_font_options_create();
	::cairo_surface_get_font_options(surface, options);
	if (Is_error(sig, surface)) {
		::cairo_font_options_destroy(options);
		return Value::Nil;
	}
	Object_font_options *pObjFontOptions = new Object_font_options(options);
	return Value(pObjFontOptions);
}

// cairo.surface#get_content()
Gura_DeclareMethod(surface, get_content)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This function returns the content type of surface which indicates whether the surface contains color and/or alpha information.\n"
	"See cairo_content_t.\n"
	);
}

Gura_ImplementMethod(surface, get_content)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_content_t content = ::cairo_surface_get_content(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return Value(content);
}

// cairo.surface#mark_dirty():reduce
Gura_DeclareMethod(surface, mark_dirty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Tells cairo that drawing has been done to surface using means other than cairo, and that cairo should reread any cached areas.\n"
	"Note that you must call cairo.surface#flush() before doing such drawing.\n"
	);
}

Gura_ImplementMethod(surface, mark_dirty)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_mark_dirty(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.surface#mark_dirty_rectangle(x:number, y:number, width:number, height:number):reduce
Gura_DeclareMethod(surface, mark_dirty_rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Like cairo.surface#mark_dirty(), but drawing has been done only to the specified rectangle,\n"
	"so that cairo can retain cached contents for other parts of the surface.\n"
	"\n"
	"Any cached clip set on the surface will be reset by this function, to make sure that future cairo calls have the clip set that they expect.\n"
	);
}

Gura_ImplementMethod(surface, mark_dirty_rectangle)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_mark_dirty_rectangle(surface,
			args.GetInt(0), args.GetInt(1), args.GetInt(2), args.GetInt(3));
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.surface#set_device_offset(x_offset:number, y_offset:number):reduce
Gura_DeclareMethod(surface, set_device_offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x_offset", VTYPE_number);
	DeclareArg(env, "y_offset", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets an offset that is added to the device coordinates determined by the CTM when drawing to surface.\n"
	"One use case for this function is when we want to create a cairo.surface\n"
	"that redirects drawing for a portion of an onscreen surface to an offscreen surface\n"
	"in a way that is completely invisible to the user of the cairo API.\n"
	"Setting a transformation via cairo.context#translate() isn't sufficient to do this,\n"
	"since functions like cairo.context#device_to_user() will expose the hidden offset.\n"
	"\n"
	"Note that the offset affects drawing to the surface as well as using the surface in a source pattern.\n"
	);
}

Gura_ImplementMethod(surface, set_device_offset)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_set_device_offset(surface, args.GetDouble(0), args.GetDouble(1));
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.surface#get_device_offset()
Gura_DeclareMethod(surface, get_device_offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This function returns the previous device offset set by cairo.surface#set_device_offset().\n"
	);
}

Gura_ImplementMethod(surface, get_device_offset)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	double x_offset, y_offset;
	::cairo_surface_get_device_offset(surface, &x_offset, &y_offset);
	if (Is_error(sig, surface)) return Value::Nil;
	return CreateValueList(env, x_offset, y_offset);
}

// cairo.surface#set_fallback_resolution(x_pixels_per_inch:number, y_pixels_per_inch:number):reduce
Gura_DeclareMethod(surface, set_fallback_resolution)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x_pixels_per_inch", VTYPE_number);
	DeclareArg(env, "y_pixels_per_inch", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Set the horizontal and vertical resolution for image fallbacks.\n"
	"\n"
	"When certain operations aren't supported natively by a backend, cairo will fallback by rendering operations to an image and then overlaying that image onto the output.\n"
	"For backends that are natively vector-oriented, this function can be used to set the resolution used for these image fallbacks,\n"
	"(larger values will result in more detailed images, but also larger file sizes).\n"
	"\n"
	"Some examples of natively vector-oriented backends are the ps, pdf, and svg backends.\n"
	"\n"
	"For backends that are natively raster-oriented, image fallbacks are still possible,\n"
	"but they are always performed at the native device resolution.\n"
	"So this function has no effect on those backends.\n"
	"\n"
	"Note: The fallback resolution only takes effect at the time of completing a page (with cairo.context#show_page() or cairo.context#copy_page())\n"
	"so there is currently no way to have more than one fallback resolution in effect on a single page.\n"
	"\n"
	"The default fallback resoultion is 300 pixels per inch in both dimensions.\n"
	);
}

Gura_ImplementMethod(surface, set_fallback_resolution)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_set_fallback_resolution(surface, args.GetDouble(0), args.GetDouble(1));
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.surface#get_fallback_resolution()
Gura_DeclareMethod(surface, get_fallback_resolution)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This function returns the previous fallback resolution set by cairo.surface#set_fallback_resolution(), or default fallback resolution if never set.\n"
	);
}

Gura_ImplementMethod(surface, get_fallback_resolution)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	double x_pixels_per_inch, y_pixels_per_inch;
	::cairo_surface_get_fallback_resolution(surface, &x_pixels_per_inch, &y_pixels_per_inch);
	if (Is_error(sig, surface)) return Value::Nil;
	return CreateValueList(env, x_pixels_per_inch, y_pixels_per_inch);
}

// cairo.surface#get_type()
Gura_DeclareMethod(surface, get_type)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This function returns the type of the backend used to create a surface. See cairo_surface_type_t for available types.\n"
	);
}

Gura_ImplementMethod(surface, get_type)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_surface_type_t rtn = ::cairo_surface_get_type(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return Value(rtn);
}

// cairo.surface#get_reference_count()
Gura_DeclareMethod(surface, get_reference_count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns the current reference count of surface.\n"
	);
}

Gura_ImplementMethod(surface, get_reference_count)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	unsigned int rtn = cairo_surface_get_reference_count(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return Value(rtn);
}

//#cairo_status_t cairo_surface_set_user_data(cairo_surface_t *surface, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_surface_get_user_data(cairo_surface_t *surface, const cairo_user_data_key_t *key);

// cairo.surface#copy_page():reduce
Gura_DeclareMethod(surface, copy_page)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Emits the current page for backends that support multiple pages, but doesn't clear it,\n"
	"so that the contents of the current page will be retained for the next page.\n"
	"Use cairo.surface#show_page() if you want to get an empty page after the emission.\n"
	"\n"
	"There is a convenience function for this that takes a cairo.context, namely cairo.context#copy_page().\n"
	);
}

Gura_ImplementMethod(surface, copy_page)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_copy_page(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.surface#show_page():reduce
Gura_DeclareMethod(surface, show_page)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Emits and clears the current page for backends that support multiple pages.\n"
	"Use cairo.surface#copy_page() if you don't want to clear the page.\n"
	"\n"
	"There is a convenience function for this that takes a cairo.context, namely cairo.context#show_page().\n"
	);
}

Gura_ImplementMethod(surface, show_page)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_show_page(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.surface#has_show_text_glyphs()
Gura_DeclareMethod(surface, has_show_text_glyphs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns whether the surface supports sophisticated cairo.context#show_text_glyphs() operations.\n"
	"That is, whether it actually uses the provided text and cluster data to a cairo.context#show_text_glyphs() call.\n"
	"\n"
	"Note: Even if this function returns false, a cairo.context#show_text_glyphs() operation targeted at surface will still succeed.\n"
	"It just will act like a cairo.context#show_glyphs() operation.\n"
	"Users can use this function to avoid computing UTF-8 text and cluster mapping if the target surface does not use it.\n"
	);
}

Gura_ImplementMethod(surface, has_show_text_glyphs)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	bool rtn = ::cairo_surface_has_show_text_glyphs(surface)? true : false;
	if (Is_error(sig, surface)) return Value::Nil;
	return Value(rtn);
}

// cairo.surface#set_mime_data():reduce
Gura_DeclareMethod(surface, set_mime_data)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(surface, set_mime_data)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Nil;
}

// cairo.surface#get_mime_data()
Gura_DeclareMethod(surface, get_mime_data)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(surface, get_mime_data)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Nil;
}

// cairo.surface#supports_mime_type()
Gura_DeclareMethod(surface, supports_mime_type)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(surface, supports_mime_type)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Nil;
}

// cairo.surface#map_to_image(extents:cairo.rectangle_int)
Gura_DeclareMethod(surface, map_to_image)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "extents", VTYPE_rectangle_int);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(surface, map_to_image)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_rectangle_int_t &extents = Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_surface_t *rtn = ::cairo_surface_map_to_image(surface, &extents);
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Nil;
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.surface#unmap_image()
Gura_DeclareMethod(surface, unmap_image)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(surface, unmap_image)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Nil;
}

// cairo.surface#write_to_png(stream:stream:w):reduce
Gura_DeclareMethod(surface, write_to_png)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(surface, write_to_png)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	std::unique_ptr<Writer_Stream> pWriter(new Writer_Stream(sig, 0, 0,
											args.GetStream(0).Reference()));
	::cairo_surface_write_to_png_stream(surface, Writer_Stream::write_func, pWriter.get());
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// implementation of class surface
Gura_ImplementUserClassWithCast(surface)
{
	Gura_AssignMethod(surface, create_similar);
	Gura_AssignMethod(surface, create_similar_image);
	Gura_AssignMethod(surface, create_for_rectangle);
	Gura_AssignMethod(surface, status);
	Gura_AssignMethod(surface, finish);
	Gura_AssignMethod(surface, flush);
	Gura_AssignMethod(surface, get_device);
	Gura_AssignMethod(surface, get_font_options);
	Gura_AssignMethod(surface, get_content);
	Gura_AssignMethod(surface, mark_dirty);
	Gura_AssignMethod(surface, mark_dirty_rectangle);
	Gura_AssignMethod(surface, set_device_offset);
	Gura_AssignMethod(surface, get_device_offset);
	Gura_AssignMethod(surface, set_fallback_resolution);
	Gura_AssignMethod(surface, get_fallback_resolution);
	Gura_AssignMethod(surface, get_type);
	Gura_AssignMethod(surface, copy_page);
	Gura_AssignMethod(surface, show_page);
	Gura_AssignMethod(surface, has_show_text_glyphs);
	Gura_AssignMethod(surface, set_mime_data);
	Gura_AssignMethod(surface, get_mime_data);
	Gura_AssignMethod(surface, supports_mime_type);
	Gura_AssignMethod(surface, map_to_image);
	Gura_AssignMethod(surface, unmap_image);
	Gura_AssignMethod(surface, write_to_png);
}

Gura_ImplementCastFrom(surface)
{
	Signal &sig = GetSignal();
	Value valueCast(value);
	env.LookupClass(VTYPE_image)->CastFrom(env, valueCast, pDecl);
	if (valueCast.Is_image()) {
		Image *pImage = Object_image::GetObject(valueCast)->GetImage();
		cairo_surface_t *surface = CreateSurfaceFromImage(sig, pImage);
		if (sig.IsSignalled()) return false;
		value = Value(new Object_image_surface(surface, pImage->Reference()));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(surface)
{
	return false;
}

Gura_EndModuleScope(cairo)
