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
	const Array *GetArray() const;
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
