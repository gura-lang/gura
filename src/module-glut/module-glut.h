//=============================================================================
// Gura module: glut
//=============================================================================
#ifndef __GURA_MODULE_GLUT_H__
#define __GURA_MODULE_GLUT_H__
#include <gura.h>
#include <glut/glut.h>

Gura_BeginModuleHeader(glut)

void SetError_NotImpFunction(Signal &sig, const char *funcName);
void AssignValues(Environment &env);
void AssignFunctions(Environment &env);

Gura_EndModuleHeader(glut)

#endif
