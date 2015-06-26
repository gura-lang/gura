#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_font_options implementation
//-----------------------------------------------------------------------------
Object_font_options::~Object_font_options()
{
	::cairo_font_options_destroy(_options);
}

Object *Object_font_options::Clone() const
{
	return nullptr;
}

String Object_font_options::ToString(bool exprFlag)
{
	return String("<cairo.font_options>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for font_options
//-----------------------------------------------------------------------------
// cairo.font_options.create() {block?}
Gura_DeclareClassMethod(font_options, create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(font_options, create)
{
	cairo_font_options_t *font_options = ::cairo_font_options_create();
	Object_font_options *pObjFontOptions = new Object_font_options(font_options);
	return ReturnValue(env, sig, args, Value(pObjFontOptions));
}

//#cairo_font_options_t *cairo_font_options_copy(const cairo_font_options_t *original);
//#void cairo_font_options_destroy(cairo_font_options_t *options);

// cairo.font_options#status()
Gura_DeclareMethod(font_options, status)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, status)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *font_options = pThis->GetEntity();
	cairo_status_t rtn = ::cairo_font_options_status(font_options);
	return Value(rtn);
}

//#void cairo_ft_font_options_substitute(const cairo_font_options_t *options, FcPattern *pattern);

// cairo.font_options#merge(other:font_options):void
Gura_DeclareMethod(font_options, merge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "other", VTYPE_font_options);
}

Gura_ImplementMethod(font_options, merge)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_font_options_t *other =
					Object_font_options::GetObject(args, 0)->GetEntity();
	::cairo_font_options_merge(options, other);
	if (Is_error(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#hash()
Gura_DeclareMethod(font_options, hash)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, hash)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	unsigned long rtn = ::cairo_font_options_hash(options);
	if (Is_error(sig, options)) return Value::Null;
	return Value(rtn);
}

// cairo.font_options#equal(other:font_options)
Gura_DeclareMethod(font_options, equal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_font_options);
}

Gura_ImplementMethod(font_options, equal)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_font_options_t *other =
					Object_font_options::GetObject(args, 0)->GetEntity();
	cairo_bool_t rtn = ::cairo_font_options_equal(options, other);
	if (Is_error(sig, options)) return Value::Null;
	return Value(rtn);
}

// cairo.font_options#set_antialias(antialias:number):void
Gura_DeclareMethod(font_options, set_antialias)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "antialias", VTYPE_number);
}

Gura_ImplementMethod(font_options, set_antialias)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_antialias_t antialias = static_cast<cairo_antialias_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_font_options_set_antialias(options, antialias);
	if (Is_error(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#get_antialias()
Gura_DeclareMethod(font_options, get_antialias)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, get_antialias)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_antialias_t antialias = ::cairo_font_options_get_antialias(options);
	if (Is_error(sig, options)) return Value::Null;
	return Value(antialias);
}

// cairo.font_options#set_subpixel_order(subpixel_order:number):void
Gura_DeclareMethod(font_options, set_subpixel_order)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "subpixel_order", VTYPE_number);
}

Gura_ImplementMethod(font_options, set_subpixel_order)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_subpixel_order_t subpixel_order = static_cast<cairo_subpixel_order_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_font_options_set_subpixel_order(options, subpixel_order);
	if (Is_error(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#get_subpixel_order()
Gura_DeclareMethod(font_options, get_subpixel_order)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, get_subpixel_order)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_subpixel_order_t subpixel_order = ::cairo_font_options_get_subpixel_order(options);
	if (Is_error(sig, options)) return Value::Null;
	return Value(subpixel_order);
}

// cairo.font_options#set_hint_style(hint_style:number):void
Gura_DeclareMethod(font_options, set_hint_style)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "hint_style", VTYPE_number);
}

Gura_ImplementMethod(font_options, set_hint_style)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_hint_style_t hint_style = static_cast<cairo_hint_style_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_font_options_set_hint_style(options, hint_style);
	if (Is_error(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#get_hint_style()
Gura_DeclareMethod(font_options, get_hint_style)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, get_hint_style)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_hint_style_t hint_style = ::cairo_font_options_get_hint_style(options);
	if (Is_error(sig, options)) return Value::Null;
	return Value(hint_style);
}

// cairo.font_options#set_hint_metrics(hint_metrics:number):void
Gura_DeclareMethod(font_options, set_hint_metrics)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "hint_metrics", VTYPE_number);
}

Gura_ImplementMethod(font_options, set_hint_metrics)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_hint_metrics_t hint_metrics = static_cast<cairo_hint_metrics_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_font_options_set_hint_metrics(options, hint_metrics);
	if (Is_error(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#get_hint_metrics()
Gura_DeclareMethod(font_options, get_hint_metrics)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, get_hint_metrics)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_hint_metrics_t hint_metrics = ::cairo_font_options_get_hint_metrics(options);
	if (Is_error(sig, options)) return Value::Null;
	return Value(hint_metrics);
}

// implementation of class font_options
Gura_ImplementUserClass(font_options)
{
	Gura_AssignMethod(font_options, create);
	Gura_AssignMethod(font_options, status);
	Gura_AssignMethod(font_options, merge);
	Gura_AssignMethod(font_options, hash);
	Gura_AssignMethod(font_options, equal);
	Gura_AssignMethod(font_options, set_antialias);
	Gura_AssignMethod(font_options, get_antialias);
	Gura_AssignMethod(font_options, set_subpixel_order);
	Gura_AssignMethod(font_options, get_subpixel_order);
	Gura_AssignMethod(font_options, set_hint_style);
	Gura_AssignMethod(font_options, get_hint_style);
	Gura_AssignMethod(font_options, set_hint_metrics);
	Gura_AssignMethod(font_options, get_hint_metrics);
}

Gura_EndModuleScope(cairo)
