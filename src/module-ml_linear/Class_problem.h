#ifndef __ML_LINEAR_CLASS_PROBLEM_H__
#define __ML_LINEAR_CLASS_PROBLEM_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

class Object_ifd;

//-----------------------------------------------------------------------------
// Sample
//-----------------------------------------------------------------------------
struct Sample {
	double y;
	struct feature_node nodes[1];
public:
	static Sample *Create(const Value &valueY, const ValueList &valListX, int *pIndexMax);
	static Sample *Create(Signal &sig, const Value &valueY, const ValueList &valListX, int *pIndexMax);
};

//-----------------------------------------------------------------------------
// SampleList
//-----------------------------------------------------------------------------
typedef std::vector<Sample *> SampleList;

//-----------------------------------------------------------------------------
// SampleOwner
//-----------------------------------------------------------------------------
class SampleOwner : public SampleList {
public:
	~SampleOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Object_problem declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(problem);

class Object_problem : public Object {
private:
	struct problem _prob;
	SampleOwner _sampleOwner;
public:
	Gura_DeclareObjectAccessor(problem)
public:
	Object_problem();
	virtual ~Object_problem();
	virtual String ToString(bool exprFlag);
	struct problem &UpdateEntity();
	void AddSample(const Value &valueY, const ValueList &valListX);
};

Gura_EndModuleScope(ml_linear)

#endif
