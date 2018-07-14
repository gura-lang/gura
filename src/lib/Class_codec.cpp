//=============================================================================
// Gura class: codec
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
# Overview

The `codec` class has features to decoding/encoding character codes stored in `string` and `binary`.
Following measures are provided:

- Decode .. Converts specific character codes stored in `binary` into UTF-8 code
  and generages `string` containing the result.
  It can also delete a CR code (`0x0d`) before a LF code (`0x0d`) at each end of line
  so that lines in the result are joined with LF code.
- Encode .. Converts UTF-8 character codes stored in `string` into specific codes
  and generates `binary` containing the result.
  It can also add a CR code (`0x0d`) before a LF code (`0x0a`) at each end of line
  so that lines in the result are joined with CR-LF sequence.

You can utilize these functions using `codec` class's methods `codec#decode()` and `codec#encode()`
as well as using `stream` class's method to read/write text by specifying `codec` instance
when creating its instance.

The actual functions for encoding and decoding are provided by sub modules under `codecs` module.
Each module provides following codecs:

- `codecs.basic` .. `us-ascii`, `utf-8`, `utf-16`, `utf-16le`, `utf-16be`
- `codecs.iso8859`.. `iso-8859-1`, `iso-8859-2`, `iso-8859-3`, `iso-8859-4`, `iso-8859-5`,
  `iso-8859-6`, `iso-8859-7`, `iso-8859-8`, `iso-8859-9`, `iso-8859-10`, `iso-8859-11`,
  `iso-8859-13`, `iso-8859-14`, `iso-8859-15`, `iso-8859-16
- `codecs.korean` .. `cp949`, `euc-kr`
- `codecs.chinese` .. `cp936`, `gb2312`, `gbk`, `cp950`, `big5`
- `codecs.japanese` .. `euc-jp`, `cp932`, `shift_jis`, `ms_kanji`, `jis`, `iso-2022-jp`

Importing other codec modules would expand available codecs.
You can call `codecs.dir()` to get a list of codec names currently available.


# Predefined Variable

<table>
<tr><th>Variable</th><th>Type</th><th>Explanation</th></tr>

<tr><td><code>codec.bom@utf8</code></td><td><code>binary</code></td>
<td>BOM for UTF-8: <code>b'\xef\xbb\xbf'</code></td></tr>

<tr><td><code>codec.bom@utf16le</code></td><td><code>binary</code></td>
<td>BOM for UTF-16 little endian: <code>b'\xff\xfe'</code></td></tr>

<tr><td><code>codec.bom@utf16be</code></td><td><code>binary</code></td>
<td>BOM for UTF-16 big endian: <code>b'\xfe\xff'</code></td></tr>

<tr><td><code>codec.bom@utf32le</code></td><td><code>binary</code></td>
<td>BOM for UTF-32 little endian: <code>b'\xff\xfe\x00\x00'</code></td></tr>

<tr><td><code>codec.bom@utf32be</code></td><td><code>binary</code></td>
<td>BOM for UTF-32 big endian: <code>b'\x00\x00\xfe\xff'</code></td></tr>

</table>


# Constructor

${markdown.makedoc@function(`en
codec
)}


# Method

${markdown.makedoc@function(`en
codec.addcr
codec.decode
codec.delcr
codec.encode
)}


# Cast Operation

A function that expects a `codec` instance in its argument can also take a value of
`string` that is recognized as a codec name.

With the above casting feature, you can call a function `f(codec:codec)`
that takes a `codec` instance in its argument as below:

- ``f(codec('utf-16'))`` .. The most explicit way.
- `f('utf-16')` .. Implicit casting: from `string` to `codec`.
)**";

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
		Gura_Symbol(en),
		"Creates a `codec` instance of the specified encoding name.\n"
		"You can call `codecs.dir()` to get a list of available encoding names.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("codec", "codec"));
}

Gura_ImplementFunction(codec)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Codec> pCodec(Codec::CreateCodec(sig, arg.GetString(0), true, false));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_codec(env, pCodec.release())));
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
		Gura_Symbol(en),
		"The codec's encoder has a feature\n"
		"to add a CR code (`0x0d`) before a LF code (`0x0a`)\n"
		"so that the lines are joined with CR-LF codes in the encoded result.\n"
		"This method enables or disables the feature.\n"
		"\n"
		"- To enable it, call the method with the argument `flag` set to `true` or without any argument.\n"
		"- To disable it, call the method with the argument `flag` set to `false`.\n");
}

Gura_ImplementMethod(codec, addcr)
{
	Object_codec *pThis = Object_codec::GetObjectThis(arg);
	Codec::Encoder *pEncoder = pThis->GetCodec()->GetEncoder();
	pEncoder->SetAddcrFlag(arg.IsValid(0)? arg.GetBoolean(0) : true);
	return arg.GetValueThis();
}

// codec#decode(buff:binary):map
Gura_DeclareMethod(codec, decode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buff", VTYPE_binary);
	AddHelp(
		Gura_Symbol(en),
		"Decodes a binary `buff` and returns the decoded result as `string`.\n");
}

Gura_ImplementMethod(codec, decode)
{
	Signal &sig = env.GetSignal();
	Object_codec *pThis = Object_codec::GetObjectThis(arg);
	String dst;
	if (!pThis->GetCodec()->GetDecoder()->Decode(sig, dst, arg.GetBinary(0))) {
		return Value::Nil;
	}
	return Value(dst);
}

// codec#delcr(flag?:boolean):reduce
Gura_DeclareMethod(codec, delcr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"The codec's decoder has a feature\n"
		"to delete a CR code (`0x0d`) before a LF code (`0x0a`)\n"
		"so that the lines are joined with LF code in the decoded result.\n"
		"This method enables or disables the feature.\n"
		"\n"
		"- To enable it, call the method with the argument `flag` set to `true` or without any argument.\n"
		"- To disable it, call the method with the argument `flag` set to `false`.\n");
}

Gura_ImplementMethod(codec, delcr)
{
	Object_codec *pThis = Object_codec::GetObjectThis(arg);
	Codec::Decoder *pDecoder = pThis->GetCodec()->GetDecoder();
	pDecoder->SetDelcrFlag(arg.IsValid(0)? arg.GetBoolean(0) : true);
	return arg.GetValueThis();
}

// codec#encode(str:string):map
Gura_DeclareMethod(codec, encode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Encodes a string `str` and returns the encoded result as `binary`.\n");
}

Gura_ImplementMethod(codec, encode)
{
	Signal &sig = env.GetSignal();
	Object_codec *pThis = Object_codec::GetObjectThis(arg);
	Binary dst;
	if (!pThis->GetCodec()->GetEncoder()->Encode(sig, dst, arg.GetString(0))) {
		return Value::Nil;
	}
	return Value(new Object_binary(env, dst, true));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_codec::Class_codec(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_codec)
{
}

void Class_codec::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(codec);
	// Assignment of methods
	Gura_AssignMethod(codec, addcr);
	Gura_AssignMethod(codec, decode);
	Gura_AssignMethod(codec, delcr);
	Gura_AssignMethod(codec, encode);
	// Assignment of classes
	Gura_AssignClassValueEx("bom@utf8", Value(new Object_binary(env, Codec::BOM_UTF8, false)));
	Gura_AssignClassValueEx("bom@utf16le", Value(new Object_binary(env, Codec::BOM_UTF16LE, false)));
	Gura_AssignClassValueEx("bom@utf16be", Value(new Object_binary(env, Codec::BOM_UTF16BE, false)));
	Gura_AssignClassValueEx("bom@utf32le", Value(new Object_binary(env, Binary(Codec::BOM_UTF32LE, 4), false)));
	Gura_AssignClassValueEx("bom@utf32be", Value(new Object_binary(env, Binary(Codec::BOM_UTF32BE, 4), false)));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_codec::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	if (value.Is_string()) {
		AutoPtr<Codec> pCodec(Codec::CreateCodec(sig, value.GetString(), true, false));
		if (sig.IsSignalled()) return false;
		value = Value(new Object_codec(env, pCodec.release()));
		return true;
	}
	return false;
}

Object *Class_codec::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
