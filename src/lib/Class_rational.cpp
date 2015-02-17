//=============================================================================
// Gura class: rational
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// rational(numer:number, denom?:number):map {block?}
Gura_DeclareFunction(rational)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numer", VTYPE_number);
	DeclareArg(env, "denom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_rational));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Creates a rational value.");
}

Gura_ImplementFunction(rational)
{
	int numer = args.GetInt(0);
	int denom = args.Is_number(1)? args.GetInt(1) : 1;
	if (denom == 0) {
		sig.SetError(ERR_ZeroDivisionError, "denominator can't be zero");
		return Value::Null;
	}
	if (denom < 0) {
		numer = -numer, denom = -denom;
	}
	return ReturnValue(env, sig, args, Value(Rational(numer, denom)));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// rational#reduce()
Gura_DeclareMethodPrimitive(rational, reduce)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(rational, reduce)
{
	const Rational &num = args.GetThis().GetRational();
	return Value(num.Reduce());
}

//-----------------------------------------------------------------------------
// Implementation of suffix manager
//-----------------------------------------------------------------------------
Gura_ImplementSuffixMgrForNumber(r)
{
	bool successFlag = false;
	Number num = ToNumber(body, &successFlag);
	if (!successFlag) {
		sig.SetError(ERR_ValueError, "invalid number format");
		return Value::Null;
	}
	return Value(Rational::FromNumber(num));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_rational::Class_rational(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_rational)
{
}

void Class_rational::Prepare(Environment &env)
{
	// function assignment
	Gura_AssignFunction(rational);
	// method assignment
	Gura_AssignMethod(rational, reduce);		// primitive method
	// suffix manager assignment
	Gura_AssignSuffixMgrForNumber(r);
}

Value Class_rational::GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
				const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(denom))) {
		const Rational &num = valueThis.GetRational();
		return Value(num.denom);
	} else if (pSymbol->IsIdentical(Gura_Symbol(numer))) {
		const Rational &num = valueThis.GetRational();
		return Value(num.numer);
	}
	evaluatedFlag = false;
	return Value::Null;
}

bool Class_rational::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_number()) {		// cast number to rational
		return true;
	}
	return false;
}

bool Class_rational::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	const Rational *pRatio = value.GetRationalPtr();
	if (!stream.SerializeDouble(sig, pRatio->numer)) return false;
	if (!stream.SerializeDouble(sig, pRatio->denom)) return false;
	return true;
}

bool Class_rational::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	double numer = 0, denom = 0;
	if (!stream.DeserializeDouble(sig, numer)) return false;
	if (!stream.DeserializeDouble(sig, denom)) return false;
	if (denom == 0) {
		sig.SetError(ERR_ZeroDivisionError, "denominator can't be zero");
		return false;
	}
	value = Value(Rational(static_cast<int>(numer), static_cast<int>(denom)));
	return true;
}

bool Class_rational::Format_d(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	const Rational &num = value.GetRational();
	if (!pFormatter->PutAlignedString(sig, flags, Formatter::Format_d(flags,
									num.numer, buff, sizeof(buff)))) return false;
	if (!pFormatter->PutChar(sig, '/')) return false;
	if (!pFormatter->PutAlignedString(sig, flags, Formatter::Format_d(flags,
									num.denom, buff, sizeof(buff)))) return false;
	if (!pFormatter->PutChar(sig, 'r')) return false;
	return true;
}

}
