//----------------------------------------------------------------------------
// wxRichTextCtrl
// extracted from richtextctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextCtrl: public wxRichTextCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextCtrl *_pObj;
public:
	inline wx_RichTextCtrl() : wxRichTextCtrl(), _sig(NULL), _pObj(NULL) {}
	inline wx_RichTextCtrl(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxRichTextCtrl(parent, id, value, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextCtrl::~wx_RichTextCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextCtrlEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_RichTextCtrl *pEntity = new wx_RichTextCtrl();
	Object_wx_RichTextCtrl *pObj = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(RichTextCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxEmptyString;
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxRE_MULTILINE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxTextCtrlNameStr;
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_RichTextCtrl *pEntity = new wx_RichTextCtrl(parent, id, value, *pos, *size, style, *validator, name);
	Object_wx_RichTextCtrl *pObj = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_RichTextCtrl, AddImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "image", VTYPE_wx_Image, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, AddImage)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxImage *image = Object_wx_Image::GetObject(args, 0)->GetEntity();
	wxRichTextRange rtn = pSelf->GetEntity()->AddImage(*image);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextRange(new wxRichTextRange(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextCtrl, AddParagraph)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, AddParagraph)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxRichTextRange rtn = pSelf->GetEntity()->AddParagraph(text);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextRange(new wxRichTextRange(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextCtrl, AppendText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, AppendText)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->AppendText(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyAlignmentToSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyAlignmentToSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment alignment = static_cast<wxTextAttrAlignment>(args.GetInt(0));
	bool rtn = pSelf->GetEntity()->ApplyAlignmentToSelection(alignment);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyBoldToSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyBoldToSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ApplyBoldToSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyItalicToSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyItalicToSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ApplyItalicToSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextStyleDefinition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleDefinition *def = Object_wx_RichTextStyleDefinition::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->ApplyStyle(def);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyStyleSheet)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyStyleSheet)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *sheet = (wxRichTextStyleSheet *)(NULL);
	if (args.IsValid(0)) sheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->ApplyStyleSheet(sheet);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyUnderlineToSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyUnderlineToSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ApplyUnderlineToSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BatchingUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BatchingUndo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BatchingUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginAlignment)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment alignment = static_cast<wxTextAttrAlignment>(args.GetInt(0));
	bool rtn = pSelf->GetEntity()->BeginAlignment(alignment);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginBatchUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cmdName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginBatchUndo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString cmdName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->BeginBatchUndo(cmdName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginBold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginBold)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BeginBold();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginCharacterStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "characterStyle", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginCharacterStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString characterStyle = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->BeginCharacterStyle(characterStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginFont)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginFont)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->BeginFont(*font);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginFontSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginFontSize)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pointSize = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->BeginFontSize(pointSize);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginItalic)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginItalic)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BeginItalic();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginLeftIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginLeftIndent)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int leftIndent = args.GetInt(0);
	int leftSubIndent = 0;
	if (args.IsValid(1)) leftSubIndent = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->BeginLeftIndent(leftIndent, leftSubIndent);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginLineSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lineSpacing", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginLineSpacing)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int lineSpacing = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->BeginLineSpacing(lineSpacing);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginListStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "listStyle", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "number", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginListStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString listStyle = wxString::FromUTF8(args.GetString(0));
	int level = 1;
	if (args.IsValid(1)) level = args.GetInt(1);
	int number = 1;
	if (args.IsValid(2)) number = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->BeginListStyle(listStyle, level, number);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginNumberedBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bulletNumber", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginNumberedBullet)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int bulletNumber = args.GetInt(0);
	int leftIndent = args.GetInt(1);
	int leftSubIndent = args.GetInt(2);
	int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_ARABIC|wxTEXT_ATTR_BULLET_STYLE_PERIOD;
	if (args.IsValid(3)) bulletStyle = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->BeginNumberedBullet(bulletNumber, leftIndent, leftSubIndent, bulletStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginParagraphSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "after", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginParagraphSpacing)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int before = args.GetInt(0);
	int after = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->BeginParagraphSpacing(before, after);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginParagraphStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "paragraphStyle", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginParagraphStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString paragraphStyle = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->BeginParagraphStyle(paragraphStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginRightIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rightIndent", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginRightIndent)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rightIndent = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->BeginRightIndent(rightIndent);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = false;
	if (args.IsInstanceOf(0, VTYPE_wx_TextAttrEx)) {
		wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->BeginStyle(*style);
	} else if (args.IsInstanceOf(0, VTYPE_wx_RichTextAttr)) {
		wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->BeginStyle(*style);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginSuppressUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginSuppressUndo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BeginSuppressUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginSymbolBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginSymbolBullet)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString symbol = wxString::FromUTF8(args.GetString(0));
	if (symbol.Length() != 1) {
		sig.SetError(ERR_ValueError, "symbol must be a single character");
		return Value::Null;
	}
	int leftIndent = args.GetInt(1);
	int leftSubIndent = args.GetInt(2);
	int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_SYMBOL;
	if (args.IsValid(3)) bulletStyle = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->BeginSymbolBullet(symbol[0], leftIndent, leftSubIndent, bulletStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginTextColour)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->BeginTextColour(*colour);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginUnderline)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginUnderline)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BeginUnderline();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginURL)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "characterStyle", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginURL)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	wxString characterStyle = wxEmptyString;
	if (args.IsValid(1)) characterStyle = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->BeginURL(url, characterStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, CanCopy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanCopy)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanCopy();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, CanCut)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanCut)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanCut();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, CanDeleteSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanDeleteSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanDeleteSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, CanPaste)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanPaste)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanPaste();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, CanRedo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanRedo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanRedo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, CanUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanUndo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Clear)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, ClearListStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ClearListStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->ClearListStyle(*range, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, ClearListStyle_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ClearListStyle_1)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->ClearListStyle(*range, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, Command)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, Command)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Command(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, Copy)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Copy)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Copy();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, Create)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxEmptyString;
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxRE_MULTILINE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxTextCtrlNameStr;
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pSelf->GetEntity()->Create(parent, id, value, *pos, *size, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, Cut)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Cut)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Cut();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, Delete)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, Delete)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->Delete(*range);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, DeleteSelectedContent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, DeleteSelectedContent)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long newPos = 0;
	if (args.IsValid(0)) newPos = args.GetLong(0);
	bool rtn = pSelf->GetEntity()->DeleteSelectedContent(&newPos);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, rtn, newPos));
}

Gura_DeclareMethod(wx_RichTextCtrl, DeleteSelection)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, DeleteSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->DeleteSelection();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, DiscardEdits)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, DiscardEdits)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->DiscardEdits();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoGetBestSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoGetBestSize)
{
#if 0
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pSelf->GetEntity()->DoGetBestSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndAlignment)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndAlignment();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndAllStyles)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndAllStyles)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndAllStyles();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndBatchUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndBatchUndo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndBatchUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndBold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndBold)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndBold();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndCharacterStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndCharacterStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndCharacterStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndFont)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndFont();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndFontSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndFontSize)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndFontSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndItalic)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndItalic)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndItalic();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndLeftIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndLeftIndent)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndLeftIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndLineSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndLineSpacing)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndLineSpacing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndListStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndListStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndListStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndNumberedBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndNumberedBullet)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndNumberedBullet();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndParagraphSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndParagraphSpacing)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndParagraphSpacing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndParagraphStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndParagraphStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndParagraphStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndRightIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndRightIndent)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndRightIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndSuppressUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndSuppressUndo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndSuppressUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndSymbolBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndSymbolBullet)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndSymbolBullet();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndTextColour)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndTextColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndUnderline)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndUnderline)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndUnderline();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, EndURL)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndURL)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndURL();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, ExtendSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "oldPosition", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "newPosition", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ExtendSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long oldPosition = args.GetLong(0);
	long newPosition = args.GetLong(1);
	int flags = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->ExtendSelection(oldPosition, newPosition, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, FindNextWordPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, FindNextWordPosition)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int direction = 1;
	if (args.IsValid(0)) direction = args.GetInt(0);
	long rtn = pSelf->GetEntity()->FindNextWordPosition(direction);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, Freeze)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Freeze)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Freeze();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetBasicStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetBasicStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxTextAttrEx &rtn = pSelf->GetEntity()->GetBasicStyle();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextAttrEx(new wxTextAttrEx(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetBuffer)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxRichTextBuffer &rtn = pSelf->GetEntity()->GetBuffer();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextBuffer(new wxRichTextBuffer(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetBuffer_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetBuffer_1)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer &rtn = pSelf->GetEntity()->GetBuffer();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextBuffer(new wxRichTextBuffer(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetCaretPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetCaretPosition)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetCaretPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetCaretPositionForIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetCaretPositionForIndex)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetCaretPositionForIndex(position, *rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetCommandProcessor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetCommandProcessor)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandProcessor *rtn = (wxCommandProcessor *)pSelf->GetEntity()->GetCommandProcessor();
	return ReturnValue(env, sig, args, Value(new Object_wx_CommandProcessor(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDefaultStyleEx)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDefaultStyleEx)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxTextAttrEx &rtn = pSelf->GetEntity()->GetDefaultStyleEx();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextAttrEx(new wxTextAttrEx(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDelayedLayoutThreshold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDelayedLayoutThreshold)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetDelayedLayoutThreshold();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFilename)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFilename)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetFilename();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFirstVisiblePosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFirstVisiblePosition)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetFirstVisiblePosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetHandlerFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetHandlerFlags)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetHandlerFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetInsertionPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetInsertionPoint)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetInsertionPoint();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetLastPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetLastPosition)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextPos rtn = pSelf->GetEntity()->GetLastPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetLineLength)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetLineLength)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long lineNo = args.GetLong(0);
	int rtn = pSelf->GetEntity()->GetLineLength(lineNo);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetLineText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetLineText)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long lineNo = args.GetLong(0);
	wxString rtn = pSelf->GetEntity()->GetLineText(lineNo);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetLogicalPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ptPhysical", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetLogicalPoint)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *ptPhysical = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint rtn = pSelf->GetEntity()->GetLogicalPoint(*ptPhysical);
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetNumberOfLines)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetNumberOfLines)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetNumberOfLines();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetPhysicalPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ptLogical", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetPhysicalPoint)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *ptLogical = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint rtn = pSelf->GetEntity()->GetPhysicalPoint(*ptLogical);
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetRange)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetRange)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString rtn = pSelf->GetEntity()->GetRange(from, to);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = 0;
	long to = 0;
	pSelf->GetEntity()->GetSelection(&from, &to);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, from, to));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetSelectionRange)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetSelectionRange)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxRichTextRange &rtn = pSelf->GetEntity()->GetSelectionRange();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextRange(new wxRichTextRange(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStringSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStringSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetStringSelection();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	bool rtn = false;
	if (args.IsInstanceOf(1, VTYPE_wx_TextAttrEx)) { // TextAttrEx must be checked before TextAttr
		wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->GetStyle(position, *style);
	} else if (args.IsInstanceOf(1, VTYPE_wx_TextAttr)) {
		wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->GetStyle(position, *style);
	} else if (args.IsInstanceOf(1, VTYPE_wx_RichTextAttr)) {
		wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->GetStyle(position, *style);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyleForRange)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyleForRange)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	bool rtn = false;
	if (args.IsInstanceOf(1, VTYPE_wx_TextAttrEx)) {
		wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->GetStyleForRange(*range, *style);
	} else if (args.IsInstanceOf(1, VTYPE_wx_RichTextAttr)) {
		wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->GetStyleForRange(*range, *style);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyleSheet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyleSheet)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pSelf->GetEntity()->GetStyleSheet();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleSheet(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetUncombinedStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetUncombinedStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	bool rtn = false;
	if (args.IsInstanceOf(1, VTYPE_wx_TextAttrEx)) { // TextAttrEx must be checked before TextAttr
		wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->GetUncombinedStyle(position, *style);
	} else if (args.IsInstanceOf(1, VTYPE_wx_TextAttr)) {
		wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->GetUncombinedStyle(position, *style);
	} else if (args.IsInstanceOf(1, VTYPE_wx_RichTextAttr)) {
		wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->GetUncombinedStyle(position, *style);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetValue)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextCtrl, GetVisibleLineForCaretPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetVisibleLineForCaretPosition)
{
#if 0
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long caretPosition = args.GetLong(0);
	wxRichTextLine *rtn = (wxRichTextLine *)pSelf->GetEntity()->GetVisibleLineForCaretPosition(caretPosition);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextLine(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, HasCharacterAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, HasCharacterAttributes)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->HasCharacterAttributes(*range, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, HasCharacterAttributes_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, HasCharacterAttributes_1)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->HasCharacterAttributes(*range, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, HasParagraphAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, HasParagraphAttributes)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->HasParagraphAttributes(*range, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, HasParagraphAttributes_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, HasParagraphAttributes_1)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->HasParagraphAttributes(*range, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, HasSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, HasSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, HitTest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, HitTest)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	long pos = 0;
	wxTextCtrlHitTestResult rtn = pSelf->GetEntity()->HitTest(*pt, &pos);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, rtn, pos));
}

Gura_DeclareMethod(wx_RichTextCtrl, HitTestXY)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, HitTestXY)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxTextCoord col = 0;
	wxTextCoord row = 0;
	wxTextCtrlHitTestResult rtn = pSelf->GetEntity()->HitTest(*pt, &col, &row);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, rtn, col, row));
}

Gura_DeclareMethod(wx_RichTextCtrl, Init)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Init)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Init();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, InitCommandEvent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_RichTextCtrl, InitCommandEvent)
{
#if 0
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->InitCommandEvent(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsDefaultStyleShowing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsDefaultStyleShowing)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsDefaultStyleShowing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsEditable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsEditable)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsEditable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsFrozen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsFrozen)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsFrozen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsModified)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsModified)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsModified();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsMultiLine)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsMultiLine)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsMultiLine();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsPositionVisible)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsPositionVisible)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	bool rtn = pSelf->GetEntity()->IsPositionVisible(pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSelectionAligned)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSelectionAligned)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment alignment = static_cast<wxTextAttrAlignment>(args.GetInt(0));
	bool rtn = pSelf->GetEntity()->IsSelectionAligned(alignment);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSelectionBold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSelectionBold)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsSelectionBold();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSelectionItalics)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSelectionItalics)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsSelectionItalics();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSelectionUnderlined)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSelectionUnderlined)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsSelectionUnderlined();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSingleLine)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSingleLine)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsSingleLine();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, KeyboardNavigate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, KeyboardNavigate)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int keyCode = args.GetInt(0);
	int flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->KeyboardNavigate(keyCode, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, LayoutContent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "onlyVisibleRect", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, LayoutContent)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool onlyVisibleRect = false;
	if (args.IsValid(0)) onlyVisibleRect = args.GetBoolean(0);
	bool rtn = pSelf->GetEntity()->LayoutContent(onlyVisibleRect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, LineBreak)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, LineBreak)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->LineBreak();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, LoadFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, LoadFile)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	int type = wxRICHTEXT_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->LoadFile(file, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MarkDirty)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, MarkDirty)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->MarkDirty();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveCaret)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "showAtLineStart", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveCaret)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	bool showAtLineStart = false;
	if (args.IsValid(1)) showAtLineStart = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->MoveCaret(pos, showAtLineStart);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveCaretBack)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "oldPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveCaretBack)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long oldPosition = args.GetLong(0);
	pSelf->GetEntity()->MoveCaretBack(oldPosition);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveCaretForward)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "oldPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveCaretForward)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long oldPosition = args.GetLong(0);
	pSelf->GetEntity()->MoveCaretForward(oldPosition);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveDown)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "noLines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveDown)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int noLines = 1;
	if (args.IsValid(0)) noLines = args.GetInt(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->MoveDown(noLines, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveEnd)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveEnd)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int flags = 0;
	if (args.IsValid(0)) flags = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->MoveEnd(flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveHome)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveHome)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int flags = 0;
	if (args.IsValid(0)) flags = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->MoveHome(flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveLeft)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "noPositions", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveLeft)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int noPositions = 1;
	if (args.IsValid(0)) noPositions = args.GetInt(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->MoveLeft(noPositions, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveRight)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "noPositions", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveRight)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int noPositions = 1;
	if (args.IsValid(0)) noPositions = args.GetInt(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->MoveRight(noPositions, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveToLineEnd)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveToLineEnd)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int flags = 0;
	if (args.IsValid(0)) flags = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->MoveToLineEnd(flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveToLineStart)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveToLineStart)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int flags = 0;
	if (args.IsValid(0)) flags = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->MoveToLineStart(flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveToParagraphEnd)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveToParagraphEnd)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int flags = 0;
	if (args.IsValid(0)) flags = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->MoveToParagraphEnd(flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveToParagraphStart)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveToParagraphStart)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int flags = 0;
	if (args.IsValid(0)) flags = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->MoveToParagraphStart(flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveUp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "noLines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveUp)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int noLines = 1;
	if (args.IsValid(0)) noLines = args.GetInt(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->MoveUp(noLines, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, Newline)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, Newline)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Newline();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, NumberList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "startFrom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, NumberList)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	int startFrom = -1;
	if (args.IsValid(3)) startFrom = args.GetInt(3);
	int listLevel = -1;
	if (args.IsValid(4)) listLevel = args.GetInt(4);
	bool rtn = false;
	if (args.IsInvalid(1)) {
		wxRichTextListStyleDefinition *style = NULL;
		rtn = pSelf->GetEntity()->NumberList(*range, style, flags, startFrom, listLevel);
	} else if (args.IsString(1)) {
		wxString styleName = wxString::FromUTF8(args.GetString(1));
		rtn = pSelf->GetEntity()->NumberList(*range, styleName, flags, startFrom, listLevel);
	} else if (args.IsInstanceOf(1, VTYPE_wx_RichTextListStyleDefinition)) {
		wxRichTextListStyleDefinition *style = Object_wx_RichTextListStyleDefinition::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->NumberList(*range, style, flags, startFrom, listLevel);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, OnClear)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnClear)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnClear(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnContextMenu)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_ContextMenuEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnContextMenu)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxContextMenuEvent *event = Object_wx_ContextMenuEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnContextMenu(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnCopy)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnCopy)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnCopy(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnCut)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnCut)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnCut(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnDropFiles)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_DropFilesEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnDropFiles)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDropFilesEvent *event = Object_wx_DropFilesEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnDropFiles(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnPaste)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnPaste)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnPaste(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnRedo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnRedo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnRedo(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnSelectAll)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnSelectAll)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnSelectAll(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUndo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUndo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnUndo(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateClear)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_UpdateUIEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateClear)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxUpdateUIEvent *event = Object_wx_UpdateUIEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnUpdateClear(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateCopy)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_UpdateUIEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateCopy)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxUpdateUIEvent *event = Object_wx_UpdateUIEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnUpdateCopy(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateCut)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_UpdateUIEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateCut)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxUpdateUIEvent *event = Object_wx_UpdateUIEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnUpdateCut(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdatePaste)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_UpdateUIEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdatePaste)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxUpdateUIEvent *event = Object_wx_UpdateUIEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnUpdatePaste(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateRedo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_UpdateUIEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateRedo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxUpdateUIEvent *event = Object_wx_UpdateUIEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnUpdateRedo(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateSelectAll)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_UpdateUIEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateSelectAll)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxUpdateUIEvent *event = Object_wx_UpdateUIEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnUpdateSelectAll(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateUndo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_UpdateUIEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateUndo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxUpdateUIEvent *event = Object_wx_UpdateUIEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnUpdateUndo(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, PageDown)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "noPages", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, PageDown)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int noPages = 1;
	if (args.IsValid(0)) noPages = args.GetInt(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->PageDown(noPages, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, PageUp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "noPages", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, PageUp)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int noPages = 1;
	if (args.IsValid(0)) noPages = args.GetInt(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->PageUp(noPages, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, PaintBackground)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PaintBackground)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->PaintBackground(*dc);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, Paste)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Paste)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Paste();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, PositionCaret)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, PositionCaret)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->PositionCaret();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, PositionToXY)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, PositionToXY)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	long x = 0;
	long y = 0;
	bool rtn = pSelf->GetEntity()->PositionToXY(pos, &x, &y);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, rtn, x, y));
}

Gura_DeclareMethod(wx_RichTextCtrl, PromoteList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextListStyleDefinition, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, PromoteList)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int promoteBy = args.GetInt(0);
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 1)->GetEntity();
	wxRichTextListStyleDefinition *style = Object_wx_RichTextListStyleDefinition::GetObject(args, 2)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(3)) flags = args.GetInt(3);
	int listLevel = -1;
	if (args.IsValid(4)) listLevel = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->PromoteList(promoteBy, *range, style, flags, listLevel);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, PromoteList_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "styleName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, PromoteList_1)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int promoteBy = args.GetInt(0);
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 1)->GetEntity();
	wxString styleName = wxString::FromUTF8(args.GetString(2));
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(3)) flags = args.GetInt(3);
	int listLevel = -1;
	if (args.IsValid(4)) listLevel = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->PromoteList(promoteBy, *range, styleName, flags, listLevel);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, Redo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Redo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Redo();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, Remove)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, Remove)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pSelf->GetEntity()->Remove(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, Replace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, Replace)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString value = wxString::FromUTF8(args.GetString(2));
	pSelf->GetEntity()->Replace(from, to, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SaveFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SaveFile)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString file = wxEmptyString;
	if (args.IsValid(0)) file = wxString::FromUTF8(args.GetString(0));
	int type = wxRICHTEXT_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->SaveFile(file, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, ScrollIntoView)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, ScrollIntoView)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	int keyCode = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->ScrollIntoView(position, keyCode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SelectAll)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, SelectAll)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->SelectAll();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SelectNone)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, SelectNone)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->SelectNone();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetAndShowDefaultStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_RichTextAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetAndShowDefaultStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextAttr *attr = Object_wx_RichTextAttr::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetAndShowDefaultStyle(*attr);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetBasicStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetBasicStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetBasicStyle(*style);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetBasicStyle_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetBasicStyle_1)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetBasicStyle(*style);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetCaretPosition)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "showAtLineStart", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetCaretPosition)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	bool showAtLineStart = false;
	if (args.IsValid(1)) showAtLineStart = args.GetBoolean(1);
	pSelf->GetEntity()->SetCaretPosition(position, showAtLineStart);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDefaultStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDefaultStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = false;
	if (args.IsInstanceOf(0, VTYPE_wx_TextAttrEx)) {
		wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->SetDefaultStyle(*style);
	} else if (args.IsInstanceOf(0, VTYPE_wx_RichTextAttr)) {
		wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->SetDefaultStyle(*style);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDefaultStyleToCursorStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDefaultStyleToCursorStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->SetDefaultStyleToCursorStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDelayedLayoutThreshold)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDelayedLayoutThreshold)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long threshold = args.GetLong(0);
	pSelf->GetEntity()->SetDelayedLayoutThreshold(threshold);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetEditable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "editable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetEditable)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool editable = args.GetBoolean(0);
	pSelf->GetEntity()->SetEditable(editable);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetFilename)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetFilename)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetFilename(filename);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetFont)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->SetFont(*font);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetHandlerFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetHandlerFlags)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	pSelf->GetEntity()->SetHandlerFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetInsertionPoint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetInsertionPoint)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	pSelf->GetEntity()->SetInsertionPoint(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetInsertionPointEnd)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetInsertionPointEnd)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->SetInsertionPointEnd();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetListStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_wx_RichTextListStyleDefinition, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "startFrom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetListStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	int startFrom = -1;
	if (args.IsValid(3)) startFrom = args.GetInt(3);
	int listLevel = -1;
	if (args.IsValid(4)) listLevel = args.GetInt(4);
	bool rtn = false;
	if (args.IsString(1)) {
		wxString styleName = wxString::FromUTF8(args.GetString(1));
		rtn = pSelf->GetEntity()->SetListStyle(*range, styleName, flags, startFrom, listLevel);
	} else if (args.IsInstanceOf(1, VTYPE_wx_RichTextListStyleDefinition)) {
		wxRichTextListStyleDefinition *style = Object_wx_RichTextListStyleDefinition::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->SetListStyle(*range, style, flags, startFrom, listLevel);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetSelection)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pSelf->GetEntity()->SetSelection(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetSelectionRange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetSelectionRange)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetSelectionRange(*range);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyle)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	bool rtn = false;
	if (args.IsInstanceOf(1, VTYPE_wx_TextAttrEx)) { // TextAttrEx must be checked before TextAttr
		wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->SetStyle(*range, *style);
	} else if (args.IsInstanceOf(1, VTYPE_wx_TextAttr)) {
		wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->SetStyle(range->GetStart(), range->GetEnd(), *style);
	} else if (args.IsInstanceOf(1, VTYPE_wx_RichTextAttr)) {
		wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
		rtn = pSelf->GetEntity()->SetStyle(*range, *style);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyle_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyle_1)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long start = args.GetLong(0);
	long end = args.GetLong(1);
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 2)->GetEntity();
	bool rtn = pSelf->GetEntity()->SetStyle(start, end, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyle_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyle_2)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long start = args.GetLong(0);
	long end = args.GetLong(1);
	wxTextAttr *style = Object_wx_TextAttr::GetObject(args, 2)->GetEntity();
	bool rtn = pSelf->GetEntity()->SetStyle(start, end, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyleEx)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyleEx)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->SetStyleEx(*range, *style, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyleEx_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyleEx_1)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->SetStyleEx(*range, *style, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyleEx_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyleEx_2)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long start = args.GetLong(0);
	long end = args.GetLong(1);
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 2)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(3)) flags = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->SetStyleEx(start, end, *style, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyleSheet)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyleSheet)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetStyleSheet(styleSheet);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetValue)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetValue(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetupScrollbars)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "atTop", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetupScrollbars)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool atTop = false;
	if (args.IsValid(0)) atTop = args.GetBoolean(0);
	pSelf->GetEntity()->SetupScrollbars(atTop);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, ShowPosition)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ShowPosition)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	pSelf->GetEntity()->ShowPosition(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, SuppressingUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, SuppressingUndo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->SuppressingUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, Thaw)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Thaw)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Thaw();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, Undo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Undo)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Undo();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, WordLeft)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "noWords", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, WordLeft)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int noWords = 1;
	if (args.IsValid(0)) noWords = args.GetInt(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->WordLeft(noWords, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, WordRight)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "noWords", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, WordRight)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int noWords = 1;
	if (args.IsValid(0)) noWords = args.GetInt(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->WordRight(noWords, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteImageFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteImageFile)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int bitmapType = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->WriteImage(filename, bitmapType);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteImageBlock)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "imageBlock", VTYPE_wx_RichTextImageBlock, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteImageBlock)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextImageBlock *imageBlock = Object_wx_RichTextImageBlock::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->WriteImage(*imageBlock);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteBitmap)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteBitmap)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	int bitmapType = wxBITMAP_TYPE_PNG;
	if (args.IsValid(1)) bitmapType = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->WriteImage(*bitmap, bitmapType);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "image", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteImage)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxImage *image = Object_wx_Image::GetObject(args, 0)->GetEntity();
	int bitmapType = wxBITMAP_TYPE_PNG;
	if (args.IsValid(1)) bitmapType = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->WriteImage(*image, bitmapType);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteText)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->WriteText(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextCtrl, XYToPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextCtrl, XYToPosition)
{
	Object_wx_RichTextCtrl *pSelf = Object_wx_RichTextCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	long rtn = pSelf->GetEntity()->XYToPosition(x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCtrl
//----------------------------------------------------------------------------
Object_wx_RichTextCtrl::~Object_wx_RichTextCtrl()
{
}

Object *Object_wx_RichTextCtrl::Clone() const
{
	return NULL;
}

String Object_wx_RichTextCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextCtrl::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RichTextCtrlEmpty);
	Gura_AssignFunction(RichTextCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCtrl)
{
	Gura_AssignMethod(wx_RichTextCtrl, AddImage);
	Gura_AssignMethod(wx_RichTextCtrl, AddParagraph);
	Gura_AssignMethod(wx_RichTextCtrl, AppendText);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyAlignmentToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyBoldToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyItalicToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyStyle);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyUnderlineToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, BatchingUndo);
	Gura_AssignMethod(wx_RichTextCtrl, BeginAlignment);
	Gura_AssignMethod(wx_RichTextCtrl, BeginBatchUndo);
	Gura_AssignMethod(wx_RichTextCtrl, BeginBold);
	Gura_AssignMethod(wx_RichTextCtrl, BeginCharacterStyle);
	Gura_AssignMethod(wx_RichTextCtrl, BeginFont);
	Gura_AssignMethod(wx_RichTextCtrl, BeginFontSize);
	Gura_AssignMethod(wx_RichTextCtrl, BeginItalic);
	Gura_AssignMethod(wx_RichTextCtrl, BeginLeftIndent);
	Gura_AssignMethod(wx_RichTextCtrl, BeginLineSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, BeginListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, BeginNumberedBullet);
	Gura_AssignMethod(wx_RichTextCtrl, BeginParagraphSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, BeginParagraphStyle);
	Gura_AssignMethod(wx_RichTextCtrl, BeginRightIndent);
	Gura_AssignMethod(wx_RichTextCtrl, BeginStyle);
	Gura_AssignMethod(wx_RichTextCtrl, BeginSuppressUndo);
	Gura_AssignMethod(wx_RichTextCtrl, BeginSymbolBullet);
	Gura_AssignMethod(wx_RichTextCtrl, BeginTextColour);
	Gura_AssignMethod(wx_RichTextCtrl, BeginUnderline);
	Gura_AssignMethod(wx_RichTextCtrl, BeginURL);
	Gura_AssignMethod(wx_RichTextCtrl, CanCopy);
	Gura_AssignMethod(wx_RichTextCtrl, CanCut);
	Gura_AssignMethod(wx_RichTextCtrl, CanDeleteSelection);
	Gura_AssignMethod(wx_RichTextCtrl, CanPaste);
	Gura_AssignMethod(wx_RichTextCtrl, CanRedo);
	Gura_AssignMethod(wx_RichTextCtrl, CanUndo);
	Gura_AssignMethod(wx_RichTextCtrl, Clear);
	Gura_AssignMethod(wx_RichTextCtrl, ClearListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, ClearListStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, Command);
	Gura_AssignMethod(wx_RichTextCtrl, Copy);
	Gura_AssignMethod(wx_RichTextCtrl, Create);
	Gura_AssignMethod(wx_RichTextCtrl, Cut);
	Gura_AssignMethod(wx_RichTextCtrl, Delete);
	Gura_AssignMethod(wx_RichTextCtrl, DeleteSelectedContent);
	Gura_AssignMethod(wx_RichTextCtrl, DeleteSelection);
	Gura_AssignMethod(wx_RichTextCtrl, DiscardEdits);
	Gura_AssignMethod(wx_RichTextCtrl, DoGetBestSize);
	Gura_AssignMethod(wx_RichTextCtrl, EndAlignment);
	Gura_AssignMethod(wx_RichTextCtrl, EndAllStyles);
	Gura_AssignMethod(wx_RichTextCtrl, EndBatchUndo);
	Gura_AssignMethod(wx_RichTextCtrl, EndBold);
	Gura_AssignMethod(wx_RichTextCtrl, EndCharacterStyle);
	Gura_AssignMethod(wx_RichTextCtrl, EndFont);
	Gura_AssignMethod(wx_RichTextCtrl, EndFontSize);
	Gura_AssignMethod(wx_RichTextCtrl, EndItalic);
	Gura_AssignMethod(wx_RichTextCtrl, EndLeftIndent);
	Gura_AssignMethod(wx_RichTextCtrl, EndLineSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, EndListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, EndNumberedBullet);
	Gura_AssignMethod(wx_RichTextCtrl, EndParagraphSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, EndParagraphStyle);
	Gura_AssignMethod(wx_RichTextCtrl, EndRightIndent);
	Gura_AssignMethod(wx_RichTextCtrl, EndStyle);
	Gura_AssignMethod(wx_RichTextCtrl, EndSuppressUndo);
	Gura_AssignMethod(wx_RichTextCtrl, EndSymbolBullet);
	Gura_AssignMethod(wx_RichTextCtrl, EndTextColour);
	Gura_AssignMethod(wx_RichTextCtrl, EndUnderline);
	Gura_AssignMethod(wx_RichTextCtrl, EndURL);
	Gura_AssignMethod(wx_RichTextCtrl, ExtendSelection);
	Gura_AssignMethod(wx_RichTextCtrl, FindNextWordPosition);
	Gura_AssignMethod(wx_RichTextCtrl, Freeze);
	Gura_AssignMethod(wx_RichTextCtrl, GetBasicStyle);
	Gura_AssignMethod(wx_RichTextCtrl, GetBuffer);
	Gura_AssignMethod(wx_RichTextCtrl, GetBuffer_1);
	Gura_AssignMethod(wx_RichTextCtrl, GetCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, GetCaretPositionForIndex);
	Gura_AssignMethod(wx_RichTextCtrl, GetCommandProcessor);
	Gura_AssignMethod(wx_RichTextCtrl, GetDefaultStyleEx);
	Gura_AssignMethod(wx_RichTextCtrl, GetDelayedLayoutThreshold);
	Gura_AssignMethod(wx_RichTextCtrl, GetFilename);
	Gura_AssignMethod(wx_RichTextCtrl, GetFirstVisiblePosition);
	Gura_AssignMethod(wx_RichTextCtrl, GetHandlerFlags);
	Gura_AssignMethod(wx_RichTextCtrl, GetInsertionPoint);
	Gura_AssignMethod(wx_RichTextCtrl, GetLastPosition);
	Gura_AssignMethod(wx_RichTextCtrl, GetLineLength);
	Gura_AssignMethod(wx_RichTextCtrl, GetLineText);
	Gura_AssignMethod(wx_RichTextCtrl, GetLogicalPoint);
	Gura_AssignMethod(wx_RichTextCtrl, GetNumberOfLines);
	Gura_AssignMethod(wx_RichTextCtrl, GetPhysicalPoint);
	Gura_AssignMethod(wx_RichTextCtrl, GetRange);
	Gura_AssignMethod(wx_RichTextCtrl, GetSelection);
	Gura_AssignMethod(wx_RichTextCtrl, GetSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, GetStringSelection);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyle);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyleForRange);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, GetUncombinedStyle);
	Gura_AssignMethod(wx_RichTextCtrl, GetValue);
	Gura_AssignMethod(wx_RichTextCtrl, GetVisibleLineForCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, HasCharacterAttributes);
	Gura_AssignMethod(wx_RichTextCtrl, HasCharacterAttributes_1);
	Gura_AssignMethod(wx_RichTextCtrl, HasParagraphAttributes);
	Gura_AssignMethod(wx_RichTextCtrl, HasParagraphAttributes_1);
	Gura_AssignMethod(wx_RichTextCtrl, HasSelection);
	Gura_AssignMethod(wx_RichTextCtrl, HitTest);
	Gura_AssignMethod(wx_RichTextCtrl, HitTestXY);
	Gura_AssignMethod(wx_RichTextCtrl, Init);
	Gura_AssignMethod(wx_RichTextCtrl, InitCommandEvent);
	Gura_AssignMethod(wx_RichTextCtrl, IsDefaultStyleShowing);
	Gura_AssignMethod(wx_RichTextCtrl, IsEditable);
	Gura_AssignMethod(wx_RichTextCtrl, IsFrozen);
	Gura_AssignMethod(wx_RichTextCtrl, IsModified);
	Gura_AssignMethod(wx_RichTextCtrl, IsMultiLine);
	Gura_AssignMethod(wx_RichTextCtrl, IsPositionVisible);
	Gura_AssignMethod(wx_RichTextCtrl, IsSelectionAligned);
	Gura_AssignMethod(wx_RichTextCtrl, IsSelectionBold);
	Gura_AssignMethod(wx_RichTextCtrl, IsSelectionItalics);
	Gura_AssignMethod(wx_RichTextCtrl, IsSelectionUnderlined);
	Gura_AssignMethod(wx_RichTextCtrl, IsSingleLine);
	Gura_AssignMethod(wx_RichTextCtrl, KeyboardNavigate);
	Gura_AssignMethod(wx_RichTextCtrl, LayoutContent);
	Gura_AssignMethod(wx_RichTextCtrl, LineBreak);
	Gura_AssignMethod(wx_RichTextCtrl, LoadFile);
	Gura_AssignMethod(wx_RichTextCtrl, MarkDirty);
	Gura_AssignMethod(wx_RichTextCtrl, MoveCaret);
	Gura_AssignMethod(wx_RichTextCtrl, MoveCaretBack);
	Gura_AssignMethod(wx_RichTextCtrl, MoveCaretForward);
	Gura_AssignMethod(wx_RichTextCtrl, MoveDown);
	Gura_AssignMethod(wx_RichTextCtrl, MoveEnd);
	Gura_AssignMethod(wx_RichTextCtrl, MoveHome);
	Gura_AssignMethod(wx_RichTextCtrl, MoveLeft);
	Gura_AssignMethod(wx_RichTextCtrl, MoveRight);
	Gura_AssignMethod(wx_RichTextCtrl, MoveToLineEnd);
	Gura_AssignMethod(wx_RichTextCtrl, MoveToLineStart);
	Gura_AssignMethod(wx_RichTextCtrl, MoveToParagraphEnd);
	Gura_AssignMethod(wx_RichTextCtrl, MoveToParagraphStart);
	Gura_AssignMethod(wx_RichTextCtrl, MoveUp);
	Gura_AssignMethod(wx_RichTextCtrl, Newline);
	Gura_AssignMethod(wx_RichTextCtrl, NumberList);
	Gura_AssignMethod(wx_RichTextCtrl, OnClear);
	Gura_AssignMethod(wx_RichTextCtrl, OnContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, OnCopy);
	Gura_AssignMethod(wx_RichTextCtrl, OnCut);
	Gura_AssignMethod(wx_RichTextCtrl, OnDropFiles);
	Gura_AssignMethod(wx_RichTextCtrl, OnPaste);
	Gura_AssignMethod(wx_RichTextCtrl, OnRedo);
	Gura_AssignMethod(wx_RichTextCtrl, OnSelectAll);
	Gura_AssignMethod(wx_RichTextCtrl, OnUndo);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateClear);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateCopy);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateCut);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdatePaste);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateRedo);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateSelectAll);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateUndo);
	Gura_AssignMethod(wx_RichTextCtrl, PageDown);
	Gura_AssignMethod(wx_RichTextCtrl, PageUp);
	Gura_AssignMethod(wx_RichTextCtrl, PaintBackground);
	Gura_AssignMethod(wx_RichTextCtrl, Paste);
	Gura_AssignMethod(wx_RichTextCtrl, PositionCaret);
	Gura_AssignMethod(wx_RichTextCtrl, PositionToXY);
	Gura_AssignMethod(wx_RichTextCtrl, PromoteList);
	Gura_AssignMethod(wx_RichTextCtrl, PromoteList_1);
	Gura_AssignMethod(wx_RichTextCtrl, Redo);
	Gura_AssignMethod(wx_RichTextCtrl, Remove);
	Gura_AssignMethod(wx_RichTextCtrl, Replace);
	Gura_AssignMethod(wx_RichTextCtrl, SaveFile);
	Gura_AssignMethod(wx_RichTextCtrl, ScrollIntoView);
	Gura_AssignMethod(wx_RichTextCtrl, SelectAll);
	Gura_AssignMethod(wx_RichTextCtrl, SelectNone);
	Gura_AssignMethod(wx_RichTextCtrl, SetAndShowDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetBasicStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetBasicStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, SetCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, SetDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetDefaultStyleToCursorStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetDelayedLayoutThreshold);
	Gura_AssignMethod(wx_RichTextCtrl, SetEditable);
	Gura_AssignMethod(wx_RichTextCtrl, SetFilename);
	Gura_AssignMethod(wx_RichTextCtrl, SetFont);
	Gura_AssignMethod(wx_RichTextCtrl, SetHandlerFlags);
	Gura_AssignMethod(wx_RichTextCtrl, SetInsertionPoint);
	Gura_AssignMethod(wx_RichTextCtrl, SetInsertionPointEnd);
	Gura_AssignMethod(wx_RichTextCtrl, SetListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetSelection);
	Gura_AssignMethod(wx_RichTextCtrl, SetSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyle_2);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyleEx);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyleEx_1);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyleEx_2);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, SetValue);
	Gura_AssignMethod(wx_RichTextCtrl, SetupScrollbars);
	Gura_AssignMethod(wx_RichTextCtrl, ShowPosition);
	Gura_AssignMethod(wx_RichTextCtrl, SuppressingUndo);
	Gura_AssignMethod(wx_RichTextCtrl, Thaw);
	Gura_AssignMethod(wx_RichTextCtrl, Undo);
	Gura_AssignMethod(wx_RichTextCtrl, WordLeft);
	Gura_AssignMethod(wx_RichTextCtrl, WordRight);
	Gura_AssignMethod(wx_RichTextCtrl, WriteImageFile);
	Gura_AssignMethod(wx_RichTextCtrl, WriteImageBlock);
	Gura_AssignMethod(wx_RichTextCtrl, WriteBitmap);
	Gura_AssignMethod(wx_RichTextCtrl, WriteImage);
	Gura_AssignMethod(wx_RichTextCtrl, WriteText);
	Gura_AssignMethod(wx_RichTextCtrl, XYToPosition);
}

Gura_ImplementDescendantCreator(wx_RichTextCtrl)
{
	return new Object_wx_RichTextCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
