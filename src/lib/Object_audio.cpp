//
// Object_audio
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object implementation for audio
//-----------------------------------------------------------------------------
Object_audio::Object_audio(Environment &env, Audio *pAudio) :
			Object(env.LookupClass(VTYPE_audio)), _pAudio(pAudio)
{
}

Object_audio::Object_audio(Class *pClass, Audio *pAudio) :
			Object(pClass), _pAudio(pAudio)
{
}

Object *Object_audio::Clone() const
{
	return NULL; //new Object_audio(*this);
}

bool Object_audio::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(format));
	symbols.insert(Gura_Symbol(channels));
	symbols.insert(Gura_Symbol(samples));
	symbols.insert(Gura_Symbol(samplespersec));
	symbols.insert(Gura_Symbol(bytespersample));
	return true;
}

Value Object_audio::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(Audio::FormatToSymbol(_pAudio->GetFormat()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(channels))) {
		return Value(static_cast<unsigned int>(_pAudio->GetChannels()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(samples))) {
		return Value(static_cast<unsigned int>(_pAudio->GetSamples()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(samplespersec))) {
		return Value(static_cast<unsigned int>(_pAudio->GetSamplesPerSec()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(bytespersample))) {
		return Value(static_cast<unsigned int>(_pAudio->GetBytesPerSample()));
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
	rtn += Audio::FormatToSymbol(_pAudio->GetFormat())->GetName();
	rtn += ":";
	if (_pAudio->IsValid()) {
		char buff[32];
		::sprintf(buff, "%d", static_cast<int>(_pAudio->GetSamples()));
		rtn += buff;
	} else {
		rtn += "invalid";
	}
	rtn += ":";
	do {
		char buff[32];
		::sprintf(buff, "%dch", static_cast<int>(_pAudio->GetChannels()));
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// audio(args+):map {block?}
Gura_DeclareFunction(audio)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "args", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(audio)
{
	size_t nChannels = 1;
	size_t nSamplesPerSec = 10000;
	ValueList valList = args.GetList(0);
	AutoPtr<Audio> pAudio;
	if (valList[0].IsSymbol()) {
		Audio::Format format = Audio::SymbolToFormat(sig, valList[0].GetSymbol());
		if (sig.IsSignalled()) return Value::Null;
		if (valList.size() < 2) {
			Declaration::SetError_NotEnoughArguments(sig);
			return Value::Null;
		}
		if (valList.size() >= 3) {
			nChannels = valList[2].GetSizeT();
			if (nChannels != 1 && nChannels != 2) {
				sig.SetError(ERR_ValueError, "channels must be one or two");
				return Value::Null;
			}
		}
		if (valList.size() >= 4) {
			nSamplesPerSec = valList[3].GetSizeT();
			if (nSamplesPerSec == 0) {
				sig.SetError(ERR_ValueError, "samplespersec must be more then zero");
				return Value::Null;
			}
		}
		pAudio.reset(new Audio(format, nChannels, nSamplesPerSec));
		if (!pAudio->AllocBuffer(sig, valList[1].GetSizeT())) return Value::Null;
	} else {
		Declaration(Gura_Symbol(stream), VTYPE_stream, OCCUR_Once, FLAG_Read, NULL).
									ValidateAndCast(env, sig, valList[0]);
		if (sig.IsSignalled()) return Value::Null;
		Stream &stream = valList[0].GetStream();
		pAudio.reset(new Audio(Audio::FORMAT_None, nChannels, nSamplesPerSec));
		const char *audioType = NULL;
		if (valList.size() >= 2) {
			Declaration(Gura_Symbol(audiotype), VTYPE_string).
									ValidateAndCast(env, sig, valList[1]);
			if (sig.IsSignalled()) return Value::Null;
			audioType = valList[1].GetString();
		}
		if (!pAudio->Read(env, sig, stream, audioType)) return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_audio(env, pAudio.release())));
}

//-----------------------------------------------------------------------------
// Gura interfaces for audio
//-----------------------------------------------------------------------------
// audio#sinewave(channel:number, pitch:number, samples:number, amplitude?:number):reduce
Gura_DeclareMethod(audio, sinewave)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "pitch", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
	DeclareArg(env, "amplitude", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(audio, sinewave)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	Audio *pAudio = pThis->GetAudio();
	size_t iChannel = args.GetSizeT(0);
	size_t pitch = args.GetSizeT(1);
	size_t nSamples = args.GetSizeT(2);
	int amplitude = args.IsNumber(3)? args.GetInt(3) : -1;
	if (!pAudio->AddSineWave(sig, iChannel, pitch, nSamples, amplitude)) {
		return Value::Null;
	}
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

// audio#store(channel:number, offset:number, samples:number, src):reduce
Gura_DeclareMethod(audio, store)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
	DeclareArg(env, "src", VTYPE_any);
}

Gura_ImplementMethod(audio, store)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	return args.GetThis();
}

// audio#extract(channel:number, offset:number, samples:number, dst)
Gura_DeclareMethod(audio, extract)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
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

// audio#fillrange(channel:number, offset:number, samples:number, data:number):reduce
Gura_DeclareMethod(audio, fillrange)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
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
}

void Class_audio::Prepare(Environment &env)
{
	Gura_AssignFunction(audio);
	Gura_AssignMethod(audio, sinewave);
	Gura_AssignMethod(audio, put);
	Gura_AssignMethod(audio, get);
	Gura_AssignMethod(audio, store);
	Gura_AssignMethod(audio, extract);
	Gura_AssignMethod(audio, fill);
	Gura_AssignMethod(audio, fillrange);
}

bool Class_audio::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	size_t nChannels = 1;
	size_t nSamplesPerSec = 10000;
	env.LookupClass(VTYPE_stream)->CastFrom(env, sig, value, pDecl);
	if (value.IsStream()) {
		AutoPtr<Audio> pAudio(new Audio(Audio::FORMAT_None, nChannels, nSamplesPerSec));
		pAudio->Read(env, sig, value.GetStream(), NULL);
		value = Value::Null; // delete stream instance
		if (sig.IsSignalled()) return false;
		value = Value(new Object_audio(env, pAudio.release()));
		return true;
	}
	return false;
}

}
