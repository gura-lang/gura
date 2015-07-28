#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Stroker implementation
//-----------------------------------------------------------------------------
Object_Stroker::~Object_Stroker()
{
	::FT_Stroker_Done(_stroker);
}

Object *Object_Stroker::Clone() const
{
	return nullptr;
}

String Object_Stroker::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Stroker>");
	return String(buff);
}

bool Object_Stroker::DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, sig, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_Stroker::DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
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

Value Object_Stroker::DoSetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Stroker
//-----------------------------------------------------------------------------
// freetype.Stroker():map {block?}
Gura_DeclareFunction(Stroker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(Stroker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Stroker)
{
	AutoPtr<Object_Stroker> pObj(new Object_Stroker());
	FT_Error err = ::FT_Stroker_New(g_lib, &pObj->GetEntity());
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(pObj.release()));
}

// freetype.Stroker#BeginSubPath(to:freetype.Vector, open:boolean):reduce
Gura_DeclareMethod(Stroker, BeginSubPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "to", VTYPE_Vector);
	DeclareArg(env, "open", VTYPE_boolean);
}

Gura_ImplementMethod(Stroker, BeginSubPath)
{
	FT_Stroker stroker = Object_Stroker::GetThisObj(args)->GetEntity();
	FT_Vector *to = Object_Vector::GetObject(args, 0)->GetEntity();
	bool open = args.GetBoolean(1);
	FT_Error err = ::FT_Stroker_BeginSubPath(stroker, to, open);
	if (err != 0) {
		SetError_Freetype(sig, err);
		return Value::Null;
	}
	return args.GetThis();
}

Gura_ImplementUserClass(Stroker)
{
	Gura_AssignFunction(Stroker);
	Gura_AssignMethod(Stroker, BeginSubPath);
}

Gura_EndModuleScope(freetype)
