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
	//Gura::Signal *_pSig;
	Object_wx_Colour *_pObj;
public:
	inline wx_Colour() : wxColour(), _pObj(nullptr) {}
	inline wx_Colour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : wxColour(red, green, blue, alpha), _pObj(nullptr) {}
	inline wx_Colour(const wxString& colourNname) : wxColour(colourNname), _pObj(nullptr) {}
	inline wx_Colour(const wxColour& colour) : wxColour(colour), _pObj(nullptr) {}
	~wx_Colour();
	inline void AssocWithGura(Object_wx_Colour *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Colour::~wx_Colour()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Colour::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxColour
//----------------------------------------------------------------------------
Gura_DeclareFunction(ColourEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Colour));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Colour *pEntity = new wx_Colour();
	Object_wx_Colour *pObj = Object_wx_Colour::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(Colour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Colour));
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Colour)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	unsigned alpha = wxALPHA_OPAQUE;
	if (args.IsValid(3)) alpha = args.GetInt(3);
	wx_Colour *pEntity = new wx_Colour(red, green, blue, alpha);
	Object_wx_Colour *pObj = Object_wx_Colour::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(NamedColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Colour));
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NamedColour)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	wx_Colour *pEntity = new wx_Colour(colourName);
	Object_wx_Colour *pObj = Object_wx_Colour::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_Colour, Alpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Alpha)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->Alpha();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, Blue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Blue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->Blue();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, GetAsString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, GetAsString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long flags = args.GetLong(0);
	wxString rtn = pThis->GetEntity()->GetAsString(flags);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

#if 0
Gura_DeclareMethod(wx_Colour, GetPixel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, GetPixel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetPixel();
	return ReturnValue(env, args, Value(rtn));
}
#endif

Gura_DeclareMethod(wx_Colour, Green)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Green)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->Green();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, Red)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Red)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->Red();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Colour, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	unsigned alpha = wxALPHA_OPAQUE;
	if (args.IsValid(3)) alpha = args.GetInt(3);
	pThis->GetEntity()->Set(red, green, blue, alpha);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Colour, SetRGB)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "RGB", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Colour, SetRGB)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned RGB = args.GetInt(0);
	pThis->GetEntity()->Set(RGB);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Colour, SetFromName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Colour, SetFromName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Colour *pThis = Object_wx_Colour::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Set(str);
	return ReturnValue(env, args, Value(rtn));
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
	return nullptr;
}

String Object_wx_Colour::ToString(bool exprFlag)
{
	String rtn("<wx.Colour:");
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
	//Gura_AssignMethod(wx_Colour, GetPixel);
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
	Signal &sig = GetSignal();
	if (value.Is_color()) {
		const Color &color = Object_color::GetObject(value)->GetColor();
		wx_Colour *pEntity = new wx_Colour(color.GetR(), color.GetG(), color.GetB(), color.GetA());
		Object_wx_Colour *pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		value = Value(pObj);
		return true;
	} else if (value.Is_string()) {
		Color color = Color::CreateNamedColor(sig, value.GetString(), 255);
		if (sig.IsSignalled()) return false;
		wx_Colour *pEntity = new wx_Colour(color.GetR(), color.GetG(), color.GetB(), color.GetA());
		Object_wx_Colour *pObj = new Object_wx_Colour(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
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
	return new Object_wx_Colour((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
