#ifndef __FREETYPE_CLASS_BDF_PROPERTY_H__
#define __FREETYPE_CLASS_BDF_PROPERTY_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_BDF_Property declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(BDF_Property);

class Object_BDF_Property : public Object {
public:
	Gura_DeclareObjectAccessor(BDF_Property)
private:
	BDF_Property _property;
public:
	inline Object_BDF_Property(const BDF_Property &property) :
			Object(Gura_UserClass(BDF_Property)), _property(property) {}
	inline Object_BDF_Property(const Object_BDF_Property &obj) :
			Object(obj), _property(obj._property) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline BDF_Property &GetEntity() { return _property; }
	inline const BDF_Property &GetEntity() const { return _property; }
};

Gura_EndModuleScope(freetype)

#endif
