//=============================================================================
// Gura module: model.obj
// Specification: http://www.martinreddy.net/gfx/3d/OBJ.spec
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(model_obj)

//-----------------------------------------------------------------------------
// Tokenizer
//-----------------------------------------------------------------------------
TokenId Tokenizer::Tokenize(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	_iChar = 0;
	if (_tokenIdPending != TOKEN_None) {
		TokenId tokenId = _tokenIdPending;
		_tokenIdPending = TOKEN_None;
		return tokenId;
	}
	for (;;) {
		int chRaw = stream.GetChar(sig);
		if (sig.IsSignalled()) break;
		char ch = (chRaw < 0)? '\0' : static_cast<char>(static_cast<UChar>(chRaw));
		Gura_BeginPushbackRegion();
		switch (_stat) {
		case STAT_LineTop: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '\n' || ch == '\0') {
				// nothing to do
			} else if (ch == '#') {
				_stat = STAT_SkipToNextLine;
			} else {
				Gura_Pushback();
				_stat = STAT_Field;
			}
			break;
		}
		case STAT_SkipToNextLine: {
			if (ch == '\n') {
				_stat = STAT_LineTop;
			} else {
				// nothing to do
			}
			break;
		}
		case STAT_Field: {
			if (ch == ' ' || ch == '\t') {
				_stat = STAT_SkipWhite;
				_field[_iChar] = '\0';
				return TOKEN_Field;
			} else if (ch == '\n') {
				_tokenIdPending = TOKEN_EOL;
				_stat = STAT_LineTop;
				_field[_iChar] = '\0';
				return TOKEN_Field;
			} else if (ch == '\0') {
				_tokenIdPending = TOKEN_EOF;
				_stat = STAT_FileEnd;
				_field[_iChar] = '\0';
				return TOKEN_Field;
			} else {
				_field[_iChar++] = ch;
				if (_iChar >= ArraySizeOf(_field)) {
					SetError_FormatError(env);
					return TOKEN_EOF;
				}
			}
			break;
		}
		case STAT_SkipWhite: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '\n') {
				_stat = STAT_LineTop;
			} else if (ch == '\0') {
				_stat = STAT_LineTop;
			} else {
				Gura_Pushback();
				_stat = STAT_Field;
			}
			break;
		}
		case STAT_FileEnd: {
			// nothing to do
			break;
		}
		}
		Gura_EndPushbackRegion();
		if (ch == '\0') break;
	}
	return TOKEN_EOF;
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// model.obj.test(stream:stream)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(test)
{
	enum {
		STAT_keyword,
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
	} stat = STAT_keyword;
	Stream &stream = arg.GetStream(0);
	Tokenizer tokenizer;
	for (;;) {
		TokenId tokenId = tokenizer.Tokenize(env, stream);
		switch (stat) {
		case STAT_keyword: {
			if (tokenId == TOKEN_Field) {
				const char *field = tokenizer.GetField();
				::printf("%s\n", field);
				if (::strcmp(field, "v") == 0) {
					// geometric vertices: v x y z [w]
					stat = STAT_v;
				} else if (::strcmp(field, "vt") == 0) {
					// texture vertices: vt u [v] [w]
					stat = STAT_vt;
				} else if (::strcmp(field, "vn") == 0) {
					// vertex normals: vn i j k
					stat = STAT_vn;
				} else if (::strcmp(field, "vp") == 0) {
					// parameter space vertices: vp u v [w]
					stat = STAT_vp;
				} else if (::strcmp(field, "cstype") == 0) {
					// curve or surface type: cstype [rat] type
					stat = STAT_cstype;
				} else if (::strcmp(field, "deg") == 0) {
					// degree: deg degu [degv]
					stat = STAT_deg;
				} else if (::strcmp(field, "bmat") == 0) {
					// basic matrix: bmat u|v matrix
					stat = STAT_bmat;
				} else if (::strcmp(field, "step") == 0) {
					// step size: step stepu [stepv]
					stat = STAT_step;
				} else if (::strcmp(field, "p") == 0) {
					// point: p v1 v2 v3 ...
					stat = STAT_p;
				} else if (::strcmp(field, "l") == 0) {
					// line: l v1/vt1 v2/vt2 v3/vt3 ...
					stat = STAT_l;
				} else if (::strcmp(field, "f") == 0) {
					// face: f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3 ...
					stat = STAT_f;
				} else if (::strcmp(field, "curv") == 0) {
					// curve: curv u0 u1 v1 v2 ...
					stat = STAT_curv;
				} else if (::strcmp(field, "curv2") == 0) {
					// 2D curve: curv2 vp1 vp2 vp3 ...
					stat = STAT_curv2;
				} else if (::strcmp(field, "surf") == 0) {
					// surface: surf s0 s1 t0 t1 v1/vt1/vn1 v2/vt2/vn2 ...
					stat = STAT_surf;
				} else if (::strcmp(field, "parm") == 0) {
					// parameter values: parm u|v p1 p2 p3 ...
					stat = STAT_parm;
				} else if (::strcmp(field, "trim") == 0) {
					// outer trimming loop: trim u0 u1 curv2d u0 u1 curv2d ...
					stat = STAT_trim;
				} else if (::strcmp(field, "hole") == 0) {
					// inner trimming loop: u0 u1 curv2d u0 u1 curv2d ...
					stat = STAT_hole;
				} else if (::strcmp(field, "scrv") == 0) {
					// special curve: u0 u1 curv2d u0 u1 curv2d ...
					stat = STAT_scrv;
				} else if (::strcmp(field, "sp") == 0) {
					// special point: vp1 vp ...
					stat = STAT_sp;
				} else if (::strcmp(field, "end") == 0) {
					// end statement: end
					stat = STAT_end;
				} else if (::strcmp(field, "con") == 0) {
					// connect: con surf_1 q0_1 q1_1 curv2d_1 surf_2 q0_2 q1_2 curv2d_2
					stat = STAT_con;
				} else if (::strcmp(field, "g") == 0) {
					// group name: g group_name1 group_name2 ...
					stat = STAT_g;
				} else if (::strcmp(field, "s") == 0) {
					// smoothing group: s group_number
					stat = STAT_s;
				} else if (::strcmp(field, "mg") == 0) {
					// merging group: mg group_number res
					stat = STAT_mg;
				} else if (::strcmp(field, "o") == 0) {
					// object name: o object_name
					stat = STAT_o;
				} else if (::strcmp(field, "bevel") == 0) {
					// bevel interpolation: bevel on|off
					stat = STAT_beval;
				} else if (::strcmp(field, "c_interp") == 0) {
					// color interpolation: c_interp on|off
					stat = STAT_c_interp;
				} else if (::strcmp(field, "d_interp") == 0) {
					// dissolve interpolation: d_interp on|off
					stat = STAT_d_interp;
				} else if (::strcmp(field, "lod") == 0) {
					// level of detail: lod level
					stat = STAT_lod;
				} else if (::strcmp(field, "usemap") == 0) {
					// map name: usemap map_name|off
					stat = STAT_usemap;
				} else if (::strcmp(field, "maplib") == 0) {
					// material library: maplib filename1 filename2 ...
					stat = STAT_maplib;
				} else if (::strcmp(field, "usemtl") == 0) {
					// material name: usemtl material_name
					stat = STAT_usemtl;
				} else if (::strcmp(field, "mtllib") == 0) {
					// material library: mtllib filename1 filename2 ...
					stat = STAT_mtllib;
				} else if (::strcmp(field, "shadow_obj") == 0) {
					// shadow casting: shadow_obj filename
					stat = STAT_shadow_obj;
				} else if (::strcmp(field, "trace_obj") == 0) {
					// ray tracing: trace_obj filename
					stat = STAT_trace_obj;
				} else if (::strcmp(field, "ctech") == 0) {
					// curve approximation technique: ctech technique resolution
					stat = STAT_ctech;
				} else if (::strcmp(field, "stech") == 0) {
					// surface approximation technique: stech technique resolution
					stat = STAT_stech;
				}
			}
			break;
		}
		}
		if (tokenId == TOKEN_EOF) break;
	}
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_FormatError(Environment &env)
{
	env.SetError(ERR_FormatError, "invalid format of OBJ file");
}

Gura_EndModuleBody(model_obj, obj)

Gura_RegisterModule(model_obj)
