#ifndef __GURA_OBJECT_BINARY_H__
#define __GURA_OBJECT_BINARY_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_binary / Object_binary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_binary : public Class {
public:
	Class_binary(Environment *pEnvOuter);
	virtual void Prepare();
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
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
		virtual ~IteratorByte();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorUnpack : public Iterator {
	private:
		AutoPtr<Object_binary> _pObj;
		String _format;
		size_t _offset, _offsetInit;
		int _cntMax, _cnt;
	public:
		IteratorUnpack(Object_binary *pObj, const char *format, size_t offset, int cntMax);
		virtual ~IteratorUnpack();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
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
	virtual String ToString(Signal sig, bool exprFlag);
	inline Binary &GetBinary() { return _binary; }
	inline const Binary &GetBinary() const { return _binary; }
	inline bool IsWritable() const { return _writableFlag; }
};

//-----------------------------------------------------------------------------
// Class_binaryptr / Object_binaryptr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_binaryptr : public Class {
public:
	Class_binaryptr(Environment *pEnvOuter);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

class GURA_DLLDECLARE Object_binaryptr : public Object {
public:
	Gura_DeclareObjectAccessor(binaryptr)
private:
	AutoPtr<Object_binary> _pObjBinary;
	size_t _offset;
public:
	inline Object_binaryptr(Class *pClass, Object_binary *pObjBinary, size_t offset) :
		Object(pClass), _pObjBinary(pObjBinary), _offset(offset) {}
	inline Object_binaryptr(Environment &env, Object_binary *pObjBinary, size_t offset) :
		Object(env.LookupClass(VTYPE_binaryptr)), _pObjBinary(pObjBinary), _offset(offset) {}
	inline Object_binaryptr(const Object_binaryptr &obj) :
		Object(obj), _pObjBinary(dynamic_cast<Object_binary *>(Object::Reference(obj.GetBinaryObj()))),
		_offset(obj._offset) {}
	virtual ~Object_binaryptr();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline Object_binary *GetBinaryObj() { return _pObjBinary.get(); }
	inline const Object_binary *GetBinaryObj() const { return _pObjBinary.get(); }
	inline Binary &GetBinary() { return _pObjBinary->GetBinary(); }
	inline const Binary &GetBinary() const { return _pObjBinary->GetBinary(); }
	inline bool IsWritable() const { return _pObjBinary->IsWritable(); }
	inline size_t GetOffset() const { return _offset; }
	inline void Reset() { _offset = 0; }
	bool Pack(Signal sig, bool forwardFlag,
							const char *format, const ValueList &valList);
	Value Unpack(Signal sig, bool forwardFlag,
							const char *format, bool exeedErrorFlag);
	bool UnpackForward(Signal sig, int distance, bool exceedErrorFlag);
};

//-----------------------------------------------------------------------------
// Stream_Binary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Stream_Binary : public Stream {
private:
	AutoPtr<Object_binary> _pObjBinary;
	size_t _offset;
public:
	Stream_Binary(Signal sig, Object_binary *pObjBinary, bool seekEndFlag);
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
