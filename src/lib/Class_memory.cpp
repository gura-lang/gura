//=============================================================================
// Gura class: memory
//=============================================================================
#include "stdafx.h"

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

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_memory::Class_memory(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_memory)
{
}

void Class_memory::Prepare(Environment &env)
{
	Gura_AssignFunction(memory);
}

bool Class_memory::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
#if 0
	Signal &sig = GetSignal();
	size_t nChannels = 1;
	size_t nSamplesPerSec = 10000;
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, pDecl);
	if (value.Is_stream()) {
		AutoPtr<Memory> pMemory(new Memory(Memory::FORMAT_None, nChannels, nSamplesPerSec));
		pMemory->Read(env, value.GetStream(), nullptr);
		value = Value::Nil; // delete stream instance
		if (sig.IsSignalled()) return false;
		value = Value(new Object_memory(env, pMemory.release()));
		return true;
	}
#endif
	return false;
}

}
