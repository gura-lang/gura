//-----------------------------------------------------------------------------
// Gura test module
//-----------------------------------------------------------------------------
#include "Module_markdown.h"

Gura_BeginModule(test)

class ItemOwner;

//-----------------------------------------------------------------------------
// Item
//-----------------------------------------------------------------------------
class Item {
public:
	enum Type {
		TYPE_Root,			// container
		TYPE_Header1,		// container
		TYPE_Header2,		// container
		TYPE_Paragraph,		// container
		TYPE_Normal,		// text
		TYPE_Emphasis,		// text
		TYPE_Strong,		// text
		TYPE_InlineCode,	// text
		TYPE_BlockCode,		// container
		TYPE_OList,			// container
		TYPE_UList,			// container
		TYPE_ListItem,		// container
	};
private:
	int _cntRef;
	Type _type;
	AutoPtr<ItemOwner> _pItemOwner;
	std::auto_ptr<String> _pText;
	int _indentLevel;
public:
	Gura_DeclareReferenceAccessor(Item);
public:
	Item(Type type, ItemOwner *pItemOwner, int indentLevel = 0);
	Item(Type type, const String &text, int indentLevel = 0);
private:
	inline ~Item() {}
public:
	inline const Type GetType() const { return _type; }
	inline bool IsList() const { return _type == TYPE_UList || _type == TYPE_OList; }
	inline bool IsOwner() const { return !_pItemOwner.IsNull(); }
	inline void SetItemOwner(ItemOwner *pItemOwner) { _pItemOwner.reset(pItemOwner); }
	inline ItemOwner *GetItemOwner() { return _pItemOwner.get(); }
	inline const ItemOwner *GetItemOwner() const { return _pItemOwner.get(); }
	inline const char *GetText() const {
		return (_pText.get() == NULL)? NULL : _pText->c_str();
	}
	inline void SetIndentLevel(int indentLevel) { _indentLevel = indentLevel; }
	inline int GetIndentLevel() const { return _indentLevel; }
	const char *GetTypeName() const;
	void Print(int indentLevel) const;
};

//-----------------------------------------------------------------------------
// ItemList
//-----------------------------------------------------------------------------
class ItemList : public std::vector<Item *> {
public:
	void Print(int indentLevel) const;
};

//-----------------------------------------------------------------------------
// ItemOwner
//-----------------------------------------------------------------------------
class ItemOwner : public ItemList {
public:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(ItemOwner);
public:
	inline ItemOwner() : _cntRef(1) {}
private:
	~ItemOwner();
public:
	void Clear();
	void Store(const ItemList &itemList);
};

//-----------------------------------------------------------------------------
// ItemStack
//-----------------------------------------------------------------------------
class ItemStack : public ItemList {
};

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
class Document {
private:
	enum Stat {
		STAT_LineTop,
		STAT_LineHead,
		STAT_EqualFirst,
		STAT_HyphenFirst,
		STAT_Header1,
		STAT_Header2,
		STAT_Digit,
		STAT_UListItemPre,
		STAT_UListItem,
		STAT_UListItemPost,
		STAT_OListItemPre,
		STAT_OListItem,
		STAT_OListItemPost,
		STAT_OListItemPost_Digit,
		STAT_Normal,
		STAT_EmphasisPre,
		STAT_Emphasis,
		STAT_Strong,
		STAT_StrongEnd,
	};
private:
	Stat _stat;
	Stat _statRtn;
	int _indentLevel;
	String _text;
	String _textAdd;
	AutoPtr<Item> _pItemRoot;
	ItemOwner *_pItemOwner;
	ItemStack _itemStack;
public:
	Document();
	bool ParseStream(Signal sig, Stream &stream);
	bool ParseChar(Signal sig, char ch);
	inline Item *GetItemRoot() { return _pItemRoot.get(); }
	inline const Item *GetItemRoot() const { return _pItemRoot.get(); }
	inline static bool IsEOL(char ch) { return ch == '\n'; }
	inline static bool IsEOF(char ch) { return ch == '\0'; }
	inline static bool IsDigit(char ch) { return '0' <= ch && ch <= '9'; }
};

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
// Document
//-----------------------------------------------------------------------------
Document::Document() : _stat(STAT_LineTop), _statRtn(STAT_LineTop),
											_indentLevel(0), _pItemOwner(NULL)
{
	_pItemRoot.reset(new Item(Item::TYPE_Root, new ItemOwner()));
	_pItemOwner = new ItemOwner();
	_itemStack.push_back(_pItemRoot.get());
}

bool Document::ParseStream(Signal sig, Stream &stream)
{
	for (;;) {
		int chRaw = stream.GetChar(sig);
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		if (!ParseChar(sig, ch)) return false;
		if (chRaw < 0) break;
	}
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
// markdown.test(stream:stream)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
}

Gura_ImplementFunction(test)
{
	Document doc;
	Stream &stream = args.GetStream(0);
	doc.ParseStream(sig, stream);
	doc.GetItemRoot()->Print(0);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(test, test)

Gura_RegisterModule(test)
