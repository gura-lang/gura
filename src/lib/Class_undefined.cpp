//=============================================================================
// Gura class: undefined
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_undefined::Class_undefined(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_undefined)
{
}

void Class_undefined::Prepare(Environment &env)
{
}

bool Class_undefined::CastFrom(Environment &env, Signal &sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_undefined::Serialize(Environment &env, Signal &sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_undefined::Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

bool Class_undefined::Format_d(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_u(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_b(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_o(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_x(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
 }

bool Class_undefined::Format_e(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_f(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_g(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_s(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_c(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

}
