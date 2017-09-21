#ifndef __GURA_ML_CIFAR_CLASS_CIFAR10_H__
#define __GURA_ML_CIFAR_CLASS_CIFAR10_H__
#include <gura.h>

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// Cifar10
//-----------------------------------------------------------------------------
class Cifar10 {
public:
	struct Header {
		Gura_PackedUInt32_BE(magicNumber);
		Gura_PackedUInt32_BE(nImages);
		Gura_PackedUInt32_BE(nRows);
		Gura_PackedUInt32_BE(nCols);
	};
private:
	size_t _nImages;
	size_t _nRows;
	size_t _nCols;
	AutoPtr<Memory> _pMemory;
public:
	inline Cifar10() : _nImages(0), _nRows(0), _nCols(0) {}
	bool Read(Signal &sig, Stream &stream);
	inline size_t GetNumImages() const { return _nImages; }
	inline size_t GetNumRows() const { return _nRows; }
	inline size_t GetNumColumns() const { return _nCols; }
	Array *ToArray(bool flattenFlag, bool rawDataFlag) const;
};

//-----------------------------------------------------------------------------
// Object_cifar10 declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(cifar10);

class Object_cifar10 : public Object {
private:
	std::unique_ptr<Cifar10> _pCifar10;
public:
	Gura_DeclareObjectAccessor(Cifar10)
public:
	Object_cifar10(Cifar10 *pCifar10);
	virtual String ToString(bool exprFlag);
	inline Cifar10 &GetCifar10() { return *_pCifar10; }
};

Gura_EndModuleScope(ml_cifar)

#endif
