//-----------------------------------------------------------------------------
// Gura hash module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(hash)

Gura_DeclareUserSymbol(digest);
Gura_DeclareUserSymbol(hexdigest);

//-----------------------------------------------------------------------------
// Object_hash implementation
//-----------------------------------------------------------------------------
Object_hash::Object_hash(Environment &env, HashBase *pHash, const char *name) :
					Object_stream(Gura_UserClass(hash), pHash), _name(name)
{
}

Object_hash::Object_hash(Class *pClass, HashBase *pHash, const char *name) :
					Object_stream(pClass, pHash), _name(name)
{
}

Object_hash::~Object_hash()
{
}

Object *Object_hash::Clone() const
{
	return NULL;
}

bool Object_hash::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(digest));
	symbols.insert(Gura_UserSymbol(hexdigest));
	symbols.insert(Gura_Symbol(number));
	return true;
}

Value Object_hash::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_UserSymbol(digest))) {
		evaluatedFlag = true;
		return Value(new Object_binary(env, GetHash().GetDigest(), true));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(hexdigest))) {
		evaluatedFlag = true;
		const Binary &digest = GetHash().GetDigest();
		String str;
		foreach_const (Binary, p, digest) {
			char buff[8];
			::sprintf(buff, "%02x", static_cast<UChar>(*p));
			str += buff;
		}
		return Value(str);
	} else if (pSymbol->IsIdentical(Gura_Symbol(number))) {
		evaluatedFlag = true;
		return GetHash().GetValue();
	}
	return Value::Null;
}

String Object_hash::ToString(bool exprFlag)
{
	String str = "<hash:";
	str += _name;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_hash
//-----------------------------------------------------------------------------
// hash#init():reduce
Gura_DeclareMethod(hash, init)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(hash, init)
{
	HashBase &hash = Object_hash::GetThisObj(args)->GetHash();
	hash.Init();
	return args.GetThis();
}

// hash#update(stream:stream:r):reduce
Gura_DeclareMethod(hash, update)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementMethod(hash, update)
{
	HashBase &hash = Object_hash::GetThisObj(args)->GetHash();
	args.GetStream(0).ReadToStream(env, sig, hash, 0x10000, false);
	return args.GetThis();
}

// implementation of class Hash
Gura_ImplementUserClass(hash)
{
	Gura_AssignMethod(hash, init);
	Gura_AssignMethod(hash, update);
}

//-----------------------------------------------------------------------------
// HashBase implementation
//-----------------------------------------------------------------------------
const char *HashBase::GetIdentifier() const
{
	return NULL;
}

size_t HashBase::DoRead(Signal sig, void *buff, size_t len)
{
	return 0;
}

bool HashBase::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode) { return false; }
bool HashBase::DoFlush(Signal sig) { return true; }
bool HashBase::DoClose(Signal sig) { return Stream::DoClose(sig); }

const Value &HashBase::GetValue()
{
	return _value;
}

//-----------------------------------------------------------------------------
// Hash_MD5 implementation
//-----------------------------------------------------------------------------
Hash_MD5::Hash_MD5(Environment &env, Signal sig) : HashBase(env, sig)
{
	_digest.clear();
	::md5_init(&_state);
}

void Hash_MD5::Init()
{
	_digest.clear();
	::md5_init(&_state);
}

const char *Hash_MD5::GetName() const
{
	return "<hash:md5>";
}

size_t Hash_MD5::DoWrite(Signal sig, const void *buff, size_t len)
{
	::md5_append(&_state, reinterpret_cast<const md5_byte_t *>(buff), static_cast<int>(len));
	return len;
}

void Hash_MD5::Finish()
{
	md5_byte_t digest[16];
	::md5_finish(&_state, digest);
	_digest = Binary(reinterpret_cast<char *>(digest), sizeof(digest));
}

const Binary &Hash_MD5::GetDigest()
{
	if (_digest.empty()) Finish();
	return _digest;
}

//-----------------------------------------------------------------------------
// Hash_SHA1 implementation
//-----------------------------------------------------------------------------
Hash_SHA1::Hash_SHA1(Environment &env, Signal sig) : HashBase(env, sig)
{
	_digest.clear();
	::sha1_starts(&_ctx);
}

void Hash_SHA1::Init()
{
	_digest.clear();
	::sha1_starts(&_ctx);
}

const char *Hash_SHA1::GetName() const
{
	return "<hash:sha1>";
}

size_t Hash_SHA1::DoWrite(Signal sig, const void *buff, size_t len)
{
	::sha1_update(&_ctx, reinterpret_cast<uint8 *>(const_cast<void *>(buff)),
													static_cast<uint32>(len));
	return len;
}

void Hash_SHA1::Finish()
{
	uint8 digest[20];
	::sha1_finish(&_ctx, digest);
	_digest = Binary(reinterpret_cast<char *>(digest), sizeof(digest));
}

const Binary &Hash_SHA1::GetDigest()
{
	if (_digest.empty()) Finish();
	return _digest;
}

//-----------------------------------------------------------------------------
// Hash_CRC32 implementation
//-----------------------------------------------------------------------------
Hash_CRC32::Hash_CRC32(Environment &env, Signal sig) : HashBase(env, sig)
{
	_digest.clear();
}

void Hash_CRC32::Init()
{
	_digest.clear();
	_crc32.Initialize();
}

const char *Hash_CRC32::GetName() const
{
	return "<hash:crc32>";
}

size_t Hash_CRC32::DoWrite(Signal sig, const void *buff, size_t len)
{
	_crc32.Update(buff, len);
	return len;
}

void Hash_CRC32::Finish()
{
	UChar digest[4];
	ULong result = _crc32.GetResult();
	digest[0] = static_cast<UChar>(result >> 24);
	digest[1] = static_cast<UChar>(result >> 16);
	digest[2] = static_cast<UChar>(result >> 8);
	digest[3] = static_cast<UChar>(result >> 0);
	_value = Value(result);
	_digest = Binary(reinterpret_cast<char *>(digest), sizeof(digest));
}

const Binary &Hash_CRC32::GetDigest()
{
	if (_digest.empty()) Finish();
	return _digest;
}

const Value &Hash_CRC32::GetValue()
{
	if (_digest.empty()) Finish();
	return _value;
}

//-----------------------------------------------------------------------------
// Gura module functions: hash
//-----------------------------------------------------------------------------
// hash.md5(stream?:stream:r) {block?}
Gura_DeclareFunction(md5)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(md5)
{
	Object_hash *pObj = new Object_hash(env, new Hash_MD5(env, sig), "md5");
	if (args.Is_stream(0)) {
		args.GetStream(0).ReadToStream(env, sig, pObj->GetHash(), 0x10000, false);
	}
	return ReturnValue(env, sig, args, Value(pObj));
}

// hash.sha1(stream?:stream:r) {block?}
Gura_DeclareFunction(sha1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(sha1)
{
	Object_hash *pObj = new Object_hash(env, new Hash_SHA1(env, sig), "sha1");
	if (args.Is_stream(0)) {
		args.GetStream(0).ReadToStream(env, sig, pObj->GetHash(), 0x10000, false);
	}
	return ReturnValue(env, sig, args, Value(pObj));
}

// hash.crc32(stream?:stream:r) {block?}
Gura_DeclareFunction(crc32)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(crc32)
{
	Object_hash *pObj = new Object_hash(env, new Hash_CRC32(env, sig), "crc32");
	if (args.Is_stream(0)) {
		args.GetStream(0).ReadToStream(env, sig, pObj->GetHash(), 0x10000, false);
	}
	return ReturnValue(env, sig, args, Value(pObj));
}

// Module entry
Gura_ModuleEntry()
{
	Gura_RealizeUserSymbol(digest);
	Gura_RealizeUserSymbol(hexdigest);
	// function assignment
	Gura_AssignFunction(md5);
	Gura_AssignFunction(sha1);
	Gura_AssignFunction(crc32);
	// class realization
	Gura_RealizeUserClass(hash, env.LookupClass(VTYPE_stream));
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(hash, hash)

Gura_RegisterModule(hash)
