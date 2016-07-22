//=============================================================================
// Alias.h
//=============================================================================
#ifndef __GURA_DOXYGEN_ALIAS_H__
#define __GURA_DOXYGEN_ALIAS_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Alias
//-----------------------------------------------------------------------------
class Alias {
public:
	class Elem {
	public:
		virtual ~Elem();
		virtual bool Evaluate(Environment &env, String &rtn, const StringList &strArgs) const = 0;
		virtual String ToString() const = 0;
	};
	class Elem_String : public Elem {
	private:
		String _str;
	public:
		inline Elem_String(const String &str) : _str(str) {}
		virtual bool Evaluate(Environment &env, String &rtn, const StringList &strArgs) const;
		virtual String ToString() const;
	};
	class Elem_ArgRef : public Elem {
	private:
		size_t _iArg;
	public:
		inline Elem_ArgRef(size_t iArg) : _iArg(iArg) {}
		virtual bool Evaluate(Environment &env, String &rtn, const StringList &strArgs) const;
		virtual String ToString() const;
	};
	class ElemList : public std::vector<Elem *> {
	public:
		bool Evaluate(Environment &env, String &rtn, const StringList &strArgs) const;
		String ToString() const;
	};
	class ElemOwner : public ElemList {
	public:
		~ElemOwner();
		void Clear();
	};
private:
	int _cntRef;
	String _key;
	ElemOwner _elemOwner;
public:
	Gura_DeclareReferenceAccessor(Alias);
public:
	Alias();
protected:
	inline ~Alias() {}
public:
	bool Parse(Environment &env, const char *str);
	bool Evaluate(Environment &env, String &rtn, const StringList &strArgs) const;
	void Print() const;
	inline const char *GetKey() const { return _key.c_str(); }
private:
	static bool IsKeyCharBegin(char ch) {
		return IsAlpha(ch) || ch == '_';
	}
	static bool IsKeyChar(char ch) {
		return IsKeyCharBegin(ch) || IsDigit(ch);
	}
};

//-----------------------------------------------------------------------------
// AliasDict
//-----------------------------------------------------------------------------
class AliasDict : public std::map<String, Alias *> {
public:
	~AliasDict();
	void Clear();
	void Print() const;
};

//-----------------------------------------------------------------------------
// Aliases
//-----------------------------------------------------------------------------
class Aliases {
private:
	int _cntRef;
	AliasDict _aliasDict;
public:
	Gura_DeclareReferenceAccessor(Aliases);
public:
	Aliases();
protected:
	inline ~Aliases() {}
public:
	bool AddSource(Environment &env, const char *str);
	const Alias *Lookup(const char *cmdName, size_t nArgs) const;
	void Print() const;
};

Gura_EndModuleScope(doxygen)

#endif
