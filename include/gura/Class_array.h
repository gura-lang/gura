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
class Object_array : public Object {
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
	virtual Object *Clone() const { return nullptr; }
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
	virtual Value IndexGet(Environment &env, const Value &valueIdx) {
		Signal &sig = GetSignal();
		if (!valueIdx.Is_number()) {
			sig.SetError(ERR_ValueError, "index must be a number");
			return Value::Nil;
		}
		size_t idx = valueIdx.GetSizeT();
		if (idx >= _pArray->GetSize()) {
			sig.SetError(ERR_OutOfRangeError, "index is out of range");
			return Value::Nil;
		}
		return Value(_pArray->GetPointer()[idx]);
	}
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value) {
		Signal &sig = GetSignal();
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
class Class_array : public Class {
public:
	// array@T(arg) {block?}
	class Func_array : public Function {
	private:
		ValueType _valType;
	public:
		Func_array(Environment &env, const Symbol *pSymbol, ValueType valType) :
				Function(env, pSymbol, FUNCTYPE_Function, FLAG_None), _valType(valType) {
			SetFuncAttr(valType, RSLTMODE_Normal, FLAG_None);
			DeclareArg(env, "arg", VTYPE_any, OCCUR_Once);
			DeclareArg(env, "init", VTYPE_number, OCCUR_ZeroOrOnce);
			SetClassToConstruct(env.LookupClass(valType));
			DeclareBlock(OCCUR_ZeroOrOnce);
		}
		virtual Value DoEval(Environment &env, Args &args) const {
			Signal &sig = env.GetSignal();
			AutoPtr<Array<T_Elem> > pArray;
			if (args.Is_number(0)) {
				pArray.reset(new Array<T_Elem>(args.GetSizeT(0)));
				if (args.Is_number(1)) {
					pArray->Fill(static_cast<T_Elem>(args.GetNumber(1)));
				} else {
					pArray->FillZero();
				}
			} else if (args.Is_list(0)) {
				const ValueList &valList = args.GetList(0);
				pArray.reset(CreateArrayFromList<T_Elem>(sig, valList));
				if (pArray.IsNull()) return Value::Nil;
			} else {
				Declaration::SetError_InvalidArgument(sig);
				return Value::Nil;
			}
			Value value(new Object_array<T_Elem>(env, _valType, pArray.release()));
			return ReturnValue(env, args, value);
		}
	};
	// @T() {block}
	class Func_ArrayInit : public Function {
	private:
		ValueType _valType;
	public:
		Func_ArrayInit(Environment &env, const Symbol *pSymbol, ValueType valType) :
				Function(env, pSymbol, FUNCTYPE_Function, FLAG_None), _valType(valType) {
			SetFuncAttr(valType, RSLTMODE_Normal, FLAG_None);
			DeclareBlock(OCCUR_Once);
		}
		virtual Value DoEval(Environment &env, Args &args) const {
			Signal &sig = env.GetSignal();
			SeqPostHandler *pSeqPostHandler = nullptr;
			const Expr_Block *pExprBlock = args.GetBlockCooked(env);
			const ExprOwner &exprOwner = pExprBlock->GetExprOwner();
			AutoPtr<Array<T_Elem> > pArray(new Array<T_Elem>(exprOwner.size()));
			T_Elem *p = pArray->GetPointer();
			foreach_const (ExprOwner, ppExpr, exprOwner) {
				const Expr *pExpr = *ppExpr;
				if (pExpr->IsBlock()) {
					sig.SetError(ERR_ValueError, "invalid element for array initialization");
					return Value::Nil;
				}
				Value value = pExpr->Exec2(env, pSeqPostHandler);
				if (!value.Is_number() && !value.Is_boolean()) {
					sig.SetError(ERR_ValueError, "invalid element for array initialization");
					return Value::Nil;
				}
				*p++ = static_cast<T_Elem>(value.GetNumber());
			}
			return Value(new Object_array<T_Elem>(env, _valType, pArray.release()));
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
				Gura_Symbol(en), Help::FMT_markdown,
				"Creates an iterator that iterates each element in the array.\n"
				"\n"
				GURA_HELPTEXT_ITERATOR_en()
				"\n"
				"The block parameter is `|elem:number, idx:number|`\n"
				"where `elem` is the element value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Args &args) const {
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetObjectThis(args)->GetArray();
			AutoPtr<Iterator> pIterator(new Iterator_Array<T_Elem>(pArray->Reference()));
			return ReturnIterator(env, args, pIterator.release());
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
				Gura_Symbol(en), Help::FMT_markdown,
				"Prints out a binary dump of the array's content.\n"
			);
		}
		virtual Value DoEval(Environment &env, Args &args) const {
			Signal &sig = env.GetSignal();
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetObjectThis(args)->GetArray();
			bool upperFlag = args.IsSet(Gura_Symbol(upper));
			Stream *pStream = args.IsValid(0)?
				&Object_stream::GetObject(args, 0)->GetStream() : env.GetConsole();
			pArray->Dump(sig, *pStream, upperFlag);
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
				Gura_Symbol(en), Help::FMT_markdown,
				"Fills array with a specified value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Args &args) const {
			Array<T_Elem> *pArray = Object_array<T_Elem>::GetObjectThis(args)->GetArray();
			pArray->Fill(static_cast<T_Elem>(args.GetNumber(0)));
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
				Gura_Symbol(en), Help::FMT_markdown,
				"Creates an array that has extracted specified number of elements\n"
				"from the beginning of the source.\n"
				"\n"
				"If `block` is specified, it would be evaluated with a block parameter\n"
				"`|array:array@T|`, where `array` is the created instance.\n"
				"In this case, the block's result would become the function's returned value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Args &args) const {
			Signal &sig = env.GetSignal();
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetObjectThis(args)->GetArray();
			size_t n = args.GetSizeT(0);
			if (n > pArray->GetSize()) {
				sig.SetError(ERR_OutOfRangeError, "offset is out of range");
				return Value::Nil;
			}
			size_t offsetBase = pArray->GetOffsetBase();
			AutoPtr<Array<T_Elem> > pArrayRtn(
				new Array<T_Elem>(pArray->GetMemory()->Reference(), n, offsetBase));
			Value value(new Object_array<T_Elem>(env, _valType, pArrayRtn.release()));
			return ReturnValue(env, args, value);
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
				Gura_Symbol(en), Help::FMT_markdown,
				"Creates an array that has extracted elements of the source\n"
				"after skipping the first `n` elements.\n"
				"\n"
				"If `block` is specified, it would be evaluated with a block parameter\n"
				"`|array:array@T|`, where `array` is the created instance.\n"
				"In this case, the block's result would become the function's returned value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Args &args) const {
			Signal &sig = env.GetSignal();
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetObjectThis(args)->GetArray();
			size_t n = args.GetSizeT(0);
			if (n > pArray->GetSize()) {
				sig.SetError(ERR_OutOfRangeError, "offset is out of range");
				return Value::Nil;
			}
			size_t cnt = pArray->GetSize() - n;
			size_t offsetBase = pArray->GetOffsetBase() + n;
			AutoPtr<Array<T_Elem> > pArrayRtn(
				new Array<T_Elem>(pArray->GetMemory()->Reference(), cnt, offsetBase));
			Value value(new Object_array<T_Elem>(env, _valType, pArrayRtn.release()));
			return ReturnValue(env, args, value);
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
				Gura_Symbol(en), Help::FMT_markdown,
				"Pastes elements of `src` into the target `array` instance.\n"
				"\n"
				"The argument `offset` specifies the posision where elements are pasted in\n"
			);
		}
		virtual Value DoEval(Environment &env, Args &args) const {
			Signal &sig = env.GetSignal();
			Array<T_Elem> *pArray = Object_array<T_Elem>::GetObjectThis(args)->GetArray();
			size_t offset = args.GetSizeT(0);
			const Array<T_Elem> *pArraySrc = Object_array<T_Elem>::GetObject(args, 1)->GetArray();
			pArray->Paste(sig, offset, pArraySrc);
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
				Gura_Symbol(en), Help::FMT_markdown,
				"Creates an array that has extracted specified number of elements\n"
				"from the bottom of the source.\n"
				"\n"
				"If `block` is specified, it would be evaluated with a block parameter\n"
				"`|array:array@T|`, where `array` is the created instance.\n"
				"In this case, the block's result would become the function's returned value.\n"
			);
		}
		virtual Value DoEval(Environment &env, Args &args) const {
			Signal &sig = env.GetSignal();
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetObjectThis(args)->GetArray();
			size_t n = args.GetSizeT(0);
			if (n > pArray->GetSize()) {
				sig.SetError(ERR_OutOfRangeError, "offset is out of range");
				return Value::Nil;
			}
			size_t offsetBase = pArray->GetOffsetBase() + pArray->GetSize() - n;
			AutoPtr<Array<T_Elem> > pArrayRtn(
				new Array<T_Elem>(pArray->GetMemory()->Reference(), n, offsetBase));
			Value value(new Object_array<T_Elem>(env, _valType, pArrayRtn.release()));
			return ReturnValue(env, args, value);
		}
	};
private:
	String _elemName;
public:
	Class_array(Environment *pEnvOuter, ValueType valType, const String &elemName) :
							Class(pEnvOuter, valType), _elemName(elemName) {}
	virtual void Prepare(Environment &env) {
		do {
			const Symbol *pSymbol = ValueTypePool::GetInstance()->
									Lookup(GetValueType())->GetSymbol();
			env.AssignFunction(new Func_array(env, pSymbol, GetValueType()));
		} while (0);
		do {
			String funcName;
			funcName += "@";
			funcName += _elemName;
			const Symbol *pSymbol = Symbol::Add(funcName.c_str());
			env.AssignFunction(new Func_ArrayInit(env, pSymbol, GetValueType()));
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
			AutoPtr<Array<T_Elem> > pArray(CreateArrayFromList<T_Elem>(sig, value.GetList()));
			if (pArray.IsNull()) return false;
			value = Value(new Object_array<T_Elem>(env, GetValueType(), pArray.release()));
			return true;
		}
		return false;
	}
	virtual bool CastTo(Environment &env, Value &value, const Declaration &decl) {
		if (decl.IsType(VTYPE_list)) {
			AutoPtr<Array<T_Elem> > pArray(
				Object_array<T_Elem>::GetObject(value)->GetArray()->Reference());
			ValueList &valList = value.InitAsList(env);
			valList.reserve(pArray->GetSize());
			CopyArrayToList(pArray.get(), valList);
			return true;
		} else if (decl.IsType(VTYPE_iterator)) {
			const Array<T_Elem> *pArray = Object_array<T_Elem>::GetObject(value)->GetArray();
			AutoPtr<Iterator> pIterator(new Iterator_Array<T_Elem>(pArray->Reference()));
			value = Value(new Object_iterator(env, pIterator.release()));
			return true;
		}
		return false;
	}
};

}

#endif
