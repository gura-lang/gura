//-----------------------------------------------------------------------------
// Gura midi module
//-----------------------------------------------------------------------------
#include "Module_midi.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Object_smf
//-----------------------------------------------------------------------------
Object *Object_smf::Clone() const
{
	return NULL;
}

bool Object_smf::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_Symbol(string));
	return true;
}

Value Object_smf::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(env, _str);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

String Object_smf::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<midi.smf:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.smf
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for midi.smf
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(smf)
{
}

//-----------------------------------------------------------------------------
// Object_devinfo
//-----------------------------------------------------------------------------
Object *Object_devinfo::Clone() const
{
	return NULL;
}

bool Object_devinfo::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_Symbol(string));
	return true;
}

Value Object_devinfo::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(env, _str);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

String Object_devinfo::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<midi.devinfo:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.devinfo
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for midi.devinfo
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(devinfo)
{
}

//-----------------------------------------------------------------------------
// Object_device
//-----------------------------------------------------------------------------
Object *Object_device::Clone() const
{
	return NULL;
}

bool Object_device::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_Symbol(string));
	return true;
}

Value Object_device::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(env, _str);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

String Object_device::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<midi.device:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.device
//-----------------------------------------------------------------------------
// midi.device#rawwrite(msg+:number):map
Gura_DeclareMethod(device, rawwrite)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msg", VTYPE_number, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(device, rawwrite)
{
	Object_device *pThis = Object_device::GetThisObj(args);
	const ValueList &valList = args.GetList(0);
	size_t nArgs = valList.size();
	if (nArgs == 1) {
		pThis->GetHandle().RawWrite(valList[0].GetUChar());
	} else if (nArgs == 2) {
		pThis->GetHandle().RawWrite(valList[0].GetUChar(), valList[1].GetUChar());
	} else if (nArgs == 3) {
		pThis->GetHandle().RawWrite(valList[0].GetUChar(), valList[1].GetUChar(),
														valList[2].GetUChar());
	} else if (nArgs == 4) {
		pThis->GetHandle().RawWrite(valList[0].GetUChar(), valList[1].GetUChar(),
							valList[2].GetUChar(), valList[3].GetUChar());
	} else {
		sig.SetError(ERR_ArgumentError, "too many arguments");
		return Value::Null;
	}
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for midi.device
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(device)
{
	Gura_AssignMethod(device, rawwrite);
}

//-----------------------------------------------------------------------------
// Gura module functions: midi
//-----------------------------------------------------------------------------
// midi.device(id?:number) {block?}
Gura_DeclareFunction(device)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(device));
	AddHelp(Gura_Symbol(en), "open a MIDI device and returns a handle to it.");
}

Gura_ImplementFunction(device)
{
	int id = args.IsNumber(0)? args.GetInt(0) : 0;
	AutoPtr<Object_device> pObj(new Object_device(env));
	if (!pObj->GetHandle().Open(id)) {
		sig.SetError(ERR_IOError, "can't open MIDI device #%d", id);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// midi.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
	AddHelp(Gura_Symbol(en), "adds two numbers and returns the result.");
}

Gura_ImplementFunction(test)
{
	::printf("%d\n", ::midiOutGetNumDevs());
	::printf("%d\n", ::midiInGetNumDevs());
	
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeUserClass(smf, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(devinfo, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(device, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(device);
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(midi, midi)

Gura_RegisterModule(midi)
