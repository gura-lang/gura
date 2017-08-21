#ifndef __GURA_ML_MNIST_CLASS_IMAGESET_H__
#define __GURA_ML_MNIST_CLASS_IMAGESET_H__
#include <gura.h>

Gura_BeginModuleScope(ml_mnist)

//-----------------------------------------------------------------------------
// ImageSet
//-----------------------------------------------------------------------------
class ImageSet {
public:
	struct Header {
		Gura_PackedUInt32_BE(magicNumber);
		Gura_PackedUInt32_BE(nImages);
		Gura_PackedUInt32_BE(nRows);
		Gura_PackedUInt32_BE(nColumns);
	};
private:
	size_t _nImages;
	size_t _nRows;
	size_t _nColumns;
	AutoPtr<Memory> _pMemory;
public:
	inline ImageSet() : _nImages(0), _nRows(0), _nColumns(0) {}
	bool Read(Signal &sig, Stream &stream);
	inline size_t GetNumImages() const { return _nImages; }
	inline size_t GetNumRows() const { return _nRows; }
	inline size_t GetNumColumns() const { return _nColumns; }
};

//-----------------------------------------------------------------------------
// Object_ImageSet declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(ImageSet);

class Object_ImageSet : public Object {
private:
	std::unique_ptr<ImageSet> _pImageSet;
public:
	Gura_DeclareObjectAccessor(ImageSet)
public:
	Object_ImageSet(ImageSet *pImageSet);
	virtual String ToString(bool exprFlag);
	inline ImageSet &GetImageSet() { return *_pImageSet; }
};

Gura_EndModuleScope(ml_mnist)

#endif
