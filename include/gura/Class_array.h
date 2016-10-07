//=============================================================================
// Gura class: arrayT
//=============================================================================
#ifndef __GURA_CLASS_ARRAYT_H__
#define __GURA_CLASS_ARRAYT_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_arrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Object_arrayT : public Object {
public:
	Gura_DeclareObjectAccessor(arrayT)
private:
	AutoPtr<ArrayT<T_Elem> > _pArrayT;
public:
	Object_arrayT(Environment &env, ValueType valType, ArrayT<T_Elem> *pArrayT) :
				Object(env.LookupClass(valType)), _pArrayT(pArrayT) {}
	Object_arrayT(Class *pClass, ArrayT<T_Elem> *pArrayT) :
				Object(pClass), _pArrayT(pArrayT) {}
	inline ArrayT<T_Elem> *GetArrayT() { return _pArrayT.get(); }
	inline const ArrayT<T_Elem> *GetArrayT() const { return _pArrayT.get(); }
	virtual Object *Clone() const { return nullptr; }
	virtual String ToString(bool exprFlag) {
		char buff[64];
		String str;
		str += "<";
		str += GetClassName();
		str += ":";
		::sprintf(buff, "%ldelements", _pArrayT->GetSize());
		str += buff;
		str += ">";
		return str;
	}
	virtual Value IndexGet(Environment &env, const Value &valueIdx) {
		Signal &sig = GetSignal();
		if (!valueIdx.Is_number()) {
			sig.SetError(ERR_ValueError, "index must be a number");
			return Value::Nil;
		}
		size_t idx = valueIdx.GetSizeT();
		if (idx >= _pArrayT->GetSize()) {
			sig.SetError(ERR_OutOfRangeError, "index is out of range");
			return Value::Nil;
		}
		return Value(_pArrayT->GetPointer()[idx]);
	}
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value) {
		Signal &sig = GetSignal();
		if (!valueIdx.Is_number()) {
			sig.SetError(ERR_ValueError, "index must be a number");
			return;
		}
		size_t idx = valueIdx.GetSizeT();
		if (idx >= _pArrayT->GetSize()) {
			sig.SetError(ERR_OutOfRangeError, "index is out of range");
			return;
		}
		_pArrayT->GetPointer()[idx] = static_cast<T_Elem>(value.GetNumber());
	}
};

//-----------------------------------------------------------------------------
// Class_arrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Class_arrayT : public Class {
public:
	// array@T(arg) {block?}
	class Func_Constructor : public Function {
	private:
		ValueType _valType;
	public:
		Func_Constructor(Environment &env, const Symbol *pSymbol, ValueType valType) :
				Function(env, pSymbol, FUNCTYPE_Function, FLAG_None), _valType(valType) {
			SetFuncAttr(valType, RSLTMODE_Normal, FLAG_None);
			DeclareArg(env, "arg", VTYPE_any, OCCUR_Once);
			DeclareArg(env, "init", VTYPE_number, OCCUR_ZeroOrOnce);
			SetClassToConstruct(env.LookupClass(valType));
			DeclareBlock(OCCUR_ZeroOrOnce);
			AddHelp(
				Gura_Symbol(en),
				"Creates an `array@T` instance.\n"
				"You can call this function in the following formats:\n"
				"\n"
				"- `array@T(len:number, init?:number)` .. Creates an `array@T` instance that has\n"
				"  specified length of buffer. If the argument `init` is specified, the buffer would be\n"
				"  initialized with the value.\n"
				"- `array@T(list:list)` .. Creates an `array@T` instance initialized with\n"
				"  numbers contained in `list`.\n"
				"\n"
				GURA_HELPTEXT_BLOCK_en("array", "array@T")
			);
		}
		virtual Value DoEval(Environment &env, Argument &arg) const {
			Signal &sig = env.GetSignal();
			AutoPtr<ArrayT<T_Elem> > pArrayT;
			if (arg.Is_number(0)) {
				pArrayT.reset(new ArrayT<T_Elem>(arg.GetSizeT(0)));
				if (arg.Is_number(1)) {
					pArrayT->Fill(static_cast<T_Elem>(arg.GetNumber(1)));
				} else {
					pArrayT->FillZero();
				}
			} else if (arg.Is_list(0)) {
				const ValueList &valList = arg.GetList(0);
				pArrayT.reset(CreateArrayTFromList<T_Elem>(sig, valList));
				if (pArrayT.IsNull()) return Value::Nil;
			} else {
				Declaration::SetError_InvalidArgument(env);
				return Value::Nil;
			}
			Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayT.release()));
			return ReturnValue(env, arg, value);
		}
	};
	// @T() {block}
	class Func_Initializer : public Function {
	private:
		ValueType _valType;
	public:
		Func_Initializer(Environment &env, const Symbol *pSymbol, ValueType valType) :
				Function(env, pSymbol, FUNCTYPE_Function, FLAG_None), _valType(valType) {
			SetFuncAttr(valType, RSLTMODE_Normal, FLAG_None);
			DeclareBlock(OCCUR_Once);
			AddHelp(
				Gura_Symbol(en),
				"Creates an `array@T` instance that is initialized with values described in `block`.\n"
				"\n"
				"The code below creates an `array@uchar` instance that has four elements.\n"
				"\n"
				"    @uchar { 0x01, 0x23, 0x45, 0x67 }\n"
				"\n"
				"The code below creates an `array@ushort` instance that has three elements.\n"
				"\n"
				"    @ushort { 0x0123, 0x4567, 0x89ab }\n"
			);
		}
		virtual Value DoEval(Environment &env, Argument &arg) const {
			Signal &sig = env.GetSignal();
			const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
			const ExprOwner &exprOwner = pExprBlock->GetExprOwner();
			AutoPtr<ArrayT<T_Elem> > pArrayT(new ArrayT<T_Elem>(exprOwner.size()));
			T_Elem *p = pArrayT->GetPointer();
			foreach_const (ExprOwner, ppExpr, exprOwner) {
				const Expr *pExpr = *ppExpr;
				if (pExpr->IsBlock()) {
					sig.SetError(ERR_ValueError, "invalid element for array initialization");
					return Value::Nil;
				}
				Value value = pExpr->Exec(env);
				if (!value.Is_number() && !value.Is_boolean()) {
					sig.SetError(ERR_ValueError, "invalid element for array initialization");
					return Value::Nil;
				}
				*p++ = static_cast<T_Elem>(value.GetNumber());
			}
			return Value(new Object_arrayT<T_Elem>(env, _valType, pArrayT.release()));
		}
	};
	// array@T#each() {block?}
	class Func_each : public Function {
	private:
		ValueType _valType;
	public:
		Func_each(Environment &env, ValueType valType) :
				Function(env, Symbol::Add("each"), FUNCTYPE_Instance, FLAG_None),
				_valType(valType) {
			SetFuncAttr(VTYPE_iterator, RSLTMODE_Normal, FLAG_None);
			DeclareBlock(OCCUR_ZeroOrOnce);
			AddHelp(
				Gura_Symbol(en),
				"Creates an iterator that iterates each element in the array.\n"
				"\n"
				GURA_HELPTEXT_ITERATOR_en()
				"\n"
				"The block parameter is `|elem:number, idx:number|`\n"
				"where `elem` is the element value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Argument &arg) const {
			const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
			AutoPtr<Iterator> pIterator(new Iterator_ArrayT<T_Elem>(pArrayT->Reference()));
			return ReturnIterator(env, arg, pIterator.release());
		}
	};
	// array@T#dump():void
	class Func_dump : public Function {
	private:
		ValueType _valType;
	public:
		Func_dump(Environment &env, ValueType valType) :
				Function(env, Symbol::Add("dump"), FUNCTYPE_Instance, FLAG_None),
				_valType(valType) {
			SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
			DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
			DeclareAttr(Gura_Symbol(upper));
			AddHelp(
				Gura_Symbol(en),
				"Prints out a binary dump of the array's content.\n"
			);
		}
		virtual Value DoEval(Environment &env, Argument &arg) const {
			Signal &sig = env.GetSignal();
			const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
			bool upperFlag = arg.IsSet(Gura_Symbol(upper));
			Stream *pStream = arg.IsValid(0)?
				&Object_stream::GetObject(arg, 0)->GetStream() : env.GetConsole();
			pArrayT->Dump(sig, *pStream, upperFlag);
			return Value::Nil;
		}
	};
	// array@T#fill(value:number):void
	class Func_fill : public Function {
	private:
		ValueType _valType;
	public:
		Func_fill(Environment &env, ValueType valType) :
				Function(env, Symbol::Add("fill"), FUNCTYPE_Instance, FLAG_None),
				_valType(valType) {
			SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
			DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
			AddHelp(
				Gura_Symbol(en),
				"Fills array with a specified value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Argument &arg) const {
			ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
			pArrayT->Fill(static_cast<T_Elem>(arg.GetNumber(0)));
			return Value::Nil;
		}
	};
	// array@T#head(n:number):map {block?}
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
				Gura_Symbol(en),
				"Creates an array that has extracted specified number of elements\n"
				"from the beginning of the source.\n"
				"\n"
				"If `block` is specified, it would be evaluated with a block parameter\n"
				"`|array:array@T|`, where `array` is the created instance.\n"
				"In this case, the block's result would become the function's returned value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Argument &arg) const {
			Signal &sig = env.GetSignal();
			const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
			size_t n = arg.GetSizeT(0);
			if (n > pArrayT->GetSize()) {
				sig.SetError(ERR_OutOfRangeError, "offset is out of range");
				return Value::Nil;
			}
			size_t offsetBase = pArrayT->GetOffsetBase();
			AutoPtr<ArrayT<T_Elem> > pArrayTRtn(
				new ArrayT<T_Elem>(pArrayT->GetMemory().Reference(), n, offsetBase));
			Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayTRtn.release()));
			return ReturnValue(env, arg, value);
		}
	};
	// array@T#offset(n:number):map {block?}
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
				Gura_Symbol(en),
				"Creates an array that has extracted elements of the source\n"
				"after skipping the first `n` elements.\n"
				"\n"
				"If `block` is specified, it would be evaluated with a block parameter\n"
				"`|array:array@T|`, where `array` is the created instance.\n"
				"In this case, the block's result would become the function's returned value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Argument &arg) const {
			Signal &sig = env.GetSignal();
			const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
			size_t n = arg.GetSizeT(0);
			if (n > pArrayT->GetSize()) {
				sig.SetError(ERR_OutOfRangeError, "offset is out of range");
				return Value::Nil;
			}
			size_t cnt = pArrayT->GetSize() - n;
			size_t offsetBase = pArrayT->GetOffsetBase() + n;
			AutoPtr<ArrayT<T_Elem> > pArrayTRtn(
				new ArrayT<T_Elem>(pArrayT->GetMemory().Reference(), cnt, offsetBase));
			Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayTRtn.release()));
			return ReturnValue(env, arg, value);
		}
	};
	// array@T#paste(offset:number, src:array):map:void
	class Func_paste : public Function {
	private:
		ValueType _valType;
	public:
		Func_paste(Environment &env, ValueType valType) :
				Function(env, Symbol::Add("paste"), FUNCTYPE_Instance, FLAG_None),
				_valType(valType) {
			SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
			DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
			DeclareArg(env, "src", valType, OCCUR_Once);
			AddHelp(
				Gura_Symbol(en),
				"Pastes elements of `src` into the target `array` instance.\n"
				"\n"
				"The argument `offset` specifies the posision where elements are pasted in\n"
			);
		}
		virtual Value DoEval(Environment &env, Argument &arg) const {
			Signal &sig = env.GetSignal();
			ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
			size_t offset = arg.GetSizeT(0);
			const ArrayT<T_Elem> *pArrayTSrc = Object_arrayT<T_Elem>::GetObject(arg, 1)->GetArrayT();
			pArrayT->Paste(sig, offset, pArrayTSrc);
			return Value::Nil;
		}
	};
	// array@T#tail(n:number):map {block?}
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
				Gura_Symbol(en),
				"Creates an array that has extracted specified number of elements\n"
				"from the bottom of the source.\n"
				"\n"
				"If `block` is specified, it would be evaluated with a block parameter\n"
				"`|array:array@T|`, where `array` is the created instance.\n"
				"In this case, the block's result would become the function's returned value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Argument &arg) const {
			Signal &sig = env.GetSignal();
			const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
			size_t n = arg.GetSizeT(0);
			if (n > pArrayT->GetSize()) {
				sig.SetError(ERR_OutOfRangeError, "offset is out of range");
				return Value::Nil;
			}
			size_t offsetBase = pArrayT->GetOffsetBase() + pArrayT->GetSize() - n;
			AutoPtr<ArrayT<T_Elem> > pArrayTRtn(
				new ArrayT<T_Elem>(pArrayT->GetMemory().Reference(), n, offsetBase));
			Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayTRtn.release()));
			return ReturnValue(env, arg, value);
		}
	};
private:
	String _elemName;
public:
	Class_arrayT(Environment *pEnvOuter, ValueType valType, const String &elemName) :
							Class(pEnvOuter, valType), _elemName(elemName) {}
	virtual void Prepare(Environment &env) {
		do {
			const Symbol *pSymbol = ValueTypePool::GetInstance()->
									Lookup(GetValueType())->GetSymbol();
			env.AssignFunction(new Func_Constructor(env, pSymbol, GetValueType()));
		} while (0);
		do {
			String funcName;
			funcName += "@";
			funcName += _elemName;
			const Symbol *pSymbol = Symbol::Add(funcName.c_str());
			env.AssignFunction(new Func_Initializer(env, pSymbol, GetValueType()));
		} while (0);
		AssignFunction(new Func_dump(*this, GetValueType()));
		AssignFunction(new Func_each(*this, GetValueType()));
		AssignFunction(new Func_fill(*this, GetValueType()));
		AssignFunction(new Func_head(*this, GetValueType()));
		AssignFunction(new Func_offset(*this, GetValueType()));
		AssignFunction(new Func_paste(*this, GetValueType()));
		AssignFunction(new Func_tail(*this, GetValueType()));
	}
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl) {
		Signal &sig = GetSignal();
		if (value.Is_list()) {
			AutoPtr<ArrayT<T_Elem> > pArrayT(CreateArrayTFromList<T_Elem>(sig, value.GetList()));
			if (pArrayT.IsNull()) return false;
			value = Value(new Object_arrayT<T_Elem>(env, GetValueType(), pArrayT.release()));
			return true;
		}
		return false;
	}
	virtual bool CastTo(Environment &env, Value &value, const Declaration &decl) {
		if (decl.IsType(VTYPE_list)) {
			AutoPtr<ArrayT<T_Elem> > pArrayT(
				Object_arrayT<T_Elem>::GetObject(value)->GetArrayT()->Reference());
			Object_list *pObjList = value.InitAsList(env);
			pObjList->Reserve(pArrayT->GetSize());
			CopyArrayTToList(pArrayT.get(), pObjList->GetListForModify());
			pObjList->SetValueType(VTYPE_number);
			return true;
		} else if (decl.IsType(VTYPE_iterator)) {
			const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObject(value)->GetArrayT();
			AutoPtr<Iterator> pIterator(new Iterator_ArrayT<T_Elem>(pArrayT->Reference()));
			value = Value(new Object_iterator(env, pIterator.release()));
			return true;
		}
		return false;
	}
};

}

#endif
