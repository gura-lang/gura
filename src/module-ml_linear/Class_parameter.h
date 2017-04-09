#ifndef __ML_LINEAR_CLASS_PARAMETER_H__
#define __ML_LINEAR_CLASS_PARAMETER_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Weight
//-----------------------------------------------------------------------------
struct Weight {
	int label;
	double weight;
public:
	inline Weight(int label_, double weight_) : label(label_), weight(weight_) {}
};

//-----------------------------------------------------------------------------
// WeightList
//-----------------------------------------------------------------------------
typedef std::vector<Weight> WeightList;

//-----------------------------------------------------------------------------
// WeightOwner
//-----------------------------------------------------------------------------
typedef WeightList WeightOwner;

//-----------------------------------------------------------------------------
// Object_parameter declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(parameter);

class Object_parameter : public Object {
private:
	double _eps;
	struct parameter _param;
	WeightOwner _weightOwner;
public:
	Gura_DeclareObjectAccessor(parameter)
public:
	Object_parameter();
	virtual ~Object_parameter();
	virtual String ToString(bool exprFlag);
	void AddWeight(int label, double weight);
	inline struct parameter &GetEntity() { return _param; }
	struct parameter &UpdateEntity();
};

Gura_EndModuleScope(ml_linear)

#endif
