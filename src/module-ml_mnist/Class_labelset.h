#ifndef __GURA_ML_MNIST_CLASS_LABELSET_H__
#define __GURA_ML_MNIST_CLASS_LABELSET_H__
#include <gura.h>

Gura_BeginModuleScope(ml_mnist)

//-----------------------------------------------------------------------------
// LabelSet
//-----------------------------------------------------------------------------
class LabelSet {
public:
	struct Header {
		Gura_PackedUInt32_BE(magicNumber);
		Gura_PackedUInt32_BE(nLabels);
	};
private:
	size_t _nLabels;
	AutoPtr<Memory> _pMemory;
public:
	inline LabelSet() : _nLabels(0) {}
	bool Read(Signal &sig, Stream &stream);
	inline size_t GetNumLabels() const { return _nLabels; }
	Array *ToArray(Signal &sig, bool onehotFlag, Array::ElemType elemType) const;
};

//-----------------------------------------------------------------------------
// Object_labelset declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(labelset);

class Object_labelset : public Object {
private:
	std::unique_ptr<LabelSet> _pLabelSet;
public:
	Gura_DeclareObjectAccessor(labelset)
public:
	Object_labelset(LabelSet *pLabelSet);
	virtual String ToString(bool exprFlag);
	inline LabelSet &GetLabelSet() { return *_pLabelSet; }
};

Gura_EndModuleScope(ml_mnist)

#endif
