#include "stdafx.h"

Gura_BeginModuleScope(llvm)

//-----------------------------------------------------------------------------
// Iterator_IdentifierInMember
//-----------------------------------------------------------------------------
Iterator_IdentifierInMember::Iterator_IdentifierInMember(Environment *pEnv, Signal &sig,
									   Iterator *pIterator, const Symbol *pSymbol) :
		Iterator(pIterator->IsInfinite()), _pEnv(pEnv), _sig(sig),
		_pIterator(pIterator), _pSymbol(pSymbol)
{
}

Iterator_IdentifierInMember::~Iterator_IdentifierInMember()
{
	if (IsVirgin()) Consume(*_pEnv, _sig);
}

Iterator *Iterator_IdentifierInMember::GetSource()
{
	return _pIterator.get();
}

bool Iterator_IdentifierInMember::DoNext(Environment &env, Signal &sig, Value &value)
{
	Value valueThis;
	if (!_pIterator->Next(env, sig, valueThis)) return false;
	Fundamental *pFund = valueThis.IsPrimitive()?
		env.LookupClass(valueThis.GetValueType()) : valueThis.ExtractFundamental(sig);
	if (pFund == nullptr) return false;
	Value *pValue = pFund->LookupValue(_pSymbol, ENVREF_Escalate);
	if (pValue == nullptr) {
		sig.SetError(ERR_ValueError, "undefined member variable %s", _pSymbol->GetName());
		return false;
	}
	if (pValue->Is_function()) {
		Object_function *pObjFunc =
			dynamic_cast<Object_function *>(Object_function::GetObject(*pValue)->Clone());
		pObjFunc->SetThis(valueThis);
		Gura_CopyValue(value, Value(pObjFunc));
	} else {
		Gura_CopyValue(value, *pValue);
	}
	return true;
}

String Iterator_IdentifierInMember::ToString() const
{
	String rtn;
	rtn += "member_map(";
	rtn += _pSymbol->GetName();
	rtn += ";";
	rtn += _pIterator->ToString();
	rtn += ")";
	return rtn;
}

void Iterator_IdentifierInMember::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_CallerInMember
//-----------------------------------------------------------------------------
Iterator_CallerInMember::Iterator_CallerInMember(
	Environment *pEnv, Signal &sig,
	Iterator *pIterator, const Symbol *pSymbol, const BridgeFunctionT bridgeFunc) :
	Iterator(pIterator->IsInfinite()), _pEnv(pEnv), _sig(sig),
	_pIterator(pIterator), _pSymbol(pSymbol), _bridgeFunc(bridgeFunc)
{
}

Iterator_CallerInMember::~Iterator_CallerInMember()
{
	if (IsVirgin()) Consume(*_pEnv, _sig);
}

Iterator *Iterator_CallerInMember::GetSource()
{
	return _pIterator.get();
}

bool Iterator_CallerInMember::DoNext(Environment &env, Signal &sig, Value &value)
{
	Value valueThis;
	if (!_pIterator->Next(env, sig, valueThis)) return false;
	Fundamental *pFund = valueThis.IsPrimitive()?
		env.LookupClass(valueThis.GetValueType()) : valueThis.ExtractFundamental(sig);
	if (pFund == nullptr) return false;
	Value *pValue = pFund->LookupValue(_pSymbol, ENVREF_Escalate);
	if (pValue == nullptr) {
		sig.SetError(ERR_ValueError, "undefined member variable %s", _pSymbol->GetName());
		return false;
	}
	(*_bridgeFunc)(env, valueThis, value);
	return true;
}

String Iterator_CallerInMember::ToString() const
{
	String rtn;
	rtn += "member_map(";
	rtn += _pSymbol->GetName();
	rtn += ";";
	rtn += _pIterator->ToString();
	rtn += ")";
	return rtn;
}

void Iterator_CallerInMember::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

Gura_EndModuleScope(llvm)
