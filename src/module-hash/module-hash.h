//-----------------------------------------------------------------------------
// Gura module: hash
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_HASH_H__
#define __GURA_MODULE_HASH_H__

#include <gura.h>
#include <md5.h>
extern "C" {
#include <sha1.h>
}

Gura_BeginModuleHeader(hash)

//-----------------------------------------------------------------------------
// AccumulatorBase declaration
//-----------------------------------------------------------------------------
class AccumulatorBase : public Stream {
protected:
	Value _value;
	Binary _digest;
public:
	inline AccumulatorBase(Environment &env, Signal &sig) : Stream(env, sig, ATTR_Infinite | ATTR_Writable) {}
	virtual const char *GetIdentifier() const;
	virtual void Init() = 0;
	virtual void Finish() = 0;
	virtual const Binary &GetDigest() = 0;
	virtual const Value &GetValue();
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len) = 0;
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
};

//-----------------------------------------------------------------------------
// Object_accumulator declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(accumulator);

class Object_accumulator : public Object_stream {
public:
	Gura_DeclareObjectAccessor(accumulator)
private:
	String _name;
public:
	Object_accumulator(Environment &env, AccumulatorBase *pAccumulator, const char *name);
	Object_accumulator(Class *pClass, AccumulatorBase *pAccumulator, const char *name);
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline AccumulatorBase &GetAccumulator() {
		return *dynamic_cast<AccumulatorBase *>(&GetStream());
	}
};

//-----------------------------------------------------------------------------
// Accumulator_MD5 declaration
//-----------------------------------------------------------------------------
class Accumulator_MD5 : public AccumulatorBase {
private:
	md5_state_t _state;
public:
	Accumulator_MD5(Environment &env, Signal &sig);
	virtual void Init();
	virtual const char *GetName() const;
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual void Finish();
	virtual const Binary &GetDigest();
};

//-----------------------------------------------------------------------------
// Accumulator_SHA1 declaration
//-----------------------------------------------------------------------------
class Accumulator_SHA1 : public AccumulatorBase {
private:
    sha1_context _ctx;
public:
	Accumulator_SHA1(Environment &env, Signal &sig);
	virtual void Init();
	virtual const char *GetName() const;
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual void Finish();
	virtual const Binary &GetDigest();
};

//-----------------------------------------------------------------------------
// Accumulator_CRC32 declaration
//-----------------------------------------------------------------------------
class Accumulator_CRC32 : public AccumulatorBase {
private:
	CRC32 _crc32;
public:
	Accumulator_CRC32(Environment &env, Signal &sig);
	virtual void Init();
	virtual const char *GetName() const;
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual void Finish();
	virtual const Binary &GetDigest();
	virtual const Value &GetValue();
};

Gura_EndModuleHeader(hash)

#endif
