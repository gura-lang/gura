//----------------------------------------------------------------------------
// wxColour
// extracted from colour.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Colour: public wxColour, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Colour *_pObj;
public:
	inline wx_Colour() : wxColour(), _sig(NULL), _pObj(NULL) {}
	inline wx_Colour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : wxColour(red, green, blue, alpha), _sig(NULL), _pObj(NULL) {}
	inline wx_Colour(const wxString& colourNname) : wxColour(colourNname), _sig(NULL), _pObj(NULL) {}
	inline wx_Colour(const wxColour& colour) : wxColour(colour), _sig(NULL), _pObj(NULL) {}
	~wx_Colour();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Colour *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Colour::~wx_Colour()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Colour::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxColour
//----------------------------------------------------------------------------
Gura_DeclareFunction(ColourEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Colour));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Colour *pEntity = new wx_Colour();
	Object_wx_Colour *pObj = Object_wx_Colour::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Colour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Colour));
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Colour)
{
	if (!CheckWxReady(sig)) return Value::Null;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	unsigned alpha = wxALPHA_OPAQUE;
	if (args.IsValid(3)) alpha = args.GetInt(3);
	wx_Colour *pEntity = new wx_Colour(red, green, blue, alpha);
	Object_wx_Colour *pObj = Object_wx_Colour::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(NamedColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Colour));
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NamedColour)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	wx_Colour *pEntity = new wx_Colour(colourName);
	Object_wx_Colour *pObj = Object_wx_Colour::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Colour, Alpha)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Alpha)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->Alpha();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, Blue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Blue)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->Blue();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, GetAsString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, GetAsString)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	wxString rtn = pThis->GetEntity()->GetAsString(flags);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Colour, GetPixel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, GetPixel)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetPixel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, Green)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Green)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->Green();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, IsOk)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, Red)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Red)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->Red();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, Set)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Set)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	unsigned alpha = wxALPHA_OPAQUE;
	if (args.IsValid(3)) alpha = args.GetInt(3);
	pThis->GetEntity()->Set(red, green, blue, alpha);
	return Value::Null;
}

Gura_DeclareMethod(wx_Colour, SetRGB)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "RGB", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, SetRGB)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned RGB = args.GetInt(0);
	pThis->GetEntity()->Set(RGB);
	return Value::Null;
}

Gura_DeclareMethod(wx_Colour, SetFromName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, SetFromName)
{
	Object_wx_Colour *pThis = Object_wx_Colour::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Set(str);
	return ReturnValue(env, sig, args, Value(rtn));
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_Colour, wx_Colour)
{
	wxColour *item1 = Object_wx_Colour::GetObject(valueLeft)->GetEntity();
	wxColour *item2 = Object_wx_Colour::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_Colour, wx_Colour)
{
	wxColour *item1 = Object_wx_Colour::GetObject(valueLeft)->GetEntity();
	wxColour *item2 = Object_wx_Colour::GetObject(valueRight)->GetEntity();
	return *item1 != *item2;
}

//----------------------------------------------------------------------------
// Object implementation for wxColour
//----------------------------------------------------------------------------
Object_wx_Colour::~Object_wx_Colour()
{
}

Object *Object_wx_Colour::Clone() const
{
	return NULL;
}

String Object_wx_Colour::ToString(bool exprFlag)
{
	String rtn("<wx.Colour:");
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
// Class implementation for wxColour
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClassWithCast(wx_Colour)
{
	Gura_AssignFunction(ColourEmpty);
	Gura_AssignFunction(Colour);
	Gura_AssignFunction(NamedColour);
	Gura_AssignBinaryOperator(Eq, wx_Colour, wx_Colour);
	Gura_AssignBinaryOperator(Ne, wx_Colour, wx_Colour);
	Gura_AssignMethod(wx_Colour, Alpha);
	Gura_AssignMethod(wx_Colour, Blue);
	Gura_AssignMethod(wx_Colour, GetAsString);
	Gura_AssignMethod(wx_Colour, GetPixel);
	Gura_AssignMethod(wx_Colour, Green);
	Gura_AssignMethod(wx_Colour, IsOk);
	Gura_AssignMethodEx(wx_Colour, IsOk, "Ok");
	Gura_AssignMethod(wx_Colour, Red);
	Gura_AssignMethod(wx_Colour, Set);
	Gura_AssignMethod(wx_Colour, SetRGB);
	Gura_AssignMethod(wx_Colour, SetFromName);
}

Gura_ImplementCastFrom(wx_Colour)
{
	if (value.Is_color()) {
		const Object_color *pObjColor = Object_color::GetObject(value);
		wx_Colour *pEntity = new wx_Colour(
						pObjColor->GetRed(), pObjColor->GetGreen(),
						pObjColor->GetBlue(), pObjColor->GetAlpha());
		Object_wx_Colour *pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		value = Value(pObj);
		return true;
	} else if (value.Is_string()) {
		AutoPtr<Object_color> pObjColor(
				Object_color::CreateNamedColor(env, sig, value.GetString(), 255));
		if (sig.IsSignalled()) return false;
		wx_Colour *pEntity = new wx_Colour(
						pObjColor->GetRed(), pObjColor->GetGreen(),
						pObjColor->GetBlue(), pObjColor->GetAlpha());
		Object_wx_Colour *pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		value = Value(pObj);
		return true;
	}
	return false;
}

Gura_ImplementCastTo(wx_Colour)
{
	return false;
}

Gura_ImplementDescendantCreator(wx_Colour)
{
	return new Object_wx_Colour((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
