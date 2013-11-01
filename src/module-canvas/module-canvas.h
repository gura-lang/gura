//-----------------------------------------------------------------------------
// Gura canvas module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_CANVAS_H__
#define __GURA_MODULE_CANVAS_H__
#include <gura.h>

Gura_BeginModuleHeader(canvas)

Gura_DeclareUserSymbol(red);
Gura_DeclareUserSymbol(blue);
Gura_DeclareUserSymbol(green);
Gura_DeclareUserSymbol(cyan);
Gura_DeclareUserSymbol(light_blue);
Gura_DeclareUserSymbol(yellow);
Gura_DeclareUserSymbol(black);
Gura_DeclareUserSymbol(white);
Gura_DeclareUserSymbol(grey);

Gura_DeclareUserSymbol(solid);
Gura_DeclareUserSymbol(dot);
Gura_DeclareUserSymbol(dash);
Gura_DeclareUserSymbol(dot_dash);

Gura_DeclareUserSymbol(bdiagonal);
Gura_DeclareUserSymbol(cross);
Gura_DeclareUserSymbol(diagcross);
Gura_DeclareUserSymbol(fdiagonal);
Gura_DeclareUserSymbol(horizontal);
Gura_DeclareUserSymbol(vertical);

Gura_DeclareUserSymbol(normal);
Gura_DeclareUserSymbol(default);
Gura_DeclareUserSymbol(decorative);
Gura_DeclareUserSymbol(roman);
Gura_DeclareUserSymbol(script);
Gura_DeclareUserSymbol(swiss);
Gura_DeclareUserSymbol(modern);
Gura_DeclareUserSymbol(teletype);
Gura_DeclareUserSymbol(slant);
Gura_DeclareUserSymbol(italic);
Gura_DeclareUserSymbol(light);
Gura_DeclareUserSymbol(bold);

Gura_DeclareUserSymbol(n);
Gura_DeclareUserSymbol(ne);
Gura_DeclareUserSymbol(e);
Gura_DeclareUserSymbol(se);
Gura_DeclareUserSymbol(s);
Gura_DeclareUserSymbol(sw);
Gura_DeclareUserSymbol(w);
Gura_DeclareUserSymbol(nw);
Gura_DeclareUserSymbol(c);

//-----------------------------------------------------------------------------
// Anchor
//-----------------------------------------------------------------------------
enum Anchor {
	ANCHOR_N,
	ANCHOR_NE,
	ANCHOR_E,
	ANCHOR_SE,
	ANCHOR_S,
	ANCHOR_SW,
	ANCHOR_W,
	ANCHOR_NW,
	ANCHOR_C,
};

void DeclareAnchorAttrs(Function *pFunc);
Anchor GetAnchor(const SymbolSet &attrs);

//-----------------------------------------------------------------------------
// Color
//-----------------------------------------------------------------------------
struct Color {
	UChar _red, _blue, _green;
	inline Color() : _red(0), _blue(0), _green(0) {}
	inline Color(UChar red, UChar blue, UChar green) :
									_red(red), _blue(blue), _green(green) {}
	Color(Signal sig, const Value &value);
#if defined(GURA_ON_MSWIN)
	inline COLORREF ToWin32() const { return RGB(_red, _blue, _green); }
#endif
};

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
class Device {
protected:
	int _cntRef;
	Number _width, _height;
public:
	inline Device(Number width, Number height) : _cntRef(1),
											_width(width), _height(height) {}
	inline Device *IncRef() { _cntRef++; return this; }
	inline int DecRef() { _cntRef--; return _cntRef; }
	inline int GetRefCnt() const { return _cntRef; }
	inline static void Delete(Device *pDevice) {
		if (pDevice != NULL && pDevice->DecRef() <= 0) delete pDevice;
	}
	virtual ~Device();
	Value Initialize(Environment &env, Signal sig, const Function *pFuncBlock);
	virtual const char *GetName() const = 0;
	virtual void Close() = 0;
	virtual void Fill(Signal sig, const Value &color) = 0;
	virtual void SetPen(Signal sig, const Value &color, Number width, const Symbol *pSymbol) = 0;
	virtual void SetBrush(Signal sig, const Value &color, const Symbol *pSymbol) = 0;
	virtual void SetFont(Signal sig, Number height,
			const Symbol *family, const Symbol *style, const Symbol *weight,
			const char *faceName) = 0;
	virtual void SetTextColor(Signal sig, const Value &color) = 0;
	virtual void Text(Signal sig, Number x, Number y, const char *text, Number wdBound, Number htBound, Anchor anchor) = 0;
	virtual void TextRot(Signal sig, Number x, Number y, const char *text, Number angle) = 0;
	virtual void Line(Signal sig, Number x1, Number y1, Number x2, Number y2) = 0;
	virtual void Rectangle(Signal sig, Number x, Number y, Number width, Number height, Anchor anchor) = 0;
	virtual void Ellipse(Signal sig, Number x, Number y, Number width, Number height, Anchor anchor) = 0;
	virtual void Pie(Signal sig, Number x, Number y, Number width, Number height,
								Number degStart, Number degEnd, Anchor anchor) = 0;
	virtual void Polygon(Signal sig, const ValueList &xs, const ValueList &ys, bool closeFlag) = 0;
	virtual void Polygon(Signal sig, const ValueList &pts, bool closeFlag) = 0;
	inline Number GetWidth() const { return _width; }
	inline Number GetHeight() const { return _height; }
};

//-----------------------------------------------------------------------------
// Object_Canvas
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Canvas);

class Object_Canvas : public Object {
private:
	Device *_pDevice;
public:
	Gura_DeclareObjectAccessor(Canvas)
public:
	inline Object_Canvas(Environment &env, Device *pDevice) :
						Object(Gura_UserClass(Canvas)), _pDevice(pDevice) {}
	inline Object_Canvas(const Object_Canvas &obj) :
						Object(obj), _pDevice(obj._pDevice->IncRef()) {}
	virtual ~Object_Canvas();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	Device &Device() { return *_pDevice; }
};

//-----------------------------------------------------------------------------
// Device_EnhMetaFile
//-----------------------------------------------------------------------------
class Device_EnhMetaFile : public Device {
private:
	HDC _hdc;
	RECT _rc;
	LOGFONT _lf;
public:
	Device_EnhMetaFile(Signal sig, const char *fileName,
		Number width, Number height, const char *appName, const char *imageName);
	inline POINT ToPoint(Number x, Number y) {
		POINT pt;
		pt.x = static_cast<long>(x * 100);
		pt.y = static_cast<long>(y * 100) + _rc.bottom;
		return pt;
	}
	virtual ~Device_EnhMetaFile();
	virtual const char *GetName() const;
	virtual void Close();
	virtual void Fill(Signal sig, const Value &color);
	virtual void SetPen(Signal sig, const Value &color, Number width, const Symbol *pSymbol);
	virtual void SetBrush(Signal sig, const Value &color, const Symbol *pSymbol);
	virtual void SetFont(Signal sig, Number height,
			const Symbol *family, const Symbol *style, const Symbol *weight,
			const char *faceName);
	virtual void SetTextColor(Signal sig, const Value &color);
	virtual void Text(Signal sig, Number x, Number y, const char *text, Number wdBound, Number htBound, Anchor anchor);
	virtual void TextRot(Signal sig, Number x, Number y, const char *text, Number angle);
	virtual void Line(Signal sig, Number x1, Number y1, Number x2, Number y2);
	virtual void Rectangle(Signal sig, Number x, Number y, Number width, Number height, Anchor anchor);
	virtual void Ellipse(Signal sig, Number x, Number y, Number width, Number height, Anchor anchor);
	virtual void Pie(Signal sig, Number x, Number y, Number width, Number height,
								Number degStart, Number degEnd, Anchor anchor);
	virtual void Polygon(Signal sig, const ValueList &xs, const ValueList &ys, bool closeFlag);
	virtual void Polygon(Signal sig, const ValueList &pts, bool closeFlag);
private:
	static void PrepareSimpleLogfont(LOGFONT *plf, LONG lHeight, LPCTSTR pszFaceName);
	static void MakeRect(RECT *prc, const POINT &pt, int width, int height, Anchor anchor);
};

Gura_EndModuleHeader(canvas)

#endif
