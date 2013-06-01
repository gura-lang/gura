//-----------------------------------------------------------------------------
// Gura midi module
//-----------------------------------------------------------------------------
#include "Module_midi.h"

Gura_BeginModule(midi)

struct HeaderChunkTop {
	enum { Size = 8 };
	char MThd[4];
	Gura_PackedULong_BE(header_length);
};

struct HeaderChunk {
	Gura_PackedUShort_BE(format);
	Gura_PackedUShort_BE(num_track_chunks);
	Gura_PackedUShort_BE(division);
};

struct TrackChunkTop {
	enum { Size = 8 };
	char MTrk[4];
	Gura_PackedULong_BE(length);
};

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
// midi.port#rawwrite(msg+:number):map:void
Gura_DeclareMethod(port, rawwrite)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msg", VTYPE_number, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(port, rawwrite)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	const ValueList &valList = args.GetList(0);
	size_t nArgs = valList.size();
	if (nArgs == 1) {
		pThis->GetPort().RawWrite(valList[0].GetUChar());
	} else if (nArgs == 2) {
		pThis->GetPort().RawWrite(valList[0].GetUChar(), valList[1].GetUChar());
	} else if (nArgs == 3) {
		pThis->GetPort().RawWrite(valList[0].GetUChar(), valList[1].GetUChar(),
														valList[2].GetUChar());
	} else if (nArgs == 4) {
		pThis->GetPort().RawWrite(valList[0].GetUChar(), valList[1].GetUChar(),
							valList[2].GetUChar(), valList[3].GetUChar());
	} else {
		sig.SetError(ERR_ArgumentError, "too many arguments");
		return Value::Null;
	}
	return Value::Null;
}

// midi.port#mmlplay(mml:string):map;void
Gura_DeclareMethod(port, mmlplay)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mml", VTYPE_string);
}

Gura_ImplementMethod(port, mmlplay)
{
	Object_port *pThis = Object_port::GetThisObj(args);
	char channel = 0;
	pThis->GetPort().MmlPlay(channel, args.GetString(0));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for midi.port
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(port)
{
	Gura_AssignMethod(port, rawwrite);
	Gura_AssignMethod(port, mmlplay);
}

//-----------------------------------------------------------------------------
// Gura module functions: midi
//-----------------------------------------------------------------------------
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
	if (!pObj->GetPort().Open(id)) {
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

enum MIDIEvent {
	MIDIEVT_None,
	MIDIEVT_NoteOff,
	MIDIEVT_NoteOn,
	MIDIEVT_PolyphonicKeyPressure,
	MIDIEVT_ControlChange,
	MIDIEVT_ProgramChange,
	MIDIEVT_ChannelPressure,
	MIDIEVT_PitchBendChange,
};

enum MetaEvent {
	METAEVT_None,
	METAEVT_SequenceNumber,
	METAEVT_TextEvent,
	METAEVT_CopyrightNotice,
	METAEVT_SequenceOrTrackName,
	METAEVT_InstrumentName,
	METAEVT_LyricText,
	METAEVT_MarkerText,
	METAEVT_CuePoint,
	METAEVT_MIDIChannelPrefixAssignment,
	METAEVT_EndOfTrack,
	METAEVT_TempoSetting,
	METAEVT_SMPTEOffset,
	METAEVT_TimeSignature,
	METAEVT_KeySignature,
	METAEVT_SequencerSpecificEvent,
};

void OnMIDIEvent(unsigned long deltaTime, unsigned char data[], size_t length)
{
	::printf("%08x MIDIEvent %02x\n", deltaTime, data[0]);
}

void OnSysExEvent(unsigned long deltaTime)
{
	::printf("%08x SysExEvent\n", deltaTime);
}

void OnMetaEvent(unsigned long deltaTime, unsigned char eventType, unsigned char data[], size_t length)
{
	::printf("%08x MetaEvent %02x\n", deltaTime, eventType);
}

bool ReadSMF(Environment &env, Signal sig, Stream &stream)
{
	AutoPtr<Memory> pMemory(new MemoryHeap(1024));
	unsigned short format = 0;
	unsigned short num_track_chunks = 0;
	unsigned short division = 0;
	do {
		HeaderChunkTop headerChunkTop;
		if (stream.Read(sig, &headerChunkTop, HeaderChunkTop::Size) != HeaderChunkTop::Size) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		if (::strcmp(headerChunkTop.MThd, "MThd") != 0) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		size_t header_length = Gura_UnpackULong(headerChunkTop.header_length);
		HeaderChunk &headerChunk = *reinterpret_cast<HeaderChunk *>(pMemory->GetPointer());
		if (header_length > pMemory->GetSize()) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		if (stream.Read(sig, pMemory->GetPointer(), header_length) != header_length) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		format = Gura_UnpackUShort(headerChunk.format);
		num_track_chunks = Gura_UnpackUShort(headerChunk.num_track_chunks);
		division = Gura_UnpackUShort(headerChunk.division);
	} while (0);
	enum Stat {
		STAT_EventStart,
		STAT_DeltaTime,
		STAT_EventId,
		STAT_MIDIEvent,
		STAT_SysExEventF0,
		STAT_SysExEventF7,
		STAT_MetaEvent_Type,
		STAT_MetaEvent_Length,
		STAT_MetaEvent_Data,
	};
	::printf("%d %d %d\n", format, num_track_chunks, division);
	for (unsigned short i = 0; i < num_track_chunks; i++) {
		TrackChunkTop trackChunkTop;
		if (stream.Read(sig, &trackChunkTop, TrackChunkTop::Size) != TrackChunkTop::Size) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		if (::strcmp(trackChunkTop.MTrk, "MTrk") != 0) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		unsigned char eventType = 0x00;
		unsigned char data[256];
		Stat stat = STAT_EventStart;
		unsigned long deltaTime = 0x00000000;
		unsigned long length = 0x00000000;
		unsigned long idxData = 0;
		size_t lengthRest = Gura_UnpackULong(trackChunkTop.length);
		while  (lengthRest > 0) {
			size_t lengthRead = ChooseMin(lengthRest, pMemory->GetSize());
			if (stream.Read(sig, pMemory->GetPointer(), lengthRead) != lengthRead) {
				sig.SetError(ERR_FormatError, "invalid SMF format");
				return false;
			}
			lengthRest -= lengthRead;
			unsigned char *p = reinterpret_cast<unsigned char *>(pMemory->GetPointer());
			for ( ; lengthRead > 0; p++, lengthRead--) {
				unsigned char ch = *p;
				if (stat == STAT_EventStart) {
					deltaTime = 0x00000000;
					length = 0x00000000;
					stat = STAT_DeltaTime;
				}
				if (stat == STAT_DeltaTime) {
					deltaTime = (deltaTime << 7) + (ch & 0x7f);
					if ((ch & 0x80) == 0) {
						stat = STAT_EventId;
					}
				} else if (stat == STAT_EventId) {
					unsigned char chUpper = ch & 0xf0;
					if (chUpper == 0x80 || chUpper == 0x90 || chUpper == 0xa0
										|| chUpper == 0xb0 || chUpper == 0xe0) {
						idxData = 0;
						length = 3;
						data[idxData++] = ch;
						stat = STAT_MIDIEvent;
					} else if (chUpper == 0xc0 || chUpper == 0xd0) {
						idxData = 0;
						length = 2;
						data[idxData++] = ch;
						stat = STAT_MIDIEvent;
					} else if (ch == 0xf0) {
						stat = STAT_SysExEventF0;
					} else if (ch == 0xf7) {
						stat = STAT_SysExEventF7;
					} else if (ch == 0xff) {
						stat = STAT_MetaEvent_Type;
					} else {
						sig.SetError(ERR_FormatError, "unknown SMF event id %02x", ch);
						return false;
					}
				} else if (stat == STAT_MIDIEvent) {
					data[idxData++] = ch;
					if (idxData == length) {
						OnMIDIEvent(deltaTime, data, length);
						stat = STAT_EventStart;
					}
				} else if (stat == STAT_SysExEventF0) {
					if (ch == 0xf7) {
						OnSysExEvent(deltaTime);
						stat = STAT_EventStart;
					}
				} else if (stat == STAT_SysExEventF7) {
					if (ch == 0xf7) {
						OnSysExEvent(deltaTime);
						stat = STAT_EventStart;
					}
				} else if (stat == STAT_MetaEvent_Type) {
					eventType = ch;
					stat = STAT_MetaEvent_Length;
				} else if (stat == STAT_MetaEvent_Length) {
					length = (length << 7) + (ch & 0x7f);
					if ((ch & 0x80) != 0) {
						// nothing to do
					} else if (length == 0) {
						OnMetaEvent(deltaTime, eventType, data, 0);
						stat = STAT_EventStart;
					} else {
						idxData = 0;
						stat = STAT_MetaEvent_Data;
					}
				} else if (stat == STAT_MetaEvent_Data) {
					if (idxData < sizeof(data)) data[idxData] = ch;
					idxData++;
					if (idxData == length) {
						OnMetaEvent(deltaTime, eventType, data, ChooseMin(
								static_cast<size_t>(length), sizeof(data)));
						stat = STAT_EventStart;
					}
				}
			}
		}
	}
	return true;
}

Gura_ImplementFunction(test)
{
	ReadSMF(env, sig, args.GetStream(0));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeUserClass(smf, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(portinfo, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(port, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(port);
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(midi, midi)

Gura_RegisterModule(midi)
