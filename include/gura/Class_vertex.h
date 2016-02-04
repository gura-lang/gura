//=============================================================================
// Gura class: vertex
//=============================================================================
#ifndef __GURA_CLASS_VERTEX_H__
#define __GURA_CLASS_VERTEX_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_vertex
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_vertex : public Class {
public:
	Class_vertex(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_vertex
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_vertex : public Object {
public:
	Gura_DeclareObjectAccessor(vertex)
private:
	AutoPtr<VertexRef> _pVertex;
public:
	inline Object_vertex(const Object_vertex &obj) :
		Object(obj), _pVertex(new VertexRef(obj.GetVertex())) {}
	inline Object_vertex(Environment &env) :
		Object(env.LookupClass(VTYPE_vertex)), _pVertex(new VertexRef()) {}
	inline Object_vertex(Environment &env, const Vertex &vertex) :
		Object(env.LookupClass(VTYPE_vertex)), _pVertex(new VertexRef(vertex)) {}
	inline Object_vertex(Environment &env, VertexRef *pVertex) :
		Object(env.LookupClass(VTYPE_vertex)), _pVertex(pVertex) {}
	inline Object_vertex(Class *pClass) : Object(pClass) {}
	inline void SetVertexRef(VertexRef *pVertex) { _pVertex.reset(pVertex); }
	inline VertexRef *GetVertexRef() { return _pVertex.get(); }
	inline const VertexRef *GetVertexRef() const { return _pVertex.get(); }
	inline Vertex &GetVertex() { return *_pVertex; }
	inline const Vertex &GetVertex() const { return *_pVertex; }
	virtual ~Object_vertex();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

}

#endif
