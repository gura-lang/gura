//=============================================================================
// Gura module: gmp
//=============================================================================
#ifndef __GURA_MODULE_GMP_H__
#define __GURA_MODULE_GMP_H__
#include <gura.h>
#include <gmpxx.h>
#include "Class_mpz.h"
#include "Class_mpq.h"
#include "Class_mpf.h"
#include "Operators.h"

Gura_BeginModuleHeader(gmp)

mpq_class MpqFromRational(const Rational &ratio);

Gura_EndModuleHeader(gmp)

#endif
