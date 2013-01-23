//----------------------------------------------------------------------------
// wxCursor
// extracted from cursor.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Cursor: public wxCursor, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Cursor *_pObj;
public:
	inline wx_Cursor() : wxCursor(), _sig(NULL), _pObj(NULL) {}
	inline wx_Cursor(const char bits[], int width, int height, int hotSpotX, int hotSpotY, const char maskBits[]) : wxCursor(bits, width, height, hotSpotX, hotSpotY, maskBits), _sig(NULL), _pObj(NULL) {}
#if defined(__WXMSW__)
	inline wx_Cursor(const wxString& cursorName, long type, int hotSpotX, int hotSpotY) : wxCursor(cursorName, type, hotSpotX, hotSpotY), _sig(NULL), _pObj(NULL) {}
#endif
	inline wx_Cursor(int cursorId) : wxCursor(cursorId), _sig(NULL), _pObj(NULL) {}
	inline wx_Cursor(const wxImage& image) : wxCursor(image), _sig(NULL), _pObj(NULL) {}
	inline wx_Cursor(const wxCursor& cursor) : wxCursor(cursor), _sig(NULL), _pObj(NULL) {}
	~wx_Cursor();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Cursor *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Cursor::~wx_Cursor()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Cursor::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCursor
//----------------------------------------------------------------------------
Gura_DeclareFunction(CursorEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CursorEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Cursor *pEntity = new wx_Cursor();
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Cursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	const Binary &_bits = args.GetBinary(0);
	const char *bits = _bits.data();
	int width = args.GetInt(1);
	int height = args.GetInt(2);
	size_t bytesRequired = ((width + 7) / 8) * height;
	if (_bits.size() < bytesRequired) {
		sig.SetError(ERR_ValueError, "bits doesn't have enough size of data");
		return Value::Null;
	}
	int hotSpotX = -1;
	if (args.IsValid(3)) hotSpotX = args.GetInt(3);
	int hotSpotY = -1;
	if (args.IsValid(4)) hotSpotY = args.GetInt(4);
	const char *maskBits = NULL;
	if (args.IsValid(5)) {
		const Binary &_maskBits = args.GetBinary(5);
		maskBits = _maskBits.data();
		if (_maskBits.size() < bytesRequired) {
			sig.SetError(ERR_ValueError, "maskBits doesn't have enough size of data");
			return Value::Null;
		}
	}
	//wxColour *fg = (wxColour *)(NULL);
	//if (args.IsValid(6)) fg = Object_wx_Colour::GetObject(args, 6)->GetEntity();
	//wxColour *bg = (wxColour *)(NULL);
	//if (args.IsValid(7)) bg = Object_wx_Colour::GetObject(args, 7)->GetEntity();
	wx_Cursor *pEntity = new wx_Cursor(bits, width, height, hotSpotX, hotSpotY, maskBits);
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(NamedCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareArg(env, "cursorName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "hotSpotX", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "hotSpotY", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NamedCursor)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	wxString cursorName = wxString::FromUTF8(args.GetString(0));
	long type = args.GetLong(1);
	int hotSpotX = 0;
	if (args.IsValid(2)) hotSpotX = args.GetInt(2);
	int hotSpotY = 0;
	if (args.IsValid(3)) hotSpotY = args.GetInt(3);
	wx_Cursor *pEntity = new wx_Cursor(cursorName, type, hotSpotX, hotSpotY);
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(StockCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareArg(env, "cursorId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StockCursor)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int cursorId = args.GetInt(0);
	wx_Cursor *pEntity = new wx_Cursor(cursorId);
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Cursor_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Cursor));
	DeclareArg(env, "image", VTYPE_wx_Image, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Cursor_3)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxImage *image = Object_wx_Image::GetObject(args, 0)->GetEntity();
	wx_Cursor *pEntity = new wx_Cursor(*image);
	Object_wx_Cursor *pObj = Object_wx_Cursor::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Cursor(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Cursor, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Cursor, IsOk)
{
	Object_wx_Cursor *pSelf = Object_wx_Cursor::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCursor
//----------------------------------------------------------------------------
Object_wx_Cursor::~Object_wx_Cursor()
{
}

Object *Object_wx_Cursor::Clone() const
{
	return NULL;
}

String Object_wx_Cursor::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Cursor:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Cursor::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(CursorEmpty);
	Gura_AssignFunction(Cursor);
	Gura_AssignFunction(NamedCursor);
	Gura_AssignFunction(StockCursor);
	Gura_AssignFunction(Cursor_3);
}

//----------------------------------------------------------------------------
// Class implementation for wxCursor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Cursor)
{
	Gura_AssignMethod(wx_Cursor, IsOk);
}

Gura_ImplementDescendantCreator(wx_Cursor)
{
	return new Object_wx_Cursor((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
