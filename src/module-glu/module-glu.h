//-----------------------------------------------------------------------------
// Gura module: glu
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_GLU_H__
#define __GURA_MODULE_GLU_H__
#include <gura.h>
#if defined(GURA_ON_DARWIN)
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

Gura_BeginModuleHeader(glu)

//-----------------------------------------------------------------------------
// Object_Quadric
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Quadric);

class Object_Quadric : public Object {
public:
	Gura_DeclareObjectAccessor(Quadric)
private:
	GLUquadric *_qobj;
	static Function *_pFunc_QuadricErrorProc;
public:
	inline Object_Quadric(GLUquadric *qobj) :
			Object(Gura_UserClass(Quadric)), _qobj(qobj) {}
	inline Object_Quadric(const Object_Quadric &obj) : Object(obj) {}
	virtual ~Object_Quadric();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline GLUquadric *GetQuadric() { return _qobj; }
	inline static Value CreateValue(GLUquadric *qobj) {
		return Value(new Object_Quadric(qobj));
	}
	void SetQuadricErrorProc(Function *pFunc);
	static void Callback_QuadricErrorProc(GLenum err);
};

//-----------------------------------------------------------------------------
// Object_Tesselator
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Tesselator);

class Object_Tesselator : public Object {
public:
	Gura_DeclareObjectAccessor(Tesselator)
private:
	GLUtesselator *_tess;
public:
	inline Object_Tesselator(GLUtesselator *tess) :
			Object(Gura_UserClass(Tesselator)), _tess(tess) {}
	inline Object_Tesselator(const Object_Tesselator &obj) : Object(obj) {}
	virtual ~Object_Tesselator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline GLUtesselator *GetTesselator() { return _tess; }
	inline static Value CreateValue(GLUtesselator *tess) {
		return Value(new Object_Tesselator(tess));
	}
};

//-----------------------------------------------------------------------------
// Object_Nurbs
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Nurbs);

class Object_Nurbs : public Object {
public:
	Gura_DeclareObjectAccessor(Nurbs)
private:
	GLUnurbs *_nobj;
public:
	inline Object_Nurbs(GLUnurbs *nobj) :
			Object(Gura_UserClass(Nurbs)), _nobj(nobj) {}
	inline Object_Nurbs(const Object_Nurbs &obj) : Object(obj) {}
	virtual ~Object_Nurbs();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline GLUnurbs *GetNurbs() { return _nobj; }
	inline static Value CreateValue(GLUnurbs *nobj) {
		return Value(new Object_Nurbs(nobj));
	}
};

Gura_EndModuleHeader(glu)

#endif
