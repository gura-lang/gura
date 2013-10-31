//-----------------------------------------------------------------------------
// Gura base64 module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(base64)

//-----------------------------------------------------------------------------
// Gura module functions: base64
//-----------------------------------------------------------------------------
// base64.reader(stream:stream:r)
Gura_DeclareFunction(reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "linelen", VTYPE_number, OCCUR_Once, FLAG_Nil, new Expr_Value(76));
}

Gura_ImplementFunction(writer)
{
	Stream &stream = args.GetStream(0);
	int nCharsPerLine = args.IsNumber(1)? args.GetInt(1) : -1;
	AutoPtr<Stream> pStream(new Stream_Base64Writer(env, sig,
								stream.Reference(), nCharsPerLine));
	return Value(new Object_stream(env, pStream.release()));
}

// base64.decode(stream:stream:r)
Gura_DeclareFunction(decode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "linelen", VTYPE_number, OCCUR_Once, FLAG_Nil, new Expr_Value(76));
}

Gura_ImplementFunction(encode)
{
	int nCharsPerLine = args.IsNumber(1)? args.GetInt(1) : -1;
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	Stream &streamSrc = args.GetStream(0);
	AutoPtr<Stream> pStreamDst(new Stream_Base64Writer(env, sig,
		new Stream_Binary(env, sig, Object_binary::Reference(pObjBinary.get()), true), nCharsPerLine));
	if (!streamSrc.ReadToStream(env, sig, *pStreamDst)) return Value::Null;
	return Value(pObjBinary.release());
}

//-----------------------------------------------------------------------------
// Gura interfaces for stream class
//-----------------------------------------------------------------------------
// stream#base64reader()
Gura_DeclareMethod(stream, base64reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(stream, base64reader)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	AutoPtr<Stream> pStream(new Stream_Base64Reader(env, sig, stream.Reference()));
	return Value(new Object_stream(env, pStream.release()));
}

// stream#base64writer(linelen:number => 76)
Gura_DeclareMethod(stream, base64writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "linelen", VTYPE_number, OCCUR_Once, FLAG_Nil, new Expr_Value(76));
}

Gura_ImplementMethod(stream, base64writer)
{
	int nCharsPerLine = args.IsNumber(0)? args.GetInt(0) : -1;
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	AutoPtr<Stream> pStream(new Stream_Base64Writer(env, sig,
								stream.Reference(), nCharsPerLine));
	return Value(new Object_stream(env, pStream.release()));
}

// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(reader);
	Gura_AssignFunction(writer);
	Gura_AssignFunction(decode);
	Gura_AssignFunction(encode);
	// method assignment to stream type
	Gura_AssignMethodTo(VTYPE_stream, stream, base64reader);
	Gura_AssignMethodTo(VTYPE_stream, stream, base64writer);
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(base64, base64)

Gura_RegisterModule(base64)
