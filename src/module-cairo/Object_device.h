#ifndef __CAIRO_OBJECT_DEVICE_H__
#define __CAIRO_OBJECT_DEVICE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_device declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(device);

class Object_device : public Object {
private:
	cairo_device_t *_device;
public:
	Gura_DeclareObjectAccessor(device)
public:
	inline Object_device(cairo_device_t *device) :
					Object(Gura_UserClass(device)), _device(device) {}
	virtual ~Object_device();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_device_t *GetEntity() { return _device; }
};

Gura_EndModuleScope(cairo)

#endif
