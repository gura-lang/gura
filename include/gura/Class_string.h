//=============================================================================
// Gura class: string
//=============================================================================
#ifndef __GURA_CLASS_STRING_H__
#define __GURA_CLASS_STRING_H__

#include "Class.h"

namespace Gura {

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
		virtual String ToString() const;
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
		virtual String ToString() const;
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
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class GURA_DLLDECLARE IteratorFold : public Iterator {
	private:
		String _str;
		size_t _lenPerFold;
		size_t _lenStep;
		bool _neatFlag;
		String::const_iterator _pCur;
	public:
		IteratorFold(const String &str, size_t lenPerFold, size_t lenStep, bool neatFlag);
		virtual ~IteratorFold();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class GURA_DLLDECLARE IteratorFoldw : public Iterator {
	private:
		String _str;
		size_t _widthPerFold;
		bool _paddingFlag;
		String::const_iterator _pCur;
	public:
		IteratorFoldw(const String &str, size_t widthPerFold, bool paddingFlag);
		virtual ~IteratorFoldw();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString() const;
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

}

#endif
