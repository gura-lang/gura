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
protected:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(Elem);
public:
	Elem();
protected:
	inline ~Elem() {}
	virtual String ToString() const = 0;
};

//-----------------------------------------------------------------------------
// ElemList
//-----------------------------------------------------------------------------
class ElemList : public std::vector<Elem *> {
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
// Elem_Container
//-----------------------------------------------------------------------------
class Elem_Container : public Elem {
protected:
	ElemOwner _elemOwner;
public:
	Elem_Container();
	inline void AddElem(Elem *pElem) { _elemOwner.push_back(pElem); }
	inline const ElemOwner &GetElemOwner() const { return _elemOwner; }
	virtual String ToString() const;
};

//-----------------------------------------------------------------------------
// Elem_Text
//-----------------------------------------------------------------------------
class Elem_Text : public Elem {
protected:
	String _text;
public:
	Elem_Text(const String &text);
	virtual String ToString() const;
};

//-----------------------------------------------------------------------------
// Elem_Command
//-----------------------------------------------------------------------------
class Elem_Command : public Elem {
protected:
	const CommandFormat *_pCmdFmt;
	ElemOwner _elemArgs;
public:
	Elem_Command(const CommandFormat *pCmdFmt);
	inline const CommandFormat *GetCommandFormat() const { return _pCmdFmt; }
	inline void AddArg(Elem *pElem) { _elemArgs.push_back(pElem); }
	inline const ElemOwner &GetElemArgs() const { return _elemArgs; }
	virtual String ToString() const;
};

Gura_EndModuleScope(doxygen)

#endif
