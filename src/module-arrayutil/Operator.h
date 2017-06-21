#ifndef __GURA_MODULE_ARRAYUTIL_OPERATOR_H__
#define __GURA_MODULE_ARRAYUTIL_OPERATOR_H__

Gura_BeginModuleScope(arrayutil)

void AssignOperators(Environment &env);
Value CalcDot(Environment &env, const Array *pArrayL, const Array *pArrayR);

Gura_EndModuleScope(arrayutil)

#endif
