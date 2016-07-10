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
	};
	class Elem_Text : public Elem {
	private:
		String _str;
	public:
		inline Elem_Text(const String &str) : _str(str) {}
		virtual bool Evaluate(Environment &env, String &rtn, const StringList &strArgs) const;
	};
	class Elem_ArgRef : public Elem {
	private:
		size_t _iArg;
	public:
		inline Elem_ArgRef(size_t iArg) : _iArg(iArg) {}
		virtual bool Evaluate(Environment &env, String &rtn, const StringList &strArgs) const;
	};
	class ElemList : public std::vector<Elem *> {
	public:
		bool Evaluate(Environment &env, String &rtn, const StringList &strArgs) const;
	};
	class ElemOwner : public ElemList {
	public:
		~ElemOwner();
		void Clear();
	};
private:
	String _key;
	ElemOwner _elemOwner;
public:
	Alias();
	bool Parse(const char *str);
	String Evaluate(Environment &env, const StringList &strArgs) const;
};

//-----------------------------------------------------------------------------
// Aliases
//-----------------------------------------------------------------------------
class Aliases {
public:
	bool Parse(const char *str);
};

Gura_EndModuleScope(doxygen)

#endif
