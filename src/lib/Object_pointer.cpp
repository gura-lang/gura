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

String Object_pointer::ToString(Signal sig, bool exprFlag)
{
	char buff[64];
	::sprintf(buff, "<pointer:%d>", static_cast<int>(_offset));
	return String(buff);
}

bool Object_pointer::UnpackForward(Signal sig, int distance, bool exceedErrorFlag)
{
	return _pObjBinary->GetBinary().UnpackForward(sig, _offset, distance, exceedErrorFlag);
}

Value Object_pointer::Unpack(Signal sig,
					bool forwardFlag, const char *format, bool exceedErrorFlag)
{
	Environment &env = *this;
	size_t offset = _offset;
	Value value = _pObjBinary->GetBinary().Unpack(env, sig, offset, format, exceedErrorFlag);
	if (forwardFlag) _offset = offset;
	return value;
}

bool Object_pointer::Pack(Signal sig,
					bool forwardFlag, const char *format, const ValueList &valList)
{
	Environment &env = *this;
	size_t offset = _offset;
	if (!_pObjBinary->GetBinary().Pack(env, sig, offset, format, valList)) return false;
	if (forwardFlag) _offset = offset;
	return true;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_pointer
//-----------------------------------------------------------------------------
// pointer#reset()
Gura_DeclareMethod(pointer, reset)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pointer, reset)
{
	Object_pointer *pThis = Object_pointer::GetThisObj(args);
	pThis->Reset();
	return Value::Null;
}

// pointer#pack(format:string, value+):reduce:[stay]
Gura_DeclareMethod(pointer, pack)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "value", VTYPE_any, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(stay));
}

Gura_ImplementMethod(pointer, pack)
{
	Object_pointer *pThis = Object_pointer::GetThisObj(args);
	if (!pThis->IsWritable()) {
		sig.SetError(ERR_ValueError, "not a writable binary");
		return Value::Null;
	}
	bool forwardFlag = !args.IsSet(Gura_Symbol(stay));
	pThis->Pack(sig, forwardFlag, args.GetString(0), args.GetList(1));
	return args.GetThis();
}

// pointer#unpack(format:string):[stay]
Gura_DeclareMethod(pointer, unpack)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareAttr(Gura_Symbol(stay));
}

Gura_ImplementMethod(pointer, unpack)
{
	Object_pointer *pThis = Object_pointer::GetThisObj(args);
	bool forwardFlag = !args.IsSet(Gura_Symbol(stay));
	return pThis->Unpack(sig, forwardFlag, args.GetString(0), false);
}

// pointer#unpacks(format:string, cnt?:number)
Gura_DeclareMethod(pointer, unpacks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "cnt", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(pointer, unpacks)
{
	Object_pointer *pThis = Object_pointer::GetThisObj(args);
	Object_binary *pObj = Object_binary::Reference(pThis->GetBinaryObj());
	const char *format = args.GetString(0);
	int cntMax = args.IsNumber(1)? args.GetInt(1) : -1;
	Iterator *pIterator =
		new Object_binary::IteratorUnpack(pObj, format, pThis->GetOffset(), cntMax);
	return ReturnIterator(env, sig, args, pIterator);
}

// pointer#forward(distance:number):reduce
Gura_DeclareMethod(pointer, forward)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "distance", VTYPE_number);
}

Gura_ImplementMethod(pointer, forward)
{
	Object_pointer *pThis = Object_pointer::GetThisObj(args);
	bool exeedErrorFlag = true;
	pThis->UnpackForward(sig, args.GetInt(0), exeedErrorFlag);
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_pointer::Class_pointer(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_pointer)
{
	Gura_AssignMethod(pointer, reset);
	Gura_AssignMethod(pointer, pack);
	Gura_AssignMethod(pointer, unpack);
	Gura_AssignMethod(pointer, unpacks);
	Gura_AssignMethod(pointer, forward);
}

Object *Class_pointer::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return NULL;
}

void Class_pointer::OnModuleEntry(Environment &env, Signal sig)
{
}

}
