//-----------------------------------------------------------------------------
// Gura midi module
//-----------------------------------------------------------------------------
#include "Module_midi.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Object_event
//-----------------------------------------------------------------------------
Object *Object_event::Clone() const
{
	return NULL;
}

bool Object_event::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(timestamp));
	symbols.insert(Gura_UserSymbol(status));
	symbols.insert(Gura_UserSymbol(name));
	symbols.insert(Gura_UserSymbol(args));
	return true;
}

Value Object_event::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
		return Value(_pEvent->GetTimeStamp());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(status))) {
		return Value(_pEvent->GetStatusCode());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(name))) {
		return Value(env, _pEvent->GetName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(args))) {
		return Value(env, _pEvent->GetArgsName());
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_event::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<midi.event:";
	do {
		char buff[32];
		::sprintf(buff, "%08x:", _pEvent->GetTimeStamp());
		rtn += buff;
	} while (0);
	rtn += _pEvent->GetName();
	String argsName = _pEvent->GetArgsName();
	if (!argsName.empty()) {
		rtn += " ";
		rtn += argsName;
	}
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.event
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for midi.event
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(event)
{
}

//-----------------------------------------------------------------------------
// Object_track
//-----------------------------------------------------------------------------
Object *Object_track::Clone() const
{
	return NULL;
}

bool Object_track::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(events));
	return true;
}

Value Object_track::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(events))) {
		Iterator *pIterator =
				new Iterator_event(EventOwner::Reference(&_pTrack->GetEventOwner()));
		return Value(env, pIterator);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_track::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<midi.track";
	do {
		char buff[64];
		::sprintf(buff, ":%devents", _pTrack->GetEventOwner().size());
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.track
//-----------------------------------------------------------------------------
// midi.track#parse(text:string):map:void
Gura_DeclareMethod(track, parse)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
}

Gura_ImplementMethod(track, parse)
{
	Object_track *pThis = Object_track::GetThisObj(args);
	pThis->GetTrack()->ParseMML(sig, args.GetString(0));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for midi.track
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(track)
{
	Gura_AssignMethod(track, parse);
}

//-----------------------------------------------------------------------------
// Object_content
//-----------------------------------------------------------------------------
Object *Object_content::Clone() const
{
	return NULL;
}

bool Object_content::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(format));
	symbols.insert(Gura_UserSymbol(tracks));
	symbols.insert(Gura_UserSymbol(division));
	return true;
}

Value Object_content::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		return Value(_content.GetFormat());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(tracks))) {
		Iterator *pIterator =
				new Iterator_track(TrackOwner::Reference(&_content.GetTrackOwner()));
		return Value(env, pIterator);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(division))) {
		return Value(_content.GetDivision());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_content::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		unsigned short format = value.GetUShort();
		if (format > 2) {
			sig.SetError(ERR_ValueError, "wrong number for format");
			return Value::Null;
		}
		_content.SetFormat(format);
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(division))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		unsigned short division = value.GetUShort();
		_content.SetDivision(division);
		return value;
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_content::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<midi.content";
	do {
		char buff[128];
		::sprintf(buff, ":format=%d:tracks=%d:division=%d",
			_content.GetFormat(), _content.GetTrackOwner().size(), _content.GetDivision());
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.content
//-----------------------------------------------------------------------------
// midi.content#read(stream:stream:r):map:void
Gura_DeclareMethod(content, read)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementMethod(content, read)
{
	Object_content *pThis = Object_content::GetThisObj(args);
	if (!pThis->GetContent().Read(env, sig, args.GetStream(0))) return Value::Null;
	return Value::Null;
}

// midi.content#write(stream:stream:w):map:void
Gura_DeclareMethod(content, write)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
}

Gura_ImplementMethod(content, write)
{
	Object_content *pThis = Object_content::GetThisObj(args);
	if (!pThis->GetContent().Write(env, sig, args.GetStream(0))) return Value::Null;
	return Value::Null;
}

// midi.content#play(port:midi.port):void
Gura_DeclareMethod(content, play)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "port", VTYPE_port);
}

Gura_ImplementMethod(content, play)
{
	Content &content = Object_content::GetThisObj(args)->GetContent();
	Port *pPort = Object_port::GetObject(args, 0)->GetPort();
	content.Play(sig, pPort);
	return Value::Null;
}

// midi.content#track(index:number):map {block?}
Gura_DeclareMethod(content, track)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(content, track)
{
	Object_content *pThis = Object_content::GetThisObj(args);
	size_t index = args.GetSizeT(0);
	TrackOwner &trackOwner = pThis->GetContent().GetTrackOwner();
	if (index >= trackOwner.size()) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return Value::Null;
	}
	Track *pTrack = trackOwner[index];
	return ReturnValue(env, sig, args,
				Value(new Object_track(env, Track::Reference(pTrack))));
}

// midi.content#addtrack():map {block?}
Gura_DeclareMethod(content, addtrack)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(content, addtrack)
{
	Object_content *pThis = Object_content::GetThisObj(args);
	TrackOwner &trackOwner = pThis->GetContent().GetTrackOwner();
	Track *pTrack = new Track();
	trackOwner.push_back(pTrack);
	return ReturnValue(env, sig, args,
				Value(new Object_track(env, Track::Reference(pTrack))));
}

//-----------------------------------------------------------------------------
// Class implementation for midi.content
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(content)
{
	Gura_AssignMethod(content, read);
	Gura_AssignMethod(content, write);
	Gura_AssignMethod(content, play);
	Gura_AssignMethod(content, track);
	Gura_AssignMethod(content, addtrack);
}

Gura_ImplementCastFrom(content)
{
	env.LookupClass(VTYPE_stream)->CastFrom(env, sig, value, pDecl);
	if (value.IsStream()) {
		AutoPtr<Object_content> pObj(new Object_content(env));
		pObj->GetContent().Read(env, sig, value.GetStream());
		value = Value::Null; // delete stream instance
		if (sig.IsSignalled()) return false;
		value = Value(pObj.release());
		return true;
	}
	return false;
}

Gura_ImplementCastTo(content)
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

// midi.port#play(content:midi.content):map:void
Gura_DeclareMethod(port, play)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "content", VTYPE_content);
}

Gura_ImplementMethod(port, play)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	Content &content = Object_content::GetObject(args, 0)->GetContent();
	content.Play(sig, pThis->GetPort());
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for midi.port
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(port)
{
	Gura_AssignMethod(port, send);
	Gura_AssignMethod(port, play);
}

Gura_ImplementCastFrom(port)
{
	if (value.IsNumber()) {
		int id = value.GetInt();
		AutoPtr<Object_port> pObj(new Object_port(env));
		if (!pObj->GetPort()->Open(id)) {
			sig.SetError(ERR_IOError, "can't open MIDI port #%d", id);
			return false;
		}
		value = Value(pObj.release());
		return true;
	}
	return false;
}

Gura_ImplementCastTo(port)
{
	return false;
}

//-----------------------------------------------------------------------------
// Iterator_track
//-----------------------------------------------------------------------------
Iterator_track::Iterator_track(TrackOwner *pTrackOwner) :
						Iterator(false), _idx(0), _pTrackOwner(pTrackOwner)
{
}

Iterator *Iterator_track::GetSource()
{
	return NULL;
}

bool Iterator_track::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idx < _pTrackOwner->size()) {
		Track *pTrack = (*_pTrackOwner)[_idx++];
		value = Value(new Object_track(env, Track::Reference(pTrack)));
		return true;
	}
	return false;
}

String Iterator_track::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:midi.track";
	rtn += ">";
	return rtn;
}

void Iterator_track::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_event
//-----------------------------------------------------------------------------
Iterator_event::Iterator_event(EventOwner *pEventOwner) :
						Iterator(false), _idx(0), _pEventOwner(pEventOwner)
{
}

Iterator *Iterator_event::GetSource()
{
	return NULL;
}

bool Iterator_event::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idx < _pEventOwner->size()) {
		Event *pEvent = (*_pEventOwner)[_idx++];
		value = Value(new Object_event(env, Event::Reference(pEvent)));
		return true;
	}
	return false;
}

String Iterator_event::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:midi.event";
	rtn += ">";
	return rtn;
}

void Iterator_event::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Gura module functions: midi
//-----------------------------------------------------------------------------
// midi.content(stream?:stream) {block?}
Gura_DeclareFunction(content)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(content));
	AddHelp(Gura_Symbol(en), "create an instance that contains SMF information.");
}

Gura_ImplementFunction(content)
{
	AutoPtr<Object_content> pObj(new Object_content(env));
	Content &content = pObj->GetContent();
	if (args.IsStream(0)) {
		if (!content.Read(env, sig, args.GetStream(0))) return Value::Null;
	} else {
		content.SetDivision(140);
	}
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
	// symbol realization
	Gura_RealizeUserSymbol(timestamp);
	Gura_RealizeUserSymbol(status);
	Gura_RealizeUserSymbol(name);
	Gura_RealizeUserSymbol(args);
	Gura_RealizeUserSymbol(format);
	Gura_RealizeUserSymbol(division);
	Gura_RealizeUserSymbol(tracks);
	Gura_RealizeUserSymbol(events);
	// class realization
	Gura_RealizeUserClassWithoutPrepare(event, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(track, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(content, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(portinfo, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(port, env.LookupClass(VTYPE_object));
	Gura_UserClass(event)->Prepare(env);
	Gura_UserClass(track)->Prepare(env);
	Gura_UserClass(content)->Prepare(env);
	Gura_UserClass(portinfo)->Prepare(env);
	Gura_UserClass(port)->Prepare(env);
	// function assignment
	Gura_AssignFunction(content);
	Gura_AssignFunction(port);
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(midi, midi)

Gura_RegisterModule(midi)
