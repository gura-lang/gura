//-----------------------------------------------------------------------------
// Gura midi module
//-----------------------------------------------------------------------------
#ifndef __MODULE_MIDI_H__
#define __MODULE_MIDI_H__
#include <gura.h>
#include "Port.h"
#include "Content.h"
#include "MML.h"

Gura_BeginModule(midi)

Gura_DeclareUserSymbol(timestamp);
Gura_DeclareUserSymbol(status);
Gura_DeclareUserSymbol(name);
Gura_DeclareUserSymbol(args);
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
// Class declaration for midi.content
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(content);

class Object_content : public Object {
private:
	Content _content;
public:
	Gura_DeclareObjectAccessor(content)
public:
	inline Object_content(Environment &env) : Object(Gura_UserClass(content)) {}
	inline Content &GetContent() { return _content; }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
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
	AutoPtr<Port> _pPort;
public:
	inline Object_port(Environment &env) : Object(Gura_UserClass(port)), _pPort(new Port()) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline Port *GetPort() { return _pPort.get(); }
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
