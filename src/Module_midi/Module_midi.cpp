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
// midi.smf#read(stream:stream:r):map:void
Gura_DeclareMethod(smf, read)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementMethod(smf, read)
{
	Object_smf *pThis = Object_smf::GetThisObj(args);
	if (!pThis->GetSMF().Read(sig, args.GetStream(0))) return Value::Null;
	return Value::Null;
}

// midi.smf#write(stream:stream:w):map:void
Gura_DeclareMethod(smf, write)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
}

Gura_ImplementMethod(smf, write)
{
	Object_smf *pThis = Object_smf::GetThisObj(args);
	if (!pThis->GetSMF().Write(sig, args.GetStream(0))) return Value::Null;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for midi.smf
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(smf)
{
	Gura_AssignMethod(smf, read);
}

Gura_ImplementCastFrom(smf)
{
	env.LookupClass(VTYPE_stream)->CastFrom(env, sig, value, pDecl);
	if (value.IsStream()) {
		AutoPtr<Object_smf> pObj(new Object_smf(env));
		pObj->GetSMF().Read(sig, value.GetStream());
		value = Value::Null; // delete stream instance
		if (sig.IsSignalled()) return false;
		value = Value(pObj.release());
		return true;
	}
	return false;
}

Gura_ImplementCastTo(smf)
{
	return false;
}

//-----------------------------------------------------------------------------
// Object_mml
//-----------------------------------------------------------------------------
Object *Object_mml::Clone() const
{
	return NULL;
}

bool Object_mml::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_Symbol(string));
	return true;
}

Value Object_mml::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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

String Object_mml::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<midi.mml:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.mml
//-----------------------------------------------------------------------------
// midi.mml#parse(channel:number, text:string):map:void
Gura_DeclareMethod(mml, parse)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "text", VTYPE_string);
}

Gura_ImplementMethod(mml, parse)
{
	Object_mml *pThis = Object_mml::GetThisObj(args);
	if (!pThis->GetMML().Parse(sig, args.GetChar(0), args.GetString(1))) return Value::Null;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for midi.mml
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mml)
{
	Gura_AssignMethod(mml, parse);
}

Gura_ImplementCastFrom(mml)
{
	if (value.IsString()) {
		unsigned char channel = 0;
		AutoPtr<Object_mml> pObj(new Object_mml(env));
		if (!pObj->GetMML().Parse(sig, channel, value.GetString())) return false;
		value = Value(pObj.release());
		return true;
	}
	return false;
}

Gura_ImplementCastTo(mml)
{
	return false;
}

//-----------------------------------------------------------------------------
// Object_portinfo
//-----------------------------------------------------------------------------
Object *Object_portinfo::Clone() const
{
	return NULL;
}

bool Object_portinfo::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_Symbol(string));
	return true;
}

Value Object_portinfo::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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

String Object_portinfo::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<midi.portinfo:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.portinfo
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for midi.portinfo
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(portinfo)
{
}

//-----------------------------------------------------------------------------
// Object_port
//-----------------------------------------------------------------------------
Object *Object_port::Clone() const
{
	return NULL;
}

bool Object_port::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_Symbol(string));
	return true;
}

Value Object_port::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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

String Object_port::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<midi.port:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.port
//-----------------------------------------------------------------------------
// midi.port#send(msg+:number):map:void
Gura_DeclareMethod(port, send)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msg", VTYPE_number, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(port, send)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	const ValueList &valList = args.GetList(0);
	size_t nArgs = valList.size();
	if (nArgs == 1) {
		pThis->GetPort()->Send(valList[0].GetUChar());
	} else if (nArgs == 2) {
		pThis->GetPort()->Send(valList[0].GetUChar(), valList[1].GetUChar());
	} else if (nArgs == 3) {
		pThis->GetPort()->Send(valList[0].GetUChar(), valList[1].GetUChar(),
														valList[2].GetUChar());
	} else if (nArgs == 4) {
		pThis->GetPort()->Send(valList[0].GetUChar(), valList[1].GetUChar(),
							valList[2].GetUChar(), valList[3].GetUChar());
	} else {
		sig.SetError(ERR_ArgumentError, "too many arguments");
		return Value::Null;
	}
	return Value::Null;
}

// midi.port#play(smf:midi.smf):map:void
Gura_DeclareMethod(port, play)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "smf", VTYPE_smf);
}

Gura_ImplementMethod(port, play)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	SMF &smf = Object_smf::GetObject(args, 0)->GetSMF();
	smf.Play(sig, pThis->GetPort());
	return Value::Null;
}

// midi.port#mmlplay(mml:midi.mml):map:void
Gura_DeclareMethod(port, mmlplay)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mml", VTYPE_mml);
}

Gura_ImplementMethod(port, mmlplay)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	MML &mml = Object_mml::GetObject(args, 0)->GetMML();
	mml.Play(sig, pThis->GetPort());
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for midi.port
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(port)
{
	Gura_AssignMethod(port, send);
	Gura_AssignMethod(port, play);
	Gura_AssignMethod(port, mmlplay);
}

//-----------------------------------------------------------------------------
// Gura module functions: midi
//-----------------------------------------------------------------------------
// midi.smf(stream?:stream) {block?}
Gura_DeclareFunction(smf)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(smf));
	AddHelp(Gura_Symbol(en), "create an instance that contains SMF information.");
}

Gura_ImplementFunction(smf)
{
	AutoPtr<Object_smf> pObj(new Object_smf(env));
	if (args.IsStream(0)) {
		if (!pObj->GetSMF().Read(sig, args.GetStream(0))) return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// midi.mml() {block?}
Gura_DeclareFunction(mml)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(mml));
	AddHelp(Gura_Symbol(en), "create an instance that parses MML string and stores its data.");
}

Gura_ImplementFunction(mml)
{
	AutoPtr<Object_mml> pObj(new Object_mml(env));
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// midi.port(id?:number) {block?}
Gura_DeclareFunction(port)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(port));
	AddHelp(Gura_Symbol(en), "open a MIDI port and returns a handle to it.");
}

Gura_ImplementFunction(port)
{
	int id = args.IsNumber(0)? args.GetInt(0) : 0;
	AutoPtr<Object_port> pObj(new Object_port(env));
	if (!pObj->GetPort()->Open(id)) {
		sig.SetError(ERR_IOError, "can't open MIDI port #%d", id);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// midi.test(stream:stream)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
}

Gura_ImplementFunction(test)
{
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeUserClass(smf, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(mml, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(portinfo, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(port, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(smf);
	Gura_AssignFunction(mml);
	Gura_AssignFunction(port);
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(midi, midi)

Gura_RegisterModule(midi)
