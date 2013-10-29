#ifndef __GURA_PRIMITIVECLASS_H__
#define __GURA_PRIMITIVECLASS_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_nil
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_nil : public Class {
public:
	Class_nil(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_undefined
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_undefined : public Class {
public:
	Class_undefined(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_symbol
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_symbol : public Class {
public:
	Class_symbol(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_boolean
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_boolean : public Class {
public:
	Class_boolean(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_number
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_number : public Class {
public:
	Class_number(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_complex
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_complex : public Class {
public:
	Class_complex(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Value GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
			const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const;
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_fraction
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_fraction : public Class {
public:
	Class_fraction(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Value GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
			const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const;
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_string
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_string : public Class {
public:
	class GURA_DLLDECLARE IteratorEach : public Iterator {
	public:
		enum Attr { ATTR_None, ATTR_UTF8, ATTR_UTF32, };
	private:
		String _str;
		int _cnt, _cntMax;
		Attr _attr;
		String::const_iterator _pCur;
	public:
		IteratorEach(const String &str, int maxSplit, Attr attr);
		virtual ~IteratorEach();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class GURA_DLLDECLARE IteratorLine : public Iterator {
	private:
		String _str;
		int _cnt, _cntMax;
		String::const_iterator _pCur;
		bool _includeEOLFlag;
	public:
		IteratorLine(const String &str, int cntMax, bool includeEOLFlag);
		virtual ~IteratorLine();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class GURA_DLLDECLARE IteratorSplit : public Iterator {
	private:
		String _str;
		String _sep;
		int _cnt, _cntMax;
		bool _ignoreCaseFlag;
		bool _doneFlag;
		String::const_iterator _pCur;
	public:
		IteratorSplit(const String &str,
						const char *sep, int cntMax, bool ignoreCaseFlag);
		virtual ~IteratorSplit();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class GURA_DLLDECLARE IteratorFold : public Iterator {
	private:
		String _str;
		size_t _cntPerFold;
		size_t _cntStep;
		String::const_iterator _pCur;
	public:
		IteratorFold(const String &str, size_t cntPerFold, size_t cntStep);
		virtual ~IteratorFold();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Class_string(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Value IndexGetPrimitive(Environment &env, Signal sig,
						const Value &valueThis, const Value &valueIdx) const;
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

//-----------------------------------------------------------------------------
// Class_quote
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_quote : public Class {
public:
	Class_quote(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_any
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_any : public Class {
public:
	Class_any(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

}

#endif
