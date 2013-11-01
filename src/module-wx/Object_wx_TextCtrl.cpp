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
	Gura::Signal _sig;
	Object_wx_TextCtrl *_pObj;
public:
	inline wx_TextCtrl() : wxTextCtrl(), _sig(NULL), _pObj(NULL) {}
	inline wx_TextCtrl(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxTextCtrl(parent, id, value, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
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
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TextCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextCtrl::~wx_TextCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TextCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextCtrlEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TextCtrl *pEntity = new wx_TextCtrl();
	Object_wx_TextCtrl *pObj = Object_wx_TextCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TextCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(TextCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
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
	Object_wx_TextCtrl *pObj = Object_wx_TextCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TextCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TextCtrl, AppendText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, AppendText)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->AppendText(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, CanCopy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanCopy)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanCopy();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, CanCut)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanCut)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanCut();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, CanPaste)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanPaste)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanPaste();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, CanRedo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanRedo)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanRedo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, CanUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, CanUndo)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Clear)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, Copy)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Copy)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Copy();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
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
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, Cut)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Cut)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Cut();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, DiscardEdits)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, DiscardEdits)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DiscardEdits();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, EmulateKeyPress)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, EmulateKeyPress)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->EmulateKeyPress(*event);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetDefaultStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetDefaultStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxTextAttr &rtn = pThis->GetEntity()->GetDefaultStyle();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextAttr(new wxTextAttr(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextCtrl, GetInsertionPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetInsertionPoint)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetInsertionPoint();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetLastPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetLastPosition)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextPos rtn = pThis->GetEntity()->GetLastPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetLineLength)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetLineLength)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long lineNo = args.GetLong(0);
	int rtn = pThis->GetEntity()->GetLineLength(lineNo);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetLineText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetLineText)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long lineNo = args.GetLong(0);
	wxString rtn = pThis->GetEntity()->GetLineText(lineNo);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextCtrl, GetNumberOfLines)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetNumberOfLines)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetNumberOfLines();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetRange)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetRange)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString rtn = pThis->GetEntity()->GetRange(from, to);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextCtrl, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetSelection)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long from;
	long to;
	pThis->GetEntity()->GetSelection(&from, &to);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, from, to));
}

Gura_DeclareMethod(wx_TextCtrl, GetStringSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetStringSelection)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetStringSelection();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextCtrl, GetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->GetStyle(position, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, GetValue)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextCtrl, HitTest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, HitTest)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxTextCoord col;
	wxTextCoord row;
	wxTextCtrlHitTestResult rtn = pThis->GetEntity()->HitTest(*pt, &col, &row);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, rtn, col, row));
}

Gura_DeclareMethod(wx_TextCtrl, IsEditable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsEditable)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEditable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, IsEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsEmpty)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, IsModified)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsModified)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsModified();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, IsMultiLine)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsMultiLine)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsMultiLine();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, IsSingleLine)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, IsSingleLine)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsSingleLine();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, LoadFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fileType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, LoadFile)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int fileType = wxTEXT_TYPE_ANY;
	if (args.IsValid(1)) fileType = args.GetInt(1);
	bool rtn = pThis->GetEntity()->LoadFile(filename, fileType);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, OnChar)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, OnChar)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnChar(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, MarkDirty)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, MarkDirty)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->MarkDirty();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, OnDropFiles)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_DropFilesEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, OnDropFiles)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDropFilesEvent *event = Object_wx_DropFilesEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnDropFiles(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, Paste)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Paste)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Paste();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, PositionToXY)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, PositionToXY)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	long x;
	long y;
	bool rtn = pThis->GetEntity()->PositionToXY(pos, &x, &y);
	if (!rtn) return Value::Null;
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y));
}

Gura_DeclareMethod(wx_TextCtrl, Redo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Redo)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Redo();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, Remove)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, Remove)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pThis->GetEntity()->Remove(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, Replace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, Replace)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString value = wxString::FromUTF8(args.GetString(2));
	pThis->GetEntity()->Replace(from, to, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, SaveFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fileType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, SaveFile)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int fileType = wxTEXT_TYPE_ANY;
	if (args.IsValid(1)) fileType = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SaveFile(filename, fileType);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, SetDefaultStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, SetDefaultStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetDefaultStyle(*style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, SetEditable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "editable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetEditable)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool editable = args.GetBoolean(0);
	pThis->GetEntity()->SetEditable(editable);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, SetInsertionPoint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetInsertionPoint)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	pThis->GetEntity()->SetInsertionPoint(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, SetInsertionPointEnd)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, SetInsertionPointEnd)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, SetMaxLength)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetMaxLength)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned len = args.GetInt(0);
	pThis->GetEntity()->SetMaxLength(len);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, SetModified)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "modified", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetModified)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool modified = args.GetBoolean(0);
	pThis->GetEntity()->SetModified(modified);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, SetSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetSelection)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pThis->GetEntity()->SetSelection(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, SetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, SetStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long start = args.GetLong(0);
	long end = args.GetLong(1);
	wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->SetStyle(start, end, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextCtrl, SetValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetValue)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetValue(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, ChangeValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, ChangeValue)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->ChangeValue(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, ShowPosition)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, ShowPosition)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	pThis->GetEntity()->ShowPosition(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, Undo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, Undo)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Undo();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, WriteText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, WriteText)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->WriteText(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextCtrl, XYToPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextCtrl, XYToPosition)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	long rtn = pThis->GetEntity()->XYToPosition(x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTextCtrl
//----------------------------------------------------------------------------
Object_wx_TextCtrl::~Object_wx_TextCtrl()
{
}

Object *Object_wx_TextCtrl::Clone() const
{
	return NULL;
}

String Object_wx_TextCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.TextCtrl:");
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
	return new Object_wx_TextCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
