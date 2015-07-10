//=============================================================================
// Gura class: nil
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_nil::Class_nil(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_nil)
{
}

void Class_nil::Prepare(Environment &env)
{
}

bool Class_nil::CastFrom(Environment &env, Signal &sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_nil::Serialize(Environment &env, Signal &sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_nil::Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

bool Class_nil::Format_d(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_u(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_b(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_o(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_x(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_e(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_f(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_g(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_s(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_c(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutInvalid(sig, flags);
}

}
