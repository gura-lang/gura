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
#include "../module-opengl/Utils.h"

#if defined(GURA_ON_MSWIN)
#else
#define __stdcall
#endif

#define DispatchCallback(funcToSetCallback, obj, which, name) \
case which: { \
	if (func != NULL) { \
		int idx = 0; \
		for ( ; idx < ArraySizeOf(_tbl_CB_##name); idx++) { \
			if (_pFuncs_CB_##name[idx] == NULL) break; \
		} \
		if (idx >= ArraySizeOf(_tbl_CB_##name)) { \
			sig.SetError(ERR_OutOfRangeError, "no room to register the callback"); \
			return; \
		} \
		_idx_CB_##name = idx; \
		_pFuncs_CB_##name[idx] = func->Reference(); \
		funcToSetCallback(obj, which, reinterpret_cast<CallbackType>(_tbl_CB_##name[idx])); \
	} else if (_idx_CB_##name >= 0) { \
		int idx = _idx_CB_##name; \
		Function::Delete(_pFuncs_CB_##name[idx]); \
		_pFuncs_CB_##name[idx] = NULL;	\
		funcToSetCallback(obj, which, NULL); \
	} \
	break; \
}

#define DeclareCallbackInfo(name) \
int _idx_CB_##name; \
static CallbackType _tbl_CB_##name[]; \
static Function *_pFuncs_CB_##name[]

#define ImplementCallbackInfo(objClass, name)	\
CallbackType Object_##objClass::_tbl_CB_##name[] = { \
	reinterpret_cast<CallbackType>(CB_##name<0>), reinterpret_cast<CallbackType>(CB_##name<1>), \
	reinterpret_cast<CallbackType>(CB_##name<2>), reinterpret_cast<CallbackType>(CB_##name<3>), \
	reinterpret_cast<CallbackType>(CB_##name<4>), reinterpret_cast<CallbackType>(CB_##name<5>), \
	reinterpret_cast<CallbackType>(CB_##name<6>), reinterpret_cast<CallbackType>(CB_##name<7>), \
	reinterpret_cast<CallbackType>(CB_##name<8>), reinterpret_cast<CallbackType>(CB_##name<9>), \
	reinterpret_cast<CallbackType>(CB_##name<10>), reinterpret_cast<CallbackType>(CB_##name<11>), \
	reinterpret_cast<CallbackType>(CB_##name<12>), reinterpret_cast<CallbackType>(CB_##name<13>), \
	reinterpret_cast<CallbackType>(CB_##name<14>), reinterpret_cast<CallbackType>(CB_##name<15>), \
	reinterpret_cast<CallbackType>(CB_##name<16>), reinterpret_cast<CallbackType>(CB_##name<17>), \
	reinterpret_cast<CallbackType>(CB_##name<18>), reinterpret_cast<CallbackType>(CB_##name<19>), \
}; \
Function *Object_##objClass::_pFuncs_CB_##name[ArraySizeOf(_tbl_CB_##name)] = {}

#define InitializeCallbackInfo(name) \
_idx_CB_##name = -1;

#define DeinitializeCallbackInfo(name) \
if (_idx_CB_##name >= 0) { \
	int idx = _idx_CB_##name; \
	Function::Delete(_pFuncs_CB_##name[idx]); \
	_pFuncs_CB_##name[idx] = NULL; \
}

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
	inline Object_Tesselator *GetObjTesselator() { return _pObjTess; }
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
	inline Object_Tesselator *GetObjTesselator() { return _pObjTess; }
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
	DeclareCallbackInfo(error);
public:
	Object_Quadric(GLUquadric *quad);
	virtual ~Object_Quadric();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	void SetCallback(Signal sig, GLenum which, const Function *func);
	inline GLUquadric *GetQuadric() { return _quad; }
private:
	inline Object_Quadric(const Object_Quadric &obj) : Object(obj) {}
public:
	static void _CB_error(GLenum err_no, const Function *pFunc);
	template<int idx> static void CB_error(GLenum err_no) {
		_CB_error(err_no, _pFuncs_CB_error[idx]);
	}
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
	DeclareCallbackInfo(begin);
	DeclareCallbackInfo(edge_flag);
	DeclareCallbackInfo(vertex);
	DeclareCallbackInfo(end);
	DeclareCallbackInfo(error);
	DeclareCallbackInfo(combine);
	DeclareCallbackInfo(begin_data);
	DeclareCallbackInfo(edge_flag_data);
	DeclareCallbackInfo(end_data);
	DeclareCallbackInfo(vertex_data);
	DeclareCallbackInfo(error_data);
	DeclareCallbackInfo(combine_data);
public:
	Object_Tesselator(GLUtesselator *tess);
	virtual ~Object_Tesselator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	void SetCallback(Signal sig, GLenum which, const Function *func);
	inline GLUtesselator *GetTesselator() { return _tess; }
	inline PolygonPack *CreatePolygonPack(const Value &polygonData) {
		PolygonPack *pPolygonPack = new PolygonPack(this, polygonData);
		_pPolygonPack.reset(pPolygonPack);
		return pPolygonPack;
	}
	inline void DeletePolygonPack() { _pPolygonPack.reset(NULL); }
	inline PolygonPack *GetPolygonPack() { return _pPolygonPack.get(); }
private:
	inline Object_Tesselator(const Object_Tesselator &obj) : Object(obj) {}
public:
	static void _CB_begin(GLenum type, const Function *pFunc);
	template<int idx> static void CB_begin(GLenum type) {
		_CB_begin(type, _pFuncs_CB_begin[idx]);
	}
	static void _CB_edge_flag(GLboolean flag, const Function *pFunc);
	template<int idx> static void CB_edge_flag(GLboolean flag) {
		_CB_edge_flag(flag, _pFuncs_CB_edge_flag[idx]);
	}
	static void _CB_vertex(void *vertex_data, const Function *pFunc);
	template<int idx> static void CB_vertex(void *vertex_data) {
		_CB_vertex(vertex_data, _pFuncs_CB_vertex[idx]);
	}
	static void _CB_end(const Function *pFunc);
	template<int idx> static void CB_end(void) {
		_CB_end(_pFuncs_CB_end[idx]);
	}
	static void _CB_error(GLenum err_no, const Function *pFunc);
	template<int idx> static void CB_error(GLenum err_no) {
		_CB_error(err_no, _pFuncs_CB_error[idx]);
	}
	static void _CB_combine(GLdouble coords[3], void *vertex_data[4],
							GLfloat weight[4], void **outData, const Function *pFunc);
	template<int idx> static void CB_combine(GLdouble coords[3], void *vertex_data[4],
							GLfloat weight[4], void **outData) {
		_CB_combine(coords, vertex_data, weight, outData, _pFuncs_CB_combine[idx]);
	}
	static void _CB_begin_data(GLenum type, void *polygon_data, const Function *pFunc);
	template<int idx> static void CB_begin_data(GLenum type, void *polygon_data) {
		_CB_begin_data(type, polygon_data, _pFuncs_CB_begin_data[idx]);
	}
	static void _CB_edge_flag_data(GLboolean flag, void *polygon_data, const Function *pFunc);
	template<int idx> static void CB_edge_flag_data(GLboolean flag, void *polygon_data) {
		_CB_edge_flag_data(flag, polygon_data, _pFuncs_CB_edge_flag_data[idx]);
	}
	static void _CB_end_data(void *polygon_data, const Function *pFunc);
	template<int idx> static void CB_end_data(void *polygon_data) {
		_CB_end_data(polygon_data, _pFuncs_CB_end_data[idx]);
	}
	static void _CB_vertex_data(void *vertex_data, void *polygon_data, const Function *pFunc);
	template<int idx> static void CB_vertex_data(void *vertex_data, void *polygon_data) {
		_CB_vertex_data(vertex_data, polygon_data, _pFuncs_CB_vertex_data[idx]);
	}
	static void _CB_error_data(GLenum err_no, void *polygon_data, const Function *pFunc);
	template<int idx> static void CB_error_data(GLenum err_no, void *polygon_data) {
		_CB_error_data(err_no, polygon_data, _pFuncs_CB_error_data[idx]);
	}
	static void _CB_combine_data(GLdouble coords[3], void *vertex_data[4],
				 GLfloat weight[4], void **outDatab, void *polygon_data, const Function *pFunc);
	template<int idx> static void CB_combine_data(GLdouble coords[3], void *vertex_data[4],
				  GLfloat weight[4], void **outDatab, void *polygon_data) {
		_CB_combine_data(coords, vertex_data, weight, outDatab, polygon_data,
						 _pFuncs_CB_combine_data[idx]);
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
	GLUnurbs *_nurb;
	Value _userData;
	Value _userDataEXT;
	DeclareCallbackInfo(begin);
	DeclareCallbackInfo(vertex);
	DeclareCallbackInfo(normal);
	DeclareCallbackInfo(color);
	DeclareCallbackInfo(texture_coord);
	DeclareCallbackInfo(end);
	DeclareCallbackInfo(begin_data);
	DeclareCallbackInfo(vertex_data);
	DeclareCallbackInfo(normal_data);
	DeclareCallbackInfo(color_data);
	DeclareCallbackInfo(texture_coord_data);
	DeclareCallbackInfo(end_data);
	DeclareCallbackInfo(error);
public:
	Object_Nurbs(GLUnurbs *nurb);
	virtual ~Object_Nurbs();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	void SetCallback(Signal sig, GLenum which, const Function *func);
	inline GLUnurbs *GetNurbs() { return _nurb; }
	inline void SetCallbackData(const Value &userData) { _userData = userData; }
	inline void SetCallbackDataEXT(const Value &userData) { _userDataEXT = userData; }
	inline const Value &GetCallbackData() const { return _userData; }
	inline const Value &GetCallbackDataEXT() const { return _userDataEXT; }
private:
	inline Object_Nurbs(const Object_Nurbs &obj) : Object(obj) {}
public:
	static void _CB_begin(GLenum type, const Function *pFunc);
	template<int idx> static void CB_begin(GLenum type) {
		_CB_begin(type, _pFuncs_CB_begin[idx]);
	}
	static void _CB_vertex(GLfloat *vertex, const Function *pFunc);
	template<int idx> static void CB_vertex(GLfloat *vertex) {
		_CB_vertex(vertex, _pFuncs_CB_vertex[idx]);
	}
	static void _CB_normal(GLfloat *normal, const Function *pFunc);
	template<int idx> static void CB_normal(GLfloat *normal) {
		_CB_normal(normal, _pFuncs_CB_normal[idx]);
	}
	static void _CB_color(GLfloat *color, const Function *pFunc);
	template<int idx> static void CB_color(GLfloat *color) {
		_CB_color(color, _pFuncs_CB_color[idx]);
	}
	static void _CB_texture_coord(GLfloat *tex_coord, const Function *pFunc);
	template<int idx> static void CB_texture_coord(GLfloat *tex_coord) {
		_CB_texture_coord(tex_coord, _pFuncs_CB_texture_coord[idx]);
	}
	static void _CB_end(const Function *pFunc);
	template<int idx> static void CB_end(void) {
		_CB_end(_pFuncs_CB_end[idx]);
	}
	static void _CB_begin_data(GLenum type, void *userData, const Function *pFunc);
	template<int idx> static void CB_begin_data(GLenum type, void *userData) {
		_CB_begin_data(type, userData, _pFuncs_CB_begin_data[idx]);
	}
	static void _CB_vertex_data(GLfloat *vertex, void *userData, const Function *pFunc);
	template<int idx> static void CB_vertex_data(GLfloat *vertex, void *userData) {
		_CB_vertex_data(vertex, userData, _pFuncs_CB_vertex_data[idx]);
	}
	static void _CB_normal_data(GLfloat *normal, void *userData, const Function *pFunc);
	template<int idx> static void CB_normal_data(GLfloat *normal, void *userData) {
		_CB_normal_data(normal, userData, _pFuncs_CB_normal_data[idx]);
	}
	static void _CB_color_data(GLfloat *color, void *userData, const Function *pFunc);
	template<int idx> static void CB_color_data(GLfloat *color, void *userData) {
		_CB_color_data(color, userData, _pFuncs_CB_color_data[idx]);
	}
	static void _CB_texture_coord_data(GLfloat *tex_coord, void *userData, const Function *pFunc);
	template<int idx> static void CB_texture_coord_data(GLfloat *tex_coord, void *userData) {
		_CB_texture_coord_data(tex_coord, userData, _pFuncs_CB_texture_coord_data[idx]);
	}
	static void _CB_end_data(void *userData, const Function *pFunc);
	template<int idx> static void CB_end_data(void *userData) {
		_CB_end_data(userData, _pFuncs_CB_end_data[idx]);
	}
	static void _CB_error(GLenum err_no, const Function *pFunc);
	template<int idx> static void CB_error(GLenum err_no) {
		_CB_error(err_no, _pFuncs_CB_error[idx]);
	}
};

Gura_EndModuleHeader(glu)

#endif
