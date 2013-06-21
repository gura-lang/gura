//-----------------------------------------------------------------------------
// Gura midi module
//-----------------------------------------------------------------------------
#include "Module_midi.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// information table
//-----------------------------------------------------------------------------
struct ControllerInfo {
	const char *name;
	const Symbol *pSymbol;
};

struct ProgramInfo {
	const char *name;
	const Symbol *pSymbol;
};

static ControllerInfo g_controllerInfos[] = {
	{ "bank_select",					NULL }, // 0
	{ "modulation_wheel",				NULL }, // 1
	{ "breath_controller",				NULL }, // 2
	{ NULL,								NULL }, // 3
	{ "foot_pedal",						NULL }, // 4
	{ "portamento_time",				NULL }, // 5
	{ "data_entry",						NULL }, // 6
	{ "volume",							NULL }, // 7
	{ "balance",						NULL }, // 8
	{ NULL,								NULL }, // 9
	{ "pan_position",					NULL }, // 10
	{ "expression",						NULL }, // 11
	{ "effect_control_1",				NULL }, // 12
	{ "effect_control_2",				NULL }, // 13
	{ NULL,								NULL }, // 14
	{ NULL,								NULL }, // 15
	{ "general_purpose_slider_1",		NULL }, // 16
	{ "general_purpose_slider_2",		NULL }, // 17
	{ "general_purpose_slider_3",		NULL }, // 18
	{ "general_purpose_slider_4",		NULL }, // 19
	{ NULL,								NULL }, // 20
	{ NULL,								NULL }, // 21
	{ NULL,								NULL }, // 22
	{ NULL,								NULL }, // 23
	{ NULL,								NULL }, // 24
	{ NULL,								NULL }, // 25
	{ NULL,								NULL }, // 26
	{ NULL,								NULL }, // 27
	{ NULL,								NULL }, // 28
	{ NULL,								NULL }, // 29
	{ NULL,								NULL }, // 30
	{ NULL,								NULL }, // 31
	{ "bank_select_fine",				NULL }, // 32
	{ "modulation_wheel_fine",			NULL }, // 33
	{ "breath_controller_fine",			NULL }, // 34
	{ NULL,								NULL }, // 35
	{ "foot_pedal_fine",				NULL }, // 36
	{ "portamento_time_fine",			NULL }, // 37
	{ "data_entry_fine",				NULL }, // 38
	{ "volume_fine",					NULL }, // 39
	{ "balance_fine",					NULL }, // 40
	{ NULL,								NULL }, // 41
	{ "pan_position_fine",				NULL }, // 42
	{ "expression_fine",				NULL }, // 43
	{ "effect_control_1_fine",			NULL }, // 44
	{ "effect_control_2_fine",			NULL }, // 45
	{ NULL,								NULL }, // 46
	{ NULL,								NULL }, // 47
	{ NULL,								NULL }, // 48
	{ NULL,								NULL }, // 49
	{ NULL,								NULL }, // 50
	{ NULL,								NULL }, // 51
	{ NULL,								NULL }, // 52
	{ NULL,								NULL }, // 53
	{ NULL,								NULL }, // 54
	{ NULL,								NULL }, // 55
	{ NULL,								NULL }, // 56
	{ NULL,								NULL }, // 57
	{ NULL,								NULL }, // 58
	{ NULL,								NULL }, // 59
	{ NULL,								NULL }, // 60
	{ NULL,								NULL }, // 61
	{ NULL,								NULL }, // 62
	{ NULL,								NULL }, // 63
	{ "hold_pedal",						NULL }, // 64
	{ "portamento",						NULL }, // 65
	{ "sustenuto_pedal",				NULL }, // 66
	{ "soft_pedal",						NULL }, // 67
	{ "legato_pedal",					NULL }, // 68
	{ "hold_2_pedal",					NULL }, // 69
	{ "sound_variation",				NULL }, // 70
	{ "sound_timbre",					NULL }, // 71
	{ "sound_release_time",				NULL }, // 72
	{ "sound_attack_time",				NULL }, // 73
	{ "sound_brightness",				NULL }, // 74
	{ "sound_control_6",				NULL }, // 75
	{ "sound_control_7",				NULL }, // 76
	{ "sound_control_8",				NULL }, // 77
	{ "sound_control_9",				NULL }, // 78
	{ "sound_control_10",				NULL }, // 79
	{ "general_purpose_button_1",		NULL }, // 80
	{ "general_purpose_button_2",		NULL }, // 81
	{ "general_purpose_button_3",		NULL }, // 82
	{ "general_purpose_button_4",		NULL }, // 83
	{ NULL,								NULL }, // 84
	{ NULL,								NULL }, // 85
	{ NULL,								NULL }, // 86
	{ NULL,								NULL }, // 87
	{ NULL,								NULL }, // 88
	{ NULL,								NULL }, // 89
	{ NULL,								NULL }, // 90
	{ "effects_level",					NULL }, // 91
	{ "tremulo_level",					NULL }, // 92
	{ "chorus_level",					NULL }, // 93
	{ "celeste_level",					NULL }, // 94
	{ "phaser_level",					NULL }, // 95
	{ "data_button_increment",			NULL }, // 96
	{ "data_button_decrement",			NULL }, // 97
	{ "non_registered_parameter_fine",	NULL }, // 98
	{ "non_registered_parameter",		NULL }, // 99
	{ "registered_parameter_fine",		NULL }, // 100
	{ "registered_parameter",			NULL }, // 101
	{ NULL,								NULL }, // 102
	{ NULL,								NULL }, // 103
	{ NULL,								NULL }, // 104
	{ NULL,								NULL }, // 105
	{ NULL,								NULL }, // 106
	{ NULL,								NULL }, // 107
	{ NULL,								NULL }, // 108
	{ NULL,								NULL }, // 109
	{ NULL,								NULL }, // 110
	{ NULL,								NULL }, // 111
	{ NULL,								NULL }, // 112
	{ NULL,								NULL }, // 113
	{ NULL,								NULL }, // 114
	{ NULL,								NULL }, // 115
	{ NULL,								NULL }, // 116
	{ NULL,								NULL }, // 117
	{ NULL,								NULL }, // 118
	{ NULL,								NULL }, // 119
	{ "all_sound_off",					NULL }, // 120
	{ "all_controllers_off",			NULL }, // 121
	{ "local_keyboard",					NULL }, // 122
	{ "all_notes_off",					NULL }, // 123
	{ "omni_mode_off",					NULL }, // 124
	{ "omni_mode_on",					NULL }, // 125
	{ "mono_operation",					NULL }, // 126
	{ "poly_operation",					NULL }, // 127
};

static ProgramInfo g_programInfos[] = {
	{ "acoustic_grand_piano",			NULL }, // 0
	{ "bright_acoustic_piano",			NULL }, // 1
	{ "electric_grand_piano",			NULL }, // 2
	{ "honky_tonk_piano",				NULL }, // 3
	{ "electric_piano1",				NULL }, // 4
	{ "electric_piano2",				NULL }, // 5
	{ "harpsichord",					NULL }, // 6
	{ "clavi",							NULL }, // 7
	{ "celesta",						NULL }, // 8
	{ "glockenspiel",					NULL }, // 9
	{ "music_box",						NULL }, // 10
	{ "vibraphone",						NULL }, // 11
	{ "marimba",						NULL }, // 12
	{ "xylophone",						NULL }, // 13
	{ "tublar_bells",					NULL }, // 14
	{ "dulcimer",						NULL }, // 15
	{ "drawbar_organ",					NULL }, // 16
	{ "percussive_organ",				NULL }, // 17
	{ "rock_organ",						NULL }, // 18
	{ "church_organ",					NULL }, // 19
	{ "reed_organ",						NULL }, // 20
	{ "accordion",						NULL }, // 21
	{ "hamonica",						NULL }, // 22
	{ "tango_accordion",				NULL }, // 23
	{ "acoustic_guitar_nylon",			NULL }, // 24
	{ "acoustic_guitar_steel",			NULL }, // 25
	{ "electric_guitar_jazz",			NULL }, // 26
	{ "electric_guitar_clean",			NULL }, // 27
	{ "electric_guitar_muted",			NULL }, // 28
	{ "overdriven_guitar",				NULL }, // 29
	{ "distortion_guitar",				NULL }, // 30
	{ "guitar_harmonics",				NULL }, // 31
	{ "acoustic_bass",					NULL }, // 32
	{ "electric_bass_finger",			NULL }, // 33
	{ "electric_bass_pick",				NULL }, // 34
	{ "fretless_bass",					NULL }, // 35
	{ "slap_bass1",						NULL }, // 36
	{ "slap_bass2",						NULL }, // 37
	{ "synth_bass1",					NULL }, // 38
	{ "synth_bass2",					NULL }, // 39
	{ "violin",							NULL }, // 40
	{ "viola",							NULL }, // 41
	{ "cello",							NULL }, // 42
	{ "contrabass",						NULL }, // 43
	{ "tremolo_strings",				NULL }, // 44
	{ "pizzicato_strings",				NULL }, // 45
	{ "orchestral_harp",				NULL }, // 46
	{ "timpani",						NULL }, // 47
	{ "string_ensemble1",				NULL }, // 48
	{ "string_ensemble2",				NULL }, // 49
	{ "synth_string1",					NULL }, // 50
	{ "synth_string2",					NULL }, // 51
	{ "choir_aahs",						NULL }, // 52
	{ "voice_oohs",						NULL }, // 53
	{ "synth_voice",					NULL }, // 54
	{ "orchestra_hit",					NULL }, // 55
	{ "trumpet",						NULL }, // 56
	{ "trombone",						NULL }, // 57
	{ "tuba",							NULL }, // 58
	{ "muted_trumpet",					NULL }, // 59
	{ "french_horn",					NULL }, // 60
	{ "brass_section",					NULL }, // 61
	{ "synth_brass1",					NULL }, // 62
	{ "synth_brass2",					NULL }, // 63
	{ "soprano_sax",					NULL }, // 64
	{ "alto_sax",						NULL }, // 65
	{ "tenor_sax",						NULL }, // 66
	{ "baritone_sax",					NULL }, // 67
	{ "oboe",							NULL }, // 68
	{ "english_horn",					NULL }, // 69
	{ "bassoon",						NULL }, // 70
	{ "clarinet",						NULL }, // 71
	{ "piccolo",						NULL }, // 72
	{ "flute",							NULL }, // 73
	{ "recorder",						NULL }, // 74
	{ "pan_flute",						NULL }, // 75
	{ "blow_bottle",					NULL }, // 76
	{ "shakuhachi",						NULL }, // 77
	{ "whistle",						NULL }, // 78
	{ "ocarina",						NULL }, // 79
	{ "lead1_square",					NULL }, // 80
	{ "lead2_sawtooth",					NULL }, // 81
	{ "lead3_calliope",					NULL }, // 82
	{ "lead4_chiff",					NULL }, // 83
	{ "lead5_chanrang",					NULL }, // 84
	{ "lead6_voice",					NULL }, // 85
	{ "lead7_fifths",					NULL }, // 86
	{ "lead8_bass",						NULL }, // 87
	{ "pad1_new_age",					NULL }, // 88
	{ "pad2_warm",						NULL }, // 89
	{ "pad3_polysynth",					NULL }, // 90
	{ "pad4_choir",						NULL }, // 91
	{ "pad5_bowed",						NULL }, // 92
	{ "pad6_metalic",					NULL }, // 93
	{ "pad7_halo",						NULL }, // 94
	{ "pad8_sweep",						NULL }, // 95
	{ "fx1_rain",						NULL }, // 96
	{ "fx2_soundtrack",					NULL }, // 97
	{ "fx3_crystal",					NULL }, // 98
	{ "fx4_atmosphere",					NULL }, // 99
	{ "fx5_brightness",					NULL }, // 100
	{ "fx6_goblins",					NULL }, // 101
	{ "fx7_echoes",						NULL }, // 102
	{ "fx8_sci_fi",						NULL }, // 103
	{ "sitar",							NULL }, // 104
	{ "banjo",							NULL }, // 105
	{ "shamisen",						NULL }, // 106
	{ "koto",							NULL }, // 107
	{ "kalimba",						NULL }, // 108
	{ "bag_pipe",						NULL }, // 109
	{ "fiddle",							NULL }, // 110
	{ "shanai",							NULL }, // 111
	{ "tinkle_bell",					NULL }, // 112
	{ "agogo",							NULL }, // 113
	{ "steel_drums",					NULL }, // 114
	{ "woodblock",						NULL }, // 115
	{ "taiko_drum",						NULL }, // 116
	{ "melodic_tom",					NULL }, // 117
	{ "synth_drum",						NULL }, // 118
	{ "reverse_cymbal",					NULL }, // 119
	{ "guitar_flet_noise",				NULL }, // 120
	{ "breath_noise",					NULL }, // 121
	{ "seashore",						NULL }, // 122
	{ "bird_tweet",						NULL }, // 123
	{ "telephone_ring",					NULL }, // 124
	{ "helicopter",						NULL }, // 125
	{ "applause",						NULL }, // 126
	{ "gunshot",						NULL },	// 127
};

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
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(timestamp));
	symbols.insert(Gura_UserSymbol(status));
	symbols.insert(Gura_UserSymbol(name));
	symbols.insert(Gura_UserSymbol(symbol));
	symbols.insert(Gura_UserSymbol(args));
	return DoDirProp(env, sig, symbols);
}

Value Object_event::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		if (_pEvent->IsMIDIEvent()) {
			return Value(Gura_UserSymbol(midi));
		} else if (_pEvent->IsSysExEvent()) {
			return Value(Gura_UserSymbol(sysex));
		} else if (_pEvent->IsMetaEvent()) {
			return Value(Gura_UserSymbol(meta));
		} else {
			return Value::Null; // this must not happen
		}
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(timestamp))) {
		return Value(_pEvent->GetTimeStamp());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(status))) {
		return Value(_pEvent->GetStatusCode());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(name))) {
		return Value(env, _pEvent->GetSymbol()->GetName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(symbol))) {
		return Value(_pEvent->GetSymbol());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(args))) {
		return Value(env, _pEvent->GetArgsName());
	}
	evaluatedFlag = false;
	return _pEvent->DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

Value Object_event::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
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
	rtn += _pEvent->GetSymbol()->GetName();
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
		::sprintf(buff, ":%devents:seek%d",
					_pTrack->GetEventOwner().size(), _pTrack->Tell());
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.track
//-----------------------------------------------------------------------------
// midi.track#seek(offset:number, origin?:symbol):reduce
Gura_DeclareMethod(track, seek)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "origin", VTYPE_symbol, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, seek)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	if (!args.IsSymbol(1)) {
		if (!pTrack->SeekSet(sig, args.GetLong(0))) return Value::Null;
	} else if (args.GetSymbol(1)->IsIdentical(Gura_Symbol(set))) {
		if (!pTrack->SeekSet(sig, args.GetLong(0))) return Value::Null;
	} else if (args.GetSymbol(1)->IsIdentical(Gura_Symbol(cur))) {
		if (!pTrack->SeekCur(sig, args.GetLong(0))) return Value::Null;
	} else {
		sig.SetError(ERR_ArgumentError, "invalid symbol");
		return Value::Null;
	}
	return args.GetThis();
}

// midi.track#tell()
Gura_DeclareMethod(track, tell)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(track, tell)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	return Value(pTrack->Tell());
}

// midi.track#erase(n?:number):reduce
Gura_DeclareMethod(track, erase)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, erase)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	size_t cnt = args.IsNumber(0)? args.GetSizeT(0) : 1;
	if (!pTrack->Erase(sig, cnt)) return Value::Null;
	return args.GetThis();
}

// midi.track#mml(text:string):map:reduce
Gura_DeclareMethod(track, mml)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
}

Gura_ImplementMethod(track, mml)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	pTrack->ParseMML(sig, args.GetString(0));
	return args.GetThis();
}

// midi.track#note_off(channel:number, note:number, velocity:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, note_off)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "note", VTYPE_number);
	DeclareArg(env, "velocity", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, note_off)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char note = args.GetUChar(1);
	unsigned char velocity = args.GetUChar(2);
	unsigned long deltaTime = args.IsNumber(3)? args.GetULong(3) : 0;
	AutoPtr<Event> pEvent(new MIDIEvent_NoteOff(0, channel, note, velocity));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#note_on(channel:number, note:number, velocity:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, note_on)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "note", VTYPE_number);
	DeclareArg(env, "velocity", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, note_on)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char note = args.GetUChar(1);
	unsigned char velocity = args.GetUChar(2);
	unsigned long deltaTime = args.IsNumber(3)? args.GetULong(3) : 0;
	AutoPtr<Event> pEvent(new MIDIEvent_NoteOn(0, channel, note, velocity));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#poly_pressure(channel:number, note:number, value:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, poly_pressure)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "note", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, poly_pressure)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char note = args.GetUChar(1);
	unsigned char value = args.GetUChar(2);
	unsigned long deltaTime = args.IsNumber(3)? args.GetULong(3) : 0;
	AutoPtr<Event> pEvent(new MIDIEvent_PolyPressure(0, channel, note, value));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#control_change(channel:number, controller, value:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, control_change)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "controller", VTYPE_any);
	DeclareArg(env, "value", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, control_change)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char controller = 0;
	if (args.IsNumber(1)) {
		controller = args.GetUChar(1);
	} else if (args.IsSymbol(1)) {
		int n = SymbolToController(args.GetSymbol(1));
		if (n < 0) {
			sig.SetError(ERR_TypeError, "invalid controller name '%s'",
											args.GetSymbol(1)->GetName());
			return Value::Null;
		}
		controller = static_cast<unsigned char>(n);
	} else {
		sig.SetError(ERR_TypeError, "controller must be specified by number or symbol");
		return Value::Null;
	}
	unsigned char value = args.GetUChar(2);
	unsigned long deltaTime = args.IsNumber(3)? args.GetULong(3) : 0;
	AutoPtr<Event> pEvent(new MIDIEvent_ControlChange(0, channel, controller, value));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#program_change(channel:number, program, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, program_change)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "program", VTYPE_any);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, program_change)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char program = 0;
	if (args.IsNumber(1)) {
		program = args.GetUChar(1);
	} else if (args.IsSymbol(1)) {
		int n = SymbolToProgram(args.GetSymbol(1));
		if (n < 0) {
			sig.SetError(ERR_TypeError, "invalid program name '%s'",
											args.GetSymbol(1)->GetName());
			return Value::Null;
		}
		program = static_cast<unsigned char>(n);
	} else {
		sig.SetError(ERR_TypeError, "program must be specified by number or symbol");
		return Value::Null;
	}
	unsigned long deltaTime = args.IsNumber(2)? args.GetULong(2) : 0;
	AutoPtr<Event> pEvent(new MIDIEvent_ProgramChange(0, channel, program));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#channel_pressure(channel:number, pressure:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, channel_pressure)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "pressure", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, channel_pressure)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char pressure = args.GetUChar(1);
	unsigned long deltaTime = args.IsNumber(2)? args.GetULong(2) : 0;
	AutoPtr<Event> pEvent(new MIDIEvent_ChannelPressure(0, channel, pressure));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#pitch_bend(channel:number, value:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, pitch_bend)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, pitch_bend)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned short value = args.GetUShort(1);
	unsigned long deltaTime = args.IsNumber(2)? args.GetULong(2) : 0;
	AutoPtr<Event> pEvent(new MIDIEvent_PitchBend(0, channel, value));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#sequence_number(number:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, sequence_number)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "number", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, sequence_number)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_SequenceNumber(0, args.GetUShort(0)));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#text_event(text:string, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, text_event)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, text_event)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_TextEvent(0, args.GetStringSTL(0)));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#copyright_notice(text:string, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, copyright_notice)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, copyright_notice)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_CopyrightNotice(0, args.GetStringSTL(0)));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#sequence_or_track_name(text:string, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, sequence_or_track_name)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, sequence_or_track_name)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_SequenceOrTrackName(0, args.GetStringSTL(0)));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#instrument_name(text:string, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, instrument_name)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, instrument_name)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_InstrumentName(0, args.GetStringSTL(0)));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#lyric_text(text:string, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, lyric_text)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, lyric_text)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_LyricText(0, args.GetStringSTL(0)));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#marker_text(text:string, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, marker_text)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, marker_text)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_MarkerText(0, args.GetStringSTL(0)));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#cue_point(text:string, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, cue_point)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, cue_point)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_CuePoint(0, args.GetStringSTL(0)));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#midi_channel_prefix_assignment(channel:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, midi_channel_prefix_assignment)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, midi_channel_prefix_assignment)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char channel = args.GetUChar(0);
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_MIDIChannelPrefixAssignment(0, channel));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#end_of_track(deltaTime?:number):map:reduce
Gura_DeclareMethod(track, end_of_track)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, end_of_track)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long deltaTime = args.IsNumber(0)? args.GetULong(0) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_EndOfTrack(0));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#tempo_setting(mpqn:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, tempo_setting)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "mpqn", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, tempo_setting)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned long mpqn = args.GetULong(0);
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_TempoSetting(0, mpqn));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#smpte_offset(hour:number, minute:number, second:number, frame:number, subFrame:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, smpte_offset)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "hour", VTYPE_number);
	DeclareArg(env, "minute", VTYPE_number);
	DeclareArg(env, "second", VTYPE_number);
	DeclareArg(env, "frame", VTYPE_number);
	DeclareArg(env, "subFrame", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, smpte_offset)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char hour = args.GetUChar(0);
	unsigned char minute = args.GetUChar(1);
	unsigned char second = args.GetUChar(2);
	unsigned char frame = args.GetUChar(3);
	unsigned char subFrame = args.GetUChar(4);
	unsigned long deltaTime = args.IsNumber(5)? args.GetULong(5) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_SMPTEOffset(0, hour, minute, second, frame, subFrame));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#time_signature(numerator:number, denominator:number, metronome:number, cnt32nd:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, time_signature)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "numerator", VTYPE_number);
	DeclareArg(env, "denominator", VTYPE_number);
	DeclareArg(env, "metronome", VTYPE_number);
	DeclareArg(env, "cnt32nd", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, time_signature)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char numerator = args.GetUChar(0);
	unsigned char denominator = args.GetUChar(1);
	unsigned char metronome = args.GetUChar(2);
	unsigned char cnt32nd = args.GetUChar(3);
	unsigned long deltaTime = args.IsNumber(4)? args.GetULong(4) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_TimeSignature(0, numerator, denominator, metronome, cnt32nd));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#key_signature(key:number, scale:number, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, key_signature)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number);
	DeclareArg(env, "scale", VTYPE_number);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, key_signature)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	unsigned char key = args.GetUChar(0);
	unsigned char scale = args.GetUChar(1);
	unsigned long deltaTime = args.IsNumber(2)? args.GetULong(2) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_KeySignature(0, key, scale));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#sequencer_specific_event(binary:binary, deltaTime?:number):map:reduce
Gura_DeclareMethod(track, sequencer_specific_event)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "binary", VTYPE_binary);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(track, sequencer_specific_event)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	const Binary &binary = args.GetBinary(0);
	unsigned long deltaTime = args.IsNumber(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_SequencerSpecificEvent(0, binary));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Class implementation for midi.track
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(track)
{
	Gura_AssignMethod(track, seek);
	Gura_AssignMethod(track, tell);
	Gura_AssignMethod(track, erase);
	Gura_AssignMethod(track, mml);
	Gura_AssignMethod(track, note_off);
	Gura_AssignMethod(track, note_on);
	Gura_AssignMethod(track, poly_pressure);
	Gura_AssignMethod(track, control_change);
	Gura_AssignMethod(track, program_change);
	Gura_AssignMethod(track, channel_pressure);
	Gura_AssignMethod(track, pitch_bend);
	Gura_AssignMethod(track, sequence_number);
	Gura_AssignMethod(track, text_event);
	Gura_AssignMethod(track, copyright_notice);
	Gura_AssignMethod(track, sequence_or_track_name);
	Gura_AssignMethod(track, instrument_name);
	Gura_AssignMethod(track, lyric_text);
	Gura_AssignMethod(track, marker_text);
	Gura_AssignMethod(track, cue_point);
	Gura_AssignMethod(track, midi_channel_prefix_assignment);
	Gura_AssignMethod(track, end_of_track);
	Gura_AssignMethod(track, tempo_setting);
	Gura_AssignMethod(track, smpte_offset);
	Gura_AssignMethod(track, time_signature);
	Gura_AssignMethod(track, key_signature);
	Gura_AssignMethod(track, sequencer_specific_event);
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
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(events))) {
		Iterator *pIterator =
				new Iterator_eventAll(TrackOwner::Reference(&_content.GetTrackOwner()));
		return Value(env, pIterator);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(division))) {
		return Value(_content.GetProperty()->GetDivision());
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
		_content.GetProperty()->SetDivision(division);
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
				_content.GetFormat(), _content.GetTrackOwner().size(),
				_content.GetProperty()->GetDivision());
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.content
//-----------------------------------------------------------------------------
// midi.content#read(stream:stream:r):map:reduce
Gura_DeclareMethod(content, read)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementMethod(content, read)
{
	Object_content *pThis = Object_content::GetThisObj(args);
	if (!pThis->GetContent().Read(env, sig, args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

// midi.content#write(stream:stream:w):map:reduce
Gura_DeclareMethod(content, write)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
}

Gura_ImplementMethod(content, write)
{
	Object_content *pThis = Object_content::GetThisObj(args);
	if (!pThis->GetContent().Write(env, sig, args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

// midi.content#play(port:midi.port, speed?:number):reduce
Gura_DeclareMethod(content, play)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "port", VTYPE_port);
	DeclareArg(env, "speed", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(content, play)
{
	Content &content = Object_content::GetThisObj(args)->GetContent();
	Port *pPort = Object_port::GetObject(args, 0)->GetPort();
	double speed = args.GetDouble(1);
	content.Play(sig, pPort, speed);
	return args.GetThis();
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
		size_t n = index - trackOwner.size() + 1;
		while (n-- > 0) {
			trackOwner.push_back(new Track(Property::Reference(
									pThis->GetContent().GetProperty())));
		}
	}
	Track *pTrack = trackOwner[index];
	return ReturnValue(env, sig, args,
				Value(new Object_track(env, Track::Reference(pTrack))));
}

// midi.content#mml(text+:string):reduce
Gura_DeclareMethod(content, mml)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "text", VTYPE_string, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(content, mml)
{
	Object_content *pThis = Object_content::GetThisObj(args);
	pThis->GetContent().ParseMML(sig, args.GetList(0));
	return args.GetThis();
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
	Gura_AssignMethod(content, mml);
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
// midi.port#send(msg+:number):map:reduce
Gura_DeclareMethod(port, send)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
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
	return args.GetThis();
}

// midi.port#play(content:midi.content, speed?:number):map:reduce
Gura_DeclareMethod(port, play)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "content", VTYPE_content);
	DeclareArg(env, "speed", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(port, play)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	Content &content = Object_content::GetObject(args, 0)->GetContent();
	double speed = args.IsNumber(1)? args.GetDouble(1) : 1;
	content.Play(sig, pThis->GetPort(), speed);
	return args.GetThis();
}

// midi.port#mml(text+:string):reduce
Gura_DeclareMethod(port, mml)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "text", VTYPE_string, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(port, mml)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	Content content;
	content.ParseMML(sig, args.GetList(0));
	double speed = 1;
	content.Play(sig, pThis->GetPort(), speed);
	return args.GetThis();
}

// midi.port#note_off(channel:number, note:number, velocity:number):map:reduce
Gura_DeclareMethod(port, note_off)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "note", VTYPE_number);
	DeclareArg(env, "velocity", VTYPE_number);
}

Gura_ImplementMethod(port, note_off)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char note = args.GetUChar(1);
	unsigned char velocity = args.GetUChar(2);
	pPort->Send(MIDIEvent_NoteOff::Status | channel, note, velocity);
	return args.GetThis();
}

// midi.port#note_on(channel:number, note:number, velocity:number):map:reduce
Gura_DeclareMethod(port, note_on)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "note", VTYPE_number);
	DeclareArg(env, "velocity", VTYPE_number);
}

Gura_ImplementMethod(port, note_on)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char note = args.GetUChar(1);
	unsigned char velocity = args.GetUChar(2);
	pPort->Send(MIDIEvent_NoteOn::Status | channel, note, velocity);
	return args.GetThis();
}

// midi.port#poly_pressure(channel:number, note:number, value:number):map:reduce
Gura_DeclareMethod(port, poly_pressure)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "note", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
}

Gura_ImplementMethod(port, poly_pressure)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char note = args.GetUChar(1);
	unsigned char value = args.GetUChar(2);
	pPort->Send(MIDIEvent_PolyPressure::Status | channel, note, value);
	return args.GetThis();
}

// midi.port#control_change(channel:number, controller:number, value:number):map:reduce
Gura_DeclareMethod(port, control_change)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "controller", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
}

Gura_ImplementMethod(port, control_change)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char controller = args.GetUChar(1);
	unsigned char value = args.GetUChar(2);
	pPort->Send(MIDIEvent_ControlChange::Status | channel, controller, value);
	return args.GetThis();
}

// midi.port#program_change(channel:number, program:number):map:reduce
Gura_DeclareMethod(port, program_change)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "program", VTYPE_number);
}

Gura_ImplementMethod(port, program_change)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char program = args.GetUChar(1);
	pPort->Send(MIDIEvent_ProgramChange::Status | channel, program);
	return args.GetThis();
}

// midi.port#channel_pressure(channel:number, pressure:number):map:reduce
Gura_DeclareMethod(port, channel_pressure)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "pressure", VTYPE_number);
}

Gura_ImplementMethod(port, channel_pressure)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned char pressure = args.GetUChar(1);
	pPort->Send(MIDIEvent_ChannelPressure::Status | channel, pressure);
	return args.GetThis();
}

// midi.port#pitch_bend(channel:number, value:number):map:reduce
Gura_DeclareMethod(port, pitch_bend)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
}

Gura_ImplementMethod(port, pitch_bend)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	unsigned char channel = args.GetUChar(0) & 0x0f;
	unsigned short value = args.GetUShort(1);
	pPort->Send(MIDIEvent_PitchBend::Status | channel,
			static_cast<unsigned char>((value >> 0) & 0x7f),
			static_cast<unsigned char>((value >> 7) & 0x7f));
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Class implementation for midi.port
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(port)
{
	Gura_AssignMethod(port, send);
	Gura_AssignMethod(port, play);
	Gura_AssignMethod(port, mml);
	Gura_AssignMethod(port, note_off);
	Gura_AssignMethod(port, note_on);
	Gura_AssignMethod(port, poly_pressure);
	Gura_AssignMethod(port, control_change);
	Gura_AssignMethod(port, program_change);
	Gura_AssignMethod(port, channel_pressure);
	Gura_AssignMethod(port, pitch_bend);
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
						Iterator(false), _idxTrack(0), _pTrackOwner(pTrackOwner)
{
}

Iterator *Iterator_track::GetSource()
{
	return NULL;
}

bool Iterator_track::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idxTrack < _pTrackOwner->size()) {
		Track *pTrack = (*_pTrackOwner)[_idxTrack++];
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
// Iterator_eventAll
//-----------------------------------------------------------------------------
Iterator_eventAll::Iterator_eventAll(TrackOwner *pTrackOwner) :
		Iterator(false), _idxTrack(0), _idxEvent(0), _pTrackOwner(pTrackOwner)
{
}

Iterator *Iterator_eventAll::GetSource()
{
	return NULL;
}

bool Iterator_eventAll::DoNext(Environment &env, Signal sig, Value &value)
{
	for ( ; _idxTrack < _pTrackOwner->size(); _idxTrack++) {
		Track *pTrack = (*_pTrackOwner)[_idxTrack];
		const EventOwner &eventOwner = pTrack->GetEventOwner();
		if (_idxEvent < eventOwner.size()) {
			Event *pEvent = eventOwner[_idxEvent++];
			value = Value(new Object_event(env, Event::Reference(pEvent)));
			return true;
		}
	}
	return false;
}

String Iterator_eventAll::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:midi.event_all";
	rtn += ">";
	return rtn;
}

void Iterator_eventAll::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_event
//-----------------------------------------------------------------------------
Iterator_event::Iterator_event(EventOwner *pEventOwner) :
						Iterator(false), _idxEvent(0), _pEventOwner(pEventOwner)
{
}

Iterator *Iterator_event::GetSource()
{
	return NULL;
}

bool Iterator_event::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idxEvent < _pEventOwner->size()) {
		Event *pEvent = (*_pEventOwner)[_idxEvent++];
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
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(midi);
	Gura_RealizeUserSymbol(sysex);
	Gura_RealizeUserSymbol(meta);
	Gura_RealizeUserSymbol(timestamp);
	Gura_RealizeUserSymbol(status);
	Gura_RealizeUserSymbol(name);
	Gura_RealizeUserSymbol(symbol);
	Gura_RealizeUserSymbol(args);
	Gura_RealizeUserSymbol(format);
	Gura_RealizeUserSymbol(division);
	Gura_RealizeUserSymbol(tracks);
	Gura_RealizeUserSymbol(events);
	Gura_RealizeUserSymbol(channel);
	Gura_RealizeUserSymbol(note);
	Gura_RealizeUserSymbol(velocity);
	Gura_RealizeUserSymbol(value);
	Gura_RealizeUserSymbol(controller);
	Gura_RealizeUserSymbol(program);
	Gura_RealizeUserSymbol(pressure);
	Gura_RealizeUserSymbol(binary);
	Gura_RealizeUserSymbol(number);
	Gura_RealizeUserSymbol(text);
	Gura_RealizeUserSymbol(mpqn);
	Gura_RealizeUserSymbol(hour);
	Gura_RealizeUserSymbol(minute);
	Gura_RealizeUserSymbol(second);
	Gura_RealizeUserSymbol(frame);
	Gura_RealizeUserSymbol(subFrame);
	Gura_RealizeUserSymbol(numerator);
	Gura_RealizeUserSymbol(denominator);
	Gura_RealizeUserSymbol(metronome);
	Gura_RealizeUserSymbol(cnt32nd);
	Gura_RealizeUserSymbol(key);
	Gura_RealizeUserSymbol(scale);
	Gura_RealizeUserSymbol(note_off);
	Gura_RealizeUserSymbol(note_on);
	Gura_RealizeUserSymbol(poly_pressure);
	Gura_RealizeUserSymbol(control_change);
	Gura_RealizeUserSymbol(program_change);
	Gura_RealizeUserSymbol(channel_pressure);
	Gura_RealizeUserSymbol(pitch_bend);
	Gura_RealizeUserSymbol(sys_ex_event);
	Gura_RealizeUserSymbol(unknown);
	Gura_RealizeUserSymbol(sequence_number);
	Gura_RealizeUserSymbol(text_event);
	Gura_RealizeUserSymbol(copyright_notice);
	Gura_RealizeUserSymbol(sequence_or_track_name);
	Gura_RealizeUserSymbol(instrument_name);
	Gura_RealizeUserSymbol(lyric_text);
	Gura_RealizeUserSymbol(marker_text);
	Gura_RealizeUserSymbol(cue_point);
	Gura_RealizeUserSymbol(midi_channel_prefix_assignment);
	Gura_RealizeUserSymbol(end_of_track);
	Gura_RealizeUserSymbol(tempo_setting);
	Gura_RealizeUserSymbol(smpte_offset);
	Gura_RealizeUserSymbol(time_signature);
	Gura_RealizeUserSymbol(key_signature);
	Gura_RealizeUserSymbol(sequencer_specific_event);
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
	// value assignment
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		valList.reserve(ArraySizeOf(g_controllerInfos));
		for (size_t i = 0; i < ArraySizeOf(g_controllerInfos); i++) {
			ControllerInfo &controllerInfo = g_controllerInfos[i];
			if (controllerInfo.name == NULL) {
				valList.push_back(Value::Null);
			} else {
				controllerInfo.pSymbol = Symbol::Add(controllerInfo.name);
				valList.push_back(Value(controllerInfo.pSymbol));
			}
		}
		Gura_AssignValue(controllers, value);
	} while (0);
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		valList.reserve(ArraySizeOf(g_programInfos));
		for (size_t i = 0; i < ArraySizeOf(g_programInfos); i++) {
			ProgramInfo &programInfo = g_programInfos[i];
			programInfo.pSymbol = Symbol::Add(programInfo.name);
			valList.push_back(Value(programInfo.pSymbol));
		}
		Gura_AssignValue(programs, value);
	} while (0);
	// function assignment
	Gura_AssignFunction(content);
	Gura_AssignFunction(port);
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
int NameToController(const char *name)
{
	for (int i = 0; i < ArraySizeOf(g_controllerInfos); i++) {
		if (::strcasecmp(g_controllerInfos[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

int SymbolToController(const Symbol *pSymbol)
{
	for (int i = 0; i < ArraySizeOf(g_controllerInfos); i++) {
		if (g_controllerInfos[i].pSymbol != NULL &&
					g_controllerInfos[i].pSymbol->IsIdentical(pSymbol)) {
			return i;
		}
	}
	return -1;
}

const char *ControllerToName(int controller)
{
	if (0 <= controller && controller < ArraySizeOf(g_controllerInfos)) {
		return g_controllerInfos[controller].name;
	}
	return NULL;
}

const Symbol *ControllerToSymbol(int controller)
{
	if (0 <= controller && controller < ArraySizeOf(g_controllerInfos)) {
		return g_controllerInfos[controller].pSymbol;
	}
	return NULL;
}

int SymbolToProgram(const Symbol *pSymbol)
{
	for (int i = 0; i < ArraySizeOf(g_programInfos); i++) {
		if (g_programInfos[i].pSymbol != NULL &&
					g_programInfos[i].pSymbol->IsIdentical(pSymbol)) {
			return i;
		}
	}
	return -1;
}

int NameToProgram(const char *name)
{
	for (int i = 0; i < ArraySizeOf(g_programInfos); i++) {
		if (::strcasecmp(g_programInfos[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

const char *ProgramToName(int program)
{
	if (0 <= program && program < ArraySizeOf(g_programInfos)) {
		return g_programInfos[program].name;
	}
	return NULL;
}

Gura_EndModule(midi, midi)

Gura_RegisterModule(midi)
