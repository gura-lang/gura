//=============================================================================
// Gura class: color
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_color
//-----------------------------------------------------------------------------
Object_color::~Object_color()
{
}

Object *Object_color::Clone() const
{
	return new Object_color(*this);
}

bool Object_color::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(r));
	symbols.insert(Gura_Symbol(g));
	symbols.insert(Gura_Symbol(b));
	symbols.insert(Gura_Symbol(a));
	return true;
}

Value Object_color::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(r))) {
		return Value(_color.GetR());
	} else if (pSymbol->IsIdentical(Gura_Symbol(g))) {
		return Value(_color.GetG());
	} else if (pSymbol->IsIdentical(Gura_Symbol(b))) {
		return Value(_color.GetB());
	} else if (pSymbol->IsIdentical(Gura_Symbol(a))) {
		return Value(_color.GetA());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_color::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(r))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		evaluatedFlag = true;
		UChar r = value.GetUChar();
		_color.SetR(r);
		return Value(r);
	} else if (pSymbol->IsIdentical(Gura_Symbol(g))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		evaluatedFlag = true;
		UChar g = value.GetUChar();
		_color.SetG(g);
		return Value(g);
	} else if (pSymbol->IsIdentical(Gura_Symbol(b))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		evaluatedFlag = true;
		UChar b = value.GetUChar();
		_color.SetB(b);
		return Value(b);
	} else if (pSymbol->IsIdentical(Gura_Symbol(a))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		evaluatedFlag = true;
		UChar a = value.GetUChar();
		_color.SetA(a);
		return Value(a);
	}
	return Value::Null;
}

String Object_color::ToString(bool exprFlag)
{
	String str;
	str += "<color:";
	str += _color.GetHTML();
	char buff[32];
	::sprintf(buff, ",a:%02x", _color.GetA());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// color(args+) {block?}
Gura_DeclareFunction(color)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "args", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_color));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets either of a color symbol or a list of elements of r, g, b and a,\n"
	"and returns an color object.");
}

Gura_ImplementFunction(color)
{
	const ValueList &valList = args.GetList(0);
	if (valList[0].Is_string()) {
		UChar a = (valList.size() < 2)? 255 : valList[1].GetUChar();
		Color color = Color::CreateNamedColor(sig, valList[0].GetString(), a);
		if (sig.IsSignalled()) return Value::Null;
		return ReturnValue(env, sig, args, Value(new Object_color(env, color)));
	} else if (valList[0].Is_symbol()) {
		UChar a = (valList.size() < 2)? 255 : valList[1].GetUChar();
		Color color = Color::CreateNamedColor(sig, valList[0].GetSymbol()->GetName(), a);
		if (sig.IsSignalled()) return Value::Null;
		return ReturnValue(env, sig, args, Value(new Object_color(env, color)));
	} else if (valList[0].Is_number()) {
		UChar r = valList[0].GetUChar();
		if (valList.size() < 3) {
			Declaration::SetError_InvalidArgument(sig);
			return Value::Null;
		}
		UChar g = valList[1].GetUChar();
		UChar b = valList[2].GetUChar();
		UChar a = (valList.size() < 4)? 255 : valList[3].GetUChar();
		return ReturnValue(env, sig, args,
					Value(new Object_color(env, r, g, b, a)));
	}
	Declaration::SetError_InvalidArgument(sig);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// color#getgray()
Gura_DeclareMethod(color, getgray)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(color, getgray)
{
	const Color &color = Object_color::GetThisObj(args)->GetColor();
	return Value(color.GetGray());
}

// color#html()
Gura_DeclareMethod(color, html)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(color, html)
{
	const Color &color = Object_color::GetThisObj(args)->GetColor();
	return Value(color.GetHTML());
}

// color#tolist():[alpha]
Gura_DeclareMethod(color, tolist)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(alpha));
}

Gura_ImplementMethod(color, tolist)
{
	const Color &color = Object_color::GetThisObj(args)->GetColor();
	bool alphaIncludeFlag = args.IsSet(Gura_Symbol(alpha));
	if (alphaIncludeFlag) {
		return Value::CreateList(env,
					Value(color.GetR()), Value(color.GetG()),
					Value(color.GetB()), Value(color.GetA()));
	} else {
		return Value::CreateList(env,
					Value(color.GetR()), Value(color.GetG()),
					Value(color.GetB()));
	}
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_color::Class_color(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_color)
{
}

void Class_color::Prepare(Environment &env)
{
	Gura_AssignMethod(color, getgray);
	Gura_AssignMethod(color, html);
	Gura_AssignMethod(color, tolist);
	do {
		Environment &env = *this;
		Value value;
		ValueList &valList = value.InitAsList(env);
		size_t cnt = 0;
		const Color::ElementEntry *elementEntries = Color::GetElementEntries(&cnt);
		valList.reserve(cnt);
		for (size_t i = 0; i < cnt; i++) {
			const Color::ElementEntry &elementEntry = elementEntries[i];
			valList.push_back(Value(elementEntry.name));
		}
		Gura_AssignValue(names, value);
	} while (0);
	Gura_AssignFunction(color);
	Gura_AssignClassValue(black,	Value(new Object_color(env, Color::black)));
	Gura_AssignClassValue(maroon,	Value(new Object_color(env, Color::maroon)));
	Gura_AssignClassValue(green,	Value(new Object_color(env, Color::green)));
	Gura_AssignClassValue(olive,	Value(new Object_color(env, Color::olive)));
	Gura_AssignClassValue(navy,		Value(new Object_color(env, Color::navy)));
	Gura_AssignClassValue(purple,	Value(new Object_color(env, Color::purple)));
	Gura_AssignClassValue(teal,		Value(new Object_color(env, Color::teal)));
	Gura_AssignClassValue(gray,		Value(new Object_color(env, Color::gray)));
	Gura_AssignClassValue(silver,	Value(new Object_color(env, Color::silver)));
	Gura_AssignClassValue(red,		Value(new Object_color(env, Color::red)));
	Gura_AssignClassValue(lime,		Value(new Object_color(env, Color::lime)));
	Gura_AssignClassValue(yellow,	Value(new Object_color(env, Color::yellow)));
	Gura_AssignClassValue(blue,		Value(new Object_color(env, Color::blue)));
	Gura_AssignClassValue(fuchsia,	Value(new Object_color(env, Color::fuchsia)));
	Gura_AssignClassValue(aqua,		Value(new Object_color(env, Color::aqua)));
	Gura_AssignClassValue(white,	Value(new Object_color(env, Color::white)));
	Gura_AssignClassValue(zero,		Value(new Object_color(env, Color::zero)));
}

bool Class_color::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_symbol()) {
		Color color = Color::CreateNamedColor(sig, value.GetSymbol()->GetName(), 255);
		if (sig.IsSignalled()) return false;
		value = Value(new Object_color(env, color));
		return true;
	} else if (value.Is_string()) {
		Color color = Color::CreateNamedColor(sig, value.GetString(), 255);
		if (sig.IsSignalled()) return false;
		value = Value(new Object_color(env, color));
		return true;
	} else if (value.Is_list()) {
		const Function *pConstructor = GetConstructor();
		if (pConstructor == NULL) return false;
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValueListArg(value.GetList());
		value = pConstructor->Eval(env, sig, *pArgs);
		return !sig.IsSignalled();
	}
	return false;
}

Object *Class_color::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
