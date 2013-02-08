#include "stdafx.h"

Gura_BeginModule(cairo)

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

}}
