#ifndef __GURA_ML_MNIST_CLASS_IMAGESET_H__
#define __GURA_ML_MNIST_CLASS_IMAGESET_H__
#include <gura.h>

Gura_BeginModuleScope(ml_mnist)

//-----------------------------------------------------------------------------
// ImageSet
//-----------------------------------------------------------------------------
class ImageSet {
private:
	int _number_of_images;
	int _number_of_rows;
	int _number_of_columns;
	AutoPtr<Memory> _pMemory;
public:
	inline ImageSet() : _number_of_images(0), _number_of_rows(0), _number_of_columns(0) {}
	bool Read(Signal &sig, Stream &stream);
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
