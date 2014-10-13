#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_HapticEffect implementation
//-----------------------------------------------------------------------------
Object_HapticEffect::~Object_HapticEffect()
{
	//::SDL_HapticEffectClose(_pHapticEffect);
}

Object *Object_HapticEffect::Clone() const
{
	return NULL;
}

String Object_HapticEffect::ToString(bool exprFlag)
{
	return String("<sdl2.HapticEffect>");
}

bool Object_HapticEffect::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	Uint16 type = _pHapticEffect->type;
	if (type == SDL_HAPTIC_CONSTANT) {

	} else if (type == SDL_HAPTIC_SINE ||
			   //type == SDL_HAPTIC_SQUARE ||
			   type == SDL_HAPTIC_TRIANGLE ||
			   type == SDL_HAPTIC_SAWTOOTHUP ||
			   type == SDL_HAPTIC_SAWTOOTHDOWN) {

	} else if (type == SDL_HAPTIC_SPRING ||
			   type == SDL_HAPTIC_DAMPER ||
			   type == SDL_HAPTIC_INERTIA ||
			   type == SDL_HAPTIC_FRICTION) {

	} else if (type == SDL_HAPTIC_RAMP) {

	} else if (type == SDL_HAPTIC_LEFTRIGHT) {

	} else if (type == SDL_HAPTIC_CUSTOM) {

	}
	return true;
}

Value Object_HapticEffect::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	Uint16 type = _pHapticEffect->type;
	if (type == SDL_HAPTIC_CONSTANT) {
		SDL_HapticConstant &effect = _pHapticEffect->constant;
	} else if (type == SDL_HAPTIC_SINE ||
			   //type == SDL_HAPTIC_SQUARE ||
			   type == SDL_HAPTIC_TRIANGLE ||
			   type == SDL_HAPTIC_SAWTOOTHUP ||
			   type == SDL_HAPTIC_SAWTOOTHDOWN) {
		SDL_HapticPeriodic &effect = _pHapticEffect->periodic;
	} else if (type == SDL_HAPTIC_SPRING ||
			   type == SDL_HAPTIC_DAMPER ||
			   type == SDL_HAPTIC_INERTIA ||
			   type == SDL_HAPTIC_FRICTION) {
		SDL_HapticCondition &effect = _pHapticEffect->condition;
	} else if (type == SDL_HAPTIC_RAMP) {
		SDL_HapticRamp &effect = _pHapticEffect->ramp;
	} else if (type == SDL_HAPTIC_LEFTRIGHT) {
		SDL_HapticLeftRight &effect = _pHapticEffect->leftright;
	} else if (type == SDL_HAPTIC_CUSTOM) {
		SDL_HapticCustom &effect = _pHapticEffect->custom;
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_HapticEffect::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for HapticEffect
//-----------------------------------------------------------------------------
// implementation of class HapticEffect
Gura_ImplementUserClass(HapticEffect)
{
}

Gura_EndModuleScope(sdl2)
