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
	class ArgIndexMap : public std::map<const Symbol *, int> {
	};
	class EndDetector {
	protected:
		StringSet _namesEnd;
	public:
		bool IsEndCommand(const char *name) const;
		inline StringSet &GetNamesEnd() { return _namesEnd; }
		inline const StringSet &GetNamesEnd() const { return _namesEnd; }
	};
protected:
	const Symbol *_pSymbol;
	const Symbol *_pSymbolEx;
	CmdType _cmdType;
	std::unique_ptr<EndDetector> _pEndDetector;
	ArgOwner _argOwner;
	ArgIndexMap _argIndexMap;
	static CommandFormatList _cmdFmtList;
	static CommandFormatDict _cmdFmtDict;
public:
	static const CommandFormat *Brief;
public:
	inline CommandFormat(CmdType cmdType) : _cmdType(cmdType) {}
	inline CommandFormat(const char *name, CmdType cmdType, EndDetector *pEndDetector) :
		_pSymbol(Symbol::Add(name)), _pSymbolEx(Symbol::Add((String("@") + name).c_str())),
		_cmdType(cmdType), _pEndDetector(pEndDetector) {}
	inline CmdType GetType() const { return _cmdType; }
	inline bool IsStructure() const		{ return _cmdType == CMDTYPE_Structure; }
	inline bool IsSection() const		{ return _cmdType == CMDTYPE_Section; }
	inline bool IsLink() const			{ return _cmdType == CMDTYPE_Link; }
	inline bool IsExample() const		{ return _cmdType == CMDTYPE_Example; }
	inline bool IsVisual() const		{ return _cmdType == CMDTYPE_Visual; }
	inline bool IsGroup() const			{ return _cmdType == CMDTYPE_Group; }
	inline bool IsCustom() const		{ return _cmdType == CMDTYPE_Custom; }
	inline bool IsSpecial() const		{ return _cmdType != CMDTYPE_Custom; }
	inline bool IsSectionIndicator() const {
		return _cmdType == CMDTYPE_Section || (!_argOwner.empty() && _argOwner.back()->IsPara());
	}
	inline bool IsLineIndicator() const {
		return !_argOwner.empty() && (_argOwner.back()->IsLine() || _argOwner.back()->IsLineOpt());
	}
	inline const EndDetector *GetEndDetector() const { return _pEndDetector.get(); }
	inline bool IsEndCommand(const char *name) const {
		return _pEndDetector.get() != nullptr && _pEndDetector->IsEndCommand(name);
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
	inline int GetArgIndex(const Symbol *pSymbol) const {
		ArgIndexMap::const_iterator iter = _argIndexMap.find(pSymbol);
		return (iter == _argIndexMap.end())? -1 : iter->second;
	}
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
	void ReserveArgOwner(size_t nArgs) {
		_argOwner.reserve(nArgs);
	}
	void AddArg(Arg *pArg) {
		_argIndexMap[Symbol::Add(pArg->GetName())] = static_cast<int>(_argOwner.size());
		_argOwner.push_back(pArg);
	}
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
	inline static EndDetector *End(const String &name) {
		std::unique_ptr<EndDetector> pEndDetector(new EndDetector());
		StringSet &namesEnd = pEndDetector->GetNamesEnd();
		namesEnd.insert(name);
		return pEndDetector.release();
	}
	inline static EndDetector *End(const String &name1, const String &name2) {
		std::unique_ptr<EndDetector> pEndDetector(new EndDetector());
		StringSet &namesEnd = pEndDetector->GetNamesEnd();
		namesEnd.insert(name1);
		namesEnd.insert(name2);
		return pEndDetector.release();
	}
	inline static EndDetector *End(const String &name1, const String &name2, const String &name3) {
		std::unique_ptr<EndDetector> pEndDetector(new EndDetector());
		StringSet &namesEnd = pEndDetector->GetNamesEnd();
		namesEnd.insert(name1);
		namesEnd.insert(name2);
		namesEnd.insert(name3);
		return pEndDetector.release();
	}
	inline static CommandFormat *Create(const char *name, CmdType cmdType, EndDetector *pEndDetector) {
		CommandFormat *pCmdFmt = new CommandFormat(name, cmdType, pEndDetector);
		_cmdFmtList.push_back(pCmdFmt);
		_cmdFmtDict[name] = pCmdFmt;
		return pCmdFmt;
	}
	inline static CommandFormat *Register(const char *name, CmdType cmdType, EndDetector *pEndDetector) {
		CommandFormat *pCmdFmt = Create(name, cmdType, pEndDetector);
		return pCmdFmt;
	}
	inline static CommandFormat *Register(const char *name, CmdType cmdType, EndDetector *pEndDetector, Arg *pArg1) {
		CommandFormat *pCmdFmt = Create(name, cmdType, pEndDetector);
		pCmdFmt->ReserveArgOwner(1);
		pCmdFmt->AddArg(pArg1);
		return pCmdFmt;
	}
	inline static CommandFormat *Register(const char *name, CmdType cmdType, EndDetector *pEndDetector,
								Arg *pArg1, Arg *pArg2) {
		CommandFormat *pCmdFmt = Create(name, cmdType, pEndDetector);
		pCmdFmt->ReserveArgOwner(2);
		pCmdFmt->AddArg(pArg1);
		pCmdFmt->AddArg(pArg2);
		return pCmdFmt;
	}
	inline static CommandFormat *Register(const char *name, CmdType cmdType, EndDetector *pEndDetector,
								Arg *pArg1, Arg *pArg2, Arg *pArg3) {
		CommandFormat *pCmdFmt = Create(name, cmdType, pEndDetector);
		pCmdFmt->ReserveArgOwner(3);
		pCmdFmt->AddArg(pArg1);
		pCmdFmt->AddArg(pArg2);
		pCmdFmt->AddArg(pArg3);
		return pCmdFmt;
	}
	inline static CommandFormat *Register(const char *name, CmdType cmdType, EndDetector *pEndDetector,
								Arg *pArg1, Arg *pArg2, Arg *pArg3, Arg *pArg4) {
		CommandFormat *pCmdFmt = Create(name, cmdType, pEndDetector);
		pCmdFmt->ReserveArgOwner(4);
		pCmdFmt->AddArg(pArg1);
		pCmdFmt->AddArg(pArg2);
		pCmdFmt->AddArg(pArg3);
		pCmdFmt->AddArg(pArg4);
		return pCmdFmt;
	}
	static const char *ArgTypeToName(ArgType argType);
};

Gura_EndModuleScope(doxygen)

#endif
