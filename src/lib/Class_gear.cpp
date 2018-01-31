//=============================================================================
// Gura class: gear
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear
//-----------------------------------------------------------------------------
Gear::~Gear()
{
}

bool Gear::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Gear::DoGetProp(Environment &env, const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Nil;
}

void Gear::CalcPadding(size_t sizeIn, size_t sizeKernel, size_t strides, PaddingType paddingType,
					   size_t *pSizePad, size_t *pSizeOut)
{
	size_t sizePad = 0, sizeOut = 0;
	if (paddingType == PADDINGTYPE_Valid) {
		// sizeIn = 9, strides = 3
		// +++++++++  +++++++++  +++++++++  +++++++++
		// **         ***        ****       *****
		//    **         ***        ****       *****
		//       **         ***
		//
		// sizeIn = 10, strides = 3
		// ++++++++++  ++++++++++  ++++++++++  ++++++++++
		// **          ***         ****        *****
		//    **          ***         ****        *****
		//       **          ***         ****
		//
		sizeOut = (sizeIn - sizeKernel + strides) / strides;
	} else if (paddingType == PADDINGTYPE_Same) {
		// sizeIn = 9, strides = 3 ... sizeOut = 3
		// +++++++++  +++++++++  +++++++++.  .+++++++++.
		// **         ***        ****        *****
		//    **         ***        ****        *****
		//       **         ***        ****        *****
		//
		// sizeIn = 10, strides = 3 ... sizeOut = 4
		// ++++++++++.  .++++++++++.  .++++++++++..  ..++++++++++..
		// **           ***           ****           *****
		//    **           ***           ****           *****
		//       **           ***           ****           *****
		//          **           ***           ****           *****
		//
		sizeOut = (sizeIn + strides - 1) / strides;
		sizePad = strides * (sizeOut - 1) + sizeKernel - sizeIn;
	} else {
		// nothing to do 
	}
	if (pSizePad != nullptr) *pSizePad = sizePad;
	if (pSizeOut != nullptr) *pSizeOut = sizeOut;
}

Gear::PaddingType Gear::SymbolToPaddingType(Signal &sig, const Symbol *pSymbol)
{
	PaddingType paddingType = SymbolToPaddingType(pSymbol);
	if (paddingType == PADDINGTYPE_Invalid) {
		sig.SetError(ERR_ValueError, "specify `valid or `same for padding type",
					 pSymbol->GetName());
	}
	return paddingType;
}

Gear::PaddingType Gear::SymbolToPaddingType(const Symbol *pSymbol)
{
	return
		pSymbol->IsIdentical(Gura_Symbol(valid))? PADDINGTYPE_Valid :
		pSymbol->IsIdentical(Gura_Symbol(same))? PADDINGTYPE_Same :
		PADDINGTYPE_Invalid;
}

const Symbol *Gear::PaddingTypeToSymbol(PaddingType paddingType)
{
	return
		(paddingType == PADDINGTYPE_Valid)? Gura_Symbol(valid) :
		(paddingType == PADDINGTYPE_Same)? Gura_Symbol(same) :
		Gura_Symbol(none);
}

//-----------------------------------------------------------------------------
// Object_gear
//-----------------------------------------------------------------------------
Object_gear::Object_gear(Environment &env, Gear *pGear) :
	Object(env.LookupClass(VTYPE_gear)), _pGear(pGear)
{
}

Object_gear::Object_gear(Class *pClass, Gear *pGear) :
	Object(pClass), _pGear(pGear)
{
}

bool Object_gear::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return _pGear->DoDirProp(env, symbols);
}

Value Object_gear::DoGetProp(Environment &env, const Symbol *pSymbol,
							 const SymbolSet &attrs, bool &evaluatedFlag)
{
	return _pGear->DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Object_gear::ToString(bool exprFlag)
{
	String str;
	str += "<gear@";
	str += _pGear->ToString();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear.calcpadding(size_in:number, size_kernel:number, strides:number, padding:symbol):map {block?}
Gura_DeclareClassMethod(gear, calcpadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size_in", VTYPE_number);
	DeclareArg(env, "size_kernel", VTYPE_number);
	DeclareArg(env, "strides", VTYPE_number);
	DeclareArg(env, "padding", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates padding amounts from given input size, gear size and strides.\n"
		"The argument `padding` specifies padding manner and can take `` `same`` or `` `valid``.\n"
		"The returned value is a list of `[padding, size_out]`.");
}

Gura_ImplementClassMethod(gear, calcpadding)
{
	size_t sizeIn = arg.GetSizeT(0);
	size_t sizeKernel = arg.GetSizeT(1);
	size_t strides = arg.GetSizeT(2);
	Gear::PaddingType paddingType = Gear::SymbolToPaddingType(env, arg.GetSymbol(3));
	if (paddingType == Gear::PADDINGTYPE_Invalid) return Value::Nil;
	size_t sizePad = 0, sizeOut = 0;
	Gear::CalcPadding(sizeIn, sizeKernel, strides, paddingType, &sizePad, &sizeOut);
	return Value::CreateList(env, Value(sizePad), Value(sizeOut));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear::Class_gear(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_gear)
{
}

void Class_gear::DoPrepare(Environment &env)
{
	// Assignment of methods
	Gura_AssignMethod(gear, calcpadding);
	// Assignment of value
	Gura_AssignValue(gear, Value(this));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
