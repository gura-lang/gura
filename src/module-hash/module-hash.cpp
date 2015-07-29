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

bool Object_accumulator::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(digest));
	symbols.insert(Gura_UserSymbol(hexdigest));
	symbols.insert(Gura_Symbol(number));
	return true;
}

Value Object_accumulator::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_UserSymbol(digest))) {
		evaluatedFlag = true;
		return Value(new Object_binary(env, GetAccumulator().GetDigest(), true));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(hexdigest))) {
		evaluatedFlag = true;
		const Binary &digest = GetAccumulator().GetDigest();
		String str;
		foreach_const (Binary, p, digest) {
			char buff[8];
			::sprintf(buff, "%02x", static_cast<UChar>(*p));
			str += buff;
		}
		return Value(str);
	} else if (pSymbol->IsIdentical(Gura_Symbol(number))) {
		evaluatedFlag = true;
		return GetAccumulator().GetValue();
	}
	return Value::Null;
}

String Object_accumulator::ToString(bool exprFlag)
{
	String str = "<hash.accumulator:";
	str += _name;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_accumulator
//-----------------------------------------------------------------------------
// accumulator#init():reduce
Gura_DeclareMethod(accumulator, init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Initializes the state of the accumulator.");
}

Gura_ImplementMethod(accumulator, init)
{
	AccumulatorBase &accumulator = Object_accumulator::GetThisObj(args)->GetAccumulator();
	accumulator.Init();
	return args.GetThis();
}

// accumulator#update(stream:stream:r):reduce
Gura_DeclareMethod(accumulator, update)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Updates the accumulator with the content of `stream`.");
}

Gura_ImplementMethod(accumulator, update)
{
	Signal &sig = env.GetSignal();
	AccumulatorBase &accumulator = Object_accumulator::GetThisObj(args)->GetAccumulator();
	args.GetStream(0).ReadToStream(env, sig, accumulator, 0x10000, false);
	return args.GetThis();
}

// implementation of class Accumulator
Gura_ImplementUserClass(accumulator)
{
	Gura_AssignValue(accumulator, Value(Reference()));
	Gura_AssignMethod(accumulator, init);
	Gura_AssignMethod(accumulator, update);
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
Accumulator_MD5::Accumulator_MD5(Environment &env, Signal &sig) : AccumulatorBase(env, sig)
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
Accumulator_SHA1::Accumulator_SHA1(Environment &env, Signal &sig) : AccumulatorBase(env, sig)
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
Accumulator_CRC32::Accumulator_CRC32(Environment &env, Signal &sig) : AccumulatorBase(env, sig)
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
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an `hash.accumulator` instance\n"
		"that calculates MD5 hashed value from the content of `stream`.\n");
}

Gura_ImplementFunction(md5)
{
	Signal &sig = env.GetSignal();
	Object_accumulator *pObj = new Object_accumulator(env, new Accumulator_MD5(env, sig), "md5");
	if (args.Is_stream(0)) {
		args.GetStream(0).ReadToStream(env, sig, pObj->GetAccumulator(), 0x10000, false);
	}
	return ReturnValue(env, args, Value(pObj));
}

// hash.sha1(stream?:stream:r) {block?}
Gura_DeclareFunction(sha1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an `hash.accumulator` instance\n"
		"that calculates SHA1 hashed value from the content of `stream`.\n");
}

Gura_ImplementFunction(sha1)
{
	Signal &sig = env.GetSignal();
	Object_accumulator *pObj = new Object_accumulator(env, new Accumulator_SHA1(env, sig), "sha1");
	if (args.Is_stream(0)) {
		args.GetStream(0).ReadToStream(env, sig, pObj->GetAccumulator(), 0x10000, false);
	}
	return ReturnValue(env, args, Value(pObj));
}

// hash.crc32(stream?:stream:r) {block?}
Gura_DeclareFunction(crc32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an `hash.accumulator` instance\n"
		"that calculates CRC32 hashed value from the content of `stream`.\n");
}

Gura_ImplementFunction(crc32)
{
	Signal &sig = env.GetSignal();
	Object_accumulator *pObj = new Object_accumulator(env, new Accumulator_CRC32(env, sig), "crc32");
	if (args.Is_stream(0)) {
		args.GetStream(0).ReadToStream(env, sig, pObj->GetAccumulator(), 0x10000, false);
	}
	return ReturnValue(env, args, Value(pObj));
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
	Gura_RealizeAndPrepareUserClass(accumulator, env.LookupClass(VTYPE_stream));
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(hash, hash)

Gura_RegisterModule(hash)
