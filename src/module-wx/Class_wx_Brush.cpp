//----------------------------------------------------------------------------
// wxBrush
// extracted from brush.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Brush: public wxBrush, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Brush *_pObj;
public:
	inline wx_Brush() : wxBrush(), _pObj(nullptr) {}
	inline wx_Brush(const wxColour& colour, int style) : wxBrush(colour, style), _pObj(nullptr) {}
	inline wx_Brush(const wxString& colourName, int style) : wxBrush(colourName, style), _pObj(nullptr) {}
	inline wx_Brush(const wxBitmap& stippleBitmap) : wxBrush(stippleBitmap), _pObj(nullptr) {}
	inline wx_Brush(const wxBrush& brush) : wxBrush(brush), _pObj(nullptr) {}
	~wx_Brush();
	inline void AssocWithGura(Object_wx_Brush *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Brush::~wx_Brush()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Brush::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBrush
//----------------------------------------------------------------------------
Gura_DeclareFunction(BrushEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BrushEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Brush *pEntity = new wx_Brush();
	Object_wx_Brush *pObj = Object_wx_Brush::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Brush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Brush)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	int style = wxSOLID;
	if (args.IsValid(1)) style = args.GetInt(1);
	wx_Brush *pEntity = new wx_Brush(*colour, style);
	Object_wx_Brush *pObj = Object_wx_Brush::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Brush_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Brush_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	int style = args.GetInt(1);
	wx_Brush *pEntity = new wx_Brush(colourName, style);
	Object_wx_Brush *pObj = Object_wx_Brush::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Brush_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareArg(env, "stippleBitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Brush_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap *stippleBitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wx_Brush *pEntity = new wx_Brush(*stippleBitmap);
	Object_wx_Brush *pObj = Object_wx_Brush::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Brush_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareArg(env, "brush", VTYPE_wx_Brush, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Brush_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBrush *brush = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	wx_Brush *pEntity = new wx_Brush(*brush);
	Object_wx_Brush *pObj = Object_wx_Brush::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Brush, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Brush, GetStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, GetStipple)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *rtn = (wxBitmap *)pThis->GetEntity()->GetStipple();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Brush, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Brush, IsHatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, IsHatch)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsHatch();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Brush, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Brush, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, SetColour_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetColour_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetColour(colourName);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, SetColour_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetColour_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	pThis->GetEntity()->SetColour(red, green, blue);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, SetStipple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetStipple)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetStipple(*bitmap);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Brush, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Brush *pThis = Object_wx_Brush::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int style = args.GetInt(0);
	pThis->GetEntity()->SetStyle(style);
	return Value::Nil;
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_Brush, wx_Brush)
{
	wxBrush *item1 = Object_wx_Brush::GetObject(valueLeft)->GetEntity();
	wxBrush *item2 = Object_wx_Brush::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_Brush, wx_Brush)
{
	wxBrush *item1 = Object_wx_Brush::GetObject(valueLeft)->GetEntity();
	wxBrush *item2 = Object_wx_Brush::GetObject(valueRight)->GetEntity();
	return *item1 != *item2;
}

//----------------------------------------------------------------------------
// Object implementation for wxBrush
//----------------------------------------------------------------------------
Object_wx_Brush::~Object_wx_Brush()
{
}

Object *Object_wx_Brush::Clone() const
{
	return nullptr;
}

String Object_wx_Brush::ToString(bool exprFlag)
{
	String rtn("<wx.Brush:");
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
// Class implementation for wxBrush
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Brush)
{
	Gura_AssignFunction(BrushEmpty);
	Gura_AssignFunction(Brush);
	Gura_AssignFunction(Brush_1);
	Gura_AssignFunction(Brush_2);
	Gura_AssignFunction(Brush_3);
	Gura_AssignBinaryOperator(Eq, wx_Brush, wx_Brush);		// ==
	Gura_AssignBinaryOperator(Ne, wx_Brush, wx_Brush);	// !=
	Gura_AssignMethod(wx_Brush, GetColour);
	Gura_AssignMethod(wx_Brush, GetStipple);
	Gura_AssignMethod(wx_Brush, GetStyle);
	Gura_AssignMethod(wx_Brush, IsHatch);
	Gura_AssignMethod(wx_Brush, IsOk);
	Gura_AssignMethodEx(wx_Brush, IsOk, "Ok");
	Gura_AssignMethod(wx_Brush, SetColour);
	Gura_AssignMethod(wx_Brush, SetColour_1);
	Gura_AssignMethod(wx_Brush, SetColour_2);
	Gura_AssignMethod(wx_Brush, SetStipple);
	Gura_AssignMethod(wx_Brush, SetStyle);
}

Gura_ImplementDescendantCreator(wx_Brush)
{
	return new Object_wx_Brush((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
