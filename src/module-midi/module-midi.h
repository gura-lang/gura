//-----------------------------------------------------------------------------
// Gura module: midi
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_MIDI_H__
#define __GURA_MODULE_MIDI_H__
#include <gura.h>
#include "Port.h"
#include "Sequence.h"
#include "MML.h"
#include "SoundFont.h"

Gura_BeginModuleHeader(midi)

Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(midi);
Gura_DeclareUserSymbol(sysex);
Gura_DeclareUserSymbol(meta);
Gura_DeclareUserSymbol(timestamp);
Gura_DeclareUserSymbol(status);
Gura_DeclareUserSymbol(id);
Gura_DeclareUserSymbol(name);
Gura_DeclareUserSymbol(dispname);
Gura_DeclareUserSymbol(symbol);
Gura_DeclareUserSymbol(args);
Gura_DeclareUserSymbol(format);
Gura_DeclareUserSymbol(division);
Gura_DeclareUserSymbol(tracks);
Gura_DeclareUserSymbol(events);
Gura_DeclareUserSymbol(channel);
Gura_DeclareUserSymbol(note);
Gura_DeclareUserSymbol(velocity);
Gura_DeclareUserSymbol(value);
Gura_DeclareUserSymbol(controller);
Gura_DeclareUserSymbol(program);
Gura_DeclareUserSymbol(pressure);
Gura_DeclareUserSymbol(binary);
Gura_DeclareUserSymbol(number);
Gura_DeclareUserSymbol(text);
Gura_DeclareUserSymbol(mpqn);
Gura_DeclareUserSymbol(hour);
Gura_DeclareUserSymbol(minute);
Gura_DeclareUserSymbol(second);
Gura_DeclareUserSymbol(frame);
Gura_DeclareUserSymbol(subFrame);
Gura_DeclareUserSymbol(numerator);
Gura_DeclareUserSymbol(denominator);
Gura_DeclareUserSymbol(metronome);
Gura_DeclareUserSymbol(cnt32nd);
Gura_DeclareUserSymbol(key);
Gura_DeclareUserSymbol(scale);
Gura_DeclareUserSymbol(note_off);
Gura_DeclareUserSymbol(note_on);
Gura_DeclareUserSymbol(poly_pressure);
Gura_DeclareUserSymbol(control_change);
Gura_DeclareUserSymbol(program_change);
Gura_DeclareUserSymbol(channel_pressure);
Gura_DeclareUserSymbol(pitch_bend);
Gura_DeclareUserSymbol(sys_ex_event);
Gura_DeclareUserSymbol(unknown);
Gura_DeclareUserSymbol(sequence_number);
Gura_DeclareUserSymbol(text_event);
Gura_DeclareUserSymbol(copyright_notice);
Gura_DeclareUserSymbol(sequence_or_track_name);
Gura_DeclareUserSymbol(instrument_name);
Gura_DeclareUserSymbol(lyric_text);
Gura_DeclareUserSymbol(marker_text);
Gura_DeclareUserSymbol(cue_point);
Gura_DeclareUserSymbol(midi_channel_prefix_assignment);
Gura_DeclareUserSymbol(end_of_track);
Gura_DeclareUserSymbol(tempo_setting);
Gura_DeclareUserSymbol(smpte_offset);
Gura_DeclareUserSymbol(time_signature);
Gura_DeclareUserSymbol(key_signature);
Gura_DeclareUserSymbol(sequencer_specific_event);
Gura_DeclareUserSymbol(background);
Gura_DeclareUserSymbol(player);
Gura_DeclareUserSymbol(stream);
Gura_DeclareUserSymbol(speed);
Gura_DeclareUserSymbol(count);
Gura_DeclareUserSymbol(repeat);
Gura_DeclareUserSymbol(progress);
Gura_DeclareUserSymbol(audio);

//-----------------------------------------------------------------------------
// information table
//-----------------------------------------------------------------------------
struct ControllerInfo {
	const char *name;
	const Symbol *pSymbol;
};

struct ProgramInfo {
	const char *name;
	const char *dispName;
	const Symbol *pSymbol;
};

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
int ControllerIdBySymbol(const Symbol *pSymbol);
int ControllerIdByName(const char *name);
const ControllerInfo *ControllerInfoById(int controller);
inline const ControllerInfo *ControllerInfoBySymbol(const Symbol *pSymbol) {
	return ControllerInfoById(ControllerIdBySymbol(pSymbol));
}
inline const ControllerInfo *ControllerInfoByName(const char *name) {
	return ControllerInfoById(ControllerIdByName(name));
}

int ProgramIdBySymbol(const Symbol *pSymbol);
int ProgramIdByName(const char *name);
const ProgramInfo *ProgramInfoById(int program);
inline const ProgramInfo *ProgramInfoBySymbol(const Symbol *pSymbol) {
	return ProgramInfoById(ProgramIdBySymbol(pSymbol));
}
inline const ProgramInfo *ProgramInfoByName(const char *name) {
	return ProgramInfoById(ProgramIdByName(name));
}

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
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
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
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for midi.sequence
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(sequence);

class Object_sequence : public Object {
private:
	Sequence _sequence;
public:
	Gura_DeclareObjectAccessor(sequence)
public:
	inline Object_sequence(Environment &env) : Object(Gura_UserClass(sequence)) {}
	inline Sequence &GetSequence() { return _sequence; }
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
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
	virtual String ToString(bool exprFlag);
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
	virtual String ToString(bool exprFlag);
	inline Port *GetPort() { return _pPort.get(); }
};

//-----------------------------------------------------------------------------
// Class declaration for midi.player
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(player);

class Object_player : public Object {
public:
	Gura_DeclareObjectAccessor(player)
private:
	AutoPtr<Player> _pPlayer;
public:
	inline Object_player(Environment &env, Player *pPlayer) :
					Object(Gura_UserClass(player)), _pPlayer(pPlayer) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Player *GetPlayer() { return _pPlayer.get(); }
};

//-----------------------------------------------------------------------------
// Class declaration for midi.controller
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(controller);

class Object_controller : public Object {
public:
	Gura_DeclareObjectAccessor(controller)
private:
	UChar _controller;
public:
	inline Object_controller(Environment &env, UChar controller) :
			Object(Gura_UserClass(controller)), _controller(controller) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline UChar GetController() const { return _controller; }
	inline const ControllerInfo &GetControllerInfo() const { return *ControllerInfoById(_controller); }
};

//-----------------------------------------------------------------------------
// Class declaration for midi.program
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(program);

class Object_program : public Object {
public:
	Gura_DeclareObjectAccessor(program)
private:
	int _program;
public:
	inline Object_program(Environment &env, UChar program) :
			Object(Gura_UserClass(program)), _program(program) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline UChar GetProgram() const { return _program; }
	inline const ProgramInfo &GetProgramInfo() const { return *ProgramInfoById(_program); }
};

//-----------------------------------------------------------------------------
// Class declaration for midi.soundfont
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(soundfont);

class Object_soundfont : public Object {
public:
	Gura_DeclareObjectAccessor(soundfont)
private:
	SoundFont _soundFont;
public:
	inline Object_soundfont(Environment &env, Stream *pStream) :
					Object(Gura_UserClass(soundfont)), _soundFont(pStream) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SoundFont &GetSoundFont() { return _soundFont; }
};

//-----------------------------------------------------------------------------
// Class declaration for midi.synthesizer
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(synthesizer);

class Object_synthesizer : public Object {
public:
	Gura_DeclareObjectAccessor(synthesizer)
private:
	AutoPtr<SoundFont::Synthesizer> _pSynthesizer;
public:
	inline Object_synthesizer(Environment &env, SoundFont::Synthesizer *pSynthesizer) :
					Object(Gura_UserClass(synthesizer)), _pSynthesizer(pSynthesizer) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SoundFont::Synthesizer *GetSynthesizer() { return _pSynthesizer.get(); }
};

//-----------------------------------------------------------------------------
// Iterator_track
//-----------------------------------------------------------------------------
class Iterator_track : public Iterator {
private:
	size_t _idxTrack;
	AutoPtr<TrackOwner> _pTrackOwner;
public:
	Iterator_track(TrackOwner *pTrackOwner);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_eventAll
//-----------------------------------------------------------------------------
class Iterator_eventAll : public Iterator {
private:
	size_t _idxTrack;
	size_t _idxEvent;
	AutoPtr<TrackOwner> _pTrackOwner;
public:
	Iterator_eventAll(TrackOwner *pTrackOwner);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_event
//-----------------------------------------------------------------------------
class Iterator_event : public Iterator {
private:
	size_t _idxEvent;
	AutoPtr<EventOwner> _pEventOwner;
public:
	Iterator_event(EventOwner *pEventOwner);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleHeader(midi)

#endif
