//=============================================================================
// Gura class: stream
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_stream
//-----------------------------------------------------------------------------
bool Object_stream::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(stat));
	symbols.insert(Gura_Symbol(name));
	symbols.insert(Gura_Symbol(identifier));
	symbols.insert(Gura_Symbol(readable));
	symbols.insert(Gura_Symbol(writable));
	symbols.insert(Gura_Symbol(codec));
	return true;
}

Value Object_stream::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(stat))) {
		Object *pObj = GetStream().GetStatObj(sig);
		if (pObj != nullptr) return Value(pObj);
	} else if (pSymbol->IsIdentical(Gura_Symbol(name))) {
		return Value(GetStream().GetName());
	} else if (pSymbol->IsIdentical(Gura_Symbol(identifier))) {
		const char *identifier = GetStream().GetIdentifier();
		if (identifier == nullptr) return Value::Nil;
		return Value(identifier);
	} else if (pSymbol->IsIdentical(Gura_Symbol(readable))) {
		return Value(GetStream().IsReadable());
	} else if (pSymbol->IsIdentical(Gura_Symbol(writable))) {
		return Value(GetStream().IsWritable());
	} else if (pSymbol->IsIdentical(Gura_Symbol(codec))) {
		return Value(new Object_codec(env, Codec::Reference(GetStream().GetCodec())));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Iterator *Object_stream::CreateIterator(Signal &sig)
{
	return new IteratorLine(Object_stream::Reference(this), -1, true);
}

String Object_stream::ToString(bool exprFlag)
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
// Implementation of functions
//-----------------------------------------------------------------------------
// stream(pathname:string, mode?:string, encoding?:string):map {block?}
Gura_DeclareFunction(stream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareArg(env, "mode", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "codec", VTYPE_codec, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	if (::strcmp(GetName(), "stream") == 0) {
		SetClassToConstruct(env.LookupClass(VTYPE_stream));
	}
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `stream` instance from the specified `pathname`.\n"
		"\n"
		"The argument `mode` takes one of the strings that specifies what access\n"
		"should be allowed with the stream.\n"
		"If omitted, the stream would be opened with read mode.\n"
		"\n"
		"- `'r'` .. read\n"
		"- `'w'` .. write\n"
		"- `'a'` .. append\n"
		"\n"
		"The argument `codec` specifies a name of the character codec that converts\n"
		"between the stream's character code and UTF-8, which is a code\n"
		"used in the iterpreter's internal process.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("s", "stream"));
}

Gura_ImplementFunction(stream)
{
	Signal &sig = env.GetSignal();
	ULong attr = Stream::ATTR_Readable;
	if (arg.IsValid(1)) {
		attr = Stream::ParseOpenMode(sig, arg.GetString(1));
		if (sig.IsSignalled()) return Value::Nil;
	}
	Stream *pStream = Stream::Open(env, arg.GetString(0), attr);
	if (sig.IsSignalled()) return Value::Nil;
	if (arg.IsValid(2)) {
		Codec *pCodec = Object_codec::GetObject(arg, 2)->GetCodec();
		pStream->SetCodec(Codec::Reference(pCodec));
	} else {
		pStream->SetCodec(Codec::CreateCodecNone(true, false));
	}
	Value result(new Object_stream(env, pStream));
	if (arg.IsBlockSpecified()) {
		const Function *pFuncBlock =
						arg.GetBlockFunc(env, GetSymbolForBlock());
		if (pFuncBlock == nullptr) return Value::Nil;
		AutoPtr<Argument> pArgSub(new Argument(pFuncBlock));
		if (!pArgSub->AddValue(env, result)) return Value::Nil;
		pFuncBlock->Eval(env, *pArgSub);
		result = Value::Nil;	// object is destroyed here
	}
	return result;
}

// readlines(stream?:stream:r):[chop] {block?}
Gura_DeclareFunction(readlines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareAttr(Gura_Symbol(chop));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that reads text from the specified stream line by line.\n"
		"\n"
		"If attribute `:chop` is specified, it eliminates an end-of-line character that\n"
		"appears at the end of each line.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(readlines)
{
	Signal &sig = env.GetSignal();
	Object_stream *pObjStream = nullptr;
	if (arg.Is_stream(0)) {
		pObjStream = Object_stream::GetObject(arg, 0);
	} else {
		Module *pModuleSys = env.GetGlobal()->GetModule_sys();
		const Value *pValue = pModuleSys->LookupValue(Gura_Symbol(stdin), ENVREF_NoEscalate);
		if (pValue == nullptr) return Value::Nil;
		if (!pValue->Is_stream()) return Value::Nil;
		pObjStream = Object_stream::GetObject(*pValue);
	}
	if (!pObjStream->GetStream().CheckReadable(sig)) return Value::Nil;
	bool includeEOLFlag = !arg.IsSet(Gura_Symbol(chop));
	Iterator *pIterator = new Object_stream::IteratorLine(
				Object_stream::Reference(pObjStream), -1, includeEOLFlag);
	return ReturnIterator(env, arg, pIterator);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// stream#addcr(flag?:boolean):reduce
Gura_DeclareMethod(stream, addcr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"The codec's encoder in the stream has a feature\n"
		"to add a CR code (0x0d) before a LF code (0x0a)\n"
		"so that the lines are joined with CR-LF codes in the encoded result.\n"
		"This method enables or disables the feature.\n"
		"\n"
		"- To enable it, call the method with the argument `flag` set to `true` or without any argument.\n"
		"- To disable it, call the method with the argument `flag` set to `false`.\n");
}

Gura_ImplementMethod(stream, addcr)
{
	Object_stream *pThis = Object_stream::GetObjectThis(arg);
	Codec::Encoder *pEncoder = pThis->GetStream().GetCodec()->GetEncoder();
	pEncoder->SetAddcrFlag(arg.IsValid(0)? arg.GetBoolean(0) : true);
	return arg.GetValueThis();
}

// stream#close():void
Gura_DeclareMethod(stream, close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Closes the stream.");
}

Gura_ImplementMethod(stream, close)
{
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	stream.Close();
	return Value::Nil;
}

// stream#compare(stream:stream:r):map
Gura_DeclareMethod(stream, compare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `true` if there's no difference between the binary sequences of\n"
		"the target stream instance and that of `stream` in the argument.\n");
}

Gura_ImplementMethod(stream, compare)
{
	Signal &sig = env.GetSignal();
	Stream &stream1 = Object_stream::GetObjectThis(arg)->GetStream();
	Stream &stream2 = arg.GetStream(0);
	bool sameFlag = stream1.Compare(sig, stream2);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(sameFlag);
}

// stream.copy(src:stream:r, dst:stream:w, bytesunit:number => 65536):map:void:[finalize] {block?}
Gura_DeclareClassMethod(stream, copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "bytesunit", VTYPE_number,
					OCCUR_Once, FLAG_None, new Expr_Value(65536));
	DeclareAttr(Gura_Symbol(finalize));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Copies the content in `src` to the stream `dst`.\n"
		"\n"
		"The copying is done by the following process:\n"
		"\n"
		"1. Reads data from stream `src` into a buffer with the size specified by `bytesunit`.\n"
		"2. If `block` is specified, it would be evaluated with a block parameter `|buff:binary|`\n"
		"   where `buff` contains the read data. When the block's result is a `binary` instance,\n"
		"   the content would be written to the stream `dst`.\n"
		"   Otherwise, the read data would be written to stream `dst`.\n"
		"3. If `block` is not specified,　the read data would be written to stream `dst`.\n"
		"4. Continues from step 1 to 3 until data from `src` runs out.\n"
		"\n"
		"If the attribute `:finalize` is specified, some finalizing process will be applied\n"
		"at the end such as copying time stamp and attributes.\n"
		"\n"
		"This has the same feature as `stream#copyfrom()` and `stream#copyto()`.");
}

Gura_ImplementClassMethod(stream, copy)
{
	Signal &sig = env.GetSignal();
	bool finalizeFlag = arg.IsSet(Gura_Symbol(finalize));
	Stream &streamSrc = arg.GetStream(0);
	Stream &streamDst = arg.GetStream(1);
	size_t bytesUnit = arg.GetSizeT(2);
	const Function *pFuncFilter =
					arg.GetBlockFunc(env, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Nil;
	if (bytesUnit == 0 || bytesUnit > 1024 * 1024) {
		sig.SetError(ERR_ValueError, "wrong value for bytesunit");
		return Value::Nil;
	}
	streamSrc.ReadToStream(env, streamDst, bytesUnit, finalizeFlag, pFuncFilter);
	return Value::Nil;
}

// stream#copyfrom(src:stream:r, bytesunit:number => 65536):map:reduce:[finalize] {block?}
Gura_DeclareMethod(stream, copyfrom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "bytesunit", VTYPE_number,
					OCCUR_Once, FLAG_None, new Expr_Value(65536));
	DeclareAttr(Gura_Symbol(finalize));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Copies the content in `src` to the target stream instance.\n"
		"\n"
		"The copying is done by the following process:\n"
		"\n"
		"1. Reads data from stream `src` into a buffer with the size specified by `bytesunit`.\n"
		"2. If `block` is specified, it would be evaluated with a block parameter `|buff:binary|`\n"
		"   where `buff` contains the read data. When the block's result is a `binary` instance,\n"
		"   the content would be written to the stream `dst`.\n"
		"   Otherwise, the read data would be written to stream `dst`.\n"
		"3. If `block` is not specified,　the read data would be written to stream `dst`.\n"
		"4. Continues from step 1 to 3 until data from `src` runs out.\n"
		"\n"
		"If the attribute `:finalize` is specified, some finalizing process will be applied\n"
		"at the end such as copying time stamp and attributes.\n"
		"\n"
		"This has the same feature as `stream.copy()` and `stream#copyto()`.");
}

Gura_ImplementMethod(stream, copyfrom)
{
	Signal &sig = env.GetSignal();
	bool finalizeFlag = arg.IsSet(Gura_Symbol(finalize));
	Stream &streamDst = Object_stream::GetObjectThis(arg)->GetStream();
	Stream &streamSrc = arg.GetStream(0);
	size_t bytesUnit = arg.GetSizeT(1);
	const Function *pFuncFilter =
					arg.GetBlockFunc(env, GetSymbolForBlock());
	if (bytesUnit == 0 || bytesUnit > 1024 * 1024) {
		sig.SetError(ERR_ValueError, "wrong value for bytesunit");
		return Value::Nil;
	}
	if (!streamSrc.ReadToStream(env, streamDst, bytesUnit, finalizeFlag, pFuncFilter)) {
		return Value::Nil;
	}
	return arg.GetValueThis();
}

// stream#copyto(dst:stream:w, bytesunit:number => 65536):map:reduce {block?}
Gura_DeclareMethod(stream, copyto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "bytesunit", VTYPE_number,
					OCCUR_Once, FLAG_None, new Expr_Value(65536));
	DeclareAttr(Gura_Symbol(finalize));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Copies the content in the target stream instance to stream `dst`.\n"
		"\n"
		"The copying is done by the following process:\n"
		"\n"
		"1. Reads data from stream `src` into a buffer with the size specified by `bytesunit`.\n"
		"2. If `block` is specified, it would be evaluated with a block parameter `|buff:binary|`\n"
		"   where `buff` contains the read data. When the block's result is a `binary` instance,\n"
		"   the content would be written to the stream `dst`.\n"
		"   Otherwise, the read data would be written to stream `dst`.\n"
		"3. If `block` is not specified,　the read data would be written to stream `dst`.\n"
		"4. Continues from step 1 to 3 until data from `src` runs out.\n"
		"\n"
		"If the attribute `:finalize` is specified, some finalizing process will be applied\n"
		"at the end such as copying time stamp and attributes.\n"
		"\n"
		"This has the same feature as `stream.copy()` and `stream#copyfrom()`.");
}

Gura_ImplementMethod(stream, copyto)
{
	Signal &sig = env.GetSignal();
	bool finalizeFlag = arg.IsSet(Gura_Symbol(finalize));
	Stream &streamSrc = Object_stream::GetObjectThis(arg)->GetStream();
	Stream &streamDst = arg.GetStream(0);
	size_t bytesUnit = arg.GetSizeT(1);
	const Function *pFuncFilter =
					arg.GetBlockFunc(env, GetSymbolForBlock());
	if (bytesUnit == 0 || bytesUnit > 1024 * 1024) {
		sig.SetError(ERR_ValueError, "wrong value for bytesunit");
		return Value::Nil;
	}
	if (!streamSrc.ReadToStream(env, streamDst, bytesUnit, finalizeFlag, pFuncFilter)) {
		return Value::Nil;
	}
	return arg.GetValueThis();
}

// stream#delcr(flag?:boolean):reduce
Gura_DeclareMethod(stream, delcr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"The codec's decoder in the stream has a feature\n"
		"to delete a CR code (0x0d) before a LF code (0x0a)\n"
		"so that the lines are joined with LF code in the decoded result.\n"
		"This method enables or disables the feature.\n"
		"\n"
		"- To enable it, call the method with the argument `flag` set to `true` or without any argument.\n"
		"- To disable it, call the method with the argument `flag` set to `false`.\n");
}

Gura_ImplementMethod(stream, delcr)
{
	Object_stream *pThis = Object_stream::GetObjectThis(arg);
	Codec::Decoder *pDecoder = pThis->GetStream().GetCodec()->GetDecoder();
	pDecoder->SetDelcrFlag(arg.IsValid(0)? arg.GetBoolean(0) : true);
	return arg.GetValueThis();
}

// stream#deserialize()
Gura_DeclareMethod(stream, deserialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, deserialize)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Nil;
	Value value;
	if (!Value::Deserialize(env, stream, value, false)) return Value::Nil;
	return value;
}

// stream#flush():void
Gura_DeclareMethod(stream, flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Flushes cached data to the stream.");
}

Gura_ImplementMethod(stream, flush)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	stream.Flush(sig);
	return Value::Nil;
}

// stream#peek(len:number)
Gura_DeclareMethod(stream, peek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, peek)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Nil;
	Value result;
	size_t len = static_cast<size_t>(arg.GetNumber(0));
	char *buff = new char [len];
	size_t lenRead = stream.Peek(sig, buff, len);
	if (lenRead == 0) {
		delete [] buff;
		return Value::Nil;
	}
	result = Value(new Object_binary(env, Binary(buff, lenRead), true));
	delete [] buff;
	return result;
}

#if 0
// stream#prefetch()
Gura_DeclareMethod(stream, prefetch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, prefetch)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Nil;
	Stream *pStream = Stream::Prefetch(sig, &stream, false);
	return Value(new Object_stream(env, pStream));
}
#endif

// stream#print(values*):map:void
Gura_DeclareMethod(stream, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints out `values` to the `stream` instance.\n");
}

Gura_ImplementMethod(stream, print)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Nil;
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		String str(pValue->ToString(false));
		if (sig.IsSignalled()) break;
		stream.Print(sig, str.c_str());
		if (sig.IsSignalled()) break;
	}
	return Value::Nil;
}

// stream#printf(format, values*):map:void
Gura_DeclareMethod(stream, printf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints out `values` to the `stream` instance according to formatter specifiers in `format`.\n"
		"\n"
		"Refer to the help of `printf()` function to see information about formatter specifiers.\n");
}

Gura_ImplementMethod(stream, printf)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Nil;
	stream.PrintFmt(sig, arg.GetString(0), arg.GetList(1));
	return Value::Nil;
}

// stream#println(values*):map:void
Gura_DeclareMethod(stream, println)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints out `values` and an end-of-line character to the `stream` instance.\n");
}

Gura_ImplementMethod(stream, println)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Nil;
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		String str(pValue->ToString(false));
		if (sig.IsSignalled()) break;
		stream.Print(sig, str.c_str());
		if (sig.IsSignalled()) break;
	}
	stream.Print(sig, "\n");
	return Value::Nil;
}

// stream#read(len?:number)
Gura_DeclareMethod(stream, read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, read)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Nil;
	Value result;
	if (arg.Is_number(0)) {
		size_t len = static_cast<size_t>(arg.GetNumber(0));
		char *buff = new char [len];
		size_t lenRead = stream.Read(sig, buff, len);
		if (lenRead == 0) {
			delete [] buff;
			return Value::Nil;
		}
		result = Value(new Object_binary(env, Binary(buff, lenRead), true));
		delete [] buff;
	} else if (stream.IsInfinite()) {
		sig.SetError(ERR_IOError, "specify a reading size for infinite stream");
		return Value::Nil;
	} else {
		const int bytesBuff = 4096;
		AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
		Binary &buff = pObjBinary->GetBinary();
		AutoPtr<Memory> pMemory(new MemoryHeap(bytesBuff));
		char *buffSeg = reinterpret_cast<char *>(pMemory->GetPointer());
		size_t lenRead = stream.Read(sig, buffSeg, bytesBuff);
		if (lenRead == 0) return Value::Nil;
		do {
			buff.append(buffSeg, lenRead);
		} while ((lenRead = stream.Read(sig, buffSeg, bytesBuff)) > 0);
		if (sig.IsSignalled()) return Value::Nil;
		result = Value(pObjBinary.release());
	}
	return result;
}

// stream#readchar()
Gura_DeclareMethod(stream, readchar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, readchar)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Nil;
	String str = stream.ReadChar(sig);
	if (str.empty()) return Value::Nil;
	return Value(str);
}

// stream#readline():[chop]
Gura_DeclareMethod(stream, readline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(chop));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, readline)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Nil;
	int cntChars = 4096;	// tentative
	bool includeEOLFlag = !arg.IsSet(Gura_Symbol(chop));
	String str;
	while (cntChars-- > 0) {
		int ch = stream.GetChar(sig);
		if (sig.IsSignalled()) return Value::Nil;
		if (ch < 0) break;
		if (ch == '\n') {
			if (includeEOLFlag) str += '\n';
			return Value(str);
		}
		str += ch;
	}
	if (str.empty()) return Value::Nil;
	return Value(str);
}

// stream#readlines(nlines?:number):[chop] {block?}
// conrresponding to string#eachline()
Gura_DeclareMethod(stream, readlines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(chop));
	DeclareArg(env, "nlines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that reads text from the specified stream line by line.\n"
		"\n"
		"The argument `nlines` specifies how many lines should be read from the stream.\n"
		"If omitted, it would read all the lines.\n"
		"\n"
		"If attribute `:chop` is specified, it eliminates an end-of-line character that\n"
		"appears at the end of each line.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(stream, readlines)
{
	Signal &sig = env.GetSignal();
	Object_stream *pThis = Object_stream::GetObjectThis(arg);
	Stream &stream = pThis->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Nil;
	int nLinesMax = arg.Is_number(0)? static_cast<int>(arg.GetNumber(0)) : -1;
	bool includeEOLFlag = !arg.IsSet(Gura_Symbol(chop));
	Iterator *pIterator = new Object_stream::IteratorLine(
				Object_stream::Reference(pThis), nLinesMax, includeEOLFlag);
	return ReturnIterator(env, arg, pIterator);
}

// stream#readtext()
Gura_DeclareMethod(stream, readtext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, readtext)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckReadable(sig)) return Value::Nil;
	String str;
	for (;;) {
		int ch = stream.GetChar(sig);
		if (sig.IsSignalled()) return Value::Nil;
		if (ch < 0) break;
		str += ch;
	}
	return Value(str);
}

// stream#seek(offset:number, origin?:symbol):reduce
Gura_DeclareMethod(stream, seek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "origin", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, seek)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	Stream::SeekMode seekMode = Stream::SeekSet;
	if (arg.GetValue(1).Is_symbol()) {
		const Symbol *pSymbol = arg.GetSymbol(1);
		if (pSymbol->IsIdentical(Gura_Symbol(set))) {
			seekMode = Stream::SeekSet;
		} else if (pSymbol->IsIdentical(Gura_Symbol(cur))) {
			seekMode = Stream::SeekCur;
		} else {
			sig.SetError(ERR_ValueError, "invalid seek mode '%s'", pSymbol->GetName());
			return Value::Nil;
		}
	}
	stream.Seek(sig, arg.GetLong(0), seekMode);
	return arg.GetValueThis();
}

// stream#serialize(value):void
Gura_DeclareMethod(stream, serialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, serialize)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Nil;
	const Value &value = arg.GetValue(0);
	Value::Serialize(env, stream, value);
	return Value::Nil;
}

// stream#setcodec(codec:codec:nil):reduce
Gura_DeclareMethod(stream, setcodec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "codec", VTYPE_codec, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, setcodec)
{
	Object_stream *pThis = Object_stream::GetObjectThis(arg);
	Codec *pCodec = nullptr;
	if (arg.IsValid(0)) {
		pCodec = Codec::Reference(Object_codec::GetObject(arg, 0)->GetCodec());
	} else {
		pCodec = Codec::CreateCodecNone(true, false);
	}
	pThis->GetStream().SetCodec(pCodec);
	return arg.GetValueThis();
}

// stream#tell()
Gura_DeclareMethod(stream, tell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, tell)
{
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	return Value(static_cast<ULong>(stream.Tell()));
}

// stream#write(buff:binary, len?:number):reduce
Gura_DeclareMethod(stream, write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "buff", VTYPE_binary);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(stream, write)
{
	Signal &sig = env.GetSignal();
	Stream &stream = Object_stream::GetObjectThis(arg)->GetStream();
	if (!stream.CheckWritable(sig)) return Value::Nil;
	const Binary &binary = arg.GetBinary(0);
	size_t len = arg.Is_number(1)? arg.GetSizeT(1) : binary.size();
	if (len > binary.size()) {
		sig.SetError(ERR_MemoryError, "too large length");
		return Value::Nil;
	}
	stream.Write(sig, binary.c_str(), binary.size());
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Implementation of operator
//-----------------------------------------------------------------------------
// operator <<
Gura_ImplementBinaryOperator(Shl, stream, any)
{
	Signal &sig = env.GetSignal();
	Stream &stream = valueLeft.GetStream();
	if (!stream.CheckWritable(sig)) return Value::Nil;
	if (valueRight.Is_binary()) {
		const Binary &binary = valueRight.GetBinary();
		stream.Write(sig, binary.c_str(), binary.size());
		if (sig.IsSignalled()) return Value::Nil;
	} else {
		String str(valueRight.ToString(false));
		if (sig.IsSignalled()) return Value::Nil;
		stream.Print(sig, str.c_str());
		if (sig.IsSignalled()) return Value::Nil;
	}
	return valueLeft;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_stream::Class_stream(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_stream)
{
}

void Class_stream::Prepare(Environment &env)
{
	Gura_AssignFunctionEx(stream, "open");
	Gura_AssignFunction(stream);
	Gura_AssignFunction(readlines);
	Gura_AssignBinaryOperator(Shl, stream, any);
	Gura_AssignMethod(stream, addcr);
	Gura_AssignMethod(stream, close);
	Gura_AssignMethod(stream, compare);
	Gura_AssignMethod(stream, copy);
	Gura_AssignMethod(stream, copyfrom);
	Gura_AssignMethod(stream, copyto);
	Gura_AssignMethod(stream, delcr);
	Gura_AssignMethod(stream, deserialize);
	Gura_AssignMethod(stream, flush);
	Gura_AssignMethod(stream, peek);
	//Gura_AssignMethod(stream, prefetch);
	Gura_AssignMethod(stream, print);
	Gura_AssignMethod(stream, printf);
	Gura_AssignMethod(stream, println);
	Gura_AssignMethod(stream, read);
	Gura_AssignMethod(stream, readchar);
	Gura_AssignMethod(stream, readline);
	Gura_AssignMethod(stream, readlines);
	Gura_AssignMethod(stream, readtext);
	Gura_AssignMethod(stream, seek);
	Gura_AssignMethod(stream, serialize);
	Gura_AssignMethod(stream, setcodec);
	Gura_AssignMethod(stream, tell);
	Gura_AssignMethod(stream, write);
}

bool Class_stream::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	Signal &sig = GetSignal();
	if (value.Is_string()) {
		ULong attr = Stream::ATTR_Readable;
		if (pDecl != nullptr) {
			if (pDecl->GetFlag(FLAG_Write)) attr = Stream::ATTR_Writable;
			if (pDecl->GetFlag(FLAG_Read)) attr |= Stream::ATTR_Readable;
		}
		Stream *pStream = Stream::Open(env, value.GetString(), attr);
		if (sig.IsSignalled()) return false;
		value = Value(new Object_stream(env, pStream));
		return true;
	} else if (value.Is_binary()) {
		Object_binary *pObjBinary = Object_binary::Reference(Object_binary::GetObject(value));
		bool seekEndFlag = pDecl->GetFlag(FLAG_Write);
		Object *pObj = new Object_stream(env,
					new Stream_Binary(env, pObjBinary, seekEndFlag));
		value = Value(pObj);
		return true;
	}
	return false;
}

Object *Class_stream::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

//-----------------------------------------------------------------------------
// Object_stream::IteratorLine
//-----------------------------------------------------------------------------
Iterator *Object_stream::IteratorLine::GetSource()
{
	return nullptr;
}

bool Object_stream::IteratorLine::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	Stream &stream = _pObj->GetStream();
	if (_nLines == _nLinesMax) return false;
	String str;
	if (!stream.ReadLine(sig, str, _includeEOLFlag)) return false;
	_nLines++;
	value = Value(str);
	return true;
}

String Object_stream::IteratorLine::ToString() const
{
	return String("stream#readlines");
}

void Object_stream::IteratorLine::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
