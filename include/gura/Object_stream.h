#ifndef __GURA_OBJECT_STREAM_H__
#define __GURA_OBJECT_STREAM_H__

#include "Object.h"
#include "Stream.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_stream
//-----------------------------------------------------------------------------
class DLLDECLARE Class_stream : public Class {
public:
	Class_stream(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_stream
//-----------------------------------------------------------------------------
class DLLDECLARE Object_stream : public Object {
public:
	class IteratorLine : public Iterator {
	private:
		Object_stream *_pObj;
		int _nLinesMax;
		bool _includeEOLFlag;
		int _nLines;
	public:
		inline IteratorLine(Object_stream *pObj, int nLinesMax, bool includeEOLFlag) :
			Iterator(pObj->GetStream().IsInfinite()), _pObj(pObj), _nLinesMax(nLinesMax),
			_includeEOLFlag(includeEOLFlag), _nLines(0) {}
		virtual ~IteratorLine();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareObjectAccessor(stream)
protected:
	Stream *_pStream;
public:
	inline Object_stream(Environment &env, Stream *pStream) :
						Object(env.LookupClass(VTYPE_stream)), _pStream(pStream) {}
	inline Object_stream(Class *pClass, Stream *pStream) :
						Object(pClass), _pStream(pStream) {}
	inline Stream &GetStream() { return *_pStream; }
	virtual ~Object_stream();
	virtual Iterator *CreateIterator(Signal sig);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

}

#endif
