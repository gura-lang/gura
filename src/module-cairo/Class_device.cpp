#include "stdafx.h"

Gura_BeginModuleScope(cairo)

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

String Object_device::ToString(bool exprFlag)
{
	return String("<cairo.device>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for device
//-----------------------------------------------------------------------------
//#cairo_device_t *cairo_device_reference(cairo_device_t *device);
//#void cairo_device_destroy(cairo_device_t *device);

// cairo.device#status()
Gura_DeclareMethod(device, status)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(device, status)
{
	Object_device *pThis = Object_device::GetThisObj(args);
	cairo_device_t *device = pThis->GetEntity();
	cairo_status_t rtn = ::cairo_device_status(device);
	return Value(rtn);
}

// cairo.device#finish():reduce
Gura_DeclareMethod(device, finish)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(device, finish)
{
	Object_device *pThis = Object_device::GetThisObj(args);
	cairo_device_t *device = pThis->GetEntity();
	::cairo_device_finish(device);
	return args.GetThis();
}

// cairo.device#flush():reduce
Gura_DeclareMethod(device, flush)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(device, flush)
{
	Object_device *pThis = Object_device::GetThisObj(args);
	cairo_device_t *device = pThis->GetEntity();
	::cairo_device_flush(device);
	return args.GetThis();
}

// cairo.device#get_type()
Gura_DeclareMethod(device, get_type)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(device, get_type)
{
	Object_device *pThis = Object_device::GetThisObj(args);
	cairo_device_t *device = pThis->GetEntity();
	cairo_device_type_t rtn = ::cairo_device_get_type(device);
	return Value(rtn);
}

//#unsigned int cairo_device_get_reference_count(cairo_device_t *device);
//#cairo_status_t cairo_device_set_user_data(cairo_device_t *device, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_device_get_user_data(cairo_device_t *device, const cairo_user_data_key_t *key);

// cairo.device#acquire()
Gura_DeclareMethod(device, acquire)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(device, acquire)
{
	Object_device *pThis = Object_device::GetThisObj(args);
	cairo_device_t *device = pThis->GetEntity();
	cairo_status_t status = ::cairo_device_acquire(device);
	return Value(status);
}

// cairo.device#release():void
Gura_DeclareMethod(device, release)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(device, release)
{
	Object_device *pThis = Object_device::GetThisObj(args);
	cairo_device_t *device = pThis->GetEntity();
	::cairo_device_release(device);
	return Value::Null;
}

// implementation of class device
Gura_ImplementUserClass(device)
{
	Gura_AssignMethod(device, status);
	Gura_AssignMethod(device, finish);
	Gura_AssignMethod(device, flush);
	Gura_AssignMethod(device, get_type);
	Gura_AssignMethod(device, acquire);
	Gura_AssignMethod(device, release);
}

Gura_EndModuleScope(cairo)
