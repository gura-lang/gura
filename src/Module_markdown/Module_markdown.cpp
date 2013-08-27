//-----------------------------------------------------------------------------
// Gura markdown module
//-----------------------------------------------------------------------------
#include "Module_markdown.h"

Gura_BeginModule(markdown)

//-----------------------------------------------------------------------------
// Item
//-----------------------------------------------------------------------------
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
		{ TYPE_Root,			"Root",				},	// container
		{ TYPE_Header1,			"Header1",			},	// container
		{ TYPE_Header2,			"Header2",			},	// container
		{ TYPE_Paragraph,		"Paragraph",		},	// container
		{ TYPE_Normal,			"Normal",			},	// text
		{ TYPE_Emphasis,		"Emphasis",			},	// text
		{ TYPE_Strong,			"Strong",			},	// text
		{ TYPE_InlineCode,		"InlineCode",		},	// text
		{ TYPE_BlockCode,		"BlockCode",		},	// container
		{ TYPE_OList,			"OList",			},	// container
		{ TYPE_UList,			"UList",			},	// container
		{ TYPE_ListItem,		"ListItem",			},	// container
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].type == _type) return tbl[i].name;
	}
	return "";
}

void Item::Print(int indentLevel) const
{
	if (!_pItemOwner.IsNull()) {
		::printf("%*s[%s]\n", indentLevel * 2, "", GetTypeName());
		_pItemOwner->Print(indentLevel + 1);
	}
	if (_pText.get() != NULL) {
		::printf("%*s[%s]'%s'\n", indentLevel * 2, "", GetTypeName(), GetText());
	}
}

//-----------------------------------------------------------------------------
// ItemList
//-----------------------------------------------------------------------------
void ItemList::Print(int indentLevel) const
{
	foreach_const (ItemList, ppItem, *this) {
		const Item *pItem = *ppItem;
		pItem->Print(indentLevel);
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
// Parser
//-----------------------------------------------------------------------------
Parser::Parser() : _stat(STAT_LineTop), _statRtn(STAT_LineTop),
											_indentLevel(0), _pItemOwner(NULL)
{
	_pItemRoot.reset(new Item(Item::TYPE_Root, new ItemOwner()));
	_pItemOwner = new ItemOwner();
	_itemStack.push_back(_pItemRoot.get());
}

bool Parser::ParseStream(Signal sig, Stream &stream)
{
	for (;;) {
		int chRaw = stream.GetChar(sig);
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		if (!ParseChar(sig, ch)) return false;
		if (chRaw < 0) break;
	}
}

bool Parser::ParseChar(Signal sig, char ch)
{
	bool continueFlag = false;
	do 	{
	continueFlag = false;
	switch (_stat) {
	case STAT_LineTop: {
		_indentLevel = 0;
		continueFlag = true;
		_stat = STAT_LineHead;
		break;
	}
	case STAT_LineHead: {
		if (ch == ' ' ) {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (ch == '=') {
			_textAdd.clear();
			_textAdd += ch;
			_stat = STAT_EqualFirst;
		} else if (ch == '-') {
			_textAdd.clear();
			_textAdd += ch;
			_stat = STAT_HyphenFirst;
		} else if (IsDigit(ch)) {
			continueFlag = true;
			_stat = STAT_Digit;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner);
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner = NULL;
				if (IsEOL(ch)) _pItemOwner = new ItemOwner();
			}
		} else {
			if (!_text.empty()) _text += ' ';
			continueFlag = true;
			_stat = STAT_Normal;
		}
		break;
	}
	case STAT_EqualFirst: {
		if (ch == '=') {
			_textAdd += ch;
			_stat = STAT_Header1;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			if (!_text.empty()) _text += ' ';
			_text += _textAdd;
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAdd;
			_text += ch;
			_stat = STAT_Normal;
		}
		break;
	}
	case STAT_HyphenFirst: {
		if (ch == '-') {
			_textAdd += ch;
			_stat = STAT_Header2;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			if (!_text.empty()) _text += ' ';
			_text += _textAdd;
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else if (ch == ' ' || ch == '\t') {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner);
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner = new ItemOwner();
			}
			continueFlag = true;
			_stat = STAT_UListItemPre;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAdd;
			_text += ch;
			_stat = STAT_Normal;
		}
		break;
	}
	case STAT_Header1: {
		if (ch == '=') {
			_textAdd += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_Header1, _pItemOwner);
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner = new ItemOwner();
			}
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAdd;
			_text += ch;
			_stat = STAT_Normal;
		}
		break;
	}
	case STAT_Header2: {
		if (ch == '-') {
			_textAdd += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_Header2, _pItemOwner);
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner = new ItemOwner();
			}
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAdd;
			_text += ch;
			_stat = STAT_Normal;
		}
		break;
	}
	case STAT_Digit: {
		if (IsDigit(ch)) {
			_text += ch;
		} else if (ch == '.') {
			_text.clear();
			_stat = STAT_OListItemPre;
		} else {
			_stat = STAT_Normal;
		}
		break;
	}
	case STAT_UListItemPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			Item *pItemParent = _itemStack.back();
			if (pItemParent->GetType() == Item::TYPE_UList) {
				while (_indentLevel < pItemParent->GetIndentLevel()) {
					_itemStack.pop_back();
					pItemParent = _itemStack.back();
				}
				if (_indentLevel > pItemParent->GetIndentLevel()) {
					Item *pItem = new Item(Item::TYPE_UList, new ItemOwner(), _indentLevel);
					pItemParent->GetItemOwner()->push_back(pItem);
					_itemStack.push_back(pItem);
				}
			} else {
				Item *pItem = new Item(Item::TYPE_UList, new ItemOwner(), _indentLevel);
				pItemParent->GetItemOwner()->push_back(pItem);
				_itemStack.push_back(pItem);
			}
			continueFlag = true;
			_stat = STAT_UListItem;
		}
		break;
	}
	case STAT_UListItem: {
		if (ch == '*') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_statRtn = _stat;
			_stat = STAT_EmphasisPre;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_indentLevel = 0;
			continueFlag = IsEOF(ch);
			_stat = STAT_UListItemPost;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_UListItemPost: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (ch == '-' || IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_ListItem, _pItemOwner);
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner = new ItemOwner();
			}
			if (ch == '-') {
				_stat = STAT_UListItemPre;
			} else {
				ItemStack::iterator ppItem = _itemStack.begin();
				foreach (ItemStack, ppItem, _itemStack) {
					Item *pItem = *ppItem;
					if (pItem->IsList()) {
						_itemStack.erase(ppItem, _itemStack.end());
						break;
					}
				}
				continueFlag = IsEOF(ch);
				_stat = STAT_LineTop;
			}
		} else {
			_text += ' ';
			_text += ch;
			_stat = STAT_UListItem;
		}
		break;
	}
	case STAT_OListItemPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			Item *pItemParent = _itemStack.back();
			if (pItemParent->GetType() == Item::TYPE_OList) {
				// nothing to do
			} else {
				Item *pItem = new Item(Item::TYPE_OList, new ItemOwner(), _indentLevel);
				pItemParent->GetItemOwner()->push_back(pItem);
				_itemStack.push_back(pItem);
			}
			continueFlag = true;
			_stat = STAT_OListItem;
		}
		break;
	}
	case STAT_OListItem: {
		if (ch == '*') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_statRtn = _stat;
			_stat = STAT_EmphasisPre;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_indentLevel = 0;
			continueFlag = IsEOF(ch);
			_stat = STAT_OListItemPost;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_OListItemPost: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (IsDigit(ch)) {
			_textAdd.clear();
			continueFlag = true;
			_stat = STAT_OListItemPost_Digit;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_ListItem, _pItemOwner);
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner = new ItemOwner();
			}
			_itemStack.pop_back();
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			_text += ' ';
			_text += ch;
			_stat = STAT_OListItem;
		}
		break;
	}
	case STAT_OListItemPost_Digit: {
		if (IsDigit(ch)) {
			_textAdd += ch;
		} else if (ch == '.') {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_ListItem, _pItemOwner);
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner = new ItemOwner();
			}
			_stat = STAT_OListItemPre;
		} else {
			_text += ' ';
			_text += _textAdd;
			_stat = STAT_OListItem;
		}
		break;
	}
	case STAT_Normal: {
		if (ch == '*') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_statRtn = _stat;
			_stat = STAT_EmphasisPre;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_EmphasisPre: {
		if (ch == '*') {
			_stat = STAT_Strong;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = _statRtn;
		} else {
			continueFlag = true;
			_stat = STAT_Emphasis;
		}
		break;
	}
	case STAT_Emphasis: {
		if (ch == '*') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Emphasis, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_stat = _statRtn;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Emphasis, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			continueFlag = true;
			_stat = _statRtn;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_Strong: {
		if (ch == '*') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Strong, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_stat = STAT_StrongEnd;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Strong, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			continueFlag = true;
			_stat = _statRtn;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_StrongEnd: {
		if (ch == '*') {
			_stat = _statRtn;
		} else {
			continueFlag = true;
			_stat = _statRtn;
		}
		break;
	}
	}
	} while (continueFlag);
	return true;
}

//-----------------------------------------------------------------------------
// Gura module functions: markdown
//-----------------------------------------------------------------------------
// markdown.parse(stream:stream)
Gura_DeclareFunction(parse)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
}

Gura_ImplementFunction(parse)
{
	Parser parser;
	Stream &stream = args.GetStream(0);
	parser.ParseStream(sig, stream);
	parser.GetItemRoot()->Print(0);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(parse);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(markdown, markdown)

Gura_RegisterModule(markdown)
