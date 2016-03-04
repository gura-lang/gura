//=============================================================================
// Gura class: binary
//=============================================================================
#ifndef __GURA_CLASS_BINARY_H__
#define __GURA_CLASS_BINARY_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_binary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_binary : public Class {
public:
	Class_binary(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_binary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_binary : public Object {
public:
	class GURA_DLLDECLARE IteratorByte : public Iterator {
	private:
		AutoPtr<Object_binary> _pObj;
		int _cnt;
		size_t _offset;
	public:
		IteratorByte(Object_binary *pObj, int cntMax);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class GURA_DLLDECLARE PointerEx : public Pointer {
	protected:
		AutoPtr<Object_binary> _pObjBinary;
	public:
		PointerEx(size_t offset, Object_binary *pObjBinary);
		PointerEx(const PointerEx &ptr);
		inline Object_binary *GetBinaryObj() { return _pObjBinary.get(); }
		inline const Object_binary *GetBinaryObj() const { return _pObjBinary.get(); }
		inline Binary &GetBinary() { return _pObjBinary->GetBinary(); }
		inline const Binary &GetBinary() const { return _pObjBinary->GetBinary(); }
	public:
		virtual bool PackPrepare(Environment &env, size_t bytes);
		virtual void PackBuffer(const void *buff, size_t bytes);
		virtual const UChar *UnpackPrepare(Environment &env, size_t bytes, bool exceedErrorFlag);
	public:
		virtual Pointer *Clone() const;
		virtual Object *GetTarget() const;
		virtual const UChar *GetPointerC() const;
		virtual size_t GetEntireSize() const;
		virtual bool IsWritable() const;
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
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
	virtual Iterator *CreateIterator(Signal &sig);
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
	Stream_Binary(Environment &env, Object_binary *pObjBinary, bool seekEndFlag);
	virtual ~Stream_Binary();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
	virtual size_t DoGetSize();
	inline Binary &GetBinary() { return _pObjBinary->GetBinary(); }
	inline const Binary &GetBinary() const { return _pObjBinary->GetBinary(); }
};

}

#endif
