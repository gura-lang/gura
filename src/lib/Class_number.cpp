//=============================================================================
// Gura class: number
//=============================================================================
#include "stdafx.h"

namespace Gura {
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
Class_number::Class_number(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_number)
{
}

void Class_number::Prepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(number, Value(Reference()));
	// value assignment
	Gura_AssignClassValueEx("max@char", Value(127));
	Gura_AssignClassValueEx("min@char", Value(-128));
	Gura_AssignClassValueEx("max@uchar", Value(255));
	Gura_AssignClassValueEx("min@uchar", Value(0));
	Gura_AssignClassValueEx("max@short", Value(32767));
	Gura_AssignClassValueEx("min@short", Value(-32768));
	Gura_AssignClassValueEx("max@ushort", Value(65535));
	Gura_AssignClassValueEx("min@ushort", Value(0));
	Gura_AssignClassValueEx("max@int32", Value(2147483647));
	Gura_AssignClassValueEx("min@int32", Value(-2147483648.));
	Gura_AssignClassValueEx("max@uint32", Value(4294967295));
	Gura_AssignClassValueEx("min@uint32", Value(0));
	Gura_AssignClassValueEx("size@char", Value(1));
	Gura_AssignClassValueEx("size@uchar", Value(1));
	Gura_AssignClassValueEx("size@short", Value(2));
	Gura_AssignClassValueEx("size@ushort", Value(2));
	Gura_AssignClassValueEx("size@int32", Value(4));
	Gura_AssignClassValueEx("size@uint32", Value(4));
	Gura_AssignClassValueEx("size@int64", Value(8));
	Gura_AssignClassValueEx("size@uint64", Value(8));
	Gura_AssignClassValueEx("size@float", Value(4));
	Gura_AssignClassValueEx("size@double", Value(8));
	// method assignment
	Gura_AssignMethod(number, roundoff);	// primitive method
	// help document
	AddHelp(
		Gura_Symbol(en),
		R"**(
)**");
}

Value Class_number::GetPropPrimitive(const Value &valueThis,
				const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(abs))) {
		double num = valueThis.GetDouble();
		return Value(::fabs(num));
	} else if (pSymbol->IsIdentical(Gura_Symbol(arg))) {
		return Value::Zero;
	} else if (pSymbol->IsIdentical(Gura_Symbol(imag))) {
		return Value::Zero;
	} else if (pSymbol->IsIdentical(Gura_Symbol(norm))) {
		double num = valueThis.GetDouble();
		return Value(num * num);
	} else if (pSymbol->IsIdentical(Gura_Symbol(real))) {
		double num = valueThis.GetDouble();
		return Value(num);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

bool Class_number::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
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

bool Class_number::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	return stream.SerializeDouble(sig, value.GetDouble());
}

bool Class_number::Deserialize(Environment &env, Stream &stream, Value &value) const
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
