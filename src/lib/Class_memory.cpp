//=============================================================================
// Gura class: memory
//=============================================================================
#include "stdafx.h"

// memory#array@T():map {block?}
#define ImplementArrayConstructor(name, T) \
Gura_DeclareMethodAlias(memory, array_##name, "array@" #name) \
{ \
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map); \
	DeclareBlock(OCCUR_ZeroOrOnce); \
	AddHelp( \
		Gura_Symbol(en), Help::FMT_markdown, \
		"Creates an `array@" #name "` instance that accesses the content of the target `memory` instance."); \
} \
\
Gura_ImplementMethod(memory, array_##name) \
{ \
	Memory *pMemory = Object_memory::GetObjectThis(arg)->GetMemory(); \
	size_t cnt = pMemory->GetSize() / sizeof(T); \
	AutoPtr<Array<T> > pArray(new Array<T>(pMemory->Reference(), cnt)); \
	return ReturnValue(env, arg, Value(new Object_array<T>( \
										   env, VTYPE_array_##name, pArray.release()))); \
}

namespace Gura {

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
	return true;
}

Value Object_memory::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(Audio::FormatToSymbol(_pAudio->GetFormat()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(channels))) {
		return Value(static_cast<UInt>(_pAudio->GetChannels()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(samples))) {
		return Value(static_cast<UInt>(_pAudio->GetSamples()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(samplespersec))) {
		return Value(static_cast<UInt>(_pAudio->GetSamplesPerSec()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(bytespersample))) {
		return Value(static_cast<UInt>(_pAudio->GetBytesPerSample()));
	}
#endif
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
		Gura_Symbol(en), Help::FMT_markdown,
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

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_memory::Class_memory(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_memory)
{
}

void Class_memory::Prepare(Environment &env)
{
	Gura_AssignFunction(memory);
	Gura_AssignMethod(memory, array_char);
	Gura_AssignMethod(memory, array_uchar);
	Gura_AssignMethod(memory, array_short);
	Gura_AssignMethod(memory, array_ushort);
	Gura_AssignMethod(memory, array_int);
	Gura_AssignMethod(memory, array_uint);
	Gura_AssignMethod(memory, array_int32);
	Gura_AssignMethod(memory, array_uint32);
	Gura_AssignMethod(memory, array_int64);
	Gura_AssignMethod(memory, array_uint64);
	Gura_AssignMethod(memory, array_float);
	Gura_AssignMethod(memory, array_double);
}

bool Class_memory::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	if (value.Is_array_char()) {
		Memory *pMemory = Object_array<Char>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_uchar()) {
		Memory *pMemory = Object_array<UChar>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_short()) {
		Memory *pMemory = Object_array<Short>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_ushort()) {
		Memory *pMemory = Object_array<UShort>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_int()) {
		Memory *pMemory = Object_array<Int>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_uint()) {
		Memory *pMemory = Object_array<UInt>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_int32()) {
		Memory *pMemory = Object_array<Int32>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_uint32()) {
		Memory *pMemory = Object_array<UInt32>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_int64()) {
		Memory *pMemory = Object_array<Int64>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_uint64()) {
		Memory *pMemory = Object_array<UInt64>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_float()) {
		Memory *pMemory = Object_array<float>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	} else if (value.Is_array_double()) {
		Memory *pMemory = Object_array<double>::GetObject(value)->GetArray()->GetMemory();
		value = Value(new Object_memory(env, pMemory->Reference()));
		return true;
	}
	return false;
}

}
