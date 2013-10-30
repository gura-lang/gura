//-----------------------------------------------------------------------------
// Gura hash module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_HASH_H__
#define __GURA_MODULE_HASH_H__

#include <gura.h>
#include <md5.h>
extern "C" {
#include <sha1.h>
}

Gura_BeginModuleHeader(hash, hash)

//-----------------------------------------------------------------------------
// HashBase declaration
//-----------------------------------------------------------------------------
class HashBase : public Stream {
protected:
	Value _value;
	Binary _digest;
public:
	inline HashBase(Environment &env, Signal sig) : Stream(env, sig, ATTR_Infinite | ATTR_Writable) {}
	virtual const char *GetIdentifier() const;
	virtual void Init() = 0;
	virtual void Finish() = 0;
	virtual const Binary &GetDigest() = 0;
	virtual const Value &GetValue();
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len) = 0;
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
};

//-----------------------------------------------------------------------------
// Object_hash declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(hash);

class Object_hash : public Object_stream {
public:
	Gura_DeclareObjectAccessor(hash)
private:
	String _name;
public:
	Object_hash(Environment &env, HashBase *pHash, const char *name);
	Object_hash(Class *pClass, HashBase *pHash, const char *name);
	virtual ~Object_hash();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline HashBase &GetHash() {
		return *dynamic_cast<HashBase *>(&GetStream());
	}
};

//-----------------------------------------------------------------------------
// Hash_MD5 declaration
//-----------------------------------------------------------------------------
class Hash_MD5 : public HashBase {
private:
	md5_state_t _state;
public:
	Hash_MD5(Environment &env, Signal sig);
	virtual void Init();
	virtual const char *GetName() const;
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual void Finish();
	virtual const Binary &GetDigest();
};

//-----------------------------------------------------------------------------
// Hash_SHA1 declaration
//-----------------------------------------------------------------------------
class Hash_SHA1 : public HashBase {
private:
    sha1_context _ctx;
public:
	Hash_SHA1(Environment &env, Signal sig);
	virtual void Init();
	virtual const char *GetName() const;
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual void Finish();
	virtual const Binary &GetDigest();
};

//-----------------------------------------------------------------------------
// Hash_CRC32 declaration
//-----------------------------------------------------------------------------
class Hash_CRC32 : public HashBase {
private:
	CRC32 _crc32;
public:
	Hash_CRC32(Environment &env, Signal sig);
	virtual void Init();
	virtual const char *GetName() const;
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual void Finish();
	virtual const Binary &GetDigest();
	virtual const Value &GetValue();
};

Gura_EndModuleHeader(hash, hash)

#endif
