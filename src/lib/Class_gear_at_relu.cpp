//=============================================================================
// Gura class: gear@relu
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_Relu
//-----------------------------------------------------------------------------
Gear_Relu::GearFuncTable Gear_Relu::gearFuncTable = {{nullptr}};

bool Gear_Relu::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	GearFuncT gearFunc = gearFuncTable.funcs[pArray->GetElemType()];
	if (gearFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply ReLU gear on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*gearFunc)(sig, pArrayRtn, pArray, this);
}

String Gear_Relu::ToString() const
{
	return "relu";
}

//-----------------------------------------------------------------------------
// NodeGear_Relu
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Operator_Relu2Out {
public:
	inline static void Calc(T_Elem &elemRtn, Boolean &elemBool, const T_Elem &elem) {
		elemBool = (elem > 0);
		elemRtn = elemBool? elem : 0;
	}
};

bool NodeGear_Relu::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool NodeGear_Relu::EvalForward(Environment &env)
{
	static const Array::Unary2OutFuncT funcs[Array::ETYPE_Max] = {
		nullptr,
		&Array::Unary2OutFuncTmpl<Boolean,	Boolean,	Boolean,	Operator_Relu2Out<Boolean> >,
		&Array::Unary2OutFuncTmpl<Int8,		Boolean,	Int8,		Operator_Relu2Out<Int8> >,
		&Array::Unary2OutFuncTmpl<UInt8,	Boolean,	UInt8,		Operator_Relu2Out<UInt8> >,
		&Array::Unary2OutFuncTmpl<Int16,	Boolean,	Int16,		Operator_Relu2Out<Int16> >,
		&Array::Unary2OutFuncTmpl<UInt16,	Boolean,	UInt16,		Operator_Relu2Out<UInt16> >,
		&Array::Unary2OutFuncTmpl<Int32,	Boolean,	Int32,		Operator_Relu2Out<Int32> >,
		&Array::Unary2OutFuncTmpl<UInt32,	Boolean,	UInt32,		Operator_Relu2Out<UInt32> >,
		&Array::Unary2OutFuncTmpl<Int64,	Boolean,	Int64,		Operator_Relu2Out<Int64> >,
		&Array::Unary2OutFuncTmpl<UInt64,	Boolean,	UInt64,		Operator_Relu2Out<UInt64> >,
		&Array::Unary2OutFuncTmpl<Half,		Boolean,	Half,		Operator_Relu2Out<Half> >,
		&Array::Unary2OutFuncTmpl<Float,	Boolean,	Float,		Operator_Relu2Out<Float> >,
		&Array::Unary2OutFuncTmpl<Double,	Boolean,	Double,		Operator_Relu2Out<Double> >,
		nullptr,
		nullptr,
	};
	const Array *pArray = GetConnectorSrc()->GetArrayFwd();
	Array::Unary2OutFuncT func = funcs[pArray->GetElemType()];
	if (func == nullptr) {
		env.SetError(ERR_TypeError, "can't evaluate forward function");
		return nullptr;
	}
	(*func)(env, _pArrayFwd, _pArrayBool, pArray);
	return env.IsNoSignalled();
}

bool NodeGear_Relu::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		if (!Array::ApplyBinaryFunc(
				env, Array::binaryFuncPack_Mul, _connectorSrc.GetArrayBwdAutoPtr(),
				_pArrayBool.get(),
				(*ppConnectorDst)->GetArrayBwd())) return false;
	}
	return true;
}

bool NodeGear_Relu::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return NodeGear::DoDirProp(env, symbols);
}

Value NodeGear_Relu::DoGetProp(Environment &env, const Symbol *pSymbol,
								   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return NodeGear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

Trainer::NodeGear *NodeGear_Relu::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Relu(Object_gear_at_relu::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Object_gear_at_relu
//-----------------------------------------------------------------------------
Value Object_gear_at_relu::valueConst;

Object_gear_at_relu::Object_gear_at_relu(Environment &env, Gear_Relu *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_relu), pGear)
{
}

Object *Object_gear_at_relu::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@relu() {block?}
Gura_DeclareFunctionAlias(gear_at_relu, "gear@relu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_relu));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@relu` instance.\n");
}

Gura_ImplementFunction(gear_at_relu)
{
	return ReturnValue(env, arg, Object_gear_at_relu::valueConst);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_relu::Class_gear_at_relu(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_relu)
{
}

void Class_gear_at_relu::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_relu);
	// Assignment of value
	Object_gear_at_relu::valueConst = Value(new Object_gear_at_relu(env, new Gear_Relu()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_relu::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
