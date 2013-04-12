//
// Object_stream
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_stream
//-----------------------------------------------------------------------------
bool Object_stream::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(stat));
	symbols.insert(Gura_Symbol(name));
	symbols.insert(Gura_Symbol(identifier));
	symbols.insert(Gura_Symbol(readable));
	symbols.insert(Gura_Symbol(writable));
	symbols.insert(Gura_Symbol(codec));
	return true;
}

Value Object_stream::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(stat))) {
		Object *pObj = GetStream().GetStatObj(sig);
		if (pObj != NULL) return Value(pObj);
	} else if (pSymbol->IsIdentical(Gura_Symbol(name))) {
		return Value(env, GetStream().GetName());
	} else if (pSymbol->IsIdentical(Gura_Symbol(identifier))) {
		const char *identifier = GetStream().GetIdentifier();
		if (identifier == NULL) return Value::Null;
		return Value(env, identifier);
	} else if (pSymbol->IsIdentical(Gura_Symbol(readable))) {
		return Value(GetStream().IsReadable());
	} else if (pSymbol->IsIdentical(Gura_Symbol(writable))) {
		return Value(GetStream().IsWritable());
	} else if (pSymbol->IsIdentical(Gura_Symbol(codec))) {
		return Value(new Object_codec(env, Codec::Reference(GetStream().GetCodec())));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Iterator *Object_stream::CreateIterator(Signal sig)
{
	return new IteratorLine(Object_stream::Reference(this), -1, true);
}

String Object_stream::ToString(Signal sig, bool exprFlag)
{
	String str;
	Stream &stream = GetStream();
	str += "<stream:";
	if (stream.IsReadable()) str += "R";
	if (stream.IsWritable()) str += "W";
	str += ":";
	str += stream.GetCodec()->GetEncoding();
	if (stream.GetCodec()->GetDecoder()->GetDelcrFlag()) {
		str += ":delcr";
	}
	if (stream.GetCodec()->GetEncoder()->GetAddcrFlag()) {
		str += ":addcr";
	}
	if (*stream.GetName() != '\0') {
		str += ":";
		str += stream.GetName();
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// open(name:string, mode?:string, encoding?:string):map {block?}
Gura_DeclareFunction(open)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string);
	DeclareArg(env, "mode", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "codec", VTYPE_codec, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(open)
{
	unsigned long attr = Stream::ATTR_Readable;
	if (args.IsValid(1)) {
		attr = Stream::ParseOpenMode(sig, args.GetString(1));
		if (sig.IsSignalled()) return Value::Null;
	}
	Stream *pStream = Directory::OpenStream(env, sig, args.GetString(0), attr);
	if (sig.IsSignalled()) return Value::Null;
	if (args.IsValid(2)) {
		Codec *pCodec = Object_codec::GetObject(args, 2)->GetCodec();
		pStream->SetCodec(Codec::Reference(pCodec));
	} else {
		pStream->SetCodec(Codec::CreateCodecNone(true, false));
	}
	Value result(new Object_stream(env, pStream));
	if (args.IsBlockSpecified()) {
		const Function *pFuncBlock =
						args.GetBlockFunc(env, sig, GetSymbolForBlock());
		if (pFuncBlock == NULL) return Value::Null;
		ValueList valListArg(result);
		Args argsSub(valListArg);
		pFuncBlock->Eval(env, sig, argsSub);
		result = Value::Null;	// object is destroyed here
	}
	return result;
}

// copy(src:stream:r, dst:stream:w, bytesunit:number => 65536):map:void {block?}
Gura_DeclareFunction(copy)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "bytesunit", VTYPE_number,
					OCCUR_Once, FLAG_None, new Expr_Value(65536));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(copy)
{
	bool finalizeFlag = true;
	Stream &streamSrc = args.GetStream(0);
	Stream &streamDst = args.GetStream(1);
	size_t bytesUnit = args.GetSizeT(2);
	const Function *pFuncFilter =
					args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Null;
	if (bytesUnit == 0 || bytesUnit > 1024 * 1024) {
		sig.SetError(ERR_ValueError, "wrong value for bytesunit");
		return Value::Null;
	}
	streamSrc.ReadToStream(env, sig, streamDst, bytesUnit, finalizeFlag, pFuncFilter);
	return Value::Null;
}

// template(src:stream:r, dst?:stream:w):map:[noindent,lasteol]
Gura_DeclareFunctionAlias(template_, "template")
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(template_)
{
	bool autoIndentFlag = !args.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = args.IsSet(Gura_Symbol(lasteol));
	Stream &streamSrc = args.GetStream(0);
	if (args.IsStream(1)) {
		Stream &streamDst = args.GetStream(1);
		TemplateEngine(autoIndentFlag, appendLastEOLFlag).
							EvalStream(env, sig, streamSrc, streamDst);
		return Value::Null;
	} else {
		String strDst;
		SimpleStream_StringWrite streamDst(strDst);
		if (!TemplateEngine(autoIndentFlag, appendLastEOLFlag).
				EvalStream(env, sig, streamSrc, streamDst)) return Value::Null;
		return Value(env, strDst.c_str());
	}
}

// readlines(stream?:stream:r):[chop] {block?}
Gura_DeclareFunction(readlines)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareAttr(Gura_Symbol(chop));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(readlines)
{
	Object_stream *pObjStream = NULL;
	if (args.IsStream(0)) {
		pObjStream = Object_stream::GetObject(args, 0);
	} else {
		Module *pModuleSys = env.GetModule_sys();
		const Value *pValue = pModuleSys->LookupValue(Gura_Symbol(stdin), ENVREF_NoEscalate);
		if (pValue == NULL) return Value::Null;
		if (!pValue->IsStream()) return Value::Null;
		pObjStream = Object_stream::GetObject(*pValue);
	}
	if (!pObjStream->GetStream().CheckReadable(sig)) return Value::Null;
	bool includeEOLFlag = !args.IsSet(Gura_Symbol(chop));
	Iterator *pIterator = new Object_stream::IteratorLine(
				Object_stream::Reference(pObjStream), -1, includeEOLFlag);
	return ReturnIterator(env, sig, args, pIterator);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stream
//-----------------------------------------------------------------------------
// stream#close()
Gura_DeclareMethod(stream, close)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(stream, close)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	stream.Close();
	return Value::Null;
}

// stream#read(len?:number)
Gura_DeclareMethod(stream, read)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, read)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Null;
	Value result;
	if (args.IsNumber(0)) {
		size_t len = static_cast<size_t>(args.GetNumber(0));
		char *buff = new char [len];
		size_t lenRead = stream.Read(sig, buff, len);
		if (lenRead == 0) {
			delete [] buff;
			return Value::Null;
		}
		result = Value(new Object_binary(env, Binary(buff, lenRead), true));
		delete [] buff;
	} else if (stream.IsInfinite()) {
		sig.SetError(ERR_IOError, "specify a reading size for infinite stream");
		return Value::Null;
	} else {
		const int bytesBuff = 4096;
		AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
		Binary &buff = pObjBinary->GetBinary();
		OAL::Memory memory(bytesBuff);
		char *buffSeg = reinterpret_cast<char *>(memory.GetPointer());
		size_t lenRead = stream.Read(sig, buffSeg, bytesBuff);
		if (lenRead == 0) return Value::Null;
		do {
			buff.append(buffSeg, lenRead);
		} while ((lenRead = stream.Read(sig, buffSeg, bytesBuff)) > 0);
		if (sig.IsSignalled()) return Value::Null;
		result = Value(pObjBinary.release());
	}
	return result;
}

// stream#peek(len:number)
Gura_DeclareMethod(stream, peek)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, peek)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Null;
	Value result;
	size_t len = static_cast<size_t>(args.GetNumber(0));
	char *buff = new char [len];
	size_t lenRead = stream.Peek(sig, buff, len);
	if (lenRead == 0) {
		delete [] buff;
		return Value::Null;
	}
	result = Value(new Object_binary(env, Binary(buff, lenRead), true));
	delete [] buff;
	return result;
}

// stream#write(buff:binary, len?:number):reduce
Gura_DeclareMethod(stream, write)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "buff", VTYPE_binary);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, write)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Null;
	const Binary &binary = args.GetBinary(0);
	size_t len = args.IsNumber(1)? args.GetSizeT(1) : binary.size();
	if (len > binary.size()) {
		sig.SetError(ERR_MemoryError, "too large length");
		return Value::Null;
	}
	stream.Write(sig, binary.c_str(), binary.size());
	return args.GetThis();
}

// stream#seek(offset:number, origin?:symbol):reduce
Gura_DeclareMethod(stream, seek)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "origin", VTYPE_symbol, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, seek)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	Stream::SeekMode seekMode = Stream::SeekSet;
	if (args.GetValue(1).IsSymbol()) {
		const Symbol *pSymbol = args.GetSymbol(1);
		if (pSymbol->IsIdentical(Gura_Symbol(set))) {
			seekMode = Stream::SeekSet;
		} else if (pSymbol->IsIdentical(Gura_Symbol(cur))) {
			seekMode = Stream::SeekCur;
		} else {
			sig.SetError(ERR_ValueError, "invalid seek mode %s", pSymbol->GetName());
			return Value::Null;
		}
	}
	stream.Seek(sig, args.GetLong(0), seekMode);
	return args.GetThis();
}

// stream#tell()
Gura_DeclareMethod(stream, tell)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(stream, tell)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	return Value(static_cast<unsigned long>(stream.Tell()));
}

// stream#flush();void
Gura_DeclareMethod(stream, flush)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(stream, flush)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	stream.Flush(sig);
	return Value::Null;
}

// stream#compare(stream:stream:r):map
Gura_DeclareMethod(stream, compare)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementMethod(stream, compare)
{
	Stream &stream1 = Object_stream::GetThisObj(args)->GetStream();
	Stream &stream2 = args.GetStream(0);
	bool sameFlag = stream1.Compare(sig, stream2);
	if (sig.IsSignalled()) return Value::Null;
	return Value(sameFlag);
}

// stream#copyto(stream:stream:w, bytesunit:number => 65536):map:reduce {block?}
Gura_DeclareMethod(stream, copyto)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "bytesunit", VTYPE_number,
					OCCUR_Once, FLAG_None, new Expr_Value(65536));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, copyto)
{
	bool finalizeFlag = true;
	Stream &streamSrc = Object_stream::GetThisObj(args)->GetStream();
	Stream &streamDst = args.GetStream(0);
	size_t bytesUnit = args.GetSizeT(1);
	const Function *pFuncFilter =
					args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (bytesUnit == 0 || bytesUnit > 1024 * 1024) {
		sig.SetError(ERR_ValueError, "wrong value for bytesunit");
		return Value::Null;
	}
	if (!streamSrc.ReadToStream(env, sig, streamDst, bytesUnit, finalizeFlag, pFuncFilter)) {
		return Value::Null;
	}
	return args.GetThis();
}

// stream#copyfrom(stream:stream:r, bytesunit:number => 65536):map:reduce {block?}
Gura_DeclareMethod(stream, copyfrom)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "bytesunit", VTYPE_number,
					OCCUR_Once, FLAG_None, new Expr_Value(65536));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, copyfrom)
{
	bool finalizeFlag = true;
	Stream &streamDst = Object_stream::GetThisObj(args)->GetStream();
	Stream &streamSrc = args.GetStream(0);
	size_t bytesUnit = args.GetSizeT(1);
	const Function *pFuncFilter =
					args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (bytesUnit == 0 || bytesUnit > 1024 * 1024) {
		sig.SetError(ERR_ValueError, "wrong value for bytesunit");
		return Value::Null;
	}
	if (!streamSrc.ReadToStream(env, sig, streamDst, bytesUnit, finalizeFlag, pFuncFilter)) {
		return Value::Null;
	}
	return args.GetThis();
}

// stream#setcodec(codec:codec:nil):reduce
Gura_DeclareMethod(stream, setcodec)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "codec", VTYPE_codec, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(stream, setcodec)
{
	Object_stream *pThis = Object_stream::GetThisObj(args);
	Codec *pCodec = NULL;
	if (args.IsValid(0)) {
		pCodec = Codec::Reference(Object_codec::GetObject(args, 0)->GetCodec());
	} else {
		pCodec = Codec::CreateCodecNone(true, false);
	}
	pThis->GetStream().SetCodec(pCodec);
	return args.GetThis();
}

// stream#addcr(flag?:boolean):reduce
Gura_DeclareMethod(stream, addcr)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, addcr)
{
	Object_stream *pThis = Object_stream::GetThisObj(args);
	CodecEncoder *pEncoder = pThis->GetStream().GetCodec()->GetEncoder();
	pEncoder->SetAddcrFlag(args.IsValid(0)? args.GetBoolean(0) : true);
	return args.GetThis();
}

// stream#delcr(flag?:boolean):reduce
Gura_DeclareMethod(stream, delcr)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, delcr)
{
	Object_stream *pThis = Object_stream::GetThisObj(args);
	CodecDecoder *pDecoder = pThis->GetStream().GetCodec()->GetDecoder();
	pDecoder->SetDelcrFlag(args.IsValid(0)? args.GetBoolean(0) : true);
	return args.GetThis();
}

// stream#readline():[chop]
Gura_DeclareMethod(stream, readline)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(chop));
}

Gura_ImplementMethod(stream, readline)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Null;
	int cntChars = 4096;	// tentative
	bool includeEOLFlag = !args.IsSet(Gura_Symbol(chop));
	String str;
	while (cntChars-- > 0) {
		int ch = stream.GetChar(sig);
		if (sig.IsSignalled()) return Value::Null;
		if (ch < 0) break;
		if (ch == '\n') {
			if (includeEOLFlag) str += '\n';
			return Value(env, str.c_str());
		}
		str += ch;
	}
	if (str.empty()) return Value::Null;
	return Value(env, str.c_str());
}

// stream#readlines(nlines?:number):[chop] {block?}
// conrresponding to string#splitlines()
Gura_DeclareMethod(stream, readlines)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(chop));
	DeclareArg(env, "nlines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, readlines)
{
	Object_stream *pThis = Object_stream::GetThisObj(args);
	Stream &stream = pThis->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Null;
	int nLinesMax = args.IsNumber(0)? static_cast<int>(args.GetNumber(0)) : -1;
	bool includeEOLFlag = !args.IsSet(Gura_Symbol(chop));
	Iterator *pIterator = new Object_stream::IteratorLine(
				Object_stream::Reference(pThis), nLinesMax, includeEOLFlag);
	return ReturnIterator(env, sig, args, pIterator);
}

// stream#readtext()
Gura_DeclareMethod(stream, readtext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(stream, readtext)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Null;
	String str;
	for (;;) {
		int ch = stream.GetChar(sig);
		if (sig.IsSignalled()) return Value::Null;
		if (ch < 0) break;
		str += ch;
	}
	return Value(env, str.c_str());
}

// stream#parse() {block?}
Gura_DeclareMethod(stream, parse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Parse a content of a script stream and returns an expr object.");
}

Gura_ImplementMethod(stream, parse)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	Expr *pExpr = Parser().ParseStream(env, sig, stream);
	if (pExpr == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Value(env, pExpr));
}

// stream#template(dst?:stream:w):map:[noindent,lasteol]
Gura_DeclareMethodAlias(stream, template_, "template")
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(stream, template_)
{
	bool autoIndentFlag = !args.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = args.IsSet(Gura_Symbol(lasteol));
	Stream &streamSrc = Object_stream::GetThisObj(args)->GetStream();
	if (args.IsStream(0)) {
		Stream &streamDst = args.GetStream(0);
		TemplateEngine(autoIndentFlag, appendLastEOLFlag).
							EvalStream(env, sig, streamSrc, streamDst);
		return Value::Null;
	} else {
		String strDst;
		SimpleStream_StringWrite streamDst(strDst);
		if (!TemplateEngine(autoIndentFlag, appendLastEOLFlag).
				EvalStream(env, sig, streamSrc, streamDst)) return Value::Null;
		return Value(env, strDst.c_str());
	}
}

// stream#print(values*):map:void
Gura_DeclareMethod(stream, print)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementMethod(stream, print)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Null;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		String str(pValue->ToString(sig, false));
		if (sig.IsSignalled()) break;
		stream.Print(sig, str.c_str());
		if (sig.IsSignalled()) break;
	}
	return Value::Null;
}

// stream#println(values*):map:void
Gura_DeclareMethod(stream, println)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementMethod(stream, println)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Null;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		String str(pValue->ToString(sig, false));
		if (sig.IsSignalled()) break;
		stream.Print(sig, str.c_str());
		if (sig.IsSignalled()) break;
	}
	stream.Print(sig, "\n");
	return Value::Null;
}

// stream#printf(format, values*):map:void
Gura_DeclareMethod(stream, printf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementMethod(stream, printf)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Null;
	stream.Printf(sig, args.GetString(0), args.GetList(1));
	return Value::Null;
}

// stream#serialize(value):void
Gura_DeclareMethod(stream, serialize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
}

Gura_ImplementMethod(stream, serialize)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Null;
	const Value &value = args.GetValue(0);
	Value::Serialize(env, sig, stream, value);
	return Value::Null;
}

// stream#deserialize()
Gura_DeclareMethod(stream, deserialize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(stream, deserialize)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Null;
	Value value;
	if (!Value::Deserialize(env, sig, stream, value, false)) return Value::Null;
	return value;
}

#if 0
// stream#prefetch()
Gura_DeclareMethod(stream, prefetch)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
}

Gura_ImplementMethod(stream, prefetch)
{
	Stream &stream = Object_stream::GetThisObj(args)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Null;
	Stream *pStream = Stream::Prefetch(sig, &stream, false);
	return Value(env, pStream);
}
#endif

// stream#__shl__(stream:stream, value)
Gura_DeclareMethod(stream, __shl__)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_any, OCCUR_Once);
}

Gura_ImplementMethod(stream, __shl__)
{
	Stream &stream = args.GetStream(0);
	if (!stream.CheckWritable(sig)) return Value::Null;
	if (args.IsBinary(1)) {
		const Binary &binary = args.GetBinary(1);
		stream.Write(sig, binary.c_str(), binary.size());
		if (sig.IsSignalled()) return Value::Null;
	} else {
		const Value &value = args.GetValue(1);
		String str(value.ToString(sig, false));
		if (sig.IsSignalled()) return Value::Null;
		stream.Print(sig, str.c_str());
		if (sig.IsSignalled()) return Value::Null;
	}
	return args.GetValue(0);
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_stream::Class_stream(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_stream)
{
	Gura_AssignMethod(stream, close);
	Gura_AssignMethod(stream, read);
	Gura_AssignMethod(stream, peek);
	Gura_AssignMethod(stream, write);
	Gura_AssignMethod(stream, seek);
	Gura_AssignMethod(stream, tell);
	Gura_AssignMethod(stream, flush);
	Gura_AssignMethod(stream, compare);
	Gura_AssignMethod(stream, copyto);
	Gura_AssignMethod(stream, copyfrom);
	Gura_AssignMethod(stream, setcodec);
	Gura_AssignMethod(stream, addcr);
	Gura_AssignMethod(stream, delcr);
	Gura_AssignMethod(stream, readline);
	Gura_AssignMethod(stream, readlines);
	Gura_AssignMethod(stream, readtext);
	Gura_AssignMethod(stream, parse);
	Gura_AssignMethod(stream, template_);
	Gura_AssignMethod(stream, print);
	Gura_AssignMethod(stream, println);
	Gura_AssignMethod(stream, printf);
	Gura_AssignMethod(stream, serialize);
	Gura_AssignMethod(stream, deserialize);
	//Gura_AssignMethod(stream, prefetch);
	Gura_AssignMethod(stream, __shl__);
}

bool Class_stream::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsString()) {
		unsigned long attr = Stream::ATTR_Readable;
		if (pDecl != NULL) {
			if (pDecl->GetWriteFlag()) attr = Stream::ATTR_Writable;
			if (pDecl->GetReadFlag()) attr |= Stream::ATTR_Readable;
		}
		Stream *pStream = Directory::OpenStream(env, sig, value.GetString(), attr);
		if (sig.IsSignalled()) return false;
		value = Value(new Object_stream(env, pStream));
		return true;
	} else if (value.IsBinary()) {
		Object_binary *pObjBinary = Object_binary::Reference(
						dynamic_cast<Object_binary *>(value.GetObject()));
		bool seekEndFlag = pDecl->GetWriteFlag();
		Object *pObj = new Object_stream(env,
					new Stream_Binary(env, sig, pObjBinary, seekEndFlag));
		value = Value(pObj);
		return true;
	}
	return false;
}

Object *Class_stream::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return NULL;
}

void Class_stream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(open);
	Gura_AssignFunction(copy);
	Gura_AssignFunction(template_);
	Gura_AssignFunction(readlines);
}

//-----------------------------------------------------------------------------
// Object_stream::IteratorLine
//-----------------------------------------------------------------------------
Iterator *Object_stream::IteratorLine::GetSource()
{
	return NULL;
}

bool Object_stream::IteratorLine::DoNext(Environment &env, Signal sig, Value &value)
{
	Stream &stream = _pObj->GetStream();
	String str;
	if (_nLines == _nLinesMax) return false;
	int ch = stream.GetChar(sig);
	if (ch < 0) return false;
	for ( ; ch >= 0; ch = stream.GetChar(sig)) {
		if (ch == '\n') {
			if (_includeEOLFlag) str += '\n';
			break;
		}
		str += ch;
	}
	if (sig.IsSignalled()) return false;
	_nLines++;
	value = Value(*_pObj, str.c_str());
	return true;
}

String Object_stream::IteratorLine::ToString(Signal sig) const
{
	return String("<iterator:stream#readlines>");
}

void Object_stream::IteratorLine::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
