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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a stream instance that decompresses bzip2 data from the specified `stream`\n"
		"that has readable attribute.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("st", "stream"));
}

Gura_ImplementFunction(reader)
{
	Signal &sig = env.GetSignal();
	Stream &stream = arg.GetStream(0);
	Object_stream *pObjStream = GenerateDecompressor(env, stream);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(pObjStream));
}

// bzip2.writer(stream:stream:w, blockSize100k?:number) {block?}
Gura_DeclareFunction(writer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "blockSize100k", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a stream instance that compresses data into bzip2 format\n"
		"and writes it to the specified `stream` that has writable attribute.\n"
		"\n"
		"The argument `blockSize100k` takes a number between 1 and 9\n"
		"that specifies the block size to be used for compression.\n"
		"The actual block size is 100000 times of this value.\n"
		"Nine gives the best compression but takes most memory.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("st", "stream"));
}

Gura_ImplementFunction(writer)
{
	Signal &sig = env.GetSignal();
	Stream &stream = arg.GetStream(0);
	int blockSize100k = arg.Is_number(1)? arg.GetInt(1) : 9;
	if (blockSize100k < 1 || 9 < blockSize100k) {
		sig.SetError(ERR_ValueError, "blockSize100k must be specified between 1 and 9");
		return Value::Nil;
	}
	Object_stream *pObjStream = GenerateCompressor(env, stream, blockSize100k);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(pObjStream));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stream
//-----------------------------------------------------------------------------
// stream#reader@bzip2() {block?}
Gura_DeclareMethodAlias(stream, reader_bzip2, "reader@bzip2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a stream instance that decompresses bzip2 data from the specified `stream`\n"
		"that has readable attribute.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("st", "stream"));
}

Gura_ImplementMethod(stream, reader_bzip2)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	Object_stream *pObjStream = GenerateDecompressor(env, stream);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(pObjStream));
}

// stream#writer_bzip2(blockSize100k?:number) {block?}
Gura_DeclareMethodAlias(stream, writer_bzip2, "writer@bzip2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "blockSize100k", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a stream instance that compresses data into bzip2 format\n"
		"and writes it to the specified `stream` that has writable attribute.\n"
		"\n"
		"The argument `blockSize100k` takes a number between 1 and 9\n"
		"that specifies the block size to be used for compression.\n"
		"The actual block size is 100000 times of this value.\n"
		"Nine gives the best compression but takes most memory.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("st", "stream"));
}

Gura_ImplementMethod(stream, writer_bzip2)
{
	Signal &sig = env.GetSignal();
	int blockSize100k = arg.Is_number(0)? arg.GetInt(0) : 9;
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (blockSize100k < 1 || 9 < blockSize100k) {
		sig.SetError(ERR_ValueError, "blockSize100k must be specified between 1 and 9");
		return Value::Nil;
	}
	Object_stream *pObjStream = GenerateCompressor(env, stream, blockSize100k);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(pObjStream));
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
	// function assignment
	Gura_AssignFunction(reader);
	Gura_AssignFunction(writer);
	// method assignment to stream type
	Gura_AssignMethodTo(VTYPE_stream, stream, reader_bzip2);
	Gura_AssignMethodTo(VTYPE_stream, stream, writer_bzip2);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Object_stream *GenerateDecompressor(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	int verbosity = 0;
	int small = 0;
	AutoPtr<BZLib::Stream_Decompressor> pStream(
		new BZLib::Stream_Decompressor(env, stream.Reference(), InvalidSize));
	if (!pStream->Initialize(sig, verbosity, small)) return nullptr;
	return new Object_stream(env, pStream.release());
}

Object_stream *GenerateCompressor(Environment &env, Stream &stream, int blockSize100k)
{
	Signal &sig = env.GetSignal();
	int verbosity = 0;
	int workFactor = 0;
	AutoPtr<BZLib::Stream_Compressor> pStream(
		new BZLib::Stream_Compressor(env, stream.Reference()));
	if (!pStream->Initialize(sig, blockSize100k, verbosity, workFactor)) return nullptr;
	return new Object_stream(env, pStream.release());
}

Gura_EndModuleBody(bzip2, bzip2)

Gura_RegisterModule(bzip2)
