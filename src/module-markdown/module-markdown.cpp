//-----------------------------------------------------------------------------
// Gura markdown module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(markdown)

AutoPtr<Function> g_pFunc_Presenter;

//-----------------------------------------------------------------------------
// Item
//-----------------------------------------------------------------------------
Item::Item(Type type, int indentLevel) : _cntRef(1), _type(type), _indentLevel(indentLevel)
{
}

Item::Item(Type type, ItemOwner *pItemOwner, int indentLevel) : _cntRef(1),
			_type(type), _pItemOwner(pItemOwner), _indentLevel(indentLevel)
{
}

Item::Item(Type type, const String &text, int indentLevel) : _cntRef(1),
			_type(type), _pText(new String(text)), _indentLevel(indentLevel)
{
}

const char *Item::GetTypeName() const
{
	static const struct {
		Type type;
		const char *name;
	} tbl[] = {
		{ TYPE_Root,			"root",			},	// container
		{ TYPE_Header1,			"h1",			},	// container
		{ TYPE_Header2,			"h2",			},	// container
		{ TYPE_Header3,			"h3",			},	// container
		{ TYPE_Header4,			"h4",			},	// container
		{ TYPE_Header5,			"h5",			},	// container
		{ TYPE_Header6,			"h6",			},	// container
		{ TYPE_Paragraph,		"p",			},	// container
		{ TYPE_BlockQuote,		"blockquote",	},	// container
		{ TYPE_Emphasis,		"em",			},	// container
		{ TYPE_Strong,			"strong",		},	// container
		{ TYPE_CodeBlock,		"codeblock",	},	// container
		{ TYPE_OList,			"ol",			},	// container
		{ TYPE_UList,			"ul",			},	// container
		{ TYPE_ListItem,		"li",			},	// container
		{ TYPE_Line,			"line",			},	// container
		{ TYPE_Link,			"a",			},	// container
		{ TYPE_Image,			"img",			},	// text
		{ TYPE_Text,			"text",			},	// text
		{ TYPE_Code,			"code",			},	// text
		{ TYPE_Entity,			"entity",		},	// text
		{ TYPE_Tag,				"tag",			},	// container and text (attributes)
		{ TYPE_HorzRule,		"hr",			},	// no-content
		{ TYPE_LineBreak,		"br",			},	// no-content
		{ TYPE_Referee,			"referee",		},	// no-content
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].type == _type) return tbl[i].name;
	}
	return "?";
}

void Item::Print(Signal sig, Stream &stream, int indentLevel) const
{
	for (int i = 0; i < indentLevel; i++) stream.Print(sig, "  ");
	stream.Print(sig, "<");
	stream.Print(sig, GetTypeName());
	if (_pURL.get() != NULL) {
		stream.Print(sig, " url='");
		stream.Print(sig, _pURL->c_str());
		stream.Print(sig, "'");
	}
	if (_pTitle.get() != NULL) {
		stream.Print(sig, " title='");
		stream.Print(sig, _pTitle->c_str());
		stream.Print(sig, "'");
	}
	if (_pRefId.get() != NULL) {
		stream.Print(sig, " refid='");
		stream.Print(sig, _pRefId->c_str());
		stream.Print(sig, "'");
	}
	if (_pAttrs.get() != NULL) {
		stream.Print(sig, " attrs='");
		stream.Print(sig, _pAttrs->c_str());
		stream.Print(sig, "'");
	}
	stream.Print(sig, ">");
	if (_pText.get() != NULL) {
		stream.Print(sig, "'");
		stream.Print(sig, _pText->c_str());
		stream.Print(sig, "'");
	}
	stream.Print(sig, "\n");
	
	if (!_pItemOwner.IsNull()) {
		_pItemOwner->Print(sig, stream, indentLevel + 1);
	}
}

//-----------------------------------------------------------------------------
// ItemList
//-----------------------------------------------------------------------------
Item *ItemList::FindByRefId(const char *refId) const
{
	if (refId == NULL) return NULL;
	foreach_const (ItemList, ppItem, *this) {
		Item *pItem = *ppItem;
		if (pItem->GetRefId() != NULL &&
					::strcasecmp(pItem->GetRefId(), refId) == 0) {
			return pItem;
		}
	}
	return NULL;
}

void ItemList::Print(Signal sig, Stream &stream, int indentLevel) const
{
	foreach_const (ItemList, ppItem, *this) {
		const Item *pItem = *ppItem;
		pItem->Print(sig, stream, indentLevel);
	}
}

//-----------------------------------------------------------------------------
// ItemOwner
//-----------------------------------------------------------------------------
ItemOwner::~ItemOwner()
{
	Clear();
}

void ItemOwner::Clear()
{
	foreach (ItemOwner, ppItem, *this) {
		Item *pItem = *ppItem;
		Item::Delete(pItem);
	}
	clear();
}

void ItemOwner::Store(const ItemList &itemList)
{
	foreach_const (ItemList, ppItem, itemList) {
		const Item *pItem = *ppItem;
		push_back(pItem->Reference());
	}
}

//-----------------------------------------------------------------------------
// ItemOwner
//-----------------------------------------------------------------------------
ItemOwnerStack::~ItemOwnerStack()
{
	Clear();
}

void ItemOwnerStack::Clear()
{
	foreach (ItemOwnerStack, ppItemOwner, *this) {
		ItemOwner *pItemOwner = *ppItemOwner;
		ItemOwner::Delete(pItemOwner);
	}
	clear();
}

//-----------------------------------------------------------------------------
// ItemStack
//-----------------------------------------------------------------------------
void ItemStack::ClearListItem()
{
	foreach (ItemStack, ppItem, *this) {
		Item *pItem = *ppItem;
		if (pItem->Is_list()) {
			erase(ppItem, end());
			break;
		}
	}
}

int ItemStack::CountQuoteLevel() const
{
	int quoteLevel = 0;
	foreach_const (ItemStack, ppItem, *this) {
		Item *pItem = *ppItem;
		if (pItem->IsBlockQuote()) quoteLevel++;
	}
	return quoteLevel;
}

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
Document::Document() : _cntRef(1), _resolvedFlag(false), _stat(STAT_LineTop),
		_indentLevel(0), _quoteLevel(0), _cntEmptyLine(0),
		_pItemOwner(new ItemOwner()), _pItemRefereeOwner(new ItemOwner())
{
	_statStack.Push(STAT_LineTop);
	_pItemRoot.reset(new Item(Item::TYPE_Root, new ItemOwner()));
	_itemStack.push_back(_pItemRoot.get());
}

bool Document::ParseStream(Signal sig, SimpleStream &stream)
{
	for (;;) {
		int chRaw = stream.GetChar(sig);
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		if (!ParseChar(sig, ch)) return false;
		if (chRaw < 0) break;
	}
	return true;
}

bool Document::ParseString(Signal sig, const char *text)
{
	SimpleStream_CStringReader stream(text);
	return ParseStream(sig, stream);
}

bool Document::_ParseString(Signal sig, String text)
{
	foreach (String, p, text) {
		if (!ParseChar(sig, *p)) return false;
	}
	return true;
}

void Document::AddItemReferee(Item *pItem)
{
	_pItemRefereeOwner->push_back(pItem);
	_resolvedFlag = false;
}

void Document::ResolveReference()
{
	if (_resolvedFlag) return;
	foreach (ItemList, ppItemLink, _itemsLinkReferrer) {
		Item *pItemLink = *ppItemLink;
		const char *refId = pItemLink->GetRefId();
		Item *pItemRef = _pItemRefereeOwner->FindByRefId(refId);
		if (pItemRef != NULL) {
			const char *url = pItemRef->GetURL();
			const char *title = pItemRef->GetTitle();
			if (url != NULL) pItemLink->SetURL(url);
			if (title != NULL) pItemLink->SetTitle(title);
		}
	}
	_resolvedFlag = true;
}

bool Document::ParseChar(Signal sig, char ch)
{
	bool continueFlag = true;
	do {
	continueFlag = false;
	switch (_stat) {
	case STAT_LineTop: {
		_indentLevel = 0;
		continueFlag = true;
		_stat = STAT_LineHead;
		break;
	}
	case STAT_LineHead: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel = 1;
			_stat = STAT_BlockQuote;
		} else if (ch == '=') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_Equal;
		} else if (ch == '#' && _indentLevel <= 0) {
			FlushItem(Item::TYPE_Paragraph, false);
			_indentLevel = 1;
			_stat = STAT_SetextHeaderHead;
		} else if (ch == '*') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_Asterisk;
		} else if (ch == '+') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_Plus;
		} else if (ch == '-') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_Hyphen;
		} else if (IsDigit(ch)) {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_Digit;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushItem(Item::TYPE_Paragraph, false);
			_indentLevel = 0;
			_stat = STAT_LineHeadNL;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			continueFlag = true;
			BeginCodeBlock(NULL);
		} else {
			if (ch == '[') {
				_pItemLink.reset(new Item(Item::TYPE_Referee));
				_textAhead.clear();
				_textAhead += ch;
				_field.clear();
				_stat = STAT_RefereeRefId;
			} else {
				if (!_text.empty()) _text += ' ';
				continueFlag = true;
				_stat = STAT_Text;
			}
		}
		break;
	}
	case STAT_LineHeadNL: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (ch == '>') {
			continueFlag = true;
			_stat = STAT_LineHead;
		} else {
			_quoteLevel = 0;
			AdjustBlockQuote();
			continueFlag = true;
			_stat = STAT_LineHead;
		}
		break;
	}
	case STAT_BlockQuote: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			continueFlag = true;
			AdjustBlockQuote();
			BeginCodeBlock(_textAhead.c_str());
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel++;
		} else {
			AdjustBlockQuote();
			continueFlag = true;
			_stat = STAT_LineHead;
		}
		break;
	}
	case STAT_Equal: {
		if (ch == '=') {
			_textAhead += ch;
			_stat = STAT_AtxHeader1;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = STAT_AtxHeader1;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			continueFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_Asterisk: {
		if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false);
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel >= INDENT_CodeBlock) {
			continueFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(STAT_Text);
			continueFlag = true;
			_stat = STAT_AsteriskEmphasisPre;
		}
		break;
	}
	case STAT_Plus: {
		if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false);
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel >= INDENT_CodeBlock) {
			continueFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_Hyphen: {
		if (ch == '-') {
			_textAhead += ch;
			_stat = STAT_AtxHeader2;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = STAT_AtxHeader2;
		} else if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false);
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel >= INDENT_CodeBlock) {
			continueFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_Digit: {
		if (IsDigit(ch)) {
			_textAhead += ch;
		} else if (ch == '.') {
			_textAhead += ch;
			_stat = STAT_DigitDot;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			continueFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_DigitDot: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_OList);
		} else if (_indentLevel >= INDENT_CodeBlock) {
			continueFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_SetextHeaderHead: {
		if (ch == '#') {
			_indentLevel++;
		} else if (ch == ' ' || ch == '\t') {
			_stat = STAT_SetextHeaderPre;
		} else {
			_text.clear();
			continueFlag = true;
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_SetextHeaderPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			_text.clear();
			continueFlag = true;
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_SetextHeader: {
		if (CheckSpecialChar(ch)) {
			// nothing to do
		} else if (ch == '#') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_SetextHeaderPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Item::Type type =
				(_indentLevel == 1)? Item::TYPE_Header1 :
				(_indentLevel == 2)? Item::TYPE_Header2 :
				(_indentLevel == 3)? Item::TYPE_Header3 :
				(_indentLevel == 4)? Item::TYPE_Header4 :
				(_indentLevel == 5)? Item::TYPE_Header5 :
				(_indentLevel == 6)? Item::TYPE_Header6 :
				Item::TYPE_Header6;
			FlushItem(type, true);
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_SetextHeaderPost: {
		if (ch == '#') {
			_textAhead += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = STAT_SetextHeader;
		} else {
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_AtxHeader1: {
		if (ch == '=') {
			_textAhead += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushItem(Item::TYPE_Header1, false);
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_AtxHeader2: {
		if (ch == '-') {
			_textAhead += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			FlushText(Item::TYPE_Text, false);
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_Header2, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
			} else if (IsHorzRule(_textAhead.c_str())) {
				Item *pItem = new Item(Item::TYPE_HorzRule);
				pItemParent->GetItemOwner()->push_back(pItem);
			} else {
				_text += _textAhead;
			}
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_ListItemPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem: {
		if (CheckSpecialChar(ch)) {
			// nothing to do
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_indentLevel = 0;
			continueFlag = IsEOF(ch);
			_stat = STAT_ListItem_LineHead;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_ListItem_LineHead: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel = 1;
			_stat = STAT_ListItem_BlockQuote;
		} else if (ch == '*') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItem_Asterisk;
		} else if (ch == '+') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItem_Plus;
		} else if (ch == '-') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItem_Hyphen;
		} else if (IsDigit(ch)) {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItem_Digit;
		} else if (IsEOL(ch)) {
			_indentLevel = 0;
			_stat = STAT_ListItemNL;
		} else if (IsEOF(ch)) {
			EndListItem();
			_itemStack.ClearListItem();
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_text += ' ';
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem_BlockQuote: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			continueFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel++;
		} else {
			AdjustBlockQuote();
			continueFlag = true;
			_stat = STAT_ListItem_LineHead;
		}
		break;
	}
	case STAT_ListItem_Asterisk: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else {
			_text += ' ';
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(STAT_ListItem);
			continueFlag = true;
			_stat = STAT_AsteriskEmphasisPre;
		}
		break;
	}
	case STAT_ListItem_Plus: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem_Hyphen: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem_Digit: {
		if (IsDigit(ch)) {
			_textAhead += ch;
		} else if (ch == '.') {
			_textAhead += ch;
			_stat = STAT_ListItem_DigitDot;
		} else {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem_DigitDot: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_OList);
		} else {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (ch == '*') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemNL_Asterisk;
		} else if (ch == '+') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemNL_Plus;
		} else if (ch == '-') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemNL_Hyphen;
		} else if (IsDigit(ch)) {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemNL_Digit;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndListItem();
			_itemStack.ClearListItem();
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			AdjustBlockQuote();
			continueFlag = true;
			_stat = STAT_LineTop;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			continueFlag = true;
			BeginCodeBlockInList(NULL);
		} else {
 			FlushItem(Item::TYPE_Paragraph, false);
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL_Asterisk: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			continueFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			continueFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
			FlushItem(Item::TYPE_Paragraph, false);
			continueFlag = true;
			_statStack.Push(STAT_ListItem);
			_stat = STAT_AsteriskEmphasisPre;
		}
		break;
	}
	case STAT_ListItemNL_Plus: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			continueFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			continueFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
 			FlushItem(Item::TYPE_Paragraph, false);
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL_Hyphen: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			continueFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			continueFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
 			FlushItem(Item::TYPE_Paragraph, false);
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL_Digit: {
		if (IsDigit(ch)) {
			_textAhead += ch;
		} else if (ch == '.') {
			_textAhead += ch;
			_stat = STAT_ListItemNL_DigitDot;
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			continueFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			continueFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL_DigitDot: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_OList);
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			continueFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			continueFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
 			FlushItem(Item::TYPE_Paragraph, false);
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_CodeBlock: {
		if (IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			do {
				Item *pItem = new Item(Item::TYPE_Text, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			} while (0);
			do {
				Item *pItem = new Item(Item::TYPE_Line, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
			} while (0);
			_cntEmptyLine = 0;
			_indentLevel = 0;
			_stat = STAT_CodeBlock_LineHead;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_CodeBlock_LineHead: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel = 1;
			_stat = STAT_CodeBlock_BlockQuote;
#if 0
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_cntEmptyLine++;
			_indentLevel = 0;
#endif
		} else if (_indentLevel >= INDENT_CodeBlock) {
			Item *pItemParent = _itemStack.back();
			for (int i = 0; i < _cntEmptyLine; i++) {
				do {
					Item *pItem = new Item(Item::TYPE_Text, _text);
					_pItemOwner->push_back(pItem);
					_text.clear();
				} while (0);
				do {
					Item *pItem = new Item(Item::TYPE_Line, _pItemOwner.release());
					pItemParent->GetItemOwner()->push_back(pItem);
					_pItemOwner.reset(new ItemOwner());
				} while (0);
			}
			_text.clear();
			for (int i = 0; i < _indentLevel - INDENT_CodeBlock; i++) _text += ' ';
			continueFlag = true;
			_stat = STAT_CodeBlock;
		} else {
			continueFlag = true;
			EndCodeBlock();
		}
		break;
	}
	case STAT_CodeBlock_BlockQuote: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			continueFlag = true;
			if (AdjustBlockQuote()) {
				EndCodeBlock();
				BeginCodeBlock(_textAhead.c_str());
			} else {
				for (int i = 0; i < _indentLevel - INDENT_CodeBlock; i++) _text += ' ';
				_stat = STAT_CodeBlock;
			}
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel++;
		} else {
			continueFlag = true;
			EndCodeBlock();
			AdjustBlockQuote();
		}
		break;
	}
	case STAT_CodeBlockInList: {
		if (IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			do {
				Item *pItem = new Item(Item::TYPE_Text, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			} while (0);
			do {
				Item *pItem = new Item(Item::TYPE_Line, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
			} while (0);
			_indentLevel = 0;
			continueFlag = IsEOF(ch);
			_stat = STAT_CodeBlockInList_LineHead;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_CodeBlockInList_LineHead: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			for (int i = 0; i < _indentLevel - INDENT_CodeBlockInList; i++) _text += ' ';
			continueFlag = true;
			_stat = STAT_CodeBlockInList;
		} else {
			continueFlag = true;
			EndCodeBlockInList();
		}
		break;
	}
	case STAT_Backquote: {
		if (ch == '`') {
			_stat = STAT_CodeEsc;
		} else {
			continueFlag = true;
			_stat = STAT_Code;
		}
		break;
	}
	case STAT_Code: {
		if (ch == '`') {
			FlushText(Item::TYPE_Code, true);
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushText(Item::TYPE_Code, true);
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_CodeEsc: {
		if (ch == '`') {
			_stat = STAT_CodeEsc_Backquote;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushText(Item::TYPE_Code, true);
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_CodeEsc_Backquote: {
		if (ch == '`') {
			FlushText(Item::TYPE_Code, true);
			_stat = _statStack.Pop();
		} else {
			_text += '`';
			continueFlag = true;
			_stat = STAT_CodeEsc;
		}
		break;
	}
	case STAT_Text: {
		if (CheckSpecialChar(ch)) {
			// nothing to do
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_AsteriskEmphasisPre: {
		if (ch == '*') {
			BeginDecoration(Item::TYPE_Strong);
			_stat = STAT_AsteriskStrong;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			BeginDecoration(Item::TYPE_Emphasis);
			continueFlag = true;
			_stat = STAT_AsteriskEmphasis;
		}
		break;
	}
	case STAT_AsteriskEmphasis: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(_stat);
			_stat = STAT_Backquote;
		} else if (ch == '*') {
			EndDecoration();
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_AsteriskStrong: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(_stat);
			_stat = STAT_Backquote;
		} else if (ch == '*') {
			_stat = STAT_AsteriskStrongEnd;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_AsteriskStrongEnd: {
		if (ch == '*') {
			EndDecoration();
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			FlushText(Item::TYPE_Text, true);
			BeginDecoration(Item::TYPE_Emphasis);
			_statStack.Push(STAT_AsteriskStrong);
			continueFlag = true;
			_stat = STAT_AsteriskEmphasis;
		}
		break;
	}
	case STAT_UnderscoreEmphasisPre: {
		if (ch == '_') {
			BeginDecoration(Item::TYPE_Strong);
			_stat = STAT_UnderscoreStrong;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			BeginDecoration(Item::TYPE_Emphasis);
			continueFlag = true;
			_stat = STAT_UnderscoreEmphasis;
		}
		break;
	}
	case STAT_UnderscoreEmphasis: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(_stat);
			_stat = STAT_Backquote;
		} else if (ch == '_') {
			EndDecoration();
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_UnderscoreStrong: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(_stat);
			_stat = STAT_Backquote;
		} else if (ch == '_') {
			_stat = STAT_UnderscoreStrongEnd;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_UnderscoreStrongEnd: {
		if (ch == '_') {
			EndDecoration();
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			FlushText(Item::TYPE_Text, true);
			BeginDecoration(Item::TYPE_Emphasis);
			_statStack.Push(STAT_UnderscoreStrong);
			continueFlag = true;
			_stat = STAT_UnderscoreEmphasis;
		}
		break;
	}
	case STAT_Ampersand: {
		if (ch == ';') {
			FlushText(Item::TYPE_Text, false);
			Item *pItem = new Item(Item::TYPE_Entity, _field);
			_pItemOwner->push_back(pItem);
			_stat = _statStack.Pop();
 		} else if (IsAlpha(ch)) {
			_textAhead += ch;
			_field += ch;
		} else {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_AngleBracket: {
		if (ch == '>') {
			String tagName, attrs;
			bool endFlag = false;
			if (IsLink(_field.c_str())) {
				FlushText(Item::TYPE_Text, false);
				Item *pItemLink = new Item(Item::TYPE_Link, new ItemOwner());
				pItemLink->SetURL(_field);
				_pItemOwner->push_back(pItemLink);
				do {
					Item *pItem = new Item(Item::TYPE_Text, _field);
					pItemLink->GetItemOwner()->push_back(pItem);
				} while (0);
			} else if (IsBeginTag(_field.c_str(), tagName, attrs, endFlag)) {
				FlushText(Item::TYPE_Text, false);
				BeginTag(tagName.c_str(), attrs.c_str(), endFlag);
			} else if (IsEndTag(_field.c_str(), tagName)) {
				EndTag(tagName.c_str());
			} else {
				_text += _textAhead;
				_text += ch;
			}
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_LinkAltTextPre: {
		if (ch == '[') {
			_textAhead += ch;
			_stat = STAT_LinkAltText;
		} else {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_LinkAltText: {
		if (ch == ']') {
			_textAhead += ch;
			_pItemLink->SetText(Strip(_field.c_str()));
			_stat = STAT_LinkTextPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_LinkText: {
		if (ch == ']') {
			_textAhead += ch;
			do {
				Item *pItem = new Item(Item::TYPE_Text, Strip(_field.c_str()));
				_pItemLink->GetItemOwner()->push_back(pItem);
			} while (0);
			_stat = STAT_LinkTextPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_LinkTextPost: {
		if (ch == '[') {
			_field.clear();
			_stat = STAT_LinkRefId;
		} else if (ch == '(') {
			_textAhead += ch;
			_stat = STAT_LinkURLPre;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_LinkRefId: {
		if (ch == ']') {
			FlushText(Item::TYPE_Text, false);
			_pItemLink->SetRefId(_field);
			_itemsLinkReferrer.push_back(_pItemLink.get());
			_pItemOwner->push_back(_pItemLink.release());
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_LinkURLPre: {
		if (ch == ' ' || ch == '\t') {
			_textAhead += ch;
		} else if (ch == '<') {
			_field.clear();
			_textAhead += ch;
			_stat = STAT_LinkURLAngle;
		} else {
			_field.clear();
			continueFlag = true;
			_stat = STAT_LinkURL;
		}
		break;
	}
	case STAT_LinkURL: {
		if (ch == '"') {
			_pItemLink->SetURL(Strip(_field.c_str()));
			_textAhead += ch;
			_field.clear();
			_stat = STAT_LinkTitleDoubleQuote;
		} else if (ch == '\'') {
			_pItemLink->SetURL(Strip(_field.c_str()));
			_textAhead += ch;
			_field.clear();
			_stat = STAT_LinkTitleSingleQuote;
		} else if (ch == ')') {
			FlushText(Item::TYPE_Text, false);
			_pItemLink->SetURL(Strip(_field.c_str()));
			_pItemOwner->push_back(_pItemLink.release());
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_LinkURLAngle: {
		if (ch == '>') {
			_pItemLink->SetURL(Strip(_field.c_str()));
			_textAhead += ch;
			_stat = STAT_LinkURLAnglePost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_LinkURLAnglePost: {
		if (ch == '"') {
			_textAhead += ch;
			_field.clear();
			_stat = STAT_LinkTitleDoubleQuote;
		} else if (ch == '\'') {
			_textAhead += ch;
			_field.clear();
			_stat = STAT_LinkTitleSingleQuote;
		} else if (ch == ')') {
			FlushText(Item::TYPE_Text, false);
			_pItemOwner->push_back(_pItemLink.release());
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
		}
		break;
	}
	case STAT_LinkTitleDoubleQuote: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_EscapeInLink;
		} else if (ch == '"') {
			_pItemLink->SetTitle(_field.c_str());
			_textAhead += ch;
			_stat = STAT_LinkTitlePost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_LinkTitleSingleQuote: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_EscapeInLink;
		} else if (ch == '\'') {
			_pItemLink->SetTitle(_field.c_str());
			_textAhead += ch;
			_stat = STAT_LinkTitlePost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_LinkTitlePost: {
		if (ch == ' ' || ch == '\t') {
			_textAhead += ch;
		} else if (ch == ')') {
			FlushText(Item::TYPE_Text, false);
			_pItemOwner->push_back(_pItemLink.release());
			_stat = _statStack.Pop();
		} else {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_RefereeRefId: {
		if (ch == ']') {
			_pItemLink->SetRefId(_field);
			_textAhead += ch;
			_stat = STAT_RefereeRefIdPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_RefereeRefIdPost: {
		if (ch == ':') {
			_textAhead += ch;
			_stat = STAT_RefereeURLPreWhite;
		} else {
			continueFlag = true;
			_stat = STAT_Text;
			if (!_ParseString(sig, _textAhead)) return false;
		}
		break;
	}
	case STAT_RefereeURLPreWhite: {
		if (ch == ' ' || ch == '\t') {
			_textAhead += ch;
			_stat = STAT_RefereeURLPre;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_RefereeURLPre: {
		if (ch == ' ' || ch == '\t') {
			_textAhead += ch;
		} else if (ch == '<') {
			_field.clear();
			_stat = STAT_RefereeURLAngle;
		} else {
			_field.clear();
			continueFlag = true;
			_stat = STAT_RefereeURL;
		}
		break;
	}
	case STAT_RefereeURL: {
		if (ch == '"') {
			_pItemLink->SetURL(Strip(_field.c_str()));
			_textAhead += ch;
			_field.clear();
			_stat = STAT_RefereeTitleDoubleQuote;
		} else if (ch == '\'') {
			_pItemLink->SetURL(Strip(_field.c_str()));
			_textAhead += ch;
			_field.clear();
			_stat = STAT_RefereeTitleSingleQuote;
		} else if (ch == '(') {
			_pItemLink->SetURL(Strip(_field.c_str()));
			_textAhead += ch;
			_field.clear();
			_stat = STAT_RefereeTitleParenthesis;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushText(Item::TYPE_Text, false);
			_pItemLink->SetURL(Strip(_field.c_str()));
			AddItemReferee(_pItemLink.release());
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_RefereeURLAngle: {
		if (ch == '>') {
			_pItemLink->SetURL(Strip(_field.c_str()));
			_textAhead += ch;
			_stat = STAT_RefereeURLAnglePost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_RefereeURLAnglePost: {
		if (ch == '"') {
			_textAhead += ch;
			_field.clear();
			_stat = STAT_RefereeTitleDoubleQuote;
		} else if (ch == '\'') {
			_textAhead += ch;
			_field.clear();
			_stat = STAT_RefereeTitleSingleQuote;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushText(Item::TYPE_Text, false);
			AddItemReferee(_pItemLink.release());
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_textAhead += ch;
		}
		break;
	}
	case STAT_RefereeTitleDoubleQuote: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_EscapeInLink;
		} else if (ch == '"') {
			_pItemLink->SetTitle(_field.c_str());
			_textAhead += ch;
			_stat = STAT_RefereeTitlePost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_RefereeTitleSingleQuote: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_EscapeInLink;
		} else if (ch == '\'') {
			_pItemLink->SetTitle(_field.c_str());
			_textAhead += ch;
			_stat = STAT_RefereeTitlePost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_RefereeTitleParenthesis: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_EscapeInLink;
		} else if (ch == ')') {
			_pItemLink->SetTitle(_field.c_str());
			_textAhead += ch;
			_stat = STAT_RefereeTitlePost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_RefereeTitlePost: {
		if (ch == ' ' || ch == '\t') {
			_textAhead += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushText(Item::TYPE_Text, false);
			AddItemReferee(_pItemLink.release());
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_Escape: {
		_text += ch;
		_stat = _statStack.Pop();
		break;
	}
	case STAT_EscapeInLink: {
		_textAhead += ch;
		_field += ch;
		_stat = _statStack.Pop();
		break;
	}
	}
	} while (continueFlag);
	return true;
}

bool Document::CheckSpecialChar(char ch)
{
	if (ch == '\\') {
		_statStack.Push(_stat);
		_stat = STAT_Escape;
		return true;
	} else if (ch == '`') {
		FlushText(Item::TYPE_Text, false);
		_statStack.Push(_stat);
		_stat = STAT_Backquote;
		return true;
	} else if (ch == '*') {
		FlushText(Item::TYPE_Text, false);
		_statStack.Push(_stat);
		_stat = STAT_AsteriskEmphasisPre;
		return true;
	} else if (ch == '_') {
		FlushText(Item::TYPE_Text, false);
		_statStack.Push(_stat);
		_stat = STAT_UnderscoreEmphasisPre;
		return true;
	} else if (ch == '&') {
		_textAhead.clear();
		_field.clear();
		_textAhead += ch;
		_statStack.Push(_stat);
		_stat = STAT_Ampersand;
		return true;
	} else if (ch == '<') {
		_textAhead.clear();
		_field.clear();
		_textAhead += ch;
		_statStack.Push(_stat);
		_stat = STAT_AngleBracket;
		return true;
	} else if (ch == '[') {
		_pItemLink.reset(new Item(Item::TYPE_Link, new ItemOwner()));
		_textAhead.clear();
		_field.clear();
		_textAhead += ch;
		_statStack.Push(_stat);
		_stat = STAT_LinkText;
		return true;
	} else if (ch == '!') {
		_pItemLink.reset(new Item(Item::TYPE_Image));
		_textAhead.clear();
		_field.clear();
		_textAhead += ch;
		_statStack.Push(_stat);
		_stat = STAT_LinkAltTextPre;
		return true;
	}
	return false;
}

bool Document::AdjustBlockQuote()
{
	bool adjustFlag = false;
	int quoteLevel = _itemStack.CountQuoteLevel();
	if (quoteLevel < _quoteLevel) {
 			FlushItem(Item::TYPE_Paragraph, false);
		for ( ; quoteLevel < _quoteLevel; quoteLevel++) {
			Item *pItemParent = _itemStack.back();
			Item *pItem = new Item(Item::TYPE_BlockQuote, new ItemOwner());
			pItemParent->GetItemOwner()->push_back(pItem);
			_itemStack.push_back(pItem);
		}
		adjustFlag = true;
	} else if (quoteLevel > _quoteLevel) {
 			FlushItem(Item::TYPE_Paragraph, false);
		while (quoteLevel > _quoteLevel) {
			Item *pItem = _itemStack.back();
			if (pItem->IsBlockQuote()) quoteLevel--;
			_itemStack.pop_back();
		}
		adjustFlag = true;
	}
	return adjustFlag;
}

void Document::FlushText(Item::Type type, bool stripFlag)
{
	if (!_text.empty()) {
		Item *pItem = new Item(type, Strip(_text.c_str(), stripFlag, stripFlag));
		_pItemOwner->push_back(pItem);
		_text.clear();
	}
}

void Document::FlushItem(Item::Type type, bool stripFlag)
{
	Item *pItemParent = _itemStack.back();
	FlushText(Item::TYPE_Text, stripFlag);
	if (!_pItemOwner->empty()) {
		Item *pItem = new Item(type, _pItemOwner.release());
		pItemParent->GetItemOwner()->push_back(pItem);
		_pItemOwner.reset(new ItemOwner());
	}
}

void Document::FlushElement()
{
	Item *pItemParent = _itemStack.back();
	FlushText(Item::TYPE_Text, false);
	if (pItemParent->GetItemOwner()->empty()) {
		pItemParent->GetItemOwner()->Store(*_pItemOwner);
		_pItemOwner.reset(new ItemOwner());
	} else if (!_pItemOwner->empty()) {
		Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner.release());
		pItemParent->GetItemOwner()->push_back(pItem);
		_pItemOwner.reset(new ItemOwner());
	}
}

void Document::BeginCodeBlock(const char *textInit)
{
	FlushItem(Item::TYPE_Paragraph, false);
	for (int i = 0; i < _indentLevel - INDENT_CodeBlock; i++) _text += ' ';
	if (textInit != NULL) _text += textInit;
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_CodeBlock, new ItemOwner(), _indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} while (0);
	_stat = STAT_CodeBlock;
}

void Document::EndCodeBlock()
{
	_itemStack.pop_back();
	_stat = STAT_LineTop;
}

void Document::BeginCodeBlockInList(const char *textInit)
{
	FlushItem(Item::TYPE_Paragraph, false);
	for (int i = 0; i < _indentLevel - INDENT_CodeBlockInList; i++) _text += ' ';
	if (textInit != NULL) _text += textInit;
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_CodeBlock, new ItemOwner(), _indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} while (0);
	_statStack.Push(STAT_ListItem_LineHead);
	_stat = STAT_CodeBlockInList;
}

void Document::EndCodeBlockInList()
{
	_itemStack.pop_back();
	_stat = _statStack.Pop();
}

// type must be TYPE_UList or TYPE_OList
void Document::BeginListItem(Item::Type type)
{
	Item *pItemParent = _itemStack.back();
	while (_indentLevel < pItemParent->GetIndentLevel()) {
		if (pItemParent->IsListItem()) {
			EndListItem();
		} else {
			_itemStack.pop_back();
		}
		pItemParent = _itemStack.back();
	}
	if (pItemParent->IsListItem()) {
		if (_indentLevel == pItemParent->GetIndentLevel()) {
			EndListItem();
			pItemParent = _itemStack.back();
		} else {
			FlushElement();
		}
	}
	if (pItemParent->IsRoot() || pItemParent->IsBlockQuote() ||
							pItemParent->GetIndentLevel() < _indentLevel) {
		Item *pItem = new Item(type, new ItemOwner(), _indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} else if (pItemParent->GetType() != type) {
		_itemStack.pop_back();
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(type, new ItemOwner(), _indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	}
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_ListItem, new ItemOwner());
		pItem->SetIndentLevel(_indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} while (0);
	_stat = STAT_ListItemPre;
}

void Document::EndListItem()
{
	FlushElement();
	_itemStack.pop_back();
}

void Document::BeginDecoration(Item::Type type)
{
	Item *pItem = new Item(type, new ItemOwner());
	_pItemOwner->push_back(pItem);
	_itemOwnerStack.Push(_pItemOwner.release());
	_pItemOwner.reset(pItem->GetItemOwner()->Reference());
}

void Document::EndDecoration()
{
	FlushText(Item::TYPE_Text, false);
	_pItemOwner.reset(_itemOwnerStack.Pop());
}

void Document::BeginTag(const char *tagName, const char *attrs, bool endFlag)
{
	FlushItem(Item::TYPE_Paragraph, false);
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_Tag);
		pItem->SetText(tagName);
		if (*attrs != '\0') pItem->SetAttrs(attrs);
		pItemParent->GetItemOwner()->push_back(pItem);
		if (!endFlag) {
			pItem->SetItemOwner(new ItemOwner());
			_itemStack.push_back(pItem);
		}
	} while (0);
}

void Document::EndTag(const char *tagName)
{
	FlushElement();
	Item *pItem = _itemStack.back();
	if (pItem->IsTag()) _itemStack.pop_back();
}

bool Document::IsAtxHeader2(const char *text)
{
	for (const char *p = text; ; p++) {
		char ch = *p;
		::printf("[%c]\n", ch);
		if (ch != '-') return false;
	}
	return true;
}

bool Document::IsHorzRule(const char *text)
{
	return ::strlen(text) >= 3;
}

bool Document::IsLink(const char *text)
{
	enum Stat {
		STAT_Begin,
		STAT_Head,
		STAT_EMail,
		STAT_EMailDot,
		STAT_EMailAfterDot,
		STAT_URL,
	} stat = STAT_Begin;
	String head;
	for (const char *p = text; ; p++) {
		char ch = *p;
		switch (stat) {
		case STAT_Begin: {
			if (IsAlpha(ch)) {
				head += ch;
				stat = STAT_Head;
			} else {
				return false;
			}
			break;
		}
		case STAT_Head: {
			if (IsAlpha(ch)) {
				head += ch;
			} else if (ch == '@') {
				stat = STAT_EMail;
			} else if (ch == ':') {
				stat = STAT_URL;
			} else {
				return false;
			}
			break;
		}
		case STAT_EMail: {
			if (IsAlpha(ch)) {
				// nothing to do
			} else if (ch == '.') {
				stat = STAT_EMailDot;
			} else {
				return false;
			}
			break;
		}
		case STAT_EMailDot: {
			if (IsAlpha(ch)) {
				stat = STAT_EMailAfterDot;
			} else {
				return false;
			}
			break;
		}
		case STAT_EMailAfterDot: {
			if (IsAlpha(ch)) {
				// nothing to do
			} else if (ch == '.') {
				stat = STAT_EMailDot;
			} else if (ch == '\0') {
				// nothing to do
			} else {
				return false;
			}
			break;
		}
		case STAT_URL: {
			if (IsURIC(ch)) {
				// nothing to do
			} else if (ch == '\0') {
				if (!(head == "http" || head == "https" || head == "ftp")) {
					return false;
				}
			} else {
				return false;
			}
			break;
		}
		}
		if (ch == '\0') break;
	}
	return true;
}

bool Document::IsBeginTag(const char *text,
						String &tagName, String &attrs, bool &endFlag)
{
	enum Stat {
		STAT_Begin,
		STAT_TagName,
		STAT_AttrsPre,
		STAT_Attrs,
		STAT_Slash,
	} stat = STAT_Begin;
	tagName.clear();
	attrs.clear();
	endFlag = false;
	for (const char *p = text; ; p++) {
		char ch = *p;
		switch (stat) {
		case STAT_Begin: {
			if (IsAlpha(ch)) {
				tagName += ch;
				stat = STAT_TagName;
			} else {
				return false;
			}
			break;
		}
		case STAT_TagName: {
			if (IsAlpha(ch) || IsDigit(ch)) {
				tagName += ch;
			} else if (ch == '/') {
				stat = STAT_Slash;
			} else if (ch == '\0') {
				// nothing to do
			} else if (ch == ' ' || ch == '\t') {
				stat = STAT_AttrsPre;
			} else {
				return false;
			}
			break;
		}
		case STAT_AttrsPre: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (IsAlpha(ch)) {
				attrs += ch;
				stat = STAT_Attrs;
			} else if (ch == '/') {
				stat = STAT_Slash;
			} else if (ch == '\0') {
				return false;	// not allow "<hoge  >"
			} else {
				return false;
			}
			break;
		}
		case STAT_Attrs: {
			if (ch == '\0') {
				// nothing to do
			} else if (ch == '/') {
				stat = STAT_Slash;
			} else {
				attrs += ch;
			}
			break;
		}
		case STAT_Slash: {
			if (ch == '\0') {
				endFlag = true;
			} else {
				attrs += '/';
				attrs += ch;
				stat = STAT_Attrs;
			}
			break;
		}
		}
		if (ch == '\0') break;
	}
	return true;
}

bool Document::IsEndTag(const char *text, String &tagName)
{
	enum Stat {
		STAT_Begin,
		STAT_TagNameFirst,
		STAT_TagName,
	} stat = STAT_Begin;
	tagName.clear();
	for (const char *p = text; ; p++) {
		char ch = *p;
		switch (stat) {
		case STAT_Begin: {
			if (ch == '/') {
				tagName += ch;
				stat = STAT_TagNameFirst;
			} else {
				return false;
			}
			break;
		}
		case STAT_TagNameFirst: {
			if (IsAlpha(ch)) {
				tagName += ch;
				stat = STAT_TagName;
			} else {
				return false;
			}
			break;
		}
		case STAT_TagName: {
			if (IsAlpha(ch) || IsDigit(ch)) {
				tagName += ch;
			} else if (ch == '\0') {
				// nothing to do
			} else {
				return false;
			}
			break;
		}
		}
		if (ch == '\0') break;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Object_document
//-----------------------------------------------------------------------------
Object *Object_document::Clone() const
{
	return NULL;
}

bool Object_document::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(root));
	symbols.insert(Gura_UserSymbol(refs));
	return true;
}

Value Object_document::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(root))) {
		_pDocument->ResolveReference();
		return Value(new Object_item(_pDocument->GetItemRoot()->Reference()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(refs))) {
		const ItemOwner *pItemOwner = _pDocument->GetItemRefereeOwner();
		Iterator *pIterator = new Iterator_item(pItemOwner->Reference());
		return Value(env, pIterator);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_document::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

String Object_document::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<markdown.document";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for markdown.document
//-----------------------------------------------------------------------------
// markdown.document#read(stream:stream:w):void
Gura_DeclareMethod(document, read)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(document, read)
{
	Document *pDocument = Object_document::GetThisObj(args)->GetDocument();
	pDocument->ParseStream(sig, args.GetStream(0));
	return Value::Null;
}

// markdown.document#print():void
Gura_DeclareMethod(document, print)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(document, print)
{
	Document *pDocument = Object_document::GetThisObj(args)->GetDocument();
	pDocument->ResolveReference();
	const Item *pItem = pDocument->GetItemRoot();
	pItem->Print(sig, *env.GetConsole(), 0);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for markdown.document
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(document)
{
	Gura_AssignMethod(document, read);
	Gura_AssignMethod(document, print);
}

//-----------------------------------------------------------------------------
// Object_item
//-----------------------------------------------------------------------------
Object *Object_item::Clone() const
{
	return NULL;
}

bool Object_item::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(text));
	symbols.insert(Gura_UserSymbol(children));
	symbols.insert(Gura_UserSymbol(url));
	symbols.insert(Gura_UserSymbol(title));
	symbols.insert(Gura_UserSymbol(attrs));
	return true;
}

Value Object_item::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		return Value(Symbol::Add(_pItem->GetTypeName()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(text))) {
		const char *text = _pItem->GetText();
		if (text == NULL) return Value::Null;
		return Value(env, text);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(children))) {
		const ItemOwner *pItemOwner = _pItem->GetItemOwner();
		if (pItemOwner == NULL) return Value::Null;
		Iterator *pIterator = new Iterator_item(pItemOwner->Reference());
		return Value(env, pIterator);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(url))) {
		const char *url = _pItem->GetURL();
		if (url == NULL) return Value::Null;
		return Value(env, url);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(title))) {
		const char *title = _pItem->GetTitle();
		if (title == NULL) return Value::Null;
		return Value(env, title);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(attrs))) {
		const char *attrs = _pItem->GetAttrs();
		if (attrs == NULL) return Value::Null;
		return Value(env, attrs);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_item::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

String Object_item::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<markdown.item:";
	rtn += _pItem->GetTypeName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for markdown.item
//-----------------------------------------------------------------------------
// markdown.item#print():void
Gura_DeclareMethod(item, print)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(item, print)
{
	Item *pItem = Object_item::GetThisObj(args)->GetItem();
	pItem->Print(sig, *env.GetConsole(), 0);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for markdown.item
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(item)
{
	Gura_AssignMethod(item, print);
}

//-----------------------------------------------------------------------------
// Gura module functions: markdown
//-----------------------------------------------------------------------------
// markdown.document(stream?:stream) {block?}
Gura_DeclareFunction(document)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(document));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns a markdown.document instance.\n"
	"If `stream` is specified, the content of the instance shall be initialized with the result of parsing the stream.\n"
	);
}

Gura_ImplementFunction(document)
{
	AutoPtr<Document> pDocument(new Document());
	if (args.Is_stream(0)) {
		if (!pDocument->ParseStream(sig, args.GetStream(0))) return Value::Null;
	}
	AutoPtr<Object_document> pObj(new Object_document(pDocument.release()));
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// markdown.setpresenter():void {block}
Gura_DeclareFunction(setpresenter)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets a presentation function that shows helps written in Markdown format.\n"
	"The function is specified as a block that takes block parameters `|title:string, doc:markdown.document|`.\n"
	);
}

Gura_ImplementFunction(setpresenter)
{
	const Function *pFuncBlock =
						args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Null;
	g_pFunc_Presenter.reset(pFuncBlock->Reference());
	return Value::Null;
}

// operator <<
Gura_ImplementBinaryOperator(Shl, document, string)
{
	Document *pDocument = Object_document::GetObject(valueLeft)->GetDocument();
	const char *text = valueRight.GetString();
	if (!pDocument->ParseString(sig, text)) return Value::Null;
	return valueLeft;
}

//-----------------------------------------------------------------------------
// Iterator_item
//-----------------------------------------------------------------------------
Iterator_item::Iterator_item(ItemOwner *pItemOwner) :
						Iterator(false), _idxItem(0), _pItemOwner(pItemOwner)
{
}

Iterator *Iterator_item::GetSource()
{
	return NULL;
}

bool Iterator_item::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idxItem < _pItemOwner->size()) {
		Item *pItem = (*_pItemOwner)[_idxItem++];
		value = Value(new Object_item(pItem->Reference()));
		return true;
	}
	return false;
}

String Iterator_item::ToString() const
{
	String rtn;
	rtn += "<iterator:markdown.item";
	rtn += ">";
	return rtn;
}

void Iterator_item::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// HelpPresenter_markdown
//-----------------------------------------------------------------------------
bool HelpPresenter_markdown::DoPresent(Environment &env, Signal sig,
									const char *title, const Help *pHelp) const
{
	if (g_pFunc_Presenter.IsNull()) {
		sig.SetError(ERR_FormatError, "presenter function is not registered");
		return false;
	}
	//ValueList valListArg;
	AutoPtr<Args> pArgs(new Args());
	if (title == NULL) {
		pArgs->AddValue(Value::Null);
	} else {
		pArgs->AddValue(Value(env, title));
	}
	if (pHelp == NULL) {
		pArgs->AddValue(Value::Null);
	} else {
		AutoPtr<Document> pDocument(new Document());
		SimpleStream_CStringReader streamSrc(pHelp->GetText());
		if (!pDocument->ParseStream(sig, streamSrc)) return false;
		pArgs->AddValue(Value(new Object_document(pDocument->Reference())));
	}
	g_pFunc_Presenter->Eval(env, sig, *pArgs);
	return !sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(root);
	Gura_RealizeUserSymbol(refs);
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(text);
	Gura_RealizeUserSymbol(children);
	Gura_RealizeUserSymbol(url);
	Gura_RealizeUserSymbol(title);
	Gura_RealizeUserSymbol(attrs);
	// class realization
	Gura_RealizeUserClassWithoutPrepare(document, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(item, env.LookupClass(VTYPE_object));
	Gura_UserClass(document)->Prepare(env);
	Gura_UserClass(item)->Prepare(env);
	// function assignment
	Gura_AssignFunction(document);
	Gura_AssignFunction(setpresenter);
	// operator assignment
	Gura_AssignBinaryOperator(Shl, document, string);
	// registoration of HelpPresenter
	HelpPresenter::Register(env, new HelpPresenter_markdown());
}

Gura_ModuleTerminate()
{
	g_pFunc_Presenter.reset(NULL);
}

Gura_EndModuleBody(markdown, markdown)

Gura_RegisterModule(markdown)
