//=============================================================================
// Gura class: memory
//=============================================================================
#include "stdafx.h"
#include "gura/Class_arrayT.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_memory
//-----------------------------------------------------------------------------
Object_memory::Object_memory(Environment &env, Memory *pMemory) :
			Object(env.LookupClass(VTYPE_memory)), _pMemory(pMemory)
{
}

Object_memory::Object_memory(Class *pClass, Memory *pMemory) :
			Object(pClass), _pMemory(pMemory)
{
}

Object *Object_memory::Clone() const
{
	return nullptr; //new Object_memory(*this);
}

bool Object_memory::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(p));
	symbols.insert(Gura_Symbol(size));
	return true;
}

Value Object_memory::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(p))) {
		Pointer *pPointer = new PointerEx(0, Reference());
		return Value(new Object_pointer(env, pPointer));
	} else if (pSymbol->IsIdentical(Gura_Symbol(size))) {
		return Value(_pMemory->GetSize());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_memory::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Object_memory::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<memory:";
	do {
		char buff[80];
		::sprintf(buff, "%ldbytes", _pMemory->GetSize());
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Object_memory::PointerEx
//-----------------------------------------------------------------------------
Object_memory::PointerEx::PointerEx(size_t offset, Object_memory *pObjMemory) :
	Pointer(offset), _pObjMemory(pObjMemory)
{
}

Object_memory::PointerEx::PointerEx(const PointerEx &ptr) :
	Pointer(ptr), _pObjMemory(dynamic_cast<Object_memory *>(ptr._pObjMemory->Reference()))
{
}

bool Object_memory::PointerEx::StorePrepare(Signal &sig, size_t bytes)
{
	Memory &memory = _pObjMemory->GetMemory();
	if (_offset + bytes <= memory.GetSize()) return true;
	sig.SetError(ERR_OutOfRangeError, "pointer exceeds the range of memory");
	return false;
}

void Object_memory::PointerEx::StoreBuffer(const void *buff, size_t bytes)
{
	Memory &memory = _pObjMemory->GetMemory();
	if (_offset >= memory.GetSize()) return;
	size_t bytesToCopy = ChooseMin(memory.GetSize() - _offset, bytes);
	if (buff != nullptr) ::memcpy(memory.GetPointer(_offset), buff, bytesToCopy);
	_offset += bytesToCopy;
}

const UChar *Object_memory::PointerEx::ExtractPrepare(
	Signal &sig, size_t bytes, bool exceedErrorFlag)
{
	Memory &memory = _pObjMemory->GetMemory();
	if (_offset + bytes <= memory.GetSize()) {
		const UChar *p = reinterpret_cast<const UChar *>(memory.GetPointer(_offset));
		_offset += bytes;
		return p;
	}
	if (exceedErrorFlag) {
		sig.SetError(ERR_OutOfRangeError, "pointer exceeds the range of memory");
	}
	return nullptr;
}

Pointer *Object_memory::PointerEx::Clone() const
{
	return new PointerEx(*this);
}

Object *Object_memory::PointerEx::GetTarget() const
{
	return _pObjMemory.get();
}

const UChar *Object_memory::PointerEx::GetPointerC() const
{
	return reinterpret_cast<const UChar *>(_pObjMemory->GetMemory().GetPointer(_offset));
}

UChar *Object_memory::PointerEx::GetWritablePointerC() const
{
	return reinterpret_cast<UChar *>(_pObjMemory->GetMemory().GetPointer(_offset));
}

size_t Object_memory::PointerEx::GetEntireSize() const
{
	return _pObjMemory->GetMemory().GetSize();
}

bool Object_memory::PointerEx::IsWritable() const
{
	return true;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// memory(bytes:number):map {block?}
Gura_DeclareFunction(memory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bytes", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_memory));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(memory)
{
	size_t bytes = arg.GetSizeT(0);
	AutoPtr<Memory> pMemory(new MemoryHeap(bytes));
	return ReturnValue(env, arg, Value(new Object_memory(env, pMemory.release())));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// memory#array@T():map {block?}
#define ImplementArrayConstructor(name, T) \
Gura_DeclareMethodAlias(memory, array_at_##name, "array@" #name) \
{ \
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map); \
	DeclareBlock(OCCUR_ZeroOrOnce); \
	AddHelp( \
		Gura_Symbol(en), \
		"Creates an `array@" #name "` instance that accesses the content of the target `memory` instance."); \
} \
\
Gura_ImplementMethod(memory, array_at_##name) \
{ \
	Memory &memory = Object_memory::GetObjectThis(arg)->GetMemory(); \
	size_t cnt = memory.GetSize() / sizeof(T); \
	AutoPtr<ArrayT<T> > pArrayT(new ArrayT<T>(memory.Reference())); \
	pArrayT->SetSize1D(cnt); \
	return ReturnValue(env, arg, Value(new Object_arrayT<T>( \
										   env, VTYPE_array_at_##name, pArrayT.release()))); \
}

ImplementArrayConstructor(char, Char)
ImplementArrayConstructor(uchar, UChar)
ImplementArrayConstructor(short, Short)
ImplementArrayConstructor(ushort, UShort)
ImplementArrayConstructor(int, Int)
ImplementArrayConstructor(uint, UInt)
ImplementArrayConstructor(int32, Int32)
ImplementArrayConstructor(uint32, UInt32)
ImplementArrayConstructor(int64, Int64)
ImplementArrayConstructor(uint64, UInt64)
ImplementArrayConstructor(float, float)
ImplementArrayConstructor(double, double)

// memory#dump(stream?:stream:w):void:[upper]
Gura_DeclareMethod(memory, dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareAttr(Gura_Symbol(upper));
	AddHelp(
		Gura_Symbol(en),
		"Prints a hexadecimal dump from the content of the `memory` to the standard output.\n"
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

Gura_ImplementMethod(memory, dump)
{
	Signal &sig = env.GetSignal();
	Stream *pStream = arg.IsInstanceOf(0, VTYPE_stream)?
								&arg.GetStream(0) : env.GetConsole();
	Object_memory *pThis = Object_memory::GetObjectThis(arg);
	const Memory &memory = pThis->GetMemory();
	pStream->Dump(sig, memory.GetPointer(), memory.GetSize(), arg.IsSet(Gura_Symbol(upper)));
	return Value::Nil;
}

// memory#pointer(offset?:number) {block?}
Gura_DeclareMethod(memory, pointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a `pointer` instance that has an initial offset specified\n"
		"by the argument `offset`. If the argument is omitted, it would return a `pointer`\n"
		"instance that points to the top of the memory.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("p", "pointer"));
}

Gura_ImplementMethod(memory, pointer)
{
	Object_memory *pThis = Object_memory::GetObjectThis(arg);
	size_t offset = arg.Is_number(0)? arg.GetSizeT(0) : 0;
	Pointer *pPointer = new Object_memory::PointerEx(offset, pThis->Reference());
	return ReturnValue(env, arg, Value(new Object_pointer(env, pPointer)));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_memory::Class_memory(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_memory)
{
}

void Class_memory::Prepare(Environment &env)
{
	Gura_AssignFunction(memory);
	Gura_AssignMethod(memory, array_at_char);
	Gura_AssignMethod(memory, array_at_uchar);
	Gura_AssignMethod(memory, array_at_short);
	Gura_AssignMethod(memory, array_at_ushort);
	Gura_AssignMethod(memory, array_at_int);
	Gura_AssignMethod(memory, array_at_uint);
	Gura_AssignMethod(memory, array_at_int32);
	Gura_AssignMethod(memory, array_at_uint32);
	Gura_AssignMethod(memory, array_at_int64);
	Gura_AssignMethod(memory, array_at_uint64);
	Gura_AssignMethod(memory, array_at_float);
	Gura_AssignMethod(memory, array_at_double);
	Gura_AssignMethod(memory, dump);
	Gura_AssignMethod(memory, pointer);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en + 1);
}

bool Class_memory::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	if (value.Is_array_at_char()) {
		Memory &memory = Object_arrayT<Char>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_uchar()) {
		Memory &memory = Object_arrayT<UChar>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_short()) {
		Memory &memory = Object_arrayT<Short>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_ushort()) {
		Memory &memory = Object_arrayT<UShort>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_int()) {
		Memory &memory = Object_arrayT<Int>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_uint()) {
		Memory &memory = Object_arrayT<UInt>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_int32()) {
		Memory &memory = Object_arrayT<Int32>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_uint32()) {
		Memory &memory = Object_arrayT<UInt32>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_int64()) {
		Memory &memory = Object_arrayT<Int64>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_uint64()) {
		Memory &memory = Object_arrayT<UInt64>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_float()) {
		Memory &memory = Object_arrayT<float>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	} else if (value.Is_array_at_double()) {
		Memory &memory = Object_arrayT<double>::GetObject(value)->GetArrayT()->GetMemory();
		value = Value(new Object_memory(env, memory.Reference()));
		return true;
	}
	return false;
}

}
