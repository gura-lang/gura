//-----------------------------------------------------------------------------
// Gura module: markdown
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(markdown)

inline bool IsTagNameFirst(char ch) { return IsAlpha(ch); }
inline bool IsTagNameFollower(char ch) { return IsAlpha(ch) || IsDigit(ch) || ch == '.'; }

//-----------------------------------------------------------------------------
// Item
//-----------------------------------------------------------------------------
const Item::TypeNamePair Item::_typeNamePairs[] = {
	{ TYPE_None,			"none",			},
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
	{ TYPE_Comment,			"comment",		},	// text
	{ TYPE_Code,			"code",			},	// text
	{ TYPE_Entity,			"entity",		},	// text
	{ TYPE_Tag,				"tag",			},	// container and text (attributes)
	{ TYPE_HorzRule,		"hr",			},	// no-content
	{ TYPE_LineBreak,		"br",			},	// no-content
	{ TYPE_Referee,			"referee",		},	// no-content
};

Item::Item(Type type) :
	_cntRef(1), _type(type), _align(ALIGN_None),
	_indentLevel(0), _indentLevelItemBody(0), _markdownAcceptableFlag(true)
{
}

Item::Item(Type type, ItemOwner *pItemOwner) :
	_cntRef(1), _type(type), _pItemOwner(pItemOwner), _align(ALIGN_None),
	_indentLevel(0), _indentLevelItemBody(0), _markdownAcceptableFlag(true)
{
}

Item::Item(Type type, const String &text) :
	_cntRef(1), _type(type), _pText(new String(text)), _align(ALIGN_None),
	_indentLevel(0), _indentLevelItemBody(0), _markdownAcceptableFlag(true)
{
}

const char *Item::GetTypeName() const
{
	for (int i = 0; i < ArraySizeOf(_typeNamePairs); i++) {
		if (_typeNamePairs[i].type == _type) return _typeNamePairs[i].name;
	}
	return "?";
}

void Item::Print(Signal &sig, Stream &stream, int indentLevel) const
{
	for (int i = 0; i < indentLevel; i++) stream.Print(sig, "  ");
	stream.Print(sig, "<");
	stream.Print(sig, GetTypeName());
	if (_pURL.get() != nullptr) {
		stream.Print(sig, " url='");
		stream.Print(sig, _pURL->c_str());
		stream.Print(sig, "'");
	}
	if (_pTitle.get() != nullptr) {
		stream.Print(sig, " title='");
		stream.Print(sig, _pTitle->c_str());
		stream.Print(sig, "'");
	}
	if (_pRefId.get() != nullptr) {
		stream.Print(sig, " refid='");
		stream.Print(sig, _pRefId->c_str());
		stream.Print(sig, "'");
	}
	if (_pAttrs.get() != nullptr) {
		stream.Print(sig, " attrs='");
		stream.Print(sig, _pAttrs->c_str());
		stream.Print(sig, "'");
	}
	stream.Print(sig, ">");
	if (_pText.get() != nullptr) {
		stream.Print(sig, "'");
		stream.Print(sig, _pText->c_str());
		stream.Print(sig, "'");
	}
	stream.Print(sig, "\n");
	
	if (!_pItemOwner.IsNull()) {
		_pItemOwner->Print(sig, stream, indentLevel + 1);
	}
}

const char *Item::TypeToName(Type type)
{
	for (int i = 0; i < ArraySizeOf(_typeNamePairs); i++) {
		if (_typeNamePairs[i].type == type) return _typeNamePairs[i].name;
	}
	return "?";
}

Item::Type Item::NameToType(const char *name)
{
	for (int i = 0; i < ArraySizeOf(_typeNamePairs); i++) {
		if (::strcmp(_typeNamePairs[i].name, name) == 0) return _typeNamePairs[i].type;
	}
	return TYPE_None;
}

//-----------------------------------------------------------------------------
// ItemList
//-----------------------------------------------------------------------------
Item *ItemList::FindByRefId(const char *refId) const
{
	if (refId == nullptr) return nullptr;
	foreach_const (ItemList, ppItem, *this) {
		Item *pItem = *ppItem;
		if (pItem->GetRefId() != nullptr &&
					::strcasecmp(pItem->GetRefId(), refId) == 0) {
			return pItem;
		}
	}
	return nullptr;
}

size_t ItemList::CountByType(Item::Type type, bool recursiveFlag) const
{
	size_t cnt = 0;
	foreach_const (ItemList, ppItem, *this) {
		Item *pItem = *ppItem;
		if (pItem->GetType() == type) cnt++;
		if (recursiveFlag) {
			ItemOwner *pItemOwner = pItem->GetItemOwner();
			if (pItemOwner != nullptr) cnt += pItemOwner->CountByType(type, recursiveFlag);
		}
	}
	return cnt;
}

void ItemList::Print(Signal &sig, Stream &stream, int indentLevel) const
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
Document::Document() :
	_cntRef(1), _resolvedFlag(false), _decoPrecedingFlag(false),
	_iTableRow(-1), _iTableCol(0), _stat(STAT_LineTop), _iLine(0), _iCol(0), _chPrev('\0'),
	_indentLevel(0), _indentLevelTableTop(0), _headerLevel(0), _headerLevelOffset(0),
	_quoteLevel(0), _cntEmptyLine(0), _pItemOwner(new ItemOwner()), _pItemRefereeOwner(new ItemOwner())
{
	_statStack.Push(STAT_LineTop);
	_pItemRoot.reset(new Item(Item::TYPE_Root, new ItemOwner()));
	_itemStack.push_back(_pItemRoot.get());
}

bool Document::ParseStream(Signal &sig, SimpleStream &stream)
{
	enum {
		STAT_FirstRowTop,
		STAT_FirstRowBody,
		STAT_GuideRowTop,
		STAT_GuideRowBody,
		STAT_TrailingRowTop,
		STAT_TrailingRowHead,
		STAT_TrailingRowBody,
		STAT_SkipToEOL,
	} stat = STAT_FirstRowTop;
	_iLine = 0;
	_iCol = 0;
	_chPrev = '\0';
	String textPrefetch;
	String guide;
	StringList guideList;
	for (;;) {
		int chRaw;
		textPrefetch.clear();
		int nTrailingRows = 0;
		bool pipeFoundFlag = false;
		bool prefetchFlag = true;
		stat = STAT_FirstRowTop;
		int indentLevelForCodeBlock = GetIndentLevelForCodeBlock();
		int indentLevel = 0;
		_indentLevelTableTop = 0;
		while (prefetchFlag && (chRaw = stream.GetChar(sig)) >= 0) {
			char ch = static_cast<char>(static_cast<UChar>(chRaw));
			textPrefetch += ch;
			Gura_BeginPushbackRegionEx(char, 16, ch);
			if (stat == STAT_FirstRowTop) {
				if (ch == '|') {
					pipeFoundFlag = true;
					stat = STAT_FirstRowBody;
				} else if (IsEOL(ch)) {
					prefetchFlag = false;
				} else {
					pipeFoundFlag = false;
					stat = STAT_FirstRowBody;
				}
			} else if (stat == STAT_FirstRowBody) {
				if (ch == '|') {
					pipeFoundFlag = true;
				} else if (IsEOL(ch)) {
					if (pipeFoundFlag) {
						indentLevel = 0;
						stat = STAT_GuideRowTop;
					} else {
						prefetchFlag = false;
					}
				} else {
					// nothing to do 
				}
			} else if (stat == STAT_GuideRowTop) {
				if (ch == ' ') {
					indentLevel++;
				} else if (ch == '\t') {
					indentLevel += WIDTH_Tab;
				} else if (indentLevel >= indentLevelForCodeBlock) {
					Gura_PushbackEx(ch);
					stat = STAT_SkipToEOL;
				} else {
					if (ch == '|') {
						pipeFoundFlag = true;
						_indentLevelTableTop = indentLevel + 1;
					} else {
						pipeFoundFlag = false;
						Gura_PushbackEx(ch);
					}
					guideList.clear();
					guide.clear();
					stat = STAT_GuideRowBody;
				}
			} else if (stat == STAT_GuideRowBody) {
				if (ch == '|') {
					pipeFoundFlag = true;
					guideList.push_back(Strip(guide.c_str()));
					guide.clear();
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
					pipeFoundFlag = true;
					stat = STAT_TrailingRowBody;
				} else if (IsWhite(ch) || IsEOL(ch)) {
					Gura_PushbackEx(ch);
					stat = STAT_TrailingRowHead;
				} else {
					pipeFoundFlag = false;
					stat = STAT_TrailingRowBody;
				}
			} else if (stat == STAT_TrailingRowHead) {
				if (IsWhite(ch)) {
					// nothing to do
				} else if (IsEOL(ch)) {
					// detected a blank line
					prefetchFlag = false;
				} else {
					Gura_PushbackEx(ch);
					stat = STAT_TrailingRowBody;
				}
			} else if (stat == STAT_TrailingRowBody) {
				if (ch == '|') {
					pipeFoundFlag = true;
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
			Gura_EndPushbackRegionEx();
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
			FlushItem(Item::TYPE_Paragraph, false, false);
			BeginTable();
			Stat statPrev = _stat;
			_stat = STAT_LineTop;
			if (!_ParseString(sig, textPrefetch)) return false;
			EndTable();
			_stat = statPrev;
		}
	}
	return true;
}

bool Document::ParseString(Signal &sig, const char *text)
{
	SimpleStream_CStringReader stream(text);
	return ParseStream(sig, stream);
}

bool Document::_ParseString(Signal &sig, String text)
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
		if (pItemRef != nullptr) {
			const char *url = pItemRef->GetURL();
			const char *title = pItemRef->GetTitle();
			if (url != nullptr) pItemLink->SetURL(url);
			if (title != nullptr) pItemLink->SetTitle(title);
		}
	}
	_resolvedFlag = true;
}

bool Document::ParseChar(Signal &sig, char ch)
{
	Gura_BeginPushbackRegionEx(char, 16, ch);
	switch (_stat) {
	case STAT_LineTop: {
		_indentLevel = 0;
		if (!IsTableMode()) {
			Gura_PushbackEx(ch);
			_stat = STAT_LineHead;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_LineHeadTable;
		}
		break;
	}
	case STAT_LineHead: {
		if (!IsMarkdownAcceptable()) {
			// When within a tag, ignore special characters except for '<'.
			Gura_PushbackEx(ch);
			_stat = STAT_Text;
		} else if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += WIDTH_Tab;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(nullptr);
			_stat = STAT_CodeBlock;
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
			_headerLevel = 1;
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
			Gura_PushbackEx(ch);
			_stat = STAT_Text;
		}
		_decoPrecedingFlag = false;
		break;
	}
	case STAT_LineHeadTable: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += WIDTH_Tab;
		} else if (IsEOL(ch)) {
			_indentLevel = 0;
		} else {
			BeginTableRow();
			if (ch != '|' || _indentLevel >= _indentLevelTableTop) {
				Gura_PushbackEx(ch);
			}
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_LineHeadNL: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += WIDTH_Tab;
		} else if (ch == '>') {
			Gura_PushbackEx(ch);
			_stat = STAT_LineHead;
		} else {
			_quoteLevel = 0;
			AdjustBlockQuote();
			Gura_PushbackEx(ch);
			_stat = STAT_LineHead;
		}
		break;
	}
	case STAT_BlockQuote: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += WIDTH_Tab;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			AdjustBlockQuote();
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel++;
		} else {
			AdjustBlockQuote();
			Gura_PushbackEx(ch);
			_stat = STAT_LineHead;
		}
		break;
	}
	case STAT_EqualAtHead: {
		if (ch == '=') {
			_textAhead += ch;
			_stat = STAT_AtxHeader1;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Gura_PushbackEx(ch);
			_stat = STAT_AtxHeader1;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
			AppendJointSpace();
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_AsteriskAtHead: {
		if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false, false);
			_stat = STAT_UListItemPre;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
			AppendJointSpace();
			FlushText(Item::TYPE_Text, false, false);
			_statStack.Push(STAT_Text);
			Gura_PushbackEx(ch);
			_stat = STAT_Asterisk;
		}
		break;
	}
	case STAT_PlusAtHead: {
		if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false, false);
			_stat = STAT_UListItemPre;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
			AppendJointSpace();
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_HyphenAtHead: {
		if (ch == '-') {
			_textAhead += ch;
			_stat = STAT_AtxHeader2;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Gura_PushbackEx(ch);
			_stat = STAT_AtxHeader2;
		} else if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false, false);
			_stat = STAT_UListItemPre;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
			AppendJointSpace();
			_text += _textAhead;
			Gura_PushbackEx(ch);
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
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
			AppendJointSpace();
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_DigitDotAtHead: {
		if (ch == ' ' || ch == '\t') {
			_stat = STAT_OListItemPre;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
			AppendJointSpace();
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_BackquoteAtHead: {
		if (ch == '`') {
			_textAhead += ch;
			_stat = STAT_BackquoteAtHead2nd;
		} else {
			if (_decoPrecedingFlag) _text += ' ';
			AppendJointSpace();
			Gura_PushbackEx(ch);
			Gura_PushbackEx('`');
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_BackquoteAtHead2nd: {
		if (ch == '`') {
			_field.clear();
			_stat = STAT_FencedCodeBlockAttr;
		} else {
			if (_decoPrecedingFlag) _text += ' ';
			AppendJointSpace();
			Gura_PushbackEx(ch);
			Gura_PushbackEx('`');
			Gura_PushbackEx('`');
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_SetextHeaderHead: {
		if (ch == '#') {
			_headerLevel++;
		} else if (ch == ' ' || ch == '\t') {
			_stat = STAT_SetextHeaderPre;
		} else {
			_text.clear();
			Gura_PushbackEx(ch);
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_SetextHeaderPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			_text.clear();
			Gura_PushbackEx(ch);
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
			int headerLevel = _headerLevel + _headerLevelOffset;
			FlushItem(HeaderLevelToItemType(headerLevel), false, true);
			if (IsEOF(ch)) Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
			_stat = STAT_SetextHeader;
		} else {
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_AtxHeader1: {
		if (ch == '=') {
			_textAhead += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			int headerLevel = 1 + _headerLevelOffset;
			FlushItem(HeaderLevelToItemType(headerLevel), false, false);
			if (IsEOF(ch)) Gura_PushbackEx(ch);
			_stat = STAT_LineTop;
		} else {
			AppendJointSpace();
			_text += _textAhead;
			Gura_PushbackEx(ch);
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
				int headerLevel = 2 + _headerLevelOffset;
				Item *pItem = new Item(HeaderLevelToItemType(headerLevel), _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
			} else if (IsHorzRule(_textAhead.c_str())) {
				Item *pItem = new Item(Item::TYPE_HorzRule);
				pItemParent->GetItemOwner()->push_back(pItem);
			} else {
				_text += _textAhead;
			}
			if (IsEOF(ch)) Gura_PushbackEx(ch);
			_stat = STAT_LineTop;
		} else {
			AppendJointSpace();
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_UListItemPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			BeginListItem(Item::TYPE_UList);
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_OListItemPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			BeginListItem(Item::TYPE_OList);
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem: {
		if (CheckSpecialChar(ch)) {
			// nothing to do
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_indentLevel = 0;
			if (IsEOF(ch)) Gura_PushbackEx(ch);
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
			_indentLevel += WIDTH_Tab;
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel = 1;
			_stat = STAT_ListItem_BlockQuoteAtHead;
		} else if (ch == '*') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItem_AsteriskAtHead;
		} else if (ch == '+') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItem_PlusAtHead;
		} else if (ch == '-') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItem_HyphenAtHead;
		} else if (IsDigit(ch)) {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItem_DigitAtHead;
		} else if (IsEOL(ch)) {
			_indentLevel = 0;
			_stat = STAT_ListItemNL;
		} else if (IsEOF(ch)) {
			EndListItem();
			_itemStack.ClearListItem();
			Gura_PushbackEx(ch);
			_stat = STAT_LineTop;
		} else {
			UpdateIndentLevelItemBody(_indentLevel);
			_text += ' ';
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem_BlockQuoteAtHead: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += WIDTH_Tab;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel++;
		} else {
			AdjustBlockQuote();
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem_LineHead;
		}
		break;
	}
	case STAT_ListItem_AsteriskAtHead: {
		if (ch == ' ' || ch == '\t') {
			_stat = STAT_UListItemPre;
		} else {
			_text += ' ';
			FlushText(Item::TYPE_Text, false, false);
			_statStack.Push(STAT_ListItem);
			Gura_PushbackEx(ch);
			_stat = STAT_Asterisk;
		}
		break;
	}
	case STAT_ListItem_PlusAtHead: {
		if (ch == ' ' || ch == '\t') {
			_stat = STAT_UListItemPre;
		} else {
			_text += ' ';
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem_HyphenAtHead: {
		if (ch == ' ' || ch == '\t') {
			_stat = STAT_UListItemPre;
		} else {
			_text += ' ';
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem_DigitAtHead: {
		if (IsDigit(ch)) {
			_textAhead += ch;
		} else if (ch == '.') {
			_textAhead += ch;
			_stat = STAT_ListItem_DigitDotAtHead;
		} else {
			_text += ' ';
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem_DigitDotAtHead: {
		if (ch == ' ' || ch == '\t') {
			_stat = STAT_OListItemPre;
		} else {
			_text += ' ';
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += WIDTH_Tab;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndListItem();
			_itemStack.ClearListItem();
			if (IsEOF(ch)) Gura_PushbackEx(ch);
			_stat = STAT_LineTop;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(nullptr);
			_stat = STAT_CodeBlock;
		} else if (ch == '*') {
			UpdateIndentLevelItemBody(_indentLevel);
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemNL_AsteriskAtHead;
		} else if (ch == '+') {
			UpdateIndentLevelItemBody(_indentLevel);
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemNL_PlusAtHead;
		} else if (ch == '-') {
			UpdateIndentLevelItemBody(_indentLevel);
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemNL_HyphenAtHead;
		} else if (IsDigit(ch)) {
			UpdateIndentLevelItemBody(_indentLevel);
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemNL_DigitAtHead;
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			AdjustBlockQuote();
			Gura_PushbackEx(ch);
			_stat = STAT_LineTop;
		} else {
			UpdateIndentLevelItemBody(_indentLevel);
 			FlushItem(Item::TYPE_Paragraph, false, false);
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL_AsteriskAtHead: {
		if (ch == ' ' || ch == '\t') {
			_stat = STAT_UListItemPre;
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			Gura_PushbackEx(ch);
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
			FlushItem(Item::TYPE_Paragraph, false, false);
			Gura_PushbackEx(ch);
			_statStack.Push(STAT_ListItem);
			_stat = STAT_Asterisk;
		}
		break;
	}
	case STAT_ListItemNL_PlusAtHead: {
		if (ch == ' ' || ch == '\t') {
			_stat = STAT_UListItemPre;
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			Gura_PushbackEx(ch);
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
 			FlushItem(Item::TYPE_Paragraph, false, false);
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL_HyphenAtHead: {
		if (ch == ' ' || ch == '\t') {
			_stat = STAT_UListItemPre;
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			Gura_PushbackEx(ch);
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
 			FlushItem(Item::TYPE_Paragraph, false, false);
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL_DigitAtHead: {
		if (IsDigit(ch)) {
			_textAhead += ch;
		} else if (ch == '.') {
			_textAhead += ch;
			_stat = STAT_ListItemNL_DigitDotAtHead;
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			Gura_PushbackEx(ch);
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
			_text += ' ';
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemNL_DigitDotAtHead: {
		if (ch == ' ' || ch == '\t') {
			_stat = STAT_OListItemPre;
		} else if (_indentLevel <= 0) {
			EndListItem();
			_itemStack.ClearListItem();
			_stat = STAT_LineTop;
			if (!_ParseString(sig, _textAhead)) return false;
			Gura_PushbackEx(ch);
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			BeginCodeBlock(_textAhead.c_str());
			_stat = STAT_CodeBlock;
		} else {
 			FlushItem(Item::TYPE_Paragraph, false, false);
			_text += _textAhead;
			Gura_PushbackEx(ch);
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
			_indentLevel += WIDTH_Tab;
		} else if (IsEOL(ch)) {
			_cntEmptyLine++;
			_indentLevel = 0;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
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
			for (int i = 0; i < _indentLevel - GetIndentLevelForCodeBlock(); i++) _text += ' ';
			Gura_PushbackEx(ch);
			_stat = STAT_CodeBlock;
		} else if (ch == '>' && _indentLevel == 0) {
			_indentLevel = -1;
			_quoteLevel = 1;
			_stat = STAT_CodeBlockUnderBlockQuote;
		} else {
			Gura_PushbackEx(ch);
			EndCodeBlock();
			_stat = !IsWithin(Item::TYPE_ListItem)? STAT_LineTop :
				(_cntEmptyLine == 0)? STAT_ListItem_LineHead : STAT_ListItemNL;
		}
		break;
	}
	case STAT_FencedCodeBlockAttr: {
		if (IsEOL(ch) || IsEOF(ch)) {
			BeginFencedCodeBlock();
			_stat = STAT_FencedCodeBlock;
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
			_stat = STAT_FencedCodeBlock;
		}
		break;
	}
	case STAT_FencedCodeBlock_LineHead3rd: {
		if (ch == '`') {
			_stat = STAT_FencedCodeBlock_SkipToEOL;
		} else {
			_text += _textAhead;
			Gura_PushbackEx(ch);
			_stat = STAT_FencedCodeBlock;
		}
		break;
	}
	case STAT_FencedCodeBlock_SkipToEOL: {
		if (IsEOL(ch) || IsEOF(ch)) {
			EndFencedCodeBlock();
			_stat = IsWithin(Item::TYPE_ListItem)? STAT_ListItem_LineHead : STAT_LineTop;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_CodeBlockUnderBlockQuote: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += WIDTH_Tab;
		} else if (_indentLevel >= GetIndentLevelForCodeBlock()) {
			Gura_PushbackEx(ch);
			if (AdjustBlockQuote()) {
				EndCodeBlock();
				BeginCodeBlock(_textAhead.c_str());
				_stat = STAT_CodeBlock;
			} else {
				for (int i = 0; i < _indentLevel - GetIndentLevelForCodeBlock(); i++) _text += ' ';
				_stat = STAT_CodeBlock;
			}
		} else if (ch == '>') {
			_indentLevel = -1;
			_quoteLevel++;
		} else {
			Gura_PushbackEx(ch);
			EndCodeBlock();
			AdjustBlockQuote();
			_stat = STAT_LineTop;
		}
		break;
	}
	case STAT_Backquote: {
		if (ch == '`') {
			_stat = STAT_CodeEsc;
		} else {
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
				_stat = STAT_SkipWhiteAfterPipe;
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
			} else if (IsMarkdownAcceptable()) {
				if (EndsWith(_text.c_str(), "  ", false) != nullptr) {
					FlushText(Item::TYPE_Text, false, true);
					Item *pItem = new Item(Item::TYPE_LineBreak);
					_pItemOwner->push_back(pItem);
				}
				_stat = STAT_LineTop;
			} else {
				_text += ch;
			}
		} else if (IsEOF(ch)) {
			Gura_PushbackEx(ch);
			_stat = STAT_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_SkipWhiteAfterPipe: {
		if (IsWhite(ch)) {
			// nothing to do
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_Text;
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
			Gura_PushbackEx(ch);
			_stat = _statStack.Pop();
		} else {
			BeginDecoration(Item::TYPE_Emphasis);
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
			_stat = _statStack.Pop();
		} else {
			FlushText(Item::TYPE_Text, true, true);
			BeginDecoration(Item::TYPE_Emphasis);
			_statStack.Push(STAT_AsteriskStrong);
			Gura_PushbackEx(ch);
			_stat = STAT_AsteriskEmphasis;
		}
		break;
	}
	case STAT_Underscore: {
		if (ch == '_') {
			BeginDecoration(Item::TYPE_Strong);
			_stat = STAT_UnderscoreStrong;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Gura_PushbackEx(ch);
			_stat = _statStack.Pop();
		} else {
			BeginDecoration(Item::TYPE_Emphasis);
			Gura_PushbackEx(ch);
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
			_stat = STAT_UnderscoreEmphasisPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			CancelDecoration("_");
			Gura_PushbackEx(ch);
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_UnderscoreEmphasisPost: {
		if (IsWordChar(ch)) {
			_text += '_';
			Gura_PushbackEx(ch);
			_stat = STAT_UnderscoreEmphasis;
		} else {
			EndDecoration();
			Gura_PushbackEx(ch);
			_stat = STAT_DecorationPost;
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
			Gura_PushbackEx(ch);
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_UnderscoreStrongEnd: {
		if (ch == '_') {
			_stat = STAT_UnderscoreStrongPost;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			ReplaceDecoration(Item::TYPE_Emphasis, "_");
			Gura_PushbackEx(ch);
			_stat = _statStack.Pop();
		} else {
			FlushText(Item::TYPE_Text, true, true);
			BeginDecoration(Item::TYPE_Emphasis);
			_statStack.Push(STAT_UnderscoreStrong);
			Gura_PushbackEx(ch);
			_stat = STAT_UnderscoreEmphasis;
		}
		break;
	}
	case STAT_UnderscoreStrongPost: {
		if (IsWordChar(ch)) {
			_text += "__";
			Gura_PushbackEx(ch);
			_stat = STAT_UnderscoreStrong;
		} else {
			EndDecoration();
			Gura_PushbackEx(ch);
			_stat = STAT_DecorationPost;
		}
		break;
	}
	case STAT_Tilda: {
		if (ch == '~') {
			BeginDecoration(Item::TYPE_Strike);
			_stat = STAT_TildaStrike;
		} else {
			_text += '~';
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_DecorationPost: {
		_stat = _statStack.Pop();
		if (_stat == STAT_Text && IsEOL(ch)) {
			_decoPrecedingFlag = true;
		}
		Gura_PushbackEx(ch);
		break;
	}
	case STAT_Entity: {
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
			Gura_PushbackEx(ch);
			_stat = _statStack.Pop();
		}
		break;
	}
	case STAT_AngleBracketFirst: {
		if (ch == '!') {
			_stat = STAT_CommentStartFirst;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_AngleBracket;
		}
		break;
	}
	case STAT_CommentStartFirst: {
		if (ch == '-') {
			_stat = STAT_CommentStartSecond;
		} else {
			Gura_PushbackEx(ch);
			Gura_PushbackEx('!');
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
			Gura_PushbackEx(ch);
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
			FlushText(Item::TYPE_Comment, false, false);
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
			bool markdownAcceptableFlag = false;
			if (IsLink(_field.c_str())) {
				FlushText(Item::TYPE_Text, false, false);
				Item *pItemLink = new Item(Item::TYPE_Link, new ItemOwner());
				pItemLink->SetURL(_field);
				_pItemOwner->push_back(pItemLink);
				do {
					Item *pItem = new Item(Item::TYPE_Text, _field);
					pItemLink->GetItemOwner()->push_back(pItem);
				} while (0);
			} else if (IsBeginTag(_field.c_str(), tagName, attrs, closedFlag, markdownAcceptableFlag)) {
				const char *p = nullptr;
				int headerLevelShift = 0;
				if ((p = StartsWith(tagName.c_str(), "gura.headerdown", 0, true)) != nullptr) {
					headerLevelShift = +1;
				} else if ((p = StartsWith(tagName.c_str(), "gura.headerup", 0, true)) != nullptr) {
					headerLevelShift = -1;
				}
				if (p == nullptr) {
					BeginTag(tagName.c_str(), attrs.c_str(), closedFlag, markdownAcceptableFlag);
				} else {
					if (!closedFlag) {
						sig.SetError(ERR_FormatError, "the tag must be used as a single one.");
						return false;
					}
					if (*p != '\0') {
						char *pEnd = nullptr;
						ULong nMultiply = ::strtoul(p, &pEnd, 10);
						if (*pEnd != '\0' || nMultiply > 5) {
							sig.SetError(ERR_FormatError, "invalid tag name");
							return false;
						}
						headerLevelShift *= nMultiply;
					}
					_headerLevelOffset += headerLevelShift;
				}
			} else if (IsEndTag(_field.c_str(), tagName)) {
				if (!EndTag(tagName.c_str())) {
					sig.SetError(ERR_FormatError, "unbalanced tags at line %d", _iLine + 1);
					return false;
				}
			} else {
				_text += _textAhead;
				_text += ch;
			}
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
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
			Gura_PushbackEx(ch);
			_stat = STAT_LineTop;
		} else {
			_text += _textAhead;
			Gura_PushbackEx(ch);
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
	Gura_EndPushbackRegionEx();
	if (IsEOL(ch)) {
		_iLine++;
		_iCol = 0;
	} else if (ch == '\t') {
		_iCol = (_iCol / WIDTH_Tab) * WIDTH_Tab + WIDTH_Tab;
	} else {
		_iCol++;
	}
	_chPrev = ch;
	return true;
}

bool Document::CheckSpecialChar(char ch)
{
	if (ch == '\\') {
		if (!IsMarkdownAcceptable()) return false;
		_statStack.Push(_stat);
		_stat = STAT_Escape;
		return true;
	} else if (ch == '`') {
		if (!IsMarkdownAcceptable()) return false;
		FlushText(Item::TYPE_Text, false, false);
		_statStack.Push(_stat);
		_stat = STAT_Backquote;
		return true;
	} else if (ch == '*') {
		if (!IsMarkdownAcceptable()) return false;
		FlushText(Item::TYPE_Text, false, false);
		_statStack.Push(_stat);
		_stat = STAT_Asterisk;
		return true;
	} else if (ch == '_' && !IsWordChar(_chPrev)) {
		if (!IsMarkdownAcceptable()) return false;
		FlushText(Item::TYPE_Text, false, false);
		_statStack.Push(_stat);
		_stat = STAT_Underscore;
		return true;
	} else if (ch == '~') {
		if (!IsMarkdownAcceptable()) return false;
		FlushText(Item::TYPE_Text, false, false);
		_statStack.Push(_stat);
		_stat = STAT_Tilda;
		return true;
	} else if (ch == '&') {
		_textAhead.clear();
		_field.clear();
		_textAhead += ch;
		_statStack.Push(_stat);
		_stat = STAT_Entity;
		return true;
	} else if (ch == '<') {
		_textAhead.clear();
		_field.clear();
		_textAhead += ch;
		_statStack.Push(_stat);
		_stat = STAT_AngleBracketFirst;
		return true;
	} else if (ch == '[') {
		if (!IsMarkdownAcceptable()) return false;
		_pItemLink.reset(new Item(Item::TYPE_Link, new ItemOwner()));
		_textAhead.clear();
		_field.clear();
		_textAhead += ch;
		_statStack.Push(_stat);
		_stat = STAT_LinkText;
		return true;
	} else if (ch == '!') {
		if (!IsMarkdownAcceptable()) return false;
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
}

void Document::EndTable()
{
	while (!_itemStack.empty()) {
		Item *pItem = _itemStack.back();
		_itemStack.pop_back();
		if (pItem->IsTag() && ::strcmp(pItem->GetText(), "table") == 0) break;
	}
	_iTableRow = -1;
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
	for (int i = 0; i < _indentLevel - GetIndentLevelForCodeBlock(); i++) _text += ' ';
	if (textInit != nullptr) _text += textInit;
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_CodeBlock, new ItemOwner());
		pItem->SetIndentLevel(_indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} while (0);
}

void Document::EndCodeBlock()
{
	_itemStack.pop_back();
}

void Document::BeginFencedCodeBlock()
{
	FlushItem(Item::TYPE_Paragraph, false, false);
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_CodeBlock, new ItemOwner());
		pItem->SetIndentLevel(_indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} while (0);
}

void Document::EndFencedCodeBlock()
{
	_itemStack.pop_back();
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
		Item *pItem = new Item(type, new ItemOwner());
		pItem->SetIndentLevel(_indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} else if (pItemParent->GetType() != type) {
		_itemStack.pop_back();
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(type, new ItemOwner());
		pItem->SetIndentLevel(_indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	}
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_ListItem, new ItemOwner());
		pItem->SetIndentLevel(_indentLevel);
		pItem->SetIndentLevelItemBody(_iCol);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} while (0);
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

// Marks the beginning of HTML tag.
void Document::BeginTag(const char *tagName, const char *attrs, bool closedFlag, bool markdownAcceptableFlag)
{
	FlushText(Item::TYPE_Text, false, false);
	Item *pItem = new Item(Item::TYPE_Tag);
	pItem->SetMarkdownAcceptableFlag(markdownAcceptableFlag);
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

// Marks the ending of HTML tag.
bool Document::EndTag(const char *tagName)
{
	if (!IsWithinTag() || ::strcmp(_itemStackTag.back()->GetText(), tagName) != 0) {
		return false;
	}
	FlushText(Item::TYPE_Text, false, false);
	_pItemOwner.reset(_itemOwnerStack.Pop());
	_itemStackTag.pop_back();
	return true;
}

int Document::GetIndentLevel() const
{
	foreach_const_reverse (ItemStack, ppItem, _itemStack) {
		const Item *pItem = *ppItem;
		if (pItem->IsListItem()) {
			return pItem->GetIndentLevelItemBody();
		}
	}
	return 0;
}

int Document::GetIndentLevelForCodeBlock() const
{
	return GetIndentLevel() + INDENT_CodeBlock;
}

void Document::UpdateIndentLevelItemBody(int indentLevelItemBody)
{
	foreach_reverse (ItemStack, ppItem, _itemStack) {
		Item *pItem = *ppItem;
		if (pItem->IsListItem()) {
			pItem->SetIndentLevelItemBody(indentLevelItemBody);
			break;
		}
	}
}

bool Document::IsWithin(Item::Type type) const
{
	foreach_const_reverse (ItemStack, ppItem, _itemStack) {
		const Item *pItem = *ppItem;
		if (pItem->GetType() == type) return true;
	}
	return false;
}

Item::Type Document::HeaderLevelToItemType(int headerLevel)
{
	return
		(headerLevel <= 1)? Item::TYPE_Header1 :
		(headerLevel == 2)? Item::TYPE_Header2 :
		(headerLevel == 3)? Item::TYPE_Header3 :
		(headerLevel == 4)? Item::TYPE_Header4 :
		(headerLevel == 5)? Item::TYPE_Header5 :
		(headerLevel == 6)? Item::TYPE_Header6 :
		Item::TYPE_Header6;
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

bool Document::IsBeginTag(const char *text, String &tagName,
						  String &attrs, bool &closedFlag, bool &markdownAcceptableFlag)
{
	enum Stat {
		STAT_Begin,
		STAT_AfterSpecialChar,
		STAT_TagName,
		STAT_AttrsPre,
		STAT_Attrs,
		STAT_Slash,
	} stat = STAT_Begin;
	tagName.clear();
	attrs.clear();
	closedFlag = false;
	markdownAcceptableFlag = false;
	for (const char *p = text; ; p++) {
		char ch = *p;
		switch (stat) {
		case STAT_Begin: {
			if (IsTagNameFirst(ch)) {
				tagName += ch;
				stat = STAT_TagName;
			} else if (ch == '@') {
				// A special form of tag <@tag> within which MarkDown format is acceptable.
				markdownAcceptableFlag = true;
				stat = STAT_AfterSpecialChar;
			} else {
				return false;
			}
			break;
		}
		case STAT_AfterSpecialChar: {
			if (IsTagNameFirst(ch)) {
				tagName += ch;
				stat = STAT_TagName;
			} else {
				return false;
			}
			break;
		}
		case STAT_TagName: {
			if (IsTagNameFollower(ch)) {
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
		STAT_AfterSpecialChar,
		STAT_TagName,
	} stat = STAT_Begin;
	tagName.clear();
	for (const char *p = text; ; p++) {
		char ch = *p;
		switch (stat) {
		case STAT_Begin: {
			if (ch == '/') {
				stat = STAT_TagNameFirst;
			} else {
				return false;
			}
			break;
		}
		case STAT_TagNameFirst: {
			if (IsTagNameFirst(ch)) {
				tagName += ch;
				stat = STAT_TagName;
			} else if (ch == '@') {
				// A special form of tag: </@tag>.
				stat = STAT_AfterSpecialChar;
			} else {
				return false;
			}
			break;
		}
		case STAT_AfterSpecialChar: {
			if (IsTagNameFirst(ch)) {
				tagName += ch;
				stat = STAT_TagName;
			} else {
				return false;
			}
			break;
		}
		case STAT_TagName: {
			if (IsTagNameFollower(ch)) {
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
	return nullptr;
}

bool Object_document::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(refs));
	symbols.insert(Gura_UserSymbol(root));
	return true;
}

Value Object_document::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	return Value::Nil;
}

Value Object_document::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Nil;
}

String Object_document::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<markdown.document";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Constructor for markdown.document
//-----------------------------------------------------------------------------
// markdown.document(stream?:stream:r) {block?}
Gura_DeclareFunction(document)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	SetClassToConstruct(Gura_UserClass(document));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an instance of `markdown.document`.\n"
		"If `stream` is specified, the content of the instance shall be initialized\n"
		"with the result of parsing the stream.\n"
	);
}

Gura_ImplementFunction(document)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Document> pDocument(new Document());
	if (arg.Is_stream(0)) {
		if (!pDocument->ParseStream(sig, arg.GetStream(0))) return Value::Nil;
	}
	AutoPtr<Object_document> pObj(new Object_document(pDocument.release()));
	return ReturnValue(env, arg, Value(pObj.release()));
}

//-----------------------------------------------------------------------------
// Gura interfaces for markdown.document
//-----------------------------------------------------------------------------
// markdown.document#countitem(type:symbol)
Gura_DeclareMethod(document, countitem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "type", VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"Count the number of items of the specified type.");
}

Gura_ImplementMethod(document, countitem)
{
	Document *pDocument = Object_document::GetObjectThis(arg)->GetDocument();
	const Symbol *pSymbol = arg.GetSymbol(0);
	Item::Type type = Item::NameToType(pSymbol->GetName());
	if (type == Item::TYPE_None) {
		env.SetError(ERR_ValueError, "invalid symbol for item type: `%s", pSymbol->GetName());
		return Value::Nil;
	}
	size_t cnt = pDocument->GetItemRoot()->GetItemOwner()->CountByType(type, true);
	return Value(cnt);
}

// markdown.document#parse(str:string):void
Gura_DeclareMethod(document, parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Parses a Markdown text in a string.");
}

Gura_ImplementMethod(document, parse)
{
	Signal &sig = env.GetSignal();
	Document *pDocument = Object_document::GetObjectThis(arg)->GetDocument();
	pDocument->ParseString(sig, arg.GetString(0));
	return Value::Nil;
}

// markdown.document#read(stream:stream:r):void
Gura_DeclareMethod(document, read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en),
		"Parses a Markdown text from a stream.");
}

Gura_ImplementMethod(document, read)
{
	Signal &sig = env.GetSignal();
	Document *pDocument = Object_document::GetObjectThis(arg)->GetDocument();
	pDocument->ParseStream(sig, arg.GetStream(0));
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for markdown.document
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(document)
{
	Gura_AssignFunction(document);
	Gura_AssignMethod(document, countitem);
	Gura_AssignMethod(document, parse);
	Gura_AssignMethod(document, read);
}

//-----------------------------------------------------------------------------
// Object_item
//-----------------------------------------------------------------------------
Object *Object_item::Clone() const
{
	return nullptr;
}

bool Object_item::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(text));
	symbols.insert(Gura_UserSymbol(children));
	symbols.insert(Gura_UserSymbol(url));
	symbols.insert(Gura_UserSymbol(title));
	symbols.insert(Gura_UserSymbol(attrs));
	symbols.insert(Gura_UserSymbol(align));
	return true;
}

Value Object_item::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		return Value(Symbol::Add(_pItem->GetTypeName()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(text))) {
		const char *text = _pItem->GetText();
		if (text == nullptr) return Value::Nil;
		return Value(text);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(children))) {
		const ItemOwner *pItemOwner = _pItem->GetItemOwner();
		if (pItemOwner == nullptr) return Value::Nil;
		Iterator *pIterator = new Iterator_item(pItemOwner->Reference());
		return Value(new Object_iterator(env, pIterator));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(url))) {
		const char *url = _pItem->GetURL();
		if (url == nullptr) return Value::Nil;
		return Value(url);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(title))) {
		const char *title = _pItem->GetTitle();
		if (title == nullptr) return Value::Nil;
		return Value(title);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(attrs))) {
		const char *attrs = _pItem->GetAttrs();
		if (attrs == nullptr) return Value::Nil;
		return Value(attrs);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(align))) {
		Align align = _pItem->GetAlign();
		return Value(
			(align == ALIGN_Left)? Gura_Symbol(left) :
			(align == ALIGN_Center)? Gura_Symbol(center) :
			(align == ALIGN_Right)? Gura_Symbol(right) : Gura_Symbol(none));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_item::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Nil;
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
// markdown.item#countdescendant(type:symbol)
Gura_DeclareMethod(item, countdescendant)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "type", VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"Count the number of descendant items of the specified type.");
}

Gura_ImplementMethod(item, countdescendant)
{
	Item *pItem = Object_item::GetObjectThis(arg)->GetItem();
	const Symbol *pSymbol = arg.GetSymbol(0);
	Item::Type type = Item::NameToType(pSymbol->GetName());
	if (type == Item::TYPE_None) {
		env.SetError(ERR_ValueError, "invalid symbol for item type: `%s", pSymbol->GetName());
		return Value::Nil;
	}
	const ItemOwner *pItemOwner = pItem->GetItemOwner();
	size_t cnt = (pItemOwner == nullptr)? 0 : pItemOwner->CountByType(type, true);
	return Value(cnt);
}

// markdown.item#print(indent?:number):void
Gura_DeclareMethod(item, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Prints structured content of the item.\n"
		"Argument `indent` specifies an indentation level and is set to zero when omitted.\n");
}

Gura_ImplementMethod(item, print)
{
	Signal &sig = env.GetSignal();
	Item *pItem = Object_item::GetObjectThis(arg)->GetItem();
	int indentLevel = arg.Is_number(0)? arg.GetInt(0) : 0;
	pItem->Print(sig, *env.GetConsole(), indentLevel);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for markdown.item
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(item)
{
	Gura_AssignValue(item, Value(Reference()));
	Gura_AssignMethod(item, countdescendant);
	Gura_AssignMethod(item, print);
}

//-----------------------------------------------------------------------------
// Implementation of operators
//-----------------------------------------------------------------------------
// operator <<
Gura_ImplementBinaryOperator(Shl, document, string)
{
	Signal &sig = env.GetSignal();
	Document *pDocument = Object_document::GetObject(valueLeft)->GetDocument();
	const char *text = valueRight.GetString();
	if (!pDocument->ParseString(sig, text)) return Value::Nil;
	return valueLeft;
}

//-----------------------------------------------------------------------------
// Iterator_item
//-----------------------------------------------------------------------------
Iterator_item::Iterator_item(ItemOwner *pItemOwner) :
						Iterator(Finite), _idxItem(0), _pItemOwner(pItemOwner)
{
}

Iterator *Iterator_item::GetSource()
{
	return nullptr;
}

bool Iterator_item::DoNext(Environment &env, Value &value)
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
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

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
	// class preparation
	Gura_PrepareUserClass(document);
	Gura_PrepareUserClass(item);
	// operator assignment
	Gura_AssignBinaryOperator(Shl, document, string);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(markdown, markdown)

Gura_RegisterModule(markdown)
