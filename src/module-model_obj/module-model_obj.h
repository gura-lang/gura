//=============================================================================
// Gura module: model.obj
//=============================================================================
#ifndef __GURA_MODULE_MODEL_OBJ_H__
#define __GURA_MODULE_MODEL_OBJ_H__
#include <gura.h>

Gura_BeginModuleHeader(model_obj)

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
	size_t _iChar;
	char _field[128];
	TokenId _tokenIdPending;
public:
	inline Tokenizer() : _stat(STAT_LineTop), _iChar(0), _tokenIdPending(TOKEN_None) {}
	TokenId Tokenize(Environment &env, Stream &stream);
	inline const char *GetField() const { return _field; }
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
	inline Vertex4(double _x, double _y, double _z, double _w) :
		Gura::VertexRef(_x, _y, _z), w(_w) {}
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
	Vertex4Owner _vs;
	Vertex3Owner _vps;
	Vertex3Owner _vns;
	Vertex3Owner _vts;
	FaceOwner _faces;
public:
	bool Read(Environment &env, Stream &stream);
private:
	static bool ExtractFloat(Environment &env, const char *field, double *pNum);
	static bool ExtractIndex(Environment &env, const char *field, int *pNum);
	static bool ExtractIndexPair(Environment &env, const char *field, int *piV, int *piVt);
	static bool ExtractIndexTriplet(Environment &env, const char *field, int *piV, int *piVt, int *piVn);
};

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_FormatError(Environment &env);

Gura_EndModuleHeader(model_obj)

#endif
