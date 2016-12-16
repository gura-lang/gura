//=============================================================================
// Gura class: color
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
An instance of the `color` class represents a color data that consists of red, green, blue and alpha elements.

You can create a `color` instance by calling `color()` function.

There are class variables as shown below:

# Predefined Variable

<table>
<tr><th>Variable</th><th>Type</th><th>Explanation</th></tr>

<tr><td><code>color.names</code></td><td><code>string[]</code></td>
<td>A list of color names that can be passed to <code>color()</code> function.</td></tr>

<tr><td><code>color.zero</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(0, 0, 0, 0)</code></td></tr>

<tr><td><code>color.black</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(0, 0, 0, 255)</code></td></tr>

<tr><td><code>color.maroon</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(128, 0, 0, 255)</code></td></tr>

<tr><td><code>color.green</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(0, 128, 0, 255)</code></td></tr>

<tr><td><code>color.olive</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(128, 128, 0, 255)</code></td></tr>

<tr><td><code>color.navy</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(0, 0, 128, 255)</code></td></tr>

<tr><td><code>color.purple</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(128, 0, 128, 255)</code></td></tr>

<tr><td><code>color.teal</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(0, 128, 128, 255)</code></td></tr>

<tr><td><code>color.gray</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(128, 128, 128, 255)</code></td></tr>

<tr><td><code>color.silver</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(192, 192, 192, 255)</code></td></tr>

<tr><td><code>color.red</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(255, 0, 0, 255)</code></td></tr>

<tr><td><code>color.lime</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(0, 255, 0, 255)</code></td></tr>

<tr><td><code>color.yellow</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(255, 255, 0, 255)</code></td></tr>

<tr><td><code>color.blue</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(0, 0, 255, 255)</code></td></tr>

<tr><td><code>color.fuchsia</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(255, 0, 255, 255)</code></td></tr>

<tr><td><code>color.aqua</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(0, 255, 255, 255)</code></td></tr>

<tr><td><code>color.white</code></td><td><code>color</code></td>
<td>Color instance equivalent with <code>color(255, 255, 255, 255)</code></td></tr>

</table>


# Property

A `color` instance has the following properties:

<table>
<tr><th>Property</th><th>Type</th><th>R/W</th><th>Explanation</th></tr>

<tr><td><code>r</code></td><td><code>number</code></td><td>R/W</td>
<td>Value of the red element.</td></tr>

<tr><td><code>g</code></td><td><code>number</code></td><td>R/W</td>
<td>Value of the green element.</td></tr>

<tr><td><code>b</code></td><td><code>number</code></td><td>R/W</td>
<td>Value of the blue element.</td></tr>

<tr><td><code>a</code></td><td><code>number</code></td><td>R/W</td>
<td>Value of the alpha element.</td></tr>

</table>


# Cast Operation

A function that expects a `color` instance in its argument can also take a value of
`symbol`, `string` and `list` as below:

- `symbol` .. Recognized as a color name to look up the color table.
- `string` .. Recognized as a color name to look up the color table.
- `list` .. Expected to contain elements in a format `[red, green, blue]` or
  `[red, green, blue, alpha]`.

With the above casting feature, you can call a function `f(c:color)`
that takes a `color` instance in its argument as below:

- ``f(color(`purple))`` .. The most explicit way.
- ``f(`purple)`` .. Implicit casting: from `symbol` to `color`.
- `f('purple')` .. Implicit casting: from `string` to `color`.
- `f([128, 0, 128])` .. Implicit casting: from `list` to `color`.


# Constructor

${markdown.funcentry(`en
color
)}


# Method

${markdown.funcentry(`en
color.getgray
color.html
color.list
)}
)**";

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

bool Object_color::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(r));
	symbols.insert(Gura_Symbol(g));
	symbols.insert(Gura_Symbol(b));
	symbols.insert(Gura_Symbol(a));
	return true;
}

Value Object_color::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	return Value::Nil;
}

Value Object_color::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	if (pSymbol->IsIdentical(Gura_Symbol(r))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		UChar r = value.GetUChar();
		_color.SetR(r);
		return Value(r);
	} else if (pSymbol->IsIdentical(Gura_Symbol(g))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		UChar g = value.GetUChar();
		_color.SetG(g);
		return Value(g);
	} else if (pSymbol->IsIdentical(Gura_Symbol(b))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		UChar b = value.GetUChar();
		_color.SetB(b);
		return Value(b);
	} else if (pSymbol->IsIdentical(Gura_Symbol(a))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		UChar a = value.GetUChar();
		_color.SetA(a);
		return Value(a);
	}
	return Value::Nil;
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
// color(args+):map {block?}
Gura_DeclareFunction(color)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "args", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_color));
	AddHelp(
		Gura_Symbol(en),
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
	Color color = Color::CreateFromValues(env, arg.GetList(0));
	if (env.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_color(env, color)));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// color#getgray()
Gura_DeclareMethod(color, getgray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a gray scale from RGB elements in the `color` instance.\n"
		"\n"
		"This is computed by a formula: `gray = 0.299 * red + 0.587 * blue + 0.114 * blue`.\n");
}

Gura_ImplementMethod(color, getgray)
{
	const Color &color = Object_color::GetObjectThis(arg)->GetColor();
	return Value(color.GetGray());
}

// color#html()
Gura_DeclareMethod(color, html)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns a color string in a format of `'#rrggbb'` that is used in HTML documents.");
}

Gura_ImplementMethod(color, html)
{
	const Color &color = Object_color::GetObjectThis(arg)->GetColor();
	return Value(color.GetHTML());
}

// color#list():[alpha]
Gura_DeclareMethod(color, list)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(alpha));
	AddHelp(
		Gura_Symbol(en),
		"Returns a list of RGB elements in a form `[r, g, b]`.\n"
		"\n"
		"Specifying `:alpha` attribute would add the alpha element to the list.");
}

Gura_ImplementMethod(color, list)
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

void Class_color::DoPrepare(Environment &env)
{
	Gura_AssignMethod(color, getgray);
	Gura_AssignMethod(color, html);
	Gura_AssignMethod(color, list);
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
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_color::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	if (value.Is_symbol()) {
		Color color = Color::CreateNamedColor(env, value.GetSymbol()->GetName(), 255);
		if (env.IsSignalled()) return false;
		value = Value(new Object_color(env, color));
		return true;
	} else if (value.Is_string()) {
		Color color = Color::CreateNamedColor(env, value.GetString(), 255);
		if (env.IsSignalled()) return false;
		value = Value(new Object_color(env, color));
		return true;
	} else if (value.Is_list()) {
		Color color = Color::CreateFromValues(env, value.GetList());
		if (env.IsSignalled()) return false;
		value = Value(new Object_color(env, color));
		return true;
	}
	return false;
}

Object *Class_color::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
