//=============================================================================
// Gura class: gear@conv1d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
# Overview


# Constructor

${markdown.makedoc@function(`en
gear@conv1d
)}


# Property

A `gear@conv1d` instance has the following properties:

${markdown.makedoc@property(`en, gear@conv1d)}
)**";

//-----------------------------------------------------------------------------
// Gear_Conv1d
//-----------------------------------------------------------------------------
Gear_Conv1d::GearFuncTable Gear_Conv1d::gearFuncTable = {{{nullptr}}};

bool Gear_Conv1d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizePad = 0;
	CalcPadding1d(this, pArray->GetDims(), &sizePad);
	return pArray->CalcConv1d(sig, pArrayRtn, GetArrayGear(), GetStrides(), sizePad, GetChannelPos());
}

bool Gear_Conv1d::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return Gear::DoDirProp(env, symbols);
}

Value Gear_Conv1d::DoGetProp(Environment &env, const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Gear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Gear_Conv1d::ToString() const
{
	char buff[80];
	String str = "conv1d";
	str += ":filter_num=";
	if (HasFilterDim()) {
		::sprintf(buff, "%zu", GetFilterNum());
		str += buff;
	} else {
		str += "none";
	}
	str += ":channel_num=";
	if (HasChannelDim()) {
		::sprintf(buff, "%zu", GetChannelNum());
		str += buff;
	} else {
		str += "none";
	}
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

Object *Gear_Conv1d::ToObject(Environment &env) const
{
	return new Object_gear_at_conv1d(env, Reference());
}

//-----------------------------------------------------------------------------
// NodeGear_Conv1d
//-----------------------------------------------------------------------------
bool NodeGear_Conv1d::IsVulnerable() const
{
	return true;
}

bool NodeGear_Conv1d::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return NodeGear::DoDirProp(env, symbols);
}

Value NodeGear_Conv1d::DoGetProp(Environment &env, const Symbol *pSymbol,
								   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return NodeGear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

bool NodeGear_Conv1d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool NodeGear_Conv1d::EvalBackward(Environment &env)
{
	return false;
}

Trainer::NodeGear *NodeGear_Conv1d::CreatorEx::Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const
{
	return new NodeGear_Conv1d(Object_gear_at_conv1d::GetObject(value)->GetGear()->Reference(), pConnectorDst,
							   pTrainer->CreateOptimizerInstance());
}

//-----------------------------------------------------------------------------
// Object_gear_at_conv1d
//-----------------------------------------------------------------------------
Object_gear_at_conv1d::Object_gear_at_conv1d(Environment &env, Gear_Conv1d *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_conv1d), pGear)
{
}

Object *Object_gear_at_conv1d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@conv1d(array:array, strides?:number, padding?:symbol, channel_pos?:symbol):map {block?}
Gura_DeclareFunctionAlias(gear_at_conv1d, "gear@conv1d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "array", VTYPE_array);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_conv1d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@conv1d` instance.\n"
		"\n"
		"The `array` is an `array` instance that has one of the following shapes:\n"
		"\n"
		"- `[size]` .. 1-dimension\n"
		"- `[size, channel_num]` .. 2-dimensions and `channel_pos` is `` `last``\n"
		"- `[channel_num, size]` .. 2-dimensions and `channel_pos` is `` `first``\n"
		"- `[filter_num, size]` .. 2-dimensions and `channel_pos` is `` `none``\n"
		"- `[filter_num, size, channel_num]` .. 3-dimensions and `channel_pos` is `` `last``\n"
		"- `[filter_num, channel_num, size]` .. 3-dimensions and `channel_pos` is `` `first``\n"
		"\n"
		"where `size` is the size of the filter's kernel,\n"
		"`channel_num` is the number of channels and `filter_num` is the number of filters.\n"
		"\n"
		"The `strides` is a strides for a sliding window. Default is one.\n"
		"\n"
		"The `padding` is a padding style and takes `` `valid`` or `` `same``. Default is `` `same``.\n"
		"When `valid` is specified, there is no padding. When `same` is specified, zero values are padded so that\n"
		"the result array has the size of the division of the original size by `strides`.\n"
		"\n"
		"The `channel_pos` is a channel position and takes `` `none``, `` `first`` or `` `last``.\n"
		"If not specified, `` `none` for an array without channel dimension\n"
		"and `` `last`` for others are to be set.\n");
}

Gura_ImplementFunction(gear_at_conv1d)
{
	const Array *pArrayGear = Object_array::GetObject(arg, 0)->GetArray();
	const Array::Dimensions &dims = pArrayGear->GetDims();
	size_t nDims = dims.size();
	if (nDims != 1 && nDims != 2 && nDims != 3) {
		env.SetError(ERR_ValueError,
					 "the `array` instance given to `gear@conv1d` constructor must have dimensions of 1, 2 or 3.");
		return Value::Nil;
	}
	size_t strides = 1;
	Gear::PaddingType paddingType = Gear::PADDINGTYPE_Same;
	Array::ChannelPos channelPos = Array::CHANNELPOS_Invalid;
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
	} else {
		channelPos = (nDims == 1)? Array::CHANNELPOS_None : Array::CHANNELPOS_Last;
	}
	if (!dims.HasEnoughDims(env, 1, channelPos)) return Value::Nil;
	Object_gear_at_conv1d *pObj = new Object_gear_at_conv1d(
		env, new Gear_Conv1d(pArrayGear->Reference(), strides, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// gear@conv1d#array
Gura_DeclareProperty_R(gear_at_conv1d, array)
{
	SetPropAttr(VTYPE_array);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(gear_at_conv1d, array)
{
	const Gear_Conv1d *pGear = Object_gear_at_conv1d::GetObject(valueThis)->GetGear();
	return Value(new Object_array(env, pGear->GetArrayGear()->Reference()));
}

// gear@conv1d#channel_num
Gura_DeclareProperty_R(gear_at_conv1d, channel_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv1d, channel_num)
{
	const Gear_Conv1d *pGear = Object_gear_at_conv1d::GetObject(valueThis)->GetGear();
	return pGear->HasChannelDim()? Value(pGear->GetChannelNum()) : Value::Nil;
}

// gear@conv1d#channel_pos
Gura_DeclareProperty_R(gear_at_conv1d, channel_pos)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv1d, channel_pos)
{
	const Gear_Conv1d *pGear = Object_gear_at_conv1d::GetObject(valueThis)->GetGear();
	return Value(Array::ChannelPosToSymbol(pGear->GetChannelPos()));
}

// gear@conv1d#filter_num
Gura_DeclareProperty_R(gear_at_conv1d, filter_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv1d, filter_num)
{
	const Gear_Conv1d *pGear = Object_gear_at_conv1d::GetObject(valueThis)->GetGear();
	return pGear->HasFilterDim()? Value(pGear->GetFilterNum()) : Value::Nil;
}

// gear@conv1d#padding
Gura_DeclareProperty_R(gear_at_conv1d, padding)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv1d, padding)
{
	const Gear_Conv1d *pGear = Object_gear_at_conv1d::GetObject(valueThis)->GetGear();
	return Value(Gear::PaddingTypeToSymbol(pGear->GetPaddingType()));
}

// gear@conv1d#size
Gura_DeclareProperty_R(gear_at_conv1d, size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv1d, size)
{
	const Gear_Conv1d *pGear = Object_gear_at_conv1d::GetObject(valueThis)->GetGear();
	return Value(pGear->GetSize());
}

// gear@conv1d#strides
Gura_DeclareProperty_R(gear_at_conv1d, strides)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv1d, strides)
{
	const Gear_Conv1d *pGear = Object_gear_at_conv1d::GetObject(valueThis)->GetGear();
	return Value(pGear->GetStrides());
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_conv1d::Class_gear_at_conv1d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_conv1d)
{
}

void Class_gear_at_conv1d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_conv1d);
	// Assignment of properties
	Gura_AssignProperty(gear_at_conv1d, array);
	Gura_AssignProperty(gear_at_conv1d, channel_num);
	Gura_AssignProperty(gear_at_conv1d, channel_pos);
	Gura_AssignProperty(gear_at_conv1d, filter_num);
	Gura_AssignProperty(gear_at_conv1d, padding);
	Gura_AssignProperty(gear_at_conv1d, size);
	Gura_AssignProperty(gear_at_conv1d, strides);
	// Assignment of NodeGear creator for Trainer
	Trainer::RegisterNodeGearCreator(VTYPE_gear_at_conv1d, new NodeGear_Conv1d::CreatorEx());
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_conv1d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
