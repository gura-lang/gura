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
	Gura::Signal _sig;
	Object_wx_Bitmap *_pObj;
public:
	inline wx_Bitmap() : wxBitmap(), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Bitmap(const wxBitmap& bitmap) : wxBitmap(bitmap), _sig(nullptr), _pObj(nullptr) {}
	//inline wx_Bitmap(const void* data, int type, int width, int height, int depth) : wxBitmap(data, type, width, height, depth), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Bitmap(const char bits[], int width, int height, int depth) : wxBitmap(bits, width, height, depth), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Bitmap(int width, int height, int depth) : wxBitmap(width, height, depth), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Bitmap(const char* const* bits) : wxBitmap(bits), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Bitmap(const wxString& name, wxBitmapType type) : wxBitmap(name, type), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Bitmap(const wxImage& img, int depth) : wxBitmap(img, depth), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Bitmap(const wxIcon& icon) : wxBitmap(icon), _sig(nullptr), _pObj(nullptr) {}
	//virtual bool Create(int width, int height, int depth);
	//virtual bool Create(const void* data, int type, int width, int height, int depth);
	~wx_Bitmap();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Bitmap *pObj) {
		_sig = sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Bitmap *pEntity = new wx_Bitmap();
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	Object_image *pObjImage = Object_image::GetObject(args, 0);
	std::unique_ptr<wxImage> pImage(new wxImage(
		pObjImage->GetImage()->GetWidth(), pObjImage->GetImage()->GetHeight(), false));
	ConvertToWxImage(pObjImage->GetImage(), pImage.get());
	wx_Bitmap *pEntity = new wx_Bitmap(*pImage, -1);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	const char **bits = new const char *[args.GetList(0).size()];
	size_t i = 0;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		const Value &value = *pValue;
		bits[i++] = value.GetString();
	}
	wx_Bitmap *pEntity = new wx_Bitmap(bits);
	delete[] bits;
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int data = args.GetInt(0);
	int type = args.GetInt(1);
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	int depth = -1;
	if (args.IsValid(4)) depth = args.GetInt(4);
	wx_Bitmap *pEntity = new wx_Bitmap(data, type, width, height, depth);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
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
	if (!CheckWxReady(sig)) return Value::Null;
	const char *bits = args.GetBinary(0).data();
	int width = args.GetInt(1);
	int height = args.GetInt(2);
	int depth = 1;
	if (args.IsValid(3)) depth = args.GetInt(3);
	wx_Bitmap *pEntity = new wx_Bitmap(bits, width, height, depth);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	int depth = -1;
	if (args.IsValid(2)) depth = args.GetInt(2);
	wx_Bitmap *pEntity = new wx_Bitmap(width, height, depth);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(args.GetInt(1));
	wx_Bitmap *pEntity = new wx_Bitmap(name, type);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	wx_Bitmap *pEntity = new wx_Bitmap(*icon);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxImage *img = Object_wx_Image::GetObject(args, 0)->GetEntity();
	int depth = -1;
	if (args.IsValid(1)) depth = args.GetInt(1);
	wx_Bitmap *pEntity = new wx_Bitmap(*img, depth);
	Object_wx_Bitmap *pObj = Object_wx_Bitmap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Bitmap(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareClassMethod(wx_Bitmap, AddHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_BitmapHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Bitmap, AddHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmapHandler *handler = Object_wx_BitmapHandler::GetObject(args, 0)->GetEntity();
	wxBitmap::AddHandler(handler);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Bitmap, CleanUpHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Bitmap, CleanUpHandlers)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmap::CleanUpHandlers();
	return Value::Null;
}

Gura_DeclareMethod(wx_Bitmap, ConvertToImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, ConvertToImage)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImage rtn = pThis->GetEntity()->ConvertToImage();
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Bitmap, CopyFromIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, CopyFromIcon)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->CopyFromIcon(*icon);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	int depth = -1;
	if (args.IsValid(2)) depth = args.GetInt(2);
	bool rtn = pThis->GetEntity()->Create(width, height, depth);
	return ReturnValue(env, sig, args, Value(rtn));
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
#if 0
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int data = args.GetInt(0);
	int type = args.GetInt(1);
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	int depth = -1;
	if (args.IsValid(4)) depth = args.GetInt(4);
	bool rtn = pThis->GetEntity()->Create(data, type, width, height, depth);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Bitmap, FindHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Bitmap, FindHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxBitmapHandler *rtn = (wxBitmapHandler *)wxBitmap::FindHandler(name);
	return ReturnValue(env, sig, args, Value(new Object_wx_BitmapHandler(rtn, nullptr, OwnerFalse)));
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxString extension = wxString::FromUTF8(args.GetString(0));
	wxBitmapType bitmapType = static_cast<wxBitmapType>(args.GetInt(1));
	wxBitmapHandler *rtn = (wxBitmapHandler *)wxBitmap::FindHandler(extension, bitmapType);
	return ReturnValue(env, sig, args, Value(new Object_wx_BitmapHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Bitmap, FindHandler_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Bitmap, FindHandler_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmapType bitmapType = static_cast<wxBitmapType>(args.GetInt(0));
	wxBitmapHandler *rtn = (wxBitmapHandler *)wxBitmap::FindHandler(bitmapType);
	return ReturnValue(env, sig, args, Value(new Object_wx_BitmapHandler(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Bitmap, GetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetDepth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDepth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Bitmap, GetHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Bitmap, GetHandlers)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxList &rtn = wxBitmap::GetHandlers();
	return ReturnValue(env, sig, args, Value(new Object_wx_List(new wxList(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Bitmap, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetHeight)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, GetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetPalette)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPalette *rtn = (wxPalette *)pThis->GetEntity()->GetPalette();
	return ReturnValue(env, sig, args, Value(new Object_wx_Palette(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Bitmap, GetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetMask)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMask *rtn = (wxMask *)pThis->GetEntity()->GetMask();
	return ReturnValue(env, sig, args, Value(new Object_wx_Mask(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Bitmap, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetWidth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, GetSubBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, GetSubBitmap)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxBitmap rtn = pThis->GetEntity()->GetSubBitmap(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_Bitmap, InitStandardHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Bitmap, InitStandardHandlers)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmap::InitStandardHandlers();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Bitmap, InsertHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_BitmapHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Bitmap, InsertHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmapHandler *handler = Object_wx_BitmapHandler::GetObject(args, 0)->GetEntity();
	wxBitmap::InsertHandler(handler);
	return Value::Null;
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
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->LoadFile(name, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Bitmap, IsOk)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Bitmap, RemoveHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Bitmap, RemoveHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxBitmap::RemoveHandler(name);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(args.GetInt(1));
	wxPalette *palette = (wxPalette *)(nullptr);
	if (args.IsValid(2)) palette = Object_wx_Palette::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->SaveFile(name, type, palette);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Bitmap, SetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetDepth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int depth = args.GetInt(0);
	pThis->GetEntity()->SetDepth(depth);
	return Value::Null;
}

Gura_DeclareMethod(wx_Bitmap, SetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetHeight)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pThis->GetEntity()->SetHeight(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Bitmap, SetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_wx_Mask, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetMask)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMask *mask = Object_wx_Mask::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMask(mask);
	return Value::Null;
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
#if 0
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int isOk = args.GetInt(0);
	pThis->GetEntity()->SetOk(isOk);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Bitmap, SetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetPalette)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPalette *palette = Object_wx_Palette::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPalette(*palette);
	return Value::Null;
}

Gura_DeclareMethod(wx_Bitmap, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetWidth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetWidth(width);
	return Value::Null;
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
	pBitmap->AssocWithGura(sig, pObj);
	value = Value(pObj);
	return true;
}

Gura_ImplementCastTo(wx_Bitmap)
{
	return false;
}

Gura_EndModuleScope(wx)
