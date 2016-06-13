//=============================================================================
// CommandFormat.h
//=============================================================================
#ifndef __GURA_DOXYGEN_COMMANDFORMAT_H__
#define __GURA_DOXYGEN_COMMANDFORMAT_H__

Gura_BeginModuleScope(doxygen)

class CommandFormat;

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
		CMDTYPE_Structure,
		CMDTYPE_Section,
		CMDTYPE_Link,
		CMDTYPE_Example,
		CMDTYPE_Visual,
	};
	enum ArgType {
		ARGTYPE_Word,
		ARGTYPE_WordOpt,
		ARGTYPE_Bracket,
		ARGTYPE_Line,
		ARGTYPE_LineOpt,
		ARGTYPE_Quoted,
		ARGTYPE_QuotedOpt,
		ARGTYPE_Para,
		ARGTYPE_ParaOpt,
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
		inline bool IsQuoted() const	{ return _argType == ARGTYPE_Quoted; }
		inline bool IsQuotedOpt() const	{ return _argType == ARGTYPE_QuotedOpt; }
		inline bool IsPara() const		{ return _argType == ARGTYPE_Para; }
		inline bool IsParaOpt() const	{ return _argType == ARGTYPE_ParaOpt; }
		const char *GetName() const { return _name.c_str(); }
	};
	class ArgList : public std::vector<Arg *> {
	};
	class ArgOwner : public ArgList {
	public:
		~ArgOwner();
		void Clear();
	};
protected:
	String _name;
	CmdType _cmdType;
	ArgOwner _argOwner;
	static std::unique_ptr<CommandFormatDict> _pCmdFmtDict;
public:
	inline CommandFormat(const char *name, CmdType cmdType) : _name(name), _cmdType(cmdType) {}
	inline bool IsStructure() const	{ return _cmdType == CMDTYPE_Structure; }
	inline bool IsSection() const	{ return _cmdType == CMDTYPE_Section; }
	inline bool IsLink() const		{ return _cmdType == CMDTYPE_Link; }
	inline bool IsExample() const	{ return _cmdType == CMDTYPE_Example; }
	inline bool IsVisual() const	{ return _cmdType == CMDTYPE_Visual; }
	inline const char *GetName() const { return _name.c_str(); }
	inline const ArgOwner &GetArgOwner() const { return _argOwner; }
public:
	static void Initialize();
	static const CommandFormat *Lookup(const char *name);
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
	inline static Arg *ArgQuoted(const char *name) {
		return new Arg(ARGTYPE_Quoted, name);
	}
	inline static Arg *ArgQuotedOpt(const char *name) {
		return new Arg(ARGTYPE_QuotedOpt, name);
	}
	inline static Arg *ArgPara(const char *name) {
		return new Arg(ARGTYPE_Para, name);
	}
	inline static Arg *ArgParaOpt(const char *name) {
		return new Arg(ARGTYPE_ParaOpt, name);
	}
	inline static CommandFormat *Create(const char *name, CmdType cmdType) {
		CommandFormat *pCmdFmt = new CommandFormat(name, cmdType);
		(*_pCmdFmtDict)[name] = pCmdFmt;
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
};

Gura_EndModuleScope(doxygen)

#endif
