//----------------------------------------------------------------------------
// wxFont
// extracted from font.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Font: public wxFont, public GuraObjectObserver {
private:
	Object_wx_Font *_pObj;
public:
	inline wx_Font() : wxFont(), _pObj(NULL) {}
	inline wx_Font(const wxFont& font) : wxFont(font), _pObj(NULL) {}
	inline wx_Font(int pointSize, wxFontFamily family, int style, wxFontWeight weight, const bool underline, const wxString& faceName, wxFontEncoding encoding) : wxFont(pointSize, family, style, weight, underline, faceName, encoding), _pObj(NULL) {}
#if defined(__WXMSW__)
	inline wx_Font(const wxSize& pixelSize, wxFontFamily family, int style, wxFontWeight weight, const bool underline, const wxString& faceName, wxFontEncoding encoding) : wxFont(pixelSize, family, style, weight, underline, faceName, encoding), _pObj(NULL) {}
#endif
	~wx_Font();
	inline void AssocWithGura(Object_wx_Font *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Font::~wx_Font()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Font::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFont
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Font *pEntity = new wx_Font();
	Object_wx_Font *pObj = Object_wx_Font::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Font(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Font)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "underline", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Font)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int pointSize = args.GetInt(0);
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(1));
	int style = args.GetInt(2);
	wxFontWeight weight = static_cast<wxFontWeight>(args.GetInt(3));
	bool underline = false;
	if (args.IsValid(4)) underline = args.GetBoolean(4);
	wxString faceName = wxT("");
	if (args.IsValid(5)) faceName = wxString::FromUTF8(args.GetString(5));
	wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
	if (args.IsValid(6)) encoding = static_cast<wxFontEncoding>(args.GetInt(6));
	wx_Font *pEntity = new wx_Font(pointSize, family, style, weight, underline, faceName, encoding);
	Object_wx_Font *pObj = Object_wx_Font::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Font(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(FontEx)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareArg(env, "pixelSize", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "underline", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontEx)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	wxSize *pixelSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(1));
	int style = args.GetInt(2);
	wxFontWeight weight = static_cast<wxFontWeight>(args.GetInt(3));
	bool underline = false;
	if (args.IsValid(4)) underline = args.GetBoolean(4);
	wxString faceName = wxT("");
	if (args.IsValid(5)) faceName = wxString::FromUTF8(args.GetString(5));
	wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
	if (args.IsValid(6)) encoding = static_cast<wxFontEncoding>(args.GetInt(6));
	wx_Font *pEntity = new wx_Font(*pixelSize, family, style, weight, underline, faceName, encoding);
	Object_wx_Font *pObj = Object_wx_Font::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Font(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_Font, IsFixedWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, IsFixedWidth)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsFixedWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Font, GetDefaultEncoding)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Font, GetDefaultEncoding)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFontEncoding rtn = wxFont::GetDefaultEncoding();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetEncoding)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetEncoding)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFontEncoding rtn = pSelf->GetEntity()->GetEncoding();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetFaceName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetFaceName)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetFaceName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetFamily)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetFamily)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetFamily();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetFamilyString)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetFamilyString)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetFamilyString();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetNativeFontInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetNativeFontInfo)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxNativeFontInfo *rtn = pSelf->GetEntity()->GetNativeFontInfo();
	Value value;
	if (rtn != NULL) {
		value = Value(new Object_wx_NativeFontInfo(new wxNativeFontInfo(*rtn), NULL, OwnerTrue));
	}
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Font, GetNativeFontInfoDesc)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetNativeFontInfoDesc)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetNativeFontInfoDesc();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetNativeFontInfoUserDesc)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetNativeFontInfoUserDesc)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetNativeFontInfoUserDesc();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetPointSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetPointSize)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetPointSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetStyle)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetStyleString)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetStyleString)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetStyleString();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetUnderlined)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetUnderlined)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetUnderlined();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetWeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetWeight)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetWeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetWeightString)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetWeightString)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetWeightString();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_Font, New)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "underline", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Font, New)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int pointSize = args.GetInt(0);
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(1));
	int style = args.GetInt(2);
	wxFontWeight weight = static_cast<wxFontWeight>(args.GetInt(3));
	bool underline = false;
	if (args.IsValid(4)) underline = args.GetBoolean(4);
	wxString faceName = wxT("");
	if (args.IsValid(5)) faceName = wxString::FromUTF8(args.GetString(5));
	wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
	if (args.IsValid(6)) encoding = static_cast<wxFontEncoding>(args.GetInt(6));
	wxFont *rtn = (wxFont *)wxFont::New(pointSize, family, style, weight, underline, faceName, encoding);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Font, New_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Font, New_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int pointSize = args.GetInt(0);
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(1));
	int flags = wxFONTFLAG_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wxString faceName = wxT("");
	if (args.IsValid(3)) faceName = wxString::FromUTF8(args.GetString(3));
	wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
	if (args.IsValid(4)) encoding = static_cast<wxFontEncoding>(args.GetInt(4));
	wxFont *rtn = (wxFont *)wxFont::New(pointSize, family, flags, faceName, encoding);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Font, New_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pixelSize", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "underline", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Font, New_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSize *pixelSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(1));
	int style = args.GetInt(2);
	wxFontWeight weight = static_cast<wxFontWeight>(args.GetInt(3));
	bool underline = false;
	if (args.IsValid(4)) underline = args.GetBoolean(4);
	wxString faceName = wxT("");
	if (args.IsValid(5)) faceName = wxString::FromUTF8(args.GetString(5));
	wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
	if (args.IsValid(6)) encoding = static_cast<wxFontEncoding>(args.GetInt(6));
	wxFont *rtn = (wxFont *)wxFont::New(*pixelSize, family, style, weight, underline, faceName, encoding);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Font, New_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pixelSize", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Font, New_3)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSize *pixelSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(1));
	int flags = wxFONTFLAG_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wxString faceName = wxT("");
	if (args.IsValid(3)) faceName = wxString::FromUTF8(args.GetString(3));
	wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
	if (args.IsValid(4)) encoding = static_cast<wxFontEncoding>(args.GetInt(4));
	wxFont *rtn = (wxFont *)wxFont::New(*pixelSize, family, flags, faceName, encoding);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Font, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, IsOk)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Font, SetDefaultEncoding)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Font, SetDefaultEncoding)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	wxFont::SetDefaultEncoding(encoding);
	return Value::Null;
}

Gura_DeclareMethod(wx_Font, SetEncoding)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetEncoding)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	pSelf->GetEntity()->SetEncoding(encoding);
	return Value::Null;
}

Gura_DeclareMethod(wx_Font, SetFaceName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, SetFaceName)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString faceName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->SetFaceName(faceName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, SetFamily)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetFamily)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(0));
	pSelf->GetEntity()->SetFamily(family);
	return Value::Null;
}

Gura_DeclareMethod(wx_Font, SetNativeFontInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, SetNativeFontInfo)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString info = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->SetNativeFontInfo(info);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, SetNativeFontInfoUserDesc)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, SetNativeFontInfoUserDesc)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString info = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->SetNativeFontInfoUserDesc(info);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, SetPointSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetPointSize)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pointSize = args.GetInt(0);
	pSelf->GetEntity()->SetPointSize(pointSize);
	return Value::Null;
}

Gura_DeclareMethod(wx_Font, SetStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetStyle)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int style = args.GetInt(0);
	pSelf->GetEntity()->SetStyle(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_Font, SetUnderlined)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "underlined", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetUnderlined)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool underlined = args.GetBoolean(0);
	pSelf->GetEntity()->SetUnderlined(underlined);
	return Value::Null;
}

Gura_DeclareMethod(wx_Font, SetWeight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetWeight)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFontWeight weight = static_cast<wxFontWeight>(args.GetInt(0));
	pSelf->GetEntity()->SetWeight(weight);
	return Value::Null;
}

Gura_DeclareMethod(wx_Font, __eq__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Font, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, __eq__)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	wxFont *item1 = Object_wx_Font::GetObject(args, 0)->GetEntity();
	wxFont *item2 = Object_wx_Font::GetObject(args, 1)->GetEntity();
	return *item1 == *item2;
}

Gura_DeclareMethod(wx_Font, __ne__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Font, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, __ne__)
{
	Object_wx_Font *pSelf = Object_wx_Font::GetSelfObj(args);
	wxFont *item1 = Object_wx_Font::GetObject(args, 0)->GetEntity();
	wxFont *item2 = Object_wx_Font::GetObject(args, 1)->GetEntity();
	return *item1 != *item2;
}

//----------------------------------------------------------------------------
// Object implementation for wxFont
//----------------------------------------------------------------------------
Object_wx_Font::~Object_wx_Font()
{
}

Object *Object_wx_Font::Clone() const
{
	wx_Font *pEntity = new wx_Font(*dynamic_cast<wxFont *>(_pEntity));
	Object_wx_Font *pObj = new Object_wx_Font(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return pObj;
}

String Object_wx_Font::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Font:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Font::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(FontEmpty);
	Gura_AssignFunction(Font);
	Gura_AssignFunction(FontEx);
}

//----------------------------------------------------------------------------
// Class implementation for wxFont
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Font)
{
	Gura_AssignMethod(wx_Font, IsFixedWidth);
	Gura_AssignMethod(wx_Font, GetDefaultEncoding);
	Gura_AssignMethod(wx_Font, GetEncoding);
	Gura_AssignMethod(wx_Font, GetFaceName);
	Gura_AssignMethod(wx_Font, GetFamily);
	Gura_AssignMethod(wx_Font, GetFamilyString);
	Gura_AssignMethod(wx_Font, GetNativeFontInfo);
	Gura_AssignMethod(wx_Font, GetNativeFontInfoDesc);
	Gura_AssignMethod(wx_Font, GetNativeFontInfoUserDesc);
	Gura_AssignMethod(wx_Font, GetPointSize);
	Gura_AssignMethod(wx_Font, GetStyle);
	Gura_AssignMethod(wx_Font, GetStyleString);
	Gura_AssignMethod(wx_Font, GetUnderlined);
	Gura_AssignMethod(wx_Font, GetWeight);
	Gura_AssignMethod(wx_Font, GetWeightString);
	Gura_AssignMethod(wx_Font, New);
	Gura_AssignMethod(wx_Font, New_1);
	Gura_AssignMethod(wx_Font, New_2);
	Gura_AssignMethod(wx_Font, New_3);
	Gura_AssignMethod(wx_Font, IsOk);
	Gura_AssignMethodEx(wx_Font, IsOk, "Ok");
	Gura_AssignMethod(wx_Font, SetDefaultEncoding);
	Gura_AssignMethod(wx_Font, SetEncoding);
	Gura_AssignMethod(wx_Font, SetFaceName);
	Gura_AssignMethod(wx_Font, SetFamily);
	Gura_AssignMethod(wx_Font, SetNativeFontInfo);
	Gura_AssignMethod(wx_Font, SetNativeFontInfoUserDesc);
	Gura_AssignMethod(wx_Font, SetPointSize);
	Gura_AssignMethod(wx_Font, SetStyle);
	Gura_AssignMethod(wx_Font, SetUnderlined);
	Gura_AssignMethod(wx_Font, SetWeight);
	Gura_AssignMethod(wx_Font, __eq__);
	Gura_AssignMethod(wx_Font, __ne__);
}

Gura_ImplementDescendantCreator(wx_Font)
{
	return new Object_wx_Font((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
