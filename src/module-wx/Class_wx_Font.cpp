//----------------------------------------------------------------------------
// wxFont
// extracted from font.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Font: public wxFont, public GuraObjectObserver {
private:
	Object_wx_Font *_pObj;
public:
	inline wx_Font() : wxFont(), _pObj(nullptr) {}
	inline wx_Font(const wxFont& font) : wxFont(font), _pObj(nullptr) {}
	inline wx_Font(int pointSize, wxFontFamily family, int style, wxFontWeight weight, const bool underline, const wxString& faceName, wxFontEncoding encoding) : wxFont(pointSize, family, style, weight, underline, faceName, encoding), _pObj(nullptr) {}
#if defined(__WXMSW__)
	inline wx_Font(const wxSize& pixelSize, wxFontFamily family, int style, wxFontWeight weight, const bool underline, const wxString& faceName, wxFontEncoding encoding) : wxFont(pixelSize, family, style, weight, underline, faceName, encoding), _pObj(nullptr) {}
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
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Font::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFont
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Font *pEntity = new wx_Font();
	Object_wx_Font *pObj = Object_wx_Font::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Font(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(Font)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
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
	Object_wx_Font *pObj = Object_wx_Font::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Font(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(FontEx)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
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
	Object_wx_Font *pObj = Object_wx_Font::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Font(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_Font, IsFixedWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, IsFixedWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsFixedWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Font, GetDefaultEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Font, GetDefaultEncoding)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFontEncoding rtn = wxFont::GetDefaultEncoding();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontEncoding rtn = pThis->GetEntity()->GetEncoding();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetFaceName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFaceName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetFamily)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetFamily)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFamily();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetFamilyString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetFamilyString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFamilyString();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetNativeFontInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetNativeFontInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxNativeFontInfo *rtn = pThis->GetEntity()->GetNativeFontInfo();
	Value value;
	if (rtn != nullptr) {
		value = Value(new Object_wx_NativeFontInfo(new wxNativeFontInfo(*rtn), nullptr, OwnerTrue));
	}
	return ReturnValue(env, args, value);
}

Gura_DeclareMethod(wx_Font, GetNativeFontInfoDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetNativeFontInfoDesc)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetNativeFontInfoDesc();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetNativeFontInfoUserDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetNativeFontInfoUserDesc)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetNativeFontInfoUserDesc();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPointSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetStyleString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetStyleString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetStyleString();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Font, GetUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetUnderlined();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetWeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetWeight();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, GetWeightString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, GetWeightString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetWeightString();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_Font, New)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
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
	return ReturnValue(env, args, Value(new Object_wx_Font(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Font, New_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Font, New_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int pointSize = args.GetInt(0);
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(1));
	int flags = wxFONTFLAG_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wxString faceName = wxT("");
	if (args.IsValid(3)) faceName = wxString::FromUTF8(args.GetString(3));
	wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
	if (args.IsValid(4)) encoding = static_cast<wxFontEncoding>(args.GetInt(4));
	wxFont *rtn = (wxFont *)wxFont::New(pointSize, family, flags, faceName, encoding);
	return ReturnValue(env, args, Value(new Object_wx_Font(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Font, New_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
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
	return ReturnValue(env, args, Value(new Object_wx_Font(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Font, New_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pixelSize", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Font, New_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSize *pixelSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(1));
	int flags = wxFONTFLAG_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wxString faceName = wxT("");
	if (args.IsValid(3)) faceName = wxString::FromUTF8(args.GetString(3));
	wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
	if (args.IsValid(4)) encoding = static_cast<wxFontEncoding>(args.GetInt(4));
	wxFont *rtn = (wxFont *)wxFont::New(*pixelSize, family, flags, faceName, encoding);
	return ReturnValue(env, args, Value(new Object_wx_Font(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Font, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Font, SetDefaultEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Font, SetDefaultEncoding)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	wxFont::SetDefaultEncoding(encoding);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	pThis->GetEntity()->SetEncoding(encoding);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, SetFaceName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString faceName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SetFaceName(faceName);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, SetFamily)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetFamily)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontFamily family = static_cast<wxFontFamily>(args.GetInt(0));
	pThis->GetEntity()->SetFamily(family);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetNativeFontInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, SetNativeFontInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString info = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SetNativeFontInfo(info);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, SetNativeFontInfoUserDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Font, SetNativeFontInfoUserDesc)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString info = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SetNativeFontInfoUserDesc(info);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Font, SetPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pointSize = args.GetInt(0);
	pThis->GetEntity()->SetPointSize(pointSize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int style = args.GetInt(0);
	pThis->GetEntity()->SetStyle(style);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "underlined", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool underlined = args.GetBoolean(0);
	pThis->GetEntity()->SetUnderlined(underlined);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetWeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontWeight weight = static_cast<wxFontWeight>(args.GetInt(0));
	pThis->GetEntity()->SetWeight(weight);
	return Value::Nil;
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_Font, wx_Font)
{
	wxFont *item1 = Object_wx_Font::GetObject(valueLeft)->GetEntity();
	wxFont *item2 = Object_wx_Font::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_Font, wx_Font)
{
	wxFont *item1 = Object_wx_Font::GetObject(valueLeft)->GetEntity();
	wxFont *item2 = Object_wx_Font::GetObject(valueRight)->GetEntity();
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

String Object_wx_Font::ToString(bool exprFlag)
{
	String rtn("<wx.Font:");
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
// Class implementation for wxFont
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Font)
{
	Gura_AssignFunction(FontEmpty);
	Gura_AssignFunction(Font);
	Gura_AssignFunction(FontEx);
	Gura_AssignBinaryOperator(Ne, wx_Font, wx_Font);
	Gura_AssignBinaryOperator(Ne, wx_Font, wx_Font);
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
}

Gura_ImplementDescendantCreator(wx_Font)
{
	return new Object_wx_Font((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
