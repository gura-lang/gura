//=============================================================================
// Gura class: audio
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_audio
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
	return nullptr; //new Object_audio(*this);
}

String Object_audio::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<audio:";
	rtn += Audio::FormatToSymbol(_pAudio->GetFormat())->GetName();
	rtn += ":";
	do {
		char buff[32];
		::sprintf(buff, "%dch", static_cast<int>(_pAudio->GetChannels()));
		rtn += buff;
	} while (0);
	rtn += ":";
	do {
		char buff[32];
		::sprintf(buff, "%dHz", static_cast<int>(_pAudio->GetSamplesPerSec()));
		rtn += buff;
	} while (0);
	rtn += ":";
	if (_pAudio->IsValid()) {
		char buff[32];
		::sprintf(buff, "%dsamples", static_cast<int>(_pAudio->GetSamples()));
		rtn += buff;
	} else {
		rtn += "invalid";
	}
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// audio(args+):map {block?}
Gura_DeclareFunction(audio)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "args", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_audio));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(audio)
{
	Signal &sig = env.GetSignal();
	size_t nChannels = 1;
	size_t nSamplesPerSec = 10000;
	ValueList valList = arg.GetList(0);
	AutoPtr<Audio> pAudio;
	if (valList[0].Is_symbol()) {
		Audio::Format format = Audio::SymbolToFormat(sig, valList[0].GetSymbol());
		if (sig.IsSignalled()) return Value::Nil;
		if (valList.size() >= 2) {
			//AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(channels), VTYPE_number));
			//pDecl->ValidateAndCast(env, valList[1]);
			//if (sig.IsSignalled()) return Value::Nil;
			Value valueCasted;
			if (!valList[1].CastType(env, VTYPE_number, valueCasted)) return Value::Nil;
			nChannels = valueCasted.GetSizeT();
			if (nChannels != 1 && nChannels != 2) {
				sig.SetError(ERR_ValueError, "channels must be one or two");
				return Value::Nil;
			}
		}
		if (valList.size() >= 3) {
			//AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(samplespersec), VTYPE_number));
			//pDecl->ValidateAndCast(env, valList[2]);
			//if (sig.IsSignalled()) return Value::Nil;
			Value valueCasted;
			if (!valList[2].CastType(env, VTYPE_number, valueCasted)) return Value::Nil;
			nSamplesPerSec = valueCasted.GetSizeT();
			if (nSamplesPerSec == 0) {
				sig.SetError(ERR_ValueError, "samplespersec must be more then zero");
				return Value::Nil;
			}
		}
		pAudio.reset(new Audio(format, nChannels, nSamplesPerSec));
	} else {
		//AutoPtr<Declaration> pDecl(
		//	new Declaration(
		//		Gura_Symbol(stream), VTYPE_stream, OCCUR_Once, FLAG_Read, 0, nullptr));
		//pDecl->ValidateAndCast(env, valList[0]);
		//if (sig.IsSignalled()) return Value::Nil;
		Value valueCasted;
		if (!valList[0].CastType(env, VTYPE_stream, valueCasted, FLAG_Read)) return Value::Nil;
		Stream &stream = valueCasted.GetStream();
		pAudio.reset(new Audio(Audio::FORMAT_None, nChannels, nSamplesPerSec));
		const char *audioType = nullptr;
		if (valList.size() >= 2) {
			//AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(audiotype), VTYPE_string));
			//pDecl->ValidateAndCast(env, valList[1]);
			//if (sig.IsSignalled()) return Value::Nil;
			Value valueCasted;
			if (!valList[1].CastType(env, VTYPE_string, valueCasted)) return Value::Nil;
			audioType = valueCasted.GetString();
		}
		if (!pAudio->Read(env, stream, audioType)) return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_audio(env, pAudio.release())));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// audio#format
Gura_DeclareProperty_R(audio, format)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(audio, format)
{
	Audio *pAudio = Object_audio::GetObject(valueThis)->GetAudio();
	return Value(Audio::FormatToSymbol(pAudio->GetFormat()));
}

// audio#channels
Gura_DeclareProperty_R(audio, channels)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(audio, channels)
{
	Audio *pAudio = Object_audio::GetObject(valueThis)->GetAudio();
	return Value(static_cast<UInt>(pAudio->GetChannels()));
}

// audio#samples
Gura_DeclareProperty_R(audio, samples)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(audio, samples)
{
	Audio *pAudio = Object_audio::GetObject(valueThis)->GetAudio();
	return Value(static_cast<UInt>(pAudio->GetSamples()));
}

// audio#samplespersec
Gura_DeclareProperty_R(audio, samplespersec)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(audio, samplespersec)
{
	Audio *pAudio = Object_audio::GetObject(valueThis)->GetAudio();
	return Value(static_cast<UInt>(pAudio->GetSamplesPerSec()));
}

// audio#bytespersample
Gura_DeclareProperty_R(audio, bytespersample)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(audio, bytespersample)
{
	Audio *pAudio = Object_audio::GetObject(valueThis)->GetAudio();
	return Value(static_cast<UInt>(pAudio->GetBytesPerSample()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// audio#each(channel:number, offset?:number):map {block?}
Gura_DeclareMethod(audio, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(audio, each)
{
	Signal &sig = env.GetSignal();
	Audio *pAudio = Object_audio::GetObjectThis(arg)->GetAudio();
	size_t iChannel = arg.GetSizeT(0);
	if (iChannel >= pAudio->GetChannels()) {
		sig.SetError(ERR_ValueError, "channel is out of range");
		return Value::Nil;
	}
	size_t offset = arg.Is_number(1)? arg.GetSizeT(1) : 0;
	AutoPtr<Iterator> pIterator(new Audio::IteratorEach(
								pAudio->Reference(), iChannel, offset));
	return ReturnIterator(env, arg, pIterator.release());
}

// audio#get(channel:number, offset:number):map
Gura_DeclareMethod(audio, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(audio, get)
{
	Signal &sig = env.GetSignal();
	Audio *pAudio = Object_audio::GetObjectThis(arg)->GetAudio();
	size_t iChannel = arg.GetSizeT(0);
	if (iChannel >= pAudio->GetChannels()) {
		sig.SetError(ERR_ValueError, "channel is out of range");
		return Value::Nil;
	}
	size_t offset = arg.GetSizeT(1);
	int data = 0;
	if (!pAudio->GetData(iChannel, offset, &data)) {
		sig.SetError(ERR_IndexError, "offset is out of range");
		return Value::Nil;
	}
	return Value(data);
}

// audio#put(channel:number, offset:number, data:number):reduce:map
Gura_DeclareMethod(audio, put)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "data", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(audio, put)
{
	Signal &sig = env.GetSignal();
	Audio *pAudio = Object_audio::GetObjectThis(arg)->GetAudio();
	size_t iChannel = arg.GetSizeT(0);
	if (iChannel >= pAudio->GetChannels()) {
		sig.SetError(ERR_ValueError, "channel is out of range");
		return Value::Nil;
	}
	size_t offset = arg.GetSizeT(1);
	int data = arg.GetInt(2);
	if (!pAudio->PutData(iChannel, offset, data)) {
		sig.SetError(ERR_IndexError, "offset is out of range");
		return Value::Nil;
	}
	return arg.GetValueThis();
}

// audio#sinewave(channel:number, freq:number, len:number, amplitude?:number):reduce:map
Gura_DeclareMethod(audio, sinewave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "freq", VTYPE_number);
	DeclareArg(env, "len", VTYPE_number);
	DeclareArg(env, "amplitude", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(audio, sinewave)
{
	Signal &sig = env.GetSignal();
	Audio *pAudio = Object_audio::GetObjectThis(arg)->GetAudio();
	size_t iChannel = arg.GetSizeT(0);
	if (iChannel >= pAudio->GetChannels()) {
		sig.SetError(ERR_ValueError, "channel is out of range");
		return Value::Nil;
	}
	double freq = arg.GetDouble(1);
	size_t nSamples = static_cast<size_t>(arg.GetDouble(2) * pAudio->GetSamplesPerSec());
	int amplitude = arg.Is_number(3)? arg.GetInt(3) : -1;
	if (!pAudio->AddSineWave(sig, iChannel, freq, nSamples, amplitude)) {
		return Value::Nil;
	}
	return arg.GetValueThis();
}

// audio#store(channel:number, offset:number, data:iterator):reduce
Gura_DeclareMethod(audio, store)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "channel", VTYPE_number);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "data", VTYPE_iterator);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(audio, store)
{
	Signal &sig = env.GetSignal();
	Audio *pAudio = Object_audio::GetObjectThis(arg)->GetAudio();
	size_t iChannel = arg.GetSizeT(0);
	if (iChannel >= pAudio->GetChannels()) {
		sig.SetError(ERR_ValueError, "channel is out of range");
		return Value::Nil;
	}
	size_t offset = arg.GetSizeT(1);
	Iterator *pIterator = arg.GetIterator(2);
	if (!pAudio->StoreData(env, iChannel, offset, pIterator)) return Value::Nil;
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_audio::Class_audio(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_audio)
{
}

void Class_audio::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(audio);
	// Assignment of properties
	Gura_AssignProperty(audio, format);
	Gura_AssignProperty(audio, channels);
	Gura_AssignProperty(audio, samples);
	Gura_AssignProperty(audio, samplespersec);
	Gura_AssignProperty(audio, bytespersample);
	// Assignment of methods
	Gura_AssignMethod(audio, each);
	Gura_AssignMethod(audio, get);
	Gura_AssignMethod(audio, put);
	Gura_AssignMethod(audio, sinewave);
	Gura_AssignMethod(audio, store);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_audio::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	size_t nChannels = 1;
	size_t nSamplesPerSec = 10000;
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, flags);
	if (value.Is_stream()) {
		AutoPtr<Audio> pAudio(new Audio(Audio::FORMAT_None, nChannels, nSamplesPerSec));
		pAudio->Read(env, value.GetStream(), nullptr);
		value = Value::Nil; // delete stream instance
		if (sig.IsSignalled()) return false;
		value = Value(new Object_audio(env, pAudio.release()));
		return true;
	}
	return false;
}

}
