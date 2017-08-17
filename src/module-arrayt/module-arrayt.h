//=============================================================================
// Gura module: arrayt
//=============================================================================
#ifndef __GURA_MODULE_ARRAYUTIL_H__
#define __GURA_MODULE_ARRAYUTIL_H__
#include <gura.h>
#include "Operator.h"
#include "Creator.h"
#include "Method.h"

#define DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl) \
const static FuncT funcTbl[Array::ETYPE_Max] = { \
	nullptr, \
	&FuncTmpl<Boolean>, \
	&FuncTmpl<Int8>, \
	&FuncTmpl<UInt8>, \
	&FuncTmpl<Int16>, \
	&FuncTmpl<UInt16>, \
	&FuncTmpl<Int32>, \
	&FuncTmpl<UInt32>, \
	&FuncTmpl<Int64>, \
	&FuncTmpl<UInt64>, \
	&FuncTmpl<Half>, \
	&FuncTmpl<Float>, \
	&FuncTmpl<Double>, \
	&FuncTmpl<Complex>, \
	nullptr, \
}

Gura_BeginModuleHeader(arrayt)
Gura_EndModuleHeader(arrayt)

#endif
