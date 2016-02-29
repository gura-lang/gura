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
	symbols.insert(Gura_Symbol(target));
	symbols.insert(Gura_Symbol(offset));
	return true;
}

Value Object_pointer::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(target))) {
		return Value(GetPointer()->GetTarget()->Reference());
	} else if (pSymbol->IsIdentical(Gura_Symbol(offset))) {
		return Value(GetPointer()->GetOffset());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_pointer::ToString(bool exprFlag)
{
	char buff[64];
	::sprintf(buff, "<pointer:%d>", static_cast<int>(GetPointer()->GetOffset()));
	return String(buff);
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
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	bool exceedErrorFlag = true;
	pPointer->Advance(env, arg.GetInt(0), exceedErrorFlag);
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
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	if (!pPointer->IsWritable()) {
		env.SetError(ERR_ValueError, "not a writable binary");
		return Value::Nil;
	}
	bool forwardFlag = !arg.IsSet(Gura_Symbol(stay));
	pPointer->Pack(env, forwardFlag, arg.GetString(0), arg.GetList(1));
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
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	pPointer->Reset();
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
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	bool forwardFlag = !arg.IsSet(Gura_Symbol(stay));
	bool exceedErrorFlag = !arg.IsSet(Gura_Symbol(nil));
	return pPointer->Unpack(env, forwardFlag,
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
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	Iterator *pIterator = pPointer->CreateUnpackIterator(arg.GetString(0), arg.GetList(1));
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
	//Gura_AssignFunction(pointer);
	Gura_AssignValue(pointer, Value(Reference()));
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
