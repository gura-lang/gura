#ifndef __MODULE_CAIRO_H__
#define __MODULE_CAIRO_H__

#include <gura.h>
#if defined(HAVE_WINDOWS_H)
#define CAIRO_WIN32_STATIC_BUILD
#endif
#include <cairo.h>
#include <cairo-pdf.h>
#include <cairo-ps.h>
#include <cairo-svg.h>
#if defined(HAVE_WINDOWS_H)
#include <cairo-win32.h>
#endif

Gura_BeginModule(cairo)

Gura_DeclareUserSymbol(ascent);
Gura_DeclareUserSymbol(descent);
Gura_DeclareUserSymbol(height);
Gura_DeclareUserSymbol(image);
Gura_DeclareUserSymbol(max_x_advance);
Gura_DeclareUserSymbol(max_y_advance);
Gura_DeclareUserSymbol(stream);
Gura_DeclareUserSymbol(surface);
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(width);
Gura_DeclareUserSymbol(x_advance);
Gura_DeclareUserSymbol(x_bearing);
Gura_DeclareUserSymbol(y_advance);
Gura_DeclareUserSymbol(y_bearing);

extern const double NUM_PI;

class Writer;
class Object_surface;

//-----------------------------------------------------------------------------
// Object_context declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(context);

class Object_context : public Object {
private:
	cairo_t *_cr;
	AutoPtr<Object_surface> _pObjSurface;
public:
	Gura_DeclareObjectAccessor(context)
public:
	inline Object_context(cairo_t *cr, Object_surface *pObjSurface) :
		Object(Gura_UserClass(context)), _cr(cr), _pObjSurface(pObjSurface) {}
	virtual ~Object_context();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_t *GetContext() { return _cr; }
	inline Object_surface *GetSurfaceObj() { return _pObjSurface.get(); }
	void Destroy();
};

//-----------------------------------------------------------------------------
// Object_font_extents declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(font_extents);

class Object_font_extents : public Object {
private:
	cairo_font_extents_t _font_extents;
public:
	Gura_DeclareObjectAccessor(font_extents)
public:
	inline Object_font_extents(const cairo_font_extents_t &font_extents) :
			Object(Gura_UserClass(font_extents)), _font_extents(font_extents) {}
	virtual ~Object_font_extents();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_font_extents_t &GetEntity() { return _font_extents; }
};

//-----------------------------------------------------------------------------
// Object_text_extents declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(text_extents);

class Object_text_extents : public Object {
private:
	cairo_text_extents_t _text_extents;
public:
	Gura_DeclareObjectAccessor(text_extents)
public:
	inline Object_text_extents(const cairo_text_extents_t &text_extents) :
			Object(Gura_UserClass(text_extents)), _text_extents(text_extents) {}
	virtual ~Object_text_extents();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_text_extents_t &GetEntity() { return _text_extents; }
};

//-----------------------------------------------------------------------------
// Object_rectangle declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(rectangle);

class Object_rectangle : public Object {
private:
	cairo_rectangle_t _rectangle;
public:
	Gura_DeclareObjectAccessor(rectangle)
public:
	inline Object_rectangle(const cairo_rectangle_t &rectangle) :
					Object(Gura_UserClass(rectangle)), _rectangle(rectangle) {}
	virtual ~Object_rectangle();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_rectangle_t &GetEntity() { return _rectangle; }
};

//-----------------------------------------------------------------------------
// Object_rectangle_int declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(rectangle_int);

class Object_rectangle_int : public Object {
private:
	cairo_rectangle_int_t _rectangle;
public:
	Gura_DeclareObjectAccessor(rectangle_int)
public:
	inline Object_rectangle_int(const cairo_rectangle_int_t &rectangle) :
					Object(Gura_UserClass(rectangle_int)), _rectangle(rectangle) {}
	virtual ~Object_rectangle_int();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_rectangle_int_t &GetEntity() { return _rectangle; }
};

//-----------------------------------------------------------------------------
// Object_region declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(region);

class Object_region : public Object {
private:
	cairo_region_t *_region;
public:
	Gura_DeclareObjectAccessor(region)
public:
	inline Object_region(cairo_region_t *region) :
						Object(Gura_UserClass(region)), _region(region) {}
	virtual ~Object_region();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_region_t *GetEntity() { return _region; }
};

//-----------------------------------------------------------------------------
// Object_font_face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(font_face);

class Object_font_face : public Object {
private:
	cairo_font_face_t *_font_face;
public:
	Gura_DeclareObjectAccessor(font_face)
public:
	inline Object_font_face(cairo_font_face_t *font_face) :
					Object(Gura_UserClass(font_face)), _font_face(font_face) {}
	virtual ~Object_font_face();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_font_face_t *GetEntity() { return _font_face; }
};

//-----------------------------------------------------------------------------
// Object_scaled_font declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(scaled_font);

class Object_scaled_font : public Object {
private:
	cairo_scaled_font_t *_scaled_font;
public:
	Gura_DeclareObjectAccessor(scaled_font)
public:
	inline Object_scaled_font(cairo_scaled_font_t *scaled_font) :
					Object(Gura_UserClass(scaled_font)), _scaled_font(scaled_font) {}
	virtual ~Object_scaled_font();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_scaled_font_t *GetEntity() { return _scaled_font; }
};

//-----------------------------------------------------------------------------
// Object_font_options declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(font_options);

class Object_font_options : public Object {
private:
	cairo_font_options_t *_options;
public:
	Gura_DeclareObjectAccessor(font_options)
public:
	inline Object_font_options(cairo_font_options_t *options) :
					Object(Gura_UserClass(font_options)), _options(options) {}
	virtual ~Object_font_options();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_font_options_t *GetEntity() { return _options; }
};

//-----------------------------------------------------------------------------
// Object_device declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(device);

class Object_device : public Object {
private:
	cairo_device_t *_device;
public:
	Gura_DeclareObjectAccessor(device)
public:
	inline Object_device(cairo_device_t *device) :
					Object(Gura_UserClass(device)), _device(device) {}
	virtual ~Object_device();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_device_t *GetEntity() { return _device; }
};

//-----------------------------------------------------------------------------
// Object_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(surface);

class Object_surface : public Object {
private:
	cairo_surface_t *_surface;
	AutoPtr<Object_image> _pObjImage;	// valid when initialized as image
	Writer *_pWriter;					// valid when initialized as pdf, ps
public:
	Gura_DeclareObjectAccessor(surface)
public:
	inline Object_surface(cairo_surface_t *surface) :
				Object(Gura_UserClass(surface)),
				_surface(surface), _pObjImage(NULL), _pWriter(NULL) {}
	inline Object_surface(cairo_surface_t *surface, Object_image *pObjImage) :
				Object(Gura_UserClass(surface)),
				_surface(surface), _pObjImage(pObjImage), _pWriter(NULL) {}
	inline Object_surface(cairo_surface_t *surface, Writer *pWriter) :
				Object(Gura_UserClass(surface)),
				_surface(surface), _pObjImage(NULL), _pWriter(pWriter) {}
	virtual ~Object_surface();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_surface_t *GetEntity() { return _surface; }
	inline Object_image *GetImageObj() { return _pObjImage.get(); }
	inline bool HasSize() const {
		return !_pObjImage.IsNull() || _pWriter != NULL;
	}
	double GetWidth() const;
	double GetHeight() const;
};

//-----------------------------------------------------------------------------
// Object_pattern declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(pattern);

class Object_pattern : public Object {
private:
	cairo_pattern_t *_pattern;
public:
	Gura_DeclareObjectAccessor(pattern)
public:
	inline Object_pattern(cairo_pattern_t *pattern) :
						Object(Gura_UserClass(pattern)), _pattern(pattern) {}
	virtual ~Object_pattern();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_pattern_t *GetEntity() { return _pattern; }
};

//-----------------------------------------------------------------------------
// Object_path declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(path);

class Object_path : public Object {
private:
	cairo_path_t *_path;
public:
	Gura_DeclareObjectAccessor(path)
public:
	inline Object_path(cairo_path_t *path) :
						Object(Gura_UserClass(path)), _path(path) {}
	virtual ~Object_path();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_path_t *GetEntity() { return _path; }
};

//-----------------------------------------------------------------------------
// Object_glyph declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(glyph);

class Object_glyph : public Object {
private:
	cairo_glyph_t _glyph;
public:
	Gura_DeclareObjectAccessor(glyph)
public:
	inline Object_glyph(const cairo_glyph_t &glyph) :
						Object(Gura_UserClass(glyph)), _glyph(glyph) {}
	virtual ~Object_glyph();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_glyph_t &GetEntity() { return _glyph; }
	inline const cairo_glyph_t &GetEntity() const { return _glyph; }
};

//-----------------------------------------------------------------------------
// Object_text_cluster declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(text_cluster);

class Object_text_cluster : public Object {
private:
	cairo_text_cluster_t _text_cluster;
public:
	Gura_DeclareObjectAccessor(text_cluster)
public:
	inline Object_text_cluster(const cairo_text_cluster_t &text_cluster) :
						Object(Gura_UserClass(text_cluster)), _text_cluster(text_cluster) {}
	virtual ~Object_text_cluster();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_text_cluster_t &GetEntity() { return _text_cluster; }
	inline const cairo_text_cluster_t &GetEntity() const { return _text_cluster; }
};

//-----------------------------------------------------------------------------
// Writer declaration
//-----------------------------------------------------------------------------
class Writer {
protected:
	Signal _sig;
	double _width, _height;
public:
	inline Writer(Signal sig, double width, double height) :
						_sig(sig), _width(width), _height(height) {}
	virtual ~Writer();
	virtual Stream *GetStream() = 0;
	inline double GetWidth() const { return _width; }
	inline double GetHeight() const { return _height; }
};

//-----------------------------------------------------------------------------
// Writer_Stream declaration
//-----------------------------------------------------------------------------
class Writer_Stream : public Writer {
private:
	AutoPtr<Stream> _pStream;
public:
	inline Writer_Stream(Signal sig, double width, double height, Stream *pStream) :
				Writer(sig, width, height), _pStream(pStream) {}
	virtual ~Writer_Stream();
	cairo_status_t WriteFunc(const unsigned char *data, unsigned int length);
	static cairo_status_t write_func(void *closure,
						const unsigned char *data, unsigned int length);
	virtual Stream *GetStream();
};

#if defined(HAVE_WINDOWS_H)
//-----------------------------------------------------------------------------
// Writer_EnhMetaFile declaration
//-----------------------------------------------------------------------------
class Writer_EnhMetaFile : public Writer {
private:
	HDC _hdc;
public:
	inline Writer_EnhMetaFile(Signal sig, double width, double height, HDC hdc) :
				Writer(sig, width, height), _hdc(hdc) {}
	virtual ~Writer_EnhMetaFile();
	virtual Stream *GetStream();
};

//-----------------------------------------------------------------------------
// Writer_WindowsDC declaration
//-----------------------------------------------------------------------------
class Writer_WindowsDC : public Writer {
private:
	HDC _hdc;
public:
	inline Writer_WindowsDC(Signal sig, double width, double height, HDC hdc) :
				Writer(sig, width, height), _hdc(hdc) {}
	virtual ~Writer_WindowsDC();
	virtual Stream *GetStream();
};
#endif

//-----------------------------------------------------------------------------
// Error handling
//-----------------------------------------------------------------------------
bool IsInvalid(Signal sig, cairo_t *cr);
bool IsError(Signal sig, cairo_status_t status);
bool IsError(Signal sig, cairo_t *cr);
bool IsError(Signal sig, cairo_pattern_t *pattern);
bool IsError(Signal sig, cairo_region_t *region);
bool IsError(Signal sig, cairo_font_face_t *font_face);
bool IsError(Signal sig, cairo_scaled_font_t *scaled_font);
bool IsError(Signal sig, cairo_device_t *device);
bool IsError(Signal sig, cairo_surface_t *surface);
bool IsError(Signal sig, cairo_font_options_t *options);

//-----------------------------------------------------------------------------
// Value converter
//-----------------------------------------------------------------------------
Value RectangleToValue(Environment &env, const cairo_rectangle_t &rectangle);
bool ValueListToRectangle(Signal sig, cairo_rectangle_t &rectangle, const ValueList &valList);
bool ValueListToRectangle(Signal sig, cairo_rectangle_int_t &rectangle, const ValueList &valList);
Object_matrix *CairoToMatrix(Environment &env, cairo_matrix_t &matrix);
bool MatrixToCairo(Signal sig, cairo_matrix_t &matrix, Object_matrix *pObjMatrix);
Value CreateValueList(Environment &env, double x1, double x2);
Value CreateValueList(Environment &env, double x1, double x2, double x3);
Value CreateValueList(Environment &env, double x1, double x2, double x3, double x4);
Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5);
Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5, double x6);
cairo_surface_t *CreateSurfaceFromImage(Signal sig, Object_image *pObjImage);
const char *SurfaceTypeToName(cairo_surface_type_t surface_type);

}}

#endif
