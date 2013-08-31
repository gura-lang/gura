//-----------------------------------------------------------------------------
// Gura markdown module
//-----------------------------------------------------------------------------
#include "Module_markdown.h"

Gura_BeginModule(markdown)

AutoPtr<Function> _pFunc_Presenter;

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
		{ TYPE_Root,			"root",		},	// container
		{ TYPE_Header1,			"h1",		},	// container
		{ TYPE_Header2,			"h2",		},	// container
		{ TYPE_Header3,			"h3",		},	// container
		{ TYPE_Header4,			"h4",		},	// container
		{ TYPE_Header5,			"h5",		},	// container
		{ TYPE_Header6,			"h6",		},	// container
		{ TYPE_Paragraph,		"p",		},	// container
		{ TYPE_Normal,			"normal",	},	// text
		{ TYPE_Emphasis,		"em",		},	// text
		{ TYPE_Strong,			"strong",	},	// text
		{ TYPE_InlineCode,		"code",		},	// text
		{ TYPE_BlockCode,		"pre",		},	// container
		{ TYPE_OList,			"ol",		},	// container
		{ TYPE_UList,			"ul",		},	// container
		{ TYPE_ListItem,		"li",		},	// container
		{ TYPE_Line,			"line",		},	// container
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].type == _type) return tbl[i].name;
	}
	return "?";
}

void Item::Print(int indentLevel) const
{
	const char *typeName = GetTypeName();
	if (_pText.get() == NULL) {
		::printf("%*s<%s>\n", indentLevel * 2, "", typeName);
	} else {
		::printf("%*s<%s>'%s'\n", indentLevel * 2, "", typeName, GetText());
	}
	if (!_pItemOwner.IsNull()) {
		_pItemOwner->Print(indentLevel + 1);
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
// Document
//-----------------------------------------------------------------------------
Document::Document() : _cntRef(1), _stat(STAT_LineTop), _statRtn(STAT_LineTop),
								_indentLevel(0), _pItemOwner(new ItemOwner())
{
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
	SimpleStream_CString stream(text);
	return ParseStream(sig, stream);
}

bool Document::ParseChar(Signal sig, char ch)
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
		if (ch == ' ') {
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
				Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
			}
		} else if (_indentLevel < 4) {
			if (!_text.empty()) _text += ' ';
			continueFlag = true;
			_stat = STAT_Normal;
		} else {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
			}
			do {
				Item *pItem = new Item(Item::TYPE_BlockCode, new ItemOwner(), _indentLevel);
				pItemParent->GetItemOwner()->push_back(pItem);
				_itemStack.push_back(pItem);
			} while (0);
			_text += ch;
			_stat = STAT_BlockCode;
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
		} else if (_indentLevel < 4) {
			if (!_text.empty()) _text += ' ';
			_text += _textAdd;
			_text += ch;
			_stat = STAT_Normal;
		} else {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
			}
			_text = _textAdd;
			_text += ch;
			do {
				Item *pItem = new Item(Item::TYPE_BlockCode, new ItemOwner(), _indentLevel);
				pItemParent->GetItemOwner()->push_back(pItem);
				_itemStack.push_back(pItem);
			} while (0);
			_stat = STAT_BlockCode;
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
				Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
			}
			continueFlag = true;
			_stat = STAT_UListItemPre;
		} else if (_indentLevel < 4) {
			if (!_text.empty()) _text += ' ';
			_text += _textAdd;
			_text += ch;
			_stat = STAT_Normal;
		} else {
			Item *pItemParent = _itemStack.back();
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
			}
			_text = _textAdd;
			_text += ch;
			do {
				Item *pItem = new Item(Item::TYPE_BlockCode, new ItemOwner(), _indentLevel);
				pItemParent->GetItemOwner()->push_back(pItem);
				_itemStack.push_back(pItem);
			} while (0);
			_stat = STAT_BlockCode;
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
				Item *pItem = new Item(Item::TYPE_Header1, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
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
				Item *pItem = new Item(Item::TYPE_Header2, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
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
		if (ch == '`') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_statRtn = _stat;
			_stat = STAT_InlineCode;
		} else if (ch == '*') {
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
				Item *pItem = new Item(Item::TYPE_ListItem, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
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
		if (ch == '`') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_statRtn = _stat;
			_stat = STAT_InlineCode;
		} else if (ch == '*') {
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
				Item *pItem = new Item(Item::TYPE_ListItem, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
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
				Item *pItem = new Item(Item::TYPE_ListItem, _pItemOwner.release());
				pItemParent->GetItemOwner()->push_back(pItem);
				_pItemOwner.reset(new ItemOwner());
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
		if (ch == '`') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_statRtn = _stat;
			_stat = STAT_InlineCode;
		} else if (ch == '*') {
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
	case STAT_BlockCode: {
		if (ch == '`') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_statRtn = _stat;
			_stat = STAT_InlineCode;
		} else if (ch == '*') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_statRtn = _stat;
			_stat = STAT_EmphasisPre;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			Item *pItemParent = _itemStack.back();
			do {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
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
			_stat = STAT_BlockCode_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_BlockCode_LineTop: {
		if (ch == ' ' || ch == '\t') {
			_indentLevel += (ch == ' ')? 1 : 4;
			if (_indentLevel >= 4) {
				_stat = STAT_BlockCode;
			}
		} else {
			_itemStack.pop_back();
			continueFlag = true;
			_stat = STAT_LineTop;
		}
		break;
	}
	case STAT_InlineCode: {
		if (ch == '`') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_InlineCode, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_stat = _statRtn;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_InlineCode, _text);
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
	return true;
}

Value Object_document::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(root))) {
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

String Object_document::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<markdown.document";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for markdown.document
//-----------------------------------------------------------------------------
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
	const Item *pItem = Object_document::GetThisObj(args)->GetDocument()->GetItemRoot();
	pItem->Print(0);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for markdown.document
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(document)
{
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
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_item::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

String Object_item::ToString(Signal sig, bool exprFlag)
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
	pItem->Print(0);
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
	if (args.IsStream(0)) {
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
	"The function is specified as a block that takes block parameters `|title:string, item:markdown.item|`.\n"
	);
}

Gura_ImplementFunction(setpresenter)
{
	const Function *pFuncBlock =
						args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Null;
	_pFunc_Presenter.reset(pFuncBlock->Reference());
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

String Iterator_item::ToString(Signal sig) const
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
	if (_pFunc_Presenter.IsNull()) {
		sig.SetError(ERR_FormatError, "presenter function is not registered");
		return false;
	}
	ValueList valListArg;
	if (title == NULL) {
		valListArg.push_back(Value::Null);
	} else {
		valListArg.push_back(Value(env, title));
	}
	if (pHelp == NULL) {
		valListArg.push_back(Value::Null);
	} else {
		AutoPtr<Document> pDocument(new Document());
		SimpleStream_CString streamSrc(pHelp->GetText());
		if (!pDocument->ParseStream(sig, streamSrc)) return false;
		valListArg.push_back(Value(new Object_item(pDocument->GetItemRoot()->Reference())));
	}
	Args args(valListArg);
	_pFunc_Presenter->Eval(env, sig, args);
	return !sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(root);
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(text);
	Gura_RealizeUserSymbol(children);
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
	_pFunc_Presenter.reset(NULL);
}

Gura_EndModule(markdown, markdown)

Gura_RegisterModule(markdown)
