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
	bool escapeFlag = false;
	for (;;) {
		int chRaw = stream.GetChar(sig);
		if (sig.IsSignalled()) break;
		char ch = (chRaw < 0)? '\0' : static_cast<char>(static_cast<UChar>(chRaw));
		if (ch == '\\' && !escapeFlag) {
			escapeFlag = true;
			continue;
		}
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
				if (escapeFlag) {
					// nothing to do
				} else {
					_stat = STAT_LineTop;
				}
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
				if (escapeFlag) {
					_stat = STAT_SkipWhite;
				} else {
					_tokenIdPending = TOKEN_EOL;
					_stat = STAT_LineTop;
				}
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
				if (escapeFlag) {
					// nothing to do
				} else {
					_stat = STAT_LineTop;
				}
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
		escapeFlag = false;
		if (ch == '\0') break;
	}
	return TOKEN_EOF;
}

//-----------------------------------------------------------------------------
// FaceOwner
//-----------------------------------------------------------------------------
FaceOwner::~FaceOwner()
{
	Clear();
}

void FaceOwner::Clear()
{
	foreach (FaceOwner, ppFace, *this) {
		Face::Delete(*ppFace);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Content
//-----------------------------------------------------------------------------
bool Content::Read(Environment &env, Stream &stream)
{
	Stat stat = STAT_Keyword;
	size_t iParam = 0;
	Tokenizer tokenizer;
	double numTbl[32];
	for (;;) {
		TokenId tokenId = tokenizer.Tokenize(env, stream);
		const char *field = tokenizer.GetField();
		switch (stat) {
		case STAT_Keyword: {
			if (tokenId == TOKEN_Field) {
				::printf("%s\n", field);
				iParam = 0;
				if (::strcmp(field, "call") == 0) {
					stat = STAT_call;
				} else if (::strcmp(field, "csh") == 0) {
					stat = STAT_csh;
				} else if (::strcmp(field, "v") == 0) {
					stat = STAT_v;
				} else if (::strcmp(field, "vt") == 0) {
					stat = STAT_vt;
				} else if (::strcmp(field, "vn") == 0) {
					stat = STAT_vn;
				} else if (::strcmp(field, "vp") == 0) {
					stat = STAT_vp;
				} else if (::strcmp(field, "cstype") == 0) {
					stat = STAT_cstype;
				} else if (::strcmp(field, "deg") == 0) {
					stat = STAT_deg;
				} else if (::strcmp(field, "bmat") == 0) {
					stat = STAT_bmat;
				} else if (::strcmp(field, "step") == 0) {
					stat = STAT_step;
				} else if (::strcmp(field, "p") == 0) {
					stat = STAT_p;
				} else if (::strcmp(field, "l") == 0) {
					stat = STAT_l;
				} else if (::strcmp(field, "f") == 0) {
					_faceOwner.push_back(new Face());
					stat = STAT_f;
				} else if (::strcmp(field, "curv") == 0) {
					stat = STAT_curv;
				} else if (::strcmp(field, "curv2") == 0) {
					stat = STAT_curv2;
				} else if (::strcmp(field, "surf") == 0) {
					stat = STAT_surf;
				} else if (::strcmp(field, "parm") == 0) {
					stat = STAT_parm;
				} else if (::strcmp(field, "trim") == 0) {
					stat = STAT_trim;
				} else if (::strcmp(field, "hole") == 0) {
					stat = STAT_hole;
				} else if (::strcmp(field, "scrv") == 0) {
					stat = STAT_scrv;
				} else if (::strcmp(field, "sp") == 0) {
					stat = STAT_sp;
				} else if (::strcmp(field, "end") == 0) {
					stat = STAT_end;
				} else if (::strcmp(field, "con") == 0) {
					stat = STAT_con;
				} else if (::strcmp(field, "g") == 0) {
					stat = STAT_g;
				} else if (::strcmp(field, "s") == 0) {
					stat = STAT_s;
				} else if (::strcmp(field, "mg") == 0) {
					stat = STAT_mg;
				} else if (::strcmp(field, "o") == 0) {
					stat = STAT_o;
				} else if (::strcmp(field, "bevel") == 0) {
					stat = STAT_beval;
				} else if (::strcmp(field, "c_interp") == 0) {
					stat = STAT_c_interp;
				} else if (::strcmp(field, "d_interp") == 0) {
					stat = STAT_d_interp;
				} else if (::strcmp(field, "lod") == 0) {
					stat = STAT_lod;
				} else if (::strcmp(field, "usemap") == 0) {
					stat = STAT_usemap;
				} else if (::strcmp(field, "maplib") == 0) {
					stat = STAT_maplib;
				} else if (::strcmp(field, "usemtl") == 0) {
					stat = STAT_usemtl;
				} else if (::strcmp(field, "mtllib") == 0) {
					stat = STAT_mtllib;
				} else if (::strcmp(field, "shadow_obj") == 0) {
					stat = STAT_shadow_obj;
				} else if (::strcmp(field, "trace_obj") == 0) {
					stat = STAT_trace_obj;
				} else if (::strcmp(field, "ctech") == 0) {
					stat = STAT_ctech;
				} else if (::strcmp(field, "stech") == 0) {
					stat = STAT_stech;
				} else {
					env.SetError(ERR_FormatError, "unknown keyword '%s'", field);
					return false;
				}
			}
			break;
		}
		//----------------------------------------------------------------------
		// General statement
		case STAT_call: {
			// reads another obj file: call filename.ext arg1 arg2 ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_csh: {
			// executed UNIX command: csh command|-command
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		//----------------------------------------------------------------------
		// Vertex data
		case STAT_v: {
			// geometric vertices: v x y z [w]
			if (tokenId == TOKEN_EOL) {
				// complete
				
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				if (iParam >= 4) {
					env.SetError(ERR_FormatError, "too many elements for vt");
					return false;
				}
				double num;
				if (!ExtractFloat(env, field, &num)) {
					SetError_FormatError(env);
					return false;
				}
				numTbl[iParam++] = num;
			}
			break;
		}
		case STAT_vt: {
			// texture vertices: vt u [v] [w]
			if (tokenId == TOKEN_EOL) {
				// complete
				
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				if (iParam >= 3) {
					env.SetError(ERR_FormatError, "too many elements for vt");
					return false;
				}
				double num;
				if (!ExtractFloat(env, field, &num)) {
					SetError_FormatError(env);
					return false;
				}
				numTbl[iParam++] = num;
			}
			break;
		}
		case STAT_vn: {
			// vertex normals: vn i j k
			if (tokenId == TOKEN_EOL) {
				// complete
				
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				if (iParam >= 3) {
					env.SetError(ERR_FormatError, "too many elements for vn");
					return false;
				}
				double num;
				if (!ExtractFloat(env, field, &num)) {
					SetError_FormatError(env);
					return false;
				}
				numTbl[iParam++] = num;
			}
			break;
		}
		case STAT_vp: {
			// parameter space vertices: vp u v [w]
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		//----------------------------------------------------------------------
		// Free-form curve/surface attributes
		case STAT_cstype: {
			// curve or surface type: cstype [rat] type
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_deg: {
			// degree: deg degu [degv]
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_bmat: {
			// basic matrix: bmat u|v matrix
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_step: {
			// step size: step stepu [stepv]
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		//----------------------------------------------------------------------
		// Elements
		case STAT_p: {
			// point: p v1 v2 v3 ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				int iV;
				if (!ExtractIndex(env, field, &iV)) {
					return false;
				} else if (iV <= 0) {
					env.SetError(ERR_FormatError, "invalid index for vertex");
					return false;
				}
				iParam++;
			}
			break;
		}
		case STAT_l: {
			// line: l v1/vt1 v2/vt2 v3/vt3 ...
			if (tokenId == TOKEN_EOL) {
				// complete
				
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				int iV, iVt;
				if (!ExtractIndexPair(env, field, &iV, &iVt)) {
					return false;
				} else if (iV <= 0) {
					env.SetError(ERR_FormatError, "invalid index for vertex");
					return false;
				}
				iParam++;
			}
			break;
		}
		case STAT_f: {
			// face: f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3 ...
			if (tokenId == TOKEN_EOL) {
				// complete
				if (iParam < 3) {
					env.SetError(ERR_FormatError, "at least three index triplets must exist");
					return false;
				}
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				Face *pFace = _faceOwner.back();
				int iV, iVt, iVn;
				if (!ExtractIndexTriplet(env, field, &iV, &iVt, &iVn)) {
					return false;
				} else if (iV <= 0) {
					env.SetError(ERR_FormatError, "invalid index for vertex");
					return false;
				}
				pFace->AddIndexTriplet(iV, iVt, iVn);
				iParam++;
			}
			break;
		}
		case STAT_curv: {
			// curve: curv u0 u1 v1 v2 ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_curv2: {
			// 2D curve: curv2 vp1 vp2 vp3 ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_surf: {
			// surface: surf s0 s1 t0 t1 v1/vt1/vn1 v2/vt2/vn2 ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		//----------------------------------------------------------------------
		// Parameter values and knot vectors
		case STAT_parm: {
			// parameter values: parm u|v p1 p2 p3 ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_trim: {
			// outer trimming loop: trim u0 u1 curv2d u0 u1 curv2d ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_hole: {
			// inner trimming loop: u0 u1 curv2d u0 u1 curv2d ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_scrv: {
			// special curve: u0 u1 curv2d u0 u1 curv2d ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_sp: {
			// special point: vp1 vp ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_end: {
			// end statement: end
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		//----------------------------------------------------------------------
		// Connectivity between free-form surfaces
		case STAT_con: {
			// connect: con surf_1 q0_1 q1_1 curv2d_1 surf_2 q0_2 q1_2 curv2d_2
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		//----------------------------------------------------------------------
		// Grouping
		case STAT_g: {
			// group name: g group_name1 group_name2 ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_s: {
			// smoothing group: s group_number
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_mg: {
			// merging group: mg group_number res
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_o: {
			// object name: o object_name
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		//----------------------------------------------------------------------
		// Display/render attributes
		case STAT_beval: {
			// bevel interpolation: bevel on|off
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_c_interp: {
			// color interpolation: c_interp on|off
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_d_interp: {
			// dissolve interpolation: d_interp on|off
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_lod: {
			// level of detail: lod level
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_usemap: {
			// map name: usemap map_name|off
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_maplib: {
			// map library: maplib filename1 filename2 ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_usemtl: {
			// material name: usemtl material_name
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_mtllib: {
			// material library: mtllib filename1 filename2 ...
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_shadow_obj: {
			// shadow casting: shadow_obj filename
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_trace_obj: {
			// ray tracing: trace_obj filename
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_ctech: {
			// curve approximation technique: ctech technique resolution
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		case STAT_stech: {
			// surface approximation technique: stech technique resolution
			if (tokenId == TOKEN_EOL) {
				stat = STAT_Keyword;
			} else if (tokenId == TOKEN_Field) {
				iParam++;
			}
			break;
		}
		}
		if (tokenId == TOKEN_EOF) break;
	}

}

bool Content::ExtractFloat(Environment &env, const char *field, double *pNum)
{
	char *p = nullptr;
	*pNum = ::strtod(field, &p);
	if (*p == '\0') return true;
	env.SetError(ERR_FormatError, "invalid format of float number");
	return false;
}

bool Content::ExtractIndex(Environment &env, const char *field, int *piV)
{
	const char *errMsg = "invalid format of vertex index";
	char *p = nullptr;
	*piV = static_cast<int>(::strtol(field, &p, 10));
	if (*p != '\0') {
		env.SetError(ERR_FormatError, errMsg);
		return false;
	}
	if (*piV < 0) {
		env.SetError(ERR_FormatError, errMsg);
	}
	return true;
}

bool Content::ExtractIndexPair(Environment &env, const char *field, int *piV, int *piVt)
{
	const char *errMsg = "invalid format of vertex index pair";
	*piV = *piVt = 0;
	char *p = const_cast<char *>(field);
	if (*p == '/') {
		*piV = 0;
		p++;
	} else if (IsDigit(*p)) {
		*piV = static_cast<int>(::strtol(p, &p, 10));
		if (*p == '/') p++;
	} else {
		env.SetError(ERR_FormatError, errMsg);
		return false;
	}
	if (*p == '\0') {
		return true;
	} else if (*p == '/') {
		p++;
	} else if (IsDigit(*p)) {
		*piVt = static_cast<int>(::strtol(p, &p, 10));
	} else {
		env.SetError(ERR_FormatError, errMsg);
		return false;
	}
	if (*p != '\0') {
		env.SetError(ERR_FormatError, errMsg);
		return false;
	}
	if (*piV < 0 || *piVt < 0) {
		env.SetError(ERR_FormatError, errMsg);
	}
	return true;
}

bool Content::ExtractIndexTriplet(Environment &env, const char *field, int *piV, int *piVt, int *piVn)
{
	const char *errMsg = "invalid format of vertex index triplet";
	*piV = *piVt = *piVn = 0;
	char *p = const_cast<char *>(field);
	if (*p == '/') {
		*piV = 0;
		p++;
	} else if (IsDigit(*p)) {
		*piV = static_cast<int>(::strtol(p, &p, 10));
		if (*p == '/') p++;
	} else {
		env.SetError(ERR_FormatError, errMsg);
		return false;
	}
	if (*p == '\0') {
		return true;
	} else if (*p == '/') {
		p++;
	} else if (IsDigit(*p)) {
		*piVt = static_cast<int>(::strtol(p, &p, 10));
		if (*p == '/') p++;
	} else {
		env.SetError(ERR_FormatError, errMsg);
		return false;
	}
	if (*p == '\0') {
		return true;
	} else if (*p == '/') {
		p++;
	} else if (IsDigit(*p)) {
		*piVn = static_cast<int>(::strtol(p, &p, 10));
	} else {
		env.SetError(ERR_FormatError, errMsg);
		return false;
	}
	if (*p != '\0') {
		env.SetError(ERR_FormatError, errMsg);
		return false;
	}
	if (*piV < 0 || *piVt < 0 || *piVn < 0) {
		env.SetError(ERR_FormatError, errMsg);
	}
	return true;
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
	Content content;
	content.Read(env, arg.GetStream(0));
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
