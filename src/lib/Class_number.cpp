//=============================================================================
// Gura class: number
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// number#abs
Gura_DeclareProperty_R(number, abs)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(number, abs)
{
	double num = valueThis.GetDouble();
	return Value(::fabs(num));
}

// number#arg:[deg]
Gura_DeclareProperty_R(number, arg)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(number, arg)
{
	return Value::Zero;
}

// number#imag
Gura_DeclareProperty_R(number, imag)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(number, imag)
{
	return Value::Zero;
}

// number#norm
Gura_DeclareProperty_R(number, norm)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(number, norm)
{
	double num = valueThis.GetDouble();
	return Value(num * num);
}

// number#real
Gura_DeclareProperty_R(number, real)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(number, real)
{
	double num = valueThis.GetDouble();
	return Value(num);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// number#roundoff(threshold:number => 1e-10)
Gura_DeclareMethodPrimitive(number, roundoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None, 0,
											new Expr_Value(RoundOffThreshold));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(number, roundoff)
{
	double num = arg.GetValueThis().GetDouble();
	double numAbs = (num >= 0)? num : -num;
	if (numAbs < arg.GetDouble(0)) num = 0;
	return Value(num);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_number::Class_number(Environment *pEnvOuter) : ClassPrimitive(pEnvOuter, VTYPE_number)
{
}

void Class_number::DoPrepare(Environment &env)
{
	// Assignment of class
	Gura_AssignValue(number, Value(Reference()));
	// Assignment of values
	Gura_AssignClassValueEx("max@int8",		Value(static_cast<Int8>(127)));
	Gura_AssignClassValueEx("min@int8",		Value(static_cast<Int8>(-128)));
	Gura_AssignClassValueEx("max@uint8",	Value(static_cast<UInt8>(255)));
	Gura_AssignClassValueEx("min@uint8",	Value(static_cast<UInt>(0)));
	Gura_AssignClassValueEx("max@int16",	Value(static_cast<Int16>(32767)));
	Gura_AssignClassValueEx("min@int16",	Value(static_cast<Int16>(-32768)));
	Gura_AssignClassValueEx("max@uint16",	Value(static_cast<UInt16>(65535)));
	Gura_AssignClassValueEx("min@uint16",	Value(static_cast<UInt16>(0)));
	Gura_AssignClassValueEx("max@int32",	Value(static_cast<Int32>(2147483647)));
	Gura_AssignClassValueEx("min@int32",	Value(static_cast<Int32>(-2147483648)));
	Gura_AssignClassValueEx("max@uint32",	Value(static_cast<UInt32>(4294967295)));
	Gura_AssignClassValueEx("min@uint32",	Value(0));
	Gura_AssignClassValueEx("size@int8",	Value(1));
	Gura_AssignClassValueEx("size@uint8",	Value(1));
	Gura_AssignClassValueEx("size@int16",	Value(2));
	Gura_AssignClassValueEx("size@uint16",	Value(2));
	Gura_AssignClassValueEx("size@int32",	Value(4));
	Gura_AssignClassValueEx("size@uint32",	Value(4));
	Gura_AssignClassValueEx("size@int64",	Value(8));
	Gura_AssignClassValueEx("size@uint64",	Value(8));
	Gura_AssignClassValueEx("size@float",	Value(4));
	Gura_AssignClassValueEx("size@double",	Value(8));
	// Assignment of properties
	Gura_AssignProperty(number, abs);
	Gura_AssignProperty(number, arg);
	Gura_AssignProperty(number, imag);
	Gura_AssignProperty(number, norm);
	Gura_AssignProperty(number, real);
	// Assignment of method
	Gura_AssignMethod(number, roundoff);	// primitive method
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_number::CastFrom(Environment &env, Value &value, ULong flags)
{
	bool allowPartFlag = false;
	bool successFlag = false;
	double num = value.ToNumber(allowPartFlag, successFlag);
	if (successFlag) {
		value = Value(num);
		return true;
	}
	//sig.SetError(ERR_ValueError, "failed to convert to a number");
	return false;
}

Class::SerializeFmtVer Class_number::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_number::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	return stream.SerializeDouble(sig, value.GetDouble());
}

bool Class_number::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	Signal &sig = GetSignal();
	double num = 0;
	if (!stream.DeserializeDouble(sig, num)) return false;
	value = Value(num);
	return true;
}

bool Class_number::Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_d(flags,
						value.GetInt64(), buff, sizeof(buff)));
}

bool Class_number::Format_u(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_u(flags,
						value.GetUInt64(), buff, sizeof(buff)));
}

bool Class_number::Format_b(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_b(flags,
						value.GetUInt64(), buff, sizeof(buff)));
}

bool Class_number::Format_o(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_o(flags,
						value.GetUInt64(), buff, sizeof(buff)));
}

bool Class_number::Format_x(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_x(flags,
						value.GetUInt64(), buff, sizeof(buff)));
}

bool Class_number::Format_e(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	if (flags.precision == Formatter::PREC_Null) flags.precision = Formatter::PREC_Default;
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_e(flags,
						value.GetNumber(), buff, sizeof(buff)));
}

bool Class_number::Format_f(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	if (flags.precision == Formatter::PREC_Null) flags.precision = Formatter::PREC_Default;
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_f(flags,
						value.GetNumber(), buff, sizeof(buff)));
}

bool Class_number::Format_g(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	if (flags.precision == Formatter::PREC_Null) flags.precision = Formatter::PREC_Default;
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_g(flags,
						value.GetNumber(), buff, sizeof(buff)));
}

bool Class_number::Format_c(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutChar(sig, value.GetChar());
}

}
