#ifndef __GURA_ML_CIFAR_CLASS_CIFAR10_H__
#define __GURA_ML_CIFAR_CLASS_CIFAR10_H__
#include <gura.h>
#include "Class_labelset.h"
#include "Class_imageset.h"

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// Cifar10
//-----------------------------------------------------------------------------
class Cifar10 {
private:
	AutoPtr<LabelSet> _pLabelSet;
	AutoPtr<ImageSet> _pImageSet;
public:
	enum { EntryBytes = 1 + 1024 * 3 };
public:
	Cifar10();
	bool Read(Signal &sig, Stream &stream);
	Array *ImageDataToArray(Signal &sig, bool flattenFlag, Array::ElemType elemType, bool normalizeFlag) const;
	inline const LabelSet *GetLabelSet() const { return _pLabelSet.get(); }
	inline const ImageSet *GetImageSet() const { return _pImageSet.get(); }
};

//-----------------------------------------------------------------------------
// Object_cifar10 declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(cifar10);

class Object_cifar10 : public Object {
private:
	std::unique_ptr<Cifar10> _pCifar10;
public:
	Gura_DeclareObjectAccessor(cifar10)
public:
	Object_cifar10(Cifar10 *pCifar10);
	virtual String ToString(bool exprFlag);
	inline const Cifar10 *GetCifar10() const { return _pCifar10.get(); }
};

Gura_EndModuleScope(ml_cifar)

#endif
