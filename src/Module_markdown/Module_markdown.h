//-----------------------------------------------------------------------------
// Gura markdown module
// Specification: http://daringfireball.net/projects/markdown/
//-----------------------------------------------------------------------------
#ifndef __MODULE_MARKDOWN_H__
#define __MODULE_MARKDOWN_H__
#include <gura.h>

Gura_BeginModule(markdown)

//-----------------------------------------------------------------------------
// symbols
//-----------------------------------------------------------------------------
Gura_DeclareUserSymbol(root);
Gura_DeclareUserSymbol(refs);
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(text);
Gura_DeclareUserSymbol(children);
Gura_DeclareUserSymbol(url);
Gura_DeclareUserSymbol(title);

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
		TYPE_BlockQuote,	// container
		TYPE_Emphasis,		// container
		TYPE_Strong,		// container
		TYPE_CodeBlock,		// container
		TYPE_OList,			// container
		TYPE_UList,			// container
		TYPE_ListItem,		// container
		TYPE_Line,			// container
		TYPE_Link,			// container
		TYPE_Image,			// text
		TYPE_Text,			// text
		TYPE_Code,			// text
		TYPE_Entity,		// text
		TYPE_HorzRule,		// no-content
		TYPE_LineBreak,		// no-content
		TYPE_Referee,		// no-content
	};
private:
	int _cntRef;
	Type _type;
	AutoPtr<ItemOwner> _pItemOwner;
	std::auto_ptr<String> _pText;
	std::auto_ptr<String> _pURL;	// valid when type is Link or Image
	std::auto_ptr<String> _pTitle;	// valid when type is Link or Image
	std::auto_ptr<String> _pRefId;	// valid when type is Link or Image
	int _indentLevel;
public:
	Gura_DeclareReferenceAccessor(Item);
public:
	Item(Type type, int indentLevel = 0);
	Item(Type type, ItemOwner *pItemOwner, int indentLevel = 0);
	Item(Type type, const String &text, int indentLevel = 0);
private:
	inline ~Item() {}
public:
	inline void SetType(Item::Type type) { _type = type; }
	inline const Type GetType() const { return _type; }
	inline bool IsRoot() const { return _type == TYPE_Root; }
	inline bool IsBlockQuote() const { return _type == TYPE_BlockQuote; }
	inline bool IsList() const { return _type == TYPE_UList || _type == TYPE_OList; }
	inline bool IsListItem() const { return _type == TYPE_ListItem; }
	inline bool IsOwner() const { return !_pItemOwner.IsNull(); }
	inline void SetItemOwner(ItemOwner *pItemOwner) { _pItemOwner.reset(pItemOwner); }
	inline ItemOwner *GetItemOwner() { return _pItemOwner.get(); }
	inline const ItemOwner *GetItemOwner() const { return _pItemOwner.get(); }
	inline const char *GetText() const {
		return (_pText.get() == NULL)? NULL : _pText->c_str();
	}
	inline const char *GetURL() const {
		return (_pURL.get() == NULL)? NULL : _pURL->c_str();
	}
	inline const char *GetTitle() const {
		return (_pTitle.get() == NULL)? NULL : _pTitle->c_str();
	}
	inline const char *GetRefId() const {
		return (_pRefId.get() == NULL)? NULL : _pRefId->c_str();
	}
	inline void SetText(const String &text) { _pText.reset(new String(text)); }
	inline void SetURL(const String &url) { _pURL.reset(new String(url)); }
	inline void SetTitle(const String &title) { _pTitle.reset(new String(title)); }
	inline void SetRefId(const String &refId) { _pRefId.reset(new String(refId)); }
	inline void ClearURL() { _pURL.reset(NULL); }
	inline void ClearTitle() { _pTitle.reset(NULL); }
	inline void ClearRefId() { _pRefId.reset(NULL); }
	inline void SetIndentLevel(int indentLevel) { _indentLevel = indentLevel; }
	inline int GetIndentLevel() const { return _indentLevel; }
	const char *GetTypeName() const;
	void Print(Signal sig, Stream &stream, int indentLevel) const;
};

//-----------------------------------------------------------------------------
// ItemList
//-----------------------------------------------------------------------------
class ItemList : public std::vector<Item *> {
public:
	Item *FindByRefId(const char *refId) const;
	void Print(Signal sig, Stream &stream, int indentLevel) const;
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
// ItemOwnerStack
//-----------------------------------------------------------------------------
class ItemOwnerStack : public std::vector<ItemOwner *> {
public:
	~ItemOwnerStack();
	void Clear();
	inline void Push(ItemOwner *pItemOwner) { push_back(pItemOwner); }
	inline ItemOwner *Pop() {
		ItemOwner *pItemOwner = back();
		pop_back();
		return pItemOwner;
	}
};

//-----------------------------------------------------------------------------
// ItemStack
//-----------------------------------------------------------------------------
class ItemStack : public ItemList {
public:
	void ClearListItem();
	int CountQuoteLevel() const;
};

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
class Document {
private:
	enum Stat {
		STAT_LineTop,
		STAT_LineHead,
		STAT_LineHeadNL,
		STAT_BlockQuote,
		STAT_Equal,
		STAT_Asterisk,
		STAT_Plus,
		STAT_Hyphen,
		STAT_Digit,
		STAT_DigitDot,
		STAT_SetextHeaderHead,
		STAT_SetextHeaderPre,
		STAT_SetextHeader,
		STAT_SetextHeaderPost,
		STAT_AtxHeader1,
		STAT_AtxHeader2,
		STAT_ListItemPre,
		STAT_ListItem,
		STAT_ListItem_LineHead,
		STAT_ListItem_BlockQuote,
		STAT_ListItem_Asterisk,
		STAT_ListItem_Plus,
		STAT_ListItem_Hyphen,
		STAT_ListItem_Digit,
		STAT_ListItem_DigitDot,
		STAT_ListItemNL,
		STAT_ListItemNL_Asterisk,
		STAT_ListItemNL_Plus,
		STAT_ListItemNL_Hyphen,
		STAT_ListItemNL_Digit,
		STAT_ListItemNL_DigitDot,
		STAT_CodeBlock,
		STAT_CodeBlock_LineTop,
		STAT_CodeBlock_BlockQuote,
		STAT_CodeBlockInList,
		STAT_CodeBlockInList_LineTop,
		STAT_CodeBlockInList_BlockQuote,
		STAT_Backquote,
		STAT_Code,
		STAT_CodeEsc,
		STAT_CodeEsc_Backquote,
		STAT_Text,
		STAT_AsteriskEmphasisPre,
		STAT_AsteriskEmphasis,
		STAT_AsteriskStrong,
		STAT_AsteriskStrongEnd,
		STAT_UnderscoreEmphasisPre,
		STAT_UnderscoreEmphasis,
		STAT_UnderscoreStrong,
		STAT_UnderscoreStrongEnd,
		STAT_AutoLink,
		STAT_LinkAltTextPre,
		STAT_LinkAltText,
		STAT_LinkText,
		STAT_LinkTextPost,
		STAT_LinkRefId,
		STAT_LinkURLPre,
		STAT_LinkURL,
		STAT_LinkURLAngle,
		STAT_LinkURLAnglePost,
		STAT_LinkTitleDoubleQuote,
		STAT_LinkTitleSingleQuote,
		STAT_LinkTitlePost,
		STAT_RefereeRefIdPre,
		STAT_RefereeRefId,
		STAT_RefereeRefIdPost,
		STAT_RefereeURLPreWhite,
		STAT_RefereeURLPre,
		STAT_RefereeURL,
		STAT_RefereeURLAngle,
		STAT_RefereeURLAnglePost,
		STAT_RefereeTitleDoubleQuote,
		STAT_RefereeTitleSingleQuote,
		STAT_RefereeTitleParenthesis,
		STAT_RefereeTitlePost,
		STAT_Escape,
		STAT_EscapeInLink,
	};
	enum {
		INDENT_CodeBlock		= 4,
		INDENT_CodeBlockInList	= 8,
	};
	class StatStack : public std::vector<Stat> {
	public:
		inline void Push(Stat stat) { push_back(stat); }
		inline Stat Pop() {
			Stat stat = back();
			pop_back();
			return stat;
		}
	};
private:
	int _cntRef;
	bool _resolvedFlag;
	Stat _stat;
	StatStack _statStack;
	int _indentLevel;
	int _quoteLevel;
	String _text;
	String _textAhead;
	String _field;
	AutoPtr<ItemOwner> _pItemOwner;
	AutoPtr<ItemOwner> _pItemRefereeOwner;
	AutoPtr<Item> _pItemRoot;
	AutoPtr<Item> _pItemLink;
	ItemList _itemsLinkReferrer;
	ItemStack _itemStack;
	ItemOwnerStack _itemOwnerStack;
public:
	Gura_DeclareReferenceAccessor(Document);
public:
	Document();
private:
	inline ~Document() {}
public:
	bool ParseStream(Signal sig, SimpleStream &stream);
	bool ParseString(Signal sig, const char *text);
	void AddItemReferee(Item *pItem);
	void ResolveReference();
	inline const Item *GetItemRoot() { return _pItemRoot.get(); }
	inline const ItemOwner *GetItemRefereeOwner() const {
		return _pItemRefereeOwner.get();
	}
private:
	bool _ParseString(Signal sig, String text);
	bool ParseChar(Signal sig, char ch);
	bool CheckSpecialChar(char ch);
	bool AdjustBlockQuote();
	void FlushText(Item::Type type, bool stripFlag);
	void FlushItem(Item::Type type, bool stripFlag);
	void BeginCodeBlock(const char *textInit);
	void EndCodeBlock();
	void BeginCodeBlockInList(const char *textInit);
	void EndCodeBlockInList();
	void BeginListItem(Item::Type type);
	void FlushListItem();
	void EndListItem();
	void BeginDecoration(Item::Type type);
	void EndDecoration();
	static bool IsAtxHeader2(const char *text);
	static bool IsHorzRule(const char *text);
	static bool IsLink(const char *text);
	inline static bool IsEOL(char ch) { return ch == '\n'; }
	inline static bool IsEOF(char ch) { return ch == '\0'; }
	inline static bool IsDigit(char ch) { return '0' <= ch && ch <= '9'; }
};

//-----------------------------------------------------------------------------
// Class declaration for markdown.document
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(document);

class Object_document : public Object {
private:
	AutoPtr<Document> _pDocument;
public:
	Gura_DeclareObjectAccessor(document)
public:
	inline Object_document(Document *pDocument) : Object(Gura_UserClass(document)), _pDocument(pDocument) {}
	inline Document *GetDocument() { return _pDocument.get(); }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
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
// HelpPresenter_markdown
//-----------------------------------------------------------------------------
class HelpPresenter_markdown : public HelpPresenter {
public:
	inline HelpPresenter_markdown() : HelpPresenter("markdown") {}
	virtual bool DoPresent(Environment &env, Signal sig, const char *title, const Help *pHelp) const;
};

}}

#endif
