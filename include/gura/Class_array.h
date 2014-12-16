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
		str += "<";
		str += GetClassName();
		str += ":";
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
		return Value(_pArray->GetPointer()[idx]);
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
		_pArray->GetPointer()[idx] = static_cast<T_Elem>(value.GetNumber());
	}
};

//-----------------------------------------------------------------------------
// Class_array
//-----------------------------------------------------------------------------
template<typename T_Elem>
class GURA_DLLDECLARE Class_array : public Class {
public:
	// array@char(arg), array@uchar(arg)
	// array@short(arg), array@ushort(arg)
	// array@long(arg), array@ulong(arg)
	// array@float(arg), array@double(arg)
	class Func_array : public Function {
	private:
		ValueType _valType;
	public:
		Func_array(Environment &env, const Symbol *pSymbol, ValueType valType) :
				Function(env, pSymbol, FUNCTYPE_Function, FLAG_None), _valType(valType) {
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
				pArray.reset(Array<T_Elem>::CreateFromList(sig, valList));
				if (pArray.IsNull()) return Value::Null;
			} else {
				Declaration::SetError_InvalidArgument(sig);
				return Value::Null;
			}
			Value value(new Object_array<T_Elem>(env, _valType, pArray.release()));
			return ReturnValue(env, sig, args, value);
		}
	};
	// array#each() {block?}
	class Func_each : public Function {
	private:
		ValueType _valType;
	public:
		Func_each(Environment &env, ValueType valType) :
				Function(env, Symbol::Add("each"), FUNCTYPE_Instance, FLAG_None),
				_valType(valType) {
			SetFuncAttr(valType, RSLTMODE_Normal, FLAG_None);
			DeclareBlock(OCCUR_ZeroOrOnce);
			AddHelp(
				Gura_Symbol(en), Help::FMT_markdown,
				"Creates an iterator that iterates each element in the array.\n"
			);
		}
		virtual Value DoEval(Environment &env, Signal sig, Args &args) const {
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetThisObj(args)->GetArray();
			AutoPtr<Iterator> pIterator(pArray->CreateIterator());
			return ReturnIterator(env, sig, args, pIterator.release());
		}
	};
	// array#head(n:number):map {block?}
	class Func_head : public Function {
	private:
		ValueType _valType;
	public:
		Func_head(Environment &env, ValueType valType) :
				Function(env, Symbol::Add("head"), FUNCTYPE_Instance, FLAG_None),
				_valType(valType) {
			SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
			DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
			DeclareBlock(OCCUR_ZeroOrOnce);
			AddHelp(
				Gura_Symbol(en), Help::FMT_markdown,
				"Creates an array that extracts specified number of elements at the beginning of the source.\n"
			);
		}
		virtual Value DoEval(Environment &env, Signal sig, Args &args) const {
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetThisObj(args)->GetArray();
			size_t n = args.GetSizeT(0);
			if (n > pArray->GetSize()) {
				sig.SetError(ERR_OutOfRangeError, "offset is out of range");
				return Value::Null;
			}
			size_t offsetBase = pArray->GetOffsetBase();
			AutoPtr<Array<T_Elem> > pArrayRtn(
				new Array<T_Elem>(pArray->GetMemory()->Reference(), n, offsetBase));
			Value value(new Object_array<T_Elem>(env, _valType, pArrayRtn.release()));
			return ReturnValue(env, sig, args, value);
		}
	};
	// array#offset(n:number):map {block?}
	class Func_offset : public Function {
	private:
		ValueType _valType;
	public:
			Func_offset(Environment &env, ValueType valType) :
				Function(env, Symbol::Add("offset"), FUNCTYPE_Instance, FLAG_None),
				_valType(valType) {
			SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
			DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
			DeclareBlock(OCCUR_ZeroOrOnce);
			AddHelp(
				Gura_Symbol(en), Help::FMT_markdown,
				"Creates an array that skips `n` elements of the source.\n"
			);
		}
		virtual Value DoEval(Environment &env, Signal sig, Args &args) const {
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetThisObj(args)->GetArray();
			size_t n = args.GetSizeT(0);
			if (n > pArray->GetSize()) {
				sig.SetError(ERR_OutOfRangeError, "offset is out of range");
				return Value::Null;
			}
			size_t cnt = pArray->GetSize() - n;
			size_t offsetBase = pArray->GetOffsetBase() + n;
			AutoPtr<Array<T_Elem> > pArrayRtn(
				new Array<T_Elem>(pArray->GetMemory()->Reference(), cnt, offsetBase));
			Value value(new Object_array<T_Elem>(env, _valType, pArrayRtn.release()));
			return ReturnValue(env, sig, args, value);
		}
	};
	// array#tail(n:number):map {block?}
	class Func_tail : public Function {
	private:
		ValueType _valType;
	public:
		Func_tail(Environment &env, ValueType valType) :
				Function(env, Symbol::Add("tail"), FUNCTYPE_Instance, FLAG_None),
				_valType(valType) {
			SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
			DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
			DeclareBlock(OCCUR_ZeroOrOnce);
			AddHelp(
				Gura_Symbol(en), Help::FMT_markdown,
				"Creates an array that extracts specified number of elements at the bottom of the source.\n"
			);
		}
		virtual Value DoEval(Environment &env, Signal sig, Args &args) const {
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetThisObj(args)->GetArray();
			size_t n = args.GetSizeT(0);
			if (n > pArray->GetSize()) {
				sig.SetError(ERR_OutOfRangeError, "offset is out of range");
				return Value::Null;
			}
			size_t offsetBase = pArray->GetOffsetBase() + pArray->GetSize() - n;
			AutoPtr<Array<T_Elem> > pArrayRtn(
				new Array<T_Elem>(pArray->GetMemory()->Reference(), n, offsetBase));
			Value value(new Object_array<T_Elem>(env, _valType, pArrayRtn.release()));
			return ReturnValue(env, sig, args, value);
		}
	};
public:
	Class_array(Environment *pEnvOuter, ValueType valType) : Class(pEnvOuter, valType) {}
	virtual void Prepare(Environment &env) {
		const Symbol *pSymbol = ValueTypePool::GetInstance()->Lookup(GetValueType())->GetSymbol();
		env.AssignFunction(new Func_array(env, pSymbol, GetValueType()));
		AssignFunction(new Func_each(*this, GetValueType()));
		AssignFunction(new Func_head(*this, GetValueType()));
		AssignFunction(new Func_offset(*this, GetValueType()));
		AssignFunction(new Func_tail(*this, GetValueType()));
	}
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl) {
		if (value.Is_list()) {
			AutoPtr<Array<T_Elem> > pArray(Array<T_Elem>::CreateFromList(sig, value.GetList()));
			if (pArray.IsNull()) return false;
			value = Value(new Object_array<T_Elem>(env, GetValueType(), pArray.release()));
			return true;
		}
		return false;
	}
	virtual bool CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl) {
		if (decl.IsType(VTYPE_list)) {
			AutoPtr<Iterator> pIterator(Object_array<T_Elem>::GetObject(value)->
													GetArray()->CreateIterator());
			value = pIterator->ToList(env, sig, true, false);
			return !sig.IsSignalled();
		} else if (decl.IsType(VTYPE_iterator)) {
			AutoPtr<Iterator> pIterator(Object_array<T_Elem>::GetObject(value)->
													GetArray()->CreateIterator());
			value = Value(new Object_iterator(env, pIterator.release()));
			return true;
		}
		return false;
	}
};

}

#endif
