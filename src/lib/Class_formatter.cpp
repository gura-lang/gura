//=============================================================================
// Gura class: formatter
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
# Overview

The `formatter` class provides information about a format specifier.

The function `printf()` has the following declaration:

    printf('name: %s, age: %d\n', name, age)

The first argument is a string containing format specifiers like `%s` and `%d`
that determine the manner on how the correspoding values `name` and `age` should be formatted.
In the formatting mechanism, when the specifiers `%s` and `%d` appear,
it would call methods `name.__format_s__()` and `age.__format_s__()` respectively
which are format handlers responsible of formatting these values.
In general, a format handler has a format like `__format_X__(fmt:formatter)`
where `X` is the symbol of the specifier and `fmt` is a `formatter` instance that carries
information about the associated specifier such as minimum width and a padding character.
The handler must return a `string` as its result.

The table below summarizes associations between specifiers
and the method name of their format handlers:

<table>
<tr><th>Specifier</th><th>Method Name</th></tr>
<tr><td><code>%d</code></td><td><code>__format_d__</code></td></tr>
<tr><td><code>%u</code></td><td><code>__format_u__</code></td></tr>
<tr><td><code>%b</code></td><td><code>__format_b__</code></td></tr>
<tr><td><code>%o</code></td><td><code>__format_o__</code></td></tr>
<tr><td><code>%x</code></td><td><code>__format_x__</code></td></tr>
<tr><td><code>%e</code></td><td><code>__format_e__</code></td></tr>
<tr><td><code>%f</code></td><td><code>__format_f__</code></td></tr>
<tr><td><code>%g</code></td><td><code>__format_g__</code></td></tr>
<tr><td><code>%s</code></td><td><code>__format_s__</code></td></tr>
<tr><td><code>%c</code></td><td><code>__format_c__</code></td></tr>
</table>

This feature is supposed to be used when you want your original class\'s instance
properly formatted in `printf`. Below is an example to implement a format handler
for the specifier `%d`:

    A = class {

        // any implementations

        __format_d__(fmt:format) = {
            // returns a string for %d specifier.
        }
    }

    a = A()
    printf('%d', a) // a.__format_d__() is called


# Method

${markdown.makedoc@function(`en
formatter.getminwidth
formatter.getpadding
formatter.getplusmode
formatter.getprecision
formatter.isleftalign
formatter.issharp
formatter.isuppercase
)}
)**";

//-----------------------------------------------------------------------------
// Object_formatter
//-----------------------------------------------------------------------------
Object_formatter::Object_formatter(const Object_formatter &obj) :
										Object(obj), _flags(obj._flags)
{
}

Object_formatter::~Object_formatter()
{
}

Object *Object_formatter::Clone() const
{
	return new Object_formatter(*this);
}

String Object_formatter::ToString(bool exprFlag)
{
	String str;
	str += "<formatter:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// formatter#getminwidth()
Gura_DeclareMethod(formatter, getminwidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns an expected minimum width for the field.\n"
		"\n"
		"For example, with `'%3d'`, this method would return `3`.\n");
}

Gura_ImplementMethod(formatter, getminwidth)
{
	const Formatter::Flags &flags = Object_formatter::GetObjectThis(arg)->GetFlags();
	return Value(flags.fieldMinWidth);
}

// formatter#getpadding()
Gura_DeclareMethod(formatter, getpadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns a string containing a padding character, a space or `'0'`.\n"
		"\n"
		"In default, a space is used for padding.\n"
		"For example, with `'%3d'`, this method would return `' '`.\n"
		"\n"
		"When a character `'0'` appears after `'%'`, that becomes the padding character.\n"
		"For example, with `'%03d'`, this method would return `'0'`.\n");
}

Gura_ImplementMethod(formatter, getpadding)
{
	const Formatter::Flags &flags = Object_formatter::GetObjectThis(arg)->GetFlags();
	char str[] = { flags.charPadding, '\0' };
	return Value(str);
}

// formatter#getplusmode()
Gura_DeclareMethod(formatter, getplusmode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns a symbol that indicates an expected action when a positive number appears.\n"
		"\n"
		"- `` `none`` .. No character ahead of the number.\n"
		"- `` `space`` .. A space should be inserted.\n"
		"- `` `plus`` .. A plus character should be inserted.\n");
}

Gura_ImplementMethod(formatter, getplusmode)
{
	const Formatter::Flags &flags = Object_formatter::GetObjectThis(arg)->GetFlags();
	const Symbol *pSymbol =
		(flags.plusMode == Formatter::PLUSMODE_None)? Gura_Symbol(none) :
		(flags.plusMode == Formatter::PLUSMODE_Space)? Gura_Symbol(space) :
		(flags.plusMode == Formatter::PLUSMODE_Plus)? Gura_Symbol(plus) :
		Gura_Symbol(none);
	return Value(pSymbol);
}

// formatter#getprecision()
Gura_DeclareMethod(formatter, getprecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns an expected precision for the field.\n"
		"\n"
		"For example, with `'%.3d'`, this method would return `3`.\n");
}

Gura_ImplementMethod(formatter, getprecision)
{
	const Formatter::Flags &flags = Object_formatter::GetObjectThis(arg)->GetFlags();
	return Value(flags.precision);
}

// formatter#isleftalign()
Gura_DeclareMethod(formatter, isleftalign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the field is expected to be aligned on left.\n"
		"\n"
		"For example, with `'%-3d'`, this method would return `true`.\n");
}

Gura_ImplementMethod(formatter, isleftalign)
{
	const Formatter::Flags &flags = Object_formatter::GetObjectThis(arg)->GetFlags();
	return Value(flags.leftAlignFlag);
}

// formatter#issharp()
Gura_DeclareMethod(formatter, issharp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the specifier sequence includes `'#'` flag,\n"
		"which means some literal prefixes such as `0x` are expected to be appended at the top.\n"
		"\n"
		"For example, with `'%#x'`, this method would return `true`.\n");
}

Gura_ImplementMethod(formatter, issharp)
{
	const Formatter::Flags &flags = Object_formatter::GetObjectThis(arg)->GetFlags();
	return Value(flags.sharpFlag);
}

// formatter#isuppercase()
Gura_DeclareMethod(formatter, isuppercase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if alphabet characters are expected to be shown in upper case.\n"
		"\n"
		"Upper case characters are requested\n"
		"when a specifier such as `'%X'`, `'%E'` and `'%G'` is specified.\n");
}

Gura_ImplementMethod(formatter, isuppercase)
{
	const Formatter::Flags &flags = Object_formatter::GetObjectThis(arg)->GetFlags();
	return Value(flags.upperCaseFlag);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_formatter::Class_formatter(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_formatter)
{
}

void Class_formatter::DoPrepare(Environment &env)
{
	Gura_AssignValue(formatter, Value(Reference()));
	Gura_AssignMethod(formatter, getminwidth);
	Gura_AssignMethod(formatter, getpadding);
	Gura_AssignMethod(formatter, getplusmode);
	Gura_AssignMethod(formatter, getprecision);
	Gura_AssignMethod(formatter, isleftalign);
	Gura_AssignMethod(formatter, issharp);
	Gura_AssignMethod(formatter, isuppercase);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_formatter::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
