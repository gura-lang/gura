#ifndef __GURA_CLASS_BINARY_H__
#define __GURA_CLASS_BINARY_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_binary / Object_binary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_binary : public Class {
public:
	Class_binary(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

class GURA_DLLDECLARE Object_binary : public Object {
public:
	class IteratorByte : public Iterator {
	private:
		AutoPtr<Object_binary> _pObj;
		int _cnt, _cntMax;
		size_t _offset;
	public:
		IteratorByte(Object_binary *pObj, int cntMax);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorUnpack : public Iterator {
	private:
		AutoPtr<Object_binary> _pObj;
		String _format;
		ValueList _valListArg;
		size_t _offset, _offsetInit;
	public:
		IteratorUnpack(Object_binary *pObj, const char *format,
										const ValueList &valListArg, size_t offset);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareObjectAccessor(binary)
private:
	Binary _binary;
	bool _writableFlag;
public:
	inline Object_binary(Class *pClass) : Object(pClass), _writableFlag(true) {}
	inline Object_binary(Environment &env) : Object(env.LookupClass(VTYPE_binary)), _writableFlag(true) {}
	inline Object_binary(Environment &env, const Binary &binary, bool writableFlag) :
						Object(env.LookupClass(VTYPE_binary)),
						_binary(binary), _writableFlag(writableFlag) {}
	inline Object_binary(Environment &env, const char *buff, size_t size, bool writableFlag) :
						Object(env.LookupClass(VTYPE_binary)),
						_binary(buff, size), _writableFlag(writableFlag) {}
	Object_binary(const Object_binary &obj);
	virtual ~Object_binary();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value);
	virtual Iterator *CreateIterator(Signal sig);
	virtual String ToString(bool exprFlag);
	inline Binary &GetBinary() { return _binary; }
	inline const Binary &GetBinary() const { return _binary; }
	inline bool IsWritable() const { return _writableFlag; }
};

//-----------------------------------------------------------------------------
// Stream_Binary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Stream_Binary : public Stream {
private:
	AutoPtr<Object_binary> _pObjBinary;
	size_t _offset;
public:
	Stream_Binary(Environment &env, Signal sig, Object_binary *pObjBinary, bool seekEndFlag);
	virtual ~Stream_Binary();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	inline Binary &GetBinary() { return _pObjBinary->GetBinary(); }
	inline const Binary &GetBinary() const { return _pObjBinary->GetBinary(); }
};

}

#endif
