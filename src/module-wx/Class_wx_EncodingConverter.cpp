//----------------------------------------------------------------------------
// wxEncodingConverter
// extracted from encconv.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_EncodingConverter: public wxEncodingConverter, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_EncodingConverter *_pObj;
public:
	inline wx_EncodingConverter() : wxEncodingConverter(), _pObj(nullptr) {}
	~wx_EncodingConverter();
	inline void AssocWithGura(Object_wx_EncodingConverter *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_EncodingConverter::~wx_EncodingConverter()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_EncodingConverter::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxEncodingConverter
//----------------------------------------------------------------------------
Gura_DeclareFunction(EncodingConverterEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_EncodingConverter));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EncodingConverterEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_EncodingConverter *pEntity = new wx_EncodingConverter();
	Object_wx_EncodingConverter *pObj = Object_wx_EncodingConverter::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_EncodingConverter(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_EncodingConverter, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "input_enc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "output_enc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "method", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EncodingConverter, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontEncoding input_enc = static_cast<wxFontEncoding>(args.GetInt(0));
	wxFontEncoding output_enc = static_cast<wxFontEncoding>(args.GetInt(1));
	int method = wxCONVERT_STRICT;
	if (args.IsValid(2)) method = args.GetInt(2);
	bool rtn = pThis->GetEntity()->Init(input_enc, output_enc, method);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_EncodingConverter, CanConvert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encIn", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "encOut", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_EncodingConverter, CanConvert)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFontEncoding encIn = static_cast<wxFontEncoding>(args.GetInt(0));
	wxFontEncoding encOut = static_cast<wxFontEncoding>(args.GetInt(1));
	bool rtn = wxEncodingConverter::CanConvert(encIn, encOut);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_EncodingConverter, Convert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char input = args.GetChar(0);
	char output = args.GetChar(1);
	bool rtn = pThis->GetEntity()->Convert(input, output);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wchar_t input = static_cast<wchar_t>(args.GetUShort(0));
	wchar_t output = static_cast<wchar_t>(args.GetUShort(1));
	bool rtn = pThis->GetEntity()->Convert(input, output);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_2)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char input = args.GetChar(0);
	wchar_t output = static_cast<wchar_t>(args.GetUShort(1));
	bool rtn = pThis->GetEntity()->Convert(input, output);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_3)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wchar_t input = static_cast<wchar_t>(args.GetUShort(0));
	char output = args.GetChar(1);
	bool rtn = pThis->GetEntity()->Convert(input, output);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

#if 0
Gura_DeclareMethod(wx_EncodingConverter, Convert_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Convert(str);
	return ReturnValue(env, args, Value(rtn));
}
#endif

Gura_DeclareMethod(wx_EncodingConverter, Convert_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_5)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wchar_t str = static_cast<wchar_t>(args.GetUShort(0));
	bool rtn = pThis->GetEntity()->Convert(str);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "input", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString input = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->Convert(input);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_EncodingConverter, GetPlatformEquivalents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "platform", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_EncodingConverter, GetPlatformEquivalents)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxFontEncoding enc = static_cast<wxFontEncoding>(args.GetInt(0));
	int platform = wxPLATFORM_CURRENT;
	if (args.IsValid(1)) platform = args.GetInt(1);
	wxFontEncodingArray rtn = wxEncodingConverter::GetPlatformEquivalents(enc, platform);
	return ReturnValue(env, args, Value(new Object_wx_FontEncodingArray(new wxFontEncodingArray(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_EncodingConverter, GetAllEquivalents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_EncodingConverter, GetAllEquivalents)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxFontEncoding enc = static_cast<wxFontEncoding>(args.GetInt(0));
	wxFontEncodingArray rtn = wxEncodingConverter::GetAllEquivalents(enc);
	return ReturnValue(env, args, Value(new Object_wx_FontEncodingArray(new wxFontEncodingArray(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxEncodingConverter
//----------------------------------------------------------------------------
Object_wx_EncodingConverter::~Object_wx_EncodingConverter()
{
}

Object *Object_wx_EncodingConverter::Clone() const
{
	return nullptr;
}

String Object_wx_EncodingConverter::ToString(bool exprFlag)
{
	String rtn("<wx.EncodingConverter:");
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
// Class implementation for wxEncodingConverter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EncodingConverter)
{
	Gura_AssignFunction(EncodingConverterEmpty);
	Gura_AssignMethod(wx_EncodingConverter, Init);
	Gura_AssignMethod(wx_EncodingConverter, CanConvert);
	Gura_AssignMethod(wx_EncodingConverter, Convert);
	Gura_AssignMethod(wx_EncodingConverter, Convert_1);
	Gura_AssignMethod(wx_EncodingConverter, Convert_2);
	Gura_AssignMethod(wx_EncodingConverter, Convert_3);
	//Gura_AssignMethod(wx_EncodingConverter, Convert_4);
	Gura_AssignMethod(wx_EncodingConverter, Convert_5);
	Gura_AssignMethod(wx_EncodingConverter, Convert_6);
	Gura_AssignMethod(wx_EncodingConverter, GetPlatformEquivalents);
	Gura_AssignMethod(wx_EncodingConverter, GetAllEquivalents);
}

Gura_ImplementDescendantCreator(wx_EncodingConverter)
{
	return new Object_wx_EncodingConverter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
