//=============================================================================
// Gura module: glut
//=============================================================================
#ifndef __GURA_MODULE_GLUT_H__
#define __GURA_MODULE_GLUT_H__
#include <gura.h>
#if defined(GURA_ON_DARWIN)
#include <glut/glut.h>
#else
#include <GL/glut.h>
#endif

Gura_BeginModuleHeader(glut)

//-----------------------------------------------------------------------------
// functions
//-----------------------------------------------------------------------------
void SetError_NotImpFunction(Signal &sig, const char *funcName);
void AssignValues(Environment &env);
void AssignFunctions(Environment &env);

//-----------------------------------------------------------------------------
// Object_Font
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Font);

class Object_Font : public Object {
public:
	Gura_DeclareObjectAccessor(Font)
private:
	void *_font;
public:
	inline Object_Font(void *font) : Object(Gura_UserClass(Font)), _font(font) {}
	inline Object_Font(const Object_Font &obj) : Object(obj), _font(obj._font) {}
	virtual ~Object_Font();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void *GetEntity() { return _font; }
};

Gura_EndModuleHeader(glut)

#endif
