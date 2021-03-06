//----------------------------------------------------------------------------
// wxImage
// extracted from image.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Image: public wxImage, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Image *_pObj;
public:
	inline wx_Image() : wxImage(), _pObj(nullptr) {}
	inline wx_Image(const wxImage& image) : wxImage(image), _pObj(nullptr) {}
	//inline wx_Image(const wxBitmap& bitmap) : wxImage(bitmap), _pObj(nullptr) {}
	inline wx_Image(int width, int height, bool clear) : wxImage(width, height, clear), _pObj(nullptr) {}
	//inline wx_Image(int width, int height, unsigned char* data, bool static_data) : wxImage(width, height, data, static_data), _pObj(nullptr) {}
	inline wx_Image(const wxString& name, wxBitmapType type, int index) : wxImage(name, type, index), _pObj(nullptr) {}
	inline wx_Image(const wxString& name, const wxString& mimetype, int index) : wxImage(name, mimetype, index), _pObj(nullptr) {}
	inline wx_Image(wxInputStream& stream, wxBitmapType type, int index) : wxImage(stream, type, index), _pObj(nullptr) {}
	inline wx_Image(wxInputStream& stream, const wxString& mimetype, int index) : wxImage(stream, mimetype, index), _pObj(nullptr) {}
	inline wx_Image(const char* const* xpmData) : wxImage(xpmData), _pObj(nullptr) {}
	~wx_Image();
	inline void AssocWithGura(Object_wx_Image *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Image::~wx_Image()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Image::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxImage
//----------------------------------------------------------------------------
Gura_DeclareFunction(ImageEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ImageEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Image *pEntity = new wx_Image();
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Image)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "image", VTYPE_wx_Image, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxImage *image = Object_wx_Image::GetObject(arg, 0)->GetEntity();
	wx_Image *pEntity = new wx_Image(*image);
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Image_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Image_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	wx_Image *pEntity = new wx_Image(*bitmap);
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(Image_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clear", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	bool clear = true;
	if (arg.IsValid(2)) clear = arg.GetBoolean(2);
	wx_Image *pEntity = new wx_Image(width, height, clear);
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Image_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "static_data", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Image_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	unsigned char data = arg.GetUChar(2);
	bool static_data = ;
	if (arg.IsValid(3)) static_data = arg.GetBoolean(3);
	wx_Image *pEntity = new wx_Image(width, height, data, static_data);
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(Image_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_4)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxBitmapType type = wxBITMAP_TYPE_ANY;
	if (arg.IsValid(1)) type = static_cast<wxBitmapType>(arg.GetLong(1));
	int index = -1;
	if (arg.IsValid(2)) index = arg.GetInt(2);
	wx_Image *pEntity = new wx_Image(name, type, index);
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Image_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_5)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString mimetype = wxString::FromUTF8(arg.GetString(1));
	int index = -1;
	if (arg.IsValid(2)) index = arg.GetInt(2);
	wx_Image *pEntity = new wx_Image(name, mimetype, index);
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Image_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_6)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxInputStream *stream = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	wxBitmapType type = wxBITMAP_TYPE_ANY;
	if (arg.IsValid(1)) type = static_cast<wxBitmapType>(arg.GetLong(1));
	int index = -1;
	if (arg.IsValid(2)) index = arg.GetInt(2);
	wx_Image *pEntity = new wx_Image(*stream, type, index);
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Image_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_7)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxInputStream *stream = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	wxString mimetype = wxString::FromUTF8(arg.GetString(1));
	int index = -1;
	if (arg.IsValid(2)) index = arg.GetInt(2);
	wx_Image *pEntity = new wx_Image(*stream, mimetype, index);
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Image_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "xpmData", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_8)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char xpmData = arg.GetChar(0);
	wx_Image *pEntity = new wx_Image(xpmData);
	Object_wx_Image *pObj = Object_wx_Image::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_Image, AddHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_ImageHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Image, AddHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxImageHandler *handler = Object_wx_ImageHandler::GetObject(arg, 0)->GetEntity();
	wxImage::AddHandler(handler);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, CanRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, CanRead)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->CanRead(filename);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, Blur)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "blurRadius", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Blur)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int blurRadius = arg.GetInt(0);
	wxImage rtn = pThis->GetEntity()->Blur(blurRadius);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, BlurHorizontal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "blurRadius", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, BlurHorizontal)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int blurRadius = arg.GetInt(0);
	wxImage rtn = pThis->GetEntity()->BlurHorizontal(blurRadius);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, BlurVertical)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "blurRadius", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, BlurVertical)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int blurRadius = arg.GetInt(0);
	wxImage rtn = pThis->GetEntity()->BlurVertical(blurRadius);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_Image, CleanUpHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Image, CleanUpHandlers)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxImage::CleanUpHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, ComputeHistogram)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "histogram", VTYPE_wx_ImageHistogram, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, ComputeHistogram)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageHistogram *histogram = Object_wx_ImageHistogram::GetObject(arg, 0)->GetEntity();
	unsigned rtn = pThis->GetEntity()->ComputeHistogram(*histogram);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, ConvertAlphaToMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, ConvertAlphaToMask)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned threshold = 128;
	if (arg.IsValid(0)) threshold = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->ConvertAlphaToMask(threshold);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, ConvertToGreyscale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lr", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "lg", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "lb", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, ConvertToGreyscale)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double lr = 0.299;
	if (arg.IsValid(0)) lr = arg.GetDouble(0);
	double lg = 0.587;
	if (arg.IsValid(1)) lg = arg.GetDouble(1);
	double lb = 0.114;
	if (arg.IsValid(2)) lb = arg.GetDouble(2);
	wxImage rtn = pThis->GetEntity()->ConvertToGreyscale(lr, lg, lb);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, ConvertToMono)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, ConvertToMono)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned r = arg.GetInt(0);
	unsigned g = arg.GetInt(1);
	unsigned b = arg.GetInt(2);
	wxImage rtn = pThis->GetEntity()->ConvertToMono(r, g, b);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImage rtn = pThis->GetEntity()->Copy();
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clear", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	bool clear = true;
	if (arg.IsValid(2)) clear = arg.GetBoolean(2);
	bool rtn = pThis->GetEntity()->Create(width, height, clear);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Image, Destroy)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, FindFirstUnusedColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "startR", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "startG", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "startB", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, FindFirstUnusedColour)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned char r = arg.GetUChar(0);
	unsigned char g = arg.GetUChar(1);
	unsigned char b = arg.GetUChar(2);
	unsigned startR = 1;
	if (arg.IsValid(3)) startR = arg.GetInt(3);
	unsigned startG = 0;
	if (arg.IsValid(4)) startG = arg.GetInt(4);
	unsigned startB = 0;
	if (arg.IsValid(5)) startB = arg.GetInt(5);
	bool rtn = pThis->GetEntity()->FindFirstUnusedColour(r, g, b, startR, startG, startB);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_Image, FindHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, FindHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxImageHandler *rtn = (wxImageHandler *)wxImage::FindHandler(name);
	return ReturnValue(env, arg, Value(new Object_wx_ImageHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Image, FindHandler_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, FindHandler_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString extension = wxString::FromUTF8(arg.GetString(0));
	wxBitmapType imageType = static_cast<wxBitmapType>(arg.GetLong(1));
	wxImageHandler *rtn = (wxImageHandler *)wxImage::FindHandler(extension, imageType);
	return ReturnValue(env, arg, Value(new Object_wx_ImageHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Image, FindHandler_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, FindHandler_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmapType imageType = static_cast<wxBitmapType>(arg.GetLong(0));
	wxImageHandler *rtn = (wxImageHandler *)wxImage::FindHandler(imageType);
	return ReturnValue(env, arg, Value(new Object_wx_ImageHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Image, FindHandlerMime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, FindHandlerMime)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString mimetype = wxString::FromUTF8(arg.GetString(0));
	wxImageHandler *rtn = (wxImageHandler *)wxImage::FindHandlerMime(mimetype);
	return ReturnValue(env, arg, Value(new Object_wx_ImageHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Image, GetImageExtWildcard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, GetImageExtWildcard)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString rtn = wxImage::GetImageExtWildcard();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Image, GetAlphaXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetAlphaXY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	unsigned rtn = pThis->GetEntity()->GetAlpha(x, y);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetAlpha)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImage *pEntity = pThis->GetEntity();
	char *rtn = reinterpret_cast<char *>(pEntity->GetAlpha());
	size_t bytes = pEntity->GetWidth() * pEntity->GetHeight();
	if (rtn == nullptr || bytes == 0) return Value::Nil;
	return ReturnValue(env, arg,
						Value(new Object_binary(env, rtn, bytes)));
}

Gura_DeclareMethod(wx_Image, GetBlue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetBlue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	unsigned rtn = pThis->GetEntity()->GetBlue(x, y);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned char rtn = pThis->GetEntity()->GetData();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, GetGreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetGreen)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	unsigned rtn = pThis->GetEntity()->GetGreen(x, y);
	return ReturnValue(env, arg, Value(rtn));
}

#if 0
Gura_DeclareClassMethod(wx_Image, GetImageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, GetImageCount)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	long type = wxBITMAP_TYPE_ANY;
	if (arg.IsValid(1)) type = arg.GetLong(1);
	int rtn = wxImage::GetImageCount(filename, type);
	return ReturnValue(env, arg, Value(rtn));
}
#endif

#if 0
Gura_DeclareClassMethod(wx_Image, GetImageCount_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, GetImageCount_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxInputStream *stream = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	long type = wxBITMAP_TYPE_ANY;
	if (arg.IsValid(1)) type = arg.GetLong(1);
	int rtn = wxImage::GetImageCount(*stream, type);
	return ReturnValue(env, arg, Value(rtn));
}
#endif

Gura_DeclareClassMethod(wx_Image, GetHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, GetHandlers)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxList &rtn = wxImage::GetHandlers();
	return ReturnValue(env, arg, Value(new Object_wx_List(new wxList(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetHeight();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetMaskBlue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetMaskBlue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetMaskBlue();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetMaskGreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetMaskGreen)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetMaskGreen();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetMaskRed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetMaskRed)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetMaskRed();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetOrFindMaskColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*r", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*g", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*b", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetOrFindMaskColour)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned *r = arg.GetInt(0);
	unsigned *g = arg.GetInt(1);
	unsigned *b = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->GetOrFindMaskColour(*r, *g, *b);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, GetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetPalette)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxPalette &rtn = pThis->GetEntity()->GetPalette();
	return ReturnValue(env, arg, Value(new Object_wx_Palette(new wxPalette(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, GetRed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetRed)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	unsigned rtn = pThis->GetEntity()->GetRed(x, y);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetSubImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetSubImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	wxImage rtn = pThis->GetEntity()->GetSubImage(*rect);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, HSVValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "h", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "s", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "v", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_Image, HSVValue)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double h = 0.0;
	if (arg.IsValid(0)) h = arg.GetDouble(0);
	double s = 0.0;
	if (arg.IsValid(1)) s = arg.GetDouble(1);
	double v = 0.0;
	if (arg.IsValid(2)) v = arg.GetDouble(2);
	pThis->GetEntity()->HSVValue(h, s, v);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, HSVtoRGB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, HSVtoRGB)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_Image, HasAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, HasAlpha)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasAlpha();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, HasMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, HasMask)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasMask();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetOption)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = pThis->GetEntity()->GetOption(name);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Image, GetOptionInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetOptionInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	int rtn = pThis->GetEntity()->GetOptionInt(name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, HasOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, HasOption)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->HasOption(name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, InitAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Image, InitAlpha)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->InitAlpha();
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_Image, InitStandardHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Image, InitStandardHandlers)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxImage::InitStandardHandlers();
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_Image, InsertHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_ImageHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Image, InsertHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxImageHandler *handler = Object_wx_ImageHandler::GetObject(arg, 0)->GetEntity();
	wxImage::InsertHandler(handler);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, IsTransparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, IsTransparent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	unsigned threshold = 128;
	if (arg.IsValid(2)) threshold = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->IsTransparent(x, y, threshold);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxBitmapType type = wxBITMAP_TYPE_ANY;
	if (arg.IsValid(1)) type = static_cast<wxBitmapType>(arg.GetLong(1));
	int index = -1;
	if (arg.IsValid(2)) index = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->LoadFile(name, type, index);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, LoadFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, LoadFile_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString mimetype = wxString::FromUTF8(arg.GetString(1));
	int index = -1;
	if (arg.IsValid(2)) index = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->LoadFile(name, mimetype, index);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, LoadFile_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, LoadFile_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxInputStream *stream = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	wxBitmapType type = static_cast<wxBitmapType>(arg.GetLong(1));
	int index = -1;
	if (arg.IsValid(2)) index = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->LoadFile(*stream, type, index);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, LoadFile_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, LoadFile_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxInputStream *stream = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	wxString mimetype = wxString::FromUTF8(arg.GetString(1));
	int index = -1;
	if (arg.IsValid(2)) index = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->LoadFile(*stream, mimetype, index);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, RGBValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "r", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "g", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "b", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_Image, RGBValue)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned r = 0;
	if (arg.IsValid(0)) r = arg.GetInt(0);
	unsigned g = 0;
	if (arg.IsValid(1)) g = arg.GetInt(1);
	unsigned b = 0;
	if (arg.IsValid(2)) b = arg.GetInt(2);
	pThis->GetEntity()->RGBValue(r, g, b);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, RGBtoHSV)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, RGBtoHSV)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareClassMethod(wx_Image, RemoveHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, RemoveHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxImage::RemoveHandler(name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, Mirror)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "horizontally", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Mirror)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool horizontally = true;
	if (arg.IsValid(0)) horizontally = arg.GetBoolean(0);
	wxImage rtn = pThis->GetEntity()->Mirror(horizontally);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "r1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "g1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "b1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "r2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "g2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "b2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, Replace)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned r1 = arg.GetInt(0);
	unsigned g1 = arg.GetInt(1);
	unsigned b1 = arg.GetInt(2);
	unsigned r2 = arg.GetInt(3);
	unsigned g2 = arg.GetInt(4);
	unsigned b2 = arg.GetInt(5);
	pThis->GetEntity()->Replace(r1, g1, b1, r2, g2, b2);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, Rescale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "quality", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Rescale)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	wxImageResizeQuality quality = wxIMAGE_QUALITY_NORMAL;
	if (arg.IsValid(2)) quality = static_cast<wxImageResizeQuality>(arg.GetInt(2));
	wxImage &rtn = pThis->GetEntity()->Rescale(width, height, quality);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Resize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "green", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Resize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	wxPoint *pos = Object_wx_Point::GetObject(arg, 1)->GetEntity();
	int red = -1;
	if (arg.IsValid(2)) red = arg.GetInt(2);
	int green = -1;
	if (arg.IsValid(3)) green = arg.GetInt(3);
	int blue = -1;
	if (arg.IsValid(4)) blue = arg.GetInt(4);
	wxImage &rtn = pThis->GetEntity()->Resize(*size, *pos, red, green, blue);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "rotationCentre", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "interpolating", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "offsetAfterRotation", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Rotate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double angle = arg.GetDouble(0);
	wxPoint *rotationCentre = Object_wx_Point::GetObject(arg, 1)->GetEntity();
	bool interpolating = true;
	if (arg.IsValid(2)) interpolating = arg.GetBoolean(2);
	wxPoint *offsetAfterRotation = (wxPoint *)(nullptr);
	if (arg.IsValid(3)) offsetAfterRotation = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxImage rtn = pThis->GetEntity()->Rotate(angle, *rotationCentre, interpolating, offsetAfterRotation);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, RotateHue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, RotateHue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double angle = arg.GetDouble(0);
	pThis->GetEntity()->RotateHue(angle);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, Rotate90)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "clockwise", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Rotate90)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool clockwise = true;
	if (arg.IsValid(0)) clockwise = arg.GetBoolean(0);
	wxImage rtn = pThis->GetEntity()->Rotate90(clockwise);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(arg.GetInt(1));
	bool rtn = pThis->GetEntity()->SaveFile(name, type);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SaveFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString mimetype = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->SaveFile(name, mimetype);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SaveFile_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->SaveFile(name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SaveFile_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(arg, 0)->GetEntity();
	wxBitmapType type = static_cast<wxBitmapType>(arg.GetInt(1));
	bool rtn = pThis->GetEntity()->SaveFile(*stream, type);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SaveFile_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(arg, 0)->GetEntity();
	wxString mimetype = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->SaveFile(*stream, mimetype);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "quality", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Scale)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	wxImageResizeQuality quality = wxIMAGE_QUALITY_NORMAL;
	if (arg.IsValid(2)) quality = static_cast<wxImageResizeQuality>(arg.GetInt(2));
	wxImage rtn = pThis->GetEntity()->Scale(width, height, quality);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "green", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Size)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	wxPoint *pos = Object_wx_Point::GetObject(arg, 1)->GetEntity();
	int red = -1;
	if (arg.IsValid(2)) red = arg.GetInt(2);
	int green = -1;
	if (arg.IsValid(3)) green = arg.GetInt(3);
	int blue = -1;
	if (arg.IsValid(4)) blue = arg.GetInt(4);
	wxImage rtn = pThis->GetEntity()->Size(*size, *pos, red, green, blue);
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, SetAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "alpha", VTYPE_binary, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SetAlpha)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned char alpha = 0;
	const Binary &buff = arg.GetBinary(0);
	wxImage *pEntity = pThis->GetEntity();
	pEntity->SetAlpha(nullptr, false);
	size_t bytesDst = pEntity->GetWidth() * pEntity->GetHeight();
	if (bytesDst > buff.size()) {
		sig.SetError(ERR_ValueError, "not enough data");
		return Value::Nil;
	}
	::memcpy(pEntity->GetAlpha(), buff.data(), bytesDst);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, SetAlphaXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetAlphaXY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	unsigned alpha = arg.GetInt(2);
	pThis->GetEntity()->SetAlpha(x, y, alpha);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Image, SetData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned char data = arg.GetUChar(0);
	pThis->GetEntity()->SetData(data);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, SetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "hasMask", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SetMask)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool hasMask = true;
	if (arg.IsValid(0)) hasMask = arg.GetBoolean(0);
	pThis->GetEntity()->SetMask(hasMask);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, SetMaskColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetMaskColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned red = arg.GetInt(0);
	unsigned green = arg.GetInt(1);
	unsigned blue = arg.GetInt(2);
	pThis->GetEntity()->SetMaskColour(red, green, blue);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, SetMaskFromImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "mr", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mg", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mb", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SetMaskFromImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImage *mask = Object_wx_Image::GetObject(arg, 0)->GetEntity();
	unsigned mr = arg.GetInt(1);
	unsigned mg = arg.GetInt(2);
	unsigned mb = arg.GetInt(3);
	bool rtn = pThis->GetEntity()->SetMaskFromImage(*mask, mr, mg, mb);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SetOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetOption)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString value = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetOption(name, value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, SetOption_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetOption_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	int value = arg.GetInt(1);
	pThis->GetEntity()->SetOption(name, value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, SetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetPalette)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPalette *palette = Object_wx_Palette::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetPalette(*palette);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, SetRGB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetRGB)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	unsigned red = arg.GetInt(2);
	unsigned green = arg.GetInt(3);
	unsigned blue = arg.GetInt(4);
	pThis->GetEntity()->SetRGB(x, y, red, green, blue);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Image, SetRGBRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetRGBRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	unsigned red = arg.GetInt(1);
	unsigned green = arg.GetInt(2);
	unsigned blue = arg.GetInt(3);
	pThis->GetEntity()->SetRGB(*rect, red, green, blue);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxImage
//----------------------------------------------------------------------------
Object_wx_Image::~Object_wx_Image()
{
}

Object *Object_wx_Image::Clone() const
{
	return nullptr;
}

String Object_wx_Image::ToString(bool exprFlag)
{
	String rtn("<wx.Image:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClassWithCast(wx_Image)
{
	Gura_AssignFunction(ImageEmpty);
	Gura_AssignFunction(Image);
	Gura_AssignFunction(Image_1);
	Gura_AssignFunction(Image_2);
	Gura_AssignFunction(Image_3);
	Gura_AssignFunction(Image_4);
	Gura_AssignFunction(Image_5);
	Gura_AssignFunction(Image_6);
	Gura_AssignFunction(Image_7);
	Gura_AssignFunction(Image_8);
	Gura_AssignMethod(wx_Image, AddHandler);
	Gura_AssignMethod(wx_Image, CanRead);
	Gura_AssignMethod(wx_Image, Blur);
	Gura_AssignMethod(wx_Image, BlurHorizontal);
	Gura_AssignMethod(wx_Image, BlurVertical);
	Gura_AssignMethod(wx_Image, CleanUpHandlers);
	Gura_AssignMethod(wx_Image, ComputeHistogram);
	Gura_AssignMethod(wx_Image, ConvertAlphaToMask);
	Gura_AssignMethod(wx_Image, ConvertToGreyscale);
	Gura_AssignMethod(wx_Image, ConvertToMono);
	Gura_AssignMethod(wx_Image, Copy);
	Gura_AssignMethod(wx_Image, Create);
	Gura_AssignMethod(wx_Image, Destroy);
	Gura_AssignMethod(wx_Image, FindFirstUnusedColour);
	Gura_AssignMethod(wx_Image, FindHandler);
	Gura_AssignMethod(wx_Image, FindHandler_1);
	Gura_AssignMethod(wx_Image, FindHandler_2);
	Gura_AssignMethod(wx_Image, FindHandlerMime);
	Gura_AssignMethod(wx_Image, GetImageExtWildcard);
	Gura_AssignMethod(wx_Image, GetAlphaXY);
	Gura_AssignMethod(wx_Image, GetAlpha);
	Gura_AssignMethod(wx_Image, GetBlue);
	Gura_AssignMethod(wx_Image, GetData);
	Gura_AssignMethod(wx_Image, GetGreen);
	//Gura_AssignMethod(wx_Image, GetImageCount);
	//Gura_AssignMethod(wx_Image, GetImageCount_1);
	Gura_AssignMethod(wx_Image, GetHandlers);
	Gura_AssignMethod(wx_Image, GetHeight);
	Gura_AssignMethod(wx_Image, GetMaskBlue);
	Gura_AssignMethod(wx_Image, GetMaskGreen);
	Gura_AssignMethod(wx_Image, GetMaskRed);
	Gura_AssignMethod(wx_Image, GetOrFindMaskColour);
	Gura_AssignMethod(wx_Image, GetPalette);
	Gura_AssignMethod(wx_Image, GetRed);
	Gura_AssignMethod(wx_Image, GetSubImage);
	Gura_AssignMethod(wx_Image, GetWidth);
	Gura_AssignMethod(wx_Image, HSVValue);
	Gura_AssignMethod(wx_Image, HSVtoRGB);
	Gura_AssignMethod(wx_Image, HasAlpha);
	Gura_AssignMethod(wx_Image, HasMask);
	Gura_AssignMethod(wx_Image, GetOption);
	Gura_AssignMethod(wx_Image, GetOptionInt);
	Gura_AssignMethod(wx_Image, HasOption);
	Gura_AssignMethod(wx_Image, InitAlpha);
	Gura_AssignMethod(wx_Image, InitStandardHandlers);
	Gura_AssignMethod(wx_Image, InsertHandler);
	Gura_AssignMethod(wx_Image, IsTransparent);
	Gura_AssignMethod(wx_Image, LoadFile);
	Gura_AssignMethod(wx_Image, LoadFile_1);
	Gura_AssignMethod(wx_Image, LoadFile_2);
	Gura_AssignMethod(wx_Image, LoadFile_3);
	Gura_AssignMethod(wx_Image, IsOk);
	Gura_AssignMethod(wx_Image, RGBValue);
	Gura_AssignMethod(wx_Image, RGBtoHSV);
	Gura_AssignMethod(wx_Image, RemoveHandler);
	Gura_AssignMethod(wx_Image, Mirror);
	Gura_AssignMethod(wx_Image, Replace);
	Gura_AssignMethod(wx_Image, Rescale);
	Gura_AssignMethod(wx_Image, Resize);
	Gura_AssignMethod(wx_Image, Rotate);
	Gura_AssignMethod(wx_Image, RotateHue);
	Gura_AssignMethod(wx_Image, Rotate90);
	Gura_AssignMethod(wx_Image, SaveFile);
	Gura_AssignMethod(wx_Image, SaveFile_1);
	Gura_AssignMethod(wx_Image, SaveFile_2);
	Gura_AssignMethod(wx_Image, SaveFile_3);
	Gura_AssignMethod(wx_Image, SaveFile_4);
	Gura_AssignMethod(wx_Image, Scale);
	Gura_AssignMethod(wx_Image, Size);
	Gura_AssignMethod(wx_Image, SetAlpha);
	Gura_AssignMethod(wx_Image, SetAlphaXY);
	Gura_AssignMethod(wx_Image, SetData);
	Gura_AssignMethod(wx_Image, SetMask);
	Gura_AssignMethod(wx_Image, SetMaskColour);
	Gura_AssignMethod(wx_Image, SetMaskFromImage);
	Gura_AssignMethod(wx_Image, SetOption);
	Gura_AssignMethod(wx_Image, SetOption_1);
	Gura_AssignMethod(wx_Image, SetPalette);
	Gura_AssignMethod(wx_Image, SetRGB);
	Gura_AssignMethod(wx_Image, SetRGBRect);
}

Gura_ImplementDescendantCreator(wx_Image)
{
	return new Object_wx_Image((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_ImplementCastFrom(wx_Image)
{
	if (value.Is_image()) {
		Object_image *pObjImage = Object_image::GetObject(value);
		wx_Image *pImage = new wx_Image(pObjImage->GetImage()->GetWidth(),
									pObjImage->GetImage()->GetHeight(), false);
		ConvertToWxImage(pObjImage->GetImage(), pImage);
		Object_wx_Image *pObj = new Object_wx_Image(pImage, pImage, OwnerTrue);
		pImage->AssocWithGura(pObj);
		value = Value(pObj);
		return true;
	}
	return false;
}

Gura_ImplementCastTo(wx_Image)
{
	return false;
}

Gura_EndModuleScope(wx)
