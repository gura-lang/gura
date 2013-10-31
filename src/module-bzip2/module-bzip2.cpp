//-----------------------------------------------------------------------------
// Gura bzip2 module
//-----------------------------------------------------------------------------
#include "module-bzip2.h"

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

// bzip2.writer(stream:stream:w) {block?}
Gura_DeclareFunction(writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(writer)
{
	Stream &stream = args.GetStream(0);
	Object_stream *pObjStream = GenerateCompressor(env, sig, stream);
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

// stream#bzip2writer() {block?}
Gura_DeclareMethod(stream, bzip2writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, bzip2writer)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	Object_stream *pObjStream = GenerateCompressor(env, sig, stream);
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
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Object_stream *GenerateDecompressor(Environment &env, Signal sig, Stream &stream)
{
	AutoPtr<BZLib::Stream_Decompressor> pStream(
		new BZLib::Stream_Decompressor(env, sig, stream.Reference(), InvalidSize));
	if (!pStream->Initialize(sig, 0, 0)) return NULL;
	return new Object_stream(env, pStream.release());
}

Object_stream *GenerateCompressor(Environment &env, Signal sig, Stream &stream)
{
	AutoPtr<BZLib::Stream_Compressor> pStream(
		new BZLib::Stream_Compressor(env, sig, stream.Reference()));
	if (!pStream->Initialize(sig, 9, 0, 0)) return NULL;
	return new Object_stream(env, pStream.release());
}

Gura_EndModuleBody(bzip2, bzip2)

Gura_RegisterModule(bzip2)
