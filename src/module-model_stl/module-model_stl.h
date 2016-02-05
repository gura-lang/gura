//=============================================================================
// Gura module: model.stl
//=============================================================================
#ifndef __GURA_MODULE_MODEL_STL_H__
#define __GURA_MODULE_MODEL_STL_H__
#include <gura.h>

Gura_BeginModuleHeader(model_stl)

Gura_DeclareUserSymbol(header);
Gura_DeclareUserSymbol(name);
Gura_DeclareUserSymbol(faces);
Gura_DeclareUserSymbol(normal);
Gura_DeclareUserSymbol(vertex1);
Gura_DeclareUserSymbol(vertex2);
Gura_DeclareUserSymbol(vertex3);
Gura_DeclareUserSymbol(attr);

//-----------------------------------------------------------------------------
// TokenId
//-----------------------------------------------------------------------------
enum TokenId {
	TOKEN_None, TOKEN_EOL, TOKEN_EOF, TOKEN_Field,
};

//-----------------------------------------------------------------------------
// FaceBin
//-----------------------------------------------------------------------------
struct FaceBin {
	enum { Size = sizeof(float) * 3 * 4 + 2 };
	float normal[3];
	float vertex1[3];
	float vertex2[3];
	float vertex3[3];
	UShort attr;
};

//-----------------------------------------------------------------------------
// Face
//-----------------------------------------------------------------------------
class Face {
private:
	AutoPtr<VertexRef> _pNormal;
	VertexRef *_pVertexes[3];
	UShort _attr;
public:
	Face();
	Face(const Face &face);
	~Face();
	inline void SetNormal(VertexRef *pNormal) { _pNormal.reset(pNormal); }
	inline void SetVertex(size_t idx, VertexRef *pVertex) { _pVertexes[idx] = pVertex; }
	inline void SetAttr(UShort attr) { _attr = attr; }
	inline const VertexRef &GetNormal() const { return *_pNormal; }
	inline const VertexRef &GetVertex(size_t idx) const { return *_pVertexes[idx]; }
	inline UShort GetAttr() const { return _attr; }
	void UpdateNormal();
	String ToString(const char *sep = "; ") const;
};

//-----------------------------------------------------------------------------
// Tokenizer
//-----------------------------------------------------------------------------
class Tokenizer {
public:
	enum Stat {
		STAT_LineTop, STAT_Field, STAT_SkipWhite, STAT_FileEnd,
	};
private:
	Stat _stat;
	size_t _iChar;
	char _field[128];
	TokenId _tokenIdPending;
public:
	inline Tokenizer() : _stat(STAT_LineTop), _iChar(0), _tokenIdPending(TOKEN_None) {}
	TokenId Tokenize(Environment &env, Stream &stream);
	inline const char *GetField() const { return _field; }
};

//-----------------------------------------------------------------------------
// Object_face
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(face);

class Object_face : public Object {
private:
	Face _face;
public:
	Gura_DeclareObjectAccessor(face)
public:
	Object_face();
	Object_face(const Object_face &obj);
	virtual ~Object_face();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Face &GetFace() { return _face; }
};

//-----------------------------------------------------------------------------
// Iterator_faces
//-----------------------------------------------------------------------------
class Iterator_faces : public Iterator {
public:
	enum Stat {
		STAT_facet, STAT_normal, STAT_normal_coords,
		STAT_outer, STAT_loop,
		STAT_vertex, STAT_vertex_coords,
		STAT_endloop,
		STAT_endfacet,
	};
private:
	bool _binaryFlag;
	AutoPtr<Stream> _pStream;
	size_t _idxFace;
	size_t _nFace;			// for binary
	String _text;			// header for binary / solid name for text
	Stat _stat;				// for text
	Tokenizer _tokenizer;	// for text
public:
	Iterator_faces(Stream *pStream);
	virtual ~Iterator_faces();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	bool Prepare(Environment &env);
	inline bool GetBinaryFlag() const { return _binaryFlag; }
	inline const String &GetText() const { return _text; }
private:
	bool DoNextFromBinary(Environment &env, Value &value);
	bool DoNextFromText(Environment &env, Value &value);
};

//-----------------------------------------------------------------------------
// Object_solid
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(solid);

class Object_solid : public Object {
private:
	AutoPtr<Iterator_faces> _pIterator;
public:
	Gura_DeclareObjectAccessor(solid)
public:
	Object_solid(Iterator_faces *pIterator);
	Object_solid(const Object_solid &obj);
	virtual ~Object_solid();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleHeader(model_stl)

#endif
