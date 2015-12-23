//=============================================================================
// Gura class: pointer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_pointer
//-----------------------------------------------------------------------------
Object_pointer::~Object_pointer()
{
}

Object *Object_pointer::Clone() const
{
	return new Object_pointer(*this);
}

bool Object_pointer::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(binary));
	symbols.insert(Gura_Symbol(offset));
	return true;
}

Value Object_pointer::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(binary))) {
		return Value(_pObjBinary->Reference());
	} else if (pSymbol->IsIdentical(Gura_Symbol(offset))) {
		return Value(_offset);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_pointer::ToString(bool exprFlag)
{
	char buff[64];
	::sprintf(buff, "<pointer:%d>", static_cast<int>(_offset));
	return String(buff);
}

bool Object_pointer::UnpackForward(Signal &sig, int distance, bool exceedErrorFlag)
{
	return _pObjBinary->GetBinary().UnpackForward(sig, _offset, distance, exceedErrorFlag);
}

Value Object_pointer::Unpack(Signal &sig, bool forwardFlag,
		const char *format, const ValueList &valListArg, bool exceedErrorFlag)
{
	Environment &env = *this;
	size_t offset = _offset;
	Value value = _pObjBinary->GetBinary().Unpack(env, offset,
											format, valListArg, exceedErrorFlag);
	if (forwardFlag) _offset = offset;
	return value;
}

bool Object_pointer::Pack(Signal &sig,
				bool forwardFlag, const char *format, const ValueList &valListArg)
{
	Environment &env = *this;
	size_t offset = _offset;
	if (!_pObjBinary->GetBinary().Pack(env, offset, format, valListArg)) return false;
	if (forwardFlag) _offset = offset;
	return true;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// pointer(buff:binary, offset?:number) {block?}
Gura_DeclareFunction(pointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "buff", VTYPE_binary, OCCUR_Once);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_pointer));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `pointer` instance that points to the specified `binary` instance.\n"
		"\n"
		"If the argument `offset` is specified, the initial offset of the pointer is preset to the value.\n"
		"Otherwise, the offset is set to the top of the binary.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("p", "pointer"));
}

Gura_ImplementFunction(pointer)
{
	Object_binary *pObj = Object_binary::GetObject(arg, 0);
	size_t offset = arg.Is_number(1)? arg.GetSizeT(1) : 0;
	return ReturnValue(env, arg, Value(new Object_pointer(env, pObj->Reference(), offset)));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// pointer#forward(distance:number):reduce
Gura_DeclareMethod(pointer, forward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "distance", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Put the pointer offset forward by `distance`.\n"
		"If a negative number is specified for the argument, the offset would be put backward.\n");
}

Gura_ImplementMethod(pointer, forward)
{
	Signal &sig = env.GetSignal();
	Object_pointer *pThis = Object_pointer::GetObjectThis(arg);
	bool exceedErrorFlag = true;
	pThis->UnpackForward(sig, arg.GetInt(0), exceedErrorFlag);
	return arg.GetValueThis();
}

// pointer#pack(format:string, value+):reduce:[stay]
Gura_DeclareMethod(pointer, pack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(stay));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Packs `values` in the argument list according to specifiers in the `format`\n"
		"into a binary and adds it to where the pointer points.\n"
		"The pointer offset is automatically incremented by the added length\n"
		"unless `:stay` attribute is specified.\n"
		"\n"
		"This method returns a reference to the pointer instance itself.\n"
		"\n"
		"For detail information about packing specifiers, see the help of `binary#pack()`.\n");
}

Gura_ImplementMethod(pointer, pack)
{
	Signal &sig = env.GetSignal();
	Object_pointer *pThis = Object_pointer::GetObjectThis(arg);
	if (!pThis->IsWritable()) {
		sig.SetError(ERR_ValueError, "not a writable binary");
		return Value::Nil;
	}
	bool forwardFlag = !arg.IsSet(Gura_Symbol(stay));
	pThis->Pack(sig, forwardFlag, arg.GetString(0), arg.GetList(1));
	return arg.GetValueThis();
}

// pointer#reset()
Gura_DeclareMethod(pointer, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(pointer, reset)
{
	Object_pointer *pThis = Object_pointer::GetObjectThis(arg);
	pThis->Reset();
	return Value::Nil;
}

// pointer#unpack(format:string, values*:number):[nil,stay]
Gura_DeclareMethod(pointer, unpack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_number, OCCUR_ZeroOrMore);
	DeclareAttr(Gura_Symbol(nil));
	DeclareAttr(Gura_Symbol(stay));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(pointer, unpack)
{
	Signal &sig = env.GetSignal();
	Object_pointer *pThis = Object_pointer::GetObjectThis(arg);
	bool forwardFlag = !arg.IsSet(Gura_Symbol(stay));
	bool exceedErrorFlag = !arg.IsSet(Gura_Symbol(nil));
	return pThis->Unpack(sig, forwardFlag,
					arg.GetString(0), arg.GetList(1), exceedErrorFlag);
}

// pointer#unpacks(format:string, values*:number)
Gura_DeclareMethod(pointer, unpacks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_number, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(pointer, unpacks)
{
	Object_pointer *pThis = Object_pointer::GetObjectThis(arg);
	Object_binary *pObj = Object_binary::Reference(pThis->GetBinaryObj());
	Iterator *pIterator = new Object_binary::IteratorUnpack(pObj,
						arg.GetString(0), arg.GetList(1), pThis->GetOffset());
	return ReturnIterator(env, arg, pIterator);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_pointer::Class_pointer(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_pointer)
{
}

void Class_pointer::Prepare(Environment &env)
{
	Gura_AssignFunction(pointer);
	Gura_AssignMethod(pointer, forward);
	Gura_AssignMethod(pointer, pack);
	Gura_AssignMethod(pointer, reset);
	Gura_AssignMethod(pointer, unpack);
	Gura_AssignMethod(pointer, unpacks);
}

Object *Class_pointer::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
