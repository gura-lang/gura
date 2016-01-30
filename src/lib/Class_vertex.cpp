//=============================================================================
// Gura class: vertex
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_vertex
//-----------------------------------------------------------------------------
Object_vertex::~Object_vertex()
{
}

Object *Object_vertex::Clone() const
{
	return new Object_vertex(*this);
}

bool Object_color::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	symbols.insert(Gura_Symbol(z));
	symbols.insert(Gura_Symbol(w));
	return true;
}

Value Object_color::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_vertex.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_vertex.y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(z))) {
		return Value(_vertex.z);
	} else if (pSymbol->IsIdentical(Gura_Symbol(w))) {
		return Value(_vertex.w);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_color::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double x = value.GetDouble();
		_vertex.x = x;
		return Value(x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double y = value.GetDouble();
		_vertex.y = y;
		return Value(x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(z))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double z = value.GetDouble();
		_vertex.z = z;
		return Value(x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(w))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double w = value.GetDouble();
		_vertex.w = w;
		return Value(w);
	}
	return Value::Nil;
}

String Object_vertex::ToString(bool exprFlag)
{
	String str;
	str += "<vertex:";
	str += _vertex.ToString();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// color(args+):map {block?}
Gura_DeclareFunction(color)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "args", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_color));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `color` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("c", "color")
		"\n"
		"There are two forms to call this function as below:"
		"\n"
		"- `color(name:string, a?:number)` ..\n"
		"  Creates an instance from color name and an optional alpha element.\n"
		"  Predefined variable `color.names` is a list that contains available color names.\n"
		"  A string in a format of `'#rrggbb'` that is used in HTML documents\n"
		"  is also acceptable as a color name.\n"
		"- `color(r:number, g?:number, b?:number, a?:number)` ..\n"
		"  Creates an instance from RGB elements and an optional alpha element.\n");
}

Gura_ImplementFunction(color)
{
	Signal &sig = env.GetSignal();
	const ValueList &valList = arg.GetList(0);
	if (valList[0].Is_string() || valList[0].Is_symbol()) {
		UChar a = 255;
		if (valList.size() < 2) {
			// nothing to do
		} else if (valList[1].Is_number()) {
			a = valList[1].GetUChar();
		} else {
			Declaration::SetError_InvalidArgument(env);
			return Value::Nil;
		}
		const char *name = valList[0].Is_string()?
			valList[0].GetString() : valList[0].GetSymbol()->GetName();
		Color color = Color::CreateNamedColor(sig, name, a);
		if (sig.IsSignalled()) return Value::Nil;
		return ReturnValue(env, arg, Value(new Object_color(env, color)));
	} else if (valList[0].Is_number()) {
		UChar r = valList[0].GetUChar();
		if (valList.size() < 3) {
			Declaration::SetError_InvalidArgument(env);
			return Value::Nil;
		}
		UChar g = valList[1].GetUChar();
		UChar b = valList[2].GetUChar();
		UChar a = (valList.size() < 4)? 255 : valList[3].GetUChar();
		return ReturnValue(env, arg,
					Value(new Object_color(env, r, g, b, a)));
	}
	Declaration::SetError_InvalidArgument(env);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// color#tolist():[alpha]
Gura_DeclareMethod(color, tolist)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(alpha));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a list of RGB elements in a form `[r, g, b]`.\n"
		"\n"
		"Specifying `:alpha` attribute would add the alpha element to the list.");
}

Gura_ImplementMethod(color, tolist)
{
	const Color &color = Object_color::GetObjectThis(arg)->GetColor();
	bool alphaIncludeFlag = arg.IsSet(Gura_Symbol(alpha));
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
		Value value;
		Object_list *pObjList = value.InitAsList(env);
		size_t cnt = 0;
		const Color::ElementEntry *elementEntries = Color::GetElementEntries(&cnt);
		pObjList->Reserve(cnt);
		for (size_t i = 0; i < cnt; i++) {
			const Color::ElementEntry &elementEntry = elementEntries[i];
			pObjList->Add(Value(elementEntry.name));
		}
		Gura_AssignClassValue(names, value);
	} while (0);
	Gura_AssignFunction(color);
	Gura_AssignClassValue(zero,		Value(new Object_color(env, Color::zero)));
}

bool Class_color::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	Signal &sig = GetSignal();
	if (value.Is_list()) {
		const Function *pConstructor = GetConstructor();
		if (pConstructor == nullptr) return false;
		AutoPtr<Argument> pArg(new Argument(pConstructor));
		if (!pArg->StoreValues(env, value.GetList())) return false;
		value = pConstructor->Eval(env, *pArg);
		return !sig.IsSignalled();
	}
	return false;
}

Object *Class_color::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
