//----------------------------------------------------------------------------
// wxTextInputStream
// extracted from txtstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextInputStream: public wxTextInputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TextInputStream *_pObj;
public:
	inline wx_TextInputStream(wxInputStream& stream, const wxString& sep) : wxTextInputStream(stream, sep), _pObj(nullptr) {}
	//inline wx_TextInputStream(wxInputStream& stream, const wxString& sep, wxMBConv& conv) : wxTextInputStream(stream, sep, conv), _pObj(nullptr) {}
	~wx_TextInputStream();
	inline void AssocWithGura(Object_wx_TextInputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextInputStream::~wx_TextInputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextInputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextInputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxInputStream *stream = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	wxString sep = wxT(" \t");
	if (arg.IsValid(1)) sep = wxString::FromUTF8(arg.GetString(1));
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (arg.IsValid(2)) conv = Object_wx_MBConv::GetObject(arg, 2)->GetEntity();
	//wx_TextInputStream *pEntity = new wx_TextInputStream(*stream, sep, *conv);
	wx_TextInputStream *pEntity = new wx_TextInputStream(*stream, sep);
	Object_wx_TextInputStream *pObj = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_TextInputStream, Read8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read8)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int base = 10;
	if (arg.IsValid(0)) base = arg.GetInt(0);
	wxUint8 rtn = pThis->GetEntity()->Read8(base);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read8S)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read8S)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int base = 10;
	if (arg.IsValid(0)) base = arg.GetInt(0);
	wxInt8 rtn = pThis->GetEntity()->Read8S(base);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read16)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int base = 10;
	if (arg.IsValid(0)) base = arg.GetInt(0);
	wxUint16 rtn = pThis->GetEntity()->Read16(base);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read16S)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read16S)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int base = 10;
	if (arg.IsValid(0)) base = arg.GetInt(0);
	wxInt16 rtn = pThis->GetEntity()->Read16S(base);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read32)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int base = 10;
	if (arg.IsValid(0)) base = arg.GetInt(0);
	wxUint32 rtn = pThis->GetEntity()->Read32(base);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read32S)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read32S)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int base = 10;
	if (arg.IsValid(0)) base = arg.GetInt(0);
	wxInt32 rtn = pThis->GetEntity()->Read32S(base);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, GetChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, GetChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->GetChar();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, ReadDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, ReadDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double rtn = pThis->GetEntity()->ReadDouble();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, ReadLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, ReadLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->ReadLine();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

#if 0
Gura_DeclareMethod(wx_TextInputStream, ReadString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, ReadString)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->ReadString();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}
#endif

Gura_DeclareMethod(wx_TextInputStream, ReadWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, ReadWord)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->ReadWord();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextInputStream, SetStringSeparators)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, SetStringSeparators)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString sep = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetStringSeparators(sep);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxTextInputStream
//----------------------------------------------------------------------------
Object_wx_TextInputStream::~Object_wx_TextInputStream()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_TextInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TextInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TextInputStream:");
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
// Class implementation for wxTextInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextInputStream)
{
	Gura_AssignFunction(TextInputStream);
	Gura_AssignMethod(wx_TextInputStream, Read8);
	Gura_AssignMethod(wx_TextInputStream, Read8S);
	Gura_AssignMethod(wx_TextInputStream, Read16);
	Gura_AssignMethod(wx_TextInputStream, Read16S);
	Gura_AssignMethod(wx_TextInputStream, Read32);
	Gura_AssignMethod(wx_TextInputStream, Read32S);
	Gura_AssignMethod(wx_TextInputStream, GetChar);
	Gura_AssignMethod(wx_TextInputStream, ReadDouble);
	Gura_AssignMethod(wx_TextInputStream, ReadLine);
	//Gura_AssignMethod(wx_TextInputStream, ReadString);
	Gura_AssignMethod(wx_TextInputStream, ReadWord);
	Gura_AssignMethod(wx_TextInputStream, SetStringSeparators);
}

Gura_ImplementDescendantCreator(wx_TextInputStream)
{
	return new Object_wx_TextInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
