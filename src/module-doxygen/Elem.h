//=============================================================================
// Elem.h
//=============================================================================
#ifndef __GURA_DOXYGEN_ELEM_H__
#define __GURA_DOXYGEN_ELEM_H__

Gura_BeginModuleScope(doxygen)

class Renderer;
class Configuration;

//-----------------------------------------------------------------------------
// Elem
//-----------------------------------------------------------------------------
class Elem {
public:
	enum Type {
		TYPE_None,
		TYPE_Composite,
		TYPE_Empty,
		TYPE_String,
		TYPE_Command,
	};
protected:
	int _cntRef;
	Type _type;
public:
	static const Elem *Empty;
public:
	Gura_DeclareReferenceAccessor(Elem);
public:
	Elem(Type type);
protected:
	virtual ~Elem();
public:
	inline Type GetType() const { return _type; }
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const = 0;
	virtual String ToString() const = 0;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const = 0;
	static void Initialize();
};

//-----------------------------------------------------------------------------
// ElemList
//-----------------------------------------------------------------------------
class ElemList : public std::vector<Elem *> {
public:
	bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const;
	void Print(Environment &env, SimpleStream &stream, int indentLevel) const;
};

//-----------------------------------------------------------------------------
// ElemOwner
//-----------------------------------------------------------------------------
class ElemOwner : public ElemList {
protected:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(ElemOwner);
public:
	ElemOwner();
protected:
	~ElemOwner();
public:
	void Clear();
};

//-----------------------------------------------------------------------------
// Elem_Composite
//-----------------------------------------------------------------------------
class Elem_Composite : public Elem {
protected:
	AutoPtr<ElemOwner> _pElemOwner;
public:
	Elem_Composite(Type type = TYPE_Composite);
	Elem_Composite(ElemOwner *pElemOwner, Type type = TYPE_Composite);
	const Elem *ReduceContent() const;
	inline void AddElem(Elem *pElem) { _pElemOwner->push_back(pElem); }
	inline ElemOwner &GetElemOwner() { return *_pElemOwner; }
	inline const ElemOwner &GetElemOwner() const { return *_pElemOwner; }
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const;
	virtual String ToString() const;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const;
};

//-----------------------------------------------------------------------------
// Elem_Empty
//-----------------------------------------------------------------------------
class Elem_Empty : public Elem {
public:
	Elem_Empty(Type type = TYPE_Empty);
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const;
	virtual String ToString() const;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const;
};

//-----------------------------------------------------------------------------
// Elem_String
//-----------------------------------------------------------------------------
class Elem_String : public Elem {
protected:
	String _str;
public:
	Elem_String(const String &str, Type type = TYPE_String);
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const;
	virtual String ToString() const;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const;
};

//-----------------------------------------------------------------------------
// Elem_Command
//-----------------------------------------------------------------------------
class Elem_Command : public Elem {
protected:
	const CommandFormat *_pCmdFmt;
	AutoPtr<ElemOwner> _pElemArgs;
public:
	Elem_Command(const CommandFormat *pCmdFmt, Type type = TYPE_Command);
	inline const CommandFormat *GetCommandFormat() const { return _pCmdFmt; }
	inline void AddArg(Elem *pElem) { _pElemArgs->push_back(pElem); }
	inline const ElemOwner &GetElemArgs() const { return *_pElemArgs; }
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const;
	virtual String ToString() const;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const;
};

//-----------------------------------------------------------------------------
// Iterator_Elem
//-----------------------------------------------------------------------------
class Iterator_Elem : public Iterator {
protected:
	AutoPtr<ElemOwner> _pElemOwner;
	size_t _idx;
public:
	Iterator_Elem(ElemOwner *pElemOwner);
	Iterator_Elem(const Iterator_Elem &iter);
	virtual Iterator *Clone() const;
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleScope(doxygen)

#endif
