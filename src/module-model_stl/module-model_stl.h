//=============================================================================
// Gura module: model.stl
//=============================================================================
#ifndef __GURA_MODULE_MODEL_STL_H__
#define __GURA_MODULE_MODEL_STL_H__
#include <gura.h>

Gura_BeginModuleHeader(model_stl)
//-----------------------------------------------------------------------------
// TokenId
//-----------------------------------------------------------------------------
enum TokenId {
	TOKEN_None, TOKEN_EOL, TOKEN_EOF, TOKEN_Field,
};

//-----------------------------------------------------------------------------
// Facet
//-----------------------------------------------------------------------------
class Facet {
private:
	Vertex _normal;
	Vertex _vertexes[3];
public:
	inline Facet() {}
	Facet(const Facet &facet);
	inline void SetNormal(const Vertex &normal) { _normal = normal; }
	inline void SetVertex(size_t idx, const Vertex &vertex) { _vertexes[idx] = vertex; }
	inline const Vertex &GetNormal() const { return _normal; }
	inline const Vertex &GetVertex(size_t idx) const { return _vertexes[idx]; }
	String ToString() const;
};

//-----------------------------------------------------------------------------
// Object_facet
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(facet);

class Object_facet : public Object {
private:
	Facet _facet;
public:
	Gura_DeclareObjectAccessor(facet)
public:
	Object_facet();
	Object_facet(const Object_facet &obj);
	virtual ~Object_facet();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Facet &GetFacet() { return _facet; }
};

//-----------------------------------------------------------------------------
// Iterator_facet
//-----------------------------------------------------------------------------
class Iterator_facet : public Iterator {
private:
	AutoPtr<Stream> _pStream;
public:
	Iterator_facet(Stream *pStream);
	virtual ~Iterator_facet();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Solid
//-----------------------------------------------------------------------------
class Solid {
private:
	
};

//-----------------------------------------------------------------------------
// Tokenizer
//-----------------------------------------------------------------------------
class Tokenizer {
public:
	enum Stat {
		STAT_FileTop, STAT_FileEnd, STAT_LineTop, STAT_Field, STAT_SkipWhite,
	};
private:
	Stat _stat;
	String _field;
	TokenId _tokenIdPending;
public:
	inline Tokenizer() : _stat(STAT_FileTop), _tokenIdPending(TOKEN_None) {}
	TokenId Tokenize(Environment &env, Stream &stream);
	inline const String &GetField() const { return _field; }
};

Gura_EndModuleHeader(model_stl)

#endif
