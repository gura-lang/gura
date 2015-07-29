//----------------------------------------------------------------------------
// wxPen
// extracted from pen.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Pen: public wxPen, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Pen *_pObj;
public:
	inline wx_Pen() : wxPen(), _pObj(nullptr) {}
	inline wx_Pen(const wxColour& colour, int width, int style) : wxPen(colour, width, style), _pObj(nullptr) {}
	inline wx_Pen(const wxString& colourName, int width, int style) : wxPen(colourName, width, style), _pObj(nullptr) {}
#if defined(__WXMSW__)
	inline wx_Pen(const wxBitmap& stipple, int width) : wxPen(stipple, width), _pObj(nullptr) {}
#endif
	inline wx_Pen(const wxPen& pen) : wxPen(pen), _pObj(nullptr) {}
	~wx_Pen();
	inline void AssocWithGura(Object_wx_Pen *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Pen::~wx_Pen()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Pen::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPen
//----------------------------------------------------------------------------
Gura_DeclareFunction(PenEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PenEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Pen *pEntity = new wx_Pen();
	Object_wx_Pen *pObj = Object_wx_Pen::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Pen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Pen)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	int width = 1;
	if (args.IsValid(1)) width = args.GetInt(1);
	int style = wxSOLID;
	if (args.IsValid(2)) style = args.GetInt(2);
	wx_Pen *pEntity = new wx_Pen(*colour, width, style);
	Object_wx_Pen *pObj = Object_wx_Pen::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Pen_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Pen_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	int width = args.GetInt(1);
	int style = args.GetInt(2);
	wx_Pen *pEntity = new wx_Pen(colourName, width, style);
	Object_wx_Pen *pObj = Object_wx_Pen::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Pen_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareArg(env, "stipple", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Pen_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	wxBitmap *stipple = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	int width = args.GetInt(1);
	wx_Pen *pEntity = new wx_Pen(*stipple, width);
	Object_wx_Pen *pObj = Object_wx_Pen::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(Pen_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareArg(env, "pen", VTYPE_wx_Pen, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Pen_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxPen *pen = Object_wx_Pen::GetObject(args, 0)->GetEntity();
	wx_Pen *pEntity = new wx_Pen(*pen);
	Object_wx_Pen *pObj = Object_wx_Pen::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Pen, GetCap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetCap)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCap();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Pen, GetDashes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetDashes)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDash *dashes;
	int rtn = pThis->GetEntity()->GetDashes(&dashes);
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(rtn);
	for (int i = 0; i < rtn; i++) {
		valList.push_back(Value(dashes[i]));
	}
	return ReturnValue(env, args, result);
}

Gura_DeclareMethod(wx_Pen, GetJoin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetJoin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetJoin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, GetStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetStipple)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *rtn = (wxBitmap *)pThis->GetEntity()->GetStipple();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(rtn, nullptr, OwnerFalse)));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_Pen, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, SetCap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "capStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetCap)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPenCap capStyle = static_cast<wxPenCap>(args.GetInt(0));
	pThis->GetEntity()->SetCap(capStyle);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetColour_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetColour_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetColour(colourName);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetColour_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetColour_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	pThis->GetEntity()->SetColour(red, green, blue);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetDashes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dashes", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_Pen, SetDashes)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	CArrayOfDash dashes(args.GetList(0));
	pThis->GetEntity()->SetDashes(dashes.Count(), dashes.Data());
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetJoin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "join_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetJoin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPenJoin join_style = static_cast<wxPenJoin>(args.GetInt(0));
	pThis->GetEntity()->SetJoin(join_style);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stipple", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetStipple)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *stipple = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetStipple(*stipple);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_Pen, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int style = args.GetInt(0);
	pThis->GetEntity()->SetStyle(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Pen *pThis = Object_wx_Pen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetWidth(width);
	return Value::Null;
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_Pen, wx_Pen)
{
	wxPen *item1 = Object_wx_Pen::GetObject(valueLeft)->GetEntity();
	wxPen *item2 = Object_wx_Pen::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_Pen, wx_Pen)
{
	wxPen *item1 = Object_wx_Pen::GetObject(valueLeft)->GetEntity();
	wxPen *item2 = Object_wx_Pen::GetObject(valueRight)->GetEntity();
	return *item1 != *item2;
}

//----------------------------------------------------------------------------
// Object implementation for wxPen
//----------------------------------------------------------------------------
Object_wx_Pen::~Object_wx_Pen()
{
}

Object *Object_wx_Pen::Clone() const
{
	return new Object_wx_Pen(new wxPen(*dynamic_cast<wxPen *>(_pEntity)), nullptr, OwnerTrue);
}

String Object_wx_Pen::ToString(bool exprFlag)
{
	String rtn("<wx.Pen:");
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
// Class implementation for wxPen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Pen)
{
	Gura_AssignFunction(PenEmpty);
	Gura_AssignFunction(Pen);
	Gura_AssignFunction(Pen_1);
	Gura_AssignFunction(Pen_2);
	Gura_AssignFunction(Pen_3);
	Gura_AssignBinaryOperator(Eq, wx_Pen, wx_Pen);
	Gura_AssignBinaryOperator(Ne, wx_Pen, wx_Pen);
	Gura_AssignMethod(wx_Pen, GetCap);
	Gura_AssignMethod(wx_Pen, GetColour);
	Gura_AssignMethod(wx_Pen, GetDashes);
	Gura_AssignMethod(wx_Pen, GetJoin);
	Gura_AssignMethod(wx_Pen, GetStipple);
	Gura_AssignMethod(wx_Pen, GetStyle);
	Gura_AssignMethod(wx_Pen, GetWidth);
	Gura_AssignMethod(wx_Pen, IsOk);
	Gura_AssignMethodEx(wx_Pen, IsOk, "Ok");
	Gura_AssignMethod(wx_Pen, SetCap);
	Gura_AssignMethod(wx_Pen, SetColour);
	Gura_AssignMethod(wx_Pen, SetColour_1);
	Gura_AssignMethod(wx_Pen, SetColour_2);
	Gura_AssignMethod(wx_Pen, SetDashes);
	Gura_AssignMethod(wx_Pen, SetJoin);
	Gura_AssignMethod(wx_Pen, SetStipple);
	Gura_AssignMethod(wx_Pen, SetStyle);
	Gura_AssignMethod(wx_Pen, SetWidth);
}

Gura_ImplementDescendantCreator(wx_Pen)
{
	return new Object_wx_Pen((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
