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

bool Class_nil::CastFrom(Environment &env, Signal &__to_delete__, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_nil::Serialize(Environment &env, Signal &__to_delete__, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_nil::Deserialize(Environment &env, Signal &__to_delete__, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

bool Class_nil::Format_d(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_u(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_b(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_o(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_x(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_e(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_f(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_g(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_s(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_nil::Format_c(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

}
