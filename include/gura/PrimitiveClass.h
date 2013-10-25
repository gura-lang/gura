#ifndef __GURA_OBJECT_STRING_H__
#define __GURA_OBJECT_STRING_H__

#include "Object.h"

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
// Stream_StringReader
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Stream_StringReader : public Stream {
private:
	String _str;
	size_t _offset;
public:
	Stream_StringReader(Environment &env, Signal sig, const String &str);
	virtual ~Stream_StringReader();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
};

}

#endif
