//-----------------------------------------------------------------------------
// Gura module: bzip2
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(bzip2)

//-----------------------------------------------------------------------------
// Gura module functions: bzip2
//-----------------------------------------------------------------------------
// bzip2.reader(stream:stream:r) {block?}
Gura_DeclareFunction(reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(reader)
{
	Stream &stream = args.GetStream(0);
	Object_stream *pObjStream = GenerateDecompressor(env, sig, stream);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjStream));
}

// bzip2.writer(stream:stream:w, blockSize100k?:number) {block?}
Gura_DeclareFunction(writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "blockSize100k", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(writer)
{
	Stream &stream = args.GetStream(0);
	int blockSize100k = args.Is_number(1)? args.GetInt(1) : 9;
	if (blockSize100k < 1 || 9 < blockSize100k) {
		sig.SetError(ERR_ValueError, "blockSize100k must be specified between 1 and 9");
		return Value::Null;
	}
	Object_stream *pObjStream = GenerateCompressor(env, sig, stream, blockSize100k);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjStream));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stream
//-----------------------------------------------------------------------------
// stream#bzip2reader() {block?}
Gura_DeclareMethod(stream, bzip2reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, bzip2reader)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	Object_stream *pObjStream = GenerateDecompressor(env, sig, stream);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjStream));
}

// stream#bzip2writer(blockSize100k?:number) {block?}
Gura_DeclareMethod(stream, bzip2writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "blockSize100k", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, bzip2writer)
{
	int blockSize100k = args.Is_number(0)? args.GetInt(0) : 9;
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (blockSize100k < 1 || 9 < blockSize100k) {
		sig.SetError(ERR_ValueError, "blockSize100k must be specified between 1 and 9");
		return Value::Null;
	}
	Object_stream *pObjStream = GenerateCompressor(env, sig, stream, blockSize100k);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjStream));
}

// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(reader);
	Gura_AssignFunction(writer);
	// method assignment to stream type
	Gura_AssignMethodTo(VTYPE_stream, stream, bzip2reader);
	Gura_AssignMethodTo(VTYPE_stream, stream, bzip2writer);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Object_stream *GenerateDecompressor(Environment &env, Signal sig, Stream &stream)
{
	int verbosity = 0;
	int small = 0;
	AutoPtr<BZLib::Stream_Decompressor> pStream(
		new BZLib::Stream_Decompressor(env, sig, stream.Reference(), InvalidSize));
	if (!pStream->Initialize(sig, verbosity, small)) return NULL;
	return new Object_stream(env, pStream.release());
}

Object_stream *GenerateCompressor(Environment &env, Signal sig, Stream &stream, int blockSize100k)
{
	int verbosity = 0;
	int workFactor = 0;
	AutoPtr<BZLib::Stream_Compressor> pStream(
		new BZLib::Stream_Compressor(env, sig, stream.Reference()));
	if (!pStream->Initialize(sig, blockSize100k, verbosity, workFactor)) return NULL;
	return new Object_stream(env, pStream.release());
}

Gura_EndModuleBody(bzip2, bzip2)

Gura_RegisterModule(bzip2)
