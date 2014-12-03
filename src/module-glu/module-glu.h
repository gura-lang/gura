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

#define DispatchCallback(funcToSetCallback, obj, which, name) \
case which: { \
	int idx = _cnt_CB_##name++; \
	if (idx >= ArraySizeOf(_tbl_CB_##name)) { \
		sig.SetError(ERR_OutOfRangeError, "too many callbacks"); \
		return; \
	} \
	if (func == NULL) { \
		funcToSetCallback(obj, which, NULL); \
	} else { \
		_pFuncs_CB_##name[idx] = func->Reference(); \
		funcToSetCallback(obj, which, reinterpret_cast<CallbackType>(_tbl_CB_##name[idx])); \
	} \
	break; \
}

#define DeclareCallbackInfo(name) \
int _idx_CB_##name; \
static int _cnt_CB_##name; \
static CallbackType _tbl_CB_##name[]; \
static Function *_pFuncs_CB_##name[]

#define ImplementCallbackInfo(objClass, name)	\
int Object_##objClass::_cnt_CB_##name = 0; \
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
	DeclareCallbackInfo(error);
public:
	Object_Quadric(GLUquadric *quad);
	virtual ~Object_Quadric();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	static void SetCallback(Signal sig, GLUquadric *quad, GLenum which, const Function *func);
	inline GLUquadric *GetQuadric() { return _quad; }
private:
	inline Object_Quadric(const Object_Quadric &obj) : Object(obj) {}
public:
	template<int idx> static void CB_error(GLenum errno) {
		const Function *pFunc = _pFuncs_CB_error[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value(static_cast<int>(errno)));
		pFunc->Eval(env, g_sig, *pArgs);
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
	static void SetCallback(Signal sig, GLUtesselator *tess, GLenum which, const Function *func);
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
	template<int idx> static void CB_begin(GLenum type) {
		const Function *pFunc = _pFuncs_CB_begin[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value(static_cast<int>(type)));
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_edge_flag(GLboolean flag) {
		const Function *pFunc = _pFuncs_CB_edge_flag[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value(flag == GL_TRUE));
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_vertex(void *vertex_data) {
		const Function *pFunc = _pFuncs_CB_vertex[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(reinterpret_cast<VertexPack *>(vertex_data)->GetVertexData());
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_end(void) {
		const Function *pFunc = _pFuncs_CB_end[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_error(GLenum errno) {
		const Function *pFunc = _pFuncs_CB_error[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value(errno));
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_combine(GLdouble coords[3], void *vertex_data[4],
										 GLfloat weight[4], void **outData) {
		const Function *pFunc = _pFuncs_CB_combine[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->AddValue(Value::CreateList(env, coords, 3));
		do {
			Value value;
			ValueList &valList = value.InitAsList(env, 4);
			for (int i = 0; i < 4; i++) {
				valList.push_back(reinterpret_cast<VertexPack *>(vertex_data[i])->GetVertexData());
			}
			pArgs->AddValue(value);
		} while (0);
		pArgs->AddValue(Value::CreateList(env, weight, 4));
		Value rtn = pFunc->Eval(env, g_sig, *pArgs);

		// outData
	}
	template<int idx> static void CB_begin_data(GLenum type, void *polygon_data) {
		const Function *pFunc = _pFuncs_CB_begin_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValues(
			Value(type),
			reinterpret_cast<PolygonPack *>(polygon_data)->GetPolygonData());
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_edge_flag_data(GLboolean flag, void *polygon_data) {
		const Function *pFunc = _pFuncs_CB_edge_flag_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValues(
			Value(flag == GL_TRUE),
			reinterpret_cast<PolygonPack *>(polygon_data)->GetPolygonData());
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_end_data(void *polygon_data) {
		const Function *pFunc = _pFuncs_CB_end_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(reinterpret_cast<PolygonPack *>(polygon_data)->GetPolygonData());
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_vertex_data(void *vertex_data, void *polygon_data) {
		const Function *pFunc = _pFuncs_CB_vertex_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValues(
			reinterpret_cast<VertexPack *>(vertex_data)->GetVertexData(),
			reinterpret_cast<PolygonPack *>(polygon_data)->GetPolygonData());
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_error_data(GLenum errno, void *polygon_data) {
		const Function *pFunc = _pFuncs_CB_error_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValues(
			Value(errno),
			reinterpret_cast<PolygonPack *>(polygon_data)->GetPolygonData());
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_combine_data(GLdouble coords[3], void *vertex_data[4],
								  GLfloat weight[4], void **outDatab, void *polygon_data) {
		const Function *pFunc = _pFuncs_CB_combine_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->AddValue(Value::CreateList(env, coords, 3));
		do {
			Value value;
			ValueList &valList = value.InitAsList(env, 4);
			for (int i = 0; i < 4; i++) {
				valList.push_back(reinterpret_cast<VertexPack *>(vertex_data[i])->GetVertexData());
			}
			pArgs->AddValue(value);
		} while (0);
		pArgs->AddValue(Value::CreateList(env, weight, 4));
		pArgs->AddValue(reinterpret_cast<PolygonPack *>(polygon_data)->GetPolygonData());
		Value rtn = pFunc->Eval(env, g_sig, *pArgs);

		// outDatab
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
	static void SetCallback(Signal sig, GLUnurbs *nurb, GLenum which, const Function *func);
	inline GLUnurbs *GetNurbs() { return _nurb; }
private:
	inline Object_Nurbs(const Object_Nurbs &obj) : Object(obj) {}
public:
	template<int idx> static void CB_begin(GLenum type) {
		const Function *pFunc = _pFuncs_CB_begin[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value(type));
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_vertex(GLfloat *vertex) {
		const Function *pFunc = _pFuncs_CB_vertex[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value::CreateList(env, vertex, 3));
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_normal(GLfloat *normal) {
		const Function *pFunc = _pFuncs_CB_normal[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value::CreateList(env, normal, 3));
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_color(GLfloat *color) {
		const Function *pFunc = _pFuncs_CB_color[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value::CreateList(env, color, 4));
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_texture_coord(GLfloat *tex_coord) {
		const Function *pFunc = _pFuncs_CB_texture_coord[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value::CreateList(env, tex_coord, 4)); // 1, 2, 3, 4
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_end(void) {
		const Function *pFunc = _pFuncs_CB_end[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_begin_data(GLenum type, void *userData) {
		const Function *pFunc = _pFuncs_CB_begin_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());

		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_vertex_data(GLfloat *vertex, void *userData) {
		const Function *pFunc = _pFuncs_CB_vertex_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());

		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_normal_data(GLfloat *normal, void *userData) {
		const Function *pFunc = _pFuncs_CB_normal_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());

		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_color_data(GLfloat *color, void *userData) {
		const Function *pFunc = _pFuncs_CB_color_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());

		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_texture_coord_data(GLfloat *tex_coord, void *userData) {
		const Function *pFunc = _pFuncs_CB_texture_coord_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());

		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_end_data(void *userData) {
		const Function *pFunc = _pFuncs_CB_end_data[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());

		pFunc->Eval(env, g_sig, *pArgs);
	}
	template<int idx> static void CB_error(GLenum errno) {
		const Function *pFunc = _pFuncs_CB_error[idx];
		if (pFunc == NULL) return;
		Environment &env = pFunc->GetEnvScope();
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValue(Value(errno));
		pFunc->Eval(env, g_sig, *pArgs);
	}
};

Gura_EndModuleHeader(glu)

#endif
