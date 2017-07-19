#ifndef __CERES_CLASS_SOLVEROPTIONS_H__
#define __CERES_CLASS_SOLVEROPTIONS_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_Solver_Options declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Solver_Options);

class Object_Solver_Options : public Object {
private:
	ceres::Solver::Options _options;
public:
	Gura_DeclareObjectAccessor(Solver_Options)
public:
	Object_Solver_Options();
	virtual String ToString(bool exprFlag);
	inline ceres::Solver::Options &GetOptions() { return _options; }
};

Gura_EndModuleScope(ceres)

#endif
