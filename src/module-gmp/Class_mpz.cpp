//=============================================================================
// Gura class: gmp.mpz
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpz
//-----------------------------------------------------------------------------
Object_mpz::Object_mpz() : Object(Gura_UserClass(mpz))
{
}

String Object_mpz::ToString(bool exprFlag)
{
	return String("<gmp.mpz>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for mpz
//-----------------------------------------------------------------------------
// implementation of class mpz
Gura_ImplementUserClass(mpz)
{
}

Gura_EndModuleScope(gmp)
