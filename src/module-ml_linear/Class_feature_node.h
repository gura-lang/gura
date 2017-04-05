#ifndef __ML_LINEAR_CLASS_FEATURE_NODE_H__
#define __ML_LINEAR_CLASS_FEATURE_NODE_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

class Object_ifd;

//-----------------------------------------------------------------------------
// Object_feature_node declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(feature_node);

class Object_feature_node : public Object {
private:
	Gura_DeclareObjectAccessor(feature_node)
public:
	Object_feature_node();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(ml_linear)

#endif
