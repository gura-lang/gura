//=============================================================================
// Gura class: pointer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_pointer
//-----------------------------------------------------------------------------
Object_pointer::~Object_pointer()
{
}

Object *Object_pointer::Clone() const
{
	return new Object_pointer(*this);
}

bool Object_pointer::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(offset));
	symbols.insert(Gura_Symbol(size));
	symbols.insert(Gura_Symbol(target));
	return true;
}

Value Object_pointer::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(offset))) {
		return Value(GetPointer()->GetOffset());
	} else if (pSymbol->IsIdentical(Gura_Symbol(size))) {
		return Value(GetPointer()->GetSize());
	} else if (pSymbol->IsIdentical(Gura_Symbol(target))) {
		return Value(GetPointer()->GetTarget()->Reference());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_pointer::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	if (pSymbol->IsIdentical(Gura_Symbol(offset))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		size_t offset = value.GetSizeT();
		GetPointer()->SetOffset(offset);
		return Value(offset);
	}
	return Value::Nil;
}

String Object_pointer::ToString(bool exprFlag)
{
	char buff[64];
	::sprintf(buff, "<pointer:%d>", static_cast<int>(GetPointer()->GetOffset()));
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// pointer(org:pointer):map {block?}
Gura_DeclareFunction(pointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "org", VTYPE_pointer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_pointer));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `pointer` instance that is cloned from the given instance `org`.\n"
		"You can use this to cast a `binary` and `memory` instance to the `pointer`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("ptr", "pointer"));
}

Gura_ImplementFunction(pointer)
{
	Pointer *pPointer = Object_pointer::GetObject(arg, 0)->GetPointer();
	return ReturnValue(env, arg, Value(new Object_pointer(env, pPointer->Clone())));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// pointer#copyfrom(src:pointer, bytes?:number):map:reduce
Gura_DeclareMethod(pointer, copyfrom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "src", VTYPE_pointer, OCCUR_Once);
	DeclareArg(env, "bytes", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Copies data from `src` to the target pointer.\n"
		"\n"
		"If the argument `bytes` is specified, it would limit the size of data to be copied.\n"
		"Otherwise, all the data pointerd by `src` is to be copied.\n"
		"\n"
		"This method returns a reference to the target instance itself.\n");
}

Gura_ImplementMethod(pointer, copyfrom)
{
	Pointer *pPointerDst = Object_pointer::GetObjectThis(arg)->GetPointer();
	Pointer *pPointerSrc = Object_pointer::GetObject(arg, 0)->GetPointer();
	size_t bytes = arg.IsValid(1)? arg.GetSizeT(1) : pPointerSrc->GetSize();
	pPointerDst->PutBuffer(env, pPointerSrc->GetPointerC(), bytes);
	return arg.GetValueThis();
}

// pointer#copyto(dst:pointer, bytes?:number):map:reduce
Gura_DeclareMethod(pointer, copyto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "dst", VTYPE_pointer, OCCUR_Once);
	DeclareArg(env, "bytes", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Copies data from the target pointer to `dst`.\n"
		"\n"
		"If the argument `bytes` is specified, it would limit the size of data to be copied.\n"
		"Otherwise, all the data pointerd by the target instance is to be copied.\n"
		"\n"
		"This method returns a reference to the target instance itself.\n");
}

Gura_ImplementMethod(pointer, copyto)
{
	Pointer *pPointerSrc = Object_pointer::GetObjectThis(arg)->GetPointer();
	Pointer *pPointerDst = Object_pointer::GetObject(arg, 0)->GetPointer();
	size_t bytes = arg.IsValid(1)? arg.GetSizeT(1) : pPointerSrc->GetSize();
	pPointerDst->PutBuffer(env, pPointerSrc->GetPointerC(), bytes);
	return arg.GetValueThis();
}

// pointer#decode(codec:codec, bytes?:number) {block?}
Gura_DeclareMethod(pointer, decode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "codec", VTYPE_codec);
	DeclareArg(env, "bytes", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Decodes the content of the `pointer` as a sequence of string characters using `codec`\n"
		"and returns the result in `string`.\n"
		"\n"
		"If the argument `bytes` is specified, it would limit the size of data to be decoded.\n"
		"Otherwise, all the data pointerd by the target instance is to be decoded.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("str", "string"));
}

Gura_ImplementMethod(pointer, decode)
{
	Signal &sig = env.GetSignal();
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	Codec *pCodec = Object_codec::GetObject(arg, 0)->GetCodec();
	String str;
	size_t bytes = pPointer->GetSize();
	if (arg.IsValid(1) && (bytes = arg.GetSizeT(1)) > pPointer->GetSize()) {
		env.SetError(ERR_OutOfRangeError, "out of range");
		return Value::Nil;
	}
	const char *p = reinterpret_cast<const char *>(pPointer->GetPointerC());
	if (!pCodec->GetDecoder()->Decode(sig, str, p, bytes)) {
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(str));
}

// pointer#dump(stream?:stream:w, bytes?:number):reduce:[upper]
Gura_DeclareMethod(pointer, dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareArg(env, "bytes", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(upper));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints a hexadecimal dump from the content of the `pointer` to the standard output.\n"
		"If the argument `stream` is specified, the result would be output to the stream.\n"
		"\n"
		"If the argument `bytes` is specified, it would limit the size of data to be dumped.\n"
		"Otherwise, all the data pointerd by the target instance is to be dumped.\n"
		"\n"
		"In default, hexadecimal digit are printed with lower-case characters.\n"
		"Specifying an attribute `:upper` would output them with upper-case characters instead.\n"
		"\n"
		"Example:\n"
		"    >>> b'A quick brown fox jumps over the lazy dog.'.p.dump():upper\n"
		"    41 20 71 75 69 63 6B 20 62 72 6F 77 6E 20 66 6F  A quick brown fo\n"
		"    78 20 6A 75 6D 70 73 20 6F 76 65 72 20 74 68 65  x jumps over the\n"
		"    20 6C 61 7A 79 20 64 6F 67 2E                     lazy dog.\n");
}

Gura_ImplementMethod(pointer, dump)
{
	Signal &sig = env.GetSignal();
	Stream *pStream = arg.IsInstanceOf(0, VTYPE_stream)?
								&arg.GetStream(0) : env.GetConsole();
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	size_t bytes = arg.IsValid(1)? arg.GetSizeT(1) : pPointer->GetSize();
	pStream->Dump(sig, pPointer->GetPointerC(), bytes, arg.IsSet(Gura_Symbol(upper)));
	return arg.GetValueThis();
}

// pointer#encodeuri(bytes?:number) {block?}
Gura_DeclareMethod(pointer, encodeuri)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "bytes", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a string in which non-URIC characters are converted to percent-encoded string.\n"
		"\n"
		"For example, `b'\"Hello\"'.p.encodeuri()` would return `'%22Hello%22'`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("str", "string"));
}

Gura_ImplementMethod(pointer, encodeuri)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	const char *p = reinterpret_cast<const char *>(pPointer->GetPointerC());
	size_t bytes = pPointer->GetSize();
	if (arg.IsValid(0) && (bytes = arg.GetSizeT(0)) > pPointer->GetSize()) {
		env.SetError(ERR_OutOfRangeError, "out of range");
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(EncodeURI(p, bytes)));
}

// pointer#forward(distance:number):reduce
Gura_DeclareMethod(pointer, forward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "distance", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Put the pointer offset forward by `distance`.\n"
		"If a negative number is specified for the argument, the offset would be put backward.\n"
		"\n"
		"An error would occur when the pointer's offset becomes a negative value\n"
		"while it would be no error when the offset exceeds the target maximum range.\n"
		"\n"
		"This method returns a reference to the target instance itself.\n");
}

Gura_ImplementMethod(pointer, forward)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	if (!pPointer->Advance(env, arg.GetInt(0))) return Value::Nil;
	return arg.GetValueThis();
}

// pointer#hex(bytes?:number):[upper,cstr,carray] {block?}
Gura_DeclareMethod(pointer, hex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "bytes", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(upper));
	DeclareAttr(Gura_Symbol(cstr));
	DeclareAttr(Gura_Symbol(carray));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts the binary data into a hexadecimal string.\n"
		"\n"
		"In default, the result string is a sequence of joined hexadecimal values without any space.\n"
		"You can specify the following attribute to change the format:\n"
		"\n"
		"- `:cstr` .. Format of C string.\n"
		"- `:carray` .. Format of C array.\n"
		"\n"
		"Alphabet characters are described in lower characters\n"
		"unless the attribute `:upper` is specified.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("str", "string")
		"\n"
		"Example:\n"
		"\n"
		"<table>\n"
		"<tr><th>Code</th><th>Result</th></tr>\n"
		"<tr><td><code>b'\\x01\\x23\\xab\\xcd'.p.hex()</code></td><td><code>'0123abcd'</code></td></tr>\n"
		"<tr><td><code>b'\\x01\\x23\\xab\\xcd'.p.hex():upper</code></td><td><code>'0123ABCD'</code></td></tr>\n"
		"<tr><td><code>b'\\x01\\x23\\xab\\xcd'.p.hex():cstr</code></td><td><code>'\\\\x01\\\\x23\\\\xab\\\\xcd'</code></td></tr>\n"
		"<tr><td><code>b'\\x01\\x23\\xab\\xcd'.p.hex():carray</code></td><td><code>'0x01, 0x23, 0xab, 0xcd'</code></td></tr>\n"
		"</table>\n");
}

Gura_ImplementMethod(pointer, hex)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	String rtn;
	bool upperFlag = arg.IsSet(Gura_Symbol(upper));
	const char *sep = arg.IsSet(Gura_Symbol(carray))? ", " : nullptr;
	const char *format =
		arg.IsSet(Gura_Symbol(cstr))? (upperFlag? "\\x%02X" : "\\x%02x") :
		arg.IsSet(Gura_Symbol(carray))? (upperFlag? "0x%02X" : "0x%02x") :
		(upperFlag? "%02X" : "%02x");
	const UChar *pTop = pPointer->GetPointerC();
	size_t bytes = pPointer->GetSize();
	if (arg.IsValid(0) && (bytes = arg.GetSizeT(0)) > pPointer->GetSize()) {
		env.SetError(ERR_OutOfRangeError, "out of range");
		return Value::Nil;
	}
	for (const UChar *p = pTop; bytes > 0; p++, bytes--) {
		if (sep != nullptr && p != pTop) rtn += sep;
		char buff[32];
		::sprintf(buff, format, *p);
		rtn += buff;
	}
	return ReturnValue(env, arg, Value(rtn));
}

// pointer#pack(format:string, value+):reduce:[stay]
Gura_DeclareMethod(pointer, pack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(stay));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Packs `values` in the argument list according to specifiers in the `format`\n"
		"into a binary and adds it to where the pointer points.\n"
		"The pointer offset is automatically incremented by the added length\n"
		"unless `:stay` attribute is specified.\n"
		"\n"
		"This method returns a reference to the target instance itself.\n"
		"\n"
		"A specifier has a format of \"`nX`\" where `X` is a format character\n"
		"that represents a packing format and `n` is a number of packing size.\n"
		"The number can be omitted, and it would be treated as `1` in that case.\n"
		"\n"
		"Following format characters would take a `number` value from the argument list\n"
		"and pack them into a binary sequence.\n"
		"\n"
		"- `b` .. One-byte signed number.\n"
		"- `B` .. One-byte unsigned number.\n"
		"- `h` .. Two-byte signed number.\n"
		"- `H` .. Two-byte unsigned number.\n"
		"- `i` .. Four-byte signed number.\n"
		"- `I` .. Four-byte unsigned number.\n"
		"- `l` .. Four-byte signed number.\n"
		"- `L` .. Four-byte unsigned number.\n"
		"- `q` .. Eight-byte signed number.\n"
		"- `Q` .. Eight-byte unsigned number.\n"
		"- `f` .. Float-typed number occupying four bytes.\n"
		"- `d` .. Double-typed number occupying eight bytes.\n"
		"\n"
		"As for them, the packing size `n` means the number of values to be packed.\n"
		"\n"
		"Following format characters would take a `string` value from the argument list\n"
		"and pack them into a binary sequence.\n"
		"\n"
		"- `s` .. Packs a sequence of UTF-8 codes in the string.\n"
		"         The packing size `n` means the size of the room in bytes\n"
		"         where the character codes are to be packed.\n"
		"         Only the sequence within the allocated room would be packed.\n"
		"         If the string length is smaller than the room,\n"
		"         the lacking part would be filled with zero.\n"
		"- `c` .. Picks the first byte of the string and packs it as a one-byte unsigned number.\n"
		"         The packing size `n` means the number of values to be packed.\n"
		"\n"
		"Following format character would take no value from the argument list.\n"
		"\n"
		"- `x` .. Fills the binary with zero.\n"
		"         The packing size `n` means the size of the room in bytes\n"
		"         to be filled with zero.\n"
		"\n"
		"The default byte-order for numbers of two-byte, four-byte and eight-byte\n"
		"depends on the system the interpreter is currently running.\n"
		"You can change it by the following specifiers:\n"
		"\n"
		"- `@` .. System-dependent order.\n"
		"- `=` .. System-dependent order.\n"
		"- `<` .. Little endian\n"
		"- `>` .. Big endian\n"
		"- `!` .. Big endian\n"
		"\n"
		"You can specify an asterisk character \"`*`\" for the number of packing size\n"
		"that picks that number from the argument list.\n"
		"\n"
		"You can specify encoding name embraced with \"`{`\" and \"`}`\" in the format\n"
		"to change coding character set from UTF-8\n"
		"while packing a string with format character \"`s`\".\n");
}

Gura_ImplementMethod(pointer, pack)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	if (!pPointer->IsWritable()) {
		env.SetError(ERR_ValueError, "not a writable binary");
		return Value::Nil;
	}
	if (!(arg.IsSet(Gura_Symbol(stay))?
		  pPointer->PackStay(env, arg.GetString(0), arg.GetList(1)) :
		  pPointer->Pack(env, arg.GetString(0), arg.GetList(1)))) return Value::Nil;
	return arg.GetValueThis();
}

// pointer#reader() {block?}
Gura_DeclareMethod(pointer, reader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `stream` instance with which you can read data from the memory\n"
		"pointerd by the pointer."
		"\n"
		GURA_HELPTEXT_BLOCK_en("s", "stream"));
}

Gura_ImplementMethod(pointer, reader)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	Stream *pStream = new Pointer::StreamEx(env, pPointer->Clone());
	return ReturnValue(env, arg, Value(new Object_stream(env, pStream)));
}

// pointer#reset():reduce
Gura_DeclareMethod(pointer, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Moves the pointer position to the beginning.\n"
		"\n"
		"This method returns a reference to the target instance itself.\n");
}

Gura_ImplementMethod(pointer, reset)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	pPointer->Reset();
	return arg.GetValueThis();
}

// pointer#seek(offset:number):reduce
Gura_DeclareMethod(pointer, seek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Moves the pointer position to the specified `offset`.\n"
		"\n"
		"This method returns a reference to the target instance itself.\n");
}

Gura_ImplementMethod(pointer, seek)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	size_t offset = arg.GetSizeT(0);
	pPointer->SetOffset(offset);
	return arg.GetValueThis();
}

// pointer#unpack(format:string, values*:number):[nil,stay] {block?}
Gura_DeclareMethod(pointer, unpack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_number, OCCUR_ZeroOrMore);
	DeclareAttr(Gura_Symbol(nil));
	DeclareAttr(Gura_Symbol(stay));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Extracts values from data sequence pointed by the `pointer` instance according to specifiers in the `format`\n"
		"and returns a list containing the values.\n"
		"\n"
		"A specifier has a format of \"`nX`\" where `X` is a format character\n"
		"that represents a packing format and `n` is a number of packing size.\n"
		"The number can be omitted, and it would be treated as `1` in that case.\n"
		"\n"
		"Following format characters would extract an integer or float value of specified size\n"
		"from the binary and returns a `number` value.\n"
		"\n"
		"- `b` .. One-byte signed number.\n"
		"- `B` .. One-byte unsigned number.\n"
		"- `h` .. Two-byte signed number.\n"
		"- `H` .. Two-byte unsigned number.\n"
		"- `i` .. Four-byte signed number.\n"
		"- `I` .. Four-byte unsigned number.\n"
		"- `l` .. Four-byte signed number.\n"
		"- `L` .. Four-byte unsigned number.\n"
		"- `q` .. Eight-byte signed number.\n"
		"- `Q` .. Eight-byte unsigned number.\n"
		"- `f` .. Float-typed number occupying four bytes.\n"
		"- `d` .. Double-typed number occupying eight bytes.\n"
		"\n"
		"As for them, the packing size `n` means the number of values to be extracted.\n"
		"\n"
		"Following format characters would extract a string sequence from the binary\n"
		"and returns a `string` value.\n"
		"\n"
		"- `s` .. Extracts a sequence of UTF-8 codes and returns `string` instance containing it.\n"
		"         The unpacking size `n` means the size of the room in bytes\n"
		"         where the character codes are to be unpacked.\n"
		"- `c` .. Extracts a one-byte unsigned number and returns a `string` instance containing it.\n"
		"         The unpacking size `n` means the number of values to be extracted.\n"
		"\n"
		"Following format character would not return any value.\n"
		"\n"
		"- `x` .. Advances the address by one byte.\n"
		"         If the unpacking size `n` is specifies,\n"
		"         it would advance the address by `n` bytes.\n"
		"\n"
		"The default byte-order for numbers of two-byte, four-byte and eight-byte\n"
		"depends on the system the interpreter is currently running.\n"
		"You can change it by the following specifiers:\n"
		"\n"
		"- `@` .. System-dependent order.\n"
		"- `=` .. System-dependent order.\n"
		"- `<` .. Little endian\n"
		"- `>` .. Big endian\n"
		"- `!` .. Big endian\n"
		"\n"
		"You can specify an asterisk character \"`*`\" for the number of unpacking size\n"
		"that picks that number from the argument list.\n"
		"\n"
		"You can specify encoding name embraced with \"`{`\" and \"`}`\" in the format\n"
		"to change coding character set from UTF-8\n"
		"while extracting a string with format character \"`s`\".\n"
		"\n"
		"An error occurs if the binary size is smaller than the format reqeusts.\n"
		"If the attribute `:nil` is specified, `nil` value would be returned for such a case.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("list", "list"));
}

Gura_ImplementMethod(pointer, unpack)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	bool exceedErrorFlag = !arg.IsSet(Gura_Symbol(nil));
	Value value = arg.IsSet(Gura_Symbol(stay))?
		pPointer->UnpackStay(env, arg.GetString(0), arg.GetList(1), exceedErrorFlag) :
		pPointer->Unpack(env, arg.GetString(0), arg.GetList(1), exceedErrorFlag);
	return ReturnValue(env, arg, value);
}

// pointer#unpacks(format:string, values*:number):map {block?}
Gura_DeclareMethod(pointer, unpacks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_number, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an iterator that extracts values from data pointed by the `pointer` instance\n"
		"according to specifiers in `format`.\n"
		"\n"
		"For detailed information about specifiers, see the help of `pointer#unpack()`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("iter", "iterator"));
}

Gura_ImplementMethod(pointer, unpacks)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	AutoPtr<Iterator> pIterator(new Pointer::IteratorUnpack(
									pPointer->Clone(), arg.GetString(0), arg.GetList(1)));
	return ReturnIterator(env, arg, pIterator.release());
}

// pointer#writer() {block?}
Gura_DeclareMethod(pointer, writer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `stream` instance with which you can append data to the memory\n"
		"pointed by the pointer."
		"\n"
		GURA_HELPTEXT_BLOCK_en("s", "stream"));
}

Gura_ImplementMethod(pointer, writer)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	Stream *pStream = new Pointer::StreamEx(env, pPointer->Clone());
	return ReturnValue(env, arg, Value(new Object_stream(env, pStream)));
}

#define ImplementAccessorMethod(type, Type) \
Gura_DeclareMethodAlias(pointer, each_##type, "each@" #type) \
{ \
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None); \
	DeclareAttr(Gura_Symbol(be)); \
	DeclareBlock(OCCUR_ZeroOrOnce); \
	AddHelp( \
		Gura_Symbol(en), Help::FMT_markdown, \
		"Creates an iterator that extracts numbers in size of " #type " from the current pointer position.\n" \
		"\n" \
		"In default, it assumes the byte seqeuces are ordered in little-endian.\n" \
		"You can specify `:be` attribute to extract them in big-endian order.\n" \
		"\n" \
		GURA_HELPTEXT_ITERATOR_en()); \
} \
Gura_ImplementMethod(pointer, each_##type) \
{ \
	bool bigEndianFlag = arg.IsSet(Gura_Symbol(be)); \
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer(); \
	AutoPtr<Iterator> pIterator(new Pointer::IteratorEach<Type>(pPointer->Reference(), bigEndianFlag)); \
	return ReturnIterator(env, arg, pIterator.release()); \
} \
Gura_DeclareMethodAlias(pointer, get_##type, "get@" #type) \
{ \
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None); \
	DeclareAttr(Gura_Symbol(be)); \
	DeclareAttr(Gura_Symbol(nil)); \
	DeclareAttr(Gura_Symbol(stay)); \
	DeclareBlock(OCCUR_ZeroOrOnce); \
	AddHelp( \
		Gura_Symbol(en), Help::FMT_markdown, \
		"Returns an extracted number in size of " #type " from the current pointer position.\n" \
		"\n" \
		"In default, it assumes the byte seqeuces are ordered in little-endian.\n" \
		"You can specify `:be` attribute to extract them in big-endian order.\n" \
		"\n" \
		GURA_HELPTEXT_BLOCK_en("n", "number")); \
} \
Gura_ImplementMethod(pointer, get_##type) \
{ \
	bool exceedErrorFlag = !arg.IsSet(Gura_Symbol(nil)); \
	bool bigEndianFlag = arg.IsSet(Gura_Symbol(be)); \
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer(); \
	Type num; \
	if (!(arg.IsSet(Gura_Symbol(stay))? \
		  pPointer->GetStay<Type>(env, &num, bigEndianFlag, exceedErrorFlag) : \
		  pPointer->Get<Type>(env, &num, bigEndianFlag, exceedErrorFlag))) return Value::Nil; \
	return ReturnValue(env, arg, Value(num)); \
} \
Gura_DeclareMethodAlias(pointer, put_##type, "put@" #type) \
{ \
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map); \
	DeclareArg(env, "n", VTYPE_number); \
	DeclareAttr(Gura_Symbol(be)); \
	DeclareAttr(Gura_Symbol(stay)); \
	AddHelp( \
		Gura_Symbol(en), Help::FMT_markdown, \
		"Stores the specified number to the current pointer position in size of " #type ".\n" \
		"\n" \
		"In default, it stores the byte sequences in the order of little-endian.\n" \
		"You can specify `:be` sttribute to store them in big-endian order.\n" \
		"\n" \
		"This method returns a reference to the target instance itself.\n"); \
} \
Gura_ImplementMethod(pointer, put_##type) \
{ \
	bool bigEndianFlag = arg.IsSet(Gura_Symbol(be)); \
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer(); \
	if (!(arg.IsSet(Gura_Symbol(stay))? \
		  pPointer->PutStay<Type>(env, arg.Get##Type(0), bigEndianFlag) : \
		  pPointer->Put<Type>(env, arg.Get##Type(0), bigEndianFlag))) return Value::Nil; \
	return arg.GetValueThis(); \
} \

ImplementAccessorMethod(char, Char)
ImplementAccessorMethod(uchar, UChar)
ImplementAccessorMethod(short, Short)
ImplementAccessorMethod(ushort, UShort)
ImplementAccessorMethod(int32, Int32)
ImplementAccessorMethod(uint32, UInt32)
ImplementAccessorMethod(int64, Int64)
ImplementAccessorMethod(uint64, UInt64)
ImplementAccessorMethod(float, Float)
ImplementAccessorMethod(double, Double)

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_pointer::Class_pointer(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_pointer)
{
}

void Class_pointer::Prepare(Environment &env)
{
	Gura_AssignFunction(pointer);
	Gura_AssignMethod(pointer, copyfrom);
	Gura_AssignMethod(pointer, copyto);
	Gura_AssignMethod(pointer, decode);
	Gura_AssignMethod(pointer, dump);
	Gura_AssignMethod(pointer, encodeuri);
	Gura_AssignMethod(pointer, each_char);
	Gura_AssignMethod(pointer, each_uchar);
	Gura_AssignMethod(pointer, each_short);
	Gura_AssignMethod(pointer, each_ushort);
	Gura_AssignMethod(pointer, each_int32);
	Gura_AssignMethod(pointer, each_uint32);
	Gura_AssignMethod(pointer, each_int64);
	Gura_AssignMethod(pointer, each_uint64);
	Gura_AssignMethod(pointer, each_float);
	Gura_AssignMethod(pointer, each_double);
	Gura_AssignMethod(pointer, forward);
	Gura_AssignMethod(pointer, get_char);
	Gura_AssignMethod(pointer, get_uchar);
	Gura_AssignMethod(pointer, get_short);
	Gura_AssignMethod(pointer, get_ushort);
	Gura_AssignMethod(pointer, get_int32);
	Gura_AssignMethod(pointer, get_uint32);
	Gura_AssignMethod(pointer, get_int64);
	Gura_AssignMethod(pointer, get_uint64);
	Gura_AssignMethod(pointer, get_float);
	Gura_AssignMethod(pointer, get_double);
	Gura_AssignMethod(pointer, hex);
	Gura_AssignMethod(pointer, pack);
	Gura_AssignMethod(pointer, put_char);
	Gura_AssignMethod(pointer, put_uchar);
	Gura_AssignMethod(pointer, put_short);
	Gura_AssignMethod(pointer, put_ushort);
	Gura_AssignMethod(pointer, put_int32);
	Gura_AssignMethod(pointer, put_uint32);
	Gura_AssignMethod(pointer, put_int64);
	Gura_AssignMethod(pointer, put_uint64);
	Gura_AssignMethod(pointer, put_float);
	Gura_AssignMethod(pointer, put_double);
	Gura_AssignMethod(pointer, reader);
	Gura_AssignMethod(pointer, reset);
	Gura_AssignMethod(pointer, seek);
	Gura_AssignMethod(pointer, unpack);
	Gura_AssignMethod(pointer, unpacks);
	Gura_AssignMethod(pointer, writer);
}

bool Class_pointer::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	if (value.Is_binary()) {
		Object_binary *pObj = Object_binary::GetObject(value);
		Pointer *pPointer = new Object_binary::PointerEx(0, pObj->Reference());
		value = Value(new Object_pointer(env, pPointer));
		return true;
	} else if (value.Is_memory()) {
		Object_memory *pObj = Object_memory::GetObject(value);
		Pointer *pPointer = new Object_memory::PointerEx(0, pObj->Reference());
		value = Value(new Object_pointer(env, pPointer));
		return true;
	}
	return false;
}

Object *Class_pointer::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
