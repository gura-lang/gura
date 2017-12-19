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
// NodeGear_Conv2d
//-----------------------------------------------------------------------------
bool NodeGear_Conv2d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool NodeGear_Conv2d::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return NodeGear::DoDirProp(env, symbols);
}

Value NodeGear_Conv2d::DoGetProp(Environment &env, const Symbol *pSymbol,
								   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return NodeGear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

bool NodeGear_Conv2d::EvalForward(Environment &env)
{
	Gear_Conv2d *pGear = GetGear();
	const Double padNum = 0;
	// pArraySrc .. [H, W], [H, W, C], [C, H, W], [N, C, H, W] or [N, H, W, C]
	const Array *pArrayFwdSrc = GetConnectorSrc()->GetArrayFwd();
	// _pArrayFwdSrcVec .. [H_out * W_out, C * FH * FW] or [N, H_out * W_out, C * FH * FW]
	if (_pArrayFwdSrcVec.IsNull()) {
		Gear::CalcPadding2d(pGear, pArrayFwdSrc->GetDimensions(),
							&_sizePadRow, &_sizePadCol, &_sizeOutRow, &_sizeOutCol);
	}
	if (!pArrayFwdSrc->ExpandKernelVec2d(
			env, _pArrayFwdSrcVec, pGear->GetSizeRow(), pGear->GetSizeCol(),
			pGear->GetStridesRow(), pGear->GetStridesCol(), _sizePadRow, _sizePadCol,
			pGear->GetChannelPos(), padNum)) return false;
	const Array *pArrayGear = pGear->GetArrayGear();
	const Array::Dimensions &dimsGear = pArrayGear->GetDimensions();
	if (_pArrayGearTrans.IsNull()) {
		Array::Dimensions dims;
		if (pGear->HasChannelDim()) {
			if (pGear->HasFilterDim()) {
				// pArrayGear .. [FN, C, FH, FW] or [FN, FH, FW, C]
				// _pArrayGearReshape .. [FN, C * FH * FW]
				// _pArrayGearTrans .. [C * FH * FW, FN]
				dims.reserve(2);
				dims.push_back(Array::Dimension(dimsGear[0].GetSize()));
				dims.push_back(Array::Dimension(dimsGear[1].GetSize() * dimsGear[2].GetSize() * dimsGear[3].GetSize()));
			} else {
				// pArrayGear .. [C, FH, FW], [FH, FW, C]
				// _pArrayGearReshape .. [1, C * FH * FW]
				// _pArrayGearTrans .. [C * FH * FW, 1]
				dims.reserve(2);
				dims.push_back(Array::Dimension(1));
				dims.push_back(Array::Dimension(dimsGear[0].GetSize() * dimsGear[1].GetSize() * dimsGear[2].GetSize()));
			}
		} else {
			if (pGear->HasFilterDim()) {
				// pArrayGear .. [FN, FH, FW] or [FN, FH, FW]
				// _pArrayGearReshape .. [FN, FH * FW]
				// _pArrayGearTrans .. [FH * FW, FN]
				dims.reserve(2);
				dims.push_back(Array::Dimension(dimsGear[0].GetSize()));
				dims.push_back(Array::Dimension(dimsGear[1].GetSize() * dimsGear[2].GetSize()));
			} else {
				// pArrayGear .. [FH, FW], [FH, FW]
				// _pArrayGearReshape .. [1, FH * FW]
				// _pArrayGearTrans .. [FH * FW, 1]
				dims.reserve(2);
				dims.push_back(Array::Dimension(1));
				dims.push_back(Array::Dimension(dimsGear[0].GetSize() * dimsGear[1].GetSize()));
			}
		}
		pArrayGear->Reshape(_pArrayGearReshape, dims);
		_pArrayGearReshape->Transpose2d(_pArrayGearTrans);
	}
	// _pArrayFwdPre = _pArrayFwdSrcVec |.| _pArrayGearTrans
	if (!Array::ApplyBinaryFunc(
			env, Array::binaryFuncPack_Dot, _pArrayFwdPre,
			_pArrayFwdSrcVec.get(), _pArrayGearTrans.get())) return false;
	//::printf("_pArrayFwdSrcVec: %s\n", _pArrayFwdSrcVec->GetDimensions().ToString().c_str());
	//::printf("_pArrayGearTrans: %s\n", _pArrayGearTrans->GetDimensions().ToString().c_str());
	//::printf("_pArrayFwdPre: %s\n", _pArrayFwdPre->GetDimensions().ToString().c_str());
	if (_pArrayFwd.IsNull()) {
		const Array::Dimensions &dimsPre = _pArrayFwdPre->GetDimensions();
		Array::Dimensions dims;
		if (dimsPre.size() == 2) {
			if (pGear->HasFilterDim()) {
				// _pArrayFwdPre .. [H_out * W_out, FN]
				// _pArrayFwd .. [H_out, W_out, FN]
				dims.reserve(3);
				dims.push_back(Array::Dimension(_sizeOutRow));
				dims.push_back(Array::Dimension(_sizeOutCol));
				dims.push_back(Array::Dimension(dimsPre[1].GetSize()));
			} else {
				// _pArrayFwdPre .. [H_out * W_out, 1]
				// _pArrayFwd .. [H_out, W_out]
				dims.reserve(3);
				dims.push_back(Array::Dimension(_sizeOutRow));
				dims.push_back(Array::Dimension(_sizeOutCol));
			}
		} else {
			if (pGear->HasFilterDim()) {
				// _pArrayFwdPre .. [N, H_out * W_out, FN]
				// _pArrayFwd .. [N, H_out, W_out, FN]
				dims.reserve(4);
				dims.push_back(Array::Dimension(dimsPre[0].GetSize()));
				dims.push_back(Array::Dimension(_sizeOutRow));
				dims.push_back(Array::Dimension(_sizeOutCol));
				dims.push_back(Array::Dimension(dimsPre[2].GetSize()));
			} else {
				// _pArrayFwdPre .. [N, H_out * W_out, 1]
				// _pArrayFwd .. [N, H_out, W_out]
				dims.reserve(3);
				dims.push_back(Array::Dimension(dimsPre[0].GetSize()));
				dims.push_back(Array::Dimension(_sizeOutRow));
				dims.push_back(Array::Dimension(_sizeOutCol));
			}
		}
		_pArrayFwdPre->Reshape(_pArrayFwd, dims);
	}
	return true;
}

bool NodeGear_Conv2d::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		//const Array *pArrayBwdSrc = (*ppConnectorDst)->GetArrayBwd();
		//AutoPtr<Array> &pArrayBwd = _connectorSrc.GetArrayBwdAutoPtr();
		// pArrayBwdSrc .. [H_out, W_out], [H_out, W_out, FN], [FN, H_out, W_out], [N, H_out, W_out], [N, H_out, W_out, FN]
		// pArrayBwdSrcReshape .. [H_out * W_out], [H_out * W_out, FN], [FN, H_out * W_out], [N * h_out, W_out], [N * H_out * W_out, FN]
		// pArrayBwdSrcTrans .. [FN, N * H_out * W_out]
		// _pArrayFwdPre = _pArrayFwdSrcVec |.| _pArrayGearTrans
		// _pArrayFwdSrcVec .. [H_out * W_out, C * FH * FW] or [N, H_out * W_out, C * FH * FW]
		// _pArrayGearReshape .. [FN, C * FH * FW]
		// _pArrayGearTrans .. [C * FH * FW, FN]
		// pArrayBwdVec = pArrayBwdSrcReshape |.| _pArrayGearReshape
		// pArrayGearDiff = pArrayBwdSrcTrans |.| _pArrayFwdSrcVec
		// pArrayBwdVec .. [N * H_out * W_out, C * FH * FW]
		// pArrayGearDiff .. [FN, C * FH * FW]
	}
	return true;
}

Trainer::NodeGear *NodeGear_Conv2d::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Conv2d(Object_gear_at_conv2d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
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
		"- `[filter_num, row_size, col_size]` .. 3-dimensions and `channel_pos` is `` `none``\n"
		"- `[filter_num, row_size, col_size, channel_num]` .. 4-dimensions and `channel_pos` is `` `last``\n"
		"- `[filter_num, channel_num, row_size, col_size]` .. 4-dimensions and `channel_pos` is `` `first``\n"
		"\n"
		"where `row_size` and `col_size` are the size of the filter's kernel,\n"
		"`channel_num` is the number of channels and `filter_num` is the number of filters.\n"
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
	Gear::PaddingType paddingType = Gear::PADDINGTYPE_Same;
	Array::ChannelPos channelPos = Array::CHANNELPOS_Invalid;
	Value value1, value2;
	if (arg.IsInvalid(1)) {
		// nothing to do
	} else if (arg.GetListValues(1, &value1, &value2)) {
		stridesRow = value1.GetSizeT();
		stridesCol = value2.GetSizeT();
	} else {
		env.SetError(ERR_ValueError, "strides must have two elements");
		return Value::Nil;
	}
	if (arg.IsValid(2)) {
		paddingType = Gear::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Gear::PADDINGTYPE_Invalid) return Value::Nil;
	}
	if (arg.IsValid(3)) {
		channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3));
		if (channelPos == Array::CHANNELPOS_Invalid) return Value::Nil;
	} else {
		channelPos = (nDims == 2)? Array::CHANNELPOS_None : Array::CHANNELPOS_Last;
	}
	if (!dims.HasEnoughDims(env, 2, channelPos)) return Value::Nil;
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

// gear@conv1d#filter_num
Gura_DeclareProperty_R(gear_at_conv2d, filter_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_conv2d, filter_num)
{
	const Gear_Conv2d *pGear = Object_gear_at_conv2d::GetObject(valueThis)->GetGear();
	return pGear->HasFilterDim()? Value(pGear->GetFilterNum()) : Value::Nil;
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
	Gura_AssignProperty(gear_at_conv2d, filter_num);
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
