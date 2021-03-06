//=============================================================================
// Gura class: complex
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
# Overview

The `complex` class provides measures to calculate complex numbers.

You can create a `complex` instance by following ways:

- Calls `complex()` function with a real and imaginary part of numbers. e.g., `complex(2, 3)`
- Calls `complex.polar()` function with an absolute value and an argument in radius.
  e.g., `complex.polar(5, math.pi / 6)`
- Appending `j` suffix after a number literal would create an imaginal part of a complex numbrer.
  e.g., `2 + 3j`


# Constructor

${markdown.makedoc@function(`en
complex
)}


# Method

${markdown.makedoc@function(`en
complex.polar
complex.roundoff
)}
)**";

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
		Gura_Symbol(en),
		"Creates a `complex` instance with a real part `real` and an imaginary part `imag`.\n"
		"\n"
		"If the argument `imag` is omitted, the imaginary part would be set to zero.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("n", "complex"));
}

Gura_ImplementFunction(complex)
{
	double real = arg.GetDouble(0);
	double imag = arg.Is_number(1)? arg.GetDouble(1) : 0;
	return ReturnValue(env, arg, Value(Complex(real, imag)));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// complex#abs
Gura_DeclareProperty_R(complex, abs)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(complex, abs)
{
	Complex *pNum = valueThis.GetComplexPtr();
	return Value(std::abs(*pNum));
}

// complex#arg:[deg]
Gura_DeclareProperty_R(complex, arg)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(complex, arg)
{
	Complex *pNum = valueThis.GetComplexPtr();
	double arg = std::arg(*pNum);
	if (attrs.IsSet(Gura_Symbol(deg))) arg = RadToDeg(arg);
	return Value(arg);
}

// complex#imag
Gura_DeclareProperty_R(complex, imag)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(complex, imag)
{
	Complex *pNum = valueThis.GetComplexPtr();
	return Value(pNum->imag());
}

// complex#norm
Gura_DeclareProperty_R(complex, norm)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(complex, norm)
{
	Complex *pNum = valueThis.GetComplexPtr();
	return Value(std::norm(*pNum));
}

// complex#real
Gura_DeclareProperty_R(complex, real)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(complex, real)
{
	Complex *pNum = valueThis.GetComplexPtr();
	return Value(pNum->real());
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
		Gura_Symbol(en),
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
	double abs = arg.GetDouble(0);
	double arg_ = arg.GetDouble(1);
	if (arg.IsSet(Gura_Symbol(deg))) arg_ = DegToRad(arg_);
	return ReturnValue(env, arg, Value(Complex::Polar(abs, arg_)));
}

// complex#roundoff(threshold:number => 1e-10) {block?}
Gura_DeclareMethodPrimitive(complex, roundoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None, 0,
											new Expr_Value(RoundOffThreshold));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a complex number with real and imaginary parts being rounded off.\n"
		"\n"
		"The argument `threshold` specifies the threshold value for the round-off.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("n", "complex"));
}

Gura_ImplementMethod(complex, roundoff)
{
	Complex num = arg.GetValueThis().GetComplex();
	double numThreshold = arg.GetDouble(0);
	double real = num.real(), imag = num.imag();
	double realAbs = (real >= 0)? real : -real;
	double imagAbs = (imag >= 0)? imag : -imag;
	if (realAbs < numThreshold) real = 0;
	if (imagAbs < numThreshold) imag = 0;
	if (imag == 0) return Value(real);
	return ReturnValue(env, arg, Value(Complex(real, imag)));
}

//-----------------------------------------------------------------------------
// Implementation of suffix manager
//-----------------------------------------------------------------------------
Gura_ImplementSuffixMgrForNumber(j)
{
	Signal &sig = env.GetSignal();
	bool successFlag = false;
	Number num = ToNumber(body, &successFlag);
	if (!successFlag) {
		sig.SetError(ERR_ValueError, "invalid number format");
		return Value::Nil;
	}
	return Value(Complex(0, num));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_complex::Class_complex(Environment *pEnvOuter) : ClassPrimitive(pEnvOuter, VTYPE_complex)
{
}

void Class_complex::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(complex);
	// Assignment of properties
	Gura_AssignProperty(complex, abs);
	Gura_AssignProperty(complex, arg);
	Gura_AssignProperty(complex, imag);
	Gura_AssignProperty(complex, norm);
	Gura_AssignProperty(complex, real);
	// Assignment of methods
	Gura_AssignMethod(complex, polar);
	Gura_AssignMethod(complex, roundoff);	// primitive method
	// Assignment of suffix manager
	Gura_AssignSuffixMgrForNumber(j);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_complex::CastFrom(Environment &env, Value &value, ULong flags)
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

Class::SerializeFmtVer Class_complex::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_complex::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	const Complex *pComp = value.GetComplexPtr();
	if (!stream.SerializeDouble(sig, pComp->real())) return false;
	if (!stream.SerializeDouble(sig, pComp->imag())) return false;
	return true;
}

bool Class_complex::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	if (serializeFmtVer == SerializeFmtVer_1) {
		double re = 0, im = 0;
		if (!stream.DeserializeDouble(env, re)) return false;
		if (!stream.DeserializeDouble(env, im)) return false;
		value = Value(Complex(re, im));
		return true;
	}
	SetError_UnsupportedSerializeFmtVer(serializeFmtVer);
	return false;
}

bool Class_complex::Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	const Complex &num = value.GetComplex();
	if (!pFormatter->PutAlignedString(
			sig, flags, Formatter::Format_d(
				flags, static_cast<Int64>(num.real()), buff, sizeof(buff)))) return false;
	if (num.imag() != 0) {
		Formatter::Flags flagsImag = flags;
		flagsImag.plusMode = Formatter::PLUSMODE_Plus;
		if (!pFormatter->PutAlignedString(
				sig, flagsImag, Formatter::Format_d(
					flagsImag, static_cast<Int64>(num.imag()), buff, sizeof(buff)))) return false;
		if (!pFormatter->PutChar(sig, 'j')) return false;
	}
	return true;
}

bool Class_complex::Format_e(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	const Complex &num = value.GetComplex();
	if (!pFormatter->PutAlignedString(sig, flags, Formatter::Format_e(flags,
									num.real(), buff, sizeof(buff)))) return false;
	if (num.imag() != 0) {
		Formatter::Flags flagsImag = flags;
		flagsImag.plusMode = Formatter::PLUSMODE_Plus;
		if (!pFormatter->PutAlignedString(
				sig, flagsImag, Formatter::Format_e(
					flagsImag, num.imag(), buff, sizeof(buff)))) return false;
		if (!pFormatter->PutChar(sig, 'j')) return false;
	}
	return true;
}

bool Class_complex::Format_f(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	const Complex &num = value.GetComplex();
	if (!pFormatter->PutAlignedString(sig, flags, Formatter::Format_f(flags,
									num.real(), buff, sizeof(buff)))) return false;
	if (num.imag() != 0) {
		Formatter::Flags flagsImag = flags;
		flagsImag.plusMode = Formatter::PLUSMODE_Plus;
		if (!pFormatter->PutAlignedString(
				sig, flagsImag, Formatter::Format_f(
					flagsImag, num.imag(), buff, sizeof(buff)))) return false;
		if (!pFormatter->PutChar(sig, 'j')) return false;
	}
	return true;
}

bool Class_complex::Format_g(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	const Complex &num = value.GetComplex();
	if (!pFormatter->PutAlignedString(sig, flags, Formatter::Format_g(flags,
									num.real(), buff, sizeof(buff)))) return false;
	if (num.imag() != 0) {
		Formatter::Flags flagsImag = flags;
		flagsImag.plusMode = Formatter::PLUSMODE_Plus;
		if (!pFormatter->PutAlignedString(
				sig, flagsImag, Formatter::Format_g(
					flagsImag, num.imag(), buff, sizeof(buff)))) return false;
		if (!pFormatter->PutChar(sig, 'j')) return false;
	}
	return true;
}

}
