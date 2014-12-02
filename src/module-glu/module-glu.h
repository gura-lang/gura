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

#if defined(GURA_ON_MSWIN)
#else
#define __stdcall
#endif

Gura_BeginModuleHeader(glu)

typedef void (__stdcall *CallbackType)();

class Object_Tesselator;

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
GLenum GetImageFormat(Signal sig, Image *pImage);
void SetError_NotImpFunction(Signal &sig, const char *funcName);

//-----------------------------------------------------------------------------
// VertexPack
//-----------------------------------------------------------------------------
class VertexPack {
private:
	Object_Tesselator *_pObjTess;
	Value _vertexData;
public:
	inline VertexPack(Object_Tesselator *pObjTess, const Value &vertexData) :
							_pObjTess(pObjTess), _vertexData(vertexData) {}
	inline Value GetVertexData() { return _vertexData; }
};

class VertexPackList : public std::vector<VertexPack *> {
};

class VertexPackOwner : public VertexPackList {
public:
	~VertexPackOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// PolygonPack
//-----------------------------------------------------------------------------
class PolygonPack {
private:
	Object_Tesselator *_pObjTess;
	Value _polygonData;
	VertexPackOwner _vertexPackOwner;
public:
	inline PolygonPack(Object_Tesselator *pObjTess, const Value &polygonData) :
							_pObjTess(pObjTess), _polygonData(polygonData) {}
	inline Value GetPolygonData() { return _polygonData; }
	inline VertexPack *CreateVertexPack(const Value &vertexData) {
		VertexPack *pVertexPack = new VertexPack(_pObjTess, vertexData);
		_vertexPackOwner.push_back(pVertexPack);
		return pVertexPack;
	}
};

//-----------------------------------------------------------------------------
// Object_Quadric
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Quadric);

class Object_Quadric : public Object {
public:
	Gura_DeclareObjectAccessor(Quadric)
private:
	GLUquadric *_quad;
	static AutoPtr<Function> _pFunc_CB_error;
public:
	inline Object_Quadric(GLUquadric *quad) :
			Object(Gura_UserClass(Quadric)), _quad(quad) {}
	virtual ~Object_Quadric();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	static void SetCallback(Signal sig, GLUquadric *quad, GLenum which, const Function *func);
	inline GLUquadric *GetQuadric() { return _quad; }
	inline static void SetFunc_CB_error(Function *pFunc) { _pFunc_CB_error.reset(pFunc); }
private:
	inline Object_Quadric(const Object_Quadric &obj) : Object(obj) {}
public:
	static void CB_error(GLenum errno);
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
	std::auto_ptr<PolygonPack> _pPolygonPack;
	static AutoPtr<Function> _pFunc_CB_begin;
	static AutoPtr<Function> _pFunc_CB_edgeFlag;
	static AutoPtr<Function> _pFunc_CB_vertex;
	static AutoPtr<Function> _pFunc_CB_end;
	static AutoPtr<Function> _pFunc_CB_error;
	static AutoPtr<Function> _pFunc_CB_combine;
	static AutoPtr<Function> _pFunc_CB_beginData;
	static AutoPtr<Function> _pFunc_CB_edgeFlagData;
	static AutoPtr<Function> _pFunc_CB_endData;
	static AutoPtr<Function> _pFunc_CB_vertexData;
	static AutoPtr<Function> _pFunc_CB_errorData;
	static AutoPtr<Function> _pFunc_CB_combineData;
public:
	inline Object_Tesselator(GLUtesselator *tess) :
			Object(Gura_UserClass(Tesselator)), _tess(tess) {}
	virtual ~Object_Tesselator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline GLUtesselator *GetTesselator() { return _tess; }
	inline void CreatePolygonPack(const Value &polygonData) {
		_pPolygonPack.reset(new PolygonPack(this, polygonData));
	}
	inline void DeletePolygonPack() { _pPolygonPack.reset(NULL); }
	inline PolygonPack *GetPolygonPack() { return _pPolygonPack.get(); }
private:
	inline Object_Tesselator(const Object_Tesselator &obj) : Object(obj) {}
public:
	static void CB_begin(GLenum type);
	static void CB_edgeFlag(GLboolean flag);
	static void CB_vertex(void *vertex_data);
	static void CB_end(void);
	static void CB_error(GLenum errno);
	static void CB_combine(GLdouble coords[3], void *vertex_data[4],
						   GLfloat weight[4], void **outData);
	static void CB_beginData(GLenum type, void *polygon_data);
	static void CB_edgeFlagData(GLboolean flag, void *polygon_data);
	static void CB_endData(void *polygon_data);
	static void CB_vertexData(void *vertex_data, void *polygon_data);
	static void CB_errorData(GLenum errno, void *polygon_data);
	static void CB_combineData(GLdouble coords[3], void *vertex_data[4],
							   GLfloat weight[4], void **outDatab, void *polygon_data);
};

//-----------------------------------------------------------------------------
// Object_Nurbs
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Nurbs);

class Object_Nurbs : public Object {
public:
	Gura_DeclareObjectAccessor(Nurbs)
private:
	GLUnurbs *_nurb;
	static AutoPtr<Function> _pFunc_CB_begin;
	static AutoPtr<Function> _pFunc_CB_vertex;
	static AutoPtr<Function> _pFunc_CB_normal;
	static AutoPtr<Function> _pFunc_CB_color;
	static AutoPtr<Function> _pFunc_CB_texCoord;
	static AutoPtr<Function> _pFunc_CB_end;
	static AutoPtr<Function> _pFunc_CB_beginData;
	static AutoPtr<Function> _pFunc_CB_vertexData;
	static AutoPtr<Function> _pFunc_CB_normalData;
	static AutoPtr<Function> _pFunc_CB_colorData;
	static AutoPtr<Function> _pFunc_CB_texCoordData;
	static AutoPtr<Function> _pFunc_CB_endData;
	static AutoPtr<Function> _pFunc_CB_error;
public:
	inline Object_Nurbs(GLUnurbs *nurb) :
				Object(Gura_UserClass(Nurbs)), _nurb(nurb) {}
	virtual ~Object_Nurbs();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline GLUnurbs *GetNurbs() { return _nurb; }
private:
	inline Object_Nurbs(const Object_Nurbs &obj) : Object(obj) {}
public:
	static void CB_begin(GLenum type);
	static void CB_vertex(GLfloat *vertex);
	static void CB_normal(GLfloat *normal);
	static void CB_color(GLfloat *color);
	static void CB_texCoord(GLfloat *tex_coord);
	static void CB_end(void);
	static void CB_beginData(GLenum type, void *userData);
	static void CB_vertexData(GLfloat *vertex, void *userData);
	static void CB_normalData(GLfloat *normal, void *userData);
	static void CB_colorData(GLfloat *color, void *userData);
	static void CB_texCoordData(GLfloat *tex_coord, void *userData);
	static void CB_endData(void *userData);
	static void CB_error(GLenum errno);
};

Gura_EndModuleHeader(glu)

#endif
