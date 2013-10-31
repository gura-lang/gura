#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Bitmap implementation
//-----------------------------------------------------------------------------
Object_Bitmap::~Object_Bitmap()
{
	if (_pObjHolder.get() == NULL) {
		::FT_Bitmap_Done(g_lib, _pBitmap);
		delete _pBitmap;
	}
}

Object *Object_Bitmap::Clone() const
{
	return NULL;
}

String Object_Bitmap::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Bitmap>");
	return String(buff);
}

bool Object_Bitmap::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_Bitmap::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Bitmap::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
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

//-----------------------------------------------------------------------------
// Class implementation for freetype.Bitmap
//-----------------------------------------------------------------------------
// freetype.Bitmap() {block?}
Gura_DeclareFunction(Bitmap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Bitmap)
{
	FT_Bitmap *pBitmap = new FT_Bitmap;
	::FT_Bitmap_New(pBitmap);
	AutoPtr<Object_Bitmap> pObjRtn(new Object_Bitmap(NULL, pBitmap));
	return ReturnValue(env, sig, args, Value(pObjRtn.release()));
}

// freetype.Bitmap#Embolden(xStrength:number, yStrength:number):reduce
Gura_DeclareMethod(Bitmap, Embolden)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number);
}

Gura_ImplementMethod(Bitmap, Embolden)
{
	FT_Bitmap *bitmap = Object_Bitmap::GetThisObj(args)->GetEntity();
	FT_Pos xStrength = static_cast<FT_Pos>(args.GetDouble(0) * (1 << 6)); // 26.6
	FT_Pos yStrength = static_cast<FT_Pos>(args.GetDouble(0) * (1 << 6)); // 26.6
	FT_Error err = ::FT_Bitmap_Embolden(g_lib, bitmap, xStrength, yStrength);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return args.GetThis();
}

Gura_ImplementUserClass(Bitmap)
{
	Gura_AssignMethod(Bitmap, Embolden);
}

Gura_EndModuleScope(freetype)
