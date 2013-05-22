//----------------------------------------------------------------------------
// wxImage
// extracted from image.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Image: public wxImage, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Image *_pObj;
public:
	inline wx_Image() : wxImage(), _sig(NULL), _pObj(NULL) {}
	inline wx_Image(const wxImage& image) : wxImage(image), _sig(NULL), _pObj(NULL) {}
	//inline wx_Image(const wxBitmap& bitmap) : wxImage(bitmap), _sig(NULL), _pObj(NULL) {}
	inline wx_Image(int width, int height, bool clear) : wxImage(width, height, clear), _sig(NULL), _pObj(NULL) {}
	//inline wx_Image(int width, int height, unsigned char* data, bool static_data) : wxImage(width, height, data, static_data), _sig(NULL), _pObj(NULL) {}
	inline wx_Image(const wxString& name, long type, int index) : wxImage(name, type, index), _sig(NULL), _pObj(NULL) {}
	inline wx_Image(const wxString& name, const wxString& mimetype, int index) : wxImage(name, mimetype, index), _sig(NULL), _pObj(NULL) {}
	inline wx_Image(wxInputStream& stream, long type, int index) : wxImage(stream, type, index), _sig(NULL), _pObj(NULL) {}
	inline wx_Image(wxInputStream& stream, const wxString& mimetype, int index) : wxImage(stream, mimetype, index), _sig(NULL), _pObj(NULL) {}
	inline wx_Image(const char* const* xpmData) : wxImage(xpmData), _sig(NULL), _pObj(NULL) {}
	~wx_Image();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Image *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Image::~wx_Image()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Image::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxImage
//----------------------------------------------------------------------------
Gura_DeclareFunction(ImageEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ImageEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Image *pEntity = new wx_Image();
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Image)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "image", VTYPE_wx_Image, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxImage *image = Object_wx_Image::GetObject(args, 0)->GetEntity();
	wx_Image *pEntity = new wx_Image(*image);
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Image_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Image_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wx_Image *pEntity = new wx_Image(*bitmap);
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Image_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clear", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	bool clear = true;
	if (args.IsValid(2)) clear = args.GetBoolean(2);
	wx_Image *pEntity = new wx_Image(width, height, clear);
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Image_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	unsigned char data = args.GetUChar(2);
	bool static_data = ;
	if (args.IsValid(3)) static_data = args.GetBoolean(3);
	wx_Image *pEntity = new wx_Image(width, height, data, static_data);
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Image_4)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_4)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	long type = wxBITMAP_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetLong(1);
	int index = -1;
	if (args.IsValid(2)) index = args.GetInt(2);
	wx_Image *pEntity = new wx_Image(name, type, index);
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Image_5)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_5)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString mimetype = wxString::FromUTF8(args.GetString(1));
	int index = -1;
	if (args.IsValid(2)) index = args.GetInt(2);
	wx_Image *pEntity = new wx_Image(name, mimetype, index);
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Image_6)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_6)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	long type = wxBITMAP_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetLong(1);
	int index = -1;
	if (args.IsValid(2)) index = args.GetInt(2);
	wx_Image *pEntity = new wx_Image(*stream, type, index);
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Image_7)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_7)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxString mimetype = wxString::FromUTF8(args.GetString(1));
	int index = -1;
	if (args.IsValid(2)) index = args.GetInt(2);
	wx_Image *pEntity = new wx_Image(*stream, mimetype, index);
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Image_8)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Image));
	DeclareArg(env, "xpmData", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Image_8)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char xpmData = args.GetChar(0);
	wx_Image *pEntity = new wx_Image(xpmData);
	Object_wx_Image *pObj = Object_wx_Image::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Image(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Image, AddHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_ImageHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Image, AddHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxImageHandler *handler = Object_wx_ImageHandler::GetObject(args, 0)->GetEntity();
	wxImage::AddHandler(handler);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, CanRead)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, CanRead)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->CanRead(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, Blur)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "blurRadius", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Blur)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int blurRadius = args.GetInt(0);
	wxImage rtn = pThis->GetEntity()->Blur(blurRadius);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, BlurHorizontal)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "blurRadius", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, BlurHorizontal)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int blurRadius = args.GetInt(0);
	wxImage rtn = pThis->GetEntity()->BlurHorizontal(blurRadius);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, BlurVertical)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "blurRadius", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, BlurVertical)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int blurRadius = args.GetInt(0);
	wxImage rtn = pThis->GetEntity()->BlurVertical(blurRadius);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_Image, CleanUpHandlers)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Image, CleanUpHandlers)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxImage::CleanUpHandlers();
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, ComputeHistogram)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "histogram", VTYPE_wx_ImageHistogram, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, ComputeHistogram)
{
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageHistogram *histogram = Object_wx_ImageHistogram::GetObject(args, 0)->GetEntity();
	unsigned rtn = pThis->GetEntity()->ComputeHistogram(*histogram);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, ConvertAlphaToMask)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, ConvertAlphaToMask)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned threshold = 128;
	if (args.IsValid(0)) threshold = args.GetInt(0);
	bool rtn = pThis->GetEntity()->ConvertAlphaToMask(threshold);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, ConvertToGreyscale)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lr", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "lg", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "lb", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, ConvertToGreyscale)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double lr = 0.299;
	if (args.IsValid(0)) lr = args.GetDouble(0);
	double lg = 0.587;
	if (args.IsValid(1)) lg = args.GetDouble(1);
	double lb = 0.114;
	if (args.IsValid(2)) lb = args.GetDouble(2);
	wxImage rtn = pThis->GetEntity()->ConvertToGreyscale(lr, lg, lb);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, ConvertToMono)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, ConvertToMono)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned r = args.GetInt(0);
	unsigned g = args.GetInt(1);
	unsigned b = args.GetInt(2);
	wxImage rtn = pThis->GetEntity()->ConvertToMono(r, g, b);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Copy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Copy)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImage rtn = pThis->GetEntity()->Copy();
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clear", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Create)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	bool clear = true;
	if (args.IsValid(2)) clear = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->Create(width, height, clear);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, Destroy)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Image, Destroy)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Destroy();
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, FindFirstUnusedColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned char r = args.GetUChar(0);
	unsigned char g = args.GetUChar(1);
	unsigned char b = args.GetUChar(2);
	unsigned startR = 1;
	if (args.IsValid(3)) startR = args.GetInt(3);
	unsigned startG = 0;
	if (args.IsValid(4)) startG = args.GetInt(4);
	unsigned startB = 0;
	if (args.IsValid(5)) startB = args.GetInt(5);
	bool rtn = pThis->GetEntity()->FindFirstUnusedColour(r, g, b, startR, startG, startB);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Image, FindHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, FindHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxImageHandler *rtn = (wxImageHandler *)wxImage::FindHandler(name);
	return ReturnValue(env, sig, args, Value(new Object_wx_ImageHandler(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Image, FindHandler_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, FindHandler_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString extension = wxString::FromUTF8(args.GetString(0));
	long imageType = args.GetLong(1);
	wxImageHandler *rtn = (wxImageHandler *)wxImage::FindHandler(extension, imageType);
	return ReturnValue(env, sig, args, Value(new Object_wx_ImageHandler(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Image, FindHandler_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, FindHandler_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	long imageType = args.GetLong(0);
	wxImageHandler *rtn = (wxImageHandler *)wxImage::FindHandler(imageType);
	return ReturnValue(env, sig, args, Value(new Object_wx_ImageHandler(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Image, FindHandlerMime)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, FindHandlerMime)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString mimetype = wxString::FromUTF8(args.GetString(0));
	wxImageHandler *rtn = (wxImageHandler *)wxImage::FindHandlerMime(mimetype);
	return ReturnValue(env, sig, args, Value(new Object_wx_ImageHandler(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Image, GetImageExtWildcard)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, GetImageExtWildcard)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxImage::GetImageExtWildcard();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Image, GetAlphaXY)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetAlphaXY)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	unsigned rtn = pThis->GetEntity()->GetAlpha(x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetAlpha)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetAlpha)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImage *pEntity = pThis->GetEntity();
	char *rtn = reinterpret_cast<char *>(pEntity->GetAlpha());
	size_t bytes = pEntity->GetWidth() * pEntity->GetHeight();
	if (rtn == NULL || bytes == 0) return Value::Null;
	return ReturnValue(env, sig, args,
						Value(new Object_binary(env, rtn, bytes)));
}

Gura_DeclareMethod(wx_Image, GetBlue)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetBlue)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	unsigned rtn = pThis->GetEntity()->GetBlue(x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetData)
{
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned char rtn = pThis->GetEntity()->GetData();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, GetGreen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetGreen)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	unsigned rtn = pThis->GetEntity()->GetGreen(x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Image, GetImageCount)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, GetImageCount)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	long type = wxBITMAP_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetLong(1);
	int rtn = wxImage::GetImageCount(filename, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Image, GetImageCount_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, GetImageCount_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	long type = wxBITMAP_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetLong(1);
	int rtn = wxImage::GetImageCount(*stream, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Image, GetHandlers)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, GetHandlers)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxList &rtn = wxImage::GetHandlers();
	return ReturnValue(env, sig, args, Value(new Object_wx_List(new wxList(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, GetHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetHeight)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetMaskBlue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetMaskBlue)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetMaskBlue();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetMaskGreen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetMaskGreen)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetMaskGreen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetMaskRed)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetMaskRed)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetMaskRed();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetOrFindMaskColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*r", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*g", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*b", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetOrFindMaskColour)
{
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned *r = args.GetInt(0);
	unsigned *g = args.GetInt(1);
	unsigned *b = args.GetInt(2);
	bool rtn = pThis->GetEntity()->GetOrFindMaskColour(*r, *g, *b);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, GetPalette)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetPalette)
{
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxPalette &rtn = pThis->GetEntity()->GetPalette();
	return ReturnValue(env, sig, args, Value(new Object_wx_Palette(new wxPalette(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, GetRed)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetRed)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	unsigned rtn = pThis->GetEntity()->GetRed(x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetSubImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetSubImage)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxImage rtn = pThis->GetEntity()->GetSubImage(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, GetWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetWidth)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, HSVValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "h", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "s", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "v", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_Image, HSVValue)
{
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double h = 0.0;
	if (args.IsValid(0)) h = args.GetDouble(0);
	double s = 0.0;
	if (args.IsValid(1)) s = args.GetDouble(1);
	double v = 0.0;
	if (args.IsValid(2)) v = args.GetDouble(2);
	pThis->GetEntity()->HSVValue(h, s, v);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, HSVtoRGB)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, HSVtoRGB)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_Image, HasAlpha)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, HasAlpha)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasAlpha();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, HasMask)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, HasMask)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasMask();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, GetOption)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetOption)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetOption(name);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Image, GetOptionInt)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, GetOptionInt)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->GetOptionInt(name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, HasOption)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, HasOption)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasOption(name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, InitAlpha)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Image, InitAlpha)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->InitAlpha();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Image, InitStandardHandlers)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Image, InitStandardHandlers)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxImage::InitStandardHandlers();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Image, InsertHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_ImageHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Image, InsertHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxImageHandler *handler = Object_wx_ImageHandler::GetObject(args, 0)->GetEntity();
	wxImage::InsertHandler(handler);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, IsTransparent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, IsTransparent)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	unsigned threshold = 128;
	if (args.IsValid(2)) threshold = args.GetInt(2);
	bool rtn = pThis->GetEntity()->IsTransparent(x, y, threshold);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, LoadFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, LoadFile)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	long type = wxBITMAP_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetLong(1);
	int index = -1;
	if (args.IsValid(2)) index = args.GetInt(2);
	bool rtn = pThis->GetEntity()->LoadFile(name, type, index);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, LoadFile_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, LoadFile_1)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString mimetype = wxString::FromUTF8(args.GetString(1));
	int index = -1;
	if (args.IsValid(2)) index = args.GetInt(2);
	bool rtn = pThis->GetEntity()->LoadFile(name, mimetype, index);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, LoadFile_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, LoadFile_2)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	long type = args.GetLong(1);
	int index = -1;
	if (args.IsValid(2)) index = args.GetInt(2);
	bool rtn = pThis->GetEntity()->LoadFile(*stream, type, index);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, LoadFile_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, LoadFile_3)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxString mimetype = wxString::FromUTF8(args.GetString(1));
	int index = -1;
	if (args.IsValid(2)) index = args.GetInt(2);
	bool rtn = pThis->GetEntity()->LoadFile(*stream, mimetype, index);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, IsOk)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, RGBValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "r", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "g", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "b", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_Image, RGBValue)
{
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned r = 0;
	if (args.IsValid(0)) r = args.GetInt(0);
	unsigned g = 0;
	if (args.IsValid(1)) g = args.GetInt(1);
	unsigned b = 0;
	if (args.IsValid(2)) b = args.GetInt(2);
	pThis->GetEntity()->RGBValue(r, g, b);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, RGBtoHSV)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, RGBtoHSV)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareClassMethod(wx_Image, RemoveHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Image, RemoveHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxImage::RemoveHandler(name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, Mirror)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "horizontally", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Mirror)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool horizontally = true;
	if (args.IsValid(0)) horizontally = args.GetBoolean(0);
	wxImage rtn = pThis->GetEntity()->Mirror(horizontally);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Replace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "r1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "g1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "b1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "r2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "g2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "b2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, Replace)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned r1 = args.GetInt(0);
	unsigned g1 = args.GetInt(1);
	unsigned b1 = args.GetInt(2);
	unsigned r2 = args.GetInt(3);
	unsigned g2 = args.GetInt(4);
	unsigned b2 = args.GetInt(5);
	pThis->GetEntity()->Replace(r1, g1, b1, r2, g2, b2);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, Rescale)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "quality", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Rescale)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	int quality = wxIMAGE_QUALITY_NORMAL;
	if (args.IsValid(2)) quality = args.GetInt(2);
	wxImage &rtn = pThis->GetEntity()->Rescale(width, height, quality);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Resize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "green", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Resize)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxPoint *pos = Object_wx_Point::GetObject(args, 1)->GetEntity();
	int red = -1;
	if (args.IsValid(2)) red = args.GetInt(2);
	int green = -1;
	if (args.IsValid(3)) green = args.GetInt(3);
	int blue = -1;
	if (args.IsValid(4)) blue = args.GetInt(4);
	wxImage &rtn = pThis->GetEntity()->Resize(*size, *pos, red, green, blue);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Rotate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "rotationCentre", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "interpolating", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "offsetAfterRotation", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Rotate)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double angle = args.GetDouble(0);
	wxPoint *rotationCentre = Object_wx_Point::GetObject(args, 1)->GetEntity();
	bool interpolating = true;
	if (args.IsValid(2)) interpolating = args.GetBoolean(2);
	wxPoint *offsetAfterRotation = (wxPoint *)(NULL);
	if (args.IsValid(3)) offsetAfterRotation = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxImage rtn = pThis->GetEntity()->Rotate(angle, *rotationCentre, interpolating, offsetAfterRotation);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, RotateHue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, RotateHue)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double angle = args.GetDouble(0);
	pThis->GetEntity()->RotateHue(angle);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, Rotate90)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "clockwise", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Rotate90)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool clockwise = true;
	if (args.IsValid(0)) clockwise = args.GetBoolean(0);
	wxImage rtn = pThis->GetEntity()->Rotate90(clockwise);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, SaveFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	int type = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SaveFile(name, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SaveFile_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile_1)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString mimetype = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SaveFile(name, mimetype);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SaveFile_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile_2)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SaveFile(name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SaveFile_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile_3)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	int type = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SaveFile(*stream, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SaveFile_4)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "mimetype", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SaveFile_4)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxString mimetype = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SaveFile(*stream, mimetype);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, Scale)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "quality", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Scale)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	int quality = wxIMAGE_QUALITY_NORMAL;
	if (args.IsValid(2)) quality = args.GetInt(2);
	wxImage rtn = pThis->GetEntity()->Scale(width, height, quality);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, Size)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "green", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, Size)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxPoint *pos = Object_wx_Point::GetObject(args, 1)->GetEntity();
	int red = -1;
	if (args.IsValid(2)) red = args.GetInt(2);
	int green = -1;
	if (args.IsValid(3)) green = args.GetInt(3);
	int blue = -1;
	if (args.IsValid(4)) blue = args.GetInt(4);
	wxImage rtn = pThis->GetEntity()->Size(*size, *pos, red, green, blue);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Image, SetAlpha)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "alpha", VTYPE_binary, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SetAlpha)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned char alpha = NULL;
	const Binary &buff = args.GetBinary(0);
	wxImage *pEntity = pThis->GetEntity();
	pEntity->SetAlpha(NULL, false);
	size_t bytesDst = pEntity->GetWidth() * pEntity->GetHeight();
	if (bytesDst > buff.size()) {
		sig.SetError(ERR_ValueError, "not enough data");
		return Value::Null;
	}
	::memcpy(pEntity->GetAlpha(), buff.data(), bytesDst);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, SetAlphaXY)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetAlphaXY)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	unsigned alpha = args.GetInt(2);
	pThis->GetEntity()->SetAlpha(x, y, alpha);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, SetData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Image, SetData)
{
#if 0
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned char data = args.GetUChar(0);
	pThis->GetEntity()->SetData(data);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, SetMask)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "hasMask", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SetMask)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool hasMask = true;
	if (args.IsValid(0)) hasMask = args.GetBoolean(0);
	pThis->GetEntity()->SetMask(hasMask);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, SetMaskColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetMaskColour)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	pThis->GetEntity()->SetMaskColour(red, green, blue);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, SetMaskFromImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "mr", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mg", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mb", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Image, SetMaskFromImage)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImage *mask = Object_wx_Image::GetObject(args, 0)->GetEntity();
	unsigned mr = args.GetInt(1);
	unsigned mg = args.GetInt(2);
	unsigned mb = args.GetInt(3);
	bool rtn = pThis->GetEntity()->SetMaskFromImage(*mask, mr, mg, mb);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Image, SetOption)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetOption)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetOption(name, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, SetOption_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetOption_1)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	int value = args.GetInt(1);
	pThis->GetEntity()->SetOption(name, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, SetPalette)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetPalette)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPalette *palette = Object_wx_Palette::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPalette(*palette);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, SetRGB)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetRGB)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	unsigned red = args.GetInt(2);
	unsigned green = args.GetInt(3);
	unsigned blue = args.GetInt(4);
	pThis->GetEntity()->SetRGB(x, y, red, green, blue);
	return Value::Null;
}

Gura_DeclareMethod(wx_Image, SetRGBRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, SetRGBRect)
{
	Object_wx_Image *pThis = Object_wx_Image::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	unsigned red = args.GetInt(1);
	unsigned green = args.GetInt(2);
	unsigned blue = args.GetInt(3);
	pThis->GetEntity()->SetRGB(*rect, red, green, blue);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxImage
//----------------------------------------------------------------------------
Object_wx_Image::~Object_wx_Image()
{
}

Object *Object_wx_Image::Clone() const
{
	return NULL;
}

String Object_wx_Image::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Image:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Image::DoAssignConstructor(Environment &env, Signal sig)
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
}

//----------------------------------------------------------------------------
// Class implementation for wxImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClassWithCast(wx_Image)
{
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
	Gura_AssignMethod(wx_Image, GetImageCount);
	Gura_AssignMethod(wx_Image, GetImageCount_1);
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
	return new Object_wx_Image((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_ImplementCastFrom(wx_Image)
{
	if (value.IsImage()) {
		Object_image *pObjImage = Object_image::GetObject(value);
		wx_Image *pImage = new wx_Image(pObjImage->GetImage()->GetWidth(),
									pObjImage->GetImage()->GetHeight(), false);
		ConvertToWxImage(pObjImage->GetImage(), pImage);
		Object_wx_Image *pObj = new Object_wx_Image(pImage, pImage, OwnerTrue);
		pImage->AssocWithGura(sig, pObj);
		value = Value(pObj);
		return true;
	}
	return false;
}

Gura_ImplementCastTo(wx_Image)
{
	return false;
}

}}
