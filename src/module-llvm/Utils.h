#ifndef __GURA_MODULE_LLVM_UTILS_H__
#define __GURA_MODULE_LLVM_UTILS_H__
#include <gura.h>

Gura_BeginModuleScope(llvm)
//-----------------------------------------------------------------------------
// Restorer
//-----------------------------------------------------------------------------
template<typename T> class Restorer {
private:
	T &_target;
	T _valueOrg;
public:
	inline Restorer(T &target, T value) : _target(target), _valueOrg(target) {
		_target = value;
	}
	inline ~Restorer() {
		_target = _valueOrg;
	}
};

//-----------------------------------------------------------------------------
// Iterator_IdentifierInMember
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Iterator_IdentifierInMember : public Iterator {
private:
	AutoPtr<Environment> _pEnv;
	Signal &_sig;
	AutoPtr<Iterator> _pIterator;
	const Symbol *_pSymbol;
public:
	Iterator_IdentifierInMember(Environment *pEnv, Signal &sig, Iterator *pIterator, const Symbol *pSymbol);
	virtual ~Iterator_IdentifierInMember();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal &sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleScope(llvm)

#endif
