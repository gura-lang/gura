//=============================================================================
// Gura module: model.stl
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(model_stl)
//-----------------------------------------------------------------------------
// Facet
//-----------------------------------------------------------------------------
Facet::Facet(const Facet &facet) : _normal(facet._normal)
{
	for (size_t i = 0; i < ArraySizeOf(_vertexes); i++) {
		_vertexes[i] = facet._vertexes[i];
	}
}

String Facet::ToString() const
{
	String str;
	str += _normal.ToString();
	for (size_t i = 0; i < ArraySizeOf(_vertexes); i++) {
		str += ";";
		str += _vertexes[i].ToString();
	}
	return str;
}

//-----------------------------------------------------------------------------
// Object_facet
//-----------------------------------------------------------------------------
Object_facet::Object_facet() : Object(Gura_UserClass(facet))
{
}

Object_facet::Object_facet(const Object_facet &obj) :
	Object(Gura_UserClass(facet)), _facet(obj._facet)
{
}

Object_facet::~Object_facet()
{
}

Object *Object_facet::Clone() const
{
	return new Object_facet(*this);
}

String Object_facet::ToString(bool exprFlag)
{
	return String("<model.stl.facet>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for facet
//-----------------------------------------------------------------------------

// implementation of class facet
Gura_ImplementUserClass(facet)
{
}

//-----------------------------------------------------------------------------
// Iterator_facet
//-----------------------------------------------------------------------------
Iterator_facet::Iterator_facet(Stream *pStream) : Iterator(false), _pStream(pStream)
{
}

Iterator_facet::~Iterator_facet()
{
}

Iterator *Iterator_facet::GetSource()
{
	return nullptr;
}

bool Iterator_facet::DoNext(Environment &env, Value &value)
{
	return false;
}

String Iterator_facet::ToString() const
{
	String rtn;
	rtn += "<iterator:model.stl.facet";
	rtn += ">";
	return rtn;
}

void Iterator_facet::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Tokenizer
//-----------------------------------------------------------------------------
TokenId Tokenizer::Tokenize(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	_field.clear();
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
		case STAT_FileTop: {
			if (ch == 's') {
				Gura_Pushback();
				_stat = STAT_Field;
			}
			break;
		}
		case STAT_FileEnd: {
			// nothing to do
			break;
		}
		case STAT_LineTop: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '\n' || ch == '\0') {
				// nothing to do
			} else {
				Gura_Pushback();
				_stat = STAT_Field;
			}
			break;
		}
		case STAT_Field: {
			if (ch == ' ' || ch == '\t') {
				_stat = STAT_SkipWhite;
				return TOKEN_Field;
			} else if (ch == '\n') {
				_tokenIdPending = TOKEN_EOL;
				_stat = STAT_LineTop;
				return TOKEN_Field;
			} else if (ch == '\0') {
				_tokenIdPending = TOKEN_EOF;
				_stat = STAT_FileEnd;
				return TOKEN_Field;
			} else {
				_field += ch;
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
		}
		Gura_EndPushbackRegion();
		if (ch == '\0') break;
	}
	return TOKEN_EOF;
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// model.stl.test(stream:stream)
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
		STAT_solid, STAT_solid_name, STAT_solid_EOL,
		STAT_facet, STAT_normal, STAT_normal_coords,
		STAT_outer, STAT_loop,
		STAT_vertex, STAT_vertex_coords,
		STAT_endloop,
		STAT_endfacet,
	} _stat = STAT_solid;
	size_t nCoords = 0;
	size_t nVertexes = 0;
	Vertex vertex;
	Tokenizer _tokenizer;
	Stream &stream = arg.GetStream(0);
	AutoPtr<Object_facet> pObjFacet;
	for (;;) {
		TokenId tokenId = _tokenizer.Tokenize(env, stream);
		switch (_stat) {
		case STAT_solid: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				if (field == "solid") {
					_stat = STAT_solid_name;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_solid_name: {
			if (tokenId == TOKEN_EOL) {
				_stat = STAT_facet;
			} else if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				_stat = STAT_solid_EOL;
			}
			break;
		}
		case STAT_solid_EOL: {
			if (tokenId == TOKEN_EOL) {
				_stat = STAT_facet;
			}
			break;
		}
		case STAT_facet: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				if (field == "facet") {
					pObjFacet.reset(new Object_facet());
					_stat = STAT_normal;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_normal: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				if (field == "normal") {
					nCoords = 0;
					_stat = STAT_normal_coords;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_normal_coords: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				double num = 0;
				char *p = nullptr;
				num = ::strtod(field.c_str(), &p);
				if (*p != '\0') {
					// error
				}
				if (nCoords == 0) {
					vertex.x = num;
				} else if (nCoords == 1) {
					vertex.y = num;
				} else if (nCoords == 2) {
					Facet &facet = pObjFacet->GetFacet();
					vertex.z = num;
					facet.SetNormal(vertex);
					_stat = STAT_outer;
				}
				nCoords++;
			}
			break;
		}
		case STAT_outer: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				if (field == "outer") {
					_stat = STAT_loop;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_loop: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				if (field == "loop") {
					nVertexes = 0;
					_stat = STAT_vertex;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_vertex: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				if (field == "vertex") {
					nCoords = 0;
					_stat = STAT_vertex_coords;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_vertex_coords: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				double num = 0;
				char *p = nullptr;
				num = ::strtod(field.c_str(), &p);
				if (*p != '\0') {
					// error
				}
				if (nCoords == 0) {
					vertex.x = num;
				} else if (nCoords == 1) {
					vertex.y = num;
				} else if (nCoords == 2) {
					Facet &facet = pObjFacet->GetFacet();
					vertex.z = num;
					nCoords = 0;
					facet.SetVertex(nVertexes, vertex);
					if (nVertexes == 2) {
						::printf("%s\n", facet.ToString().c_str());
						// completed facet
						_stat = STAT_endloop;
					}
					nVertexes++;
				}
				nCoords++;
			}
			break;
		}
		case STAT_endloop: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				if (field == "endloop") {
					_stat = STAT_endfacet;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_endfacet: {
			if (tokenId == TOKEN_Field) {
				const String &field = _tokenizer.GetField();
				if (field == "endfacet") {
					_stat = STAT_facet;
				} else {
					// error
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
	// class realization
	Gura_RealizeUserClass(facet, env.LookupClass(VTYPE_object));
	Gura_PrepareUserClass(facet);
	// class reference assignment
	Gura_AssignValue(facet, Value(Gura_UserClass(facet)->Reference()));
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(model_stl, stl)

Gura_RegisterModule(model_stl)
