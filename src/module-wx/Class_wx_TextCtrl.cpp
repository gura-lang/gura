//----------------------------------------------------------------------------
// wxTextCtrl
// extracted from text.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(CanCopy);
Gura_DeclarePrivUserSymbol(CanCut);
Gura_DeclarePrivUserSymbol(CanPaste);
Gura_DeclarePrivUserSymbol(CanRedo);
Gura_DeclarePrivUserSymbol(CanUndo);
Gura_DeclarePrivUserSymbol(Clear);
Gura_DeclarePrivUserSymbol(Copy);
Gura_DeclarePrivUserSymbol(Cut);
Gura_DeclarePrivUserSymbol(GetInsertionPoint);
Gura_DeclarePrivUserSymbol(GetLastPosition);
Gura_DeclarePrivUserSymbol(GetRange);
Gura_DeclarePrivUserSymbol(GetSelection);
Gura_DeclarePrivUserSymbol(GetStringSelection);
Gura_DeclarePrivUserSymbol(Paste);
Gura_DeclarePrivUserSymbol(Redo);
Gura_DeclarePrivUserSymbol(Remove);
Gura_DeclarePrivUserSymbol(Replace);
Gura_DeclarePrivUserSymbol(SetEditable);
Gura_DeclarePrivUserSymbol(SetInsertionPoint);
Gura_DeclarePrivUserSymbol(SetInsertionPointEnd);
Gura_DeclarePrivUserSymbol(SetMaxLength);
Gura_DeclarePrivUserSymbol(SetSelection);
Gura_DeclarePrivUserSymbol(SetValue);
Gura_DeclarePrivUserSymbol(ChangeValue);
Gura_DeclarePrivUserSymbol(Undo);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextCtrl: public wxTextCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TextCtrl *_pObj;
public:
	inline wx_TextCtrl() : wxTextCtrl(), _pObj(nullptr) {}
	inline wx_TextCtrl(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxTextCtrl(parent, id, value, pos, size, style, validator, name), _pObj(nullptr) {}
	//virtual bool CanCopy();
	//virtual bool CanCut();
	//virtual bool CanPaste();
	//virtual bool CanRedo();
	//virtual bool CanUndo();
	//virtual void Clear();
	//virtual void Copy();
	//virtual void Cut();
	//virtual long GetInsertionPoint();
	//virtual wxTextPos GetLastPosition();
	//virtual wxString GetRange(long from, long to);
	//virtual void GetSelection(long* from, long* to);
	//virtual wxString GetStringSelection();
	//virtual void Paste();
	//virtual void Redo();
	//virtual void Remove(long from, long to);
	//virtual void Replace(long from, long to, const wxString& value);
	//virtual void SetEditable(const bool editable);
	//virtual void SetInsertionPoint(long pos);
	//virtual void SetInsertionPointEnd();
	//virtual void SetMaxLength(unsigned long len);
	//virtual void SetSelection(long from, long to);
	//virtual void SetValue(const wxString& value);
	//virtual void ChangeValue(const wxString& value);
	//virtual void Undo();
	~wx_TextCtrl();
	inline void AssocWithGura(Object_wx_TextCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextCtrl::~wx_TextCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextCtrlEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextCtrlEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TextCtrl *pEntity = new wx_TextCtrl();
	Object_wx_TextCtrl *pObj = Object_wx_TextCtrl::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(TextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextCtrl)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxT("");
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxTextCtrlNameStr;
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_TextCtrl *pEntity = new wx_TextCtrl(parent, id, value, *pos, *size, style, *validator, name);
	Object_wx_TextCtrl *pObj = Object_wx_TextCtrl::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_TextCtrl, AppendText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, AppendText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->AppendText(text);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, CanCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanCopy)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanCopy();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, CanCut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanCut)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanCut();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, CanPaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanPaste)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanPaste();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, CanRedo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanRedo)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanRedo();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanUndo();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxT("");
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxTextCtrlNameStr;
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, value, *pos, *size, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, Cut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Cut)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, DiscardEdits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, DiscardEdits)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DiscardEdits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, EmulateKeyPress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, EmulateKeyPress)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->EmulateKeyPress(*event);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetDefaultStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxTextAttr &rtn = pThis->GetEntity()->GetDefaultStyle();
	return ReturnValue(env, args, Value(new Object_wx_TextAttr(new wxTextAttr(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextCtrl, GetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetInsertionPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetInsertionPoint();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetLastPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetLastPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextPos rtn = pThis->GetEntity()->GetLastPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetLineLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetLineLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long lineNo = args.GetLong(0);
	int rtn = pThis->GetEntity()->GetLineLength(lineNo);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetLineText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetLineText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long lineNo = args.GetLong(0);
	wxString rtn = pThis->GetEntity()->GetLineText(lineNo);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextCtrl, GetNumberOfLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetNumberOfLines)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetNumberOfLines();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString rtn = pThis->GetEntity()->GetRange(from, to);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextCtrl, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from;
	long to;
	pThis->GetEntity()->GetSelection(&from, &to);
	return ReturnValue(env, args, Value::CreateList(env, from, to));
}

Gura_DeclareMethod(wx_TextCtrl, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetStringSelection();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextCtrl, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long position = args.GetLong(0);
	wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->GetStyle(position, *style);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxTextCoord col;
	wxTextCoord row;
	wxTextCtrlHitTestResult rtn = pThis->GetEntity()->HitTest(*pt, &col, &row);
	return ReturnValue(env, args, Value::CreateList(env, rtn, col, row));
}

Gura_DeclareMethod(wx_TextCtrl, IsEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsEditable)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEditable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, IsModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsModified();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, IsMultiLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsMultiLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsMultiLine();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, IsSingleLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsSingleLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsSingleLine();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fileType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int fileType = wxTEXT_TYPE_ANY;
	if (args.IsValid(1)) fileType = args.GetInt(1);
	bool rtn = pThis->GetEntity()->LoadFile(filename, fileType);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, OnChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, OnChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnChar(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, MarkDirty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, MarkDirty)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->MarkDirty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, OnDropFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_DropFilesEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, OnDropFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDropFilesEvent *event = Object_wx_DropFilesEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnDropFiles(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, Paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Paste)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, PositionToXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, PositionToXY)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long pos = args.GetLong(0);
	long x;
	long y;
	bool rtn = pThis->GetEntity()->PositionToXY(pos, &x, &y);
	if (!rtn) return Value::Nil;
	return ReturnValue(env, args, Value::CreateList(env, x, y));
}

Gura_DeclareMethod(wx_TextCtrl, Redo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Redo)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pThis->GetEntity()->Remove(from, to);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, Replace)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString value = wxString::FromUTF8(args.GetString(2));
	pThis->GetEntity()->Replace(from, to, value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fileType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, SaveFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int fileType = wxTEXT_TYPE_ANY;
	if (args.IsValid(1)) fileType = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SaveFile(filename, fileType);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, SetDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, SetDefaultStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetDefaultStyle(*style);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, SetEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "editable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetEditable)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool editable = args.GetBoolean(0);
	pThis->GetEntity()->SetEditable(editable);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetInsertionPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long pos = args.GetLong(0);
	pThis->GetEntity()->SetInsertionPoint(pos);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SetInsertionPointEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, SetInsertionPointEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SetMaxLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetMaxLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned len = args.GetInt(0);
	pThis->GetEntity()->SetMaxLength(len);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SetModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "modified", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool modified = args.GetBoolean(0);
	pThis->GetEntity()->SetModified(modified);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pThis->GetEntity()->SetSelection(from, to);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long start = args.GetLong(0);
	long end = args.GetLong(1);
	wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->SetStyle(start, end, *style);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetValue(value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, ChangeValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, ChangeValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->ChangeValue(value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, ShowPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, ShowPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long pos = args.GetLong(0);
	pThis->GetEntity()->ShowPosition(pos);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Undo)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, WriteText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, WriteText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->WriteText(text);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, XYToPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, XYToPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	long rtn = pThis->GetEntity()->XYToPosition(x, y);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTextCtrl
//----------------------------------------------------------------------------
Object_wx_TextCtrl::~Object_wx_TextCtrl()
{
}

Object *Object_wx_TextCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_TextCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.TextCtrl:");
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
// Class implementation for wxTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextCtrl)
{
	Gura_RealizeUserSymbol(CanCopy);
	Gura_RealizeUserSymbol(CanCut);
	Gura_RealizeUserSymbol(CanPaste);
	Gura_RealizeUserSymbol(CanRedo);
	Gura_RealizeUserSymbol(CanUndo);
	Gura_RealizeUserSymbol(Clear);
	Gura_RealizeUserSymbol(Copy);
	Gura_RealizeUserSymbol(Cut);
	Gura_RealizeUserSymbol(GetInsertionPoint);
	Gura_RealizeUserSymbol(GetLastPosition);
	Gura_RealizeUserSymbol(GetRange);
	Gura_RealizeUserSymbol(GetSelection);
	Gura_RealizeUserSymbol(GetStringSelection);
	Gura_RealizeUserSymbol(Paste);
	Gura_RealizeUserSymbol(Redo);
	Gura_RealizeUserSymbol(Remove);
	Gura_RealizeUserSymbol(Replace);
	Gura_RealizeUserSymbol(SetEditable);
	Gura_RealizeUserSymbol(SetInsertionPoint);
	Gura_RealizeUserSymbol(SetInsertionPointEnd);
	Gura_RealizeUserSymbol(SetMaxLength);
	Gura_RealizeUserSymbol(SetSelection);
	Gura_RealizeUserSymbol(SetValue);
	Gura_RealizeUserSymbol(ChangeValue);
	Gura_RealizeUserSymbol(Undo);
	Gura_AssignWxStringValue(TextCtrlNameStr);
	Gura_AssignFunction(TextCtrlEmpty);
	Gura_AssignFunction(TextCtrl);
	Gura_AssignMethod(wx_TextCtrl, AppendText);
	Gura_AssignMethod(wx_TextCtrl, CanCopy);
	Gura_AssignMethod(wx_TextCtrl, CanCut);
	Gura_AssignMethod(wx_TextCtrl, CanPaste);
	Gura_AssignMethod(wx_TextCtrl, CanRedo);
	Gura_AssignMethod(wx_TextCtrl, CanUndo);
	Gura_AssignMethod(wx_TextCtrl, Clear);
	Gura_AssignMethod(wx_TextCtrl, Copy);
	Gura_AssignMethod(wx_TextCtrl, Create);
	Gura_AssignMethod(wx_TextCtrl, Cut);
	Gura_AssignMethod(wx_TextCtrl, DiscardEdits);
	Gura_AssignMethod(wx_TextCtrl, EmulateKeyPress);
	Gura_AssignMethod(wx_TextCtrl, GetDefaultStyle);
	Gura_AssignMethod(wx_TextCtrl, GetInsertionPoint);
	Gura_AssignMethod(wx_TextCtrl, GetLastPosition);
	Gura_AssignMethod(wx_TextCtrl, GetLineLength);
	Gura_AssignMethod(wx_TextCtrl, GetLineText);
	Gura_AssignMethod(wx_TextCtrl, GetNumberOfLines);
	Gura_AssignMethod(wx_TextCtrl, GetRange);
	Gura_AssignMethod(wx_TextCtrl, GetSelection);
	Gura_AssignMethod(wx_TextCtrl, GetStringSelection);
	Gura_AssignMethod(wx_TextCtrl, GetStyle);
	Gura_AssignMethod(wx_TextCtrl, GetValue);
	Gura_AssignMethod(wx_TextCtrl, HitTest);
	Gura_AssignMethod(wx_TextCtrl, IsEditable);
	Gura_AssignMethod(wx_TextCtrl, IsEmpty);
	Gura_AssignMethod(wx_TextCtrl, IsModified);
	Gura_AssignMethod(wx_TextCtrl, IsMultiLine);
	Gura_AssignMethod(wx_TextCtrl, IsSingleLine);
	Gura_AssignMethod(wx_TextCtrl, LoadFile);
	Gura_AssignMethod(wx_TextCtrl, OnChar);
	Gura_AssignMethod(wx_TextCtrl, MarkDirty);
	Gura_AssignMethod(wx_TextCtrl, OnDropFiles);
	Gura_AssignMethod(wx_TextCtrl, Paste);
	Gura_AssignMethod(wx_TextCtrl, PositionToXY);
	Gura_AssignMethod(wx_TextCtrl, Redo);
	Gura_AssignMethod(wx_TextCtrl, Remove);
	Gura_AssignMethod(wx_TextCtrl, Replace);
	Gura_AssignMethod(wx_TextCtrl, SaveFile);
	Gura_AssignMethod(wx_TextCtrl, SetDefaultStyle);
	Gura_AssignMethod(wx_TextCtrl, SetEditable);
	Gura_AssignMethod(wx_TextCtrl, SetInsertionPoint);
	Gura_AssignMethod(wx_TextCtrl, SetInsertionPointEnd);
	Gura_AssignMethod(wx_TextCtrl, SetMaxLength);
	Gura_AssignMethod(wx_TextCtrl, SetModified);
	Gura_AssignMethod(wx_TextCtrl, SetSelection);
	Gura_AssignMethod(wx_TextCtrl, SetStyle);
	Gura_AssignMethod(wx_TextCtrl, SetValue);
	Gura_AssignMethod(wx_TextCtrl, ChangeValue);
	Gura_AssignMethod(wx_TextCtrl, ShowPosition);
	Gura_AssignMethod(wx_TextCtrl, Undo);
	Gura_AssignMethod(wx_TextCtrl, WriteText);
	Gura_AssignMethod(wx_TextCtrl, XYToPosition);
}

Gura_ImplementDescendantCreator(wx_TextCtrl)
{
	return new Object_wx_TextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
