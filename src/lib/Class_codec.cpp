//=============================================================================
// Gura class: codec
//=============================================================================
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

String Object_codec::ToString(bool exprFlag)
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
// Implementation of functions
//-----------------------------------------------------------------------------
// codec(encoding:string) {block?}
Gura_DeclareFunction(codec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "encoding", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_codec));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `codec` instance of the specified encoding name.\n"
		"You can call `codecs.dir()` to get a list of available encoding names.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter `|codec:codec|`,\n"
		"where `codec` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n");
}

Gura_ImplementFunction(codec)
{
	AutoPtr<Codec> pCodec(Codec::CreateCodec(sig, args.GetString(0), true, false));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_codec(env, pCodec.release())));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// codec#addcr(flag?:boolean):reduce
Gura_DeclareMethod(codec, addcr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"The codec's encoder has a feature\n"
		"to add a CR code (0x0d) before a LF code (0x0a)\n"
		"so that the lines are joined with CR-LF codes in the encoded result.\n"
		"This method enables or disables the feature.\n"
		"\n"
		"- To enable it, call the method with the argument `flag` set to `true` or without any argument.\n"
		"- To disable it, call the method with the argument `flag` set to `false`.\n");
}

Gura_ImplementMethod(codec, addcr)
{
	Object_codec *pThis = Object_codec::GetThisObj(args);
	Codec::Encoder *pEncoder = pThis->GetCodec()->GetEncoder();
	pEncoder->SetAddcrFlag(args.IsValid(0)? args.GetBoolean(0) : true);
	return args.GetThis();
}

// codec#decode(buff:binary):map
Gura_DeclareMethod(codec, decode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buff", VTYPE_binary);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Decodes a binary `buff` and returns the decoded result as `string`.\n");
}

Gura_ImplementMethod(codec, decode)
{
	Object_codec *pThis = Object_codec::GetThisObj(args);
	String dst;
	if (!pThis->GetCodec()->GetDecoder()->Decode(sig, dst, args.GetBinary(0))) {
		return Value::Null;
	}
	return Value(dst);
}

// codec#delcr(flag?:boolean):reduce
Gura_DeclareMethod(codec, delcr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"The codec's decoder has a feature\n"
		"to delete a CR code (0x0d) before a LF code (0x0a)\n"
		"so that the lines are joined with LF code in the decoded result.\n"
		"This method enables or disables the feature.\n"
		"\n"
		"- To enable it, call the method with the argument `flag` set to `true` or without any argument.\n"
		"- To disable it, call the method with the argument `flag` set to `false`.\n");
}

Gura_ImplementMethod(codec, delcr)
{
	Object_codec *pThis = Object_codec::GetThisObj(args);
	Codec::Decoder *pDecoder = pThis->GetCodec()->GetDecoder();
	pDecoder->SetDelcrFlag(args.IsValid(0)? args.GetBoolean(0) : true);
	return args.GetThis();
}

// codec#encode(str:string):map
Gura_DeclareMethod(codec, encode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Encodes a string `str` and returns the encoded result as `binary`.\n");
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

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_codec::Class_codec(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_codec)
{
}

void Class_codec::Prepare(Environment &env)
{
	Gura_AssignFunction(codec);
	Gura_AssignMethod(codec, addcr);
	Gura_AssignMethod(codec, decode);
	Gura_AssignMethod(codec, delcr);
	Gura_AssignMethod(codec, encode);
	Gura_AssignClassValueEx("bom@utf8", Value(new Object_binary(env, Codec::BOM_UTF8, false)));
	Gura_AssignClassValueEx("bom@utf16le", Value(new Object_binary(env, Codec::BOM_UTF16LE, false)));
	Gura_AssignClassValueEx("bom@utf16be", Value(new Object_binary(env, Codec::BOM_UTF16BE, false)));
	Gura_AssignClassValueEx("bom@utf32le", Value(new Object_binary(env, Binary(Codec::BOM_UTF32LE, 4), false)));
	Gura_AssignClassValueEx("bom@utf32be", Value(new Object_binary(env, Binary(Codec::BOM_UTF32BE, 4), false)));
}

bool Class_codec::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_string()) {
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

}
