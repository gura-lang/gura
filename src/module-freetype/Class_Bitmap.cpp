#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Bitmap implementation
//-----------------------------------------------------------------------------
Object_Bitmap::~Object_Bitmap()
{
	if (_pObjHolder.get() == nullptr) {
		::FT_Bitmap_Done(g_lib, _pBitmap);
		delete _pBitmap;
	}
}

Object *Object_Bitmap::Clone() const
{
	return nullptr;
}

String Object_Bitmap::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Bitmap>");
	return String(buff);
}

bool Object_Bitmap::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_Bitmap::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	return Value::Nil;
}

Value Object_Bitmap::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
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

//-----------------------------------------------------------------------------
// Class implementation for freetype.Bitmap
//-----------------------------------------------------------------------------
// freetype.Bitmap() {block?}
Gura_DeclareFunction(Bitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Bitmap)
{
	FT_Bitmap *pBitmap = new FT_Bitmap;
	::FT_Bitmap_New(pBitmap);
	AutoPtr<Object_Bitmap> pObjRtn(new Object_Bitmap(nullptr, pBitmap));
	return ReturnValue(env, args, Value(pObjRtn.release()));
}

// freetype.Bitmap#Embolden(xStrength:number, yStrength:number):reduce
Gura_DeclareMethod(Bitmap, Embolden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number);
}

Gura_ImplementMethod(Bitmap, Embolden)
{
	Signal &sig = env.GetSignal();
	FT_Bitmap *bitmap = Object_Bitmap::GetThisObj(args)->GetEntity();
	FT_Pos xStrength = static_cast<FT_Pos>(args.GetDouble(0) * (1 << 6)); // 26.6
	FT_Pos yStrength = static_cast<FT_Pos>(args.GetDouble(0) * (1 << 6)); // 26.6
	FT_Error err = ::FT_Bitmap_Embolden(g_lib, bitmap, xStrength, yStrength);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Nil;
	}
	return args.GetThis();
}

Gura_ImplementUserClass(Bitmap)
{
	Gura_AssignValue(Bitmap, Value(Reference()));
	Gura_AssignMethod(Bitmap, Embolden);
}

Gura_EndModuleScope(freetype)
