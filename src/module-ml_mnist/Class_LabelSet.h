#ifndef __GURA_ML_MNIST_CLASS_LABELSET_H__
#define __GURA_ML_MNIST_CLASS_LABELSET_H__
#include <gura.h>

Gura_BeginModuleScope(ml_mnist)

//-----------------------------------------------------------------------------
// LabelSet
//-----------------------------------------------------------------------------
class LabelSet {

	
};

//-----------------------------------------------------------------------------
// Object_LabelSet declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(LabelSet);

class Object_LabelSet : public Object {
private:
	std::unique_ptr<LabelSet> _pLabelSet;
public:
	Gura_DeclareObjectAccessor(LabelSet)
public:
	Object_LabelSet(LabelSet *pLabelSet);
	virtual String ToString(bool exprFlag);
	inline LabelSet &GetLabelSet() { return *_pLabelSet; }
};

Gura_EndModuleScope(ml_mnist)

#endif
