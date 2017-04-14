#include "stdafx.h"
#include "Class_problem.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_problem implementation
//-----------------------------------------------------------------------------
Object_problem::Object_problem() : Object(Gura_UserClass(problem)),
	_indexMax(0), _pSampleOwner(new SampleOwner())
{
	::memset(&_prob, 0x00, sizeof(_prob));
	_prob.l = 0;
	_prob.n = 0;
	_prob.y = nullptr;
	_prob.x = nullptr;
	_prob.bias = -1;
}

Object_problem::~Object_problem()
{
	delete[] _prob.y;
	delete[] _prob.x;
}

String Object_problem::ToString(bool exprFlag)
{
	return String("<ml.linear.problem>");
}

struct problem &Object_problem::UpdateEntity(double bias)
{
	delete[] _prob.y;
	delete[] _prob.x;
	_prob.l = static_cast<int>(_pSampleOwner->size());
	_prob.y = new double[_prob.l];
	_prob.x = new struct feature_node *[_prob.l];
	_prob.bias = bias;
	if (bias >= 0) {
		_prob.n = _indexMax + 1;
		size_t i = 0;
		foreach_const (SampleOwner, ppSample, *_pSampleOwner) {
			Sample *pSample = *ppSample;
			pSample->GetFeature()->SetBias(_prob.n, bias);
			_prob.y[i] = pSample->GetLabel();
			_prob.x[i] = pSample->GetFeature()->GetNodes();
			i++;
		}
	} else {
		_prob.n = _indexMax;
		size_t i = 0;
		foreach_const (SampleOwner, ppSample, *_pSampleOwner) {
			Sample *pSample = *ppSample;
			pSample->GetFeature()->ClearBias();
			_prob.y[i] = pSample->GetLabel();
			_prob.x[i] = pSample->GetFeature()->GetNodes();
			i++;
		}
	}
	return _prob;
}

void Object_problem::AddSample(Sample *pSample)
{
	_pSampleOwner->push_back(pSample);
	int indexMax = pSample->GetFeature()->GetIndexMax();
	if (_indexMax < indexMax) _indexMax = indexMax;
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
// ml.linear.problem#samples
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
// ml.linear.problem.add_sample(sample:ml.linear.sample):reduce:map
Gura_DeclareMethod(problem, add_sample)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "sample", VTYPE_sample);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(problem, add_sample)
{
	Object_problem *pObjProb = Object_problem::GetObjectThis(arg);
	Sample *pSample = Object_sample::GetObject(arg, 0)->GetEntity();
	pObjProb->AddSample(pSample->Reference());
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// ml.linear.problem() {block?}
Gura_DeclareFunction(problem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(problem));
	AddHelp(
		Gura_Symbol(en),
		"Creates an instance of ml.linear.problem.\n");
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

Gura_EndModuleScope(ml_linear)
