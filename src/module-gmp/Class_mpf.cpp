//=============================================================================
// Gura class: gmp.mpf
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpf
//-----------------------------------------------------------------------------
Object_mpf::Object_mpf(mpf_t num) : Object(Gura_UserClass(mpf)), _num(num)
{
}

Object_mpf::Object_mpf(const mpf_class &num) : Object(Gura_UserClass(mpf)), _num(num)
{
}

bool Object_mpf::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(prec));
	return true;
}

Value Object_mpf::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(prec))) {
		return Value(_num.get_prec());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_mpf::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(prec))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		mp_bitcnt_t prec = value.GetInt();
		_num.set_prec(prec);
		return Value(prec);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_mpf::ToString(bool exprFlag)
{
	char *p = NULL;
	::gmp_asprintf(&p, "%.Ff", _num.get_mpf_t());
	String str = p;
	if (::strchr(p, '.') == NULL) str += '.';
	str += 'L';
	::free(p);
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpf(value?, prec?:number) {block?}
Gura_DeclareFunction(mpf)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "prec", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpf));
}

Gura_ImplementFunction(mpf)
{
	mpf_t num;
	if (args.Is_number(1)) {
		::mpf_init2(num, args.GetInt(1));
	} else {
		::mpf_init(num);
	}
	if (args.IsInvalid(0)) {
		// nothing to do
	} else if (args.Is_number(0)) {
		::mpf_set_d(num, args.GetDouble(0));
	} else if (args.Is_string(0)) {
		if (::mpf_set_str(num, args.GetString(0), 0) < 0) {
			::mpf_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
			return Value::Null;
		}
	} else {
		::mpf_clear(num);
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpf(num)));
}

//-----------------------------------------------------------------------------
// Implementation of class methods
//-----------------------------------------------------------------------------
// gmp.mpf.get_defaul_prec()
Gura_DeclareClassMethod(mpf, get_default_prec)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementClassMethod(mpf, get_default_prec)
{
	mp_bitcnt_t prec = ::mpf_get_default_prec();
	return Value(prec);
}

// gmp.mpf.set_defaul_prec(prec:number):void
Gura_DeclareClassMethod(mpf, set_default_prec)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "prec", VTYPE_number);
}

Gura_ImplementClassMethod(mpf, set_default_prec)
{
	mp_bitcnt_t prec = args.GetInt(0);
	::mpf_set_default_prec(prec);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Implementation of instance methods
//-----------------------------------------------------------------------------
// string#mpf(base?:number):map {block?}
Gura_DeclareMethod(string, mpf)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, mpf)
{
	const char *strThis = args.GetThis().GetString();
	int base = args.Is_number(0)? args.GetInt(0) : 0;
	mpf_t num;
	::mpf_init(num);
	if (::mpf_set_str(num, strThis, base) < 0) {
		::mpf_clear(num);
		sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
		return false;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpf(num)));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpf)
{
	// assignment of function
	Gura_AssignFunction(mpf);
	// assignment of class methods
	Gura_AssignMethod(mpf, get_default_prec);
	Gura_AssignMethod(mpf, set_default_prec);
	// assignment of instance methods
	
	Gura_AssignMethodTo(VTYPE_string, string, mpf);
}

Gura_ImplementCastFrom(mpf)
{
	if (value.Is_number()) {
		mpf_t num;
		::mpf_init(num);
		::mpf_set_d(num, value.GetDouble());
		value = Value(new Object_mpf(num));
		return true;
	} else if (value.Is_string()) {
		mpf_t num;
		::mpf_init(num);
		if (::mpf_set_str(num, value.GetString(), 0) < 0) {
			::mpf_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
			return false;
		}
		value = Value(new Object_mpf(num));
		return true;
	} else if (value.IsType(VTYPE_mpz)) {
		
	} else if (value.IsType(VTYPE_mpq)) {
		
	}
	return false;
}

Gura_ImplementCastTo(mpf)
{
	if (decl.IsType(VTYPE_number)) {
		double num = Object_mpf::GetEntity(value).get_d();
		value = Value(num);
		return true;
	}
	return false;
}

Gura_EndModuleScope(gmp)
