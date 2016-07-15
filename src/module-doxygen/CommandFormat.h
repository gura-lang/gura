//=============================================================================
// CommandFormat.h
//=============================================================================
#ifndef __GURA_DOXYGEN_COMMANDFORMAT_H__
#define __GURA_DOXYGEN_COMMANDFORMAT_H__

Gura_BeginModuleScope(doxygen)

class Object_parser;
class CommandFormat;

//-----------------------------------------------------------------------------
// CommandFormatList
//-----------------------------------------------------------------------------
class CommandFormatList : public std::vector<const CommandFormat *> {
};

//-----------------------------------------------------------------------------
// CommandFormatDict
//-----------------------------------------------------------------------------
class CommandFormatDict : public std::map<const String, const CommandFormat *> {
};

//-----------------------------------------------------------------------------
// CommandFormat
//-----------------------------------------------------------------------------
class CommandFormat {
public:
	enum CmdType {
		CMDTYPE_None,
		CMDTYPE_Structure,
		CMDTYPE_Section,
		CMDTYPE_Link,
		CMDTYPE_Example,
		CMDTYPE_Visual,
		CMDTYPE_Group,
		CMDTYPE_Custom,
	};
	enum ArgType {
		ARGTYPE_Word,
		ARGTYPE_WordOpt,
		ARGTYPE_Bracket,
		ARGTYPE_Line,
		ARGTYPE_LineOpt,
		ARGTYPE_Quote,
		ARGTYPE_QuoteOpt,
		ARGTYPE_Brace,
		ARGTYPE_BraceOpt,
		ARGTYPE_Para,
	};
	class Arg {
	protected:
		ArgType _argType;
		String _name;
	public:
		inline Arg(ArgType argType, const char *name) : _argType(argType), _name(name) {}
		inline bool IsWord() const		{ return _argType == ARGTYPE_Word; }
		inline bool IsWordOpt() const	{ return _argType == ARGTYPE_WordOpt; }
		inline bool IsBracket() const	{ return _argType == ARGTYPE_Bracket; }
		inline bool IsLine() const		{ return _argType == ARGTYPE_Line; }
		inline bool IsLineOpt() const	{ return _argType == ARGTYPE_LineOpt; }
		inline bool IsQuote() const		{ return _argType == ARGTYPE_Quote; }
		inline bool IsQuoteOpt() const	{ return _argType == ARGTYPE_QuoteOpt; }
		inline bool IsBrace() const		{ return _argType == ARGTYPE_Brace; }
		inline bool IsBraceOpt() const	{ return _argType == ARGTYPE_BraceOpt; }
		inline bool IsPara() const		{ return _argType == ARGTYPE_Para; }
		const char *GetName() const { return _name.c_str(); }
		ArgType GetArgType() const { return _argType; }
		const char *GetArgTypeName() const { return ArgTypeToName(_argType); }
	};
	class ArgList : public std::vector<Arg *> {
	};
	class ArgOwner : public ArgList {
	public:
		~ArgOwner();
		void Clear();
	};
protected:
	const Symbol *_pSymbol;
	const Symbol *_pSymbolEx;
	CmdType _cmdType;
	ArgOwner _argOwner;
	static CommandFormatList _cmdFmtList;
	static CommandFormatDict _cmdFmtDict;
public:
	inline CommandFormat(CmdType cmdType) : _cmdType(cmdType) {}
	inline CommandFormat(const char *name, CmdType cmdType) :
		_pSymbol(Symbol::Add(name)), _pSymbolEx(Symbol::Add((String("@") + name).c_str())),
		_cmdType(cmdType) {}
	inline CmdType GetType() const { return _cmdType; }
	inline bool IsSpecial() const { return _cmdType != CMDTYPE_Custom; }
	inline bool IsCustom() const { return _cmdType == CMDTYPE_Custom; }
	inline bool IsSectionIndicator() const {
		return _cmdType == CMDTYPE_Section || (!_argOwner.empty() && _argOwner.back()->IsPara());
	}
	inline bool IsLineIndicator() const {
		return !_argOwner.empty() && (_argOwner.back()->IsLine() || _argOwner.back()->IsLineOpt());
	}
	inline void SetName(const char *name) {
		_pSymbol = Symbol::Add(name);
		_pSymbolEx = Symbol::Add((String("@") + name).c_str());
	}
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline const char *GetNameEx() const { return _pSymbolEx->GetName(); }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const Symbol *GetSymbolEx() const { return _pSymbolEx; }
	inline const ArgOwner &GetArgOwner() const { return _argOwner; }
	String MakeHandlerDeclaration() const;
	bool HasNormalCommandName() const;
public:
	static void Initialize();
	static const CommandFormat *Lookup(const char *name);
	static void MakeScript(Environment &env, Stream &stream);
	inline static const CommandFormatList &GetCommandFormatList() {
		return _cmdFmtList;
	}
protected:
	inline static Arg *ArgWord(const char *name) {
		return new Arg(ARGTYPE_Word, name);
	}
	inline static Arg *ArgWordOpt(const char *name) {
		return new Arg(ARGTYPE_WordOpt, name);
	}
	inline static Arg *ArgBracket(const char *name) {
		return new Arg(ARGTYPE_Bracket, name);
	}
	inline static Arg *ArgLine(const char *name) {
		return new Arg(ARGTYPE_Line, name);
	}
	inline static Arg *ArgLineOpt(const char *name) {
		return new Arg(ARGTYPE_LineOpt, name);
	}
	inline static Arg *ArgQuote(const char *name) {
		return new Arg(ARGTYPE_Quote, name);
	}
	inline static Arg *ArgQuoteOpt(const char *name) {
		return new Arg(ARGTYPE_QuoteOpt, name);
	}
	inline static Arg *ArgBrace(const char *name) {
		return new Arg(ARGTYPE_Brace, name);
	}
	inline static Arg *ArgBraceOpt(const char *name) {
		return new Arg(ARGTYPE_BraceOpt, name);
	}
	inline static Arg *ArgPara(const char *name) {
		return new Arg(ARGTYPE_Para, name);
	}
	inline static CommandFormat *Create(const char *name, CmdType cmdType) {
		CommandFormat *pCmdFmt = new CommandFormat(name, cmdType);
		_cmdFmtList.push_back(pCmdFmt);
		_cmdFmtDict[name] = pCmdFmt;
		return pCmdFmt;
	}
	inline static void Register(const char *name, CmdType cmdType) {
		Create(name, cmdType);
	}
	inline static void Register(const char *name, CmdType cmdType, Arg *pArg1) {
		CommandFormat *pCmdFmt = Create(name, cmdType);
		pCmdFmt->_argOwner.reserve(1);
		pCmdFmt->_argOwner.push_back(pArg1);
	}
	inline static void Register(const char *name, CmdType cmdType,
								Arg *pArg1, Arg *pArg2) {
		CommandFormat *pCmdFmt = Create(name, cmdType);
		pCmdFmt->_argOwner.reserve(2);
		pCmdFmt->_argOwner.push_back(pArg1);
		pCmdFmt->_argOwner.push_back(pArg2);
	}
	inline static void Register(const char *name, CmdType cmdType,
								Arg *pArg1, Arg *pArg2, Arg *pArg3) {
		CommandFormat *pCmdFmt = Create(name, cmdType);
		pCmdFmt->_argOwner.reserve(3);
		pCmdFmt->_argOwner.push_back(pArg1);
		pCmdFmt->_argOwner.push_back(pArg2);
		pCmdFmt->_argOwner.push_back(pArg3);
	}
	inline static void Register(const char *name, CmdType cmdType,
								Arg *pArg1, Arg *pArg2, Arg *pArg3, Arg *pArg4) {
		CommandFormat *pCmdFmt = Create(name, cmdType);
		pCmdFmt->_argOwner.reserve(4);
		pCmdFmt->_argOwner.push_back(pArg1);
		pCmdFmt->_argOwner.push_back(pArg2);
		pCmdFmt->_argOwner.push_back(pArg3);
		pCmdFmt->_argOwner.push_back(pArg4);
	}
	static const char *ArgTypeToName(ArgType argType);
};

Gura_EndModuleScope(doxygen)

#endif
