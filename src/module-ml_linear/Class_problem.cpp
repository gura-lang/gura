#include "stdafx.h"
#include "Class_problem.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Sample
//-----------------------------------------------------------------------------
Sample *Sample::Create(const Value &valueY, const ValueList &valListX, int *pIndexMax)
{
	int nNodes = 0;
	foreach_const (ValueList, pValueX, valListX) {
		if (pValueX->GetDouble() != 0) nNodes++;
	}
	Sample *pSample = reinterpret_cast<Sample *>(
		::malloc(sizeof(Sample) + sizeof(struct feature_node) * nNodes));
	pSample->y = valueY.GetDouble();
	int index = 0;
	int iNode = 0;
	foreach_const (ValueList, pValueX, valListX) {
		index++;
		if (pValueX->GetDouble() != 0) {
			pSample->nodes[iNode].index;
			pSample->nodes[iNode].value = pValueX->GetDouble();
			iNode++;
		}
	}
	*pIndexMax = index;
	return pSample;
}

Sample *Sample::Create(Signal &sig, const Value &valueY, const ValueList &valListX, int *pIndexMax)
{
	if (!valueY.Is_number()) {
		sig.SetError(ERR_ValueError, "y must be a number");
		return nullptr;
	}
	if (valListX.GetValueTypeOfElements() != VTYPE_number) {
		sig.SetError(ERR_ValueError, "x must consist of numbers");
		return nullptr;
	}
	return Create(valueY, valListX, pIndexMax);
}

//-----------------------------------------------------------------------------
// SampleOwner
//-----------------------------------------------------------------------------
SampleOwner::~SampleOwner()
{
	Clear();
}

void SampleOwner::Clear()
{
	foreach (SampleOwner, ppSample, *this) {
		::free(*ppSample);
	}
}

//-----------------------------------------------------------------------------
// Object_problem implementation
//-----------------------------------------------------------------------------
Object_problem::Object_problem() : Object(Gura_UserClass(problem))
{
	::memset(&_prob, 0x00, sizeof(_prob));
	_prob.l = 0;
	_prob.n = 0;
	_prob.y = nullptr;
	_prob.x = nullptr;
	_prob.bias = 0;
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

struct problem &Object_problem::UpdateEntity()
{
	delete[] _prob.y;
	delete[] _prob.x;
	_prob.l = static_cast<int>(_sampleOwner.size());
	_prob.y = new double[_prob.l];
	_prob.x = new struct feature_node *[_prob.l];
	size_t i = 0;
	foreach_const (SampleOwner, ppSample, _sampleOwner) {
		Sample *pSample = *ppSample;
		_prob.y[i] = pSample->y;
		_prob.x[i] = pSample->nodes;
		i++;
	}
	return _prob;
}

void Object_problem::AddSample(const Value &valueY, const ValueList &valListX)
{
	int indexMax = 0;
	_sampleOwner.push_back(Sample::Create(valueY, valListX, &indexMax));
	if (_prob.n < indexMax) _prob.n = indexMax;
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
