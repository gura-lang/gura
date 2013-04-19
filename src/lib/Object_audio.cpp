//
// Object_audio
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object implementation for audio
//-----------------------------------------------------------------------------
Object_audio::~Object_audio()
{
	FreeBuffer();
}

Object *Object_audio::Clone() const
{
	return NULL; //new Object_audio(*this);
}

bool Object_audio::AllocBuffer(Signal sig, size_t len)
{
	FreeBuffer();
	_pMemory.reset(new OAL::MemoryHeap(_nChannels * len * GetBytesPerData()));
	_buff = reinterpret_cast<unsigned char *>(_pMemory->GetPointer());
	_len = len;
	return true;
}

void Object_audio::FreeBuffer()
{
	_pMemory.reset(NULL);
	_buff = NULL;
	_len = 0;
}

bool Object_audio::SetSineWave(Signal sig, size_t iChannel,
			size_t pitch, int phase, int amplitude, size_t offset, size_t len)
{
	const double PI2 = Math_PI * 2;
	int amplitudeMax =
		(_format == FORMAT_U8 || _format == FORMAT_S8)? 0x7f :
		(_format == FORMAT_U16LE || _format == FORMAT_S16LE ||
		 _format == FORMAT_U16BE || _format == FORMAT_S16BE)? 0x7fff : 0;
	if (iChannel >= _nChannels) {
		sig.SetError(ERR_ValueError, "channel is out of range");
		return false;
	}
	if (amplitude < 0) {
		amplitude = amplitudeMax;
	} else if (amplitude > amplitudeMax) {
		sig.SetError(ERR_ValueError, "amplitude is out of range");
		return false;
	}
	if (len > _len) len = _len;
	if (offset >= _len) return true;
	if (offset + len > _len) len = _len - offset;
	unsigned char *buffp = _buff + (offset * _nChannels + iChannel) * GetBytesPerData();
	size_t bytesPerUnit = GetBytesPerData() * _nChannels;
	for (size_t i = 0; i < len; i++) {
		int data = static_cast<int>(::sin(PI2 * (i + phase) / pitch) * amplitude);
		StoreData(buffp, data);
		buffp += bytesPerUnit;
	}
	return true;
}

Object_audio::Format Object_audio::SymbolToFormat(Signal sig, const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_Symbol(u8))) {
		return FORMAT_U8;
	} else if (pSymbol->IsIdentical(Gura_Symbol(s8))) {
		return FORMAT_S8;
	} else if (pSymbol->IsIdentical(Gura_Symbol(u16le))) {
		return FORMAT_U16LE;
	} else if (pSymbol->IsIdentical(Gura_Symbol(s16le))) {
		return FORMAT_S16LE;
	} else if (pSymbol->IsIdentical(Gura_Symbol(u16be))) {
		return FORMAT_U16BE;
	} else if (pSymbol->IsIdentical(Gura_Symbol(s16be))) {
		return FORMAT_S16BE;
	} else {
		sig.SetError(ERR_ValueError, "unsupported audio format '%s'", pSymbol->GetName());
		return FORMAT_None;
	}
}

const Symbol *Object_audio::FormatToSymbol(Format format)
{
	if (format == FORMAT_U8) {
		return Gura_Symbol(u8);
	} else if (format == FORMAT_S8) {
		return Gura_Symbol(s8);
	} else if (format == FORMAT_U16LE) {
		return Gura_Symbol(u16le);
	} else if (format == FORMAT_S16LE) {
		return Gura_Symbol(s16le);
	} else if (format == FORMAT_U16BE) {
		return Gura_Symbol(u16be);
	} else if (format == FORMAT_S16BE) {
		return Gura_Symbol(s16be);
	} else {
		return Gura_Symbol(nil);
	}
}

bool Object_audio::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(format));
	symbols.insert(Gura_Symbol(channels));
	symbols.insert(Gura_Symbol(len));
	return true;
}

Value Object_audio::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(FormatToSymbol(_format));
	} else if (pSymbol->IsIdentical(Gura_Symbol(channels))) {
		return Value(static_cast<unsigned int>(_nChannels));
	} else if (pSymbol->IsIdentical(Gura_Symbol(len))) {
		return Value(static_cast<unsigned int>(_len));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_audio::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

String Object_audio::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<audio:";
	rtn += FormatToSymbol(_format)->GetName();
	rtn += ":";
	if (IsValid()) {
		char buff[32];
		::sprintf(buff, "%d", static_cast<int>(GetLength()));
		rtn += buff;
	} else {
		rtn += "invalid";
	}
	rtn += ":";
	do {
		char buff[32];
		::sprintf(buff, "%dch", static_cast<int>(_nChannels));
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// audio(format:symbol, len:number, channels:number => 1) {block?}
Gura_DeclareFunction(audio)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_symbol);
	DeclareArg(env, "len", VTYPE_number);
	DeclareArg(env, "channels", VTYPE_number,
							OCCUR_Once, FLAG_None, new Expr_Value(1));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(audio)
{
	Object_audio::Format format = Object_audio::SymbolToFormat(sig, args.GetSymbol(0));
	if (sig.IsSignalled()) return Value::Null;
	size_t nChannels = args.GetSizeT(2);
	Object_audio *pObj = new Object_audio(env, format, nChannels);
	if (!pObj->AllocBuffer(sig, args.GetSizeT(1))) {
		delete pObj;
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj));
}

//-----------------------------------------------------------------------------
// Gura interfaces for audio
//-----------------------------------------------------------------------------
// audio#sinewave(channel:number, pitch:number, phase?:number,
//                amplitude?:number, offset?:number, len?:number):reduce
Gura_DeclareMethod(audio, sinewave)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "pitch", VTYPE_number);
	DeclareArg(env, "phase", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "amplitude", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(audio, sinewave)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	size_t iChannel = args.GetSizeT(0);
	size_t pitch = args.GetSizeT(1);
	int phase = args.IsNumber(2)? args.GetInt(2) : 0;
	int amplitude = args.IsNumber(3)? args.GetInt(3) : -1;
	size_t offset = args.IsNumber(4)? args.GetSizeT(4) : 0;
	size_t len = args.IsNumber(5)? args.GetSizeT(5) : InvalidSize;
	if (!pThis->SetSineWave(sig, iChannel, pitch, phase, amplitude, offset, len)) {
		return Value::Null;
	}
	//for (size_t i = 0; i < pThis->GetLength() * pThis->GetBytesPerData(); i++) {
	//	::printf(" %02x", pThis->GetBuffer()[i]);
	//}
	return args.GetThis();
}

// audio#put(channel:number, offset:number, data:number):reduce
Gura_DeclareMethod(audio, put)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "data", VTYPE_number);
}

Gura_ImplementMethod(audio, put)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	return args.GetThis();
}

// audio#get(channel:number, offset:number)
Gura_DeclareMethod(audio, get)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
}

Gura_ImplementMethod(audio, get)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	return Value::Null;
}

// audio#store(channel:number, offset:number, len:number, src):reduce
Gura_DeclareMethod(audio, store)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "len", VTYPE_number);
	DeclareArg(env, "src", VTYPE_any);
}

Gura_ImplementMethod(audio, store)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	return args.GetThis();
}

// audio#extract(channel:number, offset:number, len:number, dst)
Gura_DeclareMethod(audio, extract)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "len", VTYPE_number);
	DeclareArg(env, "dst", VTYPE_any);
}

Gura_ImplementMethod(audio, extract)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	return Value::Null;
}

// audio#fill(data:number):reduce
Gura_DeclareMethod(audio, fill)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "data", VTYPE_number);
}

Gura_ImplementMethod(audio, fill)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	return args.GetThis();
}

// audio#fillrange(channel:number, offset:number, len:number, data:number):reduce
Gura_DeclareMethod(audio, fillrange)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "len", VTYPE_number);
	DeclareArg(env, "data", VTYPE_number);
}

Gura_ImplementMethod(audio, fillrange)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Class implementation for audio
//-----------------------------------------------------------------------------
Class_audio::Class_audio(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_audio)
{
	Gura_AssignMethod(audio, sinewave);
	Gura_AssignMethod(audio, put);
	Gura_AssignMethod(audio, get);
	Gura_AssignMethod(audio, store);
	Gura_AssignMethod(audio, extract);
	Gura_AssignMethod(audio, fill);
	Gura_AssignMethod(audio, fillrange);
}

Object *Class_audio::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_audio::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(audio);
}

//-----------------------------------------------------------------------------
// AudioStreamer
//-----------------------------------------------------------------------------
AudioStreamer::List *AudioStreamer::_pList = NULL;
void AudioStreamer::Register(AudioStreamer *pAudioStreamer)
{
	if (_pList == NULL) _pList = new List();
	_pList->push_back(pAudioStreamer);
}

AudioStreamer *AudioStreamer::FindResponsible(Signal sig, Stream &stream, const char *audioType)
{
	if (_pList == NULL) return NULL;
	if (audioType != NULL) return FindByAudioType(audioType);
	foreach (List, ppAudioStreamer, *_pList) {
		AudioStreamer *pAudioStreamer = *ppAudioStreamer;
		if (pAudioStreamer->IsResponsible(sig, stream)) return pAudioStreamer;
		if (sig.IsSignalled()) break;
	}
	return NULL;
}

AudioStreamer *AudioStreamer::FindByAudioType(const char *audioType)
{
	if (_pList == NULL) return NULL;
	foreach (List, ppAudioStreamer, *_pList) {
		AudioStreamer *pAudioStreamer = *ppAudioStreamer;
		if (::strcasecmp(pAudioStreamer->GetAudioType(), audioType) == 0) {
			return pAudioStreamer;
		}
	}
	return NULL;
}

}
