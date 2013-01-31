//
// Object_codec
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_codec
//-----------------------------------------------------------------------------
Object_codec::~Object_codec()
{
	ReleaseCodec();
}

Object *Object_codec::Clone() const
{
	return NULL;
}

bool Object_codec::InstallCodec(Signal sig, const char *encoding, bool processEOLFlag)
{
	if (encoding == NULL) encoding = "us-ascii";
	CodecFactory *pCodecFactory = CodecFactory::Lookup(encoding);
	if (pCodecFactory == NULL) {
		sig.SetError(ERR_CodecError, "unsupported encoding name %s", encoding);
		return false;
	}
	ReleaseCodec();
	_encoding = encoding;
	_pEncoder.reset(pCodecFactory->CreateEncoder(processEOLFlag));
	_pDecoder.reset(pCodecFactory->CreateDecoder(processEOLFlag));
	return true;
}

void Object_codec::ReleaseCodec()
{
	_encoding.clear();
	_pEncoder.reset(NULL);
	_pDecoder.reset(NULL);
}

String Object_codec::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<codec:";
	str += _encoding;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// codec(encoding:string, process_eol:boolean => false) {block?}
Gura_DeclareFunction(codec)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "encoding", VTYPE_string);
	DeclareArg(env, "process_eol", VTYPE_boolean,
						OCCUR_Once, FLAG_None, new Expr_Value(Value(false)));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_codec));
}

Gura_ImplementFunction(codec)
{
	Object_codec *pObj = new Object_codec(env);
	if (!pObj->InstallCodec(sig, args.GetString(0), args.GetBoolean(1))) {
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_codec
//-----------------------------------------------------------------------------
// codec.dir()
Gura_DeclareClassMethod(codec, dir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp(
	"Returns a list of character codecs that are registered.");
}

Gura_ImplementClassMethod(codec, dir)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (CodecFactory::List, ppCodecFactory, CodecFactory::GetList()) {
		const CodecFactory *pCodecFactory = *ppCodecFactory;
		valList.push_back(Value(env, pCodecFactory->GetName()));
	}
	return result;
}

// codec#encode(string:string):map
Gura_DeclareMethod(codec, encode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string);
	SetHelp("");
}

Gura_ImplementMethod(codec, encode)
{
	Object_codec *pThis = Object_codec::GetThisObj(args);
	Binary dst;
	if (!pThis->GetEncoder()->Encode(sig, dst, args.GetString(0))) {
		return Value::Null;
	}
	Value result;
	result.InitAsBinary(env, dst, true);
	return result;
}

// codec#decode(buff:binary):map
Gura_DeclareMethod(codec, decode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buff", VTYPE_binary);
	SetHelp("");
}

Gura_ImplementMethod(codec, decode)
{
	Object_codec *pThis = Object_codec::GetThisObj(args);
	String dst;
	if (!pThis->GetDecoder()->Decode(sig, dst, args.GetBinary(0))) {
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
	Gura_AssignMethod(codec, encode);
	Gura_AssignMethod(codec, decode);
}

bool Class_codec::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsString()) {
		Object_codec *pObj = new Object_codec(env);
		if (!pObj->InstallCodec(sig, value.GetString(), false)) {
			return false;
		}
		value = Value(pObj);
		return true;
	}
	return false;
}

Object *Class_codec::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_codec::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(codec);
}

}
