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
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.Face#ascender
Gura_DeclareProperty_R(Face, ascender)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, ascender)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	double y_ppem = face->size->metrics.y_ppem;	// pixels/EM
	double units_per_EM = face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (attrs.IsSet(Gura_UserSymbol(pixel))) {
		return Value(face->ascender * y_ppem / units_per_EM);
	}
	return Value(face->ascender); // font_units
}

// freetype.Face#available_sizes
Gura_DeclareProperty_R(Face, available_sizes)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, available_sizes)
{
	//face->num_fixed_sizes
	//face->available_sizes
	return Value::Nil;
}

// freetype.Face#bbox
Gura_DeclareProperty_R(Face, bbox)
{
	SetPropAttr(VTYPE_list);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, bbox)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	return Value::CreateList(
		env,
		Value(static_cast<Int32>(face->bbox.xMin)), Value(static_cast<Int32>(face->bbox.yMin)),
		Value(static_cast<Int32>(face->bbox.xMax)), Value(static_cast<Int32>(face->bbox.yMax))); // font_units
}

// freetype.Face#charmap
Gura_DeclareProperty_R(Face, charmap)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, charmap)
{
	return Value::Nil;
}

// freetype.Face#charmaps
Gura_DeclareProperty_R(Face, charmaps)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, charmaps)
{
	return Value::Nil;
}

// freetype.Face#descender
Gura_DeclareProperty_R(Face, descender)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, descender)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	double y_ppem = face->size->metrics.y_ppem;	// pixels/EM
	double units_per_EM = face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (attrs.IsSet(Gura_UserSymbol(pixel))) {
		return Value(face->descender * y_ppem / units_per_EM);
	}
	return Value(face->descender); // font_units
}

// freetype.Face#face_flags
Gura_DeclareProperty_R(Face, face_flags)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, face_flags)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	return Value(static_cast<Int32>(face->face_flags));
}

// freetype.Face#face_index
Gura_DeclareProperty_R(Face, face_index)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, face_index)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	return Value(static_cast<Int32>(face->face_index));
}

// freetype.Face#family_name
Gura_DeclareProperty_R(Face, family_name)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, family_name)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	if (face->family_name == nullptr) return Value::Nil;
	return Value(face->family_name);
}

// freetype.Face#generic
Gura_DeclareProperty_R(Face, generic)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, generic)
{
	return Value::Nil;
}

// freetype.Face#glyph
Gura_DeclareProperty_R(Face, glyph)
{
	SetPropAttr(VTYPE_GlyphSlot);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, glyph)
{
	Object_Face *pObjThis = Object_Face::GetObject(valueThis);
	const FT_Face &face = pObjThis->GetEntity();
	AutoPtr<Object_GlyphSlot> pObj(new Object_GlyphSlot(Object::Reference(pObjThis), face->glyph));
	return Value(pObj.release());
}

// freetype.Face#height
Gura_DeclareProperty_R(Face, height)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, height)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	double y_ppem = face->size->metrics.y_ppem;	// pixels/EM
	double units_per_EM = face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (attrs.IsSet(Gura_UserSymbol(pixel))) {
		return Value(face->height * y_ppem / units_per_EM);
	}
	return Value(face->height); // font_units
}

// freetype.Face#max_advance_height
Gura_DeclareProperty_R(Face, max_advance_height)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, max_advance_height)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	double y_ppem = face->size->metrics.y_ppem;	// pixels/EM
	double units_per_EM = face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (attrs.IsSet(Gura_UserSymbol(pixel))) {
		return Value(face->max_advance_height * y_ppem / units_per_EM);
	}
	return Value(face->max_advance_height); // font_units
}

// freetype.Face#max_advance_width
Gura_DeclareProperty_R(Face, max_advance_width)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, max_advance_width)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	double y_ppem = face->size->metrics.y_ppem;	// pixels/EM
	double units_per_EM = face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (attrs.IsSet(Gura_UserSymbol(pixel))) {
		return Value(face->max_advance_width * y_ppem / units_per_EM);
	}
	return Value(face->max_advance_width); // font_units
}

// freetype.Face#num_charmaps
Gura_DeclareProperty_R(Face, num_charmaps)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, num_charmaps)
{
	return Value::Nil;
}

// freetype.Face#num_faces
Gura_DeclareProperty_R(Face, num_faces)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, num_faces)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	return Value(static_cast<Int32>(face->num_faces));
}

// freetype.Face#num_fixed_sizes
Gura_DeclareProperty_R(Face, num_fixed_sizes)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, num_fixed_sizes)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	return Value(face->num_fixed_sizes);
}

// freetype.Face#num_glyphs
Gura_DeclareProperty_R(Face, num_glyphs)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, num_glyphs)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	return Value(static_cast<Int32>(face->num_glyphs));
}

// freetype.Face#size
Gura_DeclareProperty_R(Face, size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, size)
{
	return Value::Nil;
}

// freetype.Face#style_flags
Gura_DeclareProperty_R(Face, style_flags)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, style_flags)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	return Value(static_cast<Int32>(face->style_flags));
}

// freetype.Face#style_name
Gura_DeclareProperty_R(Face, style_name)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, style_name)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	if (face->style_name == nullptr) return Value::Nil;
	return Value(face->style_name);
}

// freetype.Face#underline_position
Gura_DeclareProperty_R(Face, underline_position)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, underline_position)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	double y_ppem = face->size->metrics.y_ppem;	// pixels/EM
	double units_per_EM = face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (attrs.IsSet(Gura_UserSymbol(pixel))) {
		return Value(face->underline_position * y_ppem / units_per_EM);
	}
	return Value(face->underline_position); // font_units
}

// freetype.Face#underline_thickness
Gura_DeclareProperty_R(Face, underline_thickness)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, underline_thickness)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	double y_ppem = face->size->metrics.y_ppem;	// pixels/EM
	double units_per_EM = face->units_per_EM;	// fontUnits/EM (typically 2048 or 1000)
	if (attrs.IsSet(Gura_UserSymbol(pixel))) {
		return Value(face->underline_thickness * y_ppem / units_per_EM);
	}
	return Value(face->underline_thickness); // font_units
}

// freetype.Face#units_per_EM
Gura_DeclareProperty_R(Face, units_per_EM)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Face, units_per_EM)
{
	const FT_Face &face = Object_Face::GetObject(valueThis)->GetEntity();
	return Value(face->units_per_EM);
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
			   OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	SetClassToConstruct(Gura_UserClass(Face));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Face)
{
	Signal &sig = env.GetSignal();
	int index = arg.GetInt(1);
	AutoPtr<Object_Face> pObjFace(new Object_Face());
	if (!pObjFace->Initialize(env, sig, &arg.GetStream(0), index)) return Value::Nil;
	return ReturnValue(env, arg, Value(pObjFace.release()));
}

// freetype.Face#CheckTrueTypePatents()
Gura_DeclareMethod(Face, CheckTrueTypePatents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Face, CheckTrueTypePatents)
{
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
	FT_UInt glyph_index = static_cast<FT_UInt>(arg.GetUInt(0));
	FT_Int32 load_flags = static_cast<FT_Int32>(arg.GetLong(1));
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
	FT_UInt glyph_index_start = static_cast<FT_UInt>(arg.GetUInt(0));
	FT_UInt count = static_cast<FT_UInt>(arg.GetUInt(1));
	FT_Int32 load_flags = static_cast<FT_Int32>(arg.GetLong(2));
	FT_Fixed *advances = new FT_Fixed[count];
	FT_Error err = ::FT_Get_Advances(face, glyph_index_start, count, load_flags, advances);
	if (err != 0) {
		delete[] advances;
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	pObjList->Reserve(count);
	for (FT_UInt i = 0; i < count; i++) {
		pObjList->Add(static_cast<double>(advances[i]) / (1 << 16));
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
	FT_UInt glyph_index = static_cast<FT_UInt>(arg.GetUInt(0));
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
	FT_UInt left_glyph = static_cast<FT_UInt>(arg.GetUInt(0));
	FT_UInt right_glyph = static_cast<FT_UInt>(arg.GetUInt(1));
	FT_UInt kern_mode = static_cast<FT_UInt>(arg.GetUInt(2));
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
	FT_ULong char_code = static_cast<FT_ULong>(arg.GetULong(0));
	FT_Int32 load_flags = static_cast<FT_Int32>(arg.GetInt(1));
	FT_Error err = ::FT_Load_Char(face, char_code, load_flags);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
	FT_UInt glyph_index = static_cast<FT_UInt>(arg.GetUInt(0));
	FT_Int32 load_flags = static_cast<FT_Int32>(arg.GetInt(1));
	FT_Error err = ::FT_Load_Glyph(face, glyph_index, load_flags);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
	FT_Error err = ::FT_Select_Charmap(face, encoding);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
	FT_CharMap charmap = Object_CharMap::GetObject(arg, 0)->GetEntity();
	FT_Error err = ::FT_Set_Charmap(face, charmap);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
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
	FT_Face face = Object_Face::GetObjectThis(arg)->GetEntity();
	FT_UInt pixel_width = static_cast<FT_UInt>(arg.GetULong(0));
	FT_UInt pixel_height = static_cast<FT_UInt>(arg.GetULong(1));
	FT_Error err = ::FT_Set_Pixel_Sizes(face, pixel_width, pixel_height);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Face
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(Face)
{
	// Assignment of function
	Gura_AssignFunction(Face);
	// Assignment of properties
	Gura_AssignProperty(Face, ascender);
	Gura_AssignProperty(Face, available_sizes);
	Gura_AssignProperty(Face, bbox);
	Gura_AssignProperty(Face, charmap);
	Gura_AssignProperty(Face, charmaps);
	Gura_AssignProperty(Face, descender);
	Gura_AssignProperty(Face, face_flags);
	Gura_AssignProperty(Face, face_index);
	Gura_AssignProperty(Face, family_name);
	Gura_AssignProperty(Face, generic);
	Gura_AssignProperty(Face, glyph);
	Gura_AssignProperty(Face, height);
	Gura_AssignProperty(Face, max_advance_height);
	Gura_AssignProperty(Face, max_advance_width);
	Gura_AssignProperty(Face, num_charmaps);
	Gura_AssignProperty(Face, num_faces);
	Gura_AssignProperty(Face, num_fixed_sizes);
	Gura_AssignProperty(Face, num_glyphs);
	Gura_AssignProperty(Face, size);
	Gura_AssignProperty(Face, style_flags);
	Gura_AssignProperty(Face, style_name);
	Gura_AssignProperty(Face, underline_position);
	Gura_AssignProperty(Face, underline_thickness);
	Gura_AssignProperty(Face, units_per_EM);
	// Assignment of methods
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
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, flags);
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
