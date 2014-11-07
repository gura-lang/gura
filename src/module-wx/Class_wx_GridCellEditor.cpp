//----------------------------------------------------------------------------
// wxGridCellEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellEditor: public wxGridCellEditor, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridCellEditor *_pObj;
public:
	//inline wx_GridCellEditor() : wxGridCellEditor(), _sig(NULL), _pObj(NULL) {}
	~wx_GridCellEditor();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellEditor *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellEditor::~wx_GridCellEditor()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridCellEditor::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellEditor
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GridCellEditor, IsCreated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellEditor, IsCreated)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsCreated();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridCellEditor, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "evtHandler", VTYPE_wx_EvtHandler, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, Create)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxEvtHandler *evtHandler = Object_wx_EvtHandler::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->Create(parent, id, evtHandler);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellEditor, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, SetSize)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSize(*rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellEditor, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellEditor, Show)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	wxGridCellAttr *attr = (wxGridCellAttr *)(NULL);
	if (args.IsValid(1)) attr = Object_wx_GridCellAttr::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Show(show, attr);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellEditor, PaintBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rectCell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, PaintBackground)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rectCell = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->PaintBackground(*dc, *rectCell, *attr);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellEditor, BeginEdit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, BeginEdit)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGrid *grid = Object_wx_Grid::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->BeginEdit(row, col, grid);
	return Value::Null;
}

#if 0
Gura_DeclareMethod(wx_GridCellEditor, EndEdit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellEditor, EndEdit)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGrid *grid = Object_wx_Grid::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->EndEdit(row, col, grid);
	return ReturnValue(env, sig, args, Value(rtn));
}
#endif

Gura_DeclareMethod(wx_GridCellEditor, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, Reset)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Reset();
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellEditor, StartingKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, StartingKey)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->StartingKey(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellEditor, StartingClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, StartingClick)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->StartingClick();
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellEditor, HandleReturn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, HandleReturn)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->HandleReturn(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellEditor, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, Destroy)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Destroy();
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellEditor, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellEditor, Clone)
{
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellEditor *rtn = (wxGridCellEditor *)pThis->GetEntity()->Clone();
	return ReturnValue(env, sig, args, Value(new Object_wx_GridCellEditor(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellEditor
//----------------------------------------------------------------------------
Object_wx_GridCellEditor::~Object_wx_GridCellEditor()
{
}

Object *Object_wx_GridCellEditor::Clone() const
{
	return NULL;
}

String Object_wx_GridCellEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellEditor:");
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
// Class implementation for wxGridCellEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellEditor)
{
	Gura_AssignMethod(wx_GridCellEditor, IsCreated);
	Gura_AssignMethod(wx_GridCellEditor, Create);
	Gura_AssignMethod(wx_GridCellEditor, SetSize);
	Gura_AssignMethod(wx_GridCellEditor, Show);
	Gura_AssignMethod(wx_GridCellEditor, PaintBackground);
	Gura_AssignMethod(wx_GridCellEditor, BeginEdit);
	//Gura_AssignMethod(wx_GridCellEditor, EndEdit);
	Gura_AssignMethod(wx_GridCellEditor, Reset);
	Gura_AssignMethod(wx_GridCellEditor, StartingKey);
	Gura_AssignMethod(wx_GridCellEditor, StartingClick);
	Gura_AssignMethod(wx_GridCellEditor, HandleReturn);
	Gura_AssignMethod(wx_GridCellEditor, Destroy);
	Gura_AssignMethod(wx_GridCellEditor, Clone);
}

Gura_ImplementDescendantCreator(wx_GridCellEditor)
{
	return new Object_wx_GridCellEditor((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
