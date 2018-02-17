//=============================================================================
// Gura class: gear@averagepool1d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_AveragePool1d
//-----------------------------------------------------------------------------
bool Gear_AveragePool1d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizePad = 0;
	CalcPadding1d(this, pArray->GetDims(), &sizePad);
	return pArray->CalcAveragePool1d(sig, pArrayRtn, GetSize(), GetStrides(), sizePad, GetChannelPos());
}

bool Gear_AveragePool1d::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return Gear::DoDirProp(env, symbols);
}

Value Gear_AveragePool1d::DoGetProp(Environment &env, const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Gear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Gear_AveragePool1d::ToString() const
{
	String str;
	char buff[80];
	str += "averagepool1d";
	::sprintf(buff, ":size=%zu", GetSize());
	str += buff;
	::sprintf(buff, ":strides=%zu", GetStrides());
	str += buff;
	::sprintf(buff, ":padding=%s", PaddingTypeToSymbol(GetPaddingType())->GetName());
	str += buff;
	::sprintf(buff, ":channel_pos=%s", Array::ChannelPosToSymbol(GetChannelPos())->GetName());
	str += buff;
	return str;
}

Object *Gear_AveragePool1d::ToObject(Environment &env) const
{
	return new Object_gear_at_averagepool1d(env, Reference());
}

//-----------------------------------------------------------------------------
// NodeGear_AveragePool1d
//-----------------------------------------------------------------------------
bool NodeGear_AveragePool1d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool NodeGear_AveragePool1d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool NodeGear_AveragePool1d::EvalBackward(Environment &env)
{
	return false;
}

Trainer::NodeGear *NodeGear_AveragePool1d::CreatorEx::Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const
{
	return new NodeGear_AveragePool1d(Object_gear_at_averagepool1d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Object_gear_at_averagepool1d
//-----------------------------------------------------------------------------
Object_gear_at_averagepool1d::Object_gear_at_averagepool1d(Environment &env, Gear_AveragePool1d *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_averagepool1d), pGear)
{
}

Object *Object_gear_at_averagepool1d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@averagepool1d(size:number, strides?:number, padding?:symbol, channel_pos?:symbol):map {block?}
Gura_DeclareFunctionAlias(gear_at_averagepool1d, "gear@averagepool1d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_averagepool1d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@averagepool1d` instance.\n"
		"\n"
		"The `size` is a gear size.\n"
		"\n"
		"The `strides` is a strides of sliding window. Default is one.\n"
		"\n"
		"The `padding` is a padding style `` `valid`` or `` `same``. Default is `` `same``.\n"
		"\n"
		"The `channel_pos` specifies where channel dimension is positioned and takes `` `first`` or `` `last``.\n"
		"Default is `` `last``. \n");
}

Gura_ImplementFunction(gear_at_averagepool1d)
{
	size_t size = arg.GetSizeT(0);
	size_t strides = arg.IsValid(1)? arg.GetSizeT(1) : 1;
	Gear::PaddingType paddingType = Gear::PADDINGTYPE_Same;
	Array::ChannelPos channelPos = Array::CHANNELPOS_Last;
	if (arg.IsValid(1)) {
		strides = arg.GetSizeT(1);
	}
	if (arg.IsValid(2)) {
		paddingType = Gear::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Gear::PADDINGTYPE_Invalid) return Value::Nil;
	}
	if (arg.IsValid(3)) {
		channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3));
		if (channelPos == Array::CHANNELPOS_Invalid) return Value::Nil;
	}
	Object_gear_at_averagepool1d *pObj = new Object_gear_at_averagepool1d(
		env, new Gear_AveragePool1d(size, strides, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// gear@averagepool1d#channel_pos
Gura_DeclareProperty_R(gear_at_averagepool1d, channel_pos)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_averagepool1d, channel_pos)
{
	const Gear_AveragePool1d *pGear = Object_gear_at_averagepool1d::GetObject(valueThis)->GetGear();
	return Value(Array::ChannelPosToSymbol(pGear->GetChannelPos()));
}

// gear@averagepool1d#padding
Gura_DeclareProperty_R(gear_at_averagepool1d, padding)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_averagepool1d, padding)
{
	const Gear_AveragePool1d *pGear = Object_gear_at_averagepool1d::GetObject(valueThis)->GetGear();
	return Value(Gear::PaddingTypeToSymbol(pGear->GetPaddingType()));
}

// gear@averagepool1d#size
Gura_DeclareProperty_R(gear_at_averagepool1d, size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_averagepool1d, size)
{
	const Gear_AveragePool1d *pGear = Object_gear_at_averagepool1d::GetObject(valueThis)->GetGear();
	return Value(pGear->GetSize());
}

// gear@averagepool1d#strides
Gura_DeclareProperty_R(gear_at_averagepool1d, strides)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_averagepool1d, strides)
{
	const Gear_AveragePool1d *pGear = Object_gear_at_averagepool1d::GetObject(valueThis)->GetGear();
	return Value(pGear->GetStrides());
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_averagepool1d::Class_gear_at_averagepool1d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_averagepool1d)
{
}

void Class_gear_at_averagepool1d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_averagepool1d);
	// Assignment of properties
	Gura_AssignProperty(gear_at_averagepool1d, channel_pos);
	Gura_AssignProperty(gear_at_averagepool1d, padding);
	Gura_AssignProperty(gear_at_averagepool1d, size);
	Gura_AssignProperty(gear_at_averagepool1d, strides);
	// Assignment of NodeGear creator for Trainer
	Trainer::RegisterNodeGearCreator(VTYPE_gear_at_averagepool1d, new NodeGear_AveragePool1d::CreatorEx());
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_averagepool1d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
