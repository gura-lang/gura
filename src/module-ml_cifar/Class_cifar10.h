#ifndef __GURA_ML_CIFAR_CLASS_CIFAR10_H__
#define __GURA_ML_CIFAR_CLASS_CIFAR10_H__
#include <gura.h>

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// Cifar10
//-----------------------------------------------------------------------------
class Cifar10 {
public:
	struct ImageData {
		UInt8 planeR[1024];
		UInt8 planeG[1024];
		UInt8 planeB[1024];
	};
private:
	AutoPtr<Memory> _pMemoryLabel;
	AutoPtr<Memory> _pMemoryImageData;
	size_t _nImages;
public:
	enum { EntryBytes = 1 + 1024 * 3 };
	enum { nPlanes = 3, nRows = 32, nCols = 32 };
public:
	Cifar10();
	inline size_t GetNumImages() const { return _nImages; }
	bool Read(Signal &sig, Stream &stream);
	Array *ImageDataToArray(Signal &sig, bool flattenFlag, Array::ElemType elemType, bool normalizeFlag) const;
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
