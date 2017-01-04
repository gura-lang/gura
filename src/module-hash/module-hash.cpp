//-----------------------------------------------------------------------------
// Gura module: hash
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(hash)

Gura_DeclareUserSymbol(digest);
Gura_DeclareUserSymbol(hexdigest);

//-----------------------------------------------------------------------------
// Object_accumulator implementation
//-----------------------------------------------------------------------------
Object_accumulator::Object_accumulator(Environment &env, AccumulatorBase *pAccumulator, const char *name) :
					Object_stream(Gura_UserClass(accumulator), pAccumulator), _name(name)
{
}

Object_accumulator::Object_accumulator(Class *pClass, AccumulatorBase *pAccumulator, const char *name) :
					Object_stream(pClass, pAccumulator), _name(name)
{
}

Object *Object_accumulator::Clone() const
{
	return nullptr;
}

String Object_accumulator::ToString(bool exprFlag)
{
	String str = "<hash.accumulator:";
	str += _name;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// hash.accumulator#digest
Gura_DeclareProperty_R(accumulator, digest)
{
	SetPropAttr(VTYPE_binary);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(accumulator, digest)
{
	AccumulatorBase &accumulator = Object_accumulator::GetObject(valueThis)->GetAccumulator();
	return Value(new Object_binary(env, accumulator.GetDigest(), true));
}

// hash.accumulator#hexdigest
Gura_DeclareProperty_R(accumulator, hexdigest)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(accumulator, hexdigest)
{
	AccumulatorBase &accumulator = Object_accumulator::GetObject(valueThis)->GetAccumulator();
	const Binary &digest = accumulator.GetDigest();
	String str;
	foreach_const (Binary, p, digest) {
		char buff[8];
		::sprintf(buff, "%02x", static_cast<UChar>(*p));
		str += buff;
	}
	return Value(str);
}

// hash.accumulator#number
Gura_DeclareProperty_R(accumulator, number)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(accumulator, number)
{
	AccumulatorBase &accumulator = Object_accumulator::GetObject(valueThis)->GetAccumulator();
	return accumulator.GetValue();
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_accumulator
//-----------------------------------------------------------------------------
// accumulator#init():reduce
Gura_DeclareMethod(accumulator, init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Initializes the state of the accumulator.");
}

Gura_ImplementMethod(accumulator, init)
{
	AccumulatorBase &accumulator = Object_accumulator::GetObjectThis(arg)->GetAccumulator();
	accumulator.Init();
	return arg.GetValueThis();
}

// accumulator#update(stream:stream:r):reduce
Gura_DeclareMethod(accumulator, update)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en),
		"Updates the accumulator with the content of `stream`.");
}

Gura_ImplementMethod(accumulator, update)
{
	Signal &sig = env.GetSignal();
	AccumulatorBase &accumulator = Object_accumulator::GetObjectThis(arg)->GetAccumulator();
	arg.GetStream(0).ReadToStream(env, accumulator, 0x10000, false);
	return arg.GetValueThis();
}

// implementation of class Accumulator
Gura_ImplementUserClass(accumulator)
{
	// Assignment of properties
	Gura_AssignProperty(accumulator, digest);
	Gura_AssignProperty(accumulator, hexdigest);
	Gura_AssignProperty(accumulator, number);
	// Assignment of methods
	Gura_AssignMethod(accumulator, init);
	Gura_AssignMethod(accumulator, update);
	// Assignment of value
	Gura_AssignValue(accumulator, Value(Reference()));
}

//-----------------------------------------------------------------------------
// AccumulatorBase implementation
//-----------------------------------------------------------------------------
const char *AccumulatorBase::GetIdentifier() const
{
	return nullptr;
}

size_t AccumulatorBase::DoRead(Signal &sig, void *buff, size_t len)
{
	return 0;
}

bool AccumulatorBase::DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode) { return false; }
bool AccumulatorBase::DoFlush(Signal &sig) { return true; }
bool AccumulatorBase::DoClose(Signal &sig) { return Stream::DoClose(sig); }

const Value &AccumulatorBase::GetValue()
{
	return _value;
}

//-----------------------------------------------------------------------------
// Accumulator_MD5 implementation
//-----------------------------------------------------------------------------
Accumulator_MD5::Accumulator_MD5(Environment &env) : AccumulatorBase(env)
{
	_digest.clear();
	::md5_init(&_state);
}

void Accumulator_MD5::Init()
{
	_digest.clear();
	::md5_init(&_state);
}

const char *Accumulator_MD5::GetName() const
{
	return "<hash.accumulator:md5>";
}

size_t Accumulator_MD5::DoWrite(Signal &sig, const void *buff, size_t len)
{
	::md5_append(&_state, reinterpret_cast<const md5_byte_t *>(buff), static_cast<int>(len));
	return len;
}

void Accumulator_MD5::Finish()
{
	md5_byte_t digest[16];
	::md5_finish(&_state, digest);
	_digest = Binary(reinterpret_cast<char *>(digest), sizeof(digest));
}

const Binary &Accumulator_MD5::GetDigest()
{
	if (_digest.empty()) Finish();
	return _digest;
}

//-----------------------------------------------------------------------------
// Accumulator_SHA1 implementation
//-----------------------------------------------------------------------------
Accumulator_SHA1::Accumulator_SHA1(Environment &env) : AccumulatorBase(env)
{
	_digest.clear();
	::sha1_starts(&_ctx);
}

void Accumulator_SHA1::Init()
{
	_digest.clear();
	::sha1_starts(&_ctx);
}

const char *Accumulator_SHA1::GetName() const
{
	return "<hash.accumulator:sha1>";
}

size_t Accumulator_SHA1::DoWrite(Signal &sig, const void *buff, size_t len)
{
	::sha1_update(&_ctx, reinterpret_cast<uint8 *>(const_cast<void *>(buff)),
													static_cast<uint32>(len));
	return len;
}

void Accumulator_SHA1::Finish()
{
	uint8 digest[20];
	::sha1_finish(&_ctx, digest);
	_digest = Binary(reinterpret_cast<char *>(digest), sizeof(digest));
}

const Binary &Accumulator_SHA1::GetDigest()
{
	if (_digest.empty()) Finish();
	return _digest;
}

//-----------------------------------------------------------------------------
// Accumulator_CRC32 implementation
//-----------------------------------------------------------------------------
Accumulator_CRC32::Accumulator_CRC32(Environment &env) : AccumulatorBase(env)
{
	_digest.clear();
}

void Accumulator_CRC32::Init()
{
	_digest.clear();
	_crc32.Initialize();
}

const char *Accumulator_CRC32::GetName() const
{
	return "<accumulator:crc32>";
}

size_t Accumulator_CRC32::DoWrite(Signal &sig, const void *buff, size_t len)
{
	_crc32.Update(buff, len);
	return len;
}

void Accumulator_CRC32::Finish()
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

const Binary &Accumulator_CRC32::GetDigest()
{
	if (_digest.empty()) Finish();
	return _digest;
}

const Value &Accumulator_CRC32::GetValue()
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `hash.accumulator` instance\n"
		"that calculates MD5 hashed value from the content of `stream`.\n");
}

Gura_ImplementFunction(md5)
{
	Object_accumulator *pObj = new Object_accumulator(env, new Accumulator_MD5(env), "md5");
	if (arg.Is_stream(0)) {
		arg.GetStream(0).ReadToStream(env, pObj->GetAccumulator(), 0x10000, false);
	}
	return ReturnValue(env, arg, Value(pObj));
}

// hash.sha1(stream?:stream:r) {block?}
Gura_DeclareFunction(sha1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `hash.accumulator` instance\n"
		"that calculates SHA1 hashed value from the content of `stream`.\n");
}

Gura_ImplementFunction(sha1)
{
	Object_accumulator *pObj = new Object_accumulator(env, new Accumulator_SHA1(env), "sha1");
	if (arg.Is_stream(0)) {
		arg.GetStream(0).ReadToStream(env, pObj->GetAccumulator(), 0x10000, false);
	}
	return ReturnValue(env, arg, Value(pObj));
}

// hash.crc32(stream?:stream:r) {block?}
Gura_DeclareFunction(crc32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `hash.accumulator` instance\n"
		"that calculates CRC32 hashed value from the content of `stream`.\n");
}

Gura_ImplementFunction(crc32)
{
	Object_accumulator *pObj = new Object_accumulator(env, new Accumulator_CRC32(env), "crc32");
	if (arg.Is_stream(0)) {
		arg.GetStream(0).ReadToStream(env, pObj->GetAccumulator(), 0x10000, false);
	}
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	Gura_RealizeUserSymbol(digest);
	Gura_RealizeUserSymbol(hexdigest);
	// function assignment
	Gura_AssignFunction(md5);
	Gura_AssignFunction(sha1);
	Gura_AssignFunction(crc32);
	// class realization
	Gura_RealizeAndPrepareUserClass(accumulator, env.LookupClass(VTYPE_stream));
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(hash, hash)

Gura_RegisterModule(hash)
