//=============================================================================
// Gura module: model.obj
//=============================================================================
#ifndef __GURA_MODULE_MODEL_OBJ_H__
#define __GURA_MODULE_MODEL_OBJ_H__
#include <gura.h>

Gura_BeginModuleHeader(model_obj)

Gura_DeclareUserSymbol(faces);
Gura_DeclareUserSymbol(v1);
Gura_DeclareUserSymbol(v2);
Gura_DeclareUserSymbol(v3);
Gura_DeclareUserSymbol(v4);
Gura_DeclareUserSymbol(vt1);
Gura_DeclareUserSymbol(vt2);
Gura_DeclareUserSymbol(vt3);
Gura_DeclareUserSymbol(vt4);
Gura_DeclareUserSymbol(vn1);
Gura_DeclareUserSymbol(vn2);
Gura_DeclareUserSymbol(vn3);
Gura_DeclareUserSymbol(vn4);

class Content;

//-----------------------------------------------------------------------------
// TokenId
//-----------------------------------------------------------------------------
enum TokenId {
	TOKEN_None, TOKEN_EOL, TOKEN_EOF, TOKEN_Field,
};

//-----------------------------------------------------------------------------
// Tokenizer
//-----------------------------------------------------------------------------
class Tokenizer {
public:
	enum Stat {
		STAT_LineTop, STAT_SkipToNextLine, STAT_Field, STAT_SkipWhite, STAT_FileEnd,
	};
private:
	Stat _stat;
	size_t _iLine;
	size_t _iChar;
	char _field[128];
	TokenId _tokenIdPending;
public:
	inline Tokenizer() : _stat(STAT_LineTop), _iLine(0), _iChar(0), _tokenIdPending(TOKEN_None) {}
	TokenId Tokenize(Environment &env, Stream &stream);
	inline const char *GetField() const { return _field; }
	inline size_t GetLineNo() const { return _iLine + 1; }
};

//-----------------------------------------------------------------------------
// Vertex3
//-----------------------------------------------------------------------------
struct Vertex3 : public Gura::VertexRef {
public:
	inline Vertex3(double _x, double _y, double _z) :
		Gura::VertexRef(_x, _y, _z) {}
};

//-----------------------------------------------------------------------------
// Vertex3List
//-----------------------------------------------------------------------------
typedef std::vector<Vertex3 *> Vertex3List;

//-----------------------------------------------------------------------------
// Vertex3Owner
//-----------------------------------------------------------------------------
class Vertex3Owner : public Vertex3List {
public:
	~Vertex3Owner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Vertex4
//-----------------------------------------------------------------------------
struct Vertex4 : public Gura::VertexRef {
public:
	double w;
public:
	Gura_DeclareReferenceAccessor(Vertex4)
public:
	inline Vertex4(double _x, double _y, double _z, double _w) :
		Gura::VertexRef(_x, _y, _z), w(_w) {}
	String ToString() const;
};

//-----------------------------------------------------------------------------
// Vertex4List
//-----------------------------------------------------------------------------
typedef std::vector<Vertex4 *> Vertex4List;

//-----------------------------------------------------------------------------
// Vertex4Owner
//-----------------------------------------------------------------------------
class Vertex4Owner : public Vertex4List {
public:
	~Vertex4Owner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Index
//-----------------------------------------------------------------------------
typedef int Index;

//-----------------------------------------------------------------------------
// IndexList
//-----------------------------------------------------------------------------
typedef std::vector<Index> IndexList;

//-----------------------------------------------------------------------------
// IndexPair
//-----------------------------------------------------------------------------
class IndexPair {
public:
	int iV, iVt;
public:
	inline IndexPair(int _iV, int _iVt) : iV(_iV), iVt(_iVt) {}
};

//-----------------------------------------------------------------------------
// IndexPairList
//-----------------------------------------------------------------------------
typedef std::vector<IndexPair> IndexPairList;

//-----------------------------------------------------------------------------
// IndexTriplet
//-----------------------------------------------------------------------------
class IndexTriplet {
public:
	int iV, iVt, iVn;
public:
	inline IndexTriplet(int _iV, int _iVt, int _iVn) : iV(_iV), iVt(_iVt), iVn(_iVn) {}
};

//-----------------------------------------------------------------------------
// IndexTripletList
//-----------------------------------------------------------------------------
typedef std::vector<IndexTriplet> IndexTripletList;

//-----------------------------------------------------------------------------
// Point
//-----------------------------------------------------------------------------
class Point {
private:
	size_t _cntRef;
	IndexList _indexList;
public:
	Gura_DeclareReferenceAccessor(Point)
public:
	inline Point() : _cntRef(1) { _indexList.reserve(16); }
protected:
	inline ~Point() {}
public:
	inline void AddIndex(int iV) {
		_indexList.push_back(iV);
	}
	inline const IndexList &GetIndexList() const { return _indexList; }
	const Vertex4 *GetV(const Content &content, size_t iIndex) const;
};

//-----------------------------------------------------------------------------
// PointList
//-----------------------------------------------------------------------------
typedef std::vector<Point *> PointList;

//-----------------------------------------------------------------------------
// PointOwner
//-----------------------------------------------------------------------------
class PointOwner : public PointList {
public:
	~PointOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Line
//-----------------------------------------------------------------------------
class Line {
private:
	size_t _cntRef;
	IndexPairList _indexPairList;
public:
	Gura_DeclareReferenceAccessor(Line)
public:
	inline Line() : _cntRef(1) { _indexPairList.reserve(16); }
protected:
	inline ~Line() {}
public:
	inline void AddIndexPair(int iV, int iVt) {
		_indexPairList.push_back(IndexPair(iV, iVt));
	}
	inline const IndexPairList &GetIndexPairList() const { return _indexPairList; }
	const Vertex4 *GetV(const Content &content, size_t iIndexPair) const;
	const Vertex3 *GetVt(const Content &content, size_t iIndexPair) const;
};

//-----------------------------------------------------------------------------
// LineList
//-----------------------------------------------------------------------------
typedef std::vector<Line *> LineList;

//-----------------------------------------------------------------------------
// LineOwner
//-----------------------------------------------------------------------------
class LineOwner : public LineList {
public:
	~LineOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Face
//-----------------------------------------------------------------------------
class Face {
private:
	size_t _cntRef;
	IndexTripletList _indexTripletList;
public:
	Gura_DeclareReferenceAccessor(Face)
public:
	inline Face() : _cntRef(1) { _indexTripletList.reserve(4); }
protected:
	inline ~Face() {}
public:
	inline void AddIndexTriplet(int iV, int iVt, int iVn) {
		_indexTripletList.push_back(IndexTriplet(iV, iVt, iVn));
	}
	inline const IndexTripletList &GetIndexTripletList() const { return _indexTripletList; }
	const Vertex4 *GetV(const Content &content, size_t iIndexTriplet) const;
	const Vertex3 *GetVt(const Content &content, size_t iIndexTriplet) const;
	const Vertex3 *GetVn(const Content &content, size_t iIndexTriplet) const;
};

//-----------------------------------------------------------------------------
// FaceList
//-----------------------------------------------------------------------------
typedef std::vector<Face *> FaceList;

//-----------------------------------------------------------------------------
// FaceOwner
//-----------------------------------------------------------------------------
class FaceOwner : public FaceList {
public:
	~FaceOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Content
//-----------------------------------------------------------------------------
class Content {
public:
	enum Stat {
		STAT_Keyword,
		STAT_call,
		STAT_csh,
		STAT_v,
		STAT_vt,
		STAT_vn,
		STAT_vp,
		STAT_cstype,
		STAT_deg,
		STAT_bmat,
		STAT_step,
		STAT_p,
		STAT_l,
		STAT_f,
		STAT_curv,
		STAT_curv2,
		STAT_surf,
		STAT_parm,
		STAT_trim,
		STAT_hole,
		STAT_scrv,
		STAT_sp,
		STAT_end,
		STAT_con,
		STAT_g,
		STAT_s,
		STAT_mg,
		STAT_o,
		STAT_beval,
		STAT_c_interp,
		STAT_d_interp,
		STAT_lod,
		STAT_usemap,
		STAT_maplib,
		STAT_usemtl,
		STAT_mtllib,
		STAT_shadow_obj,
		STAT_trace_obj,
		STAT_ctech,
		STAT_stech,
	};
private:
	size_t _cntRef;
	Vertex4Owner	_vs;
	Vertex3Owner	_vps;
	Vertex3Owner	_vns;
	Vertex3Owner	_vts;
	PointOwner		_points;
	LineOwner		_lines;
	FaceOwner		_faces;
public:
	Gura_DeclareReferenceAccessor(Content)
public:
	inline Content() : _cntRef(1) {}
protected:
	inline ~Content() {}
public:
	bool Read(Environment &env, Stream &stream);
	inline const FaceOwner &GetFaces() const { return _faces; }
	inline const Face *GetFace(size_t iFace) const {
		return (iFace < _faces.size())? _faces[iFace] : nullptr;
	}
	inline const Vertex4 *GetV(size_t iV) const {
		return (0 < iV && iV < _vs.size() + 1)? _vs[iV - 1] : nullptr;
	}
	inline const Vertex3 *GetVp(size_t iVp) const {
		return (0 < iVp && iVp < _vps.size() + 1)? _vps[iVp - 1] : nullptr;
	}
	inline const Vertex3 *GetVn(size_t iVn) const {
		return (0 < iVn && iVn < _vns.size() + 1)? _vns[iVn - 1] : nullptr;
	}
	inline const Vertex3 *GetVt(size_t iVt) const {
		return (0 < iVt && iVt < _vts.size() + 1)? _vts[iVt - 1] : nullptr;
	}
private:
	static bool ExtractFloat(Environment &env, const char *field, double *pNum);
	static bool ExtractIndex(Environment &env, const char *field, int *pNum);
	static bool ExtractIndexPair(Environment &env, const char *field, int *piV, int *piVt);
	static bool ExtractIndexTriplet(Environment &env, const Tokenizer &tokenizer, const char *field, int *piV, int *piVt, int *piVn);
};

//-----------------------------------------------------------------------------
// Object_vertex4
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(vertex4);

class Object_vertex4 : public Object_vertex {
public:
	Gura_DeclareObjectAccessor(vertex4)
public:
	Object_vertex4(Vertex4 *pVertex);
	virtual ~Object_vertex4();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline const Vertex4 *GetVertex4() const {
		return reinterpret_cast<const Vertex4 *>(GetVertexRef());
	}
};

//-----------------------------------------------------------------------------
// Object_content
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(content);

class Object_content : public Object {
private:
	AutoPtr<Content> _pContent;
public:
	Gura_DeclareObjectAccessor(content)
public:
	Object_content(Content *pContent);
	Object_content(const Object_content &obj);
	virtual ~Object_content();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline const Content *GetContent() const { return _pContent.get(); }
};

//-----------------------------------------------------------------------------
// Object_face
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(face);

class Object_face : public Object {
private:
	AutoPtr<Content> _pContent;
	AutoPtr<Face> _pFace;
public:
	Gura_DeclareObjectAccessor(face)
public:
	Object_face(Content *pContent, Face *pFace);
	Object_face(const Object_face &obj);
	virtual ~Object_face();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline const Content *GetContent() const { return _pContent.get(); }
	inline const Face *GetFace() const { return _pFace.get(); }
};

//-----------------------------------------------------------------------------
// Iterator_face
//-----------------------------------------------------------------------------
class Iterator_face : public Iterator {
private:
	AutoPtr<Content> _pContent;
	size_t _iFace;
public:
	Iterator_face(Content *pContent);
	virtual ~Iterator_face();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_FormatError(Environment &env);
void SetError_NotImplementedKeyword(Environment &env, const char *keyword);

Gura_EndModuleHeader(model_obj)

#endif
