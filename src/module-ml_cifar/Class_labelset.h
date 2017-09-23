#ifndef __GURA_ML_CIFAR_CLASS_LABELSET_H__
#define __GURA_ML_CIFAR_CLASS_LABELSET_H__
#include <gura.h>

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// LabelSet
//-----------------------------------------------------------------------------
class LabelSet {
private:
	int _cntRef;
	size_t _nLabels;
	AutoPtr<Memory> _pMemory;
public:
	Gura_DeclareReferenceAccessor(LabelSet);
public:
	inline LabelSet() : _cntRef(1), _nLabels(0) {}
protected:
	inline ~LabelSet() {}
public:
	bool Read(Signal &sig, Stream &stream);
	inline size_t GetNumLabels() const { return _nLabels; }
	Array *ToArray(Signal &sig, bool onehotFlag, Array::ElemType elemType) const;
	void AllocMemory(size_t nLabels);
	inline UInt8 *GetPointer() { return reinterpret_cast<UInt8 *>(_pMemory->GetPointer()); }
};

//-----------------------------------------------------------------------------
// Object_labelset declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(labelset);

class Object_labelset : public Object {
private:
	AutoPtr<LabelSet> _pLabelSet;
public:
	Gura_DeclareObjectAccessor(labelset)
public:
	Object_labelset(LabelSet *pLabelSet);
	virtual String ToString(bool exprFlag);
	inline LabelSet *GetLabelSet() { return _pLabelSet.get(); }
};

Gura_EndModuleScope(ml_cifar)

#endif
