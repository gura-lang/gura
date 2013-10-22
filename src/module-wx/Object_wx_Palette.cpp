//----------------------------------------------------------------------------
// wxPalette
// extracted from palette.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Palette: public wxPalette, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Palette *_pObj;
public:
	inline wx_Palette() : wxPalette(), _sig(NULL), _pObj(NULL) {}
	inline wx_Palette(const wxPalette& palette) : wxPalette(palette), _sig(NULL), _pObj(NULL) {}
	//inline wx_Palette(int n, const unsigned char* red, const unsigned char* green, const unsigned char* blue) : wxPalette(n, red, green, blue), _sig(NULL), _pObj(NULL) {}
	~wx_Palette();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Palette *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Palette::~wx_Palette()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Palette::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPalette
//----------------------------------------------------------------------------
Gura_DeclareFunction(PaletteEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Palette));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PaletteEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Palette *pEntity = new wx_Palette();
	Object_wx_Palette *pObj = Object_wx_Palette::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Palette(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Palette)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Palette));
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Palette)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPalette *palette = Object_wx_Palette::GetObject(args, 0)->GetEntity();
	wx_Palette *pEntity = new wx_Palette(*palette);
	Object_wx_Palette *pObj = Object_wx_Palette::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Palette(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Palette_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Palette));
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Palette_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int n = args.GetInt(0);
	unsigned char red = args.GetUChar(1);
	unsigned char green = args.GetUChar(2);
	unsigned char blue = args.GetUChar(3);
	wx_Palette *pEntity = new wx_Palette(n, red, green, blue);
	Object_wx_Palette *pObj = Object_wx_Palette::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Palette(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_Palette, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Palette, Create)
{
#if 0
	Object_wx_Palette *pThis = Object_wx_Palette::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	unsigned char red = args.GetUChar(1);
	unsigned char green = args.GetUChar(2);
	unsigned char blue = args.GetUChar(3);
	bool rtn = pThis->GetEntity()->Create(n, red, green, blue);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Palette, GetColoursCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Palette, GetColoursCount)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetColoursCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Palette, GetPixel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Palette, GetPixel)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	int rtn = pThis->GetEntity()->GetPixel(red, green, blue);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Palette, GetRGB)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pixel", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Palette, GetRGB)
{
#if 0
	Object_wx_Palette *pThis = Object_wx_Palette::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pixel = args.GetInt(0);
	unsigned char red = args.GetUChar(1);
	unsigned char green = args.GetUChar(2);
	unsigned char blue = args.GetUChar(3);
	bool rtn = pThis->GetEntity()->GetRGB(pixel, red, green, blue);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Palette, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Palette, IsOk)
{
	Object_wx_Palette *pThis = Object_wx_Palette::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPalette
//----------------------------------------------------------------------------
Object_wx_Palette::~Object_wx_Palette()
{
}

Object *Object_wx_Palette::Clone() const
{
	return NULL;
}

String Object_wx_Palette::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Palette:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxPalette
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Palette)
{
	Gura_AssignFunction(PaletteEmpty);
	Gura_AssignFunction(Palette);
	Gura_AssignFunction(Palette_1);
	Gura_AssignMethod(wx_Palette, Create);
	Gura_AssignMethod(wx_Palette, GetColoursCount);
	Gura_AssignMethod(wx_Palette, GetPixel);
	Gura_AssignMethod(wx_Palette, GetRGB);
	Gura_AssignMethod(wx_Palette, IsOk);
}

Gura_ImplementDescendantCreator(wx_Palette)
{
	return new Object_wx_Palette((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
