//-----------------------------------------------------------------------------
// Gura module: cairo
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_CAIRO_H__
#define __GURA_MODULE_CAIRO_H__

#include <gura.h>
#if defined(GURA_ON_MSWIN)
#define CAIRO_WIN32_STATIC_BUILD
#endif
#include <cairo.h>
#include <cairo-pdf.h>
#include <cairo-ps.h>
#include <cairo-svg.h>
#if defined(GURA_ON_MSWIN)
#include <cairo-win32.h>
#endif

Gura_BeginModuleHeader(cairo)

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

//-----------------------------------------------------------------------------
// Reader declaration
//-----------------------------------------------------------------------------
class Reader {
protected:
	Signal _sig;
public:
	inline Reader(Signal sig) : _sig(sig) {}
	virtual ~Reader();
	virtual Stream *GetStream() = 0;
};

//-----------------------------------------------------------------------------
// Reader_Stream declaration
//-----------------------------------------------------------------------------
class Reader_Stream : public Reader {
private:
	AutoPtr<Stream> _pStream;
public:
	inline Reader_Stream(Signal sig, Stream *pStream) :
				Reader(sig), _pStream(pStream) {}
	virtual ~Reader_Stream();
	cairo_status_t ReadFunc(unsigned char *data, unsigned int length);
	static cairo_status_t read_func(void *closure,
						unsigned char *data, unsigned int length);
	virtual Stream *GetStream();
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

#if defined(GURA_ON_MSWIN)
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
bool Is_error(Signal sig, cairo_status_t status);
bool Is_error(Signal sig, cairo_t *cr);
bool Is_error(Signal sig, cairo_pattern_t *pattern);
bool Is_error(Signal sig, cairo_region_t *region);
bool Is_error(Signal sig, cairo_font_face_t *font_face);
bool Is_error(Signal sig, cairo_scaled_font_t *scaled_font);
bool Is_error(Signal sig, cairo_device_t *device);
bool Is_error(Signal sig, cairo_surface_t *surface);
bool Is_error(Signal sig, cairo_font_options_t *options);

//-----------------------------------------------------------------------------
// Value converter
//-----------------------------------------------------------------------------
Value RectangleToValue(Environment &env, const cairo_rectangle_t &rectangle);
bool ValueListToRectangle(Signal sig, cairo_rectangle_t &rectangle, const ValueList &valList);
bool ValueListToRectangle(Signal sig, cairo_rectangle_int_t &rectangle, const ValueList &valList);
Matrix *CairoToMatrix(const cairo_matrix_t &matrix);
bool MatrixToCairo(Signal sig, cairo_matrix_t &matrix, Matrix *pMat);
Value CreateValueList(Environment &env, double x1, double x2);
Value CreateValueList(Environment &env, double x1, double x2, double x3);
Value CreateValueList(Environment &env, double x1, double x2, double x3, double x4);
Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5);
Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5, double x6);
cairo_surface_t *CreateSurfaceFromImage(Signal sig, Image *pImage);
const char *SurfaceTypeToName(cairo_surface_type_t surface_type);

Gura_EndModuleHeader(cairo)

#endif
