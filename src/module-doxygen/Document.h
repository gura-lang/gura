//=============================================================================
// Document.h
//=============================================================================
#ifndef __GURA_DOXYGEN_DOCUMENT_H__
#define __GURA_DOXYGEN_DOCUMENT_H__

#define BeginPushbackRegion(var) \
_pushbackBuff[_pushbackLevel++] = var; \
while (_pushbackLevel > 0) { \
var = _pushbackBuff[--_pushbackLevel];

#define EndPushbackRegion() \
}

Gura_BeginModuleScope(doxygen)

class Object_document;

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
class Parser {
public:
	enum Stat {
		STAT_Init,
		STAT_String,
		STAT_AcceptCommandInString,
		STAT_AcceptCommandInArgLine,
		STAT_AcceptCommandInArgPara,
		STAT_AcceptCommandInArgCustom,
		STAT_CommandSpecial,
		STAT_CommandCustom,
		STAT_NextArg,
		STAT_BranchArg,
		STAT_ArgWord,
		STAT_ArgWord_Punctuation,
		STAT_ArgWordQuote,
		STAT_ArgBracket,
		STAT_ArgLine,
		STAT_ArgQuote,
		STAT_ArgBrace,
		STAT_ArgPara,
		STAT_ArgParaNewline,
		STAT_ArgCustom,
		STAT_ArgCustom_Backslash,
		STAT_Complete,
	};
private:
	const Aliases *_pAliases;
	Parser *_pParserParent;
	Stat _stat;
	String _str;
	String _strArg;
	String _strAhead;
	String _cmdName;
	StringList _strArgs;
	int _pushbackLevel;
	char _pushbackBuff[16];
	char _chAhead;
	char _chPrev;
	bool _aheadFlag;
	AutoPtr<ElemOwner> _pElemOwner;
	AutoPtr<Elem_Command> _pElemCmdCur;
	AutoPtr<Elem_Composite> _pElemArg;
	std::unique_ptr<Parser> _pParserChild;
public:
	Parser(const Aliases *pAliases, Parser *pParserParent = nullptr);
	void SetCommandSpecial(const CommandFormat *pCmdFmt);
	void SetCommandCustom(const String &cmdName);
	bool FeedChar(Environment &env, char ch);
	bool FeedString(Environment &env, const char *str);
	String EvaluateCustomCommand(Environment &env) const;
	void FlushElemString(const char *str);
	void FlushElemCommand(Elem_Command *pElem);
	ElemOwner &DetermineElemOwner();
	static bool ContainsCommand(const char *str);
	inline void SetElemOwner(ElemOwner *pElemOwner) { _pElemOwner.reset(pElemOwner); }
	inline const ElemOwner &GetElemOwner() const { return *_pElemOwner; }
	inline bool IsTopLevel() const { return _pParserParent == nullptr; }
	inline bool IsComplete() const { return _stat == STAT_Complete; }
	inline const char *GetString() const { return _str.c_str(); }
	inline void Pushback(char ch) {
		if (_pParserParent == nullptr) {
			_pushbackBuff[_pushbackLevel++] = ch;
		} else {
			_pParserParent->Pushback(ch);
		}
	}
	inline void SetAheadFlag(bool aheadFlag) { _aheadFlag = aheadFlag; }
	inline static bool IsCommandEnd(const String &cmdName, char ch) {
		return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' ||
			(!(cmdName == "f" || cmdName.empty()) && (ch == '[' || ch == '{'));
	}
};

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
class Document {
public:
	enum Stat {
		STAT_Indent,
		STAT_Source,
		STAT_LineCommentBgn,
		STAT_LineDoxygenFirstChar,
		STAT_LineDoxygen,
		STAT_LineComment,
		STAT_BlockCommentBgn,
		STAT_BlockCommentBgn_Asterisk,
		STAT_BlockDoxygenFirstChar,
		STAT_BlockDoxygen,
		STAT_BlockDoxygen_Asterisk,
		STAT_BlockDoxygen_Indent,
		STAT_BlockDoxygen_IndentAsterisk,
		STAT_BlockDoxygen_IndentAfterAsterisk,
		STAT_BlockComment,
		STAT_BlockComment_Asterisk,
		STAT_Slash,
		STAT_ExIndent,
		STAT_ExDoxygen,
	};
	enum Region {
		RGN_Other,
		RGN_LineDoxygen,
		RGN_LineDoxygenMixed,
		RGN_BlockDoxygen,
		RGN_BlockDoxygenMixed,
	};
private:
	int _cntRef;
	Stat _stat;
	bool _commentLineFlag;
	Region _regionPrev;
	String _sourceName;
	AutoPtr<StructureOwner> _pStructureOwner;
	std::unique_ptr<Parser> _pParser;
public:
	Gura_DeclareReferenceAccessor(Document);
public:
	Document();
protected:
	inline ~Document() {}
public:
	bool ReadStream(Environment &env, SimpleStream &stream,
					const Aliases *pAliases, bool extractedFlag);
	inline const char *GetSourceName() const { return _sourceName.c_str(); }
	inline const StructureOwner &GetStructureOwner() const { return *_pStructureOwner; }
protected:
	bool FeedChar(Environment &env, char ch);
	void AddStructure();
};

Gura_EndModuleScope(doxygen)

#endif
