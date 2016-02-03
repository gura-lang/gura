//=============================================================================
// Gura module: model.stl
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(model_stl)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_FormatError(Environment &env)
{
	env.SetError(ERR_FormatError, "invalid format of STL file");
}

//-----------------------------------------------------------------------------
// Facet
//-----------------------------------------------------------------------------
Facet::Facet(const Facet &facet) : _normal(facet._normal), _attr(facet._attr)
{
	for (size_t i = 0; i < ArraySizeOf(_vertexes); i++) {
		_vertexes[i] = facet._vertexes[i];
	}
}

void Facet::UpdateNormal()
{
	_normal = Vertex::CalcNormal(_vertexes[0], _vertexes[1], _vertexes[2], true);
}

String Facet::ToString(const char *sep) const
{
	String str;
	char buff[80];
	str += _normal.ToString();
	for (size_t i = 0; i < ArraySizeOf(_vertexes); i++) {
		str += sep;
		str += _vertexes[i].ToString();
	}
	str += sep;
	::sprintf(buff, "%04x", _attr);
	str += buff;
	return str;
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

bool Object_facet::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_UserSymbol(normal));
	symbols.insert(Gura_UserSymbol(vertex1));
	symbols.insert(Gura_UserSymbol(vertex2));
	symbols.insert(Gura_UserSymbol(vertex3));
	return true;
}

Value Object_facet::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(normal))) {
		return Value(new Object_vertex(env, _facet.GetNormal()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(vertex1))) {
		return Value(new Object_vertex(env, _facet.GetVertex(0)));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(vertex2))) {
		return Value(new Object_vertex(env, _facet.GetVertex(1)));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(vertex3))) {
		return Value(new Object_vertex(env, _facet.GetVertex(2)));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(attr))) {
		return Value(_facet.GetAttr());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_facet::ToString(bool exprFlag)
{
	String str;
	str += "<model.stl.facet:";
	str += _facet.ToString(":");
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for facet
//-----------------------------------------------------------------------------

// implementation of class facet
Gura_ImplementUserClass(facet)
{
}

//-----------------------------------------------------------------------------
// Iterator_reader
//-----------------------------------------------------------------------------
Iterator_reader::Iterator_reader(Stream *pStream) :
	Iterator(false), _binaryFlag(false), _pStream(pStream),
	_idxFacet(0), _nFacet(0), _stat(STAT_facet)
{
}

Iterator_reader::~Iterator_reader()
{
}

Iterator *Iterator_reader::GetSource()
{
	return nullptr;
}

bool Iterator_reader::Prepare(Environment &env)
{
	Signal &sig = env.GetSignal();
	char buff[81];
	size_t bytesRead = _pStream->Read(sig, buff, 6);
	if (bytesRead < 6) {
		SetError_FormatError(env);
		return false;
	}
	if (::memcmp(buff, "solid ", 6) == 0) {
		String field;
		for (;;) {
			int chRaw = _pStream->GetChar(sig);
			if (sig.IsSignalled()) return false;
			char ch = (chRaw < 0)? '\0' : static_cast<char>(static_cast<UChar>(chRaw));
			if (ch == '\0' || ch == '\n') break;
			field += ch;
		}
		_text = Strip(field.c_str());
	} else {
		_binaryFlag = true;
		size_t bytesRead = _pStream->Read(sig, buff + 6, 80 - 6);
		buff[80] = '\0';
		if (bytesRead < 80 - 6) {
			SetError_FormatError(env);
			return false;
		}
		_text = buff;
		bytesRead = _pStream->Read(sig, buff, 4);
		if (bytesRead < 4) {
			SetError_FormatError(env);
			return false;
		}
		_nFacet = *reinterpret_cast<UInt *>(buff);
	}
	return true;
}

bool Iterator_reader::DoNext(Environment &env, Value &value)
{
	return _binaryFlag? DoNextFromBinary(env, value) : DoNextFromText(env, value);
}

bool Iterator_reader::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_UserSymbol(header));
	symbols.insert(Gura_UserSymbol(solidname));
	return true;
}

Value Iterator_reader::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(header))) {
		if (!_binaryFlag) return Value::Nil;
		return Value(_text);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(solidname))) {
		if (_binaryFlag) return Value::Nil;
		return Value(_text);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Iterator_reader::ToString() const
{
	String rtn;
	rtn += "<iterator:model.stl.reader";
	if (!_text.empty()) {
		rtn += ":";
		rtn += _text;
	}
	rtn += ">";
	return rtn;
}

void Iterator_reader::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

bool Iterator_reader::DoNextFromBinary(Environment &env, Value &value)
{
	if (_idxFacet >= _nFacet) return false;
	Signal &sig = env.GetSignal();
	FacetBin facetBin;
	size_t bytesRead = _pStream->Read(sig, &facetBin, FacetBin::Size);
	if (bytesRead < FacetBin::Size) {
		SetError_FormatError(env);
		return false;
	}
	AutoPtr<Object_facet> pObjFacet(new Object_facet());
	Facet &facet = pObjFacet->GetFacet();
	facet.SetVertex(0, Vertex(facetBin.vertex1[0], facetBin.vertex1[1], facetBin.vertex1[2]));
	facet.SetVertex(1, Vertex(facetBin.vertex2[0], facetBin.vertex2[1], facetBin.vertex2[2]));
	facet.SetVertex(2, Vertex(facetBin.vertex3[0], facetBin.vertex3[1], facetBin.vertex3[2]));
	facet.SetAttr(facetBin.attr);
	if (facetBin.normal[0] == 0. && facetBin.normal[1] == 0. && facetBin.normal[2] == 0.) {
		facet.UpdateNormal();
	} else {
		facet.SetNormal(Vertex(facetBin.normal[0], facetBin.normal[1], facetBin.normal[2]));
	}
	value = Value(pObjFacet.release());
	_idxFacet++;
	return true;
}

bool Iterator_reader::DoNextFromText(Environment &env, Value &value)
{
	size_t nCoords = 0;
	size_t nVertexes = 0;
	Vertex vertex;
	AutoPtr<Object_facet> pObjFacet;
	for (;;) {
		TokenId tokenId = _tokenizer.Tokenize(env, *_pStream);
		switch (_stat) {
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
				nCoords++;
				if (nCoords == 1) {
					vertex.x = num;
				} else if (nCoords == 2) {
					vertex.y = num;
				} else if (nCoords == 3) {
					vertex.z = num;
					Facet &facet = pObjFacet->GetFacet();
					facet.SetNormal(vertex);
					_stat = STAT_outer;
				}
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
				nCoords++;
				if (nCoords == 1) {
					vertex.x = num;
				} else if (nCoords == 2) {
					vertex.y = num;
				} else if (nCoords == 3) {
					vertex.z = num;
					Facet &facet = pObjFacet->GetFacet();
					facet.SetVertex(nVertexes, vertex);
					nVertexes++;
					if (nVertexes == 3) {
						if (facet.GetNormal().IsZero()) {
							facet.UpdateNormal();
						}
						_stat = STAT_endloop;
					} else {
						_stat = STAT_vertex;
					}
				}
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
					value = Value(pObjFacet.release());
					_idxFacet++;
					return true;
				} else {
					// error
				}
			}
			break;
		}
		}
		if (tokenId == TOKEN_EOF) break;
	}
	return false;
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// model.stl.reader(stream:stream) {block?}
Gura_DeclareFunction(reader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(reader)
{
	AutoPtr<Iterator_reader> pIterator(new Iterator_reader(arg.GetStream(0).Reference()));
	if (!pIterator->Prepare(env)) return Value::Nil;
	return ReturnIterator(env, arg, pIterator.release());
}

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
	// symbol realization
	Gura_RealizeUserSymbol(header);
	Gura_RealizeUserSymbol(solidname);
	Gura_RealizeUserSymbol(normal);
	Gura_RealizeUserSymbol(vertex1);
	Gura_RealizeUserSymbol(vertex2);
	Gura_RealizeUserSymbol(vertex3);
	Gura_RealizeUserSymbol(attr);
	// function assignment
	Gura_AssignFunction(reader);
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
