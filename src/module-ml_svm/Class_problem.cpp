#include "stdafx.h"
#include "Class_problem.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Object_problem implementation
//-----------------------------------------------------------------------------
Object_problem::Object_problem() : Object(Gura_UserClass(problem)),
	_indexMax(0), _pSampleOwner(new SampleOwner())
{
	::memset(&_prob, 0x00, sizeof(_prob));
	_prob.l = 0;
	_prob.y = nullptr;
	_prob.x = nullptr;
}

Object_problem::~Object_problem()
{
	delete[] _prob.y;
	delete[] _prob.x;
}

String Object_problem::ToString(bool exprFlag)
{
	return String("<ml.svm.problem>");
}

struct svm_problem &Object_problem::UpdateEntity()
{
	delete[] _prob.y;
	delete[] _prob.x;
	_prob.l = static_cast<int>(_pSampleOwner->size());
	_prob.y = new double[_prob.l];
	_prob.x = new struct svm_node *[_prob.l];
	size_t i = 0;
	foreach_const (SampleOwner, ppSample, *_pSampleOwner) {
		Sample *pSample = *ppSample;
		_prob.y[i] = pSample->GetLabel();
		_prob.x[i] = pSample->GetFeature()->GetNodes();
		i++;
	}
	return _prob;
}

void Object_problem::AddSample(double label, Feature *pFeature)
{
	_pSampleOwner->push_back(new Sample(label, pFeature));
	int indexMax = pFeature->GetIndexMax();
	if (_indexMax < indexMax) _indexMax = indexMax;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.svm.problem#samples
Gura_DeclareProperty_R(problem, samples)
{
	SetPropAttr(VTYPE_iterator);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(problem, samples)
{
	Object_problem *pObjProb = Object_problem::GetObject(valueThis);
	AutoPtr<Iterator> pIterator(new Iterator_sample(pObjProb->GetSampleOwner()->Reference()));
	return Value(new Object_iterator(env, pIterator.release()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// ml.svm.problem.add_sample(label:number, feature:feature):reduce
Gura_DeclareMethod(problem, add_sample)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "label", VTYPE_number);
	DeclareArg(env, "feature", VTYPE_feature);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(problem, add_sample)
{
	Object_problem *pObjProb = Object_problem::GetObjectThis(arg);
	double label = arg.GetDouble(0);
	Feature *pFeature = Object_feature::GetObject(arg, 1)->GetEntity();
	pObjProb->AddSample(label, pFeature->Reference());
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// ml.svm.problem() {block?}
Gura_DeclareFunction(problem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(problem));
	AddHelp(
		Gura_Symbol(en),
		"Creates an instance of ml.svm.problem.\n");
}

Gura_ImplementFunction(problem)
{
	return ReturnValue(env, arg, Value(new Object_problem()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(problem)
{
	// Assignment of properties
	Gura_AssignProperty(problem, samples);
	// Assignment of methods
	Gura_AssignMethod(problem, add_sample);
	// Assignment of function
	Gura_AssignFunction(problem);
}

Gura_EndModuleScope(ml_svm)
