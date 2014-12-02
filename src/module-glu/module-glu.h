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

extern Signal g_sig;

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
	static int _cnt_CB_error;
	static CallbackType _tbl_CB_error[];
	static Function *_pFuncs_CB_error[];
public:
	inline Object_Quadric(GLUquadric *quad) :
			Object(Gura_UserClass(Quadric)), _quad(quad) {}
	virtual ~Object_Quadric();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	static void SetCallback(Signal sig, GLUquadric *quad, GLenum which, const Function *func);
	inline GLUquadric *GetQuadric() { return _quad; }
private:
	inline Object_Quadric(const Object_Quadric &obj) : Object(obj) {}
public:
	template<int idx> static void CB_errorX(GLenum errno) {
		const Function *pFunc = _pFuncs_CB_error[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->AddValue(Value(static_cast<int>(errno)));
		pFunc->Eval(env, g_sig, *pArgs);
	}
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
	/*
	static CallbackType _tbl_CB_begin[];
	static CallbackType _tbl_CB_edge_flag[];
	static CallbackType _tbl_CB_vertex[];
	static CallbackType _tbl_CB_end[];
	static CallbackType _tbl_CB_error[];
	static CallbackType _tbl_CB_combine[];
	static CallbackType _tbl_CB_begin_data[];
	static CallbackType _tbl_CB_edge_flag_data[];
	static CallbackType _tbl_CB_end_data[];
	static CallbackType _tbl_CB_vertex_data[];
	static CallbackType _tbl_CB_error_data[];
	static CallbackType _tbl_CB_combine_data[];
	*/
	static Function *_pFunc_CB_begin;
	static Function *_pFunc_CB_edge_flag;
	static Function *_pFunc_CB_vertex;
	static Function *_pFunc_CB_end;
	static Function *_pFunc_CB_error;
	static Function *_pFunc_CB_combine;
	static Function *_pFunc_CB_begin_data;
	static Function *_pFunc_CB_edge_flag_data;
	static Function *_pFunc_CB_end_data;
	static Function *_pFunc_CB_vertex_data;
	static Function *_pFunc_CB_error_data;
	static Function *_pFunc_CB_combine_data;
public:
	inline Object_Tesselator(GLUtesselator *tess) :
			Object(Gura_UserClass(Tesselator)), _tess(tess) {}
	virtual ~Object_Tesselator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	static void SetCallback(Signal sig, GLUtesselator *tess, GLenum which, const Function *func);
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
	static void CB_edge_flag(GLboolean flag);
	static void CB_vertex(void *vertex_data);
	static void CB_end(void);
	static void CB_error(GLenum errno);
	static void CB_combine(GLdouble coords[3], void *vertex_data[4],
						   GLfloat weight[4], void **outData);
	static void CB_begin_data(GLenum type, void *polygon_data);
	static void CB_edge_flag_data(GLboolean flag, void *polygon_data);
	static void CB_end_data(void *polygon_data);
	static void CB_vertex_data(void *vertex_data, void *polygon_data);
	static void CB_error_data(GLenum errno, void *polygon_data);
	static void CB_combine_data(GLdouble coords[3], void *vertex_data[4],
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
	/*
	static CallbackType _tbl_CB_begin[];
	static CallbackType _tbl_CB_vertex[];
	static CallbackType _tbl_CB_normal[];
	static CallbackType _tbl_CB_color[];
	static CallbackType _tbl_CB_tex_coord[];
	static CallbackType _tbl_CB_end[];
	static CallbackType _tbl_CB_begin_data[];
	static CallbackType _tbl_CB_vertex_data[];
	static CallbackType _tbl_CB_normal_data[];
	static CallbackType _tbl_CB_color_data[];
	static CallbackType _tbl_CB_tex_coord_data[];
	static CallbackType _tbl_CB_end_data[];
	static CallbackType _tbl_CB_error[];
	*/
	static Function *_pFunc_CB_begin;
	static Function *_pFunc_CB_vertex;
	static Function *_pFunc_CB_normal;
	static Function *_pFunc_CB_color;
	static Function *_pFunc_CB_tex_coord;
	static Function *_pFunc_CB_end;
	static Function *_pFunc_CB_begin_data;
	static Function *_pFunc_CB_vertex_data;
	static Function *_pFunc_CB_normal_data;
	static Function *_pFunc_CB_color_data;
	static Function *_pFunc_CB_tex_coord_data;
	static Function *_pFunc_CB_end_data;
	static Function *_pFunc_CB_error;
public:
	inline Object_Nurbs(GLUnurbs *nurb) :
				Object(Gura_UserClass(Nurbs)), _nurb(nurb) {}
	virtual ~Object_Nurbs();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	static void SetCallback(Signal sig, GLUnurbs *nurb, GLenum which, const Function *func);
	inline GLUnurbs *GetNurbs() { return _nurb; }
private:
	inline Object_Nurbs(const Object_Nurbs &obj) : Object(obj) {}
public:
	


	static void CB_begin(GLenum type);
	static void CB_vertex(GLfloat *vertex);
	static void CB_normal(GLfloat *normal);
	static void CB_color(GLfloat *color);
	static void CB_tex_coord(GLfloat *tex_coord);
	static void CB_end(void);
	static void CB_begin_data(GLenum type, void *userData);
	static void CB_vertex_data(GLfloat *vertex, void *userData);
	static void CB_normal_data(GLfloat *normal, void *userData);
	static void CB_color_data(GLfloat *color, void *userData);
	static void CB_tex_coord_data(GLfloat *tex_coord, void *userData);
	static void CB_end_data(void *userData);
	static void CB_error(GLenum errno);
};

Gura_EndModuleHeader(glu)

#endif
