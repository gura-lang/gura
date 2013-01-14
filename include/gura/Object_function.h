#ifndef __GURA_OBJECT_FUNCTION_H__
#define __GURA_OBJECT_FUNCTION_H__

#include "Object.h"
#include "Expr.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_function / Object_function
//-----------------------------------------------------------------------------
class DLLDECLARE Class_function : public Class {
public:
	Class_function(Environment *pEnvOuter);
	virtual void Prepare();
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

class DLLDECLARE Object_function : public Object {
public:
	Gura_DeclareObjectAccessor(function)
protected:
	AutoPtr<Function> _pFunc;
	Value _valueSelf;
public:
	inline Object_function(Environment &env, Function *pFunc, const Value &valueSelf) :
				Object(env.LookupClass(VTYPE_function)), _pFunc(pFunc), _valueSelf(valueSelf) {}
	inline Object_function(Class *pClass, Function *pFunc, const Value &valueSelf) :
				Object(pClass), _pFunc(pFunc), _valueSelf(valueSelf) {}
	inline Object_function(const Object_function &obj) :
				Object(obj), _pFunc(Function::Reference(obj._pFunc.get())),
				_valueSelf(obj._valueSelf) {}
	~Object_function();
	virtual bool IsFunction() const;
	virtual Object *Clone() const;
	inline Function *GetFunction() { return _pFunc.get(); }
	inline const Function *GetFunction() const { return _pFunc.get(); }
	inline void SetSelf(const Value &valueSelf) { _valueSelf = valueSelf; }
	inline Value GetSelf() const { return _valueSelf; }
	inline String GetName() const { return _pFunc->GetName(); }
	virtual String GetFullName(Signal sig);
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoSerialize(Signal sig, Stream &stream) const;
	virtual bool DoDeserialize(Signal sig, Stream &stream);
	virtual bool DoPropDir(Signal sig, SymbolSet &symbols);
	virtual Value DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual Value DoPropSet(Signal sig, const Symbol *pSymbol, const Value &value, bool &evaluatedFlag);
	virtual Value DoCall(Environment &env, Signal sig, Args &args);
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	Value Eval(Environment &env, Signal sig, ValueList &valListArg) const;
	String MakePrefix(Signal sig) const;
};

}

#endif
