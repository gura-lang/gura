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
	Gura::Signal _sig;
	Object_wx_TextInputStream *_pObj;
public:
	inline wx_TextInputStream(wxInputStream& stream, const wxString& sep) : wxTextInputStream(stream, sep), _sig(NULL), _pObj(NULL) {}
	//inline wx_TextInputStream(wxInputStream& stream, const wxString& sep, wxMBConv& conv) : wxTextInputStream(stream, sep, conv), _sig(NULL), _pObj(NULL) {}
	~wx_TextInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TextInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextInputStream::~wx_TextInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TextInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextInputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextInputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxString sep = wxT(" \t");
	if (args.IsValid(1)) sep = wxString::FromUTF8(args.GetString(1));
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	//wx_TextInputStream *pEntity = new wx_TextInputStream(*stream, sep, *conv);
	wx_TextInputStream *pEntity = new wx_TextInputStream(*stream, sep);
	Object_wx_TextInputStream *pObj = Object_wx_TextInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TextInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TextInputStream, Read8)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read8)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int base = 10;
	if (args.IsValid(0)) base = args.GetInt(0);
	wxUint8 rtn = pThis->GetEntity()->Read8(base);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read8S)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read8S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int base = 10;
	if (args.IsValid(0)) base = args.GetInt(0);
	wxInt8 rtn = pThis->GetEntity()->Read8S(base);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read16)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read16)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int base = 10;
	if (args.IsValid(0)) base = args.GetInt(0);
	wxUint16 rtn = pThis->GetEntity()->Read16(base);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read16S)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read16S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int base = 10;
	if (args.IsValid(0)) base = args.GetInt(0);
	wxInt16 rtn = pThis->GetEntity()->Read16S(base);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read32)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read32)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int base = 10;
	if (args.IsValid(0)) base = args.GetInt(0);
	wxUint32 rtn = pThis->GetEntity()->Read32(base);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, Read32S)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, Read32S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int base = 10;
	if (args.IsValid(0)) base = args.GetInt(0);
	wxInt32 rtn = pThis->GetEntity()->Read32S(base);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, GetChar)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, GetChar)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChar rtn = pThis->GetEntity()->GetChar();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, ReadDouble)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, ReadDouble)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double rtn = pThis->GetEntity()->ReadDouble();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextInputStream, ReadLine)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, ReadLine)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->ReadLine();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

#if 0
Gura_DeclareMethod(wx_TextInputStream, ReadString)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, ReadString)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->ReadString();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}
#endif

Gura_DeclareMethod(wx_TextInputStream, ReadWord)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextInputStream, ReadWord)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->ReadWord();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextInputStream, SetStringSeparators)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, SetStringSeparators)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString sep = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetStringSeparators(sep);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTextInputStream
//----------------------------------------------------------------------------
Object_wx_TextInputStream::~Object_wx_TextInputStream()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_TextInputStream::Clone() const
{
	return NULL;
}

String Object_wx_TextInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TextInputStream:");
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
	return new Object_wx_TextInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
