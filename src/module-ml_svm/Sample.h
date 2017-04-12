#ifndef __ML_SVM_SAMPLE_H__
#define __ML_SVM_SAMPLE_H__
#include <gura.h>
#include "Feature.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Sample
//-----------------------------------------------------------------------------
class Sample {
private:
	int _cntRef;
	double _label;
	AutoPtr<Feature> _pFeature;
public:
	Gura_DeclareReferenceAccessor(Sample);
public:
	inline Sample(double label, Feature *pFeature) :
						_cntRef(1), _label(label), _pFeature(pFeature) {}
protected:
	inline ~Sample() {}
public:
	double GetLabel() const { return _label; }
	Feature *GetFeature() { return _pFeature.get(); }
	const Feature *GetFeature() const { return _pFeature.get(); }
};

//-----------------------------------------------------------------------------
// SampleList
//-----------------------------------------------------------------------------
typedef std::vector<Sample *> SampleList;

//-----------------------------------------------------------------------------
// SampleOwner
//-----------------------------------------------------------------------------
class SampleOwner : public SampleList {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(SampleOwner);
public:
	inline SampleOwner() : _cntRef(1) {}
protected:
	~SampleOwner();
public:
	void Clear();
};

Gura_EndModuleScope(ml_svm)

#endif
