//=============================================================================
// Gura class: gear@conv2d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_Conv2d
//-----------------------------------------------------------------------------
Gear_Conv2d::GearFuncTable Gear_Conv2d::gearFuncTable = {{{nullptr}}};

bool Gear_Conv2d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizePadRow = 0, sizePadCol = 0;
	CalcPadding2d(this, pArray->GetDimensions(), &sizePadRow, &sizePadCol);
	return pArray->CalcConv2d(sig, pArrayRtn, GetArrayGear(), GetStridesRow(), GetStridesCol(),
							  sizePadRow, sizePadCol, GetChannelPos());
}

String Gear_Conv2d::ToString() const
{
	char buff[80];
	String str = "conv2d";
	if (HasGearDim()) {
		::sprintf(buff, ":gear_num=%zu", GetGearNum());
		str += buff;
	}
	if (HasChannelDim()) {
		::sprintf(buff, ":channel_num=%zu", GetChannelNum());
		str += buff;
	}
	::sprintf(buff, ":size=(%zu,%zu)", GetSizeRow(), GetSizeCol());
	str += buff;
	::sprintf(buff, ":strides=(%zu,%zu)", GetStridesRow(), GetStridesCol());
	str += buff;
	::sprintf(buff, ":padding=%s", PaddingTypeToSymbol(GetPaddingType())->GetName());
	str += buff;
	::sprintf(buff, ":channel_pos=%s", Array::ChannelPosToSymbol(GetChannelPos())->GetName());
	str += buff;
	return str;
}

//-----------------------------------------------------------------------------
// Object_gear_at_conv2d
//-----------------------------------------------------------------------------
Object_gear_at_conv2d::Object_gear_at_conv2d(Environment &env, Gear_Conv2d *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_conv2d), pGear)
{
}

Object *Object_gear_at_conv2d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@conv2d(array:array, strides[]?:number, padding?:symbol, channel_pos?:symbol):map {block?}
Gura_DeclareFunctionAlias(gear_at_conv2d, "gear@conv2d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "array", VTYPE_array);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_conv2d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@conv2d` instance.\n"
		"\n"
		"The given `array` instance shoud have one of the following shapes:\n"
		"\n"
		"- `[row_size, col_size]` .. 2-dimensions\n"
		"- `[row_size, col_size, channel_num]` .. 3-dimensions and `channel_pos` is `` `last``\n"
		"- `[channel_num, row_size, col_size]` .. 3-dimensions and `channel_pos` is `` `first``\n"
		"- `[gear_num, row_size, col_size]` .. 3-dimensions and `channel_pos` is `` `none``\n"
		"- `[gear_num, row_size, col_size, channel_num]` .. 4-dimensions and `channel_pos` is `` `last``\n"
		"- `[gear_num, channel_num, row_size, col_size]` .. 4-dimensions and `channel_pos` is `` `first``\n"
		"\n"
		"where `row_size` and `col_size` are the size of the gear's kernel,\n"
		"`channel_num` is the number of channels and `gear_num` is the number of gears.\n"
		"\n"
		"The `strides` is a list of strides for a sliding window in row and column. Default is `[1, 1]`.\n"
		"\n"
		"The `padding` is a padding style and takes `` `valid`` or `` `same``. Default is `` `same``.\n"
		"When `valid` is specified, there is no padding. When `same` is specified, zero values are padded so that\n"
		"the result array has the size of the division of the original size by `strides`.\n"
		"\n"
		"The `channel_pos` is a channel position and takes `` `none``, `` `first`` or `` `last``.\n"
		"If not specified, `` `none` for an array without channel dimension\n"
		"and `` `last`` for others are to be set.\n");
}

Gura_ImplementFunction(gear_at_conv2d)
{
	const Array *pArrayGear = Object_array::GetObject(arg, 0)->GetArray();
	const Array::Dimensions &dims = pArrayGear->GetDimensions();
	size_t nDims = dims.size();
	if (nDims != 2 && nDims != 3 && nDims != 4) {
		env.SetError(ERR_ValueError,
					 "the `array` instance given to `gear@conv2d` constructor must have dimensions of 2, 3 or 4.");
		return Value::Nil;
	}
	size_t stridesRow = 1;
	size_t stridesCol = 1;
	if (arg.IsValid(1)) {
		const ValueList &valList = arg.GetList(1);
		if (valList.size() != 2) {
			env.SetError(ERR_ValueError, "strides must have two elements");
			return Value::Nil;
		}
		stridesRow = valList[0].GetSizeT();
		stridesCol = valList[1].GetSizeT();
	}
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
			if (nDims == 4) {
				env.SetError(ERR_ValueError, "channel dimension does exist in the array");
				return Value::Nil;
			}
		} else if (channelPos == Array::CHANNELPOS_Last) {
			if (nDims == 2) {
				env.SetError(ERR_ValueError, "channel dimension is expected to exist at last");
				return Value::Nil;
			}
		}
	} else {
		channelPos = (nDims == 2)? Array::CHANNELPOS_None : Array::CHANNELPOS_Last;
	}
	Object_gear_at_conv2d *pObj = new Object_gear_at_conv2d(
		env, new Gear_Conv2d(pArrayGear->Reference(), stridesRow, stridesCol, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// gear@conv2d#array
Gura_DeclareProperty_R(gear_at_conv2d, array)
{
	SetPropAttr(VTYPE_array);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(gear_at_conv2d, array)
{
	const Gear_Conv2d *pGear = Object_gear_at_conv2d::GetObject(valueThis)->GetGear();
	return Value(new Object_array(env, pGear->GetArrayGear()->Reference()));
}

// gear@conv2d#channel_num
Gura_DeclareProperty_R(gear_at_conv2d, channel_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv2d, channel_num)
{
	const Gear_Conv2d *pGear = Object_gear_at_conv2d::GetObject(valueThis)->GetGear();
	return pGear->HasChannelDim()? Value(pGear->GetChannelNum()) : Value::Nil;
}

// gear@conv2d#channel_pos
Gura_DeclareProperty_R(gear_at_conv2d, channel_pos)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv2d, channel_pos)
{
	const Gear_Conv2d *pGear = Object_gear_at_conv2d::GetObject(valueThis)->GetGear();
	return Value(Array::ChannelPosToSymbol(pGear->GetChannelPos()));
}

// gear@conv1d#gear_num
Gura_DeclareProperty_R(gear_at_conv2d, gear_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv2d, gear_num)
{
	const Gear_Conv2d *pGear = Object_gear_at_conv2d::GetObject(valueThis)->GetGear();
	return pGear->HasGearDim()? Value(pGear->GetGearNum()) : Value::Nil;
}

// gear@conv2d#padding
Gura_DeclareProperty_R(gear_at_conv2d, padding)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv2d, padding)
{
	const Gear_Conv2d *pGear = Object_gear_at_conv2d::GetObject(valueThis)->GetGear();
	return Value(Gear::PaddingTypeToSymbol(pGear->GetPaddingType()));
}

// gear@conv2d#size
Gura_DeclareProperty_R(gear_at_conv2d, size)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv2d, size)
{
	const Gear_Conv2d *pGear = Object_gear_at_conv2d::GetObject(valueThis)->GetGear();
	return Value::CreateList(env, Value(pGear->GetSizeRow()), Value(pGear->GetSizeCol()));
}

// gear@conv2d#strides
Gura_DeclareProperty_R(gear_at_conv2d, strides)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv2d, strides)
{
	const Gear_Conv2d *pGear = Object_gear_at_conv2d::GetObject(valueThis)->GetGear();
	return Value::CreateList(env, Value(pGear->GetStridesRow()), Value(pGear->GetStridesCol()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_conv2d::Class_gear_at_conv2d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_conv2d)
{
}

void Class_gear_at_conv2d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_conv2d);
	// Assignment of properties
	Gura_AssignProperty(gear_at_conv2d, array);
	Gura_AssignProperty(gear_at_conv2d, channel_num);
	Gura_AssignProperty(gear_at_conv2d, channel_pos);
	Gura_AssignProperty(gear_at_conv2d, gear_num);
	Gura_AssignProperty(gear_at_conv2d, padding);
	Gura_AssignProperty(gear_at_conv2d, size);
	Gura_AssignProperty(gear_at_conv2d, strides);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_conv2d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
