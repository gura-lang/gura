#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_region implementation
//-----------------------------------------------------------------------------
Object_region::~Object_region()
{
	::cairo_region_destroy(_region);
}

Object *Object_region::Clone() const
{
	return nullptr;
}

String Object_region::ToString(bool exprFlag)
{
	return String("<cairo.region>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for region
//-----------------------------------------------------------------------------
// cairo.region.create() {block?}
Gura_DeclareClassMethod(region, create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(region, create)
{
	Signal &sig = env.GetSignal();
	cairo_region_t *region = ::cairo_region_create();
	if (Is_error(sig, region)) {
		::cairo_region_destroy(region);
		return Value::Nil;
	}
	return ReturnValue(env, args, Value(new Object_region(region)));
}

// cairo.region.create_rectangle(rectangle:cairo.rectangle_int) {block?}
Gura_DeclareClassMethod(region, create_rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(region, create_rectangle)
{
	Signal &sig = env.GetSignal();
	cairo_rectangle_int_t rectangle =
				Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_region_t *region = ::cairo_region_create_rectangle(&rectangle);
	if (Is_error(sig, region)) {
		::cairo_region_destroy(region);
		return Value::Nil;
	}
	return ReturnValue(env, args, Value(new Object_region(region)));
}

// cairo.region.create_rectangles(rectangle[]:cairo.rectangle_int) {block?}
Gura_DeclareClassMethod(region, create_rectangles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rects", VTYPE_rectangle_int, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(region, create_rectangles)
{
	Signal &sig = env.GetSignal();
	const ValueList &valList = args.GetList(0);
	int count = static_cast<int>(valList.size());
	cairo_rectangle_int_t *rects = new cairo_rectangle_int_t[count];
	size_t i = 0;
	foreach_const (ValueList, pValue, valList) {
		rects[i++] = Object_rectangle_int::GetObject(*pValue)->GetEntity();
	}
	cairo_region_t *region = ::cairo_region_create_rectangles(rects, count);
	delete[] rects;
	if (Is_error(sig, region)) {
		::cairo_region_destroy(region);
		return Value::Nil;
	}
	return ReturnValue(env, args, Value(new Object_region(region)));
}

// cairo.region#copy() {block?}
Gura_DeclareMethod(region, copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(region, copy)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *original = pThis->GetEntity();
	cairo_region_t *region = ::cairo_region_copy(original);
	if (Is_error(sig, region)) {
		::cairo_region_destroy(region);
		return Value::Nil;
	}
	return ReturnValue(env, args, Value(new Object_region(region)));
}

//#cairo_region_t *cairo_region_reference(cairo_region_t *region);
//#void cairo_region_destroy(cairo_region_t *region);

// cairo.region#status()
Gura_DeclareMethod(region, status)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(region, status)
{
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_status_t rtn = ::cairo_region_status(region);
	return Value(rtn);
}

// cairo.region#get_extents()
Gura_DeclareMethod(region, get_extents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(region, get_extents)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_rectangle_int_t extents;
	::cairo_region_get_extents(region, &extents);
	if (Is_error(sig, region)) return Value::Nil;
	return Value(new Object_rectangle_int(extents));
}

// cairo.region#num_rectangles()
Gura_DeclareMethod(region, num_rectangles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(region, num_rectangles)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	int rtn = ::cairo_region_num_rectangles(region);
	if (Is_error(sig, region)) return Value::Nil;
	return Value(rtn);
}

// cairo.region#get_rectangle(nth:number)
Gura_DeclareMethod(region, get_rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "nth", VTYPE_number);
}

Gura_ImplementMethod(region, get_rectangle)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	int nth = args.GetInt(0);
	cairo_rectangle_int_t rectangle;
	::cairo_region_get_rectangle(region, nth, &rectangle);
	if (Is_error(sig, region)) return Value::Nil;
	return Value(new Object_rectangle_int(rectangle));
}

// cairo.region#is_empty()
Gura_DeclareMethod(region, is_empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(region, is_empty)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	bool rtn = ::cairo_region_is_empty(region)? true : false;
	if (Is_error(sig, region)) return Value::Nil;
	return Value(rtn);
}

// cairo.region#contains_point(x:number, y:number)
Gura_DeclareMethod(region, contains_point)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(region, contains_point)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	bool rtn = ::cairo_region_contains_point(region, args.GetInt(0), args.GetInt(1))? true : false;
	if (Is_error(sig, region)) return Value::Nil;
	return Value(rtn);
}

// cairo.region#contains_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, contains_rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, contains_rectangle)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_region_overlap_t region_overlap =
					::cairo_region_contains_rectangle(region, &rectangle);
	if (Is_error(sig, region)) return Value::Nil;
	return Value(region_overlap);
}

// cairo.region#equal(region:cairo.region)
Gura_DeclareMethod(region, equal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "region", VTYPE_region);
}

Gura_ImplementMethod(region, equal)
{
	Signal &sig = env.GetSignal();
	cairo_region_t *a = Object_region::GetThisObj(args)->GetEntity();
	cairo_region_t *b = Object_region::GetObject(args, 0)->GetEntity();
	bool rtn = ::cairo_region_equal(a, b)? true : false;
	if (Is_error(sig, a)) return Value::Nil;
	return Value(rtn);
}

// cairo.region#translate(dx:number, dy:number)
Gura_DeclareMethod(region, translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dx", VTYPE_number);
	DeclareArg(env, "dy", VTYPE_number);
}

Gura_ImplementMethod(region, translate)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	::cairo_region_translate(region, args.GetInt(0), args.GetInt(1));
	if (Is_error(sig, region)) return Value::Nil;
	return Value::Nil;
}

// cairo.region#intersect(other:cairo.region)
Gura_DeclareMethod(region, intersect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_region);
}

Gura_ImplementMethod(region, intersect)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (Is_error(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	cairo_region_t *other = Object_region::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_intersect(dst, other);
	if (Is_error(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#intersect_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, intersect_rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, intersect_rectangle)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (Is_error(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_intersect_rectangle(dst, &rectangle);
	if (Is_error(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#subtract(other:cairo.region)
Gura_DeclareMethod(region, subtract)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_region);
}

Gura_ImplementMethod(region, subtract)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (Is_error(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	cairo_region_t *other = Object_region::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_subtract(dst, other);
	if (Is_error(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#subtract_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, subtract_rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, subtract_rectangle)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (Is_error(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_subtract_rectangle(dst, &rectangle);
	if (Is_error(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#union(other:cairo.region)
Gura_DeclareMethodAlias(region, union_, "union")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_region);
}

Gura_ImplementMethod(region, union_)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (Is_error(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	cairo_region_t *other = Object_region::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_union(dst, other);
	if (Is_error(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#union_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, union_rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, union_rectangle)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (Is_error(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_union_rectangle(dst, &rectangle);
	if (Is_error(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#xor(other:cairo.region)
Gura_DeclareMethodAlias(region, xor_, "xor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "other", VTYPE_region);
}

Gura_ImplementMethod(region, xor_)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (Is_error(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	cairo_region_t *other = Object_region::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_xor(dst, other);
	if (Is_error(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// cairo.region#xor_rectangle(rectangle:cairo.rectangle_int)
Gura_DeclareMethod(region, xor_rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rectangle", VTYPE_rectangle_int);
}

Gura_ImplementMethod(region, xor_rectangle)
{
	Signal &sig = env.GetSignal();
	Object_region *pThis = Object_region::GetThisObj(args);
	cairo_region_t *region = pThis->GetEntity();
	cairo_region_t *dst = ::cairo_region_copy(region);
	if (Is_error(sig, dst)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	cairo_rectangle_int_t &rectangle =
					Object_rectangle_int::GetObject(args, 0)->GetEntity();
	cairo_status_t status = ::cairo_region_xor_rectangle(dst, &rectangle);
	if (Is_error(sig, status)) {
		::cairo_region_destroy(dst);
		return Value::Nil;
	}
	Object_region *pObjRegion = new Object_region(dst);
	return Value(pObjRegion);
}

// implementation of class region
Gura_ImplementUserClass(region)
{
	Gura_AssignMethod(region, create);
	Gura_AssignMethod(region, create_rectangle);
	Gura_AssignMethod(region, create_rectangles);
	Gura_AssignMethod(region, copy);
	Gura_AssignMethod(region, status);
	Gura_AssignMethod(region, get_extents);
	Gura_AssignMethod(region, num_rectangles);
	Gura_AssignMethod(region, get_rectangle);
	Gura_AssignMethod(region, is_empty);
	Gura_AssignMethod(region, contains_point);
	Gura_AssignMethod(region, contains_rectangle);
	Gura_AssignMethod(region, equal);
	Gura_AssignMethod(region, translate);
	Gura_AssignMethod(region, intersect);
	Gura_AssignMethod(region, intersect_rectangle);
	Gura_AssignMethod(region, subtract);
	Gura_AssignMethod(region, subtract_rectangle);
	Gura_AssignMethod(region, union_);
	Gura_AssignMethod(region, union_rectangle);
	Gura_AssignMethod(region, xor_);
	Gura_AssignMethod(region, xor_rectangle);
}

Gura_EndModuleScope(cairo)
