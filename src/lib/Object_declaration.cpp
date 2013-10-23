//
// Object_declaration
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gura interfaces for declaration
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Object implementation for declaration
//-----------------------------------------------------------------------------
Object *Object_declaration::Clone() const
{
	return new Object_declaration(*this);
}

bool Object_declaration::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(values));
	return true;
}

Value Object_declaration::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(values))) {
		Value rtn;
		rtn.InitAsList(env, _pArgs->GetValueListArg());
		return rtn;
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

String Object_declaration::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<declaration:";
	str += ">";
	return str;
}

//----------------------------------------------------------------------------
// Class implementation for declaration
//----------------------------------------------------------------------------
Class_declaration::Class_declaration(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_declaration)
{
}

void Class_declaration::Prepare(Environment &env)
{
}

}
