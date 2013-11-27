//
// ClassBasic
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_nil
//-----------------------------------------------------------------------------
Class_nil::Class_nil(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_nil)
{
}

void Class_nil::Prepare(Environment &env)
{
}

bool Class_nil::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_nil::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_nil::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

//-----------------------------------------------------------------------------
// Class_undefined
//-----------------------------------------------------------------------------
Class_undefined::Class_undefined(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_undefined)
{
}

void Class_undefined::Prepare(Environment &env)
{
}

bool Class_undefined::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_undefined::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_undefined::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

//-----------------------------------------------------------------------------
// Class_symbol
//-----------------------------------------------------------------------------
Class_symbol::Class_symbol(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_symbol)
{
}

void Class_symbol::Prepare(Environment &env)
{
}

bool Class_symbol::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_string()) {
		value = Value(Symbol::Add(value.GetString()));
		return true;
	}
	return false;
}

bool Class_symbol::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return stream.SerializeSymbol(sig, value.GetSymbol());
}

bool Class_symbol::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	const Symbol *pSymbol = NULL;
	if (!stream.DeserializeSymbol(sig, &pSymbol)) return false;
	value = Value(pSymbol);
	return true;
}

//-----------------------------------------------------------------------------
// Class_boolean
//-----------------------------------------------------------------------------
Class_boolean::Class_boolean(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_boolean)
{
}

void Class_boolean::Prepare(Environment &env)
{
}

bool Class_boolean::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_list()) {
		return true;
	} else {
		value = Value(value.GetBoolean());
		return true;
	}
}

bool Class_boolean::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return stream.SerializeUChar(sig, static_cast<UChar>(value.GetBoolean()));
}

bool Class_boolean::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	UChar num = 0;
	if (!stream.DeserializeUChar(sig, num)) return false;
	value = Value(num != 0);
	return true;
}

//-----------------------------------------------------------------------------
// Class_number
//-----------------------------------------------------------------------------
// number#roundoff(threshold:number => 1e-10)
Gura_DeclareMethodPrimitive(number, roundoff)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
}

Gura_ImplementMethod(number, roundoff)
{
	double num = args.GetThis().GetDouble();
	double numAbs = (num >= 0)? num : -num;
	if (numAbs < args.GetDouble(0)) num = 0;
	return Value(num);
}

Class_number::Class_number(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_number)
{
}

void Class_number::Prepare(Environment &env)
{
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

//-----------------------------------------------------------------------------
// Class_complex
//-----------------------------------------------------------------------------
// complex(real:number, imag?:number):map {block?}
Gura_DeclareFunction(complex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "real", VTYPE_number);
	DeclareArg(env, "imag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_complex));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates a complex value.");
}

Gura_ImplementFunction(complex)
{
	double real = args.GetDouble(0);
	double imag = args.Is_number(1)? args.GetDouble(1) : 0;
	return ReturnValue(env, sig, args, Value(Complex(real, imag)));
}

// complex.polar(abs:number, angle:number):map:[deg] {block?}
Gura_DeclareClassMethod(complex, polar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "abs", VTYPE_number);
	DeclareArg(env, "arg", VTYPE_number);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates a complex value.");
}

Gura_ImplementClassMethod(complex, polar)
{
	double abs = args.GetDouble(0);
	double arg = args.GetDouble(1);
	if (args.IsSet(Gura_Symbol(deg))) arg = DegToRad(arg);
	return ReturnValue(env, sig, args, Value(Complex::Polar(abs, arg)));
}

// complex#roundoff(threshold:number => 1e-10)
Gura_DeclareMethodPrimitive(complex, roundoff)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
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
	return Value(Complex(real, imag));
}

Class_complex::Class_complex(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_complex)
{
}

void Class_complex::Prepare(Environment &env)
{
	Gura_AssignFunction(complex);
	Gura_AssignMethod(complex, polar);
	Gura_AssignMethod(complex, roundoff);	// primitive method
}

Value Class_complex::GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
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

bool Class_complex::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_number()) {		// cast number to complex
		return true;
	} else if (value.Is_fraction()) {
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

bool Class_complex::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	const Complex *pComp = value.GetComplexPtr();
	if (!stream.SerializeDouble(sig, pComp->real())) return false;
	if (!stream.SerializeDouble(sig, pComp->imag())) return false;
	return true;
}

bool Class_complex::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	double re = 0, im = 0;
	if (!stream.DeserializeDouble(sig, re)) return false;
	if (!stream.DeserializeDouble(sig, im)) return false;
	value = Value(Complex(re, im));
	return true;
}

//-----------------------------------------------------------------------------
// Class_fraction
//-----------------------------------------------------------------------------
// fraction(numer:number, denom?:number):map {block?}
Gura_DeclareFunction(fraction)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numer", VTYPE_number);
	DeclareArg(env, "denom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_fraction));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Creates a fraction value.");
}

Gura_ImplementFunction(fraction)
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
	return ReturnValue(env, sig, args, Value(Fraction(numer, denom)));
}

// fraction#reduce()
Gura_DeclareMethodPrimitive(fraction, reduce)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(fraction, reduce)
{
	const Fraction &num = args.GetThis().GetFraction();
	return Value(num.Reduce());
}

Class_fraction::Class_fraction(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_fraction)
{
}

void Class_fraction::Prepare(Environment &env)
{
	Gura_AssignFunction(fraction);
	Gura_AssignMethod(fraction, reduce);		// primitive method
}

Value Class_fraction::GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
				const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(denom))) {
		const Fraction &num = valueThis.GetFraction();
		return Value(num.denom);
	} else if (pSymbol->IsIdentical(Gura_Symbol(numer))) {
		const Fraction &num = valueThis.GetFraction();
		return Value(num.numer);
	}
	evaluatedFlag = false;
	return Value::Null;
}

bool Class_fraction::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_number()) {		// cast number to fraction
		return true;
	}
	return false;
}

bool Class_fraction::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	const Fraction *pFrac = value.GetFractionPtr();
	if (!stream.SerializeDouble(sig, pFrac->numer)) return false;
	if (!stream.SerializeDouble(sig, pFrac->denom)) return false;
	return true;
}

bool Class_fraction::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	double numer = 0, denom = 0;
	if (!stream.DeserializeDouble(sig, numer)) return false;
	if (!stream.DeserializeDouble(sig, denom)) return false;
	if (denom == 0) {
		sig.SetError(ERR_ZeroDivisionError, "denominator can't be zero");
		return false;
	}
	value = Value(Fraction(static_cast<int>(numer), static_cast<int>(denom)));
	return true;
}

//-----------------------------------------------------------------------------
// Class_string
//-----------------------------------------------------------------------------
// string#align(len:number, padding:string => " "):map:[center,left,right]
Gura_DeclareMethod(string, align)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number);
	DeclareArg(env, "padding", VTYPE_string, OCCUR_Once, FLAG_None, new Expr_String(" "));
	DeclareAttr(Gura_Symbol(center));
	DeclareAttr(Gura_Symbol(left));
	DeclareAttr(Gura_Symbol(right));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string aligned in left, right or center within a specified length.\n"
	"An attribute :center aligns the string in center, :left in left and :right in right\n"
	"An attribute :center is the default behaviour.\n"
	"It fills a padding area with a character specified by an argument padding,\n"
	"and a white space is used when itt is omitted");
}

Gura_ImplementMethod(string, align)
{
	size_t len = args.GetSizeT(0);
	const char *padding = args.GetString(1);
	if (Length(padding) != 1) {
		sig.SetError(ERR_ValueError, "padding must consist of a single character");
		return Value::Null;
	}
	String str;
	if (args.IsSet(Gura_Symbol(right))) {
		str = RJust(args.GetThis().GetString(), len, padding);
	} else if (args.IsSet(Gura_Symbol(left))) {
		str = LJust(args.GetThis().GetString(), len, padding);
	} else {
		str = Center(args.GetThis().GetString(), len, padding);
	}
	return Value(str);
}

// string#binary()
Gura_DeclareMethodPrimitive(string, binary)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(string, binary)
{
	const char *str = args.GetThis().GetString();
	return Value(new Object_binary(env, str, ::strlen(str), true));
}

// string#capitalize()
Gura_DeclareMethod(string, capitalize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string copied from the original one but with the first character\n"
	"capitalized.");
}

Gura_ImplementMethod(string, capitalize)
{
	return Value(Capitalize(args.GetThis().GetString()));
}

// string#chop(suffix*:string):[eol,icase]
Gura_DeclareMethod(string, chop)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "suffix", VTYPE_string, OCCUR_ZeroOrMore);
	DeclareAttr(Gura_Symbol(eol));
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string that removes a last character.\n"
	"If an attribute :eol is specified, only the end-of-line character shall be\n"
	"removed. In this case, if the end-of-line has a sequence of CR-LF, CR code\n"
	"shall be removed as well.");
}

Gura_ImplementMethod(string, chop)
{
	bool eolOnlyFlag = args.IsSet(Gura_Symbol(eol));
	const ValueList &valList = args.GetList(0);
	if (valList.empty()) {
		return Value(Chop(args.GetThis().GetString(), eolOnlyFlag));
	}
	String rtn = args.GetThis().GetStringSTL();
	if (eolOnlyFlag) rtn = Chop(rtn.c_str(), true);
	foreach_const (ValueList, pValue, valList) {
		const char *p1 = rtn.c_str();
		const char *p2 = EndsWith(p1, pValue->GetString(), args.IsSet(Gura_Symbol(icase)));
		if (p2 != NULL) return Value(String(p1, p2));
	}
	return Value(rtn);
}

// string#decodeuri()
Gura_DeclareMethod(string, decodeuri)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string in which percent-encoded characters are decoded.");
}

Gura_ImplementMethod(string, decodeuri)
{
	return Value(DecodeURI(args.GetThis().GetString()));
}

// string#each():[utf8,utf32] {block?}
Gura_DeclareMethod(string, each)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareAttr(Gura_Symbol(utf8));
	DeclareAttr(Gura_Symbol(utf32));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator generating strings of each character in the original one.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |char:string, idx:number|");
}

Gura_ImplementMethod(string, each)
{
	Class_string::IteratorEach::Attr attr =
		args.IsSet(Gura_Symbol(utf8))? Class_string::IteratorEach::ATTR_UTF8 :
		args.IsSet(Gura_Symbol(utf32))? Class_string::IteratorEach::ATTR_UTF32 :
		Class_string::IteratorEach::ATTR_None;
	Iterator *pIterator = new Class_string::IteratorEach(
								args.GetThis().GetStringSTL(), -1, attr);
	return ReturnIterator(env, sig, args, pIterator);
}

// string#eachline(nlines?:number):[chop] {block?}
// conrresponding to file#readlines()
Gura_DeclareMethod(string, eachline)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "nlines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(chop));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator generating strings of each line in the original one.\n"
	"In default, end-of-line characters are involved in the result,\n"
	"and you can eliminates them by specifying :chop attribute.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |line:string, idx:number|");
}

Gura_ImplementMethod(string, eachline)
{
	int maxSplit = args.Is_number(0)? args.GetInt(0) : -1;
	bool includeEOLFlag = !args.IsSet(Gura_Symbol(chop));
	return ReturnIterator(env, sig, args, new Class_string::IteratorLine(
					args.GetThis().GetStringSTL(), maxSplit, includeEOLFlag));
}

// string#encode(codec:codec)
Gura_DeclareMethodPrimitive(string, encode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "codec", VTYPE_codec);
}

Gura_ImplementMethod(string, encode)
{
	Codec *pCodec = Object_codec::GetObject(args, 0)->GetCodec();
	Binary buff;
	if (!pCodec->GetEncoder()->Encode(sig, buff, args.GetThis().GetString())) {
		return Value::Null;
	}
	return Value(new Object_binary(env, buff, true));
}

// string#encodeuri()
Gura_DeclareMethod(string, encodeuri)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string in which non-URIC characters are percent-encoded.");
}

Gura_ImplementMethod(string, encodeuri)
{
	return Value(EncodeURI(args.GetThis().GetString()));
}

// string#endswith(suffix:string, endpos?:number):map:[rest,icase]
Gura_DeclareMethod(string, endswith)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "suffix",	VTYPE_string);
	DeclareArg(env, "endpos",	VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(rest));
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns true if the string ends with suffix. If attribute :rest is specified,\n"
	"it returns the rest part if the string ends with suffix, or nil otherewise.\n"
	"You can specify a bottom position for the matching by an argument endpos.\n"
	"With an attribute :icase, case of characters are ignored while finding.");
}

Gura_ImplementMethod(string, endswith)
{
	const char *str = args.GetThis().GetString();
	bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	const char *rtn = args.Is_number(1)?
		EndsWith(str, args.GetString(0), args.GetInt(1), ignoreCaseFlag) :
		EndsWith(str, args.GetString(0), ignoreCaseFlag);
	if (args.IsSet(Gura_Symbol(rest))) {
		if (rtn == NULL) return Value::Null;
		return Value(str, rtn - str);
	}
	return rtn != NULL;
}

// string#escapehtml():[quote]
Gura_DeclareMethod(string, escapehtml)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(quote));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string that converts characters into escape sequences.");
}

Gura_ImplementMethod(string, escapehtml)
{
	bool quoteFlag = args.IsSet(Gura_Symbol(quote));
	return Value(EscapeHtml(args.GetThis().GetString(), quoteFlag));
}

// string#find(sub:string, pos?:number => 0):map:[icase,rev]
Gura_DeclareMethod(string, find)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sub",	VTYPE_string);
	DeclareArg(env, "pos",	VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareAttr(Gura_Symbol(icase));
	DeclareAttr(Gura_Symbol(rev));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Finds a sub string from the string and returns its position.\n"
	"Number of position starts from zero. You can specify a position to start\n"
	"finding by an argument pos. It returns nil if finding fails.\n"
	"With an attribute :icase, case of characters are ignored while finding.\n"
	"When an attribute :rev is specified, finding starts from tail of the string\n");
}

Gura_ImplementMethod(string, find)
{
	return FindString(env, sig, args.GetThis().GetString(), args.GetString(0),
									args.GetInt(1), args.GetAttrs());
}

// string#fold(len:number, step?:number):[neat] {block?}
Gura_DeclareMethod(string, fold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "len", VTYPE_number);
	DeclareArg(env, "step", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(neat));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that folds string in a specified length.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |sub:string, idx:number|");
}

Gura_ImplementMethod(string, fold)
{
	int cntPerFold = args.GetInt(0);
	int cntStep = args.Is_number(1)? args.GetInt(1) : cntPerFold;
	bool neatFlag = args.IsSet(Gura_Symbol(neat));
	Iterator *pIterator = new Class_string::IteratorFold(
		args.GetThis().GetStringSTL(), cntPerFold, cntStep, neatFlag);
	return ReturnIterator(env, sig, args, pIterator);
}

// string#format(values*):map
Gura_DeclareMethod(string, format)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Parses the content of the string object as a format specifier similar to\n"
	"C language's printf and returns a formatted string of argument values.");
}

Gura_ImplementMethod(string, format)
{
	return Value(Formatter::Format(sig, args.GetThis().GetString(), args.GetList(0)));
}

// string#isempty()
Gura_DeclareMethod(string, isempty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns true if the string is empty.");
}

Gura_ImplementMethod(string, isempty)
{
	return Value(*args.GetThis().GetString() == '\0');
}

// string#left(len?:number):map
Gura_DeclareMethod(string, left)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a copy of the string in len characters from its left side");
}

Gura_ImplementMethod(string, left)
{
	if (!args.Is_number(0)) return args.GetThis();
	return Value(Left(args.GetThis().GetString(), args.GetSizeT(0)));
}

// string#len()
Gura_DeclareMethod(string, len)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns the length of the string in characters.");
}

Gura_ImplementMethod(string, len)
{
	return Value(static_cast<UInt>(Length(args.GetThis().GetString())));
}

// string#lower()
Gura_DeclareMethod(string, lower)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a string of lowercase characters of the original one");
}

Gura_ImplementMethod(string, lower)
{
	return Value(Lower(args.GetThis().GetString()));
}

// string#mid(pos:number => 0, len?:number):map
Gura_DeclareMethod(string, mid)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a copy of part of the string in len characters starting from pos.\n"
	"If an argument len is omitted, it returns a string from pos to its end.\n"
	"Number of an argument pos starts from zero.\n"
	"Example:\n"
	">>> \"Hello world\".mid(3, 2)\n"
	"lo\n"
	">>> \"Hello world\".mid(5)\n"
	"world");
}

Gura_ImplementMethod(string, mid)
{
	return Value(Middle(args.GetThis().GetString(), args.GetInt(0),
						args.Is_number(1)? args.GetInt(1) : -1));
}

// string#parse() {block?}
Gura_DeclareMethod(string, parse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Parse a string returns an expr object.");
}

Gura_ImplementMethod(string, parse)
{
	AutoPtr<Expr_Block> pExpr(new Expr_Block());
	Parser parser(SRCNAME_string);
	if (!parser.ParseString(env, sig, pExpr->GetExprOwner(),
							args.GetThis().GetString())) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_expr(env, pExpr.release())));
}

// string#print(stream?:stream:w):void
Gura_DeclareMethodPrimitive(string, print)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(string, print)
{
	Stream *pStream = args.IsInstanceOf(0, VTYPE_stream)?
								&args.GetStream(0) : env.GetConsole();
	pStream->Print(sig, args.GetThis().GetString());
	return Value::Null;
}

// string#println(stream?:stream:w):void
Gura_DeclareMethodPrimitive(string, println)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(string, println)
{
	Stream *pStream = args.IsInstanceOf(0, VTYPE_stream)?
								&args.GetStream(0) : env.GetConsole();
	pStream->Println(sig, args.GetThis().GetString());
	return Value::Null;
}

// string#reader() {block?}
Gura_DeclareMethod(string, reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, reader)
{
	return ReturnValue(env, sig, args, Value(new Object_stream(env,
		new Stream_StringReader(env, sig, args.GetThis().GetStringSTL()))));
}

// string#replace(sub:string, replace:string, count?:number):map:[icase] {block?}
Gura_DeclareMethod(string, replace)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sub",		VTYPE_string);
	DeclareArg(env, "replace",	VTYPE_string);
	DeclareArg(env, "count",	VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string that substitutes sub strings in the string with replace.\n"
	"An argument count limits the maximum number of substitution\n"
	"and there's no limit if it's omitted.\n"
	"With an attribute :icase,	case of characgters are ignored while finding.");
}

Gura_ImplementMethod(string, replace)
{
	String result = Replace(args.GetThis().GetString(),
			args.GetString(0), args.GetString(1),
			args.Is_number(2)? args.GetInt(2) : -1, args.GetAttrs());
	if (!args.IsBlockSpecified()) return Value(result);
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(result));
	valListArg.push_back(Value(result != args.GetThis().GetStringSTL()));
	return ReturnValues(env, sig, args, valListArg);
}

// string#right(len?:number):map
Gura_DeclareMethod(string, right)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a copy of the string in len characters from its right side");
}

Gura_ImplementMethod(string, right)
{
	if (!args.Is_number(0)) return args.GetThis();
	return Value(Right(args.GetThis().GetString(), args.GetSizeT(0)));
}

// string#split(sep?:string, count?:number):[icase] {block?}
Gura_DeclareMethod(string, split)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator generating sub strings extracted from the original one\n"
	"separated by a specified string sep.\n"
	"With an attribute :icase, case of characgters are ignored while finding.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |sub:string, idx:number|");
}

Gura_ImplementMethod(string, split)
{
	int maxSplit = args.Is_number(1)? args.GetInt(1) : -1;
	Iterator *pIterator = NULL;
	if (args.Is_string(0) && *args.GetString(0) != '\0') {
		const char *sep = args.GetString(0);
		bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
		pIterator = new Class_string::IteratorSplit(
						args.GetThis().GetStringSTL(), sep, maxSplit, ignoreCaseFlag);
	} else {
		pIterator = new Class_string::IteratorEach(args.GetThis().GetStringSTL(),
							maxSplit, Class_string::IteratorEach::ATTR_None);
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// string#startswith(prefix:string, pos:number => 0):map:[rest,icase]
Gura_DeclareMethod(string, startswith)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prefix",	VTYPE_string);
	DeclareArg(env, "pos",		VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareAttr(Gura_Symbol(rest));
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns true if the string starts with prefix. If attribute :rest is specified,\n"
	"it returns the rest part if the string starts with prefix, or nil otherewise.\n"
	"You can specify a top position for the matching by an argument pos.\n"
	"With an attribute :icase, case of characters are ignored while finding.");
}

Gura_ImplementMethod(string, startswith)
{
	const char *rtn = StartsWith(args.GetThis().GetString(), args.GetString(0),
					args.GetInt(1), args.IsSet(Gura_Symbol(icase)));
	if (args.IsSet(Gura_Symbol(rest))) {
		if (rtn == NULL) return Value::Null;
		return Value(rtn);
	}
	return rtn != NULL;
}

// string#strip():[both,left,right]
Gura_DeclareMethod(string, strip)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(both));
	DeclareAttr(Gura_Symbol(left));
	DeclareAttr(Gura_Symbol(right));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string that removes space characters on left, right or both of\n"
	"the original one. An attribute :both removes spaces on both sides, :left on left\n"
	"and :right on right. An attribut :both is the default behaviour.");
}

Gura_ImplementMethod(string, strip)
{
	return Value(Strip(args.GetThis().GetString(), args.GetAttrs()));
}

// string#template(dst?:stream:w):[noindent,lasteol]
Gura_DeclareMethodAlias(string, template_, "template")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Evaluate script coded that is embedded in a string. If stream object dst is\n"
	"specified, the result shall be a destination of the result. Otherwise, it shall\n"
	"be returned as a string value.");
}

Gura_ImplementMethod(string, template_)
{
	bool autoIndentFlag = !args.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = args.IsSet(Gura_Symbol(lasteol));
	String strSrc = args.GetThis().GetStringSTL();
	SimpleStream_StringReader streamSrc(strSrc.begin(), strSrc.end());
	if (args.Is_stream(0)) {
		Stream &streamDst = args.GetStream(0);
		Template::Parser(autoIndentFlag, appendLastEOLFlag).
							EvalStream(env, sig, streamSrc, streamDst);
		return Value::Null;
	} else {
		String strDst;
		SimpleStream_StringWriter streamDst(strDst);
		if (!Template::Parser(autoIndentFlag, appendLastEOLFlag).
					EvalStream(env, sig, streamSrc, streamDst)) return Value::Null;
		return Value(strDst.c_str());
	}
}

// string#unescapehtml()
Gura_DeclareMethod(string, unescapehtml)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string that reverts escaped sequences into characters.");
}

Gura_ImplementMethod(string, unescapehtml)
{
	return Value(UnescapeHtml(args.GetThis().GetString()));
}

// string#upper()
Gura_DeclareMethod(string, upper)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a string of uppercase characters of the original one");
}

Gura_ImplementMethod(string, upper)
{
	return Value(Upper(args.GetThis().GetString()));
}

// string#zentohan()
Gura_DeclareMethod(string, zentohan)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Converts zenkaku to hankaku characters");
}

Gura_ImplementMethod(string, zentohan)
{
	return Value(ZenToHan(args.GetThis().GetString()));
}

Class_string::Class_string(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_string)
{
}

void Class_string::Prepare(Environment &env)
{
	Gura_AssignMethod(string, align);
	Gura_AssignMethod(string, binary);
	Gura_AssignMethod(string, capitalize);
	Gura_AssignMethod(string, chop);
	Gura_AssignMethod(string, decodeuri);
	Gura_AssignMethod(string, each);
	Gura_AssignMethod(string, eachline);
	Gura_AssignMethod(string, encode);
	Gura_AssignMethod(string, encodeuri);
	Gura_AssignMethod(string, endswith);
	Gura_AssignMethod(string, escapehtml);
	Gura_AssignMethod(string, find);
	Gura_AssignMethod(string, fold);
	Gura_AssignMethod(string, format);
	Gura_AssignMethod(string, isempty);
	Gura_AssignMethod(string, left);
	Gura_AssignMethod(string, len);
	Gura_AssignMethod(string, lower);
	Gura_AssignMethod(string, mid);
	Gura_AssignMethod(string, parse);
	Gura_AssignMethod(string, print);
	Gura_AssignMethod(string, println);
	Gura_AssignMethod(string, reader);
	Gura_AssignMethod(string, replace);
	Gura_AssignMethod(string, right);
	Gura_AssignMethod(string, split);
	Gura_AssignMethod(string, startswith);
	Gura_AssignMethod(string, strip);
	Gura_AssignMethod(string, template_);
	Gura_AssignMethod(string, unescapehtml);
	Gura_AssignMethod(string, upper);
	Gura_AssignMethod(string, zentohan);
}

Value Class_string::IndexGetPrimitive(Environment &env, Signal sig,
						const Value &valueThis, const Value &valueIdx) const
{
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number for string");
		return Value::Null;
	}
	int idx = valueIdx.GetInt();
	int len = static_cast<int>(Length(valueThis.GetString()));
	if (idx >= 0) {
		if (idx >= len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return Value::Null;
		}
		return Value(PickChar(valueThis.GetStringSTL(), idx));
	} else {
		if (-idx > len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return Value::Null;
		}
		return Value(PickChar(valueThis.GetStringSTL(), len + idx));
	}
}

bool Class_string::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	value = Value(value.ToString(false));
	return !sig.IsSignalled();
}

bool Class_string::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return stream.SerializeString(sig, value.GetString());
}

bool Class_string::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	String str;
	if (!stream.DeserializeString(sig, str)) return false;
	value = Value(str);
	return true;
}

Object *Class_string::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return NULL;
}

//-----------------------------------------------------------------------------
// Class_string::IteratorEach
//-----------------------------------------------------------------------------
Class_string::IteratorEach::IteratorEach(const String &str, int cntMax, Attr attr) :
	Iterator(false), _str(str), _cnt(cntMax), _cntMax(cntMax), _attr(attr)
{
	_pCur = _str.begin();
}

Class_string::IteratorEach::~IteratorEach()
{
}

Iterator *Class_string::IteratorEach::GetSource()
{
	return NULL;
}

bool Class_string::IteratorEach::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pCur == _str.end()) return false;
	if (_attr == ATTR_UTF8) {
		UInt64 codeUTF8;
		_pCur = NextUTF8(_str, _pCur, codeUTF8);
		value = Value(codeUTF8);
	} else if (_attr == ATTR_UTF32) {
		ULong codeUTF32;
		_pCur = NextUTF32(_str, _pCur, codeUTF32);
		value = Value(codeUTF32);
	} else {
		String::const_iterator pLeft = _pCur;
		if (_cnt == 0) {
			_pCur = _str.end();
		} else {
			_pCur = NextChar(_str, _pCur);
			if (_cnt > 0) _cnt--;
		}
		value = Value(String(pLeft, _pCur));
	}
	return true;
}

String Class_string::IteratorEach::ToString() const
{
	return String("string#each");
}

void Class_string::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Class_string::IteratorLine
//-----------------------------------------------------------------------------
Class_string::IteratorLine::IteratorLine(const String &str,
											int cntMax, bool includeEOLFlag) :
			Iterator(false), _str(str), _cnt(cntMax), _cntMax(cntMax),
			_includeEOLFlag(includeEOLFlag)
{
	_pCur = _str.begin();
}

Class_string::IteratorLine::~IteratorLine()
{
}

Iterator *Class_string::IteratorLine::GetSource()
{
	return NULL;
}

bool Class_string::IteratorLine::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pCur == _str.end() || _cnt == 0) return false;
	String::const_iterator pLeft = _pCur;
	String::const_iterator pNext = _str.end();
	for ( ; _pCur != _str.end(); _pCur++) {
		if (*_pCur == '\r') {
			pNext = _pCur + 1;
			if (pNext != _str.end() && *pNext == '\n') pNext++;
			break;
		} else if (*_pCur == '\n') {
			pNext = _pCur + 1;
			break;
		}
	}
	value = Value(String(pLeft, _includeEOLFlag? pNext : _pCur));
	_pCur = pNext;
	if (_cnt > 0) _cnt--;
	return true;
}

String Class_string::IteratorLine::ToString() const
{
	return String("string#eachline");
}

void Class_string::IteratorLine::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Class_string::IteratorSplit
//-----------------------------------------------------------------------------
Class_string::IteratorSplit::IteratorSplit(const String &str, const char *sep,
											int cntMax, bool ignoreCaseFlag) :
	Iterator(false), _str(str), _sep(sep), _cnt(cntMax), _cntMax(cntMax),
	_ignoreCaseFlag(ignoreCaseFlag), _doneFlag(false)
{
	_pCur = _str.begin();
}

Class_string::IteratorSplit::~IteratorSplit()
{
}

Iterator *Class_string::IteratorSplit::GetSource()
{
	return NULL;
}

bool Class_string::IteratorSplit::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_doneFlag) {
		return false;
	} else if (_pCur == _str.end()) {
		value = Value("");
		_doneFlag = true;
	} else if (_cnt == 0) {
		String::const_iterator pEnd = _str.end();
		value = Value(String(_pCur, pEnd));
		_pCur = _str.end();
		_doneFlag = true;
	} else {
		String::const_iterator pRight =
							FindString(_pCur, _str.end(), _sep, _ignoreCaseFlag);
		value = Value(String(_pCur, pRight));
		if (pRight == _str.end()) {
			_pCur = _str.end();
			_doneFlag = true;
		} else {
			_pCur = pRight + _sep.size();
		}
		if (_cnt > 0) _cnt--;
	}
	return true;
}

String Class_string::IteratorSplit::ToString() const
{
	return String("string#split");
}

void Class_string::IteratorSplit::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Class_string::IteratorFold
//-----------------------------------------------------------------------------
Class_string::IteratorFold::IteratorFold(const String &str,
							size_t lenPerFold, size_t lenStep, bool neatFlag) :
	Iterator(false), _str(str), _lenPerFold(lenPerFold), _lenStep(lenStep), _neatFlag(neatFlag)
{
	_pCur = _str.begin();
}

Class_string::IteratorFold::~IteratorFold()
{
}

Iterator *Class_string::IteratorFold::GetSource()
{
	return NULL;
}

bool Class_string::IteratorFold::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pCur == _str.end()) return false;
	size_t lenForward = 0;
	String::const_iterator pNext, pTail;
	if (_lenStep <= _lenPerFold) {
		size_t lenForwardSub = 0;
		pNext = Forward(_pCur, _str.end(), _lenStep, &lenForward);
		pTail = Forward(pNext, _str.end(), _lenPerFold - _lenStep, &lenForwardSub);
		lenForward += lenForwardSub;
	} else {
		pTail = Forward(_pCur, _str.end(), _lenPerFold, &lenForward);
		pNext = Forward(pTail, _str.end(), _lenStep - _lenPerFold);
	}
	if (_neatFlag && lenForward < _lenPerFold) return false;
	value = Value(String(_pCur, pTail));
	_pCur = pNext;
	return true;
}

String Class_string::IteratorFold::ToString() const
{
	return String("string#fold");
}

void Class_string::IteratorFold::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Class_quote
//-----------------------------------------------------------------------------
Class_quote::Class_quote(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_quote)
{
}

void Class_quote::Prepare(Environment &env)
{
}

bool Class_quote::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_quote::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_quote::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

//-----------------------------------------------------------------------------
// Class_any
//-----------------------------------------------------------------------------
Class_any::Class_any(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_any)
{
}

void Class_any::Prepare(Environment &env)
{
}

bool Class_any::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_any::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_any::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

}
