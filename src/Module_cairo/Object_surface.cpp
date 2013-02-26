#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_surface implementation
//-----------------------------------------------------------------------------
Object_surface::~Object_surface()
{
	if (_surface != NULL) {
		::cairo_surface_destroy(_surface);
		_surface = NULL;
	}
}

Object *Object_surface::Clone() const
{
	return NULL;
}

bool Object_surface::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	return true;
}

Value Object_surface::DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Environment &env = *this;
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		cairo_surface_type_t surface_type = ::cairo_surface_get_type(_surface);
		return Value(surface_type);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_surface::ToString(Signal sig, bool exprFlag)
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_surface);
	DeclareArg(env, "content", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(surface, create_similar)
{
	cairo_surface_t *other = Object_surface::GetObject(args, 0)->GetEntity();
	cairo_content_t content = static_cast<cairo_content_t>(args.GetInt(1));
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	cairo_surface_t *surface = ::cairo_surface_create_similar(other, content, width, height);
	Object_surface *pObjSurface = new Object_surface(surface);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

// cairo.surface.create_similar(other:cairo.surface, content:number, width:number, height:number) {block?}
Gura_DeclareClassMethod(surface, create_similar_image)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_surface);
	DeclareArg(env, "format", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(surface, create_similar_image)
{
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	cairo_surface_t *other = Object_surface::GetObject(args, 0)->GetEntity();
	cairo_format_t format = static_cast<cairo_format_t>(args.GetInt(1));
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	cairo_surface_t *surface = ::cairo_surface_create_similar_image(other, format, width, height);
	Object_surface *pObjSurface = new Object_surface(surface);
	return ReturnValue(env, sig, args, Value(pObjSurface));
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Null;
#endif
}

// cairo.surface.create_for_rectangle(target:cairo.surface, x:number, y:number, width:number, height:number) {block?}
Gura_DeclareClassMethod(surface, create_for_rectangle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_surface);
	DeclareArg(env, "format", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
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
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

//#cairo_surface_t *cairo_surface_reference(cairo_surface_t *surface);
//#void cairo_surface_destroy(cairo_surface_t *surface);

// cairo.surface#status()
Gura_DeclareMethod(surface, status)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, status)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_status_t rtn = ::cairo_surface_status(surface);
	return Value(rtn);
}

// cairo.surface#finish():reduce
Gura_DeclareMethod(surface, finish)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, finish)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_finish(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#flush():reduce
Gura_DeclareMethod(surface, flush)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, flush)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_flush(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#get_device()
Gura_DeclareMethod(surface, get_device)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_device)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_device_t *device = ::cairo_surface_get_device(surface);
	if (IsError(sig, surface) || device == NULL) return Value::Null;
	Object_device *pObjDevice = new Object_device(::cairo_device_reference(device));
	return Value(pObjDevice);
}

// cairo.surface#get_font_options()
Gura_DeclareMethod(surface, get_font_options)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_font_options)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_font_options_t *options = ::cairo_font_options_create();
	::cairo_surface_get_font_options(surface, options);
	if (IsError(sig, surface)) {
		::cairo_font_options_destroy(options);
		return Value::Null;
	}
	Object_font_options *pObjFontOptions = new Object_font_options(options);
	return Value(pObjFontOptions);
}

// cairo.surface#get_content()
Gura_DeclareMethod(surface, get_content)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_content)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_content_t content = ::cairo_surface_get_content(surface);
	if (IsError(sig, surface)) return Value::Null;
	return Value(content);
}

// cairo.surface#mark_dirty():reduce
Gura_DeclareMethod(surface, mark_dirty)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, mark_dirty)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_mark_dirty(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#mark_dirty_rectangle(x:number, y:number, width:number, height:number):reduce
Gura_DeclareMethod(surface, mark_dirty_rectangle)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementMethod(surface, mark_dirty_rectangle)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_mark_dirty_rectangle(surface,
			args.GetInt(0), args.GetInt(1), args.GetInt(2), args.GetInt(3));
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#set_device_offset(x_offset:number, y_offset:number):reduce
Gura_DeclareMethod(surface, set_device_offset)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x_offset", VTYPE_number);
	DeclareArg(env, "y_offset", VTYPE_number);
}

Gura_ImplementMethod(surface, set_device_offset)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_set_device_offset(surface, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#get_device_offset()
Gura_DeclareMethod(surface, get_device_offset)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_device_offset)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	double x_offset, y_offset;
	::cairo_surface_get_device_offset(surface, &x_offset, &y_offset);
	if (IsError(sig, surface)) return Value::Null;
	return CreateValueList(env, x_offset, y_offset);
}

// cairo.surface#set_fallback_resolution(x_pixels_per_inch:number, y_pixels_per_inch:number):reduce
Gura_DeclareMethod(surface, set_fallback_resolution)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x_pixels_per_inch", VTYPE_number);
	DeclareArg(env, "y_pixels_per_inch", VTYPE_number);
}

Gura_ImplementMethod(surface, set_fallback_resolution)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_set_fallback_resolution(surface, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#get_fallback_resolution()
Gura_DeclareMethod(surface, get_fallback_resolution)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_fallback_resolution)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	double x_pixels_per_inch, y_pixels_per_inch;
	::cairo_surface_get_fallback_resolution(surface, &x_pixels_per_inch, &y_pixels_per_inch);
	if (IsError(sig, surface)) return Value::Null;
	return CreateValueList(env, x_pixels_per_inch, y_pixels_per_inch);
}

// cairo.surface#get_type()
Gura_DeclareMethod(surface, get_type)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_type)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_surface_type_t rtn = ::cairo_surface_get_type(surface);
	if (IsError(sig, surface)) return Value::Null;
	return Value(rtn);
}

// cairo.surface#get_reference_count()
Gura_DeclareMethod(surface, get_reference_count)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_reference_count)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	unsigned int rtn = cairo_surface_get_reference_count(surface);
	if (IsError(sig, surface)) return Value::Null;
	return Value(rtn);
}

//#cairo_status_t cairo_surface_set_user_data(cairo_surface_t *surface, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_surface_get_user_data(cairo_surface_t *surface, const cairo_user_data_key_t *key);

// cairo.surface#copy_page():reduce
Gura_DeclareMethod(surface, copy_page)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, copy_page)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_copy_page(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#show_page():reduce
Gura_DeclareMethod(surface, show_page)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, show_page)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_show_page(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#has_show_text_glyphs()
Gura_DeclareMethod(surface, has_show_text_glyphs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, has_show_text_glyphs)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	bool rtn = ::cairo_surface_has_show_text_glyphs(surface)? true : false;
	if (IsError(sig, surface)) return Value::Null;
	return Value(rtn);
}

// cairo.surface#set_mime_data():reduce
Gura_DeclareMethod(surface, set_mime_data)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, set_mime_data)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// cairo.surface#get_mime_data()
Gura_DeclareMethod(surface, get_mime_data)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_mime_data)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// cairo.surface#supports_mime_type()
Gura_DeclareMethod(surface, supports_mime_type)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, supports_mime_type)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// cairo.surface#map_to_image()
Gura_DeclareMethod(surface, map_to_image)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, map_to_image)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// cairo.surface#unmap_image()
Gura_DeclareMethod(surface, unmap_image)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, unmap_image)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// cairo.surface#write_to_png(stream:stream:w):reduce
Gura_DeclareMethod(surface, write_to_png)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
}

Gura_ImplementMethod(surface, write_to_png)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	std::auto_ptr<Writer_Stream> pWriter(new Writer_Stream(sig, 0, 0,
									Stream::Reference(&args.GetStream(0))));
	::cairo_surface_write_to_png_stream(surface, Writer_Stream::write_func, pWriter.get());
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
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
	if (value.IsImage()) {
		Object_image *pObjImage = Object_image::Reference(value.GetImageObj());
		cairo_surface_t *surface = CreateSurfaceFromImage(sig, pObjImage);
		if (sig.IsSignalled()) {
			Object_image::Delete(pObjImage);
			return false;
		}
		value = Value(new Object_image_surface(surface, pObjImage));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(surface)
{
	return false;
}

}}
