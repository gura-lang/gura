//=============================================================================
// Gura class: function
//=============================================================================
#ifndef __GURA_CLASS_FUNCTION_H__
#define __GURA_CLASS_FUNCTION_H__

#include "Class.h"
#include "Expr.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_function
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_function : public ClassFundamental {
public:
	Class_function(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual SerializeFmtVer GetSerializeFmtVer() const;
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const;
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_function
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_function : public Object {
public:
	Gura_DeclareObjectAccessor(function)
protected:
	AutoPtr<Function> _pFunc;
	Value _valueThis;
public:
	inline Object_function(Environment &env, Function *pFunc) :
		Object(env.LookupClass(VTYPE_function)), _pFunc(pFunc) {}
	inline Object_function(Environment &env, Function *pFunc, const Value &valueThis) :
		Object(env.LookupClass(VTYPE_function)), _pFunc(pFunc), _valueThis(valueThis) {}
	inline Object_function(Class *pClass, Function *pFunc) :
		Object(pClass), _pFunc(pFunc) {}
	inline Object_function(Class *pClass, Function *pFunc, const Value &valueThis) :
		Object(pClass), _pFunc(pFunc), _valueThis(valueThis) {}
	inline Object_function(const Object_function &obj) :
		Object(obj), _pFunc(Function::Reference(obj._pFunc.get())),
		_valueThis(obj._valueThis) {}
	~Object_function();
	virtual bool IsFunction() const;
	virtual Object *Clone() const;
	inline Function *GetFunction() { return _pFunc.get(); }
	inline const Function *GetFunction() const { return _pFunc.get(); }
	inline void SetValueThis(const Value &valueThis) { _valueThis = valueThis; }
	inline Value GetValueThis() const { return _valueThis; }
	virtual String ToString(bool exprFlag);
	virtual bool IsLeader() const;
	virtual bool IsTrailer() const;
	virtual bool IsFinalizer() const;
	virtual bool IsEndMarker() const;
	virtual OccurPattern GetBlockOccurPattern() const;
	virtual Value DoCall(
		Environment &env, const CallerInfo &callerInfo, ULong flags,
		const Value &valueThis, const Iterator *pIteratorThis,
		const TrailCtrlHolder *pTrailCtrlHolder);
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	Value Eval(Environment &env) const;
	Value Eval(Environment &env, const Value &v1) const;
	Value Eval(Environment &env, const Value &v1, const Value &v2) const;
	Value Eval(Environment &env, const Value &v1, const Value &v2, const Value &v3) const;
	Value Eval(Environment &env, const Value &v1, const Value &v2, const Value &v3, const Value &v4) const;
	Value Eval(Environment &env, const ValueList &valList) const;
};

}

#endif
