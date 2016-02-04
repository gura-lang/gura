//=============================================================================
// Gura module: model.stl
//=============================================================================
#ifndef __GURA_MODULE_MODEL_STL_H__
#define __GURA_MODULE_MODEL_STL_H__
#include <gura.h>

Gura_BeginModuleHeader(model_stl)

Gura_DeclareUserSymbol(header);
Gura_DeclareUserSymbol(solidname);
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
// FacetBin
//-----------------------------------------------------------------------------
struct FacetBin {
	enum { Size = sizeof(float) * 3 * 4 + 2 };
	float normal[3];
	float vertex1[3];
	float vertex2[3];
	float vertex3[3];
	UShort attr;
};

//-----------------------------------------------------------------------------
// Facet
//-----------------------------------------------------------------------------
class Facet {
private:
	AutoPtr<VertexRef> _pNormal;
	VertexRef *_pVertexes[3];
	UShort _attr;
public:
	Facet();
	Facet(const Facet &facet);
	~Facet();
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
	String _field;
	TokenId _tokenIdPending;
public:
	inline Tokenizer() : _stat(STAT_LineTop), _tokenIdPending(TOKEN_None) {}
	TokenId Tokenize(Environment &env, Stream &stream);
	inline const String &GetField() const { return _field; }
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
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Facet &GetFacet() { return _facet; }
};

//-----------------------------------------------------------------------------
// Iterator_reader
//-----------------------------------------------------------------------------
class Iterator_reader : public Iterator {
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
	size_t _idxFacet;
	size_t _nFacet;			// for binary
	String _text;			// header for binary / solid name for text
	Stat _stat;				// for text
	Tokenizer _tokenizer;	// for text
public:
	Iterator_reader(Stream *pStream);
	virtual ~Iterator_reader();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	bool Prepare(Environment &env);
private:
	bool DoNextFromBinary(Environment &env, Value &value);
	bool DoNextFromText(Environment &env, Value &value);
};

Gura_EndModuleHeader(model_stl)

#endif
