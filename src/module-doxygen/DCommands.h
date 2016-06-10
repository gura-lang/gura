//=============================================================================
// Commands.h
//=============================================================================
#ifndef __GURA_DOXYGEN_COMMANDS_H__
#define __GURA_DOXYGEN_COMMANDS_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Arg
//-----------------------------------------------------------------------------
class Arg {
protected:
	String _name;
	bool _optionalFlag;
public:
	inline Arg(const char *name, bool optionalFlag) :
		_name(name), _optionalFlag(optionalFlag) {}
	
};

//-----------------------------------------------------------------------------
// ArgWord
//-----------------------------------------------------------------------------
class ArgWord : public Arg {
public:
	inline ArgWord(const char *name, bool optionalFlag = false) : Arg(name, optionalFlag) {}
};

//-----------------------------------------------------------------------------
// ArgLine
//-----------------------------------------------------------------------------
class ArgLine : public Arg {
public:
	inline ArgLine(const char *name, bool optionalFlag = false) : Arg(name, optionalFlag) {}
};

//-----------------------------------------------------------------------------
// ArgPara
//-----------------------------------------------------------------------------
class ArgPara : public Arg {
public:
	inline ArgPara(const char *name, bool optionalFlag = false) : Arg(name, optionalFlag) {}
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
	ArgOwner _dargOwner;
public:
	inline Command(const char *name) {}
	inline Command(const char *name, Arg *pArg1) {
		_dargOwner.reserve(1);
		_dargOwner.push_back(pArg1);
	}
	inline Command(const char *name, Arg *pArg1, Arg *pArg2) {
		_dargOwner.reserve(2);
		_dargOwner.push_back(pArg1);
		_dargOwner.push_back(pArg2);
	}
	inline Command(const char *name, Arg *pArg1, Arg *pArg2, Arg *pArg3) {
		_dargOwner.reserve(3);
		_dargOwner.push_back(pArg1);
		_dargOwner.push_back(pArg2);
		_dargOwner.push_back(pArg3);
	}
	inline Command(const char *name, Arg *pArg1, Arg *pArg2, Arg *pArg3, Arg *pArg4) {
		_dargOwner.reserve(4);
		_dargOwner.push_back(pArg1);
		_dargOwner.push_back(pArg2);
		_dargOwner.push_back(pArg3);
		_dargOwner.push_back(pArg4);
	}
	inline Command(const char *name, Arg *pArg1, Arg *pArg2, Arg *pArg3, Arg *pArg4, Arg *pArg5) {
		_dargOwner.reserve(5);
		_dargOwner.push_back(pArg1);
		_dargOwner.push_back(pArg2);
		_dargOwner.push_back(pArg3);
		_dargOwner.push_back(pArg4);
		_dargOwner.push_back(pArg5);
	}
public:
	static void Initialize();
};

Gura_EndModuleScope(doxygen)

#endif
