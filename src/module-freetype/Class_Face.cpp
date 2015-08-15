#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Face implementation
//-----------------------------------------------------------------------------
Object_Face::~Object_Face()
{
	::FT_Done_Face(_face);
}

Object *Object_Face::Clone() const
{
	return nullptr;
}

String Object_Face::ToString(bool exprFlag)
{
	String str;
	str = "<freetype.Face";
	str += ":";
	str += _face->family_name;
	if (_face->style_name != nullptr) {
		str += ":";
		str += _face->style_name;
	}
	str += ":#";
	str += NumberToString(_face->face_index);
	str += ":";
	str += NumberToString(_face->num_faces);
	str += "faces";
	str += ">";
	return str;
}

bool Object_Face::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(num_faces));
	symbols.insert(Gura_UserSymbol(face_index));
	symbols.insert(Gura_UserSymbol(family_name));
	symbols.insert(Gura_UserSymbol(style_name));
	symbols.insert(Gura_UserSymbol(bbox));
	symbols.insert(Gura_UserSymbol(ascender));
	symbols.insert(Gura_UserSymbol(descender));
	symbols.insert(Gura_UserSymbol(height));
	symbols.insert(Gura_UserSymbol(max_advance_width));
	symbols.insert(Gura_UserSymbol(max_advance_height));
	symbols.insert(Gura_UserSymbol(underline_position));
	symbols.insert(Gura_UserSymbol(underline_thickness));
	symbols.insert(Gura_UserSymbol(glyph));
	symbols.insert(Gura_UserSymbol(size));
	symbols.insert(Gura_UserSymbol(charmap));
	return true;
}

Value Object_Face::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	double y_ppem = _face->size->metrics.y_ppem;// pixels/EM
	double units_per_EM = _face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (pSymbol->IsIdentical(Gura_UserSymbol(num_faces))) {
		return Value(_face->num_faces);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_index))) {
		return Value(_face->face_index);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(face_flags))) {
		return Value(_face->face_flags);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(style_flags))) {
		return Value(_face->style_flags);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(num_glyphs))) {
		return Value(_face->num_glyphs);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(family_name))) {
		if (_face->family_name == nullptr) return Value::Nil;
		return Value(_face->family_name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(style_name))) {
		if (_face->style_name == nullptr) return Value::Nil;
		return Value(_face->style_name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(num_fixed_sizes))) {
		return Value(_face->num_fixed_sizes);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(available_sizes))) {
		//_face->num_fixed_sizes
		//_face->available_sizes
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(num_charmaps))) {
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(charmaps))) {
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(generic))) {
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(bbox))) {
		return Value::CreateList(env,
				Value(_face->bbox.xMin), Value(_face->bbox.yMin),
				Value(_face->bbox.xMax), Value(_face->bbox.yMax)); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(units_per_EM))) {
		return Value(_face->units_per_EM);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ascender))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->ascender * y_ppem / units_per_EM);
		}
		return Value(_face->ascender); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(descender))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->descender * y_ppem / units_per_EM);
		}
		return Value(_face->descender); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->height * y_ppem / units_per_EM);
		}
		return Value(_face->height); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(max_advance_width))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->max_advance_width * y_ppem / units_per_EM);
		}
		return Value(_face->max_advance_width); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(max_advance_height))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->max_advance_height * y_ppem / units_per_EM);
		}
		return Value(_face->max_advance_height); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(underline_position))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->underline_position * y_ppem / units_per_EM);
		}
		return Value(_face->underline_position); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(underline_thickness))) {
		if (attrs.IsSet(Gura_UserSymbol(pixel))) {
			return Value(_face->underline_thickness * y_ppem / units_per_EM);
		}
		return Value(_face->underline_thickness); // font_units
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(glyph))) {
		AutoPtr<Object_GlyphSlot> pObj(new Object_GlyphSlot(Object::Reference(this), _face->glyph));
		return Value(pObj.release());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(size))) {
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(charmap))) {
		return Value::Nil;
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_Face::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Nil;
}

bool Object_Face::Initialize(Environment &env, Signal &sig, Stream *pStream, int index)
{
	AutoPtr<Stream> pStreamRef(Stream::Reference(pStream));
	if (!pStreamRef->IsBwdSeekable()) {
		pStreamRef.reset(Stream::Prefetch(env, pStreamRef.release(), true));
		if (sig.IsSignalled()) return false;
	}
	_pHandler.reset(new Handler(sig, pStreamRef.release()));
	return _pHandler->OpenFace(sig, index, &_face);
}

//-----------------------------------------------------------------------------
// Gura interfaces for freetype.Face
//-----------------------------------------------------------------------------
// freetype.Face(stream:stream, face_index:number => 0):map {block?}
Gura_DeclareFunction(Face)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareArg(env, "face_index", VTYPE_number,
						OCCUR_Once, FLAG_None, new Expr_Value(0));
	SetClassToConstruct(Gura_UserClass(Face));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Face)
{
	Signal &sig = env.GetSignal();
	int index = args.GetInt(1);
	AutoPtr<Object_Face> pObjFace(new Object_Face());
	if (!pObjFace->Initialize(env, sig, &args.GetStream(0), index)) return Value::Nil;
	return ReturnValue(env, args, Value(pObjFace.release()));
}

// freetype.Face#CheckTrueTypePatents()
Gura_DeclareMethod(Face, CheckTrueTypePatents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Face, CheckTrueTypePatents)
{
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	return Value(::FT_Face_CheckTrueTypePatents(face));
}

// freetype.Face#Get_Advance(glyph_index:number, load_flags:number)
Gura_DeclareMethod(Face, Get_Advance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "glyph_index", VTYPE_number);
	DeclareArg(env, "load_flags", VTYPE_number);
}

Gura_ImplementMethod(Face, Get_Advance)
{
	Signal &sig = env.GetSignal();
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_UInt glyph_index = static_cast<FT_UInt>(args.GetUInt(0));
	FT_Int32 load_flags = static_cast<FT_Int32>(args.GetLong(1));
	FT_Fixed advance = 0;
	FT_Error err = ::FT_Get_Advance(face, glyph_index, load_flags, &advance);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return Value(static_cast<double>(advance) / (1 << 16));
}

// freetype.Face#Get_Advances(glyph_index_start:number, count:number, load_flags:number)
Gura_DeclareMethod(Face, Get_Advances)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "glyph_index_start", VTYPE_number);
	DeclareArg(env, "count", VTYPE_number);
	DeclareArg(env, "load_flags", VTYPE_number);
}

Gura_ImplementMethod(Face, Get_Advances)
{
	Signal &sig = env.GetSignal();
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_UInt glyph_index_start = static_cast<FT_UInt>(args.GetUInt(0));
	FT_UInt count = static_cast<FT_UInt>(args.GetUInt(1));
	FT_Int32 load_flags = static_cast<FT_Int32>(args.GetLong(2));
	FT_Fixed *advances = new FT_Fixed[count];
	FT_Error err = ::FT_Get_Advances(face, glyph_index_start, count, load_flags, advances);
	if (err != 0) {
		delete[] advances;
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(count);
	for (FT_UInt i = 0; i < count; i++) {
		valList.push_back(static_cast<double>(advances[i]) / (1 << 16));
	}
	return rtn;
}

// freetype.Face#Get_Glyph_Name(glyph_index:number)
Gura_DeclareMethod(Face, Get_Glyph_Name)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "glyph_index", VTYPE_number);
}

Gura_ImplementMethod(Face, Get_Glyph_Name)
{
	Signal &sig = env.GetSignal();
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_UInt glyph_index = static_cast<FT_UInt>(args.GetUInt(0));
	char buffer[256];
	FT_Error err = ::FT_Get_Glyph_Name(face, glyph_index, buffer, sizeof(buffer));
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return Value(buffer);
}

// freetype.Face#Get_Postscript_Name()
Gura_DeclareMethod(Face, Get_Postscript_Name)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Face, Get_Postscript_Name)
{
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	const char *rtn = ::FT_Get_Postscript_Name(face);
	if (rtn == nullptr) return Value::Nil;
	return Value(rtn);
}

// freetype.Face#Get_Kerning()
Gura_DeclareMethod(Face, Get_Kerning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "left_glyph", VTYPE_number);
	DeclareArg(env, "right_glyph", VTYPE_number);
	DeclareArg(env, "kern_mode", VTYPE_number);
}

Gura_ImplementMethod(Face, Get_Kerning)
{
	Signal &sig = env.GetSignal();
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_UInt left_glyph = static_cast<FT_UInt>(args.GetUInt(0));
	FT_UInt right_glyph = static_cast<FT_UInt>(args.GetUInt(1));
	FT_UInt kern_mode = static_cast<FT_UInt>(args.GetUInt(2));
	FT_Vector akerning;
	FT_Error err = ::FT_Get_Kerning(face, left_glyph, right_glyph, kern_mode, &akerning);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return Value::CreateList(env,
				Value(static_cast<double>(akerning.x) / (1 << 6)),
				Value(static_cast<double>(akerning.x) / (1 << 6)));
}

// freetype.Face#Load_Char(char_code:number, load_flags:number):reduce
Gura_DeclareMethod(Face, Load_Char)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "char_code", VTYPE_number);
	DeclareArg(env, "load_flags", VTYPE_number);
}

Gura_ImplementMethod(Face, Load_Char)
{
	Signal &sig = env.GetSignal();
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_ULong char_code = static_cast<FT_ULong>(args.GetULong(0));
	FT_Int32 load_flags = static_cast<FT_Int32>(args.GetInt(1));
	FT_Error err = ::FT_Load_Char(face, char_code, load_flags);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return args.GetThis();
}

// freetype.Face#Load_Glyph(glyph_index:number, load_flags:number):reduce
Gura_DeclareMethod(Face, Load_Glyph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "glyph_index", VTYPE_number);
	DeclareArg(env, "load_flags", VTYPE_number);
}

Gura_ImplementMethod(Face, Load_Glyph)
{
	Signal &sig = env.GetSignal();
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_UInt glyph_index = static_cast<FT_UInt>(args.GetUInt(0));
	FT_Int32 load_flags = static_cast<FT_Int32>(args.GetInt(1));
	FT_Error err = ::FT_Load_Glyph(face, glyph_index, load_flags);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return args.GetThis();
}

#if 0
// freetype.Face#Select_Charmap(encoding:freetype.Encoding):reduce
Gura_DeclareMethod(Face, Select_Charmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "encoding", VTYPE_Encoding);
}

Gura_ImplementMethod(Face, Select_Charmap)
{
	Signal &sig = env.GetSignal();
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_Error err = ::FT_Select_Charmap(face, encoding);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return args.GetThis();
}
#endif

// freetype.Face#Set_Charmap(charmap:freetype.CharMap):reduce
Gura_DeclareMethod(Face, Set_Charmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "charmap", VTYPE_CharMap);
}

Gura_ImplementMethod(Face, Set_Charmap)
{
	Signal &sig = env.GetSignal();
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_CharMap charmap = Object_CharMap::GetObject(args, 0)->GetEntity();
	FT_Error err = ::FT_Set_Charmap(face, charmap);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return args.GetThis();
}

// freetype.Face#Set_Pixel_Sizes(pixel_width:number, pixel_height:number):reduce
Gura_DeclareMethod(Face, Set_Pixel_Sizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "pixel_width", VTYPE_number);
	DeclareArg(env, "pixel_height", VTYPE_number);
}

Gura_ImplementMethod(Face, Set_Pixel_Sizes)
{
	Signal &sig = env.GetSignal();
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_UInt pixel_width = static_cast<FT_UInt>(args.GetULong(0));
	FT_UInt pixel_height = static_cast<FT_UInt>(args.GetULong(1));
	FT_Error err = ::FT_Set_Pixel_Sizes(face, pixel_width, pixel_height);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Face
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(Face)
{
	Gura_AssignFunction(Face);
	Gura_AssignMethod(Face, CheckTrueTypePatents);
	Gura_AssignMethod(Face, Get_Advance);
	Gura_AssignMethod(Face, Get_Advances);
	Gura_AssignMethod(Face, Get_Glyph_Name);
	Gura_AssignMethod(Face, Get_Postscript_Name);
	Gura_AssignMethod(Face, Get_Kerning);
	Gura_AssignMethod(Face, Load_Char);
	Gura_AssignMethod(Face, Load_Glyph);
	//Gura_AssignMethod(Face, Select_Charmap);
	Gura_AssignMethod(Face, Set_Charmap);
	Gura_AssignMethod(Face, Set_Pixel_Sizes);
}

Gura_ImplementCastFrom(Face)
{
	Signal &sig = GetSignal();
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, pDecl);
	if (value.Is_stream()) {
		int index = 0;
		AutoPtr<Object_Face> pObjFace(new Object_Face());
		if (!pObjFace->Initialize(env, sig, &value.GetStream(), index)) return false;
		value = Value(pObjFace.release());
		return true;
	}
	return false;
}

Gura_ImplementCastTo(Face)
{
	return false;
}

Gura_EndModuleScope(freetype)
