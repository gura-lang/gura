//=============================================================================
// Commands.h
//=============================================================================
#ifndef __GURA_DOXYGEN_COMMAND_H__
#define __GURA_DOXYGEN_COMMAND_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Arg
//-----------------------------------------------------------------------------
class Arg {
public:
	enum Type {
		TYPE_Word, TYPE_Line, TYPE_Para,
	};
protected:
	Type _type;
	String _name;
	bool _optionalFlag;
public:
	inline Arg(Type type, const char *name, bool optionalFlag) :
		_type(type), _name(name), _optionalFlag(optionalFlag) {}
	
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
protected:
	inline static Arg *ArgWord(const char *name, bool optionalFlag = false) {
		return new Arg(Arg::TYPE_Word, name, optionalFlag);
	}
	inline static Arg *ArgLine(const char *name, bool optionalFlag = false) {
		return new Arg(Arg::TYPE_Line, name, optionalFlag);
	}
	inline static Arg *ArgPara(const char *name, bool optionalFlag = false) {
		return new Arg(Arg::TYPE_Para, name, optionalFlag);
	}
public:
	inline Command(const char *name) : _name(name) {}
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

Gura_EndModuleScope(doxygen)

#endif
