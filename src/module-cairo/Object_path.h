#ifndef __CAIRO_OBJECT_PATH_H__
#define __CAIRO_OBJECT_PATH_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_path declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(path);

class Object_path : public Object {
private:
	cairo_path_t *_path;
public:
	Gura_DeclareObjectAccessor(path)
public:
	inline Object_path(cairo_path_t *path) :
						Object(Gura_UserClass(path)), _path(path) {}
	virtual ~Object_path();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_path_t *GetEntity() { return _path; }
};

Gura_EndModuleScope(cairo)

#endif
