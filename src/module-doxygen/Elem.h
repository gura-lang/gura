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
		TYPE_Container,
		TYPE_Structure,
		TYPE_Empty,
		TYPE_Text,
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
	Elem_Container(Type type = TYPE_Container);
	const Elem *ReduceContent() const;
	inline void AddElem(Elem *pElem) { _elemOwner.push_back(pElem); }
	inline ElemOwner &GetElemOwner() { return _elemOwner; }
	inline const ElemOwner &GetElemOwner() const { return _elemOwner; }
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const;
	virtual String ToString() const;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const;
};

//-----------------------------------------------------------------------------
// Elem_Structure
//-----------------------------------------------------------------------------
class Elem_Structure : public Elem_Container {
public:
	Elem_Structure(Type type = TYPE_Structure);
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
// Elem_Text
//-----------------------------------------------------------------------------
class Elem_Text : public Elem {
protected:
	String _text;
public:
	Elem_Text(const String &text, Type type = TYPE_Text);
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
	ElemOwner _elemArgs;
public:
	Elem_Command(const CommandFormat *pCmdFmt, Type type = TYPE_Command);
	inline const CommandFormat *GetCommandFormat() const { return _pCmdFmt; }
	inline void AddArg(Elem *pElem) { _elemArgs.push_back(pElem); }
	inline const ElemOwner &GetElemArgs() const { return _elemArgs; }
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const;
	virtual String ToString() const;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const;
};

Gura_EndModuleScope(doxygen)

#endif
