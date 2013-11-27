//-----------------------------------------------------------------------------
// Gura midi module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(midi)

Value ActivatePlayer(Environment &env, Signal sig, Args &args,
				Sequence &sequence, Port *pPort, double speed, int cntRepeat);

//-----------------------------------------------------------------------------
// information table
//-----------------------------------------------------------------------------
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
	// Piano
	{ "acoustic_piano",				"Acoustic Piano",			NULL }, // 0
	{ "bright_piano",				"Bright Piano",				NULL }, // 1
	{ "electric_grand_piano",		"Electric Grand Piano",		NULL }, // 2
	{ "honky_tonk_piano",			"Honky-tonk Piano",			NULL }, // 3
	{ "electric_piano",				"Electric Piano",			NULL }, // 4
	{ "electric_piano_2",			"Electric Piano 2",			NULL }, // 5
	{ "harpsichord",				"Harpsichord",				NULL }, // 6
	{ "clavi",						"Clavi",					NULL }, // 7
	// Chromatic Percussion
	{ "celesta",					"Celesta",					NULL }, // 8
	{ "glockenspiel",				"Glockenspiel",				NULL }, // 9
	{ "musical_box",				"Musical box",				NULL }, // 10
	{ "vibraphone",					"Vibraphone",				NULL }, // 11
	{ "marimba",					"Marimba",					NULL }, // 12
	{ "xylophone",					"Xylophone",				NULL }, // 13
	{ "tubular_bell",				"Tubular Bell",				NULL }, // 14
	{ "dulcimer",					"Dulcimer",					NULL }, // 15
	// Organ
	{ "drawbar_organ",				"Drawbar Organ",			NULL }, // 16
	{ "percussive_organ",			"Percussive Organ",			NULL }, // 17
	{ "rock_organ",					"Rock Organ",				NULL }, // 18
	{ "church_organ",				"Church organ",				NULL }, // 19
	{ "reed_organ",					"Reed organ",				NULL }, // 20
	{ "accordion",					"Accordion",				NULL }, // 21
	{ "harmonica",					"Harmonica",				NULL }, // 22
	{ "tango_accordion",			"Tango Accordion",			NULL }, // 23
	// Guitar
	{ "acoustic_guitar_nylon",		"Acoustic Guitar (nylon)",	NULL }, // 24
	{ "acoustic_guitar_steel",		"Acoustic Guitar (steel)",	NULL }, // 25
	{ "electric_guitar_jazz",		"Electric Guitar (jazz)",	NULL }, // 26
	{ "electric_guitar_clean",		"Electric Guitar (clean)",	NULL }, // 27
	{ "electric_guitar_muted",		"Electric Guitar (muted)",	NULL }, // 28
	{ "overdriven_guitar",			"Overdriven Guitar",		NULL }, // 29
	{ "distortion_guitar",			"Distortion Guitar",		NULL }, // 30
	{ "guitar_harmonics",			"Guitar harmonics",			NULL }, // 31
	// Bass
	{ "acoustic_bass",				"Acoustic Bass",			NULL }, // 32
	{ "electric_bass_finger",		"Electric Bass (finger)",	NULL }, // 33
	{ "electric_bass_pick",			"Electric Bass (pick)",		NULL }, // 34
	{ "fretless_bass",				"Fretless Bass",			NULL }, // 35
	{ "slap_bass_1",				"Slap Bass 1",				NULL }, // 36
	{ "slap_bass_2",				"Slap Bass 2",				NULL }, // 37
	{ "synth_bass_1",				"Synth Bass 1",				NULL }, // 38
	{ "synth_bass_2",				"Synth Bass 2",				NULL }, // 39
	// Strings
	{ "violin",						"Violin",					NULL }, // 40
	{ "viola",						"Viola",					NULL }, // 41
	{ "cello",						"Cello",					NULL }, // 42
	{ "double_bass",				"Double bass",				NULL }, // 43
	{ "tremolo_strings",			"Tremolo Strings",			NULL }, // 44
	{ "pizzicato_strings",			"Pizzicato Strings",		NULL }, // 45
	{ "orchestral_harp",			"Orchestral Harp",			NULL }, // 46
	{ "timpani",					"Timpani",					NULL }, // 47
	// Ensemble
	{ "string_ensemble_1",			"String Ensemble 1",		NULL }, // 48
	{ "string_ensemble_2",			"String Ensemble 2",		NULL }, // 49
	{ "synth_strings_1",			"Synth Strings 1",			NULL }, // 50
	{ "synth_strings_2",			"Synth Strings 2",			NULL }, // 51
	{ "voice_aahs",					"Voice Aahs",				NULL }, // 52
	{ "voice_oohs",					"Voice Oohs",				NULL }, // 53
	{ "synth_voice",				"Synth Voice",				NULL }, // 54
	{ "orchestra_hit",				"Orchestra Hit",			NULL }, // 55
	// Brass
	{ "trumpet",					"Trumpet",					NULL }, // 56
	{ "trombone",					"Trombone",					NULL }, // 57
	{ "tuba",						"Tuba",						NULL }, // 58
	{ "muted_trumpet",				"Muted Trumpet",			NULL }, // 59
	{ "french_horn",				"French horn",				NULL }, // 60
	{ "brass_section",				"Brass Section",			NULL }, // 61
	{ "synth_brass_1",				"Synth Brass 1",			NULL }, // 62
	{ "synth_brass_2",				"Synth Brass 2",			NULL }, // 63
	// Reed
	{ "soprano_sax",				"Soprano Sax",				NULL }, // 64
	{ "alto_sax",					"Alto Sax",					NULL }, // 65
	{ "tenor_sax",					"Tenor Sax",				NULL }, // 66
	{ "baritone_sax",				"Baritone Sax",				NULL }, // 67
	{ "oboe",						"Oboe",						NULL }, // 68
	{ "english_horn",				"English Horn",				NULL }, // 69
	{ "bassoon",					"Bassoon",					NULL }, // 70
	{ "clarinet",					"Clarinet",					NULL }, // 71
	// Pipe
	{ "piccolo",					"Piccolo",					NULL }, // 72
	{ "flute",						"Flute",					NULL }, // 73
	{ "recorder",					"Recorder",					NULL }, // 74
	{ "pan_flute",					"Pan Flute",				NULL }, // 75
	{ "blown_bottle",				"Blown Bottle",				NULL }, // 76
	{ "shakuhachi",					"Shakuhachi",				NULL }, // 77
	{ "whistle",					"Whistle",					NULL }, // 78
	{ "ocarina",					"Ocarina",					NULL }, // 79
	// Synth Lead
	{ "lead_1_square",				"Lead 1 (square)",			NULL }, // 80
	{ "lead_2_sawtooth",			"Lead 2 (sawtooth)",		NULL }, // 81
	{ "lead_3_calliope",			"Lead 3 (calliope)",		NULL }, // 82
	{ "lead_4_chiff",				"Lead 4 (chiff)",			NULL }, // 83
	{ "lead_5_charang",				"Lead 5 (charang)",			NULL }, // 84
	{ "lead_6_voice",				"Lead 6 (voice)",			NULL }, // 85
	{ "lead_7_fifths",				"Lead 7 (fifths)",			NULL }, // 86
	{ "lead_8_bass_lead",			"Lead 8 (bass + lead)",		NULL }, // 87
	// Synth Pad
	{ "pad_1_fantasia",				"Pad 1 (Fantasia)",			NULL }, // 88
	{ "pad_2_warm",					"Pad 2 (warm)",				NULL }, // 89
	{ "pad_3_polysynth",			"Pad 3 (polysynth)",		NULL }, // 90
	{ "pad_4_choir",				"Pad 4 (choir)",			NULL }, // 91
	{ "pad_5_bowed",				"Pad 5 (bowed)",			NULL }, // 92
	{ "pad_6_metallic",				"Pad 6 (metallic)",			NULL }, // 93
	{ "pad_7_halo",					"Pad 7 (halo)",				NULL }, // 94
	{ "pad_8_sweep",				"Pad 8 (sweep)",			NULL }, // 95
	// Synth Effects
	{ "fx_1_rain",					"FX 1 (rain)",				NULL }, // 96
	{ "fx_2_soundtrack",			"FX 2 (soundtrack)",		NULL }, // 97
	{ "fx_3_crystal",				"FX 3 (crystal)",			NULL }, // 98
	{ "fx_4_atmosphere",			"FX 4 (atmosphere)",		NULL }, // 99
	{ "fx_5_brightness",			"FX 5 (brightness)",		NULL }, // 100
	{ "fx_6_goblins",				"FX 6 (goblins)",			NULL }, // 101
	{ "fx_7_echoes",				"FX 7 (echoes)",			NULL }, // 102
	{ "fx_8_sci_fi",				"FX 8 (sci-fi)",			NULL }, // 103
	// Ethnic
	{ "sitar",						"Sitar",					NULL }, // 104
	{ "banjo",						"Banjo",					NULL }, // 105
	{ "shamisen",					"Shamisen",					NULL }, // 106
	{ "koto",						"Koto",						NULL }, // 107
	{ "kalimba",					"Kalimba",					NULL }, // 108
	{ "bagpipe",					"Bagpipe",					NULL }, // 109
	{ "fiddle",						"Fiddle",					NULL }, // 110
	{ "shanai",						"Shanai",					NULL }, // 111
	// Percussive
	{ "tinkle_bell",				"Tinkle Bell",				NULL }, // 112
	{ "agogo",						"Agogo",					NULL }, // 113
	{ "steel_drums",				"Steel Drums",				NULL }, // 114
	{ "woodblock",					"Woodblock",				NULL }, // 115
	{ "taiko_drum",					"Taiko Drum",				NULL }, // 116
	{ "melodic_tom",				"Melodic Tom",				NULL }, // 117
	{ "synth_drum",					"Synth Drum",				NULL }, // 118
	{ "reverse_cymbal",				"Reverse Cymbal",			NULL }, // 119
	// Sound effects
	{ "guitar_fret_noise",			"Guitar Fret Noise",		NULL }, // 120
	{ "breath_noise",				"Breath Noise",				NULL }, // 121
	{ "seashore",					"Seashore",					NULL }, // 122
	{ "bird_tweet",					"Bird Tweet",				NULL }, // 123
	{ "telephone_ring",				"Telephone Ring",			NULL }, // 124
	{ "helicopter",					"Helicopter",				NULL }, // 125
	{ "applause",					"Applause",					NULL }, // 126
	{ "gunshot",					"Gunshot",					NULL }, // 127
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
	return true;
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

String Object_event::ToString(bool exprFlag)
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
		Iterator *pIterator = new Iterator_event(_pTrack->GetEventOwner().Reference());
		return Value(new Object_iterator(env, pIterator));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_track::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<midi.track";
	do {
		char buff[64];
		::sprintf(buff, ":%devents:seek%ld",
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Moves the insertion point in the track at which the next event is inserted.\n"
	"If `origin` is omitted or set to `` `set``, the insertion point will be set to absolute offset from the beginning.\n"
	"If `origin` is set to `` `cur``, the insertion point will be moved by offset from the current position.\n"
	);
}

Gura_ImplementMethod(track, seek)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	if (!args.Is_symbol(1)) {
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns the current insertion point in the track.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Deletes an event at the current insertion point in the track.\n"
	"The argument `n` specifies the number of events to be deleted.\n"
	"If `n` is omitted, one event will be deleted.\n"
	);
}

Gura_ImplementMethod(track, erase)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	size_t cnt = args.Is_number(0)? args.GetSizeT(0) : 1;
	if (!pTrack->Erase(sig, cnt)) return Value::Null;
	return args.GetThis();
}

// midi.track#mml(str:string, max_velocity?:number):map:reduce
Gura_DeclareMethod(track, mml)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "max_velocity", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Parses MML in the string `str` and inserts resulted MIDI events at the current insertion point in the track.\n"
	"\n"
	"The argument `max_velocity` specifies the maximum number of velocity in the MML.\n"
	"If omitted, it will be set to 127.\n"
	);
}

Gura_ImplementMethod(track, mml)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	int velocityMax = args.Is_number(1)? args.GetInt(1) : 127;
	MML mml(velocityMax);
	if (mml.ParseString(sig, pTrack, args.GetString(0)) == MML::RSLT_Error) {
		return Value::Null;
	}
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, note_off)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar note = args.GetUChar(1);
	UChar velocity = args.GetUChar(2);
	ULong deltaTime = args.Is_number(3)? args.GetULong(3) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, note_on)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar note = args.GetUChar(1);
	UChar velocity = args.GetUChar(2);
	ULong deltaTime = args.Is_number(3)? args.GetULong(3) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, poly_pressure)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar note = args.GetUChar(1);
	UChar value = args.GetUChar(2);
	ULong deltaTime = args.Is_number(3)? args.GetULong(3) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, control_change)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar controller = 0;
	if (args.Is_number(1)) {
		controller = args.GetUChar(1);
	} else if (args.Is_symbol(1)) {
		int n = ControllerIdBySymbol(args.GetSymbol(1));
		if (n < 0) {
			sig.SetError(ERR_TypeError, "invalid controller name '%s'",
											args.GetSymbol(1)->GetName());
			return Value::Null;
		}
		controller = static_cast<UChar>(n);
	} else {
		sig.SetError(ERR_TypeError, "controller must be specified by number or symbol");
		return Value::Null;
	}
	UChar value = args.GetUChar(2);
	ULong deltaTime = args.Is_number(3)? args.GetULong(3) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, program_change)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar program = 0;
	if (args.Is_number(1)) {
		program = args.GetUChar(1);
	} else if (args.Is_symbol(1)) {
		int n = ProgramIdBySymbol(args.GetSymbol(1));
		if (n < 0) {
			sig.SetError(ERR_TypeError, "invalid program name '%s'",
											args.GetSymbol(1)->GetName());
			return Value::Null;
		}
		program = static_cast<UChar>(n);
	} else {
		sig.SetError(ERR_TypeError, "program must be specified by number or symbol");
		return Value::Null;
	}
	ULong deltaTime = args.Is_number(2)? args.GetULong(2) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, channel_pressure)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar pressure = args.GetUChar(1);
	ULong deltaTime = args.Is_number(2)? args.GetULong(2) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, pitch_bend)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar channel = args.GetUChar(0) & 0x0f;
	UShort value = args.GetUShort(1);
	ULong deltaTime = args.Is_number(2)? args.GetULong(2) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, sequence_number)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, text_event)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, copyright_notice)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, sequence_or_track_name)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, instrument_name)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, lyric_text)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, marker_text)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, cue_point)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, midi_channel_prefix_assignment)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar channel = args.GetUChar(0);
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
	AutoPtr<Event> pEvent(new MetaEvent_MIDIChannelPrefixAssignment(0, channel));
	pTrack->AddEvent(pEvent.release(), deltaTime);
	return args.GetThis();
}

// midi.track#end_of_track(deltaTime?:number):map:reduce
Gura_DeclareMethod(track, end_of_track)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "deltaTime", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, end_of_track)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong deltaTime = args.Is_number(0)? args.GetULong(0) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, tempo_setting)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	ULong mpqn = args.GetULong(0);
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, smpte_offset)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar hour = args.GetUChar(0);
	UChar minute = args.GetUChar(1);
	UChar second = args.GetUChar(2);
	UChar frame = args.GetUChar(3);
	UChar subFrame = args.GetUChar(4);
	ULong deltaTime = args.Is_number(5)? args.GetULong(5) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, time_signature)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar numerator = args.GetUChar(0);
	UChar denominator = args.GetUChar(1);
	UChar metronome = args.GetUChar(2);
	UChar cnt32nd = args.GetUChar(3);
	ULong deltaTime = args.Is_number(4)? args.GetULong(4) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, key_signature)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	UChar key = args.GetUChar(0);
	UChar scale = args.GetUChar(1);
	ULong deltaTime = args.Is_number(2)? args.GetULong(2) : 0;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(track, sequencer_specific_event)
{
	Track *pTrack = Object_track::GetThisObj(args)->GetTrack();
	const Binary &binary = args.GetBinary(0);
	ULong deltaTime = args.Is_number(1)? args.GetULong(1) : 0;
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
// Object_sequence
//-----------------------------------------------------------------------------
Object *Object_sequence::Clone() const
{
	return NULL;
}

bool Object_sequence::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(format));
	symbols.insert(Gura_UserSymbol(tracks));
	symbols.insert(Gura_UserSymbol(division));
	return true;
}

Value Object_sequence::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		return Value(_sequence.GetFormat());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(tracks))) {
		Iterator *pIterator =
				new Iterator_track(_sequence.GetTrackOwner().Reference());
		return Value(new Object_iterator(env, pIterator));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(events))) {
		Iterator *pIterator =
				new Iterator_eventAll(_sequence.GetTrackOwner().Reference());
		return Value(new Object_iterator(env, pIterator));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(division))) {
		return Value(_sequence.GetProperty()->GetDivision());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_sequence::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		UShort format = value.GetUShort();
		if (format > 2) {
			sig.SetError(ERR_ValueError, "wrong number for format");
			return Value::Null;
		}
		_sequence.SetFormat(format);
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(division))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		UShort division = value.GetUShort();
		_sequence.GetProperty()->SetDivision(division);
		return value;
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_sequence::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<midi.sequence";
	do {
		char buff[128];
		::sprintf(buff, ":format=%d:tracks=%d:division=%d",
				_sequence.GetFormat(), _sequence.GetTrackOwner().size(),
				_sequence.GetProperty()->GetDivision());
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.sequence
//-----------------------------------------------------------------------------
// midi.sequence#read(stream:stream:r):map:reduce
Gura_DeclareMethod(sequence, read)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(sequence, read)
{
	Object_sequence *pThis = Object_sequence::GetThisObj(args);
	if (!pThis->GetSequence().Read(env, sig, args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

// midi.sequence#write(stream:stream:w):map:reduce
Gura_DeclareMethod(sequence, write)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(sequence, write)
{
	Object_sequence *pThis = Object_sequence::GetThisObj(args);
	if (!pThis->GetSequence().Write(env, sig, args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

// midi.sequence#play(port:midi.port, speed?:number, repeat:number:nil => 1):[background,player]
Gura_DeclareMethod(sequence, play)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "port", VTYPE_port);
	DeclareArg(env, "speed", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "repeat", VTYPE_number, OCCUR_Once,
								FLAG_Nil, new Expr_Value(Value(1)));
	DeclareAttr(Gura_UserSymbol(background));
	DeclareAttr(Gura_UserSymbol(player));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(sequence, play)
{
	Sequence &sequence = Object_sequence::GetThisObj(args)->GetSequence();
	Port *pPort = Object_port::GetObject(args, 0)->GetPort();
	double speed = args.Is_number(1)? args.GetDouble(1) : 1;
	int cntRepeat = args.Is_number(2)? args.GetInt(2) : -1;
	return ActivatePlayer(env, sig, args, sequence, pPort, speed, cntRepeat);
}

// midi.sequence#track(index:number):map {block?}
Gura_DeclareMethod(sequence, track)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(sequence, track)
{
	Object_sequence *pThis = Object_sequence::GetThisObj(args);
	size_t index = args.GetSizeT(0);
	TrackOwner &trackOwner = pThis->GetSequence().GetTrackOwner();
	if (index >= trackOwner.size()) {
		size_t n = index - trackOwner.size() + 1;
		while (n-- > 0) {
			trackOwner.push_back(new Track(Property::Reference(
									pThis->GetSequence().GetProperty())));
		}
	}
	Track *pTrack = trackOwner[index];
	return ReturnValue(env, sig, args,
				Value(new Object_track(env, Track::Reference(pTrack))));
}

// midi.sequence#mml(str:string, max_velocity?:number):reduce
Gura_DeclareMethod(sequence, mml)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "max_velocity", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(sequence, mml)
{
	Object_sequence *pThis = Object_sequence::GetThisObj(args);
	int velocityMax = args.Is_number(1)? args.GetInt(1) : 127;
	MML mml(velocityMax);
	if (!mml.ParseString(sig, pThis->GetSequence(), args.GetString(0))) return Value::Null;
	return args.GetThis();
}

// midi.sequence#readmml(stream:stream, max_velocity?:number):reduce
Gura_DeclareMethod(sequence, readmml)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareArg(env, "max_velocity", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(sequence, readmml)
{
	Object_sequence *pThis = Object_sequence::GetThisObj(args);
	int velocityMax = args.Is_number(1)? args.GetInt(1) : 127;
	MML mml(velocityMax);
	if (!mml.ParseStream(sig, pThis->GetSequence(), args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Class implementation for midi.sequence
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(sequence)
{
	Gura_AssignMethod(sequence, read);
	Gura_AssignMethod(sequence, write);
	Gura_AssignMethod(sequence, play);
	Gura_AssignMethod(sequence, track);
	Gura_AssignMethod(sequence, mml);
	Gura_AssignMethod(sequence, readmml);
}

Gura_ImplementCastFrom(sequence)
{
	Value valueCast(value);
	env.LookupClass(VTYPE_stream)->CastFrom(env, sig, valueCast, pDecl);
	if (valueCast.Is_stream()) {
		AutoPtr<Object_sequence> pObj(new Object_sequence(env));
		pObj->GetSequence().Read(env, sig, valueCast.GetStream());
		valueCast = Value::Null; // delete stream instance
		if (sig.IsSignalled()) return false;
		value = Value(pObj.release());
		return true;
	}
	return false;
}

Gura_ImplementCastTo(sequence)
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

String Object_portinfo::ToString(bool exprFlag)
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

String Object_port::ToString(bool exprFlag)
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
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

// midi.port#play(sequence:midi.sequence, speed?:number, repeat:number:nil => 1):map:[background,player]
Gura_DeclareMethod(port, play)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sequence", VTYPE_sequence);
	DeclareArg(env, "speed", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "repeat", VTYPE_number, OCCUR_Once,
								FLAG_Nil, new Expr_Value(Value(1)));
	DeclareAttr(Gura_UserSymbol(background));
	DeclareAttr(Gura_UserSymbol(player));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, play)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	Sequence &sequence = Object_sequence::GetObject(args, 0)->GetSequence();
	double speed = args.Is_number(1)? args.GetDouble(1) : 1;
	int cntRepeat = args.Is_number(2)? args.GetInt(2) : -1;
	return ActivatePlayer(env, sig, args, sequence, pThis->GetPort(), speed, cntRepeat);
}

// midi.port#mml(str:string, max_velocity?:number):[background,player]
Gura_DeclareMethod(port, mml)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "max_velocity", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_UserSymbol(background));
	DeclareAttr(Gura_UserSymbol(player));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, mml)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	Sequence sequence;
	int velocityMax = args.Is_number(1)? args.GetInt(1) : 127;
	MML mml(velocityMax);
	if (!mml.ParseString(sig, sequence, args.GetString(0))) return Value::Null;
	double speed = 1;
	int cntRepeat = 1;
	return ActivatePlayer(env, sig, args, sequence, pThis->GetPort(), speed, cntRepeat);
}

// midi.port#readmml(stream:stream, max_velocity?:number):[background,player]
Gura_DeclareMethod(port, readmml)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareArg(env, "max_velocity", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_UserSymbol(background));
	DeclareAttr(Gura_UserSymbol(player));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, readmml)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	Sequence sequence;
	int velocityMax = args.Is_number(1)? args.GetInt(1) : 127;
	MML mml(velocityMax);
	if (!mml.ParseStream(sig, sequence, args.GetStream(0))) return Value::Null;
	double speed = 1;
	int cntRepeat = 1;
	return ActivatePlayer(env, sig, args, sequence, pThis->GetPort(), speed, cntRepeat);
}

// midi.port#note_off(channel:number, note:number, velocity:number):map:reduce
Gura_DeclareMethod(port, note_off)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "note", VTYPE_number);
	DeclareArg(env, "velocity", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, note_off)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar note = args.GetUChar(1);
	UChar velocity = args.GetUChar(2);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, note_on)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar note = args.GetUChar(1);
	UChar velocity = args.GetUChar(2);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, poly_pressure)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar note = args.GetUChar(1);
	UChar value = args.GetUChar(2);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, control_change)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar controller = args.GetUChar(1);
	UChar value = args.GetUChar(2);
	pPort->Send(MIDIEvent_ControlChange::Status | channel, controller, value);
	return args.GetThis();
}

// midi.port#program_change(channel:number, program:number):map:reduce
Gura_DeclareMethod(port, program_change)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "program", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, program_change)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar program = args.GetUChar(1);
	pPort->Send(MIDIEvent_ProgramChange::Status | channel, program);
	return args.GetThis();
}

// midi.port#channel_pressure(channel:number, pressure:number):map:reduce
Gura_DeclareMethod(port, channel_pressure)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "pressure", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, channel_pressure)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	UChar channel = args.GetUChar(0) & 0x0f;
	UChar pressure = args.GetUChar(1);
	pPort->Send(MIDIEvent_ChannelPressure::Status | channel, pressure);
	return args.GetThis();
}

// midi.port#pitch_bend(channel:number, value:number):map:reduce
Gura_DeclareMethod(port, pitch_bend)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "value", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(port, pitch_bend)
{
	Port *pPort = Object_port::GetThisObj(args)->GetPort();
	UChar channel = args.GetUChar(0) & 0x0f;
	UShort value = args.GetUShort(1);
	pPort->Send(MIDIEvent_PitchBend::Status | channel,
			static_cast<UChar>((value >> 0) & 0x7f),
			static_cast<UChar>((value >> 7) & 0x7f));
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
	Gura_AssignMethod(port, readmml);
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
	if (value.Is_number()) {
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
// Object_player
//-----------------------------------------------------------------------------
Object *Object_player::Clone() const
{
	return NULL;
}

bool Object_player::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(speed));
	symbols.insert(Gura_UserSymbol(count));
	symbols.insert(Gura_UserSymbol(repeat));
	symbols.insert(Gura_UserSymbol(progress));
	return true;
}

Value Object_player::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(speed))) {
		return Value(_pPlayer->GetSpeed());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(count))) {
		return Value(_pPlayer->CountEvents());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(repeat))) {
		return Value(_pPlayer->GetRepeat());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(progress))) {
		return Value(_pPlayer->GetProgress());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_player::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(speed))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		double speed = value.GetDouble();
		if (speed <= 0) {
			sig.SetError(ERR_ValueError, "nuber of speed must be more than zero");
			return Value::Null;
		}
		_pPlayer->SetSpeed(speed);
		return value;
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_player::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<midi.player";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.player
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for midi.player
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(player)
{
}

//-----------------------------------------------------------------------------
// Object_controller
//-----------------------------------------------------------------------------
Object *Object_controller::Clone() const
{
	return NULL;
}

bool Object_controller::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(id));
	symbols.insert(Gura_UserSymbol(name));
	return true;
}

Value Object_controller::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(id))) {
		return Value(_controller);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(name))) {
		return Value(env, GetControllerInfo().name);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_controller::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<midi.controller:";
	rtn += GetControllerInfo().name;
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.controller
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for midi.controller
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(controller)
{
}

//-----------------------------------------------------------------------------
// Object_program
//-----------------------------------------------------------------------------
Object *Object_program::Clone() const
{
	return NULL;
}

bool Object_program::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(id));
	symbols.insert(Gura_UserSymbol(name));
	symbols.insert(Gura_UserSymbol(dispname));
	return true;
}

Value Object_program::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(id))) {
		return Value(_program);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(name))) {
		return Value(env, GetProgramInfo().name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(dispname))) {
		return Value(env, GetProgramInfo().dispName);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_program::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<midi.program:";
	rtn += GetProgramInfo().name;
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.program
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for midi.program
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(program)
{
}

//-----------------------------------------------------------------------------
// Object_soundfont
//-----------------------------------------------------------------------------
Object *Object_soundfont::Clone() const
{
	return NULL;
}

bool Object_soundfont::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
#if 0
	symbols.insert(Gura_UserSymbol(id));
	symbols.insert(Gura_UserSymbol(name));
	symbols.insert(Gura_UserSymbol(dispname));
#endif
	return true;
}

Value Object_soundfont::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(id))) {
		return Value(_soundfont);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(name))) {
		return Value(env, GetProgramInfo().name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(dispname))) {
		return Value(env, GetProgramInfo().dispName);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

String Object_soundfont::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<midi.soundfont";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.soundfont
//-----------------------------------------------------------------------------
// midi.soundfont#synthesizer(preset:number, bank:number, key:number, velocity:number):map {block?}
Gura_DeclareMethod(soundfont, synthesizer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "preset", VTYPE_number);
	DeclareArg(env, "bank", VTYPE_number);
	DeclareArg(env, "key", VTYPE_number);
	DeclareArg(env, "velocity", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(soundfont, synthesizer)
{
	SoundFont &soundFont = Object_soundfont::GetThisObj(args)->GetSoundFont();
	UShort wPreset = args.GetUShort(0);
	UShort wBank = args.GetUShort(1);
	UChar key = args.GetUChar(2);
	UChar velocity = args.GetUChar(3);
	SoundFont::Synthesizer *pSynthesizer =
				soundFont.CreateSynthesizer(sig, wPreset, wBank, key, velocity);
	if (pSynthesizer == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_synthesizer(env, pSynthesizer)));
}

// midi.soundfont#print():void
Gura_DeclareMethod(soundfont, print)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(soundfont, print)
{
	SoundFont &soundFont = Object_soundfont::GetThisObj(args)->GetSoundFont();
	soundFont.Print();
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for midi.soundfont
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(soundfont)
{
	Gura_AssignMethod(soundfont, synthesizer);
	Gura_AssignMethod(soundfont, print);
}

//-----------------------------------------------------------------------------
// Object_synthesizer
//-----------------------------------------------------------------------------
Object *Object_synthesizer::Clone() const
{
	return NULL;
}

bool Object_synthesizer::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(audio));
	return true;
}

Value Object_synthesizer::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(audio))) {
		return Value(new Object_audio(env,
					_pSynthesizer->GetSample()->GetAudio()->Reference()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_synthesizer::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<midi.synthesizer";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for midi.synthesizer
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for midi.synthesizer
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(synthesizer)
{
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

String Iterator_track::ToString() const
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

String Iterator_eventAll::ToString() const
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

String Iterator_event::ToString() const
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
// midi.sequence(stream?:stream) {block?}
Gura_DeclareFunction(sequence)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(sequence));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"It creates an instance that contains SMF information.\n"
	);
}

Gura_ImplementFunction(sequence)
{
	AutoPtr<Object_sequence> pObj(new Object_sequence(env));
	Sequence &sequence = pObj->GetSequence();
	if (args.Is_stream(0)) {
		if (!sequence.Read(env, sig, args.GetStream(0))) return Value::Null;
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"It opens a MIDI port and returns a handle to it.\n"
	);
}

Gura_ImplementFunction(port)
{
	int id = args.Is_number(0)? args.GetInt(0) : 0;
	AutoPtr<Object_port> pObj(new Object_port(env));
	if (!pObj->GetPort()->Open(id)) {
		sig.SetError(ERR_IOError, "can't open MIDI port #%d", id);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// midi.controller(symbol:symbol) {block?}
Gura_DeclareFunction(controller)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(controller));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"It creates a MIDI controller instance.\n"
	);
}

Gura_ImplementFunction(controller)
{
	int controller = ControllerIdBySymbol(args.GetSymbol(0));
	if (controller < 0) {
		sig.SetError(ERR_ValueError, "invalid symbol for midi controller");
		return Value::Null;
	}
	AutoPtr<Object_controller> pObj(new Object_controller(env, controller));
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// midi.program(symbol:symbol) {block?}
Gura_DeclareFunction(program)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(program));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"It creates a MIDI program instance.\n"
	);
}

Gura_ImplementFunction(program)
{
	int program = ProgramIdBySymbol(args.GetSymbol(0));
	if (program < 0) {
		sig.SetError(ERR_ValueError, "invalid symbol for midi program");
		return Value::Null;
	}
	AutoPtr<Object_program> pObj(new Object_program(env, program));
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// midi.soundfont(stream:stream) {block?}
Gura_DeclareFunction(soundfont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(soundfont));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"It creates an instance to access data in SoundFont file.\n"
	);
}

Gura_ImplementFunction(soundfont)
{
	AutoPtr<Object_soundfont> pObj(new Object_soundfont(env, args.GetStream(0).Reference()));
	if (!pObj->GetSoundFont().ReadChunks(env, sig)) return Value::Null;
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
	SoundFont sf(args.GetStream(0).Reference());
	::printf("check\n");
	sf.ReadChunks(env, sig);
	sf.Print();
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
	Gura_RealizeUserSymbol(id);
	Gura_RealizeUserSymbol(name);
	Gura_RealizeUserSymbol(dispname);
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
	Gura_RealizeUserSymbol(background);
	Gura_RealizeUserSymbol(player);
	Gura_RealizeUserSymbol(stream);
	Gura_RealizeUserSymbol(speed);
	Gura_RealizeUserSymbol(count);
	Gura_RealizeUserSymbol(repeat);
	Gura_RealizeUserSymbol(progress);
	Gura_RealizeUserSymbol(audio);
	// class realization
	Gura_RealizeUserClassWithoutPrepare(event, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(track, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(sequence, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(portinfo, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(port, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(player, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(controller, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(program, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(soundfont, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassWithoutPrepare(synthesizer, env.LookupClass(VTYPE_object));
	Gura_UserClass(event)->Prepare(env);
	Gura_UserClass(track)->Prepare(env);
	Gura_UserClass(sequence)->Prepare(env);
	Gura_UserClass(portinfo)->Prepare(env);
	Gura_UserClass(port)->Prepare(env);
	Gura_UserClass(player)->Prepare(env);
	Gura_UserClass(controller)->Prepare(env);
	Gura_UserClass(program)->Prepare(env);
	Gura_UserClass(soundfont)->Prepare(env);
	Gura_UserClass(synthesizer)->Prepare(env);
	// value assignment
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		valList.reserve(ArraySizeOf(g_controllerInfos));
		Class *pClass = Gura_UserClass(controller);
		for (size_t i = 0; i < ArraySizeOf(g_controllerInfos); i++) {
			UChar controller = static_cast<UChar>(i);
			ControllerInfo &controllerInfo = g_controllerInfos[i];
			if (controllerInfo.name == NULL) continue;
			controllerInfo.pSymbol = Symbol::Add(controllerInfo.name);
			Value value(new Object_controller(env, controller));
			valList.push_back(value);
			pClass->AssignValue(controllerInfo.pSymbol, value, EXTRA_Public);
		}
		Gura_AssignValue(controllers, value);
	} while (0);
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		valList.reserve(ArraySizeOf(g_programInfos));
		Class *pClass = Gura_UserClass(program);
		for (size_t i = 0; i < ArraySizeOf(g_programInfos); i++) {
			UChar program = static_cast<UChar>(i);
			ProgramInfo &programInfo = g_programInfos[i];
			programInfo.pSymbol = Symbol::Add(programInfo.name);
			Value value(new Object_program(env, program));
			valList.push_back(value);
			pClass->AssignValue(programInfo.pSymbol, value, EXTRA_Public);
		}
		Gura_AssignValue(programs, value);
	} while (0);
	// assignment of class reference or instance constructor
	Gura_AssignValue(event,			Value(Gura_UserClass(event)));
	Gura_AssignValue(track,			Value(Gura_UserClass(track)));
	Gura_AssignFunction(sequence);
	Gura_AssignValue(portinfo,		Value(Gura_UserClass(portinfo)));
	Gura_AssignFunction(port);
	Gura_AssignValue(player,		Value(Gura_UserClass(player)));
	Gura_AssignFunction(controller);
	Gura_AssignFunction(program);
	Gura_AssignFunction(soundfont);
	Gura_AssignValue(synthesizer,	Value(Gura_UserClass(synthesizer)));
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
int ControllerIdBySymbol(const Symbol *pSymbol)
{
	for (int i = 0; i < ArraySizeOf(g_controllerInfos); i++) {
		if (g_controllerInfos[i].pSymbol != NULL &&
					g_controllerInfos[i].pSymbol->IsIdentical(pSymbol)) {
			return i;
		}
	}
	return -1;
}

int ControllerIdByName(const char *name)
{
	for (int i = 0; i < ArraySizeOf(g_controllerInfos); i++) {
		if (::strcasecmp(g_controllerInfos[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

const ControllerInfo *ControllerInfoById(int controller)
{
	if (0 <= controller && controller < ArraySizeOf(g_controllerInfos)) {
		return &g_controllerInfos[controller];
	}
	return NULL;
}

int ProgramIdBySymbol(const Symbol *pSymbol)
{
	for (int i = 0; i < ArraySizeOf(g_programInfos); i++) {
		if (g_programInfos[i].pSymbol != NULL &&
					g_programInfos[i].pSymbol->IsIdentical(pSymbol)) {
			return i;
		}
	}
	return -1;
}

int ProgramIdByName(const char *name)
{
	for (int i = 0; i < ArraySizeOf(g_programInfos); i++) {
		if (::strcasecmp(g_programInfos[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

const ProgramInfo *ProgramInfoById(int program)
{
	if (0 <= program && program < ArraySizeOf(g_programInfos)) {
		return &g_programInfos[program];
	}
	return NULL;
}

Value ActivatePlayer(Environment &env, Signal sig, Args &args,
					Sequence &sequence, Port *pPort, double speed, int cntRepeat)
{
	AutoPtr<Player> pPlayer(sequence.GeneratePlayer(sig, pPort, speed, cntRepeat));
	if (sig.IsSignalled()) return Value::Null;
	if (args.IsSet(Gura_UserSymbol(background))) {
		Value value(new Object_player(env, Player::Reference(pPlayer.get())));
		pPlayer.release()->PlayBackground();
		return value;
	}
	if (args.IsSet(Gura_UserSymbol(player))) {
		Value value(new Object_player(env, Player::Reference(pPlayer.get())));
		return value;
	}
	pPlayer->Play();
	return Value::Null;
}

Gura_EndModuleBody(midi, midi)

Gura_RegisterModule(midi)
