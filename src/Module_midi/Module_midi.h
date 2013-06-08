//-----------------------------------------------------------------------------
// Gura midi module
//-----------------------------------------------------------------------------
#ifndef __MODULE_MIDI_H__
#define __MODULE_MIDI_H__
#include <gura.h>
#include "Port.h"
#include "SMF.h"
#include "MML.h"

Gura_BeginModule(midi)

Gura_DeclareUserSymbol(format);
Gura_DeclareUserSymbol(division);
Gura_DeclareUserSymbol(tracks);
Gura_DeclareUserSymbol(events);

//-----------------------------------------------------------------------------
// Class declaration for midi.event
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(event);

class Object_event : public Object {
private:
	AutoPtr<Event> _pEvent;
public:
	Gura_DeclareObjectAccessor(event)
public:
	inline Object_event(Environment &env, Event *pEvent) : Object(Gura_UserClass(event)), _pEvent(pEvent) {}
	inline Event *GetEvent() { return _pEvent.get(); }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for midi.track
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(track);

class Object_track : public Object {
private:
	AutoPtr<Track> _pTrack;
public:
	Gura_DeclareObjectAccessor(track)
public:
	inline Object_track(Environment &env, Track *pTrack) : Object(Gura_UserClass(track)), _pTrack(pTrack) {}
	inline Track *GetTrack() { return _pTrack.get(); }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for midi.smf
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(smf);

class Object_smf : public Object {
private:
	SMF _smf;
public:
	Gura_DeclareObjectAccessor(smf)
public:
	inline Object_smf(Environment &env) : Object(Gura_UserClass(smf)) {}
	inline SMF &GetSMF() { return _smf; }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for midi.mml
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(mml);

class Object_mml : public Object {
private:
	MML _mml;
public:
	Gura_DeclareObjectAccessor(mml)
public:
	inline Object_mml(Environment &env) : Object(Gura_UserClass(mml)) {}
	inline MML &GetMML() { return _mml; }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for midi.portinfo
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(portinfo);

class Object_portinfo : public Object {
public:
	Gura_DeclareObjectAccessor(portinfo)
public:
	inline Object_portinfo(Environment &env) : Object(Gura_UserClass(portinfo)) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for midi.port
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(port);

class Object_port : public Object {
public:
	Gura_DeclareObjectAccessor(port)
private:
	Port _port;
public:
	inline Object_port(Environment &env) : Object(Gura_UserClass(port)) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline Port *GetPort() { return &_port; }
};

//-----------------------------------------------------------------------------
// Iterator_track
//-----------------------------------------------------------------------------
class Iterator_track : public Iterator {
private:
	size_t _idx;
	AutoPtr<TrackOwner> _pTrackOwner;
public:
	Iterator_track(TrackOwner *pTrackOwner);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_event
//-----------------------------------------------------------------------------
class Iterator_event : public Iterator {
private:
	size_t _idx;
	AutoPtr<EventOwner> _pEventOwner;
public:
	Iterator_event(EventOwner *pEventOwner);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}}

#endif
