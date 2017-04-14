#include "stdafx.h"
#include "Class_sample.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Object_sample implementation
//-----------------------------------------------------------------------------
Object_sample::Object_sample(Sample *pSample) :
					Object(Gura_UserClass(sample)), _pSample(pSample)
{
}

String Object_sample::ToString(bool exprFlag)
{
	return String("<ml.svm.sample>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.svm.sample#label
Gura_DeclareProperty_R(sample, label)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(sample, label)
{
	Sample *pSample = Object_sample::GetObject(valueThis)->GetEntity();
	return Value(pSample->GetLabel());
}

// ml.svm.sample#feature
Gura_DeclareProperty_R(sample, feature)
{
	SetPropAttr(VTYPE_feature);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(sample, feature)
{
	Sample *pSample = Object_sample::GetObject(valueThis)->GetEntity();
	return Value(new Object_feature(pSample->GetFeature()->Reference()));
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// ml.svm.sample(label:number, feature:ml.svm.feature) {block?}
Gura_DeclareFunction(sample)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "label", VTYPE_number);
	DeclareArg(env, "feature", VTYPE_feature);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(sample));
	AddHelp(
		Gura_Symbol(en),
		"Creates an instance of ml.svm.sample.\n");
}

Gura_ImplementFunction(sample)
{
	double label = arg.GetDouble(0);
	Feature *pFeature = Object_feature::GetObject(arg, 1)->GetEntity();
	AutoPtr<Sample> pSample(new Sample(label, pFeature->Reference()));
	return ReturnValue(env, arg, Value(new Object_sample(pSample.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(sample)
{
	// Assignment of properties
	Gura_AssignProperty(sample, label);
	Gura_AssignProperty(sample, feature);
	// Assignment of function
	Gura_AssignFunction(sample);
}

//-----------------------------------------------------------------------------
// Iterator_sample
//-----------------------------------------------------------------------------
Iterator *Iterator_sample::GetSource()
{
	return nullptr;
}

bool Iterator_sample::DoNext(Environment &env, Value &value)
{
	if (_idx >= _pSampleOwner->size()) return false;
	value = Value(new Object_sample((*_pSampleOwner)[_idx]->Reference()));
	_idx++;
	return true;
}

String Iterator_sample::ToString() const
{
	return "ml.svm.sample";
}

void Iterator_sample::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

Gura_EndModuleScope(ml_svm)
