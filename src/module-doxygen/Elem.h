//=============================================================================
// Elem.h
//=============================================================================
#ifndef __GURA_DOXYGEN_ELEM_H__
#define __GURA_DOXYGEN_ELEM_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Elem
//-----------------------------------------------------------------------------
class Elem {
};

//-----------------------------------------------------------------------------
// ElemList
//-----------------------------------------------------------------------------
class ElemList : public std::vector<Elem *> {
};

//-----------------------------------------------------------------------------
// ElemDict
//-----------------------------------------------------------------------------
class ElemDict : public std::map<String, Elem *> {
};

//-----------------------------------------------------------------------------
// ElemOwner
//-----------------------------------------------------------------------------
class ElemOwner : public ElemList {
public:
	~ElemOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// ElemDictOwner
//-----------------------------------------------------------------------------
class ElemDictOwner : public ElemDict {
public:
	~ElemDictOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Elem_Container
//-----------------------------------------------------------------------------
class Elem_Container : public Elem {
private:
	ElemOwner _elemOwner;
};

//-----------------------------------------------------------------------------
// Elem_Text
//-----------------------------------------------------------------------------
class Elem_Text : public Elem {
private:
	String _str;
public:
	Elem_Text(const String &str);
};

//-----------------------------------------------------------------------------
// Elem_Command
//-----------------------------------------------------------------------------
class Elem_Command : public Elem {
private:
	const CommandFormat *_pCmdFmt;
	ElemDictOwner _elemDictArg;
	int _iArg;
public:
	Elem_Command(const CommandFormat *pCmdFmt);
	void SetArgElem(Elem *pElem);
	const CommandFormat::Arg *NextArg();
	const CommandFormat::Arg *GetArgCur() const;
};

Gura_EndModuleScope(doxygen)

#endif
