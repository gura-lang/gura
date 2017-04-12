#include "stdafx.h"
#include "Class_sample.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_sample implementation
//-----------------------------------------------------------------------------
Object_sample::Object_sample(Sample *pSample) :
					Object(Gura_UserClass(sample)), _pSample(pSample)
{
}

String Object_sample::ToString(bool exprFlag)
{
	return String("<ml.linear.sample>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.linear.sample#label
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

// ml.linear.sample#feature
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

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(sample)
{
	// Assignment of properties
	Gura_AssignProperty(sample, label);
	Gura_AssignProperty(sample, feature);
	// Assignment of function
	//Gura_AssignFunction(sample);
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
	return "ml.linear.sample";
}

void Iterator_sample::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

Gura_EndModuleScope(ml_linear)
