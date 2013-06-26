#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Face implementation
//-----------------------------------------------------------------------------
Object_Face::~Object_Face()
{
	::FT_Done_Face(_face);
}

Object *Object_Face::Clone() const
{
	return NULL;
}

String Object_Face::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<freetype.Face";
	str += ":";
	str += _face->family_name;
	if (_face->style_name != NULL) {
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

bool Object_Face::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
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

Value Object_Face::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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
		if (_face->family_name == NULL) return Value::Null;
		return Value(env, _face->family_name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(style_name))) {
		if (_face->style_name == NULL) return Value::Null;
		return Value(env, _face->style_name);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(num_fixed_sizes))) {
		return Value(_face->num_fixed_sizes);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(available_sizes))) {
		//_face->num_fixed_sizes
		//_face->available_sizes
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(num_charmaps))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(charmaps))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(generic))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(bbox))) {
		return Value::CreateAsList(env,
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
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(charmap))) {
		return Value::Null;
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Face::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

bool Object_Face::Initialize(Environment &env, Signal sig, Stream *pStream, int index)
{
	AutoPtr<Stream> pStreamRef(Stream::Reference(pStream));
	if (!pStreamRef->IsBwdSeekable()) {
		pStreamRef.reset(Stream::Prefetch(env, sig, pStreamRef.release(), true));
		if (sig.IsSignalled()) return false;
	}
	_pHandler.reset(new Handler(sig, pStreamRef.release()));
	return _pHandler->OpenFace(sig, index, &_face);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Face
//-----------------------------------------------------------------------------
// freetype.Face(stream:stream, face_index:number => 0):map {block?}
Gura_DeclareFunction(Face)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareArg(env, "face_index", VTYPE_number,
						OCCUR_Once, FLAG_None, new Expr_Value(0));
	SetClassToConstruct(Gura_UserClass(Face));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Face)
{
	int index = args.GetInt(1);
	AutoPtr<Object_Face> pObjFace(new Object_Face());
	if (!pObjFace->Initialize(env, sig, &args.GetStream(0), index)) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjFace.release()));
}

// freetype.Face#CheckTrueTypePatents()
Gura_DeclareMethod(Face, CheckTrueTypePatents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Face, CheckTrueTypePatents)
{
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	return Value(::FT_Face_CheckTrueTypePatents(face));
}

// freetype.Face#Load_Char(char_code:number, load_flags:number):reduce
Gura_DeclareMethod(Face, Load_Char)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "char_code", VTYPE_number);
	DeclareArg(env, "load_flags", VTYPE_number);
}

Gura_ImplementMethod(Face, Load_Char)
{
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_ULong char_code = static_cast<FT_ULong>(args.GetULong(0));
	FT_Int32 load_flags = static_cast<FT_Int32>(args.GetInt(1));
	FT_Error err = ::FT_Load_Char(face, char_code, load_flags);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return args.GetThis();
}

// freetype.Face#Set_Pixel_Sizes(pixel_width:number, pixel_height:number):reduce
Gura_DeclareMethod(Face, Set_Pixel_Sizes)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "pixel_width", VTYPE_number);
	DeclareArg(env, "pixel_height", VTYPE_number);
}

Gura_ImplementMethod(Face, Set_Pixel_Sizes)
{
	FT_Face face = Object_Face::GetThisObj(args)->GetEntity();
	FT_UInt pixel_width = static_cast<FT_UInt>(args.GetULong(0));
	FT_UInt pixel_height = static_cast<FT_UInt>(args.GetULong(1));
	FT_Error err = ::FT_Set_Pixel_Sizes(face, pixel_width, pixel_height);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
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
	Gura_AssignMethod(Face, Load_Char);
	Gura_AssignMethod(Face, Set_Pixel_Sizes);
}

Gura_ImplementCastFrom(Face)
{
	env.LookupClass(VTYPE_stream)->CastFrom(env, sig, value, pDecl);
	if (value.IsStream()) {
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

}}
