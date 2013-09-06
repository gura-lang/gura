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
		{ TYPE_Emphasis,		"em",		},	// container
		{ TYPE_Strong,			"strong",	},	// container
		{ TYPE_Block,			"block",	},	// container
		{ TYPE_OList,			"ol",		},	// container
		{ TYPE_UList,			"ul",		},	// container
		{ TYPE_ListItem,		"li",		},	// container
		{ TYPE_Line,			"line",		},	// container
		{ TYPE_Link,			"a",		},	// container
		{ TYPE_Image,			"img",		},	// container
		{ TYPE_Text,			"text",		},	// text
		{ TYPE_Code,			"code",		},	// text
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
	iterator ppItem = begin();
	foreach (ItemStack, ppItem, *this) {
		Item *pItem = *ppItem;
		if (pItem->IsList()) {
			erase(ppItem, end());
			break;
		}
	}
}

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
Document::Document() : _cntRef(1), _stat(STAT_LineTop),
								_indentLevel(0), _pItemOwner(new ItemOwner())
{
	_statStack.Push(STAT_LineTop);
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
		if (ch == '#') {
			FlushItem(Item::TYPE_Paragraph, false);
			_indentLevel = 1;
			_stat = STAT_SetextHeaderHead;
		} else {
			_indentLevel = 0;
			continueFlag = true;
			_stat = STAT_LineHead;
		}
		break;
	}
	case STAT_LineHead: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (ch == '=') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_EqualFirst;
		} else if (ch == '-') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_HyphenFirst;
		} else if (ch == '+') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_PlusFirst;
		} else if (ch == '*') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_StarFirst;
		} else if (IsDigit(ch)) {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_Digit;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushItem(Item::TYPE_Paragraph, false);
			_stat = STAT_LineTop;
		} else if (_indentLevel < INDENT_Block) {
			if (!_text.empty()) _text += ' ';
			continueFlag = true;
			_stat = STAT_Text;
		} else {
			continueFlag = true;
			BeginBlock(NULL);
		}
		break;
	}
	case STAT_EqualFirst: {
		if (ch == '=') {
			_textAhead += ch;
			_stat = STAT_AtxHeader1;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = STAT_AtxHeader1;
		} else if (_indentLevel < INDENT_Block) {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		} else {
			continueFlag = true;
			BeginBlock(_textAhead.c_str());
		}
		break;
	}
	case STAT_HyphenFirst: {
		if (ch == '-') {
			_textAhead += ch;
			_stat = STAT_AtxHeader2;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = STAT_AtxHeader2;
		} else if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false);
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel < INDENT_Block) {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		} else {
			continueFlag = true;
			BeginBlock(_textAhead.c_str());
		}
		break;
	}
	case STAT_PlusFirst: {
		if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false);
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel < INDENT_Block) {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		} else {
			continueFlag = true;
			BeginBlock(_textAhead.c_str());
		}
		break;
	}
	case STAT_StarFirst: {
		if (ch == ' ' || ch == '\t') {
			FlushItem(Item::TYPE_Paragraph, false);
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel < INDENT_Block) {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(STAT_Text);
			continueFlag = true;
			_stat = STAT_StarEmphasisPre;
		} else {
			continueFlag = true;
			BeginBlock(_textAhead.c_str());
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
			continueFlag = true;
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_SetextHeaderPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			_text.clear();
			continueFlag = true;
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_SetextHeader: {
		if (CheckDecoration(ch)) {
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
			FlushItem(type, true);
			continueFlag = IsEOF(ch);
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
			continueFlag = true;
			_stat = STAT_SetextHeader;
		} else {
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_SetextHeader;
		}
		break;
	}
	case STAT_AtxHeader1: {
		if (ch == '=') {
			_textAhead += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushItem(Item::TYPE_Header1, false);
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_AtxHeader2: {
		if (ch == '-') {
			_textAhead += ch;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushItem(Item::TYPE_Header2, false);
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_Digit: {
		if (IsDigit(ch)) {
			_textAhead += ch;
		} else if (ch == '.') {
			_textAhead += ch;
			_stat = STAT_DigitDot;
		} else if (_indentLevel < INDENT_Block) {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		} else {
			continueFlag = true;
			BeginBlock(_textAhead.c_str());
		}
		break;
	}
	case STAT_DigitDot: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_OList);
		} else if (_indentLevel < INDENT_Block) {
			if (!_text.empty()) _text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_Text;
		} else {
			continueFlag = true;
			BeginBlock(_textAhead.c_str());
		}
		break;
	}
	case STAT_ListItemPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItem: {
		if (CheckDecoration(ch)) {
			// nothing to do
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_indentLevel = 0;
			continueFlag = IsEOF(ch);
			_stat = STAT_ListItemPost;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_ListItemPost: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (IsDigit(ch)) {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemPost_Digit;
		} else if (ch == '-') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemPost_Hyphen;
		} else if (ch == '+') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemPost_Plus;
		} else if (ch == '*') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemPost_Star;
		} else if (IsEOL(ch)) {
			_indentLevel = 0;
			_stat = STAT_ListItemPost_EOL;
		} else if (IsEOF(ch)) {
			EndListItem();
			_itemStack.ClearListItem();
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_text += ' ';
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemPost_Digit: {
		if (IsDigit(ch)) {
			_textAhead += ch;
		} else if (ch == '.') {
			_textAhead += ch;
			_stat = STAT_ListItemPost_DigitDot;
		} else {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemPost_DigitDot: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_OList);
		} else {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemPost_Hyphen: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemPost_Plus: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		}
		break;
	}
	case STAT_ListItemPost_Star: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else {
			_text += ' ';
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(STAT_ListItem);
			continueFlag = true;
			_stat = STAT_StarEmphasisPre;
		}
		break;
	}
	case STAT_ListItemPost_EOL: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (IsDigit(ch)) {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemPost_EOL_Digit;
		} else if (ch == '-') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemPost_EOL_Hyphen;
		} else if (ch == '+') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemPost_EOL_Plus;
		} else if (ch == '*') {
			_textAhead.clear();
			_textAhead += ch;
			_stat = STAT_ListItemPost_EOL_Star;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndListItem();
			_itemStack.ClearListItem();
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else if (_indentLevel == 0) {
			EndListItem();
			_itemStack.ClearListItem();
			continueFlag = true;
			_stat = STAT_LineTop;
		} else if (_indentLevel < INDENT_BlockInListItem) {
 			FlushItem(Item::TYPE_Paragraph, false);
			continueFlag = true;
			_stat = STAT_ListItem;
		} else {
			continueFlag = true;
			BeginBlockInListItem(NULL);
		}
		break;
	}
	case STAT_ListItemPost_EOL_Digit: {
		if (IsDigit(ch)) {
			_textAhead += ch;
		} else if (ch == '.') {
			_textAhead += ch;
			_stat = STAT_ListItemPost_DigitDot;
		} else if (_indentLevel < INDENT_BlockInListItem) {
			_text += ' ';
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		} else {
			continueFlag = true;
			BeginBlockInListItem(_textAhead.c_str());
		}
		break;
	}
	case STAT_ListItemPost_EOL_DigitDot: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_OList);
		} else if (_indentLevel < INDENT_BlockInListItem) {
 			FlushItem(Item::TYPE_Paragraph, false);
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		} else {
			continueFlag = true;
			BeginBlockInListItem(_textAhead.c_str());
		}
		break;
	}
	case STAT_ListItemPost_EOL_Hyphen: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel < INDENT_BlockInListItem) {
 			FlushItem(Item::TYPE_Paragraph, false);
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		} else {
			continueFlag = true;
			BeginBlockInListItem(_textAhead.c_str());
		}
		break;
	}
	case STAT_ListItemPost_EOL_Plus: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel < INDENT_BlockInListItem) {
 			FlushItem(Item::TYPE_Paragraph, false);
			_text += _textAhead;
			continueFlag = true;
			_stat = STAT_ListItem;
		} else {
			continueFlag = true;
			BeginBlockInListItem(_textAhead.c_str());
		}
		break;
	}
	case STAT_ListItemPost_EOL_Star: {
		if (ch == ' ' || ch == '\t') {
			BeginListItem(Item::TYPE_UList);
		} else if (_indentLevel < INDENT_BlockInListItem) {
 			FlushItem(Item::TYPE_Paragraph, false);
			continueFlag = true;
			_statStack.Push(STAT_ListItem);
			_stat = STAT_StarEmphasisPre;
		} else {
			continueFlag = true;
			BeginBlockInListItem(_textAhead.c_str());
		}
		break;
	}
	case STAT_Block: {
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
			continueFlag = IsEOF(ch);
			_stat = STAT_Block_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_Block_LineTop: {
		if (ch == ' ') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (_indentLevel < INDENT_Block) {
			continueFlag = true;
			EndBlock();
		} else {
			for (int i = 0; i < _indentLevel - INDENT_Block; i++) _text += ' ';
			continueFlag = true;
			_stat = STAT_Block;
		}
		break;
	}
	case STAT_BlockInListItem: {
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
			continueFlag = IsEOF(ch);
			_stat = STAT_BlockInListItem_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_BlockInListItem_LineTop: {
		if (ch == ' ' || ch == '\t') {
			_indentLevel += 1;
		} else if (ch == '\t') {
			_indentLevel += 4;
		} else if (_indentLevel < INDENT_BlockInListItem) {
			continueFlag = true;
			EndBlockInListItem();
		} else {
			for (int i = 0; i < _indentLevel - INDENT_BlockInListItem; i++) _text += ' ';
			continueFlag = true;
			_stat = STAT_BlockInListItem;
		}
		break;
	}
	case STAT_BackquoteFirst: {
		if (ch == '`') {
			_stat = STAT_CodeEsc;
		} else {
			continueFlag = true;
			_stat = STAT_Code;
		}
		break;
	}
	case STAT_Code: {
		if (ch == '`') {
			FlushText(Item::TYPE_Code, true);
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			FlushText(Item::TYPE_Code, true);
			continueFlag = true;
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
			FlushText(Item::TYPE_Code, true);
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_CodeEsc_Backquote: {
		if (ch == '`') {
			FlushText(Item::TYPE_Code, true);
			_stat = _statStack.Pop();
		} else {
			_text += '`';
			continueFlag = true;
			_stat = STAT_CodeEsc;
		}
		break;
	}
	case STAT_Text: {
		if (CheckDecoration(ch)) {
			// nothing to do
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = IsEOF(ch);
			_stat = STAT_LineTop;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_StarEmphasisPre: {
		if (ch == '*') {
			BeginDecoration(Item::TYPE_Strong);
			_stat = STAT_StarStrong;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			BeginDecoration(Item::TYPE_Emphasis);
			continueFlag = true;
			_stat = STAT_StarEmphasis;
		}
		break;
	}
	case STAT_StarEmphasis: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(_stat);
			_stat = STAT_BackquoteFirst;
		} else if (ch == '*') {
			EndDecoration();
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_StarStrong: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(_stat);
			_stat = STAT_BackquoteFirst;
		} else if (ch == '*') {
			_stat = STAT_StarStrongEnd;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_StarStrongEnd: {
		if (ch == '*') {
			EndDecoration();
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			FlushText(Item::TYPE_Text, true);
			BeginDecoration(Item::TYPE_Emphasis);
			_statStack.Push(STAT_StarStrong);
			continueFlag = true;
			_stat = STAT_StarEmphasis;
		}
		break;
	}
	case STAT_UBarEmphasisPre: {
		if (ch == '_') {
			BeginDecoration(Item::TYPE_Strong);
			_stat = STAT_UBarStrong;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			BeginDecoration(Item::TYPE_Emphasis);
			continueFlag = true;
			_stat = STAT_UBarEmphasis;
		}
		break;
	}
	case STAT_UBarEmphasis: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(_stat);
			_stat = STAT_BackquoteFirst;
		} else if (ch == '_') {
			EndDecoration();
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_UBarStrong: {
		if (ch == '\\') {
			_statStack.Push(_stat);
			_stat = STAT_Escape;
		} else if (ch == '`') {
			FlushText(Item::TYPE_Text, false);
			_statStack.Push(_stat);
			_stat = STAT_BackquoteFirst;
		} else if (ch == '_') {
			_stat = STAT_UBarStrongEnd;
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_UBarStrongEnd: {
		if (ch == '_') {
			EndDecoration();
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			EndDecoration();
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			FlushText(Item::TYPE_Text, true);
			BeginDecoration(Item::TYPE_Emphasis);
			_statStack.Push(STAT_UBarStrong);
			continueFlag = true;
			_stat = STAT_UBarEmphasis;
		}
		break;
	}
	case STAT_AutoLink: {
		if (ch == '>') {
			if (IsLink(_field.c_str())) {
				FlushText(Item::TYPE_Text, false);
				Item *pItemLink = new Item(Item::TYPE_Link, new ItemOwner());
				pItemLink->SetURL(_field);
				_pItemOwner->push_back(pItemLink);
				do {
					Item *pItem = new Item(Item::TYPE_Text, _field);
					pItemLink->GetItemOwner()->push_back(pItem);
				} while (0);
			} else {
				_text += _textAhead;
				_text += ch;
			}
			_stat = _statStack.Pop();
		} else if (IsEOL(ch) || IsEOF(ch)) {
			_text += _textAhead;
			continueFlag = true;
			_stat = _statStack.Pop();
		} else {
			_textAhead += ch;
			_field += ch;
		}
		break;
	}
	case STAT_Escape: {
		_text += ch;
		_stat = _statStack.Pop();
		break;
	}
	}
	} while (continueFlag);
	return true;
}

bool Document::CheckDecoration(char ch)
{
	if (ch == '\\') {
		_statStack.Push(_stat);
		_stat = STAT_Escape;
		return true;
	} else if (ch == '`') {
		FlushText(Item::TYPE_Text, false);
		_statStack.Push(_stat);
		_stat = STAT_BackquoteFirst;
		return true;
	} else if (ch == '*') {
		FlushText(Item::TYPE_Text, false);
		_statStack.Push(_stat);
		_stat = STAT_StarEmphasisPre;
		return true;
	} else if (ch == '_') {
		FlushText(Item::TYPE_Text, false);
		_statStack.Push(_stat);
		_stat = STAT_UBarEmphasisPre;
		return true;
	} else if (ch == '<') {
		_textAhead.clear();
		_field.clear();
		_textAhead += ch;
		_statStack.Push(_stat);
		_stat = STAT_AutoLink;
		return true;
	}
	return false;
}

void Document::FlushText(Item::Type type, bool stripFlag)
{
	if (!_text.empty()) {
		Item *pItem = new Item(type, Strip(_text.c_str(), stripFlag, stripFlag));
		_pItemOwner->push_back(pItem);
		_text.clear();
	}
}

void Document::FlushItem(Item::Type type, bool stripFlag)
{
	Item *pItemParent = _itemStack.back();
	FlushText(Item::TYPE_Text, stripFlag);
	if (!_pItemOwner->empty()) {
		Item *pItem = new Item(type, _pItemOwner.release());
		pItemParent->GetItemOwner()->push_back(pItem);
		_pItemOwner.reset(new ItemOwner());
	}
}

void Document::BeginBlock(const char *textInit)
{
	FlushItem(Item::TYPE_Paragraph, false);
	for (int i = 0; i < _indentLevel - INDENT_Block; i++) _text += ' ';
	if (textInit != NULL) _text += textInit;
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_Block, new ItemOwner(), _indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} while (0);
	_stat = STAT_Block;
}

void Document::EndBlock()
{
	_itemStack.pop_back();
	_stat = STAT_LineTop;
}

void Document::BeginBlockInListItem(const char *textInit)
{
	FlushItem(Item::TYPE_Paragraph, false);
	for (int i = 0; i < _indentLevel - INDENT_BlockInListItem; i++) _text += ' ';
	if (textInit != NULL) _text += textInit;
	do {
		Item *pItemParent = _itemStack.back();
		Item *pItem = new Item(Item::TYPE_Block, new ItemOwner(), _indentLevel);
		pItemParent->GetItemOwner()->push_back(pItem);
		_itemStack.push_back(pItem);
	} while (0);
	_statStack.Push(STAT_ListItemPost);
	_stat = STAT_BlockInListItem;
}

void Document::EndBlockInListItem()
{
	_itemStack.pop_back();
	_stat = _statStack.Pop();
}

void Document::BeginListItem(Item::Type type)
{
	Item *pItemParent = _itemStack.back();
	while (_indentLevel < pItemParent->GetIndentLevel()) {
		if (pItemParent->GetType() == Item::TYPE_ListItem) {
			EndListItem();
		} else {
			_itemStack.pop_back();
		}
		pItemParent = _itemStack.back();
	}
	if (pItemParent->GetType() == Item::TYPE_ListItem) {
		if (_indentLevel == pItemParent->GetIndentLevel()) {
			EndListItem();
			pItemParent = _itemStack.back();
		} else {
			FlushListItem();
		}
	}
	if (pItemParent->GetType() == Item::TYPE_Root ||
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

void Document::FlushListItem()
{
	Item *pItemParent = _itemStack.back();
	FlushText(Item::TYPE_Text, false);
	if (pItemParent->GetItemOwner()->empty()) {
		pItemParent->GetItemOwner()->Store(*_pItemOwner);
		_pItemOwner.reset(new ItemOwner());
	} else if (!_pItemOwner->empty()) {
		Item *pItem = new Item(Item::TYPE_Paragraph, _pItemOwner.release());
		pItemParent->GetItemOwner()->push_back(pItem);
		_pItemOwner.reset(new ItemOwner());
	}
}

void Document::EndListItem()
{
	FlushListItem();
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
	FlushText(Item::TYPE_Text, false);
	_pItemOwner.reset(_itemOwnerStack.Pop());
}

bool Document::IsLink(const char *text)
{
	enum StatL {
		STATL_Begin,
		STATL_Head,
		STATL_EMail,
		STATL_EMailDot,
		STATL_EMailAfterDot,
		STATL_URL,
	} statL = STATL_Begin;
	String head;
	for (const char *p = text; ; p++) {
		char ch = *p;
		switch (statL) {
		case STATL_Begin: {
			if (IsAlpha(ch)) {
				head += ch;
				statL = STATL_Head;
			} else {
				return false;
			}
			break;
		}
		case STATL_Head: {
			if (IsAlpha(ch)) {
				head += ch;
			} else if (ch == '@') {
				statL = STATL_EMail;
			} else if (ch == ':') {
				statL = STATL_URL;
			} else {
				return false;
			}
			break;
		}
		case STATL_EMail: {
			if (IsAlpha(ch)) {
				// nothing to do
			} else if (ch == '.') {
				statL = STATL_EMailDot;
			} else {
				return false;
			}
			break;
		}
		case STATL_EMailDot: {
			if (IsAlpha(ch)) {
				statL = STATL_EMailAfterDot;
			} else {
				return false;
			}
			break;
		}
		case STATL_EMailAfterDot: {
			if (IsAlpha(ch)) {
				// nothing to do
			} else if (ch == '.') {
				statL = STATL_EMailDot;
			} else if (ch == '\0') {
				// nothing to do
			} else {
				return false;
			}
			break;
		}
		case STATL_URL: {
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
// markdown.document#read(stream:stream:w):void
Gura_DeclareMethod(document, read)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(document, read)
{
	Document *pDocument = Object_document::GetThisObj(args)->GetDocument();
	pDocument->ParseStream(sig, args.GetStream(0));
	return Value::Null;
}

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
	Document *pDocument = Object_document::GetThisObj(args)->GetDocument();
	const Item *pItem = pDocument->GetItemRoot();
	pItem->Print(sig, *env.GetConsole(), 0);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for markdown.document
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(document)
{
	Gura_AssignMethod(document, read);
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
	symbols.insert(Gura_UserSymbol(url));
	symbols.insert(Gura_UserSymbol(title));
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
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(url))) {
		const char *url = _pItem->GetURL();
		if (url == NULL) return Value::Null;
		return Value(env, url);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(title))) {
		const char *title = _pItem->GetTitle();
		if (title == NULL) return Value::Null;
		return Value(env, title);
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
	pItem->Print(sig, *env.GetConsole(), 0);
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
	Gura_RealizeUserSymbol(url);
	Gura_RealizeUserSymbol(title);
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
