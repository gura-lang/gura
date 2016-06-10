//=============================================================================
// Commands.h
//=============================================================================
#ifndef __GURA_DOXYGEN_COMMAND_H__
#define __GURA_DOXYGEN_COMMAND_H__

Gura_BeginModuleScope(doxygen)

class CommandDict;

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
// Command
//-----------------------------------------------------------------------------
class Command {
protected:
	String _name;
	ArgOwner _argOwner;
	static std::unique_ptr<CommandDict> _pCmdDict;
public:
	inline Command(const char *name) : _name(name) {}
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
	inline static Command *Create(const char *name) {
		Command *pCmd = new Command(name);
		return pCmd;
	}
	inline static Command *Create(const char *name, Arg *pArg1) {
		Command *pCmd = new Command(name);
		pCmd->_argOwner.reserve(1);
		pCmd->_argOwner.push_back(pArg1);
		return pCmd;
	}
	inline static Command *Create(const char *name, Arg *pArg1, Arg *pArg2) {
		Command *pCmd = new Command(name);
		pCmd->_argOwner.reserve(2);
		pCmd->_argOwner.push_back(pArg1);
		pCmd->_argOwner.push_back(pArg2);
		return pCmd;
	}
	inline static Command *Create(const char *name, Arg *pArg1, Arg *pArg2, Arg *pArg3) {
		Command *pCmd = new Command(name);
		pCmd->_argOwner.reserve(3);
		pCmd->_argOwner.push_back(pArg1);
		pCmd->_argOwner.push_back(pArg2);
		pCmd->_argOwner.push_back(pArg3);
		return pCmd;
	}
	inline static Command *Create(const char *name, Arg *pArg1, Arg *pArg2, Arg *pArg3, Arg *pArg4) {
		Command *pCmd = new Command(name);
		pCmd->_argOwner.reserve(4);
		pCmd->_argOwner.push_back(pArg1);
		pCmd->_argOwner.push_back(pArg2);
		pCmd->_argOwner.push_back(pArg3);
		pCmd->_argOwner.push_back(pArg4);
		return pCmd;
	}
public:
	static void Initialize();
};

//-----------------------------------------------------------------------------
// CommandDict
//-----------------------------------------------------------------------------
class CommandDict : public std::map<const String, const Command *> {
};

Gura_EndModuleScope(doxygen)

#endif
