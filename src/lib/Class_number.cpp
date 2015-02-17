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
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(number, roundoff)
{
	double num = args.GetThis().GetDouble();
	double numAbs = (num >= 0)? num : -num;
	if (numAbs < args.GetDouble(0)) num = 0;
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
	// method assignment
	Gura_AssignMethod(number, roundoff);	// primitive method
}

Value Class_number::GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
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
	return Value::Null;
}

bool Class_number::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
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

bool Class_number::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return stream.SerializeDouble(sig, value.GetDouble());
}

bool Class_number::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	double num = 0;
	if (!stream.DeserializeDouble(sig, num)) return false;
	value = Value(num);
	return true;
}

bool Class_number::Format_d(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_d(flags,
						static_cast<int>(value.GetNumber()), buff, sizeof(buff)));
}

bool Class_number::Format_u(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_u(flags,
						static_cast<UInt>(value.GetNumber()), buff, sizeof(buff)));
}

bool Class_number::Format_b(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_b(flags,
						static_cast<UInt>(value.GetNumber()), buff, sizeof(buff)));
}

bool Class_number::Format_o(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_o(flags,
						static_cast<UInt>(value.GetNumber()), buff, sizeof(buff)));
}

bool Class_number::Format_x(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_x(flags,
						static_cast<UInt>(value.GetNumber()), buff, sizeof(buff)));
}

bool Class_number::Format_e(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	if (flags.precision == Formatter::PREC_Null) flags.precision = Formatter::PREC_Default;
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_e(flags,
						value.GetNumber(), buff, sizeof(buff)));
}

bool Class_number::Format_f(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	if (flags.precision == Formatter::PREC_Null) flags.precision = Formatter::PREC_Default;
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_f(flags,
						value.GetNumber(), buff, sizeof(buff)));
}

bool Class_number::Format_g(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	if (flags.precision == Formatter::PREC_Null) flags.precision = Formatter::PREC_Default;
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_g(flags,
						value.GetNumber(), buff, sizeof(buff)));
}

bool Class_number::Format_c(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutChar(sig, static_cast<char>(value.GetNumber()));
}

}
