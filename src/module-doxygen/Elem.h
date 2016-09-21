//=============================================================================
// Elem.h
//=============================================================================
#ifndef __GURA_DOXYGEN_ELEM_H__
#define __GURA_DOXYGEN_ELEM_H__

Gura_BeginModuleScope(doxygen)

class Renderer;
class Configuration;

class ElemOwner;

//-----------------------------------------------------------------------------
// Elem
//-----------------------------------------------------------------------------
class Elem {
public:
	enum Type {
		TYPE_None,
		TYPE_Empty,
		TYPE_String,
		TYPE_Command,
		TYPE_Text,
	};
protected:
	int _cntRef;
	Type _type;
	AutoPtr<ElemOwner> _pElemChildren;
	Elem *_pElemPrev;
	Elem *_pElemNext;
public:
	static const Elem *Empty;
public:
	Gura_DeclareReferenceAccessor(Elem);
public:
	Elem(Type type);
	Elem(ElemOwner *pElemChildren, Type type);
protected:
	virtual ~Elem();
public:
	inline Type GetType() const { return _type; }
	inline bool IsParent() const { return !_pElemChildren.IsNull(); }
	inline ElemOwner &GetElemChildren() { return *_pElemChildren; }
	inline void SetElemChildren(ElemOwner *pElemChildren) { _pElemChildren.reset(pElemChildren); }
	inline void SetElemPrev(Elem *pElemPrev) { _pElemPrev = pElemPrev; }
	inline void SetElemNext(Elem *pElemNext) { _pElemNext = pElemNext; }
	inline Elem *GetElemPrev() { return _pElemPrev; }
	inline Elem *GetElemNext() { return _pElemNext; }
	inline const Elem *GetElemPrev() const { return _pElemPrev; }
	inline const Elem *GetElemNext() const { return _pElemNext; }
	size_t GetIndex() const;
	virtual const Elem *ReduceContent() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols) = 0;
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag) = 0;
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const = 0;
	virtual String ToString() const = 0;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const = 0;
	virtual bool IsSameType(const Elem *pElem) const;
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
	void AddElem(Elem *pElem);
	inline value_type At(size_t idx) { return ElemList::operator[](idx); }
private:
	void push_back(Elem *pElem) {}
	void insert(Elem *pElem) {}
	value_type operator[](size_t idx) { return ElemList::operator[](idx); }
};

//-----------------------------------------------------------------------------
// Elem_Empty
//-----------------------------------------------------------------------------
class Elem_Empty : public Elem {
public:
	Elem_Empty(Type type = TYPE_Empty);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline void Append(const char *str) { _str += str; }
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline ElemOwner &GetElemArgs() { return *_pElemArgs; }
	inline const ElemOwner &GetElemArgs() const { return *_pElemArgs; }
	inline bool IsEndCommand(const Elem_Command *pElem) {
		return _pCmdFmt->IsEndCommand(pElem->GetCommandFormat()->GetName());
	}
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const;
	virtual String ToString() const;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const;
	virtual bool IsSameType(const Elem *pElem) const;
	inline bool HasCompletedArg() const {
		return _pElemArgs->size() >= _pCmdFmt->GetArgOwner().size();
	}
	inline CommandFormat::Arg *GetCurrentArg() const {
		return _pCmdFmt->GetArgOwner()[_pElemArgs->size()];
	}
};

//-----------------------------------------------------------------------------
// Elem_Text
//-----------------------------------------------------------------------------
class Elem_Text : public Elem {
public:
	Elem_Text(Type type = TYPE_Text);
	Elem_Text(ElemOwner *pElemOwner, Type type = TYPE_Text);
	virtual const Elem *ReduceContent() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
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
