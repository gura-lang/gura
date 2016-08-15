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
	virtual const Elem *ReduceContent() const;
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
	inline void Append(const char *str) { _str += str; }
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
	virtual bool Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const;
	virtual String ToString() const;
	virtual void Print(Environment &env, SimpleStream &stream, int indentLevel) const;
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

//-----------------------------------------------------------------------------
// Iterator_Elem_Command
//-----------------------------------------------------------------------------
class Iterator_Elem_Command : public Iterator {
protected:
	AutoPtr<ElemOwner> _pElemOwner;
	size_t _idx;
	String _name;
public:
	Iterator_Elem_Command(ElemOwner *pElemOwner, const String &name);
	Iterator_Elem_Command(const Iterator_Elem_Command &iter);
	virtual Iterator *Clone() const;
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Elem_Text
//-----------------------------------------------------------------------------
class Iterator_Elem_Text : public Iterator {
protected:
	AutoPtr<ElemOwner> _pElemOwner;
	size_t _idx;
public:
	Iterator_Elem_Text(ElemOwner *pElemOwner);
	Iterator_Elem_Text(const Iterator_Elem_Text &iter);
	virtual Iterator *Clone() const;
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleScope(doxygen)

#endif
