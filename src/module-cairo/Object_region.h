#ifndef __CAIRO_OBJECT_REGION_H__
#define __CAIRO_OBJECT_REGION_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_region declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(region);

class Object_region : public Object {
private:
	cairo_region_t *_region;
public:
	Gura_DeclareObjectAccessor(region)
public:
	inline Object_region(cairo_region_t *region) :
						Object(Gura_UserClass(region)), _region(region) {}
	virtual ~Object_region();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_region_t *GetEntity() { return _region; }
};

}}

#endif
