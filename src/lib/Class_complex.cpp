//=============================================================================
// Gura class: complex
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// complex(real:number, imag?:number):map {block?}
Gura_DeclareFunction(complex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "real", VTYPE_number);
	DeclareArg(env, "imag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_complex));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `complex` instance with a real part `real` and an imaginary part `imag`.\n"
		"\n"
		"If the argument `imag` is omitted, the imaginary part would be set to zero.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("n", "complex"));
}

Gura_ImplementFunction(complex)
{
	double real = args.GetDouble(0);
	double imag = args.Is_number(1)? args.GetDouble(1) : 0;
	return ReturnValue(env, sig, args, Value(Complex(real, imag)));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// complex.polar(abs:number, arg:number):map:[deg] {block?}
Gura_DeclareClassMethod(complex, polar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "abs", VTYPE_number);
	DeclareArg(env, "arg", VTYPE_number);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `complex` instance with an absolute number `abs`\n"
		"and an angle `arg` in polar coords.\n"
		"\n"
		"The argument `arg` is specified in a unit of radian.\n"
		"You can give it a degree value by calling the function with `:deg` attribute.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("n", "complex"));
}

Gura_ImplementClassMethod(complex, polar)
{
	double abs = args.GetDouble(0);
	double arg = args.GetDouble(1);
	if (args.IsSet(Gura_Symbol(deg))) arg = DegToRad(arg);
	return ReturnValue(env, sig, args, Value(Complex::Polar(abs, arg)));
}

// complex#roundoff(threshold:number => 1e-10) {block?}
Gura_DeclareMethodPrimitive(complex, roundoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a complex number with real and imaginary parts being rounded off.\n"
		"\n"
		"The argument `threshold` specifies the threshold value for the round-off.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("n", "complex"));
}

Gura_ImplementMethod(complex, roundoff)
{
	Complex num = args.GetThis().GetComplex();
	double numThreshold = args.GetDouble(0);
	double real = num.real(), imag = num.imag();
	double realAbs = (real >= 0)? real : -real;
	double imagAbs = (imag >= 0)? imag : -imag;
	if (realAbs < numThreshold) real = 0;
	if (imagAbs < numThreshold) imag = 0;
	if (imag == 0) return Value(real);
	return ReturnValue(env, sig, args, Value(Complex(real, imag)));
}

//-----------------------------------------------------------------------------
// Implementation of suffix manager
//-----------------------------------------------------------------------------
Gura_ImplementSuffixMgrForNumber(j)
{
	bool successFlag = false;
	Number num = ToNumber(body, &successFlag);
	if (!successFlag) {
		sig.SetError(ERR_ValueError, "invalid number format");
		return Value::Null;
	}
	return Value(Complex(0, num));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_complex::Class_complex(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_complex)
{
}

void Class_complex::Prepare(Environment &env)
{
	// function assignment
	Gura_AssignFunction(complex);
	// methods assignment
	Gura_AssignMethod(complex, polar);
	Gura_AssignMethod(complex, roundoff);	// primitive method
	// suffix manager assignment
	Gura_AssignSuffixMgrForNumber(j);
}

Value Class_complex::GetPropPrimitive(Environment &env, Signal &sig, const Value &valueThis,
				const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(abs))) {
		Complex num = valueThis.GetComplex();
		return Value(std::abs(num));
	} else if (pSymbol->IsIdentical(Gura_Symbol(arg))) {
		Complex num = valueThis.GetComplex();
		double arg = std::arg(num);
		if (attrs.IsSet(Gura_Symbol(deg))) arg = RadToDeg(arg);
		return Value(arg);
	} else if (pSymbol->IsIdentical(Gura_Symbol(imag))) {
		Complex num = valueThis.GetComplex();
		return Value(num.imag());
	} else if (pSymbol->IsIdentical(Gura_Symbol(norm))) {
		Complex num = valueThis.GetComplex();
		return Value(std::norm(num));
	} else if (pSymbol->IsIdentical(Gura_Symbol(real))) {
		Complex num = valueThis.GetComplex();
		return Value(num.real());
	}
	evaluatedFlag = false;
	return Value::Null;
}

bool Class_complex::CastFrom(Environment &env, Signal &sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_number()) {		// cast number to complex
		return true;
	} else if (value.Is_rational()) {
		bool allowPartFlag = false;
		bool successFlag = false;
		Number num = value.ToNumber(allowPartFlag, successFlag);
		if (successFlag) {
			value = Value(num);
			return true;
		}
	}
	return false;
}

bool Class_complex::Serialize(Environment &env, Signal &sig, Stream &stream, const Value &value) const
{
	const Complex *pComp = value.GetComplexPtr();
	if (!stream.SerializeDouble(sig, pComp->real())) return false;
	if (!stream.SerializeDouble(sig, pComp->imag())) return false;
	return true;
}

bool Class_complex::Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const
{
	double re = 0, im = 0;
	if (!stream.DeserializeDouble(sig, re)) return false;
	if (!stream.DeserializeDouble(sig, im)) return false;
	value = Value(Complex(re, im));
	return true;
}

bool Class_complex::Format_e(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	const Complex &num = value.GetComplex();
	if (!pFormatter->PutAlignedString(sig, flags, Formatter::Format_e(flags,
									num.real(), buff, sizeof(buff)))) return false;
	Formatter::Flags flagsImag = flags;
	flagsImag.plusMode = Formatter::PLUSMODE_Plus;
	if (!pFormatter->PutAlignedString(sig, flagsImag, Formatter::Format_e(flagsImag,
									num.imag(), buff, sizeof(buff)))) return false;
	if (!pFormatter->PutChar(sig, 'j')) return false;
	return true;
}

bool Class_complex::Format_f(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	const Complex &num = value.GetComplex();
	if (!pFormatter->PutAlignedString(sig, flags, Formatter::Format_f(flags,
									num.real(), buff, sizeof(buff)))) return false;
	Formatter::Flags flagsImag = flags;
	flagsImag.plusMode = Formatter::PLUSMODE_Plus;
	if (!pFormatter->PutAlignedString(sig, flagsImag, Formatter::Format_f(flagsImag,
									num.imag(), buff, sizeof(buff)))) return false;
	if (!pFormatter->PutChar(sig, 'j')) return false;
	return true;
}

bool Class_complex::Format_g(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	char buff[128];
	const Complex &num = value.GetComplex();
	if (!pFormatter->PutAlignedString(sig, flags, Formatter::Format_g(flags,
									num.real(), buff, sizeof(buff)))) return false;
	Formatter::Flags flagsImag = flags;
	flagsImag.plusMode = Formatter::PLUSMODE_Plus;
	if (!pFormatter->PutAlignedString(sig, flagsImag, Formatter::Format_g(flagsImag,
									num.imag(), buff, sizeof(buff)))) return false;
	if (!pFormatter->PutChar(sig, 'j')) return false;
	return true;
}

}
