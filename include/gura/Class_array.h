//=============================================================================
// Gura class: array
//=============================================================================
#ifndef __GURA_CLASS_ARRAY_H__
#define __GURA_CLASS_ARRAY_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_array
//-----------------------------------------------------------------------------
template<typename T_Elem>
class GURA_DLLDECLARE Object_array : public Object {
public:
	Gura_DeclareObjectAccessor(array)
private:
	AutoPtr<Array<T_Elem> > _pArray;
public:
	Object_array(Environment &env, ValueType valType, Array<T_Elem> *pArray) :
				Object(env.LookupClass(valType)), _pArray(pArray) {}
	Object_array(Class *pClass, Array<T_Elem> *pArray) :
				Object(pClass), _pArray(pArray) {}
	inline Array<T_Elem> *GetArray() { return _pArray.get(); }
	inline const Array<T_Elem> *GetArray() const { return _pArray.get(); }
	virtual Object *Clone() const { return NULL; }
	virtual String ToString(bool exprFlag) {
		char buff[64];
		String str;
		str += "<array:";
		::sprintf(buff, "%ldelements", _pArray->GetSize());
		str += buff;
		str += ">";
		return str;
	}
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx) {
		if (!valueIdx.Is_number()) {
			sig.SetError(ERR_ValueError, "index must be a number");
			return Value::Null;
		}
		size_t idx = valueIdx.GetSizeT();
		if (idx >= _pArray->GetSize()) {
			sig.SetError(ERR_OutOfRangeError, "index is out of range");
			return Value::Null;
		}
		return Value(*_pArray->GetPointer(idx));
	}
	virtual void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value) {
		if (!valueIdx.Is_number()) {
			sig.SetError(ERR_ValueError, "index must be a number");
			return;
		}
		size_t idx = valueIdx.GetSizeT();
		if (idx >= _pArray->GetSize()) {
			sig.SetError(ERR_OutOfRangeError, "index is out of range");
			return;
		}
		*_pArray->GetPointer(idx) = static_cast<T_Elem>(value.GetNumber());
	}
};

//-----------------------------------------------------------------------------
// Class_array
//-----------------------------------------------------------------------------
template<typename T_Elem>
class GURA_DLLDECLARE Class_array : public Class {
private:
	const char *_funcName;
public:
	class Func_array : public Function {
	private:
		ValueType _valType;
	public:
		Func_array(Environment &env, const char *name, ValueType valType) :
				Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None),
				_valType(valType) {
			SetFuncAttr(valType, RSLTMODE_Normal, FLAG_None);
			DeclareArg(env, "arg", VTYPE_any, OCCUR_Once);
			SetClassToConstruct(env.LookupClass(valType));
			DeclareBlock(OCCUR_ZeroOrOnce);
		}
		virtual Value DoEval(Environment &env, Signal sig, Args &args) const {
			AutoPtr<Array<T_Elem> > pArray;
			if (args.Is_number(0)) {
				pArray.reset(new Array<T_Elem>(args.GetSizeT(0)));
			} else if (args.Is_list(0)) {
				const ValueList &valList = args.GetList(0);
				pArray.reset(new Array<T_Elem>(valList.size()));
				T_Elem *p = pArray->GetPointer(0);
				foreach_const (ValueList, pValue, valList) {
					if (!pValue->Is_number()) {
						sig.SetError(ERR_ValueError, "element must be a number");
						return Value::Null;
					}
					*p++ = static_cast<T_Elem>(pValue->GetNumber());
				}
			} else {
				Declaration::SetError_InvalidArgument(sig);
				return Value::Null;
			}
			return new Object_array<T_Elem>(env, _valType, pArray.release());
		}
	};																	\
public:
	Class_array(Environment *pEnvOuter, ValueType valType, const char *funcName) :
						Class(pEnvOuter, valType), _funcName(funcName) {}
	virtual void Prepare(Environment &env) {
		env.AssignFunction(new Func_array(env, _funcName, GetValueType()));
	}
};

}

#endif
