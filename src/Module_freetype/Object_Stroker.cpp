#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Stroker implementation
//-----------------------------------------------------------------------------
Object *Object_Stroker::Clone() const
{
	return NULL;
}

String Object_Stroker::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Stroker>");
	return String(buff);
}

bool Object_Stroker::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_Stroker::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Stroker::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Stroker
//-----------------------------------------------------------------------------
// freetype.Stroker.New():map {block?}
Gura_DeclareClassMethod(Stroker, New)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	//SetClassToConstruct(Gura_UserClass(Face));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(Stroker, New)
{
	AutoPtr<Object_Stroker> pObj(new Object_Stroker());
	FT_Error err = ::FT_Stroker_New(g_lib, &pObj->GetEntity());
	if (err != 0) {
		sig.SetError(ERR_RuntimeError, "freetype error");
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

Gura_ImplementUserClass(Stroker)
{
}

}}
