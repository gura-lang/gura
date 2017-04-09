#include "stdafx.h"
#include "Class_problem.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_problem implementation
//-----------------------------------------------------------------------------
Object_problem::Object_problem() : Object(Gura_UserClass(problem)), _indexMax(0)
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
	_prob.l = static_cast<int>(_sampleOwner.size());
	_prob.y = new double[_prob.l];
	_prob.x = new struct feature_node *[_prob.l];
	_prob.bias = bias;
	if (bias >= 0) {
		_prob.n = _indexMax + 1;
		size_t i = 0;
		foreach_const (SampleOwner, ppSample, _sampleOwner) {
			Sample *pSample = *ppSample;
			size_t iNode = pSample->nNodes - 2;
			pSample->nodes[iNode].index = _prob.n;
			pSample->nodes[iNode].value = bias;
			_prob.y[i] = pSample->y;
			_prob.x[i] = pSample->nodes;
			i++;
		}
	} else {
		_prob.n = _indexMax;
		size_t i = 0;
		foreach_const (SampleOwner, ppSample, _sampleOwner) {
			Sample *pSample = *ppSample;
			size_t iNode = pSample->nNodes - 2;
			pSample->nodes[iNode].index = -1;
			pSample->nodes[iNode].value = 0;
			_prob.y[i] = pSample->y;
			_prob.x[i] = pSample->nodes;
			i++;
		}
	}
	return _prob;
}

void Object_problem::AddSample(const Value &valueY, const ValueList &valListX)
{
	int indexMax = 0;
	_sampleOwner.push_back(Sample::Create(valueY, valListX, &indexMax));
	if (_indexMax < indexMax) _indexMax = indexMax;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// ml.linear.problem.add_sample(y:number, x[]:number):reduce
Gura_DeclareMethod(problem, add_sample)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(problem, add_sample)
{
	Object_problem *pObjProb = Object_problem::GetObjectThis(arg);
	pObjProb->AddSample(arg.GetValue(0), arg.GetList(1));
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
	// Assignment of methods
	Gura_AssignMethod(problem, add_sample);
	// Assignment of function
	Gura_AssignFunction(problem);
	// Assignment of value
	Gura_AssignValue(problem, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
