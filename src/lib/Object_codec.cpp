//
// Object_codec
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_codec
//-----------------------------------------------------------------------------
Object_codec::Object_codec(const Object_codec &obj) :
					Object(obj), _pCodec(obj.GetCodec()->Duplicate())
{
}

Object *Object_codec::Clone() const
{
	return new Object_codec(*this);
}

String Object_codec::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<codec:";
	str += GetCodec()->GetEncoding();
	if (GetCodec()->GetDecoder()->GetDelcrFlag()) {
		str += ":delcr";
	}
	if (GetCodec()->GetEncoder()->GetAddcrFlag()) {
		str += ":addcr";
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// codec(encoding:string) {block?}
Gura_DeclareFunction(codec)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "encoding", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_codec));
}

Gura_ImplementFunction(codec)
{
	AutoPtr<Codec> pCodec(Codec::CreateCodec(sig, args.GetString(0), true, false));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_codec(env, pCodec.release())));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_codec
//-----------------------------------------------------------------------------
// codec.dir()
Gura_DeclareClassMethod(codec, dir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), 
	"Returns a list of character codecs that are registered.");
}

Gura_ImplementClassMethod(codec, dir)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (CodecFactory::List, ppCodecFactory, CodecFactory::GetList()) {
		const CodecFactory *pCodecFactory = *ppCodecFactory;
		valList.push_back(Value(env, pCodecFactory->GetEncoding()));
	}
	return result;
}

// codec#addcr(flag?:boolean):reduce
Gura_DeclareMethod(codec, addcr)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(codec, addcr)
{
	Object_codec *pThis = Object_codec::GetThisObj(args);
	Codec::Encoder *pEncoder = pThis->GetCodec()->GetEncoder();
	pEncoder->SetAddcrFlag(args.IsValid(0)? args.GetBoolean(0) : true);
	return args.GetThis();
}

// codec#delcr(flag?:boolean):reduce
Gura_DeclareMethod(codec, delcr)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(codec, delcr)
{
	Object_codec *pThis = Object_codec::GetThisObj(args);
	Codec::Decoder *pDecoder = pThis->GetCodec()->GetDecoder();
	pDecoder->SetDelcrFlag(args.IsValid(0)? args.GetBoolean(0) : true);
	return args.GetThis();
}

// codec#encode(string:string):map
Gura_DeclareMethod(codec, encode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string);
	AddHelp(Gura_Symbol(en), "");
}

Gura_ImplementMethod(codec, encode)
{
	Object_codec *pThis = Object_codec::GetThisObj(args);
	Binary dst;
	if (!pThis->GetCodec()->GetEncoder()->Encode(sig, dst, args.GetString(0))) {
		return Value::Null;
	}
	return Value(new Object_binary(env, dst, true));
}

// codec#decode(buff:binary):map
Gura_DeclareMethod(codec, decode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buff", VTYPE_binary);
	AddHelp(Gura_Symbol(en), "");
}

Gura_ImplementMethod(codec, decode)
{
	Object_codec *pThis = Object_codec::GetThisObj(args);
	String dst;
	if (!pThis->GetCodec()->GetDecoder()->Decode(sig, dst, args.GetBinary(0))) {
		return Value::Null;
	}
	return Value(env, dst.c_str());
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_codec::Class_codec(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_codec)
{
	Gura_AssignMethod(codec, dir);
	Gura_AssignMethod(codec, addcr);
	Gura_AssignMethod(codec, delcr);
	Gura_AssignMethod(codec, encode);
	Gura_AssignMethod(codec, decode);
}

bool Class_codec::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsString()) {
		AutoPtr<Codec> pCodec(Codec::CreateCodec(sig, value.GetString(), true, false));
		if (sig.IsSignalled()) return false;
		value = Value(new Object_codec(env, pCodec.release()));
		return true;
	}
	return false;
}

Object *Class_codec::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_codec::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(codec);
}

}
