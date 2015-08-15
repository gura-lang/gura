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

bool Class_nil::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_nil::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_nil::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	value = Value::Nil;
	return true;
}

bool Class_nil::Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_u(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_b(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_o(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_x(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_e(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_f(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_g(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_s(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_c(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

}
