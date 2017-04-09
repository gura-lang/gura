#ifndef __ML_LINEAR_CLASS_FEATURE_H__
#define __ML_LINEAR_CLASS_FEATURE_H__
#include <gura.h>
#include "Feature.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_feature declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(feature);

class Object_feature : public Object {
public:
	Gura_DeclareObjectAccessor(feature)
public:
	Object_feature();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(ml_linear)

#endif
