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
			TYPE_Word, TYPE_Line, TYPE_Para,
		};
		enum Attr {
			ATTR_Mandatory, ATTR_Optional, ATTR_OptionalBracket,
		};
	protected:
		Type _type;
		String _name;
		Attr _attr;
	public:
		inline Arg(Type type, const char *name, Attr attr) :
			_type(type), _name(name), _attr(attr) {}
		inline bool IsMandatory() const { return _attr == ATTR_Mandatory; }
		inline bool IsOptional() const { return _attr == ATTR_Optional; }
		inline bool IsOptionalBracket() const { return _attr == ATTR_OptionalBracket; }
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
protected:
	inline static Arg *ArgWord(const char *name, Arg::Attr attr = Arg::ATTR_Mandatory) {
		return new Arg(Arg::TYPE_Word, name, attr);
	}
	inline static Arg *ArgLine(const char *name, Arg::Attr attr = Arg::ATTR_Mandatory) {
		return new Arg(Arg::TYPE_Line, name, attr);
	}
	inline static Arg *ArgPara(const char *name, Arg::Attr attr = Arg::ATTR_Mandatory) {
		return new Arg(Arg::TYPE_Para, name, attr);
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
public:
	static void Initialize();
};

Gura_EndModuleScope(doxygen)

#endif
