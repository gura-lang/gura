//-----------------------------------------------------------------------------
// Gura module: base64
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(base64)

//-----------------------------------------------------------------------------
// Gura module functions: base64
//-----------------------------------------------------------------------------
// base64.decode(stream:stream:r)
Gura_DeclareFunction(decode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads text stream that is formatted in base64 and returns the decoded result in binary.");
}

Gura_ImplementFunction(decode)
{
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	AutoPtr<Stream> pStreamSrc(new Stream_Base64Reader(env, sig,
									args.GetStream(0).Reference()));
	AutoPtr<Stream> pStreamDst(new Stream_Binary(env, sig,
									Object_binary::Reference(pObjBinary.get()), true));
	if (!pStreamSrc->ReadToStream(env, sig, *pStreamDst)) return Value::Null;
	return Value(pObjBinary.release());
}

// base64.encode(stream:stream:r, linelen:number => 76)
Gura_DeclareFunction(encode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "linelen", VTYPE_number, OCCUR_Once, FLAG_Nil, new Expr_Value(76));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Encodes content of the stream into base64 format and returns the result in binary.");
}

Gura_ImplementFunction(encode)
{
	int nCharsPerLine = args.Is_number(1)? args.GetInt(1) : -1;
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	Stream &streamSrc = args.GetStream(0);
	AutoPtr<Stream> pStreamDst(new Stream_Base64Writer(env, sig,
		new Stream_Binary(env, sig, Object_binary::Reference(pObjBinary.get()), true), nCharsPerLine));
	if (!streamSrc.ReadToStream(env, sig, *pStreamDst)) return Value::Null;
	return Value(pObjBinary.release());
}

// base64.reader(stream:stream:r)
Gura_DeclareFunction(reader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a stream instance that reads data formatted in base64 from `stream`.\n");
}

Gura_ImplementFunction(reader)
{
	Stream &stream = args.GetStream(0);
	AutoPtr<Stream> pStream(new Stream_Base64Reader(env, sig, stream.Reference()));
	return Value(new Object_stream(env, pStream.release()));
}

// base64.writer(stream:stream:w, linelen:number => 76)
Gura_DeclareFunction(writer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "linelen", VTYPE_number, OCCUR_Once, FLAG_Nil, new Expr_Value(76));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a stream instance that encodes data to base64 format and writes it to the `stream`.\n"
		"\n"
		"The number of characters per line is specified by an argument `linelen`.\n"
		"If omitted, that is 76.\n");
}

Gura_ImplementFunction(writer)
{
	Stream &stream = args.GetStream(0);
	int nCharsPerLine = args.Is_number(1)? args.GetInt(1) : -1;
	AutoPtr<Stream> pStream(new Stream_Base64Writer(env, sig,
								stream.Reference(), nCharsPerLine));
	return Value(new Object_stream(env, pStream.release()));
}

//-----------------------------------------------------------------------------
// Gura interfaces for stream class
//-----------------------------------------------------------------------------
// stream#reader@base64()
Gura_DeclareMethodAlias(stream, reader_base64, "reader@base64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a stream instance that reads data formatted in base64 from the target stream instance.\n");
}

Gura_ImplementMethod(stream, reader_base64)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	AutoPtr<Stream> pStream(new Stream_Base64Reader(env, sig, stream.Reference()));
	return Value(new Object_stream(env, pStream.release()));
}

// stream#writer@base64(linelen:number => 76)
Gura_DeclareMethodAlias(stream, writer_base64, "writer@base64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "linelen", VTYPE_number, OCCUR_Once, FLAG_Nil, new Expr_Value(76));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a stream instance that encodes data to base64 format and writes it to the target stream instance.\n"
		"\n"
		"The number of characters per line is specified by an argument `linelen`.\n"
		"If omitted, that is 76.\n");
}

Gura_ImplementMethod(stream, writer_base64)
{
	int nCharsPerLine = args.Is_number(0)? args.GetInt(0) : -1;
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	AutoPtr<Stream> pStream(new Stream_Base64Writer(env, sig,
								stream.Reference(), nCharsPerLine));
	return Value(new Object_stream(env, pStream.release()));
}

// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(decode);
	Gura_AssignFunction(encode);
	Gura_AssignFunction(reader);
	Gura_AssignFunction(writer);
	// method assignment to stream type
	Gura_AssignMethodTo(VTYPE_stream, stream, reader_base64);
	Gura_AssignMethodTo(VTYPE_stream, stream, writer_base64);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(base64, base64)

Gura_RegisterModule(base64)
