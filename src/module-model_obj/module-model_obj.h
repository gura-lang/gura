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
public:
	bool Read(Environment &env, Stream &stream);
private:
	static bool ExtractInteger(Environment &env, const char *field, int *pNum);
	static bool ExtractFloat(Environment &env, const char *field, double *pNum);
	static bool ExtractTriplet(Environment &env, const char *field, int *piV, int *piVt, int *piVn);
};

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_FormatError(Environment &env);

Gura_EndModuleHeader(model_obj)

#endif
