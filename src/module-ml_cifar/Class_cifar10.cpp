#include "stdafx.h"

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// Cifar10
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Object_cifar10 implementation
//-----------------------------------------------------------------------------
Object_cifar10::Object_cifar10(Cifar10 *pCifar10) :
					Object(Gura_UserClass(cifar10)), _pCifar10(pCifar10)
{
}

String Object_cifar10::ToString(bool exprFlag)
{
	char buff[80];
	String str = "<cifar.cifar10";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.cifar.cifar10(stream:stream):map {block?}
Gura_DeclareFunction(cifar10)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(cifar10));
	AddHelp(
		Gura_Symbol(en),
		"Reads CIFAR image set file from the specified `stream`\n"
		"and returns a `ml.cifar.cifar10` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("stream", "stream"));
}

Gura_ImplementFunction(cifar10)
{
#if 0
	Object_cifar10 *pObj = new Object_cifar10(pImageSet.release());
	return ReturnValue(env, arg, Value(pObj));
#endif
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class ml.cifar.cifar10
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(cifar10)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(cifar10);
	// Assignment of method
}

Gura_EndModuleScope(ml_cifar)
