//-----------------------------------------------------------------------------
// Gura bzip2 module
//-----------------------------------------------------------------------------
#include "Module_bzip2.h"
#include "gura/BZLibHelper.h"

Gura_BeginModule(bzip2)

//-----------------------------------------------------------------------------
// Gura module functions: bzip2
//-----------------------------------------------------------------------------
// bzip2.reader(stream:stream:r)
Gura_DeclareFunction(reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementFunction(reader)
{
	Stream &stream = args.GetStream(0);
	Object_stream *pObjStream = GenerateDecompressor(env, sig, stream);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObjStream);
}

// bzip2.writer(stream:stream:w)
Gura_DeclareFunction(writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
}

Gura_ImplementFunction(writer)
{
	Stream &stream = args.GetStream(0);
	Object_stream *pObjStream = GenerateCompressor(env, sig, stream);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObjStream);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stream
//-----------------------------------------------------------------------------
// stream#bzip2reader()
Gura_DeclareMethod(stream, bzip2reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(stream, bzip2reader)
{
	Stream &stream = Object_stream::GetSelfObj(args)->GetStream();
	Object_stream *pObjStream = GenerateDecompressor(env, sig, stream);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObjStream);
}

// stream#bzip2writer()
Gura_DeclareMethod(stream, bzip2writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(stream, bzip2writer)
{
	Stream &stream = Object_stream::GetSelfObj(args)->GetStream();
	Object_stream *pObjStream = GenerateCompressor(env, sig, stream);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObjStream);
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
		new BZLib::Stream_Decompressor(sig, Stream::Reference(&stream), InvalidSize));
	if (!pStream->Initialize(sig, 0, 0)) return NULL;
	return new Object_stream(env, pStream.release());
}

Object_stream *GenerateCompressor(Environment &env, Signal sig, Stream &stream)
{
	AutoPtr<BZLib::Stream_Compressor> pStream(
		new BZLib::Stream_Compressor(sig, Stream::Reference(&stream)));
	if (!pStream->Initialize(sig, 9, 0, 0)) return NULL;
	return new Object_stream(env, pStream.release());
}

Gura_EndModule(bzip2, bzip2)

Gura_RegisterModule(bzip2)
