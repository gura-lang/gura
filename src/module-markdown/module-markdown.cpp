//-----------------------------------------------------------------------------
// Gura module: markdown
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(markdown)

AutoPtr<Function> g_pFunc_Presenter;

//-----------------------------------------------------------------------------
// Item
//-----------------------------------------------------------------------------
Item::Item(Type type, int indentLevel) : _cntRef(1), _type(type),
								_indentLevel(indentLevel), _align(ALIGN_None)
{
}

Item::Item(Type type, ItemOwner *pItemOwner, int indentLevel) : _cntRef(1),
	_type(type), _pItemOwner(pItemOwner), _indentLevel(indentLevel), _align(ALIGN_None)
{
}

Item::Item(Type type, const String &text, int indentLevel) : _cntRef(1),
	_type(type), _pText(new String(text)), _indentLevel(indentLevel), _align(ALIGN_None)
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
		{ TYPE_Strike,			"strike",		},	// container
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

Item *ItemList::FindByType(Item::Type type) const
{
	foreach_const (ItemList, ppItem, *this) {
		Item *pItem = *ppItem;
		if (pItem->GetType() == type) return pItem;
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
Document::Document() : _cntRef(1), _resolvedFlag(false), _decoPrecedingFlag(false),
		_iTableRow(-1), _iTableCol(0), _stat(STAT_LineTop), _cntLine(0), _chPrev('\0'),
		_indentLevel(0), _quoteLevel(0), _cntEmptyLine(0),
		_pItemOwner(new ItemOwner()), _pItemRefereeOwner(new ItemOwner())
{
	_statStack.Push(STAT_LineTop);
	_pItemRoot.reset(new Item(Item::TYPE_Root, new ItemOwner()));
	_itemStack.push_back(_pItemRoot.get());
}

bool Document::ParseStream(Signal sig, SimpleStream &stream)
{
	enum Stat {
		STAT_FirstRowTop,
		STAT_FirstRowBody,
		STAT_GuideRowTop,
		STAT_GuideRowBody,
		STAT_TrailingRowTop,
		STAT_TrailingRowHead,
		STAT_TrailingRowBody,
		STAT_SkipToEOL,
	} stat = STAT_FirstRowTop;
	_cntLine = 0;
	_chPrev = '\0';
	String textPrefetch;
	String guide;
	StringList guideList;
	for (;;) {
		int chRaw;
		textPrefetch.clear();
		int nSeps = 0;
		int nTrailingRows = 0;
		bool pipeTopFlag = false;
		bool pipeFoundFlag = false;
		bool prefetchFlag = true;
		stat = STAT_FirstRowTop;
		while (prefetchFlag && (chRaw = stream.GetChar(sig)) >= 0) {
			char ch = static_cast<char>(static_cast<UChar>(chRaw));
			textPrefetch += ch;
			bool pushbackFlag = false;
			do {
			pushbackFlag = false;
			if (stat == STAT_FirstRowTop) {
				if (ch == '|') {
					pipeTopFlag = pipeFoundFlag = true;
					nSeps = 0;
					stat = STAT_FirstRowBody;
				} else if (IsEOL(ch)) {
					prefetchFlag = false;
				} else {
					pipeTopFlag = pipeFoundFlag = false;
					nSeps = 0;
					stat = STAT_FirstRowBody;
				}
			} else if (stat == STAT_FirstRowBody) {
				if (ch == '|') {
					pipeFoundFlag = true;
					nSeps++;
				} else if (IsEOL(ch)) {
					if (pipeFoundFlag) {
						stat = STAT_GuideRowTop;
					} else {
						prefetchFlag = false;
					}
				} else {
					// nothing to do 
				}
			} else if (stat == STAT_GuideRowTop) {
				if (ch == '|') {
					if (pipeTopFlag) {
						pipeFoundFlag = true;
						nSeps = 0;
						guideList.clear();
						guide.clear();
						stat = STAT_GuideRowBody;
					} else {
						stat = STAT_SkipToEOL;
					}
				} else if (IsEOL(ch)) {
					prefetchFlag = false;
				} else if (ch == '-' || ch == ':') {
					pipeFoundFlag = false;
					nSeps = 0;
					guideList.clear();
					guide.clear();
					guide += ch;
					stat = STAT_GuideRowBody;
				} else {
					stat = STAT_SkipToEOL;
				}
			} else if (stat == STAT_GuideRowBody) {
				if (ch == '|') {
					pipeFoundFlag = true;
					guideList.push_back(Strip(guide.c_str()));
					guide.clear();
					nSeps++;
				} else if (IsEOL(ch)) {
					if (pipeFoundFlag) {
						if (!guide.empty()) {
							guideList.push_back(Strip(guide.c_str()));
						}
						stat = STAT_TrailingRowTop;
					} else {
						prefetchFlag = false;
					}
				} else if (IsWhite(ch) || ch == '-' || ch == ':') {
					guide += ch;
				} else {
					stat = STAT_SkipToEOL;
				}
			} else if (stat == STAT_TrailingRowTop) {
				if (ch == '|') {
					if (pipeTopFlag) {
						pipeFoundFlag = true;
						nSeps = 0;
						stat = STAT_TrailingRowBody;
					} else {
						stat = STAT_SkipToEOL;
					}
				} else if (IsWhite(ch) || IsEOL(ch)) {
					pushbackFlag = true;
					stat = STAT_TrailingRowHead;
				} else {
					pipeFoundFlag = false;
					nSeps = 0;
					stat = STAT_TrailingRowBody;
				}
			} else if (stat == STAT_TrailingRowHead) {
				if (IsWhite(ch)) {
					// nothing to do
				} else if (IsEOL(ch)) {
					// detected a blank line
					prefetchFlag = false;
				} else {
					pushbackFlag = true;
					stat = STAT_TrailingRowBody;
				}
			} else if (stat == STAT_TrailingRowBody) {
				if (ch == '|') {
					pipeFoundFlag = true;
					nSeps++;
				} else if (IsEOL(ch)) {
					nTrailingRows++;
					stat = STAT_TrailingRowTop;
				} else {
					// nothing to do
				}
			} else if (stat == STAT_SkipToEOL) {
				if (IsEOL(ch)) {
					prefetchFlag = false;
				} else {
					// nothing to do
				}
			}
			} while (pushbackFlag);
		}
		if (textPrefetch.empty()) {
			if (!ParseChar(sig, '\0')) return false;
			break;
		}
		if (nTrailingRows == 0) {
			if (!_ParseString(sig, textPrefetch)) return false;
		} else {
			_alignList.clear();
			foreach (StringList, pGuide, guideList) {
				const String &guide = *pGuide;
				Align align = ALIGN_Left;
				if (guide.empty()) {
					align = ALIGN_Left;
				} else {
					bool colonLeftFlag = (guide[0] == ':');
					bool colonRightFlag = (guide[guide.size() - 1] == ':');
					if (colonLeftFlag && colonRightFlag) {
						align = ALIGN_Center;
					} else if (colonLeftFlag) {
						align = ALIGN_Left;
					} else if (colonRightFlag) {
						align = ALIGN_Right;
					} else {
						align = ALIGN_Left;
					}
				}
				_alignList.push_back(align);
			}
			BeginTable();
			if (!_ParseString(sig, textPrefetch)) return false;
			EndTable();
		}
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
	bool pushbackFlag = true;
	do {
	pushbackFlag = false;
	switch (_stat) {
	case STAT_LineTop: {
		_indentLevel = 0;
		pushbackFlag = true;
		_stat = IsTableMode()? STAT_LineHeadTable : STAT_LineHead;
		break;
	}
	case STAT_LineHead: {
		if (!_itemStackTag.empty()) {
			// When within a tag, ignore special characters except for '<'.
			pushbackFlag = true;
			_stat = STAT_Text;
		} else if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			pushbackFlag = true;
			BeginCodeBlock(NULL);
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel = 1;
			_stat = STAT_BlockQuote;
		} else if (ch == '=') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_EqualAtHead;
		} else if (ch == '#' && _indentLevel <= 0) {
			FlushItem(Item::TYPE_Paragraph, false, false);
			_indentLevel = 1;
			_stat = STAT_SetextHeaderHead;
		} else if (ch == '*') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_AsteriskAtHead;
		} else if (ch == '+') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_PlusAtHead;
		} else if (ch == '-') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_HyphenAtHead;
		} else if (IsDigit(ch)) {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_DigitAtHead;
		} else if (ch == '`') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_BackquoteAtHead;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushItem(Item::TYPE_Paragraph, false, false);
			_indentLevel = 0;
			_stat = STAT_LineHeadNL;
		} else if (ch == '[') {
			AppendJointSpace();
			_pItemLink.reset(new Item(Item::TYPE_Referee));
			_textAhead.clear();
			_textAhead += ch;
			_field.clear();
			_stat = STAT_RefereeRefId;
		} else {
			if (_decoPrecedingFlag) _text += ' ';
			AppendJointSpace();
			pushbackFlag = true;
			_stat = STAT_Text;
		}
		_decoPrecedingFlag = false;
		break;
	}
	case STAT_LineHeadTable: {
		if (IsWhite(ch) || IsEOL(ch)) {
			// nothing to do
		} else if (ch == '|') {
			// skip a pipe character placed at top of the line.
			BeginTableRow();
			_stat = STAT_Text;
		} else {
			BeginTableRow();
			pushbackFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_LineHeadNL: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (ch == '>') {
			pushbackFlag = true;
			_stat = STAT_LineHead;
		} else {
			_quoteLevel = 0;
			AdjustBlockQuote();
			pushbackFlag = true;
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
			pushbackFlag = true;
			AdjustBlockQuote();
			BeginCodeBlock(_textAhead.c_str());
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel++;
		} else {
			AdjustBlockQuote();
			pushbackFlag = true;
			_stat = STAT_LineHead;
		}
		break;
	}
	case STAT_EqualAtHead: {
		if (ch == '=') {
			_textAhead += ch;
			_stat = STAT_AtxHeader1;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			pushbackFlag = true;
			_stat = STAT_AtxHeader1;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			pushbackFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			AppendJointSpace();
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_AsteriskAtHead: {
		if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false, false);
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel >= INDENT_CodeBlock) {
			pushbackFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			FlushText(Item::TYPE_Text, false, false);
			_statStack.Push(STAT_Text);
			pushbackFlag = true;
			_stat = STAT_Asterisk;
		}
		break;
	}
	case STAT_PlusAtHead: {
		if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false, false);
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel >= INDENT_CodeBlock) {
			pushbackFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			AppendJointSpace();
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_HyphenAtHead: {
		if (ch == '-') {
			_textAhead += ch;
			_stat = STAT_AtxHeader2;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			pushbackFlag = true;
			_stat = STAT_AtxHeader2;
		} else if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false, false);
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel >= INDENT_CodeBlock) {
			pushbackFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			AppendJointSpace();
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_DigitAtHead: {
		if (IsDigit(ch)) {
			_textAhead += ch;
		} else if (ch == '.') {
			_textAhead += ch;
			_stat = STAT_DigitDotAtHead;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			pushbackFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			AppendJointSpace();
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_DigitDotAtHead: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_OList);
		} else if (_indentLevel >= INDENT_CodeBlock) {
			pushbackFlag = true;
			BeginCodeBlock(_textAhead.c_str());
		} else {
			AppendJointSpace();
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_BackquoteAtHead: {
		if (ch == '`') {
			_textAhead += ch;
			_stat = STAT_BackquoteAtHead2nd;
		} else {
			_stat = STAT_Text;
			if (CheckSpecialChar('`')) {
				// nothing to do
			} else {
				AppendJointSpace();
				_text += _textAhead;
			}
			pushbackFlag = true;
		}
		break;
	}
	case STAT_BackquoteAtHead2nd: {
		if (ch == '`') {
			_field.clear();
			_stat = STAT_FencedCodeBlockAttr;
		} else {
			_stat = STAT_Text;
			if (CheckSpecialChar('`')) {
				// see STAT_Backquote as well
				_stat = STAT_CodeEsc;
			} else {
				AppendJointSpace();
				_text += _textAhead;
			}
			pushbackFlag = true;
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
			pushbackFlag = true;
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_SetextHeaderPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			_text.clear();
			pushbackFlag = true;
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
			FlushItem(type, false, true);
			pushbackFlag = IsEOF(ch);
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
			pushbackFlag = true;
			_stat = STAT_SetextHeader;
		} else {
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_AtxHeader1: {
		if (ch == '=') {
			_textAhead += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushItem(Item::TYPE_Header1, false, false);
			pushbackFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			AppendJointSpace();
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_AtxHeader2: {
		if (ch == '-') {
			_textAhead += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			FlushText(Item::TYPE_Text, false, false);
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
			pushbackFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			AppendJointSpace();
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_ListItemPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			pushbackFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem: {
		if (CheckSpecialChar(ch)) {
			// nothing to do
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_indentLevel = 0;
			pushbackFlag = IsEOF(ch);
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
			pushbackFlag = true;
			_stat = STAT_LineTop;
		} else {
			_text += ' ';
			pushbackFlag = true;
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
			pushbackFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel++;
		} else {
			AdjustBlockQuote();
			pushbackFlag = true;
			_stat = STAT_ListItem_LineHead;
		}
		break;
	}
	case STAT_ListItem_Asterisk: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else {
			_text += ' ';
			FlushText(Item::TYPE_Text, false, false);
			_statStack.Push(STAT_ListItem);
			pushbackFlag = true;
			_stat = STAT_Asterisk;
		}
		break;
	}
	case STAT_ListItem_Plus: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else {
			_text += ' ';
			_text += _textAhead;
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			pushbackFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndListItem();
			_itemStack.ClearListItem();
			pushbackFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			pushbackFlag = true;
			BeginCodeBlockInList(NULL);
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
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			AdjustBlockQuote();
			pushbackFlag = true;
			_stat = STAT_LineTop;
		} else {
 			FlushItem(Item::TYPE_Paragraph, false, false);
			pushbackFlag = true;
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
			pushbackFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			pushbackFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
			FlushItem(Item::TYPE_Paragraph, false, false);
			pushbackFlag = true;
			_statStack.Push(STAT_ListItem);
			_stat = STAT_Asterisk;
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
			pushbackFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			pushbackFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
 			FlushItem(Item::TYPE_Paragraph, false, false);
			_text += _textAhead;
			pushbackFlag = true;
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
			pushbackFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			pushbackFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
 			FlushItem(Item::TYPE_Paragraph, false, false);
			_text += _textAhead;
			pushbackFlag = true;
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
			pushbackFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			pushbackFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
			_text += ' ';
			_text += _textAhead;
			pushbackFlag = true;
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
			pushbackFlag = true;
		} else if (_indentLevel >= INDENT_CodeBlockInList) {
			pushbackFlag = true;
			BeginCodeBlockInList(_textAhead.c_str());
		} else {
 			FlushItem(Item::TYPE_Paragraph, false, false);
			_text += _textAhead;
			pushbackFlag = true;
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
		} else if (IsEOL(ch)) {
			_cntEmptyLine++;
			_indentLevel = 0;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			Item *pItemParent = _itemStack.back();
			for (int i = 0; i < _cntEmptyLine; i++) {
				ItemOwner *pItemOwner = new ItemOwner();
				do {
					Item *pItem = new Item(Item::TYPE_Line, pItemOwner);
					pItemParent->GetItemOwner()->push_back(pItem);
				} while (0);
				do {
					Item *pItem = new Item(Item::TYPE_Text, _text);
					pItemOwner->push_back(pItem);
				} while (0);
			}
			_text.clear();
			for (int i = 0; i < _indentLevel - INDENT_CodeBlock; i++) _text += ' ';
			pushbackFlag = true;
			_stat = STAT_CodeBlock;
		} else if (ch == '>' && _indentLevel == 0) {
			_indentLevel = -1;
			_quoteLevel = 1;
			_stat = STAT_CodeBlockUnderBlockQuote;
		} else {
			pushbackFlag = true;
			EndCodeBlock();
		}
		break;
	}
	case STAT_FencedCodeBlockAttr: {
		if (IsEOL(ch) || IsEOF(ch)) {
			BeginFencedCodeBlock();
		} else {
			_field += ch;
		}
		break;
	}
	case STAT_FencedCodeBlock: {
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
			_stat = STAT_FencedCodeBlock_LineHead;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_FencedCodeBlock_LineHead: {
		if (ch == '`') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_FencedCodeBlock_LineHead2nd;
		} else {
			pushbackFlag = true;
			_stat = STAT_FencedCodeBlock;
		}
		break;
	}
	case STAT_FencedCodeBlock_LineHead2nd: {
		if (ch == '`') {
			_textAhead += ch;
			_stat = STAT_FencedCodeBlock_LineHead3rd;
		} else {
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_FencedCodeBlock;
		}
		break;
	}
	case STAT_FencedCodeBlock_LineHead3rd: {
		if (ch == '`') {
			_stat = STAT_FencedCodeBlock_SkipToEOL;
		} else {
			_text += _textAhead;
			pushbackFlag = true;
			_stat = STAT_FencedCodeBlock;
		}
		break;
	}
	case STAT_FencedCodeBlock_SkipToEOL: {
		if (IsEOL(ch) || IsEOF(ch)) {
			EndFencedCodeBlock();
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_CodeBlockUnderBlockQuote: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (_indentLevel >= INDENT_CodeBlock) {
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			pushbackFlag = IsEOF(ch);
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
			pushbackFlag = true;
			_stat = STAT_CodeBlockInList;
		} else {
			pushbackFlag = true;
			EndCodeBlockInList();
		}
		break;
	}
	case STAT_Backquote: {
		if (ch == '`') {
			// see STAT_BackquoteAtHead2nd as well
			_stat = STAT_CodeEsc;
		} else {
			pushbackFlag = true;
			_stat = STAT_Code;
		}
		break;
	}
	case STAT_Code: {
		if (ch == '`') {
			FlushText(Item::TYPE_Code, true, true);
			_stat = STAT_DecorationPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushText(Item::TYPE_Code, true, true);
			pushbackFlag = true;
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
			FlushText(Item::TYPE_Code, true, true);
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_CodeEsc_Backquote: {
		if (ch == '`') {
			FlushText(Item::TYPE_Code, true, true);
			_stat = _statStack.Pop();
		} else {
			_text += '`';
			pushbackFlag = true;
			_stat = STAT_CodeEsc;
		}
		break;
	}
	case STAT_Text: {
		if (CheckSpecialChar(ch)) {
			// nothing to do
		} else if (ch == '|') {
			if (IsTableMode()) {
				FlushTableCol(false);
			} else {
				_text += ch;
			}
		} else if (IsEOL(ch)) {
			if (IsTableMode()) {
				FlushTableCol(true);
				EndTableRow();
				if (IsTableGuideRow()) {
					_stat = STAT_SkipTableGuideRow;
				} else {
					_stat = STAT_LineTop;
				}
			} else if (_itemStackTag.empty()) {
				if (EndsWith(_text.c_str(), "  ", false) != NULL) {
					FlushText(Item::TYPE_Text, false, true);
					Item *pItem = new Item(Item::TYPE_LineBreak);
					_pItemOwner->push_back(pItem);
				}
				_stat = STAT_LineTop;
			} else {
				_text += ch;
			}
		} else if (IsEOF(ch)) {
			pushbackFlag = true;
			_stat = STAT_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_SkipTableGuideRow: {
		if (IsEOL(ch)) {
			AdvanceTableRow();
			_stat = STAT_LineTop;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_Asterisk: {
		if (ch == '*') {
			BeginDecoration(Item::TYPE_Strong);
			_stat = STAT_AsteriskStrong;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			BeginDecoration(Item::TYPE_Emphasis);
			pushbackFlag = true;
			_stat = STAT_AsteriskEmphasis;
		}
		break;
	}
	case STAT_AsteriskEmphasis: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false, false);
			_statStack.Push(_stat);
			_stat = STAT_Backquote;
		} else if (ch == '*') {
			EndDecoration();
			_stat = STAT_DecorationPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			CancelDecoration("*");
			pushbackFlag = true;
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
			FlushText(Item::TYPE_Text, false, false);
			_statStack.Push(_stat);
			_stat = STAT_Backquote;
		} else if (ch == '*') {
			_stat = STAT_AsteriskStrongEnd;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			CancelDecoration("**");
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_AsteriskStrongEnd: {
		if (ch == '*') {
			EndDecoration();
			_stat = STAT_DecorationPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			ReplaceDecoration(Item::TYPE_Emphasis, "*");
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			FlushText(Item::TYPE_Text, true, true);
			BeginDecoration(Item::TYPE_Emphasis);
			_statStack.Push(STAT_AsteriskStrong);
			pushbackFlag = true;
			_stat = STAT_AsteriskEmphasis;
		}
		break;
	}
	case STAT_Underscore: {
		if (ch == '_') {
			BeginDecoration(Item::TYPE_Strong);
			_stat = STAT_UnderscoreStrong;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			BeginDecoration(Item::TYPE_Emphasis);
			pushbackFlag = true;
			_stat = STAT_UnderscoreEmphasis;
		}
		break;
	}
	case STAT_UnderscoreEmphasis: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false, false);
			_statStack.Push(_stat);
			_stat = STAT_Backquote;
		} else if (ch == '_') {
			//EndDecoration();
			//_stat = STAT_DecorationPost;
			_stat = STAT_UnderscoreEmphasisPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			CancelDecoration("_");
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_UnderscoreEmphasisPost: {
		if (IsSpace(ch)) {
			EndDecoration();
			pushbackFlag = true;
			_stat = STAT_DecorationPost;
		} else {
			_text += '_';
			pushbackFlag = true;
			_stat = STAT_UnderscoreEmphasis;
		}
		break;
	}
	case STAT_UnderscoreStrong: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false, false);
			_statStack.Push(_stat);
			_stat = STAT_Backquote;
		} else if (ch == '_') {
			_stat = STAT_UnderscoreStrongEnd;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			CancelDecoration("__");
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_UnderscoreStrongEnd: {
		if (ch == '_') {
			//EndDecoration();
			//_stat = STAT_DecorationPost;
			_stat = STAT_UnderscoreStrongPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			ReplaceDecoration(Item::TYPE_Emphasis, "_");
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			FlushText(Item::TYPE_Text, true, true);
			BeginDecoration(Item::TYPE_Emphasis);
			_statStack.Push(STAT_UnderscoreStrong);
			pushbackFlag = true;
			_stat = STAT_UnderscoreEmphasis;
		}
		break;
	}
	case STAT_UnderscoreStrongPost: {
		if (IsSpace(ch)) {
			EndDecoration();
			pushbackFlag = true;
			_stat = STAT_DecorationPost;
		} else {
			_text += "__";
			pushbackFlag = true;
			_stat = STAT_UnderscoreStrong;
		}
		break;
	}
	case STAT_Tilda: {
		if (ch == '~') {
			BeginDecoration(Item::TYPE_Strike);
			_stat = STAT_TildaStrike;
		} else {
			_text += '~';
			pushbackFlag = true;
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_TildaStrike: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false, false);
			_statStack.Push(_stat);
			_stat = STAT_Backquote;
		} else if (ch == '~') {
			_stat = STAT_TildaStrikeEnd;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			CancelDecoration("~~");
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_TildaStrikeEnd: {
		if (ch == '~') {
			EndDecoration();
			_stat = STAT_DecorationPost;
		} else {
			CancelDecoration("~~");
			_text += '~';
			pushbackFlag = true;
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_DecorationPost: {
		_stat = _statStack.Pop();
		if (_stat == STAT_Text && IsEOL(ch)) {
			_decoPrecedingFlag = true;
		}
		pushbackFlag = true;
		break;
	}
	case STAT_Ampersand: {
		if (ch == ';') {
			FlushText(Item::TYPE_Text, false, false);
			Item *pItem = new Item(Item::TYPE_Entity, _field);
			_pItemOwner->push_back(pItem);
			_stat = _statStack.Pop();
 		} else if (IsAlpha(ch)) {
			_textAhead += ch;
			_field += ch;
		} else {
			_text += _textAhead;
			pushbackFlag = true;
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_AngleBracketFirst: {
		if (ch == '!') {
			_stat = STAT_CommentStartFirst;
		} else {
			pushbackFlag = true;
			_stat = STAT_AngleBracket;
		}
		break;
	}
	case STAT_CommentStartFirst: {
		if (ch == '-') {
			_stat = STAT_CommentStartSecond;
		} else {
			_textAhead += "!";
			_field += "!";
			pushbackFlag = true;
			_stat = STAT_AngleBracket;
		}
		break;
	}
	case STAT_CommentStartSecond: {
		if (ch == '-') {
			FlushText(Item::TYPE_Text, false, false);
			_text = "<!--";
			_stat = STAT_Comment;
		} else {
			_textAhead += "!-";
			_field += "!-";
			pushbackFlag = true;
			_stat = STAT_AngleBracket;
		}
		break;
	}
	case STAT_Comment: {
		_text += ch;
		if (ch == '-') {
			_stat = STAT_CommentEndFirst;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_CommentEndFirst: {
		_text += ch;
		if (ch == '-') {
			_stat = STAT_CommentEndSecond;
		} else {
			_stat = STAT_Comment;
		}
		break;
	}
	case STAT_CommentEndSecond: {
		_text += ch;
		if (ch == '>') {
			FlushText(Item::TYPE_Text, false, false);
			_stat = _statStack.Pop();
		} else {
			_stat = STAT_Comment;
		}
		break;
	}
	case STAT_AngleBracket: {
		if (ch == '>') {
			String tagName, attrs;
			bool closedFlag = false;
			if (IsLink(_field.c_str())) {
				FlushText(Item::TYPE_Text, false, false);
				Item *pItemLink = new Item(Item::TYPE_Link, new ItemOwner());
				pItemLink->SetURL(_field);
				_pItemOwner->push_back(pItemLink);
				do {
					Item *pItem = new Item(Item::TYPE_Text, _field);
					pItemLink->GetItemOwner()->push_back(pItem);
				} while (0);
			} else if (IsBeginTag(_field.c_str(), tagName, attrs, closedFlag)) {
				BeginTag(tagName.c_str(), attrs.c_str(), closedFlag);
			} else if (IsEndTag(_field.c_str(), tagName)) {
				if (!EndTag(tagName.c_str())) {
					sig.SetError(ERR_FormatError, "unbalanced tags at line %d", _cntLine + 1);
					return false;
				}
			} else {
				_text += _textAhead;
				_text += ch;
			}
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			pushbackFlag = true;
			_stat = _statStack.Pop();
		} else {
			// take care of STAT_CommentStartFirst and STAT_CommentStartSecond as well
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
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			AppendJointSpace();
			_text += _textAhead;
			pushbackFlag = true;
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_LinkRefId: {
		if (ch == ']') {
			FlushText(Item::TYPE_Text, false, false);
			_pItemLink->SetRefId(_field);
			_itemsLinkReferrer.push_back(_pItemLink.get());
			_pItemOwner->push_back(_pItemLink.release());
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			FlushText(Item::TYPE_Text, false, false);
			_pItemLink->SetURL(Strip(_field.c_str()));
			_pItemOwner->push_back(_pItemLink.release());
			_decoPrecedingFlag = true;
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			FlushText(Item::TYPE_Text, false, false);
			_pItemOwner->push_back(_pItemLink.release());
			_decoPrecedingFlag = true;
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			FlushText(Item::TYPE_Text, false, false);
			_pItemOwner->push_back(_pItemLink.release());
			_decoPrecedingFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += _textAhead;
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			AppendJointSpace();
			_text += _textAhead;
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			FlushText(Item::TYPE_Text, false, false);
			_pItemLink->SetURL(Strip(_field.c_str()));
			AddItemReferee(_pItemLink.release());
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			FlushText(Item::TYPE_Text, false, false);
			AddItemReferee(_pItemLink.release());
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			pushbackFlag = true;
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
			FlushText(Item::TYPE_Text, false, false);
			AddItemReferee(_pItemLink.release());
			pushbackFlag = true;
			_stat = STAT_LineTop;
		} else {
			_text += _textAhead;
			pushbackFlag = true;
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
	} while (pushbackFlag);
	if (IsEOL(ch)) _cntLine++;
	_chPrev = ch;
	return true;
}

bool Document::CheckSpecialChar(char ch)
{
	if (!_itemStackTag.empty()) {
		// When within a tag, ignore special characters except for '<'.
		if (ch == '<') {
			_textAhead.clear();
			_field.clear();
			_textAhead += ch;
			_statStack.Push(_stat);
			_stat = STAT_AngleBracketFirst;
			return true;
		}
		return false;
	}
	if (ch == '\\') {
		_statStack.Push(_stat);
		_stat = STAT_Escape;
		return true;
	} else if (ch == '`') {
		FlushText(Item::TYPE_Text, false, false);
		_statStack.Push(_stat);
		_stat = STAT_Backquote;
		return true;
	} else if (ch == '*') {
		FlushText(Item::TYPE_Text, false, false);
		_statStack.Push(_stat);
		_stat = STAT_Asterisk;
		return true;
	} else if (ch == '_' && IsSpace(_chPrev)) {
		FlushText(Item::TYPE_Text, false, false);
		_statStack.Push(_stat);
		_stat = STAT_Underscore;
		return true;
	} else if (ch == '~') {
		FlushText(Item::TYPE_Text, false, false);
		_statStack.Push(_stat);
		_stat = STAT_Tilda;
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
		_stat = STAT_AngleBracketFirst;
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
		FlushItem(Item::TYPE_Paragraph, false, false);
		for ( ; quoteLevel < _quoteLevel; quoteLevel++) {
			Item *pItemParent = _itemStack.back();
			Item *pItem = new Item(Item::TYPE_BlockQuote, new ItemOwner());
			pItemParent->GetItemOwner()->push_back(pItem);
			_itemStack.push_back(pItem);
		}
		adjustFlag = true;
	} else if (quoteLevel > _quoteLevel) {
		FlushItem(Item::TYPE_Paragraph, false, false);
		while (quoteLevel > _quoteLevel) {
			Item *pItem = _itemStack.back();
			if (pItem->IsBlockQuote()) quoteLevel--;
			_itemStack.pop_back();
		}
		adjustFlag = true;
	}
	return adjustFlag;
}

void Document::AppendJointSpace()
{
	if (!_text.empty() && !IsWhite(_text[_text.size() - 1])) _text += ' ';
}

void Document::FlushText(Item::Type type, bool stripLeftFlag, bool stripRightFlag)
{
	String text = Strip(_text.c_str(),
						stripLeftFlag || _pItemOwner->empty(), stripRightFlag);
	if (text.empty()) {
		// nothing to do
	} else if (!_pItemOwner->empty() && _pItemOwner->back()->GetType() == type) {
		_pItemOwner->back()->AppendText(text);
	} else {
		Item *pItem = new Item(type, text);
		_pItemOwner->push_back(pItem);
	}
	_text.clear();
}

void Document::FlushItem(Item::Type type, bool stripLeftFlag, bool stripRightFlag)
{
	Item *pItemParent = _itemStack.back();
	FlushText(Item::TYPE_Text, stripLeftFlag, stripRightFlag);
	if (!_pItemOwner->empty()) {
		Item *pItem = new Item(type, _pItemOwner.release());
		pItemParent->GetItemOwner()->push_back(pItem);
		_pItemOwner.reset(new ItemOwner());
	}
}

void Document::FlushElement()
{
	Item *pItemParent = _itemStack.back();
	FlushText(Item::TYPE_Text, false, false);
	if (pItemParent->GetItemOwner()->empty()) {
		pItemParent->GetItemOwner()->Store(*_pItemOwner);
		_pItemOwner.reset(new ItemOwner());
	} else if (!_pItemOwner->empty()) {
		Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner.release());
		pItemParent->GetItemOwner()->push_back(pItem);
		_pItemOwner.reset(new ItemOwner());
	}
}

void Document::BeginTable()
{
	Item *pItemParent = _itemStack.back();
	Item *pItem = new Item(Item::TYPE_Tag, new ItemOwner());
	pItem->SetText("table");
	pItemParent->GetItemOwner()->push_back(pItem);
	_itemStack.push_back(pItem);
	_iTableRow = 0;
	_stat = STAT_LineTop;
}

void Document::EndTable()
{
	while (!_itemStack.empty()) {
		Item *pItem = _itemStack.back();
		_itemStack.pop_back();
		if (pItem->IsTag() && ::strcmp(pItem->GetText(), "table") == 0) break;
	}
	_iTableRow = -1;
	_stat = STAT_LineTop;
}

void Document::BeginTableRow()
{
	Item *pItemParent = _itemStack.back();
	Item *pItem = new Item(Item::TYPE_Tag, new ItemOwner());
	pItem->SetText("tr");
	pItemParent->GetItemOwner()->push_back(pItem);
	_itemStack.push_back(pItem);
	_iTableCol = 0;
}

void Document::EndTableRow()
{
	_itemStack.pop_back();
	AdvanceTableRow();
}

void Document::FlushTableCol(bool eolFlag)
{
	bool stripLeftFlag = false, stripRightFlag = true;
	Item *pItemParent = _itemStack.back();
	FlushText(Item::TYPE_Text, stripLeftFlag, stripRightFlag);
	if (!eolFlag || !_pItemOwner->empty()) {
		Item *pItem = new Item(Item::TYPE_Tag, _pItemOwner.release());
		pItem->SetText(IsTableFirstRow()? "th" : "td");
		Align align = (_iTableCol < _alignList.size())? _alignList[_iTableCol] : ALIGN_Left;
		pItem->SetAlign(align);
		if (align == ALIGN_Center) {
			pItem->SetAttrs("style=\"text-align:center\"");
		} else if (align == ALIGN_Right) {
			pItem->SetAttrs("style=\"text-align:right\"");
		}
		pItemParent->GetItemOwner()->push_back(pItem);
		_pItemOwner.reset(new ItemOwner());
		_iTableCol++;
	}
}

void Document::BeginCodeBlock(const char *textInit)
{
	FlushItem(Item::TYPE_Paragraph, false, false);
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

void Document::BeginFencedCodeBlock()
{
	FlushItem(Item::TYPE_Paragraph, false, false);
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_CodeBlock, new ItemOwner(), _indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} while (0);
	_stat = STAT_FencedCodeBlock;
}

void Document::EndFencedCodeBlock()
{
	_itemStack.pop_back();
	_stat = STAT_LineTop;
}

void Document::BeginCodeBlockInList(const char *textInit)
{
	FlushItem(Item::TYPE_Paragraph, false, false);
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
	FlushText(Item::TYPE_Text, false, false);
	_pItemOwner.reset(_itemOwnerStack.Pop());
}

void Document::CancelDecoration(const char *textAhead)
{
	_text.insert(0, textAhead);
	FlushText(Item::TYPE_Text, false, false);
	_pItemOwner.reset(_itemOwnerStack.Pop());
	Item *pItemToCancel = _pItemOwner->back();
	_pItemOwner->pop_back();
	ItemOwner &itemOwnerToCancel = *pItemToCancel->GetItemOwner();
	ItemOwner::iterator ppItem = itemOwnerToCancel.begin();
	if (ppItem != itemOwnerToCancel.end() && (*ppItem)->IsText() &&
		!_pItemOwner->empty() && _pItemOwner->back()->IsText()) {
		_pItemOwner->back()->AppendText((*ppItem)->GetText());
		ppItem++;
	}
	for ( ; ppItem != itemOwnerToCancel.end(); ppItem++) {
		_pItemOwner->push_back((*ppItem)->Reference());
	}
	Item::Delete(pItemToCancel);
}

void Document::ReplaceDecoration(Item::Type type, const char *textAhead)
{
	_text.insert(0, textAhead);
	FlushText(Item::TYPE_Text, false, false);
	_pItemOwner.reset(_itemOwnerStack.Pop());
	Item *pItemToReplace = _pItemOwner->back();
	pItemToReplace->SetType(type);
}

void Document::BeginTag(const char *tagName, const char *attrs, bool closedFlag)
{
	FlushText(Item::TYPE_Text, false, false);
	Item *pItem = new Item(Item::TYPE_Tag);
	pItem->SetText(tagName);
	if (attrs[0] != '\0') pItem->SetAttrs(attrs);
	_pItemOwner->push_back(pItem);
	if (!closedFlag) {
		ItemOwner *pItemOwner = new ItemOwner();
		pItem->SetItemOwner(pItemOwner);
		_itemOwnerStack.Push(_pItemOwner.release());
		_pItemOwner.reset(pItemOwner->Reference());
		_itemStackTag.push_back(pItem);
	}
}

bool Document::EndTag(const char *tagName)
{
	if (_itemStackTag.empty() || ::strcmp(_itemStackTag.back()->GetText(), tagName) != 0) {
		return false;
	}
	FlushText(Item::TYPE_Text, false, false);
	_pItemOwner.reset(_itemOwnerStack.Pop());
	_itemStackTag.pop_back();
	return true;
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
						String &tagName, String &attrs, bool &closedFlag)
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
	closedFlag = false;
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
				closedFlag = true;
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
				//tagName += ch;
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
	symbols.insert(Gura_UserSymbol(refs));
	symbols.insert(Gura_UserSymbol(root));
	return true;
}

Value Object_document::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(refs))) {
		const ItemOwner *pItemOwner = _pDocument->GetItemRefereeOwner();
		Iterator *pIterator = new Iterator_item(pItemOwner->Reference());
		return Value(new Object_iterator(env, pIterator));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(root))) {
		_pDocument->ResolveReference();
		return Value(new Object_item(_pDocument->GetItemRoot()->Reference()));
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
// markdown.document#parse(str:string):void
Gura_DeclareMethod(document, parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Parses a Markdown text in a string.");
}

Gura_ImplementMethod(document, parse)
{
	Document *pDocument = Object_document::GetThisObj(args)->GetDocument();
	pDocument->ParseString(sig, args.GetString(0));
	return Value::Null;
}

// markdown.document#read(stream:stream:r):void
Gura_DeclareMethod(document, read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Parses a Markdown text from a stream.");
}

Gura_ImplementMethod(document, read)
{
	Document *pDocument = Object_document::GetThisObj(args)->GetDocument();
	pDocument->ParseStream(sig, args.GetStream(0));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for markdown.document
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(document)
{
	Gura_AssignMethod(document, parse);
	Gura_AssignMethod(document, read);
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
	symbols.insert(Gura_UserSymbol(align));
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
		return Value(text);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(children))) {
		const ItemOwner *pItemOwner = _pItem->GetItemOwner();
		if (pItemOwner == NULL) return Value::Null;
		Iterator *pIterator = new Iterator_item(pItemOwner->Reference());
		return Value(new Object_iterator(env, pIterator));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(url))) {
		const char *url = _pItem->GetURL();
		if (url == NULL) return Value::Null;
		return Value(url);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(title))) {
		const char *title = _pItem->GetTitle();
		if (title == NULL) return Value::Null;
		return Value(title);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(attrs))) {
		const char *attrs = _pItem->GetAttrs();
		if (attrs == NULL) return Value::Null;
		return Value(attrs);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(align))) {
		Align align = _pItem->GetAlign();
		return Value(
			(align == ALIGN_Left)? Gura_Symbol(left) :
			(align == ALIGN_Center)? Gura_Symbol(center) :
			(align == ALIGN_Right)? Gura_Symbol(right) : Gura_Symbol(none));
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
// markdown.item#print(indent?:number):void
Gura_DeclareMethod(item, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints structured content of the item.\n"
		"Argument `indent` specifies an indentation level and is set to zero when omitted.\n");
}

Gura_ImplementMethod(item, print)
{
	Item *pItem = Object_item::GetThisObj(args)->GetItem();
	int indentLevel = args.Is_number(0)? args.GetInt(0) : 0;
	pItem->Print(sig, *env.GetConsole(), indentLevel);
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
// markdown.document(stream?:stream:r) {block?}
Gura_DeclareFunction(document)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	SetClassToConstruct(Gura_UserClass(document));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an instance of `markdown.document`.\n"
		"If `stream` is specified, the content of the instance shall be initialized\n"
		"with the result of parsing the stream.\n"
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets a presentation procedure that shows helps written in Markdown format.\n"
		"The procedure is written in the function's block that takes block parameters:\n"
		"`|title:string, doc:markdown.document|`.\n"
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

//-----------------------------------------------------------------------------
// Implementation of operators
//-----------------------------------------------------------------------------
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
		pArgs->AddValue(Value(title));
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
	Gura_RealizeUserSymbol(align);
	// class realization
	Gura_RealizeUserClass(document, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(item, env.LookupClass(VTYPE_object));
	Gura_PrepareUserClass(document);
	Gura_PrepareUserClass(item);
	// class reference assignment
	Gura_AssignValue(item, Value(Gura_UserClass(item)->Reference()));
	// function assignment
	Gura_AssignFunction(document);
	Gura_AssignFunction(setpresenter);
	// operator assignment
	Gura_AssignBinaryOperator(Shl, document, string);
	// registoration of HelpPresenter
	HelpPresenter::Register(env, new HelpPresenter_markdown());
	return true;
}

Gura_ModuleTerminate()
{
	g_pFunc_Presenter.reset(NULL);
}

Gura_EndModuleBody(markdown, markdown)

Gura_RegisterModule(markdown)
