#ifndef __GURA_ML_CIFAR_CLASS_IMAGESET_H__
#define __GURA_ML_CIFAR_CLASS_IMAGESET_H__
#include <gura.h>

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// ImageSet
//-----------------------------------------------------------------------------
class ImageSet {
public:
	struct Packed {
		UInt8 planeR[1024];
		UInt8 planeG[1024];
		UInt8 planeB[1024];
	};
private:
	int _cntRef;
	size_t _nImages;
	AutoPtr<Memory> _pMemory;
public:
	enum { nPlanes = 3, nRows = 32, nCols = 32 };
public:
	Gura_DeclareReferenceAccessor(ImageSet);
public:
	inline ImageSet() : _cntRef(1), _nImages(0) {}
protected:
	inline ~ImageSet() {}
public:
	bool Read(Signal &sig, Stream &stream);
	inline size_t GetNumImages() const { return _nImages; }
	inline size_t GetNumRows() const { return nRows; }
	inline size_t GetNumColumns() const { return nCols; }
	Array *ToArray(Signal &sig, bool flattenFlag, Array::ElemType elemType, bool normalizeFlag) const;
	void AllocMemory(size_t nImage);
	inline Packed *GetPointer() { return reinterpret_cast<Packed *>(_pMemory->GetPointer()); }
};

//-----------------------------------------------------------------------------
// Object_imageset declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(imageset);

class Object_imageset : public Object {
private:
	AutoPtr<ImageSet> _pImageSet;
public:
	Gura_DeclareObjectAccessor(imageset)
public:
	Object_imageset(ImageSet *pImageSet);
	virtual String ToString(bool exprFlag);
	inline ImageSet *GetImageSet() { return _pImageSet.get(); }
};

Gura_EndModuleScope(ml_cifar)

#endif
