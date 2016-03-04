// -*- coding: utf-8 -*-
//=============================================================================
// Gura class: binary
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_binary
//-----------------------------------------------------------------------------
Object_binary::Object_binary(const Object_binary &obj) :
		Object(obj), _binary(obj._binary), _writableFlag(obj._writableFlag)
{
}

Object_binary::~Object_binary()
{
}

Object *Object_binary::Clone() const
{
	return new Object_binary(*this);
}

bool Object_binary::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(size));
	symbols.insert(Gura_Symbol(writable));
	return true;
}

Value Object_binary::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(size))) {
		return Value(GetBinary().size());
	} else if (pSymbol->IsIdentical(Gura_Symbol(writable))) {
		return Value(_writableFlag);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_binary::IndexGet(Environment &env, const Value &valueIdx)
{
	if (!valueIdx.Is_number()) {
		env.SetError(ERR_IndexError, "index must be a number for binary");
		return Value::Nil;
	}
	int idx = valueIdx.GetInt();
	int len = static_cast<int>(_binary.size());
	if (idx >= 0) {
		if (idx >= len) {
			env.SetError(ERR_IndexError, "index is out of range");
			return Value::Nil;
		}
		return Value(static_cast<UChar>(_binary[idx]));
	} else {
		if (-idx > len) {
			env.SetError(ERR_IndexError, "index is out of range");
			return Value::Nil;
		}
		return Value(static_cast<UChar>(_binary[len + idx]));
	}
}

void Object_binary::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	if (!IsWritable()) {
		env.SetError(ERR_ValueError, "not a writable binary");
		return;
	}
	if (!valueIdx.Is_number()) {
		env.SetError(ERR_IndexError, "index must be a number for binary");
		return;
	}
	if (!value.Is_number()) {
		env.SetError(ERR_IndexError, "value must be a number for binary");
		return;
	}
	int idx = valueIdx.GetInt();
	long data = value.GetLong();
	if (data < 0 || data > 255) {
		env.SetError(ERR_IndexError, "value must be between 0 and 255");
		return;
	}
	int len = static_cast<int>(_binary.size());
	if (idx >= 0) {
		if (idx >= len) {
			env.SetError(ERR_IndexError, "index is out of range");
			return;
		}
		_binary[idx] = static_cast<UChar>(data);
	} else {
		if (-idx > len) {
			env.SetError(ERR_IndexError, "index is out of range");
			return;
		}
		_binary[len + idx] = static_cast<UChar>(data);
	}
}

Iterator *Object_binary::CreateIterator(Signal &sig)
{
	return new IteratorByte(Object_binary::Reference(this), -1);
}

String Object_binary::ToString(bool exprFlag)
{
	String str;
	char buff[64];
	::sprintf(buff, "<binary:%s:%dbyte",
				IsWritable()? "RW" : "R", static_cast<int>(_binary.size()));
	str += buff;
	if (!_binary.empty() && _binary.size() < 32) {
		str += ":'";
		foreach (Binary, p, _binary) {
			char ch = *p;
			if (ch == '\'' || ch == '\\') {
				str += '\\';
				str += ch;
			} else if (0x20 < ch && ch < 0x7f) {
				str += ch;
			} else {
				::sprintf(buff, "\\x%02x", static_cast<UChar>(ch));
				str += buff;
			}
		}
		str += "'";
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Object_binary::IteratorByte
//-----------------------------------------------------------------------------
Object_binary::IteratorByte::IteratorByte(Object_binary *pObj, int cntMax) :
			Iterator(false), _pObj(pObj), _cnt(cntMax), _offset(0)
{
}

Iterator *Object_binary::IteratorByte::GetSource()
{
	return nullptr;
}

bool Object_binary::IteratorByte::DoNext(Environment &env, Value &value)
{
	const Binary &binary = _pObj->GetBinary();
	if (_offset >= binary.size() || _cnt == 0) return false;
	if (_cnt > 0) _cnt--;
	value = Value(static_cast<UChar>(binary[_offset]));
	_offset++;
	return true;
}

String Object_binary::IteratorByte::ToString() const
{
	return String("binary#byte");
}

void Object_binary::IteratorByte::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_binary::PointerEx
//-----------------------------------------------------------------------------
Object_binary::PointerEx::PointerEx(size_t offset, Object_binary *pObjBinary) :
	Pointer(offset), _pObjBinary(pObjBinary)
{
}

Object_binary::PointerEx::PointerEx(const PointerEx &ptr) :
	Pointer(ptr.GetOffset()), _pObjBinary(dynamic_cast<Object_binary *>(ptr._pObjBinary->Reference()))
{
}

bool Object_binary::PointerEx::PackPrepare(Environment &env, size_t bytes)
{
	if (!_pObjBinary->IsWritable()) {
		env.SetError(ERR_ValueError, "not a writable binary");
		return false;
	}
	return true;
}

void Object_binary::PointerEx::PackBuffer(const void *buff, size_t bytes)
{
	size_t offsetNext = _offset + bytes;
	if (buff != nullptr) {
		Binary &binary = _pObjBinary->GetBinary();
		const UChar *buffp = reinterpret_cast<const UChar *>(buff);
		if (_offset < binary.size()) {
			size_t bytesToCopy = ChooseMin(binary.size() - _offset, bytes);
			std::copy(buffp, buffp + bytesToCopy, binary.begin() + _offset);
			buffp += bytesToCopy;
			bytes -= bytesToCopy;
		} else if (_offset > binary.size()) {
			binary.append(_offset - binary.size(), '\0');
		}
		binary.append(buffp, buffp + bytes);
	}
	_offset = offsetNext;
}

const UChar *Object_binary::PointerEx::UnpackPrepare(
	Environment &env, size_t bytes, bool exceedErrorFlag)
{
	Binary &binary = _pObjBinary->GetBinary();
	if (_offset + bytes <= binary.size()) {
		const UChar *p = reinterpret_cast<const UChar *>(binary.data() + _offset);
		_offset += bytes;
		return p;
	}
	if (exceedErrorFlag) {
		env.SetError(ERR_IndexError, "pointer exceeds the range of binary");
	}
	return nullptr;
}

Pointer *Object_binary::PointerEx::Clone() const
{
	return new PointerEx(*this);
}

Object *Object_binary::PointerEx::GetTarget() const
{
	return _pObjBinary.get();
}

const UChar *Object_binary::PointerEx::GetPointerC() const
{
	return reinterpret_cast<const UChar *>(_pObjBinary->GetBinary().data() + _offset);
}

size_t Object_binary::PointerEx::GetEntireSize() const
{
	return _pObjBinary->GetBinary().size();
}

bool Object_binary::PointerEx::IsWritable() const
{
	return _pObjBinary->IsWritable();
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// binary(buff*) {block?}
Gura_DeclareFunction(binary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "buff", VTYPE_any, OCCUR_ZeroOrMore);
	SetClassToConstruct(env.LookupClass(VTYPE_binary));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `binary` instance after combining `string` or `binary` specified by the arguments `buff`.\n"
		"If no argument is specified for `buff`, an empty `binary` instance would be created.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("bin", "binary"));
}

Gura_ImplementFunction(binary)
{
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	Binary &binary = pObjBinary->GetBinary();
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		if (pValue->Is_string()) {
			binary += pValue->GetString();
		} else if (pValue->Is_binary()) {
			binary += pValue->GetBinary();
		} else {
			env.SetError(ERR_ValueError, "string or binary is expected");
			return Value::Nil;
		}
	}
	return ReturnValue(env, arg, Value(pObjBinary.release()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// binary#add(buff+:binary):map:reduce
Gura_DeclareMethod(binary, add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "buff", VTYPE_binary, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Adds binary data to the `binary` instance.\n"
		"You can specify one or more binary data to be stored.\n");
}

Gura_ImplementMethod(binary, add)
{
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	if (!pThis->IsWritable()) {
		env.SetError(ERR_ValueError, "not a writable binary");
		return Value::Nil;
	}
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		pThis->GetBinary() += pValue->GetBinary();
	}
	return arg.GetValueThis();
}

// binary.alloc(bytes:number, data?:number):map {block?}
Gura_DeclareClassMethod(binary, alloc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bytes", VTYPE_number);
	DeclareArg(env, "data", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `binary` instance that has the specified size of buffer.\n"
		"If the argument `data`, which should have a number between 0 and 255, is specified,\n"
		"the buffer would be initialized with the value.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("bin", "binary"));
}

Gura_ImplementClassMethod(binary, alloc)
{
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	Binary &buff = pObjBinary->GetBinary();
	size_t bytes = arg.GetSizeT(0);
	UChar data = arg.IsValid(1)? arg.GetUChar(1) : 0;
	buff.reserve(bytes);
	buff.insert(0, bytes, static_cast<char>(data));
	return ReturnValue(env, arg, Value(pObjBinary.release()));
}

// binary#decode(codec:codec)
Gura_DeclareMethod(binary, decode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "codec", VTYPE_codec);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Decodes the content of the `binary` as a sequence of string characters using `codec`\n"
		"and returns the result in `string`.");
}

Gura_ImplementMethod(binary, decode)
{
	Signal &sig = env.GetSignal();
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	Codec *pCodec = Object_codec::GetObject(arg, 0)->GetCodec();
	String str;
	if (!pCodec->GetDecoder()->Decode(sig, str, pThis->GetBinary())) {
		return Value::Nil;
	}
	return Value(str);
}

// binary#dump(stream?:stream:w):void:[upper]
Gura_DeclareMethod(binary, dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareAttr(Gura_Symbol(upper));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints a hexadecimal dump from the content of the `binary` to the standard output.\n"
		"If the argument `stream` is specified, the result would be output to the stream.\n"
		"\n"
		"In default, hexadecimal digit are printed with lower-case characters.\n"
		"Specifying an attribute `:upper` would output them with upper-case characters instead.\n"
		"\n"
		"Example:\n"
		"    >>> b'A quick brown fox jumps over the lazy dog.'.dump():upper\n"
		"    41 20 71 75 69 63 6B 20 62 72 6F 77 6E 20 66 6F  A quick brown fo\n"
		"    78 20 6A 75 6D 70 73 20 6F 76 65 72 20 74 68 65  x jumps over the\n"
		"    20 6C 61 7A 79 20 64 6F 67 2E                     lazy dog.\n");
}

Gura_ImplementMethod(binary, dump)
{
	Signal &sig = env.GetSignal();
	Stream *pStream = arg.IsInstanceOf(0, VTYPE_stream)?
								&arg.GetStream(0) : env.GetConsole();
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	const Binary &buff = pThis->GetBinary();
	pStream->Dump(sig, buff.data(), buff.size(), arg.IsSet(Gura_Symbol(upper)));
	return Value::Nil;
}

// binary#each() {block?}
Gura_DeclareMethod(binary, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that returns each byte in the buffer.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(binary, each)
{
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	Object_binary *pObj = Object_binary::Reference(pThis);
	Iterator *pIterator = new Object_binary::IteratorByte(pObj, -1);
	return ReturnIterator(env, arg, pIterator);
}

// binary#encodeuri()
Gura_DeclareMethod(binary, encodeuri)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a string in which non-URIC characters are converted to percent-encoded string.\n"
		"\n"
		"For example, `b'\"Hello\"'.encodeuri()` would return `'%22Hello%22'`.\n");
}

Gura_ImplementMethod(binary, encodeuri)
{
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	const Binary &binary = pThis->GetBinary();
	return Value(EncodeURI(binary.data(), binary.size()));
}

// binary#hex():[upper,cstr,carray]
Gura_DeclareMethod(binary, hex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(upper));
	DeclareAttr(Gura_Symbol(cstr));
	DeclareAttr(Gura_Symbol(carray));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Converts the binary into a hexadecimal string.\n"
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
		"Example:\n"
		"\n"
		"<table>\n"
		"<tr><th>Code</th><th>Result</th></tr>\n"
		"<tr><td><code>b'\\x01\\x23\\xab\\xcd'.hex()</code></td><td><code>'0123abcd'</code></td></tr>\n"
		"<tr><td><code>b'\\x01\\x23\\xab\\xcd'.hex():upper</code></td><td><code>'0123ABCD'</code></td></tr>\n"
		"<tr><td><code>b'\\x01\\x23\\xab\\xcd'.hex():cstr</code></td><td><code>'\\\\x01\\\\x23\\\\xab\\\\xcd'</code></td></tr>\n"
		"<tr><td><code>b'\\x01\\x23\\xab\\xcd'.hex():carray</code></td><td><code>'0x01, 0x23, 0xab, 0xcd'</code></td></tr>\n"
		"</table>\n");
}

Gura_ImplementMethod(binary, hex)
{
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	String rtn;
	bool upperFlag = arg.IsSet(Gura_Symbol(upper));
	const char *sep = arg.IsSet(Gura_Symbol(carray))? ", " : nullptr;
	const char *format =
		arg.IsSet(Gura_Symbol(cstr))? (upperFlag? "\\x%02X" : "\\x%02x") :
		arg.IsSet(Gura_Symbol(carray))? (upperFlag? "0x%02X" : "0x%02x") :
		(upperFlag? "%02X" : "%02x");
	const Binary &buff = pThis->GetBinary();
	foreach_const (Binary, p, buff) {
		UChar ch = static_cast<UChar>(*p);
		if (sep != nullptr && p != buff.begin()) rtn += sep;
		char buff[32];
		::sprintf(buff, format, ch);
		rtn += buff;
	}
	return Value(rtn);
}

// binary#pointer(offset?:number) {block?}
Gura_DeclareMethod(binary, pointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a `pointer` instance that has an initial offset specified\n"
		"by the argument `offset`. If the argument is omitted, it would return a `pointer`\n"
		"instance that points to the top of the binary.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("p", "pointer"));
}

Gura_ImplementMethod(binary, pointer)
{
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	size_t offset = arg.Is_number(0)? arg.GetSizeT(0) : 0;
	Pointer *pPointer = new Object_binary::PointerEx(offset, pThis->Reference());
	return ReturnValue(env, arg, Value(new Object_pointer(env, pPointer)));
}

// binary#reader() {block?}
Gura_DeclareMethod(binary, reader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `stream` instance with which you can read data from the binary by `stream#read()` method."
		"\n"
		GURA_HELPTEXT_BLOCK_en("s", "stream"));
}

Gura_ImplementMethod(binary, reader)
{
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	Stream *pStream = new Stream_Binary(env, Object_binary::Reference(pThis), false);
	return ReturnValue(env, arg, Value(new Object_stream(env, pStream)));
}

// binary#store(offset:number, buff+:binary):map:reduce
Gura_DeclareMethod(binary, store)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "buff", VTYPE_binary, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Stores binary data `buff` in the target `binary` instance at the specified offset.\n"
		"You can specify one or more binary data to be stored.\n"
		"\n"
		"This method returns the target instance itself.\n");
}

Gura_ImplementMethod(binary, store)
{
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	if (!pThis->IsWritable()) {
		env.SetError(ERR_ValueError, "not a writable binary");
		return Value::Nil;
	}
	size_t offset = arg.GetSizeT(0);
	Binary &binary = pThis->GetBinary();
	if (offset > binary.size()) {
		binary.append(offset - binary.size(), '\0');
	}
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		size_t sizeEach = pValue->GetBinary().size();
		if (offset >= binary.size()) {
			binary += pValue->GetBinary();
		} else {
			binary.replace(offset, sizeEach, pValue->GetBinary());
		}
		offset += sizeEach;
	}
	return arg.GetValueThis();
}

// binary#writer() {block?}
Gura_DeclareMethod(binary, writer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `stream` instance with which you can append data to the binary by `stream#write()` method."
		"\n"
		GURA_HELPTEXT_BLOCK_en("s", "stream"));
}

Gura_ImplementMethod(binary, writer)
{
	Object_binary *pThis = Object_binary::GetObjectThis(arg);
	Stream *pStream = new Stream_Binary(env, Object_binary::Reference(pThis), true);
	return ReturnValue(env, arg, Value(new Object_stream(env, pStream)));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_binary::Class_binary(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_binary)
{
}

void Class_binary::Prepare(Environment &env)
{
	Gura_AssignFunction(binary);
	Gura_AssignMethod(binary, add);
	Gura_AssignMethod(binary, alloc);
	Gura_AssignMethod(binary, decode);
	Gura_AssignMethod(binary, dump);
	Gura_AssignMethod(binary, each);
	Gura_AssignMethod(binary, encodeuri);
	Gura_AssignMethod(binary, hex);
	Gura_AssignMethod(binary, pointer);
	Gura_AssignMethod(binary, reader);
	Gura_AssignMethod(binary, store);
	Gura_AssignMethod(binary, writer);
}

bool Class_binary::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	if (value.Is_string()) {
		Object_binary *pObjBinary = new Object_binary(env, value.GetStringSTL(), true);
		value = Value(pObjBinary);
		return true;
	}
	return false;
}

bool Class_binary::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return false;
}

bool Class_binary::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	return false;
}

Object *Class_binary::CreateDescendant(Environment &env, Class *pClass)
{
	return new Object_binary((pClass == nullptr)? this : pClass);
}

//-----------------------------------------------------------------------------
// Stream_Binary
//-----------------------------------------------------------------------------
Stream_Binary::Stream_Binary(Environment &env, Object_binary *pObjBinary, bool seekEndFlag) :
	Stream(env, ATTR_BwdSeekable | ATTR_Readable | (pObjBinary->IsWritable()? ATTR_Writable : 0)),
	_pObjBinary(pObjBinary), _offset(seekEndFlag? pObjBinary->GetBinary().size() : 0)
{
}

Stream_Binary::~Stream_Binary()
{
}

const char *Stream_Binary::GetName() const
{
	return "binary";
}

const char *Stream_Binary::GetIdentifier() const
{
	return nullptr;
}

size_t Stream_Binary::DoRead(Signal &sig, void *buff, size_t len)
{
	const Binary &binary = GetBinary();
	if (_offset > binary.size()) {
		sig.SetError(ERR_IndexError, "out of range");
		return 0;
	}
	len = ChooseMin(binary.size() - _offset, len);
	::memcpy(buff, binary.data() + _offset, len);
	_offset += len;
	return len;
}

size_t Stream_Binary::DoWrite(Signal &sig, const void *buff, size_t len)
{
	Binary &binary = GetBinary();
	const char *buffp = reinterpret_cast<const char *>(buff);
	if (_offset < binary.size()) {
		size_t lenReplace = ChooseMin(binary.size() - _offset, len);
		binary.replace(binary.begin() + _offset, binary.begin() + _offset + lenReplace,
													buffp, len);
	} else {
		if (_offset > binary.size()) {
			binary.append(_offset - binary.size(), 0);
		}
		binary.append(buffp, len);
	}
	_offset += len;
	return len;
}

bool Stream_Binary::DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	if (seekMode == SeekSet) {
		_offset = static_cast<size_t>(offset);
	} else if (seekMode == SeekCur) {
		_offset += offset;
	}
	return true;
}

bool Stream_Binary::DoFlush(Signal &sig)
{
	return true;
}

bool Stream_Binary::DoClose(Signal &sig)
{
	return Stream::DoClose(sig);
}

size_t Stream_Binary::DoGetSize()
{
	return GetBinary().size();
}

}
