//-----------------------------------------------------------------------------
// Gura markdown module
//-----------------------------------------------------------------------------
#ifndef __MODULE_MARKDOWN_H__
#define __MODULE_MARKDOWN_H__
#include <gura.h>

Gura_BeginModule(markdown)

//-----------------------------------------------------------------------------
// symbols
//-----------------------------------------------------------------------------
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(text);
Gura_DeclareUserSymbol(children);

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
		TYPE_Header3,		// container
		TYPE_Header4,		// container
		TYPE_Header5,		// container
		TYPE_Header6,		// container
		TYPE_Paragraph,		// container
		TYPE_Normal,		// text
		TYPE_Emphasis,		// text
		TYPE_Strong,		// text
		TYPE_InlineCode,	// text
		TYPE_BlockCode,		// container
		TYPE_OList,			// container
		TYPE_UList,			// container
		TYPE_ListItem,		// container
		TYPE_Line,			// container
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
// Parser
//-----------------------------------------------------------------------------
class Parser {
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
		STAT_BlockCode,
		STAT_BlockCode_LineTop,
		STAT_InlineCode,
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
	AutoPtr<ItemOwner> _pItemOwner;
	ItemStack _itemStack;
public:
	Parser();
	Item *Parse(Signal sig, SimpleStream &stream);
private:
	bool ParseChar(Signal sig, char ch);
	inline static bool IsEOL(char ch) { return ch == '\n'; }
	inline static bool IsEOF(char ch) { return ch == '\0'; }
	inline static bool IsDigit(char ch) { return '0' <= ch && ch <= '9'; }
};

//-----------------------------------------------------------------------------
// Class declaration for markdown.item
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(item);

class Object_item : public Object {
private:
	AutoPtr<Item> _pItem;
public:
	Gura_DeclareObjectAccessor(item)
public:
	inline Object_item(Item *pItem) : Object(Gura_UserClass(item)), _pItem(pItem) {}
	inline Item *GetItem() { return _pItem.get(); }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Iterator_item
//-----------------------------------------------------------------------------
class Iterator_item : public Iterator {
private:
	size_t _idxItem;
	AutoPtr<ItemOwner> _pItemOwner;
public:
	Iterator_item(ItemOwner *pItemOwner);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// TextFormatter_markdown
//-----------------------------------------------------------------------------
class TextFormatter_markdown : public TextFormatter {
public:
	inline TextFormatter_markdown() : TextFormatter("markdown") {}
	virtual bool DoFormat(Environment &env, Signal sig,
						SimpleStream &streamSrc, Stream &streamDst) const;
private:
	static bool OutputText(Signal sig, Stream &streamDst, const Item *pItem);
	static bool OutputText(Signal sig, Stream &streamDst, const ItemList *pItemList);
};

}}

#endif
