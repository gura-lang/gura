//----------------------------------------------------------------------------
// wxBrush
// extracted from brush.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Brush: public wxBrush, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Brush *_pObj;
public:
	inline wx_Brush() : wxBrush(), _sig(NULL), _pObj(NULL) {}
	inline wx_Brush(const wxColour& colour, int style) : wxBrush(colour, style), _sig(NULL), _pObj(NULL) {}
	inline wx_Brush(const wxString& colourName, int style) : wxBrush(colourName, style), _sig(NULL), _pObj(NULL) {}
	inline wx_Brush(const wxBitmap& stippleBitmap) : wxBrush(stippleBitmap), _sig(NULL), _pObj(NULL) {}
	inline wx_Brush(const wxBrush& brush) : wxBrush(brush), _sig(NULL), _pObj(NULL) {}
	~wx_Brush();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Brush *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Brush::~wx_Brush()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Brush::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBrush
//----------------------------------------------------------------------------
Gura_DeclareFunction(BrushEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BrushEmpty)
{
	wx_Brush *pEntity = new wx_Brush();
	Object_wx_Brush *pObj = Object_wx_Brush::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Brush)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Brush)
{
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	int style = wxSOLID;
	if (args.IsValid(1)) style = args.GetInt(1);
	wx_Brush *pEntity = new wx_Brush(*colour, style);
	Object_wx_Brush *pObj = Object_wx_Brush::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Brush_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Brush_1)
{
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	int style = args.GetInt(1);
	wx_Brush *pEntity = new wx_Brush(colourName, style);
	Object_wx_Brush *pObj = Object_wx_Brush::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Brush_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareArg(env, "stippleBitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Brush_2)
{
	wxBitmap *stippleBitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wx_Brush *pEntity = new wx_Brush(*stippleBitmap);
	Object_wx_Brush *pObj = Object_wx_Brush::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Brush_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Brush));
	DeclareArg(env, "brush", VTYPE_wx_Brush, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Brush_3)
{
	wxBrush *brush = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	wx_Brush *pEntity = new wx_Brush(*brush);
	Object_wx_Brush *pObj = Object_wx_Brush::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Brush(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Brush, GetColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, GetColour)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour &rtn = pSelf->GetEntity()->GetColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Brush, GetStipple)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, GetStipple)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *rtn = (wxBitmap *)pSelf->GetEntity()->GetStipple();
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Brush, GetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, GetStyle)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Brush, IsHatch)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, IsHatch)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsHatch();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Brush, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, IsOk)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Brush, SetColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetColour)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Brush, SetColour_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetColour_1)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetColour(colourName);
	return Value::Null;
}

Gura_DeclareMethod(wx_Brush, SetColour_2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetColour_2)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned red = args.GetInt(0);
	unsigned green = args.GetInt(1);
	unsigned blue = args.GetInt(2);
	pSelf->GetEntity()->SetColour(red, green, blue);
	return Value::Null;
}

Gura_DeclareMethod(wx_Brush, SetStipple)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetStipple)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetStipple(*bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_Brush, SetStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Brush, SetStyle)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int style = args.GetInt(0);
	pSelf->GetEntity()->SetStyle(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_Brush, __eq__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Brush, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Brush, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, __eq__)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	wxBrush *item1 = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	wxBrush *item2 = Object_wx_Brush::GetObject(args, 1)->GetEntity();
	return *item1 == *item2;
}

Gura_DeclareMethod(wx_Brush, __ne__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Brush, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Brush, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Brush, __ne__)
{
	Object_wx_Brush *pSelf = Object_wx_Brush::GetSelfObj(args);
	wxBrush *item1 = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	wxBrush *item2 = Object_wx_Brush::GetObject(args, 1)->GetEntity();
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
	return NULL;
}

String Object_wx_Brush::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Brush:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Brush::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(BrushEmpty);
	Gura_AssignFunction(Brush);
	Gura_AssignFunction(Brush_1);
	Gura_AssignFunction(Brush_2);
	Gura_AssignFunction(Brush_3);
}

//----------------------------------------------------------------------------
// Class implementation for wxBrush
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Brush)
{
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
	Gura_AssignMethod(wx_Brush, __eq__);
	Gura_AssignMethod(wx_Brush, __ne__);
}

Gura_ImplementDescendantCreator(wx_Brush)
{
	return new Object_wx_Brush((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
