//----------------------------------------------------------------------------
// wxRichTextBuffer
// extracted from richtextbuffer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextBuffer: public wxRichTextBuffer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextBuffer *_pObj;
public:
	inline wx_RichTextBuffer(const wxRichTextBuffer& obj) : wxRichTextBuffer(obj), _sig(NULL), _pObj(NULL) {}
	inline wx_RichTextBuffer() : wxRichTextBuffer(), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextBuffer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextBuffer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextBuffer::~wx_RichTextBuffer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextBuffer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextBuffer
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextBuffer));
	DeclareArg(env, "obj", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextBuffer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRichTextBuffer *obj = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wx_RichTextBuffer *pEntity = new wx_RichTextBuffer(*obj);
	Object_wx_RichTextBuffer *pObj = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(RichTextBufferEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextBufferEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_RichTextBuffer *pEntity = new wx_RichTextBuffer();
	Object_wx_RichTextBuffer *pObj = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_RichTextBuffer, AddEventHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, AddEventHandler)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->AddEventHandler(handler);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, AddHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_RichTextFileHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, AddHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRichTextFileHandler *handler = Object_wx_RichTextFileHandler::GetObject(args, 0)->GetEntity();
	wxRichTextBuffer::AddHandler(handler);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, AddParagraph)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, AddParagraph)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxRichTextRange rtn = pSelf->GetEntity()->AddParagraph(text);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextRange(new wxRichTextRange(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextBuffer, BatchingUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BatchingUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BatchingUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginAlignment)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment alignment = static_cast<wxTextAttrAlignment>(args.GetInt(0));
	bool rtn = pSelf->GetEntity()->BeginAlignment(alignment);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginBatchUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cmdName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginBatchUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString cmdName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->BeginBatchUndo(cmdName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginBold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginBold)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BeginBold();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginCharacterStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "characterStyle", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginCharacterStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString characterStyle = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->BeginCharacterStyle(characterStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginFont)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginFont)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->BeginFont(*font);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginFontSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginFontSize)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pointSize = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->BeginFontSize(pointSize);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginItalic)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginItalic)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BeginItalic();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginLeftIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginLeftIndent)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int leftIndent = args.GetInt(0);
	int leftSubIndent = 0;
	if (args.IsValid(1)) leftSubIndent = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->BeginLeftIndent(leftIndent, leftSubIndent);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginLineSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lineSpacing", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginLineSpacing)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int lineSpacing = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->BeginLineSpacing(lineSpacing);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginListStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "listStyle", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "number", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginListStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString listStyle = wxString::FromUTF8(args.GetString(0));
	int level = 1;
	if (args.IsValid(1)) level = args.GetInt(1);
	int number = 1;
	if (args.IsValid(2)) number = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->BeginListStyle(listStyle, level, number);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginNumberedBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bulletNumber", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginNumberedBullet)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int bulletNumber = args.GetInt(0);
	int leftIndent = args.GetInt(1);
	int leftSubIndent = args.GetInt(2);
	int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_ARABIC|wxTEXT_ATTR_BULLET_STYLE_PERIOD;
	if (args.IsValid(3)) bulletStyle = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->BeginNumberedBullet(bulletNumber, leftIndent, leftSubIndent, bulletStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginParagraphSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "after", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginParagraphSpacing)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int before = args.GetInt(0);
	int after = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->BeginParagraphSpacing(before, after);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginParagraphStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "paragraphStyle", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginParagraphStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString paragraphStyle = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->BeginParagraphStyle(paragraphStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginRightIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rightIndent", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginRightIndent)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rightIndent = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->BeginRightIndent(rightIndent);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->BeginStyle(*style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginSuppressUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginSuppressUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BeginSuppressUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginStandardBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bulletName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginStandardBullet)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString bulletName = wxString::FromUTF8(args.GetString(0));
	int leftIndent = args.GetInt(1);
	int leftSubIndent = args.GetInt(2);
	int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_STANDARD;
	if (args.IsValid(3)) bulletStyle = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->BeginStandardBullet(bulletName, leftIndent, leftSubIndent, bulletStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginSymbolBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginSymbolBullet)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar symbol = static_cast<wxChar>(args.GetInt(0));
	int leftIndent = args.GetInt(1);
	int leftSubIndent = args.GetInt(2);
	int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_SYMBOL;
	if (args.IsValid(3)) bulletStyle = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->BeginSymbolBullet(symbol, leftIndent, leftSubIndent, bulletStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginTextColour)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->BeginTextColour(*colour);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginUnderline)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginUnderline)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->BeginUnderline();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginURL)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "characterStyle", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginURL)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	wxString characterStyle = wxEmptyString;
	if (args.IsValid(1)) characterStyle = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->BeginURL(url, characterStyle);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, CanPasteFromClipboard)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, CanPasteFromClipboard)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanPasteFromClipboard();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, CleanUpHandlers)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, CleanUpHandlers)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRichTextBuffer::CleanUpHandlers();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, Clear)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, ClearListStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, ClearListStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->ClearListStyle(*range, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, ClearListStyle_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, ClearListStyle_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->ClearListStyle(*range, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, ClearStyleStack)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, ClearStyleStack)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->ClearStyleStack();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, Clone)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, Clone)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextObject *rtn = (wxRichTextObject *)pSelf->GetEntity()->Clone();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextObject(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextBuffer, Copy)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_wx_RichTextBuffer, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, Copy)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *obj = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Copy(*obj);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, CopyToClipboard)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, CopyToClipboard)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->CopyToClipboard(*range);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, DeleteRangeWithUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, DeleteRangeWithUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->DeleteRangeWithUndo(*range, ctrl);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, Dump)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, Dump)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Dump();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, Dump_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_TextOutputStream, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, Dump_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextOutputStream *stream = Object_wx_TextOutputStream::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Dump(*stream);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndAlignment)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndAlignment();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndAllStyles)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndAllStyles)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndAllStyles();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndBatchUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndBatchUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndBatchUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndBold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndBold)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndBold();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndCharacterStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndCharacterStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndCharacterStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndFont)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndFont();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndFontSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndFontSize)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndFontSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndItalic)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndItalic)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndItalic();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndLeftIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndLeftIndent)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndLeftIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndLineSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndLineSpacing)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndLineSpacing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndListStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndListStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndListStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndNumberedBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndNumberedBullet)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndNumberedBullet();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndParagraphSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndParagraphSpacing)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndParagraphSpacing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndParagraphStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndParagraphStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndParagraphStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndRightIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndRightIndent)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndRightIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndSuppressUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndSuppressUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndSuppressUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndSymbolBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndSymbolBullet)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndSymbolBullet();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndStandardBullet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndStandardBullet)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndStandardBullet();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndTextColour)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndTextColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndUnderline)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndUnderline)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndUnderline();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, EndURL)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndURL)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->EndURL();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, FindHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, FindHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int imageType = args.GetInt(0);
	wxRichTextFileHandler *rtn = (wxRichTextFileHandler *)wxRichTextBuffer::FindHandler(imageType);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextFileHandler(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, FindHandler_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, FindHandler_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString extension = wxString::FromUTF8(args.GetString(0));
	int imageType = args.GetInt(1);
	wxRichTextFileHandler *rtn = (wxRichTextFileHandler *)wxRichTextBuffer::FindHandler(extension, imageType);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextFileHandler(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, FindHandler_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, FindHandler_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxRichTextFileHandler *rtn = (wxRichTextFileHandler *)wxRichTextBuffer::FindHandler(name);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextFileHandler(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, FindHandlerFilenameOrType)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, FindHandlerFilenameOrType)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int imageType = args.GetInt(1);
	wxRichTextFileHandler *rtn = (wxRichTextFileHandler *)wxRichTextBuffer::FindHandlerFilenameOrType(filename, imageType);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextFileHandler(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetBasicStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetBasicStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxTextAttrEx &rtn = pSelf->GetEntity()->GetBasicStyle();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextAttrEx(new wxTextAttrEx(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetBatchedCommand)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetBatchedCommand)
{
#if 0
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextCommand *rtn = (wxRichTextCommand *)pSelf->GetEntity()->GetBatchedCommand();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextCommand(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetCommandProcessor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetCommandProcessor)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCommandProcessor *rtn = (wxCommandProcessor *)pSelf->GetEntity()->GetCommandProcessor();
	return ReturnValue(env, sig, args, Value(new Object_wx_CommandProcessor(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetDefaultStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetDefaultStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxTextAttrEx &rtn = pSelf->GetEntity()->GetDefaultStyle();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextAttrEx(new wxTextAttrEx(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, GetExtWildcard)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "combine", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "save", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, GetExtWildcard)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool combine = false;
	if (args.IsValid(0)) combine = args.GetBoolean(0);
	bool save = false;
	if (args.IsValid(1)) save = args.GetBoolean(1);
	wxArrayInt types;
	wxString rtn = wxRichTextBuffer::GetExtWildcard(combine, save, &types);
	return ReturnValue(env, sig, args, Value::CreateAsList(env,
					Value(env, static_cast<const char *>(rtn.ToUTF8())),
					ArrayIntToValue(env, types)));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, GetHandlers)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, GetHandlers)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxList &rtn = wxRichTextBuffer::GetHandlers();
	return ReturnValue(env, sig, args, Value(new Object_wx_List(new wxList(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, GetRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, GetRenderer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRichTextRenderer *rtn = (wxRichTextRenderer *)wxRichTextBuffer::GetRenderer();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextRenderer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetStyle(position, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetStyle_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetStyle_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetStyle(position, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetStyleForRange)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetStyleForRange)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetStyleForRange(*range, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetStyleSheet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetStyleSheet)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pSelf->GetEntity()->GetStyleSheet();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleSheet(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetStyleStackSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetStyleStackSize)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->GetStyleStackSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetUncombinedStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetUncombinedStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetUncombinedStyle(position, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, GetUncombinedStyle_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetUncombinedStyle_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetUncombinedStyle(position, *style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, HitTest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "textPosition", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, HitTest)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxPoint *pt = Object_wx_Point::GetObject(args, 1)->GetEntity();
	long textPosition = args.GetLong(2);
	int rtn = pSelf->GetEntity()->HitTest(*dc, *pt, textPosition);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, Init)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, Init)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Init();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_RichTextBuffer, InitStandardHandlers)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, InitStandardHandlers)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRichTextBuffer::InitStandardHandlers();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_RichTextBuffer, InsertHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_RichTextFileHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, InsertHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRichTextFileHandler *handler = Object_wx_RichTextFileHandler::GetObject(args, 0)->GetEntity();
	wxRichTextBuffer::InsertHandler(handler);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertImageWithUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "imageBlock", VTYPE_wx_RichTextImageBlock, OCCUR_Once);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertImageWithUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	wxRichTextImageBlock *imageBlock = Object_wx_RichTextImageBlock::GetObject(args, 1)->GetEntity();
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 2)->GetEntity();
	bool rtn = pSelf->GetEntity()->InsertImageWithUndo(pos, *imageBlock, ctrl);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertNewlineWithUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertNewlineWithUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->InsertNewlineWithUndo(pos, ctrl);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertTextWithUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertTextWithUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	wxString text = wxString::FromUTF8(args.GetString(1));
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 2)->GetEntity();
	bool rtn = pSelf->GetEntity()->InsertTextWithUndo(pos, text, ctrl);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, IsModified)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, IsModified)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsModified();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, LoadFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, LoadFile)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	int type = wxRICHTEXT_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->LoadFile(*stream, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, LoadFile_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, LoadFile_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int type = wxRICHTEXT_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->LoadFile(filename, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, Modify)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "modify", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, Modify)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool modify = true;
	if (args.IsValid(0)) modify = args.GetBoolean(0);
	pSelf->GetEntity()->Modify(modify);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, NumberList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextListStyleDefinition, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "startFrom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, NumberList)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxRichTextListStyleDefinition *style = Object_wx_RichTextListStyleDefinition::GetObject(args, 1)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	int startFrom = -1;
	if (args.IsValid(3)) startFrom = args.GetInt(3);
	int listLevel = -1;
	if (args.IsValid(4)) listLevel = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->NumberList(*range, style, flags, startFrom, listLevel);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, Number)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "styleName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "startFrom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, Number)
{
#if 0
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxString styleName = wxString::FromUTF8(args.GetString(1));
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	int startFrom = -1;
	if (args.IsValid(3)) startFrom = args.GetInt(3);
	int listLevel = -1;
	if (args.IsValid(4)) listLevel = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->Number(*range, styleName, flags, startFrom, listLevel);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, PasteFromClipboard)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, PasteFromClipboard)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long position = args.GetLong(0);
	bool rtn = pSelf->GetEntity()->PasteFromClipboard(position);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, PromoteList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextListStyleDefinition, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, PromoteList)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
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

Gura_DeclareMethod(wx_RichTextBuffer, PromoteList_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "styleName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, PromoteList_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
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

Gura_DeclareMethod(wx_RichTextBuffer, RemoveEventHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "deleteHandler", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, RemoveEventHandler)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	bool deleteHandler = false;
	if (args.IsValid(1)) deleteHandler = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->RemoveEventHandler(handler, deleteHandler);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, RemoveHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, RemoveHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxRichTextBuffer::RemoveHandler(name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, ResetAndClearCommands)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, ResetAndClearCommands)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->ResetAndClearCommands();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, SaveFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, SaveFile)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	int type = wxRICHTEXT_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->SaveFile(*stream, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, SaveFile_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, SaveFile_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int type = wxRICHTEXT_TYPE_ANY;
	if (args.IsValid(1)) type = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->SaveFile(filename, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, SetBasicStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetBasicStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetBasicStyle(*style);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetBasicStyle_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetBasicStyle_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetBasicStyle(*style);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetDefaultStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetDefaultStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetDefaultStyle(*style);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetListStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextListStyleDefinition, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "startFrom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetListStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxRichTextListStyleDefinition *style = Object_wx_RichTextListStyleDefinition::GetObject(args, 1)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	int startFrom = -1;
	if (args.IsValid(3)) startFrom = args.GetInt(3);
	int listLevel = -1;
	if (args.IsValid(4)) listLevel = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->SetListStyle(*range, style, flags, startFrom, listLevel);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, SetListStyle_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "styleName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "startFrom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "listLevel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetListStyle_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxString styleName = wxString::FromUTF8(args.GetString(1));
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	int startFrom = -1;
	if (args.IsValid(3)) startFrom = args.GetInt(3);
	int listLevel = -1;
	if (args.IsValid(4)) listLevel = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->SetListStyle(*range, styleName, flags, startFrom, listLevel);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_RichTextBuffer, SetRenderer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "renderer", VTYPE_wx_RichTextRenderer, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_RichTextBuffer, SetRenderer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRichTextRenderer *renderer = Object_wx_RichTextRenderer::GetObject(args, 0)->GetEntity();
	wxRichTextBuffer::SetRenderer(renderer);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetStyle)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->SetStyle(*range, *style, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, SetStyle_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetStyle_1)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 0)->GetEntity();
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 1)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->SetStyle(*range, *style, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, SetStyleSheet)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetStyleSheet)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetStyleSheet(styleSheet);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextBuffer, SubmitAction)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "action", VTYPE_wx_RichTextAction, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, SubmitAction)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextAction *action = Object_wx_RichTextAction::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->SubmitAction(action);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextBuffer, SuppressingUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextBuffer, SuppressingUndo)
{
	Object_wx_RichTextBuffer *pSelf = Object_wx_RichTextBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->SuppressingUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextBuffer
//----------------------------------------------------------------------------
Object_wx_RichTextBuffer::~Object_wx_RichTextBuffer()
{
}

Object *Object_wx_RichTextBuffer::Clone() const
{
	return NULL;
}

String Object_wx_RichTextBuffer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextBuffer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextBuffer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RichTextBuffer);
	Gura_AssignFunction(RichTextBufferEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextBuffer)
{
	Gura_AssignMethod(wx_RichTextBuffer, AddEventHandler);
	Gura_AssignMethod(wx_RichTextBuffer, AddHandler);
	Gura_AssignMethod(wx_RichTextBuffer, AddParagraph);
	Gura_AssignMethod(wx_RichTextBuffer, BatchingUndo);
	Gura_AssignMethod(wx_RichTextBuffer, BeginAlignment);
	Gura_AssignMethod(wx_RichTextBuffer, BeginBatchUndo);
	Gura_AssignMethod(wx_RichTextBuffer, BeginBold);
	Gura_AssignMethod(wx_RichTextBuffer, BeginCharacterStyle);
	Gura_AssignMethod(wx_RichTextBuffer, BeginFont);
	Gura_AssignMethod(wx_RichTextBuffer, BeginFontSize);
	Gura_AssignMethod(wx_RichTextBuffer, BeginItalic);
	Gura_AssignMethod(wx_RichTextBuffer, BeginLeftIndent);
	Gura_AssignMethod(wx_RichTextBuffer, BeginLineSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, BeginListStyle);
	Gura_AssignMethod(wx_RichTextBuffer, BeginNumberedBullet);
	Gura_AssignMethod(wx_RichTextBuffer, BeginParagraphSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, BeginParagraphStyle);
	Gura_AssignMethod(wx_RichTextBuffer, BeginRightIndent);
	Gura_AssignMethod(wx_RichTextBuffer, BeginStyle);
	Gura_AssignMethod(wx_RichTextBuffer, BeginSuppressUndo);
	Gura_AssignMethod(wx_RichTextBuffer, BeginStandardBullet);
	Gura_AssignMethod(wx_RichTextBuffer, BeginSymbolBullet);
	Gura_AssignMethod(wx_RichTextBuffer, BeginTextColour);
	Gura_AssignMethod(wx_RichTextBuffer, BeginUnderline);
	Gura_AssignMethod(wx_RichTextBuffer, BeginURL);
	Gura_AssignMethod(wx_RichTextBuffer, CanPasteFromClipboard);
	Gura_AssignMethod(wx_RichTextBuffer, CleanUpHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, Clear);
	Gura_AssignMethod(wx_RichTextBuffer, ClearListStyle);
	Gura_AssignMethod(wx_RichTextBuffer, ClearListStyle_1);
	Gura_AssignMethod(wx_RichTextBuffer, ClearStyleStack);
	Gura_AssignMethod(wx_RichTextBuffer, Clone);
	Gura_AssignMethod(wx_RichTextBuffer, Copy);
	Gura_AssignMethod(wx_RichTextBuffer, CopyToClipboard);
	Gura_AssignMethod(wx_RichTextBuffer, DeleteRangeWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, Dump);
	Gura_AssignMethod(wx_RichTextBuffer, Dump_1);
	Gura_AssignMethod(wx_RichTextBuffer, EndAlignment);
	Gura_AssignMethod(wx_RichTextBuffer, EndAllStyles);
	Gura_AssignMethod(wx_RichTextBuffer, EndBatchUndo);
	Gura_AssignMethod(wx_RichTextBuffer, EndBold);
	Gura_AssignMethod(wx_RichTextBuffer, EndCharacterStyle);
	Gura_AssignMethod(wx_RichTextBuffer, EndFont);
	Gura_AssignMethod(wx_RichTextBuffer, EndFontSize);
	Gura_AssignMethod(wx_RichTextBuffer, EndItalic);
	Gura_AssignMethod(wx_RichTextBuffer, EndLeftIndent);
	Gura_AssignMethod(wx_RichTextBuffer, EndLineSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, EndListStyle);
	Gura_AssignMethod(wx_RichTextBuffer, EndNumberedBullet);
	Gura_AssignMethod(wx_RichTextBuffer, EndParagraphSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, EndParagraphStyle);
	Gura_AssignMethod(wx_RichTextBuffer, EndRightIndent);
	Gura_AssignMethod(wx_RichTextBuffer, EndStyle);
	Gura_AssignMethod(wx_RichTextBuffer, EndSuppressUndo);
	Gura_AssignMethod(wx_RichTextBuffer, EndSymbolBullet);
	Gura_AssignMethod(wx_RichTextBuffer, EndStandardBullet);
	Gura_AssignMethod(wx_RichTextBuffer, EndTextColour);
	Gura_AssignMethod(wx_RichTextBuffer, EndUnderline);
	Gura_AssignMethod(wx_RichTextBuffer, EndURL);
	Gura_AssignMethod(wx_RichTextBuffer, FindHandler);
	Gura_AssignMethod(wx_RichTextBuffer, FindHandler_1);
	Gura_AssignMethod(wx_RichTextBuffer, FindHandler_2);
	Gura_AssignMethod(wx_RichTextBuffer, FindHandlerFilenameOrType);
	Gura_AssignMethod(wx_RichTextBuffer, GetBasicStyle);
	Gura_AssignMethod(wx_RichTextBuffer, GetBatchedCommand);
	Gura_AssignMethod(wx_RichTextBuffer, GetCommandProcessor);
	Gura_AssignMethod(wx_RichTextBuffer, GetDefaultStyle);
	Gura_AssignMethod(wx_RichTextBuffer, GetExtWildcard);
	Gura_AssignMethod(wx_RichTextBuffer, GetHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, GetRenderer);
	Gura_AssignMethod(wx_RichTextBuffer, GetStyle);
	Gura_AssignMethod(wx_RichTextBuffer, GetStyle_1);
	Gura_AssignMethod(wx_RichTextBuffer, GetStyleForRange);
	Gura_AssignMethod(wx_RichTextBuffer, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, GetStyleStackSize);
	Gura_AssignMethod(wx_RichTextBuffer, GetUncombinedStyle);
	Gura_AssignMethod(wx_RichTextBuffer, GetUncombinedStyle_1);
	Gura_AssignMethod(wx_RichTextBuffer, HitTest);
	Gura_AssignMethod(wx_RichTextBuffer, Init);
	Gura_AssignMethod(wx_RichTextBuffer, InitStandardHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, InsertHandler);
	Gura_AssignMethod(wx_RichTextBuffer, InsertImageWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, InsertNewlineWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, InsertTextWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, IsModified);
	Gura_AssignMethod(wx_RichTextBuffer, LoadFile);
	Gura_AssignMethod(wx_RichTextBuffer, LoadFile_1);
	Gura_AssignMethod(wx_RichTextBuffer, Modify);
	Gura_AssignMethod(wx_RichTextBuffer, NumberList);
	Gura_AssignMethod(wx_RichTextBuffer, Number);
	Gura_AssignMethod(wx_RichTextBuffer, PasteFromClipboard);
	Gura_AssignMethod(wx_RichTextBuffer, PromoteList);
	Gura_AssignMethod(wx_RichTextBuffer, PromoteList_1);
	Gura_AssignMethod(wx_RichTextBuffer, RemoveEventHandler);
	Gura_AssignMethod(wx_RichTextBuffer, RemoveHandler);
	Gura_AssignMethod(wx_RichTextBuffer, ResetAndClearCommands);
	Gura_AssignMethod(wx_RichTextBuffer, SaveFile);
	Gura_AssignMethod(wx_RichTextBuffer, SaveFile_1);
	Gura_AssignMethod(wx_RichTextBuffer, SetBasicStyle);
	Gura_AssignMethod(wx_RichTextBuffer, SetBasicStyle_1);
	Gura_AssignMethod(wx_RichTextBuffer, SetDefaultStyle);
	Gura_AssignMethod(wx_RichTextBuffer, SetListStyle);
	Gura_AssignMethod(wx_RichTextBuffer, SetListStyle_1);
	Gura_AssignMethod(wx_RichTextBuffer, SetRenderer);
	Gura_AssignMethod(wx_RichTextBuffer, SetStyle);
	Gura_AssignMethod(wx_RichTextBuffer, SetStyle_1);
	Gura_AssignMethod(wx_RichTextBuffer, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, SubmitAction);
	Gura_AssignMethod(wx_RichTextBuffer, SuppressingUndo);
}

Gura_ImplementDescendantCreator(wx_RichTextBuffer)
{
	return new Object_wx_RichTextBuffer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
