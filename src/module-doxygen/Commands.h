//=============================================================================
// Commands.h
//=============================================================================
#ifndef __GURA_DOXYGEN_COMMANDS_H__
#define __GURA_DOXYGEN_COMMANDS_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// DArg
//-----------------------------------------------------------------------------
class DArg {
protected:
	String _name;
	bool _optionalFlag;
public:
	inline DArg(const char *name, bool optionalFlag) :
		_name(name), _optionalFlag(optionalFlag) {}
	
};

//-----------------------------------------------------------------------------
// DArgWord
//-----------------------------------------------------------------------------
class DArgWord : public DArg {
public:
	inline DArgWord(const char *name, bool optionalFlag = false) : DArg(name, optionalFlag) {}
};

//-----------------------------------------------------------------------------
// DArgLine
//-----------------------------------------------------------------------------
class DArgLine : public DArg {
public:
	inline DArgLine(const char *name, bool optionalFlag = false) : DArg(name, optionalFlag) {}
};

//-----------------------------------------------------------------------------
// DArgPara
//-----------------------------------------------------------------------------
class DArgPara : public DArg {
public:
	inline DArgPara(const char *name, bool optionalFlag = false) : DArg(name, optionalFlag) {}
};

//-----------------------------------------------------------------------------
// DArgList
//-----------------------------------------------------------------------------
class DArgList : public std::vector<DArg *> {
};

//-----------------------------------------------------------------------------
// DArgOwner
//-----------------------------------------------------------------------------
class DArgOwner : public DArgList {
public:
	~DArgOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Command
//-----------------------------------------------------------------------------
class Command {
protected:
	DArgOwner _dargOwner;
public:
	inline Command(const char *name) {}
	inline Command(const char *name, DArg *pDArg1) {
		_dargOwner.reserve(1);
		_dargOwner.push_back(pDArg1);
	}
	inline Command(const char *name, DArg *pDArg1, DArg *pDArg2) {
		_dargOwner.reserve(2);
		_dargOwner.push_back(pDArg1);
		_dargOwner.push_back(pDArg2);
	}
	inline Command(const char *name, DArg *pDArg1, DArg *pDArg2, DArg *pDArg3) {
		_dargOwner.reserve(3);
		_dargOwner.push_back(pDArg1);
		_dargOwner.push_back(pDArg2);
		_dargOwner.push_back(pDArg3);
	}
	inline Command(const char *name, DArg *pDArg1, DArg *pDArg2, DArg *pDArg3, DArg *pDArg4) {
		_dargOwner.reserve(4);
		_dargOwner.push_back(pDArg1);
		_dargOwner.push_back(pDArg2);
		_dargOwner.push_back(pDArg3);
		_dargOwner.push_back(pDArg4);
	}
	inline Command(const char *name, DArg *pDArg1, DArg *pDArg2, DArg *pDArg3, DArg *pDArg4, DArg *pDArg5) {
		_dargOwner.reserve(5);
		_dargOwner.push_back(pDArg1);
		_dargOwner.push_back(pDArg2);
		_dargOwner.push_back(pDArg3);
		_dargOwner.push_back(pDArg4);
		_dargOwner.push_back(pDArg5);
	}
public:
	static void Initialize();
};

Gura_EndModuleScope(doxygen)

#endif
