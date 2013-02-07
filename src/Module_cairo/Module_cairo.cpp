//-----------------------------------------------------------------------------
// Gura cairo module
// cairo version 1.12.12
//-----------------------------------------------------------------------------
#include "Module_cairo.h"

#define Gura_AssignCairoValue(name) \
Gura_AssignValue(name, Value(CAIRO_##name))

Gura_BeginModule(cairo)

const double NUM_PI = 3.14159265358979323846;

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

bool Object_context::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(surface));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_context::DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(surface))) {
		return Value(Object_surface::Reference(_pObjSurface.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		if (!_pObjSurface->HasSize()) return Value::Null;
		return Value(_pObjSurface->GetWidth());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		if (!_pObjSurface->HasSize()) return Value::Null;
		return Value(_pObjSurface->GetHeight());
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
//#cairo_t *cairo_create(cairo_surface_t *target);
//#cairo_t *cairo_reference(cairo_t *cr);
//#void cairo_destroy(cairo_t *cr);
//#cairo_status_t cairo_status(cairo_t *cr);

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
	const Color &color = args.GetColorObj(0)->GetColor();
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

//#void cairo_path_destroy(cairo_path_t *path);
//#void cairo_append_path(cairo_t *cr, const cairo_path_t *path);

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

// cairo.context#glyph_path(glyph[]:cairo.glyph):reduce
Gura_DeclareMethod(context, glyph_path)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "glyph", VTYPE_glyph);
}

Gura_ImplementMethod(context, glyph_path)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	int num_glyphs = static_cast<int>(args.GetList(0).size());
	cairo_glyph_t *glyphs = ::cairo_glyph_allocate(num_glyphs);
	cairo_glyph_t *glyphp = glyphs;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		*glyphp++ = Object_glyph::GetObject(*pValue)->GetEntity();
	}
	::cairo_glyph_path(cr, glyphs, num_glyphs);
	::cairo_glyph_free(glyphs);
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
	Object_matrix *pObjMatrix = args.GetMatrixObj(0);
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
	Object_matrix *pObjMatrix = args.GetMatrixObj(0);
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

// cairo.context#show_glyphs(glyphs[]:cairo.glyph):reduce
Gura_DeclareMethod(context, show_glyphs)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "glyphs", VTYPE_glyph, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(context, show_glyphs)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	int num_glyphs = static_cast<int>(args.GetList(0).size());
	cairo_glyph_t *glyphs = ::cairo_glyph_allocate(num_glyphs);
	cairo_glyph_t *glyphp = glyphs;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		*glyphp++ = Object_glyph::GetObject(*pValue)->GetEntity();
	}
	::cairo_show_glyphs(cr, glyphs, num_glyphs);
	::cairo_glyph_free(glyphs);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#show_text_glyphs():reduce
Gura_DeclareMethod(context, show_text_glyphs)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "glyphs", VTYPE_glyph, OCCUR_Once, FLAG_List);
	DeclareArg(env, "clusters", VTYPE_text_cluster, OCCUR_Once, FLAG_List);
	DeclareArg(env, "cluster_flags", VTYPE_number);
}

Gura_ImplementMethod(context, show_text_glyphs)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	String text = args.GetStringSTL(0);
	int num_glyphs = static_cast<int>(args.GetList(1).size());
	cairo_glyph_t *glyphs = ::cairo_glyph_allocate(num_glyphs);
	cairo_glyph_t *glyphp = glyphs;
	foreach_const (ValueList, pValue, args.GetList(1)) {
		*glyphp++ = Object_glyph::GetObject(*pValue)->GetEntity();
	}
	int num_clusters = static_cast<int>(args.GetList(2).size());
	cairo_text_cluster_t *clusters = ::cairo_text_cluster_allocate(num_clusters);
	cairo_text_cluster_t *clusterp = clusters;
	foreach_const (ValueList, pValue, args.GetList(2)) {
		*clusterp++ = Object_text_cluster::GetObject(*pValue)->GetEntity();
	}
	cairo_text_cluster_flags_t cluster_flags =
					static_cast<cairo_text_cluster_flags_t>(args.GetInt(3));
	::cairo_show_text_glyphs(cr, text.c_str(), static_cast<int>(text.size()),
					glyphs, num_glyphs, clusters, num_clusters, cluster_flags);
	::cairo_glyph_free(glyphs);
	::cairo_text_cluster_free(clusters);
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

// cairo.context#glyph_extents(glyphs[]:cairo.glyph)
Gura_DeclareMethod(context, glyph_extents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(context, glyph_extents)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	int num_glyphs = static_cast<int>(args.GetList(0).size());
	cairo_glyph_t *glyphs = ::cairo_glyph_allocate(num_glyphs);
	int i = 0;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		glyphs[i++] = Object_glyph::GetObject(*pValue)->GetEntity();
	}
	cairo_text_extents_t extents;
	::cairo_glyph_extents(cr, glyphs, num_glyphs, &extents);
	::cairo_glyph_free(glyphs);
	if (IsError(sig, cr)) return Value::Null;
	Object_text_extents *pObjTextExtents = new Object_text_extents(extents);
	return Value(pObjTextExtents);
}

// implementation of class Context
Gura_ImplementUserClass(context)
{
	// Context operations
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

//-----------------------------------------------------------------------------
// Object_font_extents implementation
//-----------------------------------------------------------------------------
Object_font_extents::~Object_font_extents()
{
}

Object *Object_font_extents::Clone() const
{
	return NULL;
}

bool Object_font_extents::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(ascent));
	symbols.insert(Gura_UserSymbol(descent));
	symbols.insert(Gura_UserSymbol(height));
	symbols.insert(Gura_UserSymbol(max_x_advance));
	symbols.insert(Gura_UserSymbol(max_y_advance));
	return true;
}

Value Object_font_extents::DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(ascent))) {
		return Value(_font_extents.ascent);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(descent))) {
		return Value(_font_extents.descent);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(_font_extents.height);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(max_x_advance))) {
		return Value(_font_extents.max_x_advance);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(max_y_advance))) {
		return Value(_font_extents.max_y_advance);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_font_extents::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.font_extents>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for font_extents
//-----------------------------------------------------------------------------
// implementation of class font_extents
Gura_ImplementUserClass(font_extents)
{
}

//-----------------------------------------------------------------------------
// Object_text_extents implementation
//-----------------------------------------------------------------------------
Object_text_extents::~Object_text_extents()
{
}

Object *Object_text_extents::Clone() const
{
	return NULL;
}

bool Object_text_extents::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(x_bearing));
	symbols.insert(Gura_UserSymbol(y_bearing));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	symbols.insert(Gura_UserSymbol(x_advance));
	symbols.insert(Gura_UserSymbol(y_advance));
	return true;
}

Value Object_text_extents::DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(x_bearing))) {
		return Value(_text_extents.x_bearing);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y_bearing))) {
		return Value(_text_extents.y_bearing);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		return Value(_text_extents.width);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(_text_extents.height);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(x_advance))) {
		return Value(_text_extents.x_advance);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y_advance))) {
		return Value(_text_extents.y_advance);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_text_extents::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.text_extents>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for text_extents
//-----------------------------------------------------------------------------
// implementation of class text_extents
Gura_ImplementUserClass(text_extents)
{
}

//-----------------------------------------------------------------------------
// Object_rectangle implementation
//-----------------------------------------------------------------------------
Object_rectangle::~Object_rectangle()
{
}

Object *Object_rectangle::Clone() const
{
	return NULL;
}

String Object_rectangle::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.rectangle>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for rectangle
//-----------------------------------------------------------------------------
// implementation of class rectangle
Gura_ImplementUserClass(rectangle)
{
}

//-----------------------------------------------------------------------------
// Object_rectangle_int implementation
//-----------------------------------------------------------------------------
Object_rectangle_int::~Object_rectangle_int()
{
}

Object *Object_rectangle_int::Clone() const
{
	return NULL;
}

String Object_rectangle_int::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.rectangle_int>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for rectangle_int
//-----------------------------------------------------------------------------
// implementation of class rectangle_int
Gura_ImplementUserClass(rectangle_int)
{
}

//-----------------------------------------------------------------------------
// Object_region implementation
//-----------------------------------------------------------------------------
Object_region::~Object_region()
{
	::cairo_region_destroy(_region);
}

Object *Object_region::Clone() const
{
	return NULL;
}

String Object_region::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.region>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for region
//-----------------------------------------------------------------------------
//#cairo_region_t *cairo_region_create(void);
//#cairo_region_t *cairo_region_create_rectangle(const cairo_rectangle_int_t *rectangle);
//#cairo_region_t *cairo_region_create_rectangles(const cairo_rectangle_int_t *rects, int count);
//#cairo_region_t *cairo_region_copy(const cairo_region_t *original);
//#cairo_region_t *cairo_region_reference(cairo_region_t *region);
//#void cairo_region_destroy(cairo_region_t *region);
//#cairo_status_t cairo_region_status(const cairo_region_t *region);
//#void cairo_region_get_extents(const cairo_region_t *region, cairo_rectangle_int_t *extents);
//#int cairo_region_num_rectangles(const cairo_region_t *region);
//#void cairo_region_get_rectangle(const cairo_region_t *region, int nth, cairo_rectangle_int_t *rectangle);

// cairo.region#is_empty()
Gura_DeclareMethod(region, is_empty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(region, is_empty)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	bool rtn = ::cairo_region_is_empty(region)? true : false;
	if (IsError(sig, region)) return Value::Null;
	return Value(rtn);
}

// cairo.region#contains_point(x:number, y:number)
Gura_DeclareMethod(region, contains_point)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}


Gura_ImplementMethod(region, contains_point)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	bool rtn = ::cairo_region_contains_point(region, args.GetInt(0), args.GetInt(1))? true : false;
	if (IsError(sig, region)) return Value::Null;
	return Value(rtn);
}

// cairo.region#contains_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, contains_rectangle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, contains_rectangle)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_region_overlap_t region_overlap =
					::cairo_region_contains_rectangle(region, &rectangle);
	if (IsError(sig, region)) return Value::Null;
	return Value(region_overlap);
}

// cairo.region#equal(region:cairo.region)
Gura_DeclareMethod(region, equal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "region", VTYPE_region);
}

Gura_ImplementMethod(region, equal)
{
	cairo_region_t *a = Object_region::GetThisObj(args)->GetEntity();
	cairo_region_t *b = Object_region::GetObject(args, 0)->GetEntity();
	bool rtn = ::cairo_region_equal(a, b)? true : false;
	if (IsError(sig, a)) return Value::Null;
	return Value(rtn);
}

// cairo.region#translate(dx:number, dy:number)
Gura_DeclareMethod(region, translate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dx", VTYPE_number);
	DeclareArg(env, "dy", VTYPE_number);
}

Gura_ImplementMethod(region, translate)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	::cairo_region_translate(region, args.GetInt(0), args.GetInt(1));
	if (IsError(sig, region)) return Value::Null;
	return Value::Null;
}

// cairo.region#intersect(other:cairo.region)
Gura_DeclareMethod(region, intersect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_region);
}

Gura_ImplementMethod(region, intersect)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (IsError(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	cairo_region_t *other = Object_region::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_intersect(dst, other);
	if (IsError(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#intersect_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, intersect_rectangle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, intersect_rectangle)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (IsError(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_intersect_rectangle(dst, &rectangle);
	if (IsError(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#subtract(other:cairo.region)
Gura_DeclareMethod(region, subtract)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_region);
}

Gura_ImplementMethod(region, subtract)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (IsError(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	cairo_region_t *other = Object_region::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_subtract(dst, other);
	if (IsError(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#subtract_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, subtract_rectangle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, subtract_rectangle)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (IsError(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_subtract_rectangle(dst, &rectangle);
	if (IsError(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#union(other:cairo.region)
Gura_DeclareMethod(region, union_)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_region);
}

Gura_ImplementMethod(region, union_)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (IsError(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	cairo_region_t *other = Object_region::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_union(dst, other);
	if (IsError(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#union_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, union_rectangle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, union_rectangle)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (IsError(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_union_rectangle(dst, &rectangle);
	if (IsError(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#xor(other:cairo.region)
Gura_DeclareMethodAlias(region, xor_, "xor")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_region);
}

Gura_ImplementMethod(region, xor_)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (IsError(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	cairo_region_t *other = Object_region::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_xor(dst, other);
	if (IsError(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#xor_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, xor_rectangle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, xor_rectangle)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (IsError(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_xor_rectangle(dst, &rectangle);
	if (IsError(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Null;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// implementation of class region
Gura_ImplementUserClass(region)
{
	Gura_AssignMethod(region, is_empty);
	Gura_AssignMethod(region, contains_point);
	Gura_AssignMethod(region, contains_rectangle);
	Gura_AssignMethod(region, equal);
	Gura_AssignMethod(region, translate);
	Gura_AssignMethod(region, intersect);
	Gura_AssignMethod(region, intersect_rectangle);
	Gura_AssignMethod(region, subtract);
	Gura_AssignMethod(region, subtract_rectangle);
	Gura_AssignMethodEx(region, union_, "union");
	Gura_AssignMethod(region, union_rectangle);
	Gura_AssignMethod(region, xor_);
	Gura_AssignMethod(region, xor_rectangle);
}

//-----------------------------------------------------------------------------
// Object_font_face implementation
//-----------------------------------------------------------------------------
Object_font_face::~Object_font_face()
{
	::cairo_font_face_destroy(_font_face);
}

Object *Object_font_face::Clone() const
{
	return NULL;
}

String Object_font_face::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.font_face>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for font_face
//-----------------------------------------------------------------------------
//#cairo_font_face_t *cairo_font_face_reference(cairo_font_face_t *font_face);
//#void cairo_font_face_destroy(cairo_font_face_t *font_face);
//#cairo_status_t cairo_font_face_status(cairo_font_face_t *font_face);

//#cairo_font_type_t cairo_font_face_get_type(cairo_font_face_t *font_face);

//#unsigned int cairo_font_face_get_reference_count(cairo_font_face_t *font_face);
//#cairo_status_t cairo_font_face_set_user_data(cairo_font_face_t *font_face, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_font_face_get_user_data(cairo_font_face_t *font_face, const cairo_user_data_key_t *key);

//#cairo_font_face_t *cairo_toy_font_face_create(const char *family, cairo_font_slant_t slant, cairo_font_weight_t weight);
//#const char *cairo_toy_font_face_get_family(cairo_font_face_t *font_face);
//#cairo_font_slant_t cairo_toy_font_face_get_slant(cairo_font_face_t *font_face);
//#cairo_font_weight_t cairo_toy_font_face_get_weight(cairo_font_face_t *font_face);

//#cairo_font_face_t *cairo_ft_font_face_create_for_ft_face(FT_Face face, int load_flags);
//#cairo_font_face_t *cairo_ft_font_face_create_for_pattern(FcPattern *pattern);
//#unsigned int cairo_ft_font_face_get_synthesize(cairo_font_face_t *font_face);
//#void cairo_ft_font_face_set_synthesize(cairo_font_face_t *font_face, unsigned int synth_flags);
//#void cairo_ft_font_face_unset_synthesize (cairo_font_face_t *font_face, unsigned int synth_flags);

//#cairo_font_face_t *cairo_win32_font_face_create_for_logfontw(LOGFONTW *logfont);
//#cairo_font_face_t *cairo_win32_font_face_create_for_hfont(HFONT font);
//#cairo_font_face_t *cairo_win32_font_face_create_for_logfontw_hfont(LOGFONTW *logfont, HFONT font);

//#cairo_font_face_t *cairo_quartz_font_face_create_for_cgfont(CGFontRef font);
//#cairo_font_face_t *cairo_quartz_font_face_create_for_atsu_font_id(ATSUFontID font_id);

//#cairo_font_face_t *cairo_user_font_face_create(void);
//#void cairo_user_font_face_set_init_func(cairo_font_face_t *font_face,  cairo_user_scaled_font_init_func_t init_func);
//#cairo_user_scaled_font_init_func_t cairo_user_font_face_get_init_func(cairo_font_face_t *font_face);
//#void cairo_user_font_face_set_render_glyph_func(cairo_font_face_t *font_face, cairo_user_scaled_font_render_glyph_func_t render_glyph_func);
//#cairo_user_scaled_font_render_glyph_func_t cairo_user_font_face_get_render_glyph_func(cairo_font_face_t *font_face);
//#void cairo_user_font_face_set_unicode_to_glyph_func(cairo_font_face_t *font_face, cairo_user_scaled_font_unicode_to_glyph_func_t unicode_to_glyph_func);
//#cairo_user_scaled_font_unicode_to_glyph_func_t cairo_user_font_face_get_unicode_to_glyph_func(cairo_font_face_t *font_face);
//#void cairo_user_font_face_set_text_to_glyphs_func(cairo_font_face_t *font_face, cairo_user_scaled_font_text_to_glyphs_func_t text_to_glyphs_func);
//#cairo_user_scaled_font_text_to_glyphs_func_t cairo_user_font_face_get_text_to_glyphs_func(cairo_font_face_t *font_face);

// implementation of class font_face
Gura_ImplementUserClass(font_face)
{
}

//-----------------------------------------------------------------------------
// Object_scaled_font implementation
//-----------------------------------------------------------------------------
Object_scaled_font::~Object_scaled_font()
{
	::cairo_scaled_font_destroy(_scaled_font);
}

Object *Object_scaled_font::Clone() const
{
	return NULL;
}

String Object_scaled_font::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.scaled_font>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for scaled_font
//-----------------------------------------------------------------------------
//#cairo_scaled_font_t *cairo_scaled_font_create(cairo_font_face_t *font_face, const cairo_matrix_t *font_matrix, const cairo_matrix_t *ctm, const cairo_font_options_t *options);
//#cairo_scaled_font_t *cairo_scaled_font_reference(cairo_scaled_font_t *scaled_font);
//#void cairo_scaled_font_destroy(cairo_scaled_font_t *scaled_font);
//#cairo_status_t cairo_scaled_font_status(cairo_scaled_font_t *scaled_font);
//#void cairo_scaled_font_extents(cairo_scaled_font_t *scaled_font, cairo_font_extents_t *extents);
//#void cairo_scaled_font_text_extents(cairo_scaled_font_t *scaled_font, const char *utf8, cairo_text_extents_t *extents);
//#void cairo_scaled_font_glyph_extents(cairo_scaled_font_t *scaled_font, const cairo_glyph_t *glyphs, int num_glyphs, cairo_text_extents_t *extents);
//#cairo_status_t cairo_scaled_font_text_to_glyphs(cairo_scaled_font_t *scaled_font, double x, double y, const char *utf8, int utf8_len, cairo_glyph_t **glyphs, int *num_glyphs, cairo_text_cluster_t **clusters, int *num_clusters, cairo_text_cluster_flags_t *cluster_flags);
//#cairo_font_face_t *cairo_scaled_font_get_font_face(cairo_scaled_font_t *scaled_font);
//#void cairo_scaled_font_get_font_options(cairo_scaled_font_t *scaled_font, cairo_font_options_t *options);
//#void cairo_scaled_font_get_font_matrix(cairo_scaled_font_t *scaled_font, cairo_matrix_t *font_matrix);
//#void cairo_scaled_font_get_ctm(cairo_scaled_font_t *scaled_font, cairo_matrix_t *ctm);
//#void cairo_scaled_font_get_scale_matrix(cairo_scaled_font_t *scaled_font, cairo_matrix_t *scale_matrix);
//#cairo_font_type_t cairo_scaled_font_get_type(cairo_scaled_font_t *scaled_font);
//#unsigned int cairo_scaled_font_get_reference_count(cairo_scaled_font_t *scaled_font);
//#cairo_status_t cairo_scaled_font_set_user_data(cairo_scaled_font_t *scaled_font, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_scaled_font_get_user_data(cairo_scaled_font_t *scaled_font, const cairo_user_data_key_t *key);

//#FT_Face cairo_ft_scaled_font_lock_face(cairo_scaled_font_t *scaled_font);
//#void cairo_ft_scaled_font_unlock_face(cairo_scaled_font_t *scaled_font);

//#cairo_status_t cairo_win32_scaled_font_select_font (cairo_scaled_font_t *scaled_font, HDC hdc);
//#void cairo_win32_scaled_font_done_font(cairo_scaled_font_t *scaled_font);
//#double cairo_win32_scaled_font_get_metrics_factor(cairo_scaled_font_t *scaled_font);
//#void cairo_win32_scaled_font_get_logical_to_device(cairo_scaled_font_t *scaled_font, cairo_matrix_t *logical_to_device);
//#void cairo_win32_scaled_font_get_device_to_logical(cairo_scaled_font_t *scaled_font, cairo_matrix_t *device_to_logical);

// implementation of class font_options
Gura_ImplementUserClass(scaled_font)
{
}

//-----------------------------------------------------------------------------
// Object_font_options implementation
//-----------------------------------------------------------------------------
Object_font_options::~Object_font_options()
{
	::cairo_font_options_destroy(_options);
}

Object *Object_font_options::Clone() const
{
	return NULL;
}

String Object_font_options::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.font_options>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for font_options
//-----------------------------------------------------------------------------
//#cairo_font_options_t *cairo_font_options_create(void);
//#cairo_font_options_t *cairo_font_options_copy(const cairo_font_options_t *original);
//#void cairo_font_options_destroy(cairo_font_options_t *options);
//#cairo_status_t cairo_font_options_status(cairo_font_options_t *options);

//#void cairo_ft_font_options_substitute(const cairo_font_options_t *options, FcPattern *pattern);

// cairo.font_options#merge(other:font_options):void
Gura_DeclareMethod(font_options, merge)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "other", VTYPE_font_options);
}

Gura_ImplementMethod(font_options, merge)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_font_options_t *other =
					Object_font_options::GetObject(args, 0)->GetEntity();
	::cairo_font_options_merge(options, other);
	if (IsError(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#hash()
Gura_DeclareMethod(font_options, hash)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, hash)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	unsigned long rtn = ::cairo_font_options_hash(options);
	if (IsError(sig, options)) return Value::Null;
	return Value(rtn);
}

// cairo.font_options#equal(other:font_options)
Gura_DeclareMethod(font_options, equal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_font_options);
}

Gura_ImplementMethod(font_options, equal)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_font_options_t *other =
					Object_font_options::GetObject(args, 0)->GetEntity();
	cairo_bool_t rtn = ::cairo_font_options_equal(options, other);
	if (IsError(sig, options)) return Value::Null;
	return Value(rtn);
}

// cairo.font_options#set_antialias(antialias:number):void
Gura_DeclareMethod(font_options, set_antialias)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "antialias", VTYPE_number);
}

Gura_ImplementMethod(font_options, set_antialias)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_antialias_t antialias = static_cast<cairo_antialias_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_font_options_set_antialias(options, antialias);
	if (IsError(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#get_antialias()
Gura_DeclareMethod(font_options, get_antialias)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, get_antialias)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_antialias_t antialias = ::cairo_font_options_get_antialias(options);
	if (IsError(sig, options)) return Value::Null;
	return Value(antialias);
}

// cairo.font_options#set_subpixel_order(subpixel_order:number):void
Gura_DeclareMethod(font_options, set_subpixel_order)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "subpixel_order", VTYPE_number);
}

Gura_ImplementMethod(font_options, set_subpixel_order)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_subpixel_order_t subpixel_order = static_cast<cairo_subpixel_order_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_font_options_set_subpixel_order(options, subpixel_order);
	if (IsError(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#get_subpixel_order()
Gura_DeclareMethod(font_options, get_subpixel_order)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, get_subpixel_order)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_subpixel_order_t subpixel_order = ::cairo_font_options_get_subpixel_order(options);
	if (IsError(sig, options)) return Value::Null;
	return Value(subpixel_order);
}

// cairo.font_options#set_hint_style(hint_style:number):void
Gura_DeclareMethod(font_options, set_hint_style)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "hint_style", VTYPE_number);
}

Gura_ImplementMethod(font_options, set_hint_style)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_hint_style_t hint_style = static_cast<cairo_hint_style_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_font_options_set_hint_style(options, hint_style);
	if (IsError(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#get_hint_style()
Gura_DeclareMethod(font_options, get_hint_style)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, get_hint_style)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_hint_style_t hint_style = ::cairo_font_options_get_hint_style(options);
	if (IsError(sig, options)) return Value::Null;
	return Value(hint_style);
}

// cairo.font_options#set_hint_metrics(hint_metrics:number):void
Gura_DeclareMethod(font_options, set_hint_metrics)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "hint_metrics", VTYPE_number);
}

Gura_ImplementMethod(font_options, set_hint_metrics)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_hint_metrics_t hint_metrics = static_cast<cairo_hint_metrics_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_font_options_set_hint_metrics(options, hint_metrics);
	if (IsError(sig, options)) return Value::Null;
	return Value::Null;
}

// cairo.font_options#get_hint_metrics()
Gura_DeclareMethod(font_options, get_hint_metrics)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_options, get_hint_metrics)
{
	Object_font_options *pThis = Object_font_options::GetThisObj(args);
	cairo_font_options_t *options = pThis->GetEntity();
	cairo_hint_metrics_t hint_metrics = ::cairo_font_options_get_hint_metrics(options);
	if (IsError(sig, options)) return Value::Null;
	return Value(hint_metrics);
}

// implementation of class font_options
Gura_ImplementUserClass(font_options)
{
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

//-----------------------------------------------------------------------------
// Object_device implementation
//-----------------------------------------------------------------------------
Object_device::~Object_device()
{
	::cairo_device_destroy(_device);
}

Object *Object_device::Clone() const
{
	return NULL;
}

String Object_device::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.device>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for device
//-----------------------------------------------------------------------------
//#cairo_device_t *cairo_device_reference(cairo_device_t *device);
//#void cairo_device_destroy(cairo_device_t *device);
//#cairo_status_t cairo_device_status(cairo_device_t *device);
//#void cairo_device_finish(cairo_device_t *device);
//#void cairo_device_flush(cairo_device_t *device);
//#cairo_device_type_t cairo_device_get_type(cairo_device_t *device);
//#unsigned int cairo_device_get_reference_count(cairo_device_t *device);
//#cairo_status_t cairo_device_set_user_data(cairo_device_t *device, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_device_get_user_data(cairo_device_t *device, const cairo_user_data_key_t *key);
//#cairo_status_t cairo_device_acquire(cairo_device_t *device);
//#void cairo_device_release(cairo_device_t *device);

// implementation of class device
Gura_ImplementUserClass(device)
{
}

//-----------------------------------------------------------------------------
// Object_surface implementation
//-----------------------------------------------------------------------------
Object_surface::~Object_surface()
{
	::cairo_surface_destroy(_surface);
	delete _pWriter;
}

Object *Object_surface::Clone() const
{
	return NULL;
}

bool Object_surface::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	symbols.insert(Gura_UserSymbol(image));
	symbols.insert(Gura_UserSymbol(stream));
	return true;
}

Value Object_surface::DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	Environment &env = *this;
	evaluatedFlag = true;
	cairo_surface_type_t type = ::cairo_surface_get_type(_surface);
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		cairo_surface_type_t surface_type = ::cairo_surface_get_type(_surface);
		return Value(surface_type);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		if (!HasSize()) return Value::Null;
		return Value(GetWidth());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		if (!HasSize()) return Value::Null;
		return Value(GetHeight());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(image))) {
		if (_pObjImage.IsNull()) {
			return Value::Null;
		} else {
			return Value(Object_image::Reference(_pObjImage.get()));
		}
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(stream))) {
		if (_pWriter == NULL) return Value::Null;
		Stream *pStream = _pWriter->GetStream();
		if (pStream == NULL) return Value::Null;
		Object_stream *pObjStream = new Object_stream(env, Stream::Reference(pStream));
		return Value(pObjStream);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_surface::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<cairo.surface:";
	cairo_surface_type_t surface_type = ::cairo_surface_get_type(_surface);
	str += SurfaceTypeToName(surface_type);
	if (surface_type == CAIRO_SURFACE_TYPE_IMAGE) {
		str += ":";
		str += NumberToString(::cairo_image_surface_get_width(_surface));
		str += "x";
		str += NumberToString(::cairo_image_surface_get_height(_surface));
	}
	str += ">";
	return str;
}

double Object_surface::GetWidth() const
{
	return !_pObjImage.IsNull()? _pObjImage->GetWidth() :
		(_pWriter != NULL)? _pWriter->GetWidth() : 0.;
}

double Object_surface::GetHeight() const
{
	return !_pObjImage.IsNull()? _pObjImage->GetHeight() :
		(_pWriter != NULL)? _pWriter->GetHeight() : 0.;
}

//-----------------------------------------------------------------------------
// Gura interfaces for surface
//-----------------------------------------------------------------------------
//#cairo_surface_t *cairo_surface_create_similar(cairo_surface_t *other, cairo_content_t content, int width, int height);
//#cairo_surface_t *cairo_surface_create_similar_image(cairo_surface_t *other, cairo_format_t format, int width, int height);
//#cairo_surface_t *cairo_surface_create_for_rectangle(cairo_surface_t *target, double x, double y, double width, double height);
//#cairo_surface_t *cairo_surface_reference(cairo_surface_t *surface);
//#void cairo_surface_destroy(cairo_surface_t *surface);
//#cairo_status_t cairo_surface_status(cairo_surface_t *surface);

//#cairo_surface_t *cairo_pdf_surface_create(const char *filename, double width_in_points, double height_in_points);
//#cairo_surface_t *cairo_pdf_surface_create_for_stream (cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points);
//#void cairo_pdf_surface_restrict_to_version(cairo_surface_t *surface, cairo_pdf_version_t version);
//#void cairo_pdf_get_versions(cairo_pdf_version_t const **versions, int *num_versions);
//#const char *cairo_pdf_version_to_string(cairo_pdf_version_t version);
//#void cairo_pdf_surface_set_size(cairo_surface_t *surface, double width_in_points, double height_in_points);

//#cairo_status_t cairo_surface_write_to_png(cairo_surface_t *surface, const char *filename);
//#cairo_status_t cairo_surface_write_to_png_stream(cairo_surface_t *surface, cairo_write_func_t write_func, void *closure);

//#cairo_surface_t *cairo_ps_surface_create(const char *filename, double width_in_points, double height_in_points);
//#cairo_surface_t *cairo_ps_surface_create_for_stream(cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points);
//#void cairo_ps_surface_restrict_to_level(cairo_surface_t *surface, cairo_ps_level_t level);
//#void cairo_ps_get_levels(cairo_ps_level_t const **levels, int *num_levels);
//#const char *cairo_ps_level_to_string(cairo_ps_level_t level);
//#void cairo_ps_surface_set_eps(cairo_surface_t *surface, cairo_bool_t eps);
//#cairo_bool_t cairo_ps_surface_get_eps(cairo_surface_t *surface);
//#void cairo_ps_surface_set_size(cairo_surface_t *surface, double width_in_points, double height_in_points);
//#void cairo_ps_surface_dsc_begin_setup(cairo_surface_t *surface);
//#void cairo_ps_surface_dsc_begin_page_setup(cairo_surface_t *surface);
//#void cairo_ps_surface_dsc_comment(cairo_surface_t *surface, const char *comment);

//#cairo_surface_t *cairo_recording_surface_create(cairo_content_t content, const cairo_rectangle_t *extents);
//#void cairo_recording_surface_ink_extents(cairo_surface_t *surface, double *x0, double *y0, double *width, double *height);
//#cairo_bool_t cairo_recording_surface_get_extents(cairo_surface_t *surface, cairo_rectangle_t *extents);

//#cairo_surface_t *cairo_win32_surface_create(HDC hdc);
//#cairo_surface_t *cairo_win32_surface_create_with_dib(cairo_format_t format, int width, int height);
//#cairo_surface_t *cairo_win32_surface_create_with_ddb(HDC hdc, cairo_format_t format, int width, int height);
//#cairo_surface_t *cairo_win32_printing_surface_create(HDC hdc);
//#HDC cairo_win32_surface_get_dc(cairo_surface_t *surface);
//#cairo_surface_t *cairo_win32_surface_get_image(cairo_surface_t *surface);

//#cairo_surface_t *cairo_svg_surface_create(const char *filename, double width_in_points, double height_in_points);
//#cairo_surface_t *cairo_svg_surface_create_for_stream (cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points);
//#void cairo_svg_surface_restrict_to_version(cairo_surface_t *surface, cairo_svg_version_t version);
//#void cairo_svg_get_versions(cairo_svg_version_t const **versions, int *num_versions);
//#const char *cairo_svg_version_to_string(cairo_svg_version_t version);

//#cairo_surface_t *cairo_quartz_surface_create(cairo_format_t format, unsigned int width, unsigned int height);
//#cairo_surface_t *cairo_quartz_surface_create_for_cg_context(CGContextRef cgContext, unsigned int width, unsigned int height);
//#CGContextRef cairo_quartz_surface_get_cg_context (cairo_surface_t *surface);

//#cairo_surface_t *cairo_xcb_surface_create(xcb_connection_t *connection, xcb_drawable_t drawable, xcb_visualtype_t *visual, int width, int height);
//#cairo_surface_t *cairo_xcb_surface_create_for_bitmap(xcb_connection_t *connection, xcb_screen_t *screen, xcb_pixmap_t bitmap, int width, int height);
//#cairo_surface_t *cairo_xcb_surface_create_with_xrender_format(xcb_connection_t *connection, xcb_screen_t *screen, xcb_drawable_t drawable, xcb_render_pictforminfo_t *format, int width, int height);
//#void cairo_xcb_surface_set_size(cairo_surface_t *surface, int width, int height);
//#void cairo_xcb_surface_set_drawable(cairo_surface_t *surface, xcb_drawable_t drawable, int width, int height);
//#xcb_connection_t *cairo_xcb_device_get_connection(cairo_device_t *device);
//#void cairo_xcb_device_debug_cap_xrender_version(cairo_device_t *device, int major_version, int minor_version);
//#void cairo_xcb_device_debug_cap_xshm_version(cairo_device_t *device, int major_version, int minor_version);
//#int cairo_xcb_device_debug_get_precision(cairo_device_t *device);
//#void cairo_xcb_device_debug_set_precision(cairo_device_t *device, int precision);

//#cairo_surface_t *cairo_xlib_surface_create(Display *dpy, Drawable drawable, Visual *visual, int width, int height);
//#cairo_surface_t *cairo_xlib_surface_create_for_bitmap(Display *dpy, Pixmap bitmap, Screen *screen, int width, int height);
//#void cairo_xlib_surface_set_size(cairo_surface_t *surface, int width, int height);
//#Display *cairo_xlib_surface_get_display(cairo_surface_t *surface);
//#Screen *cairo_xlib_surface_get_screen(cairo_surface_t *surface);
//#void cairo_xlib_surface_set_drawable(cairo_surface_t *surface, Drawable drawable, int width, int height);
//#Drawable cairo_xlib_surface_get_drawable(cairo_surface_t *surface);
//#Visual *cairo_xlib_surface_get_visual(cairo_surface_t *surface);
//#int cairo_xlib_surface_get_width(cairo_surface_t *surface);
//#int cairo_xlib_surface_get_height(cairo_surface_t *surface);
//#int cairo_xlib_surface_get_depth(cairo_surface_t *surface);
//#void cairo_xlib_device_debug_cap_xrender_version(cairo_device_t *device, int major_version, int minor_version);
//#int cairo_xlib_device_debug_get_precision(cairo_device_t *device);
//#void cairo_xlib_device_debug_set_precision(cairo_device_t *device, int precision);

//#cairo_surface_t *   cairo_xlib_surface_create_with_xrender_format(Display *dpy, Drawable drawable, Screen *screen, XRenderPictFormat *format, int width, int height);
//#XRenderPictFormat * cairo_xlib_surface_get_xrender_format(cairo_surface_t *surface);

//#cairo_device_t *cairo_script_create(const char *filename);
//#cairo_device_t *cairo_script_create_for_stream(cairo_write_func_t write_func, void *closure);
//#cairo_status_t cairo_script_from_recording_surface(cairo_device_t *script, cairo_surface_t *recording_surface);
//#cairo_script_mode_t cairo_script_get_mode(cairo_device_t *script);
//#void cairo_script_set_mode(cairo_device_t *script, cairo_script_mode_t mode);
//#cairo_surface_t *cairo_script_surface_create(cairo_device_t *script, cairo_content_t content, double width, double height);
//#cairo_surface_t *cairo_script_surface_create_for_target(cairo_device_t *script, cairo_surface_t *target);
//#void cairo_script_write_comment(cairo_device_t *script, const char *comment, int len);

// cairo.surface#finish():reduce
Gura_DeclareMethod(surface, finish)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, finish)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_finish(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#flush():reduce
Gura_DeclareMethod(surface, flush)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, flush)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_flush(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#get_device()
Gura_DeclareMethod(surface, get_device)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_device)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_device_t *device = ::cairo_surface_get_device(surface);
	if (IsError(sig, surface) || device == NULL) return Value::Null;
	Object_device *pObjDevice = new Object_device(::cairo_device_reference(device));
	return Value(pObjDevice);
}

// cairo.surface#get_font_options()
Gura_DeclareMethod(surface, get_font_options)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_font_options)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_font_options_t *options = ::cairo_font_options_create();
	::cairo_surface_get_font_options(surface, options);
	if (IsError(sig, surface)) {
		::cairo_font_options_destroy(options);
		return Value::Null;
	}
	Object_font_options *pObjFontOptions = new Object_font_options(options);
	return Value(pObjFontOptions);
}

// cairo.surface#get_content()
Gura_DeclareMethod(surface, get_content)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_content)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_content_t content = ::cairo_surface_get_content(surface);
	if (IsError(sig, surface)) return Value::Null;
	return Value(content);
}

// cairo.surface#mark_dirty():reduce
Gura_DeclareMethod(surface, mark_dirty)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, mark_dirty)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_mark_dirty(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#mark_dirty_rectangle(x:number, y:number, width:number, height:number):reduce
Gura_DeclareMethod(surface, mark_dirty_rectangle)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
}

Gura_ImplementMethod(surface, mark_dirty_rectangle)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_mark_dirty_rectangle(surface,
			args.GetInt(0), args.GetInt(1), args.GetInt(2), args.GetInt(3));
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#set_device_offset(x_offset:number, y_offset:number):reduce
Gura_DeclareMethod(surface, set_device_offset)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x_offset", VTYPE_number);
	DeclareArg(env, "y_offset", VTYPE_number);
}

Gura_ImplementMethod(surface, set_device_offset)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_set_device_offset(surface, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#get_device_offset()
Gura_DeclareMethod(surface, get_device_offset)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_device_offset)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	double x_offset, y_offset;
	::cairo_surface_get_device_offset(surface, &x_offset, &y_offset);
	if (IsError(sig, surface)) return Value::Null;
	return CreateValueList(env, x_offset, y_offset);
}

// cairo.surface#set_fallback_resolution(x_pixels_per_inch:number, y_pixels_per_inch:number):reduce
Gura_DeclareMethod(surface, set_fallback_resolution)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x_pixels_per_inch", VTYPE_number);
	DeclareArg(env, "y_pixels_per_inch", VTYPE_number);
}

Gura_ImplementMethod(surface, set_fallback_resolution)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_set_fallback_resolution(surface, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#get_fallback_resolution()
Gura_DeclareMethod(surface, get_fallback_resolution)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_fallback_resolution)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	double x_pixels_per_inch, y_pixels_per_inch;
	::cairo_surface_get_fallback_resolution(surface, &x_pixels_per_inch, &y_pixels_per_inch);
	if (IsError(sig, surface)) return Value::Null;
	return CreateValueList(env, x_pixels_per_inch, y_pixels_per_inch);
}

// cairo.surface#get_type()
Gura_DeclareMethod(surface, get_type)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_type)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_surface_type_t rtn = ::cairo_surface_get_type(surface);
	if (IsError(sig, surface)) return Value::Null;
	return Value(rtn);
}

//#unsigned int cairo_surface_get_reference_count(cairo_surface_t *surface);
//#cairo_status_t cairo_surface_set_user_data(cairo_surface_t *surface, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_surface_get_user_data(cairo_surface_t *surface, const cairo_user_data_key_t *key);

// cairo.surface#copy_page():reduce
Gura_DeclareMethod(surface, copy_page)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, copy_page)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_copy_page(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#show_page():reduce
Gura_DeclareMethod(surface, show_page)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, show_page)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_surface_show_page(surface);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.surface#has_show_text_glyphs()
Gura_DeclareMethod(surface, has_show_text_glyphs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, has_show_text_glyphs)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	bool rtn = ::cairo_surface_has_show_text_glyphs(surface)? true : false;
	if (IsError(sig, surface)) return Value::Null;
	return Value(rtn);
}

// cairo.surface#set_mime_data():reduce
Gura_DeclareMethod(surface, set_mime_data)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(surface, set_mime_data)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// cairo.surface#get_mime_data()
Gura_DeclareMethod(surface, get_mime_data)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, get_mime_data)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// cairo.surface#supports_mime_type()
Gura_DeclareMethod(surface, supports_mime_type)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, supports_mime_type)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// cairo.surface#map_to_image()
Gura_DeclareMethod(surface, map_to_image)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, map_to_image)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// cairo.surface#unmap_image()
Gura_DeclareMethod(surface, unmap_image)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(surface, unmap_image)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	
	sig.SetError(ERR_SystemError, "not implemented yet");
	
	return Value::Null;
}

// implementation of class surface
Gura_ImplementUserClassWithCast(surface)
{
	Gura_AssignMethod(surface, finish);
	Gura_AssignMethod(surface, flush);
	Gura_AssignMethod(surface, get_device);
	Gura_AssignMethod(surface, get_font_options);
	Gura_AssignMethod(surface, get_content);
	Gura_AssignMethod(surface, mark_dirty);
	Gura_AssignMethod(surface, mark_dirty_rectangle);
	Gura_AssignMethod(surface, set_device_offset);
	Gura_AssignMethod(surface, get_device_offset);
	Gura_AssignMethod(surface, set_fallback_resolution);
	Gura_AssignMethod(surface, get_fallback_resolution);
	Gura_AssignMethod(surface, get_type);
	Gura_AssignMethod(surface, copy_page);
	Gura_AssignMethod(surface, show_page);
	Gura_AssignMethod(surface, has_show_text_glyphs);
	Gura_AssignMethod(surface, set_mime_data);
	Gura_AssignMethod(surface, get_mime_data);
	Gura_AssignMethod(surface, supports_mime_type);
	Gura_AssignMethod(surface, map_to_image);
	Gura_AssignMethod(surface, unmap_image);
}

Gura_ImplementCastFrom(surface)
{
	if (value.IsImage()) {
		Object_image *pObjImage = Object_image::Reference(value.GetImageObj());
		cairo_surface_t *surface = CreateSurfaceFromImage(sig, pObjImage);
		if (sig.IsSignalled()) {
			Object_image::Delete(pObjImage);
			return false;
		}
		value = Value(new Object_surface(surface, pObjImage));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(surface)
{
	return false;
}

//-----------------------------------------------------------------------------
// Object_image_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for image_surface
//-----------------------------------------------------------------------------
//#cairo_surface_t *cairo_image_surface_create_for_data(unsigned char *data, cairo_format_t format, int width, int height, int stride);
//#unsigned char *cairo_image_surface_get_data(cairo_surface_t *surface);
//#cairo_format_t cairo_image_surface_get_format(cairo_surface_t *surface);
//#int cairo_image_surface_get_width(cairo_surface_t *surface);
//#int cairo_image_surface_get_height(cairo_surface_t *surface);
//#int cairo_image_surface_get_stride(cairo_surface_t *surface);

//#cairo_surface_t *cairo_image_surface_create_from_png(const char *filename);
//#cairo_surface_t *cairo_image_surface_create_from_png_stream(cairo_read_func_t read_func, void *closure);

Gura_ImplementUserClass(image_surface)
{
}

//-----------------------------------------------------------------------------
// Object_pdf_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for pdf_surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(pdf_surface)
{
}

//-----------------------------------------------------------------------------
// Object_ps_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for ps_surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(ps_surface)
{
}

//-----------------------------------------------------------------------------
// Object_recording_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for recording_surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(recording_surface)
{
}

//-----------------------------------------------------------------------------
// Object_win32_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for win32_surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(win32_surface)
{
}

//-----------------------------------------------------------------------------
// Object_svg_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for svg_surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(svg_surface)
{
}

//-----------------------------------------------------------------------------
// Object_quartz_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for quartz_surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(quartz_surface)
{
}

//-----------------------------------------------------------------------------
// Object_xcb_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for xcb_surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(xcb_surface)
{
}

//-----------------------------------------------------------------------------
// Object_xlib_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for xlib_surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(xlib_surface)
{
}

//-----------------------------------------------------------------------------
// Object_script_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for script_surface
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(script_surface)
{
}

//-----------------------------------------------------------------------------
// Object_pattern implementation
//-----------------------------------------------------------------------------
Object_pattern::~Object_pattern()
{
	::cairo_pattern_destroy(_pattern);
}

Object *Object_pattern::Clone() const
{
	return NULL;
}

String Object_pattern::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.pattern>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for pattern
//-----------------------------------------------------------------------------
//#cairo_pattern_t *cairo_pattern_create_raster_source(void *user_data, cairo_content_t content, int width, int height);
//#void cairo_raster_source_pattern_set_callback_data(cairo_pattern_t *pattern, void *data);
//#void *cairo_raster_source_pattern_get_callback_data(cairo_pattern_t *pattern);
//#void cairo_raster_source_pattern_set_acquire(cairo_pattern_t *pattern, cairo_raster_source_acquire_func_t acquire, cairo_raster_source_release_func_t release);
//#void cairo_raster_source_pattern_get_acquire(cairo_pattern_t *pattern, cairo_raster_source_acquire_func_t *acquire, cairo_raster_source_release_func_t *release);
//#void cairo_raster_source_pattern_set_snapshot(cairo_pattern_t *pattern, cairo_raster_source_snapshot_func_t snapshot);
//#cairo_raster_source_snapshot_func_t cairo_raster_source_pattern_get_snapshot(cairo_pattern_t *pattern);
//#void cairo_raster_source_pattern_set_copy(cairo_pattern_t *pattern, cairo_raster_source_copy_func_t copy);
//#cairo_raster_source_copy_func_t cairo_raster_source_pattern_get_copy(cairo_pattern_t *pattern);
//#void cairo_raster_source_pattern_set_finish(cairo_pattern_t *pattern, cairo_raster_source_finish_func_t finish);
//#cairo_raster_source_finish_func_t cairo_raster_source_pattern_get_finish(cairo_pattern_t *pattern);

// cairo.pattern#add_color_stop_rgb(offset:number, red:number, green:number, blue:number):reduce
Gura_DeclareMethod(pattern, add_color_stop_rgb)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementMethod(pattern, add_color_stop_rgb)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	::cairo_pattern_add_color_stop_rgb(pattern, args.GetDouble(0),
		args.GetDouble(1), args.GetDouble(2), args.GetDouble(3));
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#add_color_stop_rgba(offset:number, red:number, green:number, blue:number, alpha:number):reduce
Gura_DeclareMethod(pattern, add_color_stop_rgba)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementMethod(pattern, add_color_stop_rgba)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	::cairo_pattern_add_color_stop_rgba(pattern, args.GetDouble(0),
		args.GetDouble(1), args.GetDouble(2), args.GetDouble(3), args.GetDouble(4));
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_color_stop_count()
Gura_DeclareMethod(pattern, get_color_stop_count)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_color_stop_count)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	int count;
	cairo_status_t status = ::cairo_pattern_get_color_stop_count(pattern, &count);
	if (IsError(sig, status)) return Value::Null;
	return Value(count);
}

// cairo.pattern#get_color_stop_rgba(index:number)
Gura_DeclareMethod(pattern, get_color_stop_rgba)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "index", VTYPE_number);
}

Gura_ImplementMethod(pattern, get_color_stop_rgba)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double offset, red, green, blue, alpha;
	cairo_status_t status = ::cairo_pattern_get_color_stop_rgba(pattern, args.GetInt(0),
										&offset, &red, &green, &blue, &alpha);
	if (IsError(sig, status)) return Value::Null;
	return CreateValueList(env, offset, red, green, blue, alpha);
}

//#cairo_pattern_t *cairo_pattern_create_rgb(double red, double green, double blue);
//#cairo_pattern_t *cairo_pattern_create_rgba(double red, double green, double blue, double alpha);

// cairo.pattern#get_rgba()
Gura_DeclareMethod(pattern, get_rgba)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_rgba)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double red, green, blue, alpha;
	cairo_status_t status = ::cairo_pattern_get_rgba(pattern,
										&red, &green, &blue, &alpha);
	if (IsError(sig, status)) return Value::Null;
	return CreateValueList(env, red, green, blue, alpha);
}

//#cairo_pattern_t *cairo_pattern_create_for_surface(cairo_surface_t *surface);

// cairo.pattern#get_surface()
Gura_DeclareMethod(pattern, get_surface)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_surface)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_surface_t *surface = NULL;
	cairo_status_t status = ::cairo_pattern_get_surface(pattern, &surface);
	if (IsError(sig, status)) return Value::Null;
	Object_surface *pObjSurface =
			new Object_surface(::cairo_surface_reference(surface));
	return Value(pObjSurface);
}

//#cairo_pattern_t *cairo_pattern_create_linear(double x0, double y0, double x1, double y1);

// cairo.pattern#get_linear_points()
Gura_DeclareMethod(pattern, get_linear_points)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_linear_points)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double x0, y0, x1, y1;
	cairo_status_t status =
			::cairo_pattern_get_linear_points(pattern, &x0, &y0, &x1, &y1);
	if (IsError(sig, status)) return Value::Null;
	return CreateValueList(env, x0, y0, x1, y1);
}

//#cairo_pattern_t *cairo_pattern_create_radial(double cx0, double cy0, double radius0, double cx1, double cy1, double radius1);

// cairo.pattern#get_radial_circles():reduce
Gura_DeclareMethod(pattern, get_radial_circles)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(pattern, get_radial_circles)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double x0, y0, r0, x1, y1, r1;
	cairo_status_t status =
		::cairo_pattern_get_radial_circles(pattern, &x0, &y0, &r0, &x1, &y1, &r1);
	if (IsError(sig, status)) return Value::Null;
	return CreateValueList(env, x0, y0, r0, x1, y1, r1);
}

//#cairo_pattern_t *cairo_pattern_create_mesh(void);
//#void cairo_mesh_pattern_begin_patch(cairo_pattern_t *pattern);
//#void cairo_mesh_pattern_end_patch(cairo_pattern_t *pattern);
//#void cairo_mesh_pattern_move_to(cairo_pattern_t *pattern, double x, double y);
//#void cairo_mesh_pattern_line_to(cairo_pattern_t *pattern, double x, double y);
//#void cairo_mesh_pattern_curve_to(cairo_pattern_t *pattern, double x1, double y1, double x2, double y2, double x3, double y3);
//#void cairo_mesh_pattern_set_control_point(cairo_pattern_t *pattern, unsigned int point_num, double x, double y);
//#void cairo_mesh_pattern_set_corner_color_rgb(cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue);
//#void cairo_mesh_pattern_set_corner_color_rgba(cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue, double alpha);
//#cairo_status_t cairo_mesh_pattern_get_patch_count(cairo_pattern_t *pattern, unsigned int *count);
//#cairo_path_t *cairo_mesh_pattern_get_path(cairo_pattern_t *pattern, unsigned int patch_num);
//#cairo_status_t cairo_mesh_pattern_get_control_point(cairo_pattern_t *pattern, unsigned int patch_num, unsigned int point_num, double *x, double *y);
//#cairo_status_t cairo_mesh_pattern_get_corner_color_rgba(cairo_pattern_t *pattern, unsigned int patch_num, unsigned int corner_num, double *red, double *green, double *blue, double *alpha);

//#cairo_pattern_t *cairo_pattern_reference(cairo_pattern_t *pattern);
//#void cairo_pattern_destroy(cairo_pattern_t *pattern);
//#cairo_status_t cairo_pattern_status(cairo_pattern_t *pattern);

// cairo.pattern#set_extend(extend:number):reduce
Gura_DeclareMethod(pattern, set_extend)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "extend", VTYPE_number);
}

Gura_ImplementMethod(pattern, set_extend)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_extend_t extend = static_cast<cairo_extend_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_pattern_set_extend(pattern, extend);
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_extend()
Gura_DeclareMethod(pattern, get_extend)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_extend)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_extend_t extend = ::cairo_pattern_get_extend(pattern);
	if (IsError(sig, pattern)) return Value::Null;
	return Value(extend);
}

// cairo.pattern#set_filter(filter:number):reduce
Gura_DeclareMethod(pattern, set_filter)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "filter", VTYPE_number);
}

Gura_ImplementMethod(pattern, set_filter)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_filter_t filter = static_cast<cairo_filter_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_pattern_set_filter(pattern, filter);
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_filter()
Gura_DeclareMethod(pattern, get_filter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_filter)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_filter_t filter = ::cairo_pattern_get_filter(pattern);
	if (IsError(sig, pattern)) return Value::Null;
	return Value(pattern);
}

// cairo.pattern#set_matrix(matrix:matrix):reduce
Gura_DeclareMethod(pattern, set_matrix)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_matrix);
}

Gura_ImplementMethod(pattern, set_matrix)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	Object_matrix *pObjMatrix = args.GetMatrixObj(0);
	cairo_matrix_t matrix;
	if (!MatrixToCairo(sig, matrix, pObjMatrix)) return Value::Null;
	::cairo_pattern_set_matrix(pattern, &matrix);
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_matrix()
Gura_DeclareMethod(pattern, get_matrix)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_matrix)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_matrix_t matrix;
	::cairo_pattern_get_matrix(pattern, &matrix);
	if (IsError(sig, pattern)) return Value::Null;
	Object_matrix *pObjMatrix = CairoToMatrix(env, matrix);
	return Value(pObjMatrix);
}

//#cairo_pattern_type_t cairo_pattern_get_type(cairo_pattern_t *pattern);
//#unsigned int cairo_pattern_get_reference_count(cairo_pattern_t *pattern);
//#cairo_status_t cairo_pattern_set_user_data(cairo_pattern_t *pattern, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_pattern_get_user_data(cairo_pattern_t *pattern, const cairo_user_data_key_t *key);

// implementation of class pattern
Gura_ImplementUserClass(pattern)
{
	Gura_AssignMethod(pattern, add_color_stop_rgb);
	Gura_AssignMethod(pattern, add_color_stop_rgba);
	Gura_AssignMethod(pattern, get_color_stop_count);
	Gura_AssignMethod(pattern, get_color_stop_rgba);
	Gura_AssignMethod(pattern, get_rgba);
	Gura_AssignMethod(pattern, get_surface);
	Gura_AssignMethod(pattern, get_linear_points);
	Gura_AssignMethod(pattern, get_radial_circles);
	Gura_AssignMethod(pattern, set_extend);
	Gura_AssignMethod(pattern, get_extend);
	Gura_AssignMethod(pattern, set_filter);
	Gura_AssignMethod(pattern, get_filter);
	Gura_AssignMethod(pattern, set_matrix);
	Gura_AssignMethod(pattern, get_matrix);
}

//-----------------------------------------------------------------------------
// Object_path implementation
//-----------------------------------------------------------------------------
Object_path::~Object_path()
{
	::cairo_path_destroy(_path);
}

Object *Object_path::Clone() const
{
	return NULL;
}

String Object_path::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.path>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for path
//-----------------------------------------------------------------------------
// implementation of class path
Gura_ImplementUserClass(path)
{
}

//-----------------------------------------------------------------------------
// Object_glyph implementation
//-----------------------------------------------------------------------------
Object_glyph::~Object_glyph()
{
}

Object *Object_glyph::Clone() const
{
	return NULL;
}

String Object_glyph::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.glyph>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for glyph
//-----------------------------------------------------------------------------
//#cairo_glyph_t *cairo_glyph_allocate(int num_glyphs);
//#void cairo_glyph_free(cairo_glyph_t *glyphs);

// implementation of class glyph
Gura_ImplementUserClass(glyph)
{
}

//-----------------------------------------------------------------------------
// Object_text_cluster implementation
//-----------------------------------------------------------------------------
Object_text_cluster::~Object_text_cluster()
{
}

Object *Object_text_cluster::Clone() const
{
	return NULL;
}

String Object_text_cluster::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.text_cluster>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for text_cluster
//-----------------------------------------------------------------------------
//#cairo_text_cluster_t *cairo_text_cluster_allocate(int num_clusters);
//#void cairo_text_cluster_free(cairo_text_cluster_t *clusters);

// implementation of class text_cluster
Gura_ImplementUserClass(text_cluster)
{
}

//-----------------------------------------------------------------------------
// Gura interfaces for image
// These method are available after importing opengl module.
//-----------------------------------------------------------------------------
// image#cairo() {block?}
Gura_DeclareMethod(image, cairo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, cairo)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	Object_image *pObjImage = Object_image::Reference(pThis);
	cairo_surface_t *surface = CreateSurfaceFromImage(sig, pObjImage);
	if (sig.IsSignalled()) {
		Object_image::Delete(pObjImage);
		return Value::Null;
	}
	Object_surface *pObjSurface = new Object_surface(surface, pObjImage);
	cairo_t *cr = ::cairo_create(surface);
	Value result(new Object_context(cr, pObjSurface));
	return ReturnValue(env, sig, args, result);
}

//-----------------------------------------------------------------------------
// Gura module functions: cairo
//-----------------------------------------------------------------------------
// cairo.image_create(width:number, height:number, color?:color) {block?}
Gura_DeclareFunction(image_create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(image_create)
{
	Object_image *pObjImage = new Object_image(env, Image::FORMAT_RGBA);
	size_t width = args.GetSizeT(0);
	size_t height = args.GetSizeT(1);
	if (!pObjImage->AllocBuffer(sig, width, height, 0xff)) return Value::Null;
	if (args.IsColor(2)) {
		pObjImage->Fill(args.GetColorObj(2));
	}
	cairo_surface_t *surface = ::cairo_image_surface_create_for_data(
				pObjImage->GetBuffer(), CAIRO_FORMAT_ARGB32,
				static_cast<int>(width), static_cast<int>(height),
				static_cast<int>(pObjImage->GetBytesPerLine()));
	Object_surface *pObjSurface = new Object_surface(surface, pObjImage);
	cairo_t *cr = ::cairo_create(surface);
	Value result(new Object_context(cr, pObjSurface));
	return ReturnValue(env, sig, args, result);
}

// cairo.pdf_create(stream:stream:w, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareFunction(pdf_create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(pdf_create)
{
	double width = args.GetDouble(1), height = args.GetDouble(2);
	Writer_Stream *pWriter = new Writer_Stream(sig, width, height,
									Stream::Reference(&args.GetStream(0)));
	cairo_surface_t *surface = ::cairo_pdf_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_surface(surface, pWriter);
	cairo_t *cr = ::cairo_create(surface);
	Value result(new Object_context(cr, pObjSurface));
	return ReturnValue(env, sig, args, result);
}

// cairo.ps_create(stream:stream:w, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareFunction(ps_create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ps_create)
{
	double width = args.GetDouble(1), height = args.GetDouble(2);
	Writer_Stream *pWriter = new Writer_Stream(sig, width, height,
									Stream::Reference(&args.GetStream(0)));
	cairo_surface_t *surface = ::cairo_ps_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_surface(surface, pWriter);
	cairo_t *cr = ::cairo_create(surface);
	Value result(new Object_context(cr, pObjSurface));
	return ReturnValue(env, sig, args, result);
}

// cairo.svg_create(stream:stream:w, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareFunction(svg_create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(svg_create)
{
	double width = args.GetDouble(1), height = args.GetDouble(2);
	Writer_Stream *pWriter = new Writer_Stream(sig, width, height,
									Stream::Reference(&args.GetStream(0)));
	cairo_surface_t *surface = ::cairo_svg_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_surface(surface, pWriter);
	cairo_t *cr = ::cairo_create(surface);
	Value result(new Object_context(cr, pObjSurface));
	return ReturnValue(env, sig, args, result);
}

#if defined(HAVE_WINDOWS_H)
// cairo.emf_create(filename:string, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareFunction(emf_create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "filename", VTYPE_string);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(emf_create)
{
	double width = args.GetDouble(1), height = args.GetDouble(2);
	RECT rc;
	rc.left = 0, rc.top = 0;
	rc.right = static_cast<long>(width * 20);	// unit: 1/20pt
	rc.bottom = static_cast<long>(height * 20);	// unit: 1/20pt
	HDC hdc = ::CreateEnhMetaFile(NULL, args.GetString(0), &rc, "EMF by Gura\0");
	::StartPage(hdc);
	//::SetMapMode(hdc, MM_TWIPS);				// 1 unit = 1/20pt
	::SetMapMode(hdc, MM_HIMETRIC);				// 1 unit = 0.01mm
	//::SetWindowOrgEx(hdc, 0, height * 20, NULL);
	//::MoveToEx(hdc, 0, 0, NULL);
	//::LineTo(hdc, 1000, 1000);
	//::MoveToEx(hdc, 0, 0, NULL);
	//::LineTo(hdc, 1000, -1000);
	Writer_EnhMetaFile *pWriter = new Writer_EnhMetaFile(sig, width, height, hdc);
	cairo_surface_t *surface = ::cairo_win32_surface_create(hdc);
	//cairo_surface_t *surface = ::cairo_win32_printing_surface_create(hdc);
	Object_surface *pObjSurface = new Object_surface(surface, pWriter);
	cairo_t *cr = ::cairo_create(surface);
	Value result(new Object_context(cr, pObjSurface));
	return ReturnValue(env, sig, args, result);
}

// cairo.printer_create(printer_name:string, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareFunction(printer_create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "printer_name", VTYPE_string);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(printer_create)
{
	const char *driverName = "WINSPOOL\0";
	const char *printerName = args.GetString(0);
	char printerNameDefault[MAX_PATH];
	BYTE printerInfoBuff[16384];
	PRINTER_INFO_2 *pPrinterInfo2 = reinterpret_cast<PRINTER_INFO_2 *>(printerInfoBuff);
	if (::strcmp(printerName, "") == 0) {
		DWORD cch;
		if (!::GetDefaultPrinter(printerNameDefault, &cch)) {
			sig.SetError(ERR_IOError, "failed to get a default printer");
			return Value::Null;
		}
		printerName = printerNameDefault;
	}
	do {
		HANDLE hPrinter;
		if (!::OpenPrinter(const_cast<char *>(printerName), &hPrinter, NULL)) {
			sig.SetError(ERR_IOError, "failed to open printer handler");
			return Value::Null;
		}
		DWORD cbNeeded;
		if (!::GetPrinter(hPrinter, 2, printerInfoBuff, sizeof(printerInfoBuff), &cbNeeded)) {
			sig.SetError(ERR_IOError, "failed to get printer information");
			return Value::Null;
		}
		::ClosePrinter(hPrinter);
	} while (0);
	double width = args.GetDouble(1), height = args.GetDouble(2);
	RECT rc;
	rc.left = 0, rc.top = 0;
	rc.right = static_cast<long>(width * 20);	// unit: 1/20pt
	rc.bottom = static_cast<long>(height * 20);	// unit: 1/20pt
	HDC hdc = ::CreateDC(driverName, printerName, pPrinterInfo2->pPortName, NULL);
	::SetMapMode(hdc, MM_TWIPS);				// 1 unit = 1/20pt
	//::SetMapMode(hdc, MM_HIMETRIC);			// 1 unit = 0.01mm
	Writer_WindowsDC *pWriter = new Writer_WindowsDC(sig, width, height, hdc);
	cairo_surface_t *surface = ::cairo_win32_printing_surface_create(hdc);
	Object_surface *pObjSurface = new Object_surface(surface, pWriter);
	cairo_t *cr = ::cairo_create(surface);
	Value result(new Object_context(cr, pObjSurface));
	return ReturnValue(env, sig, args, result);
}
#endif

// cairo.pattern_create_rgb(red:number, green:number, blue:number) {block?}
Gura_DeclareFunction(pattern_create_rgb)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(pattern_create_rgb)
{
	cairo_pattern_t *pattern = ::cairo_pattern_create_rgb(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2));
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
}

// cairo.pattern_create_rgba(red:number, green:number, blue:number, alpha:number) {block?}
Gura_DeclareFunction(pattern_create_rgba)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(pattern_create_rgba)
{
	cairo_pattern_t *pattern = ::cairo_pattern_create_rgba(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2), args.GetDouble(3));
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
}

// cairo.pattern_create_color(color:color, alpha?:number) {block?}
Gura_DeclareFunction(pattern_create_color)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(pattern_create_color)
{
	const Color &color = Object_color::GetObject(args, 0)->GetColor();
	double red = static_cast<double>(color.GetRed()) / 255;
	double green = static_cast<double>(color.GetGreen()) / 255;
	double blue = static_cast<double>(color.GetBlue()) / 255;
	cairo_pattern_t *pattern;
	if (args.IsNumber(1)) {
		double alpha = args.GetDouble(1);
		pattern = ::cairo_pattern_create_rgba(red, green, blue, alpha);
	} else {
		pattern = ::cairo_pattern_create_rgb(red, green, blue);
	}
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
}

// cairo.pattern_create_for_surface(surface:cairo.surface) {block?}
Gura_DeclareFunction(pattern_create_for_surface)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "surface", VTYPE_surface);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(pattern_create_for_surface)
{
	cairo_surface_t *surface = Object_surface::GetObject(args, 0)->GetEntity();
	cairo_pattern_t *pattern = ::cairo_pattern_create_for_surface(surface);
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
}

// cairo.pattern_create_linear(x0:number, y0:number, x1:number, y1:number) {block?}
Gura_DeclareFunction(pattern_create_linear)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x0", VTYPE_number);
	DeclareArg(env, "y0", VTYPE_number);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(pattern_create_linear)
{
	cairo_pattern_t *pattern = ::cairo_pattern_create_linear(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2), args.GetDouble(3));
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
}

// cairo.pattern_create_radial(cx0:number, cy0:number, radius0:number, cx1:number, cy1:number, radius1:number) {block?}
Gura_DeclareFunction(pattern_create_radial)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "cx0", VTYPE_number);
	DeclareArg(env, "cy0", VTYPE_number);
	DeclareArg(env, "radius0", VTYPE_number);
	DeclareArg(env, "cx1", VTYPE_number);
	DeclareArg(env, "cy1", VTYPE_number);
	DeclareArg(env, "radius1", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(pattern_create_radial)
{
	cairo_pattern_t *pattern = ::cairo_pattern_create_radial(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2),
			args.GetDouble(3), args.GetDouble(4), args.GetDouble(5));
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
}

//#int cairo_format_stride_for_width(cairo_format_t format, int width);
//#cairo_surface_t *cairo_image_surface_create(cairo_format_t format, int width, int height);
//#const char *cairo_status_to_string(cairo_status_t status);
//#void cairo_debug_reset_static_data(void);

// cairo.test()
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(test)
{
#if 0
	const char *driverName = "WINSPOOL\0";
	const char *printerName = "";
	char printerNameDefault[MAX_PATH];
	BYTE printerInfoBuff[16384];
	PRINTER_INFO_2 *pPrinterInfo2 = reinterpret_cast<PRINTER_INFO_2 *>(printerInfoBuff);
	if (::strcmp(printerName, "") == 0) {
		DWORD cch;
		if (!::GetDefaultPrinter(printerNameDefault, &cch)) {
			sig.SetError(ERR_IOError, "failed to get a default printer");
			return Value::Null;
		}
		printerName = printerNameDefault;
	}
	do {
		HANDLE hPrinter;
		if (!::OpenPrinter(const_cast<char *>(printerName), &hPrinter, NULL)) {
			sig.SetError(ERR_IOError, "failed to open printer handler");
			return Value::Null;
		}
		DWORD cbNeeded;
		if (!::GetPrinter(hPrinter, 2, printerInfoBuff, sizeof(printerInfoBuff), &cbNeeded)) {
			sig.SetError(ERR_IOError, "failed to get printer information");
			return Value::Null;
		}
		::ClosePrinter(hPrinter);
	} while (0);
	double width = 100 * 20, height = 100 * 20;
	RECT rc;
	rc.left = 0, rc.top = 0;
	rc.right = static_cast<long>(width * 20);	// unit: 1/20pt
	rc.bottom = static_cast<long>(height * 20);	// unit: 1/20pt
	HDC hdc = ::CreateDC(driverName, printerName, pPrinterInfo2->pPortName, NULL);
	::SetMapMode(hdc, MM_TWIPS);				// 1 unit = 1/20pt
	//::SetMapMode(hdc, MM_HIMETRIC);			// 1 unit = 0.01mm
	cairo_surface_t *surface = ::cairo_win32_printing_surface_create(hdc);
	cairo_t *cr = ::cairo_create(surface);
	
	
	
	::cairo_show_page(cr);
	::DeleteDC(hdc);
	::cairo_destroy(cr);
#endif
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(ascent);
	Gura_RealizeUserSymbol(descent);
	Gura_RealizeUserSymbol(height);
	Gura_RealizeUserSymbol(image);
	Gura_RealizeUserSymbol(max_x_advance);
	Gura_RealizeUserSymbol(max_y_advance);
	Gura_RealizeUserSymbol(stream);
	Gura_RealizeUserSymbol(surface);
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(width);
	Gura_RealizeUserSymbol(x_advance);
	Gura_RealizeUserSymbol(x_bearing);
	Gura_RealizeUserSymbol(y_advance);
	Gura_RealizeUserSymbol(y_bearing);
	// class realization
	Gura_RealizeUserClass(font_extents,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(text_extents,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(rectangle,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(rectangle_int,	env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(font_face,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(scaled_font,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(font_options,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(device,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(surface,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(image_surface,	Gura_UserClass(surface));
	Gura_RealizeUserClass(pdf_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(ps_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(recording_surface,Gura_UserClass(surface));
	Gura_RealizeUserClass(win32_surface,	Gura_UserClass(surface));
	Gura_RealizeUserClass(svg_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(quartz_surface,	Gura_UserClass(surface));
	Gura_RealizeUserClass(xcb_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(xlib_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(script_surface,	Gura_UserClass(surface));
	Gura_RealizeUserClass(pattern,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(region,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(path,				env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(glyph,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(text_cluster,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(context,			env.LookupClass(VTYPE_object));
	// method assignment to image type
	Gura_AssignMethodTo(VTYPE_image, image, cairo);
	// function assignment
	Gura_AssignFunction(image_create);
	Gura_AssignFunction(pdf_create);
	Gura_AssignFunction(ps_create);
	Gura_AssignFunction(svg_create);
#if defined(HAVE_WINDOWS_H)
	Gura_AssignFunction(emf_create);
	Gura_AssignFunction(printer_create);
#endif
	Gura_AssignFunction(pattern_create_rgb);
	Gura_AssignFunction(pattern_create_rgba);
	Gura_AssignFunction(pattern_create_color);
	Gura_AssignFunction(pattern_create_for_surface);
	Gura_AssignFunction(pattern_create_linear);
	Gura_AssignFunction(pattern_create_radial);
	Gura_AssignFunction(test);
	// cairo_path_data_type_t
	Gura_AssignCairoValue(PATH_MOVE_TO);
	Gura_AssignCairoValue(PATH_LINE_TO);
	Gura_AssignCairoValue(PATH_CURVE_TO);
	Gura_AssignCairoValue(PATH_CLOSE_PATH);
	// cairo_antialias_t
	Gura_AssignCairoValue(ANTIALIAS_DEFAULT);
	Gura_AssignCairoValue(ANTIALIAS_NONE);
	Gura_AssignCairoValue(ANTIALIAS_GRAY);
	Gura_AssignCairoValue(ANTIALIAS_SUBPIXEL);
	// cairo_fill_rule_t
	Gura_AssignCairoValue(FILL_RULE_WINDING);
	Gura_AssignCairoValue(FILL_RULE_EVEN_ODD);
	// cairo_line_cap_t
	Gura_AssignCairoValue(LINE_CAP_BUTT);
	Gura_AssignCairoValue(LINE_CAP_ROUND);
	Gura_AssignCairoValue(LINE_CAP_SQUARE);
	// cairo_line_join_t
	Gura_AssignCairoValue(LINE_JOIN_MITER);
	Gura_AssignCairoValue(LINE_JOIN_ROUND);
	Gura_AssignCairoValue(LINE_JOIN_BEVEL);
	// cairo_font_slant_t
	Gura_AssignCairoValue(FONT_SLANT_NORMAL);
	Gura_AssignCairoValue(FONT_SLANT_ITALIC);
	Gura_AssignCairoValue(FONT_SLANT_OBLIQUE);
	// cairo_font_weight_t
	Gura_AssignCairoValue(FONT_WEIGHT_NORMAL);
	Gura_AssignCairoValue(FONT_WEIGHT_BOLD);
	// cairo_font_type_t
	Gura_AssignCairoValue(FONT_TYPE_TOY);
	Gura_AssignCairoValue(FONT_TYPE_FT);
	Gura_AssignCairoValue(FONT_TYPE_WIN32);
	Gura_AssignCairoValue(FONT_TYPE_QUARTZ);
	Gura_AssignCairoValue(FONT_TYPE_USER);
	// cairo_operator_t
	Gura_AssignCairoValue(OPERATOR_CLEAR);
	Gura_AssignCairoValue(OPERATOR_SOURCE);
	Gura_AssignCairoValue(OPERATOR_OVER);
	Gura_AssignCairoValue(OPERATOR_IN);
	Gura_AssignCairoValue(OPERATOR_OUT);
	Gura_AssignCairoValue(OPERATOR_ATOP);
	Gura_AssignCairoValue(OPERATOR_DEST);
	Gura_AssignCairoValue(OPERATOR_DEST_OVER);
	Gura_AssignCairoValue(OPERATOR_DEST_IN);
	Gura_AssignCairoValue(OPERATOR_DEST_OUT);
	Gura_AssignCairoValue(OPERATOR_DEST_ATOP);
	Gura_AssignCairoValue(OPERATOR_XOR);
	Gura_AssignCairoValue(OPERATOR_ADD);
	Gura_AssignCairoValue(OPERATOR_SATURATE);
	Gura_AssignCairoValue(OPERATOR_MULTIPLY);
	Gura_AssignCairoValue(OPERATOR_SCREEN);
	Gura_AssignCairoValue(OPERATOR_OVERLAY);
	Gura_AssignCairoValue(OPERATOR_DARKEN);
	Gura_AssignCairoValue(OPERATOR_LIGHTEN);
	Gura_AssignCairoValue(OPERATOR_COLOR_DODGE);
	Gura_AssignCairoValue(OPERATOR_COLOR_BURN);
	Gura_AssignCairoValue(OPERATOR_HARD_LIGHT);
	Gura_AssignCairoValue(OPERATOR_SOFT_LIGHT);
	Gura_AssignCairoValue(OPERATOR_DIFFERENCE);
	Gura_AssignCairoValue(OPERATOR_EXCLUSION);
	Gura_AssignCairoValue(OPERATOR_HSL_HUE);
	Gura_AssignCairoValue(OPERATOR_HSL_SATURATION);
	Gura_AssignCairoValue(OPERATOR_HSL_COLOR);
	Gura_AssignCairoValue(OPERATOR_HSL_LUMINOSITY);
	// cairo_region_overlap_t
	Gura_AssignCairoValue(REGION_OVERLAP_IN);
	Gura_AssignCairoValue(REGION_OVERLAP_OUT);
	Gura_AssignCairoValue(REGION_OVERLAP_PART);
	// cairo_extend_t
	Gura_AssignCairoValue(EXTEND_NONE);
	Gura_AssignCairoValue(EXTEND_REPEAT);
	Gura_AssignCairoValue(EXTEND_REFLECT);
	Gura_AssignCairoValue(EXTEND_PAD);
	// cairo_filter_t
	Gura_AssignCairoValue(FILTER_FAST);
	Gura_AssignCairoValue(FILTER_GOOD);
	Gura_AssignCairoValue(FILTER_BEST);
	Gura_AssignCairoValue(FILTER_NEAREST);
	Gura_AssignCairoValue(FILTER_BILINEAR);
	Gura_AssignCairoValue(FILTER_GAUSSIAN);
	// cairo_content_t
	Gura_AssignCairoValue(CONTENT_COLOR);
	Gura_AssignCairoValue(CONTENT_ALPHA);
	Gura_AssignCairoValue(CONTENT_COLOR_ALPHA);
	// cairo_subpixel_order_t
	Gura_AssignCairoValue(SUBPIXEL_ORDER_DEFAULT);
	Gura_AssignCairoValue(SUBPIXEL_ORDER_RGB);
	Gura_AssignCairoValue(SUBPIXEL_ORDER_BGR);
	Gura_AssignCairoValue(SUBPIXEL_ORDER_VRGB);
	Gura_AssignCairoValue(SUBPIXEL_ORDER_VBGR);
	// cairo_hint_style_t
	Gura_AssignCairoValue(HINT_STYLE_DEFAULT);
	Gura_AssignCairoValue(HINT_STYLE_NONE);
	Gura_AssignCairoValue(HINT_STYLE_SLIGHT);
	Gura_AssignCairoValue(HINT_STYLE_MEDIUM);
	Gura_AssignCairoValue(HINT_STYLE_FULL);
	// cairo_hint_metrics_t
	Gura_AssignCairoValue(HINT_METRICS_DEFAULT);
	Gura_AssignCairoValue(HINT_METRICS_OFF);
	Gura_AssignCairoValue(HINT_METRICS_ON);
	// cairo_surface_type_t
	Gura_AssignCairoValue(SURFACE_TYPE_IMAGE);
	Gura_AssignCairoValue(SURFACE_TYPE_PDF);
	Gura_AssignCairoValue(SURFACE_TYPE_PS);
	Gura_AssignCairoValue(SURFACE_TYPE_XLIB);
	Gura_AssignCairoValue(SURFACE_TYPE_XCB);
	Gura_AssignCairoValue(SURFACE_TYPE_GLITZ);
	Gura_AssignCairoValue(SURFACE_TYPE_QUARTZ);
	Gura_AssignCairoValue(SURFACE_TYPE_WIN32);
	Gura_AssignCairoValue(SURFACE_TYPE_BEOS);
	Gura_AssignCairoValue(SURFACE_TYPE_DIRECTFB);
	Gura_AssignCairoValue(SURFACE_TYPE_SVG);
	Gura_AssignCairoValue(SURFACE_TYPE_OS2);
	Gura_AssignCairoValue(SURFACE_TYPE_WIN32_PRINTING);
	Gura_AssignCairoValue(SURFACE_TYPE_QUARTZ_IMAGE);
	Gura_AssignCairoValue(SURFACE_TYPE_SCRIPT);
	Gura_AssignCairoValue(SURFACE_TYPE_QT);
	Gura_AssignCairoValue(SURFACE_TYPE_RECORDING);
	Gura_AssignCairoValue(SURFACE_TYPE_VG);
	Gura_AssignCairoValue(SURFACE_TYPE_GL);
	Gura_AssignCairoValue(SURFACE_TYPE_DRM);
	Gura_AssignCairoValue(SURFACE_TYPE_TEE);
	Gura_AssignCairoValue(SURFACE_TYPE_XML);
	Gura_AssignCairoValue(SURFACE_TYPE_SKIA);
	Gura_AssignCairoValue(SURFACE_TYPE_SUBSURFACE);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Writer implementation
//-----------------------------------------------------------------------------
Writer::~Writer()
{
}

//-----------------------------------------------------------------------------
// Writer_Stream implementation
//-----------------------------------------------------------------------------
Writer_Stream::~Writer_Stream()
{
	//_pStream->Close();
}

cairo_status_t Writer_Stream::WriteFunc(const unsigned char *data, unsigned int length)
{
	_pStream->Write(_sig, data, length);
	if (_sig.IsSignalled()) return CAIRO_STATUS_WRITE_ERROR;
	return CAIRO_STATUS_SUCCESS;
}

cairo_status_t Writer_Stream::write_func(void *closure,
						const unsigned char *data, unsigned int length)
{
	Writer_Stream *pWriter = reinterpret_cast<Writer_Stream *>(closure);
	return pWriter->WriteFunc(data, length);
}

Stream *Writer_Stream::GetStream()
{
	return _pStream.get();
}

#if defined(HAVE_WINDOWS_H)
//-----------------------------------------------------------------------------
// Writer_EnhMetaFile implementation
//-----------------------------------------------------------------------------
Writer_EnhMetaFile::~Writer_EnhMetaFile()
{
	::EndPage(_hdc);
	HENHMETAFILE hEmf = ::CloseEnhMetaFile(_hdc);
	::DeleteEnhMetaFile(hEmf);
}

Stream *Writer_EnhMetaFile::GetStream()
{
	return NULL;
}

//-----------------------------------------------------------------------------
// Writer_WindowsDC implementation
//-----------------------------------------------------------------------------
Writer_WindowsDC::~Writer_WindowsDC()
{
	::DeleteDC(_hdc);
}

Stream *Writer_WindowsDC::GetStream()
{
	return NULL;
}
#endif

//-----------------------------------------------------------------------------
// Error handling
//-----------------------------------------------------------------------------
bool IsInvalid(Signal sig, cairo_t *cr)
{
	if (cr == NULL) {
		sig.SetError(ERR_ValueError, "invalid context");
		return true;
	}
	return false;
}

bool IsError(Signal sig, cairo_status_t status)
{
	if (status == CAIRO_STATUS_SUCCESS) return false;
	sig.SetError(ERR_RuntimeError, "%s", ::cairo_status_to_string(status));
	return true;
}

bool IsError(Signal sig, cairo_t *cr)
{
	return IsError(sig, ::cairo_status(cr));
}

bool IsError(Signal sig, cairo_pattern_t *pattern)
{
	return IsError(sig, ::cairo_pattern_status(pattern));
}

bool IsError(Signal sig, cairo_region_t *region)
{
	return IsError(sig, ::cairo_region_status(region));
}

bool IsError(Signal sig, cairo_font_face_t *font_face)
{
	return IsError(sig, ::cairo_font_face_status(font_face));
}

bool IsError(Signal sig, cairo_scaled_font_t *scaled_font)
{
	return IsError(sig, ::cairo_scaled_font_status(scaled_font));
}

bool IsError(Signal sig, cairo_device_t *device)
{
	return IsError(sig, ::cairo_device_status(device));
}

bool IsError(Signal sig, cairo_surface_t *surface)
{
	return IsError(sig, ::cairo_surface_status(surface));
}

bool IsError(Signal sig, cairo_font_options_t *options)
{
	return IsError(sig, ::cairo_font_options_status(options));
}

const char *SurfaceTypeToName(cairo_surface_type_t surface_type)
{
	struct Info {
		cairo_surface_type_t surface_type;
		const char *name;
	};
	static const Info infoTbl[] = {
		{ CAIRO_SURFACE_TYPE_IMAGE,			"image"			},
		{ CAIRO_SURFACE_TYPE_PDF,			"pdf"			},
		{ CAIRO_SURFACE_TYPE_PS,			"ps"			},
		{ CAIRO_SURFACE_TYPE_XLIB,			"xlib"			},
		{ CAIRO_SURFACE_TYPE_XCB,			"xcb"			},
		{ CAIRO_SURFACE_TYPE_GLITZ,			"glitz"			},
		{ CAIRO_SURFACE_TYPE_QUARTZ,		"quartz"		},
		{ CAIRO_SURFACE_TYPE_WIN32,			"win32"			},
		{ CAIRO_SURFACE_TYPE_BEOS,			"beos"			},
		{ CAIRO_SURFACE_TYPE_DIRECTFB,		"directfb"		},
		{ CAIRO_SURFACE_TYPE_SVG,			"svg"			},
		{ CAIRO_SURFACE_TYPE_OS2,			"os2"			},
		{ CAIRO_SURFACE_TYPE_WIN32_PRINTING,"win32_printing"},
		{ CAIRO_SURFACE_TYPE_QUARTZ_IMAGE,	"quartz_image"	},
		{ CAIRO_SURFACE_TYPE_SCRIPT,		"script"		},
		{ CAIRO_SURFACE_TYPE_QT,			"qt"			},
		{ CAIRO_SURFACE_TYPE_RECORDING,		"recording"		},
		{ CAIRO_SURFACE_TYPE_VG,			"vg"			},
		{ CAIRO_SURFACE_TYPE_GL,			"gl"			},
		{ CAIRO_SURFACE_TYPE_DRM,			"drm"			},
		{ CAIRO_SURFACE_TYPE_TEE,			"tee"			},
		{ CAIRO_SURFACE_TYPE_XML,			"xml"			},
		{ CAIRO_SURFACE_TYPE_SKIA		,	"skia"			},
		{ CAIRO_SURFACE_TYPE_SUBSURFACE,	"subsurface"	},
	};
	for (size_t i = 0; i < NUMBEROF(infoTbl); i++) {
		if (infoTbl[i].surface_type == surface_type) return infoTbl[i].name;
	}
	return "(unknown)";
}

//-----------------------------------------------------------------------------
// Value converter
//-----------------------------------------------------------------------------
Value RectangleToValue(Environment &env, const cairo_rectangle_t &rectangle)
{
	Value value;
	ValueList &valList = value.InitAsList(env);
	valList.reserve(4);
	valList.push_back(Value(rectangle.x));
	valList.push_back(Value(rectangle.y));
	valList.push_back(Value(rectangle.width));
	valList.push_back(Value(rectangle.height));
	valList.push_back(value);
	return value;
}

bool ValueListToRectangle(Signal sig, cairo_rectangle_t &rectangle, const ValueList &valList)
{
	if (valList.size() != 4) {
		sig.SetError(ERR_ValueError, "list must have four elements");
		return false;
	}
	rectangle.x = valList[0].GetDouble();
	rectangle.y = valList[1].GetDouble();
	rectangle.width = valList[2].GetDouble();
	rectangle.height = valList[3].GetDouble();
	return true;
}

bool ValueListToRectangle(Signal sig, cairo_rectangle_int_t &rectangle, const ValueList &valList)
{
	if (valList.size() != 4) {
		sig.SetError(ERR_ValueError, "list must have four elements");
		return false;
	}
	rectangle.x = valList[0].GetInt();
	rectangle.y = valList[1].GetInt();
	rectangle.width = valList[2].GetInt();
	rectangle.height = valList[3].GetInt();
	return true;
}

Object_matrix *CairoToMatrix(Environment &env, cairo_matrix_t &matrix)
{
	Object_matrix *pObjMatrix = new Object_matrix(env, 3, 3);
	pObjMatrix->SetElement(0, 0, Value(matrix.xx));
	pObjMatrix->SetElement(0, 1, Value(matrix.xy));
	pObjMatrix->SetElement(1, 0, Value(matrix.yx));
	pObjMatrix->SetElement(1, 1, Value(matrix.yy));
	pObjMatrix->SetElement(0, 2, Value(matrix.x0));
	pObjMatrix->SetElement(1, 2, Value(matrix.y0));
	pObjMatrix->SetElement(2, 2, Value(1.));
	return pObjMatrix;
}

bool MatrixToCairo(Signal sig, cairo_matrix_t &matrix, Object_matrix *pObjMatrix)
{
	if (pObjMatrix->GetRows() != 3 || pObjMatrix->GetCols() != 3) {
		sig.SetError(ERR_ValueError, "matrix size must be 3x3");
		return false;
	}
	matrix.xx = pObjMatrix->GetElement(0, 0).GetDouble();
	matrix.xy = pObjMatrix->GetElement(0, 1).GetDouble();
	matrix.yx = pObjMatrix->GetElement(1, 0).GetDouble();
	matrix.yy = pObjMatrix->GetElement(1, 1).GetDouble();
	matrix.x0 = pObjMatrix->GetElement(0, 2).GetDouble();
	matrix.y0 = pObjMatrix->GetElement(1, 2).GetDouble();
	return true;
}

Value CreateValueList(Environment &env, double x1, double x2)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(2);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	return result;
}

Value CreateValueList(Environment &env, double x1, double x2, double x3)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(3);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	valList.push_back(Value(x3));
	return result;
}

Value CreateValueList(Environment &env, double x1, double x2, double x3, double x4)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(4);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	valList.push_back(Value(x3));
	valList.push_back(Value(x4));
	return result;
}

Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(5);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	valList.push_back(Value(x3));
	valList.push_back(Value(x4));
	valList.push_back(Value(x5));
	return result;
}

Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5, double x6)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(6);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	valList.push_back(Value(x3));
	valList.push_back(Value(x4));
	valList.push_back(Value(x5));
	valList.push_back(Value(x6));
	return result;
}

cairo_surface_t *CreateSurfaceFromImage(Signal sig, Object_image *pObjImage)
{
	if (!pObjImage->CheckValid(sig)) return NULL;
	if (pObjImage->GetFormat() != Image::FORMAT_RGBA) {
		sig.SetError(ERR_FormatError, "cairo can be applied to image in `rgba format");
		return NULL;
	}
	size_t width = pObjImage->GetWidth();
	size_t height = pObjImage->GetHeight();
	cairo_surface_t *surface = ::cairo_image_surface_create_for_data(
				pObjImage->GetBuffer(), CAIRO_FORMAT_ARGB32,
				static_cast<int>(width), static_cast<int>(height),
				static_cast<int>(pObjImage->GetBytesPerLine()));
	return surface;
}

Gura_EndModule(cairo, cairo)

Gura_RegisterModule(cairo)

//#void cairo_matrix_init(cairo_matrix_t *matrix, double xx, double yx, double xy, double yy, double x0, double y0);
//#void cairo_matrix_init_identity(cairo_matrix_t *matrix);
//#void cairo_matrix_init_translate(cairo_matrix_t *matrix, double tx, double ty);
//#void cairo_matrix_init_scale(cairo_matrix_t *matrix, double sx, double sy);
//#void cairo_matrix_init_rotate(cairo_matrix_t *matrix, double radians);
//#void cairo_matrix_translate(cairo_matrix_t *matrix, double tx, double ty);
//#void cairo_matrix_scale(cairo_matrix_t *matrix, double sx, double sy);
//#void cairo_matrix_rotate(cairo_matrix_t *matrix, double radians);
//#cairo_status_t cairo_matrix_invert(cairo_matrix_t *matrix);
//#void cairo_matrix_multiply(cairo_matrix_t *result, const cairo_matrix_t *a, const cairo_matrix_t *b);
//#void cairo_matrix_transform_distance(const cairo_matrix_t *matrix, double *dx, double *dy);
//#void cairo_matrix_transform_point(const cairo_matrix_t *matrix, double *x, double *y);
