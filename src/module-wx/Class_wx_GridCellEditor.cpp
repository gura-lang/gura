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
	//Gura::Signal *_pSig;
	Object_wx_GridCellEditor *_pObj;
public:
	//inline wx_GridCellEditor() : wxGridCellEditor(), _pObj(nullptr) {}
	~wx_GridCellEditor();
	inline void AssocWithGura(Object_wx_GridCellEditor *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellEditor::~wx_GridCellEditor()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridCellEditor::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsCreated();
	return ReturnValue(env, args, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxEvtHandler *evtHandler = Object_wx_EvtHandler::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->Create(parent, id, evtHandler);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSize(*rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellEditor, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = args.GetBoolean(0);
	wxGridCellAttr *attr = (wxGridCellAttr *)(nullptr);
	if (args.IsValid(1)) attr = Object_wx_GridCellAttr::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Show(show, attr);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rectCell = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->PaintBackground(*dc, *rectCell, *attr);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGrid *grid = Object_wx_Grid::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->BeginEdit(row, col, grid);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGrid *grid = Object_wx_Grid::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->EndEdit(row, col, grid);
	return ReturnValue(env, args, Value(rtn));
}
#endif

Gura_DeclareMethod(wx_GridCellEditor, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, StartingKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, StartingKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->StartingKey(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, StartingClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, StartingClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->StartingClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, HandleReturn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEditor, HandleReturn)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->HandleReturn(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellEditor, Destroy)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEditor, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellEditor, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEditor *pThis = Object_wx_GridCellEditor::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellEditor *rtn = (wxGridCellEditor *)pThis->GetEntity()->Clone();
	return ReturnValue(env, args, Value(new Object_wx_GridCellEditor(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellEditor
//----------------------------------------------------------------------------
Object_wx_GridCellEditor::~Object_wx_GridCellEditor()
{
}

Object *Object_wx_GridCellEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellEditor:");
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
	return new Object_wx_GridCellEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
