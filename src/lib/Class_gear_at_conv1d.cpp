//=============================================================================
// Gura class: gear@conv1d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_Conv1d
//-----------------------------------------------------------------------------
Gear_Conv1d::GearFuncTable Gear_Conv1d::gearFuncTable = {{{nullptr}}};

bool Gear_Conv1d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizePad = 0;
	CalcPadding1d(this, pArray->GetDimensions(), &sizePad);
	return pArray->CalcConv1d(sig, pArrayRtn, GetArrayGear(), GetStrides(), sizePad, GetChannelPos());
}

String Gear_Conv1d::ToString() const
{
	char buff[80];
	String str = "conv1d";
	if (HasGearDim()) {
		::sprintf(buff, ":gear_num=%zu", GetGearNum());
		str += buff;
	}
	if (HasChannelDim()) {
		::sprintf(buff, ":channel_num=%zu", GetChannelNum());
		str += buff;
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
		"- `[gear_num, size]` .. 2-dimensions and `channel_pos` is `` `none``\n"
		"- `[gear_num, size, channel_num]` .. 3-dimensions and `channel_pos` is `` `last``\n"
		"- `[gear_num, channel_num, size]` .. 3-dimensions and `channel_pos` is `` `first``\n"
		"\n"
		"where `size` is the size of the gear's kernel,\n"
		"`channel_num` is the number of channels and `gear_num` is the number of gears.\n"
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
	const Array::Dimensions &dims = pArrayGear->GetDimensions();
	size_t nDims = dims.size();
	if (nDims != 1 && nDims != 2 && nDims != 3) {
		env.SetError(ERR_ValueError,
					 "the `array` instance given to `gear@conv1d` constructor must have dimensions of 1, 2 or 3.");
		return Value::Nil;
	}
	size_t strides = arg.IsValid(1)? arg.GetSizeT(1) : 1;
	Gear::PaddingType paddingType = Gear::PADDINGTYPE_Same;
	if (arg.IsValid(2)) {
		paddingType = Gear::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Gear::PADDINGTYPE_Invalid) return Value::Nil;
	}
	Array::ChannelPos channelPos = Array::CHANNELPOS_Invalid;
	if (arg.IsValid(3)) {
		channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3));
		if (channelPos == Array::CHANNELPOS_Invalid) {
			return Value::Nil;
		} else if (channelPos == Array::CHANNELPOS_None) {
			if (nDims == 3) {
				env.SetError(ERR_ValueError, "channel dimension does exist in the array");
				return Value::Nil;
			}
		} else if (channelPos == Array::CHANNELPOS_Last) {
			if (nDims == 1) {
				env.SetError(ERR_ValueError, "channel dimension is expected to exist at last");
				return Value::Nil;
			}
		}
	} else {
		channelPos = (nDims == 1)? Array::CHANNELPOS_None : Array::CHANNELPOS_Last;
	}
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

// gear@conv1d#gear_num
Gura_DeclareProperty_R(gear_at_conv1d, gear_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv1d, gear_num)
{
	const Gear_Conv1d *pGear = Object_gear_at_conv1d::GetObject(valueThis)->GetGear();
	return pGear->HasGearDim()? Value(pGear->GetGearNum()) : Value::Nil;
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
	Gura_AssignProperty(gear_at_conv1d, gear_num);
	Gura_AssignProperty(gear_at_conv1d, padding);
	Gura_AssignProperty(gear_at_conv1d, size);
	Gura_AssignProperty(gear_at_conv1d, strides);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_conv1d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
