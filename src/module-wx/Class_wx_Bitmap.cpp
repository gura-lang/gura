//----------------------------------------------------------------------------
// wxBitmap
// extracted from bitmap.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Create);
Gura_DeclarePrivUserSymbol(Create_1);

//----------------------------------------------------------------------------
// Class derivation of wxBitmap
//----------------------------------------------------------------------------
class wx_Bitmap : public wxBitmap, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Bitmap *_pObj;
public:
	inline wx_Bitmap() : wxBitmap(), _pObj(nullptr) {}
	inline wx_Bitmap(const wxBitmap& bitmap) : wxBitmap(bitmap), _pObj(nullptr) {}
	//inline wx_Bitmap(const void* data, int type, int width, int height, int depth) : wxBitmap(data, type, width, height, depth), _pObj(nullptr) {}
	inline wx_Bitmap(const char bits[], int width, int height, int depth) : wxBitmap(bits, width, height, depth), _pObj(nullptr) {}
	inline wx_Bitmap(int width, int height, int depth) : wxBitmap(width, height, depth), _pObj(nullptr) {}
	inline wx_Bitmap(const char* const* bits) : wxBitmap(bits), _pObj(nullptr) {}
	inline wx_Bitmap(const wxString& name, wxBitmapType type) : wxBitmap(name, type), _pObj(nullptr) {}
	inline wx_Bitmap(const wxImage& img, int depth) : wxBitmap(img, depth), _pObj(nullptr) {}
	inline wx_Bitmap(const wxIcon& icon) : wxBitmap(icon), _pObj(nullptr) {}
	//virtual bool Create(int width, int height, int depth);
	//virtual bool Create(const void* data, int type, int width, int height, int depth);
	~wx_Bitmap();
	inline void AssocWithGura(Object_wx_Bitmap *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Bitmap::~wx_Bitmap()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Bitmap::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmap
//----------------------------------------------------------------------------
Gura_DeclareFunction(EmptyBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EmptyBitmap)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Bitmap *pEntity = new wx_Bitmap();
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Bitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareArg(env, "image", VTYPE_image, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Bitmap)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	Object_image *pObjImage = Object_image::GetObject(arg, 0);
	std::unique_ptr<wxImage> pImage(new wxImage(
		pObjImage->GetImage()->GetWidth(), pObjImage->GetImage()->GetHeight(), false));
	ConvertToWxImage(pObjImage->GetImage(), pImage.get());
	wx_Bitmap *pEntity = new wx_Bitmap(*pImage, -1);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(BitmapFromXPMData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareArg(env, "bits", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapFromXPMData)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	const char **bits = new const char *[arg.GetList(0).size()];
	size_t i = 0;
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		const Value &value = *pValue;
		bits[i++] = value.GetString();
	}
	wx_Bitmap *pEntity = new wx_Bitmap(bits);
	delete[] bits;
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Bitmap_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Bitmap_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	int data = arg.GetInt(0);
	int type = arg.GetInt(1);
	int width = arg.GetInt(2);
	int height = arg.GetInt(3);
	int depth = -1;
	if (arg.IsValid(4)) depth = arg.GetInt(4);
	wx_Bitmap *pEntity = new wx_Bitmap(data, type, width, height, depth);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(BitmapFromBits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareArg(env, "bits", VTYPE_binary, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapFromBits)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	const char *bits = arg.GetBinary(0).data();
	int width = arg.GetInt(1);
	int height = arg.GetInt(2);
	int depth = 1;
	if (arg.IsValid(3)) depth = arg.GetInt(3);
	wx_Bitmap *pEntity = new wx_Bitmap(bits, width, height, depth);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(BitmapWH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapWH)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	int depth = -1;
	if (arg.IsValid(2)) depth = arg.GetInt(2);
	wx_Bitmap *pEntity = new wx_Bitmap(width, height, depth);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(BitmapFromFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapFromFile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(arg.GetInt(1));
	wx_Bitmap *pEntity = new wx_Bitmap(name, type);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(BitmapFromIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapFromIcon)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxIcon *icon = Object_wx_Icon::GetObject(arg, 0)->GetEntity();
	wx_Bitmap *pEntity = new wx_Bitmap(*icon);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(BitmapFromImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareArg(env, "img", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapFromImage)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxImage *img = Object_wx_Image::GetObject(arg, 0)->GetEntity();
	int depth = -1;
	if (arg.IsValid(1)) depth = arg.GetInt(1);
	wx_Bitmap *pEntity = new wx_Bitmap(*img, depth);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareClassMethod(wx_Bitmap, AddHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_BitmapHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Bitmap, AddHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmapHandler *handler = Object_wx_BitmapHandler::GetObject(arg, 0)->GetEntity();
	wxBitmap::AddHandler(handler);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_Bitmap, CleanUpHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Bitmap, CleanUpHandlers)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap::CleanUpHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, ConvertToImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, ConvertToImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImage rtn = pThis->GetEntity()->ConvertToImage();
	return ReturnValue(env, arg, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Bitmap, CopyFromIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, CopyFromIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIcon *icon = Object_wx_Icon::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->CopyFromIcon(*icon);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	int depth = -1;
	if (arg.IsValid(2)) depth = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->Create(width, height, depth);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, Create_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int data = arg.GetInt(0);
	int type = arg.GetInt(1);
	int width = arg.GetInt(2);
	int height = arg.GetInt(3);
	int depth = -1;
	if (arg.IsValid(4)) depth = arg.GetInt(4);
	bool rtn = pThis->GetEntity()->Create(data, type, width, height, depth);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_Bitmap, FindHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Bitmap, FindHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxBitmapHandler *rtn = (wxBitmapHandler *)wxBitmap::FindHandler(name);
	return ReturnValue(env, arg, Value(new Object_wx_BitmapHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Bitmap, FindHandler_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Bitmap, FindHandler_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString extension = wxString::FromUTF8(arg.GetString(0));
	wxBitmapType bitmapType = static_cast<wxBitmapType>(arg.GetInt(1));
	wxBitmapHandler *rtn = (wxBitmapHandler *)wxBitmap::FindHandler(extension, bitmapType);
	return ReturnValue(env, arg, Value(new Object_wx_BitmapHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Bitmap, FindHandler_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Bitmap, FindHandler_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmapType bitmapType = static_cast<wxBitmapType>(arg.GetInt(0));
	wxBitmapHandler *rtn = (wxBitmapHandler *)wxBitmap::FindHandler(bitmapType);
	return ReturnValue(env, arg, Value(new Object_wx_BitmapHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Bitmap, GetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetDepth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetDepth();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_Bitmap, GetHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Bitmap, GetHandlers)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxList &rtn = wxBitmap::GetHandlers();
	return ReturnValue(env, arg, Value(new Object_wx_List(new wxList(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Bitmap, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetHeight();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, GetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetPalette)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPalette *rtn = (wxPalette *)pThis->GetEntity()->GetPalette();
	return ReturnValue(env, arg, Value(new Object_wx_Palette(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Bitmap, GetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetMask)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMask *rtn = (wxMask *)pThis->GetEntity()->GetMask();
	return ReturnValue(env, arg, Value(new Object_wx_Mask(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Bitmap, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, GetSubBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetSubBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	wxBitmap rtn = pThis->GetEntity()->GetSubBitmap(*rect);
	return ReturnValue(env, arg, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_Bitmap, InitStandardHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Bitmap, InitStandardHandlers)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap::InitStandardHandlers();
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_Bitmap, InsertHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_BitmapHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Bitmap, InsertHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmapHandler *handler = Object_wx_BitmapHandler::GetObject(arg, 0)->GetEntity();
	wxBitmap::InsertHandler(handler);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(arg.GetInt(1));
	bool rtn = pThis->GetEntity()->LoadFile(name, type);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_Bitmap, RemoveHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Bitmap, RemoveHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxBitmap::RemoveHandler(name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, SaveFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(arg.GetInt(1));
	wxPalette *palette = (wxPalette *)(nullptr);
	if (arg.IsValid(2)) palette = Object_wx_Palette::GetObject(arg, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->SaveFile(name, type, palette);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, SetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetDepth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int depth = arg.GetInt(0);
	pThis->GetEntity()->SetDepth(depth);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int height = arg.GetInt(0);
	pThis->GetEntity()->SetHeight(height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_wx_Mask, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetMask)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMask *mask = Object_wx_Mask::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetMask(mask);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "isOk", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Bitmap, SetOk)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int isOk = arg.GetInt(0);
	pThis->GetEntity()->SetOk(isOk);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetPalette)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPalette *palette = Object_wx_Palette::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetPalette(*palette);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	pThis->GetEntity()->SetWidth(width);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxBitmap
//----------------------------------------------------------------------------
Object_wx_Bitmap::~Object_wx_Bitmap()
{
}

Object *Object_wx_Bitmap::Clone() const
{
	return nullptr;
}

String Object_wx_Bitmap::ToString(bool exprFlag)
{
	String rtn("<wx.Bitmap:");
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
// Class implementation for wxBitmap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClassWithCast(wx_Bitmap)
{
	Gura_RealizeUserSymbol(Create);
	Gura_RealizeUserSymbol(Create_1);
	Gura_AssignFunction(EmptyBitmap);
	Gura_AssignFunction(Bitmap);
	Gura_AssignFunction(BitmapFromXPMData);
	Gura_AssignFunction(Bitmap_1);
	Gura_AssignFunction(BitmapFromBits);
	Gura_AssignFunction(BitmapWH);
	Gura_AssignFunction(BitmapFromFile);
	Gura_AssignFunction(BitmapFromIcon);
	Gura_AssignFunction(BitmapFromImage);
	Gura_AssignMethod(wx_Bitmap, AddHandler);
	Gura_AssignMethod(wx_Bitmap, CleanUpHandlers);
	Gura_AssignMethod(wx_Bitmap, ConvertToImage);
	Gura_AssignMethod(wx_Bitmap, CopyFromIcon);
	Gura_AssignMethod(wx_Bitmap, Create);
	Gura_AssignMethod(wx_Bitmap, Create_1);
	Gura_AssignMethod(wx_Bitmap, FindHandler);
	Gura_AssignMethod(wx_Bitmap, FindHandler_1);
	Gura_AssignMethod(wx_Bitmap, FindHandler_2);
	Gura_AssignMethod(wx_Bitmap, GetDepth);
	Gura_AssignMethod(wx_Bitmap, GetHandlers);
	Gura_AssignMethod(wx_Bitmap, GetHeight);
	Gura_AssignMethod(wx_Bitmap, GetPalette);
	Gura_AssignMethod(wx_Bitmap, GetMask);
	Gura_AssignMethod(wx_Bitmap, GetWidth);
	Gura_AssignMethod(wx_Bitmap, GetSubBitmap);
	Gura_AssignMethod(wx_Bitmap, InitStandardHandlers);
	Gura_AssignMethod(wx_Bitmap, InsertHandler);
	Gura_AssignMethod(wx_Bitmap, LoadFile);
	Gura_AssignMethod(wx_Bitmap, IsOk);
	Gura_AssignMethodEx(wx_Bitmap, IsOk, "Ok");
	Gura_AssignMethod(wx_Bitmap, RemoveHandler);
	Gura_AssignMethod(wx_Bitmap, SaveFile);
	Gura_AssignMethod(wx_Bitmap, SetDepth);
	Gura_AssignMethod(wx_Bitmap, SetHeight);
	Gura_AssignMethod(wx_Bitmap, SetMask);
	Gura_AssignMethod(wx_Bitmap, SetOk);
	Gura_AssignMethod(wx_Bitmap, SetPalette);
	Gura_AssignMethod(wx_Bitmap, SetWidth);
}

Gura_ImplementDescendantCreator(wx_Bitmap)
{
	return new Object_wx_Bitmap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_ImplementCastFrom(wx_Bitmap)
{
	if (!value.Is_image()) return false;
	Object_image *pObjImage = Object_image::GetObject(value);
	std::unique_ptr<wxImage> pImage(new wxImage(
		pObjImage->GetImage()->GetWidth(), pObjImage->GetImage()->GetHeight(), false));
	ConvertToWxImage(pObjImage->GetImage(), pImage.get());
	wx_Bitmap *pBitmap = new wx_Bitmap(*pImage, -1);
	Object_wx_Bitmap *pObj = new Object_wx_Bitmap(pBitmap, pBitmap, OwnerTrue);
	pBitmap->AssocWithGura(pObj);
	value = Value(pObj);
	return true;
}

Gura_ImplementCastTo(wx_Bitmap)
{
	return false;
}

Gura_EndModuleScope(wx)
