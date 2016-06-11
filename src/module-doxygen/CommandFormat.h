//=============================================================================
// CommandFormat.h
//=============================================================================
#ifndef __GURA_DOXYGEN_COMMANDFORMAT_H__
#define __GURA_DOXYGEN_COMMANDFORMAT_H__

Gura_BeginModuleScope(doxygen)

class CommandFormatDict;

//-----------------------------------------------------------------------------
// Arg
//-----------------------------------------------------------------------------
class Arg {
public:
	enum Type {
		TYPE_Word, TYPE_Line, TYPE_Para,
	};
	enum Attr {
		ATTR_None, ATTR_Optional, ATTR_OptionalBracket,
	};
protected:
	Type _type;
	String _name;
	Attr _attr;
public:
	inline Arg(Type type, const char *name, Attr attr) :
		_type(type), _name(name), _attr(attr) {}
	
};

//-----------------------------------------------------------------------------
// ArgList
//-----------------------------------------------------------------------------
class ArgList : public std::vector<Arg *> {
};

//-----------------------------------------------------------------------------
// ArgOwner
//-----------------------------------------------------------------------------
class ArgOwner : public ArgList {
public:
	~ArgOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// CommandFormat
//-----------------------------------------------------------------------------
class CommandFormat {
protected:
	String _name;
	ArgOwner _argOwner;
	static std::unique_ptr<CommandFormatDict> _pCmdFmtDict;
public:
	inline CommandFormat(const char *name) : _name(name) {}
	inline const char *GetName() const { return _name.c_str(); }
protected:
	inline static Arg *ArgWord(const char *name, Arg::Attr attr = Arg::ATTR_None) {
		return new Arg(Arg::TYPE_Word, name, attr);
	}
	inline static Arg *ArgLine(const char *name, Arg::Attr attr = Arg::ATTR_None) {
		return new Arg(Arg::TYPE_Line, name, attr);
	}
	inline static Arg *ArgPara(const char *name, Arg::Attr attr = Arg::ATTR_None) {
		return new Arg(Arg::TYPE_Para, name, attr);
	}
	inline static CommandFormat *Create(const char *name) {
		CommandFormat *pCmdFmt = new CommandFormat(name);
		return pCmdFmt;
	}
	inline static CommandFormat *Create(const char *name, Arg *pArg1) {
		CommandFormat *pCmdFmt = new CommandFormat(name);
		pCmdFmt->_argOwner.reserve(1);
		pCmdFmt->_argOwner.push_back(pArg1);
		return pCmdFmt;
	}
	inline static CommandFormat *Create(const char *name, Arg *pArg1, Arg *pArg2) {
		CommandFormat *pCmdFmt = new CommandFormat(name);
		pCmdFmt->_argOwner.reserve(2);
		pCmdFmt->_argOwner.push_back(pArg1);
		pCmdFmt->_argOwner.push_back(pArg2);
		return pCmdFmt;
	}
	inline static CommandFormat *Create(const char *name, Arg *pArg1, Arg *pArg2, Arg *pArg3) {
		CommandFormat *pCmdFmt = new CommandFormat(name);
		pCmdFmt->_argOwner.reserve(3);
		pCmdFmt->_argOwner.push_back(pArg1);
		pCmdFmt->_argOwner.push_back(pArg2);
		pCmdFmt->_argOwner.push_back(pArg3);
		return pCmdFmt;
	}
	inline static CommandFormat *Create(const char *name, Arg *pArg1, Arg *pArg2, Arg *pArg3, Arg *pArg4) {
		CommandFormat *pCmdFmt = new CommandFormat(name);
		pCmdFmt->_argOwner.reserve(4);
		pCmdFmt->_argOwner.push_back(pArg1);
		pCmdFmt->_argOwner.push_back(pArg2);
		pCmdFmt->_argOwner.push_back(pArg3);
		pCmdFmt->_argOwner.push_back(pArg4);
		return pCmdFmt;
	}
public:
	static void Initialize();
};

//-----------------------------------------------------------------------------
// CommandFormatDict
//-----------------------------------------------------------------------------
class CommandFormatDict : public std::map<const String, const CommandFormat *> {
};

Gura_EndModuleScope(doxygen)

#endif
