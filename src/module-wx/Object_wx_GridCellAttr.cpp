//----------------------------------------------------------------------------
// wxGridCellAttr
// extracted from gridattr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellAttr: public wxGridCellAttr, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellAttr *_pObj;
public:
	inline wx_GridCellAttr() : wxGridCellAttr(), _sig(NULL), _pObj(NULL) {}
	inline wx_GridCellAttr(const wxColour& colText, const wxColour& colBack, const wxFont& font, int hAlign, int vAlign) : wxGridCellAttr(colText, colBack, font, hAlign, vAlign), _sig(NULL), _pObj(NULL) {}
	~wx_GridCellAttr();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellAttr *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellAttr::~wx_GridCellAttr()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellAttr::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAttr
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellAttrEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellAttrEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridCellAttr *pEntity = new wx_GridCellAttr();
	Object_wx_GridCellAttr *pObj = Object_wx_GridCellAttr::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(GridCellAttr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAttr));
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareArg(env, "hAlign", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vAlign", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellAttr)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBack = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxFont *font = Object_wx_Font::GetObject(args, 2)->GetEntity();
	int hAlign = args.GetInt(3);
	int vAlign = args.GetInt(4);
	wx_GridCellAttr *pEntity = new wx_GridCellAttr(*colText, *colBack, *font, hAlign, vAlign);
	Object_wx_GridCellAttr *pObj = Object_wx_GridCellAttr::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridCellAttr, Clone)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, Clone)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellAttr *rtn = (wxGridCellAttr *)pThis->GetEntity()->Clone();
	return ReturnValue(env, sig, args, Value(new Object_wx_GridCellAttr(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridCellAttr, IncRef)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellAttr, IncRef)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->IncRef();
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellAttr, DecRef)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellAttr, DecRef)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DecRef();
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellAttr, SetTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetTextColour)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*colText);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellAttr, SetBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetBackgroundColour)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colBack = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*colBack);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellAttr, SetFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetFont)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellAttr, SetAlignment)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "hAlign", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vAlign", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetAlignment)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int hAlign = args.GetInt(0);
	int vAlign = args.GetInt(1);
	pThis->GetEntity()->SetAlignment(hAlign, vAlign);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellAttr, SetReadOnly)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "isReadOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, SetReadOnly)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool isReadOnly = true;
	if (args.IsValid(0)) isReadOnly = args.GetBoolean(0);
	pThis->GetEntity()->SetReadOnly(isReadOnly);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellAttr, SetRenderer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "renderer", VTYPE_wx_GridCellRenderer, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetRenderer)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellRenderer *renderer = Object_wx_GridCellRenderer::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetRenderer(renderer);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellAttr, SetEditor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "editor", VTYPE_wx_GridCellEditor, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetEditor)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellEditor *editor = Object_wx_GridCellEditor::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetEditor(editor);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellAttr, HasTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasTextColour)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTextColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasBackgroundColour)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBackgroundColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasFont)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasFont();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasAlignment)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasAlignment();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasRenderer)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasRenderer();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasEditor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasEditor)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasEditor();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, GetTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetTextColour)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridCellAttr, GetBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetBackgroundColour)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridCellAttr, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetFont)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridCellAttr, GetAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetAlignment)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int hAlign = 0;
	int vAlign = 0;
	pThis->GetEntity()->GetAlignment(&hAlign, &vAlign);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, hAlign, vAlign));
}

Gura_DeclareMethod(wx_GridCellAttr, GetRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetRenderer)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGrid *grid = Object_wx_Grid::GetObject(args, 0)->GetEntity();
	int row = args.GetInt(1);
	int col = args.GetInt(2);
	wxGridCellRenderer *rtn = (wxGridCellRenderer *)pThis->GetEntity()->GetRenderer(grid, row, col);
	return ReturnValue(env, sig, args, Value(new Object_wx_GridCellRenderer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridCellAttr, GetEditor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetEditor)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGrid *grid = Object_wx_Grid::GetObject(args, 0)->GetEntity();
	int row = args.GetInt(1);
	int col = args.GetInt(2);
	wxGridCellEditor *rtn = (wxGridCellEditor *)pThis->GetEntity()->GetEditor(grid, row, col);
	return ReturnValue(env, sig, args, Value(new Object_wx_GridCellEditor(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridCellAttr, IsReadOnly)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, IsReadOnly)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsReadOnly();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, SetDefAttr)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "defAttr", VTYPE_wx_GridCellAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetDefAttr)
{
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellAttr *defAttr = Object_wx_GridCellAttr::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDefAttr(defAttr);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAttr
//----------------------------------------------------------------------------
Object_wx_GridCellAttr::~Object_wx_GridCellAttr()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	//if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_GridCellAttr::Clone() const
{
	return NULL;
}

String Object_wx_GridCellAttr::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridCellAttr:");
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
// Class implementation for wxGridCellAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAttr)
{
	Gura_AssignFunction(GridCellAttrEmpty);
	Gura_AssignFunction(GridCellAttr);
	Gura_AssignMethod(wx_GridCellAttr, Clone);
	Gura_AssignMethod(wx_GridCellAttr, IncRef);
	Gura_AssignMethod(wx_GridCellAttr, DecRef);
	Gura_AssignMethod(wx_GridCellAttr, SetTextColour);
	Gura_AssignMethod(wx_GridCellAttr, SetBackgroundColour);
	Gura_AssignMethod(wx_GridCellAttr, SetFont);
	Gura_AssignMethod(wx_GridCellAttr, SetAlignment);
	Gura_AssignMethod(wx_GridCellAttr, SetReadOnly);
	Gura_AssignMethod(wx_GridCellAttr, SetRenderer);
	Gura_AssignMethod(wx_GridCellAttr, SetEditor);
	Gura_AssignMethod(wx_GridCellAttr, HasTextColour);
	Gura_AssignMethod(wx_GridCellAttr, HasBackgroundColour);
	Gura_AssignMethod(wx_GridCellAttr, HasFont);
	Gura_AssignMethod(wx_GridCellAttr, HasAlignment);
	Gura_AssignMethod(wx_GridCellAttr, HasRenderer);
	Gura_AssignMethod(wx_GridCellAttr, HasEditor);
	Gura_AssignMethod(wx_GridCellAttr, GetTextColour);
	Gura_AssignMethod(wx_GridCellAttr, GetBackgroundColour);
	Gura_AssignMethod(wx_GridCellAttr, GetFont);
	Gura_AssignMethod(wx_GridCellAttr, GetAlignment);
	Gura_AssignMethod(wx_GridCellAttr, GetRenderer);
	Gura_AssignMethod(wx_GridCellAttr, GetEditor);
	Gura_AssignMethod(wx_GridCellAttr, IsReadOnly);
	Gura_AssignMethod(wx_GridCellAttr, SetDefAttr);
}

Gura_ImplementDescendantCreator(wx_GridCellAttr)
{
	return new Object_wx_GridCellAttr((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
