#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_context implementation
//-----------------------------------------------------------------------------
Object_context::~Object_context()
{
	Destroy();
}

Object *Object_context::Clone() const
{
	return NULL;
}

bool Object_context::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(surface));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_context::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(surface))) {
		return Value(Object_surface::Reference(_pObjSurface.get()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_context::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<cairo.context:";
	if (_cr == NULL) {
		str += "invalid";
	} else {
		cairo_surface_t *surface = ::cairo_get_target(_cr);
		cairo_surface_type_t surface_type = ::cairo_surface_get_type(surface);
		str += SurfaceTypeToName(surface_type);
		if (surface_type == CAIRO_SURFACE_TYPE_IMAGE) {
			str += ":";
			str += NumberToString(::cairo_image_surface_get_width(surface));
			str += "x";
			str += NumberToString(::cairo_image_surface_get_height(surface));
		}
	}
	str += ">";
	return str;
}

void Object_context::Destroy()
{
	if (_cr != NULL) {
		::cairo_destroy(_cr);
		_cr = NULL;
		_pObjSurface.reset(NULL);
	}
}

//-----------------------------------------------------------------------------
// Gura interfaces for context
// context operations
//-----------------------------------------------------------------------------
//#cairo_t *cairo_reference(cairo_t *cr);
//#void cairo_destroy(cairo_t *cr);

// cairo.context#status()
Gura_DeclareMethod(context, status)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, status)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *context = pThis->GetEntity();
	cairo_status_t rtn = ::cairo_status(context);
	return Value(rtn);
}

// cairo.context#destroy():reduce
Gura_DeclareMethod(context, destroy)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, destroy)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	pThis->Destroy();
	return Value::Null;
}

// cairo.context#save():reduce {block?}
Gura_DeclareMethod(context, save)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(context, save)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_save(cr);
	if (IsError(sig, cr)) return Value::Null;
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec(env, sig);
		::cairo_restore(cr);
		if (IsError(sig, cr)) return Value::Null;
	}
	return args.GetThis();
}

// cairo.context#restore():reduce
Gura_DeclareMethod(context, restore)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, restore)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_restore(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_target()
Gura_DeclareMethod(context, get_target)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_target)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_surface_t *surface = ::cairo_get_target(cr);
	if (IsError(sig, cr)) return Value::Null;
	return Value(Object_surface::Reference(pThis->GetSurfaceObj()));
}

// cairo.context#push_group():reduce
Gura_DeclareMethod(context, push_group)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, push_group)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_push_group(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#push_group_with_content(content:number):reduce
Gura_DeclareMethod(context, push_group_with_content)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "content", VTYPE_number);
}

Gura_ImplementMethod(context, push_group_with_content)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_content_t content = static_cast<cairo_content_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_push_group_with_content(cr, content);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#pop_group()
Gura_DeclareMethod(context, pop_group)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, pop_group)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_pattern_t *pattern = ::cairo_pop_group(cr);
	if (IsError(sig, cr)) return Value::Null;
	Object_pattern *pObjPattern = new Object_pattern(pattern);
	return Value(pObjPattern);
}

// cairo.context#pop_group_to_source():reduce
Gura_DeclareMethod(context, pop_group_to_source)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, pop_group_to_source)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_pop_group_to_source(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_group_target()
Gura_DeclareMethod(context, get_group_target)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_group_target)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_surface_t *surface = ::cairo_get_group_target(cr);
	if (IsError(sig, cr)) return Value::Null;
	Object_surface *pObjSurface =
			new Object_surface(::cairo_surface_reference(surface));
	return Value(pObjSurface);
}

// cairo.context#set_source_rgb(red:number, green:number, blue:number):reduce
Gura_DeclareMethod(context, set_source_rgb)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementMethod(context, set_source_rgb)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_set_source_rgb(cr, args.GetDouble(0), args.GetDouble(1), args.GetDouble(2));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#set_source_rgba(red:number, green:number, blue:number, alpha:number):reduce
Gura_DeclareMethod(context, set_source_rgba)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementMethod(context, set_source_rgba)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_set_source_rgba(cr, args.GetDouble(0), args.GetDouble(1),
									args.GetDouble(2), args.GetDouble(3));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#set_source_color(color:color, alpha?:number):reduce
Gura_DeclareMethod(context, set_source_color)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(context, set_source_color)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	const Color &color = Object_color::GetObject(args, 0)->GetColor();
	double red = static_cast<double>(color.GetRed()) / 255;
	double green = static_cast<double>(color.GetGreen()) / 255;
	double blue = static_cast<double>(color.GetBlue()) / 255;
	if (args.IsNumber(1)) {
		double alpha = args.GetDouble(1);
		::cairo_set_source_rgba(cr, red, green, blue, alpha);
	} else {
		::cairo_set_source_rgb(cr, red, green, blue);
	}
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#set_source(source:cairo.pattern):reduce
Gura_DeclareMethod(context, set_source)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "source", VTYPE_pattern);
}

Gura_ImplementMethod(context, set_source)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_pattern_t *source = Object_pattern::GetObject(args, 0)->GetEntity();
	::cairo_set_source(cr, source);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#set_source_surface(surface:cairo.surface, x:number, y:number):reduce
Gura_DeclareMethod(context, set_source_surface)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "surface", VTYPE_surface);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(context, set_source_surface)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_surface_t *surface = Object_surface::GetObject(args, 0)->GetEntity();
	double x = args.GetDouble(1);
	double y = args.GetDouble(2);
	::cairo_set_source_surface(cr, surface, x, y);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_source()
Gura_DeclareMethod(context, get_source)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_source)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_pattern_t *pattern = ::cairo_get_source(cr);
	if (IsError(sig, cr)) return Value::Null;
	Object_pattern *pObjPattern =
				new Object_pattern(::cairo_pattern_reference(pattern));
	return Value(pObjPattern);
}

// cairo.context#set_antialias(antialias:number):reduce
Gura_DeclareMethod(context, set_antialias)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "antialias", VTYPE_number);
}

Gura_ImplementMethod(context, set_antialias)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_antialias_t antialias = static_cast<cairo_antialias_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_set_antialias(cr, antialias);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_antialias()
Gura_DeclareMethod(context, get_antialias)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_antialias)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_antialias_t antialias = ::cairo_get_antialias(cr);
	if (IsError(sig, cr)) return Value::Null;
	return Value(antialias);
}

// cairo.context#set_dash(dashes[]:number, offset:number):reduce
Gura_DeclareMethod(context, set_dash)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "dashes", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "offset", VTYPE_number);
}

Gura_ImplementMethod(context, set_dash)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	int num_dashes = static_cast<int>(args.GetList(0).size());
	double *dashes = new double [num_dashes];
	int i = 0;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		dashes[i++] = pValue->GetDouble();
	}
	double offset = args.GetDouble(1);
	::cairo_set_dash(cr, dashes, num_dashes, offset);
	delete[] dashes;
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_dash()
Gura_DeclareMethod(context, get_dash)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_dash)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	int num_dashes = ::cairo_get_dash_count(cr);
	double *dashes = new double [num_dashes];
	double offset = 0;
	::cairo_get_dash(cr, dashes, &offset);
	if (IsError(sig, cr)) {
		delete[] dashes;
		return Value::Null;
	}
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(num_dashes);
	for (int i = 0; i < num_dashes; i++) {
		valList.push_back(Value(dashes[num_dashes]));
	}
	delete[] dashes;
	return Value::CreateAsList(env, rtn, Value(offset));
}

// cairo.context#set_fill_rule(fill_rule:number):reduce
Gura_DeclareMethod(context, set_fill_rule)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "fill_rule", VTYPE_number);
}

Gura_ImplementMethod(context, set_fill_rule)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_fill_rule_t fill_rule = static_cast<cairo_fill_rule_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_set_fill_rule(cr, fill_rule);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_fill_rule()
Gura_DeclareMethod(context, get_fill_rule)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_fill_rule)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_fill_rule_t fill_rule = ::cairo_get_fill_rule(cr);
	if (IsError(sig, cr)) return Value::Null;
	return Value(fill_rule);
}

// cairo.context#set_line_cap(line_cap:number):reduce
Gura_DeclareMethod(context, set_line_cap)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "line_cap", VTYPE_number);
}

Gura_ImplementMethod(context, set_line_cap)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_line_cap_t line_cap = static_cast<cairo_line_cap_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_set_line_cap(cr, line_cap);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_line_cap()
Gura_DeclareMethod(context, get_line_cap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_line_cap)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_line_cap_t line_cap = ::cairo_get_line_cap(cr);
	if (IsError(sig, cr)) return Value::Null;
	return Value(line_cap);
}

// cairo.context#set_line_join(line_join:number):reduce
Gura_DeclareMethod(context, set_line_join)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "line_join", VTYPE_number);
}

Gura_ImplementMethod(context, set_line_join)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_line_join_t line_join = static_cast<cairo_line_join_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_set_line_join(cr, line_join);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_line_join()
Gura_DeclareMethod(context, get_line_join)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_line_join)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_line_join_t line_join = ::cairo_get_line_join(cr);
	if (IsError(sig, cr)) return Value::Null;
	return Value(line_join);
}

// cairo.context#set_line_width(width:number):reduce
Gura_DeclareMethod(context, set_line_width)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
}

Gura_ImplementMethod(context, set_line_width)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_set_line_width(cr, args.GetDouble(0));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_line_width()
Gura_DeclareMethod(context, get_line_width)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_line_width)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double width = ::cairo_get_line_width(cr);
	if (IsError(sig, cr)) return Value::Null;
	return Value(width);
}

// cairo.context#set_miter_limit(limit:number):reduce
Gura_DeclareMethod(context, set_miter_limit)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "limit", VTYPE_number);
}

Gura_ImplementMethod(context, set_miter_limit)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_set_miter_limit(cr, args.GetDouble(0));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_miter_limit()
Gura_DeclareMethod(context, get_miter_limit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_miter_limit)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double limit = ::cairo_get_miter_limit(cr);
	if (IsError(sig, cr)) return Value::Null;
	return Value(limit);
}

// cairo.context#set_operator(op:number):reduce
Gura_DeclareMethod(context, set_operator)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "op", VTYPE_number);
}

Gura_ImplementMethod(context, set_operator)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_operator_t operator_ = static_cast<cairo_operator_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_set_operator(cr, operator_);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_operator()
Gura_DeclareMethod(context, get_operator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_operator)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_operator_t operator_ = ::cairo_get_operator(cr);
	if (IsError(sig, cr)) return Value::Null;
	return Value(operator_);
}

// cairo.context#set_tolerance(tolerance:number):reduce
Gura_DeclareMethod(context, set_tolerance)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "tolerance", VTYPE_number);
}

Gura_ImplementMethod(context, set_tolerance)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_set_tolerance(cr, args.GetDouble(0));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_tolerance()
Gura_DeclareMethod(context, get_tolerance)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_tolerance)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double tolerance = ::cairo_get_tolerance(cr);
	if (IsError(sig, cr)) return Value::Null;
	return Value(tolerance);
}

// cairo.context#clip():reduce
Gura_DeclareMethod(context, clip)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, clip)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_clip(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#clip_preserve():reduce
Gura_DeclareMethod(context, clip_preserve)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, clip_preserve)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_clip_preserve(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#clip_extents()
Gura_DeclareMethod(context, clip_extents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, clip_extents)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double x1, y1, x2, y2;
	::cairo_clip_extents(cr, &x1, &y1, &x2, &y2);
	if (IsError(sig, cr)) return Value::Null;
	return CreateValueList(env, x1, y1, x2, y2);
}

// cairo.context#in_clip(x:number, y:number)
Gura_DeclareMethod(context, in_clip)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(context, in_clip)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	bool rtn = ::cairo_in_clip(cr, args.GetDouble(0), args.GetDouble(1))? true : false;
	if (IsError(sig, cr)) return Value::Null;
	return Value(rtn);
}

// cairo.context#reset_clip():reduce
Gura_DeclareMethod(context, reset_clip)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, reset_clip)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_reset_clip(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

//#void cairo_rectangle_list_destroy(cairo_rectangle_list_t *rectangle_list);

// cairo.context#copy_clip_rectangle_list()
Gura_DeclareMethod(context, copy_clip_rectangle_list)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, copy_clip_rectangle_list)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_rectangle_list_t *rectangle_list = ::cairo_copy_clip_rectangle_list(cr);
	if (IsError(sig, cr)) {
		::cairo_rectangle_list_destroy(rectangle_list);
		return Value::Null;
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(rectangle_list->num_rectangles);
	for (int i = 0; i < rectangle_list->num_rectangles; i++) {
		cairo_rectangle_t &rectangle = rectangle_list->rectangles[i];
		valList.push_back(RectangleToValue(env, rectangle));
	}
	::cairo_rectangle_list_destroy(rectangle_list);
	return result;
}

// cairo.context#fill():reduce
Gura_DeclareMethod(context, fill)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, fill)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_fill(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#fill_preserve():reduce
Gura_DeclareMethod(context, fill_preserve)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, fill_preserve)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_fill_preserve(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#fill_extents():reduce
Gura_DeclareMethod(context, fill_extents)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, fill_extents)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double x1, y1, x2, y2;
	::cairo_fill_extents(cr, &x1, &y1, &x2, &y2);
	if (IsError(sig, cr)) return Value::Null;
	return CreateValueList(env, x1, y1, x2, y2);
}

// cairo.context#in_fill(x:number, y:number)
Gura_DeclareMethod(context, in_fill)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(context, in_fill)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	bool rtn = ::cairo_in_fill(cr, args.GetDouble(0), args.GetDouble(1))? true : false;
	if (IsError(sig, cr)) return Value::Null;
	return Value(rtn);
}

// cairo.context#mask(pattern:cairo.pattern):reduce
Gura_DeclareMethod(context, mask)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "pattern", VTYPE_pattern);
}

Gura_ImplementMethod(context, mask)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_pattern_t *pattern = Object_pattern::GetObject(args, 0)->GetEntity();
	::cairo_mask(cr, pattern);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#mask_surface(surface:cairo.surface, surface_x:number, surface_y:number):reduce
Gura_DeclareMethod(context, mask_surface)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "surface", VTYPE_surface);
	DeclareArg(env, "surface_x", VTYPE_number);
	DeclareArg(env, "surface_y", VTYPE_number);
}

Gura_ImplementMethod(context, mask_surface)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_surface_t *surface = Object_surface::GetObject(args, 0)->GetEntity();
	double surface_x = args.GetDouble(1);
	double surface_y = args.GetDouble(2);
	::cairo_mask_surface(cr, surface, surface_x, surface_y);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#paint():reduce
Gura_DeclareMethod(context, paint)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, paint)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_paint(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#paint_with_alpha(alpha:number):reduce
Gura_DeclareMethod(context, paint_with_alpha)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementMethod(context, paint_with_alpha)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_paint_with_alpha(cr, args.GetDouble(0));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#stroke():reduce
Gura_DeclareMethod(context, stroke)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, stroke)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_stroke(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#stroke_preserve():reduce
Gura_DeclareMethod(context, stroke_preserve)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, stroke_preserve)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_stroke_preserve(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#stroke_extents()
Gura_DeclareMethod(context, stroke_extents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, stroke_extents)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double x1, y1, x2, y2;
	::cairo_stroke_extents(cr, &x1, &y1, &x2, &y2);
	if (IsError(sig, cr)) return Value::Null;
	return CreateValueList(env, x1, y1, x2, y2);
}

// cairo.context#in_stroke(x:number, y:number)
Gura_DeclareMethod(context, in_stroke)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(context, in_stroke)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	bool rtn = ::cairo_in_stroke(cr, args.GetDouble(0), args.GetDouble(1))? true : false;
	if (IsError(sig, cr)) return Value::Null;
	return Value(rtn);
}

// cairo.context#copy_page():reduce
Gura_DeclareMethod(context, copy_page)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, copy_page)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_copy_page(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#show_page():reduce
Gura_DeclareMethod(context, show_page)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, show_page)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_show_page(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

//#unsigned int cairo_get_reference_count(cairo_t *cr);
//#cairo_status_t cairo_set_user_data(cairo_t *cr, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_get_user_data(cairo_t *cr, const cairo_user_data_key_t *key);

//-----------------------------------------------------------------------------
// Gura interfaces for context
// Paths - Creating paths and manipulating path data
//-----------------------------------------------------------------------------
// cairo.context#copy_path()
Gura_DeclareMethod(context, copy_path)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, copy_path)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_path_t *path = ::cairo_copy_path(cr);
	if (IsError(sig, cr)) return Value::Null;
	Value result(new Object_path(path));
	return result;
}

// cairo.context#copy_path_flat()
Gura_DeclareMethod(context, copy_path_flat)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, copy_path_flat)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_path_t *path = ::cairo_copy_path_flat(cr);
	if (IsError(sig, cr)) return Value::Null;
	Value result(new Object_path(path));
	return result;
}

// cairo.context#append_path(path:path):reduce
Gura_DeclareMethod(context, append_path)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "path", VTYPE_path);
}

Gura_ImplementMethod(context, append_path)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_path_t *path = Object_path::GetObject(args, 0)->GetEntity();
	::cairo_append_path(cr, path);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#has_current_point()
Gura_DeclareMethod(context, has_current_point)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, has_current_point)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	bool rtn = ::cairo_has_current_point(cr)? true : false;
	if (IsError(sig, cr)) return Value::Null;
	return Value(rtn);
}

// cairo.context#get_current_point()
Gura_DeclareMethod(context, get_current_point)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_current_point)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double x, y;
	::cairo_get_current_point(cr, &x, &y);
	if (IsError(sig, cr)) return Value::Null;
	return CreateValueList(env, x, y);
}

// cairo.context#new_path():reduce
Gura_DeclareMethod(context, new_path)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, new_path)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_new_path(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#new_sub_path():reduce
Gura_DeclareMethod(context, new_sub_path)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, new_sub_path)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_new_sub_path(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#close_path():reduce
Gura_DeclareMethod(context, close_path)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, close_path)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_close_path(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#arc(xc:number, yc:number, radius:number,
//                   angle1?:number, angle2?:number):map:reduce
Gura_DeclareMethod(context, arc)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "xc", VTYPE_number);
	DeclareArg(env, "yc", VTYPE_number);
	DeclareArg(env, "radius", VTYPE_number);
	DeclareArg(env, "angle1", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "angle2", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(context, arc)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double angle1 = args.IsNumber(3)? args.GetDouble(3) : 0;
	double angle2 = args.IsNumber(4)? args.GetDouble(4) : 2 * NUM_PI;
	::cairo_arc(cr, args.GetDouble(0), args.GetDouble(1),
										args.GetDouble(2), angle1, angle2);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#arc_negative(xc:number, yc:number, radius:number,
//                            angle1?:number, angle2?:number):map:reduce
Gura_DeclareMethod(context, arc_negative)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "xc", VTYPE_number);
	DeclareArg(env, "yc", VTYPE_number);
	DeclareArg(env, "radius", VTYPE_number);
	DeclareArg(env, "angle1", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "angle2", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(context, arc_negative)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double angle1 = args.IsNumber(3)? args.GetDouble(3) : 0;
	double angle2 = args.IsNumber(4)? args.GetDouble(4) : 2 * NUM_PI;
	::cairo_arc_negative(cr, args.GetDouble(0), args.GetDouble(1),
										args.GetDouble(2), angle1, angle2);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#curve_to(x1:number, y1:number, x2:number, y2:number, x3:number, y3:number):map:reduce
Gura_DeclareMethod(context, curve_to)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareArg(env, "x2", VTYPE_number);
	DeclareArg(env, "y2", VTYPE_number);
	DeclareArg(env, "x3", VTYPE_number);
	DeclareArg(env, "y3", VTYPE_number);
}

Gura_ImplementMethod(context, curve_to)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_curve_to(cr,
			args.GetDouble(0), args.GetDouble(1),
			args.GetDouble(2), args.GetDouble(3),
			args.GetDouble(4), args.GetDouble(5));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#line_to(x:number, y:number):map:reduce
Gura_DeclareMethod(context, line_to)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(context, line_to)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_line_to(cr, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#move_to(x:number, y:number):map:reduce
Gura_DeclareMethod(context, move_to)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(context, move_to)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_move_to(cr, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#rectangle(x:number, y:number, width:number, height:number):map:reduce
Gura_DeclareMethod(context, rectangle)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementMethod(context, rectangle)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_rectangle(cr,
			args.GetDouble(0), args.GetDouble(1),
			args.GetDouble(2), args.GetDouble(3));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#glyph_path(glyphs:cairo.glyph):reduce
Gura_DeclareMethod(context, glyph_path)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "glyphs", VTYPE_glyph);
}

Gura_ImplementMethod(context, glyph_path)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	Object_glyph *pObjGlyph = Object_glyph::GetObject(args, 0);
	::cairo_glyph_path(cr, pObjGlyph->GetGlyphs(), pObjGlyph->GetNumGlyphs());
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#text_path(text:string):map:reduce
Gura_DeclareMethod(context, text_path)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string);
}

Gura_ImplementMethod(context, text_path)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_text_path(cr, args.GetString(0));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#rel_curve_to(dx1:number, dy1:number, dx2:number, dy2:number, dx3:number, dy3:number):map:reduce
Gura_DeclareMethod(context, rel_curve_to)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "dx1", VTYPE_number);
	DeclareArg(env, "dy1", VTYPE_number);
	DeclareArg(env, "dx2", VTYPE_number);
	DeclareArg(env, "dy2", VTYPE_number);
	DeclareArg(env, "dx3", VTYPE_number);
	DeclareArg(env, "dy3", VTYPE_number);
}

Gura_ImplementMethod(context, rel_curve_to)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_rel_curve_to(cr,
			args.GetDouble(0), args.GetDouble(1),
			args.GetDouble(2), args.GetDouble(3),
			args.GetDouble(4), args.GetDouble(5));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#rel_line_to(dx:number, dy:number):map:reduce
Gura_DeclareMethod(context, rel_line_to)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number);
	DeclareArg(env, "dy", VTYPE_number);
}

Gura_ImplementMethod(context, rel_line_to)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_rel_line_to(cr, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#rel_move_to(dx:number, dy:number):map:reduce
Gura_DeclareMethod(context, rel_move_to)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number);
	DeclareArg(env, "dy", VTYPE_number);
}

Gura_ImplementMethod(context, rel_move_to)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_rel_move_to(cr, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#path_extents()
Gura_DeclareMethod(context, path_extents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, path_extents)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double x1, y1, x2, y2;
	::cairo_path_extents(cr, &x1, &y1, &x2, &y2);
	if (IsError(sig, cr)) return Value::Null;
	return CreateValueList(env, x1, y1, x2, y2);
}

//-----------------------------------------------------------------------------
// Gura interfaces for context
// Transformations - Manipulating the current transformation matrix
//-----------------------------------------------------------------------------
// cairo.context#translate(tx:number, ty:number):reduce
Gura_DeclareMethod(context, translate)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "tx", VTYPE_number);
	DeclareArg(env, "ty", VTYPE_number);
}

Gura_ImplementMethod(context, translate)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_translate(cr, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#scale(sx:number, sy:number):reduce
Gura_DeclareMethod(context, scale)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "sx", VTYPE_number);
	DeclareArg(env, "sy", VTYPE_number);
}

Gura_ImplementMethod(context, scale)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_scale(cr, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#rotate(angle:number):reduce
Gura_DeclareMethod(context, rotate)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number);
}

Gura_ImplementMethod(context, rotate)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_rotate(cr, args.GetDouble(0));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#transform(matrix:matrix):reduce
Gura_DeclareMethod(context, transform)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_matrix);
}

Gura_ImplementMethod(context, transform)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	Object_matrix *pObjMatrix = Object_matrix::GetObject(args, 0);
	cairo_matrix_t matrix;
	if (!MatrixToCairo(sig, matrix, pObjMatrix)) return Value::Null;
	::cairo_transform(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#set_matrix(matrix:matrix):reduce
Gura_DeclareMethod(context, set_matrix)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_matrix);
}

Gura_ImplementMethod(context, set_matrix)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	Object_matrix *pObjMatrix = Object_matrix::GetObject(args, 0);
	cairo_matrix_t matrix;
	if (!MatrixToCairo(sig, matrix, pObjMatrix)) return Value::Null;
	::cairo_set_matrix(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_matrix()
Gura_DeclareMethod(context, get_matrix)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_matrix)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_matrix_t matrix;
	::cairo_get_matrix(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	Object_matrix *pObjMatrix = CairoToMatrix(env, matrix);
	return Value(pObjMatrix);
}

// cairo.context#identity_matrix():reduce
Gura_DeclareMethod(context, identity_matrix)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(context, identity_matrix)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_identity_matrix(cr);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#user_to_device(x:number, y:number)
Gura_DeclareMethod(context, user_to_device)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(context, user_to_device)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double x = args.GetDouble(0);
	double y = args.GetDouble(1);
	::cairo_user_to_device(cr, &x, &y);
	if (IsError(sig, cr)) return Value::Null;
	return CreateValueList(env, x, y);
}

// cairo.context#user_to_device_distance(dx:number, dy:number)
Gura_DeclareMethod(context, user_to_device_distance)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dx", VTYPE_number);
	DeclareArg(env, "dy", VTYPE_number);
}

Gura_ImplementMethod(context, user_to_device_distance)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double dx = args.GetDouble(0);
	double dy = args.GetDouble(1);
	::cairo_user_to_device_distance(cr, &dx, &dy);
	if (IsError(sig, cr)) return Value::Null;
	return CreateValueList(env, dx, dy);
}

// cairo.context#device_to_user(x:number, y:number)
Gura_DeclareMethod(context, device_to_user)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(context, device_to_user)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double x = args.GetDouble(0);
	double y = args.GetDouble(1);
	::cairo_device_to_user(cr, &x, &y);
	if (IsError(sig, cr)) return Value::Null;
	return CreateValueList(env, x, y);
}

// cairo.context#device_to_user_distance(dx:number, dy:number)
Gura_DeclareMethod(context, device_to_user_distance)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dx", VTYPE_number);
	DeclareArg(env, "dy", VTYPE_number);
}

Gura_ImplementMethod(context, device_to_user_distance)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double dx = args.GetDouble(0);
	double dy = args.GetDouble(1);
	::cairo_device_to_user_distance(cr, &dx, &dy);
	if (IsError(sig, cr)) return Value::Null;
	return CreateValueList(env, dx, dy);
}

//-----------------------------------------------------------------------------
// Gura interfaces for context
// text - Rendering text and glyphs
//-----------------------------------------------------------------------------
// cairo.context#select_font_face(family:string, slant:number, weight:number):reduce
Gura_DeclareMethod(context, select_font_face)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "family", VTYPE_string);
	DeclareArg(env, "slant", VTYPE_number);
	DeclareArg(env, "weight", VTYPE_number);
}

Gura_ImplementMethod(context, select_font_face)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	const char *family = args.GetString(0);
	cairo_font_slant_t slant = static_cast<cairo_font_slant_t>(args.GetInt(1));
	if (sig.IsSignalled()) return Value::Null;
	cairo_font_weight_t weight = static_cast<cairo_font_weight_t>(args.GetInt(2));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_select_font_face(cr, family, slant, weight);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#set_font_size(size:number):reduce
Gura_DeclareMethod(context, set_font_size)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "size", VTYPE_number);
}

Gura_ImplementMethod(context, set_font_size)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_set_font_size(cr, args.GetDouble(0));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#set_font_matrix(matrix:matrix):reduce
Gura_DeclareMethod(context, set_font_matrix)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_matrix);
}

Gura_ImplementMethod(context, set_font_matrix)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	Object_matrix *pObjMatrix = Object_matrix::GetObject(args, 0);
	cairo_matrix_t matrix;
	if (!MatrixToCairo(sig, matrix, pObjMatrix)) return Value::Null;
	::cairo_set_font_matrix(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_font_matrix()
Gura_DeclareMethod(context, get_font_matrix)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_font_matrix)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_matrix_t matrix;
	::cairo_get_font_matrix(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	Object_matrix *pObjMatrix = CairoToMatrix(env, matrix);
	return Value(pObjMatrix);
}

// cairo.context#set_font_options(options:cairo.font_options):reduce
Gura_DeclareMethod(context, set_font_options)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "options", VTYPE_font_options);
}

Gura_ImplementMethod(context, set_font_options)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_set_font_options(cr,
				Object_font_options::GetObject(args, 0)->GetEntity());
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_font_options()
Gura_DeclareMethod(context, get_font_options)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_font_options)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_font_options_t *options = ::cairo_font_options_create();
	::cairo_get_font_options(cr, options);
	if (IsError(sig, cr)) {
		::cairo_font_options_destroy(options);
		return Value::Null;
	}
	Object_font_options *pObjFontOptions = new Object_font_options(options);
	return Value(pObjFontOptions);
}

// cairo.context#set_font_face(font_face:cairo.font_face):reduce
Gura_DeclareMethod(context, set_font_face)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "font_face", VTYPE_font_face);
}

Gura_ImplementMethod(context, set_font_face)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_set_font_face(cr,
				Object_font_face::GetObject(args, 0)->GetEntity());
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_font_face()
Gura_DeclareMethod(context, get_font_face)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_font_face)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_font_face_t *font_face = ::cairo_get_font_face(cr);
	if (IsError(sig, cr)) {
		return Value::Null;
	}
	Object_font_face *pObjFontFace = new Object_font_face(::cairo_font_face_reference(font_face));
	return Value(pObjFontFace);
}

// cairo.context#set_scaled_font(scaled_font:cairo.scaled_font):reduce
Gura_DeclareMethod(context, set_scaled_font)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "scaled_font", VTYPE_scaled_font);
}

Gura_ImplementMethod(context, set_scaled_font)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_set_scaled_font(cr,
				Object_scaled_font::GetObject(args, 0)->GetEntity());
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_scaled_font()
Gura_DeclareMethod(context, get_scaled_font)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, get_scaled_font)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_scaled_font_t *scaled_font = ::cairo_get_scaled_font(cr);
	if (IsError(sig, cr)) {
		return Value::Null;
	}
	Object_scaled_font *pObjFontFace = new Object_scaled_font(::cairo_scaled_font_reference(scaled_font));
	return Value(pObjFontFace);
}

// cairo.context#show_text(text:string):reduce
Gura_DeclareMethod(context, show_text)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "text", VTYPE_string);
}

Gura_ImplementMethod(context, show_text)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	::cairo_show_text(cr, args.GetString(0));
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#show_glyphs(glyphs:cairo.glyph):reduce
Gura_DeclareMethod(context, show_glyphs)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "glyphs", VTYPE_glyph);
}

Gura_ImplementMethod(context, show_glyphs)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	Object_glyph *pObjGlyph = Object_glyph::GetObject(args, 0);
	::cairo_show_glyphs(cr, pObjGlyph->GetGlyphs(), pObjGlyph->GetNumGlyphs());
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#show_text_glyphs(text:string, glyphs:cairo.glyphs,
//              clusters:cairo.text_cluster, cluster_flags:number):reduce
Gura_DeclareMethod(context, show_text_glyphs)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "glyphs", VTYPE_glyph);
	DeclareArg(env, "clusters", VTYPE_text_cluster);
	DeclareArg(env, "cluster_flags", VTYPE_number);
}

Gura_ImplementMethod(context, show_text_glyphs)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	String text = args.GetStringSTL(0);
	Object_glyph *pObjGlyph = Object_glyph::GetObject(args, 1);
	Object_text_cluster *pObjCluster = Object_text_cluster::GetObject(args, 2);
	cairo_text_cluster_flags_t cluster_flags =
					static_cast<cairo_text_cluster_flags_t>(args.GetInt(3));
	::cairo_show_text_glyphs(cr, text.c_str(), static_cast<int>(text.size()),
		pObjGlyph->GetGlyphs(), pObjGlyph->GetNumGlyphs(),
		pObjCluster->GetClusters(), pObjCluster->GetNumClusters(), cluster_flags);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#font_extents()
Gura_DeclareMethod(context, font_extents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, font_extents)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_font_extents_t extents;
	::cairo_font_extents(cr, &extents);
	if (IsError(sig, cr)) return Value::Null;
	Object_font_extents *pObjFontExtents = new Object_font_extents(extents);
	return Value(pObjFontExtents);
}

// cairo.context#text_extents(text:string)
Gura_DeclareMethod(context, text_extents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "text", VTYPE_string);
}

Gura_ImplementMethod(context, text_extents)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_text_extents_t extents;
	::cairo_text_extents(cr, args.GetString(0), &extents);
	if (IsError(sig, cr)) return Value::Null;
	Object_text_extents *pObjTextExtents = new Object_text_extents(extents);
	return Value(pObjTextExtents);
}

// cairo.context#glyph_extents(glyphs:cairo.glyph)
Gura_DeclareMethod(context, glyph_extents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "glyphs", VTYPE_glyph);
}

Gura_ImplementMethod(context, glyph_extents)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	Object_glyph *pObjGlyph = Object_glyph::GetObject(args, 0);
	cairo_text_extents_t extents;
	::cairo_glyph_extents(cr, pObjGlyph->GetGlyphs(), pObjGlyph->GetNumGlyphs(), &extents);
	if (IsError(sig, cr)) return Value::Null;
	Object_text_extents *pObjTextExtents = new Object_text_extents(extents);
	return Value(pObjTextExtents);
}

// implementation of class Context
Gura_ImplementUserClass(context)
{
	// Context operations
	Gura_AssignMethod(context, status);
	Gura_AssignMethod(context, destroy);
	Gura_AssignMethod(context, save);
	Gura_AssignMethod(context, restore);
	Gura_AssignMethod(context, get_target);
	Gura_AssignMethod(context, push_group);
	Gura_AssignMethod(context, push_group_with_content);
	Gura_AssignMethod(context, pop_group);
	Gura_AssignMethod(context, pop_group_to_source);
	Gura_AssignMethod(context, get_group_target);
	Gura_AssignMethod(context, set_source_rgb);
	Gura_AssignMethod(context, set_source_rgba);
	Gura_AssignMethod(context, set_source_color);
	Gura_AssignMethod(context, set_source);
	Gura_AssignMethod(context, set_source_surface);
	Gura_AssignMethod(context, get_source);
	Gura_AssignMethod(context, set_antialias);
	Gura_AssignMethod(context, get_antialias);
	Gura_AssignMethod(context, set_dash);
	Gura_AssignMethod(context, get_dash);
	Gura_AssignMethod(context, set_fill_rule);
	Gura_AssignMethod(context, get_fill_rule);
	Gura_AssignMethod(context, set_line_cap);
	Gura_AssignMethod(context, get_line_cap);
	Gura_AssignMethod(context, set_line_join);
	Gura_AssignMethod(context, get_line_join);
	Gura_AssignMethod(context, set_line_width);
	Gura_AssignMethod(context, get_line_width);
	Gura_AssignMethod(context, set_miter_limit);
	Gura_AssignMethod(context, get_miter_limit);
	Gura_AssignMethod(context, set_operator);
	Gura_AssignMethod(context, get_operator);
	Gura_AssignMethod(context, set_tolerance);
	Gura_AssignMethod(context, get_tolerance);
	Gura_AssignMethod(context, clip);
	Gura_AssignMethod(context, clip_preserve);
	Gura_AssignMethod(context, clip_extents);
	Gura_AssignMethod(context, in_clip);
	Gura_AssignMethod(context, reset_clip);
	Gura_AssignMethod(context, copy_clip_rectangle_list);
	Gura_AssignMethod(context, fill);
	Gura_AssignMethod(context, fill_preserve);
	Gura_AssignMethod(context, fill_extents);
	Gura_AssignMethod(context, in_fill);
	Gura_AssignMethod(context, mask);
	Gura_AssignMethod(context, mask_surface);
	Gura_AssignMethod(context, paint);
	Gura_AssignMethod(context, paint_with_alpha);
	Gura_AssignMethod(context, stroke);
	Gura_AssignMethod(context, stroke_preserve);
	Gura_AssignMethod(context, stroke_extents);
	Gura_AssignMethod(context, in_stroke);
	Gura_AssignMethod(context, copy_page);
	Gura_AssignMethod(context, show_page);
	// Paths - Creating paths and manipulating path data
	Gura_AssignMethod(context, copy_path);
	Gura_AssignMethod(context, copy_path_flat);
	Gura_AssignMethod(context, append_path);
	Gura_AssignMethod(context, has_current_point);
	Gura_AssignMethod(context, get_current_point);
	Gura_AssignMethod(context, new_path);
	Gura_AssignMethod(context, new_sub_path);
	Gura_AssignMethod(context, close_path);
	Gura_AssignMethod(context, arc);
	Gura_AssignMethod(context, arc_negative);
	Gura_AssignMethod(context, curve_to);
	Gura_AssignMethod(context, line_to);
	Gura_AssignMethod(context, move_to);
	Gura_AssignMethod(context, rectangle);
	Gura_AssignMethod(context, text_path);
	Gura_AssignMethod(context, rel_curve_to);
	Gura_AssignMethod(context, rel_line_to);
	Gura_AssignMethod(context, rel_move_to);
	Gura_AssignMethod(context, path_extents);
	// Transformations - Manipulating the current transformation matrix
	Gura_AssignMethod(context, translate);
	Gura_AssignMethod(context, scale);
	Gura_AssignMethod(context, rotate);
	Gura_AssignMethod(context, transform);
	Gura_AssignMethod(context, set_matrix);
	Gura_AssignMethod(context, get_matrix);
	Gura_AssignMethod(context, identity_matrix);
	Gura_AssignMethod(context, user_to_device);
	Gura_AssignMethod(context, user_to_device_distance);
	Gura_AssignMethod(context, device_to_user);
	Gura_AssignMethod(context, device_to_user_distance);
	// text - Rendering text and glyphs
	Gura_AssignMethod(context, select_font_face);
	Gura_AssignMethod(context, set_font_size);
	Gura_AssignMethod(context, set_font_matrix);
	Gura_AssignMethod(context, get_font_matrix);
	Gura_AssignMethod(context, set_font_options);
	Gura_AssignMethod(context, get_font_options);
	Gura_AssignMethod(context, set_font_face);
	Gura_AssignMethod(context, get_font_face);
	Gura_AssignMethod(context, set_scaled_font);
	Gura_AssignMethod(context, get_scaled_font);
	Gura_AssignMethod(context, show_text);
	Gura_AssignMethod(context, show_glyphs);
	Gura_AssignMethod(context, show_text_glyphs);
	Gura_AssignMethod(context, font_extents);
	Gura_AssignMethod(context, text_extents);
	Gura_AssignMethod(context, glyph_extents);
}

}}
