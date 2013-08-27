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
		{ TYPE_Root,			"root",		},	// container
		{ TYPE_Header1,			"h1",		},	// container
		{ TYPE_Header2,			"h2",		},	// container
		{ TYPE_Paragraph,		"p",		},	// container
		{ TYPE_Normal,			"normal",	},	// text
		{ TYPE_Emphasis,		"em",		},	// text
		{ TYPE_Strong,			"strong",	},	// text
		{ TYPE_InlineCode,		"code",		},	// text
		{ TYPE_BlockCode,		"pre",		},	// container
		{ TYPE_OList,			"ol",		},	// container
		{ TYPE_UList,			"ul",		},	// container
		{ TYPE_ListItem,		"li",		},	// container
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
	AddHelp(Gura_Symbol(en),
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
// markdown.parse(stream:stream) {block?}
Gura_DeclareFunction(parse)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en),
	""
	);
}

Gura_ImplementFunction(parse)
{
	Parser parser;
	Stream &stream = args.GetStream(0);
	parser.ParseStream(sig, stream);
	Object_item *pObj = new Object_item(parser.GetItemRoot()->Reference());
	return ReturnValue(env, sig, args, Value(pObj));
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
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(text);
	Gura_RealizeUserSymbol(children);
	// class realization
	Gura_RealizeUserClassWithoutPrepare(item, env.LookupClass(VTYPE_object));
	Gura_UserClass(item)->Prepare(env);
	// function assignment
	Gura_AssignFunction(parse);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(markdown, markdown)

Gura_RegisterModule(markdown)
