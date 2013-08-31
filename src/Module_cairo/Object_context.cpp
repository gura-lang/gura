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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Checks whether an error has previously occurred for this context."
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Decreases the reference count on cr by one.\n"
	"If the result is zero, then cr and all associated resources are freed.\n"
	"See cairo.context#reference()."
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Makes a copy of the current state of cr and saves it on an internal stack of saved states for cr.\n"
	"When cairo.context#restore() is called, cr will be restored to the saved state.\n"
	"Multiple calls to cairo.context#save() and cairo.context#restore() can be nested;\n"
	"each call to cairo.context#restore() restores the state from the matching paired cairo.context#save().\n"
	"\n"
	"It isn't necessary to clear all saved states before a cairo_t is freed.\n"
	"If the reference count of a cairo_t drops to zero in response to a call to cairo.context#destroy(),\n"
	"any saved states will be freed along with the cairo_t.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Restores cr to the state saved by a preceding call to cairo.context#save()\n"
	"and removes that state from the stack of saved states."
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the target surface for the cairo context as passed to cairo.context constructor.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Temporarily redirects drawing to an intermediate surface known as a group.\n"
	"The redirection lasts until the group is completed by a call to cairo.context#pop_group() or cairo.context#pop_group_to_source().\n"
	"These calls provide the result of any drawing to the group as a pattern,\n"
	"(either as an explicit object, or set as the source pattern).\n"
	"\n"
	"This group functionality can be convenient for performing intermediate compositing.\n"
	"One common use of a group is to render objects as opaque within the group,\n"
	"(so that they occlude each other), and then blend the result with translucence onto the destination.\n"
	"\n"
	"Groups can be nested arbitrarily deep by making balanced calls to cairo.context#push_group()/cairo.context#pop_group().\n"
	"Each call pushes/pops the new target group onto/from a stack.\n"
	"\n"
	"The cairo.context#push_group() function calls cairo_save()\n"
	"so that any changes to the graphics state will not be visible outside the group,\n"
	"(the pop_group functions call cairo_restore()).\n"
	"\n"
	"By default the intermediate group will have a content type of cairo.CONTENT_COLOR_ALPHA.\n"
	"Other content types can be chosen for the group by using cairo.context#push_group_with_content() instead.\n"
	"\n"
	"As an example, here is how one might fill and stroke a path with translucence,\n"
	"but without any portion of the fill being visible under the stroke:\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Temporarily redirects drawing to an intermediate surface known as a group.\n"
	"The redirection lasts until the group is completed by a call to cairo.context#pop_group() or cairo.context#pop_group_to_source().\n"
	"These calls provide the result of any drawing to the group as a pattern,\n"
	"(either as an explicit object, or set as the source pattern).\n"
	"\n"
	"The group will have a content type of content.\n"
	"The ability to control this content type is the only distinction between this function and cairo.context#push_group()\n"
	"which you should see for a more detailed description of group rendering.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Terminates the redirection begun by a call to cairo.context#push_group() or cairo.context#push_group_with_content()\n"
	"and returns a new pattern containing the results of all drawing operations performed to the group.\n"
	"\n"
	"The cairo.context#pop_group() function calls cairo_restore(),\n"
	"(balancing a call to cairo_save() by the push_group function),\n"
	"so that any changes to the graphics state will not be visible outside the group.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Terminates the redirection begun by a call to cairo.context#push_group() or cairo.context#push_group_with_content()\n"
	"and installs the resulting pattern as the source pattern in the given cairo context.\n"
	"\n"
	"The cairo.context#pop_group() function calls cairo_restore(),\n"
	"(balancing a call to cairo_save() by the push_group function),\n"
	"so that any changes to the graphics state will not be visible outside the group.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current destination surface for the context.\n"
	"This is either the original target surface as passed to cairo.context constructor\n"
	"or the target surface for the current group as started\n"
	"by the most recent call to cairo.context#push_group() or cairo.context#push_group_with_content().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the source pattern within cr to an opaque color.\n"
	"This opaque color will then be used for any subsequent drawing operation until a new source pattern is set.\n"
	"\n"
	"The color components are floating point numbers in the range 0 to 1.\n"
	"If the values passed in are outside that range, they will be clamped.\n"
	"\n"
	"The default source pattern is opaque black, (that is, it is equivalent to cr.set_source_rgb(0.0, 0.0, 0.0)).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the source pattern within cr to a translucent color.\n"
	"This color will then be used for any subsequent drawing operation until a new source pattern is set.\n"
	"\n"
	"The color and alpha components are floating point numbers in the range 0 to 1.\n"
	"If the values passed in are outside that range, they will be clamped.\n"
	"\n"
	"The default source pattern is opaque black, (that is, it is equivalent to cr.set_source_rgba(0.0, 0.0, 0.0, 1.0)).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the source pattern within cr to source.\n"
	"This pattern will then be used for any subsequent drawing operation until a new source pattern is set.\n"
	"\n"
	"Note: The pattern's transformation matrix will be locked to the user space in effect at the time of cairo.context#set_source().\n"
	"This means that further modifications of the current transformation matrix will not affect the source pattern. See cairo.pattern#set_matrix().\n"
	"\n"
	"The default source pattern is a solid pattern that is opaque black,\n"
	"(that is, it is equivalent to cr.set_source_rgb(0.0, 0.0, 0.0)).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This is a convenience function for creating a pattern from surface\n"
	"and setting it as the source in cr with cairo.context#set_source().\n"
	"\n"
	"The x and y parameters give the user-space coordinate at which the surface origin should appear.\n"
	"(The surface origin is its upper-left corner before any transformation has been applied.)\n"
	"The x and y parameters are negated and then set as translation values in the pattern matrix.\n"
	"\n"
	"Other than the initial translation pattern matrix, as described above,\n"
	"all other pattern attributes, (such as its extend mode), are set to the default values as in cairo.pattern.create_for_surface().\n"
	"The resulting pattern can be queried with cairo.context#get_source() so that these attributes can be modified if desired,\n"
	"(eg. to create a repeating pattern with cairo.pattern#set_extend()).\n"
	);
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
	pThis->SetSurfaceSrcObj(Object_surface::Reference(Object_surface::GetObject(args, 0)));
	return args.GetThis();
}

// cairo.context#get_source()
Gura_DeclareMethod(context, get_source)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current source pattern for cr.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Set the antialiasing mode of the rasterizer used for drawing shapes.\n"
	"This value is a hint, and a particular backend may or may not support a particular value.\n"
	"At the current time, no backend supports cairo.ANTIALIAS_SUBPIXEL when drawing shapes.\n"
	"\n"
	"Note that this option does not affect text rendering, instead see cairo.font_options#set_antialias().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current shape antialiasing mode, as set by cairo.context#set_antialias().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the dash pattern to be used by cairo.context#stroke().\n"
	"A dash pattern is specified by dashes, an array of positive values.\n"
	"Each value provides the length of alternate \"on\" and \"off\" portions of the stroke.\n"
	"The offset specifies an offset into the pattern at which the stroke begins.\n"
	"\n"
	"Each \"on\" segment will have caps applied as if the segment were a separate sub-path.\n"
	"In particular, it is valid to use an \"on\" length of 0.0 with cairo.LINE_CAP_ROUND or cairo.LINE_CAP_SQUARE\n"
	"in order to distributed dots or squares along a path.\n"
	"\n"
	"Note: The length values are in user-space units as evaluated at the time of stroking.\n"
	"This is not necessarily the same as the user space at the time of cairo.context#set_dash().\n"
	"\n"
	"If length of dashes is 0 dashing is disabled.\n"
	"\n"
	"If length of dashes is 1 a symmetric pattern is assumed\n"
	"with alternating on and off portions of the size specified by the single value in dashes.\n"
	"\n"
	"If any value in dashes is negative, or if all values are 0,\n"
	"then cr will be put into an error state with a status of cairo.STATUS_INVALID_DASH.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current dash array."
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Set the current fill rule within the cairo context.\n"
	"The fill rule is used to determine which regions are inside or outside a complex\n"
	"(potentially self-intersecting) path. The current fill rule affects both cairo.context#fill() and cairo.context#clip().\n"
	"See cairo_fill_rule_t for details on the semantics of each available fill rule.\n"
	"\n"
	"The default fill rule is cairo.FILL_RULE_WINDING.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current fill rule, as set by cairo.context#set_fill_rule().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the current line cap style within the cairo context.\n"
	"See cairo_line_cap_t for details about how the available line cap styles are drawn.\n"
	"\n"
	"As with the other stroke parameters, the current line cap style is examined by cairo.context#stroke(), cairo.context#stroke_extents(),\n"
	"and cairo.context#stroke_to_path(), but does not have any effect during path construction.\n"
	"\n"
	"The default line cap style is cairo.LINE_CAP_BUTT.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current line cap style, as set by cairo.context#set_line_cap()."
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the current line join style within the cairo context.\n"
	"See cairo_line_join_t for details about how the available line join styles are drawn.\n"
	"\n"
	"As with the other stroke parameters, the current line join style is examined by cairo.context#stroke(), cairo.context#stroke_extents(),\n"
	"and cairo.context#stroke_to_path(), but does not have any effect during path construction.\n"
	"\n"
	"The default line join style is cairo.LINE_JOIN_MITER.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current line join style, as set by cairo.context#set_line_join().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the current line width within the cairo context.\n"
	"The line width value specifies the diameter of a pen that is circular in user space,\n"
	"(though device-space pen may be an ellipse in general due to scaling/shear/rotation of the CTM).\n"
	"\n"
	"Note: When the description above refers to user space and CTM\n"
	"it refers to the user space and CTM in effect at the time of the stroking operation,\n"
	"not the user space and CTM in effect at the time of the call to cairo.context#set_line_width().\n"
	"The simplest usage makes both of these spaces identical.\n"
	"That is, if there is no change to the CTM between a call to cairo.context#set_line_width() and the stroking operation,\n"
	"then one can just pass user-space values to cairo.context#set_line_width() and ignore this note.\n"
	"\n"
	"As with the other stroke parameters, the current line width is examined by cairo.context#stroke(), cairo.context#stroke_extents(),\n"
	"and cairo.context#stroke_to_path(), but does not have any effect during path construction.\n"
	"\n"
	"The default line width value is 2.0.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This function returns the current line width value exactly as set by cairo.context#set_line_width().\n"
	"Note that the value is unchanged even if the CTM has changed between the calls to cairo.context#set_line_width()\n"
	"and cairo.context#get_line_width().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the current miter limit within the cairo context.\n"
	"\n"
	"If the current line join style is set to cairo.LINE_JOIN_MITER\n"
	"(see cairo_set_line_join()), the miter limit is used to determine whether the lines should be joined with a bevel instead of a miter.\n"
	"Cairo divides the length of the miter by the line width.\n"
	"If the result is greater than the miter limit, the style is converted to a bevel.\n"
	"\n"
	"As with the other stroke parameters, the current line miter limit is examined by cairo.context#stroke(), cairo.context#stroke_extents(),\n"
	"and cairo.context#stroke_to_path(), but does not have any effect during path construction.\n"
	"\n"
	"The default miter limit value is 10.0, which will convert joins with interior angles less than 11 degrees to bevels instead of miters.\n"
	"For reference, a miter limit of 2.0 makes the miter cutoff at 60 degrees, and a miter limit of 1.414 makes the cutoff at 90 degrees.\n"
	"\n"
	"A miter limit for a desired angle can be computed as: miter limit = 1/sin(angle/2)\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current miter limit, as set by cairo.context#set_miter_limit().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the compositing operator to be used for all drawing operations.\n"
	"See cairo_operator_t for details on the semantics of each available compositing operator.\n"
	"\n"
	"The default operator is cairo.OPERATOR_OVER.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current compositing operator for a cairo context.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the tolerance used when converting paths into trapezoids.\n"
	"Curved segments of the path will be subdivided until the maximum deviation\n"
	"between the original path and the polygonal approximation is less than tolerance.\n"
	"The default value is 0.1. A larger value will give better performance,\n"
	"a smaller value, better appearance.\n"
	"(Reducing the value from the default value of 0.1 is unlikely to improve appearance significantly.)\n"
	"The accuracy of paths within Cairo is limited by the precision of its internal arithmetic,\n"
	"and the prescribed tolerance is restricted to the smallest representable internal value.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current tolerance value, as set by cairo.context#set_tolerance()."
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Establishes a new clip region by intersecting the current clip region\n"
	"with the current path as it would be filled by cairo.context#fill()\n"
	"and according to the current fill rule (see cairo.context#set_fill_rule()).\n"
	"\n"
	"After cairo.context#clip(), the current path will be cleared from the cairo context.\n"
	"\n"
	"The current clip region affects all drawing operations\n"
	"by effectively masking out any changes to the surface that are outside the current clip region.\n"
	"\n"
	"Calling cairo.context#clip() can only make the clip region smaller, never larger.\n"
	"But the current clip is part of the graphics state,\n"
	"so a temporary restriction of the clip region can be achieved by calling cairo.context#clip()\n"
	"within a cairo.context#save()/cairo.context#restore() pair.\n"
	"The only other means of increasing the size of the clip region is cairo.context#reset_clip().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Establishes a new clip region by intersecting the current clip region\n"
	"with the current path as it would be filled by cairo.context#fill()\n"
	"and according to the current fill rule (see cairo.context#set_fill_rule())."
	"\n"
	"Unlike cairo.context#clip(), cairo.context#clip_preserve() preserves the path within the cairo context.\n"
	"\n"
	"The current clip region affects all drawing operations\n"
	"by effectively masking out any changes to the surface that are outside the current clip region.\n"
	"\n"
	"Calling cairo.context#clip_preserve() can only make the clip region smaller, never larger.\n"
	"But the current clip is part of the graphics state,\n"
	"so a temporary restriction of the clip region can be achieved by calling cairo.context#clip_preserve()\n"
	"within a cairo.context#save()/cairo.context#restore() pair.\n"
	"The only other means of increasing the size of the clip region is cairo.context#reset_clip().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Computes a bounding box in user coordinates covering the area inside the current clip.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Tests whether the given point is inside the area that would be visible through the current clip,\n"
	"i.e. the area that would be filled by a cairo.context#paint() operation.\n"
	"\n"
	"See cairo.context#clip(), and cairo.context#clip_preserve().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Reset the current clip region to its original, unrestricted state.\n"
	"That is, set the clip region to an infinitely large shape containing the target surface.\n"
	"Equivalently, if infinity is too hard to grasp,\n"
	"one can imagine the clip region being reset to the exact bounds of the target surface.\n"
	"\n"
	"Note that code meant to be reusable should not call cairo_reset_clip()\n"
	"as it will cause results unexpected by higher-level code which calls cairo.context#clip().\n"
	"Consider using cairo.context#save() and cairo.context#restore() around cairo.context#clip()\n"
	"as a more robust means of temporarily restricting the clip region.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current clip region as a list of rectangles in user coordinates.\n"
	"\n"
	"The status in the list may be cairo.STATUS_CLIP_NOT_REPRESENTABLE\n"
	"to indicate that the clip region cannot be represented as a list of user-space rectangles.\n"
	"The status may have other values to indicate other errors.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that fills the current path according to the current fill rule,\n"
	"(each sub-path is implicitly closed before being filled).\n"
	"After cairo.context#fill(), the current path will be cleared from the cairo context.\n"
	"See cairo.context#set_fill_rule() and cairo.context#fill_preserve().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that fills the current path according to the current fill rule,\n"
	"(each sub-path is implicitly closed before being filled).\n"
	"Unlike cairo.context#fill(), cairo.context#fill_preserve() preserves the path within the cairo context.\n"
	"\n"
	"See cairo.context#set_fill_rule() and cairo.context#fill().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Computes a bounding box in user coordinates covering the area that\n"
	"would be affected, (the \"inked\" area), by a cairo.context#fill() operation given the current path and fill parameters.\n"
	"If the current path is empty, returns an empty rectangle ((0,0), (0,0)).\n"
	"Surface dimensions and clipping are not taken into account.\n"
	"\n"
	"Contrast with cairo.context#path_extents(), which is similar,\n"
	"but returns non-zero extents for some paths with no inked area, (such as a simple line segment).\n"
	"\n"
	"Note that cairo.context#fill_extents() must necessarily do more work to compute the precise inked areas in light of the fill rule,\n"
	"so cairo.context#path_extents() may be more desirable for sake of performance if the non-inked path extents are desired.\n"
	"\n"
	"See cairo.context#fill(), cairo.context#set_fill_rule() and cairo.context#fill_preserve().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Tests whether the given point is inside the area that would be affected by a cairo.context#fill() operation given the current path and filling parameters.\n"
	"Surface dimensions and clipping are not taken into account.\n"
	"\n"
	"See cairo.context#fill(), cairo.context#set_fill_rule() and cairo.context#fill_preserve().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that paints the current source using the alpha channel of pattern as a mask.\n"
	"(Opaque areas of pattern are painted with the source, transparent areas are not painted.)\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that paints the current source using the alpha channel of surface as a mask.\n"
	"(Opaque areas of surface are painted with the source, transparent areas are not painted.)\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that paints the current source everywhere within the current clip region.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that paints the current source everywhere within the current clip region using a mask of constant alpha value alpha.\n"
	"The effect is similar to cairo.context#paint(), but the drawing is faded out using the alpha value.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that strokes the current path according to the current line width, line join, line cap, and dash settings.\n"
	"After cairo.context#stroke(), the current path will be cleared from the cairo context.\n"
	"See cairo.context#set_line_width(), cairo.context#set_line_join(), cairo.context#set_line_cap(), cairo.context#set_dash(), and cairo.context#stroke_preserve().\n"
	"\n"
	"Note: Degenerate segments and sub-paths are treated specially and provide a useful result.\n"
	"These can result in two different situations:\n"
	"\n"
	"1. Zero-length \"on\" segments set in cairo.context#set_dash().\n"
	"If the cap style is cairo.LINE_CAP_ROUND or cairo.LINE_CAP_SQUARE then these segments will be drawn as circular dots or squares respectively.\n"
	"In the case of cairo.LINE_CAP_SQUARE, the orientation of the squares is determined by the direction of the underlying path.\n"
	"\n"
	"2. A sub-path created by cairo.context#move_to() followed by either a cairo.context#close_path() or one or more calls to cairo.context#line_to() to the same coordinate as the cairo.context#move_to().\n"
	"If the cap style is cairo.LINE_CAP_ROUND then these sub-paths will be drawn as circular dots.\n"
	"Note that in the case of cairo.LINE_CAP_SQUARE a degenerate sub-path will not be drawn at all, (since the correct orientation is indeterminate).\n"
	"\n"
	"In no case will a cap style of cairo.LINE_CAP_BUTT cause anything to be drawn in the case of either degenerate segments or sub-paths.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that strokes the current path according to the current line width, line join, line cap, and dash settings.\n"
	"Unlike cairo.context#stroke(), cairo.context#stroke_preserve() preserves the path within the cairo context.\n"
	"\n"
	"See cairo.context#set_line_width(), cairo.context#set_line_join(), cairo.context#set_line_cap(), cairo.context#set_dash(), and cairo.context#stroke_preserve().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Computes a bounding box in user coordinates covering the area that would be affected,\n"
	"(the \"inked\" area), by a cairo.context#stroke() operation given the current path and stroke parameters.\n"
	"If the current path is empty, returns an empty rectangle ((0,0), (0,0)).\n"
	"Surface dimensions and clipping are not taken into account.\n"
	"\n"
	"Note that if the line width is set to exactly zero, then cairo.context#stroke_extents() will return an empty rectangle.\n"
	"Contrast with cairo.context#path_extents() which can be used to compute the non-empty bounds as the line width approaches zero.\n"
	"\n"
	"Note that cairo.context#stroke_extents() must necessarily do more work to compute the precise inked areas in light of the stroke parameters,\n"
	"so cairo.context#path_extents() may be more desirable for sake of performance if non-inked path extents are desired.\n"
	"\n"
	"See cairo.context#stroke(), cairo.context#set_line_width(), cairo.context#set_line_join(), cairo.context#set_line_cap(), cairo.context#set_dash(), and cairo.context#stroke_preserve().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Tests whether the given point is inside the area that would be affected by a cairo.context#stroke() operation given the current path and stroking parameters.\n"
	"Surface dimensions and clipping are not taken into account.\n"
	"See cairo.context#stroke(), cairo.context#set_line_width(), cairo.context#set_line_join(), cairo.context#set_line_cap(), cairo.context#_set_dash(), and cairo.context#stroke_preserve().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Emits the current page for backends that support multiple pages, but doesn't clear it,\n"
	"so, the contents of the current page will be retained for the next page too.\n"
	"Use cairo.cairo#show_page() if you want to get an empty page after the emission.\n"
	"\n"
	"This is a convenience function that simply calls cairo.context#surface_copy_page() on cr's target.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Emits and clears the current page for backends that support multiple pages.\n"
	"Use cairo.context#copy_page() if you don't want to clear the page.\n"
	"\n"
	"This is a convenience function that simply calls cairo.context#surface_show_page() on cr's target.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates a copy of the current path and returns it to the user as a cairo.path.\n"
	"See cairo_path_data_t for hints on how to iterate over the returned data structure.\n"
	"\n"
	"The result will have no data (data==NULL and num_data==0), if either of the following conditions hold:\n"
	"\n"
	"1. If there is insufficient memory to copy the path. In this case path->status will be set to cairo.STATUS_NO_MEMORY.\n"
	"\n"
	"2. If cr is already in an error state. In this case path->status will contain the same status that would be returned by cairo.context#status().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets a flattened copy of the current path and returns it to the user as a cairo.path.\n"
	"See cairo_path_data_t for hints on how to iterate over the returned data structure.\n"
	"\n"
	"This function is like cairo.context#copy_path() except that any curves in the path will be approximated with piecewise-linear approximations,\n"
	"(accurate to within the current tolerance value).\n"
	"That is, the result is guaranteed to not have any elements of type cairo.PATH_CURVE_TO which will instead be replaced by a series of cairo.PATH_LINE_TO elements.\n"
	"\n"
	"The result will have no data (data==NULL and num_data==0), if either of the following conditions hold:\n"
	"\n"
	"1. If there is insufficient memory to copy the path. In this case path->status will be set to cairo.STATUS_NO_MEMORY.\n"
	"\n"
	"2. If cr is already in an error state. In this case path->status will contain the same status that would be returned by cairo.context#status().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Append the path onto the current path. The path may be either the return value from one of cairo.context#copy_path() or cairo.context#copy_path_flat() or it may be constructed manually.\n"
	"See cairo_path_t for details on how the path data structure should be initialized, and note that path->status must be initialized to cairo.STATUS_SUCCESS.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns whether a current point is defined on the current path.\n"
	"See cairo.context#get_current_point() for details on the current point.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current point of the current path, which is conceptually the final point reached by the path so far.\n"
	"\n"
	"The current point is returned in the user-space coordinate system.\n"
	"If there is no defined current point or if cr is in an error status, x and y will both be set to 0.0.\n"
	"It is possible to check this in advance with cairo.context#has_current_point().\n"
	"\n"
	"Most path construction functions alter the current point.\n"
	"See the following for details on how they affect the current point:\n"
	"cairo.context#new_path(), cairo.context#new_sub_path(), cairo.context#append_path(),\n"
	"cairo.context#close_path(), cairo.context#move_to(), cairo.context#line_to(), cairo.context#curve_to(),\n"
	"cairo.context#rel_move_to(), cairo.context#rel_line_to(), cairo.context#rel_curve_to(),\n"
	"cairo.context#arc(), cairo.context#arc_negative(), cairo.context#rectangle(), cairo.context#text_path(),\n"
	"cairo.context#glyph_path(), cairo.context#stroke_to_path().\n"
	"\n"
	"Some functions use and alter the current point but do not otherwise change current path: cairo.context#show_text().\n"
	"\n"
	"Some functions unset the current path and as a result, current point: cairo.context#fill(), cairo.context#stroke().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Clears the current path. After this call there will be no path and no current point.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Begin a new sub-path. Note that the existing path is not affected. After this call there will be no current point.\n"
	"\n"
	"In many cases, this call is not needed since new sub-paths are frequently started with cairo.context#move_to().\n"
	"\n"
	"A call to cairo.context#new_sub_path() is particularly useful when beginning a new sub-path with one of the cairo.context#arc() calls.\n"
	"This makes things easier as it is no longer necessary to manually compute the arc's initial coordinates for a call to cairo.context#move_to().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds a line segment to the path from the current point to the beginning of the current sub-path,\n"
	"(the most recent point passed to cairo.context#move_to()), and closes this sub-path.\n"
	"After this call the current point will be at the joined endpoint of the sub-path.\n"
	"\n"
	"The behavior of cairo.context#close_path() is distinct from simply calling cairo.context#line_to() with the equivalent coordinate in the case of stroking.\n"
	"When a closed sub-path is stroked, there are no caps on the ends of the sub-path.\n"
	"Instead, there is a line join connecting the final and initial segments of the sub-path.\n"
	"\n"
	"If there is no current point before the call to cairo.context#close_path(), this function will have no effect.\n"
	"\n"
	"Note: As of cairo version 1.2.4 any call to cairo.context#close_path() will place an explicit MOVE_TO element into the path immediately after the CLOSE_PATH element,\n"
	"(which can be seen in cairo.context#copy_path() for example).\n"
	"This can simplify path processing in some cases as it may not be necessary to save the \"last move_to point\" during processing as the MOVE_TO immediately after the CLOSE_PATH will provide that point.\n"
	);
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
//                   angle1?:number, angle2?:number):map:reduce:[deg]
Gura_DeclareMethod(context, arc)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "xc", VTYPE_number);
	DeclareArg(env, "yc", VTYPE_number);
	DeclareArg(env, "radius", VTYPE_number);
	DeclareArg(env, "angle1", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "angle2", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds a circular arc of the given radius to the current path.\n"
	"The arc is centered at (xc, yc), begins at angle1 and proceeds in the direction of increasing angles to end at angle2.\n"
	"If angle2 is less than angle1 it will be progressively increased by 2*M_PI until it is greater than angle1.\n"
	"\n"
	"If there is a current point, an initial line segment will be added to the path to connect the current point to the beginning of the arc.\n"
	"If this initial line is undesired, it can be avoided by calling cairo.context#new_sub_path() before calling cairo.context#arc().\n"
	"\n"
	"Angles are measured in radians. An angle of 0.0 is in the direction of the positive X axis (in user space).\n"
	"An angle of math.pi/2.0 radians (90 degrees) is in the direction of the positive Y axis (in user space).\n"
	"Angles increase in the direction from the positive X axis toward the positive Y axis.\n"
	"So with the default transformation matrix, angles increase in a clockwise direction.\n"
	"\n"
	"(To convert from degrees to radians, use degrees * (math.pi / 180.).)\n"
	"\n"
	"This function gives the arc in the direction of increasing angles; see cairo.context#arc_negative() to get the arc in the direction of decreasing angles.\n"
	"\n"
	"The arc is circular in user space. To achieve an elliptical arc, you can scale the current transformation matrix by different amounts in the X and Y directions.\n"
	"For example, to draw an ellipse in the box given by x, y, width, height:\n"
	"\n"
	"  cr.save()\n"
	"  cr.translate(x + width / 2., y + height / 2.)\n"
	"  cr.scale(width / 2., height / 2.)\n"
	"  cr.arc(0., 0., 1., 0., 2 * math.pi)\n"
	"  cr.restore()\n"
	"\n"
	"*Gura:* If attribute :deg is specified, angle1 and angle2 are represented in degrees instead of radians.\n"
	);
}

Gura_ImplementMethod(context, arc)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double angle1 = 0;
	double angle2 = 2 * Math_PI;
	if (args.IsSet(Gura_Symbol(deg))) {
		if (args.IsNumber(3)) angle1 = DegToRad(args.GetDouble(3));
		if (args.IsNumber(4)) angle2 = DegToRad(args.GetDouble(4));
	} else {
		if (args.IsNumber(3)) angle1 = args.GetDouble(3);
		if (args.IsNumber(4)) angle2 = args.GetDouble(4);
	}
	::cairo_arc(cr, args.GetDouble(0), args.GetDouble(1),
										args.GetDouble(2), angle1, angle2);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#arc_negative(xc:number, yc:number, radius:number,
//                            angle1?:number, angle2?:number):map:reduce:[deg]
Gura_DeclareMethod(context, arc_negative)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "xc", VTYPE_number);
	DeclareArg(env, "yc", VTYPE_number);
	DeclareArg(env, "radius", VTYPE_number);
	DeclareArg(env, "angle1", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "angle2", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds a circular arc of the given radius to the current path.\n"
	"The arc is centered at (xc, yc), begins at angle1 and proceeds in the direction of decreasing angles to end at angle2.\n"
	"If angle2 is greater than angle1 it will be progressively decreased by 2*math.pi until it is less than angle1.\n"
	"\n"
	"See cairo.context#arc() for more details. This function differs only in the direction of the arc between the two angles.\n"
	"\n"
	"*Gura:* If attribute :deg is specified, angle1 and angle2 are represented in degrees instead of radians.\n"
	);
}

Gura_ImplementMethod(context, arc_negative)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double angle1 = 0;
	double angle2 = 2 * Math_PI;
	if (args.IsSet(Gura_Symbol(deg))) {
		if (args.IsNumber(3)) angle1 = DegToRad(args.GetDouble(3));
		if (args.IsNumber(4)) angle2 = DegToRad(args.GetDouble(4));
	} else {
		if (args.IsNumber(3)) angle1 = args.GetDouble(3);
		if (args.IsNumber(4)) angle2 = args.GetDouble(4);
	}
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds a cubic Bezier spline to the path from the current point to position (x3, y3) in user-space coordinates,\n"
	"using (x1, y1) and (x2, y2) as the control points.\n"
	"After this call the current point will be (x3, y3).\n"
	"\n"
	"If there is no current point before the call to cairo.context#curve_to() this function will behave as if preceded by a call to cr.move_to(x1, y1).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds a line to the path from the current point to position (x, y) in user-space coordinates.\n"
	"After this call the current point will be (x, y).\n"
	"\n"
	"If there is no current point before the call to cairo.context#line_to() this function will behave as cr.move_to(x, y).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Begin a new sub-path. After this call the current point will be (x, y).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds a closed sub-path rectangle of the given size to the current path at position (x, y) in user-space coordinates.\n"
	"\n"
	"This function is logically equivalent to:\n"
	"\n"
	"  cr.move_to(x, y)\n"
	"  cr.rel_line_to(width, 0)\n"
	"  cr.rel_line_to(0, height)\n"
	"  cr.rel_line_to(-width, 0)\n"
	"  cr.close_path()\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds closed paths for the glyphs to the current path.\n"
	"The generated path if filled, achieves an effect similar to that of cairo.context#show_glyphs().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds closed paths for text to the current path.\n"
	"The generated path if filled, achieves an effect similar to that of cairo.context#show_text().\n"
	"\n"
	"Text conversion and positioning is done similar to cairo.context#show_text().\n"
	"\n"
	"Like cairo.context#show_text(), After this call the current point is moved to the origin of where the next glyph would be placed in this same progression.\n"
	"That is, the current point will be at the origin of the final glyph offset by its advance values.\n"
	"This allows for chaining multiple calls to to cairo.context#text_path() without having to set current point in between.\n"
	"\n"
	"Note: The cairo.context#text_path() function call is part of what the cairo designers call the \"toy\" text API.\n"
	"It is convenient for short demos and simple programs, but it is not expected to be adequate for serious text-using applications.\n"
	"See cairo.context#glyph_path() for the \"real\" text path API in cairo.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Relative-coordinate version of cairo.context#curve_to().\n"
	"All offsets are relative to the current point.\n"
	"Adds a cubic Bezier spline to the path from the current point to a point offset from the current point by (dx3, dy3),\n"
	"using points offset by (dx1, dy1) and (dx2, dy2) as the control points.\n"
	"After this call the current point will be offset by (dx3, dy3).\n"
	"\n"
	"Given a current point of (x, y), cr.rel_curve_to(dx1, dy1, dx2, dy2, dx3, dy3) is logically equivalent to cr.curve_to(x+dx1, y+dy1, x+dx2, y+dy2, x+dx3, y+dy3).\n"
	"\n"
	"It is an error to call this function with no current point.\n"
	"Doing so will cause cr to shutdown with a status of cairo.STATUS_NO_CURRENT_POINT.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Relative-coordinate version of cairo.context#line_to().\n"
	"Adds a line to the path from the current point to a point that is offset from the current point by (dx, dy) in user space.\n"
	"After this call the current point will be offset by (dx, dy).\n"
	"\n"
	"Given a current point of (x, y), cr.rel_line_to(dx, dy) is logically equivalent to cr.line_to(x + dx, y + dy).\n"
	"\n"
	"It is an error to call this function with no current point.\n"
	"Doing so will cause cr to shutdown with a status of cairo.STATUS_NO_CURRENT_POINT.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Begin a new sub-path. After this call the current point will offset by (dx, dy).\n"
	"\n"
	"Given a current point of (x, y), cr.rel_move_to(dx, dy) is logically equivalent to cr.move_to(x + dx, y + dy).\n"
	"\n"
	"It is an error to call this function with no current point.\n"
	"Doing so will cause cr to shutdown with a status of cairo.STATUS_NO_CURRENT_POINT.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Computes a bounding box in user-space coordinates covering the points on the current path.\n"
	"If the current path is empty, returns an empty rectangle ((0,0), (0,0)).\n"
	"Stroke parameters, fill rule, surface dimensions and clipping are not taken into account.\n"
	"\n"
	"Contrast with cairo.context#fill_extents() and cairo.context#stroke_extents()\n"
	"which return the extents of only the area that would be \"inked\" by the corresponding drawing operations.\n"
	"\n"
	"The result of cairo.context#path_extents() is defined as equivalent to the limit of cairo.context#stroke_extents() with cairo.LINE_CAP_ROUND as the line width approaches 0.0,\n"
	"(but never reaching the empty-rectangle returned by cairo.context#stroke_extents() for a line width of 0.0).\n"
	"\n"
	"Specifically, this means that zero-area sub-paths such as cairo.context#move_to();cairo.context#line_to() segments,\n"
	"(even degenerate cases where the coordinates to both calls are identical), will be considered as contributing to the extents.\n"
	"However, a lone cairo.context#move_to() will not contribute to the results of cairo.context#path_extents().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Modifies the current transformation matrix (CTM) by translating the user-space origin by (tx, ty).\n"
	"This offset is interpreted as a user-space coordinate according to the CTM in place before the new call to cairo.context#translate().\n"
	"In other words, the translation of the user-space origin takes place after any existing transformation.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Modifies the current transformation matrix (CTM) by scaling the X and Y user-space axes by sx and sy respectively.\n"
	"The scaling of the axes takes place after any existing transformation of user space.\n"
	);
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

// cairo.context#rotate(angle:number):reduce:[deg]
Gura_DeclareMethod(context, rotate)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Modifies the current transformation matrix (CTM) by rotating the user-space axes by angle radians.\n"
	"The rotation of the axes takes places after any existing transformation of user space.\n"
	"The rotation direction for positive angles is from the positive X axis toward the positive Y axis.\n"
	"\n"
	"*Gura:* If attribute :deg is specified, angle is represented in degrees instead of radians.\n"
	);
}

Gura_ImplementMethod(context, rotate)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	double angle = args.GetDouble(0);
	if (args.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	::cairo_rotate(cr, angle);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#transform(matrix:matrix):reduce
Gura_DeclareMethod(context, transform)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_matrix);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Modifies the current transformation matrix (CTM) by applying matrix as an additional transformation.\n"
	"The new transformation of user space takes place after any existing transformation.\n"
	);
}

Gura_ImplementMethod(context, transform)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	Object_matrix *pObjMatrix = Object_matrix::GetObject(args, 0);
	cairo_matrix_t matrix;
	if (!MatrixToCairo(sig, matrix, pObjMatrix->GetMatrix())) return Value::Null;
	::cairo_transform(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#set_matrix(matrix:matrix):reduce
Gura_DeclareMethod(context, set_matrix)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_matrix);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Modifies the current transformation matrix (CTM) by setting it equal to matrix.\n"
	);
}

Gura_ImplementMethod(context, set_matrix)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	Object_matrix *pObjMatrix = Object_matrix::GetObject(args, 0);
	cairo_matrix_t matrix;
	if (!MatrixToCairo(sig, matrix, pObjMatrix->GetMatrix())) return Value::Null;
	::cairo_set_matrix(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_matrix()
Gura_DeclareMethod(context, get_matrix)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Stores the current transformation matrix (CTM) into matrix.\n"
	);
}

Gura_ImplementMethod(context, get_matrix)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_matrix_t matrix;
	::cairo_get_matrix(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	AutoPtr<Matrix> pMat(CairoToMatrix(matrix));
	//return Value(new Object_matrix(env, pMat.release()));
	return Value::Null;
}

// cairo.context#identity_matrix():reduce
Gura_DeclareMethod(context, identity_matrix)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Resets the current transformation matrix (CTM) by setting it equal to the identity matrix.\n"
	"That is, the user-space and device-space axes will be aligned and one user-space unit will transform to one device-space unit.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Transform a coordinate from user space to device space by multiplying the given point by the current transformation matrix (CTM).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Transform a distance vector from user space to device space.\n"
	"This function is similar to cairo.context#user_to_device()\n"
	"except that the translation components of the CTM will be ignored when transforming (dx,dy).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Transform a coordinate from device space to user space by multiplying the given point by the inverse of the current transformation matrix (CTM).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Transform a distance vector from device space to user space.\n"
	"This function is similar to cairo.context#device_to_user()\n"
	"except that the translation components of the inverse CTM will be ignored when transforming (dx,dy).\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Note: The cairo.context#select_font_face() function call is part of what the cairo designers call the \"toy\" text API.\n"
	"It is convenient for short demos and simple programs, but it is not expected to be adequate for serious text-using applications.\n"
	"\n"
	"Selects a family and style of font from a simplified description as a family name, slant and weight.\n"
	"Cairo provides no operation to list available family names on the system (this is a \"toy\", remember),\n"
	"but the standard CSS2 generic family names, (\"serif\", \"sans-serif\", \"cursive\", \"fantasy\", \"monospace\"), are likely to work as expected.\n"
	"\n"
	"If family starts with the string \"cairo:\", or if no native font backends are compiled in, cairo will use an internal font family.\n"
	"The internal font family recognizes many modifiers in the family string, most notably, it recognizes the string \"monospace\".\n"
	"That is, the family name \"cairo:monospace\" will use the monospace version of the internal font family.\n"
	"\n"
	"For \"real\" font selection, see the font-backend-specific font_face_create functions for the font backend you are using.\n"
	"(For example, if you are using the freetype-based cairo-ft font backend, see cairo_ft_font_face_create_for_ft_face() or cairo_ft_font_face_create_for_pattern().)\n"
	"The resulting font face could then be used with cairo.scaled_font_create() and cairo.context#set_scaled_font().\n"
	"\n"
	"Similarly, when using the \"real\" font support, you can call directly into the underlying font system,\n"
	"(such as fontconfig or freetype), for operations such as listing available fonts, etc.\n"
	"\n"
	"It is expected that most applications will need to use a more comprehensive font handling and text layout library,\n"
	"(for example, pango), in conjunction with cairo.\n"
	"\n"
	"If text is drawn without a call to cairo.context#select_font_face(), (nor cairo.context#set_font_face() nor cairo.context#set_scaled_font()),\n"
	"the default family is platform-specific, but is essentially \"sans-serif\".\n"
	"Default slant is cairo.FONT_SLANT_NORMAL, and default weight is cairo.FONT_WEIGHT_NORMAL.\n"
	"\n"
	"This function is equivalent to a call to cairo.toy_font_face.create() followed by cairo.context#set_font_face().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the current font matrix to a scale by a factor of size, replacing any font matrix previously set with cairo.context#set_font_size() or cairo.context#set_font_matrix().\n"
	"This results in a font size of size user space units. (More precisely, this matrix will result in the font's em-square being a size by size square in user space.)\n"
	"\n"
	"If text is drawn without a call to cairo.context#set_font_size(), (nor cairo.context#set_font_matrix() nor cairo.context#set_scaled_font()), the default font size is 10.0.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the current font matrix to matrix.\n"
	"The font matrix gives a transformation from the design space of the font (in this space, the em-square is 1 unit by 1 unit) to user space.\n"
	"Normally, a simple scale is used (see cairo_set_font_size()), but a more complex font matrix can be used to shear the font or stretch it unequally along the two axes.\n"
	);
}

Gura_ImplementMethod(context, set_font_matrix)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	Object_matrix *pObjMatrix = Object_matrix::GetObject(args, 0);
	cairo_matrix_t matrix;
	if (!MatrixToCairo(sig, matrix, pObjMatrix->GetMatrix())) return Value::Null;
	::cairo_set_font_matrix(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	return args.GetThis();
}

// cairo.context#get_font_matrix()
Gura_DeclareMethod(context, get_font_matrix)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Stores the current font matrix into matrix. See cairo.context#set_font_matrix().\n"
	);
}

Gura_ImplementMethod(context, get_font_matrix)
{
	Object_context *pThis = Object_context::GetThisObj(args);
	cairo_t *cr = pThis->GetEntity();
	if (IsInvalid(sig, cr)) return Value::Null;
	cairo_matrix_t matrix;
	::cairo_get_font_matrix(cr, &matrix);
	if (IsError(sig, cr)) return Value::Null;
	AutoPtr<Matrix> pMat(CairoToMatrix(matrix));
	return Value(new Object_matrix(env, pMat.release()));
}

// cairo.context#set_font_options(options:cairo.font_options):reduce
Gura_DeclareMethod(context, set_font_options)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "options", VTYPE_font_options);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets a set of custom font rendering options for the cairo_t.\n"
	"Rendering options are derived by merging these options with the options derived from underlying surface;\n"
	"if the value in options has a default value (like cairo.ANTIALIAS_DEFAULT), then the value from the surface is used.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Retrieves font rendering options set via cairo.context#set_font_options.\n"
	"Note that the returned options do not include any options derived from the underlying surface;\n"
	"they are literally the options passed to cairo.context#set_font_options().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Replaces the current cairo_font_face_t object in the cairo_t with font_face.\n"
	"The replaced font face in the cairo_t will be destroyed if there are no other references to it.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current font face for a cairo_t.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Replaces the current font face, font matrix, and font options in the cairo_t with those of the cairo_scaled_font_t.\n"
	"Except for some translation, the current CTM of the cairo_t should be the same as that of the cairo_scaled_font_t,\n"
	"which can be accessed using cairo.context#scaled_font_get_ctm().\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current scaled font for a cairo_t.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that generates the shape from a string of UTF-8 characters,\n"
	"rendered according to the current font_face, font_size (font_matrix), and font_options.\n"
	"\n"
	"This function first computes a set of glyphs for the string of text.\n"
	"The first glyph is placed so that its origin is at the current point.\n"
	"The origin of each subsequent glyph is offset from that of the previous glyph by the advance values of the previous glyph.\n"
	"\n"
	"After this call the current point is moved to the origin of where the next glyph would be placed in this same progression.\n"
	"That is, the current point will be at the origin of the final glyph offset by its advance values.\n"
	"This allows for easy display of a single logical string with multiple calls to cairo.context#show_text().\n"
	"\n"
	"Note: The cairo.context#show_text() function call is part of what the cairo designers call the \"toy\" text API.\n"
	"It is convenient for short demos and simple programs, but it is not expected to be adequate for serious text-using applications.\n"
	"See cairo.context#show_glyphs() for the \"real\" text display API in cairo.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"A drawing operator that generates the shape from an array of glyphs,\n"
	"rendered according to the current font face, font size (font matrix), and font options.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This operation has rendering effects similar to cairo_show_glyphs() but, if the target surface supports it,\n"
	"uses the provided text and cluster mapping to embed the text for the glyphs shown in the output.\n"
	"If the target does not support the extended attributes, this function acts like the basic cairo.context#show_glyphs()\n"
	"as if it had been passed glyphs and num_glyphs.\n"
	"\n"
	"The mapping between utf8 and glyphs is provided by an array of clusters.\n"
	"Each cluster covers a number of text bytes and glyphs, and neighboring clusters cover neighboring areas of utf8 and glyphs.\n"
	"The clusters should collectively cover utf8 and glyphs in entirety.\n"
	"\n"
	"The first cluster always covers bytes from the beginning of utf8.\n"
	"If cluster_flags do not have the cairo.TEXT_CLUSTER_FLAG_BACKWARD set, the first cluster also covers the beginning of glyphs,\n"
	"otherwise it covers the end of the glyphs array and following clusters move backward.\n"
	"\n"
	"See cairo.text_cluster for constraints on valid clusters.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the font extents for the currently selected font.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the extents for a string of text.\n"
	"The extents describe a user-space rectangle that encloses the \"inked\" portion of the text, (as it would be drawn by cairo.context#show_text()).\n"
	"Additionally, the x_advance and y_advance values indicate the amount by which the current point would be advanced by cairo.context#show_text().\n"
	"\n"
	"Note that whitespace characters do not directly contribute to the size of the rectangle (extents.width and extents.height).\n"
	"They do contribute indirectly by changing the position of non-whitespace characters.\n"
	"In particular, trailing whitespace characters are likely to not affect the size of the rectangle,\n"
	"though they will affect the x_advance and y_advance values.\n"
	);
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the extents for an array of glyphs.\n"
	"The extents describe a user-space rectangle that encloses the \"inked\" portion of the glyphs, (as they would be drawn by cairo.context#show_glyphs()).\n"
	"Additionally, the x_advance and y_advance values indicate the amount by which the current point would be advanced by cairo.context#show_glyphs().\n"
	"\n"
	"Note that whitespace glyphs do not contribute to the size of the rectangle (extents.width and extents.height).\n"
	);
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
