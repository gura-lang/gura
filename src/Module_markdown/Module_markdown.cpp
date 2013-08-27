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
		TYPE_Paragraph,		// container
		TYPE_Normal,		// text
		TYPE_Emphasis,		// text
		TYPE_Strong,		// text
		TYPE_InlineCode,	// text
		TYPE_BlockCode,		// container
		TYPE_OrderedList,	// container
		TYPE_UnorderedList,	// container
		TYPE_ListItem,		// text
	};
private:
	int _cntRef;
	Type _type;
	AutoPtr<ItemOwner> _pItemOwner;
	std::auto_ptr<String> _pText;
public:
	Gura_DeclareReferenceAccessor(Item);
public:
	Item(Type type, ItemOwner *pItemOwner);
	Item(Type type, const String &text);
private:
	inline ~Item() {}
public:
	inline const Type GetType() const { return _type; }
	inline bool IsOwner() const { return !_pItemOwner.IsNull(); }
	inline void SetItemOwner(ItemOwner *pItemOwner) { _pItemOwner.reset(pItemOwner); }
	inline ItemOwner *GetItemOwner() { return _pItemOwner.get(); }
	inline const ItemOwner *GetItemOwner() const { return _pItemOwner.get(); }
	inline const char *GetText() const {
		return (_pText.get() == NULL)? NULL : _pText->c_str();
	}
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
		STAT_HyphenFirst,
		STAT_ItemPre,
		STAT_Line,
		STAT_EmphasisPre, STAT_Emphasis,
		STAT_Strong, STAT_StrongEnd,
	};
private:
	Stat _stat;
	int _cntHeadSpace;
	String _text;
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
};

//-----------------------------------------------------------------------------
// Item
//-----------------------------------------------------------------------------
Item::Item(Type type, ItemOwner *pItemOwner) : _cntRef(1),
							_type(type), _pItemOwner(pItemOwner)
{
}

Item::Item(Type type, const String &text) : _cntRef(1),
							_type(type), _pText(new String(text))
{
}

const char *Item::GetTypeName() const
{
	static const struct {
		Type type;
		const char *name;
	} tbl[] = {
		{ TYPE_Root,			"Root",			},
		{ TYPE_Paragraph,		"Paragraph",	},
		{ TYPE_Normal,			"Normal",		},
		{ TYPE_Emphasis,		"Emphasis",		},
		{ TYPE_Strong,			"Strong",		},
		{ TYPE_InlineCode,		"InlineCode",	},
		{ TYPE_BlockCode,		"BlockCode",	},
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
		::printf("%*s[%s]%s\n", indentLevel * 2, "", GetTypeName(), GetText());
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
Document::Document() : _stat(STAT_LineTop), _cntHeadSpace(0), _pItemOwner(NULL)
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
		_cntHeadSpace = 0;
		continueFlag = true;
		_stat = STAT_LineHead;
		break;
	}
	case STAT_LineHead: {
		if (ch == ' ' ) {
			_cntHeadSpace += 1;
		} else if (ch == '\t') {
			_cntHeadSpace += 4;
		} else if (ch == '-') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_stat = STAT_HyphenFirst;
		} else if (IsEOL(ch)) {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			if (!_pItemOwner->empty()) {
				Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner);
				_pItemOwner = new ItemOwner();
				_pItemOwner->push_back(pItem);
			}
		} else if (IsEOF(ch)) {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_pItemRoot->SetItemOwner(_pItemOwner);
		} else {
			if (!_text.empty()) _text += ' ';
			continueFlag = true;
			_stat = STAT_Line;
		}
		break;
	}
	case STAT_HyphenFirst: {
		if (ch == '-') {
			
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_stat = STAT_LineTop;
		} else {
			continueFlag = true;
			_stat = STAT_ItemPre;
		}
		break;
	}
	case STAT_ItemPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			continueFlag = true;
			_stat = STAT_Line;
		}
		break;
	}
	case STAT_Line: {
		if (ch == '*') {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Normal, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_stat = STAT_EmphasisPre;
		} else if (IsEOL(ch)) {
			_stat = STAT_LineTop;
		} else if (IsEOF(ch)) {
			continueFlag = true;
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
			_stat = STAT_LineTop;
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
			_stat = STAT_Line;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			if (!_text.empty()) {
				Item *pItem = new Item(Item::TYPE_Emphasis, _text);
				_pItemOwner->push_back(pItem);
				_text.clear();
			}
			_stat = STAT_LineTop;
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
			_stat = STAT_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_StrongEnd: {
		if (ch == '*') {
			_stat = STAT_Line;
		} else {
			continueFlag = true;
			_stat = STAT_Line;
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
