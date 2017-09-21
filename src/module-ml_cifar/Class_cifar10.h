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
		UChar planeR[1024];
		UChar planeG[1024];
		UChar planeB[1024];
	};
private:
	AutoPtr<Memory> _pMemoryLabel;
	AutoPtr<Memory> _pMemoryImageData;
	size_t _nEntries;
public:
	enum { EntryBytes = 1 + 1024 * 3 };
	enum { nRows = 32, nCols = 32 };
public:
	Cifar10();
	//inline const Entry *GetEntry(size_t idx) {
	//	return reinterpret_cast<const Entry *>(_pMemory->GetPointer() + idx * EntryBytes);
	//}
	inline size_t GetNumEntries() const { return _nEntries; }
	bool Read(Signal &sig, Stream &stream);
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
