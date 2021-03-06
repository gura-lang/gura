//=============================================================================
// Gura module: model.stl
// Specification: https://en.wikipedia.org/wiki/STL_%28file_format%29
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(model_stl)

//-----------------------------------------------------------------------------
// Face
//-----------------------------------------------------------------------------
Face::Face() : _pNormal(nullptr), _attr(0)
{
	for (size_t i = 0; i < ArraySizeOf(_pVertexes); i++) {
		_pVertexes[i] = nullptr;
	}
}

Face::Face(const Face &face) : _pNormal(new VertexRef(face.GetNormal())), _attr(face._attr)
{
	for (size_t i = 0; i < ArraySizeOf(_pVertexes); i++) {
		_pVertexes[i] = new VertexRef(*face._pVertexes[i]);
	}
}

Face::~Face()
{
	for (size_t i = 0; i < ArraySizeOf(_pVertexes); i++) {
		VertexRef::Delete(_pVertexes[i]);
	}
}

void Face::UpdateNormal()
{
	Vertex vRtn;
	Vertex::Normal(vRtn, *_pVertexes[0], *_pVertexes[1], *_pVertexes[2], true);
	_pNormal.reset(new VertexRef(vRtn));
}

String Face::ToString(const char *sep) const
{
	String str;
	char buff[80];
	str += _pNormal->ToString();
	for (size_t i = 0; i < ArraySizeOf(_pVertexes); i++) {
		str += sep;
		str += _pVertexes[i]->ToString();
	}
	return str;
}

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
			} else {
				Gura_Pushback();
				_stat = STAT_Field;
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
				return TOKEN_EOL;
			} else if (ch == '\0') {
				_stat = STAT_LineTop;
				return TOKEN_EOF;
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
// Object_face
//-----------------------------------------------------------------------------
Object_face::Object_face() : Object(Gura_UserClass(face))
{
}

Object_face::Object_face(const Object_face &obj) :
	Object(Gura_UserClass(face)), _face(obj._face)
{
}

Object_face::~Object_face()
{
}

Object *Object_face::Clone() const
{
	return new Object_face(*this);
}

String Object_face::ToString(bool exprFlag)
{
	String str;
	str += "<model.stl.face:";
	str += _face.ToString(":");
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// model_stl.face#attr
Gura_DeclareProperty_R(face, attr)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(face, attr)
{
	const Face &face = Object_face::GetObject(valueThis)->GetFace();
	return Value(face.GetAttr());
}

// model_stl.face#normal
Gura_DeclareProperty_R(face, normal)
{
	SetPropAttr(VTYPE_vertex);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(face, normal)
{
	const Face &face = Object_face::GetObject(valueThis)->GetFace();
	return Value(new Object_vertex(env, face.GetNormal().Reference()));
}

// model_stl.face#vertex1
Gura_DeclareProperty_R(face, vertex1)
{
	SetPropAttr(VTYPE_vertex);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(face, vertex1)
{
	const Face &face = Object_face::GetObject(valueThis)->GetFace();
	return Value(new Object_vertex(env, face.GetVertex(0).Reference()));
}

// model_stl.face#vertex2
Gura_DeclareProperty_R(face, vertex2)
{
	SetPropAttr(VTYPE_vertex);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(face, vertex2)
{
	const Face &face = Object_face::GetObject(valueThis)->GetFace();
	return Value(new Object_vertex(env, face.GetVertex(1).Reference()));
}

// model_stl.face#vertex3
Gura_DeclareProperty_R(face, vertex3)
{
	SetPropAttr(VTYPE_vertex);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(face, vertex3)
{
	const Face &face = Object_face::GetObject(valueThis)->GetFace();
	return Value(new Object_vertex(env, face.GetVertex(2).Reference()));
}

//-----------------------------------------------------------------------------
// Gura interfaces for face
//-----------------------------------------------------------------------------
// implementation of class face
Gura_ImplementUserClass(face)
{
	// Assignment of properties
	Gura_AssignProperty(face, attr);
	Gura_AssignProperty(face, normal);
	Gura_AssignProperty(face, vertex1);
	Gura_AssignProperty(face, vertex2);
	Gura_AssignProperty(face, vertex3);
}

//-----------------------------------------------------------------------------
// Object_solid
//-----------------------------------------------------------------------------
Object_solid::Object_solid(Iterator_face *pIterator) :
	Object(Gura_UserClass(solid)), _pIterator(pIterator)
{
}

Object_solid::Object_solid(const Object_solid &obj) :
	Object(Gura_UserClass(solid)),
	_pIterator(dynamic_cast<Iterator_face *>(obj._pIterator->Reference()))
{
}

Object_solid::~Object_solid()
{
}

Object *Object_solid::Clone() const
{
	return new Object_solid(*this);
}

String Object_solid::ToString(bool exprFlag)
{
	String str;
	str += "<model.stl.solid";
	if (!_pIterator->GetText().empty()) {
		str += ":";
		str += _pIterator->GetText();
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// model_stl.solid#faces
Gura_DeclareProperty_R(solid, faces)
{
	SetPropAttr(VTYPE_iterator);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(solid, faces)
{
	Iterator_face *pIterator = Object_solid::GetObject(valueThis)->GetIterator();
	return Value(new Object_iterator(env, pIterator->Reference()));
}

// model_stl.solid#header
Gura_DeclareProperty_R(solid, header)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(solid, header)
{
	Iterator_face *pIterator = Object_solid::GetObject(valueThis)->GetIterator();
	if (!pIterator->GetBinaryFlag()) return Value::Nil;
	return Value(pIterator->GetText());
}

// model_stl.solid#name
Gura_DeclareProperty_R(solid, name)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(solid, name)
{
	Iterator_face *pIterator = Object_solid::GetObject(valueThis)->GetIterator();
	if (pIterator->GetBinaryFlag()) return Value::Nil;
	return Value(pIterator->GetText());
}

//-----------------------------------------------------------------------------
// Gura interfaces for solid
//-----------------------------------------------------------------------------
// implementation of class solid
Gura_ImplementUserClass(solid)
{
	// Assignment of properties
	Gura_AssignProperty(solid, faces);
	Gura_AssignProperty(solid, header);
	Gura_AssignProperty(solid, name);
}

//-----------------------------------------------------------------------------
// Iterator_face
//-----------------------------------------------------------------------------
Iterator_face::Iterator_face(Stream *pStream) :
	Iterator(Finite), _binaryFlag(false), _pStream(pStream),
	_idxFace(0), _nFace(0), _stat(STAT_facet)
{
}

Iterator_face::~Iterator_face()
{
}

Iterator *Iterator_face::GetSource()
{
	return nullptr;
}

bool Iterator_face::Prepare(Environment &env)
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
		_nFace = *reinterpret_cast<UInt32 *>(buff);
	}
	return true;
}

bool Iterator_face::DoNext(Environment &env, Value &value)
{
	return _binaryFlag? DoNextFromBinary(env, value) : DoNextFromText(env, value);
}

String Iterator_face::ToString() const
{
	String rtn;
	rtn += "<iterator:model.stl.face>";
	return rtn;
}

void Iterator_face::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

bool Iterator_face::DoNextFromBinary(Environment &env, Value &value)
{
	if (_idxFace >= _nFace) return false;
	Signal &sig = env.GetSignal();
	FaceBin faceBin;
	size_t bytesRead = _pStream->Read(sig, &faceBin, FaceBin::Size);
	if (bytesRead < FaceBin::Size) {
		SetError_FormatError(env);
		return false;
	}
	AutoPtr<Object_face> pObjFace(new Object_face());
	Face &face = pObjFace->GetFace();
	face.SetVertex(0, new VertexRef(faceBin.vertex1[0],
									 faceBin.vertex1[1], faceBin.vertex1[2]));
	face.SetVertex(1, new VertexRef(faceBin.vertex2[0],
									 faceBin.vertex2[1], faceBin.vertex2[2]));
	face.SetVertex(2, new VertexRef(faceBin.vertex3[0],
									 faceBin.vertex3[1], faceBin.vertex3[2]));
	face.SetAttr(faceBin.attr);
	if (faceBin.normal[0] == 0. && faceBin.normal[1] == 0. && faceBin.normal[2] == 0.) {
		face.UpdateNormal();
	} else {
		face.SetNormal(new VertexRef(faceBin.normal[0],
									  faceBin.normal[1], faceBin.normal[2]));
	}
	value = Value(pObjFace.release());
	_idxFace++;
	return true;
}

bool Iterator_face::DoNextFromText(Environment &env, Value &value)
{
	size_t nCoords = 0;
	size_t nVertexes = 0;
	Vertex vertex;
	AutoPtr<Object_face> pObjFace;
	for (;;) {
		TokenId tokenId = _tokenizer.Tokenize(env, *_pStream);
		if (env.IsSignalled()) return false;
		switch (_stat) {
		case STAT_facet: {
			if (tokenId == TOKEN_Field) {
				const char *field = _tokenizer.GetField();
				if (::strcmp(field, "facet") == 0) {
					pObjFace.reset(new Object_face());
					_stat = STAT_normal;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_normal: {
			if (tokenId == TOKEN_Field) {
				const char *field = _tokenizer.GetField();
				if (::strcmp(field, "normal") == 0) {
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
				const char *field = _tokenizer.GetField();
				double num = 0;
				char *p = nullptr;
				num = ::strtod(field, &p);
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
					Face &face = pObjFace->GetFace();
					face.SetNormal(new VertexRef(vertex));
					_stat = STAT_outer;
				}
			}
			break;
		}
		case STAT_outer: {
			if (tokenId == TOKEN_Field) {
				const char *field = _tokenizer.GetField();
				if (::strcmp(field, "outer") == 0) {
					_stat = STAT_loop;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_loop: {
			if (tokenId == TOKEN_Field) {
				const char *field = _tokenizer.GetField();
				if (::strcmp(field, "loop") == 0) {
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
				const char *field = _tokenizer.GetField();
				if (::strcmp(field, "vertex") == 0) {
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
				const char *field = _tokenizer.GetField();
				double num = 0;
				char *p = nullptr;
				num = ::strtod(field, &p);
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
					Face &face = pObjFace->GetFace();
					face.SetVertex(nVertexes, new VertexRef(vertex));
					nVertexes++;
					if (nVertexes == 3) {
						if (face.GetNormal().IsZero()) {
							face.UpdateNormal();
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
				const char *field = _tokenizer.GetField();
				if (::strcmp(field, "endloop") == 0) {
					_stat = STAT_endfacet;
				} else {
					// error
				}
			}
			break;
		}
		case STAT_endfacet: {
			if (tokenId == TOKEN_Field) {
				const char *field = _tokenizer.GetField();
				if (::strcmp(field, "endfacet") == 0) {
					_stat = STAT_facet;
					value = Value(pObjFace.release());
					_idxFace++;
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
// model.stl.solid(stream:stream) {block?}
Gura_DeclareFunction(solid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(solid));
	AddHelp(
		Gura_Symbol(en),
		"Parses a file in STL format from `stream` and creates an instance of `model.stl.solid`\n"
		"that contains an iterator of `model.stl.face` representing faces in the STL.\n"
		"It can read both binary and ASCII format of STL.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("solid", "model.stl.solid"));
}

Gura_ImplementFunction(solid)
{
	AutoPtr<Iterator_face> pIterator(new Iterator_face(arg.GetStream(0).Reference()));
	if (!pIterator->Prepare(env)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_solid(pIterator.release())));
}

// model.stl.test(stream:stream)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en),
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
	Gura_RealizeUserSymbol(name);
	Gura_RealizeUserSymbol(faces);
	Gura_RealizeUserSymbol(normal);
	Gura_RealizeUserSymbol(vertex1);
	Gura_RealizeUserSymbol(vertex2);
	Gura_RealizeUserSymbol(vertex3);
	Gura_RealizeUserSymbol(attr);
	// class realization
	Gura_RealizeUserClass(face, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(solid, env.LookupClass(VTYPE_object));
	Gura_PrepareUserClass(face);
	Gura_PrepareUserClass(solid);
	// class reference assignment
	Gura_AssignValue(face, Value(Gura_UserClass(face)->Reference()));
	// function assignment
	Gura_AssignFunction(solid);
	//Gura_AssignFunction(test);
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
	env.SetError(ERR_FormatError, "invalid format of STL file");
}

Gura_EndModuleBody(model_stl, stl)

Gura_RegisterModule(model_stl)
