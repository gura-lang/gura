//=============================================================================
// Gura class: stream
//=============================================================================
#ifndef __GURA_CLASS_STREAM_H__
#define __GURA_CLASS_STREAM_H__

#include "Class.h"
#include "Stream.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_stream
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_stream : public Class {
public:
	Class_stream(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_stream
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_stream : public Object {
public:
	class IteratorLine : public Iterator {
	private:
		AutoPtr<Object_stream> _pObj;
		int _nLinesMax;
		bool _includeEOLFlag;
		int _nLines;
	public:
		inline IteratorLine(Object_stream *pObj, int nLinesMax, bool includeEOLFlag) :
			Iterator(pObj->GetStream().IsInfinite()? Infinite : Finite),
			_pObj(pObj), _nLinesMax(nLinesMax),
			_includeEOLFlag(includeEOLFlag), _nLines(0) {}
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareObjectAccessor(stream)
protected:
	AutoPtr<Stream> _pStream;
public:
	inline Object_stream(Environment &env, Stream *pStream) :
						Object(env.LookupClass(VTYPE_stream)), _pStream(pStream) {}
	inline Object_stream(Class *pClass, Stream *pStream) :
						Object(pClass), _pStream(pStream) {}
	inline Stream &GetStream() { return *_pStream; }
	virtual Iterator *CreateIterator(Signal &sig);
	virtual String ToString(bool exprFlag);
};

}

#endif
