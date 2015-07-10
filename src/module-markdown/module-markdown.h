//-----------------------------------------------------------------------------
// Gura module: markdown
// Specification: http://daringfireball.net/projects/markdown/
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_MARKDOWN_H__
#define __GURA_MODULE_MARKDOWN_H__
#include <gura.h>

Gura_BeginModuleHeader(markdown)

const int WIDTH_Tab = 4;
const int INDENT_CodeBlock = 4;

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
Gura_DeclareUserSymbol(attrs);
Gura_DeclareUserSymbol(align);

class ItemOwner;

//-----------------------------------------------------------------------------
// Align
//-----------------------------------------------------------------------------
enum Align {
	ALIGN_None, ALIGN_Left, ALIGN_Center, ALIGN_Right
};

typedef std::vector<Align> AlignList;

//-----------------------------------------------------------------------------
// Item
//-----------------------------------------------------------------------------
class Item {
public:
	enum Type {
		TYPE_Root,			// container, can be a parent
		TYPE_Header1,		// container
		TYPE_Header2,		// container
		TYPE_Header3,		// container
		TYPE_Header4,		// container
		TYPE_Header5,		// container
		TYPE_Header6,		// container
		TYPE_Paragraph,		// container
		TYPE_BlockQuote,	// container, can be a parent
		TYPE_Emphasis,		// container
		TYPE_Strong,		// container
		TYPE_Strike,		// container
		TYPE_CodeBlock,		// container, can be a parent
		TYPE_OList,			// container, can be a parent
		TYPE_UList,			// container, can be a parent
		TYPE_ListItem,		// container, can be a parent
		TYPE_Line,			// container
		TYPE_Link,			// container
		TYPE_Image,			// text
		TYPE_Text,			// text
		TYPE_Comment,		// text
		TYPE_Code,			// text
		TYPE_Entity,		// text
		TYPE_Tag,			// container and text (attributes), can be a parent
		TYPE_HorzRule,		// no-content
		TYPE_LineBreak,		// no-content
		TYPE_Referee,		// no-content
	};
private:
	int _cntRef;
	Type _type;
	AutoPtr<ItemOwner> _pItemOwner;
	std::unique_ptr<String> _pText;
	std::unique_ptr<String> _pURL;	// valid when type is Link or Image
	std::unique_ptr<String> _pTitle;	// valid when type is Link or Image
	std::unique_ptr<String> _pRefId;	// valid when type is Link or Image
	std::unique_ptr<String> _pAttrs;	// valid when type is Tag
	Align _align;					// valid when type is Tag
	int _indentLevel;
	int _indentLevelItemBody;		// valid when type is ListItem
public:
	Gura_DeclareReferenceAccessor(Item);
public:
	Item(Type type, int indentLevel = 0, int indentLevelItemBody = 0);
	Item(Type type, ItemOwner *pItemOwner, int indentLevel = 0, int indentLevelItemBody = 0);
	Item(Type type, const String &text, int indentLevel = 0, int indentLevelItemBody = 0);
private:
	inline ~Item() {}
public:
	inline void SetType(Item::Type type) { _type = type; }
	inline const Type GetType() const { return _type; }
	inline bool IsRoot() const { return _type == TYPE_Root; }
	inline bool IsBlockQuote() const { return _type == TYPE_BlockQuote; }
	inline bool Is_list() const { return _type == TYPE_UList || _type == TYPE_OList; }
	inline bool IsListItem() const { return _type == TYPE_ListItem; }
	inline bool IsTag() const { return _type == TYPE_Tag; }
	inline bool IsText() const { return _type == TYPE_Text; }
	inline bool IsOwner() const { return !_pItemOwner.IsNull(); }
	inline void SetItemOwner(ItemOwner *pItemOwner) { _pItemOwner.reset(pItemOwner); }
	inline ItemOwner *GetItemOwner() { return _pItemOwner.get(); }
	inline const ItemOwner *GetItemOwner() const { return _pItemOwner.get(); }
	inline const char *GetText() const {
		return (_pText.get() == nullptr)? nullptr : _pText->c_str();
	}
	inline const char *GetURL() const {
		return (_pURL.get() == nullptr)? nullptr : _pURL->c_str();
	}
	inline const char *GetTitle() const {
		return (_pTitle.get() == nullptr)? nullptr : _pTitle->c_str();
	}
	inline const char *GetRefId() const {
		return (_pRefId.get() == nullptr)? nullptr : _pRefId->c_str();
	}
	inline const char *GetAttrs() const {
		return (_pAttrs.get() == nullptr)? nullptr : _pAttrs->c_str();
	}
	inline Align GetAlign() const { return _align; }
	inline void SetText(const String &text) { _pText.reset(new String(text)); }
	inline void AppendText(const String &text) {
		if (_pText.get() == nullptr) {
			_pText.reset(new String(text));
		} else {
			*_pText += text;
		}
	}
	inline void SetURL(const String &url) { _pURL.reset(new String(url)); }
	inline void SetTitle(const String &title) { _pTitle.reset(new String(title)); }
	inline void SetRefId(const String &refId) { _pRefId.reset(new String(refId)); }
	inline void SetAttrs(const String &attrs) { _pAttrs.reset(new String(attrs)); }
	inline void SetAlign(Align align) { _align = align; }
	inline void ClearURL() { _pURL.reset(nullptr); }
	inline void ClearTitle() { _pTitle.reset(nullptr); }
	inline void ClearRefId() { _pRefId.reset(nullptr); }
	inline void SetIndentLevel(int indentLevel) { _indentLevel = indentLevel; }
	inline void SetIndentLevelItemBody(int indentLevelItemBody) {
		_indentLevelItemBody = indentLevelItemBody;
	}
	inline int GetIndentLevel() const { return _indentLevel; }
	inline int GetIndentLevelItemBody() const { return _indentLevelItemBody; }
	const char *GetTypeName() const;
	void Print(Signal &sig, Stream &stream, int indentLevel) const;
};

//-----------------------------------------------------------------------------
// ItemList
//-----------------------------------------------------------------------------
class ItemList : public std::vector<Item *> {
public:
	Item *FindByRefId(const char *refId) const;
	Item *FindByType(Item::Type type) const;
	void Print(Signal &sig, Stream &stream, int indentLevel) const;
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
		STAT_LineHeadTable,
		STAT_LineHeadNL,
		STAT_BlockQuote,
		STAT_EqualAtHead,
		STAT_AsteriskAtHead,
		STAT_PlusAtHead,
		STAT_HyphenAtHead,
		STAT_DigitAtHead,
		STAT_DigitDotAtHead,
		STAT_BackquoteAtHead,
		STAT_BackquoteAtHead2nd,
		STAT_SetextHeaderHead,
		STAT_SetextHeaderPre,
		STAT_SetextHeader,
		STAT_SetextHeaderPost,
		STAT_AtxHeader1,
		STAT_AtxHeader2,
		STAT_UListItemPre,
		STAT_OListItemPre,
		STAT_ListItem,
		STAT_ListItem_LineHead,
		STAT_ListItem_BlockQuoteAtHead,
		STAT_ListItem_AsteriskAtHead,
		STAT_ListItem_PlusAtHead,
		STAT_ListItem_HyphenAtHead,
		STAT_ListItem_DigitAtHead,
		STAT_ListItem_DigitDotAtHead,
		STAT_ListItemNL,
		STAT_ListItemNL_AsteriskAtHead,
		STAT_ListItemNL_PlusAtHead,
		STAT_ListItemNL_HyphenAtHead,
		STAT_ListItemNL_DigitAtHead,
		STAT_ListItemNL_DigitDotAtHead,
		STAT_CodeBlock,
		STAT_CodeBlock_LineHead,
		STAT_FencedCodeBlockAttr,
		STAT_FencedCodeBlock,
		STAT_FencedCodeBlock_LineHead,
		STAT_FencedCodeBlock_LineHead2nd,
		STAT_FencedCodeBlock_LineHead3rd,
		STAT_FencedCodeBlock_SkipToEOL,
		STAT_CodeBlockUnderBlockQuote,
		STAT_Backquote,
		STAT_Code,
		STAT_CodeEsc,
		STAT_CodeEsc_Backquote,
		STAT_Text,
		STAT_SkipWhiteAfterPipe,
		STAT_SkipTableGuideRow,
		STAT_Asterisk,
		STAT_AsteriskEmphasis,
		STAT_AsteriskStrong,
		STAT_AsteriskStrongEnd,
		STAT_Underscore,
		STAT_UnderscoreEmphasis,
		STAT_UnderscoreEmphasisPost,
		STAT_UnderscoreStrong,
		STAT_UnderscoreStrongEnd,
		STAT_UnderscoreStrongPost,
		STAT_Tilda,
		STAT_TildaStrike,
		STAT_TildaStrikeEnd,
		STAT_DecorationPost,
		STAT_Entity,
		STAT_AngleBracketFirst,
		STAT_AngleBracket,
		STAT_CommentStartFirst,
		STAT_CommentStartSecond,
		STAT_Comment,
		STAT_CommentEndFirst,
		STAT_CommentEndSecond,
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
	bool _decoPrecedingFlag;
	int _iTableRow;
	int _iTableCol;
	Stat _stat;
	int _iLine;
	int _iCol;
	char _chPrev;
	StatStack _statStack;
	int _indentLevel;
	int _indentLevelTableTop;
	int _quoteLevel;
	int _cntEmptyLine;
	String _text;
	String _textAhead;
	String _field;
	AutoPtr<ItemOwner> _pItemOwner;
	AutoPtr<ItemOwner> _pItemRefereeOwner;
	AutoPtr<Item> _pItemRoot;
	AutoPtr<Item> _pItemLink;
	ItemList _itemsLinkReferrer;
	ItemStack _itemStack;
	ItemStack _itemStackTag;
	ItemOwnerStack _itemOwnerStack;
	AlignList _alignList;
public:
	Gura_DeclareReferenceAccessor(Document);
public:
	Document();
private:
	inline ~Document() {}
public:
	bool ParseStream(Signal &sig, SimpleStream &stream);
	bool ParseString(Signal &sig, const char *text);
	void AddItemReferee(Item *pItem);
	void ResolveReference();
	inline const Item *GetItemRoot() { return _pItemRoot.get(); }
	inline const ItemOwner *GetItemRefereeOwner() const {
		return _pItemRefereeOwner.get();
	}
private:
	bool _ParseString(Signal &sig, String text);
	bool ParseChar(Signal &sig, char ch);
	bool CheckSpecialChar(char ch);
	bool AdjustBlockQuote();
	void AppendJointSpace();
	void FlushText(Item::Type type, bool stripLeftFlag, bool stripRightFlag);
	void FlushItem(Item::Type type, bool stripLeftFlag, bool stripRightFlag);
	void FlushElement();
	void BeginTable();
	void EndTable();
	void BeginTableRow();
	void EndTableRow();
	void FlushTableCol(bool eolFlag);
	void BeginCodeBlock(const char *textInit);
	void EndCodeBlock();
	void BeginFencedCodeBlock();
	void EndFencedCodeBlock();
	//void BeginCodeBlockInList(const char *textInit);
	//void EndCodeBlockInList();
	void BeginListItem(Item::Type type);
	void EndListItem();
	void BeginDecoration(Item::Type type);
	void EndDecoration();
	void CancelDecoration(const char *textAhead);
	void ReplaceDecoration(Item::Type type, const char *textAhead);
	void BeginTag(const char *tagName, const char *attrs, bool closedFlag);
	bool EndTag(const char *tagName);
	int GetIndentLevel() const;
	int GetIndentLevelForCodeBlock() const;
	void UpdateIndentLevelItemBody(int indentLevelItemBody);
	bool IsWithin(Item::Type type) const;
	static bool IsAtxHeader2(const char *text);
	static bool IsHorzRule(const char *text);
	static bool IsLink(const char *text);
	static bool IsBeginTag(const char *text, String &tagName, String &attrs, bool &closedFlag);
	static bool IsEndTag(const char *text, String &tagName);
	inline bool IsWordChar(char ch) {
		return (GetCType(ch) &
				(CTYPE_Alpha | CTYPE_Digit | CTYPE_UTF8First | CTYPE_UTF8Follower)) != 0;
	}
	inline static bool IsEOL(char ch) { return ch == '\n'; }
	inline static bool IsEOF(char ch) { return ch == '\0'; }
	inline static bool IsDigit(char ch) { return '0' <= ch && ch <= '9'; }
	inline void AdvanceTableRow() { if (_iTableRow >= 0) _iTableRow++; }
	inline bool IsTableMode() const { return _iTableRow >= 0; }
	inline bool IsTableFirstRow() const { return _iTableRow == 0; }
	inline bool IsTableGuideRow() const { return _iTableRow == 1; }
	inline bool IsTableTrailingRow() const { return _iTableRow >= 2; }
	inline bool IsWithinTag() const { return !_itemStackTag.empty(); }
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
	virtual bool DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
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
	virtual bool DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
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
	virtual bool DoNext(Environment &env, Signal &sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// HelpPresenter_markdown
//-----------------------------------------------------------------------------
class HelpPresenter_markdown : public HelpPresenter {
public:
	inline HelpPresenter_markdown() : HelpPresenter("markdown") {}
	virtual bool DoPresent(Environment &env, Signal &sig, const char *title, const Help *pHelp) const;
};

Gura_EndModuleHeader(markdown)

#endif
