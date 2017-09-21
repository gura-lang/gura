#ifndef __GURA_ML_CIFAR_CLASS_CIFAR10_H__
#define __GURA_ML_CIFAR_CLASS_CIFAR10_H__
#include <gura.h>

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// Cifar10
//-----------------------------------------------------------------------------
class Cifar10 {
private:
	size_t _nImages;
	size_t _nRows;
	size_t _nCols;
	AutoPtr<Memory> _pMemory;
public:
	inline Cifar10() : _nImages(0), _nRows(0), _nCols(0) {}
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
	inline Cifar10 &GetCifar10() { return *_pCifar10; }
};

Gura_EndModuleScope(ml_cifar)

#endif
