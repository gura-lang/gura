//=============================================================================
// Gura class: undefined
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_undefined::Class_undefined(Environment *pEnvOuter) : ClassPrimitive(pEnvOuter, VTYPE_undefined)
{
}

void Class_undefined::DoPrepare(Environment &env)
{
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_undefined::CastFrom(Environment &env, Value &value, ULong flags)
{
	return false;
}

Class::SerializeFmtVer Class_undefined::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_undefined::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_undefined::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	value = Value::Nil;
	return true;
}

bool Class_undefined::Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_u(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_b(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_o(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_x(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
 }

bool Class_undefined::Format_e(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_f(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_g(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_s(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

bool Class_undefined::Format_c(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutInvalid(sig, flags);
}

}
