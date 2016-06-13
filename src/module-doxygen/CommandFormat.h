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
	class Arg {
	public:
		enum Type {
			TYPE_Word,
			TYPE_WordOpt,
			TYPE_Bracket,
			TYPE_Line,
			TYPE_LineOpt,
			TYPE_Quoted,
			TYPE_QuotedOpt,
			TYPE_Para,
			TYPE_ParaOpt,
		};
	protected:
		Type _type;
		String _name;
	public:
		inline Arg(Type type, const char *name) : _type(type), _name(name) {}
		inline bool IsWord() const		{ return _type == TYPE_Word; }
		inline bool IsWordOpt() const	{ return _type == TYPE_WordOpt; }
		inline bool IsBracket() const	{ return _type == TYPE_Bracket; }
		inline bool IsLine() const		{ return _type == TYPE_Line; }
		inline bool IsLineOpt() const	{ return _type == TYPE_LineOpt; }
		inline bool IsQuoted() const	{ return _type == TYPE_Quoted; }
		inline bool IsQuotedOpt() const	{ return _type == TYPE_QuotedOpt; }
		inline bool IsPara() const		{ return _type == TYPE_Para; }
		inline bool IsParaOpt() const	{ return _type == TYPE_ParaOpt; }
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
	ArgOwner _argOwner;
	static std::unique_ptr<CommandFormatDict> _pCmdFmtDict;
public:
	inline CommandFormat(const char *name) : _name(name) {}
	inline const char *GetName() const { return _name.c_str(); }
	inline const ArgOwner &GetArgOwner() const { return _argOwner; }
public:
	static void Initialize();
	static const CommandFormat *Lookup(const char *name);
protected:
	inline static Arg *ArgWord(const char *name) {
		return new Arg(Arg::TYPE_Word, name);
	}
	inline static Arg *ArgWordOpt(const char *name) {
		return new Arg(Arg::TYPE_WordOpt, name);
	}
	inline static Arg *ArgBracket(const char *name) {
		return new Arg(Arg::TYPE_Bracket, name);
	}
	inline static Arg *ArgLine(const char *name) {
		return new Arg(Arg::TYPE_Line, name);
	}
	inline static Arg *ArgLineOpt(const char *name) {
		return new Arg(Arg::TYPE_LineOpt, name);
	}
	inline static Arg *ArgQuoted(const char *name) {
		return new Arg(Arg::TYPE_Quoted, name);
	}
	inline static Arg *ArgQuotedOpt(const char *name) {
		return new Arg(Arg::TYPE_QuotedOpt, name);
	}
	inline static Arg *ArgPara(const char *name) {
		return new Arg(Arg::TYPE_Para, name);
	}
	inline static Arg *ArgParaOpt(const char *name) {
		return new Arg(Arg::TYPE_ParaOpt, name);
	}
	inline static CommandFormat *Create(const char *name) {
		CommandFormat *pCmdFmt = new CommandFormat(name);
		(*_pCmdFmtDict)[name] = pCmdFmt;
		return pCmdFmt;
	}
	inline static void Register(const char *name) {
		Create(name);
	}
	inline static void Register(const char *name, Arg *pArg1) {
		CommandFormat *pCmdFmt = Create(name);
		pCmdFmt->_argOwner.reserve(1);
		pCmdFmt->_argOwner.push_back(pArg1);
	}
	inline static void Register(const char *name, Arg *pArg1, Arg *pArg2) {
		CommandFormat *pCmdFmt = Create(name);
		pCmdFmt->_argOwner.reserve(2);
		pCmdFmt->_argOwner.push_back(pArg1);
		pCmdFmt->_argOwner.push_back(pArg2);
	}
	inline static void Register(const char *name, Arg *pArg1, Arg *pArg2, Arg *pArg3) {
		CommandFormat *pCmdFmt = Create(name);
		pCmdFmt->_argOwner.reserve(3);
		pCmdFmt->_argOwner.push_back(pArg1);
		pCmdFmt->_argOwner.push_back(pArg2);
		pCmdFmt->_argOwner.push_back(pArg3);
	}
	inline static void Register(const char *name, Arg *pArg1, Arg *pArg2, Arg *pArg3, Arg *pArg4) {
		CommandFormat *pCmdFmt = Create(name);
		pCmdFmt->_argOwner.reserve(4);
		pCmdFmt->_argOwner.push_back(pArg1);
		pCmdFmt->_argOwner.push_back(pArg2);
		pCmdFmt->_argOwner.push_back(pArg3);
		pCmdFmt->_argOwner.push_back(pArg4);
	}
};

Gura_EndModuleScope(doxygen)

#endif
