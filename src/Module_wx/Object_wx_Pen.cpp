//----------------------------------------------------------------------------
// wxPen
// extracted from pen.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Pen: public wxPen, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Pen *_pObj;
public:
	inline wx_Pen() : wxPen(), _sig(NULL), _pObj(NULL) {}
	inline wx_Pen(const wxColour& colour, int width, int style) : wxPen(colour, width, style), _sig(NULL), _pObj(NULL) {}
	inline wx_Pen(const wxString& colourName, int width, int style) : wxPen(colourName, width, style), _sig(NULL), _pObj(NULL) {}
#if defined(__WXMSW__)
	inline wx_Pen(const wxBitmap& stipple, int width) : wxPen(stipple, width), _sig(NULL), _pObj(NULL) {}
#endif
	inline wx_Pen(const wxPen& pen) : wxPen(pen), _sig(NULL), _pObj(NULL) {}
	~wx_Pen();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Pen *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Pen::~wx_Pen()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Pen::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPen
//----------------------------------------------------------------------------
Gura_DeclareFunction(PenEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PenEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Pen *pEntity = new wx_Pen();
	Object_wx_Pen *pObj = Object_wx_Pen::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Pen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Pen)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	int width = 1;
	if (args.IsValid(1)) width = args.GetInt(1);
	int style = wxSOLID;
	if (args.IsValid(2)) style = args.GetInt(2);
	wx_Pen *pEntity = new wx_Pen(*colour, width, style);
	Object_wx_Pen *pObj = Object_wx_Pen::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Pen_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Pen_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	int width = args.GetInt(1);
	int style = args.GetInt(2);
	wx_Pen *pEntity = new wx_Pen(colourName, width, style);
	Object_wx_Pen *pObj = Object_wx_Pen::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Pen_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareArg(env, "stipple", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Pen_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	wxBitmap *stipple = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	int width = args.GetInt(1);
	wx_Pen *pEntity = new wx_Pen(*stipple, width);
	Object_wx_Pen *pObj = Object_wx_Pen::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(Pen_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Pen));
	DeclareArg(env, "pen", VTYPE_wx_Pen, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Pen_3)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPen *pen = Object_wx_Pen::GetObject(args, 0)->GetEntity();
	wx_Pen *pEntity = new wx_Pen(*pen);
	Object_wx_Pen *pObj = Object_wx_Pen::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Pen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Pen, GetCap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetCap)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetCap();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, GetColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetColour)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour &rtn = pSelf->GetEntity()->GetColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Pen, GetDashes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetDashes)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDash *dashes;
	int rtn = pSelf->GetEntity()->GetDashes(&dashes);
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(rtn);
	for (int i = 0; i < rtn; i++) {
		valList.push_back(Value(dashes[i]));
	}
	return ReturnValue(env, sig, args, result);
}

Gura_DeclareMethod(wx_Pen, GetJoin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetJoin)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetJoin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, GetStipple)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetStipple)
{
#if defined(__WXMSW__)
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *rtn = (wxBitmap *)pSelf->GetEntity()->GetStipple();
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(rtn, NULL, OwnerFalse)));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_Pen, GetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetStyle)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, GetWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, GetWidth)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, IsOk)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Pen, SetCap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "capStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetCap)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int capStyle = args.GetInt(0);
	pSelf->GetEntity()->SetCap(capStyle);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetColour)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetColour_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetColour_1)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetColour(colourName);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetColour_2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetColour_2)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	pSelf->GetEntity()->SetColour(red, green, blue);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetDashes)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dashes", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_Pen, SetDashes)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	CArrayOfDash dashes(args.GetList(0));
	pSelf->GetEntity()->SetDashes(dashes.Count(), dashes.Data());
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetJoin)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "join_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetJoin)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int join_style = args.GetInt(0);
	pSelf->GetEntity()->SetJoin(join_style);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetStipple)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stipple", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetStipple)
{
#if defined(__WXMSW__)
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *stipple = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetStipple(*stipple);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_Pen, SetStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetStyle)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int style = args.GetInt(0);
	pSelf->GetEntity()->SetStyle(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, SetWidth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Pen, SetWidth)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pSelf->GetEntity()->SetWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_Pen, __eq__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Pen, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Pen, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, __eq__)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	wxPen *item1 = Object_wx_Pen::GetObject(args, 0)->GetEntity();
	wxPen *item2 = Object_wx_Pen::GetObject(args, 1)->GetEntity();
	return *item1 == *item2;
}

Gura_DeclareMethod(wx_Pen, __ne__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Pen, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Pen, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Pen, __ne__)
{
	Object_wx_Pen *pSelf = Object_wx_Pen::GetSelfObj(args);
	wxPen *item1 = Object_wx_Pen::GetObject(args, 0)->GetEntity();
	wxPen *item2 = Object_wx_Pen::GetObject(args, 1)->GetEntity();
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
	return new Object_wx_Pen(new wxPen(*dynamic_cast<wxPen *>(_pEntity)), NULL, OwnerTrue);
}

String Object_wx_Pen::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Pen:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Pen::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PenEmpty);
	Gura_AssignFunction(Pen);
	Gura_AssignFunction(Pen_1);
	Gura_AssignFunction(Pen_2);
	Gura_AssignFunction(Pen_3);
}

//----------------------------------------------------------------------------
// Class implementation for wxPen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Pen)
{
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
	Gura_AssignMethod(wx_Pen, __eq__);
	Gura_AssignMethod(wx_Pen, __ne__);
}

Gura_ImplementDescendantCreator(wx_Pen)
{
	return new Object_wx_Pen((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
