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

bool Object_binary::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(writable));
	return true;
}

Value Object_binary::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(writable))) {
		evaluatedFlag = true;
		return Value(_writableFlag);
	}
	return Value::Null;
}

Value Object_binary::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number for binary");
		return Value::Null;
	}
	int idx = valueIdx.GetInt();
	int len = static_cast<int>(_binary.size());
	if (idx >= 0) {
		if (idx >= len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return Value::Null;
		}
		return Value(static_cast<UChar>(_binary[idx]));
	} else {
		if (-idx > len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return Value::Null;
		}
		return Value(static_cast<UChar>(_binary[len + idx]));
	}
}

void Object_binary::IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value)
{
	if (!IsWritable()) {
		sig.SetError(ERR_ValueError, "not a writable binary");
		return;
	}
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number for binary");
		return;
	}
	if (!value.Is_number()) {
		sig.SetError(ERR_IndexError, "value must be a number for binary");
		return;
	}
	int idx = valueIdx.GetInt();
	long data = value.GetLong();
	if (data < 0 || data > 255) {
		sig.SetError(ERR_IndexError, "value must be between 0 and 255");
		return;
	}
	int len = static_cast<int>(_binary.size());
	if (idx >= 0) {
		if (idx >= len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return;
		}
		_binary[idx] = static_cast<UChar>(data);
	} else {
		if (-idx > len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return;
		}
		_binary[len + idx] = static_cast<UChar>(data);
	}
}

Iterator *Object_binary::CreateIterator(Signal sig)
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
			Iterator(false), _pObj(pObj), _cnt(cntMax), _cntMax(cntMax),
			_offset(0)
{
}

Iterator *Object_binary::IteratorByte::GetSource()
{
	return NULL;
}

bool Object_binary::IteratorByte::DoNext(Environment &env, Signal sig, Value &value)
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
// Object_binary::IteratorUnpack
//-----------------------------------------------------------------------------
Object_binary::IteratorUnpack::IteratorUnpack(Object_binary *pObj,
				const char *format, const ValueList &valListArg, size_t offset) :
		Iterator(false), _pObj(pObj), _format(format), _valListArg(valListArg),
		_offset(offset), _offsetInit(offset)
{
}

Iterator *Object_binary::IteratorUnpack::GetSource()
{
	return NULL;
}

bool Object_binary::IteratorUnpack::DoNext(Environment &env, Signal sig, Value &value)
{
	value = _pObj->GetBinary().Unpack(env, sig, _offset, _format.c_str(), _valListArg, false);
	return value.IsValid();
}

String Object_binary::IteratorUnpack::ToString() const
{
	return String("binary#unpacks");
}

void Object_binary::IteratorUnpack::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// binary(buff*) {block?}
Gura_DeclareFunction(binary)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "buff", VTYPE_any, OCCUR_ZeroOrMore);
	SetClassToConstruct(env.LookupClass(VTYPE_binary));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(binary)
{
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	Binary &binary = pObjBinary->GetBinary();
	foreach_const (ValueList, pValue, args.GetList(0)) {
		if (pValue->Is_string()) {
			binary += pValue->GetString();
		} else if (pValue->Is_binary()) {
			binary += pValue->GetBinary();
		} else {
			sig.SetError(ERR_ValueError, "string or binary is expected");
			return Value::Null;
		}
	}
	return ReturnValue(env, sig, args, Value(pObjBinary.release()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// binary#add(buff+:binary):map:reduce
Gura_DeclareMethod(binary, add)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "buff", VTYPE_binary, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(binary, add)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	if (!pThis->IsWritable()) {
		sig.SetError(ERR_ValueError, "not a writable binary");
		return Value::Null;
	}
	foreach_const (ValueList, pValue, args.GetList(0)) {
		pThis->GetBinary() += pValue->GetBinary();
	}
	return args.GetThis();
}

// binary.alloc(bytes:number, data?:number):map {block?}
Gura_DeclareClassMethod(binary, alloc)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bytes", VTYPE_number);
	DeclareArg(env, "data", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(binary, alloc)
{
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	Binary &buff = pObjBinary->GetBinary();
	size_t bytes = args.GetSizeT(0);
	UChar data = args.IsValid(1)? args.GetUChar(1) : 0;
	buff.reserve(bytes);
	buff.insert(0, bytes, static_cast<char>(data));
	return ReturnValue(env, sig, args, Value(pObjBinary.release()));
}

// binary#decode(codec:codec)
Gura_DeclareMethodPrimitive(binary, decode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "codec", VTYPE_codec);
}

Gura_ImplementMethod(binary, decode)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	Codec *pCodec = Object_codec::GetObject(args, 0)->GetCodec();
	String str;
	if (!pCodec->GetDecoder()->Decode(sig, str, pThis->GetBinary())) {
		return Value::Null;
	}
	return Value(str);
}

// binary#dump(stream?:stream:w):void:[upper]
Gura_DeclareMethod(binary, dump)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareAttr(Gura_Symbol(upper));
}

Gura_ImplementMethod(binary, dump)
{
	Stream *pStream = args.IsInstanceOf(0, VTYPE_stream)?
								&args.GetStream(0) : env.GetConsole();
	Object_binary *pThis = Object_binary::GetThisObj(args);
	const Binary &buff = pThis->GetBinary();
	pStream->Dump(sig, buff.data(), buff.size(), args.IsSet(Gura_Symbol(upper)));
	return Value::Null;
}

// binary#each() {block?}
Gura_DeclareMethod(binary, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an iterator picking up each byte in the buffer");
}

Gura_ImplementMethod(binary, each)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	Object_binary *pObj = Object_binary::Reference(pThis);
	Iterator *pIterator = new Object_binary::IteratorByte(pObj, -1);
	return ReturnIterator(env, sig, args, pIterator);
}

// binary#encodeuri()
Gura_DeclareMethod(binary, encodeuri)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string in which non-URIC characters are percent-encoded.");
}

Gura_ImplementMethod(binary, encodeuri)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	const Binary &binary = pThis->GetBinary();
	return Value(EncodeURI(binary.data(), binary.size()));
}

// binary#hex():[upper,cstr,carray]
Gura_DeclareMethod(binary, hex)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(upper));
	DeclareAttr(Gura_Symbol(cstr));
	DeclareAttr(Gura_Symbol(carray));
}

Gura_ImplementMethod(binary, hex)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	String rtn;
	bool upperFlag = args.IsSet(Gura_Symbol(upper));
	const char *sep = args.IsSet(Gura_Symbol(carray))? ", " : NULL;
	const char *format =
		args.IsSet(Gura_Symbol(cstr))? (upperFlag? "\\x%02X" : "\\x%02x") :
		args.IsSet(Gura_Symbol(carray))? (upperFlag? "0x%02X" : "0x%02x") :
		(upperFlag? "%02X" : "%02x");
	const Binary &buff = pThis->GetBinary();
	foreach_const (Binary, p, buff) {
		UChar ch = static_cast<UChar>(*p);
		if (sep != NULL && p != buff.begin()) rtn += sep;
		char buff[32];
		::sprintf(buff, format, ch);
		rtn += buff;
	}
	return Value(rtn);
}

// binary#len()
Gura_DeclareMethod(binary, len)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns the length of the buffer in binary.");
}

Gura_ImplementMethod(binary, len)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	return Value(static_cast<UInt>(pThis->GetBinary().size()));
}

// binary.pack(format:string, value*):map {block?}
Gura_DeclareClassMethod(binary, pack)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(binary, pack)
{
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	size_t offset = 0;
	pObjBinary->GetBinary().Pack(env, sig, offset, args.GetString(0), args.GetList(1));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjBinary.release()));
}

// binary#pointer(offset:number => 0) {block?}
Gura_DeclareMethod(binary, pointer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns a pointer instance that has an initial offset specified\n"
	"by the argument.");
}

Gura_ImplementMethod(binary, pointer)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	Object_binary *pObjBinary = Object_binary::Reference(pThis);
	size_t offset = args.GetSizeT(0);
	return ReturnValue(env, sig, args, Value(new Object_pointer(env, pObjBinary, offset)));
}

// binary#reader() {block?}
Gura_DeclareMethod(binary, reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(binary, reader)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	Stream *pStream = new Stream_Binary(env, sig, Object_binary::Reference(pThis), false);
	return ReturnValue(env, sig, args, Value(new Object_stream(env, pStream)));
}

// binary#store(offset:number, buff+:binary):map:reduce
Gura_DeclareMethod(binary, store)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "buff", VTYPE_binary, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(binary, store)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	if (!pThis->IsWritable()) {
		sig.SetError(ERR_ValueError, "not a writable binary");
		return Value::Null;
	}
	size_t offset = args.GetSizeT(0);
	Binary &binary = pThis->GetBinary();
	if (offset > binary.size()) {
		binary.append(offset - binary.size(), '\0');
	}
	foreach_const (ValueList, pValue, args.GetList(1)) {
		size_t sizeEach = pValue->GetBinary().size();
		if (offset >= binary.size()) {
			binary += pValue->GetBinary();
		} else {
			binary.replace(offset, sizeEach, pValue->GetBinary());
		}
		offset += sizeEach;
	}
	return args.GetThis();
}

// binary#unpack(format:string, values*:number):[nil]
Gura_DeclareMethod(binary, unpack)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_number, OCCUR_ZeroOrMore);
	DeclareAttr(Gura_Symbol(nil));
}

Gura_ImplementMethod(binary, unpack)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	size_t offset = 0;
	bool exceedErrorFlag = !args.IsSet(Gura_Symbol(nil));
	return pThis->GetBinary().Unpack(env, sig, offset,
						args.GetString(0), args.GetList(1), exceedErrorFlag);
}

// binary#unpacks(format:string, values*:number) {block?}
Gura_DeclareMethod(binary, unpacks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_number, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(binary, unpacks)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	Object_binary *pObj = Object_binary::Reference(pThis);
	size_t offset = 0;
	Iterator *pIterator = new Object_binary::IteratorUnpack(pObj,
							args.GetString(0), args.GetList(1), offset);
	return ReturnIterator(env, sig, args, pIterator);
}

// binary#writer() {block?}
Gura_DeclareMethod(binary, writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(binary, writer)
{
	Object_binary *pThis = Object_binary::GetThisObj(args);
	Stream *pStream = new Stream_Binary(env, sig, Object_binary::Reference(pThis), true);
	return ReturnValue(env, sig, args, Value(new Object_stream(env, pStream)));
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
	Gura_AssignMethod(binary, len);
	Gura_AssignMethod(binary, pack);
	Gura_AssignMethod(binary, pointer);
	Gura_AssignMethod(binary, reader);
	Gura_AssignMethod(binary, store);
	Gura_AssignMethod(binary, unpack);
	Gura_AssignMethod(binary, unpacks);
	Gura_AssignMethod(binary, writer);
}

bool Class_binary::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_string()) {
		Object_binary *pObjBinary = new Object_binary(env, value.GetStringSTL(), true);
		value = Value(pObjBinary);
		return true;
	}
	return false;
}

bool Class_binary::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return false;
}

bool Class_binary::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	return false;
}

Object *Class_binary::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return new Object_binary((pClass == NULL)? this : pClass);
}

//-----------------------------------------------------------------------------
// Stream_Binary
//-----------------------------------------------------------------------------
Stream_Binary::Stream_Binary(Environment &env, Signal sig, Object_binary *pObjBinary, bool seekEndFlag) :
	Stream(env, sig, ATTR_BwdSeekable | ATTR_Readable | (pObjBinary->IsWritable()? ATTR_Writable : 0)),
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
	return NULL;
}

size_t Stream_Binary::DoRead(Signal sig, void *buff, size_t len)
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

size_t Stream_Binary::DoWrite(Signal sig, const void *buff, size_t len)
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

bool Stream_Binary::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	const Binary &binary = GetBinary();
	if (seekMode == SeekSet) {
		_offset = static_cast<size_t>(offset);
	} else if (seekMode == SeekCur) {
		_offset += offset;
	}
	return true;
}

bool Stream_Binary::DoFlush(Signal sig)
{
	return true;
}

bool Stream_Binary::DoClose(Signal sig)
{
	return Stream::DoClose(sig);
}

size_t Stream_Binary::DoGetSize()
{
	return GetBinary().size();
}

}
