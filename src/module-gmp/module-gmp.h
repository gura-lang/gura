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

String ComposeFormat(const Formatter::Flags &flags, const char *qualifier);
mpq_class MpqFromRational(const Rational &ratio);
bool _Format_d(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpz_class &num);
bool _Format_u(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpz_class &num);
bool _Format_b(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpz_class &num);
bool _Format_o(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpz_class &num);
bool _Format_x(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpz_class &num);

bool _Format_e(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpf_class &num);
bool _Format_f(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpf_class &num);
bool _Format_g(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpf_class &num);

bool _Format_d(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpq_class &num);
bool _Format_b(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpq_class &num);
bool _Format_o(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpq_class &num);
bool _Format_x(Signal sig, Formatter *pFormatter, const Formatter::Flags &flags, const mpq_class &num);

Gura_EndModuleHeader(gmp)

#endif
