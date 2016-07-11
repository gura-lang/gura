//=============================================================================
// Class_configuration.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_configuration
//-----------------------------------------------------------------------------
Object_configuration::~Object_configuration()
{
}

Object *Object_configuration::Clone() const
{
	return nullptr;
}

bool Object_configuration::DoDirProp(Environment &env, SymbolSet &symbols)
{
#if 0
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(elem));
#endif
	return true;
}

Value Object_configuration::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(elem))) {
		return _pElem.IsNull()? Value::Nil : Value(new Object_elem(_pElem->Reference()));
	}
	evaluatedFlag = false;
#endif
	return Value::Nil;
}

String Object_configuration::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.configuration:";
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
// doxygen.configuration(stream?:stream) {block?}
Gura_DeclareFunction(configuration)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(configuration));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(configuration)
{
	Stream &stream = arg.GetStream(0);
	AutoPtr<Configuration> pCfg(new Configuration());
	if (!pCfg->ReadStream(env, stream)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_configuration(pCfg.release())));
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for doxygen.configuration
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(configuration)
{
	Gura_AssignFunction(configuration);
}

Gura_ImplementCastFrom(configuration)
{
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, pDecl);
	if (value.Is_stream()) {
		Stream &stream = value.GetStream();
		AutoPtr<Configuration> pCfg(new Configuration());
		if (!pCfg->ReadStream(env, stream)) return false;
		value = Value(new Object_configuration(pCfg.release()));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(configuration)
{
	return false;
}

Gura_EndModuleScope(doxygen)
