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
	virtual ~Elem();
public:
	virtual String GetText() const = 0;
	virtual void Print(int indentLevel = 0) const = 0;
};

//-----------------------------------------------------------------------------
// ElemList
//-----------------------------------------------------------------------------
class ElemList : public std::vector<Elem *> {
public:
	String GetText() const;
	void Print(int indentLevel) const;
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
public:
	Elem_Container();
protected:
	inline ~Elem_Container() {}
public:
	void AddElem(Elem *pElem);
	ElemOwner &GetElemOwner() { return _elemOwner; }
	virtual String GetText() const;
	virtual void Print(int indentLevel) const;
};

//-----------------------------------------------------------------------------
// Elem_Text
//-----------------------------------------------------------------------------
class Elem_Text : public Elem {
private:
	String _str;
public:
	Elem_Text(const String &str);
protected:
	inline ~Elem_Text() {}
	virtual String GetText() const;
	virtual void Print(int indentLevel) const;
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
protected:
	inline ~Elem_Command() {}
public:
	void SetArgElem(Elem *pElem);
	bool NextArg();
	const CommandFormat::Arg *GetArgCur() const;
	virtual String GetText() const;
	virtual void Print(int indentLevel) const;
};

Gura_EndModuleScope(doxygen)

#endif
