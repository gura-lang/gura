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
	//Gura::Signal *_pSig;
	Object_wx_GridCellAttr *_pObj;
public:
	inline wx_GridCellAttr() : wxGridCellAttr(), _pObj(nullptr) {}
	inline wx_GridCellAttr(const wxColour& colText, const wxColour& colBack, const wxFont& font, int hAlign, int vAlign) : wxGridCellAttr(colText, colBack, font, hAlign, vAlign), _pObj(nullptr) {}
	~wx_GridCellAttr();
	inline void AssocWithGura(Object_wx_GridCellAttr *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellAttr::~wx_GridCellAttr()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellAttr::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAttr
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellAttrEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellAttrEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GridCellAttr *pEntity = new wx_GridCellAttr();
	Object_wx_GridCellAttr *pObj = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(GridCellAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxColour *colText = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	wxColour *colBack = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	wxFont *font = Object_wx_Font::GetObject(arg, 2)->GetEntity();
	int hAlign = arg.GetInt(3);
	int vAlign = arg.GetInt(4);
	wx_GridCellAttr *pEntity = new wx_GridCellAttr(*colText, *colBack, *font, hAlign, vAlign);
	Object_wx_GridCellAttr *pObj = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_GridCellAttr, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellAttr *rtn = (wxGridCellAttr *)pThis->GetEntity()->Clone();
	return ReturnValue(env, arg, Value(new Object_wx_GridCellAttr(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridCellAttr, IncRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellAttr, IncRef)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->IncRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttr, DecRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellAttr, DecRef)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DecRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttr, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colText = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*colText);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttr, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colBack = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*colBack);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttr, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttr, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "hAlign", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vAlign", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int hAlign = arg.GetInt(0);
	int vAlign = arg.GetInt(1);
	pThis->GetEntity()->SetAlignment(hAlign, vAlign);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttr, SetReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "isReadOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, SetReadOnly)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool isReadOnly = true;
	if (arg.IsValid(0)) isReadOnly = arg.GetBoolean(0);
	pThis->GetEntity()->SetReadOnly(isReadOnly);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttr, SetRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "renderer", VTYPE_wx_GridCellRenderer, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellRenderer *renderer = Object_wx_GridCellRenderer::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetRenderer(renderer);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttr, SetEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "editor", VTYPE_wx_GridCellEditor, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellEditor *editor = Object_wx_GridCellEditor::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetEditor(editor);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttr, HasTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasTextColour();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasBackgroundColour();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasFont();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasAlignment();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasRenderer();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, HasEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, HasEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasEditor();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridCellAttr, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridCellAttr, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, arg, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridCellAttr, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int hAlign = 0;
	int vAlign = 0;
	pThis->GetEntity()->GetAlignment(&hAlign, &vAlign);
	return ReturnValue(env, arg, Value::CreateList(env, hAlign, vAlign));
}

Gura_DeclareMethod(wx_GridCellAttr, GetRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGrid *grid = Object_wx_Grid::GetObject(arg, 0)->GetEntity();
	int row = arg.GetInt(1);
	int col = arg.GetInt(2);
	wxGridCellRenderer *rtn = (wxGridCellRenderer *)pThis->GetEntity()->GetRenderer(grid, row, col);
	return ReturnValue(env, arg, Value(new Object_wx_GridCellRenderer(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridCellAttr, GetEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, GetEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGrid *grid = Object_wx_Grid::GetObject(arg, 0)->GetEntity();
	int row = arg.GetInt(1);
	int col = arg.GetInt(2);
	wxGridCellEditor *rtn = (wxGridCellEditor *)pThis->GetEntity()->GetEditor(grid, row, col);
	return ReturnValue(env, arg, Value(new Object_wx_GridCellEditor(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridCellAttr, IsReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellAttr, IsReadOnly)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsReadOnly();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellAttr, SetDefAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "defAttr", VTYPE_wx_GridCellAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttr, SetDefAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttr *pThis = Object_wx_GridCellAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellAttr *defAttr = Object_wx_GridCellAttr::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetDefAttr(defAttr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAttr
//----------------------------------------------------------------------------
Object_wx_GridCellAttr::~Object_wx_GridCellAttr()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	//if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_GridCellAttr::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellAttr::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAttr:");
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
	return new Object_wx_GridCellAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
