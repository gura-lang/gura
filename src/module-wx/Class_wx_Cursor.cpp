//----------------------------------------------------------------------------
// wxCursor
// extracted from cursor.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Cursor: public wxCursor, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Cursor *_pObj;
public:
	inline wx_Cursor() : wxCursor(), _pObj(nullptr) {}
	//inline wx_Cursor(const char bits[], int width, int height, int hotSpotX, int hotSpotY, const char maskBits[]) : wxCursor(bits, width, height, hotSpotX, hotSpotY, maskBits), _pObj(nullptr) {}
#if defined(__WXMSW__)
	inline wx_Cursor(const wxString& cursorName, wxBitmapType type, int hotSpotX, int hotSpotY) : wxCursor(cursorName, type, hotSpotX, hotSpotY), _pObj(nullptr) {}
#endif
	inline wx_Cursor(int cursorId) : wxCursor(cursorId), _pObj(nullptr) {}
	inline wx_Cursor(const wxImage& image) : wxCursor(image), _pObj(nullptr) {}
	inline wx_Cursor(const wxCursor& cursor) : wxCursor(cursor), _pObj(nullptr) {}
	~wx_Cursor();
	inline void AssocWithGura(Object_wx_Cursor *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Cursor::~wx_Cursor()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Cursor::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCursor
//----------------------------------------------------------------------------
Gura_DeclareFunction(CursorEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CursorEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Cursor *pEntity = new wx_Cursor();
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Cursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareArg(env, "bits", VTYPE_binary, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "hotSpotX", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "hotSpotY", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maskBits", VTYPE_binary, OCCUR_ZeroOrOnce);
	//DeclareArg(env, "fg", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	//DeclareArg(env, "bg", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Cursor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	const Binary &_bits = arg.GetBinary(0);
	const char *bits = _bits.data();
	int width = arg.GetInt(1);
	int height = arg.GetInt(2);
	size_t bytesRequired = ((width + 7) / 8) * height;
	if (_bits.size() < bytesRequired) {
		sig.SetError(ERR_ValueError, "bits doesn't have enough size of data");
		return Value::Nil;
	}
	int hotSpotX = -1;
	if (arg.IsValid(3)) hotSpotX = arg.GetInt(3);
	int hotSpotY = -1;
	if (arg.IsValid(4)) hotSpotY = arg.GetInt(4);
	const char *maskBits = nullptr;
	if (arg.IsValid(5)) {
		const Binary &_maskBits = arg.GetBinary(5);
		maskBits = _maskBits.data();
		if (_maskBits.size() < bytesRequired) {
			sig.SetError(ERR_ValueError, "maskBits doesn't have enough size of data");
			return Value::Nil;
		}
	}
	//wxColour *fg = (wxColour *)(nullptr);
	//if (arg.IsValid(6)) fg = Object_wx_Colour::GetObject(arg, 6)->GetEntity();
	//wxColour *bg = (wxColour *)(nullptr);
	//if (arg.IsValid(7)) bg = Object_wx_Colour::GetObject(arg, 7)->GetEntity();
	wx_Cursor *pEntity = new wx_Cursor(bits, width, height, hotSpotX, hotSpotY, maskBits);
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(NamedCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareArg(env, "cursorName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "hotSpotX", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "hotSpotY", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NamedCursor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if defined(__WXMSW__)
	wxString cursorName = wxString::FromUTF8(arg.GetString(0));
	wxBitmapType type = static_cast<wxBitmapType>(arg.GetLong(1));
	int hotSpotX = 0;
	if (arg.IsValid(2)) hotSpotX = arg.GetInt(2);
	int hotSpotY = 0;
	if (arg.IsValid(3)) hotSpotY = arg.GetInt(3);
	wx_Cursor *pEntity = new wx_Cursor(cursorName, type, hotSpotX, hotSpotY);
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareFunction(StockCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareArg(env, "cursorId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StockCursor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int cursorId = arg.GetInt(0);
	wx_Cursor *pEntity = new wx_Cursor(cursorId);
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Cursor_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareArg(env, "image", VTYPE_wx_Image, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Cursor_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxImage *image = Object_wx_Image::GetObject(arg, 0)->GetEntity();
	wx_Cursor *pEntity = new wx_Cursor(*image);
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Cursor, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Cursor, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Cursor *pThis = Object_wx_Cursor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCursor
//----------------------------------------------------------------------------
Object_wx_Cursor::~Object_wx_Cursor()
{
}

Object *Object_wx_Cursor::Clone() const
{
	return nullptr;
}

String Object_wx_Cursor::ToString(bool exprFlag)
{
	String rtn("<wx.Cursor:");
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
// Class implementation for wxCursor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Cursor)
{
	Gura_AssignFunction(CursorEmpty);
	Gura_AssignFunction(Cursor);
	Gura_AssignFunction(NamedCursor);
	Gura_AssignFunction(StockCursor);
	Gura_AssignFunction(Cursor_3);
	Gura_AssignMethod(wx_Cursor, IsOk);
}

Gura_ImplementDescendantCreator(wx_Cursor)
{
	return new Object_wx_Cursor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
